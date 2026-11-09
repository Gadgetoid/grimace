"""
Windows CE CAB files: an uncompressed MSCF cabinet holding the files and a setup file (MSCE, the .000 member) that tells
wceload where to put them, which registry values to set and which shortcuts to make.
"""
import struct

ARCHITECTURE_ANY = 0
ARCHITECTURE_MIPS = 4000
ARCHITECTURES = {"mips": ARCHITECTURE_MIPS, "sh3": 10003, "x86": 486, "arm": 2577}

HIVES = {"HKCR": 1, "HKCU": 2, "HKLM": 3, "HKU": 4}
REG_SZ = 0x00000000
REG_BINARY = 0x00000001
REG_MULTI_SZ = 0x00010000
REG_DWORD = 0x00010001
NO_CLOBBER = 0x00000002

FILE_WARN_IF_SKIPPED = 0x00000001
FILE_NO_SKIP = 0x00000002
FILE_NO_OVERWRITE = 0x00000010
FILE_SHARED = 0x80000000

BLOCK_SIZE = 0x8000


class Setup:
    def __init__(self, app, provider, architecture=ARCHITECTURE_MIPS, unsupported="", versions=(0, 0, 0, 0, 0, 0)):
        self.app = app
        self.provider = provider
        self.architecture = architecture
        self.unsupported = unsupported
        self.versions = versions
        self.strings = []
        self.directories = []
        self.files = []
        self.hives = []
        self.keys = []
        self.links = []

    def string(self, text):
        for identifier, existing in self.strings:
            if existing == text:
                return identifier
        identifier = len(self.strings) + 1
        self.strings.append((identifier, text))
        return identifier

    def directory(self, path):
        parts = [self.string(part) for part in path.split("\\")]
        for identifier, existing in self.directories:
            if existing == parts:
                return identifier
        identifier = len(self.directories) + 1
        self.directories.append((identifier, parts))
        return identifier

    def file(self, directory, name, member, flags=0):
        identifier = len(self.files) + 1
        self.files.append((identifier, self.directory(directory), member, flags, name))
        return identifier

    def hive(self, root, key):
        parts = [self.string(part) for part in key.split("\\")]
        for identifier, existing_root, existing in self.hives:
            if existing_root == HIVES[root] and existing == parts:
                return identifier
        identifier = len(self.hives) + 1
        self.hives.append((identifier, HIVES[root], parts))
        return identifier

    def value(self, root, key, name, value, flags=None):
        if isinstance(value, int):
            kind, data = REG_DWORD, struct.pack("<I", value)
        else:
            kind, data = REG_SZ, value.encode("latin-1") + b"\0"
        if flags is not None:
            kind |= flags
        identifier = len(self.keys) + 1
        expands = isinstance(value, str) and "%" in value
        self.keys.append((identifier, self.hive(root, key), 1 if expands else 0, kind, name.encode("latin-1") + b"\0" + data))

    def shortcut(self, directory, name, file_identifier):
        identifier = len(self.links) + 1
        self.links.append((identifier, self.directory(directory), 0, file_identifier, 1, [self.string(name)]))

    def encode(self):
        def text(value):
            return value.encode("latin-1") + b"\0"

        def id_list(values):
            return struct.pack("<%dH" % (len(values) + 1), *values, 0)

        body = bytearray()
        header_size = 0x64
        app_offset = header_size + len(body)
        body += text(self.app)
        provider_offset = header_size + len(body)
        body += text(self.provider)
        unsupported_offset = header_size + len(body)
        unsupported = text(self.unsupported) + b"\0" if self.unsupported else b""
        body += unsupported

        offsets = []
        offsets.append(header_size + len(body))
        for identifier, value in self.strings:
            encoded = text(value)
            body += struct.pack("<HH", identifier, len(encoded)) + encoded
        offsets.append(header_size + len(body))
        for identifier, parts in self.directories:
            encoded = id_list(parts)
            body += struct.pack("<HH", identifier, len(encoded)) + encoded
        offsets.append(header_size + len(body))
        for identifier, directory, member, flags, name in self.files:
            encoded = text(name)
            body += struct.pack("<HHHIH", identifier, directory, member, flags, len(encoded)) + encoded
        offsets.append(header_size + len(body))
        for identifier, root, parts in self.hives:
            encoded = id_list(parts)
            body += struct.pack("<HHHH", identifier, root, 0, len(encoded)) + encoded
        offsets.append(header_size + len(body))
        for identifier, hive, expands, kind, data in self.keys:
            body += struct.pack("<HHHIH", identifier, hive, expands, kind, len(data)) + data
        offsets.append(header_size + len(body))
        for identifier, directory, macro, target, target_kind, parts in self.links:
            encoded = id_list(parts)
            body += struct.pack("<6H", identifier, directory, macro, target, target_kind, len(encoded)) + encoded

        counts = [len(self.strings), len(self.directories), len(self.files), len(self.hives), len(self.keys), len(self.links)]
        header = bytearray(header_size)
        header[0:4] = b"MSCE"
        struct.pack_into("<IIIII", header, 4, 0, header_size + len(body), 0, 1, self.architecture)
        struct.pack_into("<6I", header, 0x18, *self.versions)
        struct.pack_into("<6H", header, 0x30, *counts)
        struct.pack_into("<6I", header, 0x3C, *offsets)
        struct.pack_into("<6H", header, 0x54, app_offset, len(text(self.app)), provider_offset, len(text(self.provider)),
                         unsupported_offset if unsupported else 0, len(unsupported))
        return bytes(header + body)


def checksum(data, seed=0):
    value = seed
    full = len(data) // 4 * 4
    for position in range(0, full, 4):
        value ^= struct.unpack_from("<I", data, position)[0]
    remainder = data[full:]
    tail = 0
    if len(remainder) == 3:
        tail = remainder[0] << 16 | remainder[1] << 8 | remainder[2]
    elif len(remainder) == 2:
        tail = remainder[0] << 8 | remainder[1]
    elif len(remainder) == 1:
        tail = remainder[0]
    return value ^ tail


def cabinet(members, set_identifier=0x5643, dos_date=0x2D21, dos_time=0x6000):
    stream = b"".join(data for _, data in members)
    blocks = [stream[position:position + BLOCK_SIZE] for position in range(0, len(stream), BLOCK_SIZE)] or [b""]
    header_size = 36
    folder_size = 8
    files_offset = header_size + folder_size
    file_entries = bytearray()
    offset = 0
    for name, data in members:
        file_entries += struct.pack("<IIHHHH", len(data), offset, 0, dos_date, dos_time, 0x20) + name.encode("latin-1") + b"\0"
        offset += len(data)
    data_offset = files_offset + len(file_entries)
    data_area = bytearray()
    for block in blocks:
        sizes = struct.pack("<HH", len(block), len(block))
        block_checksum = checksum(sizes, checksum(block))
        data_area += struct.pack("<I", block_checksum) + sizes + block
    total = data_offset + len(data_area)
    header = struct.pack("<4sIIIIIBBHHHHH", b"MSCF", 0, total, 0, files_offset, 0, 3, 1, 1, len(members), 0, set_identifier, 0)
    folder = struct.pack("<IHH", data_offset, len(blocks), 0)
    return header + folder + bytes(file_entries) + bytes(data_area)


def member_name(name, number):
    stem = name.rsplit(".", 1)[0]
    cleaned = "".join(character for character in stem if character.isalnum())[:8] or "FILE"
    return "%s.%03d" % (cleaned, number)


class Package:
    def __init__(self, app, provider, **options):
        self.setup = Setup(app, provider, **options)
        self.members = []

    def add_file(self, directory, name, data, flags=0):
        number = len(self.members) + 1
        self.members.append((member_name(name, number), data))
        return self.setup.file(directory, name, number, flags)

    def build(self):
        setup = self.setup.encode()
        setup_name = member_name(self.setup.app, 0)
        return cabinet([(setup_name, setup)] + list(reversed(self.members)))

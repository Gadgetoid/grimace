"""
Write a self-installing program for Windows CE: installer/ceinstall.c built for the device, with the files, folders,
shortcuts and registry values appended as a .cepk section. It installs on CE 1.0, which has no CAB installer, and later
versions. Run it again to remove what it installed, or with /q to install without asking.

    selfinstall.py MyApp.cab MyApp.exe --stub build/ceinstall.exe

converts a CAB, uncompressed or MSZIP, to a self-installer. The format and the CAB conversion follow CEM Porter's.
"""
import argparse
import re
import struct
import zlib

ROOTS = {"HKCR": 0x80000000, "HKCU": 0x80000001, "HKLM": 0x80000002, "HKU": 0x80000003}
ROOT_NAMES = {"HKEY_CLASSES_ROOT": "HKCR", "HKEY_CURRENT_USER": "HKCU", "HKEY_LOCAL_MACHINE": "HKLM", "HKEY_USERS": "HKU"}
KINDS = {"mkdir": 1, "file": 2, "shortcut": 3, "regsz": 4, "regmulti": 5, "run": 6, "regdword": 8, "regkey": 9, "regbinary": 11,
         "setupdll": 12}
FILE_SHARED = 1
FILE_MODULE_PATH = 2
MAGIC = 0x4B504543
MARKER = struct.pack("<II", 0x4B504543, 0x4F4C4543)
SECTION_NAME = b".cepk"
SECTION_CHARACTERISTICS = 0x40000040

CE_MACROS = {
    1: "\\Program Files", 2: "\\Windows", 3: "\\Windows\\Desktop", 4: "\\Windows\\StartUp", 5: "\\My Documents",
    6: "\\Program Files\\Accessories", 7: "\\Program Files\\Communication", 8: "\\Program Files\\Games",
    9: "\\Program Files\\Pocket Outlook", 10: "\\Program Files\\Office", 11: "\\Windows\\Programs",
    12: "\\Windows\\Programs\\Accessories", 13: "\\Windows\\Programs\\Communications", 14: "\\Windows\\Programs\\Games",
    15: "\\Windows\\Fonts", 16: "\\Windows\\Recent", 17: "\\Windows\\Favorites",
}
SYSTEM_FOLDERS = {"\\windows", "\\program files", "\\windows\\programs"}
CAB_HIVES = {1: "HKCR", 2: "HKCU", 3: "HKLM", 4: "HKU"}


def align(value, alignment):
    return (value + alignment - 1) // alignment * alignment


class PayloadWriter:
    def __init__(self):
        self.data = bytearray()
        self.strings = {}

    def reserve(self, length):
        offset = len(self.data)
        self.data += bytes(length)
        return offset

    def align_to(self, alignment):
        self.data += bytes(align(len(self.data), alignment) - len(self.data))

    def string(self, text):
        if text not in self.strings:
            self.align_to(2)
            self.strings[text] = len(self.data)
            self.data += (text + "\0").encode("utf-16-le")
        return self.strings[text]

    def multi_string(self, values):
        self.align_to(2)
        offset = len(self.data)
        self.data += ("\0".join(values) + "\0\0").encode("utf-16-le")
        return offset

    def blob(self, data, with_length=False):
        self.align_to(4)
        offset = len(self.data)
        if with_length:
            self.data += struct.pack("<I", len(data))
        self.data += data
        return offset


def root_value(root):
    if isinstance(root, int):
        return root
    name = ROOT_NAMES.get(root.upper(), root.upper())
    if name not in ROOTS:
        raise ValueError("unknown registry root %s" % root)
    return ROOTS[name]


def operation_values(writer, operation):
    kind = operation["kind"]
    if kind == "mkdir":
        return [writer.string(operation["path"]), 0, 0, 0]
    if kind == "file":
        flags = (FILE_SHARED if operation.get("shared") else 0) | (FILE_MODULE_PATH if operation.get("module_path") else 0)
        return [writer.string(operation["path"]), writer.blob(operation["data"]), len(operation["data"]), flags]
    if kind == "shortcut":
        return [writer.string(operation["link"]), writer.string(operation["target"]), 0, 0]
    if kind == "regkey":
        return [root_value(operation["root"]), writer.string(operation["key"]), 0, 0]
    if kind in ("regsz", "regmulti", "regdword", "regbinary"):
        root = root_value(operation["root"])
        key = writer.string(operation["key"])
        name = writer.string(operation.get("name", ""))
        if kind == "regsz":
            value = writer.string(operation["value"])
        elif kind == "regmulti":
            value = writer.multi_string(operation["value"])
        elif kind == "regdword":
            value = operation["value"] & 0xFFFFFFFF
        else:
            value = writer.blob(operation["value"], True)
        return [root, key, name, value]
    if kind == "setupdll":
        return [writer.string(operation["path"]), writer.blob(operation["data"]), len(operation["data"]), writer.string(operation["install_folder"])]
    if kind == "run":
        return [writer.string(operation["program"]), writer.string(operation.get("arguments", "")), 0, 0]
    raise ValueError("unknown operation %s" % kind)


def build_payload(title, operations):
    writer = PayloadWriter()
    header = writer.reserve(20)
    table = writer.reserve(20 * len(operations))
    for index, operation in enumerate(operations):
        values = operation_values(writer, operation)
        struct.pack_into("<5I", writer.data, table + 20 * index, KINDS[operation["kind"]], *values)
    title_offset = writer.string(title)
    struct.pack_into("<5I", writer.data, header, MAGIC, 1, title_offset, len(operations), table)
    return bytes(writer.data)


def attach_payload(stub, payload):
    output = bytearray(stub)
    header = struct.unpack_from("<I", output, 0x3C)[0]
    section_count, = struct.unpack_from("<H", output, header + 6)
    optional_size, = struct.unpack_from("<H", output, header + 20)
    optional = header + 24
    image_base, section_alignment, file_alignment = struct.unpack_from("<III", output, optional + 28)
    table = optional + optional_size
    sections = [struct.unpack_from("<IIII", output, table + 40 * index + 8) for index in range(section_count)]
    first_raw = min(raw_offset for _, _, raw_size, raw_offset in sections if raw_size)
    entry = table + 40 * section_count
    if entry + 40 > first_raw:
        raise ValueError("no room in the stub for another section header")
    virtual_address = max(align(address + max(virtual_size, raw_size), section_alignment) for virtual_size, address, raw_size, _ in sections)
    raw_offset = align(max(offset + size for _, _, size, offset in sections), file_alignment)
    raw_size = align(len(payload), file_alignment)
    output = bytearray(bytes(output[:raw_offset]).ljust(raw_offset, b"\0")) + payload + bytes(raw_size - len(payload))
    struct.pack_into("<8sIIIIIIHHI", output, entry, SECTION_NAME, len(payload), virtual_address, raw_size, raw_offset, 0, 0, 0, 0,
                     SECTION_CHARACTERISTICS)
    struct.pack_into("<H", output, header + 6, section_count + 1)
    struct.pack_into("<I", output, optional + 56, align(virtual_address + len(payload), section_alignment))
    initialized, = struct.unpack_from("<I", output, optional + 8)
    struct.pack_into("<I", output, optional + 8, initialized + raw_size)
    marker = next((offset for offset in range(0, raw_offset, 4) if output[offset:offset + 8] == MARKER), None)
    if marker is None:
        raise ValueError("the stub has no payload marker")
    struct.pack_into("<II", output, marker + 8, image_base + virtual_address, len(payload))
    return bytes(output)


def expand_macros(text, install_folder, app_name):
    def replace(match):
        token = match.group(1)
        if token.lower() == "installdir":
            return install_folder
        if token.lower() == "appname":
            return app_name
        if token.lower().startswith("ce") and token[2:].isdigit() and int(token[2:]) in CE_MACROS:
            return CE_MACROS[int(token[2:])]
        return match.group(0)
    return re.sub(r"%([A-Za-z0-9]+)%", replace, text)


class Plan:
    def __init__(self, title, provider=""):
        self.title = title
        self.provider = provider
        self.operations = []
        self.directories = set()

    def mkdir(self, path):
        parts = path.strip("\\").split("\\")
        for count in range(1, len(parts) + 1):
            partial = "\\" + "\\".join(parts[:count])
            if partial.lower() not in SYSTEM_FOLDERS and partial.lower() not in self.directories:
                self.directories.add(partial.lower())
                self.operations.append({"kind": "mkdir", "path": partial})

    def copy(self, data, destination):
        self.mkdir(destination.rsplit("\\", 1)[0])
        if not any(operation["kind"] == "file" and operation["path"].lower() == destination.lower() for operation in self.operations):
            self.operations.append({"kind": "file", "path": destination, "data": data, "shared": destination.lower().startswith("\\windows\\")})

    def shortcut(self, link, target):
        self.mkdir(link.rsplit("\\", 1)[0])
        self.operations.append({"kind": "shortcut", "link": link, "target": target})

    def registry(self, kind, root, key, name, value):
        self.operations.append({"kind": kind, "root": root, "key": key, "name": name, "value": value})

    def build(self, stub):
        return attach_payload(stub, build_payload(self.title, self.operations))


def safe_name(name):
    return "".join(character for character in name if character not in "\\/:*?\"<>|").strip() or "Application"


def link_name(name):
    return name if name.lower().endswith(".lnk") else name + ".lnk"


def plan_from_description(description):
    plan = Plan(description["name"], description.get("provider", ""))
    install_folder = expand_macros(description["directory"], "", description["name"])
    paths = {}
    for item in description["files"]:
        folder = expand_macros(item.get("directory", description["directory"]), install_folder, description["name"])
        paths[item["name"].lower()] = folder + "\\" + item["name"]
        with open(item["path"], "rb") as source:
            plan.copy(source.read(), paths[item["name"].lower()])
    for shortcut in description.get("shortcuts", []):
        folder = expand_macros(shortcut.get("directory", "%CE11%"), install_folder, description["name"])
        plan.shortcut(folder + "\\" + link_name(shortcut["name"]), paths[shortcut["file"].lower()])
    for value in description.get("registry", []):
        kind = "regdword" if isinstance(value["value"], int) else "regsz"
        plan.registry(kind, value["root"], value["key"], value["name"], value["value"])
    return plan


def read_cab(data):
    if data[:4] != b"MSCF":
        raise ValueError("not a CAB file")
    folder_count, file_count, flags = struct.unpack_from("<HHH", data, 26)
    files_offset, = struct.unpack_from("<I", data, 16)
    if flags & 3:
        raise ValueError("multi-volume CABs aren't supported")
    position = 36
    folder_reserve = data_reserve = 0
    if flags & 4:
        header_reserve, folder_reserve, data_reserve = struct.unpack_from("<HBB", data, 36)
        position = 40 + header_reserve
    folders = []
    for _ in range(folder_count):
        first_block, block_count, compression = struct.unpack_from("<IHH", data, position)
        folders.append((first_block, block_count, compression))
        position += 8 + folder_reserve
    contents = []
    for first_block, block_count, compression in folders:
        method = compression & 0x0F
        if method not in (0, 1):
            raise ValueError("compression type %d isn't supported, only none and MSZIP" % method)
        output = bytearray()
        position = first_block
        for _ in range(block_count):
            compressed_size, uncompressed_size = struct.unpack_from("<HH", data, position + 4)
            block = data[position + 8 + data_reserve:position + 8 + data_reserve + compressed_size]
            position += 8 + data_reserve + compressed_size
            if method == 0:
                output += block
            else:
                if block[:2] != b"CK":
                    raise ValueError("MSZIP block is missing its CK signature")
                decompressor = zlib.decompressobj(-15, zdict=bytes(output[-32768:])) if output else zlib.decompressobj(-15)
                inflated = decompressor.decompress(block[2:])
                if len(inflated) != uncompressed_size:
                    raise ValueError("MSZIP block decompressed to the wrong size")
                output += inflated
        contents.append(bytes(output))
    members = {}
    position = files_offset
    for _ in range(file_count):
        size, offset, folder = struct.unpack_from("<IIH", data, position)
        name_end = data.index(b"\0", position + 16)
        name = data[position + 16:name_end].decode("latin-1")
        members[name] = contents[folder][offset:offset + size]
        position = name_end + 1
    return members


def read_setup(data):
    if data[:4] not in (b"MSCE", b"CE4+"):
        raise ValueError("not a CE setup file")

    def words(offset, count):
        return list(struct.unpack_from("<%dH" % count, data, offset))

    def text(offset, length):
        return data[offset:offset + length].split(b"\0", 1)[0].decode("latin-1")

    def ids(offset, length):
        return [value for value in words(offset, length // 2) if value]

    counts = words(0x30, 6)
    offsets = list(struct.unpack_from("<6I", data, 0x3C))
    app_offset, app_length, provider_offset, provider_length = words(0x54, 4)
    setup = {"app": text(app_offset, app_length), "provider": text(provider_offset, provider_length), "strings": {}, "directories": {},
             "files": {}, "hives": {}, "keys": [], "links": []}
    position = offsets[0]
    for _ in range(counts[0]):
        identifier, length = words(position, 2)
        setup["strings"][identifier] = text(position + 4, length)
        position += 4 + length
    position = offsets[1]
    for _ in range(counts[1]):
        identifier, length = words(position, 2)
        setup["directories"][identifier] = ids(position + 4, length)
        position += 4 + length
    position = offsets[2]
    for _ in range(counts[2]):
        identifier, directory, _ = words(position, 3)
        length, = struct.unpack_from("<H", data, position + 10)
        setup["files"][identifier] = {"directory": directory, "name": text(position + 12, length)}
        position += 12 + length
    position = offsets[3]
    for _ in range(counts[3]):
        identifier, hive, _, length = words(position, 4)
        setup["hives"][identifier] = {"hive": hive, "spec": ids(position + 8, length)}
        position += 8 + length
    position = offsets[4]
    for _ in range(counts[4]):
        _, hive, _ = words(position, 3)
        flags, = struct.unpack_from("<I", data, position + 6)
        length, = struct.unpack_from("<H", data, position + 10)
        setup["keys"].append({"hive": hive, "flags": flags, "data": data[position + 12:position + 12 + length]})
        position += 12 + length
    position = offsets[5]
    for _ in range(counts[5]):
        fields = words(position, 6)
        setup["links"].append({"fields": fields[:5], "spec": ids(position + 12, fields[5])})
        position += 12 + fields[5]
    return setup


def plan_from_cab(data, install_folder=None):
    members = read_cab(data)
    setup_name = next((name for name in members if name.lower().endswith(".000")), None)
    if not setup_name:
        raise ValueError("the CAB has no .000 setup file")
    setup = read_setup(members[setup_name])
    by_number = {int(name.rsplit(".", 1)[1]): content for name, content in members.items() if name.rsplit(".", 1)[-1].isdigit()}
    app_name = setup["app"] or "Application"
    plan = Plan(app_name, setup["provider"])
    install_folder = install_folder or "%s\\%s" % (CE_MACROS[1], safe_name(app_name))

    def joined(spec):
        return "\\".join(setup["strings"].get(value, "") for value in spec)

    def directory_path(identifier):
        path = expand_macros(joined(setup["directories"].get(identifier, [])), install_folder, app_name) or install_folder
        return path if path.startswith("\\") else "\\" + path

    destinations = {}
    for identifier in sorted(setup["files"]):
        entry = setup["files"][identifier]
        if identifier not in by_number:
            raise ValueError("file %d (%s) is missing from the CAB" % (identifier, entry["name"]))
        destinations[identifier] = directory_path(entry["directory"]) + "\\" + entry["name"]
        plan.copy(by_number[identifier], destinations[identifier])
    for key in setup["keys"]:
        hive = setup["hives"].get(key["hive"])
        if not hive:
            continue
        root = CAB_HIVES.get(hive["hive"], "HKLM")
        subkey = expand_macros(joined(hive["spec"]), install_folder, app_name)
        name, _, value = key["data"].partition(b"\0")
        name = name.decode("latin-1")
        if subkey.lower().startswith("software\\apps\\") and name.lower() in ("instl", "instldir"):
            continue
        kind = key["flags"] & 0x10001
        if kind == 0x10001:
            plan.registry("regdword", root, subkey, name, struct.unpack("<I", value[:4].ljust(4, b"\0"))[0])
        elif kind == 0x10000:
            values = [expand_macros(part, install_folder, app_name) for part in value.decode("latin-1").split("\0") if part]
            plan.registry("regmulti", root, subkey, name, values)
        elif kind == 1:
            plan.registry("regbinary", root, subkey, name, value)
        else:
            plan.registry("regsz", root, subkey, name, expand_macros(value.decode("latin-1").split("\0")[0], install_folder, app_name))
    for link in setup["links"]:
        _, base_directory, base_macro, target_identifier, target_kind = link["fields"]
        base = directory_path(base_directory) if base_directory else CE_MACROS.get(base_macro, CE_MACROS[11])
        name = expand_macros(joined(link["spec"]), install_folder, app_name)
        target = destinations.get(target_identifier) if target_kind == 1 else directory_path(target_identifier)
        if target:
            plan.shortcut(base + "\\" + name, target)
    if 999 in by_number:
        plan.operations.insert(0, {"kind": "setupdll", "path": "\\Windows\\%s setup.dll" % safe_name(app_name), "data": by_number[999],
                                   "install_folder": install_folder})
    return plan


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert a Windows CE CAB to a self-installing program, which also installs on CE 1.0")
    parser.add_argument("cab")
    parser.add_argument("output")
    parser.add_argument("--stub", required=True, help="installer/ceinstall.c built for the CAB's processor")
    parser.add_argument("--directory", help="install folder, instead of \\Program Files\\<application>")
    arguments = parser.parse_args()
    with open(arguments.cab, "rb") as source:
        plan = plan_from_cab(source.read(), arguments.directory)
    with open(arguments.stub, "rb") as stub:
        installer = plan.build(stub.read())
    with open(arguments.output, "wb") as output:
        output.write(installer)
    print("selfinstall: %s, %d operations, %d bytes" % (plan.title, len(plan.operations), len(installer)))

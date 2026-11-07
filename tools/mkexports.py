import argparse
import os
import struct
import sys

ARCHIVE_MAGIC = b"!<arch>\n"
MEMBER_HEADER_SIZE = 60
SECTION_HEADER_SIZE = 40
SYMBOL_SIZE = 18
IMPORT_PREFIX = "__imp_"
SHORT_IMPORT_SIGNATURE = (0, 0xFFFF)
ORDINAL_FLAG = 0x80000000
DECORATED_MACHINES = {0x14C, 0x1A2, 0x1A3, 0x1A6}
SHORT_NAME_ORDINAL = 0
SHORT_NAME_NOPREFIX = 2
SHORT_NAME_UNDECORATE = 3


def archive_members(data):
    if not data.startswith(ARCHIVE_MAGIC):
        raise ValueError("not an archive")
    position = len(ARCHIVE_MAGIC)
    while position + MEMBER_HEADER_SIZE <= len(data):
        name = data[position:position + 16].decode("latin-1").strip()
        size = int(data[position + 48:position + 58].decode("latin-1").strip())
        body_start = position + MEMBER_HEADER_SIZE
        yield name, data[body_start:body_start + size]
        position = body_start + size + (size & 1)


def undecorate(symbol, machine):
    if machine in DECORATED_MACHINES and symbol.startswith("_"):
        symbol = symbol[1:]
    return symbol.split("@")[0]


def short_import(body):
    machine, _, _, hint, kind = struct.unpack_from("<HIIHH", body, 6)
    name_end = body.index(b"\0", 20)
    symbol = body[20:name_end].decode("latin-1")
    dll_end = body.index(b"\0", name_end + 1)
    dll = body[name_end + 1:dll_end].decode("latin-1")
    name_type = (kind >> 2) & 7
    if name_type == SHORT_NAME_NOPREFIX:
        symbol = symbol.lstrip("?@_")
    elif name_type in (SHORT_NAME_UNDECORATE, SHORT_NAME_ORDINAL):
        symbol = undecorate(symbol, machine)
    return dll, symbol, None if name_type != SHORT_NAME_ORDINAL else hint


class CoffObject:
    def __init__(self, body):
        self.body = body
        self.machine, section_count, _, self.symbols_offset, self.symbol_count, optional_size, _ = struct.unpack_from("<HHIIIHH", body, 0)
        self.strings_offset = self.symbols_offset + SYMBOL_SIZE * self.symbol_count
        self.sections = []
        for index in range(section_count):
            raw_name, _, _, size, data_offset, relocations_offset, _, relocation_count, _, _ = struct.unpack_from(
                "<8sIIIIIIHHI", body, 20 + optional_size + SECTION_HEADER_SIZE * index)
            self.sections.append((self.name(raw_name), body[data_offset:data_offset + size], relocation_count))

    def name(self, raw):
        if raw[:4] == b"\0\0\0\0":
            offset = self.strings_offset + struct.unpack_from("<I", raw, 4)[0]
            return self.body[offset:self.body.index(b"\0", offset)].decode("latin-1")
        return raw.rstrip(b"\0").decode("latin-1")

    def symbol_names(self):
        index = 0
        while index < self.symbol_count:
            position = self.symbols_offset + SYMBOL_SIZE * index
            yield self.name(self.body[position:position + 8])
            index += 1 + self.body[position + 17]

    def section(self, name):
        for section_name, contents, relocation_count in self.sections:
            if section_name == name:
                return contents, relocation_count
        return None, 0


def long_import(member_name, body):
    coff = CoffObject(body)
    slots = [symbol for symbol in coff.symbol_names() if symbol.startswith(IMPORT_PREFIX)]
    if len(slots) != 1:
        return None
    dll = member_name.rstrip("/")
    lookup, lookup_relocations = coff.section(".idata$4")
    hint_name, _ = coff.section(".idata$6")
    if lookup and not lookup_relocations and struct.unpack_from("<I", lookup)[0] & ORDINAL_FLAG:
        return dll, undecorate(slots[0][len(IMPORT_PREFIX):], coff.machine), struct.unpack_from("<I", lookup)[0] & 0xFFFF
    if not hint_name:
        return None
    return dll, hint_name[2:hint_name.index(b"\0", 2)].decode("latin-1"), None


def library_imports(path):
    found = {}
    for member_name, body in archive_members(open(path, "rb").read()):
        if member_name in ("/", "//") or len(body) < 20:
            continue
        if struct.unpack_from("<HH", body, 0) == SHORT_IMPORT_SIGNATURE:
            entry = short_import(body)
        else:
            entry = long_import(member_name, body)
        if entry:
            dll, name, ordinal = entry
            found.setdefault(dll, {})[name] = ordinal
    return found


def dll_exports(path):
    data = open(path, "rb").read()
    header = struct.unpack_from("<I", data, 0x3C)[0]
    section_count, optional_size = struct.unpack_from("<H", data, header + 6)[0], struct.unpack_from("<H", data, header + 20)[0]
    export_rva = struct.unpack_from("<I", data, header + 24 + 96)[0]
    sections = [struct.unpack_from("<IIII", data, header + 24 + optional_size + SECTION_HEADER_SIZE * index + 8)
                for index in range(section_count)]

    def offset(rva):
        for size, address, raw_size, raw_offset in sections:
            if address <= rva < address + max(size, raw_size):
                return raw_offset + rva - address
        raise ValueError("RVA %x is in no section" % rva)

    names = {}
    if export_rva:
        directory = offset(export_rva)
        ordinal_base, _, name_count, _, names_rva, ordinals_rva = struct.unpack_from("<IIIIII", data, directory + 16)
        for index in range(name_count):
            name_offset = offset(struct.unpack_from("<I", data, offset(names_rva) + 4 * index)[0])
            name = data[name_offset:data.index(b"\0", name_offset)].decode("latin-1")
            names[name] = ordinal_base + struct.unpack_from("<H", data, offset(ordinals_rva) + 2 * index)[0]
    return {os.path.basename(path): names}


def read_exports(path):
    if open(path, "rb").read(2) == b"MZ":
        return dll_exports(path)
    return library_imports(path)


def write_lists(imports, folder):
    os.makedirs(folder, exist_ok=True)
    for dll, names in sorted(imports.items()):
        stem = os.path.splitext(dll)[0].lower()
        with open(os.path.join(folder, stem + ".txt"), "w") as output:
            output.write("".join(name + "\n" for name in sorted(names)))
        print("%s: %d" % (stem, len(names)))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="List the functions COFF import libraries import, or DLLs export, by DLL")
    parser.add_argument("libraries", nargs="+", help="import libraries (.lib; others are skipped) or DLLs")
    parser.add_argument("--output", help="write <dll>.txt export lists into this folder instead of printing")
    parser.add_argument("--ordinals", action="store_true", help="show ordinal imports' ordinals")
    arguments = parser.parse_args()
    imports = {}
    for path in arguments.libraries:
        try:
            for dll, names in read_exports(path).items():
                imports.setdefault(dll, {}).update(names)
        except ValueError as error:
            sys.exit("mkexports: %s: %s" % (path, error))
    if arguments.output:
        write_lists(imports, arguments.output)
    else:
        for dll, names in sorted(imports.items()):
            for name in sorted(names):
                ordinal = names[name]
                suffix = " @%d" % ordinal if arguments.ordinals and ordinal is not None else ""
                print("%s %s%s" % (dll, name, suffix))

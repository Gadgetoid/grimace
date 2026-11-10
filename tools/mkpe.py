"""
Linked MIPS, SH3, x86 or ARM ELF (--emit-relocs) to Windows CE PE32.

- Machine 0x166 (MIPS little endian), 0x1A2 (SH3), 0x14C (x86) or 0x1C0 (ARM), from the ELF's machine. Subsystem 9
  (Windows CE GUI), version from --ce-version (1.0, 2.0, 3.0 or 6.0), as Microsoft's linker writes for
  /subsystem:windowsce,<version>.
- Image base 0x10000, headers 0x400, file alignment 0x200.
- Sections 4 KB aligned: the R3910 has 4 KB pages only.
- Sections: .text, .rdata, .data, .idata, then .edata (DLL), .rsrc (icon, .res files), .reloc.
- Imports by name, hint 0. Slots are __imp_<name> symbols, one descriptor per run of
  slots from the same DLL (__grimace_import$<dll>$<name>, else COREDLL.dll).
- EXE: IAT at the start of .data. DLL: IAT in .idata, after descriptors and lookup tables.
- ELF relocations become base relocations: R_MIPS_32 HIGHLOW, R_MIPS_26 JMPADDR,
  R_MIPS_HI16 HIGHADJ, R_MIPS_LO16 LOW; R_SH_DIR32 HIGHLOW, and SH PC-relative and
  relaxation relocations none; R_386_32 HIGHLOW, and R_386_PC32 and R_386_PLT32 none; R_ARM_ABS32 and
  R_ARM_TARGET1 HIGHLOW, and ARM PC-relative relocations none.
"""
import argparse
import struct

IMAGE_BASE = 0x10000
SECTION_ALIGNMENT = 0x1000
FILE_ALIGNMENT = 0x200
HEADERS_SIZE = 0x400
DEFAULT_DLL = "COREDLL.dll"
IMPORT_PREFIX = "__imp_"
IMPORT_MARKER = "__grimace_import$"

CODE = 0x60000020
READ_ONLY = 0x40000040
READ_WRITE = 0xC0000040
SHF_ALLOC = 0x2
SHT_RELA = 4
SHT_REL = 9
EM_MIPS = 8
EM_SH = 42
EM_386 = 3
EM_ARM = 40
PE_MACHINES = {EM_MIPS: 0x166, EM_SH: 0x1A2, EM_386: 0x14C, EM_ARM: 0x1C0}
R_SH_DIR32 = 1
R_386_32 = 1
X86_POSITION_INDEPENDENT = {2, 4}
SH_POSITION_INDEPENDENT = set(range(2, 10)) | set(range(25, 33))
ARM_ABSOLUTE = {2, 38}
ARM_POSITION_INDEPENDENT = {0, 1, 3, 4, 28, 29, 40, 42}
RT_ICON = 3
RT_GROUP_ICON = 14
DEFAULT_LANGUAGE = 0x409
IMAGE_SUBSYSTEM_WINDOWS_CE_GUI = 9


def align(value, alignment):
    return (value + alignment - 1) // alignment * alignment


def read_elf(path):
    data = open(path, "rb").read()
    section_offset = struct.unpack_from("<I", data, 0x20)[0]
    entry_size, count, names_index = struct.unpack_from("<HHH", data, 0x2E)
    headers = [struct.unpack_from("<IIIIIIIIII", data, section_offset + entry_size * index) for index in range(count)]
    names_offset = headers[names_index][4]

    def name_at(table_offset, offset):
        end = data.index(b"\0", table_offset + offset)
        return data[table_offset + offset:end].decode()

    sections = {}
    symbols = {}
    for header in headers:
        name = name_at(names_offset, header[0])
        sections[name] = header
    symbol_table = sections[".symtab"]
    string_offset = headers[symbol_table[6]][4]
    for position in range(symbol_table[4], symbol_table[4] + symbol_table[5], 16):
        name_offset, value, _, _, _, _ = struct.unpack_from("<IIIBBH", data, position)
        if name_offset:
            symbols[name_at(string_offset, name_offset)] = value
    entry = struct.unpack_from("<I", data, 0x18)[0]
    return data, sections, symbols, entry


def elf_machine(data):
    machine = struct.unpack_from("<H", data, 0x12)[0]
    if machine not in PE_MACHINES:
        raise ValueError("ELF machine %d is not MIPS, SH, x86 or ARM" % machine)
    return machine


def read_sh_relocations(data, sections):
    found = []
    for name, header in sections.items():
        target = sections.get(name[len(".rela"):])
        if header[1] != SHT_RELA or not target or not target[2] & SHF_ALLOC:
            continue
        for position in range(0, header[5], 12):
            offset, info = struct.unpack_from("<II", data, header[4] + position)
            kind = info & 0xFF
            if kind == R_SH_DIR32:
                found.append((3, offset, None))
            elif kind and kind not in SH_POSITION_INDEPENDENT:
                raise ValueError("relocation type %d at %x" % (kind, offset))
    return found


def read_x86_relocations(data, sections):
    found = []
    for name, header in sections.items():
        target = sections.get(name[len(".rel"):])
        if header[1] != SHT_REL or not target or not target[2] & SHF_ALLOC:
            continue
        for position in range(0, header[5], 8):
            offset, info = struct.unpack_from("<II", data, header[4] + position)
            kind = info & 0xFF
            if kind == R_386_32:
                found.append((3, offset, None))
            elif kind and kind not in X86_POSITION_INDEPENDENT:
                raise ValueError("relocation type %d at %x" % (kind, offset))
    return found


def read_arm_relocations(data, sections):
    found = []
    for name, header in sections.items():
        target = sections.get(name[len(".rel"):])
        if header[1] != SHT_REL or not target or not target[2] & SHF_ALLOC:
            continue
        for position in range(0, header[5], 8):
            offset, info = struct.unpack_from("<II", data, header[4] + position)
            kind = info & 0xFF
            if kind in ARM_ABSOLUTE:
                found.append((3, offset, None))
            elif kind not in ARM_POSITION_INDEPENDENT:
                raise ValueError("relocation type %d at %x" % (kind, offset))
    return found


def read_relocations(data, sections):
    if elf_machine(data) == EM_SH:
        return read_sh_relocations(data, sections)
    if elf_machine(data) == EM_386:
        return read_x86_relocations(data, sections)
    if elf_machine(data) == EM_ARM:
        return read_arm_relocations(data, sections)
    found = []
    for name, header in sections.items():
        target = sections.get(name[len(".rel"):])
        if header[1] != SHT_REL or not target or not target[2] & SHF_ALLOC:
            continue
        entries = [struct.unpack_from("<II", data, header[4] + position) for position in range(0, header[5], 8)]
        index = 0
        while index < len(entries):
            offset, info = entries[index]
            kind = info & 0xFF
            if kind == 2:
                found.append((3, offset, None))
            elif kind == 4:
                found.append((5, offset, None))
            elif kind == 5:
                pair = index + 1
                while entries[pair][1] & 0xFF != 6:
                    pair += 1
                found.append((4, offset, entries[pair][0]))
            elif kind == 6:
                found.append((2, offset, None))
            elif kind:
                raise ValueError("relocation type %d at %x" % (kind, offset))
            index += 1
    return found


def encode_relocations(relocations, read_word):
    pages = {}
    for kind, va, low_site in relocations:
        rva = va - IMAGE_BASE
        pages.setdefault(rva & ~(SECTION_ALIGNMENT - 1), []).append((rva, kind, low_site))
    output = bytearray()
    for page in sorted(pages):
        entries = []
        for rva, kind, low_site in sorted(pages[page]):
            entries.append((kind << 12) | (rva - page))
            if kind == 4:
                high = read_word(IMAGE_BASE + rva) & 0xFFFF
                low = read_word(low_site) & 0xFFFF
                full = ((high << 16) + (low - 0x10000 if low & 0x8000 else low)) & 0xFFFFFFFF
                entries.append(full & 0xFFFF)
        if len(entries) % 2:
            entries.append(0)
        output += struct.pack("<II", page, 8 + 2 * len(entries)) + struct.pack("<%dH" % len(entries), *entries)
    return bytes(output)


def section_bytes(data, header):
    kind, address, offset, size = header[1], header[3], header[4], header[5]
    return address, bytes(size) if kind == 8 else data[offset:offset + size]


def export_symbol(export, symbols):
    name, _, symbol = export.partition("=")
    symbol = symbol or name
    if symbol not in symbols:
        raise ValueError("export %s: no symbol %s" % (name, symbol))
    return name, symbols[symbol]


def import_runs(symbols):
    markers = {}
    for name, value in symbols.items():
        if name.startswith(IMPORT_MARKER):
            markers[value] = name[len(IMPORT_MARKER):].split("$")[0]
    slots = sorted((value, name[len(IMPORT_PREFIX):]) for name, value in symbols.items() if name.startswith(IMPORT_PREFIX))
    if not slots:
        raise ValueError("the program imports nothing from any DLL; call at least one function from coredll or another DLL")
    runs = []
    for index, (value, name) in enumerate(slots):
        if value != slots[0][0] + 4 * index:
            raise ValueError("import slots are not contiguous")
        dll = markers.get(value, DEFAULT_DLL)
        if runs and runs[-1][0] == dll:
            runs[-1][1].append((value, name))
        else:
            runs.append((dll, [(value, name)]))
    return runs


def read_exports(arguments):
    exports = []
    if arguments.exports:
        exports += arguments.exports.split(",")
    if arguments.exports_file:
        exports += [line.strip() for line in open(arguments.exports_file) if line.strip()]
    return exports


def build_exports(exports, symbols, dll_name, export_rva):
    resolved = dict(export_symbol(export, symbols) for export in exports)
    names = sorted(resolved)
    function_rvas = [resolved[name] - IMAGE_BASE for name in names]
    directory_size = 40
    functions_rva = export_rva + directory_size
    names_rva = functions_rva + 4 * len(names)
    ordinals_rva = names_rva + 4 * len(names)
    strings_rva = ordinals_rva + 2 * len(names)
    strings = bytearray()
    name_rvas = []
    for name in names:
        name_rvas.append(strings_rva + len(strings))
        strings += name.encode() + b"\0"
    dll_name_rva = strings_rva + len(strings)
    strings += dll_name.encode() + b"\0"
    table = struct.pack("<IIHHIIIIIII", 0, 0, 0, 0, dll_name_rva, 1, len(names), len(names), functions_rva, names_rva, ordinals_rva)
    table += struct.pack("<%dI" % len(names), *function_rvas)
    table += struct.pack("<%dI" % len(names), *name_rvas)
    table += struct.pack("<%dH" % len(names), *range(len(names)))
    return bytes(table + strings)


def icon_resources(icon_path):
    data = open(icon_path, "rb").read()
    _, _, count = struct.unpack_from("<HHH", data, 0)
    resources = []
    group = struct.pack("<HHH", 0, 1, count)
    for index in range(count):
        width, height, colours, _, planes, bits, size, offset = struct.unpack_from("<BBBBHHII", data, 6 + 16 * index)
        resources.append((RT_ICON, index + 1, DEFAULT_LANGUAGE, data[offset:offset + size]))
        group += struct.pack("<BBBBHHIH", width, height, colours, 0, planes, bits, size, index + 1)
    resources.append((RT_GROUP_ICON, 1, DEFAULT_LANGUAGE, group))
    return resources


def read_resource_name(data, offset):
    if struct.unpack_from("<H", data, offset)[0] == 0xFFFF:
        return struct.unpack_from("<H", data, offset + 2)[0], offset + 4
    end = offset
    while struct.unpack_from("<H", data, end)[0]:
        end += 2
    return data[offset:end].decode("utf-16-le").upper(), end + 2


def compiled_resources(res_path):
    data = open(res_path, "rb").read()
    resources = []
    offset = 0
    while offset < len(data):
        data_size, header_size = struct.unpack_from("<II", data, offset)
        kind, position = read_resource_name(data, offset + 8)
        name, position = read_resource_name(data, position)
        position = align(position, 4)
        language = struct.unpack_from("<H", data, position + 6)[0]
        body = data[offset + header_size:offset + header_size + data_size]
        if kind or data_size:
            resources.append((kind, name, language, body))
        offset = align(offset + header_size + data_size, 4)
    return resources


def build_resources(resources, section_rva):
    tree = {}
    for kind, name, language, body in resources:
        languages = tree.setdefault(kind, {}).setdefault(name, {})
        if language in languages:
            raise ValueError("duplicate resource %r %r" % (kind, name))
        languages[language] = body

    def ordered(keys):
        return sorted((key for key in keys if isinstance(key, str))) + sorted((key for key in keys if isinstance(key, int)))

    directories = []
    leaves = []
    pending = [(tree, 0)]
    while pending:
        node, depth = pending.pop(0)
        entries = []
        directories.append(entries)
        for key in ordered(node):
            if depth == 2:
                leaves.append(node[key])
                entries.append((key, "leaf", len(leaves) - 1))
            else:
                pending.append((node[key], depth + 1))
                entries.append((key, "directory", len(directories) + len(pending) - 1))
    directory_offsets = []
    position = 0
    for entries in directories:
        directory_offsets.append(position)
        position += 16 + 8 * len(entries)
    names = ordered({key for entries in directories for key, _, _ in entries if isinstance(key, str)})
    name_offsets = {}
    for name in names:
        name_offsets[name] = position
        position += 2 + 2 * len(name)
    position = align(position, 4)
    data_entries_offset = position
    position += 16 * len(leaves)
    blob_offsets = []
    for body in leaves:
        blob_offsets.append(position)
        position = align(position + len(body), 4)

    output = bytearray()
    for entries in directories:
        named = sum(1 for key, _, _ in entries if isinstance(key, str))
        output += struct.pack("<IIHHHH", 0, 0, 0, 0, named, len(entries) - named)
        for key, kind, index in entries:
            identifier = 0x80000000 | name_offsets[key] if isinstance(key, str) else key
            target = 0x80000000 | directory_offsets[index] if kind == "directory" else data_entries_offset + 16 * index
            output += struct.pack("<II", identifier, target)
    for name in names:
        output += struct.pack("<H", len(name)) + name.encode("utf-16-le")
    output += bytes(data_entries_offset - len(output))
    for index, body in enumerate(leaves):
        output += struct.pack("<IIII", section_rva + blob_offsets[index], len(body), 0, 0)
    for index, body in enumerate(leaves):
        output += bytes(blob_offsets[index] - len(output)) + body
    return bytes(output)


def subsystem_version(ce_version):
    major, _, minor = ce_version.partition(".")
    return int(major), int(minor or 0)


def build(elf_path, output_path, ce_version, exports=None, dll_name=None, resources=None):
    data, sections, symbols, entry = read_elf(elf_path)
    text_va, text = section_bytes(data, sections[".text"])
    if ".rdata" in sections:
        rdata_va, rdata = section_bytes(data, sections[".rdata"])
    else:
        rdata_va, rdata = None, b""
    data_va, writable = section_bytes(data, sections[".data"])
    writable = bytearray(writable)
    if ".got" in sections:
        got_va, got = section_bytes(data, sections[".got"])
        writable += bytes(got_va - data_va - len(writable)) + got

    runs = import_runs(symbols)
    iat_va = runs[0][1][0][0]
    iat_rva = iat_va - IMAGE_BASE
    import_count = sum(len(slots) for _, slots in runs)

    hint_names = bytearray()
    name_offsets = []
    for _, slots in runs:
        for _, name in slots:
            name_offsets.append(len(hint_names))
            hint_names += struct.pack("<H", 0) + name.encode() + b"\0"
            if len(hint_names) % 2:
                hint_names += b"\0"
    dll_name_offsets = {}
    for dll, _ in runs:
        if dll not in dll_name_offsets:
            dll_name_offsets[dll] = len(hint_names)
            hint_names += dll.encode() + b"\0"
    descriptor_size = 20 * (len(runs) + 1)
    lookup_size = 4 * (import_count + len(runs))
    if exports:
        idata_va = sections[".idata"][3]
        idata_rva = idata_va - IMAGE_BASE
        lookup_rva = idata_rva + descriptor_size
        if lookup_rva + lookup_size > iat_rva:
            raise ValueError("imports need 0x%x bytes before the IAT, link with --defsym=GRIMACE_IMPORT_RESERVE=<more>" % (descriptor_size + lookup_size))
        names_rva = iat_rva + 4 * (import_count + 1)
    else:
        idata_va = align(data_va + len(writable), SECTION_ALIGNMENT)
        idata_rva = idata_va - IMAGE_BASE
        lookup_rva = idata_rva + descriptor_size
        names_rva = lookup_rva + lookup_size
    name_rvas = [names_rva + offset for offset in name_offsets]
    idata = bytearray()
    lookup = bytearray()
    position = 0
    for dll, slots in runs:
        run_name_rvas = name_rvas[position:position + len(slots)]
        idata += struct.pack("<IIIII", lookup_rva + len(lookup), 0, 0, names_rva + dll_name_offsets[dll], iat_rva + 4 * position)
        lookup += struct.pack("<%dI" % (len(slots) + 1), *run_name_rvas, 0)
        position += len(slots)
    idata += bytes(20)
    idata += lookup
    if exports:
        idata += bytes(iat_rva - idata_rva - len(idata))
        idata += struct.pack("<%dI" % (import_count + 1), *name_rvas, 0)
    idata += hint_names
    if not exports:
        for index, rva in enumerate(name_rvas):
            struct.pack_into("<I", writable, iat_va - data_va + 4 * index, rva)

    def read_word(va):
        for base, contents in ((text_va, text), (rdata_va or 0, rdata), (data_va, writable), (idata_va, idata)):
            if base <= va < base + len(contents):
                return struct.unpack_from("<I", contents, va - base)[0]
        raise ValueError("no word at %x" % va)

    relocations = encode_relocations(read_relocations(data, sections), read_word)
    code_flags = CODE | 0x80000000 if exports else CODE
    read_only_flags = READ_WRITE if exports else READ_ONLY
    layout = [
        (b".text", text_va, text, code_flags),
        *([(b".rdata", rdata_va, rdata, read_only_flags)] if rdata else []),
        (b".data", data_va, bytes(writable), READ_WRITE),
        (b".idata", idata_va, bytes(idata), READ_WRITE),
    ]
    next_va = align(idata_va + len(idata), SECTION_ALIGNMENT)
    export_table = b""
    if exports:
        export_table = build_exports(exports, symbols, dll_name, next_va - IMAGE_BASE)
        layout.append((b".edata", next_va, export_table, read_only_flags))
        export_va = next_va
        next_va = align(next_va + len(export_table), SECTION_ALIGNMENT)
    if resources:
        resource_section = build_resources(resources, next_va - IMAGE_BASE)
        layout.append((b".rsrc", next_va, resource_section, READ_ONLY))
        resource_va = next_va
        next_va = align(next_va + len(resource_section), SECTION_ALIGNMENT)
    reloc_va = next_va
    layout.append((b".reloc", reloc_va, relocations, 0x42000040))
    file_position = HEADERS_SIZE
    section_headers = bytearray()
    body = bytearray()
    for name, va, contents, flags in layout:
        raw_size = align(len(contents), FILE_ALIGNMENT)
        section_headers += struct.pack("<8sIIIIIIHHI", name, len(contents), va - IMAGE_BASE, raw_size, file_position, 0, 0, 0, 0, flags)
        body += contents + bytes(raw_size - len(contents))
        file_position += raw_size
    image_size = align(reloc_va + len(relocations), SECTION_ALIGNMENT) - IMAGE_BASE

    code_size = align(len(text), FILE_ALIGNMENT)
    initialized_size = sum(align(len(contents), FILE_ALIGNMENT) for _, _, contents, _ in layout[1:])
    directories = [(0, 0)] * 16
    directories[1] = (idata_rva, descriptor_size)
    if exports:
        directories[0] = (export_va - IMAGE_BASE, len(export_table))
    if resources:
        directories[2] = (resource_va - IMAGE_BASE, len(resource_section))
    directories[5] = (reloc_va - IMAGE_BASE, len(relocations))
    directories[12] = (iat_rva, 4 * import_count)
    optional = struct.pack(
        "<HBBIIIIIIIIIHHHHHHIIIIHHIIIIII",
        0x10B, 3, 0, code_size, initialized_size, 0,
        entry - IMAGE_BASE, text_va - IMAGE_BASE, (rdata_va or data_va) - IMAGE_BASE,
        IMAGE_BASE, SECTION_ALIGNMENT, FILE_ALIGNMENT,
        4, 0, 0, 0, *subsystem_version(ce_version), 0,
        image_size, HEADERS_SIZE, 0, IMAGE_SUBSYSTEM_WINDOWS_CE_GUI, 0,
        0x10000, 0x1000, 0x100000, 0x1000, 0, 16,
    ) + b"".join(struct.pack("<II", *directory) for directory in directories)

    dos = bytearray(0x80)
    dos[0:0x20] = bytes.fromhex("4d5a90000300000004000000ffff0000b8000000000000004000000000000000")
    struct.pack_into("<I", dos, 0x3C, 0x80)
    file_header = struct.pack("<HHIIIHH", PE_MACHINES[elf_machine(data)], len(layout), 0, 0, 0, len(optional), 0x210E if exports else 0x010E)
    headers = bytes(dos) + b"PE\0\0" + file_header + optional + bytes(section_headers)
    if len(headers) > HEADERS_SIZE:
        raise ValueError("headers too large")
    open(output_path, "wb").write(headers + bytes(HEADERS_SIZE - len(headers)) + bytes(body))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert a linked MIPS, SH3, x86 or ARM ELF into a Windows CE PE")
    parser.add_argument("elf")
    parser.add_argument("output")
    parser.add_argument("--ce-version", required=True, help="Windows CE version the program targets, e.g. 1, 2, 3 or 6")
    parser.add_argument("--exports", help="comma-separated exports, NAME or NAME=SYMBOL; makes a DLL")
    parser.add_argument("--exports-file", help="exports, one per line; makes a DLL")
    parser.add_argument("--icon")
    parser.add_argument("--resources", action="append", default=[], help="compiled resources (.res)")
    arguments = parser.parse_args()
    exports = read_exports(arguments)
    dll_name = arguments.output.replace("\\", "/").split("/")[-1]
    resources = icon_resources(arguments.icon) if arguments.icon else []
    for res_path in arguments.resources:
        resources += compiled_resources(res_path)
    build(arguments.elf, arguments.output, arguments.ce_version, exports or None, dll_name, resources)

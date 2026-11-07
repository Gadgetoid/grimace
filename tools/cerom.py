"""
Read a Windows CE 3.0 ROM image: its modules, files and DLL export tables.

The image is a flat dump of ROM starting at the address in ROMHDR.physfirst, with the
"ECEC" signature at 0x40 followed by the virtual address of ROMHDR.
"""
import argparse
import os
import struct

SIGNATURE_OFFSET = 0x40
ROMHDR_SIZE = 84
TOC_ENTRY_SIZE = 32
FILES_ENTRY_SIZE = 28
E32_UNIT_OFFSET = 32
O32_SIZE = 24
EXPORT_UNIT = 0
IMAGE_SCN_COMPRESSED = 0x2000


class Rom:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        if self.data[SIGNATURE_OFFSET:SIGNATURE_OFFSET + 4] != b"ECEC":
            raise ValueError("%s has no ECEC signature at 0x40" % path)
        self.romhdr_address = struct.unpack_from("<I", self.data, SIGNATURE_OFFSET + 4)[0]
        self.base = self._find_base()
        self.header = self._romhdr_fields(self.base)
        self.modules = [self._module(index) for index in range(self.header["nummods"])]

    def _find_base(self):
        candidate = self.romhdr_address & ~0xFFFF
        while candidate > self.romhdr_address - len(self.data):
            offset = self.romhdr_address - candidate
            if offset + ROMHDR_SIZE <= len(self.data):
                physfirst = struct.unpack_from("<I", self.data, offset + 8)[0]
                if physfirst == candidate:
                    return candidate
            candidate -= 0x10000
        raise ValueError("no ROMHDR whose physfirst matches the image")

    def _romhdr_fields(self, base):
        names = ["dllfirst", "dlllast", "physfirst", "physlast", "nummods", "ram_start", "ram_free", "ram_end",
                 "copy_entries", "copy_offset", "profile_length", "profile_offset", "numfiles", "kernel_flags",
                 "fs_ram_percent", "drivglob_start", "drivglob_length"]
        offset = self.romhdr_address - base
        values = struct.unpack_from("<17I", self.data, offset)
        fields = dict(zip(names, values))
        fields["cpu_type"], fields["misc_flags"] = struct.unpack_from("<HH", self.data, offset + 68)
        return fields

    def contains(self, address, length=1):
        return self.base <= address and address + length <= self.base + len(self.data)

    def word(self, address):
        return struct.unpack_from("<I", self.data, address - self.base)[0]

    def bytes_at(self, address, length):
        return self.data[address - self.base:address - self.base + length]

    def string(self, address):
        offset = address - self.base
        return self.data[offset:self.data.index(b"\0", offset)].decode("latin-1")

    def _module(self, index):
        offset = self.romhdr_address - self.base + ROMHDR_SIZE + TOC_ENTRY_SIZE * index
        attributes, _, _, size, name, e32, o32, load = struct.unpack_from("<8I", self.data, offset)
        objects, flags, entry, vbase = struct.unpack_from("<HHII", self.data, e32 - self.base)
        units = struct.unpack_from("<18I", self.data, e32 - self.base + E32_UNIT_OFFSET)
        sections = []
        for section in range(objects):
            vsize, rva, psize, dataptr, realaddr, section_flags = struct.unpack_from(
                "<6I", self.data, o32 - self.base + O32_SIZE * section)
            sections.append({"vsize": vsize, "rva": rva, "psize": psize, "dataptr": dataptr,
                             "realaddr": realaddr, "flags": section_flags})
        return {"name": self.string(name), "size": size, "attributes": attributes, "load": load,
                "image_flags": flags, "entry": entry, "vbase": vbase,
                "units": [(units[2 * unit], units[2 * unit + 1]) for unit in range(9)], "sections": sections}

    def module(self, name):
        for module in self.modules:
            if module["name"].lower() == name.lower():
                return module
        raise KeyError(name)

    def module_bytes(self, module, rva, length):
        for section in module["sections"]:
            if section["rva"] <= rva and rva + length <= section["rva"] + max(section["vsize"], section["psize"]):
                if section["flags"] & IMAGE_SCN_COMPRESSED:
                    raise ValueError("%s: RVA %x is in a compressed section" % (module["name"], rva))
                if rva + length > section["rva"] + section["psize"]:
                    raise ValueError("%s: RVA %x is past the section's ROM data" % (module["name"], rva))
                return self.bytes_at(section["dataptr"] + rva - section["rva"], length)
        raise ValueError("%s: RVA %x is in no section" % (module["name"], rva))

    def exports(self, module):
        rva, size = module["units"][EXPORT_UNIT]
        if not size:
            return {}
        directory = self.module_bytes(module, rva, 40)
        _, _, _, _, _, ordinal_base, function_count, name_count, functions, names, ordinals = struct.unpack(
            "<IIHHIIIIIII", directory)
        function_rvas = struct.unpack("<%dI" % function_count, self.module_bytes(module, functions, 4 * function_count))
        name_rvas = struct.unpack("<%dI" % name_count, self.module_bytes(module, names, 4 * name_count))
        name_ordinals = struct.unpack("<%dH" % name_count, self.module_bytes(module, ordinals, 2 * name_count))
        found = {}
        for name_rva, index in zip(name_rvas, name_ordinals):
            name = bytearray()
            while True:
                character = self.module_bytes(module, name_rva + len(name), 1)
                if character == b"\0":
                    break
                name += character
            found[name.decode("latin-1")] = (ordinal_base + index, function_rvas[index])
        return found


def main():
    parser = argparse.ArgumentParser(description="List a Windows CE 3.0 ROM's modules or write its DLLs' export lists")
    parser.add_argument("rom")
    parser.add_argument("--exports", metavar="FOLDER", help="write <dll>.txt, one exported name per line, for each DLL")
    parser.add_argument("--dll", action="append", default=[], help="only these DLLs (default: all)")
    arguments = parser.parse_args()
    rom = Rom(arguments.rom)
    if not arguments.exports:
        print("CPU %#x, %d modules, %d files, ROM %08x-%08x" % (
            rom.header["cpu_type"], rom.header["nummods"], rom.header["numfiles"], rom.header["physfirst"],
            rom.header["physlast"]))
        for module in rom.modules:
            try:
                exports = "%d exports" % len(rom.exports(module))
            except ValueError as error:
                exports = str(error)
            print("%-20s %08x %8d %s" % (module["name"], module["vbase"], module["size"], exports))
        return
    os.makedirs(arguments.exports, exist_ok=True)
    wanted = {name.lower() for name in arguments.dll}
    for module in rom.modules:
        name = module["name"].lower()
        if not name.endswith(".dll") or (wanted and name not in wanted):
            continue
        exports = rom.exports(module)
        if not exports:
            continue
        with open(os.path.join(arguments.exports, name[:-4] + ".txt"), "w") as output:
            output.writelines(export + "\n" for export in sorted(exports))


if __name__ == "__main__":
    main()

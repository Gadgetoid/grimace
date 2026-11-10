"""
Check every program and DLL in a build folder imports only what the target's lists export directly: for a target pinned to
a device, that device's ROM. A loader refuses a program whose imports its ROM lacks.
"""
import argparse
import glob
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools"))
import manifests


def section_offset(data, sections, rva):
    for virtual_address, virtual_size, raw_offset, raw_size in sections:
        if virtual_address <= rva < virtual_address + max(virtual_size, raw_size):
            return raw_offset + rva - virtual_address
    raise ValueError("RVA %x is in no section" % rva)


def string_at(data, offset):
    return data[offset:data.index(b"\0", offset)].decode("latin-1")


def imports(path):
    data = open(path, "rb").read()
    header = struct.unpack_from("<I", data, 0x3C)[0]
    section_count = struct.unpack_from("<H", data, header + 6)[0]
    optional_size = struct.unpack_from("<H", data, header + 20)[0]
    optional = header + 24
    import_rva = struct.unpack_from("<I", data, optional + 96 + 8)[0]
    sections = []
    for index in range(section_count):
        entry = optional + optional_size + 40 * index
        virtual_size, virtual_address, raw_size, raw_offset = struct.unpack_from("<IIII", data, entry + 8)
        sections.append((virtual_address, virtual_size, raw_offset, raw_size))
    found = []
    if not import_rva:
        return found
    descriptor = section_offset(data, sections, import_rva)
    while True:
        lookup, _, _, name, thunks = struct.unpack_from("<IIIII", data, descriptor)
        if not name:
            break
        dll = string_at(data, section_offset(data, sections, name))
        entry = section_offset(data, sections, lookup or thunks)
        while True:
            value = struct.unpack_from("<I", data, entry)[0]
            if not value:
                break
            if value & 0x80000000:
                found.append((dll, "#%d" % (value & 0xFFFF)))
            else:
                found.append((dll, string_at(data, section_offset(data, sections, value) + 2)))
            entry += 4
        descriptor += 20
    return found


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Check a build's programs and DLLs import only what the target's lists export directly")
    parser.add_argument("build")
    parser.add_argument("--arch", required=True)
    parser.add_argument("--version", required=True, choices=sorted(manifests.WIN32_WCE))
    parser.add_argument("--platform")
    parser.add_argument("--device")
    arguments = parser.parse_args()
    target = manifests.Target(arguments.arch, manifests.WIN32_WCE[arguments.version], arguments.platform, arguments.device)
    allowed = {dll.lower(): direct for dll, (direct, lazy) in manifests.imports(target).items()}
    problems = 0
    checked = 0
    for path in sorted(glob.glob(os.path.join(arguments.build, "**", "*.*"), recursive=True)):
        if not path.lower().endswith((".exe", ".dll", ".cpl")) or "CMakeFiles" in path:
            continue
        for dll, name in imports(path):
            checked += 1
            if name not in allowed.get(dll.lower().rsplit(".", 1)[0], set()):
                print("%s: %s imports %s, which %s doesn't export" % (os.path.relpath(path, arguments.build), dll, name, target.label()))
                problems += 1
    print("check-imports: %s, %d imports checked, %d problems" % (target.label(), checked, problems))
    sys.exit(1 if problems or not checked else 0)

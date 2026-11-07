"""
The runtime's sources: runtime/*.c and runtime/c99 for every target, and runtime/libc, the C library that coredll lacks below
Windows CE 3.0, for the targets that need it.

A runtime/libc file is built for a target unless the target imports every function it defines directly, so a ROM's own
function is used where every device the target covers has it. A file named <name>-<arch>.S or .c is only for that architecture.
"""
import argparse
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RUNTIME = os.path.join(ROOT, "runtime")
ARCHITECTURES = {"mips", "sh3", "x86", "arm"}
C_DEFINITION = re.compile(r"^([A-Za-z_][\w \t*]*?)\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)
ASSEMBLY_DEFINITION = re.compile(r"^\s*\.globl\s+(\w+)", re.M)


def defined_functions(path):
    text = open(path, errors="replace").read()
    if path.endswith(".S"):
        return set(ASSEMBLY_DEFINITION.findall(text))
    return {name for prefix, name in C_DEFINITION.findall(text) if not prefix.lstrip().startswith("static") and name not in ("if", "while", "for", "switch")}


def architecture_of(path):
    stem = os.path.splitext(os.path.basename(path))[0]
    suffix = stem.rsplit("-", 1)[-1]
    return suffix if "-" in stem and suffix in ARCHITECTURES else None


def libc_files():
    return sorted(glob.glob(os.path.join(RUNTIME, "libc", "**", "*.c"), recursive=True) +
                  glob.glob(os.path.join(RUNTIME, "libc", "**", "*.S"), recursive=True))


def common_files():
    return sorted(glob.glob(os.path.join(RUNTIME, "c99", "*.c"))) + sorted(glob.glob(os.path.join(RUNTIME, "*.c")))


def libc_sources(arch, direct):
    sources = []
    for path in libc_files():
        if architecture_of(path) not in (None, arch):
            continue
        functions = defined_functions(path)
        if functions and functions <= direct:
            continue
        sources.append(path)
    return sources


def provided():
    """Every function the runtime can define for some target."""
    names = set()
    for path in common_files() + libc_files():
        names |= defined_functions(path)
    return names


def read_direct_imports(folder):
    names = set()
    for path in glob.glob(os.path.join(folder, "*.txt")):
        names.update(line.strip() for line in open(path) if line.strip())
    return names


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Write the runtime/libc sources a target needs, one per line")
    parser.add_argument("--arch", required=True, choices=sorted(ARCHITECTURES))
    parser.add_argument("--imports", required=True, help="folder of <dll>.txt direct import lists, from tools/manifests.py --output")
    parser.add_argument("--output", required=True)
    arguments = parser.parse_args()
    sources = libc_sources(arguments.arch, read_direct_imports(arguments.imports))
    with open(arguments.output, "w") as output:
        output.writelines(path + "\n" for path in sources)

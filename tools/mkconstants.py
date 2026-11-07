import argparse
import os
import re
import sys
import tempfile
from importlib.machinery import SourceFileLoader

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
check = SourceFileLoader("check_headers", os.path.join(ROOT, "tests", "check-headers.py")).load_module()
MIPS = check.ARCHITECTURES["mips"]
VERSIONS = [(1, "GRIMACE_CE == 1", None), (2, "GRIMACE_CE == 2", None), (101, "GRIMACE_WCE == 101", 1)]


SDK_HEADER_HOMES = {"types.h": "windef.h", "tchar.h": "winnt.h"}


def our_guard(header):
    header = SDK_HEADER_HOMES.get(header, header)
    for path in (os.path.join(ROOT, "include", "w32api", header), os.path.join(ROOT, "include", header)):
        if os.path.exists(path):
            match = re.search(r"#ifndef\s+(\w+)\s*\n\s*#define\s+\1\b", open(path).read())
            if match:
                return match.group(1)
    return None


def literal(value):
    if value < 0:
        return "(%d)" % value
    if value > 0x7FFFFFFF:
        return "0x%XU" % value
    if value >= 0x100:
        return "0x%X" % value
    return "%d" % value


def missing_constants(clang, reference, version, work):
    sdk_include = check.sdk_folder(reference, version, work)
    headers = [header for header in check.checked_headers(version) if os.path.exists(os.path.join(sdk_include, header))]
    our_headers = [header for header in headers if os.path.exists(os.path.join(ROOT, "include", header))]
    sdk = check.Side(clang, MIPS["target"], check.WIN32_WCE[version], [sdk_include], check.SDK_DEFINES + MIPS["sdk_defines"], headers)
    ours = check.Side(clang, MIPS["target"], check.WIN32_WCE[version], [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")], ["-DGRIMACE_NO_CONSTANTS"],
                      our_headers)
    candidates = {name: name for name in sdk.macros() if not name.startswith("_")}
    sdk_values = sdk.evaluate(candidates)
    our_macros = ours.macros()
    our_values = ours.evaluate({name: name for name in sdk_values if name in our_macros})
    where = check.defining_headers(sdk_include)
    found = {}
    for name, value in sdk_values.items():
        if name in our_values or name in our_macros or check.excluded_constant(name, where.get(name), check.exclusions(version)[1]):
            continue
        found.setdefault(where[name], {})[name] = value
    return found


C_WORDS = {"const", "volatile", "struct", "union", "enum", "unsigned", "signed", "char", "short", "int", "long", "float", "double", "void",
           "_Bool", "__attribute__", "__stdcall__", "stdcall"}


def missing_types(clang, reference, version, work):
    sdk_include = os.path.join(work, "ce%d" % version)
    headers = [header for header in check.checked_headers(version) if os.path.exists(os.path.join(sdk_include, header))]
    our_headers = [header for header in headers if os.path.exists(os.path.join(ROOT, "include", header))]
    sdk = check.Side(clang, MIPS["target"], check.WIN32_WCE[version], [sdk_include], check.SDK_DEFINES + MIPS["sdk_defines"], headers)
    ours = check.Side(clang, MIPS["target"], check.WIN32_WCE[version], [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")], ["-DGRIMACE_NO_TYPES"],
                      our_headers)
    sdk_tree = sdk.tree()
    where = check.type_headers(sdk_tree)
    our_names = set(ours.macros())
    for node in ours.tree()["inner"]:
        if node.get("kind") == "TypedefDecl":
            our_names.add(node["name"])
        elif node.get("kind") == "RecordDecl" and node.get("name"):
            our_names.add(node["name"])
    tag_names = {}
    for node in sdk_tree["inner"]:
        if node.get("kind") == "TypedefDecl":
            match = re.match(r"^(struct|union) (\w+)$", node["type"]["qualType"])
            if match:
                tag_names.setdefault(match.group(0), []).append(node["name"])
    candidates = []
    for node in sdk_tree["inner"]:
        if node.get("kind") != "TypedefDecl" or node.get("isImplicit") or node["name"] in our_names:
            continue
        name = node["name"]
        if where.get(name) in check.exclusions(version)[1] or check.exclusions(version)[2].match(name):
            continue
        spelled = re.sub(r"\b(struct|union) \w+\b",
                         lambda match: next((alias for alias in tag_names.get(match.group(0), []) if alias in our_names), match.group(0)),
                         node["type"]["qualType"])
        candidates.append((name, spelled))
    found = []
    progress = True
    while progress:
        progress = False
        remaining = []
        for name, spelled in candidates:
            referenced = set(re.findall(r"[A-Za-z_]\w*", spelled)) - C_WORDS
            if referenced <= our_names and ("(" not in spelled or "(*)" in spelled):
                found.append((where.get(name), name, spelled.replace("(*)", "(*%s)" % name, 1) if "(*)" in spelled else spelled))
                our_names.add(name)
                progress = True
            else:
                remaining.append((name, spelled))
        candidates = remaining
    unresolved = [name for name, _ in candidates]
    return found, sorted(set(unresolved))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Write include/grimace/constants.h and types.h: Windows CE 1.0, 1.01 and 2.0 SDK constants and types the vendored headers lack")
    parser.add_argument("--reference", default=os.environ.get("GRIMACE_REFERENCE"))
    parser.add_argument("--clang", default=os.environ.get("CLANG", "clang"))
    arguments = parser.parse_args()
    if not arguments.reference:
        sys.exit("mkconstants: set GRIMACE_REFERENCE or pass --reference")
    lines = []
    skipped = []
    with tempfile.TemporaryDirectory() as work:
        found_constants = {}
        for version, condition, base in VERSIONS:
            lines.append("#if %s" % condition)
            found_constants[version] = missing_constants(arguments.clang, os.path.expanduser(arguments.reference), version, work)
            for header, constants in sorted(found_constants[version].items()):
                if base:
                    constants = {name: value for name, value in constants.items() if name not in found_constants[base].get(header, {})}
                guard = our_guard(header)
                if not guard:
                    skipped.append("CE %s %s: %d" % (check.VERSION_NAMES[version], header, len(constants)))
                    continue
                if not constants:
                    continue
                lines.append("#ifdef %s" % guard)
                for name, value in sorted(constants.items()):
                    lines += ["#ifndef %s" % name, "#define %s %s" % (name, literal(value)), "#endif"]
                lines.append("#endif")
            lines += ["#endif", ""]
        type_lines = []
        found_types = {}
        for version, condition, base in VERSIONS:
            type_lines.append("#if %s" % condition)
            found, unresolved = missing_types(arguments.clang, os.path.expanduser(arguments.reference), version, work)
            found_types[version] = {name for _, name, _ in found}
            for header, name, spelled in found:
                if base and name in found_types[base]:
                    continue
                guard = our_guard(header) if header else None
                if not guard:
                    skipped.append("CE %s type %s in %s" % (check.VERSION_NAMES[version], name, header))
                    continue
                declaration = "typedef %s;" % spelled if "(*%s)" % name in spelled else "typedef %s %s;" % (spelled, name)
                type_lines += ["#ifdef %s" % guard, declaration, "#endif"]
            type_lines += ["#endif", ""]
            print("mkconstants: CE %s types needing definitions: %s" % (check.VERSION_NAMES[version], " ".join(unresolved)))
    with open(os.path.join(ROOT, "include", "grimace", "constants.h"), "w") as output:
        output.write("\n".join(lines + ["#include <grimace/constants-sdk.h>", ""]))
    with open(os.path.join(ROOT, "include", "grimace", "types.h"), "w") as output:
        output.write("\n".join(type_lines))
    print("mkconstants: %d constants" % sum(1 for line in lines if line.startswith("#define")))
    for line in skipped:
        print("mkconstants: no header of ours for %s" % line)

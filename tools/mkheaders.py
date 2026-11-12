import argparse
import functools
import glob
import json
import os
import re
import subprocess
import sys

import manifests
import runtime

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
UNWRAPPED = {"pshpack1.h", "pshpack2.h", "pshpack4.h", "pshpack8.h", "poppack.h", "README.w32api", "VENDOR.md"}
WINDOWS_EXTRAS = ["stdint.h", "mmsystem.h", "shellapi.h", "wchar.h", "stdlib.h", "string.h", "stdio.h", "math.h", "ctype.h", "setjmp.h", "time.h", "windbase.h"]
WINDOWS_VERSION_EXTRAS = [("GRIMACE_WCE == 101", "windowsx.h"), ("GRIMACE_CE >= 2 || GRIMACE_WCE == 101", "tchar.h")]
OWN_HEADERS = ["wchar.h", "stdlib.h", "string.h", "stdio.h", "math.h", "ctype.h", "setjmp.h", "time.h", "windbase.h", "tchar.h", "ceddk.h", "msgqueue.h",
               "pm.h", "winddi.h", "pkfuncs.h"]
DRIVER_HEADERS = ["ceddk.h", "msgqueue.h", "pm.h", "pkfuncs.h"]
MACRO_HEADERS = {"windowsx.h"}
MIPS_TARGET = ["--target=mipsel-unknown-none-elf", "-march=mips1", "-msoft-float"]
ARCHITECTURES = {"mips": {"target": MIPS_TARGET, "defines": []},
                 "sh3": {"target": MIPS_TARGET, "defines": ["-DSH3"]},
                 "x86": {"target": ["--target=i486-unknown-none-elf", "-malign-double"], "defines": []},
                 "arm": {"target": ["--target=armv4-unknown-none-wince", "-mcpu=strongarm", "-marm", "-mfloat-abi=soft"], "defines": ["-DARM", "-D_ARM_", "-DARMV4"]}}
ENTRY_POINTS = {"WinMain", "wWinMain", "DllMain", "DllEntryPoint"}
PREREQUISITES = {"mswsock.h": ["winsock.h"]}


def vendored():
    return sorted(name for name in os.listdir(os.path.join(ROOT, "include", "w32api")) if name not in UNWRAPPED)


def sdk_files():
    path = os.path.join(ROOT, "include", "grimace", "sdk", "groups.txt")
    if not os.path.exists(path):
        return {}
    return dict(line.split() for line in open(path) if line.strip())


def write_wrappers():
    sdk = sdk_files()
    for header in vendored():
        guard_name = "GRIMACE_WRAPPED_%s" % re.sub(r"\W", "_", header).upper()
        if header == "windows.h":
            includes = ["#include <%s>" % name for name in WINDOWS_EXTRAS]
            includes += ["#if %s\n#include <%s>\n#endif" % (condition, name) for condition, name in WINDOWS_VERSION_EXTRAS]
            extra = "\n#ifndef RC_INVOKED\n%s\n#endif\n#include <grimace/extras.h>" % "\n".join(includes)
            if "windows.h" in sdk:
                extra += "\n#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)\n#include <grimace/sdk/windows.h>\n#endif"
        elif os.path.exists(os.path.join(ROOT, "include", "grimace", "extras-" + header)):
            extra = "\n#include <grimace/extras-%s>" % header
        else:
            extra = ""
        if header != "windows.h" and header in sdk:
            extra += "\n#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)\n#include <grimace/sdk/%s>\n#endif" % sdk[header]
        windows = "" if header == "windows.h" else "#include <windows.h>\n"
        windows += "".join("#include <%s>\n" % prerequisite for prerequisite in PREREQUISITES.get(header, []))
        text = ("%s#ifndef %s\n#define %s\n\n#ifdef GRIMACE_INSIDE\n#include_next <%s>%s\n#else\n#define GRIMACE_INSIDE\n"
                "#include <grimace/begin.h>\n#include_next <%s>%s\n#include <grimace/end.h>\n#undef GRIMACE_INSIDE\n#endif\n\n#endif\n") % (
            windows, guard_name, guard_name, header, extra, header, extra)
        with open(os.path.join(ROOT, "include", header), "w") as wrapper:
            wrapper.write(text)


def declarations(clang, version, arch):
    source = "#include <windows.h>\n#include <winsock.h>\n#include <tchar.h>\n" + "".join("#include <%s>\n" % header for header in vendored() + DRIVER_HEADERS)
    command = [clang] + ARCHITECTURES[arch]["target"] + ["-fshort-wchar", "-ffreestanding", "-nostdlibinc",
               "-Wno-unknown-warning-option", "-Wno-experimental-option", "-fsyntax-only", "-Xclang", "-ast-dump=json", "-D_WIN32_WCE=%d" % version,
               "-DGRIMACE_ALL_DECLARATIONS", "-DGRIMACE_NO_CONSTANTS"] + ARCHITECTURES[arch]["defines"] + ["-I", os.path.join(ROOT, "include"), "-I", os.path.join(ROOT, "include", "w32api"), "-x", "c", "-"]
    tree = json.loads(subprocess.run(command, input=source, capture_output=True, text=True, check=True).stdout)
    macro_command = [argument for argument in command if argument not in ("-fsyntax-only", "-Xclang", "-ast-dump=json")] + ["-E", "-dM"]
    macros = set(re.findall(r"^#define (\w+)", subprocess.run(macro_command, input=source, capture_output=True, text=True, check=True).stdout, re.M))
    found = set()
    for node in tree["inner"]:
        if node.get("kind") != "FunctionDecl" or node.get("isImplicit") or node.get("storageClass") == "static":
            continue
        if any(child.get("kind") == "CompoundStmt" for child in node.get("inner", [])):
            continue
        if node["name"] not in macros:
            found.add(node["name"])
    return found


def header_paths():
    paths = sorted(path for path in glob.glob(os.path.join(ROOT, "include", "w32api", "*.h")) if os.path.basename(path) not in MACRO_HEADERS)
    paths += [os.path.join(ROOT, "include", name) for name in OWN_HEADERS]
    paths += sorted(glob.glob(os.path.join(ROOT, "include", "grimace", "extras*.h")))
    return paths


def declaring_headers():
    texts = {}
    for path in header_paths() + sorted(glob.glob(os.path.join(ROOT, "include", "grimace", "sdk", "*.h"))):
        texts[path] = open(path, errors="replace").read()

    @functools.cache
    def find(function):
        pattern = re.compile(r"\b%s\s*\)?\s*\(" % re.escape(function))
        for header, text in texts.items():
            if pattern.search(text):
                return header
        raise LookupError(function)
    return find


def exported(target):
    names = set(runtime.provided())
    for direct, lazy in manifests.imports(target).values():
        names |= direct | lazy
    return names


def lazy_imports(target):
    names = set()
    for direct, lazy in manifests.imports(target).values():
        names |= lazy
    return names - runtime.provided()


def unavailable_reason(target):
    if target.device:
        return "not in Windows CE %s on %s" % (manifests.VERSION_NAMES[target.version], target.device)
    return "not in Windows CE %s or later on %s" % (manifests.VERSION_NAMES[target.version], target.arch.upper())


@functools.cache
def guard(header):
    text = open(header).read()
    match = re.search(r"#ifndef\s+(\w+)\s*\n\s*#define\s+\1\b", text)
    return match.group(1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Write wrappers for the vendored w32api headers, and include/grimace/unavailable.h, aliases.h and "
                                     "lazy-imports.h from the export lists")
    parser.add_argument("--clang", default="clang")
    parser.add_argument("--report", help="write functions the export lists have that the headers don't declare to this file")
    arguments = parser.parse_args()
    write_wrappers()
    find_header = declaring_headers()
    lines = ["#if !defined(GRIMACE_CE)", "#error \"include windows.h first\"", "#endif", ""]
    alias_lines = lines + ["#ifdef __cplusplus", "extern \"C\" {", "#endif", ""]
    lazy_lines = ["#ifdef __cplusplus", "extern \"C\" {", "#endif", ""]
    report = []
    declared_by = {}
    for target in manifests.targets():
        key = (target.arch, target.version)
        if key not in declared_by:
            declared_by[key] = declarations(arguments.clang, target.version, target.arch)
        declared = declared_by[key]
        condition = "#if %s" % target.condition()
        exports = exported(target)
        aliases = sorted(function[:-1] for function in declared
                         if function.endswith("W") and function not in exports and function[:-1] in exports and function[:-1] not in declared)
        alias_lines.append(condition)
        aliases_by_guard = {}
        for function in aliases:
            aliases_by_guard.setdefault(guard(find_header(function + "W")), []).append(function)
        for header_guard in sorted(aliases_by_guard):
            alias_lines.append("#ifdef %s" % header_guard)
            for function in aliases_by_guard[header_guard]:
                alias_lines += ["#undef %s" % function, "extern __typeof__(%sW) %s;" % (function, function), "#undef %sW" % function,
                                "#define %sW %s" % (function, function)]
            alias_lines.append("#endif")
        alias_lines += ["#endif", ""]
        missing = sorted(set(declared) - exports - ENTRY_POINTS - {function + "W" for function in aliases})
        by_guard = {}
        for function in missing:
            by_guard.setdefault(guard(find_header(function)), []).append(function)
        lines.append(condition)
        for header_guard in sorted(by_guard):
            lines.append("#ifdef %s" % header_guard)
            for function in by_guard[header_guard]:
                lines.append('extern __typeof__(%s) %s __attribute__((unavailable("%s")));' % (function, function, unavailable_reason(target)))
            lines.append("#endif")
        lines.append("#endif")
        lines.append("")
        lazy = sorted(function for function in lazy_imports(target) - ENTRY_POINTS if function in declared or function in aliases)
        lazy_lines.append(condition)
        for function in lazy:
            lazy_lines += ["#define __grimace_lazy_%s 1" % function, "extern struct grimace_lazy_import __grimace_lazy_import_%s;" % function]
        lazy_lines += ["#endif", ""]
        undeclared = sorted(exports - set(declared))
        report.append("%s: %d declared, %d exported, %d lazy, %d declared but not exported, %d exported but not declared" %
                      (target.label(), len(declared), len(exports), len(lazy), len(missing), len(undeclared)))
        report.extend("  %s" % function for function in undeclared)
    with open(os.path.join(ROOT, "include", "grimace", "unavailable.h"), "w") as output:
        output.write("\n".join(lines))
    alias_lines += ["#ifdef __cplusplus", "}", "#endif", ""]
    with open(os.path.join(ROOT, "include", "grimace", "aliases.h"), "w") as output:
        output.write("\n".join(alias_lines))
    lazy_lines += ["#ifdef __cplusplus", "}", "#endif", ""]
    with open(os.path.join(ROOT, "include", "grimace", "lazy-imports.h"), "w") as output:
        output.write("\n".join(lazy_lines))
    if arguments.report:
        with open(arguments.report, "w") as output:
            output.write("\n".join(report) + "\n")
    print("\n".join(line for line in report if not line.startswith("  ")))

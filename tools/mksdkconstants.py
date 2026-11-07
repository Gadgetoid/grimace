import argparse
import os
import re
import sys
import tempfile
from importlib.machinery import SourceFileLoader

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
check = SourceFileLoader("check_headers", os.path.join(ROOT, "tests", "check-headers.py")).load_module()
ARM = check.ARCHITECTURES["arm"]
VERSIONS = [(3, "GRIMACE_CE == 3", None)]


SDK_HEADER_HOMES = {"types.h": "windef.h", "tchar.h": "winnt.h"}


def our_guard(header):
    header = SDK_HEADER_HOMES.get(header, header)
    for path in (os.path.join(ROOT, "include", "w32api", header), os.path.join(ROOT, "include", header)):
        if os.path.exists(path):
            content = re.search(r"#define\s+(\w+_CONTENT)\b", open(path).read())
            if content:
                return content.group(1)
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


SKIPPED_MACROS = re.compile(r"^(\w+_H|\w+_H_|\w+_INCLUDED|\w+_DEFINED|COM_NO_WINDOWS_H|BEGIN_INTERFACE|END_INTERFACE|DECLARE_INTERFACE\w*|"
                            r"INTERFACE|CONST_VTBL|HUGEP|FARSTRUCT|EXTERN_C|STDMETHOD\w*|PURE|THIS|THIS_|interface|CINTERFACE|"
                            r"DEFINE_\w*GUID|MIDL_\w+|DEBUGZONE|DEBUGLED|RETAILLED|ASSERTMSG|ASSERT_IMPLIES|VERIFY)$")
DEFINE = re.compile(r"^#define (\w+)(\([^)]*\))? ?(.*)$")


def definitions(side):
    found = {}
    for line in side.run(["-E", "-dM"], "", check=True).stdout.splitlines():
        match = DEFINE.match(line)
        if match:
            found[match.group(1)] = (match.group(2) or "", match.group(3))
    return found


def defining_files(folder):
    where = {}
    for name in sorted(os.listdir(folder)):
        text = open(os.path.join(folder, name), encoding="latin-1").read()
        for macro in re.findall(r"^\s*#\s*define\s+(\w+)", text, re.M):
            where.setdefault(macro, []).append(name)
    return where


FAMILY = set()


def windows_family(clang, sdk_include):
    import subprocess
    command = [clang] + ARM["target"] + check.COMMON_FLAGS + ["-D_WIN32_WCE=300", "-DWINCEMACRO"] + check.SDK_DEFINES + ARM["sdk_defines"] + \
              ["-I" + sdk_include, "-M", "-x", "c", "-"]
    result = subprocess.run(command, input="#include <windows.h>\n", capture_output=True, text=True, check=True)
    return {os.path.basename(path).lower() for path in re.findall(r"(\S+\.h)\b", result.stdout)}


def home(files):
    ranked = sorted(files, key=lambda name: (check.HEADERS.index(name) if name in check.HEADERS else len(check.HEADERS), name))
    for name in ranked:
        if our_guard(name):
            return name
    for name in ranked:
        if name in FAMILY:
            return "windows.h"
    return ranked[0]


def missing(clang, reference, version, work):
    sdk_include = check.sdk_folder(reference, version, work)
    headers = [header for header in check.HEADERS if os.path.exists(os.path.join(sdk_include, header))]
    our_headers = [header for header in headers if os.path.exists(os.path.join(ROOT, "include", header))]
    sdk = check.Side(clang, ARM["target"], check.WIN32_WCE[version], [sdk_include], check.SDK_DEFINES + ARM["sdk_defines"], headers)
    ours = check.Side(clang, ARM["target"], check.WIN32_WCE[version], [os.path.join(ROOT, "include"), os.path.join(ROOT, "include", "w32api")],
                      ARM["defines"] + ["-DGRIMACE_NO_CONSTANTS"], our_headers)
    FAMILY.update(windows_family(clang, sdk_include))
    sdk_definitions = definitions(sdk)
    candidates = {name: name for name, (parameters, _) in sdk_definitions.items() if not name.startswith("_") and not parameters}
    sdk_values = sdk.evaluate(candidates)
    our_macros = ours.macros()
    our_names = set(our_macros) | check.declared_names(ours.tree())
    our_values = ours.evaluate({name: name for name in sdk_values if name in our_macros})
    where = defining_files(sdk_include)
    constants = {}
    macros = {}
    for name, value in sdk_values.items():
        files = where.get(name)
        if name in our_values or name in our_names or not files or check.excluded_constant(name, files[0], check.EXCLUDED_HEADERS):
            continue
        constants.setdefault(home(files), {})[name] = value
    for name, (parameters, body) in sdk_definitions.items():
        files = where.get(name)
        if name in sdk_values or name in our_names or not files or not body.strip() or files[0] in check.EXCLUDED_HEADERS:
            continue
        if not check.checked_macro_name(name, files[0]) or check.EXCLUDED_MACROS.match(name) or SKIPPED_MACROS.match(name):
            continue
        macros.setdefault(home(files), {})[name] = (parameters, body)
    return constants, macros


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Write include/grimace/constants-sdk.h: Windows CE 3.0 SDK constants and macros our headers lack")
    parser.add_argument("--reference", default=os.environ.get("GRIMACE_REFERENCE"))
    parser.add_argument("--clang", default=os.environ.get("CLANG", "clang"))
    arguments = parser.parse_args()
    if not arguments.reference:
        sys.exit("mksdkconstants: set GRIMACE_REFERENCE or pass --reference")
    lines = []
    skipped = []
    with tempfile.TemporaryDirectory() as work:
        for version, condition, _ in VERSIONS:
            lines.append("#if %s" % condition)
            constants, macros = missing(arguments.clang, os.path.expanduser(arguments.reference), version, work)
            for header in sorted(set(constants) | set(macros)):
                guard = our_guard(header)
                count = len(constants.get(header, {})) + len(macros.get(header, {}))
                if not guard:
                    skipped.append("CE %s %s: %d" % (check.VERSION_NAMES[version], header, count))
                    continue
                lines.append("#ifdef %s" % guard)
                for name, value in sorted(constants.get(header, {}).items()):
                    lines += ["#ifndef %s" % name, "#define %s %s" % (name, literal(value)), "#endif"]
                for name, (parameters, body) in sorted(macros.get(header, {}).items()):
                    lines += ["#ifndef %s" % name, "#define %s%s %s" % (name, parameters, body), "#endif"]
                lines.append("#endif")
            lines += ["#endif", ""]
    with open(os.path.join(ROOT, "include", "grimace", "constants-sdk.h"), "w") as output:
        output.write("\n".join(lines))
    print("mksdkconstants: %d constants and macros" % sum(1 for line in lines if line.startswith("#define")))
    for line in skipped:
        print("mksdkconstants: no header of ours for %s" % line)

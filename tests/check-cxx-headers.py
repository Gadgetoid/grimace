import argparse
import glob
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
COMMON_FLAGS = ["-fshort-wchar", "-ffreestanding", "-nostdlibinc", "-std=c++20", "-fno-exceptions", "-fno-rtti", "-x", "c++"]
ARCHITECTURES = {
    "mips": {"target": ["--target=mipsel-unknown-none-elf", "-march=mips1", "-msoft-float", "-Wno-unknown-warning-option", "-Wno-experimental-option"], "defines": []},
    "sh3": {"target": ["--target=sh3el-unknown-none-wince"], "defines": ["-DSHx", "-DSH3", "-D_SH3_"]},
    "x86": {"target": ["--target=i486-unknown-none-elf", "-malign-double", "-nostdinc++"], "defines": ["-D_X86_", "-Dx86"]},
    "arm": {"target": ["--target=armv4-unknown-none-wince", "-mcpu=strongarm", "-marm", "-mfloat-abi=soft"], "defines": ["-DARM", "-D_ARM_", "-DARMV4"]},
}
VERSIONS = {"mips": [1, 2], "sh3": [1, 101, 2], "x86": [2], "arm": [3]}
WIN32_WCE = {1: 100, 101: 101, 2: 200, 3: 300}
VERSION_NAMES = {1: "1.0", 101: "1.01", 2: "2.0", 3: "3.0"}


def vendored_headers():
    names = sorted(os.path.basename(path) for path in glob.glob(os.path.join(ROOT, "include", "w32api", "*.h")))
    return [name for name in names if not name.startswith(("pshpack", "poppack"))]


def sdk_headers():
    return sorted(os.path.relpath(path, os.path.join(ROOT, "include")) for path in glob.glob(os.path.join(ROOT, "include", "grimace", "cxx", "*.h")))


STANDARD_HEADERS = ["algorithm", "any", "array", "bit", "bitset", "charconv", "chrono", "cmath", "compare", "complex", "concepts", "cstdint",
                    "cstdio", "cstdlib", "cstring", "cwchar", "cwctype", "deque", "expected", "format", "forward_list", "functional",
                    "initializer_list", "iterator", "limits", "list", "map", "memory", "new", "numbers", "numeric", "optional", "queue",
                    "random", "ranges", "ratio", "set", "span", "stack", "string", "string_view", "tuple", "type_traits",
                    "unordered_map", "unordered_set", "utility", "variant", "vector", "version"]


def libcxx_include(clang):
    folder = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(clang))), "include", "c++", "v1")
    return folder if os.path.exists(os.path.join(folder, "__config")) else None


def compile_source(clang, version, arch, target_arch, source, extra, libcxx=None):
    standard = ["-nostdinc++", "-isystem", os.path.join(ROOT, "include", "grimace", "libcxx"), "-isystem", libcxx] if libcxx else []
    command = [clang, *ARCHITECTURES[target_arch]["target"], *COMMON_FLAGS, *ARCHITECTURES[arch]["defines"], "-D_WIN32_WCE=%d" % WIN32_WCE[version],
               *standard, "-isystem" if libcxx else "-I", os.path.join(ROOT, "include"), "-isystem" if libcxx else "-I",
               os.path.join(ROOT, "include", "w32api"), *extra, "-"]
    return subprocess.run(command, input=source, capture_output=True, text=True)


def check_libcxx(clang, version, arch, target_arch):
    libcxx = libcxx_include(clang)
    if not libcxx or WIN32_WCE[version] < 300:
        return []
    problems = []
    for header in STANDARD_HEADERS:
        result = compile_source(clang, version, arch, target_arch, "#include <windows.h>\n#include <%s>\n" % header, ["-std=c++23", "-fsyntax-only"], libcxx)
        if result.returncode:
            problems.append("<%s> doesn't compile with libc++:\n%s" % (header, result.stderr))
    with open(os.path.join(ROOT, "tests", "cxx-sdk.cpp")) as source:
        result = compile_source(clang, version, arch, target_arch, source.read(), ["-fsyntax-only", "-Wall", "-Wextra", "-Werror", "-Wno-unused-parameter"],
                                libcxx)
    if result.returncode:
        problems.append("tests/cxx-sdk.cpp doesn't compile with libc++:\n%s" % result.stderr)
    return problems


def cplusplus_linkage(tree):
    in_c = set()
    outside = set()

    def walk(node, language):
        for child in node.get("inner", []):
            kind = child.get("kind")
            if kind == "LinkageSpecDecl":
                walk(child, child.get("language"))
            elif kind == "FunctionDecl" and not child.get("isImplicit") and child.get("storageClass") != "static":
                if any(grandchild.get("kind") == "CompoundStmt" for grandchild in child.get("inner", [])):
                    continue
                (in_c if language == "C" else outside).add(child["name"])
    walk(tree, None)
    return sorted(outside - in_c)


FORMAT_ERRORS = [
    ('grimace::format<64>(L"%d", L"text")', "format_argument_does_not_match_its_conversion"),
    ('grimace::format<64>(L"%d", 1LL)', "format_64_bit_integer_needs_the_I64_prefix"),
    ('grimace::format<64>(L"%f", 1)', "format_argument_does_not_match_its_conversion"),
    ('grimace::format<64>(L"%*d", 1, 2)', "format_star_width_or_precision_is_not_supported"),
    ('grimace::format<64>(L"%n", 1)', "format_conversion_is_not_supported"),
    ('grimace::format<64>(L"%d %d", 1)', "format_has_more_conversions_than_arguments"),
    ('grimace::format<64>(L"%d", 1, 2)', "format_has_more_arguments_than_conversions"),
    ('grimace::format<8>(L"Total: %d", 1)', "format_output_may_not_fit_in_the_capacity"),
    ('grimace::format<12>(L"%e", 1.0)', "format_output_may_not_fit_in_the_capacity"),
]


def check_format_errors(clang, version, arch, target_arch):
    problems = []
    if WIN32_WCE[version] < 300:
        return problems
    for expression, expected in FORMAT_ERRORS:
        source = "#include <windows.h>\n#include <grimace/cxx/format.h>\nvoid test() { %s; }\n" % expression
        result = compile_source(clang, version, arch, target_arch, source, ["-fsyntax-only"])
        if result.returncode == 0 or expected not in result.stderr:
            problems.append("%s should fail with %s" % (expression, expected))
    return problems


def check(clang, version, arch, target_arch):
    problems = check_format_errors(clang, version, arch, target_arch)
    source = "".join("#include <%s>\n" % name for name in ["windows.h", "winsock.h", "tchar.h", *vendored_headers()])
    result = compile_source(clang, version, arch, target_arch, source, ["-fsyntax-only", "-w", "-Xclang", "-ast-dump=json"])
    if result.returncode:
        problems.append("Windows headers don't compile as C++:\n" + result.stderr)
    else:
        for name in cplusplus_linkage(json.loads(result.stdout)):
            problems.append("%s has C++ linkage" % name)
    for header in sdk_headers():
        result = compile_source(clang, version, arch, target_arch, "#include <windows.h>\n#include <%s>\n" % header, ["-fsyntax-only", "-Wall", "-Wextra", "-Werror"])
        if result.returncode:
            problems.append("%s doesn't compile:\n%s" % (header, result.stderr))
    with open(os.path.join(ROOT, "tests", "cxx-sdk.cpp")) as source:
        result = compile_source(clang, version, arch, target_arch, source.read(), ["-fsyntax-only", "-Wall", "-Wextra", "-Werror", "-Wno-unused-parameter"])
    if result.returncode:
        problems.append("tests/cxx-sdk.cpp doesn't compile:\n%s" % result.stderr)
    return problems


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Check the headers declare C functions with C linkage in C++, and the C++ SDK headers compile")
    parser.add_argument("--clang", default=os.environ.get("CLANG", "clang"))
    parser.add_argument("--arch", choices=sorted(ARCHITECTURES), default="mips", help="architecture defines, and CE versions, to check")
    parser.add_argument("--target-arch", choices=sorted(ARCHITECTURES), help="compile for this architecture's clang target instead, "
                        "to check with a clang that lacks --arch's backend")
    arguments = parser.parse_args()
    failed = False
    label = "" if arguments.arch == "mips" else " " + arguments.arch.upper()
    for version in VERSIONS[arguments.arch]:
        problems = check(arguments.clang, version, arguments.arch, arguments.target_arch or arguments.arch)
        problems += check_libcxx(arguments.clang, version, arguments.arch, arguments.target_arch or arguments.arch)
        for problem in problems:
            print("CE %s%s: %s" % (VERSION_NAMES[version], label, problem), file=sys.stderr)
        failed = failed or bool(problems)
        print("CE %s%s: %d problems" % (VERSION_NAMES[version], label, len(problems)))
    sys.exit(1 if failed else 0)

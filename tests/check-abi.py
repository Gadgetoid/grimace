"""
Check that the compiler follows Microsoft's Windows CE ARM calling standard, as eVC3's CLARM.EXE compiles it.

Layouts are static assertions. Calls are compiled at -O2 and each function's assembly must contain the listed
instructions, in any order; a register captured by one pattern is the same register in a later one.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FLAGS = ["--target=armv4-unknown-none-wince", "-mcpu=strongarm", "-marm", "-ffreestanding", "-nostdlibinc", "-fno-unwind-tables", "-O2"]

SOURCE = r"""
struct S1 { char c; };
struct S8 { int a, b; };
struct Mixed { int x; long long y; };
struct Bits { unsigned a : 3; unsigned b : 30; };
struct HasBits { char c; struct Bits b; };
struct MixedBits { char c; short s : 4; char d; };
enum E { E1 = 1 };

_Static_assert(sizeof(struct Mixed) == 16 && __builtin_offsetof(struct Mixed, y) == 8, "__int64 is 8-byte aligned in structures");
_Static_assert(sizeof(struct { int x; double d; }) == 16, "double is 8-byte aligned in structures");
_Static_assert(sizeof(struct { char c; struct Mixed m; }) == 24, "structures with __int64 are 8-byte aligned");
_Static_assert(sizeof(struct Bits) == 8 && sizeof(struct HasBits) == 12 && sizeof(struct MixedBits) == 6, "Microsoft bitfields");
_Static_assert(sizeof(enum E) == 4, "enums are int");
_Static_assert(sizeof(long double) == 8, "long double is double");
_Static_assert(sizeof(__WCHAR_TYPE__) == 2 && (__WCHAR_TYPE__)-1 > 0, "wchar_t is unsigned 16 bits");
_Static_assert((char)-1 < 0, "char is signed");

extern void take64(int a, long long b);
extern void split64(int a, int b, int c, long long d);
extern void stack64(int a, int b, int c, int d, int e, long long f);
extern void split_double(int a, int b, int c, double d);
extern void by_value(int a, struct Mixed m);
extern void variadic(int count, ...);
extern struct S1 get_small(void);
extern struct S8 make(int);
extern void use(struct S8 *);

void call64(void) { take64(1, 0x200000003LL); }
void callsplit(void) { split64(1, 2, 3, 0x500000004LL); }
void callstack(void) { stack64(1, 2, 3, 4, 5, 0x700000006LL); }
void calldouble(void) { split_double(1, 2, 3, 2.0); }
void callmixed(void) { struct Mixed m = { 7, 0x900000008LL }; by_value(1, m); }
void callvariadic(void) { variadic(1, 2.0, 0x500000004LL); }
int usesmall(void) { return get_small().c; }
struct S1 retsmall(void) { struct S1 r = { 5 }; return r; }
struct S8 wrap(int x) { struct S8 r = make(x); use(&r); r.a++; return r; }
char plainchar(char *p) { return *p; }
"""

EXPECTED = {
    "call64": [r"mov\s+r1, #3", r"mov\s+r2, #2", r"b\s+take64"],
    "callsplit": [r"mov\s+(r\d+), #5", r"str\s+\1, \[sp\]", r"mov\s+r3, #4", r"bl\s+split64"],
    "callstack": [r"str\s+r\d+, \[sp\]", r"str\s+r\d+, \[sp, #4\]", r"str\s+r\d+, \[sp, #8\]", r"bl\s+stack64"],
    "calldouble": [r"mov\s+(r\d+), #1073741824", r"mov\s+r3, #0", r"str\s+\1, \[sp\]", r"bl\s+split_double"],
    "callmixed": [r"mov\s+r1, #7", r"mov\s+r2, #0", r"mov\s+r3, #8", r"bl\s+by_value"],
    "callvariadic": [r"mov\s+r1, #0", r"mov\s+r2, #1073741824", r"mov\s+r3, #4", r"bl\s+variadic"],
    "usesmall": [r"(mov|sub|add)\s+r0, (sp|r11)", r"bl\s+get_small", r"ldrsb\s+r0, \["],
    "retsmall": [r"strb\s+r\d+, \[r0\]"],
    "wrap": [r"mov\s+(r\d+), r0", r"bl\s+make", r"mov\s+r0, \1", r"pop|ldm"],
    "plainchar": [r"ldrsb\s+r0, \[r0\]"],
}


def functions(assembly):
    found = {}
    current = None
    for line in assembly.splitlines():
        label = re.match(r"^(\w+):", line)
        if label:
            current = label.group(1)
            found[current] = []
        elif current and line.startswith("\t") and not line.lstrip().startswith((".", "@")):
            found[current].append(line.strip())
    return found


def check(clang):
    result = subprocess.run([clang] + FLAGS + ["-S", "-o", "-", "-x", "c", "-"], input=SOURCE, capture_output=True, text=True)
    if result.returncode:
        return [result.stderr.strip()]
    bodies = functions(result.stdout)
    problems = []
    for name, patterns in EXPECTED.items():
        lines = bodies.get(name)
        if lines is None:
            problems.append("%s: not in the assembly" % name)
            continue
        captures = {}
        for pattern in patterns:
            expanded = re.sub(r"\\(\d)", lambda match: re.escape(captures.get(match.group(1), "")), pattern)
            match = next((found for found in (re.search(expanded, line) for line in lines) if found), None)
            if not match:
                problems.append("%s: expected %r in:\n    %s" % (name, pattern, "\n    ".join(lines)))
                break
            for index, value in enumerate(match.groups(), 1):
                captures[str(index)] = value
    return problems


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Check the compiler follows Microsoft's Windows CE ARM calling standard")
    default = os.path.join(os.environ.get("GRIMACE_LLVM_ROOT", os.path.join(ROOT, "llvm")), "bin", "clang")
    parser.add_argument("--clang", default=default)
    arguments = parser.parse_args()
    problems = check(arguments.clang)
    for problem in problems:
        print("check-abi: %s" % problem, file=sys.stderr)
    print("check-abi: %d layouts, %d functions, %d problems" % (SOURCE.count("_Static_assert"), len(EXPECTED), len(problems)))
    sys.exit(1 if problems else 0)

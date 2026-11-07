import argparse
import re

IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def import_slot(function, dll, word=".word"):
    return f"""    .section .iat.{dll}.{function},"aw",%progbits
    .balign 4
    .weak __imp_{function}
    .weak "__grimace_import${dll}${function}"
__imp_{function}:
"__grimace_import${dll}${function}":
    {word} 0

"""


def mips_stub(function, dll):
    return f"""    .section .text.{function},"ax",%progbits
    .weak {function}
    .type {function},%function
{function}:
    lui $25, %hi(__imp_{function})
    lw $25, %lo(__imp_{function})($25)
    nop
    jr $25
    nop

""" + import_slot(function, dll)


def sh3_stub(function, dll):
    return f"""    .section .text.{function},"ax",%progbits
    .balign 4
    .weak {function}
    .type {function},%function
{function}:
    mov.l .Lslot_{function},r0
    mov.l @r0,r0
    jmp @r0
    nop
.Lslot_{function}:
    .long __imp_{function}

""" + import_slot(function, dll, ".long")


def x86_stub(function, dll):
    return f"""    .section .text.{function},"ax",%progbits
    .weak {function}
    .type {function},%function
{function}:
    jmp *__imp_{function}

""" + import_slot(function, dll, ".long")


def arm_stub(function, dll):
    return f"""    .section .text.{function},"ax",%progbits
    .balign 4
    .weak {function}
    .type {function},%function
{function}:
    ldr ip, .Lslot_{function}
    ldr pc, [ip]
.Lslot_{function}:
    .long __imp_{function}

""" + import_slot(function, dll, ".long")


ARCHITECTURES = {
    "mips": (["    .set noreorder", "    .set noat", ""], mips_stub),
    "sh3": ([], sh3_stub),
    "x86": ([], x86_stub),
    "arm": (["    .arm", ""], arm_stub),
}


def generate(functions, dll, arch="mips"):
    preamble, stub = ARCHITECTURES[arch]
    lines = list(preamble)
    lines += [stub(function, dll) for function in functions]
    return "\n".join(lines)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate an import library for a Windows CE DLL from its export list")
    parser.add_argument("exports")
    parser.add_argument("dll")
    parser.add_argument("output")
    parser.add_argument("--arch", choices=sorted(ARCHITECTURES), default="mips")
    arguments = parser.parse_args()
    functions = []
    for line in open(arguments.exports):
        name = line.strip()
        if IDENTIFIER.match(name) and name not in functions:
            functions.append(name)
    with open(arguments.output, "w") as output:
        output.write(generate(functions, arguments.dll, arguments.arch))

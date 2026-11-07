"""
Write an import library for a Windows CE DLL: a weak stub per function, jumping through a pointer.

A direct import's pointer is an IAT slot that the loader fills. A lazy import's pointer starts at a thunk that binds it with
LoadLibraryW and GetProcAddressW (__grimace_lazy_bind in runtime/lazy.c) on the first call, then jumps to what it found.
"""
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


def wide_string(text):
    return "    .2byte %s\n" % ", ".join(str(ord(character)) for character in text + "\0")


def lazy_import(function, thunk):
    return f"""    .section .data.__grimace_lazy_import_{function},"aw",%progbits
    .balign 4
    .weak __grimace_lazy_import_{function}
__grimace_lazy_import_{function}:
    .4byte {thunk}
    .4byte .Lgrimace_lazy_dll
    .4byte .Lgrimace_lazy_name_{function}
    .4byte 0

    .section .rodata.__grimace_lazy_name_{function},"a",%progbits
    .balign 2
.Lgrimace_lazy_name_{function}:
{wide_string(function)}
"""


def lazy_dll_name(dll):
    return f"""    .section .rodata.__grimace_lazy_dll,"a",%progbits
    .balign 2
.Lgrimace_lazy_dll:
{wide_string(dll)}
"""


def mips_stub(function, slot):
    return f"""    .section .text.{function},"ax",%progbits
    .weak {function}
    .type {function},%function
{function}:
    lui $25, %hi({slot})
    lw $25, %lo({slot})($25)
    nop
    jr $25
    nop

"""


def mips_thunk(function, thunk, descriptor):
    return f"""    .section .text.{thunk},"ax",%progbits
{thunk}:
    addiu $sp, $sp, -40
    sw $31, 36($sp)
    sw $4, 16($sp)
    sw $5, 20($sp)
    sw $6, 24($sp)
    sw $7, 28($sp)
    lui $4, %hi({descriptor})
    jal __grimace_lazy_bind
    addiu $4, $4, %lo({descriptor})
    lw $31, 36($sp)
    lw $4, 16($sp)
    lw $5, 20($sp)
    lw $6, 24($sp)
    lw $7, 28($sp)
    move $25, $2
    jr $25
    addiu $sp, $sp, 40

"""


def sh3_stub(function, slot):
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
    .long {slot}

"""


def sh3_thunk(function, thunk, descriptor):
    return f"""    .section .text.{thunk},"ax",%progbits
    .balign 4
{thunk}:
    sts.l pr,@-r15
    mov.l r7,@-r15
    mov.l r6,@-r15
    mov.l r5,@-r15
    mov.l r4,@-r15
    add #-16,r15
    mov.l .Ldescriptor_{function},r4
    mov.l .Lbind_{function},r0
    jsr @r0
    nop
    add #16,r15
    mov.l @r15+,r4
    mov.l @r15+,r5
    mov.l @r15+,r6
    mov.l @r15+,r7
    lds.l @r15+,pr
    jmp @r0
    nop
    .balign 4
.Ldescriptor_{function}:
    .long {descriptor}
.Lbind_{function}:
    .long __grimace_lazy_bind

"""


def x86_stub(function, slot):
    return f"""    .section .text.{function},"ax",%progbits
    .weak {function}
    .type {function},%function
{function}:
    jmp *{slot}

"""


def x86_thunk(function, thunk, descriptor):
    return f"""    .section .text.{thunk},"ax",%progbits
{thunk}:
    pushl ${descriptor}
    call __grimace_lazy_bind
    addl $4, %esp
    jmp *%eax

"""


def arm_stub(function, slot):
    return f"""    .section .text.{function},"ax",%progbits
    .balign 4
    .weak {function}
    .type {function},%function
{function}:
    ldr ip, .Lslot_{function}
    ldr pc, [ip]
.Lslot_{function}:
    .long {slot}

"""


def arm_thunk(function, thunk, descriptor):
    return f"""    .section .text.{thunk},"ax",%progbits
    .balign 4
{thunk}:
    stmfd sp!, {{r0-r3, ip, lr}}
    ldr r0, .Ldescriptor_{function}
    bl __grimace_lazy_bind
    str r0, [sp, #16]
    ldmfd sp!, {{r0-r3, ip, lr}}
    mov pc, ip
.Ldescriptor_{function}:
    .long {descriptor}

"""


ARCHITECTURES = {
    "mips": (["    .set noreorder", "    .set noat", ""], mips_stub, mips_thunk, ".word"),
    "sh3": ([], sh3_stub, sh3_thunk, ".long"),
    "x86": ([], x86_stub, x86_thunk, ".long"),
    "arm": (["    .arm", ""], arm_stub, arm_thunk, ".long"),
}


def generate(functions, dll, arch="mips", lazy=()):
    preamble, stub, thunk, word = ARCHITECTURES[arch]
    lines = list(preamble)
    lines += [stub(function, "__imp_" + function) + import_slot(function, dll, word) for function in functions]
    if lazy:
        lines.append(lazy_dll_name(dll))
    for function in lazy:
        descriptor = "__grimace_lazy_import_" + function
        thunk_name = "__grimace_lazy_thunk_" + function
        lines.append(stub(function, descriptor) + lazy_import(function, thunk_name) + thunk(function, thunk_name, descriptor))
    return "\n".join(lines)


def read_names(path):
    names = []
    for line in open(path):
        name = line.strip()
        if IDENTIFIER.match(name) and name not in names:
            names.append(name)
    return names


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate an import library for a Windows CE DLL from its export list")
    parser.add_argument("exports", help="functions to import directly, one per line")
    parser.add_argument("dll")
    parser.add_argument("output")
    parser.add_argument("--arch", choices=sorted(ARCHITECTURES), default="mips")
    parser.add_argument("--lazy", help="functions to import lazily, one per line")
    arguments = parser.parse_args()
    lazy = read_names(arguments.lazy) if arguments.lazy else []
    with open(arguments.output, "w") as output:
        output.write(generate(read_names(arguments.exports), arguments.dll, arguments.arch, lazy))

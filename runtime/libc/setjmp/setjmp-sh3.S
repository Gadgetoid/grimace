    .section .text.setjmp,"ax",%progbits
    .balign 2
    .globl setjmp
    .type setjmp,%function
setjmp:
    mov.l r8,@r4
    mov.l r9,@(4,r4)
    mov.l r10,@(8,r4)
    mov.l r11,@(12,r4)
    mov.l r12,@(16,r4)
    mov.l r13,@(20,r4)
    mov.l r14,@(24,r4)
    mov.l r15,@(28,r4)
    sts pr,r0
    mov.l r0,@(32,r4)
    rts
    mov #0,r0

    .section .text.longjmp,"ax",%progbits
    .balign 2
    .globl longjmp
    .type longjmp,%function
longjmp:
    mov.l @r4,r8
    mov.l @(4,r4),r9
    mov.l @(8,r4),r10
    mov.l @(12,r4),r11
    mov.l @(16,r4),r12
    mov.l @(20,r4),r13
    mov.l @(24,r4),r14
    mov.l @(28,r4),r15
    mov.l @(32,r4),r0
    lds r0,pr
    mov r5,r0
    tst r0,r0
    bf 1f
    mov #1,r0
1:
    rts
    nop

    .set noreorder
    .set noat

    .section .text.setjmp,"ax",%progbits
    .globl setjmp
    .type setjmp,%function
setjmp:
    sw $16, 0($4)
    sw $17, 4($4)
    sw $18, 8($4)
    sw $19, 12($4)
    sw $20, 16($4)
    sw $21, 20($4)
    sw $22, 24($4)
    sw $23, 28($4)
    sw $29, 32($4)
    sw $30, 36($4)
    sw $31, 40($4)
    jr $31
    move $2, $0

    .section .text.longjmp,"ax",%progbits
    .globl longjmp
    .type longjmp,%function
longjmp:
    lw $16, 0($4)
    lw $17, 4($4)
    lw $18, 8($4)
    lw $19, 12($4)
    lw $20, 16($4)
    lw $21, 20($4)
    lw $22, 24($4)
    lw $23, 28($4)
    lw $29, 32($4)
    lw $30, 36($4)
    lw $31, 40($4)
    bnez $5, 1f
    move $2, $5
    li $2, 1
1:
    jr $31
    nop

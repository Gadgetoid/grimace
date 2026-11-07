#include "internal.h"

static int put_limb(char *digits, int count, uint32_t limb, int pad) {
    char reversed[9];
    int length = 0;
    do {
        reversed[length++] = (char)('0' + limb % 10);
        limb /= 10;
    } while (limb || (pad && length < 9));
    while (pad && length < 9) {
        reversed[length++] = '0';
    }
    while (length) {
        digits[count++] = reversed[--length];
    }
    return count;
}

void __grimace_decimal_exact(double value, struct grimace_decimal *decimal) {
    union {
        double number;
        uint64_t bits;
    } view = {value};
    uint64_t mantissa = view.bits & 0xFFFFFFFFFFFFFull;
    int exponent = (int)(view.bits >> 52 & 0x7FF);
    decimal->negative = (int)(view.bits >> 63);
    decimal->infinite = exponent == 0x7FF && !mantissa;
    decimal->nan = exponent == 0x7FF && mantissa;
    decimal->count = 0;
    decimal->point = 0;
    if (exponent == 0x7FF) {
        return;
    }
    if (exponent) {
        mantissa |= 1ull << 52;
    } else {
        exponent = 1;
    }
    exponent -= 1075;
    if (!mantissa) {
        decimal->point = 1;
        return;
    }
    while (!(mantissa & 1)) {
        mantissa >>= 1;
        exponent++;
    }
    struct grimace_big big;
    __grimace_big_set(&big, mantissa);
    int fraction_digits = 0;
    if (exponent > 0) {
        __grimace_big_shift_left(&big, (unsigned)exponent);
    } else if (exponent < 0) {
        __grimace_big_multiply_power5(&big, (unsigned)-exponent);
        fraction_digits = -exponent;
    }
    uint32_t limbs[GRIMACE_BIG_LIMBS * 2];
    int limb_count = 0;
    while (big.count) {
        limbs[limb_count++] = __grimace_big_divide_small(&big, 1000000000u);
    }
    int count = put_limb(decimal->digits, 0, limbs[limb_count - 1], 0);
    for (int index = limb_count - 1; index-- > 0;) {
        count = put_limb(decimal->digits, count, limbs[index], 1);
    }
    decimal->point = count - fraction_digits;
    while (count > 1 && decimal->digits[count - 1] == '0') {
        count--;
    }
    decimal->count = count;
}

void __grimace_decimal_round(struct grimace_decimal *decimal, int keep) {
    if (keep < 0) {
        decimal->count = 0;
        return;
    }
    if (keep >= decimal->count) {
        return;
    }
    int round_up = decimal->digits[keep] >= '5';
    decimal->count = keep;
    if (round_up) {
        int index = keep - 1;
        while (index >= 0 && decimal->digits[index] == '9') {
            decimal->count = index;
            index--;
        }
        if (index < 0) {
            decimal->digits[0] = '1';
            decimal->count = 1;
            decimal->point++;
        } else {
            decimal->digits[index]++;
        }
    }
    while (decimal->count > 0 && decimal->digits[decimal->count - 1] == '0') {
        decimal->count--;
    }
}

#include "internal.h"

void __grimace_big_set(struct grimace_big *big, uint64_t value) {
    big->count = 0;
    while (value) {
        big->limb[big->count++] = (uint32_t)value;
        value >>= 32;
    }
}

void __grimace_big_multiply_small(struct grimace_big *big, uint32_t factor) {
    uint64_t carry = 0;
    for (unsigned index = 0; index < big->count; index++) {
        uint64_t product = (uint64_t)big->limb[index] * factor + carry;
        big->limb[index] = (uint32_t)product;
        carry = product >> 32;
    }
    if (carry && big->count < GRIMACE_BIG_LIMBS) {
        big->limb[big->count++] = (uint32_t)carry;
    }
}

void __grimace_big_add_small(struct grimace_big *big, uint32_t addend) {
    uint64_t carry = addend;
    for (unsigned index = 0; carry && index < big->count; index++) {
        uint64_t sum = (uint64_t)big->limb[index] + carry;
        big->limb[index] = (uint32_t)sum;
        carry = sum >> 32;
    }
    if (carry && big->count < GRIMACE_BIG_LIMBS) {
        big->limb[big->count++] = (uint32_t)carry;
    }
}

void __grimace_big_shift_left(struct grimace_big *big, unsigned bits) {
    unsigned words = bits / 32;
    unsigned shift = bits % 32;
    if (!big->count) {
        return;
    }
    if (shift) {
        uint32_t carry = 0;
        for (unsigned index = 0; index < big->count; index++) {
            uint32_t limb = big->limb[index];
            big->limb[index] = (limb << shift) | carry;
            carry = limb >> (32 - shift);
        }
        if (carry && big->count < GRIMACE_BIG_LIMBS) {
            big->limb[big->count++] = carry;
        }
    }
    if (words) {
        if (big->count + words > GRIMACE_BIG_LIMBS) {
            words = GRIMACE_BIG_LIMBS - big->count;
        }
        for (unsigned index = big->count; index-- > 0;) {
            big->limb[index + words] = big->limb[index];
        }
        for (unsigned index = 0; index < words; index++) {
            big->limb[index] = 0;
        }
        big->count += words;
    }
}

void __grimace_big_multiply_power5(struct grimace_big *big, unsigned exponent) {
    while (exponent >= 13) {
        __grimace_big_multiply_small(big, 1220703125u);
        exponent -= 13;
    }
    uint32_t factor = 1;
    while (exponent--) {
        factor *= 5;
    }
    if (factor > 1) {
        __grimace_big_multiply_small(big, factor);
    }
}

uint32_t __grimace_big_divide_small(struct grimace_big *big, uint32_t divisor) {
    uint64_t remainder = 0;
    for (unsigned index = big->count; index-- > 0;) {
        uint64_t current = (remainder << 32) | big->limb[index];
        big->limb[index] = (uint32_t)(current / divisor);
        remainder = current % divisor;
    }
    while (big->count && !big->limb[big->count - 1]) {
        big->count--;
    }
    return (uint32_t)remainder;
}

int __grimace_big_compare(const struct grimace_big *first, const struct grimace_big *second) {
    if (first->count != second->count) {
        return first->count < second->count ? -1 : 1;
    }
    for (unsigned index = first->count; index-- > 0;) {
        if (first->limb[index] != second->limb[index]) {
            return first->limb[index] < second->limb[index] ? -1 : 1;
        }
    }
    return 0;
}

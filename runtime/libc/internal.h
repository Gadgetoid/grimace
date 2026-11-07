#ifndef GRIMACE_LIBC_INTERNAL_H
#define GRIMACE_LIBC_INTERNAL_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned short grimace_wchar;

#define GRIMACE_BIG_LIMBS 100

struct grimace_big {
    unsigned count;
    uint32_t limb[GRIMACE_BIG_LIMBS];
};

void __grimace_big_set(struct grimace_big *big, uint64_t value);
void __grimace_big_multiply_small(struct grimace_big *big, uint32_t factor);
void __grimace_big_add_small(struct grimace_big *big, uint32_t addend);
void __grimace_big_shift_left(struct grimace_big *big, unsigned bits);
void __grimace_big_multiply_power5(struct grimace_big *big, unsigned exponent);
uint32_t __grimace_big_divide_small(struct grimace_big *big, uint32_t divisor);
int __grimace_big_compare(const struct grimace_big *first, const struct grimace_big *second);

struct grimace_decimal {
    char digits[800];
    int count;
    int point;
    int negative;
    int infinite;
    int nan;
};

void __grimace_decimal_exact(double value, struct grimace_decimal *decimal);
void __grimace_decimal_round(struct grimace_decimal *decimal, int keep);

struct grimace_reader {
    int (*next)(struct grimace_reader *reader);
    void (*back)(struct grimace_reader *reader, int character);
    void *state;
    size_t consumed;
};

double __grimace_parse_double(const char *text, const char **end);
int __grimace_parse_double_text(struct grimace_reader *reader, char *text, size_t capacity, int width);
unsigned long long __grimace_parse_integer(struct grimace_reader *reader, int base, int width, int *negative, int *overflow, int *valid);

struct grimace_output {
    void (*put)(struct grimace_output *output, unsigned character);
    size_t written;
};

int __grimace_format(struct grimace_output *output, const void *format, int wide_format, va_list arguments);
int __grimace_format_buffer(void *buffer, size_t capacity, int wide, const void *format, int wide_format, va_list arguments);
int __grimace_scan(struct grimace_reader *reader, const void *format, int wide_format, va_list arguments);

struct grimace_reader *__grimace_string_reader(struct grimace_reader *reader, const void *text, int wide);

#endif

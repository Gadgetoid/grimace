#include <limits.h>
#include <wchar.h>

#include "../internal.h"

int *_errno(void);

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

unsigned long wcstoul(const wchar_t *string, wchar_t **end, int base) {
    const wchar_t *start = string;
    while (is_space(*string)) {
        string++;
    }
    struct grimace_reader reader;
    int negative;
    int overflow;
    int valid;
    unsigned long long value = __grimace_parse_integer(__grimace_string_reader(&reader, string, 1), base, INT_MAX, &negative, &overflow, &valid);
    if (end) {
        *end = (wchar_t *)(valid ? string + reader.consumed : start);
    }
    if (overflow || value > ULONG_MAX) {
        *_errno() = 34;
        return ULONG_MAX;
    }
    return negative ? (unsigned long)(0ul - (unsigned long)value) : (unsigned long)value;
}

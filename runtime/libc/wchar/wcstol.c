#include <limits.h>
#include <wchar.h>

#include "../internal.h"

int *_errno(void);

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

long wcstol(const wchar_t *string, wchar_t **end, int base) {
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
    if (overflow || value > (negative ? (unsigned long long)LONG_MAX + 1 : (unsigned long long)LONG_MAX)) {
        *_errno() = 34;
        return negative ? LONG_MIN : LONG_MAX;
    }
    return negative ? (long)(0ull - value) : (long)value;
}

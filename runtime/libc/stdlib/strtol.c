#include <limits.h>
#include <stdlib.h>

#include "../internal.h"

int *_errno(void);

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

long strtol(const char *string, char **end, int base) {
    const char *start = string;
    while (is_space((unsigned char)*string)) {
        string++;
    }
    struct grimace_reader reader;
    int negative;
    int overflow;
    int valid;
    unsigned long long value = __grimace_parse_integer(__grimace_string_reader(&reader, string, 0), base, INT_MAX, &negative, &overflow, &valid);
    if (end) {
        *end = (char *)(valid ? string + reader.consumed : start);
    }
    if (overflow || value > (negative ? (unsigned long long)LONG_MAX + 1 : (unsigned long long)LONG_MAX)) {
        *_errno() = 34;
        return negative ? LONG_MIN : LONG_MAX;
    }
    return negative ? (long)(0ull - value) : (long)value;
}

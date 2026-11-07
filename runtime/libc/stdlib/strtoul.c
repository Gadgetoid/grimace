#include <limits.h>
#include <stdlib.h>

#include "../internal.h"

int *_errno(void);

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

unsigned long strtoul(const char *string, char **end, int base) {
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
    if (overflow || value > ULONG_MAX) {
        *_errno() = 34;
        return ULONG_MAX;
    }
    return negative ? (unsigned long)(0ul - (unsigned long)value) : (unsigned long)value;
}

#include <wchar.h>

#include "../internal.h"

double wcstod(const wchar_t *string, wchar_t **end) {
    char text[512];
    size_t length = 0;
    while (length + 1 < sizeof text && string[length] && string[length] < 0x80) {
        text[length] = (char)string[length];
        length++;
    }
    text[length] = 0;
    const char *stop;
    double value = __grimace_parse_double(text, &stop);
    if (end) {
        *end = (wchar_t *)string + (stop - text);
    }
    return value;
}

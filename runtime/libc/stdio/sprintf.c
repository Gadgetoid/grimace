#include <stdio.h>

#include "../internal.h"

int sprintf(char *buffer, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = __grimace_format_buffer(buffer, (size_t)-1 / 2, 0, format, 0, arguments);
    va_end(arguments);
    return length;
}

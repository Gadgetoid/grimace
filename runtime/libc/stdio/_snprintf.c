#include <stdio.h>

#include "../internal.h"

int _snprintf(char *buffer, size_t count, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = __grimace_format_buffer(buffer, count, 0, format, 0, arguments);
    va_end(arguments);
    return length;
}

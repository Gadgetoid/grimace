#include <stdio.h>

#include "../internal.h"

int _vsnprintf(char *buffer, size_t count, const char *format, va_list arguments) {
    return __grimace_format_buffer(buffer, count, 0, format, 0, arguments);
}

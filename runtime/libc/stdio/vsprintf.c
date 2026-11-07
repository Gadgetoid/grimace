#include <stdio.h>

#include "../internal.h"

int vsprintf(char *buffer, const char *format, va_list arguments) {
    return __grimace_format_buffer(buffer, (size_t)-1 / 2, 0, format, 0, arguments);
}

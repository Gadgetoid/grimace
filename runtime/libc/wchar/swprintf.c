#include <wchar.h>

#include "../internal.h"

int swprintf(wchar_t *buffer, const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = __grimace_format_buffer(buffer, (size_t)-1 / 4, 1, format, 1, arguments);
    va_end(arguments);
    return length;
}

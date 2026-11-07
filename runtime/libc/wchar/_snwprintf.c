#include <wchar.h>

#include "../internal.h"

int _snwprintf(wchar_t *buffer, size_t count, const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = __grimace_format_buffer(buffer, count, 1, format, 1, arguments);
    va_end(arguments);
    return length;
}

#include <wchar.h>

#include "../internal.h"

int _vsnwprintf(wchar_t *buffer, size_t count, const wchar_t *format, va_list arguments) {
    return __grimace_format_buffer(buffer, count, 1, format, 1, arguments);
}

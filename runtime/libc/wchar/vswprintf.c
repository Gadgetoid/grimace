#include <wchar.h>

#include "../internal.h"

int vswprintf(wchar_t *buffer, const wchar_t *format, va_list arguments) {
    return __grimace_format_buffer(buffer, (size_t)-1 / 4, 1, format, 1, arguments);
}

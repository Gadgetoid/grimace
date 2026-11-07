#include <wchar.h>

#include "../internal.h"

int swscanf(const wchar_t *string, const wchar_t *format, ...) {
    struct grimace_reader reader;
    va_list arguments;
    va_start(arguments, format);
    int result = __grimace_scan(__grimace_string_reader(&reader, string, 1), format, 1, arguments);
    va_end(arguments);
    return result;
}

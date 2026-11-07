#include <stdio.h>

#include "../internal.h"

int sscanf(const char *string, const char *format, ...) {
    struct grimace_reader reader;
    va_list arguments;
    va_start(arguments, format);
    int result = __grimace_scan(__grimace_string_reader(&reader, string, 0), format, 0, arguments);
    va_end(arguments);
    return result;
}

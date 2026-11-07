#include <stdarg.h>
#include <stddef.h>

int wvsprintfW(wchar_t *output, const wchar_t *format, va_list arguments);

int swprintf(wchar_t *buffer, const wchar_t *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int written = wvsprintfW(buffer, format, arguments);
    va_end(arguments);
    return written;
}

int vswprintf(wchar_t *buffer, const wchar_t *format, va_list arguments) {
    return wvsprintfW(buffer, format, arguments);
}

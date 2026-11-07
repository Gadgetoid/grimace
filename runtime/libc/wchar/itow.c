#include <stdlib.h>
#include <wchar.h>

static wchar_t *widen(const char *text, wchar_t *buffer) {
    wchar_t *output = buffer;
    while ((*output++ = (unsigned char)*text++) != 0) {
    }
    return buffer;
}

wchar_t *_itow(int value, wchar_t *buffer, int radix) {
    char text[34];
    return widen(_itoa(value, text, radix), buffer);
}

wchar_t *_ltow(long value, wchar_t *buffer, int radix) {
    char text[34];
    return widen(_ltoa(value, text, radix), buffer);
}

wchar_t *_ultow(unsigned long value, wchar_t *buffer, int radix) {
    char text[34];
    return widen(_ultoa(value, text, radix), buffer);
}

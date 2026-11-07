#include <stdlib.h>

static char *convert(unsigned long value, int negative, char *buffer, int radix) {
    char reversed[33];
    int count = 0;
    if (radix < 2 || radix > 36) {
        buffer[0] = 0;
        return buffer;
    }
    do {
        unsigned digit = (unsigned)(value % (unsigned)radix);
        reversed[count++] = (char)(digit < 10 ? '0' + digit : 'a' + digit - 10);
        value /= (unsigned)radix;
    } while (value);
    char *output = buffer;
    if (negative) {
        *output++ = '-';
    }
    while (count) {
        *output++ = reversed[--count];
    }
    *output = 0;
    return buffer;
}

char *_itoa(int value, char *buffer, int radix) {
    int negative = radix == 10 && value < 0;
    return convert(negative ? 0u - (unsigned)value : (unsigned)value, negative, buffer, radix);
}

char *_ltoa(long value, char *buffer, int radix) {
    int negative = radix == 10 && value < 0;
    return convert(negative ? 0ul - (unsigned long)value : (unsigned long)value, negative, buffer, radix);
}

char *_ultoa(unsigned long value, char *buffer, int radix) {
    return convert(value, 0, buffer, radix);
}

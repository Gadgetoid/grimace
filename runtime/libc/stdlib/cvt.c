#include <stdlib.h>

#include "../internal.h"

static char result[350];

static char *digits(double value, int keep_after_point, int digits, int *decimal, int *sign) {
    struct grimace_decimal number;
    __grimace_decimal_exact(value, &number);
    *sign = number.negative;
    int keep = keep_after_point ? number.point + digits : digits;
    if (keep > 340) {
        keep = 340;
    }
    __grimace_decimal_round(&number, keep);
    *decimal = number.count ? number.point : 0;
    if (keep_after_point) {
        keep = *decimal + digits;
    }
    int length = 0;
    for (; length < keep && length < 340; length++) {
        result[length] = length < number.count ? number.digits[length] : '0';
    }
    result[length > 0 ? length : 0] = 0;
    return result;
}

char *_ecvt(double value, int count, int *decimal, int *sign) {
    return digits(value, 0, count, decimal, sign);
}

char *_fcvt(double value, int count, int *decimal, int *sign) {
    return digits(value, 1, count, decimal, sign);
}

int _snprintf(char *buffer, size_t count, const char *format, ...);

char *_gcvt(double value, int count, char *buffer) {
    _snprintf(buffer, 340, "%.*g", count, value);
    return buffer;
}

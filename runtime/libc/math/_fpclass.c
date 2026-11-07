#include <math.h>
#include <stdint.h>

#define SIGNALING_NAN 0x0001
#define QUIET_NAN 0x0002
#define NEGATIVE_INFINITY 0x0004
#define NEGATIVE_NORMAL 0x0008
#define NEGATIVE_DENORMAL 0x0010
#define NEGATIVE_ZERO 0x0020
#define POSITIVE_ZERO 0x0040
#define POSITIVE_DENORMAL 0x0080
#define POSITIVE_NORMAL 0x0100
#define POSITIVE_INFINITY 0x0200

int _fpclass(double value) {
    union {
        double number;
        uint64_t bits;
    } view = {value};
    int negative = (int)(view.bits >> 63);
    unsigned exponent = (unsigned)(view.bits >> 52 & 0x7FF);
    uint64_t mantissa = view.bits & 0xFFFFFFFFFFFFFull;
    if (exponent == 0x7FF) {
        if (mantissa) {
            return mantissa >> 51 ? QUIET_NAN : SIGNALING_NAN;
        }
        return negative ? NEGATIVE_INFINITY : POSITIVE_INFINITY;
    }
    if (!exponent) {
        if (!mantissa) {
            return negative ? NEGATIVE_ZERO : POSITIVE_ZERO;
        }
        return negative ? NEGATIVE_DENORMAL : POSITIVE_DENORMAL;
    }
    return negative ? NEGATIVE_NORMAL : POSITIVE_NORMAL;
}

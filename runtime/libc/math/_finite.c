#include <math.h>
#include <stdint.h>

int _finite(double value) {
    union {
        double number;
        uint64_t bits;
    } view = {value};
    return (view.bits >> 52 & 0x7FF) != 0x7FF;
}

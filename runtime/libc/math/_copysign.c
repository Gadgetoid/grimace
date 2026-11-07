#include <math.h>
#include <stdint.h>

double _copysign(double value, double sign) {
    union {
        double number;
        uint64_t bits;
    } magnitude = {value}, source = {sign};
    magnitude.bits = (magnitude.bits & ~(1ull << 63)) | (source.bits & 1ull << 63);
    return magnitude.number;
}

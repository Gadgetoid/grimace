#include <math.h>
#include <stdint.h>

double fabs(double value) {
    union {
        double number;
        uint64_t bits;
    } view = {value};
    view.bits &= ~(1ull << 63);
    return view.number;
}

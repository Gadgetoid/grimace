#include <math.h>
#include <stdint.h>

double _nextafter(double value, double toward) {
    if (value != value || toward != toward) {
        return value + toward;
    }
    if (value == toward) {
        return toward;
    }
    union {
        double number;
        uint64_t bits;
    } view = {value};
    if (value == 0.0) {
        view.bits = 1;
        return toward > 0 ? view.number : -view.number;
    }
    if ((value < toward) == (value > 0)) {
        view.bits++;
    } else {
        view.bits--;
    }
    return view.number;
}

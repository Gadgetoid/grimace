#include <math.h>

double _logb(double value) {
    if (value != value) {
        return value;
    }
    if (value == 0.0) {
        return -1.0 / 0.0;
    }
    if (fabs(value) > 1.7976931348623157e308) {
        return fabs(value);
    }
    int exponent;
    frexp(value, &exponent);
    return (double)(exponent - 1);
}

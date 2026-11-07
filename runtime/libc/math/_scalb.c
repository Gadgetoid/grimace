#include <math.h>

double scalbn(double value, int exponent);

double _scalb(double value, long exponent) {
    if (exponent > 100000) {
        exponent = 100000;
    } else if (exponent < -100000) {
        exponent = -100000;
    }
    return scalbn(value, (int)exponent);
}

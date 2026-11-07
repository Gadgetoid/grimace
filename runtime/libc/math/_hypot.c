#include <math.h>

double _hypot(double x, double y) {
    x = fabs(x);
    y = fabs(y);
    if (x < y) {
        double held = x;
        x = y;
        y = held;
    }
    if (x == 0.0 || x != x || y != y || x > 1.7976931348623157e308) {
        return x + y;
    }
    double ratio = y / x;
    return x * sqrt(1.0 + ratio * ratio);
}

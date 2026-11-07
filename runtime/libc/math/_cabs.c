#include <math.h>

double _cabs(struct _complex value) {
    return _hypot(value.x, value.y);
}

#include <stdlib.h>

ldiv_t ldiv(long dividend, long divisor) {
    ldiv_t result = {dividend / divisor, dividend % divisor};
    return result;
}

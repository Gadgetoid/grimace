#include <stdlib.h>

div_t div(int dividend, int divisor) {
    div_t result = {dividend / divisor, dividend % divisor};
    return result;
}

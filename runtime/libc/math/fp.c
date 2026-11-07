#include <math.h>

#define DEFAULT_CONTROL 0x0008001F

static unsigned int control = DEFAULT_CONTROL;

unsigned int _clearfp(void) {
    return 0;
}

unsigned int _statusfp(void) {
    return 0;
}

unsigned int _controlfp(unsigned int value, unsigned int mask) {
    control = (control & ~mask) | (value & mask);
    return control;
}

void _fpreset(void) {
    control = DEFAULT_CONTROL;
}

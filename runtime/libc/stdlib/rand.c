#include <stdlib.h>

static unsigned long seed = 1;

void srand(unsigned int value) {
    seed = value;
}

int rand(void) {
    seed = seed * 214013 + 2531011;
    return (int)(seed >> 16 & 0x7FFF);
}

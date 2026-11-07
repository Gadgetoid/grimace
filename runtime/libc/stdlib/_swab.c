#include <stdlib.h>

void _swab(char *source, char *destination, int count) {
    for (int index = 0; index + 1 < count; index += 2) {
        char first = source[index];
        destination[index] = source[index + 1];
        destination[index + 1] = first;
    }
}

#include <string.h>

char *strncpy(char *destination, const char *source, size_t count) {
    size_t index = 0;
    for (; index < count && source[index]; index++) {
        destination[index] = source[index];
    }
    for (; index < count; index++) {
        destination[index] = 0;
    }
    return destination;
}

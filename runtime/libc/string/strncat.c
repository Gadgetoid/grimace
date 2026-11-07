#include <string.h>

char *strncat(char *destination, const char *source, size_t count) {
    char *output = destination + strlen(destination);
    while (count-- && *source) {
        *output++ = *source++;
    }
    *output = 0;
    return destination;
}

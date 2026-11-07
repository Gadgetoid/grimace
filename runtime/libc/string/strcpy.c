#include <string.h>

char *strcpy(char *destination, const char *source) {
    char *output = destination;
    while ((*output++ = *source++) != 0) {
    }
    return destination;
}

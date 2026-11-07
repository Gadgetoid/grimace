#include <string.h>

void *_memccpy(void *destination, const void *source, int value, unsigned int count) {
    unsigned char *output = destination;
    const unsigned char *input = source;
    while (count--) {
        if ((*output++ = *input++) == (unsigned char)value) {
            return output;
        }
    }
    return NULL;
}

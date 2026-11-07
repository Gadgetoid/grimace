#include <stddef.h>

void *memcpy(void *destination, const void *source, size_t count) {
    unsigned char *output = destination;
    const unsigned char *input = source;
    while (count--) {
        *output++ = *input++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t count) {
    unsigned char *output = destination;
    const unsigned char *input = source;
    if (output < input) {
        while (count--) {
            *output++ = *input++;
        }
    } else {
        while (count--) {
            output[count] = input[count];
        }
    }
    return destination;
}

void *memset(void *destination, int value, size_t count) {
    unsigned char *output = destination;
    while (count--) {
        *output++ = (unsigned char)value;
    }
    return destination;
}

int memcmp(const void *left, const void *right, size_t count) {
    const unsigned char *a = left;
    const unsigned char *b = right;
    for (; count; count--, a++, b++) {
        if (*a != *b) {
            return *a - *b;
        }
    }
    return 0;
}

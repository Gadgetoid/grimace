#include <string.h>

static int lower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;
}

int _memicmp(const void *first, const void *second, unsigned int count) {
    const unsigned char *left = first;
    const unsigned char *right = second;
    for (; count; count--, left++, right++) {
        int difference = lower(*left) - lower(*right);
        if (difference) {
            return difference;
        }
    }
    return 0;
}

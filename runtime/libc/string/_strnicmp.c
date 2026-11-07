#include <string.h>

static int lower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;
}

int _strnicmp(const char *first, const char *second, size_t count) {
    for (; count; count--, first++, second++) {
        int difference = lower((unsigned char)*first) - lower((unsigned char)*second);
        if (difference || !*first) {
            return difference;
        }
    }
    return 0;
}

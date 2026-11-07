#include <string.h>

static int lower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;
}

int _stricmp(const char *first, const char *second) {
    int difference;
    while ((difference = lower((unsigned char)*first) - lower((unsigned char)*second)) == 0 && *first) {
        first++;
        second++;
    }
    return difference;
}

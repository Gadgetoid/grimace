#include <string.h>

char *strpbrk(const char *string, const char *characters) {
    for (; *string; string++) {
        if (strchr(characters, *string)) {
            return (char *)string;
        }
    }
    return NULL;
}

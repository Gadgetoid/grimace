#include <string.h>

char *strrchr(const char *string, int character) {
    const char *found = NULL;
    for (;; string++) {
        if (*string == (char)character) {
            found = string;
        }
        if (!*string) {
            return (char *)found;
        }
    }
}

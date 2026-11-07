#include <string.h>

char *strchr(const char *string, int character) {
    for (;; string++) {
        if (*string == (char)character) {
            return (char *)string;
        }
        if (!*string) {
            return NULL;
        }
    }
}

#include <string.h>

char *strstr(const char *string, const char *substring) {
    size_t length = strlen(substring);
    if (!length) {
        return (char *)string;
    }
    for (; *string; string++) {
        if (*string == *substring && !strncmp(string, substring, length)) {
            return (char *)string;
        }
    }
    return NULL;
}

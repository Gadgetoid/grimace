#include <string.h>

char *_strnset(char *string, int character, size_t count) {
    for (char *at = string; *at && count; at++, count--) {
        *at = (char)character;
    }
    return string;
}

#include <string.h>

char *_strset(char *string, int character) {
    for (char *at = string; *at; at++) {
        *at = (char)character;
    }
    return string;
}

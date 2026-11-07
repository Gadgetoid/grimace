#include <string.h>

char *_strlwr(char *string) {
    for (char *at = string; *at; at++) {
        if (*at >= 'A' && *at <= 'Z') {
            *at += 32;
        }
    }
    return string;
}

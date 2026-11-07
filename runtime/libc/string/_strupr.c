#include <string.h>

char *_strupr(char *string) {
    for (char *at = string; *at; at++) {
        if (*at >= 'a' && *at <= 'z') {
            *at -= 32;
        }
    }
    return string;
}

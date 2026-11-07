#include <string.h>

char *_strrev(char *string) {
    size_t length = strlen(string);
    for (size_t index = 0; index < length / 2; index++) {
        char held = string[index];
        string[index] = string[length - 1 - index];
        string[length - 1 - index] = held;
    }
    return string;
}

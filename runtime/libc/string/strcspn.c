#include <string.h>

size_t strcspn(const char *string, const char *characters) {
    size_t count = 0;
    while (string[count] && !strchr(characters, string[count])) {
        count++;
    }
    return count;
}

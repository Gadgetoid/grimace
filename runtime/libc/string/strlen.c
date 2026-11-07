#include <string.h>

size_t strlen(const char *string) {
    const char *end = string;
    while (*end) {
        end++;
    }
    return (size_t)(end - string);
}

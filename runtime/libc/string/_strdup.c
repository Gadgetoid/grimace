#include <stdlib.h>
#include <string.h>

char *_strdup(const char *string) {
    size_t size = strlen(string) + 1;
    char *copy = malloc(size);
    if (copy) {
        memcpy(copy, string, size);
    }
    return copy;
}

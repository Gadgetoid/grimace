#include <string.h>

int strncmp(const char *first, const char *second, size_t count) {
    for (; count; count--, first++, second++) {
        if (*first != *second || !*first) {
            return (unsigned char)*first - (unsigned char)*second;
        }
    }
    return 0;
}

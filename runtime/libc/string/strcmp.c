#include <string.h>

int strcmp(const char *first, const char *second) {
    while (*first && *first == *second) {
        first++;
        second++;
    }
    return (unsigned char)*first - (unsigned char)*second;
}

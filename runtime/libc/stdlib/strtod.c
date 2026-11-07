#include <stdlib.h>

#include "../internal.h"

double strtod(const char *string, char **end) {
    const char *stop;
    double value = __grimace_parse_double(string, &stop);
    if (end) {
        *end = (char *)stop;
    }
    return value;
}

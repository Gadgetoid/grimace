#include <stdlib.h>

long atol(const char *string) {
    return strtol(string, NULL, 10);
}

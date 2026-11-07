#include <stdlib.h>

void *LocalAlloc(unsigned flags, size_t size);

void *malloc(size_t size) {
    return LocalAlloc(0, size ? size : 1);
}

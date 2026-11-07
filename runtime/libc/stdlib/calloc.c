#include <stdlib.h>

void *LocalAlloc(unsigned flags, size_t size);

#define LMEM_ZEROINIT 0x40

void *calloc(size_t count, size_t size) {
    if (size && count > (size_t)-1 / size) {
        return NULL;
    }
    size_t total = count * size;
    return LocalAlloc(LMEM_ZEROINIT, total ? total : 1);
}

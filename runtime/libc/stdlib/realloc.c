#include <stdlib.h>

void *LocalAlloc(unsigned flags, size_t size);
void *LocalReAlloc(void *memory, size_t size, unsigned flags);
void *LocalFree(void *memory);

#define LMEM_MOVEABLE 0x2

void *realloc(void *memory, size_t size) {
    if (!memory) {
        return LocalAlloc(0, size ? size : 1);
    }
    if (!size) {
        LocalFree(memory);
        return NULL;
    }
    return LocalReAlloc(memory, size, LMEM_MOVEABLE);
}

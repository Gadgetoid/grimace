#include <stdlib.h>

void *LocalFree(void *memory);

void free(void *memory) {
    if (memory) {
        LocalFree(memory);
    }
}

#include <stdlib.h>

size_t LocalSize(void *memory);

size_t _msize(void *memory) {
    return LocalSize(memory);
}

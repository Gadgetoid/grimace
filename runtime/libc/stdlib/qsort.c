#include <stdlib.h>

static void swap(unsigned char *first, unsigned char *second, size_t size) {
    while (size--) {
        unsigned char held = *first;
        *first++ = *second;
        *second++ = held;
    }
}

static void sift_down(unsigned char *base, size_t start, size_t count, size_t size, int (*compare)(const void *, const void *)) {
    size_t root = start;
    while (root * 2 + 1 < count) {
        size_t child = root * 2 + 1;
        if (child + 1 < count && compare(base + child * size, base + (child + 1) * size) < 0) {
            child++;
        }
        if (compare(base + root * size, base + child * size) >= 0) {
            return;
        }
        swap(base + root * size, base + child * size, size);
        root = child;
    }
}

void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *)) {
    unsigned char *items = base;
    if (count < 2 || !size) {
        return;
    }
    for (size_t start = count / 2; start-- > 0;) {
        sift_down(items, start, count, size, compare);
    }
    for (size_t end = count - 1; end > 0; end--) {
        swap(items, items + end * size, size);
        sift_down(items, 0, end, size, compare);
    }
}

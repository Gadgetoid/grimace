#include <new>
#include <windows.h>

[[noreturn]] static void out_of_memory() {
    __builtin_trap();
}

static void *allocate(size_t size) {
    void *memory = LocalAlloc(LMEM_FIXED, size ? size : 1);
    if (!memory) {
        out_of_memory();
    }
    return memory;
}

static void *allocate_aligned(size_t size, std::align_val_t alignment, bool required) {
    size_t align = static_cast<size_t>(alignment);
    void *memory = LocalAlloc(LMEM_FIXED, size + align + sizeof(void *));
    if (!memory) {
        if (required) {
            out_of_memory();
        }
        return nullptr;
    }
    size_t address = (reinterpret_cast<size_t>(memory) + sizeof(void *) + align - 1) & ~(align - 1);
    reinterpret_cast<void **>(address)[-1] = memory;
    return reinterpret_cast<void *>(address);
}

static void release(void *pointer) {
    if (pointer) {
        LocalFree(pointer);
    }
}

static void free_aligned(void *pointer) {
    if (pointer) {
        LocalFree(static_cast<void **>(pointer)[-1]);
    }
}

void *operator new(size_t size) {
    return allocate(size);
}

void *operator new[](size_t size) {
    return allocate(size);
}

void *operator new(size_t size, std::align_val_t alignment) {
    return allocate_aligned(size, alignment, true);
}

void *operator new[](size_t size, std::align_val_t alignment) {
    return allocate_aligned(size, alignment, true);
}

void *operator new(size_t size, const std::nothrow_t &) noexcept {
    return LocalAlloc(LMEM_FIXED, size ? size : 1);
}

void *operator new[](size_t size, const std::nothrow_t &) noexcept {
    return LocalAlloc(LMEM_FIXED, size ? size : 1);
}

void *operator new(size_t size, std::align_val_t alignment, const std::nothrow_t &) noexcept {
    return allocate_aligned(size, alignment, false);
}

void *operator new[](size_t size, std::align_val_t alignment, const std::nothrow_t &) noexcept {
    return allocate_aligned(size, alignment, false);
}

void operator delete(void *pointer) noexcept {
    release(pointer);
}

void operator delete[](void *pointer) noexcept {
    release(pointer);
}

void operator delete(void *pointer, size_t) noexcept {
    release(pointer);
}

void operator delete[](void *pointer, size_t) noexcept {
    release(pointer);
}

void operator delete(void *pointer, const std::nothrow_t &) noexcept {
    release(pointer);
}

void operator delete[](void *pointer, const std::nothrow_t &) noexcept {
    release(pointer);
}

void operator delete(void *pointer, std::align_val_t) noexcept {
    free_aligned(pointer);
}

void operator delete[](void *pointer, std::align_val_t) noexcept {
    free_aligned(pointer);
}

void operator delete(void *pointer, size_t, std::align_val_t) noexcept {
    free_aligned(pointer);
}

void operator delete[](void *pointer, size_t, std::align_val_t) noexcept {
    free_aligned(pointer);
}

void operator delete(void *pointer, std::align_val_t, const std::nothrow_t &) noexcept {
    free_aligned(pointer);
}

void operator delete[](void *pointer, std::align_val_t, const std::nothrow_t &) noexcept {
    free_aligned(pointer);
}

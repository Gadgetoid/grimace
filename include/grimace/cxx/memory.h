#ifndef GRIMACE_CXX_MEMORY_H
#define GRIMACE_CXX_MEMORY_H

#include <grimace/cxx/core.h>
#include <windows.h>

namespace grimace {

/**
 * Owns memory from LocalAlloc, freed with LocalFree. Also adopts memory an
 * API hands over for you to LocalFree. Move-only. No constructors or
 * destructors run: use it for plain data.
 */
template <typename T>
class local_ptr {
public:
    constexpr local_ptr() = default;

    constexpr explicit local_ptr(T *pointer) : pointer(pointer) {}

    local_ptr(const local_ptr &) = delete;
    local_ptr &operator=(const local_ptr &) = delete;

    constexpr local_ptr(local_ptr &&other) noexcept : pointer(other.release()) {}

    local_ptr &operator=(local_ptr &&other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    ~local_ptr() {
        reset();
    }

    constexpr T *get() const {
        return pointer;
    }

    constexpr explicit operator bool() const {
        return pointer != nullptr;
    }

    constexpr T &operator*() const {
        return *pointer;
    }

    constexpr T *operator->() const {
        return pointer;
    }

    constexpr T &operator[](size_t index) const {
        return pointer[index];
    }

    constexpr T *release() {
        return exchange(pointer, nullptr);
    }

    void reset(T *replacement = nullptr) {
        T *previous = exchange(pointer, replacement);
        if (previous) {
            LocalFree(previous);
        }
    }

private:
    T *pointer = nullptr;
};

/**
 * Allocates count zeroed elements of T with LocalAlloc. Empty if the allocation fails.
 */
template <typename T>
local_ptr<T> local_alloc(size_t count = 1) {
    static_assert(__is_trivially_copyable(T), "local_alloc is for plain data");
    return local_ptr<T>(static_cast<T *>(LocalAlloc(LPTR, count * sizeof(T))));
}

}

#endif

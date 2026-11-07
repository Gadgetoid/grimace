#ifndef GRIMACE_CXX_OPTIONAL_H
#define GRIMACE_CXX_OPTIONAL_H

#include <new>
#include <grimace/cxx/core.h>

namespace grimace {

/**
 * A T, or nothing.
 */
template <typename T>
class optional {
public:
    constexpr optional() : empty{}, has_value(false) {}

    constexpr optional(const T &value) : stored(value), has_value(true) {}

    constexpr optional(T &&value) : stored(move(value)), has_value(true) {}

    constexpr optional(const optional &other) : empty{}, has_value(false) {
        if (other.has_value) {
            emplace(other.stored);
        }
    }

    constexpr optional(optional &&other) : empty{}, has_value(false) {
        if (other.has_value) {
            emplace(move(other.stored));
        }
    }

    constexpr optional &operator=(const optional &other) {
        if (this != &other) {
            reset();
            if (other.has_value) {
                emplace(other.stored);
            }
        }
        return *this;
    }

    constexpr optional &operator=(optional &&other) {
        if (this != &other) {
            reset();
            if (other.has_value) {
                emplace(move(other.stored));
            }
        }
        return *this;
    }

    constexpr optional &operator=(const T &value) {
        reset();
        emplace(value);
        return *this;
    }

    constexpr ~optional() {
        reset();
    }

    constexpr explicit operator bool() const {
        return has_value;
    }

    constexpr bool present() const {
        return has_value;
    }

    constexpr T &operator*() {
        return stored;
    }

    constexpr const T &operator*() const {
        return stored;
    }

    constexpr T *operator->() {
        return &stored;
    }

    constexpr const T *operator->() const {
        return &stored;
    }

    template <typename U>
    constexpr T value_or(U &&fallback) const {
        return has_value ? stored : static_cast<T>(forward<U>(fallback));
    }

    template <typename... Args>
    constexpr T &emplace(Args &&...arguments) {
        reset();
        ::new (&stored) T(forward<Args>(arguments)...);
        has_value = true;
        return stored;
    }

    constexpr void reset() {
        if (has_value) {
            stored.~T();
            has_value = false;
        }
    }

private:
    struct nothing {};

    union {
        nothing empty;
        T stored;
    };
    bool has_value;
};

}

#endif

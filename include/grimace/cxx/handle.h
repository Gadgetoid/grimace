#ifndef GRIMACE_CXX_HANDLE_H
#define GRIMACE_CXX_HANDLE_H

#include <grimace/cxx/core.h>
#include <grimace/cxx/result.h>
#include <windows.h>

namespace grimace {

/**
 * Owns a resource of type T and releases it when it goes out of scope.
 *
 * Traits says how: `static void close(T)` releases a value, and an optional
 * `static bool is_valid(T)` says whether a value needs releasing (by default,
 * any value but T{}). Move-only.
 */
template <typename T, typename Traits>
class unique_resource {
public:
    constexpr unique_resource() = default;

    constexpr explicit unique_resource(T value) : value(value) {}

    unique_resource(const unique_resource &) = delete;
    unique_resource &operator=(const unique_resource &) = delete;

    constexpr unique_resource(unique_resource &&other) noexcept : value(other.release()) {}

    unique_resource &operator=(unique_resource &&other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    ~unique_resource() {
        reset();
    }

    constexpr T get() const {
        return value;
    }

    constexpr explicit operator bool() const {
        return is_valid(value);
    }

    /**
     * Gives up ownership without releasing, and returns the value.
     */
    constexpr T release() {
        return exchange(value, T{});
    }

    /**
     * Releases the current value, if any, and takes ownership of replacement.
     */
    void reset(T replacement = T{}) {
        T previous = exchange(value, replacement);
        if (is_valid(previous)) {
            Traits::close(previous);
        }
    }

private:
    static constexpr bool is_valid(T candidate) {
        if constexpr (requires { Traits::is_valid(candidate); }) {
            return Traits::is_valid(candidate);
        } else {
            return candidate != T{};
        }
    }

    T value{};
};

struct handle_traits {
    static void close(HANDLE handle) {
        CloseHandle(handle);
    }

    static bool is_valid(HANDLE handle) {
        return handle && handle != INVALID_HANDLE_VALUE;
    }
};

/**
 * A kernel object handle closed with CloseHandle. Treats both NULL and
 * INVALID_HANDLE_VALUE as empty.
 */
using unique_handle = unique_resource<HANDLE, handle_traits>;

/**
 * Wraps a handle an API returned, or the last error if it's NULL or INVALID_HANDLE_VALUE.
 */
inline result<unique_handle> checked_handle(HANDLE handle) {
    unique_handle owned(handle);
    if (!owned) {
        owned.release();
        return error::last();
    }
    return owned;
}

/**
 * Opens or creates a file with CreateFileW.
 */
inline result<unique_handle> create_file(LPCWSTR path, DWORD access, DWORD share, DWORD disposition,
                                         DWORD attributes = FILE_ATTRIBUTE_NORMAL) {
    return checked_handle(CreateFileW(path, access, share, nullptr, disposition, attributes, nullptr));
}

/**
 * Creates an event with CreateEventW.
 */
inline result<unique_handle> create_event(bool manual_reset, bool initially_set, LPCWSTR name = nullptr) {
    return checked_handle(CreateEventW(nullptr, manual_reset, initially_set, name));
}

}

#endif

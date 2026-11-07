#ifndef GRIMACE_CXX_RESULT_H
#define GRIMACE_CXX_RESULT_H

#include <new>
#include <grimace/cxx/core.h>
#include <windows.h>

namespace grimace {

/**
 * A failure: a Win32 error code from GetLastError, or a failed HRESULT.
 */
struct error {
    DWORD code;

    /**
     * The calling thread's last error, from GetLastError.
     */
    static error last() {
        return error{GetLastError()};
    }

    /**
     * An error from a failed HRESULT.
     */
    static constexpr error from_hresult(HRESULT result) {
        return error{static_cast<DWORD>(result)};
    }

    /**
     * True if the code is an HRESULT rather than a Win32 error code.
     */
    constexpr bool is_hresult() const {
        return (code & 0x80000000) != 0;
    }

    /**
     * The error as an HRESULT, converting a Win32 error code as HRESULT_FROM_WIN32 does.
     */
    constexpr HRESULT hresult() const {
        return is_hresult() || code == 0 ? static_cast<HRESULT>(code) : static_cast<HRESULT>((code & 0xFFFF) | 0x80070000);
    }

    friend constexpr bool operator==(error, error) = default;
};

/**
 * A value, or the error that stopped one being made. Errors are values: there are no exceptions.
 *
 * Test it with `if (result)` or ok(), then take the value with `*result`, `result->` or value().
 */
template <typename T>
class [[nodiscard]] result {
public:
    constexpr result(const T &value) : has_value(true) {
        ::new (&storage.value) T(value);
    }

    constexpr result(T &&value) : has_value(true) {
        ::new (&storage.value) T(move(value));
    }

    constexpr result(error failure) : has_value(false) {
        storage.failure = failure;
    }

    result(const result &other) : has_value(other.has_value) {
        if (has_value) {
            ::new (&storage.value) T(other.storage.value);
        } else {
            storage.failure = other.storage.failure;
        }
    }

    result(result &&other) : has_value(other.has_value) {
        if (has_value) {
            ::new (&storage.value) T(move(other.storage.value));
        } else {
            storage.failure = other.storage.failure;
        }
    }

    result &operator=(const result &) = delete;
    result &operator=(result &&) = delete;

    ~result() {
        if (has_value) {
            storage.value.~T();
        }
    }

    constexpr bool ok() const {
        return has_value;
    }

    constexpr explicit operator bool() const {
        return has_value;
    }

    constexpr T &value() & {
        return storage.value;
    }

    constexpr const T &value() const & {
        return storage.value;
    }

    constexpr T &&value() && {
        return move(storage.value);
    }

    constexpr T &operator*() & {
        return storage.value;
    }

    constexpr T &&operator*() && {
        return move(storage.value);
    }

    constexpr T *operator->() {
        return &storage.value;
    }

    constexpr const T *operator->() const {
        return &storage.value;
    }

    /**
     * The value, or fallback if there was an error.
     */
    template <typename U>
    constexpr T value_or(U &&fallback) const & {
        return has_value ? storage.value : static_cast<T>(forward<U>(fallback));
    }

    /**
     * The error. Only meaningful when ok() is false.
     */
    constexpr grimace::error error() const {
        return has_value ? grimace::error{0} : storage.failure;
    }

private:
    union storage_type {
        constexpr storage_type() : failure{0} {}
        ~storage_type() {}

        T value;
        grimace::error failure;
    } storage;
    bool has_value;
};

/**
 * Success with no value, or an error.
 */
template <>
class [[nodiscard]] result<void> {
public:
    constexpr result() : failure{0}, failed(false) {}

    constexpr result(error failure) : failure(failure), failed(true) {}

    constexpr bool ok() const {
        return !failed;
    }

    constexpr explicit operator bool() const {
        return !failed;
    }

    constexpr grimace::error error() const {
        return failure;
    }

private:
    grimace::error failure;
    bool failed;
};

/**
 * result<void> from a Win32 BOOL return: success, or the last error.
 */
inline result<void> check(BOOL succeeded) {
    if (succeeded) {
        return {};
    }
    return error::last();
}

/**
 * result<void> from an HRESULT.
 */
constexpr result<void> check_hresult(HRESULT status) {
    if (status >= 0) {
        return {};
    }
    return error::from_hresult(status);
}

}

#endif

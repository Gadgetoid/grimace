#ifndef GRIMACE_CXX_CORE_H
#define GRIMACE_CXX_CORE_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#if GRIMACE_CE >= 2
#define GRIMACE_CXX_CE2_ONLY
#else
#define GRIMACE_CXX_CE2_ONLY __attribute__((unavailable("not in Windows CE 1.0")))
#endif

namespace grimace {

template <typename T>
struct type_identity {
    using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

template <typename T>
using remove_reference_t = __remove_reference_t(T);

template <typename T>
using remove_cvref_t = __remove_cvref(T);

template <typename T>
using decay_t = __decay(T);

template <typename T, typename U>
concept same_as = __is_same(T, U) && __is_same(U, T);

template <typename From, typename To>
concept convertible_to = __is_convertible(From, To);

template <typename T>
concept integral = __is_integral(T);

template <typename T>
concept signed_integral = integral<T> && __is_signed(T);

template <typename T>
concept enumeration = __is_enum(T);

template <typename T>
constexpr remove_reference_t<T> &&move(T &&value) noexcept {
    return static_cast<remove_reference_t<T> &&>(value);
}

template <typename T>
constexpr T &&forward(remove_reference_t<T> &value) noexcept {
    return static_cast<T &&>(value);
}

template <typename T>
constexpr T &&forward(remove_reference_t<T> &&value) noexcept {
    return static_cast<T &&>(value);
}

template <typename T, typename U = T>
constexpr T exchange(T &target, U &&replacement) {
    T previous = move(target);
    target = forward<U>(replacement);
    return previous;
}

template <typename T>
constexpr void swap(T &first, T &second) {
    T held = move(first);
    first = move(second);
    second = move(held);
}

template <typename T, size_t Count>
constexpr size_t size(const T (&)[Count]) noexcept {
    return Count;
}

}

#endif

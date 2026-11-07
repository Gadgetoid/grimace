#ifndef GRIMACE_CXX_DETAIL_FORMAT_WSPRINTF_H
#define GRIMACE_CXX_DETAIL_FORMAT_WSPRINTF_H

#include <stdarg.h>
#include <grimace/cxx/fixed_string.h>
#include <windows.h>

namespace grimace {

namespace detail {

void format_has_more_conversions_than_arguments();
void format_has_more_arguments_than_conversions();
void format_argument_does_not_match_its_conversion();
void format_conversion_is_not_supported_by_wsprintfW();
void format_argument_type_is_not_supported_by_wsprintfW();
void format_output_may_not_fit_in_the_capacity();
void format_has_too_many_arguments();

enum class argument_kind { integer, character, wide_string, narrow_string, unsupported };

struct argument_info {
    argument_kind kind;
    size_t longest;
};

template <typename T>
struct fixed_wide_string_capacity {
    static constexpr size_t value = 0;
};

template <size_t Capacity>
struct fixed_wide_string_capacity<basic_fixed_string<wchar_t, Capacity>> {
    static constexpr size_t value = Capacity;
};

constexpr size_t unbounded = static_cast<size_t>(-1);

template <typename T>
consteval argument_info describe_argument() {
    using type = decay_t<T>;
    if constexpr (same_as<type, wchar_t> || same_as<type, char>) {
        return {argument_kind::character, 0};
    } else if constexpr ((integral<type> || enumeration<type>) && sizeof(type) <= 4) {
        return {argument_kind::integer, 0};
    } else if constexpr (same_as<type, wchar_t *> || same_as<type, const wchar_t *>) {
        return {argument_kind::wide_string, unbounded};
    } else if constexpr (same_as<type, char *> || same_as<type, const char *>) {
        return {argument_kind::narrow_string, unbounded};
    } else if constexpr (fixed_wide_string_capacity<type>::value != 0) {
        return {argument_kind::wide_string, fixed_wide_string_capacity<type>::value - 1};
    } else {
        return {argument_kind::unsupported, 0};
    }
}

struct format_summary {
    size_t fixed_length;
    unsigned unbounded_arguments;
};

constexpr bool is_digit(wchar_t character) {
    return character >= L'0' && character <= L'9';
}

consteval format_summary check_format(const wchar_t *text, size_t length, const argument_info *arguments, size_t argument_count,
                                      size_t capacity) {
    if (argument_count > 32) {
        format_has_too_many_arguments();
    }
    format_summary summary{0, 0};
    size_t argument = 0;
    for (size_t position = 0; position < length; position++) {
        if (text[position] != L'%') {
            summary.fixed_length++;
            continue;
        }
        position++;
        if (position < length && text[position] == L'%') {
            summary.fixed_length++;
            continue;
        }
        bool alternate = false;
        while (position < length && (text[position] == L'-' || text[position] == L'#' || text[position] == L'0')) {
            alternate = alternate || text[position] == L'#';
            position++;
        }
        size_t width = 0;
        while (position < length && is_digit(text[position])) {
            width = width * 10 + (text[position++] - L'0');
        }
        bool has_precision = false;
        size_t precision = 0;
        if (position < length && text[position] == L'.') {
            has_precision = true;
            position++;
            while (position < length && is_digit(text[position])) {
                precision = precision * 10 + (text[position++] - L'0');
            }
        }
        bool long_prefix = position < length && text[position] == L'l';
        if (long_prefix) {
            position++;
        }
        if (position >= length) {
            format_conversion_is_not_supported_by_wsprintfW();
        }
        wchar_t conversion = text[position];
        if (argument >= argument_count) {
            format_has_more_conversions_than_arguments();
        }
        argument_info given = arguments[argument];
        if (given.kind == argument_kind::unsupported) {
            format_argument_type_is_not_supported_by_wsprintfW();
        }
        size_t longest = 0;
        switch (conversion) {
        case L'd':
        case L'i':
        case L'u':
        case L'x':
        case L'X':
            if (given.kind != argument_kind::integer && given.kind != argument_kind::character) {
                format_argument_does_not_match_its_conversion();
            }
            longest = conversion == L'x' || conversion == L'X' ? 8 + (alternate ? 2 : 0) : conversion == L'u' ? 10 : 11;
            if (has_precision && precision + 3 > longest) {
                longest = precision + 3;
            }
            break;
        case L'c':
            if (long_prefix || (given.kind != argument_kind::character && given.kind != argument_kind::integer)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = 1;
            break;
        case L's':
        case L'S':
            if (long_prefix || given.kind != (conversion == L's' ? argument_kind::wide_string : argument_kind::narrow_string)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = given.longest;
            if (has_precision && (longest == unbounded || precision < longest)) {
                longest = precision;
            }
            break;
        default:
            format_conversion_is_not_supported_by_wsprintfW();
        }
        if (longest == unbounded) {
            summary.unbounded_arguments |= 1u << argument;
            longest = width;
        } else if (width > longest) {
            longest = width;
        }
        summary.fixed_length += longest;
        argument++;
    }
    if (argument < argument_count) {
        format_has_more_arguments_than_conversions();
    }
    if (summary.unbounded_arguments == 0 && summary.fixed_length > capacity) {
        format_output_may_not_fit_in_the_capacity();
    }
    return summary;
}

template <typename T>
constexpr bool is_signed_argument() {
    if constexpr (enumeration<T>) {
        return __is_signed(__underlying_type(T));
    } else {
        return __is_signed(T);
    }
}

template <typename T>
constexpr auto vararg(const T &value) {
    using type = decay_t<T>;
    if constexpr (fixed_wide_string_capacity<type>::value != 0) {
        return value.c_str();
    } else if constexpr (__is_pointer(type)) {
        const auto *pointer = value;
        return pointer;
    } else if constexpr (is_signed_argument<type>()) {
        return static_cast<int>(value);
    } else {
        return static_cast<unsigned>(value);
    }
}

template <size_t Value>
struct size_identity {
    static constexpr size_t value = Value;
};

template <typename T>
size_t unbounded_length(const T &value) {
    using type = decay_t<T>;
    if constexpr (same_as<type, wchar_t *> || same_as<type, const wchar_t *>) {
        return value ? __builtin_wcslen(value) : 6;
    } else if constexpr (same_as<type, char *> || same_as<type, const char *>) {
        return value ? __builtin_strlen(value) : 6;
    } else {
        return 0;
    }
}

[[gnu::noinline]] inline size_t format_through_heap(wchar_t *output, size_t capacity, size_t needed, const wchar_t *text, ...) {
    wchar_t *scratch = static_cast<wchar_t *>(LocalAlloc(LMEM_FIXED, (needed + 1) * sizeof(wchar_t)));
    size_t length = 0;
    if (scratch) {
        va_list arguments;
        va_start(arguments, text);
        int written = wvsprintfW(scratch, text, arguments);
        va_end(arguments);
        length = written > 0 ? static_cast<size_t>(written) : 0;
        if (length > capacity) {
            length = capacity;
        }
        for (size_t index = 0; index < length; index++) {
            output[index] = scratch[index];
        }
        LocalFree(scratch);
    }
    output[length] = 0;
    return length;
}

}

/**
 * A format string for wsprintfW, checked at compile time against the
 * argument types and against Capacity.
 *
 * Conversions are %[-][#][0][width][.precision][l]type, with type one of
 * d, i, u, x, X (integers up to 32 bits), c (a character), s (a wide string:
 * const wchar_t * or wstring<N>), S (a narrow const char *) and %%. There's no
 * floating point.
 */
template <size_t Capacity, typename... Args>
class basic_format_string {
public:
    template <size_t Length>
    consteval basic_format_string(const wchar_t (&format)[Length]) : text(format) {
        constexpr detail::argument_info arguments[] = {detail::describe_argument<Args>()..., {detail::argument_kind::unsupported, 0}};
        summary = detail::check_format(format, Length - 1, arguments, sizeof...(Args), Capacity - 1);
    }

    const wchar_t *text;
    detail::format_summary summary;
};

template <size_t Capacity, typename... Args>
using format_string = basic_format_string<detail::size_identity<Capacity>::value, type_identity_t<Args>...>;

/**
 * Formats into output with wsprintfW, replacing what it held. Returns false
 * if the result was truncated to fit, which can only happen with a const
 * wchar_t * or const char * argument and no precision.
 */
template <size_t Capacity, typename... Args>
bool format_to(wstring<Capacity> &output, format_string<Capacity, Args...> format, const Args &...arguments) {
    size_t needed = format.summary.fixed_length;
    if (format.summary.unbounded_arguments) {
        unsigned index = 0;
        ((needed += (format.summary.unbounded_arguments >> index++) & 1 ? detail::unbounded_length(arguments) : 0), ...);
        if (needed > output.capacity()) {
            output.resize(detail::format_through_heap(output.buffer(), output.capacity(), needed, format.text, detail::vararg(arguments)...));
            return false;
        }
    }
    output.resize(static_cast<size_t>(wsprintfW(output.buffer(), format.text, detail::vararg(arguments)...)));
    return true;
}

/**
 * Formats with wsprintfW into a new wstring<Capacity>.
 *
 *     auto text = grimace::format<64>(L"Taps: %d", tap_count);
 */
template <size_t Capacity = 128, typename... Args>
wstring<Capacity> format(format_string<Capacity, Args...> format, const Args &...arguments) {
    wstring<Capacity> output;
    format_to(output, format, arguments...);
    return output;
}

}

#endif

#ifndef GRIMACE_CXX_DETAIL_FORMAT_SNWPRINTF_H
#define GRIMACE_CXX_DETAIL_FORMAT_SNWPRINTF_H

#include <stdarg.h>
#include <grimace/cxx/fixed_string.h>
#include <windows.h>

namespace grimace {

namespace detail {

void format_has_more_conversions_than_arguments();
void format_has_more_arguments_than_conversions();
void format_argument_does_not_match_its_conversion();
void format_conversion_is_not_supported();
void format_argument_type_is_not_supported();
void format_star_width_or_precision_is_not_supported();
void format_64_bit_integer_needs_the_I64_prefix();
void format_output_may_not_fit_in_the_capacity();

enum class argument_kind { integer, integer64, floating, character, wide_string, narrow_string, pointer, unsupported };

struct argument_info {
    argument_kind kind;
    size_t longest;
};

template <typename T>
struct fixed_string_traits {
    static constexpr size_t capacity = 0;
    static constexpr bool wide = false;
};

template <typename Character, size_t Capacity>
struct fixed_string_traits<basic_fixed_string<Character, Capacity>> {
    static constexpr size_t capacity = Capacity;
    static constexpr bool wide = same_as<Character, wchar_t>;
};

constexpr size_t unbounded = static_cast<size_t>(-1);

template <typename T>
consteval argument_info describe_argument() {
    using type = decay_t<T>;
    if constexpr (same_as<type, wchar_t> || same_as<type, char>) {
        return {argument_kind::character, 0};
    } else if constexpr ((integral<type> || enumeration<type>) && sizeof(type) <= 4) {
        return {argument_kind::integer, 0};
    } else if constexpr ((integral<type> || enumeration<type>) && sizeof(type) == 8) {
        return {argument_kind::integer64, 0};
    } else if constexpr (same_as<type, float> || same_as<type, double> || same_as<type, long double>) {
        return {argument_kind::floating, 0};
    } else if constexpr (same_as<type, wchar_t *> || same_as<type, const wchar_t *>) {
        return {argument_kind::wide_string, unbounded};
    } else if constexpr (same_as<type, char *> || same_as<type, const char *>) {
        return {argument_kind::narrow_string, unbounded};
    } else if constexpr (fixed_string_traits<type>::capacity != 0) {
        return {fixed_string_traits<type>::wide ? argument_kind::wide_string : argument_kind::narrow_string, fixed_string_traits<type>::capacity - 1};
    } else if constexpr (__is_pointer(type) || same_as<type, decltype(nullptr)>) {
        return {argument_kind::pointer, 0};
    } else {
        return {argument_kind::unsupported, 0};
    }
}

struct format_summary {
    size_t fixed_length;
    bool may_truncate;
};

constexpr bool is_digit(wchar_t character) {
    return character >= L'0' && character <= L'9';
}

enum class size_prefix { none, h, l, L, I64 };

constexpr bool is_integer_argument(argument_info given, size_prefix prefix) {
    if (prefix == size_prefix::I64) {
        return given.kind == argument_kind::integer64;
    }
    if (given.kind == argument_kind::integer64) {
        format_64_bit_integer_needs_the_I64_prefix();
    }
    return prefix != size_prefix::L && (given.kind == argument_kind::integer || given.kind == argument_kind::character);
}

consteval format_summary check_format(const wchar_t *text, size_t length, const argument_info *arguments, size_t argument_count,
                                      size_t capacity) {
    format_summary summary{0, false};
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
        bool sign = false;
        while (position < length && (text[position] == L'-' || text[position] == L'+' || text[position] == L' ' || text[position] == L'#' ||
                                     text[position] == L'0')) {
            alternate = alternate || text[position] == L'#';
            sign = sign || text[position] == L'+' || text[position] == L' ';
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
        if (position < length && text[position] == L'*') {
            format_star_width_or_precision_is_not_supported();
        }
        size_prefix prefix = size_prefix::none;
        if (position < length && text[position] == L'h') {
            prefix = size_prefix::h;
            position++;
        } else if (position < length && text[position] == L'l') {
            prefix = size_prefix::l;
            position++;
        } else if (position < length && text[position] == L'L') {
            prefix = size_prefix::L;
            position++;
        } else if (position + 2 < length && text[position] == L'I' && text[position + 1] == L'6' && text[position + 2] == L'4') {
            prefix = size_prefix::I64;
            position += 3;
        }
        if (position >= length) {
            format_conversion_is_not_supported();
        }
        wchar_t conversion = text[position];
        if (argument >= argument_count) {
            format_has_more_conversions_than_arguments();
        }
        argument_info given = arguments[argument];
        if (given.kind == argument_kind::unsupported) {
            format_argument_type_is_not_supported();
        }
        bool wide64 = prefix == size_prefix::I64;
        size_t longest = 0;
        switch (conversion) {
        case L'd':
        case L'i':
            if (!is_integer_argument(given, prefix)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = wide64 ? 20 : 11;
            break;
        case L'u':
            if (!is_integer_argument(given, prefix)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = wide64 ? 20 : 10;
            break;
        case L'o':
            if (!is_integer_argument(given, prefix)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = (wide64 ? 22 : 11) + (alternate ? 1 : 0);
            break;
        case L'x':
        case L'X':
            if (!is_integer_argument(given, prefix)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = (wide64 ? 16 : 8) + (alternate ? 2 : 0);
            break;
        case L'c':
        case L'C':
            if (prefix == size_prefix::L || prefix == size_prefix::I64 ||
                (given.kind != argument_kind::character && given.kind != argument_kind::integer)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = 1;
            break;
        case L's':
        case L'S': {
            bool wide = conversion == L's' ? prefix != size_prefix::h : prefix == size_prefix::l;
            if (prefix == size_prefix::L || prefix == size_prefix::I64 ||
                given.kind != (wide ? argument_kind::wide_string : argument_kind::narrow_string)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = given.longest;
            if (has_precision && (longest == unbounded || precision < longest)) {
                longest = precision;
            }
            break;
        }
        case L'e':
        case L'E':
        case L'g':
        case L'G':
            if ((prefix != size_prefix::none && prefix != size_prefix::L) || given.kind != argument_kind::floating) {
                format_argument_does_not_match_its_conversion();
            }
            longest = (has_precision ? (precision ? precision : 1) : 6) + 8;
            break;
        case L'f':
            if ((prefix != size_prefix::none && prefix != size_prefix::L) || given.kind != argument_kind::floating) {
                format_argument_does_not_match_its_conversion();
            }
            longest = unbounded;
            break;
        case L'p':
            if (prefix != size_prefix::none ||
                (given.kind != argument_kind::pointer && given.kind != argument_kind::wide_string && given.kind != argument_kind::narrow_string)) {
                format_argument_does_not_match_its_conversion();
            }
            longest = 8;
            break;
        default:
            format_conversion_is_not_supported();
        }
        if (longest != unbounded && sign && conversion != L'c' && conversion != L'C' && conversion != L's' && conversion != L'S') {
            longest++;
        }
        if (longest != unbounded && has_precision && conversion != L's' && conversion != L'S' && precision + 1 > longest) {
            longest = precision + 1;
        }
        if (longest == unbounded) {
            summary.may_truncate = true;
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
    if (!summary.may_truncate && summary.fixed_length > capacity) {
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
    if constexpr (fixed_string_traits<type>::capacity != 0) {
        return value.c_str();
    } else if constexpr (__is_pointer(type)) {
        const auto *pointer = value;
        return pointer;
    } else if constexpr (same_as<type, decltype(nullptr)>) {
        return static_cast<const void *>(nullptr);
    } else if constexpr (same_as<type, float> || same_as<type, double> || same_as<type, long double>) {
        return static_cast<double>(value);
    } else if constexpr (sizeof(type) == 8) {
        if constexpr (is_signed_argument<type>()) {
            return static_cast<long long>(value);
        } else {
            return static_cast<unsigned long long>(value);
        }
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

}

/**
 * A printf format string for coredll's _snwprintf, checked at compile time
 * against the argument types and against Capacity.
 *
 * Conversions are %[flags][width][.precision][h|l|L|I64]type, with flags from
 * - + space # 0 and type one of d, i, u, o, x, X (integers up to 32 bits, or
 * 64 bits with I64), c or C (a character), s (a wide string: const wchar_t *
 * or wstring<N>), S or hs (a narrow string: const char * or string<N>), e, E,
 * f, g, G (float or double) and p (a pointer), plus %%. * widths, %n and a
 * 64-bit integer without I64 are compile errors.
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
 * Formats into output with _snwprintf, replacing what it held. Returns false
 * if the result was truncated to fit, which can only happen with %f, or a
 * const wchar_t * or const char * argument and no precision; other formats
 * that might not fit are compile errors.
 */
template <size_t Capacity, typename... Args>
bool format_to(wstring<Capacity> &output, format_string<Capacity, Args...> format, const Args &...arguments) {
    int written = _snwprintf(output.buffer(), output.capacity(), format.text, detail::vararg(arguments)...);
    if (written < 0) {
        output.resize(output.capacity());
        return false;
    }
    output.resize(static_cast<size_t>(written));
    return true;
}

/**
 * Formats with _snwprintf into a new wstring<Capacity>.
 *
 *     auto text = grimace::format<64>(L"Taps: %d, %.1f%%", tap_count, battery);
 */
template <size_t Capacity = 128, typename... Args>
wstring<Capacity> format(format_string<Capacity, Args...> format, const Args &...arguments) {
    wstring<Capacity> output;
    format_to(output, format, arguments...);
    return output;
}

}

#endif

#include <charconv>
#include <stdio.h>

namespace std {
inline namespace __1 {

namespace {

constexpr int double_digits = 17;
constexpr int float_digits = 9;

to_chars_result format_float(char *first, char *last, double value, char conversion, int precision) {
    char format[8] = {'%', '.', '*', conversion, 0};
    char buffer[400];
    int written = _snprintf(buffer, sizeof(buffer) - 1, format, precision, value);
    if (written < 0) {
        return {last, errc::value_too_large};
    }
    if (written > last - first) {
        return {last, errc::value_too_large};
    }
    for (int index = 0; index < written; index++) {
        first[index] = buffer[index];
    }
    return {first + written, errc{}};
}

to_chars_result format_shortest(char *first, char *last, double value, int digits) {
    return format_float(first, last, value, 'g', digits);
}

to_chars_result format_with(char *first, char *last, double value, chars_format format, int precision, int digits) {
    switch (format) {
    case chars_format::scientific:
        return format_float(first, last, value, 'e', precision < 0 ? digits - 1 : precision);
    case chars_format::fixed:
        return format_float(first, last, value, 'f', precision < 0 ? digits : precision);
    case chars_format::general:
        return format_float(first, last, value, 'g', precision < 0 ? digits : precision);
    default:
        return {last, errc::not_supported};
    }
}

}

to_chars_result to_chars(char *first, char *last, float value) {
    return format_shortest(first, last, value, float_digits);
}

to_chars_result to_chars(char *first, char *last, double value) {
    return format_shortest(first, last, value, double_digits);
}

to_chars_result to_chars(char *first, char *last, long double value) {
    return format_shortest(first, last, static_cast<double>(value), double_digits);
}

to_chars_result to_chars(char *first, char *last, float value, chars_format format) {
    return format_with(first, last, value, format, -1, float_digits);
}

to_chars_result to_chars(char *first, char *last, double value, chars_format format) {
    return format_with(first, last, value, format, -1, double_digits);
}

to_chars_result to_chars(char *first, char *last, long double value, chars_format format) {
    return format_with(first, last, static_cast<double>(value), format, -1, double_digits);
}

to_chars_result to_chars(char *first, char *last, float value, chars_format format, int precision) {
    return format_with(first, last, value, format, precision, float_digits);
}

to_chars_result to_chars(char *first, char *last, double value, chars_format format, int precision) {
    return format_with(first, last, value, format, precision, double_digits);
}

to_chars_result to_chars(char *first, char *last, long double value, chars_format format, int precision) {
    return format_with(first, last, static_cast<double>(value), format, precision, double_digits);
}

}
}

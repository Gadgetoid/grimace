#ifndef GRIMACE_CXX_UTF8_H
#define GRIMACE_CXX_UTF8_H

#include <grimace/cxx/fixed_string.h>

namespace grimace {

namespace detail {

constexpr char32_t replacement_character = 0xFFFD;

struct decoded {
    char32_t code_point;
    size_t length;
};

constexpr decoded decode_utf8(string_view input, size_t position) {
    unsigned char lead = static_cast<unsigned char>(input[position]);
    if (lead < 0x80) {
        return {lead, 1};
    }
    size_t length = 0;
    if (lead >= 0xC2 && lead <= 0xDF) {
        length = 2;
    } else if (lead >= 0xE0 && lead <= 0xEF) {
        length = 3;
    } else if (lead >= 0xF0 && lead <= 0xF4) {
        length = 4;
    }
    if (length == 0 || position + length > input.size()) {
        return {replacement_character, 1};
    }
    char32_t code_point = lead & (0x7F >> length);
    for (size_t index = 1; index < length; index++) {
        unsigned char next = static_cast<unsigned char>(input[position + index]);
        if ((next & 0xC0) != 0x80) {
            return {replacement_character, index};
        }
        code_point = (code_point << 6) | (next & 0x3F);
    }
    char32_t smallest = length == 2 ? 0x80 : length == 3 ? 0x800 : 0x10000;
    if (code_point < smallest || code_point > 0x10FFFF || (code_point >= 0xD800 && code_point < 0xE000)) {
        return {replacement_character, length};
    }
    return {code_point, length};
}

constexpr decoded decode_utf16(wstring_view input, size_t position) {
    char32_t unit = input[position];
    if (unit >= 0xD800 && unit < 0xDC00 && position + 1 < input.size()) {
        char32_t low = input[position + 1];
        if (low >= 0xDC00 && low < 0xE000) {
            return {0x10000 + ((unit - 0xD800) << 10) + (low - 0xDC00), 2};
        }
    }
    if (unit >= 0xD800 && unit < 0xE000) {
        return {replacement_character, 1};
    }
    return {unit, 1};
}

constexpr size_t utf16_units(char32_t code_point) {
    return code_point >= 0x10000 ? 2 : 1;
}

constexpr size_t utf8_units(char32_t code_point) {
    return code_point < 0x80 ? 1 : code_point < 0x800 ? 2 : code_point < 0x10000 ? 3 : 4;
}

}

/**
 * Converts UTF-8 to UTF-16, writing at most capacity units and never half a
 * surrogate pair. Invalid input becomes U+FFFD. Returns the units written; no
 * terminator is added. Pass a null output to measure.
 */
constexpr size_t utf8_to_utf16(string_view input, wchar_t *output, size_t capacity) {
    size_t written = 0;
    for (size_t position = 0; position < input.size();) {
        detail::decoded next = detail::decode_utf8(input, position);
        size_t units = detail::utf16_units(next.code_point);
        if (output) {
            if (written + units > capacity) {
                break;
            }
            if (units == 2) {
                char32_t offset = next.code_point - 0x10000;
                output[written] = static_cast<wchar_t>(0xD800 + (offset >> 10));
                output[written + 1] = static_cast<wchar_t>(0xDC00 + (offset & 0x3FF));
            } else {
                output[written] = static_cast<wchar_t>(next.code_point);
            }
        }
        written += units;
        position += next.length;
    }
    return written;
}

/**
 * Converts UTF-16 to UTF-8, writing at most capacity bytes and never part of
 * a character. Unpaired surrogates become U+FFFD. Returns the bytes written;
 * no terminator is added. Pass a null output to measure.
 */
constexpr size_t utf16_to_utf8(wstring_view input, char *output, size_t capacity) {
    size_t written = 0;
    for (size_t position = 0; position < input.size();) {
        detail::decoded next = detail::decode_utf16(input, position);
        size_t units = detail::utf8_units(next.code_point);
        if (output) {
            if (written + units > capacity) {
                break;
            }
            char32_t code_point = next.code_point;
            if (units == 1) {
                output[written] = static_cast<char>(code_point);
            } else {
                for (size_t index = units - 1; index > 0; index--) {
                    output[written + index] = static_cast<char>(0x80 | (code_point & 0x3F));
                    code_point >>= 6;
                }
                unsigned char lead = units == 2 ? 0xC0 : units == 3 ? 0xE0 : 0xF0;
                output[written] = static_cast<char>(lead | code_point);
            }
        }
        written += units;
        position += next.length;
    }
    return written;
}

/**
 * UTF-8 text as a wstring<Capacity>, truncated at a character boundary if it doesn't fit.
 */
template <size_t Capacity>
constexpr wstring<Capacity> to_wstring(string_view utf8) {
    wstring<Capacity> converted;
    converted.resize(utf8_to_utf16(utf8, converted.buffer(), converted.capacity()));
    return converted;
}

/**
 * UTF-16 text as a UTF-8 string<Capacity>, truncated at a character boundary if it doesn't fit.
 */
template <size_t Capacity>
constexpr string<Capacity> to_utf8(wstring_view utf16) {
    string<Capacity> converted;
    converted.resize(utf16_to_utf8(utf16, converted.buffer(), converted.capacity()));
    return converted;
}

}

#endif

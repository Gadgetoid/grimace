#ifndef GRIMACE_CXX_STRING_VIEW_H
#define GRIMACE_CXX_STRING_VIEW_H

#include <grimace/cxx/core.h>

namespace grimace {

/**
 * A pointer and length into characters someone else owns. Not necessarily
 * null-terminated: pass size() to APIs that take a length, such as DrawTextW.
 */
template <typename Character>
class basic_string_view {
public:
    static constexpr size_t npos = static_cast<size_t>(-1);

    constexpr basic_string_view() = default;

    constexpr basic_string_view(const Character *text, size_t length) : text(text), length(length) {}

    constexpr basic_string_view(const Character *text) : text(text), length(measure(text)) {}

    template <typename Text>
        requires requires(const Text &source) {
            { source.data() } -> convertible_to<const Character *>;
            { source.size() } -> convertible_to<size_t>;
        }
    constexpr basic_string_view(const Text &source) : text(source.data()), length(source.size()) {}

    constexpr const Character *data() const {
        return text;
    }

    constexpr size_t size() const {
        return length;
    }

    constexpr bool empty() const {
        return length == 0;
    }

    constexpr const Character *begin() const {
        return text;
    }

    constexpr const Character *end() const {
        return text + length;
    }

    constexpr Character operator[](size_t index) const {
        return text[index];
    }

    constexpr basic_string_view substr(size_t start, size_t count = npos) const {
        if (start > length) {
            start = length;
        }
        if (count > length - start) {
            count = length - start;
        }
        return {text + start, count};
    }

    constexpr bool starts_with(basic_string_view prefix) const {
        return prefix.length <= length && substr(0, prefix.length) == prefix;
    }

    constexpr bool ends_with(basic_string_view suffix) const {
        return suffix.length <= length && substr(length - suffix.length) == suffix;
    }

    constexpr size_t find(Character wanted, size_t start = 0) const {
        for (size_t index = start; index < length; index++) {
            if (text[index] == wanted) {
                return index;
            }
        }
        return npos;
    }

    constexpr size_t find(basic_string_view wanted, size_t start = 0) const {
        if (wanted.length > length) {
            return npos;
        }
        for (size_t index = start; index + wanted.length <= length; index++) {
            if (substr(index, wanted.length) == wanted) {
                return index;
            }
        }
        return npos;
    }

    friend constexpr bool operator==(basic_string_view first, basic_string_view second) {
        if (first.length != second.length) {
            return false;
        }
        for (size_t index = 0; index < first.length; index++) {
            if (first.text[index] != second.text[index]) {
                return false;
            }
        }
        return true;
    }

private:
    static constexpr size_t measure(const Character *text) {
        if (!text) {
            return 0;
        }
        if constexpr (same_as<Character, wchar_t>) {
            return __builtin_wcslen(text);
        } else {
            return __builtin_strlen(text);
        }
    }

    const Character *text = nullptr;
    size_t length = 0;
};

using wstring_view = basic_string_view<wchar_t>;
using string_view = basic_string_view<char>;

}

#endif

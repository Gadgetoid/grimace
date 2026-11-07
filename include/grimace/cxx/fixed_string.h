#ifndef GRIMACE_CXX_FIXED_STRING_H
#define GRIMACE_CXX_FIXED_STRING_H

#include <grimace/cxx/string_view.h>

namespace grimace {

/**
 * A string of up to Capacity - 1 characters, stored inline and always
 * null-terminated. Appending past the end truncates and returns false.
 */
template <typename Character, size_t Capacity>
class basic_fixed_string {
    static_assert(Capacity > 0, "a fixed string needs room for its terminator");

public:
    using view_type = basic_string_view<Character>;

    constexpr basic_fixed_string() {
        start_empty();
    }

    constexpr basic_fixed_string(view_type text) {
        start_empty();
        append(text);
    }

    constexpr basic_fixed_string(const Character *text) {
        start_empty();
        append(view_type(text));
    }

    static constexpr size_t capacity() {
        return Capacity - 1;
    }

    constexpr size_t size() const {
        return length;
    }

    constexpr bool empty() const {
        return length == 0;
    }

    constexpr const Character *c_str() const {
        return characters;
    }

    constexpr const Character *data() const {
        return characters;
    }

    /**
     * The buffer, for APIs that write into it. Call resize() after, with the length they wrote.
     */
    constexpr Character *buffer() {
        return characters;
    }

    constexpr view_type view() const {
        return view_type(characters, length);
    }

    constexpr const Character *begin() const {
        return characters;
    }

    constexpr const Character *end() const {
        return characters + length;
    }

    constexpr Character operator[](size_t index) const {
        return characters[index];
    }

    constexpr void clear() {
        length = 0;
        characters[0] = 0;
    }

    /**
     * Sets the length, after writing through buffer(). Clamped to capacity().
     */
    constexpr void resize(size_t new_length) {
        length = new_length < capacity() ? new_length : capacity();
        characters[length] = 0;
    }

    constexpr bool append(view_type text) {
        size_t room = capacity() - length;
        size_t count = text.size() < room ? text.size() : room;
        for (size_t index = 0; index < count; index++) {
            characters[length + index] = text[index];
        }
        length += count;
        characters[length] = 0;
        return count == text.size();
    }

    constexpr bool append(Character character) {
        if (length == capacity()) {
            return false;
        }
        characters[length++] = character;
        characters[length] = 0;
        return true;
    }

    constexpr basic_fixed_string &operator+=(view_type text) {
        append(text);
        return *this;
    }

    constexpr basic_fixed_string &operator+=(Character character) {
        append(character);
        return *this;
    }

    friend constexpr bool operator==(const basic_fixed_string &first, view_type second) {
        return first.view() == second;
    }

private:
    constexpr void start_empty() {
        if (__builtin_is_constant_evaluated()) {
            for (Character &character : characters) {
                character = 0;
            }
        }
        characters[0] = 0;
    }

    Character characters[Capacity];
    size_t length = 0;
};

template <size_t Capacity>
using wstring = basic_fixed_string<wchar_t, Capacity>;

template <size_t Capacity>
using string = basic_fixed_string<char, Capacity>;

}

#endif

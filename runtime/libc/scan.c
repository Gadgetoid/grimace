#include "internal.h"

#define NO_LIMIT 0x7FFFFFFF

static unsigned format_at(const void *format, int wide, size_t index) {
    return wide ? ((const grimace_wchar *)format)[index] : ((const unsigned char *)format)[index];
}

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

static int failure(struct grimace_reader *reader, size_t before, int converted_any, int assigned) {
    if (converted_any || reader->consumed != before) {
        return assigned;
    }
    int character = reader->next(reader);
    reader->back(reader, character);
    return character < 0 ? -1 : assigned;
}

static int skip_space(struct grimace_reader *reader) {
    int character;
    do {
        character = reader->next(reader);
    } while (is_space(character));
    reader->back(reader, character);
    return character;
}

static int in_set(const void *format, int wide, size_t start, size_t end, int character) {
    int invert = 0;
    if (format_at(format, wide, start) == '^') {
        invert = 1;
        start++;
    }
    int found = 0;
    for (size_t index = start; index < end; index++) {
        unsigned first = format_at(format, wide, index);
        if (index + 2 < end && format_at(format, wide, index + 1) == '-') {
            unsigned last = format_at(format, wide, index + 2);
            if ((unsigned)character >= first && (unsigned)character <= last) {
                found = 1;
            }
            index += 2;
        } else if ((unsigned)character == first) {
            found = 1;
        }
    }
    return found != invert;
}

static void store_character(void *target, int wide_target, size_t index, int character) {
    if (wide_target) {
        ((grimace_wchar *)target)[index] = (grimace_wchar)character;
    } else {
        ((char *)target)[index] = (char)(character < 256 ? character : '?');
    }
}

int __grimace_scan(struct grimace_reader *reader, const void *format, int wide_format, va_list arguments) {
    size_t index = 0;
    int assigned = 0;
    int converted_any = 0;
    unsigned character;
    reader->consumed = 0;
    while ((character = format_at(format, wide_format, index++)) != 0) {
        if (is_space((int)character)) {
            skip_space(reader);
            continue;
        }
        if (character != '%' || format_at(format, wide_format, index) == '%') {
            if (character == '%') {
                index++;
                skip_space(reader);
            }
            int input = reader->next(reader);
            if (input != (int)character) {
                reader->back(reader, input);
                return input < 0 && !converted_any ? -1 : assigned;
            }
            continue;
        }
        int suppress = 0;
        if (format_at(format, wide_format, index) == '*') {
            suppress = 1;
            index++;
        }
        int width = 0;
        while (format_at(format, wide_format, index) >= '0' && format_at(format, wide_format, index) <= '9') {
            width = width * 10 + (int)(format_at(format, wide_format, index++) - '0');
        }
        int size = 0;
        unsigned next = format_at(format, wide_format, index);
        if (next == 'h') {
            size = 'h';
            index++;
        } else if (next == 'l' || next == 'w') {
            size = 'l';
            index++;
            if (format_at(format, wide_format, index) == 'l') {
                size = 'q';
                index++;
            }
        } else if (next == 'L') {
            size = 'L';
            index++;
        } else if (next == 'I' && format_at(format, wide_format, index + 1) == '6' && format_at(format, wide_format, index + 2) == '4') {
            size = 'q';
            index += 3;
        }
        unsigned conversion = format_at(format, wide_format, index++);
        if (conversion == 0) {
            break;
        }
        if (conversion == 'n') {
            if (!suppress) {
                *va_arg(arguments, int *) = (int)reader->consumed;
            }
            continue;
        }
        if (conversion != 'c' && conversion != 'C' && conversion != '[') {
            if (skip_space(reader) < 0) {
                return converted_any ? assigned : -1;
            }
        }
        size_t before = reader->consumed;
        switch (conversion) {
        case 'd':
        case 'i':
        case 'u':
        case 'o':
        case 'x':
        case 'X':
        case 'p': {
            int base = conversion == 'd' || conversion == 'u' ? 10 : conversion == 'i' ? 0 : conversion == 'o' ? 8 : 16;
            int negative;
            int overflow;
            int valid;
            unsigned long long value = __grimace_parse_integer(reader, base, width ? width : NO_LIMIT, &negative, &overflow, &valid);
            if (!valid) {
                return failure(reader, before, converted_any, assigned);
            }
            converted_any = 1;
            if (negative) {
                value = 0ull - value;
            }
            if (!suppress) {
                if (conversion == 'p') {
                    *va_arg(arguments, void **) = (void *)(uintptr_t)value;
                } else if (size == 'q') {
                    *va_arg(arguments, unsigned long long *) = value;
                } else if (size == 'h') {
                    *va_arg(arguments, unsigned short *) = (unsigned short)value;
                } else {
                    *va_arg(arguments, unsigned int *) = (unsigned int)value;
                }
                assigned++;
            }
            break;
        }
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G': {
            char text[128];
            if (!__grimace_parse_double_text(reader, text, sizeof text, width ? width : NO_LIMIT)) {
                return failure(reader, before, converted_any, assigned);
            }
            converted_any = 1;
            const char *end;
            double value = __grimace_parse_double(text, &end);
            if (!suppress) {
                if (size == 'l' || size == 'L') {
                    *va_arg(arguments, double *) = value;
                } else {
                    *va_arg(arguments, float *) = (float)value;
                }
                assigned++;
            }
            break;
        }
        case 'c':
        case 'C':
        case 's':
        case 'S':
        case '[': {
            size_t set_start = index;
            size_t set_end = index;
            if (conversion == '[') {
                if (format_at(format, wide_format, set_end) == '^') {
                    set_end++;
                }
                if (format_at(format, wide_format, set_end) == ']') {
                    set_end++;
                }
                while (format_at(format, wide_format, set_end) && format_at(format, wide_format, set_end) != ']') {
                    set_end++;
                }
                index = format_at(format, wide_format, set_end) ? set_end + 1 : set_end;
            }
            int lower_conversion = conversion == 'C' ? 'c' : conversion == 'S' ? 's' : (int)conversion;
            int wide_target = conversion == 'c' || conversion == 's' || conversion == '['
                                  ? (size == 'l' || (wide_format && size != 'h'))
                                  : (wide_format ? size == 'l' : size != 'h');
            void *target = suppress ? NULL : va_arg(arguments, void *);
            int limit = width ? width : lower_conversion == 'c' ? 1 : NO_LIMIT;
            size_t count = 0;
            int input;
            while ((int)count < limit && (input = reader->next(reader)) >= 0) {
                int accept = lower_conversion == 'c' ? 1 : lower_conversion == 's' ? !is_space(input) : in_set(format, wide_format, set_start, set_end, input);
                if (!accept) {
                    reader->back(reader, input);
                    break;
                }
                if (target) {
                    store_character(target, wide_target, count, input);
                }
                count++;
            }
            if (!count) {
                return failure(reader, before, converted_any, assigned);
            }
            converted_any = 1;
            if (target) {
                if (lower_conversion != 'c') {
                    store_character(target, wide_target, count, 0);
                }
                assigned++;
            }
            break;
        }
        default:
            return assigned;
        }
    }
    return assigned;
}

static int next_narrow(struct grimace_reader *reader) {
    const unsigned char *text = reader->state;
    if (!*text) {
        return -1;
    }
    reader->state = (void *)(text + 1);
    reader->consumed++;
    return *text;
}

static void back_narrow(struct grimace_reader *reader, int character) {
    if (character >= 0) {
        reader->state = (void *)((const unsigned char *)reader->state - 1);
        reader->consumed--;
    }
}

static int next_wide(struct grimace_reader *reader) {
    const grimace_wchar *text = reader->state;
    if (!*text) {
        return -1;
    }
    reader->state = (void *)(text + 1);
    reader->consumed++;
    return *text;
}

static void back_wide(struct grimace_reader *reader, int character) {
    if (character >= 0) {
        reader->state = (void *)((const grimace_wchar *)reader->state - 1);
        reader->consumed--;
    }
}

struct grimace_reader *__grimace_string_reader(struct grimace_reader *reader, const void *text, int wide) {
    reader->next = wide ? next_wide : next_narrow;
    reader->back = wide ? back_wide : back_narrow;
    reader->state = (void *)text;
    reader->consumed = 0;
    return reader;
}

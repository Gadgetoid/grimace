#include "internal.h"

#define LEFT 1
#define PLUS 2
#define SPACE 4
#define ALTERNATE 8
#define ZERO 16

struct spec {
    int flags;
    int width;
    int precision;
};

static unsigned format_at(const void *format, int wide, size_t index) {
    return wide ? ((const grimace_wchar *)format)[index] : ((const unsigned char *)format)[index];
}

static void repeat(struct grimace_output *output, unsigned character, int count) {
    while (count-- > 0) {
        output->put(output, character);
    }
}

static void pad_before(struct grimace_output *output, const struct spec *spec, int length) {
    if (!(spec->flags & LEFT)) {
        repeat(output, ' ', spec->width - length);
    }
}

static void pad_after(struct grimace_output *output, const struct spec *spec, int length) {
    if (spec->flags & LEFT) {
        repeat(output, ' ', spec->width - length);
    }
}

static void put_text(struct grimace_output *output, const struct spec *spec, const void *text, int wide_text) {
    static const char null_text[] = "(null)";
    if (!text) {
        text = null_text;
        wide_text = 0;
    }
    int length = 0;
    while ((spec->precision < 0 || length < spec->precision) && format_at(text, wide_text, (size_t)length)) {
        length++;
    }
    pad_before(output, spec, length);
    for (int index = 0; index < length; index++) {
        output->put(output, format_at(text, wide_text, (size_t)index));
    }
    pad_after(output, spec, length);
}

static void put_number(struct grimace_output *output, const struct spec *spec, const char *prefix, const char *digits, int count, int zeros) {
    int prefix_length = 0;
    while (prefix[prefix_length]) {
        prefix_length++;
    }
    int length = prefix_length + zeros + count;
    int fill = (spec->flags & ZERO) && !(spec->flags & LEFT) && spec->width > length ? spec->width - length : 0;
    pad_before(output, spec, length + fill);
    for (int index = 0; index < prefix_length; index++) {
        output->put(output, (unsigned char)prefix[index]);
    }
    repeat(output, '0', fill + zeros);
    for (int index = 0; index < count; index++) {
        output->put(output, (unsigned char)digits[index]);
    }
    pad_after(output, spec, length + fill);
}

static void format_integer(struct grimace_output *output, struct spec *spec, unsigned long long value, int negative, unsigned conversion) {
    char digits[24];
    int count = 0;
    unsigned base = conversion == 'o' ? 8 : conversion == 'x' || conversion == 'X' || conversion == 'p' ? 16 : 10;
    const char *alphabet = conversion == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
    char reversed[24];
    while (value) {
        reversed[count++] = alphabet[value % base];
        value /= base;
    }
    for (int index = 0; index < count; index++) {
        digits[index] = reversed[count - 1 - index];
    }
    int zeros = 0;
    if (spec->precision >= 0) {
        spec->flags &= ~ZERO;
        if (spec->precision > count) {
            zeros = spec->precision - count;
        }
    } else if (count == 0) {
        zeros = 1;
    }
    const char *prefix = "";
    if (negative) {
        prefix = "-";
    } else if ((conversion == 'd' || conversion == 'i') && (spec->flags & PLUS)) {
        prefix = "+";
    } else if ((conversion == 'd' || conversion == 'i') && (spec->flags & SPACE)) {
        prefix = " ";
    } else if ((spec->flags & ALTERNATE) && count) {
        if (conversion == 'x') {
            prefix = "0x";
        } else if (conversion == 'X') {
            prefix = "0X";
        } else if (conversion == 'o' && !zeros) {
            prefix = "0";
        }
    }
    put_number(output, spec, prefix, digits, count, zeros);
}

static void put_exponent(char *text, int *length, int exponent, unsigned conversion) {
    text[(*length)++] = (char)(conversion == 'E' || conversion == 'G' ? 'E' : 'e');
    text[(*length)++] = exponent < 0 ? '-' : '+';
    if (exponent < 0) {
        exponent = -exponent;
    }
    text[(*length)++] = (char)('0' + exponent / 100);
    text[(*length)++] = (char)('0' + exponent / 10 % 10);
    text[(*length)++] = (char)('0' + exponent % 10);
}

static int digit_at(const struct grimace_decimal *decimal, int index) {
    return index >= 0 && index < decimal->count ? decimal->digits[index] : '0';
}

static void format_float(struct grimace_output *output, struct spec *spec, double value, unsigned conversion) {
    struct grimace_decimal decimal;
    char text[400];
    int length = 0;
    __grimace_decimal_exact(value, &decimal);
    const char *sign = decimal.negative ? "-" : (spec->flags & PLUS) ? "+" : (spec->flags & SPACE) ? " " : "";
    if (decimal.infinite || decimal.nan) {
        const char *word = decimal.infinite ? "1.#INF" : "1.#QNAN";
        struct spec plain = {spec->flags & ~ZERO, spec->width, -1};
        int sign_length = *sign ? 1 : 0;
        pad_before(output, &plain, sign_length + (decimal.infinite ? 6 : 7));
        if (sign_length) {
            output->put(output, (unsigned char)*sign);
        }
        while (*word) {
            output->put(output, (unsigned char)*word++);
        }
        pad_after(output, &plain, sign_length + (decimal.infinite ? 6 : 7));
        return;
    }
    int precision = spec->precision < 0 ? 6 : spec->precision;
    unsigned style = conversion;
    int strip = 0;
    if (conversion == 'g' || conversion == 'G') {
        if (precision == 0) {
            precision = 1;
        }
        struct grimace_decimal rounded = decimal;
        __grimace_decimal_round(&rounded, precision);
        int exponent = rounded.count ? rounded.point - 1 : 0;
        if (exponent < -4 || exponent >= precision) {
            style = conversion == 'g' ? 'e' : 'E';
            precision -= 1;
        } else {
            style = 'f';
            precision -= exponent + 1;
        }
        strip = !(spec->flags & ALTERNATE);
    }
    if (style == 'f') {
        __grimace_decimal_round(&decimal, decimal.point + precision);
        int point = decimal.count ? decimal.point : 1;
        if (point <= 0) {
            text[length++] = '0';
        }
        for (int index = 0; index < point && length < 350; index++) {
            text[length++] = (char)digit_at(&decimal, index);
        }
        int fraction_start = length;
        if (precision || (spec->flags & ALTERNATE)) {
            text[length++] = '.';
        }
        for (int index = 0; index < precision && length < 395; index++) {
            text[length++] = (char)digit_at(&decimal, point + index);
        }
        if (strip) {
            while (length > fraction_start + 1 && text[length - 1] == '0') {
                length--;
            }
            if (length == fraction_start + 1) {
                length--;
            }
        }
    } else {
        __grimace_decimal_round(&decimal, precision + 1);
        int exponent = decimal.count ? decimal.point - 1 : 0;
        text[length++] = (char)digit_at(&decimal, 0);
        int fraction_start = length;
        if (precision || (spec->flags & ALTERNATE)) {
            text[length++] = '.';
        }
        for (int index = 1; index <= precision && length < 380; index++) {
            text[length++] = (char)digit_at(&decimal, index);
        }
        if (strip) {
            while (length > fraction_start + 1 && text[length - 1] == '0') {
                length--;
            }
            if (length == fraction_start + 1) {
                length--;
            }
        }
        put_exponent(text, &length, exponent, style);
    }
    put_number(output, spec, sign, text, length, 0);
}

static int read_number(const void *format, int wide, size_t *index) {
    int value = 0;
    unsigned character;
    while ((character = format_at(format, wide, *index)) >= '0' && character <= '9') {
        if (value < 100000) {
            value = value * 10 + (int)(character - '0');
        }
        (*index)++;
    }
    return value;
}

int __grimace_format(struct grimace_output *output, const void *format, int wide_format, va_list arguments) {
    size_t index = 0;
    unsigned character;
    output->written = 0;
    while ((character = format_at(format, wide_format, index++)) != 0) {
        if (character != '%') {
            output->put(output, character);
            continue;
        }
        struct spec spec = {0, 0, -1};
        for (;; index++) {
            character = format_at(format, wide_format, index);
            if (character == '-') {
                spec.flags |= LEFT;
            } else if (character == '+') {
                spec.flags |= PLUS;
            } else if (character == ' ') {
                spec.flags |= SPACE;
            } else if (character == '#') {
                spec.flags |= ALTERNATE;
            } else if (character == '0') {
                spec.flags |= ZERO;
            } else {
                break;
            }
        }
        if (format_at(format, wide_format, index) == '*') {
            index++;
            spec.width = va_arg(arguments, int);
            if (spec.width < 0) {
                spec.flags |= LEFT;
                spec.width = -spec.width;
            }
        } else {
            spec.width = read_number(format, wide_format, &index);
        }
        if (format_at(format, wide_format, index) == '.') {
            index++;
            if (format_at(format, wide_format, index) == '*') {
                index++;
                spec.precision = va_arg(arguments, int);
                if (spec.precision < 0) {
                    spec.precision = -1;
                }
            } else {
                spec.precision = read_number(format, wide_format, &index);
            }
        }
        int size = 0;
        character = format_at(format, wide_format, index);
        if (character == 'h') {
            size = 'h';
            index++;
        } else if (character == 'l' || character == 'w') {
            size = 'l';
            index++;
            if (format_at(format, wide_format, index) == 'l') {
                size = 'q';
                index++;
            }
        } else if (character == 'L') {
            size = 'L';
            index++;
        } else if (character == 'I' && format_at(format, wide_format, index + 1) == '6' && format_at(format, wide_format, index + 2) == '4') {
            size = 'q';
            index += 3;
        } else if (character == 'I' && format_at(format, wide_format, index + 1) == '3' && format_at(format, wide_format, index + 2) == '2') {
            index += 3;
        }
        unsigned conversion = format_at(format, wide_format, index++);
        switch (conversion) {
        case 'd':
        case 'i': {
            long long value = size == 'q' ? va_arg(arguments, long long) : va_arg(arguments, int);
            if (size == 'h') {
                value = (short)value;
            }
            format_integer(output, &spec, value < 0 ? 0ull - (unsigned long long)value : (unsigned long long)value, value < 0, conversion);
            break;
        }
        case 'u':
        case 'o':
        case 'x':
        case 'X': {
            unsigned long long value = size == 'q' ? va_arg(arguments, unsigned long long) : va_arg(arguments, unsigned int);
            if (size == 'h') {
                value = (unsigned short)value;
            }
            format_integer(output, &spec, value, 0, conversion);
            break;
        }
        case 'p': {
            struct spec pointer = spec;
            pointer.precision = (int)(sizeof(void *) * 2);
            format_integer(output, &pointer, (uintptr_t)va_arg(arguments, void *), 0, 'X');
            break;
        }
        case 'c':
        case 'C': {
            int wide_character = conversion == 'c' ? (size == 'l' || (wide_format && size != 'h')) : (wide_format ? size == 'l' : size != 'h');
            unsigned value = (unsigned)va_arg(arguments, int);
            value = wide_character ? (value & 0xFFFF) : (value & 0xFF);
            struct spec plain = {spec.flags, spec.width, -1};
            pad_before(output, &plain, 1);
            output->put(output, value);
            pad_after(output, &plain, 1);
            break;
        }
        case 's':
        case 'S': {
            int wide_text = conversion == 's' ? (size == 'l' || (wide_format && size != 'h')) : (wide_format ? size == 'l' : size != 'h');
            put_text(output, &spec, va_arg(arguments, const void *), wide_text);
            break;
        }
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            format_float(output, &spec, va_arg(arguments, double), conversion);
            break;
        case 'n':
            if (size == 'h') {
                *va_arg(arguments, short *) = (short)output->written;
            } else {
                *va_arg(arguments, int *) = (int)output->written;
            }
            break;
        case 0:
            return (int)output->written;
        default:
            output->put(output, conversion);
            break;
        }
    }
    return (int)output->written;
}

struct buffer_output {
    struct grimace_output output;
    void *buffer;
    size_t capacity;
    int wide;
};

static void put_buffer(struct grimace_output *output, unsigned character) {
    struct buffer_output *target = (struct buffer_output *)output;
    if (output->written < target->capacity) {
        if (target->wide) {
            ((grimace_wchar *)target->buffer)[output->written] = (grimace_wchar)character;
        } else {
            ((char *)target->buffer)[output->written] = (char)(character < 256 ? character : '?');
        }
    }
    output->written++;
}

int __grimace_format_buffer(void *buffer, size_t capacity, int wide, const void *format, int wide_format, va_list arguments) {
    struct buffer_output target = {{put_buffer, 0}, buffer, capacity, wide};
    int length = __grimace_format(&target.output, format, wide_format, arguments);
    if ((size_t)length < capacity) {
        if (wide) {
            ((grimace_wchar *)buffer)[length] = 0;
        } else {
            ((char *)buffer)[length] = 0;
        }
        return length;
    }
    return (size_t)length == capacity ? length : -1;
}

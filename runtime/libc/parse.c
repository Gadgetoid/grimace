#include "internal.h"

#define SIGNIFICANT_DIGITS 40
#define HIDDEN_BIT (1ull << 52)

static const double powers_of_ten[] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11,
                                       1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22};

int *_errno(void);

static int lower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;
}

static int is_space(int character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

static int matches(const char *text, const char *word) {
    while (*word) {
        if (lower((unsigned char)*text++) != *word++) {
            return 0;
        }
    }
    return 1;
}

struct decimal_value {
    char digits[SIGNIFICANT_DIGITS + 1];
    int count;
    int exponent;
};

static int compare_with(const struct decimal_value *value, uint64_t mantissa, int binary_exponent) {
    struct grimace_big left;
    struct grimace_big right;
    __grimace_big_set(&left, 0);
    for (int index = 0; index < value->count; index++) {
        __grimace_big_multiply_small(&left, 10);
        __grimace_big_add_small(&left, (uint32_t)(value->digits[index] - '0'));
    }
    __grimace_big_set(&right, mantissa);
    if (value->exponent >= 0) {
        __grimace_big_multiply_power5(&left, (unsigned)value->exponent);
        __grimace_big_shift_left(&left, (unsigned)value->exponent);
    } else {
        __grimace_big_multiply_power5(&right, (unsigned)-value->exponent);
        __grimace_big_shift_left(&right, (unsigned)-value->exponent);
    }
    if (binary_exponent >= 0) {
        __grimace_big_shift_left(&right, (unsigned)binary_exponent);
    } else {
        __grimace_big_shift_left(&left, (unsigned)-binary_exponent);
    }
    return __grimace_big_compare(&left, &right);
}

static double approximate(const struct decimal_value *value) {
    uint64_t leading = 0;
    int used = value->count < 19 ? value->count : 19;
    for (int index = 0; index < used; index++) {
        leading = leading * 10 + (uint64_t)(value->digits[index] - '0');
    }
    double result = (double)leading;
    int exponent = value->exponent + (value->count - used);
    while (exponent > 0 && result <= 1.7976931348623157e308) {
        int step = exponent > 22 ? 22 : exponent;
        result *= powers_of_ten[step];
        exponent -= step;
    }
    while (exponent < 0 && result > 0) {
        int step = -exponent > 22 ? 22 : -exponent;
        result /= powers_of_ten[step];
        exponent += step;
    }
    return result;
}

static double nearest(const struct decimal_value *value) {
    double guess = approximate(value);
    uint64_t mantissa;
    int exponent;
    if (guess > 1.7976931348623157e308) {
        mantissa = (1ull << 53) - 1;
        exponent = 971;
    } else {
        union {
            double number;
            uint64_t bits;
        } view = {guess};
        int biased = (int)(view.bits >> 52);
        mantissa = view.bits & (HIDDEN_BIT - 1);
        if (biased) {
            mantissa |= HIDDEN_BIT;
        }
        exponent = (biased ? biased : 1) - 1075;
    }
    for (int attempt = 0; attempt < 64; attempt++) {
        int above = compare_with(value, mantissa * 2 + 1, exponent - 1);
        if (above > 0 || (above == 0 && (mantissa & 1))) {
            mantissa++;
            if (mantissa == HIDDEN_BIT << 1) {
                mantissa = HIDDEN_BIT;
                exponent++;
            }
            if (exponent > 971) {
                return 1.0 / 0.0;
            }
            if (above > 0) {
                continue;
            }
            break;
        }
        if (!mantissa) {
            break;
        }
        int below;
        if (mantissa == HIDDEN_BIT && exponent > -1074) {
            below = compare_with(value, mantissa * 4 - 1, exponent - 2);
        } else {
            below = compare_with(value, mantissa * 2 - 1, exponent - 1);
        }
        if (below < 0 || (below == 0 && (mantissa & 1))) {
            mantissa--;
            if (mantissa < HIDDEN_BIT && exponent > -1074) {
                mantissa = (HIDDEN_BIT << 1) - 1;
                exponent--;
            }
            if (below < 0) {
                continue;
            }
        }
        break;
    }
    union {
        uint64_t bits;
        double number;
    } result;
    if (mantissa >= HIDDEN_BIT) {
        result.bits = (uint64_t)(exponent + 1075) << 52 | (mantissa - HIDDEN_BIT);
    } else {
        result.bits = mantissa;
    }
    return result.number;
}

double __grimace_parse_double(const char *text, const char **end) {
    const char *start = text;
    while (is_space((unsigned char)*text)) {
        text++;
    }
    int negative = 0;
    if (*text == '+' || *text == '-') {
        negative = *text++ == '-';
    }
    if (matches(text, "inf") || matches(text, "nan")) {
        int nan = lower((unsigned char)*text) == 'n';
        text += 3;
        if (!nan && matches(text, "inity")) {
            text += 5;
        }
        *end = text;
        double special = nan ? 0.0 / 0.0 : 1.0 / 0.0;
        return negative ? -special : special;
    }
    struct decimal_value value = {{0}, 0, 0};
    int any_digits = 0;
    int sticky = 0;
    int seen_point = 0;
    for (;; text++) {
        if (*text == '.' && !seen_point) {
            seen_point = 1;
            continue;
        }
        if (*text < '0' || *text > '9') {
            break;
        }
        any_digits = 1;
        if (*text == '0' && value.count == 0) {
            if (seen_point) {
                value.exponent--;
            }
            continue;
        }
        if (value.count < SIGNIFICANT_DIGITS) {
            value.digits[value.count++] = *text;
            if (seen_point) {
                value.exponent--;
            }
        } else {
            sticky |= *text != '0';
            if (!seen_point) {
                value.exponent++;
            }
        }
    }
    if (!any_digits) {
        *end = start;
        return 0.0;
    }
    if (lower((unsigned char)*text) == 'e' || lower((unsigned char)*text) == 'd') {
        const char *mark = text++;
        int exponent_negative = 0;
        if (*text == '+' || *text == '-') {
            exponent_negative = *text++ == '-';
        }
        if (*text >= '0' && *text <= '9') {
            long exponent = 0;
            while (*text >= '0' && *text <= '9') {
                if (exponent < 100000) {
                    exponent = exponent * 10 + (*text - '0');
                }
                text++;
            }
            value.exponent += (int)(exponent_negative ? -exponent : exponent);
        } else {
            text = mark;
        }
    }
    *end = text;
    if (!value.count) {
        return negative ? -0.0 : 0.0;
    }
    if (sticky) {
        value.digits[value.count++] = '1';
        value.exponent--;
    }
    double result;
    if (value.count + value.exponent > 310) {
        result = 1.0 / 0.0;
    } else if (value.count + value.exponent < -330) {
        result = 0.0;
    } else {
        result = nearest(&value);
    }
    if (result == 0.0 || result == 1.0 / 0.0) {
        *_errno() = 34;
    }
    return negative ? -result : result;
}

static int digit_value(int character, int base) {
    int value;
    if (character >= '0' && character <= '9') {
        value = character - '0';
    } else if (lower(character) >= 'a' && lower(character) <= 'z') {
        value = lower(character) - 'a' + 10;
    } else {
        return -1;
    }
    return value < base ? value : -1;
}

unsigned long long __grimace_parse_integer(struct grimace_reader *reader, int base, int width, int *negative, int *overflow, int *valid) {
    int character = reader->next(reader);
    int used = 0;
    unsigned long long value = 0;
    *negative = 0;
    *overflow = 0;
    *valid = 0;
    if ((character == '+' || character == '-') && used < width) {
        *negative = character == '-';
        used++;
        character = reader->next(reader);
    }
    if ((base == 0 || base == 16) && character == '0' && used < width) {
        used++;
        *valid = 1;
        character = reader->next(reader);
        if (lower(character) == 'x' && used < width) {
            used++;
            int after = reader->next(reader);
            if (digit_value(after, 16) < 0) {
                reader->back(reader, after);
                return 0;
            }
            base = 16;
            character = after;
        } else if (base == 0) {
            base = 8;
        }
    } else if (base == 0) {
        base = 10;
    }
    int digit;
    while (used < width && (digit = digit_value(character, base)) >= 0) {
        if (value > (~0ull - (unsigned)digit) / (unsigned)base) {
            *overflow = 1;
        } else {
            value = value * (unsigned)base + (unsigned)digit;
        }
        *valid = 1;
        used++;
        character = reader->next(reader);
    }
    reader->back(reader, character);
    return value;
}

int __grimace_parse_double_text(struct grimace_reader *reader, char *text, size_t capacity, int width) {
    size_t length = 0;
    int character = reader->next(reader);
    int seen_digit = 0;
    int seen_point = 0;
    int seen_exponent = 0;
    while (width-- > 0 && length + 1 < capacity) {
        if (character >= '0' && character <= '9') {
            seen_digit = 1;
        } else if ((character == '+' || character == '-') &&
                   (length == 0 || lower((unsigned char)text[length - 1]) == 'e' || lower((unsigned char)text[length - 1]) == 'd')) {
        } else if (character == '.' && !seen_point && !seen_exponent) {
            seen_point = 1;
        } else if ((lower(character) == 'e' || lower(character) == 'd') && seen_digit && !seen_exponent) {
            seen_exponent = 1;
        } else {
            break;
        }
        text[length++] = (char)character;
        character = reader->next(reader);
    }
    reader->back(reader, character);
    text[length] = 0;
    return seen_digit ? (int)length : 0;
}

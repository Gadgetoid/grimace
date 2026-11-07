#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

typedef unsigned short wchar_type;

double sqrt(double value);
double sin(double value);
double cos(double value);
double tan(double value);
double asin(double value);
double acos(double value);
double atan(double value);
double atan2(double y, double x);
double sinh(double value);
double cosh(double value);
double tanh(double value);
double exp(double value);
double log(double value);
double log10(double value);
double pow(double base, double exponent);
double floor(double value);
double ceil(double value);
double fmod(double dividend, double divisor);
double frexp(double value, int *exponent);
double ldexp(double value, int exponent);
double modf(double value, double *integer);
double _hypot(double x, double y);
double _copysign(double value, double sign);
int _vsnprintf(char *buffer, size_t count, const char *format, va_list arguments);
double strtod(const char *text, char **end);
double wcstod(const wchar_type *text, wchar_type **end);
int _vsnwprintf(wchar_type *buffer, size_t count, const wchar_type *format, va_list arguments);
int _isctype(int character, int type);
int iswctype(wchar_type character, wchar_type type);
size_t mbstowcs(wchar_type *destination, const char *source, size_t count);
int DeleteFileW(const wchar_type *path);
int MoveFileW(const wchar_type *existing, const wchar_type *replacement);

#define PATH_CHARACTERS 260

wchar_type *wmemchr(const wchar_type *memory, wchar_type value, size_t count) {
    for (; count; count--, memory++) {
        if (*memory == value) {
            return (wchar_type *)memory;
        }
    }
    return 0;
}

int wmemcmp(const wchar_type *first, const wchar_type *second, size_t count) {
    for (; count; count--, first++, second++) {
        if (*first != *second) {
            return *first < *second ? -1 : 1;
        }
    }
    return 0;
}

wchar_type *wmemcpy(wchar_type *destination, const wchar_type *source, size_t count) {
    wchar_type *output = destination;
    while (count--) {
        *output++ = *source++;
    }
    return destination;
}

wchar_type *wmemmove(wchar_type *destination, const wchar_type *source, size_t count) {
    if (destination < source) {
        return wmemcpy(destination, source, count);
    }
    while (count--) {
        destination[count] = source[count];
    }
    return destination;
}

wchar_type *wmemset(wchar_type *destination, wchar_type value, size_t count) {
    for (size_t index = 0; index < count; index++) {
        destination[index] = value;
    }
    return destination;
}

typedef struct {
    long long quot;
    long long rem;
} lldiv_type;

long long llabs(long long value) {
    return value < 0 ? -value : value;
}

lldiv_type lldiv(long long dividend, long long divisor) {
    lldiv_type result = {dividend / divisor, dividend % divisor};
    return result;
}

static int digit_value(unsigned character) {
    if (character >= '0' && character <= '9') {
        return character - '0';
    }
    if (character >= 'a' && character <= 'z') {
        return character - 'a' + 10;
    }
    if (character >= 'A' && character <= 'Z') {
        return character - 'A' + 10;
    }
    return 99;
}

static int is_space(unsigned character) {
    return character == ' ' || (character >= '\t' && character <= '\r');
}

#define PARSE_INTEGER(name, character_type)                                                                        \
    static unsigned long long name(const character_type *text, character_type **end, int base, int *negative,     \
                                   int *overflow) {                                                               \
        const character_type *position = text;                                                                    \
        unsigned long long value = 0;                                                                             \
        int any = 0;                                                                                              \
        *negative = 0;                                                                                            \
        *overflow = 0;                                                                                            \
        while (is_space(*position)) {                                                                             \
            position++;                                                                                           \
        }                                                                                                         \
        if (*position == '+' || *position == '-') {                                                               \
            *negative = *position == '-';                                                                         \
            position++;                                                                                           \
        }                                                                                                         \
        if ((base == 0 || base == 16) && position[0] == '0' && (position[1] == 'x' || position[1] == 'X') &&      \
            digit_value(position[2]) < 16) {                                                                      \
            position += 2;                                                                                        \
            base = 16;                                                                                            \
        } else if (base == 0) {                                                                                   \
            base = position[0] == '0' ? 8 : 10;                                                                   \
        }                                                                                                         \
        for (;; position++) {                                                                                     \
            int digit = digit_value(*position);                                                                   \
            if (digit >= base) {                                                                                  \
                break;                                                                                            \
            }                                                                                                     \
            any = 1;                                                                                              \
            if (value > (~0ULL - digit) / base) {                                                                 \
                *overflow = 1;                                                                                    \
            }                                                                                                     \
            value = value * base + digit;                                                                         \
        }                                                                                                         \
        if (end) {                                                                                                \
            *end = (character_type *)(any ? position : text);                                                    \
        }                                                                                                         \
        return value;                                                                                             \
    }

PARSE_INTEGER(parse_narrow, char)
PARSE_INTEGER(parse_wide, wchar_type)

static long long signed_result(unsigned long long value, int negative, int overflow) {
    if (overflow || (!negative && value > LLONG_MAX) || (negative && value > (unsigned long long)LLONG_MAX + 1)) {
        return negative ? LLONG_MIN : LLONG_MAX;
    }
    return negative ? (long long)(0 - value) : (long long)value;
}

static unsigned long long unsigned_result(unsigned long long value, int negative, int overflow) {
    if (overflow) {
        return ~0ULL;
    }
    return negative ? 0 - value : value;
}

long long strtoll(const char *text, char **end, int base) {
    int negative, overflow;
    unsigned long long value = parse_narrow(text, end, base, &negative, &overflow);
    return signed_result(value, negative, overflow);
}

unsigned long long strtoull(const char *text, char **end, int base) {
    int negative, overflow;
    unsigned long long value = parse_narrow(text, end, base, &negative, &overflow);
    return unsigned_result(value, negative, overflow);
}

long long atoll(const char *text) {
    return strtoll(text, 0, 10);
}

long long wcstoll(const wchar_type *text, wchar_type **end, int base) {
    int negative, overflow;
    unsigned long long value = parse_wide(text, end, base, &negative, &overflow);
    return signed_result(value, negative, overflow);
}

unsigned long long wcstoull(const wchar_type *text, wchar_type **end, int base) {
    int negative, overflow;
    unsigned long long value = parse_wide(text, end, base, &negative, &overflow);
    return unsigned_result(value, negative, overflow);
}

int vsnprintf(char *buffer, size_t count, const char *format, va_list arguments) {
    if (count == 0) {
        return 0;
    }
    int written = _vsnprintf(buffer, count - 1, format, arguments);
    if (written < 0 || (size_t)written >= count - 1) {
        buffer[count - 1] = 0;
        return written < 0 ? (int)count : written;
    }
    buffer[written] = 0;
    return written;
}

int snprintf(char *buffer, size_t count, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int written = vsnprintf(buffer, count, format, arguments);
    va_end(arguments);
    return written;
}

double trunc(double value) {
    return value < 0 ? ceil(value) : floor(value);
}

double round(double value) {
    return value < 0 ? ceil(value - 0.5) : floor(value + 0.5);
}

long lround(double value) {
    return (long)round(value);
}

long long llround(double value) {
    return (long long)round(value);
}

double fmin(double first, double second) {
    return first != first ? second : second != second ? first : first < second ? first : second;
}

double fmax(double first, double second) {
    return first != first ? second : second != second ? first : first > second ? first : second;
}

double fdim(double first, double second) {
    return first > second ? first - second : 0.0;
}

double log2(double value) {
    return log(value) * 1.4426950408889634;
}

double exp2(double value) {
    return pow(2.0, value);
}

double cbrt(double value) {
    return value < 0 ? -pow(-value, 1.0 / 3.0) : pow(value, 1.0 / 3.0);
}

double hypot(double x, double y) {
    return _hypot(x, y);
}

double copysign(double value, double sign) {
    return _copysign(value, sign);
}

float sqrtf(float value) {
    return (float)sqrt(value);
}

float sinf(float value) {
    return (float)sin(value);
}

float cosf(float value) {
    return (float)cos(value);
}

float tanf(float value) {
    return (float)tan(value);
}

float asinf(float value) {
    return (float)asin(value);
}

float acosf(float value) {
    return (float)acos(value);
}

float atanf(float value) {
    return (float)atan(value);
}

float sinhf(float value) {
    return (float)sinh(value);
}

float coshf(float value) {
    return (float)cosh(value);
}

float tanhf(float value) {
    return (float)tanh(value);
}

float expf(float value) {
    return (float)exp(value);
}

float logf(float value) {
    return (float)log(value);
}

float log10f(float value) {
    return (float)log10(value);
}

float floorf(float value) {
    return (float)floor(value);
}

float ceilf(float value) {
    return (float)ceil(value);
}

float truncf(float value) {
    return (float)trunc(value);
}

float roundf(float value) {
    return (float)round(value);
}

float log2f(float value) {
    return (float)log2(value);
}

float exp2f(float value) {
    return (float)exp2(value);
}

float cbrtf(float value) {
    return (float)cbrt(value);
}

float atan2f(float y, float x) {
    return (float)atan2(y, x);
}

float powf(float base, float exponent) {
    return (float)pow(base, exponent);
}

float fmodf(float dividend, float divisor) {
    return (float)fmod(dividend, divisor);
}

float fminf(float first, float second) {
    return (float)fmin(first, second);
}

float fmaxf(float first, float second) {
    return (float)fmax(first, second);
}

float hypotf(float x, float y) {
    return (float)hypot(x, y);
}

float copysignf(float value, float sign) {
    return (float)copysign(value, sign);
}

float fabsf(float value) {
    return value < 0 ? -value : value;
}

float ldexpf(float value, int exponent) {
    return (float)ldexp(value, exponent);
}

float frexpf(float value, int *exponent) {
    return (float)frexp(value, exponent);
}

float modff(float value, float *integer) {
    double whole;
    float fraction = (float)modf(value, &whole);
    *integer = (float)whole;
    return fraction;
}

static int wide_path(wchar_type *output, const char *path) {
    size_t length = mbstowcs(output, path, PATH_CHARACTERS);
    if (length == (size_t)-1 || length >= PATH_CHARACTERS) {
        return 0;
    }
    output[length] = 0;
    return 1;
}

int remove(const char *path) {
    wchar_type wide[PATH_CHARACTERS + 1];
    return wide_path(wide, path) && DeleteFileW(wide) ? 0 : -1;
}

int rename(const char *existing, const char *replacement) {
    wchar_type wide_existing[PATH_CHARACTERS + 1];
    wchar_type wide_replacement[PATH_CHARACTERS + 1];
    return wide_path(wide_existing, existing) && wide_path(wide_replacement, replacement) &&
                   MoveFileW(wide_existing, wide_replacement)
               ? 0
               : -1;
}

static int error_number;

int *_errno(void) {
    return &error_number;
}

float strtof(const char *text, char **end) {
    return (float)strtod(text, end);
}

long double strtold(const char *text, char **end) {
    return strtod(text, end);
}

float wcstof(const wchar_type *text, wchar_type **end) {
    return (float)wcstod(text, end);
}

long double wcstold(const wchar_type *text, wchar_type **end) {
    return wcstod(text, end);
}

int __grimace_c99_swprintf(wchar_type *buffer, size_t count, const wchar_type *format, ...) {
    if (count == 0) {
        return -1;
    }
    va_list arguments;
    va_start(arguments, format);
    int written = _vsnwprintf(buffer, count - 1, format, arguments);
    va_end(arguments);
    if (written < 0 || (size_t)written >= count - 1) {
        buffer[count - 1] = 0;
        return written < 0 || (size_t)written >= count ? -1 : written;
    }
    buffer[written] = 0;
    return written;
}

char *strerror(int number) {
    switch (number) {
    case 0:
        return "No error";
    case 1:
        return "Operation not permitted";
    case 2:
        return "No such file or directory";
    case 5:
        return "Input/output error";
    case 9:
        return "Bad file descriptor";
    case 12:
        return "Not enough memory";
    case 13:
        return "Permission denied";
    case 17:
        return "File exists";
    case 22:
        return "Invalid argument";
    case 28:
        return "No space left on device";
    case 33:
        return "Numerical argument out of domain";
    case 34:
        return "Result out of range";
    case 38:
        return "File name too long";
    case 40:
        return "Function not implemented";
    case 42:
        return "Illegal byte sequence";
    default:
        return "Unknown error";
    }
}

int isalnum(int character) {
    return _isctype(character, 0x107);
}

int iswalnum(wchar_type character) {
    return iswctype(character, 0x107);
}

int isalpha(int character) {
    return _isctype(character, 0x103);
}

int iswalpha(wchar_type character) {
    return iswctype(character, 0x103);
}

int iscntrl(int character) {
    return _isctype(character, 0x20);
}

int iswcntrl(wchar_type character) {
    return iswctype(character, 0x20);
}

int isdigit(int character) {
    return _isctype(character, 0x4);
}

int iswdigit(wchar_type character) {
    return iswctype(character, 0x4);
}

int isgraph(int character) {
    return _isctype(character, (0x10 | 0x103 | 0x4));
}

int iswgraph(wchar_type character) {
    return iswctype(character, (0x10 | 0x103 | 0x4));
}

int islower(int character) {
    return _isctype(character, 0x2);
}

int iswlower(wchar_type character) {
    return iswctype(character, 0x2);
}

int isprint(int character) {
    return _isctype(character, (0x40 | 0x10 | 0x103 | 0x4));
}

int iswprint(wchar_type character) {
    return iswctype(character, (0x40 | 0x10 | 0x103 | 0x4));
}

int ispunct(int character) {
    return _isctype(character, 0x10);
}

int iswpunct(wchar_type character) {
    return iswctype(character, 0x10);
}

int isspace(int character) {
    return _isctype(character, 0x8);
}

int iswspace(wchar_type character) {
    return iswctype(character, 0x8);
}

int isupper(int character) {
    return _isctype(character, 0x1);
}

int iswupper(wchar_type character) {
    return iswctype(character, 0x1);
}

int isxdigit(int character) {
    return _isctype(character, 0x80);
}

int iswxdigit(wchar_type character) {
    return iswctype(character, 0x80);
}

int isblank(int character) {
    return character == ' ' || character == '\t';
}

int iswblank(wchar_type character) {
    return character == L' ' || character == L'\t';
}

long double sqrtl(long double value) {
    return sqrt(value);
}

long double sinl(long double value) {
    return sin(value);
}

long double cosl(long double value) {
    return cos(value);
}

long double tanl(long double value) {
    return tan(value);
}

long double asinl(long double value) {
    return asin(value);
}

long double acosl(long double value) {
    return acos(value);
}

long double atanl(long double value) {
    return atan(value);
}

long double sinhl(long double value) {
    return sinh(value);
}

long double coshl(long double value) {
    return cosh(value);
}

long double tanhl(long double value) {
    return tanh(value);
}

long double expl(long double value) {
    return exp(value);
}

long double logl(long double value) {
    return log(value);
}

long double log10l(long double value) {
    return log10(value);
}

long double floorl(long double value) {
    return floor(value);
}

long double ceill(long double value) {
    return ceil(value);
}

long double truncl(long double value) {
    return trunc(value);
}

long double roundl(long double value) {
    return round(value);
}

long double log2l(long double value) {
    return log2(value);
}

long double exp2l(long double value) {
    return exp2(value);
}

long double cbrtl(long double value) {
    return cbrt(value);
}

long double atan2l(long double y, long double x) {
    return atan2(y, x);
}

long double powl(long double base, long double exponent) {
    return pow(base, exponent);
}

long double fmodl(long double dividend, long double divisor) {
    return fmod(dividend, divisor);
}

long double fminl(long double first, long double second) {
    return fmin(first, second);
}

long double fmaxl(long double first, long double second) {
    return fmax(first, second);
}

long double hypotl(long double x, long double y) {
    return hypot(x, y);
}

long double copysignl(long double value, long double sign) {
    return copysign(value, sign);
}

long double fabsl(long double value) {
    return value < 0 ? -value : value;
}

long double ldexpl(long double value, int exponent) {
    return ldexp(value, exponent);
}

long double frexpl(long double value, int *exponent) {
    return frexp(value, exponent);
}

long double modfl(long double value, long double *integer) {
    double whole;
    double fraction = modf(value, &whole);
    *integer = whole;
    return fraction;
}

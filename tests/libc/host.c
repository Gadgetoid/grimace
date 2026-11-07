#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../runtime/libc/internal.h"

static int error_number;

int *_errno(void) {
    return &error_number;
}

static uint64_t state = 0x9E3779B97F4A7C15ull;

static uint64_t next_random(void) {
    state ^= state << 13;
    state ^= state >> 7;
    state ^= state << 17;
    return state;
}

static double random_double(void) {
    for (;;) {
        union {
            uint64_t bits;
            double number;
        } view = {next_random()};
        if ((view.bits >> 52 & 0x7FF) != 0x7FF) {
            return view.number;
        }
    }
}

static int ours(char *buffer, size_t capacity, const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    int length = __grimace_format_buffer(buffer, capacity, 0, format, 0, arguments);
    va_end(arguments);
    return length;
}

static void widen_exponent(char *text) {
    char *mark = strpbrk(text, "eE");
    if (mark && (mark[1] == '+' || mark[1] == '-') && strlen(mark + 2) == 2) {
        memmove(mark + 3, mark + 2, 3);
        mark[2] = '0';
    }
}

static int is_tie(double value, const char *format, const char *actual) {
    (void)format;
    char exact[1200];
    snprintf(exact, sizeof exact, "%.1100e", value < 0 ? -value : value);
    char digits[1200];
    int count = 0;
    for (const char *at = exact; *at && *at != 'e'; at++) {
        if (*at >= '0' && *at <= '9') {
            digits[count++] = *at;
        }
    }
    int kept = 0;
    int leading = 1;
    for (const char *at = actual; *at && *at != 'e' && *at != 'E'; at++) {
        if (*at >= '1' && *at <= '9') {
            leading = 0;
        }
        if (*at >= '0' && *at <= '9' && !leading) {
            kept++;
        }
    }
    if (kept >= count || digits[kept] != '5') {
        return 0;
    }
    for (int index = kept + 1; index < count; index++) {
        if (digits[index] != '0') {
            return 0;
        }
    }
    return 1;
}

static int check_format(void) {
    static const char *formats[] = {"%e", "%.0e", "%.3e", "%.15e", "%.17e", "%f", "%.0f", "%.2f", "%.10f", "%g", "%.1g", "%.6g", "%.17g",
                                    "%#g", "%#.0f", "%+e", "% f", "%12.4f", "%012.3f", "%E", "%G"};
    int failures = 0;
    for (int round = 0; round < 200000; round++) {
        double value = random_double();
        if (round % 4 == 1) {
            value = (double)(int64_t)(next_random() % 2000001) / 1000.0 - 1000.0;
        } else if (round % 4 == 2) {
            value = ldexp((double)(next_random() >> 11), (int)(next_random() % 120) - 80);
        }
        const char *format = formats[next_random() % (sizeof formats / sizeof formats[0])];
        if (strstr(format, "f") && (value > 1e30 || value < -1e30)) {
            continue;
        }
        char expected[512];
        char actual[512];
        snprintf(expected, sizeof expected, format, value);
        widen_exponent(expected);
        ours(actual, sizeof actual, format, value);
        if (strcmp(expected, actual) && !is_tie(value, format, actual)) {
            if (failures++ < 10) {
                printf("format %s %.17g: expected [%s] got [%s]\n", format, value, expected, actual);
            }
        }
    }
    printf("format: %d failures\n", failures);
    return failures;
}

static int check_integers(void) {
    static const char *formats[] = {"%d", "%5d", "%-5d|", "%05d", "%+d", "% d", "%x", "%#x", "%X", "%#o", "%u", "%.3d", "%8.3x", "%hd", "%c"};
    int failures = 0;
    for (int round = 0; round < 100000; round++) {
        int value = (int)next_random();
        if (round % 3 == 0) {
            value %= 1000;
        }
        const char *format = formats[next_random() % (sizeof formats / sizeof formats[0])];
        if (!strcmp(format, "%c")) {
            value = 'A' + (value & 15);
        }
        char expected[64];
        char actual[64];
        snprintf(expected, sizeof expected, format, value);
        ours(actual, sizeof actual, format, value);
        if (strcmp(expected, actual) && failures++ < 10) {
            printf("integer %s %d: expected [%s] got [%s]\n", format, value, expected, actual);
        }
    }
    char actual[64];
    ours(actual, sizeof actual, "%I64d %lld %I64x %s %.2s %5s %-5s| %%", -1234567890123ll, 9876543210ll, 0xFEDCBA9876ull, "text", "text", "ab", "ab");
    if (strcmp(actual, "-1234567890123 9876543210 fedcba9876 text te    ab ab   | %")) {
        printf("mixed: got [%s]\n", actual);
        failures++;
    }
    char small[4];
    if (ours(small, sizeof small, "%d", 12345) != -1 || ours(small, sizeof small, "%d", 1234) != 4 || ours(small, sizeof small, "%d", 123) != 3 ||
        strcmp(small, "123")) {
        printf("_snprintf truncation is wrong\n");
        failures++;
    }
    printf("integers: %d failures\n", failures);
    return failures;
}

static int check_parse(void) {
    int failures = 0;
    for (int round = 0; round < 200000; round++) {
        char text[128];
        if (round % 3 == 0) {
            snprintf(text, sizeof text, "%.17g", random_double());
        } else if (round % 3 == 1) {
            snprintf(text, sizeof text, "%.*e", (int)(next_random() % 25), random_double());
        } else {
            int digits = (int)(next_random() % 30) + 1;
            int length = 0;
            for (int index = 0; index < digits; index++) {
                text[length++] = (char)('0' + next_random() % 10);
                if (index == 3) {
                    text[length++] = '.';
                }
            }
            snprintf(text + length, sizeof text - (size_t)length, "e%d", (int)(next_random() % 700) - 350);
        }
        char *host_end;
        double expected = strtod(text, &host_end);
        const char *end;
        double actual = __grimace_parse_double(text, &end);
        if (memcmp(&expected, &actual, sizeof expected) || end != host_end) {
            if (failures++ < 10) {
                printf("parse %s: expected %.17g got %.17g\n", text, expected, actual);
            }
        }
    }
    static const char *cases[] = {"0", "-0", "1e-400", "1e400", "2.2250738585072011e-308", "4.9406564584124654e-324", "2.4703282292062327e-324",
                                  "2.4703282292062328e-324", "1.7976931348623157e308", "1.7976931348623159e308", "9007199254740993",
                                  "0.000000000000000000000000000000000000000000001", "123456789012345678901234567890123456789012345678901234567890",
                                  "  +3.25d2", "inf", "-Infinity", ".5", "5.", "1e", "abc"};
    for (size_t index = 0; index < sizeof cases / sizeof cases[0]; index++) {
        char text[96];
        snprintf(text, sizeof text, "%s", cases[index]);
        for (char *at = text; *at; at++) {
            if (*at == 'd') {
                *at = 'e';
            }
        }
        char *host_end;
        double expected = strtod(text, &host_end);
        const char *end;
        double actual = __grimace_parse_double(cases[index], &end);
        if (memcmp(&expected, &actual, sizeof expected) || end - cases[index] != host_end - text) {
            printf("parse case %s: expected %.17g (%ld) got %.17g (%ld)\n", cases[index], expected, (long)(host_end - text), actual,
                   (long)(end - cases[index]));
            failures++;
        }
    }
    printf("parse: %d failures\n", failures);
    return failures;
}

static int our_scan(const char *input, const char *format, ...) {
    struct grimace_reader reader;
    va_list arguments;
    va_start(arguments, format);
    int result = __grimace_scan(__grimace_string_reader(&reader, input, 0), format, 0, arguments);
    va_end(arguments);
    return result;
}

static int check_scan(void) {
    int failures = 0;
    static const char *inputs[] = {"42 -17 0x1f 077", "  12abc", "-", "", "   ", "3.25e2 -0.5 7", "name: value", "abc123def", "1,2,3", "0x", "+5 x"};
    for (size_t index = 0; index < sizeof inputs / sizeof inputs[0]; index++) {
        const char *input = inputs[index];
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
        int expected = sscanf(input, "%d %i %x %o", &a, &b, &c, &d);
        int actual = our_scan(input, "%d %i %x %o", &e, &f, &g, &h);
        if (expected != actual || a != e || (expected > 1 && b != f) || (expected > 2 && c != g) || (expected > 3 && d != h)) {
            printf("scan ints [%s]: expected %d (%d %d %d %d) got %d (%d %d %d %d)\n", input, expected, a, b, c, d, actual, e, f, g, h);
            failures++;
        }
        double x = 0, y = 0;
        float z = 0, w = 0;
        int count_expected = sscanf(input, "%lf %f", &x, &z);
        int count_actual = our_scan(input, "%lf %f", &y, &w);
        if (count_expected != count_actual || x != y || z != w) {
            printf("scan floats [%s]: expected %d %g %g got %d %g %g\n", input, count_expected, x, z, count_actual, y, w);
            failures++;
        }
        char first[32] = "", second[32] = "", third[32] = "", fourth[32] = "";
        int n1 = -1, n2 = -1;
        int strings_expected = sscanf(input, "%31[a-z]%31[^,]%n", first, third, &n1);
        int strings_actual = our_scan(input, "%31[a-z]%31[^,]%n", second, fourth, &n2);
        if (strings_expected != strings_actual || strcmp(first, second) || strcmp(third, fourth) || n1 != n2) {
            printf("scan sets [%s]: expected %d [%s][%s] %d got %d [%s][%s] %d\n", input, strings_expected, first, third, n1, strings_actual, second, fourth, n2);
            failures++;
        }
        char word[32] = "", other[32] = "";
        char letter = 0, other_letter = 0;
        if (sscanf(input, "%s %c", word, &letter) != our_scan(input, "%s %c", other, &other_letter) || strcmp(word, other) || letter != other_letter) {
            printf("scan words [%s]: expected [%s] %c got [%s] %c\n", input, word, letter, other, other_letter);
            failures++;
        }
    }
    printf("scan: %d failures\n", failures);
    return failures;
}

int main(void) {
    int failures = check_format() + check_integers() + check_parse() + check_scan();
    return failures ? 1 : 0;
}

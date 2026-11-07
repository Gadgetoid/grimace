#include <windows.h>

static double square_root(double value) {
    double estimate = value > 1 ? value : 1;
    for (int step = 0; step < 32; step++) {
        estimate = (estimate + value / estimate) / 2;
    }
    return estimate;
}

static double pi_nilakantha(int terms) {
    double pi = 3;
    double sign = 1;
    for (int term = 0; term < terms; term++) {
        double base = 2.0 * (term + 1);
        pi += sign * 4 / (base * (base + 1) * (base + 2));
        sign = -sign;
    }
    return pi;
}

static unsigned long long factorial(int value) {
    unsigned long long result = 1;
    while (value > 1) {
        result *= value--;
    }
    return result;
}

static WCHAR *format_unsigned(WCHAR *end, unsigned long long value) {
    *--end = 0;
    do {
        *--end = L'0' + (WCHAR)(value % 10);
        value /= 10;
    } while (value);
    return end;
}

static void format_fixed(WCHAR *output, double value, int decimals) {
    WCHAR digits[32];
    unsigned long long scale = 1;
    for (int decimal = 0; decimal < decimals; decimal++) {
        scale *= 10;
    }
    unsigned long long scaled = (unsigned long long)(value * scale + 0.5);
    WCHAR *fraction = format_unsigned(digits + 32, scale + scaled % scale) + 1;
    WCHAR *whole = format_unsigned(digits + 12, scaled / scale);
    wsprintfW(output, L"%s.%s", whole, fraction);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WCHAR pi[32], root[32], digits[32], text[160];
    format_fixed(pi, pi_nilakantha(1000), 9);
    format_fixed(root, square_root(2), 9);
    wsprintfW(text, L"pi = %s\nsqrt(2) = %s\n20! = %s", pi, root, format_unsigned(digits + 32, factorial(20)));
    MessageBoxW(0, text, L"Soft float and 64-bit maths", MB_OK);
    return 0;
}

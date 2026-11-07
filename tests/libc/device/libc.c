#include <windows.h>
#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static HANDLE results = INVALID_HANDLE_VALUE;
static WCHAR summary[1024];
static int passed;
static int failed;

static void line(const WCHAR *text) {
    DWORD written;
    OutputDebugStringW(text);
    if (results != INVALID_HANDLE_VALUE) {
        WriteFile(results, text, wcslen(text) * sizeof(WCHAR), &written, NULL);
    }
}

static void check(const char *name, int ok, const char *detail) {
    WCHAR text[256];
    if (ok) {
        passed++;
        return;
    }
    failed++;
    _snwprintf(text, 255, L"libc: FAIL %hs: %hs\r\n", name, detail ? detail : "");
    text[255] = 0;
    line(text);
    if (wcslen(summary) + wcslen(text) < 1000) {
        wcscat(summary, text + 6);
    }
}

static void check_text(const char *name, const char *actual, const char *expected) {
    char detail[200];
    _snprintf(detail, sizeof detail - 1, "got [%s] expected [%s]", actual, expected);
    detail[sizeof detail - 1] = 0;
    check(name, !strcmp(actual, expected), detail);
}

static void check_close(const char *name, double actual, double expected) {
    char detail[100];
    _snprintf(detail, sizeof detail - 1, "got %.17g expected %.17g", actual, expected);
    detail[sizeof detail - 1] = 0;
    check(name, fabs(actual - expected) <= fabs(expected) * 1e-15, detail);
}

static int compare_ints(const void *first, const void *second) {
    return *(const int *)first - *(const int *)second;
}

static jmp_buf jump;

static void jump_back(int value) {
    longjmp(jump, value);
}

static void formatting(void) {
    char text[200];
    sprintf(text, "%d|%5d|%-5d|%05d|%x|%#X|%o|%u|%c|%s|%.2s|%%", -42, 42, 42, 42, 255, 255, 8, 4000000000u, 'z', "text", "text");
    check_text("sprintf integers", text, "-42|   42|42   |00042|ff|0XFF|10|4000000000|z|text|te|%");
    sprintf(text, "%f|%.3f|%e|%.2E|%g|%g|%g|%.0f", 3.14159265358979, 2.0006, 12345.678, 0.000123, 100000.0, 1000000.0, 0.0001, 2.5);
    check_text("sprintf floats", text, "3.141593|2.001|1.234568e+004|1.23E-004|100000|1e+006|0.0001|3");
    sprintf(text, "%I64d|%I64x|%S", -1234567890123ll, 0x123456789Aull, L"wide");
    check_text("sprintf I64 and %S", text, "-1234567890123|123456789a|wide");
    check("_snprintf truncates", _snprintf(text, 4, "%d", 123456) == -1 && !strncmp(text, "1234", 4), NULL);
    check("snprintf C99", snprintf(text, 4, "%d", 123456) == 6 && !strcmp(text, "123"), NULL);
    WCHAR wide[64];
    swprintf(wide, L"%s %d %.1f %hs", L"wide", 7, 0.25, "narrow");
    check("swprintf", !wcscmp(wide, L"wide 7 0.3 narrow"), NULL);
}

static void scanning(void) {
    int first = 0;
    int second = 0;
    unsigned hex = 0;
    double value = 0;
    char word[16] = "";
    int count = sscanf("  12 -7 ff 2.5e1 word", "%d %d %x %lf %15s", &first, &second, &hex, &value, word);
    check("sscanf", count == 5 && first == 12 && second == -7 && hex == 255 && value == 25.0 && !strcmp(word, "word"), NULL);
    WCHAR wide_word[16];
    int wide_value = 0;
    check("swscanf", swscanf(L"99 text", L"%d %15s", &wide_value, wide_word) == 2 && wide_value == 99 && !wcscmp(wide_word, L"text"), NULL);
    char *end;
    double tenth = strtod("0.1x", &end);
    unsigned long long bits;
    memcpy(&bits, &tenth, sizeof bits);
    check("strtod 0.1", bits == 0x3FB999999999999Aull && *end == 'x', NULL);
    check("strtol", strtol("  -0x1F", &end, 0) == -31 && !*end, NULL);
    check("strtoul", strtoul("4294967295", NULL, 10) == 4294967295ul, NULL);
    check("atoi", atoi("  123abc") == 123, NULL);
    check("strtoll", strtoll("-9223372036854775807", NULL, 10) == -9223372036854775807ll, NULL);
}

static void memory(void) {
    unsigned char *block = malloc(1000);
    int ok = block != NULL;
    for (int index = 0; ok && index < 1000; index++) {
        block[index] = (unsigned char)index;
    }
    block = ok ? realloc(block, 5000) : NULL;
    for (int index = 0; block && index < 1000; index++) {
        ok &= block[index] == (unsigned char)index;
    }
    check("malloc and realloc", ok && block && _msize(block) >= 5000, NULL);
    free(block);
    int *zeros = calloc(100, sizeof(int));
    ok = zeros != NULL;
    for (int index = 0; ok && index < 100; index++) {
        ok &= zeros[index] == 0;
    }
    check("calloc", ok, NULL);
    free(zeros);
    int numbers[] = {5, 3, 9, 1, 7, 2, 8, 6, 4, 0};
    qsort(numbers, 10, sizeof(int), compare_ints);
    ok = 1;
    for (int index = 0; index < 10; index++) {
        ok &= numbers[index] == index;
    }
    check("qsort", ok, NULL);
}

static void strings(void) {
    char text[64];
    strcpy(text, "Hello");
    strcat(text, ", World");
    check("strcpy and strcat", !strcmp(text, "Hello, World") && strlen(text) == 12, NULL);
    check("strstr and strchr", strstr(text, "World") == text + 7 && strchr(text, ',') == text + 5 && strrchr(text, 'o') == text + 8, NULL);
    check("_stricmp", !_stricmp("HeLLo", "hello") && _strnicmp("abcX", "ABCy", 3) == 0, NULL);
    char tokens[] = "one, two,,three";
    char *first = strtok(tokens, ", ");
    char *second = strtok(NULL, ", ");
    char *third = strtok(NULL, ", ");
    check("strtok", first && second && third && !strcmp(first, "one") && !strcmp(second, "two") && !strcmp(third, "three") && !strtok(NULL, ", "), NULL);
    char *copy = _strdup("Copy");
    check("_strdup and _strupr", copy && !strcmp(_strupr(copy), "COPY"), NULL);
    free(copy);
    check("ctype", isalpha('a') && isdigit('7') && !isalpha('7') && isspace('\t') && toupper('q') == 'Q', NULL);
    _itoa(-255, text, 16);
    check_text("_itoa base 16", text, "ffffff01");
    _itoa(-255, text, 10);
    check_text("_itoa base 10", text, "-255");
}

static void maths(void) {
    check_close("sin", sin(1.0), 0.8414709848078965);
    check_close("cos", cos(1.0), 0.54030230586813977);
    check_close("tan", tan(0.5), 0.54630248984379048);
    check_close("exp", exp(1.0), 2.7182818284590451);
    check_close("log", log(10.0), 2.3025850929940459);
    check_close("log10", log10(1000.0), 3.0);
    check_close("pow", pow(2.0, 0.5), 1.4142135623730951);
    check_close("sqrt", sqrt(2.0), 1.4142135623730951);
    check_close("atan2", atan2(1.0, 1.0) * 4, 3.1415926535897931);
    check_close("asin", asin(0.5), 0.52359877559829893);
    check_close("sinh", sinh(1.0), 1.1752011936438014);
    check_close("tanh", tanh(0.5), 0.46211715726000974);
    check_close("fmod", fmod(10.5, 3.0), 1.5);
    check_close("floor and ceil", floor(-1.5) + ceil(1.2), 0.0);
    check_close("sinf", (double)sinf(1.0f), (double)(float)0.8414709848078965);
    check_close("_hypot", _hypot(3.0, 4.0), 5.0);
}

static void files(void) {
    FILE *file = fopen("\\libc-test.txt", "w");
    check("fopen for writing", file != NULL, NULL);
    if (!file) {
        return;
    }
    fprintf(file, "line %d\n%s %.2f\n", 1, "pi", 3.14159);
    fputs("last", file);
    fclose(file);
    file = fopen("\\libc-test.txt", "r");
    check("fopen for reading", file != NULL, NULL);
    if (!file) {
        return;
    }
    char text[64] = "";
    fgets(text, sizeof text, file);
    check_text("fgets", text, "line 1\n");
    char word[16] = "";
    double value = 0;
    check("fscanf", fscanf(file, "%15s %lf", word, &value) == 2 && !strcmp(word, "pi") && value == 3.14, NULL);
    fseek(file, 0, SEEK_END);
    check("ftell in text mode", ftell(file) == 21, NULL);
    fseek(file, -4, SEEK_END);
    check("fread", fread(text, 1, 10, file) == 4 && !strncmp(text, "last", 4) && feof(file), NULL);
    fclose(file);
    check("remove", remove("\\libc-test.txt") == 0 && !fopen("\\libc-test.txt", "r"), NULL);
    printf("libc: printf to stdout %d\n", 42);
}

static void jumps(void) {
    volatile int counter = 0;
    int value = setjmp(jump);
    counter++;
    if (value == 0) {
        jump_back(7);
    }
    check("setjmp and longjmp", value == 7 && counter == 2, NULL);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    results = CreateFileW(command_line[0] ? command_line : L"\\libc.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    formatting();
    scanning();
    memory();
    strings();
    maths();
    files();
    jumps();
    WCHAR text[64];
    swprintf(text, L"libc: %d passed, %d failed\r\n", passed, failed);
    line(text);
    wcscat(summary, text + 6);
    if (results != INVALID_HANDLE_VALUE) {
        CloseHandle(results);
    }
    MessageBoxW(NULL, summary, L"libc", MB_OK);
    return failed;
}

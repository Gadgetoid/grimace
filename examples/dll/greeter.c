#include <windows.h>

typedef int (*add_function)(int, int);
typedef int (*greeting_function)(LPWSTR, int);

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WCHAR greeting[64], text[128];
    LPCWSTR library_path = command_line[0] ? command_line : L"greet.dll";
    HMODULE library = LoadLibraryW(library_path);
    if (!library) {
        wsprintfW(text, L"Couldn't load %s", library_path);
        MessageBoxW(0, text, L"Greeter", MB_OK | MB_ICONERROR);
        return 1;
    }
    add_function add = (add_function)GetProcAddressW(library, L"Add");
    greeting_function get_greeting = (greeting_function)GetProcAddressW(library, L"Greeting");
    int sum = add(2, 3);
    get_greeting(greeting, 64);
    wsprintfW(text, L"%s\n2 + 3 = %d", greeting, sum);
    MessageBoxW(0, text, L"Greeter", MB_OK | MB_ICONINFORMATION);
    FreeLibrary(library);
    return 0;
}

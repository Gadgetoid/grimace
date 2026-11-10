#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WCHAR text[64];
    swprintf(text, L"Up for %u ms", GetTickCount());
    MessageBoxW(NULL, text, L"CE 6", MB_OK);
    return 0;
}

#include <windows.h>

static int calls;

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, void *reserved) {
    return TRUE;
}

int Add(int left, int right) {
    calls++;
    return left + right;
}

int Greeting(LPWSTR output, int size) {
    WCHAR text[64];
    int length = wsprintfW(text, L"Hello from greet.dll, call %d", ++calls);
    if (length >= size) {
        return 0;
    }
    for (int index = 0; index <= length; index++) {
        output[index] = text[index];
    }
    return length;
}

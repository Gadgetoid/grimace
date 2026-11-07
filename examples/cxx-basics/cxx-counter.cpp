#include <windows.h>

class library_state {
public:
    library_state() : constructed(2) {}

    ~library_state() {
        OutputDebugStringW(L"cxx-counter: destructor ran\r\n");
    }

    int constructed;
};

library_state state;

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    return TRUE;
}

extern "C" int ConstructedCount() {
    return state.constructed;
}

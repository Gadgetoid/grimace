#include <windows.h>

#define CPL_INIT 1
#define CPL_GETCOUNT 2
#define CPL_DBLCLK 5
#define CPL_NEWINQUIRE 8
#define IDI_APPLET 100

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHelpContext;
    LONG lData;
    HICON hIcon;
    WCHAR szName[32];
    WCHAR szInfo[64];
    WCHAR szHelpFile[128];
} applet_information;

static HINSTANCE module;

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        module = instance;
    }
    return TRUE;
}

LONG CPlApplet(HWND window, UINT message, LPARAM first, LPARAM second) {
    applet_information *information;
    switch (message) {
    case CPL_INIT:
        return 1;
    case CPL_GETCOUNT:
        return 1;
    case CPL_NEWINQUIRE:
        information = (applet_information *)second;
        information->dwSize = sizeof *information;
        information->hIcon = LoadIconW(module, MAKEINTRESOURCEW(IDI_APPLET));
        LoadStringW(module, 1, information->szName, 32);
        LoadStringW(module, 2, information->szInfo, 64);
        return 0;
    case CPL_DBLCLK:
        MessageBoxW(window, L"Applet", L"CE 6", MB_OK);
        return 0;
    }
    return 0;
}

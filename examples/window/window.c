#include <windows.h>

#define MARK_SIZE 6

static int tap_count;
static POINT last_tap = {-1, -1};

static void paint(HWND window) {
    PAINTSTRUCT paint;
    RECT client;
    WCHAR text[64];
    HDC dc = BeginPaint(window, &paint);
    GetClientRect(window, &client);
    wsprintfW(text, L"Taps: %d\nTap anywhere, Esc to quit", tap_count);
    DrawTextW(dc, text, -1, &client, DT_CENTER | DT_WORDBREAK);
    if (last_tap.x >= 0) {
        Ellipse(dc, last_tap.x - MARK_SIZE, last_tap.y - MARK_SIZE, last_tap.x + MARK_SIZE, last_tap.y + MARK_SIZE);
    }
    EndPaint(window, &paint);
}

static LRESULT CALLBACK window_procedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {
    switch (message) {
    case WM_PAINT:
        paint(window);
        return 0;
    case WM_LBUTTONDOWN:
        tap_count++;
        last_tap.x = (short)LOWORD(lparam);
        last_tap.y = (short)HIWORD(lparam);
        InvalidateRect(window, 0, TRUE);
        return 0;
    case WM_KEYDOWN:
        if (wparam == VK_ESCAPE) {
            DestroyWindow(window);
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(window, message, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WNDCLASSW window_class = {0};
    MSG message;
    HWND window;
    window_class.lpfnWndProc = window_procedure;
    window_class.hInstance = instance;
    window_class.hbrBackground = GetStockObject(WHITE_BRUSH);
    window_class.lpszClassName = L"GrimaceExampleWindow";
    RegisterClassW(&window_class);
    window = CreateWindowExW(0, window_class.lpszClassName, L"Window", WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
                             0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, 0, instance, 0);
    SetFocus(window);
    while (GetMessageW(&message, 0, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessageW(&message);
    }
    return message.wParam;
}

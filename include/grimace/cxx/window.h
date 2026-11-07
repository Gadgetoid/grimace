#ifndef GRIMACE_CXX_WINDOW_H
#define GRIMACE_CXX_WINDOW_H

#include <grimace/cxx/core.h>
#include <grimace/cxx/gdi.h>
#include <grimace/cxx/result.h>
#include <windows.h>

namespace grimace {

namespace detail {

template <typename Handler>
LRESULT handled_or_default(Handler &&handler, bool &handled) {
    if constexpr (same_as<decltype(handler()), bool>) {
        handled = handler();
    } else {
        handler();
        handled = true;
    }
    return 0;
}

}

/**
 * The whole screen, for a full-screen window.
 */
inline RECT screen_rect() {
    return RECT{0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
}

/**
 * The screen less the taskbar, for a main window. Falls back to the whole
 * screen if the system can't say, and on CE 1.0, which has no
 * SystemParametersInfoW.
 */
inline RECT work_area_rect() {
#if GRIMACE_CE >= 2
    RECT area;
    if (SystemParametersInfoW(SPI_GETWORKAREA, 0, &area, 0)) {
        return area;
    }
#endif
    return screen_rect();
}

/**
 * Gets and dispatches messages until WM_QUIT, and returns its exit code.
 */
inline int run_message_loop() {
    MSG message;
    while (GetMessageW(&message, nullptr, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessageW(&message);
    }
    return static_cast<int>(message.wParam);
}

/**
 * A window class and window, with messages sent to Derived's handlers.
 *
 * Derived declares `static constexpr const wchar_t *class_name`, and may
 * declare `static constexpr UINT class_style` and `static HBRUSH background()`
 * (default the white stock brush). It handles messages by declaring any of
 * these public member functions; the rest go to DefWindowProcW. Which ones
 * exist is decided at compile time: there are no virtual calls.
 *
 * - `on_create()`: WM_CREATE. Return false to fail creation, or void.
 * - `on_paint(grimace::paint_dc &dc)`: WM_PAINT, between BeginPaint and EndPaint.
 * - `on_tap(grimace::point where)`: WM_LBUTTONDOWN, in client coordinates.
 * - `on_key(UINT key)`: WM_KEYDOWN, a virtual key code. Return false to pass it on, or void.
 * - `on_command(WORD id, WORD code, HWND control)`: WM_COMMAND. Return false to pass it on, or void.
 * - `on_destroy()`: WM_DESTROY.
 * - `on_message(UINT message, WPARAM wparam, LPARAM lparam, LRESULT &result)`:
 *   any message, before the others. Return true if handled, with result set.
 *
 * The object must outlive its window, or destroy it: the destructor destroys
 * a window that's still open.
 */
template <typename Derived>
class window {
public:
    window() = default;
    window(const window &) = delete;
    window &operator=(const window &) = delete;

    ~window() {
        if (window_handle) {
            SetWindowLongW(window_handle, 0, 0);
            DestroyWindow(window_handle);
        }
    }

    /**
     * Registers Derived's window class. Call once, before create().
     */
    static result<void> register_class(HINSTANCE instance) {
        WNDCLASSW window_class{};
        if constexpr (requires { Derived::class_style; }) {
            window_class.style = Derived::class_style;
        }
        window_class.lpfnWndProc = procedure;
        window_class.cbWndExtra = sizeof(window *);
        window_class.hInstance = instance;
        if constexpr (requires { Derived::background(); }) {
            window_class.hbrBackground = Derived::background();
        } else {
            window_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
        }
        window_class.lpszClassName = Derived::class_name;
        if (!RegisterClassW(&window_class)) {
            return error::last();
        }
        return {};
    }

    /**
     * Creates the window, with CreateWindowExW.
     */
    result<void> create(HINSTANCE instance, LPCWSTR title, DWORD style, const RECT &bounds, HWND parent = nullptr, DWORD extended_style = 0) {
        HWND created = CreateWindowExW(extended_style, Derived::class_name, title, style, bounds.left, bounds.top, bounds.right - bounds.left,
                                       bounds.bottom - bounds.top, parent, nullptr, instance, this);
        if (!created) {
            return error::last();
        }
        return {};
    }

    HWND handle() const {
        return window_handle;
    }

    RECT client_rect() const {
        RECT bounds;
        GetClientRect(window_handle, &bounds);
        return bounds;
    }

    void invalidate(bool erase = true) const {
        InvalidateRect(window_handle, nullptr, erase);
    }

    void focus() const {
        SetFocus(window_handle);
    }

    void show(int command) const {
        ShowWindow(window_handle, command);
    }

    void destroy() const {
        DestroyWindow(window_handle);
    }

private:
    static LRESULT CALLBACK procedure(HWND handle, UINT message, WPARAM wparam, LPARAM lparam) {
        window *self = reinterpret_cast<window *>(GetWindowLongW(handle, 0));
        if (!self && message == WM_CREATE) {
            self = static_cast<window *>(reinterpret_cast<CREATESTRUCTW *>(lparam)->lpCreateParams);
            SetWindowLongW(handle, 0, reinterpret_cast<LONG>(self));
            self->window_handle = handle;
        }
        if (!self) {
            return DefWindowProcW(handle, message, wparam, lparam);
        }
        return self->dispatch(handle, message, wparam, lparam);
    }

    LRESULT dispatch(HWND handle, UINT message, WPARAM wparam, LPARAM lparam) {
        Derived &self = static_cast<Derived &>(*this);
        bool handled = false;
        if constexpr (requires(LRESULT &result) { self.on_message(message, wparam, lparam, result); }) {
            LRESULT result = 0;
            if (self.on_message(message, wparam, lparam, result)) {
                return result;
            }
        }
        switch (message) {
        case WM_CREATE:
            if constexpr (requires { self.on_create(); }) {
                detail::handled_or_default([&] { return self.on_create(); }, handled);
                return handled ? 0 : -1;
            }
            break;
        case WM_PAINT:
            if constexpr (requires(paint_dc &dc) { self.on_paint(dc); }) {
                paint_dc dc(handle);
                self.on_paint(dc);
                return 0;
            }
            break;
        case WM_LBUTTONDOWN:
            if constexpr (requires(point where) { self.on_tap(where); }) {
                self.on_tap(point{static_cast<short>(LOWORD(lparam)), static_cast<short>(HIWORD(lparam))});
                return 0;
            }
            break;
        case WM_KEYDOWN:
            if constexpr (requires(UINT key) { self.on_key(key); }) {
                LRESULT result = detail::handled_or_default([&] { return self.on_key(static_cast<UINT>(wparam)); }, handled);
                if (handled) {
                    return result;
                }
            }
            break;
        case WM_COMMAND:
            if constexpr (requires(WORD id, WORD code, HWND control) { self.on_command(id, code, control); }) {
                LRESULT result = detail::handled_or_default(
                    [&] { return self.on_command(LOWORD(wparam), HIWORD(wparam), reinterpret_cast<HWND>(lparam)); }, handled);
                if (handled) {
                    return result;
                }
            }
            break;
        case WM_DESTROY:
            if constexpr (requires { self.on_destroy(); }) {
                self.on_destroy();
            }
            SetWindowLongW(handle, 0, 0);
            window_handle = nullptr;
            return 0;
        }
        return DefWindowProcW(handle, message, wparam, lparam);
    }

    HWND window_handle = nullptr;
};

}

#endif

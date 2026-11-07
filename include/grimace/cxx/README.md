# grimace/cxx

A header-only C++20 layer over the Windows CE API, in namespace `grimace`. It needs the toolchain's C++ support (see the main README), and nothing else: no exceptions, RTTI or standard library. It works alongside the standard library where that's available (CE 3.0).

- It should cost nothing over the C it replaces: everything is inline, and the window base dispatches messages with no virtual calls.
- Errors are values. Functions that can fail return `grimace::result<T>`, which holds a `T` or a `grimace::error` (a `GetLastError` code or an HRESULT).
- It only offers what the target has. A wrapper for a CE 2.0 function is unavailable on CE 1.0, with the same error as the function (`'transparent_image' is unavailable: not in Windows CE 1.0`), and wrappers use calls both versions have where they can (`create_pen` uses `CreatePenIndirect`, since CE 1.0 has no `CreatePen`).

## Headers

| Header | |
| --- | --- |
| `result.h` | `error`, `result<T>`, `result<void>`, `check(BOOL)`, `check_hresult(HRESULT)` |
| `handle.h` | `unique_resource<T, Traits>`, `unique_handle` (`CloseHandle`), `create_file`, `create_event` |
| `memory.h` | `local_ptr<T>` (`LocalFree`), `local_alloc<T>(count)` |
| `gdi.h` | `unique_pen`, `unique_brush`, `unique_font`, `unique_bitmap`, `unique_region` (`DeleteObject`) and their `create_` functions, `select_guard`, `device_context`, `paint_dc` (`BeginPaint`/`EndPaint`), `window_dc` (`GetDC`/`ReleaseDC`), `point` |
| `string_view.h` | `wstring_view`, `string_view`: from a pointer, or anything with `data()` and `size()` (`std::wstring`, `std::wstring_view`, `grimace::wstring<N>`). They don't own the text, so don't keep one past its source. |
| `fixed_string.h` | `wstring<N>`, `string<N>`: up to N - 1 characters inline, always null-terminated |
| `utf8.h` | `utf8_to_utf16`, `utf16_to_utf8`, `to_wstring<N>`, `to_utf8<N>` |
| `format.h` | `format<N>` and `format_to`, over `wsprintfW` on CE 1.0 and 2.0 and coredll's `_snwprintf` on CE 3.0 |
| `optional.h` | `optional<T>` |
| `window.h` | `window<Derived>`, `run_message_loop`, `screen_rect`, `work_area_rect` (the screen less the taskbar, or the whole screen on CE 1.0) |
| `core.h` | `move`, `forward`, `exchange`, `swap` and a few type traits |

## Formatting

`grimace::format<N>(L"...", arguments...)` returns a `wstring<N>`. The format is checked against the arguments at compile time:

```cpp
auto text = grimace::format<64>(L"%s: %d of %u", name, done, total);
grimace::format<64>(L"%d", L"text");     // error: format_argument_does_not_match_its_conversion
grimace::format<8>(L"Total: %d", total); // error: format_output_may_not_fit_in_the_capacity
```

On CE 1.0 and 2.0 it calls `wsprintfW`. Conversions are `%[-][#][0][width][.precision][l]type`: `d`, `i`, `u`, `x` and `X` take integers or enums up to 32 bits, `c` a character, `s` a `const wchar_t *` or `wstring<N>`, and `S` a `const char *`. There's no floating point or 64-bit integers, as `wsprintfW` has none. A `const wchar_t *` or `const char *` without a precision can be any length, so `format` measures it first, and if the result wouldn't fit it formats through a heap buffer and truncates. `format_to` returns false when that happens.

On CE 3.0 it calls coredll's `_snwprintf`. Conversions are `%[flags][width][.precision][h|l|L|I64]type`, with flags from `-`, `+`, space, `#` and `0`:

- `d`, `i`, `u`, `o`, `x`, `X`: integers or enums up to 32 bits, or 64 bits with `I64` (`%I64d`)
- `c`, `C`: a character
- `s`: a wide string, `const wchar_t *` or `wstring<N>`; `S` or `hs`: a narrow string, `const char *` or `string<N>`
- `e`, `E`, `f`, `g`, `G`: a `float` or `double`
- `p`: a pointer

`*` widths and precisions, and `%n`, are compile errors. A format whose longest output wouldn't fit in N - 1 characters is a compile error, except `%f` and strings without a precision, whose length depends on the value. Those are cut off at N - 1 characters, and `format_to` returns false when that happens.

## Windows

`window<Derived>` registers a class and creates a window whose messages go to `Derived`'s handlers. Declare the ones you want, public:

```cpp
#include <grimace/cxx/window.h>

namespace {

class main_window : public grimace::window<main_window> {
public:
    static constexpr const wchar_t *class_name = L"MainWindow";

    void on_paint(grimace::paint_dc &dc) {
        dc.draw_text(L"Hello", client_rect(), DT_CENTER);
    }

    void on_destroy() {
        PostQuitMessage(0);
    }
};

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    main_window window;
    if (!main_window::register_class(instance) || !window.create(instance, L"Hello", WS_VISIBLE | WS_CAPTION | WS_SYSMENU, grimace::work_area_rect())) {
        return 1;
    }
    return grimace::run_message_loop();
}
```

Handlers are `on_create`, `on_paint(paint_dc &)`, `on_tap(point)`, `on_key(UINT)`, `on_command(WORD id, WORD code, HWND control)`, `on_destroy` and `on_message(UINT, WPARAM, LPARAM, LRESULT &)` for anything else; `window.h` says what each gets and returns. A handler that isn't public isn't found, and its message goes to `DefWindowProcW`.

Put a window class used in one file in an unnamed namespace, as above. Its functions are then local to the file, so the compiler inlines them into the window procedure instead of keeping them as separate functions.

The object stores itself in the window's extra bytes, so it must outlive the window. Its destructor destroys a window that's still open.

#ifndef GRIMACE_CXX_GDI_H
#define GRIMACE_CXX_GDI_H

#include <grimace/cxx/core.h>
#include <grimace/cxx/handle.h>
#include <grimace/cxx/string_view.h>
#include <windows.h>

namespace grimace {

/**
 * A point in client or screen coordinates.
 */
struct point {
    int x;
    int y;

    constexpr operator POINT() const {
        return POINT{x, y};
    }

    friend constexpr bool operator==(point, point) = default;
};

template <typename T>
struct gdi_object_traits {
    static void close(T object) {
        DeleteObject(object);
    }
};

/**
 * A GDI object deleted with DeleteObject. Don't let one go out of scope while
 * it's selected into a device context: declare it before the select_guard.
 */
template <typename T>
using unique_gdi_object = unique_resource<T, gdi_object_traits<T>>;

using unique_pen = unique_gdi_object<HPEN>;
using unique_brush = unique_gdi_object<HBRUSH>;
using unique_font = unique_gdi_object<HFONT>;
using unique_bitmap = unique_gdi_object<HBITMAP>;
using unique_region = unique_gdi_object<HRGN>;

/**
 * Creates a pen. Uses CreatePenIndirect, which CE 1.0 has and CreatePen it lacks.
 */
inline unique_pen create_pen(int style, int width, COLORREF colour) {
    LOGPEN description{static_cast<UINT>(style), POINT{width, 0}, colour};
    return unique_pen(CreatePenIndirect(&description));
}

inline unique_brush create_solid_brush(COLORREF colour) {
    return unique_brush(CreateSolidBrush(colour));
}

inline unique_font create_font(const LOGFONTW &description) {
    return unique_font(CreateFontIndirectW(&description));
}

inline unique_bitmap create_compatible_bitmap(HDC dc, int width, int height) {
    return unique_bitmap(CreateCompatibleBitmap(dc, width, height));
}

inline unique_region create_rect_region(const RECT &bounds) {
    return unique_region(CreateRectRgnIndirect(&bounds));
}

/**
 * Selects a GDI object into a device context, and selects the previous one
 * back when it goes out of scope.
 */
class [[nodiscard]] select_guard {
public:
    select_guard(HDC dc, HGDIOBJ object) : dc(dc), previous(SelectObject(dc, object)) {}

    select_guard(const select_guard &) = delete;
    select_guard &operator=(const select_guard &) = delete;

    ~select_guard() {
        SelectObject(dc, previous);
    }

private:
    HDC dc;
    HGDIOBJ previous;
};

/**
 * A device context someone else owns, with drawing helpers. paint_dc and
 * window_dc own theirs.
 */
class device_context {
public:
    constexpr explicit device_context(HDC dc) : dc(dc) {}

    constexpr HDC get() const {
        return dc;
    }

    template <typename Object>
    select_guard select(const unique_gdi_object<Object> &object) const {
        return select_guard(dc, object.get());
    }

    select_guard select(HGDIOBJ object) const {
        return select_guard(dc, object);
    }

    /**
     * The height of a line of text in the selected font, or 0 if it can't be measured.
     */
    int text_height() const {
        TEXTMETRICW metrics;
        return GetTextMetricsW(dc, &metrics) ? metrics.tmHeight : 0;
    }

    int draw_text(wstring_view text, RECT bounds, UINT format) const {
        return DrawTextW(dc, text.data(), static_cast<int>(text.size()), &bounds, format);
    }

    bool text_out(point at, wstring_view text) const {
        return ExtTextOutW(dc, at.x, at.y, 0, nullptr, text.data(), static_cast<UINT>(text.size()), nullptr);
    }

    bool ellipse(const RECT &bounds) const {
        return Ellipse(dc, bounds.left, bounds.top, bounds.right, bounds.bottom);
    }

    bool rectangle(const RECT &bounds) const {
        return Rectangle(dc, bounds.left, bounds.top, bounds.right, bounds.bottom);
    }

    bool round_rect(const RECT &bounds, int corner_width, int corner_height) const {
        return RoundRect(dc, bounds.left, bounds.top, bounds.right, bounds.bottom, corner_width, corner_height);
    }

    bool fill_rect(const RECT &bounds, HBRUSH brush) const {
        return FillRect(dc, &bounds, brush);
    }

    bool polyline(const POINT *points, int count) const {
        return Polyline(dc, points, count);
    }

    template <size_t Count>
    bool polyline(const POINT (&points)[Count]) const {
        return Polyline(dc, points, static_cast<int>(Count));
    }

    COLORREF set_text_color(COLORREF colour) const {
        return SetTextColor(dc, colour);
    }

    COLORREF set_background_color(COLORREF colour) const {
        return SetBkColor(dc, colour);
    }

    int set_background_mode(int mode) const {
        return SetBkMode(dc, mode);
    }

    /**
     * Draws an image with one colour left out, with TransparentImage.
     */
    GRIMACE_CXX_CE2_ONLY bool transparent_image(const RECT &destination, HANDLE source, const RECT &source_bounds, COLORREF transparent) const {
        return TransparentImage(dc, destination.left, destination.top, destination.right - destination.left, destination.bottom - destination.top,
                                source, source_bounds.left, source_bounds.top, source_bounds.right - source_bounds.left,
                                source_bounds.bottom - source_bounds.top, transparent);
    }

protected:
    HDC dc;
};

/**
 * A window's device context for WM_PAINT: BeginPaint when made, EndPaint when it goes out of scope.
 */
class paint_dc : public device_context {
public:
    explicit paint_dc(HWND window) : device_context(nullptr), window(window) {
        dc = BeginPaint(window, &paint);
    }

    paint_dc(const paint_dc &) = delete;
    paint_dc &operator=(const paint_dc &) = delete;

    ~paint_dc() {
        EndPaint(window, &paint);
    }

    /**
     * The area that needs painting.
     */
    const RECT &paint_rect() const {
        return paint.rcPaint;
    }

    bool erase_background() const {
        return paint.fErase;
    }

private:
    HWND window;
    PAINTSTRUCT paint;
};

/**
 * A window's device context from GetDC, released with ReleaseDC when it goes out of scope.
 */
class window_dc : public device_context {
public:
    explicit window_dc(HWND window) : device_context(GetDC(window)), window(window) {}

    window_dc(const window_dc &) = delete;
    window_dc &operator=(const window_dc &) = delete;

    ~window_dc() {
        ReleaseDC(window, dc);
    }

private:
    HWND window;
};

}

#endif

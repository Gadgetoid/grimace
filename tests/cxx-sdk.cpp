#include <windows.h>

#include <grimace/cxx/format.h>
#include <grimace/cxx/gdi.h>
#include <grimace/cxx/handle.h>
#include <grimace/cxx/memory.h>
#include <grimace/cxx/optional.h>
#include <grimace/cxx/result.h>
#include <grimace/cxx/utf8.h>
#include <grimace/cxx/window.h>

#if __has_include(<__config_site>)
#include <string>
#include <string_view>

int standard_text_width(HDC context, const std::wstring &owned, std::wstring_view borrowed) {
    grimace::device_context dc(context);
    dc.text_out({0, 0}, owned);
    dc.text_out({0, 0}, borrowed);
    grimace::wstring<32> copied(owned);
    return static_cast<int>(copied.size() + grimace::wstring_view(borrowed).size());
}
#endif

struct counted_text {
    const wchar_t *characters;
    size_t count;

    constexpr const wchar_t *data() const {
        return characters;
    }

    constexpr size_t size() const {
        return count;
    }
};

static_assert(grimace::wstring_view(counted_text{L"counted", 5}) == grimace::wstring_view(L"count"));
static_assert(grimace::wstring_view(grimace::wstring<8>(L"abc")).size() == 3);

RECT main_window_area() {
    return grimace::work_area_rect();
}

static_assert(grimace::wstring_view(L"window").starts_with(L"win"));
static_assert(grimace::wstring_view(L"window").find(L"dow") == 3);
static_assert(grimace::wstring<8>(L"overflowing").size() == 7);
static_assert(grimace::to_utf8<16>(L"café").size() == 5);
static_assert(grimace::to_wstring<16>("caf\xc3\xa9") == grimace::wstring_view(L"café"));
static_assert(grimace::to_wstring<16>("\xf0\x9f\x98\x80").size() == 2);
static_assert(grimace::to_utf8<16>(grimace::to_wstring<16>("\xf0\x9f\x98\x80")) == grimace::string_view("\xf0\x9f\x98\x80"));
static_assert(grimace::to_wstring<16>("a\xffz") == grimace::wstring_view(L"a\xfffdz"));
static_assert(grimace::to_wstring<16>("\xed\xa0\x80") == grimace::wstring_view(L"\xfffd"));
static_assert(grimace::to_wstring<3>("ab\xf0\x9f\x98\x80").size() == 2);
static_assert(grimace::to_utf8<4>(L"a€").size() == 1);
static_assert(grimace::error::from_hresult(E_FAIL).is_hresult());
static_assert(grimace::error{ERROR_FILE_NOT_FOUND}.hresult() == static_cast<HRESULT>(0x80070002));
static_assert(!grimace::check_hresult(E_FAIL));
static_assert(grimace::optional<int>(3).value_or(4) == 3);
static_assert(grimace::optional<int>().value_or(4) == 4);

enum class mode : unsigned char { first, second };

int format_everything(int count, const wchar_t *name, unsigned short code, mode current, const char *narrow) {
    grimace::wstring<16> label = L"label";
    auto first = grimace::format<64>(L"Taps: %d\nTap anywhere, Esc to quit", count);
    auto second = grimace::format(L"%s has %u items, code %04X, %c, %d, %-8s|", name, 3u, code, L'x', current, label);
    auto third = grimace::format<32>(L"%.10s %S %%", name, narrow);
    grimace::wstring<24> fourth;
    bool fitted = grimace::format_to(fourth, L"%#x %lu", 255, 7ul);
#if GRIMACE_CE >= 3
    grimace::string<8> short_narrow = "abc";
    auto fifth = grimace::format<96>(L"%.2f %e %G %+d %I64d %I64X %p %hs %S", 1.5, 2.0f, 3.0, count, 1LL << 40, 0xFFFFull, name, narrow, short_narrow);
    return static_cast<int>(first.size() + second.size() + third.size() + fourth.size() + fifth.size()) + fitted;
#else
    return static_cast<int>(first.size() + second.size() + third.size() + fourth.size()) + fitted;
#endif
}

namespace {

class every_handler : public grimace::window<every_handler> {
public:
    static constexpr const wchar_t *class_name = L"EveryHandler";
    static constexpr UINT class_style = CS_DBLCLKS;

    static HBRUSH background() {
        return static_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));
    }

    bool on_create() {
        return true;
    }

    void on_paint(grimace::paint_dc &dc) {
        auto pen = grimace::create_pen(PS_SOLID, 1, RGB(0, 0, 0));
        auto brush = grimace::create_solid_brush(RGB(255, 255, 255));
        auto selected_pen = dc.select(pen);
        auto selected_brush = dc.select(brush);
        dc.rectangle(client_rect());
        POINT line[] = {{0, 0}, {10, 10}};
        dc.polyline(line);
        dc.text_out({2, 2}, L"text");
    }

    void on_tap(grimace::point where) {
        grimace::window_dc dc(handle());
        dc.ellipse({where.x - 2, where.y - 2, where.x + 2, where.y + 2});
    }

    bool on_key(UINT key) {
        return key == VK_ESCAPE;
    }

    void on_command(WORD id, WORD code, HWND control) {
        last_command = id + code + (control ? 1 : 0);
    }

    bool on_message(UINT message, WPARAM, LPARAM, LRESULT &result) {
        if (message == WM_ERASEBKGND) {
            result = 1;
            return true;
        }
        return false;
    }

    void on_destroy() {
        PostQuitMessage(0);
    }

private:
    int last_command = 0;
};

class no_handlers : public grimace::window<no_handlers> {
public:
    static constexpr const wchar_t *class_name = L"NoHandlers";
};

}

int use_everything(HINSTANCE instance) {
    auto event = grimace::create_event(false, false);
    if (!event) {
        return static_cast<int>(event.error().code);
    }
    grimace::unique_handle moved = grimace::move(*event);
    auto file = grimace::create_file(L"\\missing.txt", GENERIC_READ, 0, OPEN_EXISTING);
    auto buffer = grimace::local_alloc<WCHAR>(32);
    if (!buffer) {
        return -1;
    }
    buffer[0] = L'x';
    if (!every_handler::register_class(instance) || !no_handlers::register_class(instance)) {
        return -2;
    }
    every_handler first;
    no_handlers second;
    if (!first.create(instance, L"Every", WS_VISIBLE, grimace::screen_rect()) || !second.create(instance, L"None", 0, RECT{0, 0, 10, 10})) {
        return -3;
    }
    return grimace::run_message_loop() + (file ? 1 : 0) + (moved ? 1 : 0);
}

bool has_imports() {
    return ce_has(MessageBoxW) && ce_has(GetModuleFileNameW);
}

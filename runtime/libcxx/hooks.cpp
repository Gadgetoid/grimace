#include <windows.h>

#include <exception>
#include <new>
#include <stdarg.h>

namespace std {
inline namespace __1 {

[[noreturn]] void __libcpp_verbose_abort(const char *format, ...) noexcept {
    char message[256];
    wchar_t wide[256];
    va_list arguments;
    va_start(arguments, format);
    vsnprintf(message, sizeof(message), format, arguments);
    va_end(arguments);
    mbstowcs(wide, message, 255);
    wide[255] = 0;
    OutputDebugStringW(wide);
    __builtin_trap();
}

}

const nothrow_t nothrow{};

exception::~exception() noexcept {}

const char *exception::what() const noexcept {
    return "std::exception";
}

}

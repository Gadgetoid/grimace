#include <windows.h>

#include <initializer_list>
#include <new>

static int constructed_globals;
static int destroyed_globals;

class counted {
public:
    explicit counted(int value) : value(value) {
        constructed_globals++;
    }

    ~counted() {
        destroyed_globals++;
    }

    int value;
};

class exit_report {
public:
    ~exit_report() {
        WCHAR text[64];
        wsprintfW(text, L"cxx-basics: %d destructors ran\r\n", destroyed_globals);
        OutputDebugStringW(text);
    }
};

exit_report report;

counted first_global(3);
counted second_global(4);

class shape {
public:
    virtual ~shape() = default;
    virtual int area() const = 0;
    virtual const wchar_t *name() const = 0;
};

class rectangle : public shape {
public:
    rectangle(int width, int height) : width(width), height(height) {}

    int area() const override {
        return width * height;
    }

    const wchar_t *name() const override {
        return L"rectangle";
    }

private:
    int width;
    int height;
};

class square : public rectangle {
public:
    explicit square(int side) : rectangle(side, side) {}

    const wchar_t *name() const override {
        return L"square";
    }
};

static int static_local_calls;

static int next_id() {
    static counted id(++static_local_calls * 100);
    return ++id.value;
}

template <typename T, typename Function>
T sum_of(std::initializer_list<T> values, Function transform) {
    T total{};
    for (const T &value : values) {
        total += transform(value);
    }
    return total;
}

struct alignas(16) aligned_block {
    int values[4];
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    shape *shapes[] = {new rectangle(first_global.value, second_global.value), new square(5)};
    int total_area = 0;
    for (shape *item : shapes) {
        total_area += item->area();
    }
    const wchar_t *last_name = shapes[1]->name();
    for (shape *item : shapes) {
        delete item;
    }

    int first_id = next_id();
    int second_id = next_id();

    int offset = 10;
    int squares = sum_of({1, 2, 3}, [offset](int value) { return value * value + offset; });

    int *numbers = new int[8];
    numbers[7] = 7;
    int last_number = numbers[7];
    delete[] numbers;

    aligned_block *block = new aligned_block{};
    bool aligned = (reinterpret_cast<unsigned long>(block) & 15) == 0;
    delete block;

    int *nothing = new (std::nothrow) int(5);
    int nothrow_value = nothing ? *nothing : 0;
    delete nothing;

    WCHAR library_text[64] = L"not loaded";
    LPCWSTR library_path = command_line[0] ? command_line : L"cxx-counter.dll";
    if (HMODULE library = LoadLibraryW(library_path)) {
        auto get_count = reinterpret_cast<int (*)()>(GetProcAddressW(library, L"ConstructedCount"));
        wsprintfW(library_text, L"%d constructed", get_count ? get_count() : -1);
        FreeLibrary(library);
    }

    WCHAR text[256];
    wsprintfW(text,
              L"Globals constructed: %d\nArea: %d (last: %s)\nStatic local: %d, %d (init %d)\nLambda: %d\n"
              L"Array: %d, aligned: %d, nothrow: %d\nDLL: %s",
              constructed_globals, total_area, last_name, first_id, second_id, static_local_calls, squares, last_number,
              aligned, nothrow_value, library_text);
    MessageBoxW(0, text, L"C++ basics", MB_OK | MB_ICONINFORMATION);
    return 0;
}

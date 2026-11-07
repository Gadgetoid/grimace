#include <windows.h>

#include <algorithm>
#include <array>
#include <deque>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <variant>
#include <vector>

namespace {

struct item {
    std::wstring name;
    int quantity;
    int price_pence;
};

class shape {
public:
    virtual ~shape() = default;
    virtual int area() const = 0;
};

class rectangle : public shape {
public:
    rectangle(int width, int height) : width(width), height(height) {}
    int area() const override {
        return width * height;
    }

private:
    int width;
    int height;
};

class square : public shape {
public:
    explicit square(int side) : side(side) {}
    int area() const override {
        return side * side;
    }

private:
    int side;
};

std::optional<item> find_item(const std::map<std::wstring, item> &stock, const std::wstring &name) {
    auto found = stock.find(name);
    if (found == stock.end()) {
        return std::nullopt;
    }
    return found->second;
}

int sum(std::span<const int> values) {
    return std::accumulate(values.begin(), values.end(), 0);
}

using setting = std::variant<int, bool, std::wstring>;

std::wstring describe(const setting &value) {
    return std::visit(
        [](const auto &held) -> std::wstring {
            using held_type = std::decay_t<decltype(held)>;
            if constexpr (std::is_same_v<held_type, int>) {
                return L"number " + std::to_wstring(held);
            } else if constexpr (std::is_same_v<held_type, bool>) {
                return held ? L"on" : L"off";
            } else {
                return L"\"" + held + L"\"";
            }
        },
        value);
}

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    std::map<std::wstring, item> stock;
    for (const item &entry : {item{L"battery", 2, 2999}, item{L"stylus", 5, 499}, item{L"cf card", 1, 1999}}) {
        stock[entry.name] = entry;
    }
    int value = std::accumulate(stock.begin(), stock.end(), 0,
                                [](int total, const auto &entry) { return total + entry.second.quantity * entry.second.price_pence; });

    std::set<std::wstring> categories = {L"power", L"input", L"storage", L"input"};

    std::deque<int> recent;
    for (int tap = 1; tap <= 6; tap++) {
        recent.push_back(tap * tap);
        if (recent.size() > 4) {
            recent.pop_front();
        }
    }

    std::vector<std::unique_ptr<shape>> shapes;
    shapes.push_back(std::make_unique<rectangle>(3, 4));
    shapes.push_back(std::make_unique<square>(5));
    int total_area = 0;
    for (const auto &each : shapes) {
        total_area += each->area();
    }

    auto shared = std::make_shared<square>(2);
    std::shared_ptr<shape> alias = shared;

    std::array<int, 5> readings = {4, 8, 15, 16, 23};
    std::vector<int> evens;
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(evens), [](int reading) { return reading % 2 == 0; });

    std::vector<setting> settings = {42, true, std::wstring(L"Jornada")};

    std::wstring report = L"Stock value: " + std::to_wstring(value / 100) + L"." + std::to_wstring(value % 100 / 10) + std::to_wstring(value % 10);
    report += L"\nCategories: " + std::to_wstring(categories.size());
    std::optional<item> stylus = find_item(stock, L"stylus");
    report += L"\nStylus: " + (stylus ? std::to_wstring(stylus->quantity) + L" in stock" : std::wstring(L"none"));
    report += L"\nModem: " + std::wstring(find_item(stock, L"modem") ? L"in stock" : L"none");
    report += L"\nRecent: " + std::to_wstring(recent.front()) + L" to " + std::to_wstring(recent.back());
    report += L"\nShape area: " + std::to_wstring(total_area) + L", shared " + std::to_wstring(alias->area()) + L" (" +
              std::to_wstring(shared.use_count()) + L" owners)";
    report += L"\nReadings: sum " + std::to_wstring(sum(readings)) + L", " + std::to_wstring(evens.size()) + L" even";
    for (const setting &each : settings) {
        report += L"\nSetting: " + describe(each);
    }

    MessageBoxW(nullptr, report.c_str(), L"stl-collections", MB_OK);
    return 0;
}

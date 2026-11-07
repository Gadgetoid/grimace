#include <windows.h>

#include <algorithm>
#include <any>
#include <bitset>
#include <charconv>
#include <deque>
#include <expected>
#include <format>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <variant>
#include <vector>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
    std::function<int(int)> twice = [](int value) { return value * 2; };
    std::any held = 5;
    std::bitset<16> flags(0x5a5a);
    char digits[16];
    auto converted = std::to_chars(digits, digits + sizeof(digits), 12345);
    std::forward_list<int> singly = {3, 1, 2};
    singly.sort();
    std::list<int> doubly(singly.begin(), singly.end());
    std::priority_queue<int> heap;
    heap.push(4);
    heap.push(9);
    std::stack<int, std::deque<int>> pile;
    pile.push(1);
    std::unordered_set<int> seen = {1, 2, 3};
    std::tuple<int, char> pair{1, 'a'};
    std::mt19937 generator(42);
    std::uniform_int_distribution<int> dice(1, 6);
    auto evens = std::views::iota(1, 10) | std::views::filter([](int value) { return value % 2 == 0; });
    int even_sum = 0;
    for (int value : evens) {
        even_sum += value;
    }
    std::weak_ptr<int> watcher;
    {
        auto owner = std::make_shared<int>(7);
        watcher = owner;
    }
    std::expected<int, int> outcome = 3;
    std::string formatted = std::format("{} and {}", 1, 2);
    std::string floating = std::format("{:.2f}", 3.14159);
    std::wstring text = std::to_wstring(twice(std::any_cast<int>(held)) + static_cast<int>(flags.count()) + heap.top() + pile.top() +
                                        static_cast<int>(seen.size()) + std::get<0>(pair) + dice(generator) + even_sum + doubly.front() +
                                        watcher.expired() + *outcome + static_cast<int>(converted.ptr - digits) +
                                        static_cast<int>(formatted.size() + floating.size()));
    MessageBoxW(nullptr, text.c_str(), L"stdlib", MB_OK);
    return 0;
}

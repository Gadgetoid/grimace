#include <windows.h>

#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace {

constexpr std::wstring_view passage =
    L"The Jornada 720 has a StrongARM processor, a colour screen and a keyboard. "
    L"The keyboard is small but the keyboard is good, and the screen is bright.";

std::wstring lowercase(std::wstring_view word) {
    std::wstring result(word);
    std::transform(result.begin(), result.end(), result.begin(), [](wchar_t character) { return towlower(character); });
    return result;
}

std::vector<std::wstring> split_words(std::wstring_view text) {
    std::vector<std::wstring> words;
    size_t start = 0;
    while (start < text.size()) {
        while (start < text.size() && !iswalpha(text[start]) && !iswdigit(text[start])) {
            start++;
        }
        size_t end = start;
        while (end < text.size() && (iswalpha(text[end]) || iswdigit(text[end]))) {
            end++;
        }
        if (end > start) {
            words.push_back(lowercase(text.substr(start, end - start)));
        }
        start = end;
    }
    return words;
}

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    std::vector<std::wstring> words = split_words(passage);

    std::unordered_map<std::wstring, int> counts;
    for (const std::wstring &word : words) {
        counts[word]++;
    }

    std::vector<std::pair<std::wstring, int>> ranked(counts.begin(), counts.end());
    std::sort(ranked.begin(), ranked.end(), [](const auto &first, const auto &second) {
        return first.second != second.second ? first.second > second.second : first.first < second.first;
    });

    std::wstring report = std::to_wstring(words.size()) + L" words, " + std::to_wstring(counts.size()) + L" different:\n";
    for (size_t index = 0; index < ranked.size() && index < 5; index++) {
        report += L"\n" + ranked[index].first + L": " + std::to_wstring(ranked[index].second);
    }

    auto longest = std::max_element(words.begin(), words.end(), [](const std::wstring &first, const std::wstring &second) {
        return first.size() < second.size();
    });
    report += L"\n\nLongest: " + *longest;

    MessageBoxW(nullptr, report.c_str(), L"stl-text", MB_OK);
    return 0;
}

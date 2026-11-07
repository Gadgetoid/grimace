#include <windows.h>

static HANDLE results = INVALID_HANDLE_VALUE;
static WCHAR summary[1024];

static void report(const WCHAR *name, int has, DWORD result, DWORD error) {
    WCHAR line[128];
    DWORD written;
    wsprintfW(line, L"lazy: %s has=%d result=%u error=%u\r\n", name, has, result, error);
    OutputDebugStringW(line);
    if (wcslen(summary) + wcslen(line) < 1024) {
        wcscat(summary, line + 6);
    }
    if (results != INVALID_HANDLE_VALUE) {
        WriteFile(results, line, wcslen(line) * sizeof(WCHAR), &written, NULL);
    }
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WCHAR wide[16];
    WCHAR path[MAX_PATH];
    DWORD result;

    results = CreateFileW(command_line[0] ? command_line : L"\\lazy.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    SetLastError(0);
    result = MultiByteToWideChar(CP_ACP, 0, "grimace", -1, wide, 16);
    report(L"MultiByteToWideChar", ce_has(MultiByteToWideChar), result == 8 && wide[0] == L'g' && wide[6] == L'e', GetLastError());

    SetLastError(0);
    result = GetModuleFileNameW(NULL, path, MAX_PATH);
    report(L"GetModuleFileNameW", ce_has(GetModuleFileNameW), result, GetLastError());

    SetLastError(0);
    result = FindResourceW(instance, MAKEINTRESOURCEW(1), RT_GROUP_ICON) != NULL;
    report(L"FindResourceW", ce_has(FindResourceW), result, GetLastError());

#ifdef __grimace_lazy_CreateColorBitmap
    report(L"CreateColorBitmap", ce_has(CreateColorBitmap), 0, 0);
#endif
    report(L"MessageBoxW", ce_has(MessageBoxW), 1, 0);
    report(L"done", 1, 0, 0);
    if (results != INVALID_HANDLE_VALUE) {
        CloseHandle(results);
    }
    MessageBoxW(NULL, summary, L"lazy", MB_OK);
    return 0;
}

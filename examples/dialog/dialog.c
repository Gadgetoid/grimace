#include <windows.h>

#include "resource.h"

#define NAME_LENGTH 64
#define TEXT_LENGTH 128

static WCHAR name[NAME_LENGTH];

static BOOL CALLBACK dialog_procedure(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam) {
    switch (message) {
    case WM_INITDIALOG:
        SetFocus(GetDlgItem(dialog, IDC_NAME));
        return FALSE;
    case WM_COMMAND:
        if (LOWORD(wparam) == IDOK) {
            GetDlgItemTextW(dialog, IDC_NAME, name, NAME_LENGTH);
            EndDialog(dialog, IDOK);
            return TRUE;
        }
        if (LOWORD(wparam) == IDCANCEL) {
            EndDialog(dialog, IDCANCEL);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPWSTR command_line, int show) {
    WCHAR title[TEXT_LENGTH];
    WCHAR greeting[TEXT_LENGTH];
    WCHAR text[TEXT_LENGTH + NAME_LENGTH];
    if (DialogBoxW(instance, MAKEINTRESOURCEW(IDD_NAME), NULL, dialog_procedure) != IDOK || name[0] == 0) {
        return 0;
    }
    LoadStringW(instance, IDS_TITLE, title, TEXT_LENGTH);
    LoadStringW(instance, IDS_GREETING, greeting, TEXT_LENGTH);
    wsprintfW(text, greeting, name);
    MessageBoxW(NULL, text, title, MB_OK | MB_ICONINFORMATION);
    return 0;
}

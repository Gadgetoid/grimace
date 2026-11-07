#ifndef GRIMACE_SDK_COMMDLG_H
#define GRIMACE_SDK_COMMDLG_H


#ifdef __cplusplus
extern "C" {
#endif

struct tagCHOOSECOLOR;
struct tagCHOOSECOLOR {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    COLORREF rgbResult;
    COLORREF *lpCustColors;
    DWORD Flags;
    LPARAM lCustData;
    LPCCHOOKPROC lpfnHook;
    LPCTSTR lpTemplateName;
} __attribute__((packed, aligned(1)));

struct tagPD;
struct tagPD {
    DWORD cbStruct;
    HWND hwndOwner;
    HDC hdc;
    DWORD dwFlags;
    RECT rcMinMargin;
    RECT rcMargin;
    HINSTANCE hinst;
    LPARAM lCustData;
    LPPRINTHOOKPROC pfnPrintHook;
    LPCTSTR pszPrintTemplateName;
    HGLOBAL hglbPrintTemplateResource;
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_CPL_H
#define GRIMACE_SDK_CPL_H


#ifdef __cplusplus
extern "C" {
#endif

typedef LONG (*APPLET_PROC)(HWND, UINT, LONG, LONG);
struct tagCPLINFO;
typedef struct tagCPLINFO CPLINFO;
typedef struct tagCPLINFO *LPCPLINFO;
struct tagNEWCPLINFOW;
typedef struct tagNEWCPLINFOW *LPNEWCPLINFOW;
typedef LPNEWCPLINFOW LPNEWCPLINFO;
struct tagNEWCPLINFOA;
typedef struct tagNEWCPLINFOA *LPNEWCPLINFOA;
typedef struct tagNEWCPLINFOW NEWCPLINFOW;
typedef NEWCPLINFOW NEWCPLINFO;
typedef struct tagNEWCPLINFOA NEWCPLINFOA;
struct tagCPLINFO {
    int idIcon;
    int idName;
    int idInfo;
    LONG lData;
} __attribute__((packed, aligned(1)));

struct tagNEWCPLINFOA {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHelpContext;
    LONG lData;
    HICON hIcon;
    CHAR szName[32];
    CHAR szInfo[64];
    CHAR szHelpFile[128];
} __attribute__((packed, aligned(1)));

struct tagNEWCPLINFOW {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHelpContext;
    LONG lData;
    HICON hIcon;
    WCHAR szName[32];
    WCHAR szInfo[64];
    WCHAR szHelpFile[128];
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

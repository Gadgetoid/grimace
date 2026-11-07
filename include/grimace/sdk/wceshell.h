#ifndef GRIMACE_SDK_WCESHELL_H
#define GRIMACE_SDK_WCESHELL_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/shlobj.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _EXPLORERINFO;
typedef struct _EXPLORERINFO EXPLORERINFO;
struct IShellCommandUI;
typedef struct IShellCommandUI IShellCommandUI;
struct IShellCommandUIVtbl;
typedef struct IShellCommandUIVtbl IShellCommandUIVtbl;
struct IShellListView;
typedef struct IShellListView IShellListView;
struct IShellListViewVtbl;
typedef struct IShellListViewVtbl IShellListViewVtbl;
typedef const EXPLORERINFO *LPCEXPLORERINFO;
typedef struct _EXPLORERINFO *LPEXPLORERINFO;
typedef HRESULT (*PFNDLLCREATEBROWSEROBJECT)(const CLSID *const, const IID *const, LPVOID *);
typedef PFNDLLCREATEBROWSEROBJECT LPFNDLLCREATEBROWSEROBJECT;
typedef LRESULT (*LPFNSHELLFILTER)(UINT, LPITEMIDLIST);
typedef IShellCommandUI *LPSHELLCOMMANDUI;
typedef IShellListView *LPSHELLLISTVIEW;
struct IShellCommandUI {
    struct IShellCommandUIVtbl *lpVtbl;
};

struct IShellCommandUIVtbl {
    HRESULT (*QueryInterface)(IShellCommandUI *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellCommandUI *);
    ULONG (*Release)(IShellCommandUI *);
    HRESULT (*GetAttributes)(IShellCommandUI *, ULONG *);
    HRESULT (*CommandUIActivate)(IShellCommandUI *, HWND, HMENU, int, int);
    HRESULT (*CommandUIDeactivate)(IShellCommandUI *, HWND, HMENU);
    HRESULT (*Navigate)(IShellCommandUI *, BSTR, VARIANT *, VARIANT *, VARIANT *, VARIANT *);
    HRESULT (*Refresh)(IShellCommandUI *);
    HRESULT (*HandleCommand)(IShellCommandUI *, UINT, WPARAM, LPARAM, BOOL *);
};

struct IShellListView {
    struct IShellListViewVtbl *lpVtbl;
};

struct IShellListViewVtbl {
    HRESULT (*QueryInterface)(IShellListView *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellListView *);
    ULONG (*Release)(IShellListView *);
    HRESULT (*GetAttributes)(IShellListView *, ULONG *);
    HRESULT (*RegisterFilter)(IShellListView *, LPFNSHELLFILTER, UINT);
    HRESULT (*UIActivate)(IShellListView *, LPCEXPLORERINFO, HMENU, int, int);
    HRESULT (*UIDeactivate)(IShellListView *, LPCEXPLORERINFO, HMENU, int);
    HRESULT (*UpdateContents)(IShellListView *, LPCEXPLORERINFO);
    HRESULT (*ContextMenu)(IShellListView *, LPCEXPLORERINFO);
    HRESULT (*Notify)(IShellListView *, LPCEXPLORERINFO, UINT, WPARAM, LPARAM);
};

struct _EXPLORERINFO {
    DWORD uFlags;
    LPSHELLFOLDER lpsf;
    LPITEMIDLIST pidl;
    HWND hwndExplorer;
    HWND hwndListView;
    HWND hwndToolbar;
    HMENU hmenu;
    LONG idCmdFirst;
    UINT idView;
    UINT nSortOrder;
    BOOL fRecycle;
    CEOID oidRoot;
    BOOL fInLabelEdit;
    BOOL fShowBanner;
    DWORD dwData;
};


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_SHLOBJ_H
#define GRIMACE_SDK_SHLOBJ_H

#include <grimace/sdk/objbase.h>
#include <prsht.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct IShellFolder;
typedef struct IShellFolder IShellFolder;
typedef IShellFolder *LPSHELLFOLDER;
/**
 * Retrieves the IShellFolder interface for the desktop namespace root.
 *
 * Release the returned interface when it is no longer needed.
 *
 * @param ppshf Receives the desktop IShellFolder interface.
 * @return S_OK on success, or an HRESULT error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT SHGetDesktopFolder(LPSHELLFOLDER *ppshf);
/**
 * Retrieves the shell's IMalloc interface.
 *
 * Shell extensions must use this allocator for memory that the shell will
 * free. Applications can also use it for their own allocations.
 *
 * @param ppMalloc Receives the IMalloc interface pointer.
 * @return A successful HRESULT, or E_FAIL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT SHGetMalloc(LPMALLOC *ppMalloc);
struct _ITEMIDLIST;
typedef struct _ITEMIDLIST ITEMIDLIST;
typedef const ITEMIDLIST *LPCITEMIDLIST;
/**
 * Converts a file-system item identifier list to a path.
 *
 * The destination buffer must hold at least MAX_PATH characters. The
 * function fails for locations outside the file system.
 *
 * @param pidl Fully qualified item identifier list to convert.
 * @param pszPath Receives the path.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL SHGetPathFromIDList(LPCITEMIDLIST pidl, LPTSTR pszPath);
typedef struct _ITEMIDLIST *LPITEMIDLIST;
/**
 * Retrieves the item identifier list for a special folder.
 *
 * The result is relative to the desktop namespace. Free the returned list
 * with the shell IMalloc interface from SHGetMalloc.
 *
 * @param hwndOwner Owner window for any dialog or message box.
 * @param nFolder CSIDL identifying the folder.
 * @param ppidl Receives the folder's item identifier list.
 * @return NOERROR on success, or an OLE error on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT SHGetSpecialFolderLocation(HWND hwndOwner, int nFolder, LPITEMIDLIST *ppidl);
typedef int (*BFFCALLBACK)(HWND, UINT, LPARAM, LPARAM);
struct _browseinfo;
typedef struct _browseinfo BROWSEINFO;
struct _CMInvokeCommandInfo;
typedef struct _CMInvokeCommandInfo CMINVOKECOMMANDINFO;
typedef struct {
    DWORD cbSize;
    HWND hwndOwner;
    int iShow;
    DWORD dwFlags;
    RECT rect;
    LPUNKNOWN punkRel;
    OLECHAR strNewFile[260];
} FVSHOWINFO;

struct IContextMenu;
typedef struct IContextMenu IContextMenu;
struct IContextMenuVtbl;
typedef struct IContextMenuVtbl IContextMenuVtbl;
struct ICopyHook;
typedef struct ICopyHook ICopyHook;
struct ICopyHookVtbl;
typedef struct ICopyHookVtbl ICopyHookVtbl;
struct IEnumIDList;
typedef struct IEnumIDList IEnumIDList;
struct IEnumIDListVtbl;
typedef struct IEnumIDListVtbl IEnumIDListVtbl;
struct IExtractIcon;
typedef struct IExtractIcon IExtractIcon;
struct IExtractIconVtbl;
typedef struct IExtractIconVtbl IExtractIconVtbl;
struct IFileViewer;
typedef struct IFileViewer IFileViewer;
struct IFileViewerSite;
typedef struct IFileViewerSite IFileViewerSite;
struct IFileViewerSiteVtbl;
typedef struct IFileViewerSiteVtbl IFileViewerSiteVtbl;
struct IFileViewerVtbl;
typedef struct IFileViewerVtbl IFileViewerVtbl;
struct IShellExtInit;
typedef struct IShellExtInit IShellExtInit;
struct IShellExtInitVtbl;
typedef struct IShellExtInitVtbl IShellExtInitVtbl;
struct IShellFolderVtbl;
typedef struct IShellFolderVtbl IShellFolderVtbl;
struct IShellLink;
typedef struct IShellLink IShellLink;
struct IShellLinkVtbl;
typedef struct IShellLinkVtbl IShellLinkVtbl;
struct IShellPropSheetExt;
typedef struct IShellPropSheetExt IShellPropSheetExt;
struct IShellPropSheetExtVtbl;
typedef struct IShellPropSheetExtVtbl IShellPropSheetExtVtbl;
typedef struct _browseinfo *LPBROWSEINFO;
typedef struct _CMInvokeCommandInfo *LPCMINVOKECOMMANDINFO;
typedef IContextMenu *LPCONTEXTMENU;
typedef ICopyHook *LPCOPYHOOK;
struct _SHITEMID;
typedef struct _SHITEMID SHITEMID;
typedef const SHITEMID *LPCSHITEMID;
typedef struct IEnumIDList *LPENUMIDLIST;
typedef IExtractIcon *LPEXTRACTICON;
typedef IFileViewer *LPFILEVIEWER;
typedef IFileViewerSite *LPFILEVIEWERSITE;
typedef FVSHOWINFO *LPFVSHOWINFO;
typedef IShellExtInit *LPSHELLEXTINIT;
typedef IShellPropSheetExt *LPSHELLPROPSHEETEXT;
typedef struct _SHITEMID *LPSHITEMID;
struct _STRRET;
typedef struct _STRRET *LPSTRRET;
typedef struct _browseinfo *PBROWSEINFO;
enum tagSHCONTF {
    SHCONTF_FOLDERS = 32,
    SHCONTF_NONFOLDERS = 64,
    SHCONTF_INCLUDEHIDDEN = 128
};

typedef enum tagSHCONTF SHCONTF;
enum tagSHGDN {
    SHGDN_NORMAL = 0,
    SHGDN_INFOLDER = 1,
    SHGDN_FORPARSING = 32768
};

typedef enum tagSHGDN SHGNO;
typedef enum {
    SLGP_SHORTPATH = 1,
    SLGP_UNCPRIORITY = 2
} SLGP_FLAGS;

typedef enum {
    SLR_NO_UI = 1,
    SLR_ANY_MATCH = 2,
    SLR_UPDATE = 4
} SLR_FLAGS;

typedef struct _STRRET STRRET;
struct IContextMenu {
    struct IContextMenuVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IContextMenuVtbl {
    HRESULT (*QueryInterface)(IContextMenu *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IContextMenu *);
    ULONG (*Release)(IContextMenu *);
    HRESULT (*QueryContextMenu)(IContextMenu *, HMENU, UINT, UINT, UINT, UINT);
    HRESULT (*InvokeCommand)(IContextMenu *, LPCMINVOKECOMMANDINFO);
    HRESULT (*GetCommandString)(IContextMenu *, UINT, UINT, UINT *, LPSTR, UINT);
} __attribute__((packed, aligned(1)));

struct ICopyHook {
    struct ICopyHookVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct ICopyHookVtbl {
    HRESULT (*QueryInterface)(ICopyHook *, const IID *const, LPVOID *);
    ULONG (*AddRef)(ICopyHook *);
    ULONG (*Release)(ICopyHook *);
    UINT (*CopyCallback)(ICopyHook *, HWND, UINT, UINT, LPCSTR, DWORD, LPCSTR, DWORD);
} __attribute__((packed, aligned(1)));

struct IEnumIDList {
    struct IEnumIDListVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IEnumIDListVtbl {
    HRESULT (*QueryInterface)(IEnumIDList *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IEnumIDList *);
    ULONG (*Release)(IEnumIDList *);
    HRESULT (*Next)(IEnumIDList *, ULONG, LPITEMIDLIST *, ULONG *);
    HRESULT (*Skip)(IEnumIDList *, ULONG);
    HRESULT (*Reset)(IEnumIDList *);
    HRESULT (*Clone)(IEnumIDList *, IEnumIDList **);
} __attribute__((packed, aligned(1)));

struct IExtractIcon {
    struct IExtractIconVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IExtractIconVtbl {
    HRESULT (*QueryInterface)(IExtractIcon *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IExtractIcon *);
    ULONG (*Release)(IExtractIcon *);
    HRESULT (*GetIconLocation)(IExtractIcon *, UINT, LPSTR, UINT, int *, UINT *);
    HRESULT (*Extract)(IExtractIcon *, LPCSTR, UINT, HICON *, HICON *, UINT);
} __attribute__((packed, aligned(1)));

struct IFileViewer {
    struct IFileViewerVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IFileViewerSite {
    struct IFileViewerSiteVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IFileViewerSiteVtbl {
    HRESULT (*QueryInterface)(IFileViewerSite *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IFileViewerSite *);
    ULONG (*Release)(IFileViewerSite *);
    HRESULT (*SetPinnedWindow)(IFileViewerSite *, HWND);
    HRESULT (*GetPinnedWindow)(IFileViewerSite *, HWND *);
} __attribute__((packed, aligned(1)));

struct IFileViewerVtbl {
    HRESULT (*QueryInterface)(IFileViewer *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IFileViewer *);
    ULONG (*Release)(IFileViewer *);
    HRESULT (*ShowInitialize)(IFileViewer *, LPFILEVIEWERSITE);
    HRESULT (*Show)(IFileViewer *, LPFVSHOWINFO);
    HRESULT (*PrintTo)(IFileViewer *, LPSTR, BOOL);
} __attribute__((packed, aligned(1)));

struct IShellExtInit {
    struct IShellExtInitVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IShellExtInitVtbl {
    HRESULT (*QueryInterface)(IShellExtInit *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellExtInit *);
    ULONG (*Release)(IShellExtInit *);
    HRESULT (*Initialize)(IShellExtInit *, LPCITEMIDLIST, LPDATAOBJECT, HKEY);
} __attribute__((packed, aligned(1)));

struct IShellFolder {
    struct IShellFolderVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IShellFolderVtbl {
    HRESULT (*QueryInterface)(IShellFolder *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellFolder *);
    ULONG (*Release)(IShellFolder *);
    HRESULT (*ParseDisplayName)(IShellFolder *, HWND, LPBC, LPOLESTR, ULONG *, LPITEMIDLIST *, ULONG *);
    HRESULT (*EnumObjects)(IShellFolder *, HWND, DWORD, LPENUMIDLIST *);
    HRESULT (*BindToObject)(IShellFolder *, LPCITEMIDLIST, LPBC, const IID *const, LPVOID *);
    HRESULT (*BindToStorage)(IShellFolder *, LPCITEMIDLIST, LPBC, const IID *const, LPVOID *);
    HRESULT (*CompareIDs)(IShellFolder *, LPARAM, LPCITEMIDLIST, LPCITEMIDLIST);
    HRESULT (*CreateViewObject)(IShellFolder *, HWND, const IID *const, LPVOID *);
    HRESULT (*GetAttributesOf)(IShellFolder *, UINT, LPCITEMIDLIST *, ULONG *);
    HRESULT (*GetUIObjectOf)(IShellFolder *, HWND, UINT, LPCITEMIDLIST *, const IID *const, UINT *, LPVOID *);
    HRESULT (*GetDisplayNameOf)(IShellFolder *, LPCITEMIDLIST, DWORD, LPSTRRET);
    HRESULT (*SetNameOf)(IShellFolder *, HWND, LPCITEMIDLIST, LPCOLESTR, DWORD, LPITEMIDLIST *);
} __attribute__((packed, aligned(1)));

struct IShellLink {
    struct IShellLinkVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IShellLinkVtbl {
    HRESULT (*QueryInterface)(IShellLink *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellLink *);
    ULONG (*Release)(IShellLink *);
    HRESULT (*GetPath)(IShellLink *, LPSTR, int, WIN32_FIND_DATA *, DWORD);
    HRESULT (*GetIDList)(IShellLink *, LPITEMIDLIST *);
    HRESULT (*SetIDList)(IShellLink *, LPCITEMIDLIST);
    HRESULT (*GetDescription)(IShellLink *, LPSTR, int);
    HRESULT (*SetDescription)(IShellLink *, LPCSTR);
    HRESULT (*GetWorkingDirectory)(IShellLink *, LPSTR, int);
    HRESULT (*SetWorkingDirectory)(IShellLink *, LPCSTR);
    HRESULT (*GetArguments)(IShellLink *, LPSTR, int);
    HRESULT (*SetArguments)(IShellLink *, LPCSTR);
    HRESULT (*GetHotkey)(IShellLink *, WORD *);
    HRESULT (*SetHotkey)(IShellLink *, WORD);
    HRESULT (*GetShowCmd)(IShellLink *, int *);
    HRESULT (*SetShowCmd)(IShellLink *, int);
    HRESULT (*GetIconLocation)(IShellLink *, LPSTR, int, int *);
    HRESULT (*SetIconLocation)(IShellLink *, LPCSTR, int);
    HRESULT (*SetRelativePath)(IShellLink *, LPCSTR, DWORD);
    HRESULT (*Resolve)(IShellLink *, HWND, DWORD);
    HRESULT (*SetPath)(IShellLink *, LPCSTR);
} __attribute__((packed, aligned(1)));

struct IShellPropSheetExt {
    struct IShellPropSheetExtVtbl *lpVtbl;
} __attribute__((packed, aligned(1)));

struct IShellPropSheetExtVtbl {
    HRESULT (*QueryInterface)(IShellPropSheetExt *, const IID *const, LPVOID *);
    ULONG (*AddRef)(IShellPropSheetExt *);
    ULONG (*Release)(IShellPropSheetExt *);
    HRESULT (*AddPages)(IShellPropSheetExt *, LPFNADDPROPSHEETPAGE, LPARAM);
    HRESULT (*ReplacePage)(IShellPropSheetExt *, UINT, LPFNADDPROPSHEETPAGE, LPARAM);
} __attribute__((packed, aligned(1)));

struct _CMInvokeCommandInfo {
    DWORD cbSize;
    DWORD fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    DWORD dwHotKey;
    HANDLE hIcon;
} __attribute__((packed, aligned(1)));

struct _SHITEMID {
    UINT cb;
    BYTE abID[1];
} __attribute__((packed, aligned(1)));

struct _ITEMIDLIST {
    SHITEMID mkid;
} __attribute__((packed, aligned(1)));

struct _STRRET {
    UINT uType;
    union {
        LPWSTR pOleStr;
        UINT uOffset;
        char cStr[260];
    };
} __attribute__((packed, aligned(1)));

struct _browseinfo {
    HWND hwndOwner;
    LPCITEMIDLIST pidlRoot;
    LPSTR pszDisplayName;
    LPCSTR lpszTitle;
    UINT ulFlags;
    BFFCALLBACK lpfn;
    LPARAM lParam;
    int iImage;
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

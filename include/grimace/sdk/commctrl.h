#ifndef GRIMACE_SDK_COMMCTRL_H
#define GRIMACE_SDK_COMMCTRL_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Lines up the command bar's adornments, the buttons added with
 * CommandBar_AddAdornments, after its buttons or size change.
 *
 * @param hwndCB The command bar.
 *
 * @note Windows CE 3.0 only.
 */
void CommandBar_AlignAdornments(HWND hwndCB);
typedef struct _HD_HITTESTINFO HDHITTESTINFO;
typedef const COMMANDBANDSRESTOREINFO *LPCCOMMANDBANDSRESTOREINFO;
typedef LPNMMOUSE LPNMCLICK;
typedef NMSELCHANGE *LPNMSELECT;
typedef NMMOUSE NMCLICK;
typedef NMSELCHANGE NMSELECT;
struct _HD_ITEMA;
struct _HD_ITEMA {
    UINT mask;
    int cxy;
    LPSTR pszText;
    HBITMAP hbm;
    int cchTextMax;
    int fmt;
    LPARAM lParam;
    int iImage;
    int iOrder;
};

struct _HD_ITEMW;
struct _HD_ITEMW {
    UINT mask;
    int cxy;
    LPWSTR pszText;
    HBITMAP hbm;
    int cchTextMax;
    int fmt;
    LPARAM lParam;
    int iImage;
    int iOrder;
};

struct _IMAGELISTDRAWPARAMS;
struct _IMAGELISTDRAWPARAMS {
    DWORD cbSize;
    HIMAGELIST himl;
    int i;
    HDC hdcDst;
    int x;
    int y;
    int cx;
    int cy;
    int xBitmap;
    int yBitmap;
    COLORREF rgbBk;
    COLORREF rgbFg;
    UINT fStyle;
    DWORD dwRop;
};

struct tagLVCOLUMNA;
struct tagLVCOLUMNA {
    UINT mask;
    int fmt;
    int cx;
    LPSTR pszText;
    int cchTextMax;
    int iSubItem;
    int iImage;
    int iOrder;
};

struct tagLVCOLUMNW;
struct tagLVCOLUMNW {
    UINT mask;
    int fmt;
    int cx;
    LPWSTR pszText;
    int cchTextMax;
    int iSubItem;
    int iImage;
    int iOrder;
};

struct tagLVDISPINFO;
struct tagLVDISPINFO {
    NMHDR hdr;
    LVITEMA item;
};

struct tagLVDISPINFOW;
struct tagLVDISPINFOW {
    NMHDR hdr;
    LVITEMW item;
};

struct tagLVHITTESTINFO;
struct tagLVHITTESTINFO {
    POINT pt;
    UINT flags;
    int iItem;
    int iSubItem;
};

struct tagLVITEMA;
struct tagLVITEMA {
    UINT mask;
    int iItem;
    int iSubItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
    int iIndent;
};

struct tagLVITEMW;
struct tagLVITEMW {
    UINT mask;
    int iItem;
    int iSubItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
    int iIndent;
};

struct tagNMHEADERA;
struct tagNMHEADERA {
    NMHDR hdr;
    int iItem;
    int iButton;
    HDITEMA *pitem;
};

struct tagNMHEADERW;
struct tagNMHEADERW {
    NMHDR hdr;
    int iItem;
    int iButton;
    HDITEMW *pitem;
};

struct tagNMLVFINDITEM;
struct tagNMLVFINDITEM {
    NMHDR hdr;
    int iStart;
    LVFINDINFOW lvfi;
};

struct tagTCKEYDOWN;
struct tagTCKEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
};

struct tagTVDISPINFOA;
struct tagTVDISPINFOA {
    NMHDR hdr;
    TVITEMA item;
};

struct tagTVDISPINFOW;
struct tagTVDISPINFOW {
    NMHDR hdr;
    TVITEMW item;
};

struct tagTVKEYDOWN;
struct tagTVKEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
};


#ifdef __cplusplus
}
#endif

#endif

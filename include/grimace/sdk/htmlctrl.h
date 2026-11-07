#ifndef GRIMACE_SDK_HTMLCTRL_H
#define GRIMACE_SDK_HTMLCTRL_H

#include <grimace/sdk/imgrendr.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes the HTML viewer control.
 *
 * Load `Htmlview.dll` before calling this function. OEM support may vary.
 *
 * @param hinst Application instance used to create the DISPLAYCLASS window.
 * @return TRUE on success, FALSE on failure.
 */
BOOL InitHTMLControl(HINSTANCE hinst);
struct tagINLINEIMAGEINFO;
typedef struct tagINLINEIMAGEINFO INLINEIMAGEINFO;
typedef struct tagINLINEIMAGEINFO *LPINLINEIMAGEINFO;
struct tagNM_HTMLCONTEXT;
typedef struct tagNM_HTMLCONTEXT NM_HTMLCONTEXT;
struct tagNM_HTMLVIEW;
typedef struct tagNM_HTMLVIEW NM_HTMLVIEW;
struct tagINLINEIMAGEINFO {
    DWORD dwCookie;
    int iOrigHeight;
    int iOrigWidth;
    HBITMAP hbm;
    BOOL bOwnBitmap;
};

struct tagNM_HTMLCONTEXT {
    NMHDR hdr;
    POINT pt;
    UINT uTypeFlags;
    LPTSTR szLinkHREF;
    LPTSTR szImageSrc;
    HBITMAP hbmImage;
    DWORD dwImageCookie;
    struct IImageRender *pImageRender;
};

struct tagNM_HTMLVIEW {
    NMHDR hdr;
    LPSTR szTarget;
    LPSTR szData;
    DWORD dwCookie;
};


#ifdef __cplusplus
}
#endif

#endif

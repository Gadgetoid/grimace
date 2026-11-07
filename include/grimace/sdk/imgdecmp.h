#ifndef GRIMACE_SDK_IMGDECMP_H
#define GRIMACE_SDK_IMGDECMP_H

#include <grimace/sdk/imgrendr.h>

#ifdef __cplusplus
extern "C" {
#endif

struct tagDecompressImageInfo;
typedef struct tagDecompressImageInfo DecompressImageInfo;
/**
 * Decodes image data described by a DecompressImageInfo structure.
 *
 * Provide data in `pbBuffer` or through `pfnGetData`; `dwBufferCurrent`
 * reports the valid buffered bytes. Request an HBITMAP through `phBM`, an
 * IImageRender object through `ppImageRender`, or both. `iScale` is from 1
 * to 100. `crTransparentOverride` applies to GIF images when not set to
 * (UINT)-1.
 *
 * @param pParams Image input, output, sizing and callback settings.
 * @return HRESULT indicating success or failure.
 *
 * @note Windows CE 3.0 and later.
 */
HRESULT DecompressImageIndirect(DecompressImageInfo *pParams);
/**
 * Returns the 3-3-2 color palette.
 *
 * @return Pointer to COLORREF palette entries.
 *
 * @note Windows CE 3.0 and later.
 */
COLORREF * Get332Palette(void);
/**
 * Returns the halftone color palette.
 *
 * @return Pointer to COLORREF palette entries.
 *
 * @note Windows CE 3.0 and later.
 */
COLORREF * GetHalftonePalette(void);
/**
 * Returns the image decoder's transparent color.
 *
 * @return Transparent COLORREF value.
 *
 * @note Windows CE 3.0 and later.
 */
COLORREF GetTransparentColor(void);
typedef DWORD (*GETDATAFUNC)(LPSTR, DWORD, LPARAM);
typedef void (*PROGRESSFUNC)(IImageRender *, BOOL, LPARAM);
struct tagDecompressImageInfo {
    DWORD dwSize;
    LPBYTE pbBuffer;
    DWORD dwBufferMax;
    DWORD dwBufferCurrent;
    HBITMAP *phBM;
    IImageRender **ppImageRender;
    int iBitDepth;
    LPARAM lParam;
    HDC hdc;
    int iScale;
    int iMaxWidth;
    int iMaxHeight;
    GETDATAFUNC pfnGetData;
    PROGRESSFUNC pfnImageProgress;
    COLORREF crTransparentOverride;
};


#ifdef __cplusplus
}
#endif

#endif

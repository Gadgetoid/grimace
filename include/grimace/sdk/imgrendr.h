#ifndef GRIMACE_SDK_IMGRENDR_H
#define GRIMACE_SDK_IMGRENDR_H

#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct IImageRender;
typedef struct IImageRender IImageRender;
struct IImageRenderTransparentInfo;
typedef struct IImageRenderTransparentInfo IImageRenderTransparentInfo;
struct IImageRenderTransparentInfoVtbl;
typedef struct IImageRenderTransparentInfoVtbl IImageRenderTransparentInfoVtbl;
struct IImageRenderVtbl;
typedef struct IImageRenderVtbl IImageRenderVtbl;
struct IImageRender {
    struct IImageRenderVtbl *lpVtbl;
};

struct IImageRenderTransparentInfo {
    struct IImageRenderTransparentInfoVtbl *lpVtbl;
};

struct IImageRenderTransparentInfoVtbl {
    HRESULT (*QueryInterface)(IImageRenderTransparentInfo *, const IID *const, void **);
    ULONG (*AddRef)(IImageRenderTransparentInfo *);
    ULONG (*Release)(IImageRenderTransparentInfo *);
    HRESULT (*IsTransparent)(IImageRenderTransparentInfo *, BOOL *);
};

struct IImageRenderVtbl {
    HRESULT (*QueryInterface)(IImageRender *, const IID *const, void **);
    ULONG (*AddRef)(IImageRender *);
    ULONG (*Release)(IImageRender *);
    HRESULT (*Draw)(IImageRender *, HDC, RECT *);
    HRESULT (*GetBitmap)(IImageRender *, HBITMAP *, BOOL);
    HRESULT (*GetOrigWidth)(IImageRender *, int *);
    HRESULT (*GetOrigHeight)(IImageRender *, int *);
    HRESULT (*GetBits)(IImageRender *, unsigned char **);
    HRESULT (*ImageFail)(IImageRender *, BOOL *);
};


#ifdef __cplusplus
}
#endif

#endif

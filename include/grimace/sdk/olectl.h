#ifndef GRIMACE_SDK_OLECTL_H
#define GRIMACE_SDK_OLECTL_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Implemented by a self-registering COM server, which exports it, to add
 * its classes to the registry.
 *
 * @return S_OK on success, or an error HRESULT.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT DllRegisterServer(void);
/**
 * Implemented by a self-registering COM server, which exports it, to
 * remove the registry entries DllRegisterServer added.
 *
 * @return S_OK on success, or an error HRESULT.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT DllUnregisterServer(void);
struct tagFONTDESC;
typedef struct tagFONTDESC FONTDESC;
typedef struct tagFONTDESC *LPFONTDESC;
struct tagOCPFIPARAMS;
typedef struct tagOCPFIPARAMS *LPOCPFIPARAMS;
struct tagPICTDESC;
typedef struct tagPICTDESC *LPPICTDESC;
typedef struct tagOCPFIPARAMS OCPFIPARAMS;
typedef VARIANT_BOOL OLE_CANCELBOOL;
typedef VARIANT_BOOL OLE_ENABLEDEFAULTBOOL;
typedef VARIANT_BOOL OLE_OPTEXCLUSIVE;
typedef enum {
    triUnchecked = 0,
    triChecked = 1,
    triGray = 2
} OLE_TRISTATE;

typedef float OLE_XPOS_CONTAINER;
typedef long OLE_XPOS_PIXELS;
typedef float OLE_XSIZE_CONTAINER;
typedef long OLE_XSIZE_PIXELS;
typedef float OLE_YPOS_CONTAINER;
typedef long OLE_YPOS_PIXELS;
typedef float OLE_YSIZE_CONTAINER;
typedef long OLE_YSIZE_PIXELS;
typedef struct tagPICTDESC PICTDESC;
struct tagFONTDESC {
    UINT cbSizeofstruct;
    LPOLESTR lpstrName;
    CY cySize;
    SHORT sWeight;
    SHORT sCharset;
    BOOL fItalic;
    BOOL fUnderline;
    BOOL fStrikethrough;
} __attribute__((packed, aligned(8)));

struct tagOCPFIPARAMS {
    ULONG cbStructSize;
    HWND hWndOwner;
    int x;
    int y;
    LPCOLESTR lpszCaption;
    ULONG cObjects;
    LPUNKNOWN *lplpUnk;
    ULONG cPages;
    CLSID *lpPages;
    LCID lcid;
    DISPID dispidInitialProperty;
} __attribute__((packed, aligned(4)));

struct tagPICTDESC {
    UINT cbSizeofstruct;
    UINT picType;
    union {
        struct {
            HBITMAP hbitmap;
            HPALETTE hpal;
        } bmp;
        struct {
            HMETAFILE hmeta;
            int xExt;
            int yExt;
        } wmf;
        struct {
            HICON hicon;
        } icon;
        struct {
            HENHMETAFILE hemf;
        } emf;
    };
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

#include <windows.h>
#include <winddi.h>

static ENGCALLBACKS engine;

static DHPDEV enable_pdev(DEVMODEW *pdm, LPWSTR pwszLogAddress, ULONG cPat, HSURF *phsurfPatterns, ULONG cjCaps, ULONG *pdevcaps,
                          ULONG cjDevInfo, DEVINFO *pdi, HDEV hdev, LPWSTR pwszDeviceName, HANDLE hDriver) {
    GDIINFO *information = (GDIINFO *)pdevcaps;
    if (cjCaps < sizeof(GDIINFO)) {
        return NULL;
    }
    information->ulTechnology = DT_RASDISPLAY;
    information->ulHorzRes = 800;
    information->ulVertRes = 480;
    information->cBitsPixel = 16;
    information->cPlanes = 1;
    information->flRaster = RC_BITBLT;
    if (cjDevInfo >= sizeof(DEVINFO)) {
        pdi->flGraphicsCaps = GCAPS_PALMANAGED;
    }
    return (DHPDEV)hdev;
}

static VOID disable_pdev(DHPDEV dhpdev) {
}

static HSURF enable_surface(DHPDEV dhpdev) {
    SIZEL size = {800, 480};
    return engine.EngCreateDeviceSurface((DHSURF)dhpdev, size, BMF_16BPP);
}

static VOID disable_surface(DHPDEV dhpdev) {
}

static BOOL bit_blt(SURFOBJ *psoTrg, SURFOBJ *psoSrc, SURFOBJ *psoMask, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclTrg, POINTL *pptlSrc,
                    POINTL *pptlMask, BRUSHOBJ *pbo, POINTL *pptlBrush, ROP4 rop4) {
    ENUMRECTS rectangles;
    if (pco && pco->iDComplexity == DC_COMPLEX) {
        engine.CLIPOBJ_cEnumStart(pco, FALSE, CT_RECTANGLES, CD_ANY, 1);
        while (engine.CLIPOBJ_bEnum(pco, sizeof rectangles, (ULONG *)&rectangles)) {
        }
    }
    return TRUE;
}

static ULONG *get_masks(DHPDEV dhpdev) {
    static ULONG masks[3] = {0xF800, 0x07E0, 0x001F};
    return masks;
}

static VOID power_handler(DHPDEV dhpdev, BOOL bOff) {
    OutputDebugStringW(bOff ? L"display: off\r\n" : L"display: on\r\n");
}

BOOL APIENTRY DrvEnableDriver(ULONG iEngineVersion, ULONG cj, DRVENABLEDATA *pded, PENGCALLBACKS pEngCallbacks) {
    if (cj < sizeof(DRVENABLEDATA) || !pEngCallbacks) {
        return FALSE;
    }
    engine = *pEngCallbacks;
    pded->DrvEnablePDEV = enable_pdev;
    pded->DrvDisablePDEV = disable_pdev;
    pded->DrvEnableSurface = enable_surface;
    pded->DrvDisableSurface = disable_surface;
    pded->DrvBitBlt = bit_blt;
    pded->DrvGetMasks = get_masks;
    pded->DrvPowerHandler = power_handler;
    return TRUE;
}

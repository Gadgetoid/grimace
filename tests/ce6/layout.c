#include <windows.h>
#include <winddi.h>
#include <stddef.h>

_Static_assert(sizeof(SURFOBJ) == 52, "SURFOBJ");
_Static_assert(offsetof(SURFOBJ, sizlBitmap) == 16, "SURFOBJ.sizlBitmap");
_Static_assert(offsetof(SURFOBJ, pvScan0) == 32, "SURFOBJ.pvScan0");
_Static_assert(offsetof(SURFOBJ, lDelta) == 36, "SURFOBJ.lDelta");
_Static_assert(offsetof(SURFOBJ, iBitmapFormat) == 44, "SURFOBJ.iBitmapFormat");
_Static_assert(offsetof(SURFOBJ, iType) == 48, "SURFOBJ.iType");
_Static_assert(offsetof(SURFOBJ, fjBitmap) == 50, "SURFOBJ.fjBitmap");
_Static_assert(sizeof(CLIPOBJ) == 24, "CLIPOBJ");
_Static_assert(offsetof(CLIPOBJ, iDComplexity) == 20, "CLIPOBJ.iDComplexity");
_Static_assert(offsetof(CLIPOBJ, fjOptions) == 23, "CLIPOBJ.fjOptions");
_Static_assert(sizeof(ENUMRECTS) == 20, "ENUMRECTS");
_Static_assert(sizeof(BRUSHOBJ) == 12, "BRUSHOBJ");
_Static_assert(sizeof(XLATEOBJ) == 20, "XLATEOBJ");
_Static_assert(offsetof(XLATEOBJ, iDstType) == 10, "XLATEOBJ.iDstType");
_Static_assert(offsetof(XLATEOBJ, pulXlate) == 16, "XLATEOBJ.pulXlate");
_Static_assert(sizeof(PATHOBJ) == 8, "PATHOBJ");
_Static_assert(sizeof(PATHDATA) == 12, "PATHDATA");
_Static_assert(sizeof(LINEATTRS) == 32, "LINEATTRS");
_Static_assert(offsetof(LINEATTRS, elStyleState) == 28, "LINEATTRS.elStyleState");
_Static_assert(sizeof(POINTFIX) == 8, "POINTFIX");
_Static_assert(sizeof(RECTFX) == 16, "RECTFX");
_Static_assert(sizeof(LOGFONTW) == 92, "LOGFONTW");
_Static_assert(sizeof(DEVINFO) == 296, "DEVINFO");
_Static_assert(offsetof(DEVINFO, cFonts) == 280, "DEVINFO.cFonts");
_Static_assert(offsetof(DEVINFO, hpalDefault) == 292, "DEVINFO.hpalDefault");
_Static_assert(sizeof(GDIINFO) == 152, "GDIINFO");
_Static_assert(offsetof(GDIINFO, flRaster) == 36, "GDIINFO.flRaster");
_Static_assert(offsetof(GDIINFO, flTextCaps) == 48, "GDIINFO.flTextCaps");
_Static_assert(offsetof(GDIINFO, ulReserved1) == 52, "GDIINFO.ulReserved1");
_Static_assert(offsetof(GDIINFO, ulAspectX) == 68, "GDIINFO.ulAspectX");
_Static_assert(offsetof(GDIINFO, ptlPhysOffset) == 92, "GDIINFO.ptlPhysOffset");
_Static_assert(offsetof(GDIINFO, ulPanningVertRes) == 144, "GDIINFO.ulPanningVertRes");
_Static_assert(sizeof(DRVENABLEDATA) == 28 * sizeof(void *), "DRVENABLEDATA");
_Static_assert(offsetof(DRVENABLEDATA, DrvBitBlt) == 10 * sizeof(void *), "DRVENABLEDATA.DrvBitBlt");
_Static_assert(offsetof(DRVENABLEDATA, DrvAnyBlt) == 12 * sizeof(void *), "DRVENABLEDATA.DrvAnyBlt");
_Static_assert(offsetof(DRVENABLEDATA, DrvGetMasks) == 19 * sizeof(void *), "DRVENABLEDATA.DrvGetMasks");
_Static_assert(offsetof(DRVENABLEDATA, DrvPowerHandler) == 22 * sizeof(void *), "DRVENABLEDATA.DrvPowerHandler");
_Static_assert(offsetof(DRVENABLEDATA, DrvGradientFill) == 27 * sizeof(void *), "DRVENABLEDATA.DrvGradientFill");
_Static_assert(sizeof(ENGCALLBACKS) == 13 * sizeof(void *), "ENGCALLBACKS");
_Static_assert(offsetof(ENGCALLBACKS, CLIPOBJ_bEnum) == 3 * sizeof(void *), "ENGCALLBACKS.CLIPOBJ_bEnum");
_Static_assert(offsetof(ENGCALLBACKS, EngCreateDeviceSurface) == 9 * sizeof(void *), "ENGCALLBACKS.EngCreateDeviceSurface");
_Static_assert(offsetof(ENGCALLBACKS, EngCreatePalette) == 12 * sizeof(void *), "ENGCALLBACKS.EngCreatePalette");
_Static_assert(sizeof(VIDEO_POWER_MANAGEMENT) == 12, "VIDEO_POWER_MANAGEMENT");
_Static_assert(sizeof(DEVMODEW) == 192, "DEVMODEW");
_Static_assert(offsetof(DEVMODEW, dmDisplayOrientation) == 188, "DEVMODEW.dmDisplayOrientation");

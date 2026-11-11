#ifndef GRIMACE_WINDDI_H
#define GRIMACE_WINDDI_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

DECLARE_HANDLE(HSURF);
DECLARE_HANDLE(DHSURF);
DECLARE_HANDLE(DHPDEV);
DECLARE_HANDLE(HDEV);

typedef ULONG FLONG;
typedef ULONG MIX;
typedef ULONG ROP4;
typedef LONG FIX;
typedef FLOAT FLOATL;

typedef union _FLOAT_LONG {
    FLOATL e;
    LONG l;
} FLOAT_LONG, *PFLOAT_LONG;

typedef struct _POINTFIX {
    FIX x;
    FIX y;
} POINTFIX, *PPOINTFIX;

typedef struct _RECTFX {
    FIX xLeft;
    FIX yTop;
    FIX xRight;
    FIX yBottom;
} RECTFX, *PRECTFX;

#define DDI_ERROR 0xFFFFFFFF

#define DC_TRIVIAL 0
#define DC_RECT 1
#define DC_COMPLEX 3

#define CT_RECTANGLES 0

#define CD_RIGHTDOWN 0x00000000
#define CD_LEFTDOWN 0x00000001
#define CD_RIGHTUP 0x00000002
#define CD_LEFTUP 0x00000003
#define CD_ANY 0x00000004

#define BMF_1BPP 1
#define BMF_4BPP 2
#define BMF_8BPP 3
#define BMF_16BPP 4
#define BMF_24BPP 5
#define BMF_32BPP 6

#define BMF_TOPDOWN 0x0001

#define STYPE_BITMAP 0
#define STYPE_DEVICE 1
#define STYPE_DEVBITMAP 3

#define PD_BEGINSUBPATH 0x00000001
#define PD_ENDSUBPATH 0x00000002
#define PD_RESETSTYLE 0x00000004
#define PD_CLOSEFIGURE 0x00000008
#define PD_BEZIERS 0x00000010

#define PO_BEZIERS 0x00000001
#define PO_ELLIPSE 0x00000002
#define PO_ALL_INTEGERS 0x00000004
#define PO_ENUM_AS_INTEGERS 0x00000008

#define LA_GEOMETRIC 0x00000001
#define LA_ALTERNATE 0x00000002
#define LA_STARTGAP 0x00000004
#define LA_STYLED 0x00000008

#define JOIN_ROUND 0
#define JOIN_BEVEL 1
#define JOIN_MITER 2

#define ENDCAP_ROUND 0
#define ENDCAP_SQUARE 1
#define ENDCAP_BUTT 2

#define FP_ALTERNATEMODE 1
#define FP_WINDINGMODE 2

#define XO_TRIVIAL 0x00000001
#define XO_TABLE 0x00000002
#define XO_TO_MONO 0x00000004
#define XO_FROM_CMYK 0x00000008
#define XO_DEVICE_ICM 0x00000010
#define XO_HOST_ICM 0x00000020

#define XO_SRCPALETTE 1
#define XO_DESTPALETTE 2
#define XO_SRCBITFIELDS 4
#define XO_DESTBITFIELDS 5

#define PAL_INDEXED 0x00000001
#define PAL_BITFIELDS 0x00000002
#define PAL_RGB 0x00000004
#define PAL_BGR 0x00000008
#define PAL_CMYK 0x00000010

#define SPS_ERROR 0x00000000
#define SPS_DECLINE 0x00000001
#define SPS_ACCEPT_NOEXCLUDE 0x00000002
#define SPS_ACCEPT_EXCLUDE 0x00000003

#define HS_DDI_MAX 6

#define BLT_STRETCH 0x00000008

#define ED_ABORTDOC 0x00000001

#define GCAPS_BEZIERS 0x00000001
#define GCAPS_GEOMETRICWIDE 0x00000002
#define GCAPS_ALTERNATEFILL 0x00000004
#define GCAPS_WINDINGFILL 0x00000008
#define GCAPS_HALFTONE 0x00000010
#define GCAPS_COLOR_DITHER 0x00000020
#define GCAPS_HORIZSTRIKE 0x00000040
#define GCAPS_VERTSTRIKE 0x00000080
#define GCAPS_OPAQUERECT 0x00000100
#define GCAPS_VECTORFONT 0x00000200
#define GCAPS_MONO_DITHER 0x00000400
#define GCAPS_ASYNCCHANGE 0x00000800
#define GCAPS_ASYNCMOVE 0x00001000
#define GCAPS_DONTJOURNAL 0x00002000
#define GCAPS_ARBRUSHOPAQUE 0x00008000
#define GCAPS_PANNING 0x00010000
#define GCAPS_HIGHRESTEXT 0x00040000
#define GCAPS_PALMANAGED 0x00080000
#define GCAPS_DITHERONREALIZE 0x00200000
#define GCAPS_NO64BITMEMACCESS 0x00400000
#define GCAPS_FORCEDITHER 0x00800000
#define GCAPS_GRAY16 0x01000000

#define GETVFRAMEPHYSICAL 6144
#define GETVFRAMELEN 6145
#define DBGDRIVERSTAT 6146
#define SETPOWERMANAGEMENT 6147
#define GETPOWERMANAGEMENT 6148
#define CONTRASTCOMMAND 6149
#define DRVESC_SETGAMMAVALUE 6201
#define DRVESC_GETGAMMAVALUE 6202
#define DRVESC_SETSCREENROTATION 6301
#define DRVESC_GETSCREENROTATION 6302
#define DRVESC_SAVEVIDEOMEM 6501
#define DRVESC_RESTOREVIDEOMEM 6502
#define DRVESC_QUERYVIDEOMEMUSED 6503

/**
 * A drawing surface: the display, a device bitmap or a GDI bitmap.
 */
typedef struct _SURFOBJ {
    /**
     * The driver's handle, for a surface it manages.
     */
    DHSURF dhsurf;
    /**
     * GDI's handle.
     */
    HSURF hsurf;
    /**
     * Handle from DrvEnablePDEV, for a device surface.
     */
    DHPDEV dhpdev;
    HDEV hdev;
    /**
     * Width and height in pixels.
     */
    SIZEL sizlBitmap;
    ULONG cjBits;
    PVOID pvBits;
    /**
     * First line's address, for a GDI bitmap.
     */
    PVOID pvScan0;
    /**
     * Bytes from one line to the next; negative if bottom-up.
     */
    LONG lDelta;
    /**
     * Changes whenever the surface's contents change.
     */
    ULONG iUniq;
    /**
     * BMF_ format. A PW-SH2 also passes 9 for 2 bpp
     * bitmaps, which has no public name.
     */
    ULONG iBitmapFormat;
    /**
     * STYPE_BITMAP, STYPE_DEVICE or STYPE_DEVBITMAP. A GPE
     * driver's primary surface reports STYPE_BITMAP.
     */
    USHORT iType;
    USHORT fjBitmap;
} SURFOBJ;

/**
 * A clip region.
 */
typedef struct _CLIPOBJ {
    ULONG iUniq;
    /**
     * Bounds of the region, bottom-right exclusive.
     */
    RECTL rclBounds;
    /**
     * DC_TRIVIAL: draw without clipping. DC_RECT: clip
     * to rclBounds. DC_COMPLEX: enumerate the rectangles with
     * CLIPOBJ_cEnumStart and CLIPOBJ_bEnum.
     */
    BYTE iDComplexity;
    BYTE iFComplexity;
    BYTE iMode;
    BYTE fjOptions;
} CLIPOBJ;

/**
 * A batch of clip rectangles from CLIPOBJ_bEnum.
 */
typedef struct _ENUMRECTS {
    /**
     * Number of rectangles in arcl.
     */
    ULONG c;
    RECTL arcl[1];
} ENUMRECTS;

/**
 * A brush.
 */
typedef struct _BRUSHOBJ {
    /**
     * The color for a solid brush, or 0xFFFFFFFF for a
     * pattern brush.
     */
    ULONG iSolidColor;
    /**
     * The driver's realization, or NULL if none yet: call
     * BRUSHOBJ_pvGetRbrush.
     */
    PVOID pvRbrush;
    FLONG flColorType;
} BRUSHOBJ;

/**
 * How to translate colors from one palette to another.
 */
typedef struct _XLATEOBJ {
    /**
     * Identifies the translation for caching; 0 means don't
     * cache it.
     */
    ULONG iUniq;
    /**
     * XO_TRIVIAL: source colors need no translation. XO_TABLE:
     * pulXlate translates them. XO_TO_MONO: all colors map to 0 except
     * one.
     */
    FLONG flXlate;
    /**
     * Obsolete: use XLATEOBJ_cGetPalette.
     */
    USHORT iSrcType;
    /**
     * Obsolete: use XLATEOBJ_cGetPalette.
     */
    USHORT iDstType;
    /**
     * Number of entries in pulXlate.
     */
    ULONG cEntries;
    /**
     * Destination color for each source index, with XO_TABLE.
     */
    ULONG *pulXlate;
} XLATEOBJ;

typedef struct _PATHOBJ {
    FLONG fl;
    ULONG cCurves;
} PATHOBJ;

typedef struct _PATHDATA {
    FLONG flags;
    ULONG count;
    POINTFIX *pptfx;
} PATHDATA, *PPATHDATA;

typedef struct _LINEATTRS {
    FLONG fl;
    ULONG iJoin;
    ULONG iEndCap;
    FLOAT_LONG elWidth;
    FLOATL eMiterLimit;
    ULONG cstyle;
    PFLOAT_LONG pstyle;
    FLOAT_LONG elStyleState;
} LINEATTRS, *PLINEATTRS;

typedef struct _PALOBJ {
    ULONG ulReserved;
} PALOBJ;

typedef struct _XFORMOBJ {
    ULONG ulReserved;
} XFORMOBJ;

/**
 * The driver's graphics capabilities, filled in by DrvEnablePDEV.
 *
 * Its layout follows the desktop's, without the later flGraphicsCaps2:
 * 296 bytes, the cjDevInfo CE 6.0 passes on a PW-SH2.
 */
typedef struct _DEVINFO {
    /**
     * GCAPS_ flags.
     */
    FLONG flGraphicsCaps;
    LOGFONTW lfDefaultFont;
    LOGFONTW lfAnsiVarFont;
    LOGFONTW lfAnsiFixFont;
    ULONG cFonts;
    ULONG iDitherFormat;
    USHORT cxDither;
    USHORT cyDither;
    /**
     * Default palette, from the EngCreatePalette callback.
     */
    HPALETTE hpalDefault;
} DEVINFO, *PDEVINFO;

/**
 * The device's capabilities, filled in by DrvEnablePDEV.
 *
 * Windows CE's is shorter than the desktop's. The Windows CE 5.0
 * reference's declaration is 144 bytes, but CE 6.0 on a PW-SH2 passes a
 * cjCaps of 152, and a GPE driver's values place one undocumented word
 * after flTextCaps (ulReserved1). Where the other goes is unknown;
 * ulReserved2 keeps the size. A GPE driver puts the color count, 65536 at
 * 16 bpp, in ulNumBrushes's place.
 */
typedef struct tagGDIINFO {
    /**
     * Driver version: major in the high byte, minor in the
     * low byte.
     */
    ULONG ulVersion;
    /**
     * DT_RASDISPLAY for a display.
     */
    ULONG ulTechnology;
    /**
     * Width in millimetres.
     */
    ULONG ulHorzSize;
    /**
     * Height in millimetres.
     */
    ULONG ulVertSize;
    /**
     * Width in pixels.
     */
    ULONG ulHorzRes;
    /**
     * Height in pixels.
     */
    ULONG ulVertRes;
    /**
     * Bits per pixel.
     */
    ULONG cBitsPixel;
    /**
     * Planes, normally 1.
     */
    ULONG cPlanes;
    ULONG ulNumBrushes;
    /**
     * RC_ raster capabilities, such as RC_BITBLT.
     */
    ULONG flRaster;
    /**
     * Pixels per logical inch across.
     */
    ULONG ulLogPixelsX;
    /**
     * Pixels per logical inch down.
     */
    ULONG ulLogPixelsY;
    /**
     * 0, or GCAPS_GRAY16 for antialiased text. A GPE
     * driver copies DEVINFO.flGraphicsCaps here.
     */
    ULONG flTextCaps;
    /**
     * Undocumented; a GPE driver sets 0x17.
     */
    ULONG ulReserved1;
    ULONG ulDACRed;
    ULONG ulDACGreen;
    ULONG ulDACBlue;
    /**
     * Relative pixel width, 1 to 1000.
     */
    ULONG ulAspectX;
    /**
     * Relative pixel height, 1 to 1000.
     */
    ULONG ulAspectY;
    /**
     * Relative pixel diagonal: the square root of
     * ulAspectX squared plus ulAspectY squared.
     */
    ULONG ulAspectXY;
    LONG xStyleStep;
    LONG yStyleStep;
    LONG denStyleStep;
    POINTL ptlPhysOffset;
    SIZEL szlPhysSize;
    ULONG ulNumPalReg;
    ULONG ulDevicePelsDPI;
    ULONG ulPrimaryOrder;
    ULONG ulHTPatternSize;
    ULONG ulHTOutputFormat;
    ULONG flHTFlags;
    ULONG ulVRefresh;
    ULONG ulBltAlignment;
    ULONG ulPanningHorzRes;
    ULONG ulPanningVertRes;
    ULONG ulReserved2;
} GDIINFO, *PGDIINFO;

/**
 * A power state, for the SETPOWERMANAGEMENT and GETPOWERMANAGEMENT escapes.
 */
typedef struct _VIDEO_POWER_MANAGEMENT {
    /**
     * Size of the structure.
     */
    ULONG Length;
    ULONG DPMSVersion;
    /**
     * VideoPowerOn, VideoPowerStandBy, VideoPowerSuspend or
     * VideoPowerOff. VideoPowerOff idles the device as well as turning
     * off the display.
     */
    ULONG PowerState;
} VIDEO_POWER_MANAGEMENT, *PVIDEO_POWER_MANAGEMENT;

typedef enum _VIDEO_POWER_STATE {
    VideoPowerUnspecified = 0,
    VideoPowerOn = 1,
    VideoPowerStandBy,
    VideoPowerSuspend,
    VideoPowerOff
} VIDEO_POWER_STATE, *PVIDEO_POWER_STATE;

struct ContrastCmdInputParm {
    int command;
    int parm;
};

/**
 * The display driver's functions, filled in by DrvEnableDriver.
 *
 * Windows CE's form: a fixed set of function pointers, not the desktop's
 * array of indexed DRVFN entries. Leave NULL any the driver doesn't
 * implement. DrvContrastControl has no Windows CE 5.0 reference page.
 * On a PW-SH2, CE 6.0 passes a cj of 124: three more pointers after these,
 * which no public reference describes.
 */
typedef struct tagDrvEnableData {
    /**
     * See DrvEnablePDEV.
     */
    DHPDEV (*DrvEnablePDEV)(DEVMODEW *pdm, LPWSTR pwszLogAddress, ULONG cPat, HSURF *phsurfPatterns, ULONG cjCaps, ULONG *pdevcaps,
                            ULONG cjDevInfo, DEVINFO *pdi, HDEV hdev, LPWSTR pwszDeviceName, HANDLE hDriver);
    /**
     * See DrvDisablePDEV.
     */
    VOID (*DrvDisablePDEV)(DHPDEV dhpdev);
    /**
     * See DrvEnableSurface.
     */
    HSURF (*DrvEnableSurface)(DHPDEV dhpdev);
    /**
     * See DrvDisableSurface.
     */
    VOID (*DrvDisableSurface)(DHPDEV dhpdev);
    /**
     * See DrvCreateDeviceBitmap.
     */
    HBITMAP (*DrvCreateDeviceBitmap)(DHPDEV dhpdev, SIZEL sizl, ULONG iFormat);
    /**
     * See DrvDeleteDeviceBitmap.
     */
    VOID (*DrvDeleteDeviceBitmap)(DHSURF dhsurf);
    /**
     * See DrvRealizeBrush.
     */
    BOOL (*DrvRealizeBrush)(BRUSHOBJ *pbo, SURFOBJ *psoTarget, SURFOBJ *psoPattern, SURFOBJ *psoMask, XLATEOBJ *pxlo, ULONG iHatch);
    /**
     * See DrvStrokePath.
     */
    BOOL (*DrvStrokePath)(SURFOBJ *pso, PATHOBJ *ppo, CLIPOBJ *pco, XFORMOBJ *pxo, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, LINEATTRS *plineattrs,
                          MIX mix);
    /**
     * See DrvFillPath.
     */
    BOOL (*DrvFillPath)(SURFOBJ *pso, PATHOBJ *ppo, CLIPOBJ *pco, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, MIX mix, FLONG flOptions);
    /**
     * See DrvPaint.
     */
    BOOL (*DrvPaint)(SURFOBJ *pso, CLIPOBJ *pco, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, MIX mix);
    /**
     * See DrvBitBlt.
     */
    BOOL (*DrvBitBlt)(SURFOBJ *psoTrg, SURFOBJ *psoSrc, SURFOBJ *psoMask, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclTrg, POINTL *pptlSrc,
                      POINTL *pptlMask, BRUSHOBJ *pbo, POINTL *pptlBrush, ROP4 rop4);
    /**
     * See DrvCopyBits.
     */
    BOOL (*DrvCopyBits)(SURFOBJ *psoDest, SURFOBJ *psoSrc, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclDest, POINTL *pptlSrc);
    /**
     * See DrvAnyBlt.
     */
    BOOL (*DrvAnyBlt)(SURFOBJ *psoDest, SURFOBJ *psoSrc, SURFOBJ *psoMask, CLIPOBJ *pco, XLATEOBJ *pxlo, POINTL *pptlHTOrg, RECTL *prclDest,
                      RECTL *prclSrc, POINTL *pptlMask, BRUSHOBJ *pbo, POINTL *pptlBrush, ROP4 rop4, ULONG iMode, ULONG bltFlags);
    /**
     * See DrvTransparentBlt.
     */
    BOOL (*DrvTransparentBlt)(SURFOBJ *psoDest, SURFOBJ *psoSrc, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclDest, RECTL *prclSrc,
                              ULONG TransColor);
    /**
     * See DrvSetPalette.
     */
    BOOL (*DrvSetPalette)(DHPDEV dhpdev, PALOBJ *ppalo, FLONG fl, ULONG iStart, ULONG cColors);
    /**
     * See DrvSetPointerShape.
     */
    ULONG (*DrvSetPointerShape)(SURFOBJ *pso, SURFOBJ *psoMask, SURFOBJ *psoColor, XLATEOBJ *pxlo, LONG xHot, LONG yHot, LONG x, LONG y,
                                RECTL *prcl, FLONG fl);
    /**
     * See DrvMovePointer.
     */
    VOID (*DrvMovePointer)(SURFOBJ *pso, LONG x, LONG y, RECTL *prcl);
    /**
     * See DrvGetModes.
     */
    ULONG (*DrvGetModes)(HANDLE hDriver, ULONG cjSize, DEVMODEW *pdm);
    /**
     * See DrvRealizeColor.
     */
    ULONG (*DrvRealizeColor)(USHORT iDstType, ULONG cEntries, ULONG *pPalette, ULONG rgbColor);
    /**
     * See DrvGetMasks.
     */
    ULONG *(*DrvGetMasks)(DHPDEV dhpdev);
    /**
     * See DrvUnrealizeColor.
     */
    ULONG (*DrvUnrealizeColor)(USHORT iSrcType, ULONG cEntries, ULONG *pPalette, ULONG iRealizedColor);
    /**
     * See DrvContrastControl.
     */
    BOOL (*DrvContrastControl)(DHPDEV dhpdev, ULONG cmd, ULONG *pValue);
    /**
     * See DrvPowerHandler.
     */
    VOID (*DrvPowerHandler)(DHPDEV dhpdev, BOOL bOff);
    /**
     * See DrvEndDoc.
     */
    BOOL (*DrvEndDoc)(SURFOBJ *pso, FLONG fl);
    /**
     * See DrvStartDoc.
     */
    BOOL (*DrvStartDoc)(SURFOBJ *pso, PWSTR pwszDocName, DWORD dwJobId);
    /**
     * See DrvStartPage.
     */
    BOOL (*DrvStartPage)(SURFOBJ *pso);
    /**
     * See DrvEscape.
     */
    ULONG (*DrvEscape)(DHPDEV dhpdev, SURFOBJ *pso, ULONG iEsc, ULONG cjIn, PVOID pvIn, ULONG cjOut, PVOID pvOut);
    /**
     * See DrvGradientFill.
     */
    BOOL (*DrvGradientFill)(SURFOBJ *pso, CLIPOBJ *pco, XLATEOBJ *pxlo, TRIVERTEX *pVertex, ULONG nVertex, PVOID pMesh, ULONG nMesh,
                            RECTL *prclExtents, POINTL *pptlDitherOrg, ULONG ulMode);
} DRVENABLEDATA, *PDRVENABLEDATA;

/**
 * GDI's helper functions for display drivers, passed to DrvEnableDriver.
 *
 * Windows CE has no exported Eng* functions: drivers call GDI through this
 * table. On a PW-SH2, CE 6.0 passes 16 entries: three more after these,
 * which no public reference describes.
 */
typedef struct _ENGCALLBACKS {
    /**
     * Allocates cj bytes for a brush's
     * realization, which GDI keeps and frees. Returns NULL on failure.
     */
    PVOID (*BRUSHOBJ_pvAllocRbrush)(BRUSHOBJ *pbo, ULONG cj);
    /**
     * Returns a brush's realization, calling
     * DrvRealizeBrush first if it has none.
     */
    PVOID (*BRUSHOBJ_pvGetRbrush)(BRUSHOBJ *pbo);
    /**
     * Starts enumerating a clip region's
     * rectangles: bAll TRUE for the whole region, iType CT_RECTANGLES,
     * iDirection a CD_ order (CD_ANY if it doesn't matter), cLimit the
     * most to count.
     */
    ULONG (*CLIPOBJ_cEnumStart)(CLIPOBJ *pco, BOOL bAll, ULONG iType, ULONG iDirection, ULONG cLimit);
    /**
     * Writes an ENUMRECTS of up to cj bytes to pul.
     * Returns TRUE while more remain, possibly with a count of 0.
     */
    BOOL (*CLIPOBJ_bEnum)(CLIPOBJ *pco, ULONG cj, ULONG *pul);
    /**
     * Copies cColors entries from iStart into
     * pulColors. Returns the number copied.
     */
    ULONG (*PALOBJ_cGetColors)(PALOBJ *ppalo, ULONG iStart, ULONG cColors, ULONG *pulColors);
    /**
     * Starts, or restarts, enumerating a path.
     */
    VOID (*PATHOBJ_vEnumStart)(PATHOBJ *ppo);
    /**
     * Fills a PATHDATA with the next part of the path.
     * Returns TRUE while more remain.
     */
    BOOL (*PATHOBJ_bEnum)(PATHOBJ *ppo, PATHDATA *ppd);
    /**
     * Writes the path's bounds, bottom-right
     * exclusive, to prectfx.
     */
    VOID (*PATHOBJ_vGetBounds)(PATHOBJ *ppo, PRECTFX prectfx);
    /**
     * Copies cPal entries of the source or
     * destination palette (XO_SRCPALETTE, XO_DESTPALETTE) or its masks
     * (XO_SRCBITFIELDS, XO_DESTBITFIELDS) into pPal.
     */
    ULONG (*XLATEOBJ_cGetPalette)(XLATEOBJ *pxlo, ULONG iPal, ULONG cPal, ULONG *pPal);
    /**
     * Creates a handle for a surface the driver
     * manages. iFormatCompat is the BMF_ format GDI uses for any
     * temporary buffer. Returns 0 on failure.
     */
    HSURF (*EngCreateDeviceSurface)(DHSURF dhsurf, SIZEL sizl, ULONG iFormatCompat);
    /**
     * Deletes a surface or bitmap. Returns TRUE on
     * success.
     */
    BOOL (*EngDeleteSurface)(HSURF hsurf);
    /**
     * Creates a handle for a bitmap the driver
     * manages, as for EngCreateDeviceSurface.
     */
    HBITMAP (*EngCreateDeviceBitmap)(DHSURF dhsurf, SIZEL sizl, ULONG iFormatCompat);
    /**
     * Creates a palette: PAL_INDEXED from cColors
     * entries at pulColors, PAL_BITFIELDS from the three masks, or
     * PAL_RGB or PAL_BGR.
     */
    HPALETTE (*EngCreatePalette)(ULONG iMode, ULONG cColors, PULONG pulColors, FLONG flRed, FLONG flGreen, FLONG flBlue);
} ENGCALLBACKS, *PENGCALLBACKS;

/**
 * The display driver's entry point: fills in the driver's functions.
 *
 * GWES calls it when it loads the driver, the only function a display
 * driver must export. Fill in the members of DRVENABLEDATA for the
 * functions the driver implements and leave the rest NULL. Keep a copy of
 * pEngCallbacks: Windows CE has no exported Eng* functions, so the driver
 * calls GDI only through it. Do one-time setup here, but don't enable the
 * hardware until DrvEnablePDEV.
 *
 * @param iEngineVersion DDI version GDI was written for.
 * @param cj Size of DRVENABLEDATA as GDI knows it. GDI zeroes it first;
 *        don't write members beyond those the driver knows.
 * @param pded Receives the driver's function pointers.
 * @param pEngCallbacks GDI's helper functions for the driver.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvEnableDriver(ULONG iEngineVersion, ULONG cj, DRVENABLEDATA *pded, PENGCALLBACKS pEngCallbacks);
/**
 * Tells the driver GDI no longer needs it and is about to unload it.
 *
 * Free everything the driver allocated and return the device to the state
 * it was in before the driver loaded.
 */
VOID APIENTRY DrvDisableDriver(VOID);
/**
 * Optional first call into a display driver, before DrvEnableDriver.
 *
 * Gives the driver its registry instance, for finding its configuration,
 * such as a PCI display controller's.
 *
 * @param pszInstance The display's instance key in the registry.
 * @param dwNumMonitors Number of monitors found.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DisplayInit(LPCTSTR pszInstance, DWORD dwNumMonitors);

/**
 * Creates the driver's instance for a device and describes the device.
 *
 * Allocate the driver's own per-device data and return a handle to it;
 * GDI passes it back to the other functions, usually through a SURFOBJ.
 * Fill in GDIINFO and DEVINFO from the mode in pdm, but don't create the
 * surface until DrvEnableSurface.
 *
 * @param pdm Mode to use. With dmBitsPerPel, dmPelsWidth, dmPelsHeight
 *        and dmDisplayFrequency all 0, use the hardware's default mode.
 * @param pwszLogAddress Printers only; display drivers ignore it.
 * @param cPat Printers only; display drivers ignore it.
 * @param phsurfPatterns Printers only; display drivers ignore it.
 * @param cjCaps Size of the buffer at pdevcaps.
 * @param pdevcaps Receives a GDIINFO, zeroed by GDI. Write no more than
 *        cjCaps bytes.
 * @param cjDevInfo Size of the buffer at pdi. On rotation, CE 6.0 calls
 *        again with the width and height swapped and cjDevInfo 0.
 * @param pdi Receives a DEVINFO, zeroed by GDI. Write only the members
 *        the driver understands, and no more than cjDevInfo bytes.
 * @param hdev GDI's handle for the device.
 * @param pwszDeviceName The device's name.
 * @param hDriver The driver; display drivers pass it to DrvGetModes.
 * @return The driver's device handle, or NULL on failure.
 */
DHPDEV APIENTRY DrvEnablePDEV(DEVMODEW *pdm, LPWSTR pwszLogAddress, ULONG cPat, HSURF *phsurfPatterns, ULONG cjCaps, ULONG *pdevcaps,
                              ULONG cjDevInfo, DEVINFO *pdi, HDEV hdev, LPWSTR pwszDeviceName, HANDLE hDriver);
/**
 * Frees a device instance created by DrvEnablePDEV.
 *
 * GDI calls DrvDisableSurface first if the device has a surface.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 */
VOID APIENTRY DrvDisablePDEV(DHPDEV dhpdev);
/**
 * Creates the device's drawing surface.
 *
 * A driver that manages its own surface creates the handle with the
 * EngCreateDeviceSurface callback. Any GDI bitmap handle is also a valid
 * surface.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @return The surface, or 0 on failure.
 */
HSURF APIENTRY DrvEnableSurface(DHPDEV dhpdev);
/**
 * Frees the surface DrvEnableSurface created.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 */
VOID APIENTRY DrvDisableSurface(DHPDEV dhpdev);
/**
 * Creates a bitmap the driver manages, for example in video memory.
 *
 * Return 0 to let GDI create and manage the bitmap itself. The driver can
 * store the bitmap anywhere and in any format with at least the requested
 * bits per pixel.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @param sizl Width and height in pixels.
 * @param iFormat BMF_8BPP, BMF_16BPP, BMF_24BPP or BMF_32BPP, always the
 *        primary surface's format.
 * @return The bitmap, 0 to let GDI manage it, or 0xFFFFFFFF on error.
 */
HBITMAP APIENTRY DrvCreateDeviceBitmap(DHPDEV dhpdev, SIZEL sizl, ULONG iFormat);
/**
 * Deletes a bitmap made by DrvCreateDeviceBitmap.
 *
 * @param dhsurf The driver's handle for the bitmap.
 */
VOID APIENTRY DrvDeleteDeviceBitmap(DHSURF dhsurf);
/**
 * Converts a brush into the driver's own form for a surface.
 *
 * Allocate the realization with the BRUSHOBJ_pvAllocRbrush callback; GDI
 * keeps it in BRUSHOBJ.pvRbrush and frees it.
 *
 * @param pbo The brush. Pass it to BRUSHOBJ_pvAllocRbrush.
 * @param psoTarget Surface the brush is for.
 * @param psoPattern The brush's pattern.
 * @param psoMask 1 bpp transparency mask the size of the pattern; 0 marks
 *        a background pixel.
 * @param pxlo Translates the pattern's colors, or NULL for none.
 * @param iHatch Hatch style if the brush is a hatch brush (below
 *        HS_DDI_MAX), otherwise not.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvRealizeBrush(BRUSHOBJ *pbo, SURFOBJ *psoTarget, SURFOBJ *psoPattern, SURFOBJ *psoMask, XLATEOBJ *pxlo, ULONG iHatch);
/**
 * Draws a path's outline.
 *
 * Enumerate the path with the PATHOBJ_ callbacks and the clip region with
 * the CLIPOBJ_ callbacks. Update plineattrs->elStyleState for a styled
 * line.
 *
 * @param pso Surface to draw on.
 * @param ppo The path.
 * @param pco Clip region.
 * @param pxo Transform, needed only for geometric wide lines.
 * @param pbo Brush to draw with.
 * @param pptlBrushOrg Brush origin.
 * @param plineattrs Line width, style and joins.
 * @param mix Foreground and background mix modes.
 * @return TRUE if drawn, FALSE to have GDI draw it.
 */
BOOL APIENTRY DrvStrokePath(SURFOBJ *pso, PATHOBJ *ppo, CLIPOBJ *pco, XFORMOBJ *pxo, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, LINEATTRS *plineattrs,
                            MIX mix);
/**
 * Fills a closed path with a brush.
 *
 * Optional. Don't read pbo unless the mix needs a brush.
 *
 * @param pso Surface to draw on.
 * @param ppo The path.
 * @param pco Clip region.
 * @param pbo Brush to fill with.
 * @param pptlBrushOrg Brush origin.
 * @param mix Foreground and background mix modes.
 * @param flOptions Unused.
 * @return TRUE if filled, FALSE with no error logged to have GDI fill it.
 */
BOOL APIENTRY DrvFillPath(SURFOBJ *pso, PATHOBJ *ppo, CLIPOBJ *pco, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, MIX mix, FLONG flOptions);
/**
 * Paints a region with a brush.
 *
 * The Windows CE 5.0 reference says GDI no longer calls it.
 *
 * @param pso Surface to draw on.
 * @param pco Region to paint.
 * @param pbo Brush to paint with.
 * @param pptlBrushOrg Brush origin.
 * @param mix Foreground and background mix modes.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvPaint(SURFOBJ *pso, CLIPOBJ *pco, BRUSHOBJ *pbo, POINTL *pptlBrushOrg, MIX mix);
/**
 * Transfers a block of pixels, with clipping and masking.
 *
 * Between device surfaces, GDI bitmaps or one of each. GDI has already
 * clipped prclTrg to the clip region's bounds. Read only the parameters
 * rop4 needs: for BLACKNESS, for example, pbo isn't valid.
 *
 * @param psoTrg Surface to draw on.
 * @param psoSrc Source surface, if rop4 uses one.
 * @param psoMask 1 bpp mask, if rop4 uses one; NULL to use the brush's.
 * @param pco Clip region.
 * @param pxlo Translates source colors, or NULL for none.
 * @param prclTrg Destination rectangle, bottom-right exclusive, never
 *        empty. On several monitors it can extend past the surface.
 * @param pptlSrc Source's top left.
 * @param pptlMask Mask's top left.
 * @param pbo Brush, if rop4 uses one.
 * @param pptlBrush Brush origin.
 * @param rop4 Low byte: the ROP3 where the mask is 1. High byte: the ROP3
 *        where it's 0. 0xAACC masks with psoMask.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvBitBlt(SURFOBJ *psoTrg, SURFOBJ *psoSrc, SURFOBJ *psoMask, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclTrg, POINTL *pptlSrc,
                        POINTL *pptlMask, BRUSHOBJ *pbo, POINTL *pptlBrush, ROP4 rop4);
/**
 * Copies between device surfaces and GDI's standard format bitmaps.
 *
 * Required if the driver has its own surfaces or bitmaps. Standard format
 * bitmaps are single plane and packed, with each line aligned to 4 bytes.
 *
 * @param psoDest Destination surface.
 * @param psoSrc Source surface.
 * @param pco Clip region on the destination.
 * @param pxlo Translates source colors, or NULL for none.
 * @param prclDest Destination rectangle, bottom-right exclusive.
 * @param pptlSrc Source's top left.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvCopyBits(SURFOBJ *psoDest, SURFOBJ *psoSrc, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclDest, POINTL *pptlSrc);
/**
 * Transfers a block of pixels with stretching or transparency.
 *
 * GDI calls it for StretchBlt and StretchDIBits. The Windows CE 5.0
 * reference's own page gives the eighth parameter as a POINTL source
 * point; its DRVENABLEDATA gives a RECTL source rectangle, which a stretch
 * needs.
 *
 * @param psoDest Surface to draw on.
 * @param psoSrc Source surface, if rop4 uses one.
 * @param psoMask 1 bpp mask, if rop4 uses one.
 * @param pco Clip region.
 * @param pxlo Translates source colors, or NULL for none.
 * @param pptlHTOrg Unused.
 * @param prclDest Destination rectangle, bottom-right exclusive.
 * @param prclSrc Source rectangle.
 * @param pptlMask Mask's top left.
 * @param pbo Brush, if rop4 uses one.
 * @param pptlBrush Brush origin.
 * @param rop4 As for DrvBitBlt.
 * @param iMode Documented as unused, but 1 in ordinary blits on a PW-SH2.
 * @param bltFlags BLT_STRETCH for a stretch, otherwise 0. BLT_STRETCH's
 *        value, 8, is measured on a PW-SH2 (CE 6.0).
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvAnyBlt(SURFOBJ *psoDest, SURFOBJ *psoSrc, SURFOBJ *psoMask, CLIPOBJ *pco, XLATEOBJ *pxlo, POINTL *pptlHTOrg, RECTL *prclDest,
                        RECTL *prclSrc, POINTL *pptlMask, BRUSHOBJ *pbo, POINTL *pptlBrush, ROP4 rop4, ULONG iMode, ULONG bltFlags);
/**
 * Transfers a block of pixels, leaving one source color out.
 *
 * @param psoDest Surface to draw on.
 * @param psoSrc Source surface.
 * @param pco Clip region.
 * @param pxlo Translates source colors, or NULL for none.
 * @param prclDest Destination rectangle, bottom-right exclusive, never
 *        empty.
 * @param prclSrc Source rectangle.
 * @param TransColor Source color, in the source's format, not to copy.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvTransparentBlt(SURFOBJ *psoDest, SURFOBJ *psoSrc, CLIPOBJ *pco, XLATEOBJ *pxlo, RECTL *prclDest, RECTL *prclSrc,
                                ULONG TransColor);
/**
 * Sets the hardware palette.
 *
 * Read the colors with the PALOBJ_cGetColors callback.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @param ppalo Palette to read the colors from.
 * @param fl Flags; SP_DEFAULT says it's the device's whole default
 *        palette. The public references don't give its value.
 * @param iStart First entry to set.
 * @param cColors Number of entries to set; ignore any beyond the
 *        hardware's.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvSetPalette(DHPDEV dhpdev, PALOBJ *ppalo, FLONG fl, ULONG iStart, ULONG cColors);
/**
 * Sets a new pointer shape and shows it at a position.
 *
 * Remove the old pointer first if the driver drew it. iUniq and dhsurf in
 * the mask and color surfaces can key a pointer cache.
 *
 * @param pso Display surface.
 * @param psoMask 1 bpp AND mask over XOR mask, so twice the pointer's
 *        height: 32 x 64 on a PW-A7300. NULL hides the pointer, which is
 *        how CE 6.0 hides it there, rather than a negative x to
 *        DrvMovePointer.
 * @param psoColor Color image, half the mask's height; NULL for a
 *        monochrome pointer.
 * @param pxlo Translates psoColor's colors.
 * @param xHot Hot spot's x within the pointer.
 * @param yHot Hot spot's y within the pointer.
 * @param x Where to put the hot spot.
 * @param y Where to put the hot spot.
 * @param prcl Receives a rectangle bounding the visible pointer.
 * @param fl Unused.
 * @return SPS_ACCEPT_NOEXCLUDE if the hardware shows it, or SPS_ERROR.
 */
ULONG APIENTRY DrvSetPointerShape(SURFOBJ *pso, SURFOBJ *psoMask, SURFOBJ *psoColor, XLATEOBJ *pxlo, LONG xHot, LONG yHot, LONG x, LONG y,
                                  RECTL *prcl, FLONG fl);
/**
 * Moves the pointer.
 *
 * @param pso Display surface.
 * @param x Where to put the hot spot. Negative: remove the pointer, as GDI
 *        is about to draw under it; a later nonnegative x restores it.
 * @param y Where to put the hot spot. With GCAPS_PANNING, a negative y
 *        only reports the position, at y + pso->sizlBitmap.cy.
 * @param prcl Receives a rectangle bounding the visible pointer.
 */
VOID APIENTRY DrvMovePointer(SURFOBJ *pso, LONG x, LONG y, RECTL *prcl);
/**
 * Lists the display modes the device supports.
 *
 * Call with pdm NULL to get the size needed.
 *
 * @param hDriver The driver handle DrvEnablePDEV received.
 * @param cjSize Size of the buffer at pdm.
 * @param pdm Receives a DEVMODEW per mode.
 * @return Bytes needed for all modes, or 0 if pdm is too small.
 */
ULONG APIENTRY DrvGetModes(HANDLE hDriver, ULONG cjSize, DEVMODEW *pdm);
/**
 * Finds the device color nearest an RGB color.
 *
 * @param iDstType Device palette format: PAL_INDEXED, PAL_BITFIELDS,
 *        PAL_RGB or PAL_BGR.
 * @param cEntries Number of entries in pPalette.
 * @param pPalette The device palette, or for PAL_BITFIELDS the masks.
 * @param rgbColor Color in PAL_RGB format.
 * @return The device color.
 */
ULONG APIENTRY DrvRealizeColor(USHORT iDstType, ULONG cEntries, ULONG *pPalette, ULONG rgbColor);
/**
 * Returns the current mode's red, green and blue masks.
 *
 * The ClearType and antialiased font code uses them.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @return Three ULONG masks, red, green, blue, such as 0xF800, 0x07E0
 *         and 0x001F for RGB565.
 */
ULONG *APIENTRY DrvGetMasks(DHPDEV dhpdev);
/**
 * Converts a device color back to RGB.
 *
 * @param iSrcType Device palette format: PAL_INDEXED, PAL_BITFIELDS,
 *        PAL_RGB or PAL_BGR.
 * @param cEntries Number of entries in pPalette.
 * @param pPalette The device palette, or for PAL_BITFIELDS the masks.
 * @param iRealizedColor Device color, as DrvRealizeColor returns.
 * @return The color in PAL_RGB format.
 */
ULONG APIENTRY DrvUnrealizeColor(USHORT iSrcType, ULONG cEntries, ULONG *pPalette, ULONG iRealizedColor);
/**
 * Adjusts the display's contrast.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @param cmd Contrast command.
 * @param pValue The command's value, and receives the result.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvContrastControl(DHPDEV dhpdev, ULONG cmd, ULONG *pValue);
/**
 * Tells the driver the device is suspending or resuming.
 *
 * The Windows CE 5.0 reference says it isn't used from Windows CE .NET
 * 4.2, and that TRUE powers up. On a PW-SH2, CE 6.0 calls it with TRUE on
 * suspend and FALSE on resume.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @param bOff TRUE when suspending, FALSE when resuming.
 */
VOID APIENTRY DrvPowerHandler(DHPDEV dhpdev, BOOL bOff);
/**
 * Printers: sends what ends a document.
 *
 * @param pso Printer surface.
 * @param fl ED_ABORTDOC if the job was cancelled.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvEndDoc(SURFOBJ *pso, FLONG fl);
/**
 * Printers: sends what starts a document.
 *
 * @param pso Printer surface.
 * @param pwszDocName The document's name.
 * @param dwJobId The spooler's job identifier.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvStartDoc(SURFOBJ *pso, PWSTR pwszDocName, DWORD dwJobId);
/**
 * Printers: sends what starts a page.
 *
 * @param pso Printer surface.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvStartPage(SURFOBJ *pso);
/**
 * Handles an ExtEscape call from an application.
 *
 * For QUERYESCSUPPORT, pvIn points to an escape code: return nonzero if
 * the driver supports it. Return 0 for unsupported escapes. Driver-defined
 * escapes start at 100000; Microsoft reserves those below. On a PW-SH2,
 * CE 6.0 also sends 6151 often, and 6150, 6303 and 6304 around rotation,
 * which no public reference names.
 *
 * @param dhpdev Handle from DrvEnablePDEV.
 * @param pso Surface the call is for.
 * @param iEsc Escape code.
 * @param cjIn Size of the buffer at pvIn.
 * @param pvIn Input data.
 * @param cjOut Size of the buffer at pvOut.
 * @param pvOut Receives output data.
 * @return Depends on the escape; 0 if unsupported.
 */
ULONG APIENTRY DrvEscape(DHPDEV dhpdev, SURFOBJ *pso, ULONG iEsc, ULONG cjIn, PVOID pvIn, ULONG cjOut, PVOID pvOut);
/**
 * Fills rectangles with colors interpolated between their corners.
 *
 * @param pso Surface to draw on.
 * @param pco Clip region.
 * @param pxlo Translates colors.
 * @param pVertex Vertices.
 * @param nVertex Number of vertices.
 * @param pMesh GRADIENT_RECT array.
 * @param nMesh Number of rectangles.
 * @param prclExtents Area to draw, bottom-right exclusive.
 * @param pptlDitherOrg Dither origin.
 * @param ulMode GRADIENT_FILL_RECT_H or GRADIENT_FILL_RECT_V.
 * @return TRUE on success, FALSE on failure.
 */
BOOL APIENTRY DrvGradientFill(SURFOBJ *pso, CLIPOBJ *pco, XLATEOBJ *pxlo, TRIVERTEX *pVertex, ULONG nVertex, PVOID pMesh, ULONG nMesh,
                              RECTL *prclExtents, POINTL *pptlDitherOrg, ULONG ulMode);

#ifdef __cplusplus
}
#endif

#endif

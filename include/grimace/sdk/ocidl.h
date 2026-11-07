#ifndef GRIMACE_SDK_OCIDL_H
#define GRIMACE_SDK_OCIDL_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/objbase.h>
#include <grimace/sdk/oleidl.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/urlmon.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

enum tagACTIVATEFLAGS {
    ACTIVATE_WINDOWLESS = 1
};

typedef enum tagACTIVATEFLAGS ACTIVATEFLAGS;
struct tagCADWORD;
typedef struct tagCADWORD CADWORD;
struct tagCALPOLESTR;
typedef struct tagCALPOLESTR CALPOLESTR;
struct tagCAUUID;
typedef struct tagCAUUID CAUUID;
struct tagCONNECTDATA;
typedef struct tagCONNECTDATA CONNECTDATA;
struct tagCONTROLINFO;
typedef struct tagCONTROLINFO CONTROLINFO;
enum tagCTRLINFO {
    CTRLINFO_EATS_RETURN = 1,
    CTRLINFO_EATS_ESCAPE = 2
};

typedef enum tagCTRLINFO CTRLINFO;
enum tagDVASPECT2 {
    DVASPECT_OPAQUE = 16,
    DVASPECT_TRANSPARENT = 32
};

typedef enum tagDVASPECT2 DVASPECT2;
struct tagAspectInfo;
typedef struct tagAspectInfo DVASPECTINFO;
enum tagAspectInfoFlag {
    DVASPECTINFOFLAG_CANOPTIMIZE = 1
};

typedef enum tagAspectInfoFlag DVASPECTINFOFLAG;
struct tagExtentInfo;
typedef struct tagExtentInfo DVEXTENTINFO;
enum tagExtentMode {
    DVEXTENT_CONTENT = 0,
    DVEXTENT_INTEGRAL = 1
};

typedef enum tagExtentMode DVEXTENTMODE;
enum tagGUIDKIND {
    GUIDKIND_DEFAULT_SOURCE_DISP_IID = 1
};

typedef enum tagGUIDKIND GUIDKIND;
enum tagHITRESULT {
    HITRESULT_OUTSIDE = 0,
    HITRESULT_TRANSPARENT = 1,
    HITRESULT_CLOSE = 2,
    HITRESULT_HIT = 3
};

typedef enum tagHITRESULT HITRESULT;
struct IAdviseSinkEx;
typedef struct IAdviseSinkEx IAdviseSinkEx;
struct IAdviseSinkExVtbl;
typedef struct IAdviseSinkExVtbl IAdviseSinkExVtbl;
struct IClassFactory2;
typedef struct IClassFactory2 IClassFactory2;
struct IClassFactory2Vtbl;
typedef struct IClassFactory2Vtbl IClassFactory2Vtbl;
struct IConnectionPoint;
typedef struct IConnectionPoint IConnectionPoint;
struct IConnectionPointContainer;
typedef struct IConnectionPointContainer IConnectionPointContainer;
struct IConnectionPointContainerVtbl;
typedef struct IConnectionPointContainerVtbl IConnectionPointContainerVtbl;
struct IConnectionPointVtbl;
typedef struct IConnectionPointVtbl IConnectionPointVtbl;
struct IEnumConnectionPoints;
typedef struct IEnumConnectionPoints IEnumConnectionPoints;
struct IEnumConnectionPointsVtbl;
typedef struct IEnumConnectionPointsVtbl IEnumConnectionPointsVtbl;
struct IEnumConnections;
typedef struct IEnumConnections IEnumConnections;
struct IEnumConnectionsVtbl;
typedef struct IEnumConnectionsVtbl IEnumConnectionsVtbl;
struct IEnumOleUndoUnits;
typedef struct IEnumOleUndoUnits IEnumOleUndoUnits;
struct IEnumOleUndoUnitsVtbl;
typedef struct IEnumOleUndoUnitsVtbl IEnumOleUndoUnitsVtbl;
struct IErrorLog;
typedef struct IErrorLog IErrorLog;
struct IErrorLogVtbl;
typedef struct IErrorLogVtbl IErrorLogVtbl;
struct IFont;
typedef struct IFont IFont;
struct IFontDisp;
typedef struct IFontDisp IFontDisp;
struct IFontDispVtbl;
typedef struct IFontDispVtbl IFontDispVtbl;
struct IFontVtbl;
typedef struct IFontVtbl IFontVtbl;
struct IObjectWithSite;
typedef struct IObjectWithSite IObjectWithSite;
struct IObjectWithSiteVtbl;
typedef struct IObjectWithSiteVtbl IObjectWithSiteVtbl;
struct IOleControl;
typedef struct IOleControl IOleControl;
struct IOleControlNavigation;
typedef struct IOleControlNavigation IOleControlNavigation;
struct IOleControlNavigationVtbl;
typedef struct IOleControlNavigationVtbl IOleControlNavigationVtbl;
struct IOleControlSite;
typedef struct IOleControlSite IOleControlSite;
struct IOleControlSiteVtbl;
typedef struct IOleControlSiteVtbl IOleControlSiteVtbl;
struct IOleControlVtbl;
typedef struct IOleControlVtbl IOleControlVtbl;
struct IOleInPlaceObjectWindowless;
typedef struct IOleInPlaceObjectWindowless IOleInPlaceObjectWindowless;
struct IOleInPlaceObjectWindowlessVtbl;
typedef struct IOleInPlaceObjectWindowlessVtbl IOleInPlaceObjectWindowlessVtbl;
struct IOleInPlaceSiteEx;
typedef struct IOleInPlaceSiteEx IOleInPlaceSiteEx;
struct IOleInPlaceSiteExVtbl;
typedef struct IOleInPlaceSiteExVtbl IOleInPlaceSiteExVtbl;
struct IOleInPlaceSiteWindowless;
typedef struct IOleInPlaceSiteWindowless IOleInPlaceSiteWindowless;
struct IOleInPlaceSiteWindowlessVtbl;
typedef struct IOleInPlaceSiteWindowlessVtbl IOleInPlaceSiteWindowlessVtbl;
struct IOleParentUndoUnit;
typedef struct IOleParentUndoUnit IOleParentUndoUnit;
struct IOleParentUndoUnitVtbl;
typedef struct IOleParentUndoUnitVtbl IOleParentUndoUnitVtbl;
struct IOleUndoManager;
typedef struct IOleUndoManager IOleUndoManager;
struct IOleUndoManagerVtbl;
typedef struct IOleUndoManagerVtbl IOleUndoManagerVtbl;
struct IOleUndoUnit;
typedef struct IOleUndoUnit IOleUndoUnit;
struct IOleUndoUnitVtbl;
typedef struct IOleUndoUnitVtbl IOleUndoUnitVtbl;
struct IPerPropertyBrowsing;
typedef struct IPerPropertyBrowsing IPerPropertyBrowsing;
struct IPerPropertyBrowsingVtbl;
typedef struct IPerPropertyBrowsingVtbl IPerPropertyBrowsingVtbl;
struct IPersistMemory;
typedef struct IPersistMemory IPersistMemory;
struct IPersistMemoryVtbl;
typedef struct IPersistMemoryVtbl IPersistMemoryVtbl;
struct IPersistPropertyBag;
typedef struct IPersistPropertyBag IPersistPropertyBag;
struct IPersistPropertyBagVtbl;
typedef struct IPersistPropertyBagVtbl IPersistPropertyBagVtbl;
struct IPersistStreamInit;
typedef struct IPersistStreamInit IPersistStreamInit;
struct IPersistStreamInitVtbl;
typedef struct IPersistStreamInitVtbl IPersistStreamInitVtbl;
struct IPicture;
typedef struct IPicture IPicture;
struct IPictureDisp;
typedef struct IPictureDisp IPictureDisp;
struct IPictureDispVtbl;
typedef struct IPictureDispVtbl IPictureDispVtbl;
struct IPictureVtbl;
typedef struct IPictureVtbl IPictureVtbl;
struct IPointerInactive;
typedef struct IPointerInactive IPointerInactive;
struct IPointerInactiveVtbl;
typedef struct IPointerInactiveVtbl IPointerInactiveVtbl;
struct IPropertyBag;
typedef struct IPropertyBag IPropertyBag;
struct IPropertyBagVtbl;
typedef struct IPropertyBagVtbl IPropertyBagVtbl;
struct IPropertyNotifySink;
typedef struct IPropertyNotifySink IPropertyNotifySink;
struct IPropertyNotifySinkVtbl;
typedef struct IPropertyNotifySinkVtbl IPropertyNotifySinkVtbl;
struct IPropertyPage;
typedef struct IPropertyPage IPropertyPage;
struct IPropertyPage2;
typedef struct IPropertyPage2 IPropertyPage2;
struct IPropertyPage2Vtbl;
typedef struct IPropertyPage2Vtbl IPropertyPage2Vtbl;
struct IPropertyPageSite;
typedef struct IPropertyPageSite IPropertyPageSite;
struct IPropertyPageSiteVtbl;
typedef struct IPropertyPageSiteVtbl IPropertyPageSiteVtbl;
struct IPropertyPageVtbl;
typedef struct IPropertyPageVtbl IPropertyPageVtbl;
struct IProvideClassInfo;
typedef struct IProvideClassInfo IProvideClassInfo;
struct IProvideClassInfo2;
typedef struct IProvideClassInfo2 IProvideClassInfo2;
struct IProvideClassInfo2Vtbl;
typedef struct IProvideClassInfo2Vtbl IProvideClassInfo2Vtbl;
struct IProvideClassInfoVtbl;
typedef struct IProvideClassInfoVtbl IProvideClassInfoVtbl;
struct IQuickActivate;
typedef struct IQuickActivate IQuickActivate;
struct IQuickActivateVtbl;
typedef struct IQuickActivateVtbl IQuickActivateVtbl;
struct ISimpleFrameSite;
typedef struct ISimpleFrameSite ISimpleFrameSite;
struct ISimpleFrameSiteVtbl;
typedef struct ISimpleFrameSiteVtbl ISimpleFrameSiteVtbl;
struct ISpecifyPropertyPages;
typedef struct ISpecifyPropertyPages ISpecifyPropertyPages;
struct ISpecifyPropertyPagesVtbl;
typedef struct ISpecifyPropertyPagesVtbl ISpecifyPropertyPagesVtbl;
struct IViewObjectEx;
typedef struct IViewObjectEx IViewObjectEx;
struct IViewObjectExVtbl;
typedef struct IViewObjectExVtbl IViewObjectExVtbl;
struct tagLICINFO;
typedef struct tagLICINFO LICINFO;
typedef IAdviseSinkEx *LPADVISESINKEX;
typedef struct tagCADWORD *LPCADWORD;
typedef struct tagCALPOLESTR *LPCALPOLESTR;
typedef struct tagCAUUID *LPCAUUID;
typedef IClassFactory2 *LPCLASSFACTORY2;
typedef struct tagCONNECTDATA *LPCONNECTDATA;
typedef IConnectionPoint *LPCONNECTIONPOINT;
typedef IConnectionPointContainer *LPCONNECTIONPOINTCONTAINER;
typedef struct tagCONTROLINFO *LPCONTROLINFO;
typedef IEnumConnectionPoints *LPENUMCONNECTIONPOINTS;
typedef IEnumConnections *LPENUMCONNECTIONS;
typedef IEnumOleUndoUnits *LPENUMOLEUNDOUNITS;
typedef IErrorLog *LPERRORLOG;
typedef IFont *LPFONT;
typedef IFontDisp *LPFONTDISP;
typedef struct tagLICINFO *LPLICINFO;
typedef IObjectWithSite *LPOBJECTWITHSITE;
typedef IOleControl *LPOLECONTROL;
typedef IOleControlNavigation *LPOLECONTROLNAVIGATION;
typedef IOleControlSite *LPOLECONTROLSITE;
typedef IOleInPlaceObjectWindowless *LPOLEINPLACEOBJECTWINDOWLESS;
typedef IOleInPlaceSiteEx *LPOLEINPLACESITEEX;
typedef IOleInPlaceSiteWindowless *LPOLEINPLACESITEWINDOWLESS;
typedef IOleParentUndoUnit *LPOLEPARENTUNDOUNIT;
typedef IOleUndoManager *LPOLEUNDOMANAGER;
typedef IOleUndoUnit *LPOLEUNDOUNIT;
typedef IPerPropertyBrowsing *LPPERPROPERTYBROWSING;
typedef IPersistMemory *LPPERSISTMEMORY;
typedef IPersistPropertyBag *LPPERSISTPROPERTYBAG;
typedef IPersistStreamInit *LPPERSISTSTREAMINIT;
typedef IPicture *LPPICTURE;
typedef IPictureDisp *LPPICTUREDISP;
typedef IPointerInactive *LPPOINTERINACTIVE;
struct tagPOINTF;
typedef struct tagPOINTF *LPPOINTF;
typedef IPropertyBag *LPPROPERTYBAG;
typedef IPropertyNotifySink *LPPROPERTYNOTIFYSINK;
typedef IPropertyPage *LPPROPERTYPAGE;
typedef IPropertyPage2 *LPPROPERTYPAGE2;
typedef IPropertyPageSite *LPPROPERTYPAGESITE;
struct tagPROPPAGEINFO;
typedef struct tagPROPPAGEINFO *LPPROPPAGEINFO;
typedef IProvideClassInfo *LPPROVIDECLASSINFO;
typedef IProvideClassInfo2 *LPPROVIDECLASSINFO2;
typedef IQuickActivate *LPQUICKACTIVATE;
typedef ISimpleFrameSite *LPSIMPLEFRAMESITE;
typedef ISpecifyPropertyPages *LPSPECIFYPROPERTYPAGES;
typedef TEXTMETRICW TEXTMETRICOLE;
typedef TEXTMETRICOLE *LPTEXTMETRICOLE;
typedef IViewObjectEx *LPVIEWOBJECTEX;
enum tagOLEDCFLAGS {
    OLEDC_NODRAW = 1,
    OLEDC_PAINTBKGND = 2,
    OLEDC_OFFSCREEN = 4
};

typedef enum tagOLEDCFLAGS OLEDCFLAGS;
typedef DWORD OLE_COLOR;
typedef UINT OLE_HANDLE;
typedef LONG OLE_XPOS_HIMETRIC;
typedef LONG OLE_XSIZE_HIMETRIC;
typedef LONG OLE_YPOS_HIMETRIC;
typedef LONG OLE_YSIZE_HIMETRIC;
typedef struct tagCONNECTDATA *PCONNECTDATA;
typedef IConnectionPoint *PCONNECTIONPOINT;
typedef IConnectionPointContainer *PCONNECTIONPOINTCONTAINER;
typedef IEnumConnectionPoints *PENUMCONNECTIONPOINTS;
typedef IEnumConnections *PENUMCONNECTIONS;
enum tagPictureAttributes {
    PICTURE_SCALABLE = 1,
    PICTURE_TRANSPARENT = 2
};

typedef enum tagPictureAttributes PICTUREATTRIBUTES;
enum tagPOINTERINACTIVE {
    POINTERINACTIVE_ACTIVATEONENTRY = 1,
    POINTERINACTIVE_DEACTIVATEONLEAVE = 2,
    POINTERINACTIVE_ACTIVATEONDRAG = 4
};

typedef enum tagPOINTERINACTIVE POINTERINACTIVE;
typedef struct tagPOINTF POINTF;
typedef struct tagPROPPAGEINFO PROPPAGEINFO;
enum tagPROPPAGESTATUS {
    PROPPAGESTATUS_DIRTY = 1,
    PROPPAGESTATUS_VALIDATE = 2,
    PROPPAGESTATUS_CLEAN = 4
};

typedef enum tagPROPPAGESTATUS PROPPAGESTATUS;
struct tagQACONTAINER;
typedef struct tagQACONTAINER QACONTAINER;
enum tagQACONTAINERFLAGS {
    QACONTAINER_SHOWHATCHING = 1,
    QACONTAINER_SHOWGRABHANDLES = 2,
    QACONTAINER_USERMODE = 4,
    QACONTAINER_DISPLAYASDEFAULT = 8,
    QACONTAINER_UIDEAD = 16,
    QACONTAINER_AUTOCLIP = 32,
    QACONTAINER_MESSAGEREFLECT = 64,
    QACONTAINER_SUPPORTSMNEMONICS = 128
};

typedef enum tagQACONTAINERFLAGS QACONTAINERFLAGS;
struct tagQACONTROL;
typedef struct tagQACONTROL QACONTROL;
enum tagREADYSTATE {
    READYSTATE_UNINITIALIZED = 0,
    READYSTATE_LOADING = 1,
    READYSTATE_LOADED = 2,
    READYSTATE_INTERACTIVE = 3,
    READYSTATE_COMPLETE = 4
};

typedef enum tagREADYSTATE READYSTATE;
enum tagUASFLAGS {
    UAS_NORMAL = 0,
    UAS_BLOCKED = 1,
    UAS_NOPARENTENABLE = 2,
    UAS_MASK = 3
};

typedef enum tagUASFLAGS UASFLAGS;
enum tagVIEWSTATUS {
    VIEWSTATUS_OPAQUE = 1,
    VIEWSTATUS_SOLIDBKGND = 2,
    VIEWSTATUS_DVASPECTOPAQUE = 4,
    VIEWSTATUS_DVASPECTTRANSPARENT = 8
};

typedef enum tagVIEWSTATUS VIEWSTATUS;
enum tagXFORMCOORDS {
    XFORMCOORDS_POSITION = 1,
    XFORMCOORDS_SIZE = 2,
    XFORMCOORDS_HIMETRICTOCONTAINER = 4,
    XFORMCOORDS_CONTAINERTOHIMETRIC = 8
};

typedef enum tagXFORMCOORDS XFORMCOORDS;
struct IAdviseSinkEx {
    struct IAdviseSinkExVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IAdviseSinkExVtbl {
    HRESULT (*QueryInterface)(IAdviseSinkEx *, const IID *const, void **);
    ULONG (*AddRef)(IAdviseSinkEx *);
    ULONG (*Release)(IAdviseSinkEx *);
    void (*OnDataChange)(IAdviseSinkEx *, FORMATETC *, STGMEDIUM *);
    void (*OnViewChange)(IAdviseSinkEx *, DWORD, LONG);
    void (*OnRename)(IAdviseSinkEx *, IMoniker *);
    void (*OnSave)(IAdviseSinkEx *);
    void (*OnClose)(IAdviseSinkEx *);
    void (*OnViewStatusChange)(IAdviseSinkEx *, DWORD);
} __attribute__((packed, aligned(4)));

struct IClassFactory2 {
    struct IClassFactory2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IClassFactory2Vtbl {
    HRESULT (*QueryInterface)(IClassFactory2 *, const IID *const, void **);
    ULONG (*AddRef)(IClassFactory2 *);
    ULONG (*Release)(IClassFactory2 *);
    HRESULT (*CreateInstance)(IClassFactory2 *, IUnknown *, const IID *const, void **);
    HRESULT (*LockServer)(IClassFactory2 *, BOOL);
    HRESULT (*GetLicInfo)(IClassFactory2 *, LICINFO *);
    HRESULT (*RequestLicKey)(IClassFactory2 *, DWORD, BSTR *);
    HRESULT (*CreateInstanceLic)(IClassFactory2 *, IUnknown *, IUnknown *, const IID *const, BSTR, PVOID *);
} __attribute__((packed, aligned(4)));

struct IConnectionPoint {
    struct IConnectionPointVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IConnectionPointContainer {
    struct IConnectionPointContainerVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IConnectionPointContainerVtbl {
    HRESULT (*QueryInterface)(IConnectionPointContainer *, const IID *const, void **);
    ULONG (*AddRef)(IConnectionPointContainer *);
    ULONG (*Release)(IConnectionPointContainer *);
    HRESULT (*EnumConnectionPoints)(IConnectionPointContainer *, IEnumConnectionPoints **);
    HRESULT (*FindConnectionPoint)(IConnectionPointContainer *, const IID *const, IConnectionPoint **);
} __attribute__((packed, aligned(4)));

struct IConnectionPointVtbl {
    HRESULT (*QueryInterface)(IConnectionPoint *, const IID *const, void **);
    ULONG (*AddRef)(IConnectionPoint *);
    ULONG (*Release)(IConnectionPoint *);
    HRESULT (*GetConnectionInterface)(IConnectionPoint *, IID *);
    HRESULT (*GetConnectionPointContainer)(IConnectionPoint *, IConnectionPointContainer **);
    HRESULT (*Advise)(IConnectionPoint *, IUnknown *, DWORD *);
    HRESULT (*Unadvise)(IConnectionPoint *, DWORD);
    HRESULT (*EnumConnections)(IConnectionPoint *, IEnumConnections **);
} __attribute__((packed, aligned(4)));

struct IEnumConnectionPoints {
    struct IEnumConnectionPointsVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumConnectionPointsVtbl {
    HRESULT (*QueryInterface)(IEnumConnectionPoints *, const IID *const, void **);
    ULONG (*AddRef)(IEnumConnectionPoints *);
    ULONG (*Release)(IEnumConnectionPoints *);
    HRESULT (*Next)(IEnumConnectionPoints *, ULONG, LPCONNECTIONPOINT *, ULONG *);
    HRESULT (*Skip)(IEnumConnectionPoints *, ULONG);
    HRESULT (*Reset)(IEnumConnectionPoints *);
    HRESULT (*Clone)(IEnumConnectionPoints *, IEnumConnectionPoints **);
} __attribute__((packed, aligned(4)));

struct IEnumConnections {
    struct IEnumConnectionsVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumConnectionsVtbl {
    HRESULT (*QueryInterface)(IEnumConnections *, const IID *const, void **);
    ULONG (*AddRef)(IEnumConnections *);
    ULONG (*Release)(IEnumConnections *);
    HRESULT (*Next)(IEnumConnections *, ULONG, LPCONNECTDATA, ULONG *);
    HRESULT (*Skip)(IEnumConnections *, ULONG);
    HRESULT (*Reset)(IEnumConnections *);
    HRESULT (*Clone)(IEnumConnections *, IEnumConnections **);
} __attribute__((packed, aligned(4)));

struct IEnumOleUndoUnits {
    struct IEnumOleUndoUnitsVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumOleUndoUnitsVtbl {
    HRESULT (*QueryInterface)(IEnumOleUndoUnits *, const IID *const, void **);
    ULONG (*AddRef)(IEnumOleUndoUnits *);
    ULONG (*Release)(IEnumOleUndoUnits *);
    HRESULT (*Next)(IEnumOleUndoUnits *, ULONG, IOleUndoUnit **, ULONG *);
    HRESULT (*Skip)(IEnumOleUndoUnits *, ULONG);
    HRESULT (*Reset)(IEnumOleUndoUnits *);
    HRESULT (*Clone)(IEnumOleUndoUnits *, IEnumOleUndoUnits **);
} __attribute__((packed, aligned(4)));

struct IErrorLog {
    struct IErrorLogVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IErrorLogVtbl {
    HRESULT (*QueryInterface)(IErrorLog *, const IID *const, void **);
    ULONG (*AddRef)(IErrorLog *);
    ULONG (*Release)(IErrorLog *);
    HRESULT (*AddError)(IErrorLog *, LPCOLESTR, EXCEPINFO *);
} __attribute__((packed, aligned(4)));

struct IFont {
    struct IFontVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IFontDisp {
    struct IFontDispVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IFontDispVtbl {
    HRESULT (*QueryInterface)(IFontDisp *, const IID *const, void **);
    ULONG (*AddRef)(IFontDisp *);
    ULONG (*Release)(IFontDisp *);
    HRESULT (*GetTypeInfoCount)(IFontDisp *, UINT *);
    HRESULT (*GetTypeInfo)(IFontDisp *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IFontDisp *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IFontDisp *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
} __attribute__((packed, aligned(4)));

struct IFontVtbl {
    HRESULT (*QueryInterface)(IFont *, const IID *const, void **);
    ULONG (*AddRef)(IFont *);
    ULONG (*Release)(IFont *);
    HRESULT (*get_Name)(IFont *, BSTR *);
    HRESULT (*put_Name)(IFont *, BSTR);
    HRESULT (*get_Size)(IFont *, CY *);
    HRESULT (*put_Size)(IFont *, CY);
    HRESULT (*get_Bold)(IFont *, BOOL *);
    HRESULT (*put_Bold)(IFont *, BOOL);
    HRESULT (*get_Italic)(IFont *, BOOL *);
    HRESULT (*put_Italic)(IFont *, BOOL);
    HRESULT (*get_Underline)(IFont *, BOOL *);
    HRESULT (*put_Underline)(IFont *, BOOL);
    HRESULT (*get_Strikethrough)(IFont *, BOOL *);
    HRESULT (*put_Strikethrough)(IFont *, BOOL);
    HRESULT (*get_Weight)(IFont *, SHORT *);
    HRESULT (*put_Weight)(IFont *, SHORT);
    HRESULT (*get_Charset)(IFont *, SHORT *);
    HRESULT (*put_Charset)(IFont *, SHORT);
    HRESULT (*get_hFont)(IFont *, HFONT *);
    HRESULT (*Clone)(IFont *, IFont **);
    HRESULT (*IsEqual)(IFont *, IFont *);
    HRESULT (*SetRatio)(IFont *, LONG, LONG);
    HRESULT (*QueryTextMetrics)(IFont *, TEXTMETRICOLE *);
    HRESULT (*AddRefHfont)(IFont *, HFONT);
    HRESULT (*ReleaseHfont)(IFont *, HFONT);
    HRESULT (*SetHdc)(IFont *, HDC);
} __attribute__((packed, aligned(4)));

struct IObjectWithSite {
    struct IObjectWithSiteVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IObjectWithSiteVtbl {
    HRESULT (*QueryInterface)(IObjectWithSite *, const IID *const, void **);
    ULONG (*AddRef)(IObjectWithSite *);
    ULONG (*Release)(IObjectWithSite *);
    HRESULT (*SetSite)(IObjectWithSite *, IUnknown *);
    HRESULT (*GetSite)(IObjectWithSite *, const IID *const, void **);
} __attribute__((packed, aligned(4)));

struct IOleControl {
    struct IOleControlVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleControlNavigation {
    struct IOleControlNavigationVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleControlNavigationVtbl {
    HRESULT (*QueryInterface)(IOleControlNavigation *, const IID *const, void **);
    ULONG (*AddRef)(IOleControlNavigation *);
    ULONG (*Release)(IOleControlNavigation *);
    HRESULT (*GetCurrentRect)(IOleControlNavigation *, RECT *);
    HRESULT (*GetNavigationRectCount)(IOleControlNavigation *, DWORD *);
    HRESULT (*GetNavigationRects)(IOleControlNavigation *, DWORD, RECT *);
    HRESULT (*Scroll)(IOleControlNavigation *, DWORD);
    HRESULT (*ActivateRect)(IOleControlNavigation *, DWORD);
} __attribute__((packed, aligned(4)));

struct IOleControlSite {
    struct IOleControlSiteVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleControlSiteVtbl {
    HRESULT (*QueryInterface)(IOleControlSite *, const IID *const, void **);
    ULONG (*AddRef)(IOleControlSite *);
    ULONG (*Release)(IOleControlSite *);
    HRESULT (*OnControlInfoChanged)(IOleControlSite *);
    HRESULT (*LockInPlaceActive)(IOleControlSite *, BOOL);
    HRESULT (*GetExtendedControl)(IOleControlSite *, IDispatch **);
    HRESULT (*TransformCoords)(IOleControlSite *, POINTL *, POINTF *, DWORD);
    HRESULT (*TranslateAcceleratorW)(IOleControlSite *, MSG *, DWORD);
    HRESULT (*OnFocus)(IOleControlSite *, BOOL);
    HRESULT (*ShowPropertyFrame)(IOleControlSite *);
} __attribute__((packed, aligned(4)));

struct IOleControlVtbl {
    HRESULT (*QueryInterface)(IOleControl *, const IID *const, void **);
    ULONG (*AddRef)(IOleControl *);
    ULONG (*Release)(IOleControl *);
    HRESULT (*GetControlInfo)(IOleControl *, CONTROLINFO *);
    HRESULT (*OnMnemonic)(IOleControl *, MSG *);
    HRESULT (*OnAmbientPropertyChange)(IOleControl *, DISPID);
    HRESULT (*FreezeEvents)(IOleControl *, BOOL);
} __attribute__((packed, aligned(4)));

struct IOleInPlaceObjectWindowless {
    struct IOleInPlaceObjectWindowlessVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleInPlaceObjectWindowlessVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceObjectWindowless *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceObjectWindowless *);
    ULONG (*Release)(IOleInPlaceObjectWindowless *);
    HRESULT (*GetWindow)(IOleInPlaceObjectWindowless *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceObjectWindowless *, BOOL);
    HRESULT (*InPlaceDeactivate)(IOleInPlaceObjectWindowless *);
    HRESULT (*UIDeactivate)(IOleInPlaceObjectWindowless *);
    HRESULT (*SetObjectRects)(IOleInPlaceObjectWindowless *, LPCRECT, LPCRECT);
    HRESULT (*ReactivateAndUndo)(IOleInPlaceObjectWindowless *);
    HRESULT (*OnWindowMessage)(IOleInPlaceObjectWindowless *, UINT, WPARAM, LPARAM, LRESULT *);
    HRESULT (*GetDropTarget)(IOleInPlaceObjectWindowless *, IDropTarget **);
} __attribute__((packed, aligned(4)));

struct IOleInPlaceSiteEx {
    struct IOleInPlaceSiteExVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleInPlaceSiteExVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceSiteEx *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceSiteEx *);
    ULONG (*Release)(IOleInPlaceSiteEx *);
    HRESULT (*GetWindow)(IOleInPlaceSiteEx *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceSiteEx *, BOOL);
    HRESULT (*CanInPlaceActivate)(IOleInPlaceSiteEx *);
    HRESULT (*OnInPlaceActivate)(IOleInPlaceSiteEx *);
    HRESULT (*OnUIActivate)(IOleInPlaceSiteEx *);
    HRESULT (*GetWindowContext)(IOleInPlaceSiteEx *, IOleInPlaceFrame **, IOleInPlaceUIWindow **, LPRECT, LPRECT, LPOLEINPLACEFRAMEINFO);
    HRESULT (*Scroll)(IOleInPlaceSiteEx *, SIZE);
    HRESULT (*OnUIDeactivate)(IOleInPlaceSiteEx *, BOOL);
    HRESULT (*OnInPlaceDeactivate)(IOleInPlaceSiteEx *);
    HRESULT (*DiscardUndoState)(IOleInPlaceSiteEx *);
    HRESULT (*DeactivateAndUndo)(IOleInPlaceSiteEx *);
    HRESULT (*OnPosRectChange)(IOleInPlaceSiteEx *, LPCRECT);
    HRESULT (*OnInPlaceActivateEx)(IOleInPlaceSiteEx *, BOOL *, DWORD);
    HRESULT (*OnInPlaceDeactivateEx)(IOleInPlaceSiteEx *, BOOL);
    HRESULT (*RequestUIActivate)(IOleInPlaceSiteEx *);
} __attribute__((packed, aligned(4)));

struct IOleInPlaceSiteWindowless {
    struct IOleInPlaceSiteWindowlessVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleInPlaceSiteWindowlessVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceSiteWindowless *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceSiteWindowless *);
    ULONG (*Release)(IOleInPlaceSiteWindowless *);
    HRESULT (*GetWindow)(IOleInPlaceSiteWindowless *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceSiteWindowless *, BOOL);
    HRESULT (*CanInPlaceActivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*OnInPlaceActivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*OnUIActivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*GetWindowContext)(IOleInPlaceSiteWindowless *, IOleInPlaceFrame **, IOleInPlaceUIWindow **, LPRECT, LPRECT, LPOLEINPLACEFRAMEINFO);
    HRESULT (*Scroll)(IOleInPlaceSiteWindowless *, SIZE);
    HRESULT (*OnUIDeactivate)(IOleInPlaceSiteWindowless *, BOOL);
    HRESULT (*OnInPlaceDeactivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*DiscardUndoState)(IOleInPlaceSiteWindowless *);
    HRESULT (*DeactivateAndUndo)(IOleInPlaceSiteWindowless *);
    HRESULT (*OnPosRectChange)(IOleInPlaceSiteWindowless *, LPCRECT);
    HRESULT (*OnInPlaceActivateEx)(IOleInPlaceSiteWindowless *, BOOL *, DWORD);
    HRESULT (*OnInPlaceDeactivateEx)(IOleInPlaceSiteWindowless *, BOOL);
    HRESULT (*RequestUIActivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*CanWindowlessActivate)(IOleInPlaceSiteWindowless *);
    HRESULT (*GetCapture)(IOleInPlaceSiteWindowless *);
    HRESULT (*SetCapture)(IOleInPlaceSiteWindowless *, BOOL);
    HRESULT (*GetFocus)(IOleInPlaceSiteWindowless *);
    HRESULT (*SetFocus)(IOleInPlaceSiteWindowless *, BOOL);
    HRESULT (*GetDC)(IOleInPlaceSiteWindowless *, LPCRECT, DWORD, HDC *);
    HRESULT (*ReleaseDC)(IOleInPlaceSiteWindowless *, HDC);
    HRESULT (*InvalidateRect)(IOleInPlaceSiteWindowless *, LPCRECT, BOOL);
    HRESULT (*InvalidateRgn)(IOleInPlaceSiteWindowless *, HRGN, BOOL);
    HRESULT (*ScrollRect)(IOleInPlaceSiteWindowless *, INT, INT, LPCRECT, LPCRECT);
    HRESULT (*AdjustRect)(IOleInPlaceSiteWindowless *, LPRECT);
    HRESULT (*OnDefWindowMessage)(IOleInPlaceSiteWindowless *, UINT, WPARAM, LPARAM, LRESULT *);
} __attribute__((packed, aligned(4)));

struct IOleParentUndoUnit {
    struct IOleParentUndoUnitVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleParentUndoUnitVtbl {
    HRESULT (*QueryInterface)(IOleParentUndoUnit *, const IID *const, void **);
    ULONG (*AddRef)(IOleParentUndoUnit *);
    ULONG (*Release)(IOleParentUndoUnit *);
    HRESULT (*Do)(IOleParentUndoUnit *, IOleUndoManager *);
    HRESULT (*GetDescription)(IOleParentUndoUnit *, BSTR *);
    HRESULT (*GetUnitType)(IOleParentUndoUnit *, CLSID *, LONG *);
    HRESULT (*OnNextAdd)(IOleParentUndoUnit *);
    HRESULT (*Open)(IOleParentUndoUnit *, IOleParentUndoUnit *);
    HRESULT (*Close)(IOleParentUndoUnit *, IOleParentUndoUnit *, BOOL);
    HRESULT (*Add)(IOleParentUndoUnit *, IOleUndoUnit *);
    HRESULT (*FindUnit)(IOleParentUndoUnit *, IOleUndoUnit *);
    HRESULT (*GetParentState)(IOleParentUndoUnit *, DWORD *);
} __attribute__((packed, aligned(4)));

struct IOleUndoManager {
    struct IOleUndoManagerVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleUndoManagerVtbl {
    HRESULT (*QueryInterface)(IOleUndoManager *, const IID *const, void **);
    ULONG (*AddRef)(IOleUndoManager *);
    ULONG (*Release)(IOleUndoManager *);
    HRESULT (*Open)(IOleUndoManager *, IOleParentUndoUnit *);
    HRESULT (*Close)(IOleUndoManager *, IOleParentUndoUnit *, BOOL);
    HRESULT (*Add)(IOleUndoManager *, IOleUndoUnit *);
    HRESULT (*GetOpenParentState)(IOleUndoManager *, DWORD *);
    HRESULT (*DiscardFrom)(IOleUndoManager *, IOleUndoUnit *);
    HRESULT (*UndoTo)(IOleUndoManager *, IOleUndoUnit *);
    HRESULT (*RedoTo)(IOleUndoManager *, IOleUndoUnit *);
    HRESULT (*EnumUndoable)(IOleUndoManager *, IEnumOleUndoUnits **);
    HRESULT (*EnumRedoable)(IOleUndoManager *, IEnumOleUndoUnits **);
    HRESULT (*GetLastUndoDescription)(IOleUndoManager *, BSTR *);
    HRESULT (*GetLastRedoDescription)(IOleUndoManager *, BSTR *);
    HRESULT (*Enable)(IOleUndoManager *, BOOL);
} __attribute__((packed, aligned(4)));

struct IOleUndoUnit {
    struct IOleUndoUnitVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IOleUndoUnitVtbl {
    HRESULT (*QueryInterface)(IOleUndoUnit *, const IID *const, void **);
    ULONG (*AddRef)(IOleUndoUnit *);
    ULONG (*Release)(IOleUndoUnit *);
    HRESULT (*Do)(IOleUndoUnit *, IOleUndoManager *);
    HRESULT (*GetDescription)(IOleUndoUnit *, BSTR *);
    HRESULT (*GetUnitType)(IOleUndoUnit *, CLSID *, LONG *);
    HRESULT (*OnNextAdd)(IOleUndoUnit *);
} __attribute__((packed, aligned(4)));

struct IPerPropertyBrowsing {
    struct IPerPropertyBrowsingVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPerPropertyBrowsingVtbl {
    HRESULT (*QueryInterface)(IPerPropertyBrowsing *, const IID *const, void **);
    ULONG (*AddRef)(IPerPropertyBrowsing *);
    ULONG (*Release)(IPerPropertyBrowsing *);
    HRESULT (*GetDisplayString)(IPerPropertyBrowsing *, DISPID, BSTR *);
    HRESULT (*MapPropertyToPage)(IPerPropertyBrowsing *, DISPID, CLSID *);
    HRESULT (*GetPredefinedStrings)(IPerPropertyBrowsing *, DISPID, CALPOLESTR *, CADWORD *);
    HRESULT (*GetPredefinedValue)(IPerPropertyBrowsing *, DISPID, DWORD, VARIANT *);
} __attribute__((packed, aligned(4)));

struct IPersistMemory {
    struct IPersistMemoryVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistMemoryVtbl {
    HRESULT (*QueryInterface)(IPersistMemory *, const IID *const, void **);
    ULONG (*AddRef)(IPersistMemory *);
    ULONG (*Release)(IPersistMemory *);
    HRESULT (*GetClassID)(IPersistMemory *, CLSID *);
    HRESULT (*IsDirty)(IPersistMemory *);
    HRESULT (*Load)(IPersistMemory *, LPVOID, ULONG);
    HRESULT (*Save)(IPersistMemory *, LPVOID, BOOL, ULONG);
    HRESULT (*GetSizeMax)(IPersistMemory *, ULONG *);
    HRESULT (*InitNew)(IPersistMemory *);
} __attribute__((packed, aligned(4)));

struct IPersistPropertyBag {
    struct IPersistPropertyBagVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistPropertyBagVtbl {
    HRESULT (*QueryInterface)(IPersistPropertyBag *, const IID *const, void **);
    ULONG (*AddRef)(IPersistPropertyBag *);
    ULONG (*Release)(IPersistPropertyBag *);
    HRESULT (*GetClassID)(IPersistPropertyBag *, CLSID *);
    HRESULT (*InitNew)(IPersistPropertyBag *);
    HRESULT (*Load)(IPersistPropertyBag *, IPropertyBag *, IErrorLog *);
    HRESULT (*Save)(IPersistPropertyBag *, IPropertyBag *, BOOL, BOOL);
} __attribute__((packed, aligned(4)));

struct IPersistStreamInit {
    struct IPersistStreamInitVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistStreamInitVtbl {
    HRESULT (*QueryInterface)(IPersistStreamInit *, const IID *const, void **);
    ULONG (*AddRef)(IPersistStreamInit *);
    ULONG (*Release)(IPersistStreamInit *);
    HRESULT (*GetClassID)(IPersistStreamInit *, CLSID *);
    HRESULT (*IsDirty)(IPersistStreamInit *);
    HRESULT (*Load)(IPersistStreamInit *, LPSTREAM);
    HRESULT (*Save)(IPersistStreamInit *, LPSTREAM, BOOL);
    HRESULT (*GetSizeMax)(IPersistStreamInit *, ULARGE_INTEGER *);
    HRESULT (*InitNew)(IPersistStreamInit *);
} __attribute__((packed, aligned(4)));

struct IPicture {
    struct IPictureVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPictureDisp {
    struct IPictureDispVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPictureDispVtbl {
    HRESULT (*QueryInterface)(IPictureDisp *, const IID *const, void **);
    ULONG (*AddRef)(IPictureDisp *);
    ULONG (*Release)(IPictureDisp *);
    HRESULT (*GetTypeInfoCount)(IPictureDisp *, UINT *);
    HRESULT (*GetTypeInfo)(IPictureDisp *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IPictureDisp *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IPictureDisp *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
} __attribute__((packed, aligned(4)));

struct IPictureVtbl {
    HRESULT (*QueryInterface)(IPicture *, const IID *const, void **);
    ULONG (*AddRef)(IPicture *);
    ULONG (*Release)(IPicture *);
    HRESULT (*get_Handle)(IPicture *, OLE_HANDLE *);
    HRESULT (*get_hPal)(IPicture *, OLE_HANDLE *);
    HRESULT (*get_Type)(IPicture *, SHORT *);
    HRESULT (*get_Width)(IPicture *, OLE_XSIZE_HIMETRIC *);
    HRESULT (*get_Height)(IPicture *, OLE_YSIZE_HIMETRIC *);
    HRESULT (*Render)(IPicture *, HDC, LONG, LONG, LONG, LONG, OLE_XPOS_HIMETRIC, OLE_YPOS_HIMETRIC, OLE_XSIZE_HIMETRIC, OLE_YSIZE_HIMETRIC, LPCRECT);
    HRESULT (*set_hPal)(IPicture *, OLE_HANDLE);
    HRESULT (*get_CurDC)(IPicture *, HDC *);
    HRESULT (*SelectPicture)(IPicture *, HDC, HDC *, OLE_HANDLE *);
    HRESULT (*get_KeepOriginalFormat)(IPicture *, BOOL *);
    HRESULT (*put_KeepOriginalFormat)(IPicture *, BOOL);
    HRESULT (*PictureChanged)(IPicture *);
    HRESULT (*SaveAsFile)(IPicture *, LPSTREAM, BOOL, LONG *);
    HRESULT (*get_Attributes)(IPicture *, DWORD *);
} __attribute__((packed, aligned(4)));

struct IPointerInactive {
    struct IPointerInactiveVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPointerInactiveVtbl {
    HRESULT (*QueryInterface)(IPointerInactive *, const IID *const, void **);
    ULONG (*AddRef)(IPointerInactive *);
    ULONG (*Release)(IPointerInactive *);
    HRESULT (*GetActivationPolicy)(IPointerInactive *, DWORD *);
    HRESULT (*OnInactiveMouseMove)(IPointerInactive *, LPCRECT, LONG, LONG, DWORD);
    HRESULT (*OnInactiveSetCursor)(IPointerInactive *, LPCRECT, LONG, LONG, DWORD, BOOL);
} __attribute__((packed, aligned(4)));

struct IPropertyBag {
    struct IPropertyBagVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyBagVtbl {
    HRESULT (*QueryInterface)(IPropertyBag *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyBag *);
    ULONG (*Release)(IPropertyBag *);
    HRESULT (*Read)(IPropertyBag *, LPCOLESTR, VARIANT *, IErrorLog *);
    HRESULT (*Write)(IPropertyBag *, LPCOLESTR, VARIANT *);
} __attribute__((packed, aligned(4)));

struct IPropertyNotifySink {
    struct IPropertyNotifySinkVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyNotifySinkVtbl {
    HRESULT (*QueryInterface)(IPropertyNotifySink *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyNotifySink *);
    ULONG (*Release)(IPropertyNotifySink *);
    HRESULT (*OnChanged)(IPropertyNotifySink *, DISPID);
    HRESULT (*OnRequestEdit)(IPropertyNotifySink *, DISPID);
} __attribute__((packed, aligned(4)));

struct IPropertyPage {
    struct IPropertyPageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyPage2 {
    struct IPropertyPage2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyPage2Vtbl {
    HRESULT (*QueryInterface)(IPropertyPage2 *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyPage2 *);
    ULONG (*Release)(IPropertyPage2 *);
    HRESULT (*SetPageSite)(IPropertyPage2 *, IPropertyPageSite *);
    HRESULT (*Activate)(IPropertyPage2 *, HWND, LPCRECT, BOOL);
    HRESULT (*Deactivate)(IPropertyPage2 *);
    HRESULT (*GetPageInfo)(IPropertyPage2 *, PROPPAGEINFO *);
    HRESULT (*SetObjects)(IPropertyPage2 *, ULONG, IUnknown **);
    HRESULT (*Show)(IPropertyPage2 *, UINT);
    HRESULT (*Move)(IPropertyPage2 *, LPCRECT);
    HRESULT (*IsPageDirty)(IPropertyPage2 *);
    HRESULT (*Apply)(IPropertyPage2 *);
    HRESULT (*Help)(IPropertyPage2 *, LPCOLESTR);
    HRESULT (*TranslateAcceleratorW)(IPropertyPage2 *, MSG *);
    HRESULT (*EditProperty)(IPropertyPage2 *, DISPID);
} __attribute__((packed, aligned(4)));

struct IPropertyPageSite {
    struct IPropertyPageSiteVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyPageSiteVtbl {
    HRESULT (*QueryInterface)(IPropertyPageSite *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyPageSite *);
    ULONG (*Release)(IPropertyPageSite *);
    HRESULT (*OnStatusChange)(IPropertyPageSite *, DWORD);
    HRESULT (*GetLocaleID)(IPropertyPageSite *, LCID *);
    HRESULT (*GetPageContainer)(IPropertyPageSite *, IUnknown **);
    HRESULT (*TranslateAcceleratorW)(IPropertyPageSite *, MSG *);
} __attribute__((packed, aligned(4)));

struct IPropertyPageVtbl {
    HRESULT (*QueryInterface)(IPropertyPage *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyPage *);
    ULONG (*Release)(IPropertyPage *);
    HRESULT (*SetPageSite)(IPropertyPage *, IPropertyPageSite *);
    HRESULT (*Activate)(IPropertyPage *, HWND, LPCRECT, BOOL);
    HRESULT (*Deactivate)(IPropertyPage *);
    HRESULT (*GetPageInfo)(IPropertyPage *, PROPPAGEINFO *);
    HRESULT (*SetObjects)(IPropertyPage *, ULONG, IUnknown **);
    HRESULT (*Show)(IPropertyPage *, UINT);
    HRESULT (*Move)(IPropertyPage *, LPCRECT);
    HRESULT (*IsPageDirty)(IPropertyPage *);
    HRESULT (*Apply)(IPropertyPage *);
    HRESULT (*Help)(IPropertyPage *, LPCOLESTR);
    HRESULT (*TranslateAcceleratorW)(IPropertyPage *, MSG *);
} __attribute__((packed, aligned(4)));

struct IProvideClassInfo {
    struct IProvideClassInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IProvideClassInfo2 {
    struct IProvideClassInfo2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IProvideClassInfo2Vtbl {
    HRESULT (*QueryInterface)(IProvideClassInfo2 *, const IID *const, void **);
    ULONG (*AddRef)(IProvideClassInfo2 *);
    ULONG (*Release)(IProvideClassInfo2 *);
    HRESULT (*GetClassInfoW)(IProvideClassInfo2 *, ITypeInfo **);
    HRESULT (*GetGUID)(IProvideClassInfo2 *, DWORD, GUID *);
} __attribute__((packed, aligned(4)));

struct IProvideClassInfoVtbl {
    HRESULT (*QueryInterface)(IProvideClassInfo *, const IID *const, void **);
    ULONG (*AddRef)(IProvideClassInfo *);
    ULONG (*Release)(IProvideClassInfo *);
    HRESULT (*GetClassInfoW)(IProvideClassInfo *, ITypeInfo **);
} __attribute__((packed, aligned(4)));

struct IQuickActivate {
    struct IQuickActivateVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IQuickActivateVtbl {
    HRESULT (*QueryInterface)(IQuickActivate *, const IID *const, void **);
    ULONG (*AddRef)(IQuickActivate *);
    ULONG (*Release)(IQuickActivate *);
    HRESULT (*QuickActivate)(IQuickActivate *, QACONTAINER *, QACONTROL *);
    HRESULT (*SetContentExtent)(IQuickActivate *, LPSIZEL);
    HRESULT (*GetContentExtent)(IQuickActivate *, LPSIZEL);
} __attribute__((packed, aligned(4)));

struct ISimpleFrameSite {
    struct ISimpleFrameSiteVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ISimpleFrameSiteVtbl {
    HRESULT (*QueryInterface)(ISimpleFrameSite *, const IID *const, void **);
    ULONG (*AddRef)(ISimpleFrameSite *);
    ULONG (*Release)(ISimpleFrameSite *);
    HRESULT (*PreMessageFilter)(ISimpleFrameSite *, HWND, UINT, WPARAM, LPARAM, LRESULT *, DWORD *);
    HRESULT (*PostMessageFilter)(ISimpleFrameSite *, HWND, UINT, WPARAM, LPARAM, LRESULT *, DWORD);
} __attribute__((packed, aligned(4)));

struct ISpecifyPropertyPages {
    struct ISpecifyPropertyPagesVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ISpecifyPropertyPagesVtbl {
    HRESULT (*QueryInterface)(ISpecifyPropertyPages *, const IID *const, void **);
    ULONG (*AddRef)(ISpecifyPropertyPages *);
    ULONG (*Release)(ISpecifyPropertyPages *);
    HRESULT (*GetPages)(ISpecifyPropertyPages *, CAUUID *);
} __attribute__((packed, aligned(4)));

struct IViewObjectEx {
    struct IViewObjectExVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IViewObjectExVtbl {
    HRESULT (*QueryInterface)(IViewObjectEx *, const IID *const, void **);
    ULONG (*AddRef)(IViewObjectEx *);
    ULONG (*Release)(IViewObjectEx *);
    HRESULT (*Draw)(IViewObjectEx *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, HDC, LPCRECTL, LPCRECTL, BOOL (*)(DWORD), DWORD);
    HRESULT (*GetColorSet)(IViewObjectEx *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, LOGPALETTE **);
    HRESULT (*Freeze)(IViewObjectEx *, DWORD, LONG, void *, DWORD *);
    HRESULT (*Unfreeze)(IViewObjectEx *, DWORD);
    HRESULT (*SetAdvise)(IViewObjectEx *, DWORD, DWORD, IAdviseSink *);
    HRESULT (*GetAdvise)(IViewObjectEx *, DWORD *, DWORD *, IAdviseSink **);
    HRESULT (*GetExtent)(IViewObjectEx *, DWORD, LONG, DVTARGETDEVICE *, LPSIZEL);
    HRESULT (*GetRect)(IViewObjectEx *, DWORD, LPRECTL);
    HRESULT (*GetViewStatus)(IViewObjectEx *, DWORD *);
    HRESULT (*QueryHitPoint)(IViewObjectEx *, DWORD, LPCRECT, POINT, LONG, DWORD *);
    HRESULT (*QueryHitRect)(IViewObjectEx *, DWORD, LPCRECT, LPCRECT, LONG, DWORD *);
    HRESULT (*GetNaturalExtent)(IViewObjectEx *, DWORD, LONG, DVTARGETDEVICE *, HDC, DVEXTENTINFO *, LPSIZEL);
} __attribute__((packed, aligned(4)));

struct tagAspectInfo {
    ULONG cb;
    DWORD dwFlags;
} __attribute__((packed, aligned(4)));

struct tagCADWORD {
    ULONG cElems;
    DWORD *pElems;
} __attribute__((packed, aligned(4)));

struct tagCALPOLESTR {
    ULONG cElems;
    LPOLESTR *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAUUID {
    ULONG cElems;
    GUID *pElems;
} __attribute__((packed, aligned(4)));

struct tagCONNECTDATA {
    IUnknown *pUnk;
    DWORD dwCookie;
} __attribute__((packed, aligned(4)));

struct tagCONTROLINFO {
    ULONG cb;
    HACCEL hAccel;
    USHORT cAccel;
    DWORD dwFlags;
} __attribute__((packed, aligned(4)));

struct tagExtentInfo {
    ULONG cb;
    DWORD dwExtentMode;
    SIZEL sizelProposed;
} __attribute__((packed, aligned(4)));

struct tagLICINFO {
    LONG cbLicInfo;
    BOOL fRuntimeKeyAvail;
    BOOL fLicVerified;
} __attribute__((packed, aligned(4)));

struct tagPOINTF {
    FLOAT x;
    FLOAT y;
} __attribute__((packed, aligned(4)));

struct tagPROPPAGEINFO {
    ULONG cb;
    LPOLESTR pszTitle;
    SIZE size;
    LPOLESTR pszDocString;
    LPOLESTR pszHelpFile;
    DWORD dwHelpContext;
} __attribute__((packed, aligned(4)));

struct tagQACONTAINER {
    ULONG cbSize;
    IOleClientSite *pClientSite;
    IAdviseSinkEx *pAdviseSink;
    IPropertyNotifySink *pPropertyNotifySink;
    IUnknown *pUnkEventSink;
    DWORD dwAmbientFlags;
    OLE_COLOR colorFore;
    OLE_COLOR colorBack;
    IFont *pFont;
    IOleUndoManager *pUndoMgr;
    DWORD dwAppearance;
    LONG lcid;
    HPALETTE hpal;
    struct IBindHost *pBindHost;
} __attribute__((packed, aligned(4)));

struct tagQACONTROL {
    ULONG cbSize;
    DWORD dwMiscStatus;
    DWORD dwViewStatus;
    DWORD dwEventCookie;
    DWORD dwPropNotifyCookie;
    DWORD dwPointerActivationPolicy;
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

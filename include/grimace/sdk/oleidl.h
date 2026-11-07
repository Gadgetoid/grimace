#ifndef GRIMACE_SDK_OLEIDL_H
#define GRIMACE_SDK_OLEIDL_H

#include <grimace/sdk/objbase.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct IOleAdviseHolder;
typedef struct IOleAdviseHolder IOleAdviseHolder;
typedef IOleAdviseHolder *LPOLEADVISEHOLDER;
struct IDropSource;
typedef struct IDropSource IDropSource;
typedef IDropSource *LPDROPSOURCE;
struct IOleClientSite;
typedef struct IOleClientSite IOleClientSite;
typedef IOleClientSite *LPOLECLIENTSITE;
struct IOleObject;
typedef struct IOleObject IOleObject;
typedef IOleObject *LPOLEOBJECT;
typedef HGLOBAL HOLEMENU;
struct IOleInPlaceFrame;
typedef struct IOleInPlaceFrame IOleInPlaceFrame;
typedef IOleInPlaceFrame *LPOLEINPLACEFRAME;
struct IOleInPlaceActiveObject;
typedef struct IOleInPlaceActiveObject IOleInPlaceActiveObject;
typedef IOleInPlaceActiveObject *LPOLEINPLACEACTIVEOBJECT;
struct IDropTarget;
typedef struct IDropTarget IDropTarget;
typedef IDropTarget *LPDROPTARGET;
enum tagBINDSPEED {
    BINDSPEED_INDEFINITE = 1,
    BINDSPEED_MODERATE = 2,
    BINDSPEED_IMMEDIATE = 3
};

typedef enum tagBINDSPEED BINDSPEED;
typedef RECT BORDERWIDTHS;
enum tagDISCARDCACHE {
    DISCARDCACHE_SAVEIFDIRTY = 0,
    DISCARDCACHE_NOSAVE = 1
};

typedef enum tagDISCARDCACHE DISCARDCACHE;
struct IContinue;
typedef struct IContinue IContinue;
struct IContinueVtbl;
typedef struct IContinueVtbl IContinueVtbl;
struct IDropSourceVtbl;
typedef struct IDropSourceVtbl IDropSourceVtbl;
struct IDropTargetVtbl;
typedef struct IDropTargetVtbl IDropTargetVtbl;
struct IEnumOLEVERB;
typedef struct IEnumOLEVERB IEnumOLEVERB;
struct IEnumOLEVERBVtbl;
typedef struct IEnumOLEVERBVtbl IEnumOLEVERBVtbl;
struct IOleAdviseHolderVtbl;
typedef struct IOleAdviseHolderVtbl IOleAdviseHolderVtbl;
struct IOleCache;
typedef struct IOleCache IOleCache;
struct IOleCache2;
typedef struct IOleCache2 IOleCache2;
struct IOleCache2Vtbl;
typedef struct IOleCache2Vtbl IOleCache2Vtbl;
struct IOleCacheControl;
typedef struct IOleCacheControl IOleCacheControl;
struct IOleCacheControlVtbl;
typedef struct IOleCacheControlVtbl IOleCacheControlVtbl;
struct IOleCacheVtbl;
typedef struct IOleCacheVtbl IOleCacheVtbl;
struct IOleClientSiteVtbl;
typedef struct IOleClientSiteVtbl IOleClientSiteVtbl;
struct IOleContainer;
typedef struct IOleContainer IOleContainer;
struct IOleContainerVtbl;
typedef struct IOleContainerVtbl IOleContainerVtbl;
struct IOleInPlaceActiveObjectVtbl;
typedef struct IOleInPlaceActiveObjectVtbl IOleInPlaceActiveObjectVtbl;
struct IOleInPlaceFrameVtbl;
typedef struct IOleInPlaceFrameVtbl IOleInPlaceFrameVtbl;
struct IOleInPlaceObject;
typedef struct IOleInPlaceObject IOleInPlaceObject;
struct IOleInPlaceObjectVtbl;
typedef struct IOleInPlaceObjectVtbl IOleInPlaceObjectVtbl;
struct IOleInPlaceSite;
typedef struct IOleInPlaceSite IOleInPlaceSite;
struct IOleInPlaceSiteVtbl;
typedef struct IOleInPlaceSiteVtbl IOleInPlaceSiteVtbl;
struct IOleInPlaceUIWindow;
typedef struct IOleInPlaceUIWindow IOleInPlaceUIWindow;
struct IOleInPlaceUIWindowVtbl;
typedef struct IOleInPlaceUIWindowVtbl IOleInPlaceUIWindowVtbl;
struct IOleItemContainer;
typedef struct IOleItemContainer IOleItemContainer;
struct IOleItemContainerVtbl;
typedef struct IOleItemContainerVtbl IOleItemContainerVtbl;
struct IOleLink;
typedef struct IOleLink IOleLink;
struct IOleLinkVtbl;
typedef struct IOleLinkVtbl IOleLinkVtbl;
struct IOleObjectVtbl;
typedef struct IOleObjectVtbl IOleObjectVtbl;
struct IOleWindow;
typedef struct IOleWindow IOleWindow;
struct IOleWindowVtbl;
typedef struct IOleWindowVtbl IOleWindowVtbl;
struct IParseDisplayName;
typedef struct IParseDisplayName IParseDisplayName;
struct IParseDisplayNameVtbl;
typedef struct IParseDisplayNameVtbl IParseDisplayNameVtbl;
struct IViewObject;
typedef struct IViewObject IViewObject;
struct IViewObject2;
typedef struct IViewObject2 IViewObject2;
struct IViewObject2Vtbl;
typedef struct IViewObject2Vtbl IViewObject2Vtbl;
struct IViewObjectVtbl;
typedef struct IViewObjectVtbl IViewObjectVtbl;
struct tagOBJECTDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR LINKSRCDESCRIPTOR;
typedef LPRECT LPBORDERWIDTHS;
typedef LPCRECT LPCBORDERWIDTHS;
typedef IEnumOLEVERB *LPENUMOLEVERB;
typedef struct tagOBJECTDESCRIPTOR *LPLINKSRCDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *LPOBJECTDESCRIPTOR;
typedef IOleCache *LPOLECACHE;
typedef IOleCache2 *LPOLECACHE2;
typedef IOleCacheControl *LPOLECACHECONTROL;
typedef IOleContainer *LPOLECONTAINER;
struct tagOIFI;
typedef struct tagOIFI *LPOLEINPLACEFRAMEINFO;
typedef IOleInPlaceObject *LPOLEINPLACEOBJECT;
typedef IOleInPlaceSite *LPOLEINPLACESITE;
typedef IOleInPlaceUIWindow *LPOLEINPLACEUIWINDOW;
typedef IOleItemContainer *LPOLEITEMCONTAINER;
typedef IOleLink *LPOLELINK;
struct tagOleMenuGroupWidths;
typedef struct tagOleMenuGroupWidths *LPOLEMENUGROUPWIDTHS;
enum tagOLERENDER {
    OLERENDER_NONE = 0,
    OLERENDER_DRAW = 1,
    OLERENDER_FORMAT = 2,
    OLERENDER_ASIS = 3
};

typedef enum tagOLERENDER OLERENDER;
typedef OLERENDER *LPOLERENDER;
enum tagOLEUPDATE {
    OLEUPDATE_ALWAYS = 1,
    OLEUPDATE_ONCALL = 3
};

typedef enum tagOLEUPDATE OLEUPDATE;
typedef OLEUPDATE *LPOLEUPDATE;
struct tagOLEVERB;
typedef struct tagOLEVERB *LPOLEVERB;
typedef IOleWindow *LPOLEWINDOW;
typedef IParseDisplayName *LPPARSEDISPLAYNAME;
typedef IViewObject *LPVIEWOBJECT;
typedef IViewObject2 *LPVIEWOBJECT2;
typedef struct tagOBJECTDESCRIPTOR OBJECTDESCRIPTOR;
enum tagOLECLOSE {
    OLECLOSE_SAVEIFDIRTY = 0,
    OLECLOSE_NOSAVE = 1,
    OLECLOSE_PROMPTSAVE = 2
};

typedef enum tagOLECLOSE OLECLOSE;
enum tagOLECONTF {
    OLECONTF_EMBEDDINGS = 1,
    OLECONTF_LINKS = 2,
    OLECONTF_OTHERS = 4,
    OLECONTF_ONLYUSER = 8,
    OLECONTF_ONLYIFRUNNING = 16
};

typedef enum tagOLECONTF OLECONTF;
enum tagOLEGETMONIKER {
    OLEGETMONIKER_ONLYIFTHERE = 1,
    OLEGETMONIKER_FORCEASSIGN = 2,
    OLEGETMONIKER_UNASSIGN = 3,
    OLEGETMONIKER_TEMPFORUSER = 4
};

typedef enum tagOLEGETMONIKER OLEGETMONIKER;
typedef struct tagOIFI OLEINPLACEFRAMEINFO;
enum tagOLELINKBIND {
    OLELINKBIND_EVENIFCLASSDIFF = 1
};

typedef enum tagOLELINKBIND OLELINKBIND;
typedef struct tagOleMenuGroupWidths OLEMENUGROUPWIDTHS;
enum tagOLEMISC {
    OLEMISC_RECOMPOSEONRESIZE = 1,
    OLEMISC_ONLYICONIC = 2,
    OLEMISC_INSERTNOTREPLACE = 4,
    OLEMISC_STATIC = 8,
    OLEMISC_CANTLINKINSIDE = 16,
    OLEMISC_CANLINKBYOLE1 = 32,
    OLEMISC_ISLINKOBJECT = 64,
    OLEMISC_INSIDEOUT = 128,
    OLEMISC_ACTIVATEWHENVISIBLE = 256,
    OLEMISC_RENDERINGISDEVICEINDEPENDENT = 512,
    OLEMISC_INVISIBLEATRUNTIME = 1024,
    OLEMISC_ALWAYSRUN = 2048,
    OLEMISC_ACTSLIKEBUTTON = 4096,
    OLEMISC_ACTSLIKELABEL = 8192,
    OLEMISC_NOUIACTIVATE = 16384,
    OLEMISC_ALIGNABLE = 32768,
    OLEMISC_SIMPLEFRAME = 65536,
    OLEMISC_SETCLIENTSITEFIRST = 131072,
    OLEMISC_IMEMODE = 262144,
    OLEMISC_IGNOREACTIVATEWHENVISIBLE = 524288,
    OLEMISC_WANTSTOMENUMERGE = 1048576,
    OLEMISC_SUPPORTSMULTILEVELUNDO = 2097152
};

typedef enum tagOLEMISC OLEMISC;
typedef struct tagOLEVERB OLEVERB;
enum tagOLEVERBATTRIB {
    OLEVERBATTRIB_NEVERDIRTIES = 1,
    OLEVERBATTRIB_ONCONTAINERMENU = 2
};

typedef enum tagOLEVERBATTRIB OLEVERBATTRIB;
enum tagOLEWHICHMK {
    OLEWHICHMK_CONTAINER = 1,
    OLEWHICHMK_OBJREL = 2,
    OLEWHICHMK_OBJFULL = 3
};

typedef enum tagOLEWHICHMK OLEWHICHMK;
typedef struct tagOBJECTDESCRIPTOR *PLINKSRCDESCRIPTOR;
typedef struct tagOBJECTDESCRIPTOR *POBJECTDESCRIPTOR;
typedef OLEUPDATE *POLEUPDATE;
enum tagUSERCLASSTYPE {
    USERCLASSTYPE_FULL = 1,
    USERCLASSTYPE_SHORT = 2,
    USERCLASSTYPE_APPNAME = 3
};

typedef enum tagUSERCLASSTYPE USERCLASSTYPE;
struct IContinue {
    struct IContinueVtbl *lpVtbl;
};

struct IContinueVtbl {
    HRESULT (*QueryInterface)(IContinue *, const IID *const, void **);
    ULONG (*AddRef)(IContinue *);
    ULONG (*Release)(IContinue *);
    HRESULT (*FContinue)(IContinue *);
};

struct IDropSource {
    struct IDropSourceVtbl *lpVtbl;
};

struct IDropSourceVtbl {
    HRESULT (*QueryInterface)(IDropSource *, const IID *const, void **);
    ULONG (*AddRef)(IDropSource *);
    ULONG (*Release)(IDropSource *);
    HRESULT (*QueryContinueDrag)(IDropSource *, BOOL, DWORD);
    HRESULT (*GiveFeedback)(IDropSource *, DWORD);
};

struct IDropTarget {
    struct IDropTargetVtbl *lpVtbl;
};

struct IDropTargetVtbl {
    HRESULT (*QueryInterface)(IDropTarget *, const IID *const, void **);
    ULONG (*AddRef)(IDropTarget *);
    ULONG (*Release)(IDropTarget *);
    HRESULT (*DragEnter)(IDropTarget *, IDataObject *, DWORD, POINTL, DWORD *);
    HRESULT (*DragOver)(IDropTarget *, DWORD, POINTL, DWORD *);
    HRESULT (*DragLeave)(IDropTarget *);
    HRESULT (*Drop)(IDropTarget *, IDataObject *, DWORD, POINTL, DWORD *);
};

struct IEnumOLEVERB {
    struct IEnumOLEVERBVtbl *lpVtbl;
};

struct IEnumOLEVERBVtbl {
    HRESULT (*QueryInterface)(IEnumOLEVERB *, const IID *const, void **);
    ULONG (*AddRef)(IEnumOLEVERB *);
    ULONG (*Release)(IEnumOLEVERB *);
    HRESULT (*Next)(IEnumOLEVERB *, ULONG, LPOLEVERB, ULONG *);
    HRESULT (*Skip)(IEnumOLEVERB *, ULONG);
    HRESULT (*Reset)(IEnumOLEVERB *);
    HRESULT (*Clone)(IEnumOLEVERB *, IEnumOLEVERB **);
};

struct IOleAdviseHolder {
    struct IOleAdviseHolderVtbl *lpVtbl;
};

struct IOleAdviseHolderVtbl {
    HRESULT (*QueryInterface)(IOleAdviseHolder *, const IID *const, void **);
    ULONG (*AddRef)(IOleAdviseHolder *);
    ULONG (*Release)(IOleAdviseHolder *);
    HRESULT (*Advise)(IOleAdviseHolder *, IAdviseSink *, DWORD *);
    HRESULT (*Unadvise)(IOleAdviseHolder *, DWORD);
    HRESULT (*EnumAdvise)(IOleAdviseHolder *, IEnumSTATDATA **);
    HRESULT (*SendOnRename)(IOleAdviseHolder *, IMoniker *);
    HRESULT (*SendOnSave)(IOleAdviseHolder *);
    HRESULT (*SendOnClose)(IOleAdviseHolder *);
};

struct IOleCache {
    struct IOleCacheVtbl *lpVtbl;
};

struct IOleCache2 {
    struct IOleCache2Vtbl *lpVtbl;
};

struct IOleCache2Vtbl {
    HRESULT (*QueryInterface)(IOleCache2 *, const IID *const, void **);
    ULONG (*AddRef)(IOleCache2 *);
    ULONG (*Release)(IOleCache2 *);
    HRESULT (*Cache)(IOleCache2 *, FORMATETC *, DWORD, DWORD *);
    HRESULT (*Uncache)(IOleCache2 *, DWORD);
    HRESULT (*EnumCache)(IOleCache2 *, IEnumSTATDATA **);
    HRESULT (*InitCache)(IOleCache2 *, IDataObject *);
    HRESULT (*SetData)(IOleCache2 *, FORMATETC *, STGMEDIUM *, BOOL);
    HRESULT (*UpdateCache)(IOleCache2 *, LPDATAOBJECT, DWORD, LPVOID);
    HRESULT (*DiscardCache)(IOleCache2 *, DWORD);
};

struct IOleCacheControl {
    struct IOleCacheControlVtbl *lpVtbl;
};

struct IOleCacheControlVtbl {
    HRESULT (*QueryInterface)(IOleCacheControl *, const IID *const, void **);
    ULONG (*AddRef)(IOleCacheControl *);
    ULONG (*Release)(IOleCacheControl *);
    HRESULT (*OnRun)(IOleCacheControl *, LPDATAOBJECT);
    HRESULT (*OnStop)(IOleCacheControl *);
};

struct IOleCacheVtbl {
    HRESULT (*QueryInterface)(IOleCache *, const IID *const, void **);
    ULONG (*AddRef)(IOleCache *);
    ULONG (*Release)(IOleCache *);
    HRESULT (*Cache)(IOleCache *, FORMATETC *, DWORD, DWORD *);
    HRESULT (*Uncache)(IOleCache *, DWORD);
    HRESULT (*EnumCache)(IOleCache *, IEnumSTATDATA **);
    HRESULT (*InitCache)(IOleCache *, IDataObject *);
    HRESULT (*SetData)(IOleCache *, FORMATETC *, STGMEDIUM *, BOOL);
};

struct IOleClientSite {
    struct IOleClientSiteVtbl *lpVtbl;
};

struct IOleClientSiteVtbl {
    HRESULT (*QueryInterface)(IOleClientSite *, const IID *const, void **);
    ULONG (*AddRef)(IOleClientSite *);
    ULONG (*Release)(IOleClientSite *);
    HRESULT (*SaveObject)(IOleClientSite *);
    HRESULT (*GetMoniker)(IOleClientSite *, DWORD, DWORD, IMoniker **);
    HRESULT (*GetContainer)(IOleClientSite *, IOleContainer **);
    HRESULT (*ShowObject)(IOleClientSite *);
    HRESULT (*OnShowWindow)(IOleClientSite *, BOOL);
    HRESULT (*RequestNewObjectLayout)(IOleClientSite *);
};

struct IOleContainer {
    struct IOleContainerVtbl *lpVtbl;
};

struct IOleContainerVtbl {
    HRESULT (*QueryInterface)(IOleContainer *, const IID *const, void **);
    ULONG (*AddRef)(IOleContainer *);
    ULONG (*Release)(IOleContainer *);
    HRESULT (*ParseDisplayName)(IOleContainer *, IBindCtx *, LPOLESTR, ULONG *, IMoniker **);
    HRESULT (*EnumObjects)(IOleContainer *, DWORD, IEnumUnknown **);
    HRESULT (*LockContainer)(IOleContainer *, BOOL);
};

struct IOleInPlaceActiveObject {
    struct IOleInPlaceActiveObjectVtbl *lpVtbl;
};

struct IOleInPlaceActiveObjectVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceActiveObject *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceActiveObject *);
    ULONG (*Release)(IOleInPlaceActiveObject *);
    HRESULT (*GetWindow)(IOleInPlaceActiveObject *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceActiveObject *, BOOL);
    HRESULT (*TranslateAcceleratorW)(IOleInPlaceActiveObject *, LPMSG);
    HRESULT (*OnFrameWindowActivate)(IOleInPlaceActiveObject *, BOOL);
    HRESULT (*OnDocWindowActivate)(IOleInPlaceActiveObject *, BOOL);
    HRESULT (*ResizeBorder)(IOleInPlaceActiveObject *, LPCRECT, IOleInPlaceUIWindow *, BOOL);
    HRESULT (*EnableModeless)(IOleInPlaceActiveObject *, BOOL);
};

struct IOleInPlaceFrame {
    struct IOleInPlaceFrameVtbl *lpVtbl;
};

struct IOleInPlaceFrameVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceFrame *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceFrame *);
    ULONG (*Release)(IOleInPlaceFrame *);
    HRESULT (*GetWindow)(IOleInPlaceFrame *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceFrame *, BOOL);
    HRESULT (*GetBorder)(IOleInPlaceFrame *, LPRECT);
    HRESULT (*RequestBorderSpace)(IOleInPlaceFrame *, LPCBORDERWIDTHS);
    HRESULT (*SetBorderSpace)(IOleInPlaceFrame *, LPCBORDERWIDTHS);
    HRESULT (*SetActiveObject)(IOleInPlaceFrame *, IOleInPlaceActiveObject *, LPCOLESTR);
    HRESULT (*InsertMenus)(IOleInPlaceFrame *, HMENU, LPOLEMENUGROUPWIDTHS);
    HRESULT (*SetMenu)(IOleInPlaceFrame *, HMENU, HOLEMENU, HWND);
    HRESULT (*RemoveMenus)(IOleInPlaceFrame *, HMENU);
    HRESULT (*SetStatusText)(IOleInPlaceFrame *, LPCOLESTR);
    HRESULT (*EnableModeless)(IOleInPlaceFrame *, BOOL);
    HRESULT (*TranslateAcceleratorW)(IOleInPlaceFrame *, LPMSG, WORD);
};

struct IOleInPlaceObject {
    struct IOleInPlaceObjectVtbl *lpVtbl;
};

struct IOleInPlaceObjectVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceObject *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceObject *);
    ULONG (*Release)(IOleInPlaceObject *);
    HRESULT (*GetWindow)(IOleInPlaceObject *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceObject *, BOOL);
    HRESULT (*InPlaceDeactivate)(IOleInPlaceObject *);
    HRESULT (*UIDeactivate)(IOleInPlaceObject *);
    HRESULT (*SetObjectRects)(IOleInPlaceObject *, LPCRECT, LPCRECT);
    HRESULT (*ReactivateAndUndo)(IOleInPlaceObject *);
};

struct IOleInPlaceSite {
    struct IOleInPlaceSiteVtbl *lpVtbl;
};

struct IOleInPlaceSiteVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceSite *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceSite *);
    ULONG (*Release)(IOleInPlaceSite *);
    HRESULT (*GetWindow)(IOleInPlaceSite *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceSite *, BOOL);
    HRESULT (*CanInPlaceActivate)(IOleInPlaceSite *);
    HRESULT (*OnInPlaceActivate)(IOleInPlaceSite *);
    HRESULT (*OnUIActivate)(IOleInPlaceSite *);
    HRESULT (*GetWindowContext)(IOleInPlaceSite *, IOleInPlaceFrame **, IOleInPlaceUIWindow **, LPRECT, LPRECT, LPOLEINPLACEFRAMEINFO);
    HRESULT (*Scroll)(IOleInPlaceSite *, SIZE);
    HRESULT (*OnUIDeactivate)(IOleInPlaceSite *, BOOL);
    HRESULT (*OnInPlaceDeactivate)(IOleInPlaceSite *);
    HRESULT (*DiscardUndoState)(IOleInPlaceSite *);
    HRESULT (*DeactivateAndUndo)(IOleInPlaceSite *);
    HRESULT (*OnPosRectChange)(IOleInPlaceSite *, LPCRECT);
};

struct IOleInPlaceUIWindow {
    struct IOleInPlaceUIWindowVtbl *lpVtbl;
};

struct IOleInPlaceUIWindowVtbl {
    HRESULT (*QueryInterface)(IOleInPlaceUIWindow *, const IID *const, void **);
    ULONG (*AddRef)(IOleInPlaceUIWindow *);
    ULONG (*Release)(IOleInPlaceUIWindow *);
    HRESULT (*GetWindow)(IOleInPlaceUIWindow *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleInPlaceUIWindow *, BOOL);
    HRESULT (*GetBorder)(IOleInPlaceUIWindow *, LPRECT);
    HRESULT (*RequestBorderSpace)(IOleInPlaceUIWindow *, LPCBORDERWIDTHS);
    HRESULT (*SetBorderSpace)(IOleInPlaceUIWindow *, LPCBORDERWIDTHS);
    HRESULT (*SetActiveObject)(IOleInPlaceUIWindow *, IOleInPlaceActiveObject *, LPCOLESTR);
};

struct IOleItemContainer {
    struct IOleItemContainerVtbl *lpVtbl;
};

struct IOleItemContainerVtbl {
    HRESULT (*QueryInterface)(IOleItemContainer *, const IID *const, void **);
    ULONG (*AddRef)(IOleItemContainer *);
    ULONG (*Release)(IOleItemContainer *);
    HRESULT (*ParseDisplayName)(IOleItemContainer *, IBindCtx *, LPOLESTR, ULONG *, IMoniker **);
    HRESULT (*EnumObjects)(IOleItemContainer *, DWORD, IEnumUnknown **);
    HRESULT (*LockContainer)(IOleItemContainer *, BOOL);
    HRESULT (*GetObjectW)(IOleItemContainer *, LPOLESTR, DWORD, IBindCtx *, const IID *const, void **);
    HRESULT (*GetObjectStorage)(IOleItemContainer *, LPOLESTR, IBindCtx *, const IID *const, void **);
    HRESULT (*IsRunning)(IOleItemContainer *, LPOLESTR);
};

struct IOleLink {
    struct IOleLinkVtbl *lpVtbl;
};

struct IOleLinkVtbl {
    HRESULT (*QueryInterface)(IOleLink *, const IID *const, void **);
    ULONG (*AddRef)(IOleLink *);
    ULONG (*Release)(IOleLink *);
    HRESULT (*SetUpdateOptions)(IOleLink *, DWORD);
    HRESULT (*GetUpdateOptions)(IOleLink *, DWORD *);
    HRESULT (*SetSourceMoniker)(IOleLink *, IMoniker *, const CLSID *const);
    HRESULT (*GetSourceMoniker)(IOleLink *, IMoniker **);
    HRESULT (*SetSourceDisplayName)(IOleLink *, LPCOLESTR);
    HRESULT (*GetSourceDisplayName)(IOleLink *, LPOLESTR *);
    HRESULT (*BindToSource)(IOleLink *, DWORD, IBindCtx *);
    HRESULT (*BindIfRunning)(IOleLink *);
    HRESULT (*GetBoundSource)(IOleLink *, IUnknown **);
    HRESULT (*UnbindSource)(IOleLink *);
    HRESULT (*Update)(IOleLink *, IBindCtx *);
};

struct IOleObject {
    struct IOleObjectVtbl *lpVtbl;
};

struct IOleObjectVtbl {
    HRESULT (*QueryInterface)(IOleObject *, const IID *const, void **);
    ULONG (*AddRef)(IOleObject *);
    ULONG (*Release)(IOleObject *);
    HRESULT (*SetClientSite)(IOleObject *, IOleClientSite *);
    HRESULT (*GetClientSite)(IOleObject *, IOleClientSite **);
    HRESULT (*SetHostNames)(IOleObject *, LPCOLESTR, LPCOLESTR);
    HRESULT (*Close)(IOleObject *, DWORD);
    HRESULT (*SetMoniker)(IOleObject *, DWORD, IMoniker *);
    HRESULT (*GetMoniker)(IOleObject *, DWORD, DWORD, IMoniker **);
    HRESULT (*InitFromData)(IOleObject *, IDataObject *, BOOL, DWORD);
    HRESULT (*GetClipboardData)(IOleObject *, DWORD, IDataObject **);
    HRESULT (*DoVerb)(IOleObject *, LONG, LPMSG, IOleClientSite *, LONG, HWND, LPCRECT);
    HRESULT (*EnumVerbs)(IOleObject *, IEnumOLEVERB **);
    HRESULT (*Update)(IOleObject *);
    HRESULT (*IsUpToDate)(IOleObject *);
    HRESULT (*GetUserClassID)(IOleObject *, CLSID *);
    HRESULT (*GetUserType)(IOleObject *, DWORD, LPOLESTR *);
    HRESULT (*SetExtent)(IOleObject *, DWORD, SIZEL *);
    HRESULT (*GetExtent)(IOleObject *, DWORD, SIZEL *);
    HRESULT (*Advise)(IOleObject *, IAdviseSink *, DWORD *);
    HRESULT (*Unadvise)(IOleObject *, DWORD);
    HRESULT (*EnumAdvise)(IOleObject *, IEnumSTATDATA **);
    HRESULT (*GetMiscStatus)(IOleObject *, DWORD, DWORD *);
    HRESULT (*SetColorScheme)(IOleObject *, LOGPALETTE *);
};

struct IOleWindow {
    struct IOleWindowVtbl *lpVtbl;
};

struct IOleWindowVtbl {
    HRESULT (*QueryInterface)(IOleWindow *, const IID *const, void **);
    ULONG (*AddRef)(IOleWindow *);
    ULONG (*Release)(IOleWindow *);
    HRESULT (*GetWindow)(IOleWindow *, HWND *);
    HRESULT (*ContextSensitiveHelp)(IOleWindow *, BOOL);
};

struct IParseDisplayName {
    struct IParseDisplayNameVtbl *lpVtbl;
};

struct IParseDisplayNameVtbl {
    HRESULT (*QueryInterface)(IParseDisplayName *, const IID *const, void **);
    ULONG (*AddRef)(IParseDisplayName *);
    ULONG (*Release)(IParseDisplayName *);
    HRESULT (*ParseDisplayName)(IParseDisplayName *, IBindCtx *, LPOLESTR, ULONG *, IMoniker **);
};

struct IViewObject {
    struct IViewObjectVtbl *lpVtbl;
};

struct IViewObject2 {
    struct IViewObject2Vtbl *lpVtbl;
};

struct IViewObject2Vtbl {
    HRESULT (*QueryInterface)(IViewObject2 *, const IID *const, void **);
    ULONG (*AddRef)(IViewObject2 *);
    ULONG (*Release)(IViewObject2 *);
    HRESULT (*Draw)(IViewObject2 *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, HDC, LPCRECTL, LPCRECTL, BOOL (*)(DWORD), DWORD);
    HRESULT (*GetColorSet)(IViewObject2 *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, LOGPALETTE **);
    HRESULT (*Freeze)(IViewObject2 *, DWORD, LONG, void *, DWORD *);
    HRESULT (*Unfreeze)(IViewObject2 *, DWORD);
    HRESULT (*SetAdvise)(IViewObject2 *, DWORD, DWORD, IAdviseSink *);
    HRESULT (*GetAdvise)(IViewObject2 *, DWORD *, DWORD *, IAdviseSink **);
    HRESULT (*GetExtent)(IViewObject2 *, DWORD, LONG, DVTARGETDEVICE *, LPSIZEL);
};

struct IViewObjectVtbl {
    HRESULT (*QueryInterface)(IViewObject *, const IID *const, void **);
    ULONG (*AddRef)(IViewObject *);
    ULONG (*Release)(IViewObject *);
    HRESULT (*Draw)(IViewObject *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, HDC, LPCRECTL, LPCRECTL, BOOL (*)(DWORD), DWORD);
    HRESULT (*GetColorSet)(IViewObject *, DWORD, LONG, void *, DVTARGETDEVICE *, HDC, LOGPALETTE **);
    HRESULT (*Freeze)(IViewObject *, DWORD, LONG, void *, DWORD *);
    HRESULT (*Unfreeze)(IViewObject *, DWORD);
    HRESULT (*SetAdvise)(IViewObject *, DWORD, DWORD, IAdviseSink *);
    HRESULT (*GetAdvise)(IViewObject *, DWORD *, DWORD *, IAdviseSink **);
};

struct tagOBJECTDESCRIPTOR {
    ULONG cbSize;
    CLSID clsid;
    DWORD dwDrawAspect;
    SIZEL sizel;
    POINTL pointl;
    DWORD dwStatus;
    DWORD dwFullUserTypeName;
    DWORD dwSrcOfCopy;
};

struct tagOIFI {
    UINT cb;
    BOOL fMDIApp;
    HWND hwndFrame;
    HACCEL haccel;
    UINT cAccelEntries;
};

struct tagOLEVERB {
    LONG lVerb;
    LPOLESTR lpszVerbName;
    DWORD fuFlags;
    DWORD grfAttribs;
};

struct tagOleMenuGroupWidths {
    LONG width[6];
};


#ifdef __cplusplus
}
#endif

#endif

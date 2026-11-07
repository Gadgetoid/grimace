#ifndef GRIMACE_SDK_ASFORM_H
#define GRIMACE_SDK_ASFORM_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/ocidl.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ActiveAPISet;
typedef struct ActiveAPISet ActiveAPISet;
struct ActiveAPISetVtbl;
typedef struct ActiveAPISetVtbl ActiveAPISetVtbl;
struct ActiveSmallFormEvents;
typedef struct ActiveSmallFormEvents ActiveSmallFormEvents;
struct ActiveSmallFormEventsVtbl;
typedef struct ActiveSmallFormEventsVtbl ActiveSmallFormEventsVtbl;
struct ActiveSmallXObjectEvents;
typedef struct ActiveSmallXObjectEvents ActiveSmallXObjectEvents;
struct ActiveSmallXObjectEventsVtbl;
typedef struct ActiveSmallXObjectEventsVtbl ActiveSmallXObjectEventsVtbl;
typedef struct {

} CActiveSmallForm;

typedef struct {

} CActiveSmallXObject;

enum tagDRAGSTATE {
    DRAGSTATE_NONE = 0,
    DRAGSTATE_ADD = 1,
    DRAGSTATE_SELECT = 2,
    DRAGSTATE_MOVE = 3,
    DRAGSTATE_SIZE = 4
};

typedef enum tagDRAGSTATE DRAGSTATE;
struct IASControls;
typedef struct IASControls IASControls;
struct IASControlsVtbl;
typedef struct IASControlsVtbl IASControlsVtbl;
struct IASExtendedControl;
typedef struct IASExtendedControl IASExtendedControl;
struct IASExtendedControlVtbl;
typedef struct IASExtendedControlVtbl IASExtendedControlVtbl;
struct IASForm;
typedef struct IASForm IASForm;
struct IASFormVtbl;
typedef struct IASFormVtbl IASFormVtbl;
enum tagSCROLLSTYLE {
    SCROLLSTYLE_NONE = 0,
    SCROLLSTYLE_HORIZONTAL = 1,
    SCROLLSTYLE_VERTICAL = 2,
    SCROLLSTYLE_BOTH = 3
};

typedef enum tagSCROLLSTYLE SCROLLSTYLE;
struct ActiveAPISet {
    struct ActiveAPISetVtbl *lpVtbl;
};

struct ActiveAPISetVtbl {
    HRESULT (*QueryInterface)(ActiveAPISet *, const IID *const, void **);
    ULONG (*AddRef)(ActiveAPISet *);
    ULONG (*Release)(ActiveAPISet *);
    HRESULT (*GetTypeInfoCount)(ActiveAPISet *, UINT *);
    HRESULT (*GetTypeInfo)(ActiveAPISet *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(ActiveAPISet *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(ActiveAPISet *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
};

struct ActiveSmallFormEvents {
    struct ActiveSmallFormEventsVtbl *lpVtbl;
};

struct ActiveSmallFormEventsVtbl {
    HRESULT (*QueryInterface)(ActiveSmallFormEvents *, const IID *const, void **);
    ULONG (*AddRef)(ActiveSmallFormEvents *);
    ULONG (*Release)(ActiveSmallFormEvents *);
    HRESULT (*GetTypeInfoCount)(ActiveSmallFormEvents *, UINT *);
    HRESULT (*GetTypeInfo)(ActiveSmallFormEvents *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(ActiveSmallFormEvents *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(ActiveSmallFormEvents *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
};

struct ActiveSmallXObjectEvents {
    struct ActiveSmallXObjectEventsVtbl *lpVtbl;
};

struct ActiveSmallXObjectEventsVtbl {
    HRESULT (*QueryInterface)(ActiveSmallXObjectEvents *, const IID *const, void **);
    ULONG (*AddRef)(ActiveSmallXObjectEvents *);
    ULONG (*Release)(ActiveSmallXObjectEvents *);
    HRESULT (*GetTypeInfoCount)(ActiveSmallXObjectEvents *, UINT *);
    HRESULT (*GetTypeInfo)(ActiveSmallXObjectEvents *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(ActiveSmallXObjectEvents *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(ActiveSmallXObjectEvents *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
};

struct IASControls {
    struct IASControlsVtbl *lpVtbl;
};

struct IASControlsVtbl {
    HRESULT (*QueryInterface)(IASControls *, const IID *const, void **);
    ULONG (*AddRef)(IASControls *);
    ULONG (*Release)(IASControls *);
    HRESULT (*GetTypeInfoCount)(IASControls *, UINT *);
    HRESULT (*GetTypeInfo)(IASControls *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IASControls *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IASControls *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*Add)(IASControls *, BSTR, BSTR, long, long, long, long, IUnknown **);
    HRESULT (*get_Count)(IASControls *, long *);
    HRESULT (*get_Item)(IASControls *, long, IUnknown **);
    HRESULT (*get__NewEnum)(IASControls *, IUnknown **);
    HRESULT (*Remove)(IASControls *, long);
};

struct IASExtendedControl {
    struct IASExtendedControlVtbl *lpVtbl;
};

struct IASExtendedControlVtbl {
    HRESULT (*QueryInterface)(IASExtendedControl *, const IID *const, void **);
    ULONG (*AddRef)(IASExtendedControl *);
    ULONG (*Release)(IASExtendedControl *);
    HRESULT (*GetTypeInfoCount)(IASExtendedControl *, UINT *);
    HRESULT (*GetTypeInfo)(IASExtendedControl *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IASExtendedControl *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IASExtendedControl *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*put_Left)(IASExtendedControl *, long);
    HRESULT (*get_Left)(IASExtendedControl *, long *);
    HRESULT (*put_Height)(IASExtendedControl *, long);
    HRESULT (*get_Height)(IASExtendedControl *, long *);
    HRESULT (*get_hWnd)(IASExtendedControl *, HWND *);
    HRESULT (*put_Name)(IASExtendedControl *, BSTR);
    HRESULT (*get_Name)(IASExtendedControl *, BSTR *);
    HRESULT (*put_Width)(IASExtendedControl *, long);
    HRESULT (*get_Width)(IASExtendedControl *, long *);
    HRESULT (*put_Parent)(IASExtendedControl *, IUnknown *);
    HRESULT (*get_Parent)(IASExtendedControl *, IUnknown **);
    HRESULT (*put_TabIndex)(IASExtendedControl *, long);
    HRESULT (*get_TabIndex)(IASExtendedControl *, long *);
    HRESULT (*put_TabStop)(IASExtendedControl *, BOOL);
    HRESULT (*get_TabStop)(IASExtendedControl *, BOOL *);
    HRESULT (*put_Tag)(IASExtendedControl *, long);
    HRESULT (*get_Tag)(IASExtendedControl *, long *);
    HRESULT (*put_Top)(IASExtendedControl *, long);
    HRESULT (*get_Top)(IASExtendedControl *, long *);
    HRESULT (*put_Visible)(IASExtendedControl *, BOOL);
    HRESULT (*get_Visible)(IASExtendedControl *, BOOL *);
};

struct IASForm {
    struct IASFormVtbl *lpVtbl;
};

struct IASFormVtbl {
    HRESULT (*QueryInterface)(IASForm *, const IID *const, void **);
    ULONG (*AddRef)(IASForm *);
    ULONG (*Release)(IASForm *);
    HRESULT (*GetTypeInfoCount)(IASForm *, UINT *);
    HRESULT (*GetTypeInfo)(IASForm *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IASForm *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IASForm *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*put_BackColor)(IASForm *, OLE_COLOR);
    HRESULT (*get_BackColor)(IASForm *, OLE_COLOR *);
    HRESULT (*put_BorderStyle)(IASForm *, unsigned long);
    HRESULT (*get_BorderStyle)(IASForm *, unsigned long *);
    HRESULT (*put_Caption)(IASForm *, BSTR);
    HRESULT (*get_Caption)(IASForm *, BSTR *);
    HRESULT (*get_Controls)(IASForm *, IASControls **);
    HRESULT (*put_DisabledScrollStyle)(IASForm *, SCROLLSTYLE);
    HRESULT (*get_DisabledScrollStyle)(IASForm *, SCROLLSTYLE *);
    HRESULT (*put_ForeColor)(IASForm *, OLE_COLOR);
    HRESULT (*get_ForeColor)(IASForm *, OLE_COLOR *);
    HRESULT (*get_hDC)(IASForm *, HDC *);
    HRESULT (*put_Height)(IASForm *, long);
    HRESULT (*get_Height)(IASForm *, long *);
    HRESULT (*get_hWnd)(IASForm *, HWND *);
    HRESULT (*get_Name)(IASForm *, BSTR *);
    HRESULT (*put_Left)(IASForm *, long);
    HRESULT (*get_Left)(IASForm *, long *);
    HRESULT (*put_Redraw)(IASForm *, long);
    HRESULT (*get_Redraw)(IASForm *, long *);
    HRESULT (*put_ScaleHeight)(IASForm *, long);
    HRESULT (*get_ScaleHeight)(IASForm *, long *);
    HRESULT (*put_ScaleWidth)(IASForm *, long);
    HRESULT (*get_ScaleWidth)(IASForm *, long *);
    HRESULT (*put_ScrollStyle)(IASForm *, SCROLLSTYLE);
    HRESULT (*get_ScrollStyle)(IASForm *, SCROLLSTYLE *);
    HRESULT (*put_Selected)(IASForm *, IUnknown *);
    HRESULT (*get_Selected)(IASForm *, IUnknown **);
    HRESULT (*put_Focus)(IASForm *, IUnknown *);
    HRESULT (*get_Focus)(IASForm *, IUnknown **);
    HRESULT (*put_Top)(IASForm *, long);
    HRESULT (*get_Top)(IASForm *, long *);
    HRESULT (*put_UserMode)(IASForm *, BOOL);
    HRESULT (*get_UserMode)(IASForm *, BOOL *);
    HRESULT (*put_ViewportOrgX)(IASForm *, long);
    HRESULT (*get_ViewportOrgX)(IASForm *, long *);
    HRESULT (*put_ViewportOrgY)(IASForm *, long);
    HRESULT (*get_ViewportOrgY)(IASForm *, long *);
    HRESULT (*put_WindowExtX)(IASForm *, long);
    HRESULT (*get_WindowExtX)(IASForm *, long *);
    HRESULT (*put_WindowExtY)(IASForm *, long);
    HRESULT (*get_WindowExtY)(IASForm *, long *);
    HRESULT (*put_Width)(IASForm *, long);
    HRESULT (*get_Width)(IASForm *, long *);
    HRESULT (*put_HandleEraseBkGnd)(IASForm *, long);
    HRESULT (*get_HandleEraseBkGnd)(IASForm *, long *);
    HRESULT (*Hide)(IASForm *);
    HRESULT (*Refresh)(IASForm *);
    HRESULT (*Show)(IASForm *, DWORD);
    void (*FireViewChange)(IASForm *);
    void (*OutputDebugStringW)(IASForm *, BSTR);
    HRESULT (*MoveControl)(IASForm *, LPUNKNOWN, LPCRECT, BOOL);
    HRESULT (*MoveControlToFront)(IASForm *, LPUNKNOWN);
    HRESULT (*MoveControlToBack)(IASForm *, LPUNKNOWN);
    HRESULT (*DeleteControl)(IASForm *, LPUNKNOWN);
    HRESULT (*ControlFromPoint)(IASForm *, POINT, LPUNKNOWN *);
    HRESULT (*ControlDispatchFromID)(IASForm *, DWORD, IDispatch **);
};


#ifdef __cplusplus
}
#endif

#endif

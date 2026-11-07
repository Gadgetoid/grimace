#ifndef GRIMACE_SDK_OAIDL_H
#define GRIMACE_SDK_OAIDL_H

#include <grimace/sdk/rpcndr.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct tagSAFEARRAY;
typedef struct tagSAFEARRAY SAFEARRAY;
struct ICreateErrorInfo;
typedef struct ICreateErrorInfo ICreateErrorInfo;
enum tagSYSKIND {
    SYS_WIN16 = 0,
    SYS_WIN32 = 1,
    SYS_MAC = 2
};

typedef enum tagSYSKIND SYSKIND;
struct ICreateTypeLib2;
typedef struct ICreateTypeLib2 ICreateTypeLib2;
enum tagCALLCONV {
    CC_FASTCALL = 0,
    CC_CDECL = 1,
    CC_MSCPASCAL = 2,
    CC_PASCAL = 2,
    CC_MACPASCAL = 3,
    CC_STDCALL = 4,
    CC_FPFASTCALL = 5,
    CC_SYSCALL = 6,
    CC_MPWCDECL = 7,
    CC_MPWPASCAL = 8,
    CC_MAX = 9
};

typedef enum tagCALLCONV CALLCONV;
struct tagVARIANT;
typedef struct tagVARIANT VARIANT;
typedef VARIANT VARIANTARG;
struct ITypeInfo;
typedef struct ITypeInfo ITypeInfo;
typedef LONG DISPID;
struct tagDISPPARAMS;
typedef struct tagDISPPARAMS DISPPARAMS;
struct tagEXCEPINFO;
typedef struct tagEXCEPINFO EXCEPINFO;
struct IErrorInfo;
typedef struct IErrorInfo IErrorInfo;
struct ITypeLib;
typedef struct ITypeLib ITypeLib;
struct tagSAFEARRAYBOUND;
typedef struct tagSAFEARRAYBOUND SAFEARRAYBOUND;
struct IDispatch;
typedef struct IDispatch IDispatch;
struct tagARRAYDESC;
typedef struct tagARRAYDESC ARRAYDESC;
union tagBINDPTR;
typedef union tagBINDPTR BINDPTR;
enum tagCHANGEKIND {
    CHANGEKIND_ADDMEMBER = 0,
    CHANGEKIND_DELETEMEMBER = 1,
    CHANGEKIND_SETNAMES = 2,
    CHANGEKIND_SETDOCUMENTATION = 3,
    CHANGEKIND_GENERAL = 4,
    CHANGEKIND_INVALIDATE = 5,
    CHANGEKIND_CHANGEFAILED = 6,
    CHANGEKIND_MAX = 7
};

typedef enum tagCHANGEKIND CHANGEKIND;
struct tagCLEANLOCALSTORAGE;
typedef struct tagCLEANLOCALSTORAGE CLEANLOCALSTORAGE;
typedef CY CURRENCY;
struct tagCUSTDATA;
typedef struct tagCUSTDATA CUSTDATA;
struct tagCUSTDATAITEM;
typedef struct tagCUSTDATAITEM CUSTDATAITEM;
enum tagDESCKIND {
    DESCKIND_NONE = 0,
    DESCKIND_FUNCDESC = 1,
    DESCKIND_VARDESC = 2,
    DESCKIND_TYPECOMP = 3,
    DESCKIND_IMPLICITAPPOBJ = 4,
    DESCKIND_MAX = 5
};

typedef enum tagDESCKIND DESCKIND;
struct tagELEMDESC;
typedef struct tagELEMDESC ELEMDESC;
struct tagFUNCDESC;
typedef struct tagFUNCDESC FUNCDESC;
enum tagFUNCFLAGS {
    FUNCFLAG_FRESTRICTED = 1,
    FUNCFLAG_FSOURCE = 2,
    FUNCFLAG_FBINDABLE = 4,
    FUNCFLAG_FREQUESTEDIT = 8,
    FUNCFLAG_FDISPLAYBIND = 16,
    FUNCFLAG_FDEFAULTBIND = 32,
    FUNCFLAG_FHIDDEN = 64,
    FUNCFLAG_FUSESGETLASTERROR = 128,
    FUNCFLAG_FDEFAULTCOLLELEM = 256,
    FUNCFLAG_FUIDEFAULT = 512,
    FUNCFLAG_FNONBROWSABLE = 1024,
    FUNCFLAG_FREPLACEABLE = 2048,
    FUNCFLAG_FIMMEDIATEBIND = 4096
};

typedef enum tagFUNCFLAGS FUNCFLAGS;
enum tagFUNCKIND {
    FUNC_VIRTUAL = 0,
    FUNC_PUREVIRTUAL = 1,
    FUNC_NONVIRTUAL = 2,
    FUNC_STATIC = 3,
    FUNC_DISPATCH = 4
};

typedef enum tagFUNCKIND FUNCKIND;
typedef DWORD HREFTYPE;
struct ICreateErrorInfoVtbl;
typedef struct ICreateErrorInfoVtbl ICreateErrorInfoVtbl;
struct ICreateTypeInfo;
typedef struct ICreateTypeInfo ICreateTypeInfo;
struct ICreateTypeInfo2;
typedef struct ICreateTypeInfo2 ICreateTypeInfo2;
struct ICreateTypeInfo2Vtbl;
typedef struct ICreateTypeInfo2Vtbl ICreateTypeInfo2Vtbl;
struct ICreateTypeInfoVtbl;
typedef struct ICreateTypeInfoVtbl ICreateTypeInfoVtbl;
struct ICreateTypeLib;
typedef struct ICreateTypeLib ICreateTypeLib;
struct ICreateTypeLib2Vtbl;
typedef struct ICreateTypeLib2Vtbl ICreateTypeLib2Vtbl;
struct ICreateTypeLibVtbl;
typedef struct ICreateTypeLibVtbl ICreateTypeLibVtbl;
struct tagIDLDESC;
typedef struct tagIDLDESC IDLDESC;
struct IDispatchVtbl;
typedef struct IDispatchVtbl IDispatchVtbl;
struct IEnumVARIANT;
typedef struct IEnumVARIANT IEnumVARIANT;
struct IEnumVARIANTVtbl;
typedef struct IEnumVARIANTVtbl IEnumVARIANTVtbl;
struct IErrorInfoVtbl;
typedef struct IErrorInfoVtbl IErrorInfoVtbl;
enum tagINVOKEKIND {
    INVOKE_FUNC = 1,
    INVOKE_PROPERTYGET = 2,
    INVOKE_PROPERTYPUT = 4,
    INVOKE_PROPERTYPUTREF = 8
};

typedef enum tagINVOKEKIND INVOKEKIND;
struct IRecordInfo;
typedef struct IRecordInfo IRecordInfo;
struct IRecordInfoVtbl;
typedef struct IRecordInfoVtbl IRecordInfoVtbl;
struct ISupportErrorInfo;
typedef struct ISupportErrorInfo ISupportErrorInfo;
struct ISupportErrorInfoVtbl;
typedef struct ISupportErrorInfoVtbl ISupportErrorInfoVtbl;
struct ITypeChangeEvents;
typedef struct ITypeChangeEvents ITypeChangeEvents;
struct ITypeChangeEventsVtbl;
typedef struct ITypeChangeEventsVtbl ITypeChangeEventsVtbl;
struct ITypeComp;
typedef struct ITypeComp ITypeComp;
struct ITypeCompVtbl;
typedef struct ITypeCompVtbl ITypeCompVtbl;
struct ITypeFactory;
typedef struct ITypeFactory ITypeFactory;
struct ITypeFactoryVtbl;
typedef struct ITypeFactoryVtbl ITypeFactoryVtbl;
struct ITypeInfo2;
typedef struct ITypeInfo2 ITypeInfo2;
struct ITypeInfo2Vtbl;
typedef struct ITypeInfo2Vtbl ITypeInfo2Vtbl;
struct ITypeInfoVtbl;
typedef struct ITypeInfoVtbl ITypeInfoVtbl;
struct ITypeLib2;
typedef struct ITypeLib2 ITypeLib2;
struct ITypeLib2Vtbl;
typedef struct ITypeLib2Vtbl ITypeLib2Vtbl;
struct ITypeLibVtbl;
typedef struct ITypeLibVtbl ITypeLibVtbl;
struct ITypeMarshal;
typedef struct ITypeMarshal ITypeMarshal;
struct ITypeMarshalVtbl;
typedef struct ITypeMarshalVtbl ITypeMarshalVtbl;
enum tagLIBFLAGS {
    LIBFLAG_FRESTRICTED = 1,
    LIBFLAG_FCONTROL = 2,
    LIBFLAG_FHIDDEN = 4,
    LIBFLAG_FHASDISKIMAGE = 8
};

typedef enum tagLIBFLAGS LIBFLAGS;
typedef union tagBINDPTR *LPBINDPTR;
typedef ICreateErrorInfo *LPCREATEERRORINFO;
typedef ICreateTypeInfo *LPCREATETYPEINFO;
typedef ICreateTypeInfo2 *LPCREATETYPEINFO2;
typedef ICreateTypeLib *LPCREATETYPELIB;
typedef ICreateTypeLib2 *LPCREATETYPELIB2;
typedef struct tagCUSTDATA *LPCUSTDATA;
typedef struct tagCUSTDATAITEM *LPCUSTDATAITEM;
typedef IDispatch *LPDISPATCH;
typedef struct tagELEMDESC *LPELEMDESC;
typedef IEnumVARIANT *LPENUMVARIANT;
typedef IErrorInfo *LPERRORINFO;
typedef struct tagEXCEPINFO *LPEXCEPINFO;
typedef struct tagFUNCDESC *LPFUNCDESC;
typedef struct tagIDLDESC *LPIDLDESC;
struct tagPARAMDESC;
typedef struct tagPARAMDESC *LPPARAMDESC;
struct tagPARAMDESCEX;
typedef struct tagPARAMDESCEX *LPPARAMDESCEX;
typedef IRecordInfo *LPRECORDINFO;
typedef SAFEARRAY *LPSAFEARRAY;
typedef struct tagSAFEARRAYBOUND *LPSAFEARRAYBOUND;
typedef ISupportErrorInfo *LPSUPPORTERRORINFO;
struct tagTLIBATTR;
typedef struct tagTLIBATTR *LPTLIBATTR;
struct tagTYPEATTR;
typedef struct tagTYPEATTR *LPTYPEATTR;
typedef ITypeChangeEvents *LPTYPECHANGEEVENTS;
typedef ITypeComp *LPTYPECOMP;
typedef ITypeInfo *LPTYPEINFO;
typedef ITypeInfo2 *LPTYPEINFO2;
typedef ITypeLib *LPTYPELIB;
typedef ITypeLib2 *LPTYPELIB2;
struct tagVARDESC;
typedef struct tagVARDESC *LPVARDESC;
typedef VARIANT *LPVARIANT;
typedef VARIANT *LPVARIANTARG;
typedef DISPID MEMBERID;
typedef struct tagPARAMDESC PARAMDESC;
typedef struct tagPARAMDESCEX PARAMDESCEX;
struct _wireSAFEARRAY_UNION;
typedef struct _wireSAFEARRAY_UNION SAFEARRAYUNION;
struct _wireSAFEARR_BRECORD;
typedef struct _wireSAFEARR_BRECORD SAFEARR_BRECORD;
struct _wireSAFEARR_BSTR;
typedef struct _wireSAFEARR_BSTR SAFEARR_BSTR;
struct _wireSAFEARR_DISPATCH;
typedef struct _wireSAFEARR_DISPATCH SAFEARR_DISPATCH;
struct _wireSAFEARR_HAVEIID;
typedef struct _wireSAFEARR_HAVEIID SAFEARR_HAVEIID;
struct _wireSAFEARR_UNKNOWN;
typedef struct _wireSAFEARR_UNKNOWN SAFEARR_UNKNOWN;
struct _wireSAFEARR_VARIANT;
typedef struct _wireSAFEARR_VARIANT SAFEARR_VARIANT;
enum tagSF_TYPE {
    SF_ERROR = 10,
    SF_I1 = 16,
    SF_I2 = 2,
    SF_I4 = 3,
    SF_I8 = 20,
    SF_BSTR = 8,
    SF_UNKNOWN = 13,
    SF_DISPATCH = 9,
    SF_VARIANT = 12,
    SF_RECORD = 36,
    SF_HAVEIID = 32781
};

typedef enum tagSF_TYPE SF_TYPE;
typedef struct tagTLIBATTR TLIBATTR;
typedef struct tagTYPEATTR TYPEATTR;
struct tagTYPEDESC;
typedef struct tagTYPEDESC TYPEDESC;
enum tagTYPEFLAGS {
    TYPEFLAG_FAPPOBJECT = 1,
    TYPEFLAG_FCANCREATE = 2,
    TYPEFLAG_FLICENSED = 4,
    TYPEFLAG_FPREDECLID = 8,
    TYPEFLAG_FHIDDEN = 16,
    TYPEFLAG_FCONTROL = 32,
    TYPEFLAG_FDUAL = 64,
    TYPEFLAG_FNONEXTENSIBLE = 128,
    TYPEFLAG_FOLEAUTOMATION = 256,
    TYPEFLAG_FRESTRICTED = 512,
    TYPEFLAG_FAGGREGATABLE = 1024,
    TYPEFLAG_FREPLACEABLE = 2048,
    TYPEFLAG_FDISPATCHABLE = 4096,
    TYPEFLAG_FREVERSEBIND = 8192
};

typedef enum tagTYPEFLAGS TYPEFLAGS;
enum tagTYPEKIND {
    TKIND_ENUM = 0,
    TKIND_RECORD = 1,
    TKIND_MODULE = 2,
    TKIND_INTERFACE = 3,
    TKIND_DISPATCH = 4,
    TKIND_COCLASS = 5,
    TKIND_ALIAS = 6,
    TKIND_UNION = 7,
    TKIND_MAX = 8
};

typedef enum tagTYPEKIND TYPEKIND;
typedef struct tagVARDESC VARDESC;
enum tagVARFLAGS {
    VARFLAG_FREADONLY = 1,
    VARFLAG_FSOURCE = 2,
    VARFLAG_FBINDABLE = 4,
    VARFLAG_FREQUESTEDIT = 8,
    VARFLAG_FDISPLAYBIND = 16,
    VARFLAG_FDEFAULTBIND = 32,
    VARFLAG_FHIDDEN = 64,
    VARFLAG_FRESTRICTED = 128,
    VARFLAG_FDEFAULTCOLLELEM = 256,
    VARFLAG_FUIDEFAULT = 512,
    VARFLAG_FNONBROWSABLE = 1024,
    VARFLAG_FREPLACEABLE = 2048,
    VARFLAG_FIMMEDIATEBIND = 4096
};

typedef enum tagVARFLAGS VARFLAGS;
enum tagVARKIND {
    VAR_PERINSTANCE = 0,
    VAR_STATIC = 1,
    VAR_CONST = 2,
    VAR_DISPATCH = 3
};

typedef enum tagVARKIND VARKIND;
struct _wireBRECORD;
typedef struct _wireBRECORD *wireBRECORD;
struct _wireSAFEARRAY;
typedef struct _wireSAFEARRAY *wireSAFEARRAY;
typedef wireSAFEARRAY *wirePSAFEARRAY;
struct _wireVARIANT;
typedef struct _wireVARIANT *wireVARIANT;
struct ICreateErrorInfo {
    struct ICreateErrorInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ICreateErrorInfoVtbl {
    HRESULT (*QueryInterface)(ICreateErrorInfo *, const IID *const, void **);
    ULONG (*AddRef)(ICreateErrorInfo *);
    ULONG (*Release)(ICreateErrorInfo *);
    HRESULT (*SetGUID)(ICreateErrorInfo *, const GUID *const);
    HRESULT (*SetSource)(ICreateErrorInfo *, LPOLESTR);
    HRESULT (*SetDescription)(ICreateErrorInfo *, LPOLESTR);
    HRESULT (*SetHelpFile)(ICreateErrorInfo *, LPOLESTR);
    HRESULT (*SetHelpContext)(ICreateErrorInfo *, DWORD);
} __attribute__((packed, aligned(4)));

struct ICreateTypeInfo {
    struct ICreateTypeInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ICreateTypeInfo2 {
    struct ICreateTypeInfo2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ICreateTypeInfo2Vtbl {
    HRESULT (*QueryInterface)(ICreateTypeInfo2 *, const IID *const, void **);
    ULONG (*AddRef)(ICreateTypeInfo2 *);
    ULONG (*Release)(ICreateTypeInfo2 *);
    HRESULT (*SetGuid)(ICreateTypeInfo2 *, const GUID *const);
    HRESULT (*SetTypeFlags)(ICreateTypeInfo2 *, UINT);
    HRESULT (*SetDocString)(ICreateTypeInfo2 *, LPOLESTR);
    HRESULT (*SetHelpContext)(ICreateTypeInfo2 *, DWORD);
    HRESULT (*SetVersion)(ICreateTypeInfo2 *, WORD, WORD);
    HRESULT (*AddRefTypeInfo)(ICreateTypeInfo2 *, ITypeInfo *, HREFTYPE *);
    HRESULT (*AddFuncDesc)(ICreateTypeInfo2 *, UINT, FUNCDESC *);
    HRESULT (*AddImplType)(ICreateTypeInfo2 *, UINT, HREFTYPE);
    HRESULT (*SetImplTypeFlags)(ICreateTypeInfo2 *, UINT, INT);
    HRESULT (*SetAlignment)(ICreateTypeInfo2 *, WORD);
    HRESULT (*SetSchema)(ICreateTypeInfo2 *, LPOLESTR);
    HRESULT (*AddVarDesc)(ICreateTypeInfo2 *, UINT, VARDESC *);
    HRESULT (*SetFuncAndParamNames)(ICreateTypeInfo2 *, UINT, LPOLESTR *, UINT);
    HRESULT (*SetVarName)(ICreateTypeInfo2 *, UINT, LPOLESTR);
    HRESULT (*SetTypeDescAlias)(ICreateTypeInfo2 *, TYPEDESC *);
    HRESULT (*DefineFuncAsDllEntry)(ICreateTypeInfo2 *, UINT, LPOLESTR, LPOLESTR);
    HRESULT (*SetFuncDocString)(ICreateTypeInfo2 *, UINT, LPOLESTR);
    HRESULT (*SetVarDocString)(ICreateTypeInfo2 *, UINT, LPOLESTR);
    HRESULT (*SetFuncHelpContext)(ICreateTypeInfo2 *, UINT, DWORD);
    HRESULT (*SetVarHelpContext)(ICreateTypeInfo2 *, UINT, DWORD);
    HRESULT (*SetMops)(ICreateTypeInfo2 *, UINT, BSTR);
    HRESULT (*SetTypeIdldesc)(ICreateTypeInfo2 *, IDLDESC *);
    HRESULT (*LayOut)(ICreateTypeInfo2 *);
    HRESULT (*DeleteFuncDesc)(ICreateTypeInfo2 *, UINT);
    HRESULT (*DeleteFuncDescByMemId)(ICreateTypeInfo2 *, MEMBERID, INVOKEKIND);
    HRESULT (*DeleteVarDesc)(ICreateTypeInfo2 *, UINT);
    HRESULT (*DeleteVarDescByMemId)(ICreateTypeInfo2 *, MEMBERID);
    HRESULT (*DeleteImplType)(ICreateTypeInfo2 *, UINT);
    HRESULT (*SetCustData)(ICreateTypeInfo2 *, const GUID *const, VARIANT *);
    HRESULT (*SetFuncCustData)(ICreateTypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*SetParamCustData)(ICreateTypeInfo2 *, UINT, UINT, const GUID *const, VARIANT *);
    HRESULT (*SetVarCustData)(ICreateTypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*SetImplTypeCustData)(ICreateTypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*SetHelpStringContext)(ICreateTypeInfo2 *, ULONG);
    HRESULT (*SetFuncHelpStringContext)(ICreateTypeInfo2 *, UINT, ULONG);
    HRESULT (*SetVarHelpStringContext)(ICreateTypeInfo2 *, UINT, ULONG);
    HRESULT (*Invalidate)(ICreateTypeInfo2 *);
    HRESULT (*SetName)(ICreateTypeInfo2 *, LPOLESTR);
} __attribute__((packed, aligned(4)));

struct ICreateTypeInfoVtbl {
    HRESULT (*QueryInterface)(ICreateTypeInfo *, const IID *const, void **);
    ULONG (*AddRef)(ICreateTypeInfo *);
    ULONG (*Release)(ICreateTypeInfo *);
    HRESULT (*SetGuid)(ICreateTypeInfo *, const GUID *const);
    HRESULT (*SetTypeFlags)(ICreateTypeInfo *, UINT);
    HRESULT (*SetDocString)(ICreateTypeInfo *, LPOLESTR);
    HRESULT (*SetHelpContext)(ICreateTypeInfo *, DWORD);
    HRESULT (*SetVersion)(ICreateTypeInfo *, WORD, WORD);
    HRESULT (*AddRefTypeInfo)(ICreateTypeInfo *, ITypeInfo *, HREFTYPE *);
    HRESULT (*AddFuncDesc)(ICreateTypeInfo *, UINT, FUNCDESC *);
    HRESULT (*AddImplType)(ICreateTypeInfo *, UINT, HREFTYPE);
    HRESULT (*SetImplTypeFlags)(ICreateTypeInfo *, UINT, INT);
    HRESULT (*SetAlignment)(ICreateTypeInfo *, WORD);
    HRESULT (*SetSchema)(ICreateTypeInfo *, LPOLESTR);
    HRESULT (*AddVarDesc)(ICreateTypeInfo *, UINT, VARDESC *);
    HRESULT (*SetFuncAndParamNames)(ICreateTypeInfo *, UINT, LPOLESTR *, UINT);
    HRESULT (*SetVarName)(ICreateTypeInfo *, UINT, LPOLESTR);
    HRESULT (*SetTypeDescAlias)(ICreateTypeInfo *, TYPEDESC *);
    HRESULT (*DefineFuncAsDllEntry)(ICreateTypeInfo *, UINT, LPOLESTR, LPOLESTR);
    HRESULT (*SetFuncDocString)(ICreateTypeInfo *, UINT, LPOLESTR);
    HRESULT (*SetVarDocString)(ICreateTypeInfo *, UINT, LPOLESTR);
    HRESULT (*SetFuncHelpContext)(ICreateTypeInfo *, UINT, DWORD);
    HRESULT (*SetVarHelpContext)(ICreateTypeInfo *, UINT, DWORD);
    HRESULT (*SetMops)(ICreateTypeInfo *, UINT, BSTR);
    HRESULT (*SetTypeIdldesc)(ICreateTypeInfo *, IDLDESC *);
    HRESULT (*LayOut)(ICreateTypeInfo *);
} __attribute__((packed, aligned(4)));

struct ICreateTypeLib {
    struct ICreateTypeLibVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ICreateTypeLib2 {
    struct ICreateTypeLib2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ICreateTypeLib2Vtbl {
    HRESULT (*QueryInterface)(ICreateTypeLib2 *, const IID *const, void **);
    ULONG (*AddRef)(ICreateTypeLib2 *);
    ULONG (*Release)(ICreateTypeLib2 *);
    HRESULT (*CreateTypeInfo)(ICreateTypeLib2 *, LPOLESTR, TYPEKIND, ICreateTypeInfo **);
    HRESULT (*SetName)(ICreateTypeLib2 *, LPOLESTR);
    HRESULT (*SetVersion)(ICreateTypeLib2 *, WORD, WORD);
    HRESULT (*SetGuid)(ICreateTypeLib2 *, const GUID *const);
    HRESULT (*SetDocString)(ICreateTypeLib2 *, LPOLESTR);
    HRESULT (*SetHelpFileName)(ICreateTypeLib2 *, LPOLESTR);
    HRESULT (*SetHelpContext)(ICreateTypeLib2 *, DWORD);
    HRESULT (*SetLcid)(ICreateTypeLib2 *, LCID);
    HRESULT (*SetLibFlags)(ICreateTypeLib2 *, UINT);
    HRESULT (*SaveAllChanges)(ICreateTypeLib2 *);
    HRESULT (*DeleteTypeInfo)(ICreateTypeLib2 *, LPOLESTR);
    HRESULT (*SetCustData)(ICreateTypeLib2 *, const GUID *const, VARIANT *);
    HRESULT (*SetHelpStringContext)(ICreateTypeLib2 *, ULONG);
    HRESULT (*SetHelpStringDll)(ICreateTypeLib2 *, LPOLESTR);
} __attribute__((packed, aligned(4)));

struct ICreateTypeLibVtbl {
    HRESULT (*QueryInterface)(ICreateTypeLib *, const IID *const, void **);
    ULONG (*AddRef)(ICreateTypeLib *);
    ULONG (*Release)(ICreateTypeLib *);
    HRESULT (*CreateTypeInfo)(ICreateTypeLib *, LPOLESTR, TYPEKIND, ICreateTypeInfo **);
    HRESULT (*SetName)(ICreateTypeLib *, LPOLESTR);
    HRESULT (*SetVersion)(ICreateTypeLib *, WORD, WORD);
    HRESULT (*SetGuid)(ICreateTypeLib *, const GUID *const);
    HRESULT (*SetDocString)(ICreateTypeLib *, LPOLESTR);
    HRESULT (*SetHelpFileName)(ICreateTypeLib *, LPOLESTR);
    HRESULT (*SetHelpContext)(ICreateTypeLib *, DWORD);
    HRESULT (*SetLcid)(ICreateTypeLib *, LCID);
    HRESULT (*SetLibFlags)(ICreateTypeLib *, UINT);
    HRESULT (*SaveAllChanges)(ICreateTypeLib *);
} __attribute__((packed, aligned(4)));

struct IDispatch {
    struct IDispatchVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IDispatchVtbl {
    HRESULT (*QueryInterface)(IDispatch *, const IID *const, void **);
    ULONG (*AddRef)(IDispatch *);
    ULONG (*Release)(IDispatch *);
    HRESULT (*GetTypeInfoCount)(IDispatch *, UINT *);
    HRESULT (*GetTypeInfo)(IDispatch *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IDispatch *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IDispatch *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
} __attribute__((packed, aligned(4)));

struct IEnumVARIANT {
    struct IEnumVARIANTVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumVARIANTVtbl {
    HRESULT (*QueryInterface)(IEnumVARIANT *, const IID *const, void **);
    ULONG (*AddRef)(IEnumVARIANT *);
    ULONG (*Release)(IEnumVARIANT *);
    HRESULT (*Next)(IEnumVARIANT *, ULONG, VARIANT *, ULONG *);
    HRESULT (*Skip)(IEnumVARIANT *, ULONG);
    HRESULT (*Reset)(IEnumVARIANT *);
    HRESULT (*Clone)(IEnumVARIANT *, IEnumVARIANT **);
} __attribute__((packed, aligned(4)));

struct IErrorInfo {
    struct IErrorInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IErrorInfoVtbl {
    HRESULT (*QueryInterface)(IErrorInfo *, const IID *const, void **);
    ULONG (*AddRef)(IErrorInfo *);
    ULONG (*Release)(IErrorInfo *);
    HRESULT (*GetGUID)(IErrorInfo *, GUID *);
    HRESULT (*GetSource)(IErrorInfo *, BSTR *);
    HRESULT (*GetDescription)(IErrorInfo *, BSTR *);
    HRESULT (*GetHelpFile)(IErrorInfo *, BSTR *);
    HRESULT (*GetHelpContext)(IErrorInfo *, DWORD *);
} __attribute__((packed, aligned(4)));

struct IRecordInfo {
    struct IRecordInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRecordInfoVtbl {
    HRESULT (*QueryInterface)(IRecordInfo *, const IID *const, void **);
    ULONG (*AddRef)(IRecordInfo *);
    ULONG (*Release)(IRecordInfo *);
    HRESULT (*RecordInit)(IRecordInfo *, PVOID);
    HRESULT (*RecordClear)(IRecordInfo *, PVOID);
    HRESULT (*RecordCopy)(IRecordInfo *, PVOID, PVOID);
    HRESULT (*GetGuid)(IRecordInfo *, GUID *);
    HRESULT (*GetName)(IRecordInfo *, BSTR *);
    HRESULT (*GetSize)(IRecordInfo *, ULONG *);
    HRESULT (*GetTypeInfo)(IRecordInfo *, ITypeInfo **);
    HRESULT (*GetField)(IRecordInfo *, PVOID, LPCOLESTR, VARIANT *);
    HRESULT (*GetFieldNoCopy)(IRecordInfo *, PVOID, LPCOLESTR, VARIANT *, PVOID *);
    HRESULT (*PutField)(IRecordInfo *, ULONG, PVOID, LPCOLESTR, VARIANT *);
    HRESULT (*PutFieldNoCopy)(IRecordInfo *, ULONG, PVOID, LPCOLESTR, VARIANT *);
    HRESULT (*GetFieldNames)(IRecordInfo *, ULONG *, BSTR *);
    BOOL (*IsMatchingType)(IRecordInfo *, IRecordInfo *);
    PVOID (*RecordCreate)(IRecordInfo *);
    HRESULT (*RecordCreateCopy)(IRecordInfo *, PVOID, PVOID *);
    HRESULT (*RecordDestroy)(IRecordInfo *, PVOID);
} __attribute__((packed, aligned(4)));

struct ISupportErrorInfo {
    struct ISupportErrorInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ISupportErrorInfoVtbl {
    HRESULT (*QueryInterface)(ISupportErrorInfo *, const IID *const, void **);
    ULONG (*AddRef)(ISupportErrorInfo *);
    ULONG (*Release)(ISupportErrorInfo *);
    HRESULT (*InterfaceSupportsErrorInfo)(ISupportErrorInfo *, const IID *const);
} __attribute__((packed, aligned(4)));

struct ITypeChangeEvents {
    struct ITypeChangeEventsVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeChangeEventsVtbl {
    HRESULT (*QueryInterface)(ITypeChangeEvents *, const IID *const, void **);
    ULONG (*AddRef)(ITypeChangeEvents *);
    ULONG (*Release)(ITypeChangeEvents *);
    HRESULT (*RequestTypeChange)(ITypeChangeEvents *, CHANGEKIND, ITypeInfo *, LPOLESTR, INT *);
    HRESULT (*AfterTypeChange)(ITypeChangeEvents *, CHANGEKIND, ITypeInfo *, LPOLESTR);
} __attribute__((packed, aligned(4)));

struct ITypeComp {
    struct ITypeCompVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeCompVtbl {
    HRESULT (*QueryInterface)(ITypeComp *, const IID *const, void **);
    ULONG (*AddRef)(ITypeComp *);
    ULONG (*Release)(ITypeComp *);
    HRESULT (*Bind)(ITypeComp *, LPOLESTR, ULONG, WORD, ITypeInfo **, DESCKIND *, BINDPTR *);
    HRESULT (*BindType)(ITypeComp *, LPOLESTR, ULONG, ITypeInfo **, ITypeComp **);
} __attribute__((packed, aligned(4)));

struct ITypeFactory {
    struct ITypeFactoryVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeFactoryVtbl {
    HRESULT (*QueryInterface)(ITypeFactory *, const IID *const, void **);
    ULONG (*AddRef)(ITypeFactory *);
    ULONG (*Release)(ITypeFactory *);
    HRESULT (*CreateFromTypeInfo)(ITypeFactory *, ITypeInfo *, const IID *const, IUnknown **);
} __attribute__((packed, aligned(4)));

struct ITypeInfo {
    struct ITypeInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeInfo2 {
    struct ITypeInfo2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeInfo2Vtbl {
    HRESULT (*QueryInterface)(ITypeInfo2 *, const IID *const, void **);
    ULONG (*AddRef)(ITypeInfo2 *);
    ULONG (*Release)(ITypeInfo2 *);
    HRESULT (*GetTypeAttr)(ITypeInfo2 *, TYPEATTR **);
    HRESULT (*GetTypeComp)(ITypeInfo2 *, ITypeComp **);
    HRESULT (*GetFuncDesc)(ITypeInfo2 *, UINT, FUNCDESC **);
    HRESULT (*GetVarDesc)(ITypeInfo2 *, UINT, VARDESC **);
    HRESULT (*GetNames)(ITypeInfo2 *, MEMBERID, BSTR *, UINT, UINT *);
    HRESULT (*GetRefTypeOfImplType)(ITypeInfo2 *, UINT, HREFTYPE *);
    HRESULT (*GetImplTypeFlags)(ITypeInfo2 *, UINT, INT *);
    HRESULT (*GetIDsOfNames)(ITypeInfo2 *, LPOLESTR *, UINT, MEMBERID *);
    HRESULT (*Invoke)(ITypeInfo2 *, PVOID, MEMBERID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*GetDocumentation)(ITypeInfo2 *, MEMBERID, BSTR *, BSTR *, DWORD *, BSTR *);
    HRESULT (*GetDllEntry)(ITypeInfo2 *, MEMBERID, INVOKEKIND, BSTR *, BSTR *, WORD *);
    HRESULT (*GetRefTypeInfo)(ITypeInfo2 *, HREFTYPE, ITypeInfo **);
    HRESULT (*AddressOfMember)(ITypeInfo2 *, MEMBERID, INVOKEKIND, PVOID *);
    HRESULT (*CreateInstance)(ITypeInfo2 *, IUnknown *, const IID *const, PVOID *);
    HRESULT (*GetMops)(ITypeInfo2 *, MEMBERID, BSTR *);
    HRESULT (*GetContainingTypeLib)(ITypeInfo2 *, ITypeLib **, UINT *);
    void (*ReleaseTypeAttr)(ITypeInfo2 *, TYPEATTR *);
    void (*ReleaseFuncDesc)(ITypeInfo2 *, FUNCDESC *);
    void (*ReleaseVarDesc)(ITypeInfo2 *, VARDESC *);
    HRESULT (*GetTypeKind)(ITypeInfo2 *, TYPEKIND *);
    HRESULT (*GetTypeFlags)(ITypeInfo2 *, ULONG *);
    HRESULT (*GetFuncIndexOfMemId)(ITypeInfo2 *, MEMBERID, INVOKEKIND, UINT *);
    HRESULT (*GetVarIndexOfMemId)(ITypeInfo2 *, MEMBERID, UINT *);
    HRESULT (*GetCustData)(ITypeInfo2 *, const GUID *const, VARIANT *);
    HRESULT (*GetFuncCustData)(ITypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*GetParamCustData)(ITypeInfo2 *, UINT, UINT, const GUID *const, VARIANT *);
    HRESULT (*GetVarCustData)(ITypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*GetImplTypeCustData)(ITypeInfo2 *, UINT, const GUID *const, VARIANT *);
    HRESULT (*GetDocumentation2)(ITypeInfo2 *, MEMBERID, LCID, BSTR *, DWORD *, BSTR *);
    HRESULT (*GetAllCustData)(ITypeInfo2 *, CUSTDATA *);
    HRESULT (*GetAllFuncCustData)(ITypeInfo2 *, UINT, CUSTDATA *);
    HRESULT (*GetAllParamCustData)(ITypeInfo2 *, UINT, UINT, CUSTDATA *);
    HRESULT (*GetAllVarCustData)(ITypeInfo2 *, UINT, CUSTDATA *);
    HRESULT (*GetAllImplTypeCustData)(ITypeInfo2 *, UINT, CUSTDATA *);
} __attribute__((packed, aligned(4)));

struct ITypeInfoVtbl {
    HRESULT (*QueryInterface)(ITypeInfo *, const IID *const, void **);
    ULONG (*AddRef)(ITypeInfo *);
    ULONG (*Release)(ITypeInfo *);
    HRESULT (*GetTypeAttr)(ITypeInfo *, TYPEATTR **);
    HRESULT (*GetTypeComp)(ITypeInfo *, ITypeComp **);
    HRESULT (*GetFuncDesc)(ITypeInfo *, UINT, FUNCDESC **);
    HRESULT (*GetVarDesc)(ITypeInfo *, UINT, VARDESC **);
    HRESULT (*GetNames)(ITypeInfo *, MEMBERID, BSTR *, UINT, UINT *);
    HRESULT (*GetRefTypeOfImplType)(ITypeInfo *, UINT, HREFTYPE *);
    HRESULT (*GetImplTypeFlags)(ITypeInfo *, UINT, INT *);
    HRESULT (*GetIDsOfNames)(ITypeInfo *, LPOLESTR *, UINT, MEMBERID *);
    HRESULT (*Invoke)(ITypeInfo *, PVOID, MEMBERID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*GetDocumentation)(ITypeInfo *, MEMBERID, BSTR *, BSTR *, DWORD *, BSTR *);
    HRESULT (*GetDllEntry)(ITypeInfo *, MEMBERID, INVOKEKIND, BSTR *, BSTR *, WORD *);
    HRESULT (*GetRefTypeInfo)(ITypeInfo *, HREFTYPE, ITypeInfo **);
    HRESULT (*AddressOfMember)(ITypeInfo *, MEMBERID, INVOKEKIND, PVOID *);
    HRESULT (*CreateInstance)(ITypeInfo *, IUnknown *, const IID *const, PVOID *);
    HRESULT (*GetMops)(ITypeInfo *, MEMBERID, BSTR *);
    HRESULT (*GetContainingTypeLib)(ITypeInfo *, ITypeLib **, UINT *);
    void (*ReleaseTypeAttr)(ITypeInfo *, TYPEATTR *);
    void (*ReleaseFuncDesc)(ITypeInfo *, FUNCDESC *);
    void (*ReleaseVarDesc)(ITypeInfo *, VARDESC *);
} __attribute__((packed, aligned(4)));

struct ITypeLib {
    struct ITypeLibVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeLib2 {
    struct ITypeLib2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeLib2Vtbl {
    HRESULT (*QueryInterface)(ITypeLib2 *, const IID *const, void **);
    ULONG (*AddRef)(ITypeLib2 *);
    ULONG (*Release)(ITypeLib2 *);
    UINT (*GetTypeInfoCount)(ITypeLib2 *);
    HRESULT (*GetTypeInfo)(ITypeLib2 *, UINT, ITypeInfo **);
    HRESULT (*GetTypeInfoType)(ITypeLib2 *, UINT, TYPEKIND *);
    HRESULT (*GetTypeInfoOfGuid)(ITypeLib2 *, const GUID *const, ITypeInfo **);
    HRESULT (*GetLibAttr)(ITypeLib2 *, TLIBATTR **);
    HRESULT (*GetTypeComp)(ITypeLib2 *, ITypeComp **);
    HRESULT (*GetDocumentation)(ITypeLib2 *, INT, BSTR *, BSTR *, DWORD *, BSTR *);
    HRESULT (*IsName)(ITypeLib2 *, LPOLESTR, ULONG, BOOL *);
    HRESULT (*FindName)(ITypeLib2 *, LPOLESTR, ULONG, ITypeInfo **, MEMBERID *, USHORT *);
    void (*ReleaseTLibAttr)(ITypeLib2 *, TLIBATTR *);
    HRESULT (*GetCustData)(ITypeLib2 *, const GUID *const, VARIANT *);
    HRESULT (*GetLibStatistics)(ITypeLib2 *, ULONG *, ULONG *);
    HRESULT (*GetDocumentation2)(ITypeLib2 *, INT, LCID, BSTR *, DWORD *, BSTR *);
    HRESULT (*GetAllCustData)(ITypeLib2 *, CUSTDATA *);
} __attribute__((packed, aligned(4)));

struct ITypeLibVtbl {
    HRESULT (*QueryInterface)(ITypeLib *, const IID *const, void **);
    ULONG (*AddRef)(ITypeLib *);
    ULONG (*Release)(ITypeLib *);
    UINT (*GetTypeInfoCount)(ITypeLib *);
    HRESULT (*GetTypeInfo)(ITypeLib *, UINT, ITypeInfo **);
    HRESULT (*GetTypeInfoType)(ITypeLib *, UINT, TYPEKIND *);
    HRESULT (*GetTypeInfoOfGuid)(ITypeLib *, const GUID *const, ITypeInfo **);
    HRESULT (*GetLibAttr)(ITypeLib *, TLIBATTR **);
    HRESULT (*GetTypeComp)(ITypeLib *, ITypeComp **);
    HRESULT (*GetDocumentation)(ITypeLib *, INT, BSTR *, BSTR *, DWORD *, BSTR *);
    HRESULT (*IsName)(ITypeLib *, LPOLESTR, ULONG, BOOL *);
    HRESULT (*FindName)(ITypeLib *, LPOLESTR, ULONG, ITypeInfo **, MEMBERID *, USHORT *);
    void (*ReleaseTLibAttr)(ITypeLib *, TLIBATTR *);
} __attribute__((packed, aligned(4)));

struct ITypeMarshal {
    struct ITypeMarshalVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ITypeMarshalVtbl {
    HRESULT (*QueryInterface)(ITypeMarshal *, const IID *const, void **);
    ULONG (*AddRef)(ITypeMarshal *);
    ULONG (*Release)(ITypeMarshal *);
    HRESULT (*Size)(ITypeMarshal *, PVOID, DWORD, PVOID, ULONG *);
    HRESULT (*Marshal)(ITypeMarshal *, PVOID, DWORD, PVOID, ULONG, BYTE *, ULONG *);
    HRESULT (*Unmarshal)(ITypeMarshal *, PVOID, DWORD, ULONG, BYTE *, ULONG *);
    HRESULT (*Free)(ITypeMarshal *, PVOID);
} __attribute__((packed, aligned(4)));

struct _wireBRECORD {
    ULONG fFlags;
    ULONG clSize;
    IRecordInfo *pRecInfo;
    byte *pRecord;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_BSTR {
    ULONG Size;
    wireBSTR *aBstr;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_UNKNOWN {
    ULONG Size;
    IUnknown **apUnknown;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_DISPATCH {
    ULONG Size;
    IDispatch **apDispatch;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_VARIANT {
    ULONG Size;
    wireVARIANT *aVariant;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_BRECORD {
    ULONG Size;
    wireBRECORD *aRecord;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARR_HAVEIID {
    ULONG Size;
    IUnknown **apUnknown;
    IID iid;
} __attribute__((packed, aligned(4)));

union __MIDL_IOleAutomationTypes_0001;
union __MIDL_IOleAutomationTypes_0001 {
    SAFEARR_BSTR BstrStr;
    SAFEARR_UNKNOWN UnknownStr;
    SAFEARR_DISPATCH DispatchStr;
    SAFEARR_VARIANT VariantStr;
    SAFEARR_BRECORD RecordStr;
    SAFEARR_HAVEIID HaveIidStr;
    BYTE_SIZEDARR ByteStr;
    WORD_SIZEDARR WordStr;
    DWORD_SIZEDARR LongStr;
    HYPER_SIZEDARR HyperStr;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARRAY_UNION {
    ULONG sfType;
    union __MIDL_IOleAutomationTypes_0001 u;
} __attribute__((packed, aligned(4)));

struct tagSAFEARRAYBOUND {
    ULONG cElements;
    LONG lLbound;
} __attribute__((packed, aligned(4)));

struct _wireSAFEARRAY {
    USHORT cDims;
    USHORT fFeatures;
    ULONG cbElements;
    ULONG cLocks;
    SAFEARRAYUNION uArrayStructs;
    SAFEARRAYBOUND rgsabound[1];
} __attribute__((packed, aligned(4)));

struct _wireVARIANT {
    DWORD clSize;
    DWORD rpcReserved;
    USHORT vt;
    USHORT wReserved1;
    USHORT wReserved2;
    USHORT wReserved3;
    union {
        LONG lVal;
        BYTE bVal;
        SHORT iVal;
        FLOAT fltVal;
        DOUBLE dblVal;
        VARIANT_BOOL boolVal;
        SCODE scode;
        CY cyVal;
        DATE date;
        wireBSTR bstrVal;
        IUnknown *punkVal;
        IDispatch *pdispVal;
        wireSAFEARRAY parray;
        wireBRECORD brecVal;
        BYTE *pbVal;
        SHORT *piVal;
        LONG *plVal;
        FLOAT *pfltVal;
        DOUBLE *pdblVal;
        VARIANT_BOOL *pboolVal;
        SCODE *pscode;
        CY *pcyVal;
        DATE *pdate;
        wireBSTR *pbstrVal;
        IUnknown **ppunkVal;
        IDispatch **ppdispVal;
        wireSAFEARRAY *pparray;
        wireVARIANT *pvarVal;
        CHAR cVal;
        USHORT uiVal;
        ULONG ulVal;
        INT intVal;
        UINT uintVal;
        DECIMAL decVal;
        DECIMAL *pdecVal;
        CHAR *pcVal;
        USHORT *puiVal;
        ULONG *pulVal;
        INT *pintVal;
        UINT *puintVal;
    };
} __attribute__((packed, aligned(8)));

struct tagTYPEDESC {
    union {
        struct tagTYPEDESC *lptdesc;
        struct tagARRAYDESC *lpadesc;
        HREFTYPE hreftype;
    };
    VARTYPE vt;
} __attribute__((packed, aligned(4)));

struct tagARRAYDESC {
    TYPEDESC tdescElem;
    USHORT cDims;
    SAFEARRAYBOUND rgbounds[1];
} __attribute__((packed, aligned(4)));

union tagBINDPTR {
    FUNCDESC *lpfuncdesc;
    VARDESC *lpvardesc;
    ITypeComp *lptcomp;
} __attribute__((packed, aligned(4)));

struct tagCLEANLOCALSTORAGE {
    IUnknown *pInterface;
    PVOID pStorage;
    DWORD flags;
} __attribute__((packed, aligned(4)));

struct tagCUSTDATA {
    DWORD cCustData;
    LPCUSTDATAITEM prgCustData;
} __attribute__((packed, aligned(4)));

struct __tagBRECORD;
struct __tagBRECORD {
    PVOID pvRecord;
    IRecordInfo *pRecInfo;
} __attribute__((packed, aligned(4)));

struct __tagVARIANT;
struct __tagVARIANT {
    VARTYPE vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    union {
        LONG lVal;
        BYTE bVal;
        SHORT iVal;
        FLOAT fltVal;
        DOUBLE dblVal;
        VARIANT_BOOL boolVal;
        SCODE scode;
        CY cyVal;
        DATE date;
        BSTR bstrVal;
        IUnknown *punkVal;
        IDispatch *pdispVal;
        SAFEARRAY *parray;
        BYTE *pbVal;
        SHORT *piVal;
        LONG *plVal;
        FLOAT *pfltVal;
        DOUBLE *pdblVal;
        VARIANT_BOOL *pboolVal;
        SCODE *pscode;
        CY *pcyVal;
        DATE *pdate;
        BSTR *pbstrVal;
        IUnknown **ppunkVal;
        IDispatch **ppdispVal;
        SAFEARRAY **pparray;
        VARIANT *pvarVal;
        PVOID byref;
        CHAR cVal;
        USHORT uiVal;
        ULONG ulVal;
        INT intVal;
        UINT uintVal;
        DECIMAL *pdecVal;
        CHAR *pcVal;
        USHORT *puiVal;
        ULONG *pulVal;
        INT *pintVal;
        UINT *puintVal;
        struct __tagBRECORD brecVal;
    } n3;
} __attribute__((packed, aligned(8)));

struct tagVARIANT {
    union {
        struct __tagVARIANT n2;
        DECIMAL decVal;
    } n1;
} __attribute__((packed, aligned(8)));

struct tagCUSTDATAITEM {
    GUID guid;
    VARIANTARG varValue;
} __attribute__((packed, aligned(8)));

struct tagDISPPARAMS {
    VARIANTARG *rgvarg;
    DISPID *rgdispidNamedArgs;
    UINT cArgs;
    UINT cNamedArgs;
} __attribute__((packed, aligned(4)));

struct tagIDLDESC {
    ULONG dwReserved;
    USHORT wIDLFlags;
} __attribute__((packed, aligned(4)));

struct tagPARAMDESC {
    LPPARAMDESCEX pparamdescex;
    USHORT wParamFlags;
} __attribute__((packed, aligned(4)));

struct tagELEMDESC {
    TYPEDESC tdesc;
    union {
        IDLDESC idldesc;
        PARAMDESC paramdesc;
    };
} __attribute__((packed, aligned(4)));

struct tagEXCEPINFO {
    WORD wCode;
    WORD wReserved;
    BSTR bstrSource;
    BSTR bstrDescription;
    BSTR bstrHelpFile;
    DWORD dwHelpContext;
    PVOID pvReserved;
    HRESULT (*pfnDeferredFillIn)(struct tagEXCEPINFO *);
    SCODE scode;
} __attribute__((packed, aligned(4)));

struct tagFUNCDESC {
    MEMBERID memid;
    SCODE *lprgscode;
    ELEMDESC *lprgelemdescParam;
    FUNCKIND funckind;
    INVOKEKIND invkind;
    CALLCONV callconv;
    SHORT cParams;
    SHORT cParamsOpt;
    SHORT oVft;
    SHORT cScodes;
    ELEMDESC elemdescFunc;
    WORD wFuncFlags;
} __attribute__((packed, aligned(4)));

struct tagPARAMDESCEX {
    ULONG cBytes;
    VARIANTARG varDefaultValue;
} __attribute__((packed, aligned(8)));

struct tagSAFEARRAY {
    USHORT cDims;
    USHORT fFeatures;
    ULONG cbElements;
    ULONG cLocks;
    PVOID pvData;
    SAFEARRAYBOUND rgsabound[1];
} __attribute__((packed, aligned(4)));

struct tagTLIBATTR {
    GUID guid;
    LCID lcid;
    SYSKIND syskind;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    WORD wLibFlags;
} __attribute__((packed, aligned(4)));

struct tagTYPEATTR {
    GUID guid;
    LCID lcid;
    DWORD dwReserved;
    MEMBERID memidConstructor;
    MEMBERID memidDestructor;
    LPOLESTR lpstrSchema;
    ULONG cbSizeInstance;
    TYPEKIND typekind;
    WORD cFuncs;
    WORD cVars;
    WORD cImplTypes;
    WORD cbSizeVft;
    WORD cbAlignment;
    WORD wTypeFlags;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    TYPEDESC tdescAlias;
    IDLDESC idldescType;
} __attribute__((packed, aligned(4)));

struct tagVARDESC {
    MEMBERID memid;
    LPOLESTR lpstrSchema;
    union {
        ULONG oInst;
        VARIANT *lpvarValue;
    };
    ELEMDESC elemdescVar;
    WORD wVarFlags;
    VARKIND varkind;
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

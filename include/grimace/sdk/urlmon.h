#ifndef GRIMACE_SDK_URLMON_H
#define GRIMACE_SDK_URLMON_H

#include <grimace/sdk/msxml.h>
#include <grimace/sdk/objbase.h>
#include <grimace/sdk/servprov.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

HRESULT CoInternetCombineUrl(LPCWSTR pwzBaseUrl, LPCWSTR pwzRelativeUrl, DWORD dwCombineFlags, LPWSTR pszResult, DWORD cchResult, DWORD *pcchResult, DWORD dwReserved);
HRESULT CoInternetCompareUrl(LPCWSTR pwzUrl1, LPCWSTR pwzUrl2, DWORD dwFlags);
struct IInternetSecurityManager;
typedef struct IInternetSecurityManager IInternetSecurityManager;
/**
 * Creates an Internet security manager.
 *
 * The service provider allows delegation. The reserved parameter must be
 * zero.
 *
 * @param pSP Service provider for delegation.
 * @param ppSM Receives the IInternetSecurityManager interface.
 * @param dwReserved Reserved; set to zero.
 * @return S_OK on success, or an HRESULT error.
 *
 * @note Windows CE 3.0 and later.
 */
HRESULT CoInternetCreateSecurityManager(IServiceProvider *pSP, IInternetSecurityManager **ppSM, DWORD dwReserved);
struct IInternetZoneManager;
typedef struct IInternetZoneManager IInternetZoneManager;
/**
 * Creates an Internet zone manager.
 *
 * The service provider allows delegation. The reserved parameter must be
 * zero.
 *
 * @param pSP Service provider for delegation.
 * @param ppZM Receives the IInternetZoneManager interface.
 * @param dwReserved Reserved; set to zero.
 * @return S_OK on success, or an HRESULT error.
 *
 * @note Windows CE 3.0 and later.
 */
HRESULT CoInternetCreateZoneManager(IServiceProvider *pSP, IInternetZoneManager **ppZM, DWORD dwReserved);
enum _tagPSUACTION {
    PSU_DEFAULT = 1,
    PSU_SECURITY_URL_ONLY = 2
};

typedef enum _tagPSUACTION PSUACTION;
HRESULT CoInternetGetSecurityUrl(LPCWSTR pwzUrl, LPWSTR *ppwzSecUrl, PSUACTION psuAction, DWORD dwReserved);
struct IInternetSession;
typedef struct IInternetSession IInternetSession;
HRESULT CoInternetGetSession(DWORD dwSessionMode, IInternetSession **ppIInternetSession, DWORD dwReserved);
enum _tagPARSEACTION {
    PARSE_CANONICALIZE = 1,
    PARSE_FRIENDLY = 2,
    PARSE_SECURITY_URL = 3,
    PARSE_ROOTDOCUMENT = 4,
    PARSE_DOCUMENT = 5,
    PARSE_ANCHOR = 6,
    PARSE_ENCODE = 7,
    PARSE_DECODE = 8,
    PARSE_PATH_FROM_URL = 9,
    PARSE_URL_FROM_PATH = 10,
    PARSE_MIME = 11,
    PARSE_SERVER = 12,
    PARSE_SCHEMA = 13,
    PARSE_SITE = 14,
    PARSE_DOMAIN = 15,
    PARSE_LOCATION = 16,
    PARSE_SECURITY_DOMAIN = 17
};

typedef enum _tagPARSEACTION PARSEACTION;
HRESULT CoInternetParseUrl(LPCWSTR pwzUrl, PARSEACTION ParseAction, DWORD dwFlags, LPWSTR pszResult, DWORD cchResult, DWORD *pcchResult, DWORD dwReserved);
enum _tagQUERYOPTION {
    QUERY_EXPIRATION_DATE = 1,
    QUERY_TIME_OF_LAST_CHANGE = 2,
    QUERY_CONTENT_ENCODING = 3,
    QUERY_CONTENT_TYPE = 4,
    QUERY_REFRESH = 5,
    QUERY_RECOMBINE = 6,
    QUERY_CAN_NAVIGATE = 7,
    QUERY_USES_NETWORK = 8,
    QUERY_IS_CACHED = 9,
    QUERY_IS_INSTALLEDENTRY = 10,
    QUERY_IS_CACHED_OR_MAPPED = 11,
    QUERY_USES_CACHE = 12
};

typedef enum _tagQUERYOPTION QUERYOPTION;
HRESULT CoInternetQueryInfo(LPCWSTR pwzUrl, QUERYOPTION QueryOptions, DWORD dwQueryFlags, LPVOID pvBuffer, DWORD cbBuffer, DWORD *pcbBuffer, DWORD dwReserved);
struct IBindStatusCallback;
typedef struct IBindStatusCallback IBindStatusCallback;
HRESULT CreateAsyncBindCtxEx(IBindCtx *pbc, DWORD dwOptions, IBindStatusCallback *pBSCb, IEnumFORMATETC *pEnum, IBindCtx **ppBC, DWORD reserved);
HRESULT CreateURLMoniker(LPMONIKER pMkCtx, LPCWSTR szURL, LPMONIKER *ppmk);
HRESULT FindMediaType(LPCSTR rgszTypes, CLIPFORMAT *rgcfTypes);
HRESULT FindMediaTypeClass(LPBC pBC, LPCSTR szType, CLSID *pclsID, DWORD reserved);
HRESULT FindMimeFromData(LPBC pBC, LPCWSTR pwzUrl, LPVOID pBuffer, DWORD cbSize, LPCWSTR pwzMimeProposed, DWORD dwMimeFlags, LPWSTR *ppwzMimeOut, DWORD dwReserved);
HRESULT GetClassFileOrMime(LPBC pBC, LPCWSTR szFilename, LPVOID pBuffer, DWORD cbSize, LPCWSTR szMime, DWORD dwReserved, CLSID *pclsid);
HRESULT IsAsyncMoniker(IMoniker *pmk);
HRESULT MkParseDisplayNameEx(IBindCtx *pbc, LPCWSTR szDisplayName, ULONG *pchEaten, LPMONIKER *ppmk);
HRESULT ObtainUserAgentString(DWORD dwOption, LPSTR pszUAOut, DWORD *cbSize);
HRESULT RegisterBindStatusCallback(LPBC pBC, IBindStatusCallback *pBSCb, IBindStatusCallback **ppBSCBPrev, DWORD dwReserved);
struct _tagBINDINFO;
typedef struct _tagBINDINFO BINDINFO;
void ReleaseBindInfo(BINDINFO *pbindinfo);
HRESULT RevokeBindStatusCallback(LPBC pBC, IBindStatusCallback *pBSCb);
enum __MIDL_IBindStatusCallback_0003 {
    BINDF_ASYNCHRONOUS = 1,
    BINDF_ASYNCSTORAGE = 2,
    BINDF_NOPROGRESSIVERENDERING = 4,
    BINDF_OFFLINEOPERATION = 8,
    BINDF_GETNEWESTVERSION = 16,
    BINDF_NOWRITECACHE = 32,
    BINDF_NEEDFILE = 64,
    BINDF_PULLDATA = 128,
    BINDF_IGNORESECURITYPROBLEM = 256,
    BINDF_RESYNCHRONIZE = 512,
    BINDF_HYPERLINK = 1024,
    BINDF_NO_UI = 2048,
    BINDF_SILENTOPERATION = 4096,
    BINDF_PRAGMA_NO_CACHE = 8192,
    BINDF_FREE_THREADED = 65536,
    BINDF_DIRECT_READ = 131072,
    BINDF_FORMS_SUBMIT = 262144,
    BINDF_GETFROMCACHE_IF_NET_FAIL = 524288
};

typedef enum __MIDL_IBindStatusCallback_0003 BINDF;
enum __MIDL_IBindStatusCallback_0002 {
    BINDINFOF_URLENCODESTGMEDDATA = 1,
    BINDINFOF_URLENCODEDEXTRAINFO = 2
};

typedef enum __MIDL_IBindStatusCallback_0002 BINDINFOF;
enum tagBINDSTATUS {
    BINDSTATUS_FINDINGRESOURCE = 1,
    BINDSTATUS_CONNECTING = 2,
    BINDSTATUS_REDIRECTING = 3,
    BINDSTATUS_BEGINDOWNLOADDATA = 4,
    BINDSTATUS_DOWNLOADINGDATA = 5,
    BINDSTATUS_ENDDOWNLOADDATA = 6,
    BINDSTATUS_BEGINDOWNLOADCOMPONENTS = 7,
    BINDSTATUS_INSTALLINGCOMPONENTS = 8,
    BINDSTATUS_ENDDOWNLOADCOMPONENTS = 9,
    BINDSTATUS_USINGCACHEDCOPY = 10,
    BINDSTATUS_SENDINGREQUEST = 11,
    BINDSTATUS_CLASSIDAVAILABLE = 12,
    BINDSTATUS_MIMETYPEAVAILABLE = 13,
    BINDSTATUS_CACHEFILENAMEAVAILABLE = 14,
    BINDSTATUS_BEGINSYNCOPERATION = 15,
    BINDSTATUS_ENDSYNCOPERATION = 16,
    BINDSTATUS_BEGINUPLOADDATA = 17,
    BINDSTATUS_UPLOADINGDATA = 18,
    BINDSTATUS_ENDUPLOADDATA = 19,
    BINDSTATUS_PROTOCOLCLASSID = 20,
    BINDSTATUS_ENCODING = 21,
    BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE = 22,
    BINDSTATUS_CLASSINSTALLLOCATION = 23,
    BINDSTATUS_DECODING = 24,
    BINDSTATUS_LOADINGMIMEHANDLER = 25
};

typedef enum tagBINDSTATUS BINDSTATUS;
enum tagBINDSTRING {
    BINDSTRING_HEADERS = 1,
    BINDSTRING_ACCEPT_MIMES = 2,
    BINDSTRING_EXTRA_URL = 3,
    BINDSTRING_LANGUAGE = 4,
    BINDSTRING_USERNAME = 5,
    BINDSTRING_PASSWORD = 6,
    BINDSTRING_UA_PIXELS = 7,
    BINDSTRING_UA_COLOR = 8,
    BINDSTRING_OS = 9,
    BINDSTRING_USER_AGENT = 10,
    BINDSTRING_ACCEPT_ENCODINGS = 11,
    BINDSTRING_POST_COOKIE = 12,
    BINDSTRING_POST_DATA_MIME = 13,
    BINDSTRING_URL = 14
};

typedef enum tagBINDSTRING BINDSTRING;
enum __MIDL_IBindStatusCallback_0001 {
    BINDVERB_GET = 0,
    BINDVERB_POST = 1,
    BINDVERB_PUT = 2,
    BINDVERB_CUSTOM = 3
};

typedef enum __MIDL_IBindStatusCallback_0001 BINDVERB;
enum __MIDL_IBindStatusCallback_0004 {
    BSCF_FIRSTDATANOTIFICATION = 1,
    BSCF_INTERMEDIATEDATANOTIFICATION = 2,
    BSCF_LASTDATANOTIFICATION = 4,
    BSCF_DATAFULLYAVAILABLE = 8,
    BSCF_AVAILABLEDATASIZEUNKNOWN = 16
};

typedef enum __MIDL_IBindStatusCallback_0004 BSCF;
enum __MIDL_ICodeInstall_0001 {
    CIP_DISK_FULL = 0,
    CIP_ACCESS_DENIED = 1,
    CIP_NEWER_VERSION_EXISTS = 2,
    CIP_OLDER_VERSION_EXISTS = 3,
    CIP_NAME_CONFLICT = 4,
    CIP_TRUST_VERIFICATION_COMPONENT_MISSING = 5,
    CIP_EXE_SELF_REGISTERATION_TIMEOUT = 6,
    CIP_UNSAFE_TO_ABORT = 7,
    CIP_NEED_REBOOT = 8
};

typedef enum __MIDL_ICodeInstall_0001 CIP_STATUS;
struct _tagCODEBASEHOLD;
typedef struct _tagCODEBASEHOLD CODEBASEHOLD;
struct _tagDATAINFO;
typedef struct _tagDATAINFO DATAINFO;
struct _tagHIT_LOGGING_INFO;
typedef struct _tagHIT_LOGGING_INFO HIT_LOGGING_INFO;
struct IAuthenticate;
typedef struct IAuthenticate IAuthenticate;
struct IAuthenticateVtbl;
typedef struct IAuthenticateVtbl IAuthenticateVtbl;
struct IBindHost;
typedef struct IBindHost IBindHost;
struct IBindHostVtbl;
typedef struct IBindHostVtbl IBindHostVtbl;
struct IBindProtocol;
typedef struct IBindProtocol IBindProtocol;
struct IBindProtocolVtbl;
typedef struct IBindProtocolVtbl IBindProtocolVtbl;
struct IBindStatusCallbackVtbl;
typedef struct IBindStatusCallbackVtbl IBindStatusCallbackVtbl;
struct IBinding;
typedef struct IBinding IBinding;
struct IBindingVtbl;
typedef struct IBindingVtbl IBindingVtbl;
struct ICodeInstall;
typedef struct ICodeInstall ICodeInstall;
struct ICodeInstallVtbl;
typedef struct ICodeInstallVtbl ICodeInstallVtbl;
struct IDataFilter;
typedef struct IDataFilter IDataFilter;
struct IDataFilterVtbl;
typedef struct IDataFilterVtbl IDataFilterVtbl;
struct IEncodingFilterFactory;
typedef struct IEncodingFilterFactory IEncodingFilterFactory;
struct IEncodingFilterFactoryVtbl;
typedef struct IEncodingFilterFactoryVtbl IEncodingFilterFactoryVtbl;
struct IHttpNegotiate;
typedef struct IHttpNegotiate IHttpNegotiate;
struct IHttpNegotiateVtbl;
typedef struct IHttpNegotiateVtbl IHttpNegotiateVtbl;
struct IHttpSecurity;
typedef struct IHttpSecurity IHttpSecurity;
struct IHttpSecurityVtbl;
typedef struct IHttpSecurityVtbl IHttpSecurityVtbl;
struct IInternet;
typedef struct IInternet IInternet;
struct IInternetBindInfo;
typedef struct IInternetBindInfo IInternetBindInfo;
struct IInternetBindInfoVtbl;
typedef struct IInternetBindInfoVtbl IInternetBindInfoVtbl;
struct IInternetHostSecurityManager;
typedef struct IInternetHostSecurityManager IInternetHostSecurityManager;
struct IInternetHostSecurityManagerVtbl;
typedef struct IInternetHostSecurityManagerVtbl IInternetHostSecurityManagerVtbl;
struct IInternetPriority;
typedef struct IInternetPriority IInternetPriority;
struct IInternetPriorityVtbl;
typedef struct IInternetPriorityVtbl IInternetPriorityVtbl;
struct IInternetProtocol;
typedef struct IInternetProtocol IInternetProtocol;
struct IInternetProtocolInfo;
typedef struct IInternetProtocolInfo IInternetProtocolInfo;
struct IInternetProtocolInfoVtbl;
typedef struct IInternetProtocolInfoVtbl IInternetProtocolInfoVtbl;
struct IInternetProtocolRoot;
typedef struct IInternetProtocolRoot IInternetProtocolRoot;
struct IInternetProtocolRootVtbl;
typedef struct IInternetProtocolRootVtbl IInternetProtocolRootVtbl;
struct IInternetProtocolSink;
typedef struct IInternetProtocolSink IInternetProtocolSink;
struct IInternetProtocolSinkVtbl;
typedef struct IInternetProtocolSinkVtbl IInternetProtocolSinkVtbl;
struct IInternetProtocolVtbl;
typedef struct IInternetProtocolVtbl IInternetProtocolVtbl;
struct IInternetSecurityManagerVtbl;
typedef struct IInternetSecurityManagerVtbl IInternetSecurityManagerVtbl;
struct IInternetSecurityMgrSite;
typedef struct IInternetSecurityMgrSite IInternetSecurityMgrSite;
struct IInternetSecurityMgrSiteVtbl;
typedef struct IInternetSecurityMgrSiteVtbl IInternetSecurityMgrSiteVtbl;
struct IInternetSessionVtbl;
typedef struct IInternetSessionVtbl IInternetSessionVtbl;
struct IInternetThreadSwitch;
typedef struct IInternetThreadSwitch IInternetThreadSwitch;
struct IInternetThreadSwitchVtbl;
typedef struct IInternetThreadSwitchVtbl IInternetThreadSwitchVtbl;
struct IInternetVtbl;
typedef struct IInternetVtbl IInternetVtbl;
struct IInternetZoneManagerVtbl;
typedef struct IInternetZoneManagerVtbl IInternetZoneManagerVtbl;
struct IPersistMoniker;
typedef struct IPersistMoniker IPersistMoniker;
struct IPersistMonikerVtbl;
typedef struct IPersistMonikerVtbl IPersistMonikerVtbl;
struct ISoftDistExt;
typedef struct ISoftDistExt ISoftDistExt;
struct ISoftDistExtVtbl;
typedef struct ISoftDistExtVtbl ISoftDistExtVtbl;
struct IWinInetHttpInfo;
typedef struct IWinInetHttpInfo IWinInetHttpInfo;
struct IWinInetHttpInfoVtbl;
typedef struct IWinInetHttpInfoVtbl IWinInetHttpInfoVtbl;
struct IWinInetInfo;
typedef struct IWinInetInfo IWinInetInfo;
struct IWinInetInfoVtbl;
typedef struct IWinInetInfoVtbl IWinInetInfoVtbl;
struct IWindowForBindingUI;
typedef struct IWindowForBindingUI IWindowForBindingUI;
struct IWindowForBindingUIVtbl;
typedef struct IWindowForBindingUIVtbl IWindowForBindingUIVtbl;
typedef IAuthenticate *LPAUTHENTICATION;
typedef IBindHost *LPBINDHOST;
typedef IBinding *LPBINDING;
typedef IBindProtocol *LPBINDPROTOCOL;
typedef IBindStatusCallback *LPBINDSTATUSCALLBACK;
typedef struct _tagCODEBASEHOLD *LPCODEBASEHOLD;
typedef ICodeInstall *LPCODEINSTALL;
typedef IDataFilter *LPDATAFILTER;
typedef IEncodingFilterFactory *LPENCODINGFILTERFACTORY;
typedef struct _tagHIT_LOGGING_INFO *LPHIT_LOGGING_INFO;
typedef IHttpNegotiate *LPHTTPNEGOTIATE;
typedef IHttpSecurity *LPHTTPSECURITY;
typedef IInternet *LPIINTERNET;
typedef IInternetBindInfo *LPIINTERNETBINDINFO;
typedef IInternetPriority *LPIINTERNETPRIORITY;
typedef IInternetProtocol *LPIINTERNETPROTOCOL;
typedef IInternetProtocolInfo *LPIINTERNETPROTOCOLINFO;
typedef IInternetProtocolRoot *LPIINTERNETPROTOCOLROOT;
typedef IInternetProtocolSink *LPIINTERNETPROTOCOLSINK;
typedef IInternetSession *LPIINTERNETSESSION;
typedef IInternetThreadSwitch *LPIINTERNETTHREADSWITCH;
typedef IPersistMoniker *LPPERSISTMONIKER;
struct tagRemFORMATETC;
typedef struct tagRemFORMATETC *LPREMFORMATETC;
struct _REMSECURITY_ATTRIBUTES;
typedef struct _REMSECURITY_ATTRIBUTES *LPREMSECURITY_ATTRIBUTES;
struct _tagSOFTDISTINFO;
typedef struct _tagSOFTDISTINFO *LPSOFTDISTINFO;
typedef IInternetZoneManager *LPURLZONEMANAGER;
typedef IWindowForBindingUI *LPWINDOWFORBINDINGUI;
typedef IWinInetHttpInfo *LPWININETHTTPINFO;
typedef IWinInetInfo *LPWININETINFO;
struct _ZONEATTRIBUTES;
typedef struct _ZONEATTRIBUTES *LPZONEATTRIBUTES;
enum _tagOIBDG_FLAGS {
    OIBDG_APARTMENTTHREADED = 256
};

typedef enum _tagOIBDG_FLAGS OIBDG_FLAGS;
enum _tagPI_FLAGS {
    PI_PARSE_URL = 1,
    PI_FILTER_MODE = 2,
    PI_FORCE_ASYNC = 4,
    PI_USE_WORKERTHREAD = 8,
    PI_MIMEVERIFICATION = 16,
    PI_CLSIDLOOKUP = 32,
    PI_DATAPROGRESS = 64,
    PI_SYNCHRONOUS = 128,
    PI_APARTMENTTHREADED = 256,
    PI_CLASSINSTALL = 512,
    PD_FORCE_SWITCH = 65536
};

typedef enum _tagPI_FLAGS PI_FLAGS;
typedef struct _REMSECURITY_ATTRIBUTES *PREMSECURITY_ATTRIBUTES;
struct _tagPROTOCOLDATA;
typedef struct _tagPROTOCOLDATA PROTOCOLDATA;
struct _tagPROTOCOLFILTERDATA;
typedef struct _tagPROTOCOLFILTERDATA PROTOCOLFILTERDATA;
enum __MIDL_IInternetSecurityManager_0001 {
    PUAF_DEFAULT = 0,
    PUAF_NOUI = 1,
    PUAF_ISFILE = 2,
    PUAF_WARN_IF_DENIED = 4,
    PUAF_FORCEUI_FOREGROUND = 8,
    PUAF_CHECK_TIFS = 16
};

typedef enum __MIDL_IInternetSecurityManager_0001 PUAF;
typedef struct _REMSECURITY_ATTRIBUTES REMSECURITY_ATTRIBUTES;
struct _tagRemBINDINFO;
typedef struct _tagRemBINDINFO RemBINDINFO;
typedef struct tagRemFORMATETC RemFORMATETC;
typedef struct _tagSOFTDISTINFO SOFTDISTINFO;
enum __MIDL_IInternetSecurityManager_0002 {
    SZM_CREATE = 0,
    SZM_DELETE = 1
};

typedef enum __MIDL_IInternetSecurityManager_0002 SZM_FLAGS;
enum tagURLTEMPLATE {
    URLTEMPLATE_CUSTOM = 0,
    URLTEMPLATE_PREDEFINED_MIN = 65536,
    URLTEMPLATE_LOW = 65536,
    URLTEMPLATE_MEDIUM = 69632,
    URLTEMPLATE_HIGH = 73728,
    URLTEMPLATE_PREDEFINED_MAX = 131072
};

typedef enum tagURLTEMPLATE URLTEMPLATE;
enum tagURLZONE {
    URLZONE_PREDEFINED_MIN = 0,
    URLZONE_LOCAL_MACHINE = 0,
    URLZONE_INTRANET = 1,
    URLZONE_TRUSTED = 2,
    URLZONE_INTERNET = 3,
    URLZONE_UNTRUSTED = 4,
    URLZONE_PREDEFINED_MAX = 999,
    URLZONE_USER_MIN = 1000,
    URLZONE_USER_MAX = 10000
};

typedef enum tagURLZONE URLZONE;
enum _URLZONEREG {
    URLZONEREG_DEFAULT = 0,
    URLZONEREG_HKLM = 1,
    URLZONEREG_HKCU = 2
};

typedef enum _URLZONEREG URLZONEREG;
enum __MIDL_IInternetZoneManager_0002 {
    ZAFLAGS_CUSTOM_EDIT = 1,
    ZAFLAGS_ADD_SITES = 2,
    ZAFLAGS_REQUIRE_VERIFICATION = 4,
    ZAFLAGS_INCLUDE_PROXY_OVERRIDE = 8,
    ZAFLAGS_INCLUDE_INTRANET_SITES = 16,
    ZAFLAGS_NO_UI = 32,
    ZAFLAGS_SUPPORTS_VERIFICATION = 64,
    ZAFLAGS_UNC_AS_INTRANET = 128
};

typedef enum __MIDL_IInternetZoneManager_0002 ZAFLAGS;
typedef struct _ZONEATTRIBUTES ZONEATTRIBUTES;
struct IAuthenticate {
    struct IAuthenticateVtbl *lpVtbl;
};

struct IAuthenticateVtbl {
    HRESULT (*QueryInterface)(IAuthenticate *, const IID *const, void **);
    ULONG (*AddRef)(IAuthenticate *);
    ULONG (*Release)(IAuthenticate *);
    HRESULT (*Authenticate)(IAuthenticate *, HWND *, LPWSTR *, LPWSTR *);
};

struct IBindHost {
    struct IBindHostVtbl *lpVtbl;
};

struct IBindHostVtbl {
    HRESULT (*QueryInterface)(IBindHost *, const IID *const, void **);
    ULONG (*AddRef)(IBindHost *);
    ULONG (*Release)(IBindHost *);
    HRESULT (*CreateMoniker)(IBindHost *, LPOLESTR, IBindCtx *, IMoniker **, DWORD);
    HRESULT (*MonikerBindToStorage)(IBindHost *, IMoniker *, IBindCtx *, IBindStatusCallback *, const IID *const, void **);
    HRESULT (*MonikerBindToObject)(IBindHost *, IMoniker *, IBindCtx *, IBindStatusCallback *, const IID *const, void **);
};

struct IBindProtocol {
    struct IBindProtocolVtbl *lpVtbl;
};

struct IBindProtocolVtbl {
    HRESULT (*QueryInterface)(IBindProtocol *, const IID *const, void **);
    ULONG (*AddRef)(IBindProtocol *);
    ULONG (*Release)(IBindProtocol *);
    HRESULT (*CreateBinding)(IBindProtocol *, LPCWSTR, IBindCtx *, IBinding **);
};

struct IBindStatusCallback {
    struct IBindStatusCallbackVtbl *lpVtbl;
};

struct IBindStatusCallbackVtbl {
    HRESULT (*QueryInterface)(IBindStatusCallback *, const IID *const, void **);
    ULONG (*AddRef)(IBindStatusCallback *);
    ULONG (*Release)(IBindStatusCallback *);
    HRESULT (*OnStartBinding)(IBindStatusCallback *, DWORD, IBinding *);
    HRESULT (*GetPriority)(IBindStatusCallback *, LONG *);
    HRESULT (*OnLowResource)(IBindStatusCallback *, DWORD);
    HRESULT (*OnProgress)(IBindStatusCallback *, ULONG, ULONG, ULONG, LPCWSTR);
    HRESULT (*OnStopBinding)(IBindStatusCallback *, HRESULT, LPCWSTR);
    HRESULT (*GetBindInfo)(IBindStatusCallback *, DWORD *, BINDINFO *);
    HRESULT (*OnDataAvailable)(IBindStatusCallback *, DWORD, DWORD, FORMATETC *, STGMEDIUM *);
    HRESULT (*OnObjectAvailable)(IBindStatusCallback *, const IID *const, IUnknown *);
};

struct IBinding {
    struct IBindingVtbl *lpVtbl;
};

struct IBindingVtbl {
    HRESULT (*QueryInterface)(IBinding *, const IID *const, void **);
    ULONG (*AddRef)(IBinding *);
    ULONG (*Release)(IBinding *);
    HRESULT (*Abort)(IBinding *);
    HRESULT (*Suspend)(IBinding *);
    HRESULT (*Resume)(IBinding *);
    HRESULT (*SetPriority)(IBinding *, LONG);
    HRESULT (*GetPriority)(IBinding *, LONG *);
    HRESULT (*GetBindResult)(IBinding *, CLSID *, DWORD *, LPOLESTR *, DWORD *);
};

struct ICodeInstall {
    struct ICodeInstallVtbl *lpVtbl;
};

struct ICodeInstallVtbl {
    HRESULT (*QueryInterface)(ICodeInstall *, const IID *const, void **);
    ULONG (*AddRef)(ICodeInstall *);
    ULONG (*Release)(ICodeInstall *);
    HRESULT (*GetWindow)(ICodeInstall *, const GUID *const, HWND *);
    HRESULT (*OnCodeInstallProblem)(ICodeInstall *, ULONG, LPCWSTR, LPCWSTR, DWORD);
};

struct IDataFilter {
    struct IDataFilterVtbl *lpVtbl;
};

struct IDataFilterVtbl {
    HRESULT (*QueryInterface)(IDataFilter *, const IID *const, void **);
    ULONG (*AddRef)(IDataFilter *);
    ULONG (*Release)(IDataFilter *);
    HRESULT (*DoEncode)(IDataFilter *, DWORD, LONG, BYTE *, LONG, BYTE *, LONG, LONG *, LONG *, DWORD);
    HRESULT (*DoDecode)(IDataFilter *, DWORD, LONG, BYTE *, LONG, BYTE *, LONG, LONG *, LONG *, DWORD);
    HRESULT (*SetEncodingLevel)(IDataFilter *, DWORD);
};

struct IEncodingFilterFactory {
    struct IEncodingFilterFactoryVtbl *lpVtbl;
};

struct IEncodingFilterFactoryVtbl {
    HRESULT (*QueryInterface)(IEncodingFilterFactory *, const IID *const, void **);
    ULONG (*AddRef)(IEncodingFilterFactory *);
    ULONG (*Release)(IEncodingFilterFactory *);
    HRESULT (*FindBestFilter)(IEncodingFilterFactory *, LPCWSTR, LPCWSTR, DATAINFO, IDataFilter **);
    HRESULT (*GetDefaultFilter)(IEncodingFilterFactory *, LPCWSTR, LPCWSTR, IDataFilter **);
};

struct IHttpNegotiate {
    struct IHttpNegotiateVtbl *lpVtbl;
};

struct IHttpNegotiateVtbl {
    HRESULT (*QueryInterface)(IHttpNegotiate *, const IID *const, void **);
    ULONG (*AddRef)(IHttpNegotiate *);
    ULONG (*Release)(IHttpNegotiate *);
    HRESULT (*BeginningTransaction)(IHttpNegotiate *, LPCWSTR, LPCWSTR, DWORD, LPWSTR *);
    HRESULT (*OnResponse)(IHttpNegotiate *, DWORD, LPCWSTR, LPCWSTR, LPWSTR *);
};

struct IHttpSecurity {
    struct IHttpSecurityVtbl *lpVtbl;
};

struct IHttpSecurityVtbl {
    HRESULT (*QueryInterface)(IHttpSecurity *, const IID *const, void **);
    ULONG (*AddRef)(IHttpSecurity *);
    ULONG (*Release)(IHttpSecurity *);
    HRESULT (*GetWindow)(IHttpSecurity *, const GUID *const, HWND *);
    HRESULT (*OnSecurityProblem)(IHttpSecurity *, DWORD);
};

struct IInternet {
    struct IInternetVtbl *lpVtbl;
};

struct IInternetBindInfo {
    struct IInternetBindInfoVtbl *lpVtbl;
};

struct IInternetBindInfoVtbl {
    HRESULT (*QueryInterface)(IInternetBindInfo *, const IID *const, void **);
    ULONG (*AddRef)(IInternetBindInfo *);
    ULONG (*Release)(IInternetBindInfo *);
    HRESULT (*GetBindInfo)(IInternetBindInfo *, DWORD *, BINDINFO *);
    HRESULT (*GetBindString)(IInternetBindInfo *, ULONG, LPOLESTR *, ULONG, ULONG *);
};

struct IInternetHostSecurityManager {
    struct IInternetHostSecurityManagerVtbl *lpVtbl;
};

struct IInternetHostSecurityManagerVtbl {
    HRESULT (*QueryInterface)(IInternetHostSecurityManager *, const IID *const, void **);
    ULONG (*AddRef)(IInternetHostSecurityManager *);
    ULONG (*Release)(IInternetHostSecurityManager *);
    HRESULT (*GetSecurityId)(IInternetHostSecurityManager *, BYTE *, DWORD *, DWORD);
    HRESULT (*ProcessUrlAction)(IInternetHostSecurityManager *, DWORD, BYTE *, DWORD, BYTE *, DWORD, DWORD, DWORD);
    HRESULT (*QueryCustomPolicy)(IInternetHostSecurityManager *, const GUID *const, BYTE **, DWORD *, BYTE *, DWORD, DWORD);
};

struct IInternetPriority {
    struct IInternetPriorityVtbl *lpVtbl;
};

struct IInternetPriorityVtbl {
    HRESULT (*QueryInterface)(IInternetPriority *, const IID *const, void **);
    ULONG (*AddRef)(IInternetPriority *);
    ULONG (*Release)(IInternetPriority *);
    HRESULT (*SetPriority)(IInternetPriority *, LONG);
    HRESULT (*GetPriority)(IInternetPriority *, LONG *);
};

struct IInternetProtocol {
    struct IInternetProtocolVtbl *lpVtbl;
};

struct IInternetProtocolInfo {
    struct IInternetProtocolInfoVtbl *lpVtbl;
};

struct IInternetProtocolInfoVtbl {
    HRESULT (*QueryInterface)(IInternetProtocolInfo *, const IID *const, void **);
    ULONG (*AddRef)(IInternetProtocolInfo *);
    ULONG (*Release)(IInternetProtocolInfo *);
    HRESULT (*ParseUrl)(IInternetProtocolInfo *, LPCWSTR, PARSEACTION, DWORD, LPWSTR, DWORD, DWORD *, DWORD);
    HRESULT (*CombineUrl)(IInternetProtocolInfo *, LPCWSTR, LPCWSTR, DWORD, LPWSTR, DWORD, DWORD *, DWORD);
    HRESULT (*CompareUrl)(IInternetProtocolInfo *, LPCWSTR, LPCWSTR, DWORD);
    HRESULT (*QueryInfo)(IInternetProtocolInfo *, LPCWSTR, QUERYOPTION, DWORD, LPVOID, DWORD, DWORD *, DWORD);
};

struct IInternetProtocolRoot {
    struct IInternetProtocolRootVtbl *lpVtbl;
};

struct IInternetProtocolRootVtbl {
    HRESULT (*QueryInterface)(IInternetProtocolRoot *, const IID *const, void **);
    ULONG (*AddRef)(IInternetProtocolRoot *);
    ULONG (*Release)(IInternetProtocolRoot *);
    HRESULT (*Start)(IInternetProtocolRoot *, LPCWSTR, IInternetProtocolSink *, IInternetBindInfo *, DWORD, DWORD);
    HRESULT (*Continue)(IInternetProtocolRoot *, PROTOCOLDATA *);
    HRESULT (*Abort)(IInternetProtocolRoot *, HRESULT, DWORD);
    HRESULT (*Terminate)(IInternetProtocolRoot *, DWORD);
    HRESULT (*Suspend)(IInternetProtocolRoot *);
    HRESULT (*Resume)(IInternetProtocolRoot *);
};

struct IInternetProtocolSink {
    struct IInternetProtocolSinkVtbl *lpVtbl;
};

struct IInternetProtocolSinkVtbl {
    HRESULT (*QueryInterface)(IInternetProtocolSink *, const IID *const, void **);
    ULONG (*AddRef)(IInternetProtocolSink *);
    ULONG (*Release)(IInternetProtocolSink *);
    HRESULT (*Switch)(IInternetProtocolSink *, PROTOCOLDATA *);
    HRESULT (*ReportProgress)(IInternetProtocolSink *, ULONG, LPCWSTR);
    HRESULT (*ReportData)(IInternetProtocolSink *, DWORD, ULONG, ULONG);
    HRESULT (*ReportResult)(IInternetProtocolSink *, HRESULT, DWORD, LPCWSTR);
};

struct IInternetProtocolVtbl {
    HRESULT (*QueryInterface)(IInternetProtocol *, const IID *const, void **);
    ULONG (*AddRef)(IInternetProtocol *);
    ULONG (*Release)(IInternetProtocol *);
    HRESULT (*Start)(IInternetProtocol *, LPCWSTR, IInternetProtocolSink *, IInternetBindInfo *, DWORD, DWORD);
    HRESULT (*Continue)(IInternetProtocol *, PROTOCOLDATA *);
    HRESULT (*Abort)(IInternetProtocol *, HRESULT, DWORD);
    HRESULT (*Terminate)(IInternetProtocol *, DWORD);
    HRESULT (*Suspend)(IInternetProtocol *);
    HRESULT (*Resume)(IInternetProtocol *);
    HRESULT (*Read)(IInternetProtocol *, void *, ULONG, ULONG *);
    HRESULT (*Seek)(IInternetProtocol *, LARGE_INTEGER, DWORD, ULARGE_INTEGER *);
    HRESULT (*LockRequest)(IInternetProtocol *, DWORD);
    HRESULT (*UnlockRequest)(IInternetProtocol *);
};

struct IInternetSecurityManager {
    struct IInternetSecurityManagerVtbl *lpVtbl;
};

struct IInternetSecurityManagerVtbl {
    HRESULT (*QueryInterface)(IInternetSecurityManager *, const IID *const, void **);
    ULONG (*AddRef)(IInternetSecurityManager *);
    ULONG (*Release)(IInternetSecurityManager *);
    HRESULT (*SetSecuritySite)(IInternetSecurityManager *, IInternetSecurityMgrSite *);
    HRESULT (*GetSecuritySite)(IInternetSecurityManager *, IInternetSecurityMgrSite **);
    HRESULT (*MapUrlToZone)(IInternetSecurityManager *, LPCWSTR, DWORD *, DWORD);
    HRESULT (*GetSecurityId)(IInternetSecurityManager *, LPCWSTR, BYTE *, DWORD *, DWORD);
    HRESULT (*ProcessUrlAction)(IInternetSecurityManager *, LPCWSTR, DWORD, BYTE *, DWORD, BYTE *, DWORD, DWORD, DWORD);
    HRESULT (*QueryCustomPolicy)(IInternetSecurityManager *, LPCWSTR, const GUID *const, BYTE **, DWORD *, BYTE *, DWORD, DWORD);
    HRESULT (*SetZoneMapping)(IInternetSecurityManager *, DWORD, LPCWSTR, DWORD);
    HRESULT (*GetZoneMappings)(IInternetSecurityManager *, DWORD, IEnumString **, DWORD);
};

struct IInternetSecurityMgrSite {
    struct IInternetSecurityMgrSiteVtbl *lpVtbl;
};

struct IInternetSecurityMgrSiteVtbl {
    HRESULT (*QueryInterface)(IInternetSecurityMgrSite *, const IID *const, void **);
    ULONG (*AddRef)(IInternetSecurityMgrSite *);
    ULONG (*Release)(IInternetSecurityMgrSite *);
    HRESULT (*GetWindow)(IInternetSecurityMgrSite *, HWND *);
    HRESULT (*EnableModeless)(IInternetSecurityMgrSite *, BOOL);
};

struct IInternetSession {
    struct IInternetSessionVtbl *lpVtbl;
};

struct IInternetSessionVtbl {
    HRESULT (*QueryInterface)(IInternetSession *, const IID *const, void **);
    ULONG (*AddRef)(IInternetSession *);
    ULONG (*Release)(IInternetSession *);
    HRESULT (*RegisterNameSpace)(IInternetSession *, IClassFactory *, const CLSID *const, LPCWSTR, ULONG, const LPCWSTR *, DWORD);
    HRESULT (*UnregisterNameSpace)(IInternetSession *, IClassFactory *, LPCWSTR);
    HRESULT (*RegisterMimeFilter)(IInternetSession *, IClassFactory *, const CLSID *const, LPCWSTR);
    HRESULT (*UnregisterMimeFilter)(IInternetSession *, IClassFactory *, LPCWSTR);
    HRESULT (*CreateBinding)(IInternetSession *, LPBC, LPCWSTR, IUnknown *, IUnknown **, IInternetProtocol **, DWORD);
    HRESULT (*SetSessionOption)(IInternetSession *, DWORD, LPVOID, DWORD, DWORD);
    HRESULT (*GetSessionOption)(IInternetSession *, DWORD, LPVOID, DWORD *, DWORD);
};

struct IInternetThreadSwitch {
    struct IInternetThreadSwitchVtbl *lpVtbl;
};

struct IInternetThreadSwitchVtbl {
    HRESULT (*QueryInterface)(IInternetThreadSwitch *, const IID *const, void **);
    ULONG (*AddRef)(IInternetThreadSwitch *);
    ULONG (*Release)(IInternetThreadSwitch *);
    HRESULT (*Prepare)(IInternetThreadSwitch *);
    HRESULT (*Continue)(IInternetThreadSwitch *);
};

struct IInternetVtbl {
    HRESULT (*QueryInterface)(IInternet *, const IID *const, void **);
    ULONG (*AddRef)(IInternet *);
    ULONG (*Release)(IInternet *);
};

struct IInternetZoneManager {
    struct IInternetZoneManagerVtbl *lpVtbl;
};

struct IInternetZoneManagerVtbl {
    HRESULT (*QueryInterface)(IInternetZoneManager *, const IID *const, void **);
    ULONG (*AddRef)(IInternetZoneManager *);
    ULONG (*Release)(IInternetZoneManager *);
    HRESULT (*GetZoneAttributes)(IInternetZoneManager *, DWORD, ZONEATTRIBUTES *);
    HRESULT (*SetZoneAttributes)(IInternetZoneManager *, DWORD, ZONEATTRIBUTES *);
    HRESULT (*GetZoneCustomPolicy)(IInternetZoneManager *, DWORD, const GUID *const, BYTE **, DWORD *, URLZONEREG);
    HRESULT (*SetZoneCustomPolicy)(IInternetZoneManager *, DWORD, const GUID *const, BYTE *, DWORD, URLZONEREG);
    HRESULT (*GetZoneActionPolicy)(IInternetZoneManager *, DWORD, DWORD, BYTE *, DWORD, URLZONEREG);
    HRESULT (*SetZoneActionPolicy)(IInternetZoneManager *, DWORD, DWORD, BYTE *, DWORD, URLZONEREG);
    HRESULT (*PromptAction)(IInternetZoneManager *, DWORD, HWND, LPCWSTR, LPCWSTR, DWORD);
    HRESULT (*LogAction)(IInternetZoneManager *, DWORD, LPCWSTR, LPCWSTR, DWORD);
    HRESULT (*CreateZoneEnumerator)(IInternetZoneManager *, DWORD *, DWORD *, DWORD);
    HRESULT (*GetZoneAt)(IInternetZoneManager *, DWORD, DWORD, DWORD *);
    HRESULT (*DestroyZoneEnumerator)(IInternetZoneManager *, DWORD);
    HRESULT (*CopyTemplatePoliciesToZone)(IInternetZoneManager *, DWORD, DWORD, DWORD);
};

struct IPersistMoniker {
    struct IPersistMonikerVtbl *lpVtbl;
};

struct IPersistMonikerVtbl {
    HRESULT (*QueryInterface)(IPersistMoniker *, const IID *const, void **);
    ULONG (*AddRef)(IPersistMoniker *);
    ULONG (*Release)(IPersistMoniker *);
    HRESULT (*GetClassID)(IPersistMoniker *, CLSID *);
    HRESULT (*IsDirty)(IPersistMoniker *);
    HRESULT (*Load)(IPersistMoniker *, BOOL, IMoniker *, LPBC, DWORD);
    HRESULT (*Save)(IPersistMoniker *, IMoniker *, LPBC, BOOL);
    HRESULT (*SaveCompleted)(IPersistMoniker *, IMoniker *, LPBC);
    HRESULT (*GetCurMoniker)(IPersistMoniker *, IMoniker **);
};

struct ISoftDistExt {
    struct ISoftDistExtVtbl *lpVtbl;
};

struct ISoftDistExtVtbl {
    HRESULT (*QueryInterface)(ISoftDistExt *, const IID *const, void **);
    ULONG (*AddRef)(ISoftDistExt *);
    ULONG (*Release)(ISoftDistExt *);
    HRESULT (*ProcessSoftDist)(ISoftDistExt *, LPCWSTR, IXMLElement *, LPSOFTDISTINFO);
    HRESULT (*GetFirstCodeBase)(ISoftDistExt *, LPWSTR *, LPDWORD);
    HRESULT (*GetNextCodeBase)(ISoftDistExt *, LPWSTR *, LPDWORD);
    HRESULT (*AsyncInstallDistributionUnit)(ISoftDistExt *, IBindCtx *, LPVOID, DWORD, LPCODEBASEHOLD);
};

struct IWinInetHttpInfo {
    struct IWinInetHttpInfoVtbl *lpVtbl;
};

struct IWinInetHttpInfoVtbl {
    HRESULT (*QueryInterface)(IWinInetHttpInfo *, const IID *const, void **);
    ULONG (*AddRef)(IWinInetHttpInfo *);
    ULONG (*Release)(IWinInetHttpInfo *);
    HRESULT (*QueryOption)(IWinInetHttpInfo *, DWORD, LPVOID, DWORD *);
    HRESULT (*QueryInfo)(IWinInetHttpInfo *, DWORD, LPVOID, DWORD *, DWORD *, DWORD *);
};

struct IWinInetInfo {
    struct IWinInetInfoVtbl *lpVtbl;
};

struct IWinInetInfoVtbl {
    HRESULT (*QueryInterface)(IWinInetInfo *, const IID *const, void **);
    ULONG (*AddRef)(IWinInetInfo *);
    ULONG (*Release)(IWinInetInfo *);
    HRESULT (*QueryOption)(IWinInetInfo *, DWORD, LPVOID, DWORD *);
};

struct IWindowForBindingUI {
    struct IWindowForBindingUIVtbl *lpVtbl;
};

struct IWindowForBindingUIVtbl {
    HRESULT (*QueryInterface)(IWindowForBindingUI *, const IID *const, void **);
    ULONG (*AddRef)(IWindowForBindingUI *);
    ULONG (*Release)(IWindowForBindingUI *);
    HRESULT (*GetWindow)(IWindowForBindingUI *, const GUID *const, HWND *);
};

struct _REMSECURITY_ATTRIBUTES {
    DWORD nLength;
    DWORD lpSecurityDescriptor;
    BOOL bInheritHandle;
};

struct _ZONEATTRIBUTES {
    ULONG cbSize;
    WCHAR szDisplayName[260];
    WCHAR szDescription[200];
    WCHAR szIconPath[260];
    DWORD dwTemplateMinLevel;
    DWORD dwTemplateRecommended;
    DWORD dwTemplateCurrentLevel;
    DWORD dwFlags;
};

struct _tagBINDINFO {
    ULONG cbSize;
    LPWSTR szExtraInfo;
    STGMEDIUM stgmedData;
    DWORD grfBindInfoF;
    DWORD dwBindVerb;
    LPWSTR szCustomVerb;
    DWORD cbstgmedData;
    DWORD dwOptions;
    DWORD dwOptionsFlags;
    DWORD dwCodePage;
    SECURITY_ATTRIBUTES securityAttributes;
    IID iid;
    IUnknown *pUnk;
    DWORD dwReserved;
};

struct _tagCODEBASEHOLD {
    ULONG cbSize;
    LPWSTR szDistUnit;
    LPWSTR szCodeBase;
    DWORD dwVersionMS;
    DWORD dwVersionLS;
    DWORD dwStyle;
};

struct _tagDATAINFO {
    ULONG ulTotalSize;
    ULONG ulavrPacketSize;
    ULONG ulConnectSpeed;
    ULONG ulProcessorSpeed;
};

struct _tagHIT_LOGGING_INFO {
    DWORD dwStructSize;
    LPSTR lpszLoggedUrlName;
    SYSTEMTIME StartTime;
    SYSTEMTIME EndTime;
    LPSTR lpszExtendedInfo;
};

struct _tagPROTOCOLDATA {
    DWORD grfFlags;
    DWORD dwState;
    LPVOID pData;
    ULONG cbData;
};

struct _tagPROTOCOLFILTERDATA {
    DWORD cbSize;
    IInternetProtocolSink *pProtocolSink;
    IInternetProtocol *pProtocol;
    IUnknown *pUnk;
    DWORD dwFilterFlags;
};

struct _tagRemBINDINFO {
    ULONG cbSize;
    LPWSTR szExtraInfo;
    DWORD grfBindInfoF;
    DWORD dwBindVerb;
    LPWSTR szCustomVerb;
    DWORD cbstgmedData;
    DWORD dwOptions;
    DWORD dwOptionsFlags;
    DWORD dwCodePage;
    REMSECURITY_ATTRIBUTES securityAttributes;
    IID iid;
    IUnknown *pUnk;
    DWORD dwReserved;
};

struct _tagSOFTDISTINFO {
    ULONG cbSize;
    DWORD dwFlags;
    DWORD dwAdState;
    LPWSTR szTitle;
    LPWSTR szAbstract;
    LPWSTR szHREF;
    DWORD dwInstalledVersionMS;
    DWORD dwInstalledVersionLS;
    DWORD dwUpdateVersionMS;
    DWORD dwUpdateVersionLS;
    DWORD dwAdvertisedVersionMS;
    DWORD dwAdvertisedVersionLS;
    DWORD dwReserved;
};

struct tagRemFORMATETC {
    DWORD cfFormat;
    DWORD ptd;
    DWORD dwAspect;
    LONG lindex;
    DWORD tymed;
};

enum __MIDL_IInternetZoneManager_0001 {
    MAX_ZONE_PATH = 260,
    MAX_ZONE_DESCRIPTION = 200
};


#ifdef __cplusplus
}
#endif

#endif

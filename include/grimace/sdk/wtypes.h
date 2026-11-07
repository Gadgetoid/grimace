#ifndef GRIMACE_SDK_WTYPES_H
#define GRIMACE_SDK_WTYPES_H

#include <grimace/sdk/rpcndr.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef WCHAR OLECHAR;
typedef OLECHAR *BSTR;
typedef const OLECHAR *LPCOLESTR;
typedef GUID CLSID;
typedef CLSID *LPCLSID;
typedef OLECHAR *LPOLESTR;
typedef GUID IID;
typedef unsigned short VARTYPE;
typedef WORD CLIPFORMAT;
typedef double DOUBLE;
union tagCY;
typedef union tagCY CY;
typedef short VARIANT_BOOL;
typedef double DATE;
struct tagDEC;
typedef struct tagDEC DECIMAL;
struct tagBLOB;
typedef struct tagBLOB BLOB;
struct tagBSTRBLOB;
typedef struct tagBSTRBLOB BSTRBLOB;
struct _BYTE_BLOB;
typedef struct _BYTE_BLOB BYTE_BLOB;
struct _BYTE_SIZEDARR;
typedef struct _BYTE_SIZEDARR BYTE_SIZEDARR;
struct tagCLIPDATA;
typedef struct tagCLIPDATA CLIPDATA;
enum tagCLSCTX {
    CLSCTX_INPROC_SERVER = 1,
    CLSCTX_INPROC_HANDLER = 2,
    CLSCTX_LOCAL_SERVER = 4,
    CLSCTX_INPROC_SERVER16 = 8,
    CLSCTX_REMOTE_SERVER = 16,
    CLSCTX_INPROC_HANDLER16 = 32,
    CLSCTX_INPROC_SERVERX86 = 64,
    CLSCTX_INPROC_HANDLERX86 = 128
};

typedef enum tagCLSCTX CLSCTX;
struct _COAUTHIDENTITY;
typedef struct _COAUTHIDENTITY COAUTHIDENTITY;
struct _COAUTHINFO;
typedef struct _COAUTHINFO COAUTHINFO;
struct _COSERVERINFO;
typedef struct _COSERVERINFO COSERVERINFO;
enum tagDVASPECT {
    DVASPECT_CONTENT = 1,
    DVASPECT_THUMBNAIL = 2,
    DVASPECT_ICON = 4,
    DVASPECT_DOCPRINT = 8
};

typedef enum tagDVASPECT DVASPECT;
struct _DWORD_BLOB;
typedef struct _DWORD_BLOB DWORD_BLOB;
struct _LONG_SIZEDARR;
typedef struct _LONG_SIZEDARR DWORD_SIZEDARR;
struct _FLAGGED_BYTE_BLOB;
typedef struct _FLAGGED_BYTE_BLOB FLAGGED_BYTE_BLOB;
struct _FLAGGED_WORD_BLOB;
typedef struct _FLAGGED_WORD_BLOB FLAGGED_WORD_BLOB;
typedef GUID FMTID;
struct _GDI_NONREMOTE;
typedef struct _GDI_NONREMOTE GDI_NONREMOTE;
typedef void *HCONTEXT;
typedef void *HMETAFILEPICT;
struct _HYPER_SIZEDARR;
typedef struct _HYPER_SIZEDARR HYPER_SIZEDARR;
typedef struct tagBLOB *LPBLOB;
typedef BSTR *LPBSTR;
typedef struct tagBSTRBLOB *LPBSTRBLOB;
typedef CY *LPCY;
typedef DECIMAL *LPDECIMAL;
typedef FMTID *LPFMTID;
typedef IID *LPIID;
enum tagMEMCTX {
    MEMCTX_TASK = 1,
    MEMCTX_SHARED = 2,
    MEMCTX_MACSYSTEM = 3,
    MEMCTX_UNKNOWN = -1,
    MEMCTX_SAME = -2
};

typedef enum tagMEMCTX MEMCTX;
enum tagMSHCTX {
    MSHCTX_LOCAL = 0,
    MSHCTX_NOSHAREDMEM = 1,
    MSHCTX_DIFFERENTMACHINE = 2,
    MSHCTX_INPROC = 3
};

typedef enum tagMSHCTX MSHCTX;
enum tagMSHLFLAGS {
    MSHLFLAGS_NORMAL = 0,
    MSHLFLAGS_TABLESTRONG = 1,
    MSHLFLAGS_TABLEWEAK = 2,
    MSHLFLAGS_NOPING = 4
};

typedef enum tagMSHLFLAGS MSHLFLAGS;
typedef ULONG PROPID;
typedef LONG SCODE;
typedef SCODE *PSCODE;
struct tagRemHBITMAP;
typedef struct tagRemHBITMAP RemHBITMAP;
struct tagRemBRUSH;
typedef struct tagRemBRUSH RemHBRUSH;
struct tagRemHENHMETAFILE;
typedef struct tagRemHENHMETAFILE RemHENHMETAFILE;
struct tagRemHGLOBAL;
typedef struct tagRemHGLOBAL RemHGLOBAL;
struct tagRemHMETAFILEPICT;
typedef struct tagRemHMETAFILEPICT RemHMETAFILEPICT;
struct tagRemHPALETTE;
typedef struct tagRemHPALETTE RemHPALETTE;
struct _RemotableHandle;
typedef struct _RemotableHandle RemotableHandle;
enum tagSTATFLAG {
    STATFLAG_DEFAULT = 0,
    STATFLAG_NONAME = 1,
    STATFLAG_NOOPEN = 2
};

typedef enum tagSTATFLAG STATFLAG;
enum tagSTGC {
    STGC_DEFAULT = 0,
    STGC_OVERWRITE = 1,
    STGC_ONLYIFCURRENT = 2,
    STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4
};

typedef enum tagSTGC STGC;
enum tagSTGMOVE {
    STGMOVE_MOVE = 0,
    STGMOVE_COPY = 1,
    STGMOVE_SHALLOWCOPY = 2
};

typedef enum tagSTGMOVE STGMOVE;
typedef BYTE_BLOB *UP_BYTE_BLOB;
typedef DWORD_BLOB *UP_DWORD_BLOB;
typedef FLAGGED_BYTE_BLOB *UP_FLAGGED_BYTE_BLOB;
typedef FLAGGED_WORD_BLOB *UP_FLAGGED_WORD_BLOB;
struct _WORD_BLOB;
typedef struct _WORD_BLOB WORD_BLOB;
typedef WORD_BLOB *UP_WORD_BLOB;
struct _SHORT_SIZEDARR;
typedef struct _SHORT_SIZEDARR WORD_SIZEDARR;
struct _remoteMETAFILEPICT;
typedef struct _remoteMETAFILEPICT remoteMETAFILEPICT;
struct tagrpcLOGPALETTE;
typedef struct tagrpcLOGPALETTE rpcLOGPALETTE;
struct _userBITMAP;
typedef struct _userBITMAP userBITMAP;
struct _userCLIPFORMAT;
typedef struct _userCLIPFORMAT userCLIPFORMAT;
struct _userHBITMAP;
typedef struct _userHBITMAP userHBITMAP;
struct _userHENHMETAFILE;
typedef struct _userHENHMETAFILE userHENHMETAFILE;
struct _userHGLOBAL;
typedef struct _userHGLOBAL userHGLOBAL;
struct _userHMETAFILE;
typedef struct _userHMETAFILE userHMETAFILE;
struct _userHMETAFILEPICT;
typedef struct _userHMETAFILEPICT userHMETAFILEPICT;
struct _userHPALETTE;
typedef struct _userHPALETTE userHPALETTE;
typedef FLAGGED_WORD_BLOB *wireBSTR;
typedef userCLIPFORMAT *wireCLIPFORMAT;
typedef RemotableHandle *wireHACCEL;
typedef userHBITMAP *wireHBITMAP;
typedef RemotableHandle *wireHBRUSH;
typedef RemotableHandle *wireHDC;
typedef userHENHMETAFILE *wireHENHMETAFILE;
typedef RemotableHandle *wireHFONT;
typedef userHGLOBAL *wireHGLOBAL;
typedef RemotableHandle *wireHICON;
typedef RemotableHandle *wireHMENU;
typedef userHMETAFILE *wireHMETAFILE;
typedef userHMETAFILEPICT *wireHMETAFILEPICT;
typedef userHPALETTE *wireHPALETTE;
typedef RemotableHandle *wireHWND;
struct _BYTE_BLOB {
    unsigned long clSize;
    byte abData[1];
} __attribute__((packed, aligned(4)));

struct _BYTE_SIZEDARR {
    unsigned long clSize;
    byte *pData;
} __attribute__((packed, aligned(4)));

struct _COAUTHIDENTITY {
    USHORT *User;
    ULONG UserLength;
    USHORT *Domain;
    ULONG DomainLength;
    USHORT *Password;
    ULONG PasswordLength;
    ULONG Flags;
} __attribute__((packed, aligned(4)));

struct _COAUTHINFO {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    LPWSTR pwszServerPrincName;
    DWORD dwAuthnLevel;
    DWORD dwImpersonationLevel;
    COAUTHIDENTITY *pAuthIdentityData;
    DWORD dwCapabilities;
} __attribute__((packed, aligned(4)));

struct _COSERVERINFO {
    DWORD dwReserved1;
    LPWSTR pwszName;
    COAUTHINFO *pAuthInfo;
    DWORD dwReserved2;
} __attribute__((packed, aligned(4)));

struct _DWORD_BLOB {
    unsigned long clSize;
    unsigned long alData[1];
} __attribute__((packed, aligned(4)));

struct _FLAGGED_BYTE_BLOB {
    unsigned long fFlags;
    unsigned long clSize;
    byte abData[1];
} __attribute__((packed, aligned(4)));

struct _FLAGGED_WORD_BLOB {
    unsigned long fFlags;
    unsigned long clSize;
    unsigned short asData[1];
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0002;
union __MIDL_IWinTypes_0002 {
    long hInproc;
    DWORD_BLOB *hRemote;
} __attribute__((packed, aligned(4)));

struct _GDI_NONREMOTE {
    long fContext;
    union __MIDL_IWinTypes_0002 u;
} __attribute__((packed, aligned(4)));

struct _HYPER_SIZEDARR {
    unsigned long clSize;
    long long *pData;
} __attribute__((packed, aligned(4)));

struct _LONG_SIZEDARR {
    unsigned long clSize;
    unsigned long *pData;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0009;
union __MIDL_IWinTypes_0009 {
    long hInproc;
    long hRemote;
} __attribute__((packed, aligned(4)));

struct _RemotableHandle {
    long fContext;
    union __MIDL_IWinTypes_0009 u;
} __attribute__((packed, aligned(4)));

struct _SHORT_SIZEDARR {
    unsigned long clSize;
    unsigned short *pData;
} __attribute__((packed, aligned(4)));

struct _WORD_BLOB {
    unsigned long clSize;
    unsigned short asData[1];
} __attribute__((packed, aligned(4)));

struct _remoteMETAFILEPICT {
    long mm;
    long xExt;
    long yExt;
    userHMETAFILE *hMF;
} __attribute__((packed, aligned(4)));

struct _userBITMAP {
    LONG bmType;
    LONG bmWidth;
    LONG bmHeight;
    LONG bmWidthBytes;
    WORD bmPlanes;
    WORD bmBitsPixel;
    ULONG cbSize;
    byte pBuffer[1];
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0001;
union __MIDL_IWinTypes_0001 {
    DWORD dwValue;
    wchar_t *pwszName;
} __attribute__((packed, aligned(4)));

struct _userCLIPFORMAT {
    long fContext;
    union __MIDL_IWinTypes_0001 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0007;
union __MIDL_IWinTypes_0007 {
    long hInproc;
    userBITMAP *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHBITMAP {
    long fContext;
    union __MIDL_IWinTypes_0007 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0006;
union __MIDL_IWinTypes_0006 {
    long hInproc;
    BYTE_BLOB *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHENHMETAFILE {
    long fContext;
    union __MIDL_IWinTypes_0006 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0003;
union __MIDL_IWinTypes_0003 {
    long hInproc;
    FLAGGED_BYTE_BLOB *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHGLOBAL {
    long fContext;
    union __MIDL_IWinTypes_0003 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0004;
union __MIDL_IWinTypes_0004 {
    long hInproc;
    BYTE_BLOB *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHMETAFILE {
    long fContext;
    union __MIDL_IWinTypes_0004 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0005;
union __MIDL_IWinTypes_0005 {
    long hInproc;
    remoteMETAFILEPICT *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHMETAFILEPICT {
    long fContext;
    union __MIDL_IWinTypes_0005 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IWinTypes_0008;
union __MIDL_IWinTypes_0008 {
    long hInproc;
    rpcLOGPALETTE *hRemote;
    long hGlobal;
} __attribute__((packed, aligned(4)));

struct _userHPALETTE {
    long fContext;
    union __MIDL_IWinTypes_0008 u;
} __attribute__((packed, aligned(4)));

union tagCY {
    struct {
        unsigned long Lo;
        long Hi;
    };
    LONGLONG int64;
} __attribute__((packed, aligned(8)));

struct tagDEC {
    USHORT wReserved;
    union {
        struct {
            BYTE scale;
            BYTE sign;
        };
        USHORT signscale;
    };
    ULONG Hi32;
    union {
        struct {
            ULONG Lo32;
            ULONG Mid32;
        };
        ULONGLONG Lo64;
    };
} __attribute__((packed, aligned(8)));

struct tagBLOB {
    ULONG cbSize;
    BYTE *pBlobData;
} __attribute__((packed, aligned(4)));

struct tagBSTRBLOB {
    ULONG cbSize;
    BYTE *pData;
} __attribute__((packed, aligned(4)));

struct tagCLIPDATA {
    ULONG cbSize;
    long ulClipFmt;
    BYTE *pClipData;
} __attribute__((packed, aligned(4)));

struct tagRemBRUSH {
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagRemHBITMAP {
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagRemHENHMETAFILE {
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagRemHGLOBAL {
    long fNullHGlobal;
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagRemHMETAFILEPICT {
    long mm;
    long xExt;
    long yExt;
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagRemHPALETTE {
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagrpcLOGPALETTE {
    WORD palVersion;
    WORD palNumEntries;
    PALETTEENTRY palPalEntry[1];
} __attribute__((packed, aligned(2)));

enum VARENUM {
    VT_EMPTY = 0,
    VT_NULL = 1,
    VT_I2 = 2,
    VT_I4 = 3,
    VT_R4 = 4,
    VT_R8 = 5,
    VT_CY = 6,
    VT_DATE = 7,
    VT_BSTR = 8,
    VT_DISPATCH = 9,
    VT_ERROR = 10,
    VT_BOOL = 11,
    VT_VARIANT = 12,
    VT_UNKNOWN = 13,
    VT_DECIMAL = 14,
    VT_I1 = 16,
    VT_UI1 = 17,
    VT_UI2 = 18,
    VT_UI4 = 19,
    VT_I8 = 20,
    VT_UI8 = 21,
    VT_INT = 22,
    VT_UINT = 23,
    VT_VOID = 24,
    VT_HRESULT = 25,
    VT_PTR = 26,
    VT_SAFEARRAY = 27,
    VT_CARRAY = 28,
    VT_USERDEFINED = 29,
    VT_LPSTR = 30,
    VT_LPWSTR = 31,
    VT_RECORD = 36,
    VT_FILETIME = 64,
    VT_BLOB = 65,
    VT_STREAM = 66,
    VT_STORAGE = 67,
    VT_STREAMED_OBJECT = 68,
    VT_STORED_OBJECT = 69,
    VT_BLOB_OBJECT = 70,
    VT_CF = 71,
    VT_CLSID = 72,
    VT_BSTR_BLOB = 4095,
    VT_VECTOR = 4096,
    VT_ARRAY = 8192,
    VT_BYREF = 16384,
    VT_RESERVED = 32768,
    VT_ILLEGAL = 65535,
    VT_ILLEGALMASKED = 4095,
    VT_TYPEMASK = 4095
};


#ifdef __cplusplus
}
#endif

#endif

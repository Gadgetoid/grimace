#ifndef GRIMACE_SDK_OBJBASE_H
#define GRIMACE_SDK_OBJBASE_H

#include <grimace/sdk/rpcndr.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Looks up the class identifier registered for a programmatic identifier.
 *
 * @param lpszProgID Programmatic identifier to look up.
 * @param lpclsid Receives the class identifier.
 * @return S_OK, or a COM/registry error such as REGDB_E_CLASSNOTREG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CLSIDFromProgID(LPCOLESTR lpszProgID, LPCLSID lpclsid);
/**
 * Converts a textual class identifier to a CLSID.
 *
 * @param lpsz Null-terminated class identifier string.
 * @param pclsid Receives the parsed CLSID.
 * @return S_OK, or CO_E_CLASSSTRING for malformed text.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CLSIDFromString(LPOLESTR lpsz, LPCLSID pclsid);
/**
 * Creates one instance of a registered COM class and returns an interface.
 *
 * Windows CE supports only CLSCTX_INPROC_SERVER. Aggregation requires
 * class support and a non-NULL controlling IUnknown.
 *
 * @param rclsid Class identifier to instantiate.
 * @param pUnkOuter Controlling IUnknown for aggregation, or NULL.
 * @param dwClsContext CLSCTX_INPROC_SERVER.
 * @param riid Interface identifier to request.
 * @param ppv Receives the requested interface pointer.
 * @return S_OK, or a COM activation error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CoCreateInstance(const CLSID *const rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID *const riid, LPVOID *ppv);
/**
 * Not supported by the Windows CE implementation.
 *
 * Use CoFreeUnusedLibraries to release automatically unloadable COM DLLs.
 *
 * @param hInst Library handle.
 *
 * @note Windows CE 2.0 and later.
 */
void CoFreeLibrary(HINSTANCE hInst);
/**
 * Unloads automatically loaded COM DLLs that are no longer in use.
 *
 * The loader asks each eligible DLL's DllCanUnloadNow export whether it
 * can be unloaded. Call periodically or during idle processing.
 *
 * @note Windows CE 2.0 and later.
 */
void CoFreeUnusedLibraries(void);
/**
 * Retrieves an interface on a registered COM class object.
 *
 * Use this when creating multiple objects through one class factory.
 * Windows CE supports only CLSCTX_INPROC_SERVER; pvReserved must be NULL.
 * Release the returned interface when finished.
 *
 * @param rclsid Class identifier of the class object.
 * @param dwClsContext CLSCTX_INPROC_SERVER.
 * @param pvReserved Reserved; set to NULL.
 * @param riid Interface identifier, usually IID_IClassFactory.
 * @param ppv Receives the requested interface pointer.
 * @return S_OK, or a COM registration or interface error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CoGetClassObject(const CLSID *const rclsid, DWORD dwClsContext, LPVOID pvReserved, const IID *const riid, LPVOID *ppv);
/**
 * Initializes COM for the calling thread.
 *
 * Windows CE supports only COINIT_MULTITHREADED. Balance every successful
 * call, including S_FALSE, with CoUninitialize on the same thread.
 *
 * @param pvReserved Reserved; set to NULL.
 * @param dwCoInit COINIT_MULTITHREADED.
 * @return S_OK on initialization, S_FALSE if already initialized, or an
 *         error code.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
/**
 * Loads a COM server DLL into the calling process.
 *
 * Normally called internally by CoGetClassObject. bAutoFree is ignored;
 * Windows CE tracks library references for COM unloading.
 *
 * @param lpszLibName DLL name.
 * @param bAutoFree Ignored.
 * @return Module handle, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
HINSTANCE CoLoadLibrary(LPOLESTR lpszLibName, BOOL bAutoFree);
/**
 * Allocates memory using the COM task allocator.
 *
 * Contents are uninitialized. Free the returned block with CoTaskMemFree.
 *
 * @param cb Allocation size in bytes.
 * @return Allocated block, or NULL if allocation fails.
 *
 * @note Windows CE 2.0 and later.
 */
LPVOID CoTaskMemAlloc(ULONG cb);
/**
 * Frees a block allocated by CoTaskMemAlloc or CoTaskMemRealloc.
 *
 * Passing NULL has no effect.
 *
 * @param pv Block to free, or NULL.
 *
 * @note Windows CE 2.0 and later.
 */
void CoTaskMemFree(LPVOID pv);
/**
 * Changes the size of a COM task-memory allocation.
 *
 * The block may move; preserve the returned pointer. If pv is NULL, this
 * allocates a new block. A zero size frees a non-NULL block and returns
 * NULL.
 *
 * @param pv Existing task-memory block, or NULL.
 * @param cb New size in bytes.
 * @return Resized block, or NULL on allocation failure or when freeing.
 *
 * @note Windows CE 2.0 and later.
 */
LPVOID CoTaskMemRealloc(LPVOID pv, ULONG cb);
/**
 * Balances a successful CoInitializeEx call on the current thread.
 *
 * Call once for every successful initialization. Call during shutdown,
 * after the thread has finished its COM work.
 *
 * @note Windows CE 2.0 and later.
 */
void CoUninitialize(void);
struct IBindCtx;
typedef struct IBindCtx IBindCtx;
struct IEnumFORMATETC;
typedef struct IEnumFORMATETC IEnumFORMATETC;
typedef IBindCtx *LPBC;
/**
 * Creates a bind context for moniker binding.
 *
 * The returned IBindCtx holds references to objects bound through it.
 * Release it promptly with its IUnknown::Release method.
 *
 * @param reserved Reserved; set to zero.
 * @param ppbc Receives the IBindCtx interface pointer.
 * @return S_OK, or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CreateBindCtx(DWORD reserved, LPBC *ppbc);
struct IStream;
typedef struct IStream IStream;
typedef IStream *LPSTREAM;
struct IMoniker;
typedef struct IMoniker IMoniker;
typedef IMoniker *LPMONIKER;
/**
 * Implemented by an in-process COM server, which exports it; COM calls it
 * to ask whether the DLL can be unloaded.
 *
 * @return S_OK if no objects or locks are outstanding, S_FALSE if the DLL
 *         is still in use.
 */
HRESULT DllCanUnloadNow(void);
/**
 * DLL entry point implemented by a COM server to expose its class factory.
 *
 * CoGetClassObject calls this export when loading an in-process server;
 * clients should call CoGetClassObject instead of calling this directly.
 *
 * @param rclsid Class identifier requested.
 * @param riid Interface identifier requested, usually IID_IClassFactory.
 * @param ppv Receives the requested interface pointer, or NULL on error.
 * @return S_OK, CLASS_E_CLASSNOTAVAILABLE, or a standard COM error.
 */
HRESULT DllGetClassObject(const CLSID *const rclsid, const IID *const riid, LPVOID *ppv);
struct IDataObject;
typedef struct IDataObject IDataObject;
typedef IDataObject *LPDATAOBJECT;
/**
 * Finds the CLSID registered for a file extension.
 *
 * @param szFilename File name to examine.
 * @param pclsid Receives the associated class identifier.
 * @return S_OK, MK_E_CANTOPENFILE, MK_E_INVALIDEXTENSION, or a file
 *         system error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT GetClassFile(LPCOLESTR szFilename, CLSID *pclsid);
struct tagFORMATETC;
typedef struct tagFORMATETC *LPFORMATETC;
struct IStorage;
typedef struct IStorage IStorage;
typedef IStorage *LPSTORAGE;
struct IPersistStorage;
typedef struct IPersistStorage IPersistStorage;
typedef IPersistStorage *LPPERSISTSTORAGE;
struct tagSTGMEDIUM;
typedef struct tagSTGMEDIUM uSTGMEDIUM;
typedef uSTGMEDIUM STGMEDIUM;
typedef STGMEDIUM *LPSTGMEDIUM;
struct IMalloc;
typedef struct IMalloc IMalloc;
typedef IMalloc *LPMALLOC;
/**
 * Creates a compound-file storage object.
 *
 * Pass NULL for pwcsName to create a uniquely named temporary file; the
 * caller must delete it unless STGM_DELETEONRELEASE is used. grfMode
 * controls access, sharing and create/overwrite behavior.
 *
 * @param pwcsName File path, or NULL for a temporary compound file.
 * @param grfMode STGM access and creation flags.
 * @param reserved Reserved; set to zero.
 * @param ppstgOpen Receives the IStorage interface pointer.
 * @return S_OK, STG_* error, or a wrapped file-system error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StgCreateDocfile(const OLECHAR *pwcsName, DWORD grfMode, DWORD reserved, IStorage **ppstgOpen);
struct ILockBytes;
typedef struct ILockBytes ILockBytes;
/**
 * Creates a compound-file storage object over an ILockBytes implementation.
 *
 * @param plkbyt Underlying byte-array object.
 * @param grfMode STGM access and creation flags.
 * @param reserved Reserved; set to zero.
 * @param ppstgOpen Receives the IStorage interface pointer.
 * @return S_OK, STG_* error, or an ILockBytes error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StgCreateDocfileOnILockBytes(ILockBytes *plkbyt, DWORD grfMode, DWORD reserved, IStorage **ppstgOpen);
typedef OLECHAR **SNB;
/**
 * Opens an existing root compound-file storage object.
 *
 * This opens root storage only; open nested storage through its parent
 * IStorage. Opening with shared write access may require a costly snapshot.
 *
 * @param pwcsName Storage file path; ignored when pstgPriority is non-NULL.
 * @param pstgPriority Previously opened priority storage, or NULL.
 * @param grfMode STGM access and sharing flags.
 * @param snbExclude Optional names to empty while opening.
 * @param reserved Reserved; set to zero.
 * @param ppstgOpen Receives the opened IStorage interface pointer.
 * @return S_OK, STG_* error, or a wrapped file-system error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StgOpenStorage(const OLECHAR *pwcsName, IStorage *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstgOpen);
/**
 * Opens root compound-file storage backed by an ILockBytes object.
 *
 * The storage must have been created on that byte array. If priority
 * storage is supplied, use the returned IStorage; the input priority
 * storage becomes invalid.
 *
 * @param plkbyt Underlying byte-array object.
 * @param pstgPriority Previously opened priority storage, or NULL.
 * @param grfMode STGM access and sharing flags.
 * @param snbExclude Optional names to empty while opening.
 * @param reserved Reserved; set to zero.
 * @param ppstgOpen Receives the opened IStorage interface pointer.
 * @return S_OK, STG_* error, or an ILockBytes error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StgOpenStorageOnILockBytes(ILockBytes *plkbyt, IStorage *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstgOpen);
/**
 * Converts a CLSID to a printable string.
 *
 * Free the returned string with CoTaskMemFree.
 *
 * @param rclsid Class identifier to convert.
 * @param lplpsz Receives the allocated null-terminated string.
 * @return S_OK, or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StringFromCLSID(const CLSID *const rclsid, LPOLESTR *lplpsz);
/**
 * Formats a GUID as a braced string.
 *
 * The buffer must hold the full string and terminator; a too-small buffer
 * returns zero.
 *
 * @param rguid GUID to convert.
 * @param lpsz Receives the null-terminated string.
 * @param cbMax Buffer capacity in characters.
 * @return Character count including the terminator, or zero if too small.
 *
 * @note Windows CE 2.0 and later.
 */
int StringFromGUID2(const GUID *const rguid, LPOLESTR lpsz, int cbMax);
/**
 * Converts an interface identifier to a printable string.
 *
 * Free the returned string with CoTaskMemFree.
 *
 * @param rclsid Interface identifier to convert.
 * @param lplpsz Receives the allocated null-terminated string.
 * @return S_OK, or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT StringFromIID(const IID *const rclsid, LPOLESTR *lplpsz);
enum tagADVF {
    ADVF_NODATA = 1,
    ADVF_PRIMEFIRST = 2,
    ADVF_ONLYONCE = 4,
    ADVF_DATAONSTOP = 64,
    ADVFCACHE_NOHANDLER = 8,
    ADVFCACHE_FORCEBUILTIN = 16,
    ADVFCACHE_ONSAVE = 32
};

typedef enum tagADVF ADVF;
typedef STGMEDIUM ASYNC_STGMEDIUM;
enum tagBIND_FLAGS {
    BIND_MAYBOTHERUSER = 1,
    BIND_JUSTTESTEXISTENCE = 2
};

typedef enum tagBIND_FLAGS BIND_FLAGS;
struct tagBIND_OPTS;
typedef struct tagBIND_OPTS BIND_OPTS;
struct tagBIND_OPTS2;
typedef struct tagBIND_OPTS2 BIND_OPTS2;
struct tagCABOOL;
typedef struct tagCABOOL CABOOL;
struct tagCABSTR;
typedef struct tagCABSTR CABSTR;
struct tagCABSTRBLOB;
typedef struct tagCABSTRBLOB CABSTRBLOB;
struct tagCACLIPDATA;
typedef struct tagCACLIPDATA CACLIPDATA;
struct tagCACLSID;
typedef struct tagCACLSID CACLSID;
struct tagCACY;
typedef struct tagCACY CACY;
struct tagCADATE;
typedef struct tagCADATE CADATE;
struct tagCADBL;
typedef struct tagCADBL CADBL;
struct tagCAFILETIME;
typedef struct tagCAFILETIME CAFILETIME;
struct tagCAFLT;
typedef struct tagCAFLT CAFLT;
struct tagCAH;
typedef struct tagCAH CAH;
struct tagCAI;
typedef struct tagCAI CAI;
struct tagCAL;
typedef struct tagCAL CAL;
enum tagCALLTYPE {
    CALLTYPE_TOPLEVEL = 1,
    CALLTYPE_NESTED = 2,
    CALLTYPE_ASYNC = 3,
    CALLTYPE_TOPLEVEL_CALLPENDING = 4,
    CALLTYPE_ASYNC_CALLPENDING = 5
};

typedef enum tagCALLTYPE CALLTYPE;
struct tagCALPSTR;
typedef struct tagCALPSTR CALPSTR;
struct tagCALPWSTR;
typedef struct tagCALPWSTR CALPWSTR;
struct tagCAPROPVARIANT;
typedef struct tagCAPROPVARIANT CAPROPVARIANT;
struct tagCASCODE;
typedef struct tagCASCODE CASCODE;
struct tagCAUB;
typedef struct tagCAUB CAUB;
struct tagCAUH;
typedef struct tagCAUH CAUH;
struct tagCAUI;
typedef struct tagCAUI CAUI;
struct tagCAUL;
typedef struct tagCAUL CAUL;
enum tagCOINIT {
    COINIT_APARTMENTTHREADED = 2,
    COINIT_MULTITHREADED = 0,
    COINIT_DISABLE_OLE1DDE = 4,
    COINIT_SPEED_OVER_MEMORY = 8
};

typedef enum tagCOINIT COINIT;
enum tagDATADIR {
    DATADIR_GET = 1,
    DATADIR_SET = 2
};

typedef enum tagDATADIR DATADIR;
struct tagDVTARGETDEVICE;
typedef struct tagDVTARGETDEVICE DVTARGETDEVICE;
enum tagEOLE_AUTHENTICATION_CAPABILITIES {
    EOAC_NONE = 0,
    EOAC_MUTUAL_AUTH = 1,
    EOAC_SECURE_REFS = 2,
    EOAC_ACCESS_CONTROL = 4,
    EOAC_APPID = 8,
    EOAC_DYNAMIC = 16
};

typedef enum tagEOLE_AUTHENTICATION_CAPABILITIES EOLE_AUTHENTICATION_CAPABILITIES;
enum tagEXTCONN {
    EXTCONN_STRONG = 1,
    EXTCONN_WEAK = 2,
    EXTCONN_CALLABLE = 4
};

typedef enum tagEXTCONN EXTCONN;
struct _FLAG_STGMEDIUM;
typedef struct _FLAG_STGMEDIUM FLAG_STGMEDIUM;
typedef struct tagFORMATETC FORMATETC;
struct _GDI_OBJECT;
typedef struct _GDI_OBJECT GDI_OBJECT;
struct IAdviseSink;
typedef struct IAdviseSink IAdviseSink;
struct IAdviseSink2;
typedef struct IAdviseSink2 IAdviseSink2;
struct IAdviseSink2Vtbl;
typedef struct IAdviseSink2Vtbl IAdviseSink2Vtbl;
struct IAdviseSinkVtbl;
typedef struct IAdviseSinkVtbl IAdviseSinkVtbl;
struct IBindCtxVtbl;
typedef struct IBindCtxVtbl IBindCtxVtbl;
struct IChannelHook;
typedef struct IChannelHook IChannelHook;
struct IChannelHookVtbl;
typedef struct IChannelHookVtbl IChannelHookVtbl;
struct IClassActivator;
typedef struct IClassActivator IClassActivator;
struct IClassActivatorVtbl;
typedef struct IClassActivatorVtbl IClassActivatorVtbl;
struct IClientSecurity;
typedef struct IClientSecurity IClientSecurity;
struct IClientSecurityVtbl;
typedef struct IClientSecurityVtbl IClientSecurityVtbl;
struct IComBinding;
typedef struct IComBinding IComBinding;
struct IComBindingVtbl;
typedef struct IComBindingVtbl IComBindingVtbl;
struct IDataAdviseHolder;
typedef struct IDataAdviseHolder IDataAdviseHolder;
struct IDataAdviseHolderVtbl;
typedef struct IDataAdviseHolderVtbl IDataAdviseHolderVtbl;
struct IDataObjectVtbl;
typedef struct IDataObjectVtbl IDataObjectVtbl;
struct IEnumFORMATETCVtbl;
typedef struct IEnumFORMATETCVtbl IEnumFORMATETCVtbl;
struct IEnumMoniker;
typedef struct IEnumMoniker IEnumMoniker;
struct IEnumMonikerVtbl;
typedef struct IEnumMonikerVtbl IEnumMonikerVtbl;
struct IEnumSTATDATA;
typedef struct IEnumSTATDATA IEnumSTATDATA;
struct IEnumSTATDATAVtbl;
typedef struct IEnumSTATDATAVtbl IEnumSTATDATAVtbl;
struct IEnumSTATPROPSETSTG;
typedef struct IEnumSTATPROPSETSTG IEnumSTATPROPSETSTG;
struct IEnumSTATPROPSETSTGVtbl;
typedef struct IEnumSTATPROPSETSTGVtbl IEnumSTATPROPSETSTGVtbl;
struct IEnumSTATPROPSTG;
typedef struct IEnumSTATPROPSTG IEnumSTATPROPSTG;
struct IEnumSTATPROPSTGVtbl;
typedef struct IEnumSTATPROPSTGVtbl IEnumSTATPROPSTGVtbl;
struct IEnumSTATSTG;
typedef struct IEnumSTATSTG IEnumSTATSTG;
struct IEnumSTATSTGVtbl;
typedef struct IEnumSTATSTGVtbl IEnumSTATSTGVtbl;
struct IEnumString;
typedef struct IEnumString IEnumString;
struct IEnumStringVtbl;
typedef struct IEnumStringVtbl IEnumStringVtbl;
struct IEnumUnknown;
typedef struct IEnumUnknown IEnumUnknown;
struct IEnumUnknownVtbl;
typedef struct IEnumUnknownVtbl IEnumUnknownVtbl;
struct IExternalConnection;
typedef struct IExternalConnection IExternalConnection;
struct IExternalConnectionVtbl;
typedef struct IExternalConnectionVtbl IExternalConnectionVtbl;
struct IFillLockBytes;
typedef struct IFillLockBytes IFillLockBytes;
struct IFillLockBytesVtbl;
typedef struct IFillLockBytesVtbl IFillLockBytesVtbl;
struct IGlobalInterfaceTable;
typedef struct IGlobalInterfaceTable IGlobalInterfaceTable;
struct IGlobalInterfaceTableVtbl;
typedef struct IGlobalInterfaceTableVtbl IGlobalInterfaceTableVtbl;
struct ILayoutStorage;
typedef struct ILayoutStorage ILayoutStorage;
struct ILayoutStorageVtbl;
typedef struct ILayoutStorageVtbl ILayoutStorageVtbl;
struct ILockBytesVtbl;
typedef struct ILockBytesVtbl ILockBytesVtbl;
struct IMallocSpy;
typedef struct IMallocSpy IMallocSpy;
struct IMallocSpyVtbl;
typedef struct IMallocSpyVtbl IMallocSpyVtbl;
struct IMallocVtbl;
typedef struct IMallocVtbl IMallocVtbl;
struct IMarshal;
typedef struct IMarshal IMarshal;
struct IMarshalVtbl;
typedef struct IMarshalVtbl IMarshalVtbl;
struct IMessageFilter;
typedef struct IMessageFilter IMessageFilter;
struct IMessageFilterVtbl;
typedef struct IMessageFilterVtbl IMessageFilterVtbl;
struct IMonikerVtbl;
typedef struct IMonikerVtbl IMonikerVtbl;
struct IMultiQI;
typedef struct IMultiQI IMultiQI;
struct IMultiQIVtbl;
typedef struct IMultiQIVtbl IMultiQIVtbl;
struct tagINTERFACEINFO;
typedef struct tagINTERFACEINFO INTERFACEINFO;
struct IPSFactoryBuffer;
typedef struct IPSFactoryBuffer IPSFactoryBuffer;
struct IPSFactoryBufferVtbl;
typedef struct IPSFactoryBufferVtbl IPSFactoryBufferVtbl;
struct IPersist;
typedef struct IPersist IPersist;
struct IPersistFile;
typedef struct IPersistFile IPersistFile;
struct IPersistFileVtbl;
typedef struct IPersistFileVtbl IPersistFileVtbl;
struct IPersistStorageVtbl;
typedef struct IPersistStorageVtbl IPersistStorageVtbl;
struct IPersistStream;
typedef struct IPersistStream IPersistStream;
struct IPersistStreamVtbl;
typedef struct IPersistStreamVtbl IPersistStreamVtbl;
struct IPersistVtbl;
typedef struct IPersistVtbl IPersistVtbl;
struct IProgressNotify;
typedef struct IProgressNotify IProgressNotify;
struct IProgressNotifyVtbl;
typedef struct IProgressNotifyVtbl IProgressNotifyVtbl;
struct IPropertySetStorage;
typedef struct IPropertySetStorage IPropertySetStorage;
struct IPropertySetStorageVtbl;
typedef struct IPropertySetStorageVtbl IPropertySetStorageVtbl;
struct IPropertyStorage;
typedef struct IPropertyStorage IPropertyStorage;
struct IPropertyStorageVtbl;
typedef struct IPropertyStorageVtbl IPropertyStorageVtbl;
struct IROTData;
typedef struct IROTData IROTData;
struct IROTDataVtbl;
typedef struct IROTDataVtbl IROTDataVtbl;
struct IRootStorage;
typedef struct IRootStorage IRootStorage;
struct IRootStorageVtbl;
typedef struct IRootStorageVtbl IRootStorageVtbl;
struct IRpcChannelBuffer;
typedef struct IRpcChannelBuffer IRpcChannelBuffer;
struct IRpcChannelBuffer2;
typedef struct IRpcChannelBuffer2 IRpcChannelBuffer2;
struct IRpcChannelBuffer2Vtbl;
typedef struct IRpcChannelBuffer2Vtbl IRpcChannelBuffer2Vtbl;
struct IRpcChannelBufferVtbl;
typedef struct IRpcChannelBufferVtbl IRpcChannelBufferVtbl;
struct IRpcOptions;
typedef struct IRpcOptions IRpcOptions;
struct IRpcOptionsVtbl;
typedef struct IRpcOptionsVtbl IRpcOptionsVtbl;
struct IRpcProxyBuffer;
typedef struct IRpcProxyBuffer IRpcProxyBuffer;
struct IRpcProxyBufferVtbl;
typedef struct IRpcProxyBufferVtbl IRpcProxyBufferVtbl;
struct IRpcStubBuffer;
typedef struct IRpcStubBuffer IRpcStubBuffer;
struct IRpcStubBufferVtbl;
typedef struct IRpcStubBufferVtbl IRpcStubBufferVtbl;
struct IRunnableObject;
typedef struct IRunnableObject IRunnableObject;
struct IRunnableObjectVtbl;
typedef struct IRunnableObjectVtbl IRunnableObjectVtbl;
struct IRunningObjectTable;
typedef struct IRunningObjectTable IRunningObjectTable;
struct IRunningObjectTableVtbl;
typedef struct IRunningObjectTableVtbl IRunningObjectTableVtbl;
struct ISequentialStream;
typedef struct ISequentialStream ISequentialStream;
struct ISequentialStreamVtbl;
typedef struct ISequentialStreamVtbl ISequentialStreamVtbl;
struct IServerSecurity;
typedef struct IServerSecurity IServerSecurity;
struct IServerSecurityVtbl;
typedef struct IServerSecurityVtbl IServerSecurityVtbl;
struct IStdMarshalInfo;
typedef struct IStdMarshalInfo IStdMarshalInfo;
struct IStdMarshalInfoVtbl;
typedef struct IStdMarshalInfoVtbl IStdMarshalInfoVtbl;
struct IStorageVtbl;
typedef struct IStorageVtbl IStorageVtbl;
struct IStreamVtbl;
typedef struct IStreamVtbl IStreamVtbl;
struct ISurrogate;
typedef struct ISurrogate ISurrogate;
struct ISurrogateVtbl;
typedef struct ISurrogateVtbl ISurrogateVtbl;
enum tagLOCKTYPE {
    LOCK_WRITE = 1,
    LOCK_EXCLUSIVE = 2,
    LOCK_ONLYONCE = 4
};

typedef enum tagLOCKTYPE LOCKTYPE;
typedef IAdviseSink *LPADVISESINK;
typedef IAdviseSink2 *LPADVISESINK2;
typedef IBindCtx *LPBINDCTX;
typedef struct tagBIND_OPTS *LPBIND_OPTS;
typedef struct tagBIND_OPTS2 *LPBIND_OPTS2;
typedef CLIPFORMAT *LPCLIPFORMAT;
typedef IDataAdviseHolder *LPDATAADVISEHOLDER;
typedef IEnumFORMATETC *LPENUMFORMATETC;
typedef IEnumMoniker *LPENUMMONIKER;
typedef IEnumSTATDATA *LPENUMSTATDATA;
typedef IEnumSTATPROPSETSTG *LPENUMSTATPROPSETSTG;
typedef IEnumSTATPROPSTG *LPENUMSTATPROPSTG;
typedef IEnumSTATSTG *LPENUMSTATSTG;
typedef IEnumString *LPENUMSTRING;
typedef IEnumUnknown *LPENUMUNKNOWN;
typedef IExternalConnection *LPEXTERNALCONNECTION;
typedef HRESULT (*LPFNCANUNLOADNOW)(void);
typedef HRESULT (*LPFNGETCLASSOBJECT)(const CLSID *const, const IID *const, LPVOID *);
typedef int *LPGLOBALINTERFACETABLE;
typedef struct tagINTERFACEINFO *LPINTERFACEINFO;
typedef ILockBytes *LPLOCKBYTES;
typedef IMallocSpy *LPMALLOCSPY;
typedef IMarshal *LPMARSHAL;
typedef IMessageFilter *LPMESSAGEFILTER;
typedef IMultiQI *LPMULTIQI;
typedef IPersist *LPPERSIST;
typedef IPersistFile *LPPERSISTFILE;
typedef IPersistStream *LPPERSISTSTREAM;
typedef IPropertySetStorage *LPPROPERTYSETSTORAGE;
typedef IPropertyStorage *LPPROPERTYSTORAGE;
struct tagPROPVARIANT;
typedef struct tagPROPVARIANT *LPPROPVARIANT;
typedef IRootStorage *LPROOTSTORAGE;
typedef IRunnableObject *LPRUNNABLEOBJECT;
typedef IRunningObjectTable *LPRUNNINGOBJECTTABLE;
struct tagSTATDATA;
typedef struct tagSTATDATA STATDATA;
typedef STATDATA *LPSTATDATA;
typedef IStdMarshalInfo *LPSTDMARSHALINFO;
typedef ISurrogate *LPSURROGATE;
enum tagMKREDUCE {
    MKRREDUCE_ONE = 196608,
    MKRREDUCE_TOUSER = 131072,
    MKRREDUCE_THROUGHUSER = 65536,
    MKRREDUCE_ALL = 0
};

typedef enum tagMKREDUCE MKRREDUCE;
enum tagMKSYS {
    MKSYS_NONE = 0,
    MKSYS_GENERICCOMPOSITE = 1,
    MKSYS_FILEMONIKER = 2,
    MKSYS_ANTIMONIKER = 3,
    MKSYS_ITEMMONIKER = 4,
    MKSYS_POINTERMONIKER = 5,
    MKSYS_CLASSMONIKER = 7,
    MKSYS_OBJREFMONIKER = 8
};

typedef enum tagMKSYS MKSYS;
struct tagMULTI_QI;
typedef struct tagMULTI_QI MULTI_QI;
enum tagPENDINGMSG {
    PENDINGMSG_CANCELCALL = 0,
    PENDINGMSG_WAITNOPROCESS = 1,
    PENDINGMSG_WAITDEFPROCESS = 2
};

typedef enum tagPENDINGMSG PENDINGMSG;
enum tagPENDINGTYPE {
    PENDINGTYPE_TOPLEVEL = 1,
    PENDINGTYPE_NESTED = 2
};

typedef enum tagPENDINGTYPE PENDINGTYPE;
struct tagPROPSPEC;
typedef struct tagPROPSPEC PROPSPEC;
typedef struct tagPROPVARIANT PROPVARIANT;
struct tagRPCOLEMESSAGE;
typedef struct tagRPCOLEMESSAGE RPCOLEMESSAGE;
typedef RPCOLEMESSAGE *PRPCOLEMESSAGE;
struct tagSOLE_AUTHENTICATION_SERVICE;
typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE;
typedef SOLE_AUTHENTICATION_SERVICE *PSOLE_AUTHENTICATION_SERVICE;
enum tagREGCLS {
    REGCLS_SINGLEUSE = 0,
    REGCLS_MULTIPLEUSE = 1,
    REGCLS_MULTI_SEPARATE = 2,
    REGCLS_SUSPENDED = 4,
    REGCLS_SURROGATE = 8
};

typedef enum tagREGCLS REGCLS;
typedef unsigned long RPCOLEDATAREP;
struct tagRemSNB;
typedef struct tagRemSNB RemSNB;
struct tagRemSTGMEDIUM;
typedef struct tagRemSTGMEDIUM RemSTGMEDIUM;
struct SChannelHookCallInfo;
typedef struct SChannelHookCallInfo SChannelHookCallInfo;
enum tagSERVERCALL {
    SERVERCALL_ISHANDLED = 0,
    SERVERCALL_REJECTED = 1,
    SERVERCALL_RETRYLATER = 2
};

typedef enum tagSERVERCALL SERVERCALL;
struct tagSTATPROPSETSTG;
typedef struct tagSTATPROPSETSTG STATPROPSETSTG;
struct tagSTATPROPSTG;
typedef struct tagSTATPROPSTG STATPROPSTG;
struct tagSTATSTG;
typedef struct tagSTATSTG STATSTG;
enum tagSTGTY {
    STGTY_STORAGE = 1,
    STGTY_STREAM = 2,
    STGTY_LOCKBYTES = 3,
    STGTY_PROPERTY = 4
};

typedef enum tagSTGTY STGTY;
enum tagSTREAM_SEEK {
    STREAM_SEEK_SET = 0,
    STREAM_SEEK_CUR = 1,
    STREAM_SEEK_END = 2
};

typedef enum tagSTREAM_SEEK STREAM_SEEK;
struct tagStorageLayout;
typedef struct tagStorageLayout StorageLayout;
enum tagTYMED {
    TYMED_HGLOBAL = 1,
    TYMED_FILE = 2,
    TYMED_ISTREAM = 4,
    TYMED_ISTORAGE = 8,
    TYMED_GDI = 16,
    TYMED_MFPICT = 32,
    TYMED_ENHMF = 64,
    TYMED_NULL = 0
};

typedef enum tagTYMED TYMED;
struct _userFLAG_STGMEDIUM;
typedef struct _userFLAG_STGMEDIUM userFLAG_STGMEDIUM;
struct _userSTGMEDIUM;
typedef struct _userSTGMEDIUM userSTGMEDIUM;
typedef userSTGMEDIUM *wireASYNC_STGMEDIUM;
typedef userFLAG_STGMEDIUM *wireFLAG_STGMEDIUM;
typedef RemSNB *wireSNB;
typedef userSTGMEDIUM *wireSTGMEDIUM;
struct IAdviseSink {
    struct IAdviseSinkVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IAdviseSink2 {
    struct IAdviseSink2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IAdviseSink2Vtbl {
    HRESULT (*QueryInterface)(IAdviseSink2 *, const IID *const, void **);
    ULONG (*AddRef)(IAdviseSink2 *);
    ULONG (*Release)(IAdviseSink2 *);
    void (*OnDataChange)(IAdviseSink2 *, FORMATETC *, STGMEDIUM *);
    void (*OnViewChange)(IAdviseSink2 *, DWORD, LONG);
    void (*OnRename)(IAdviseSink2 *, IMoniker *);
    void (*OnSave)(IAdviseSink2 *);
    void (*OnClose)(IAdviseSink2 *);
    void (*OnLinkSrcChange)(IAdviseSink2 *, IMoniker *);
} __attribute__((packed, aligned(4)));

struct IAdviseSinkVtbl {
    HRESULT (*QueryInterface)(IAdviseSink *, const IID *const, void **);
    ULONG (*AddRef)(IAdviseSink *);
    ULONG (*Release)(IAdviseSink *);
    void (*OnDataChange)(IAdviseSink *, FORMATETC *, STGMEDIUM *);
    void (*OnViewChange)(IAdviseSink *, DWORD, LONG);
    void (*OnRename)(IAdviseSink *, IMoniker *);
    void (*OnSave)(IAdviseSink *);
    void (*OnClose)(IAdviseSink *);
} __attribute__((packed, aligned(4)));

struct IBindCtx {
    struct IBindCtxVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IBindCtxVtbl {
    HRESULT (*QueryInterface)(IBindCtx *, const IID *const, void **);
    ULONG (*AddRef)(IBindCtx *);
    ULONG (*Release)(IBindCtx *);
    HRESULT (*RegisterObjectBound)(IBindCtx *, IUnknown *);
    HRESULT (*RevokeObjectBound)(IBindCtx *, IUnknown *);
    HRESULT (*ReleaseBoundObjects)(IBindCtx *);
    HRESULT (*SetBindOptions)(IBindCtx *, BIND_OPTS *);
    HRESULT (*GetBindOptions)(IBindCtx *, BIND_OPTS *);
    HRESULT (*GetRunningObjectTable)(IBindCtx *, IRunningObjectTable **);
    HRESULT (*RegisterObjectParam)(IBindCtx *, LPOLESTR, IUnknown *);
    HRESULT (*GetObjectParam)(IBindCtx *, LPOLESTR, IUnknown **);
    HRESULT (*EnumObjectParam)(IBindCtx *, IEnumString **);
    HRESULT (*RevokeObjectParam)(IBindCtx *, LPOLESTR);
} __attribute__((packed, aligned(4)));

struct IChannelHook {
    struct IChannelHookVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IChannelHookVtbl {
    HRESULT (*QueryInterface)(IChannelHook *, const IID *const, void **);
    ULONG (*AddRef)(IChannelHook *);
    ULONG (*Release)(IChannelHook *);
    void (*ClientGetSize)(IChannelHook *, const GUID *const, const IID *const, ULONG *);
    void (*ClientFillBuffer)(IChannelHook *, const GUID *const, const IID *const, ULONG *, void *);
    void (*ClientNotify)(IChannelHook *, const GUID *const, const IID *const, ULONG, void *, DWORD, HRESULT);
    void (*ServerNotify)(IChannelHook *, const GUID *const, const IID *const, ULONG, void *, DWORD);
    void (*ServerGetSize)(IChannelHook *, const GUID *const, const IID *const, HRESULT, ULONG *);
    void (*ServerFillBuffer)(IChannelHook *, const GUID *const, const IID *const, ULONG *, void *, HRESULT);
} __attribute__((packed, aligned(4)));

struct IClassActivator {
    struct IClassActivatorVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IClassActivatorVtbl {
    HRESULT (*QueryInterface)(IClassActivator *, const IID *const, void **);
    ULONG (*AddRef)(IClassActivator *);
    ULONG (*Release)(IClassActivator *);
    HRESULT (*GetClassObject)(IClassActivator *, const CLSID *const, DWORD, LCID, const IID *const, void **);
} __attribute__((packed, aligned(4)));

struct IClientSecurity {
    struct IClientSecurityVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IClientSecurityVtbl {
    HRESULT (*QueryInterface)(IClientSecurity *, const IID *const, void **);
    ULONG (*AddRef)(IClientSecurity *);
    ULONG (*Release)(IClientSecurity *);
    HRESULT (*QueryBlanket)(IClientSecurity *, IUnknown *, DWORD *, DWORD *, OLECHAR **, DWORD *, DWORD *, void **, DWORD *);
    HRESULT (*SetBlanket)(IClientSecurity *, IUnknown *, DWORD, DWORD, OLECHAR *, DWORD, DWORD, void *, DWORD);
    HRESULT (*CopyProxy)(IClientSecurity *, IUnknown *, IUnknown **);
} __attribute__((packed, aligned(4)));

struct IComBinding {
    struct IComBindingVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IComBindingVtbl {
    HRESULT (*QueryInterface)(IComBinding *, const IID *const, void **);
    ULONG (*AddRef)(IComBinding *);
    ULONG (*Release)(IComBinding *);
    HRESULT (*InitBinding)(IComBinding *, DWORD, DWORD, DWORD, DWORD, LPOLESTR);
    HRESULT (*QueryBinding)(IComBinding *, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPOLESTR *);
} __attribute__((packed, aligned(4)));

struct IDataAdviseHolder {
    struct IDataAdviseHolderVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IDataAdviseHolderVtbl {
    HRESULT (*QueryInterface)(IDataAdviseHolder *, const IID *const, void **);
    ULONG (*AddRef)(IDataAdviseHolder *);
    ULONG (*Release)(IDataAdviseHolder *);
    HRESULT (*Advise)(IDataAdviseHolder *, IDataObject *, FORMATETC *, DWORD, IAdviseSink *, DWORD *);
    HRESULT (*Unadvise)(IDataAdviseHolder *, DWORD);
    HRESULT (*EnumAdvise)(IDataAdviseHolder *, IEnumSTATDATA **);
    HRESULT (*SendOnDataChange)(IDataAdviseHolder *, IDataObject *, DWORD, DWORD);
} __attribute__((packed, aligned(4)));

struct IDataObject {
    struct IDataObjectVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IDataObjectVtbl {
    HRESULT (*QueryInterface)(IDataObject *, const IID *const, void **);
    ULONG (*AddRef)(IDataObject *);
    ULONG (*Release)(IDataObject *);
    HRESULT (*GetData)(IDataObject *, FORMATETC *, STGMEDIUM *);
    HRESULT (*GetDataHere)(IDataObject *, FORMATETC *, STGMEDIUM *);
    HRESULT (*QueryGetData)(IDataObject *, FORMATETC *);
    HRESULT (*GetCanonicalFormatEtc)(IDataObject *, FORMATETC *, FORMATETC *);
    HRESULT (*SetData)(IDataObject *, FORMATETC *, STGMEDIUM *, BOOL);
    HRESULT (*EnumFormatEtc)(IDataObject *, DWORD, IEnumFORMATETC **);
    HRESULT (*DAdvise)(IDataObject *, FORMATETC *, DWORD, IAdviseSink *, DWORD *);
    HRESULT (*DUnadvise)(IDataObject *, DWORD);
    HRESULT (*EnumDAdvise)(IDataObject *, IEnumSTATDATA **);
} __attribute__((packed, aligned(4)));

struct IEnumFORMATETC {
    struct IEnumFORMATETCVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumFORMATETCVtbl {
    HRESULT (*QueryInterface)(IEnumFORMATETC *, const IID *const, void **);
    ULONG (*AddRef)(IEnumFORMATETC *);
    ULONG (*Release)(IEnumFORMATETC *);
    HRESULT (*Next)(IEnumFORMATETC *, ULONG, FORMATETC *, ULONG *);
    HRESULT (*Skip)(IEnumFORMATETC *, ULONG);
    HRESULT (*Reset)(IEnumFORMATETC *);
    HRESULT (*Clone)(IEnumFORMATETC *, IEnumFORMATETC **);
} __attribute__((packed, aligned(4)));

struct IEnumMoniker {
    struct IEnumMonikerVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumMonikerVtbl {
    HRESULT (*QueryInterface)(IEnumMoniker *, const IID *const, void **);
    ULONG (*AddRef)(IEnumMoniker *);
    ULONG (*Release)(IEnumMoniker *);
    HRESULT (*Next)(IEnumMoniker *, ULONG, IMoniker **, ULONG *);
    HRESULT (*Skip)(IEnumMoniker *, ULONG);
    HRESULT (*Reset)(IEnumMoniker *);
    HRESULT (*Clone)(IEnumMoniker *, IEnumMoniker **);
} __attribute__((packed, aligned(4)));

struct IEnumSTATDATA {
    struct IEnumSTATDATAVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumSTATDATAVtbl {
    HRESULT (*QueryInterface)(IEnumSTATDATA *, const IID *const, void **);
    ULONG (*AddRef)(IEnumSTATDATA *);
    ULONG (*Release)(IEnumSTATDATA *);
    HRESULT (*Next)(IEnumSTATDATA *, ULONG, STATDATA *, ULONG *);
    HRESULT (*Skip)(IEnumSTATDATA *, ULONG);
    HRESULT (*Reset)(IEnumSTATDATA *);
    HRESULT (*Clone)(IEnumSTATDATA *, IEnumSTATDATA **);
} __attribute__((packed, aligned(4)));

struct IEnumSTATPROPSETSTG {
    struct IEnumSTATPROPSETSTGVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumSTATPROPSETSTGVtbl {
    HRESULT (*QueryInterface)(IEnumSTATPROPSETSTG *, const IID *const, void **);
    ULONG (*AddRef)(IEnumSTATPROPSETSTG *);
    ULONG (*Release)(IEnumSTATPROPSETSTG *);
    HRESULT (*Next)(IEnumSTATPROPSETSTG *, ULONG, STATPROPSETSTG *, ULONG *);
    HRESULT (*Skip)(IEnumSTATPROPSETSTG *, ULONG);
    HRESULT (*Reset)(IEnumSTATPROPSETSTG *);
    HRESULT (*Clone)(IEnumSTATPROPSETSTG *, IEnumSTATPROPSETSTG **);
} __attribute__((packed, aligned(4)));

struct IEnumSTATPROPSTG {
    struct IEnumSTATPROPSTGVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumSTATPROPSTGVtbl {
    HRESULT (*QueryInterface)(IEnumSTATPROPSTG *, const IID *const, void **);
    ULONG (*AddRef)(IEnumSTATPROPSTG *);
    ULONG (*Release)(IEnumSTATPROPSTG *);
    HRESULT (*Next)(IEnumSTATPROPSTG *, ULONG, STATPROPSTG *, ULONG *);
    HRESULT (*Skip)(IEnumSTATPROPSTG *, ULONG);
    HRESULT (*Reset)(IEnumSTATPROPSTG *);
    HRESULT (*Clone)(IEnumSTATPROPSTG *, IEnumSTATPROPSTG **);
} __attribute__((packed, aligned(4)));

struct IEnumSTATSTG {
    struct IEnumSTATSTGVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumSTATSTGVtbl {
    HRESULT (*QueryInterface)(IEnumSTATSTG *, const IID *const, void **);
    ULONG (*AddRef)(IEnumSTATSTG *);
    ULONG (*Release)(IEnumSTATSTG *);
    HRESULT (*Next)(IEnumSTATSTG *, ULONG, STATSTG *, ULONG *);
    HRESULT (*Skip)(IEnumSTATSTG *, ULONG);
    HRESULT (*Reset)(IEnumSTATSTG *);
    HRESULT (*Clone)(IEnumSTATSTG *, IEnumSTATSTG **);
} __attribute__((packed, aligned(4)));

struct IEnumString {
    struct IEnumStringVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumStringVtbl {
    HRESULT (*QueryInterface)(IEnumString *, const IID *const, void **);
    ULONG (*AddRef)(IEnumString *);
    ULONG (*Release)(IEnumString *);
    HRESULT (*Next)(IEnumString *, ULONG, LPOLESTR *, ULONG *);
    HRESULT (*Skip)(IEnumString *, ULONG);
    HRESULT (*Reset)(IEnumString *);
    HRESULT (*Clone)(IEnumString *, IEnumString **);
} __attribute__((packed, aligned(4)));

struct IEnumUnknown {
    struct IEnumUnknownVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IEnumUnknownVtbl {
    HRESULT (*QueryInterface)(IEnumUnknown *, const IID *const, void **);
    ULONG (*AddRef)(IEnumUnknown *);
    ULONG (*Release)(IEnumUnknown *);
    HRESULT (*Next)(IEnumUnknown *, ULONG, IUnknown **, ULONG *);
    HRESULT (*Skip)(IEnumUnknown *, ULONG);
    HRESULT (*Reset)(IEnumUnknown *);
    HRESULT (*Clone)(IEnumUnknown *, IEnumUnknown **);
} __attribute__((packed, aligned(4)));

struct IExternalConnection {
    struct IExternalConnectionVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IExternalConnectionVtbl {
    HRESULT (*QueryInterface)(IExternalConnection *, const IID *const, void **);
    ULONG (*AddRef)(IExternalConnection *);
    ULONG (*Release)(IExternalConnection *);
    DWORD (*AddConnection)(IExternalConnection *, DWORD, DWORD);
    DWORD (*ReleaseConnection)(IExternalConnection *, DWORD, DWORD, BOOL);
} __attribute__((packed, aligned(4)));

struct IFillLockBytes {
    struct IFillLockBytesVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IFillLockBytesVtbl {
    HRESULT (*QueryInterface)(IFillLockBytes *, const IID *const, void **);
    ULONG (*AddRef)(IFillLockBytes *);
    ULONG (*Release)(IFillLockBytes *);
    HRESULT (*FillAppend)(IFillLockBytes *, const void *, ULONG, ULONG *);
    HRESULT (*FillAt)(IFillLockBytes *, ULARGE_INTEGER, const void *, ULONG, ULONG *);
    HRESULT (*SetFillSize)(IFillLockBytes *, ULARGE_INTEGER);
    HRESULT (*Terminate)(IFillLockBytes *, BOOL);
} __attribute__((packed, aligned(4)));

struct IGlobalInterfaceTable {
    struct IGlobalInterfaceTableVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IGlobalInterfaceTableVtbl {
    HRESULT (*QueryInterface)(IGlobalInterfaceTable *, const IID *const, void **);
    ULONG (*AddRef)(IGlobalInterfaceTable *);
    ULONG (*Release)(IGlobalInterfaceTable *);
    HRESULT (*RegisterInterfaceInGlobal)(IGlobalInterfaceTable *, IUnknown *, const IID *const, DWORD *);
    HRESULT (*RevokeInterfaceFromGlobal)(IGlobalInterfaceTable *, DWORD);
    HRESULT (*GetInterfaceFromGlobal)(IGlobalInterfaceTable *, DWORD, const IID *const, void **);
} __attribute__((packed, aligned(4)));

struct ILayoutStorage {
    struct ILayoutStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ILayoutStorageVtbl {
    HRESULT (*QueryInterface)(ILayoutStorage *, const IID *const, void **);
    ULONG (*AddRef)(ILayoutStorage *);
    ULONG (*Release)(ILayoutStorage *);
    HRESULT (*LayoutScript)(ILayoutStorage *, StorageLayout *, DWORD, DWORD);
    HRESULT (*BeginMonitor)(ILayoutStorage *);
    HRESULT (*EndMonitor)(ILayoutStorage *);
    HRESULT (*ReLayoutDocfile)(ILayoutStorage *, OLECHAR *);
    HRESULT (*ReLayoutDocfileOnILockBytes)(ILayoutStorage *, ILockBytes *);
} __attribute__((packed, aligned(4)));

struct ILockBytes {
    struct ILockBytesVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ILockBytesVtbl {
    HRESULT (*QueryInterface)(ILockBytes *, const IID *const, void **);
    ULONG (*AddRef)(ILockBytes *);
    ULONG (*Release)(ILockBytes *);
    HRESULT (*ReadAt)(ILockBytes *, ULARGE_INTEGER, void *, ULONG, ULONG *);
    HRESULT (*WriteAt)(ILockBytes *, ULARGE_INTEGER, const void *, ULONG, ULONG *);
    HRESULT (*Flush)(ILockBytes *);
    HRESULT (*SetSize)(ILockBytes *, ULARGE_INTEGER);
    HRESULT (*LockRegion)(ILockBytes *, ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
    HRESULT (*UnlockRegion)(ILockBytes *, ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
    HRESULT (*Stat)(ILockBytes *, STATSTG *, DWORD);
} __attribute__((packed, aligned(4)));

struct IMalloc {
    struct IMallocVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMallocSpy {
    struct IMallocSpyVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMallocSpyVtbl {
    HRESULT (*QueryInterface)(IMallocSpy *, const IID *const, void **);
    ULONG (*AddRef)(IMallocSpy *);
    ULONG (*Release)(IMallocSpy *);
    ULONG (*PreAlloc)(IMallocSpy *, ULONG);
    void *(*PostAlloc)(IMallocSpy *, void *);
    void *(*PreFree)(IMallocSpy *, void *, BOOL);
    void (*PostFree)(IMallocSpy *, BOOL);
    ULONG (*PreRealloc)(IMallocSpy *, void *, ULONG, void **, BOOL);
    void *(*PostRealloc)(IMallocSpy *, void *, BOOL);
    void *(*PreGetSize)(IMallocSpy *, void *, BOOL);
    ULONG (*PostGetSize)(IMallocSpy *, ULONG, BOOL);
    void *(*PreDidAlloc)(IMallocSpy *, void *, BOOL);
    int (*PostDidAlloc)(IMallocSpy *, void *, BOOL, int);
    void (*PreHeapMinimize)(IMallocSpy *);
    void (*PostHeapMinimize)(IMallocSpy *);
} __attribute__((packed, aligned(4)));

struct IMallocVtbl {
    HRESULT (*QueryInterface)(IMalloc *, const IID *const, void **);
    ULONG (*AddRef)(IMalloc *);
    ULONG (*Release)(IMalloc *);
    void *(*Alloc)(IMalloc *, ULONG);
    void *(*Realloc)(IMalloc *, void *, ULONG);
    void (*Free)(IMalloc *, void *);
    ULONG (*GetSize)(IMalloc *, void *);
    int (*DidAlloc)(IMalloc *, void *);
    void (*HeapMinimize)(IMalloc *);
} __attribute__((packed, aligned(4)));

struct IMarshal {
    struct IMarshalVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMarshalVtbl {
    HRESULT (*QueryInterface)(IMarshal *, const IID *const, void **);
    ULONG (*AddRef)(IMarshal *);
    ULONG (*Release)(IMarshal *);
    HRESULT (*GetUnmarshalClass)(IMarshal *, const IID *const, void *, DWORD, void *, DWORD, CLSID *);
    HRESULT (*GetMarshalSizeMax)(IMarshal *, const IID *const, void *, DWORD, void *, DWORD, DWORD *);
    HRESULT (*MarshalInterface)(IMarshal *, IStream *, const IID *const, void *, DWORD, void *, DWORD);
    HRESULT (*UnmarshalInterface)(IMarshal *, IStream *, const IID *const, void **);
    HRESULT (*ReleaseMarshalData)(IMarshal *, IStream *);
    HRESULT (*DisconnectObject)(IMarshal *, DWORD);
} __attribute__((packed, aligned(4)));

struct IMessageFilter {
    struct IMessageFilterVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMessageFilterVtbl {
    HRESULT (*QueryInterface)(IMessageFilter *, const IID *const, void **);
    ULONG (*AddRef)(IMessageFilter *);
    ULONG (*Release)(IMessageFilter *);
    DWORD (*HandleInComingCall)(IMessageFilter *, DWORD, HTASK, DWORD, LPINTERFACEINFO);
    DWORD (*RetryRejectedCall)(IMessageFilter *, HTASK, DWORD, DWORD);
    DWORD (*MessagePending)(IMessageFilter *, HTASK, DWORD, DWORD);
} __attribute__((packed, aligned(4)));

struct IMoniker {
    struct IMonikerVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMonikerVtbl {
    HRESULT (*QueryInterface)(IMoniker *, const IID *const, void **);
    ULONG (*AddRef)(IMoniker *);
    ULONG (*Release)(IMoniker *);
    HRESULT (*GetClassID)(IMoniker *, CLSID *);
    HRESULT (*IsDirty)(IMoniker *);
    HRESULT (*Load)(IMoniker *, IStream *);
    HRESULT (*Save)(IMoniker *, IStream *, BOOL);
    HRESULT (*GetSizeMax)(IMoniker *, ULARGE_INTEGER *);
    HRESULT (*BindToObject)(IMoniker *, IBindCtx *, IMoniker *, const IID *const, void **);
    HRESULT (*BindToStorage)(IMoniker *, IBindCtx *, IMoniker *, const IID *const, void **);
    HRESULT (*Reduce)(IMoniker *, IBindCtx *, DWORD, IMoniker **, IMoniker **);
    HRESULT (*ComposeWith)(IMoniker *, IMoniker *, BOOL, IMoniker **);
    HRESULT (*Enum)(IMoniker *, BOOL, IEnumMoniker **);
    HRESULT (*IsEqual)(IMoniker *, IMoniker *);
    HRESULT (*Hash)(IMoniker *, DWORD *);
    HRESULT (*IsRunning)(IMoniker *, IBindCtx *, IMoniker *, IMoniker *);
    HRESULT (*GetTimeOfLastChange)(IMoniker *, IBindCtx *, IMoniker *, FILETIME *);
    HRESULT (*Inverse)(IMoniker *, IMoniker **);
    HRESULT (*CommonPrefixWith)(IMoniker *, IMoniker *, IMoniker **);
    HRESULT (*RelativePathTo)(IMoniker *, IMoniker *, IMoniker **);
    HRESULT (*GetDisplayName)(IMoniker *, IBindCtx *, IMoniker *, LPOLESTR *);
    HRESULT (*ParseDisplayName)(IMoniker *, IBindCtx *, IMoniker *, LPOLESTR, ULONG *, IMoniker **);
    HRESULT (*IsSystemMoniker)(IMoniker *, DWORD *);
} __attribute__((packed, aligned(4)));

struct IMultiQI {
    struct IMultiQIVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IMultiQIVtbl {
    HRESULT (*QueryInterface)(IMultiQI *, const IID *const, void **);
    ULONG (*AddRef)(IMultiQI *);
    ULONG (*Release)(IMultiQI *);
    HRESULT (*QueryMultipleInterfaces)(IMultiQI *, ULONG, MULTI_QI *);
} __attribute__((packed, aligned(4)));

struct IPSFactoryBuffer {
    struct IPSFactoryBufferVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPSFactoryBufferVtbl {
    HRESULT (*QueryInterface)(IPSFactoryBuffer *, const IID *const, void **);
    ULONG (*AddRef)(IPSFactoryBuffer *);
    ULONG (*Release)(IPSFactoryBuffer *);
    HRESULT (*CreateProxy)(IPSFactoryBuffer *, IUnknown *, const IID *const, IRpcProxyBuffer **, void **);
    HRESULT (*CreateStub)(IPSFactoryBuffer *, const IID *const, IUnknown *, IRpcStubBuffer **);
} __attribute__((packed, aligned(4)));

struct IPersist {
    struct IPersistVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistFile {
    struct IPersistFileVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistFileVtbl {
    HRESULT (*QueryInterface)(IPersistFile *, const IID *const, void **);
    ULONG (*AddRef)(IPersistFile *);
    ULONG (*Release)(IPersistFile *);
    HRESULT (*GetClassID)(IPersistFile *, CLSID *);
    HRESULT (*IsDirty)(IPersistFile *);
    HRESULT (*Load)(IPersistFile *, LPCOLESTR, DWORD);
    HRESULT (*Save)(IPersistFile *, LPCOLESTR, BOOL);
    HRESULT (*SaveCompleted)(IPersistFile *, LPCOLESTR);
    HRESULT (*GetCurFile)(IPersistFile *, LPOLESTR *);
} __attribute__((packed, aligned(4)));

struct IPersistStorage {
    struct IPersistStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistStorageVtbl {
    HRESULT (*QueryInterface)(IPersistStorage *, const IID *const, void **);
    ULONG (*AddRef)(IPersistStorage *);
    ULONG (*Release)(IPersistStorage *);
    HRESULT (*GetClassID)(IPersistStorage *, CLSID *);
    HRESULT (*IsDirty)(IPersistStorage *);
    HRESULT (*InitNew)(IPersistStorage *, IStorage *);
    HRESULT (*Load)(IPersistStorage *, IStorage *);
    HRESULT (*Save)(IPersistStorage *, IStorage *, BOOL);
    HRESULT (*SaveCompleted)(IPersistStorage *, IStorage *);
    HRESULT (*HandsOffStorage)(IPersistStorage *);
} __attribute__((packed, aligned(4)));

struct IPersistStream {
    struct IPersistStreamVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPersistStreamVtbl {
    HRESULT (*QueryInterface)(IPersistStream *, const IID *const, void **);
    ULONG (*AddRef)(IPersistStream *);
    ULONG (*Release)(IPersistStream *);
    HRESULT (*GetClassID)(IPersistStream *, CLSID *);
    HRESULT (*IsDirty)(IPersistStream *);
    HRESULT (*Load)(IPersistStream *, IStream *);
    HRESULT (*Save)(IPersistStream *, IStream *, BOOL);
    HRESULT (*GetSizeMax)(IPersistStream *, ULARGE_INTEGER *);
} __attribute__((packed, aligned(4)));

struct IPersistVtbl {
    HRESULT (*QueryInterface)(IPersist *, const IID *const, void **);
    ULONG (*AddRef)(IPersist *);
    ULONG (*Release)(IPersist *);
    HRESULT (*GetClassID)(IPersist *, CLSID *);
} __attribute__((packed, aligned(4)));

struct IProgressNotify {
    struct IProgressNotifyVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IProgressNotifyVtbl {
    HRESULT (*QueryInterface)(IProgressNotify *, const IID *const, void **);
    ULONG (*AddRef)(IProgressNotify *);
    ULONG (*Release)(IProgressNotify *);
    HRESULT (*OnProgress)(IProgressNotify *, DWORD, DWORD, BOOL, BOOL);
} __attribute__((packed, aligned(4)));

struct IPropertySetStorage {
    struct IPropertySetStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertySetStorageVtbl {
    HRESULT (*QueryInterface)(IPropertySetStorage *, const IID *const, void **);
    ULONG (*AddRef)(IPropertySetStorage *);
    ULONG (*Release)(IPropertySetStorage *);
    HRESULT (*Create)(IPropertySetStorage *, const FMTID *const, const CLSID *, DWORD, DWORD, IPropertyStorage **);
    HRESULT (*Open)(IPropertySetStorage *, const FMTID *const, DWORD, IPropertyStorage **);
    HRESULT (*Delete)(IPropertySetStorage *, const FMTID *const);
    HRESULT (*Enum)(IPropertySetStorage *, IEnumSTATPROPSETSTG **);
} __attribute__((packed, aligned(4)));

struct IPropertyStorage {
    struct IPropertyStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IPropertyStorageVtbl {
    HRESULT (*QueryInterface)(IPropertyStorage *, const IID *const, void **);
    ULONG (*AddRef)(IPropertyStorage *);
    ULONG (*Release)(IPropertyStorage *);
    HRESULT (*ReadMultiple)(IPropertyStorage *, ULONG, const PROPSPEC *, PROPVARIANT *);
    HRESULT (*WriteMultiple)(IPropertyStorage *, ULONG, const PROPSPEC *, const PROPVARIANT *, PROPID);
    HRESULT (*DeleteMultiple)(IPropertyStorage *, ULONG, const PROPSPEC *);
    HRESULT (*ReadPropertyNames)(IPropertyStorage *, ULONG, const PROPID *, LPOLESTR *);
    HRESULT (*WritePropertyNames)(IPropertyStorage *, ULONG, const PROPID *, const LPOLESTR *);
    HRESULT (*DeletePropertyNames)(IPropertyStorage *, ULONG, const PROPID *);
    HRESULT (*Commit)(IPropertyStorage *, DWORD);
    HRESULT (*Revert)(IPropertyStorage *);
    HRESULT (*Enum)(IPropertyStorage *, IEnumSTATPROPSTG **);
    HRESULT (*SetTimes)(IPropertyStorage *, const FILETIME *, const FILETIME *, const FILETIME *);
    HRESULT (*SetClass)(IPropertyStorage *, const CLSID *const);
    HRESULT (*Stat)(IPropertyStorage *, STATPROPSETSTG *);
} __attribute__((packed, aligned(4)));

struct IROTData {
    struct IROTDataVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IROTDataVtbl {
    HRESULT (*QueryInterface)(IROTData *, const IID *const, void **);
    ULONG (*AddRef)(IROTData *);
    ULONG (*Release)(IROTData *);
    HRESULT (*GetComparisonData)(IROTData *, byte *, ULONG, ULONG *);
} __attribute__((packed, aligned(4)));

struct IRootStorage {
    struct IRootStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRootStorageVtbl {
    HRESULT (*QueryInterface)(IRootStorage *, const IID *const, void **);
    ULONG (*AddRef)(IRootStorage *);
    ULONG (*Release)(IRootStorage *);
    HRESULT (*SwitchToFile)(IRootStorage *, LPOLESTR);
} __attribute__((packed, aligned(4)));

struct IRpcChannelBuffer {
    struct IRpcChannelBufferVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRpcChannelBuffer2 {
    struct IRpcChannelBuffer2Vtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRpcChannelBuffer2Vtbl {
    HRESULT (*QueryInterface)(IRpcChannelBuffer2 *, const IID *const, void **);
    ULONG (*AddRef)(IRpcChannelBuffer2 *);
    ULONG (*Release)(IRpcChannelBuffer2 *);
    HRESULT (*GetBuffer)(IRpcChannelBuffer2 *, RPCOLEMESSAGE *, const IID *const);
    HRESULT (*SendReceive)(IRpcChannelBuffer2 *, RPCOLEMESSAGE *, ULONG *);
    HRESULT (*FreeBuffer)(IRpcChannelBuffer2 *, RPCOLEMESSAGE *);
    HRESULT (*GetDestCtx)(IRpcChannelBuffer2 *, DWORD *, void **);
    HRESULT (*IsConnected)(IRpcChannelBuffer2 *);
    HRESULT (*GetProtocolVersion)(IRpcChannelBuffer2 *, DWORD *);
} __attribute__((packed, aligned(4)));

struct IRpcChannelBufferVtbl {
    HRESULT (*QueryInterface)(IRpcChannelBuffer *, const IID *const, void **);
    ULONG (*AddRef)(IRpcChannelBuffer *);
    ULONG (*Release)(IRpcChannelBuffer *);
    HRESULT (*GetBuffer)(IRpcChannelBuffer *, RPCOLEMESSAGE *, const IID *const);
    HRESULT (*SendReceive)(IRpcChannelBuffer *, RPCOLEMESSAGE *, ULONG *);
    HRESULT (*FreeBuffer)(IRpcChannelBuffer *, RPCOLEMESSAGE *);
    HRESULT (*GetDestCtx)(IRpcChannelBuffer *, DWORD *, void **);
    HRESULT (*IsConnected)(IRpcChannelBuffer *);
} __attribute__((packed, aligned(4)));

struct IRpcOptions {
    struct IRpcOptionsVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRpcOptionsVtbl {
    HRESULT (*QueryInterface)(IRpcOptions *, const IID *const, void **);
    ULONG (*AddRef)(IRpcOptions *);
    ULONG (*Release)(IRpcOptions *);
    HRESULT (*Set)(IRpcOptions *, IUnknown *, DWORD, ULONG);
    HRESULT (*Query)(IRpcOptions *, IUnknown *, DWORD, ULONG *);
} __attribute__((packed, aligned(4)));

struct IRpcProxyBuffer {
    struct IRpcProxyBufferVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRpcProxyBufferVtbl {
    HRESULT (*QueryInterface)(IRpcProxyBuffer *, const IID *const, void **);
    ULONG (*AddRef)(IRpcProxyBuffer *);
    ULONG (*Release)(IRpcProxyBuffer *);
    HRESULT (*Connect)(IRpcProxyBuffer *, IRpcChannelBuffer *);
    void (*Disconnect)(IRpcProxyBuffer *);
} __attribute__((packed, aligned(4)));

struct IRpcStubBuffer {
    struct IRpcStubBufferVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRpcStubBufferVtbl {
    HRESULT (*QueryInterface)(IRpcStubBuffer *, const IID *const, void **);
    ULONG (*AddRef)(IRpcStubBuffer *);
    ULONG (*Release)(IRpcStubBuffer *);
    HRESULT (*Connect)(IRpcStubBuffer *, IUnknown *);
    void (*Disconnect)(IRpcStubBuffer *);
    HRESULT (*Invoke)(IRpcStubBuffer *, RPCOLEMESSAGE *, IRpcChannelBuffer *);
    IRpcStubBuffer *(*IsIIDSupported)(IRpcStubBuffer *, const IID *const);
    ULONG (*CountRefs)(IRpcStubBuffer *);
    HRESULT (*DebugServerQueryInterface)(IRpcStubBuffer *, void **);
    void (*DebugServerRelease)(IRpcStubBuffer *, void *);
} __attribute__((packed, aligned(4)));

struct IRunnableObject {
    struct IRunnableObjectVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRunnableObjectVtbl {
    HRESULT (*QueryInterface)(IRunnableObject *, const IID *const, void **);
    ULONG (*AddRef)(IRunnableObject *);
    ULONG (*Release)(IRunnableObject *);
    HRESULT (*GetRunningClass)(IRunnableObject *, LPCLSID);
    HRESULT (*Run)(IRunnableObject *, LPBINDCTX);
    BOOL (*IsRunning)(IRunnableObject *);
    HRESULT (*LockRunning)(IRunnableObject *, BOOL, BOOL);
    HRESULT (*SetContainedObject)(IRunnableObject *, BOOL);
} __attribute__((packed, aligned(4)));

struct IRunningObjectTable {
    struct IRunningObjectTableVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IRunningObjectTableVtbl {
    HRESULT (*QueryInterface)(IRunningObjectTable *, const IID *const, void **);
    ULONG (*AddRef)(IRunningObjectTable *);
    ULONG (*Release)(IRunningObjectTable *);
    HRESULT (*Register)(IRunningObjectTable *, DWORD, IUnknown *, IMoniker *, DWORD *);
    HRESULT (*Revoke)(IRunningObjectTable *, DWORD);
    HRESULT (*IsRunning)(IRunningObjectTable *, IMoniker *);
    HRESULT (*GetObjectW)(IRunningObjectTable *, IMoniker *, IUnknown **);
    HRESULT (*NoteChangeTime)(IRunningObjectTable *, DWORD, FILETIME *);
    HRESULT (*GetTimeOfLastChange)(IRunningObjectTable *, IMoniker *, FILETIME *);
    HRESULT (*EnumRunning)(IRunningObjectTable *, IEnumMoniker **);
} __attribute__((packed, aligned(4)));

struct ISequentialStream {
    struct ISequentialStreamVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ISequentialStreamVtbl {
    HRESULT (*QueryInterface)(ISequentialStream *, const IID *const, void **);
    ULONG (*AddRef)(ISequentialStream *);
    ULONG (*Release)(ISequentialStream *);
    HRESULT (*Read)(ISequentialStream *, void *, ULONG, ULONG *);
    HRESULT (*Write)(ISequentialStream *, const void *, ULONG, ULONG *);
} __attribute__((packed, aligned(4)));

struct IServerSecurity {
    struct IServerSecurityVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IServerSecurityVtbl {
    HRESULT (*QueryInterface)(IServerSecurity *, const IID *const, void **);
    ULONG (*AddRef)(IServerSecurity *);
    ULONG (*Release)(IServerSecurity *);
    HRESULT (*QueryBlanket)(IServerSecurity *, DWORD *, DWORD *, OLECHAR **, DWORD *, DWORD *, void **, DWORD *);
    HRESULT (*ImpersonateClient)(IServerSecurity *);
    HRESULT (*RevertToSelf)(IServerSecurity *);
    BOOL (*IsImpersonating)(IServerSecurity *);
} __attribute__((packed, aligned(4)));

struct IStdMarshalInfo {
    struct IStdMarshalInfoVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IStdMarshalInfoVtbl {
    HRESULT (*QueryInterface)(IStdMarshalInfo *, const IID *const, void **);
    ULONG (*AddRef)(IStdMarshalInfo *);
    ULONG (*Release)(IStdMarshalInfo *);
    HRESULT (*GetClassForHandler)(IStdMarshalInfo *, DWORD, void *, CLSID *);
} __attribute__((packed, aligned(4)));

struct IStorage {
    struct IStorageVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IStorageVtbl {
    HRESULT (*QueryInterface)(IStorage *, const IID *const, void **);
    ULONG (*AddRef)(IStorage *);
    ULONG (*Release)(IStorage *);
    HRESULT (*CreateStream)(IStorage *, const OLECHAR *, DWORD, DWORD, DWORD, IStream **);
    HRESULT (*OpenStream)(IStorage *, const OLECHAR *, void *, DWORD, DWORD, IStream **);
    HRESULT (*CreateStorage)(IStorage *, const OLECHAR *, DWORD, DWORD, DWORD, IStorage **);
    HRESULT (*OpenStorage)(IStorage *, const OLECHAR *, IStorage *, DWORD, SNB, DWORD, IStorage **);
    HRESULT (*CopyTo)(IStorage *, DWORD, const IID *, SNB, IStorage *);
    HRESULT (*MoveElementTo)(IStorage *, const OLECHAR *, IStorage *, const OLECHAR *, DWORD);
    HRESULT (*Commit)(IStorage *, DWORD);
    HRESULT (*Revert)(IStorage *);
    HRESULT (*EnumElements)(IStorage *, DWORD, void *, DWORD, IEnumSTATSTG **);
    HRESULT (*DestroyElement)(IStorage *, const OLECHAR *);
    HRESULT (*RenameElement)(IStorage *, const OLECHAR *, const OLECHAR *);
    HRESULT (*SetElementTimes)(IStorage *, const OLECHAR *, const FILETIME *, const FILETIME *, const FILETIME *);
    HRESULT (*SetClass)(IStorage *, const CLSID *const);
    HRESULT (*SetStateBits)(IStorage *, DWORD, DWORD);
    HRESULT (*Stat)(IStorage *, STATSTG *, DWORD);
} __attribute__((packed, aligned(4)));

struct IStream {
    struct IStreamVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IStreamVtbl {
    HRESULT (*QueryInterface)(IStream *, const IID *const, void **);
    ULONG (*AddRef)(IStream *);
    ULONG (*Release)(IStream *);
    HRESULT (*Read)(IStream *, void *, ULONG, ULONG *);
    HRESULT (*Write)(IStream *, const void *, ULONG, ULONG *);
    HRESULT (*Seek)(IStream *, LARGE_INTEGER, DWORD, ULARGE_INTEGER *);
    HRESULT (*SetSize)(IStream *, ULARGE_INTEGER);
    HRESULT (*CopyTo)(IStream *, IStream *, ULARGE_INTEGER, ULARGE_INTEGER *, ULARGE_INTEGER *);
    HRESULT (*Commit)(IStream *, DWORD);
    HRESULT (*Revert)(IStream *);
    HRESULT (*LockRegion)(IStream *, ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
    HRESULT (*UnlockRegion)(IStream *, ULARGE_INTEGER, ULARGE_INTEGER, DWORD);
    HRESULT (*Stat)(IStream *, STATSTG *, DWORD);
    HRESULT (*Clone)(IStream *, IStream **);
} __attribute__((packed, aligned(4)));

struct ISurrogate {
    struct ISurrogateVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct ISurrogateVtbl {
    HRESULT (*QueryInterface)(ISurrogate *, const IID *const, void **);
    ULONG (*AddRef)(ISurrogate *);
    ULONG (*Release)(ISurrogate *);
    HRESULT (*LoadDllServer)(ISurrogate *, const CLSID *const);
    HRESULT (*FreeSurrogate)(ISurrogate *);
} __attribute__((packed, aligned(4)));

struct SChannelHookCallInfo {
    IID iid;
    DWORD cbSize;
    GUID uCausality;
    DWORD dwServerPid;
    DWORD iMethod;
    void *pObject;
} __attribute__((packed, aligned(4)));

struct tagSTGMEDIUM {
    DWORD tymed;
    union {
        HBITMAP hBitmap;
        HMETAFILEPICT hMetaFilePict;
        HENHMETAFILE hEnhMetaFile;
        HGLOBAL hGlobal;
        LPOLESTR lpszFileName;
        IStream *pstm;
        IStorage *pstg;
    };
    IUnknown *pUnkForRelease;
} __attribute__((packed, aligned(4)));

struct _FLAG_STGMEDIUM {
    long ContextFlags;
    long fPassOwnership;
    STGMEDIUM Stgmed;
} __attribute__((packed, aligned(4)));

union __MIDL_IAdviseSink_0002;
union __MIDL_IAdviseSink_0002 {
    wireHBITMAP hBitmap;
    wireHPALETTE hPalette;
    wireHGLOBAL hGeneric;
} __attribute__((packed, aligned(4)));

struct _GDI_OBJECT {
    DWORD ObjectType;
    union __MIDL_IAdviseSink_0002 u;
} __attribute__((packed, aligned(4)));

union __MIDL_IAdviseSink_0003;
union __MIDL_IAdviseSink_0003 {
    wireHMETAFILEPICT hMetaFilePict;
    wireHENHMETAFILE hHEnhMetaFile;
    GDI_OBJECT *hGdiHandle;
    wireHGLOBAL hGlobal;
    LPOLESTR lpszFileName;
    BYTE_BLOB *pstm;
    BYTE_BLOB *pstg;
} __attribute__((packed, aligned(4)));

struct _STGMEDIUM_UNION;
struct _STGMEDIUM_UNION {
    DWORD tymed;
    union __MIDL_IAdviseSink_0003 u;
} __attribute__((packed, aligned(4)));

struct _userSTGMEDIUM {
    struct {
        DWORD tymed;
        union __MIDL_IAdviseSink_0003 u;
    } __attribute__((packed, aligned(4)));
    IUnknown *pUnkForRelease;
} __attribute__((packed, aligned(4)));

struct _userFLAG_STGMEDIUM {
    long ContextFlags;
    long fPassOwnership;
    userSTGMEDIUM Stgmed;
} __attribute__((packed, aligned(4)));

struct tagBIND_OPTS {
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
} __attribute__((packed, aligned(4)));

struct tagBIND_OPTS2 {
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
    DWORD dwTrackFlags;
    DWORD dwClassContext;
    LCID locale;
    COSERVERINFO *pServerInfo;
} __attribute__((packed, aligned(4)));

struct tagCABOOL {
    ULONG cElems;
    VARIANT_BOOL *pElems;
} __attribute__((packed, aligned(4)));

struct tagCABSTR {
    ULONG cElems;
    BSTR *pElems;
} __attribute__((packed, aligned(4)));

struct tagCABSTRBLOB {
    ULONG cElems;
    BSTRBLOB *pElems;
} __attribute__((packed, aligned(4)));

struct tagCACLIPDATA {
    ULONG cElems;
    CLIPDATA *pElems;
} __attribute__((packed, aligned(4)));

struct tagCACLSID {
    ULONG cElems;
    CLSID *pElems;
} __attribute__((packed, aligned(4)));

struct tagCACY {
    ULONG cElems;
    CY *pElems;
} __attribute__((packed, aligned(4)));

struct tagCADATE {
    ULONG cElems;
    DATE *pElems;
} __attribute__((packed, aligned(4)));

struct tagCADBL {
    ULONG cElems;
    double *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAFILETIME {
    ULONG cElems;
    FILETIME *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAFLT {
    ULONG cElems;
    float *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAH {
    ULONG cElems;
    LARGE_INTEGER *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAI {
    ULONG cElems;
    short *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAL {
    ULONG cElems;
    long *pElems;
} __attribute__((packed, aligned(4)));

struct tagCALPSTR {
    ULONG cElems;
    LPSTR *pElems;
} __attribute__((packed, aligned(4)));

struct tagCALPWSTR {
    ULONG cElems;
    LPWSTR *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAPROPVARIANT {
    ULONG cElems;
    PROPVARIANT *pElems;
} __attribute__((packed, aligned(4)));

struct tagCASCODE {
    ULONG cElems;
    SCODE *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAUB {
    ULONG cElems;
    unsigned char *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAUH {
    ULONG cElems;
    ULARGE_INTEGER *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAUI {
    ULONG cElems;
    USHORT *pElems;
} __attribute__((packed, aligned(4)));

struct tagCAUL {
    ULONG cElems;
    ULONG *pElems;
} __attribute__((packed, aligned(4)));

struct tagDVTARGETDEVICE {
    DWORD tdSize;
    WORD tdDriverNameOffset;
    WORD tdDeviceNameOffset;
    WORD tdPortNameOffset;
    WORD tdExtDevmodeOffset;
    BYTE tdData[1];
} __attribute__((packed, aligned(4)));

struct tagFORMATETC {
    CLIPFORMAT cfFormat;
    DVTARGETDEVICE *ptd;
    DWORD dwAspect;
    LONG lindex;
    DWORD tymed;
} __attribute__((packed, aligned(4)));

struct tagINTERFACEINFO {
    IUnknown *pUnk;
    IID iid;
    WORD wMethod;
} __attribute__((packed, aligned(4)));

struct tagMULTI_QI {
    const IID *pIID;
    IUnknown *pItf;
    HRESULT hr;
} __attribute__((packed, aligned(4)));

struct tagPROPSPEC {
    ULONG ulKind;
    union {
        PROPID propid;
        LPOLESTR lpwstr;
    };
} __attribute__((packed, aligned(4)));

struct tagPROPVARIANT {
    VARTYPE vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    union {
        UCHAR bVal;
        short iVal;
        USHORT uiVal;
        VARIANT_BOOL boolVal;
        long lVal;
        ULONG ulVal;
        float fltVal;
        SCODE scode;
        LARGE_INTEGER hVal;
        ULARGE_INTEGER uhVal;
        double dblVal;
        CY cyVal;
        DATE date;
        FILETIME filetime;
        CLSID *puuid;
        BLOB blob;
        CLIPDATA *pclipdata;
        IStream *pStream;
        IStorage *pStorage;
        BSTR bstrVal;
        BSTRBLOB bstrblobVal;
        LPSTR pszVal;
        LPWSTR pwszVal;
        CAUB caub;
        CAI cai;
        CAUI caui;
        CABOOL cabool;
        CAL cal;
        CAUL caul;
        CAFLT caflt;
        CASCODE cascode;
        CAH cah;
        CAUH cauh;
        CADBL cadbl;
        CACY cacy;
        CADATE cadate;
        CAFILETIME cafiletime;
        CACLSID cauuid;
        CACLIPDATA caclipdata;
        CABSTR cabstr;
        CABSTRBLOB cabstrblob;
        CALPSTR calpstr;
        CALPWSTR calpwstr;
        CAPROPVARIANT capropvar;
    };
} __attribute__((packed, aligned(8)));

struct tagRPCOLEMESSAGE {
    void *reserved1;
    RPCOLEDATAREP dataRepresentation;
    void *Buffer;
    ULONG cbBuffer;
    ULONG iMethod;
    void * reserved2[5];
    ULONG rpcFlags;
} __attribute__((packed, aligned(4)));

struct tagRemSNB {
    unsigned long ulCntStr;
    unsigned long ulCntChar;
    OLECHAR rgString[1];
} __attribute__((packed, aligned(4)));

struct tagRemSTGMEDIUM {
    DWORD tymed;
    DWORD dwHandleType;
    unsigned long pData;
    unsigned long pUnkForRelease;
    unsigned long cbData;
    byte data[1];
} __attribute__((packed, aligned(4)));

struct tagSOLE_AUTHENTICATION_SERVICE {
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    OLECHAR *pPrincipalName;
    HRESULT hr;
} __attribute__((packed, aligned(4)));

struct tagSTATDATA {
    FORMATETC formatetc;
    DWORD advf;
    IAdviseSink *pAdvSink;
    DWORD dwConnection;
} __attribute__((packed, aligned(4)));

struct tagSTATPROPSETSTG {
    FMTID fmtid;
    CLSID clsid;
    DWORD grfFlags;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD dwOSVersion;
} __attribute__((packed, aligned(4)));

struct tagSTATPROPSTG {
    LPOLESTR lpwstrName;
    PROPID propid;
    VARTYPE vt;
} __attribute__((packed, aligned(4)));

struct tagSTATSTG {
    LPOLESTR pwcsName;
    DWORD type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD grfMode;
    DWORD grfLocksSupported;
    CLSID clsid;
    DWORD grfStateBits;
    DWORD reserved;
} __attribute__((packed, aligned(8)));

struct tagStorageLayout {
    DWORD LayoutType;
    OLECHAR *pwcsElementName;
    LARGE_INTEGER cOffset;
    LARGE_INTEGER cBytes;
} __attribute__((packed, aligned(8)));

enum __MIDL___MIDL_itf_objidl_0051_0001 {
    COMBND_RPCTIMEOUT = 1
};

enum __MIDL___MIDL_itf_objidl_0056_0001 {
    COMBND_RPCSTRINGS = 1
};


#ifdef __cplusplus
}
#endif

#endif

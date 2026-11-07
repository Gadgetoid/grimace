#ifndef GRIMACE_SDK_WINDOWS_H
#define GRIMACE_SDK_WINDOWS_H


#ifdef __cplusplus
extern "C" {
#endif

BOOL AllKeys(BOOL bAllKeys);
struct _CEGUID;
typedef struct _CEGUID CEGUID;
typedef CEGUID *PCEGUID;
/**
 * Creates a database in the object store or a mounted database volume.
 *
 * Keep the number of sort orders small; inserts and deletes become more
 * expensive as sort orders are added. Use CeSetDatabaseInfoEx to change
 * them later.
 *
 * @param pguid GUID of the mounted volume, or the object-store GUID.
 * @param pInfo Database name, type, sort orders and characteristics.
 * @return New database object ID, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
CEOID CeCreateDatabaseEx(PCEGUID pguid, CEDBASEINFO *pInfo);
/**
 * Deletes a database from the object store or a mounted volume.
 *
 * @param pguid GUID of the database volume.
 * @param oid Object ID of the database to delete.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeDeleteDatabaseEx(PCEGUID pguid, CEOID oid);
/**
 * Enumerates mounted database volumes and returns each volume name.
 *
 * Start with pguid set to CREATE_INVALIDGUID. Continue with the GUID
 * returned by each successful call. On ERROR_INSUFFICIENT_BUFFER, resize
 * the buffer and resume with the returned GUID.
 *
 * @param pguid Enumeration state; initialize to CREATE_INVALIDGUID.
 * @param lpBuf Receives a volume name.
 * @param dwSize Buffer size in characters.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeEnumDBVolumes(PCEGUID pguid, LPWSTR lpBuf, DWORD dwSize);
/**
 * Opens an enumeration context for databases on a volume.
 *
 * Set dwClassID to zero to enumerate all database types. A NULL or invalid
 * GUID searches all mounted volumes. Call CeFindNextDatabaseEx to get
 * entries and CloseHandle when finished.
 *
 * @param pguid Volume GUID, or NULL/invalid to search all volumes.
 * @param dwClassID Database type, or zero for all types.
 * @return Enumeration handle, or INVALID_HANDLE_VALUE on failure.
 *
 * @note Windows CE 3.0 only.
 */
HANDLE CeFindFirstDatabaseEx(PCEGUID pguid, DWORD dwClassID);
/**
 * Returns the next database object ID in an enumeration context.
 *
 * Call CeFindFirstDatabaseEx first and close hEnum when enumeration ends.
 * If a database is deleted during enumeration, restart it.
 *
 * @param hEnum Enumeration handle.
 * @param pguid Receives the database volume GUID.
 * @return Database object ID, or zero at the end or on failure; use
 *         GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
CEOID CeFindNextDatabaseEx(HANDLE hEnum, PCEGUID pguid);
/**
 * Flushes cached database-volume data to permanent storage.
 *
 * Use this when data must be saved before an unmount, reset or power loss.
 *
 * @param pguid GUID of the mounted volume to flush.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeFlushDBVol(PCEGUID pguid);
struct _CENOTIFYREQUEST;
typedef struct _CENOTIFYREQUEST CENOTIFYREQUEST;
typedef CENOTIFYREQUEST *PCENOTIFYREQUEST;
struct _CENOTIFICATION;
typedef struct _CENOTIFICATION CENOTIFICATION;
typedef CENOTIFICATION *PCENOTIFICATION;
/**
 * Frees a database notification structure delivered to an application.
 *
 * Free a notification received with WM_DBNOTIFICATION only with this
 * function; other methods can cause unpredictable results.
 *
 * @param pRequest Notification request associated with pNotify.
 * @param pNotify Notification structure to free.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeFreeNotification(PCENOTIFYREQUEST pRequest, PCENOTIFICATION pNotify);
/**
 * Returns the OEM-assigned trust level of the calling process.
 *
 * OEM_CERTIFY_TRUST (2) permits OS calls; OEM_CERTIFY_RUN (1) permits
 * execution but restricts some calls. Zero means the process is untrusted.
 *
 * @return OEM_CERTIFY_TRUST, OEM_CERTIFY_RUN, or 0 if untrusted.
 *
 * @note Windows CE 3.0 only.
 */
DWORD CeGetCallerTrust(void);
/**
 * Returns the OEM-assigned trust level of the current module.
 *
 * OEM_CERTIFY_TRUST (2) permits OS calls; OEM_CERTIFY_RUN (1) permits
 * execution but restricts some calls.
 *
 * @return OEM_CERTIFY_TRUST or OEM_CERTIFY_RUN.
 *
 * @note Windows CE 3.0 only.
 */
DWORD CeGetCurrentTrust(void);
int CeGetThreadPriority(HANDLE hThread);
/**
 * Returns a thread's time quantum in milliseconds.
 *
 * @param hThread Thread handle.
 * @return Quantum in milliseconds, or MAXDWORD on failure.
 *
 * @note Windows CE 3.0 only.
 */
DWORD CeGetThreadQuantum(HANDLE hThread);
/**
 * Creates or opens and mounts a database volume.
 *
 * dwFlags selects the create/open behavior. Mounts are reference-counted;
 * each caller must unmount the volume. Writes remain cached until flushed
 * or unmounted.
 *
 * @param pguid Receives the mounted volume GUID.
 * @param lpszVol Null-terminated volume file name, up to MAX_PATH characters.
 * @param dwFlags CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS or
 *                 TRUNCATE_EXISTING.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeMountDBVol(PCEGUID pguid, LPWSTR lpszVol, DWORD dwFlags);
/**
 * Retrieves information about an object in the object store or a mounted volume.
 *
 * Unlike CeOidGetInfo, this function also searches mounted database
 * volumes.
 *
 * @param pguid GUID of the database volume.
 * @param oid Object ID to query.
 * @param oidInfo Receives object information.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeOidGetInfoEx(PCEGUID pguid, CEOID oid, CEOIDINFO *oidInfo);
/**
 * Opens a database in the object store or on a mounted volume.
 *
 * Set *poid to zero and provide lpszName to open by name. Set
 * CEDB_AUTOINCREMENT to advance the seek position after reads. Close the
 * returned handle with CloseHandle; changes commit on each call.
 *
 * @param pguid Volume GUID, or CREATE_INVALIDGUID to search all volumes.
 * @param poid Database object ID, or pointer to zero for a name lookup.
 * @param lpszName Database name used when *poid is zero.
 * @param propid Sort-key property ID, or zero for no sort order.
 * @param dwFlags CEDB_AUTOINCREMENT or zero.
 * @param pReq Optional notification request.
 * @return Database handle, or INVALID_HANDLE_VALUE on failure.
 *
 * @note Windows CE 3.0 only.
 */
HANDLE CeOpenDatabaseEx(PCEGUID pguid, PCEOID poid, LPWSTR lpszName, CEPROPID propid, DWORD dwFlags, CENOTIFYREQUEST *pReq);
/**
 * Reads selected properties from the database's current record.
 *
 * Set rgPropID to NULL to read all properties. CEDB_ALLOWREALLOC allows
 * the output buffer to grow; free any returned buffer, including after a
 * failed call. With CEDB_AUTOINCREMENT, the database seek position advances.
 *
 * @param hDbase Open database handle.
 * @param dwFlags CEDB_ALLOWREALLOC or zero.
 * @param lpcPropID Receives the property count if rgPropID is NULL.
 * @param rgPropID Property IDs to read, or NULL for all properties.
 * @param lplpBuffer Receives the property buffer.
 * @param lpcbBuffer Buffer size in bytes; receives the actual or needed size.
 * @param hHeap Heap used for reallocation when CEDB_ALLOWREALLOC is set.
 * @return Record object ID, or zero on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
CEOID CeReadRecordPropsEx(HANDLE hDbase, DWORD dwFlags, LPWORD lpcPropID, CEPROPID *rgPropID, LPBYTE *lplpBuffer, LPDWORD lpcbBuffer, HANDLE hHeap);
/**
 * Asks the associated file-system driver to remount a device after media or
 * a new volume is inserted. This is intended for use by a device driver.
 *
 * @param hDevice Handle to a device registered with RegisterDevice.
 * @return TRUE on success, FALSE on failure.
 *
 * This API is part of the complete Windows CE OS package; OEM platform
 * configurations may not support it.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeResyncFilesys(HANDLE hDevice);
/**
 * Changes a database's name, type, sort orders or compression settings.
 *
 * Changing sort order or compression can take minutes. On HPC 2000 the
 * database must be closed before calling. Compression changes affect only
 * new and modified records.
 *
 * @param pguid GUID of the database volume.
 * @param oidDbase Database object ID.
 * @param pNewInfo New database settings; wNumRecords is ignored.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeSetDatabaseInfoEx(PCEGUID pguid, CEOID oidDbase, CEDBASEINFO *pNewInfo);
BOOL CeSetThreadPriority(HANDLE hThread, int nPriority);
/**
 * Unmounts a database volume and flushes its cached data.
 *
 * The volume remains mounted until every application that mounted it has
 * unmounted it.
 *
 * @param pguid GUID of the mounted volume.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL CeUnmountDBVol(PCEGUID pguid);
/**
 * Loads a file-system driver associated with a registered device.
 *
 * Use LOADFSD_ASYNCH or LOADFSD_SYNCH. Synchronous loading can deadlock;
 * use it with care.
 *
 * @param hDevice Registered device handle.
 * @param lpFSDName File-system driver name.
 * @param dwFlag LOADFSD_ASYNCH or LOADFSD_SYNCH.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL LoadFSDEx(HANDLE hDevice, LPCWSTR lpFSDName, DWORD dwFlag);
/**
 * Writes a formatted message to the kernel's debug output.
 *
 * DEBUGMSG, RETAILMSG and the other dbgapi.h macros call it. Where the
 * output goes depends on the device: usually a debug serial port or a
 * kernel debugger.
 *
 * @param lpszFmt Wide-character printf-style format string, followed by
 *        its arguments.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
void NKDbgPrintfW(LPCWSTR lpszFmt, ...);
BOOL SHRemoveFontResource(LPCTSTR szFileName);
/**
 * Sends a debug pattern to an OEM-provided LED.
 *
 * This works only when the device's OEM implements LED support.
 *
 * @param wIndex Index identifying an OS component. The OS reserves indexes for
 *               its own components; OEMs can use indexes from 0 through
 *               MAX_OEM_LEDINDEX.
 * @param dwPattern Pattern to send to the LED.
 *
 * @note Windows CE 3.0 only.
 */
void WriteDebugLED(WORD wIndex, DWORD dwPattern);
typedef struct {
    unsigned int Inexact : 1;
    unsigned int Underflow : 1;
    unsigned int Overflow : 1;
    unsigned int ZeroDivide : 1;
    unsigned int InvalidOperation : 1;
} _FPIEEE_EXCEPTION_FLAGS;

typedef float _FP32;
typedef double _FP64;
typedef struct {
    unsigned short W[5];
} _FP80;

typedef struct {
    unsigned long W[4];
} _FP128;

typedef short _I16;
typedef int _I32;
typedef struct {
    unsigned long W[2];
} _I64;

typedef unsigned short _U16;
typedef unsigned int _U32;
typedef struct {
    unsigned long W[2];
} _U64;

typedef struct {
    unsigned short W[5];
} _BCD80;

typedef struct {
    unsigned long W[4];
} _U32ARRAY;

typedef struct {
    union {
        _FP32 Fp32Value;
        _FP64 Fp64Value;
        _FP80 Fp80Value;
        _FP128 Fp128Value;
        _I16 I16Value;
        _I32 I32Value;
        _I64 I64Value;
        _U16 U16Value;
        _U32 U32Value;
        _U64 U64Value;
        _BCD80 Bcd80Value;
        char *StringValue;
        int CompareValue;
        _U32ARRAY U32ArrayValue;
    } Value;
    unsigned int OperandValid : 1;
    unsigned int Format : 4;
} _FPIEEE_VALUE;

typedef struct {
    unsigned int RoundingMode : 2;
    unsigned int Precision : 3;
    unsigned int Operation : 12;
    _FPIEEE_EXCEPTION_FLAGS Cause;
    _FPIEEE_EXCEPTION_FLAGS Enable;
    _FPIEEE_EXCEPTION_FLAGS Status;
    _FPIEEE_VALUE Operand1;
    _FPIEEE_VALUE Operand2;
    _FPIEEE_VALUE Result;
} _FPIEEE_RECORD;

/**
 * Invokes a user handler for an IEEE floating-point exception.
 *
 * Use it as an exception filter in structured exception handling. The
 * handler receives an _FPIEEE_RECORD describing the operation, operands
 * and result.
 *
 * @param exc_code Exception code.
 * @param p Exception information.
 * @param handler IEEE exception handler.
 * @return The value returned by handler.
 *
 * @note Windows CE 3.0 only.
 */
int _fpieee_flt(unsigned long exc_code, PEXCEPTION_POINTERS p, int (*handler)(_FPIEEE_RECORD *));
enum _AUDIT_EVENT_TYPE {
    AuditEventObjectAccess,
    AuditEventDirectoryServiceAccess
};

typedef enum _AUDIT_EVENT_TYPE AUDIT_EVENT_TYPE;
struct _DBGPARAM;
typedef struct _DBGPARAM DBGPARAM;
struct tagDIBSECTION2;
typedef struct tagDIBSECTION2 DIBSECTION2;
struct _EVENTSFORLOGFILE;
typedef struct _EVENTSFORLOGFILE EVENTSFORLOGFILE;
typedef DWORD EXECUTION_STATE;
typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;
struct _FLOAT128;
typedef struct _FLOAT128 FLOAT128;
typedef HANDLE HPROCESS;
typedef HANDLE HTHREAD;
struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;
typedef struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;
struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;
typedef struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;
struct _ImageArchitectureEntry;
typedef struct _ImageArchitectureEntry IMAGE_ARCHITECTURE_ENTRY;
struct _ImageArchitectureHeader;
typedef struct _ImageArchitectureHeader IMAGE_ARCHITECTURE_HEADER;
typedef IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY IMAGE_AXP64_RUNTIME_FUNCTION_ENTRY;
struct _IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef struct _IMAGE_IA64_RUNTIME_FUNCTION_ENTRY IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef struct {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD MajorVersion;
    WORD MinorVersion;
    DWORD GlobalFlagsClear;
    DWORD GlobalFlagsSet;
    DWORD CriticalSectionDefaultTimeout;
    DWORD DeCommitFreeBlockThreshold;
    DWORD DeCommitTotalFreeThreshold;
    DWORD LockPrefixTable;
    DWORD MaximumAllocationSize;
    DWORD VirtualMemoryThreshold;
    DWORD ProcessHeapFlags;
    DWORD ProcessAffinityMask;
    WORD CSDVersion;
    WORD Reserved1;
    DWORD EditList;
    DWORD Reserved[1];
} IMAGE_LOAD_CONFIG_DIRECTORY32;

struct _IMAGE_STUB_DIRECTORY;
typedef struct _IMAGE_STUB_DIRECTORY IMAGE_STUB_DIRECTORY;
struct IMPORT_OBJECT_HEADER;
typedef struct IMPORT_OBJECT_HEADER IMPORT_OBJECT_HEADER;
enum IMPORT_OBJECT_NAME_TYPE {
    IMPORT_OBJECT_ORDINAL = 0,
    IMPORT_OBJECT_NAME = 1,
    IMPORT_OBJECT_NAME_NO_PREFIX = 2,
    IMPORT_OBJECT_NAME_UNDECORATE = 3
};

typedef enum IMPORT_OBJECT_NAME_TYPE IMPORT_OBJECT_NAME_TYPE;
enum IMPORT_OBJECT_TYPE {
    IMPORT_OBJECT_CODE = 0,
    IMPORT_OBJECT_DATA = 1,
    IMPORT_OBJECT_CONST = 2
};

typedef enum IMPORT_OBJECT_TYPE IMPORT_OBJECT_TYPE;
typedef const DLGTEMPLATE *LPCDLGTEMPLATEA;
typedef const DLGTEMPLATE *LPCDLGTEMPLATEW;
typedef CHAR *LPCHAR;
typedef DWORD *LPCOLORREF;
typedef const PAINTSTRUCT *LPCPAINTSTRUCT;
typedef const WAVEFORMAT *LPCWAVEFORMAT;
typedef struct _DBGPARAM *LPDBGPARAM;
typedef struct tagDIBSECTION *LPDIBSECTION;
typedef struct tagDIBSECTION2 *LPDIBSECTION2;
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;
typedef struct tagHARDWAREINPUT *LPHARDWAREINPUT;
typedef struct tagKEYBDINPUT *LPKEYBDINPUT;
typedef struct tagMOUSEINPUT *LPMOUSEINPUT;
typedef short *LPSHORT;
struct _MEMORY_BASIC_INFORMATION_VLM;
typedef struct _MEMORY_BASIC_INFORMATION_VLM MEMORY_BASIC_INFORMATION_VLM;
struct tagCHARSETINFO;
typedef struct tagCHARSETINFO *NPCHARSETINFO;
typedef NPDEVMODEW NPDEVMODE;
typedef struct _devicemodeA *NPDEVMODEA;
typedef struct tagLOGBRUSH *NPLOGBRUSH;
typedef struct tagLOGFONTA *NPLOGFONTA;
typedef struct tagLOGFONTW *NPLOGFONTW;
typedef struct tagLOGPEN *NPLOGPEN;
typedef struct mmtime_tag *NPMMTIME;
typedef struct tagMSG *NPMSG;
typedef struct tagNEWTEXTMETRICW *NPNEWTEXTMETRICW;
typedef NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
typedef struct tagNEWTEXTMETRICA *NPNEWTEXTMETRICA;
typedef PCMWAVEFORMAT *NPPCMWAVEFORMAT;
typedef struct tagPOINT *NPPOINT;
typedef struct tagRECT *NPRECT;
typedef struct _RGNDATA *NPRGNDATA;
typedef struct tagTEXTMETRICW *NPTEXTMETRICW;
typedef NPTEXTMETRICW NPTEXTMETRIC;
typedef struct tagTEXTMETRICA *NPTEXTMETRICA;
typedef WAVEFORMAT *NPWAVEFORMAT;
typedef struct tWAVEFORMATEX *NPWAVEFORMATEX;
typedef struct wavehdr_tag *NPWAVEHDR;
struct tagWAVEINCAPS;
typedef struct tagWAVEINCAPS *NPWAVEINCAPS;
struct tagWAVEOUTCAPS;
typedef struct tagWAVEOUTCAPS *NPWAVEOUTCAPS;
struct _OBJECTID;
typedef struct _OBJECTID OBJECTID;
struct _OBJECT_TYPE_LIST;
typedef struct _OBJECT_TYPE_LIST OBJECT_TYPE_LIST;
struct _PACKEDEVENTINFO;
typedef struct _PACKEDEVENTINFO PACKEDEVENTINFO;
typedef ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;
typedef ACL_SIZE_INFORMATION *PACL_SIZE_INFORMATION;
typedef enum _AUDIT_EVENT_TYPE *PAUDIT_EVENT_TYPE;
typedef struct _BY_HANDLE_FILE_INFORMATION *PBY_HANDLE_FILE_INFORMATION;
typedef const CHAR *PCCH;
typedef struct tagCHARSETINFO *PCHARSETINFO;
typedef struct tagCOLORADJUSTMENT *PCOLORADJUSTMENT;
typedef struct tagCOMPAREITEMSTRUCT *PCOMPAREITEMSTRUCT;
typedef const PAINTSTRUCT *PCPAINTSTRUCT;
typedef struct tagCREATESTRUCTA *PCREATESTRUCTA;
typedef struct tagCREATESTRUCTW *PCREATESTRUCTW;
typedef LPCRECT PCRECT;
typedef LPCWSTR PCTSTR;
typedef struct tagDIBSECTION *PDIBSECTION;
typedef struct tagDIBSECTION2 *PDIBSECTION2;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;
typedef PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
typedef struct _EVENTSFORLOGFILE *PEVENTSFORLOGFILE;
typedef FLOAT128 *PFLOAT128;
typedef void (*PFNVOID)();
typedef struct tagFONTSIGNATURE *PFONTSIGNATURE;
typedef struct tagHANDLETABLE *PHANDLETABLE;
typedef struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY *PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;
typedef struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY *PIMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;
typedef struct _ImageArchitectureEntry *PIMAGE_ARCHITECTURE_ENTRY;
typedef struct _ImageArchitectureHeader *PIMAGE_ARCHITECTURE_HEADER;
typedef PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY PIMAGE_AXP64_RUNTIME_FUNCTION_ENTRY;
typedef struct _IMAGE_IA64_RUNTIME_FUNCTION_ENTRY *PIMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
typedef IMAGE_LOAD_CONFIG_DIRECTORY32 *PIMAGE_LOAD_CONFIG_DIRECTORY32;
typedef struct _IMAGE_STUB_DIRECTORY *PIMAGE_STUB_DIRECTORY;
typedef INT16 *PINT16;
typedef INT8 *PINT8;
struct _SECURITY_DESCRIPTOR_RELATIVE;
typedef struct _SECURITY_DESCRIPTOR_RELATIVE *PISECURITY_DESCRIPTOR_RELATIVE;
typedef struct _MEMORY_BASIC_INFORMATION_VLM *PMEMORY_BASIC_INFORMATION_VLM;
typedef struct _OBJECT_TYPE_LIST *POBJECT_TYPE_LIST;
typedef unsigned long POINTER_64_INT;
struct _POWER_DEVICE_TIMEOUTS;
typedef struct _POWER_DEVICE_TIMEOUTS POWER_DEVICE_TIMEOUTS;
typedef struct _PACKEDEVENTINFO *PPACKEDEVENTINFO;
typedef PAINTSTRUCT *PPAINTSTRUCT;
typedef struct _POWER_DEVICE_TIMEOUTS *PPOWER_DEVICE_TIMEOUTS;
typedef void **PPVOID;
typedef struct _RGNDATAHEADER *PRGNDATAHEADER;
typedef struct _LIST_ENTRY *PRLIST_ENTRY;
typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_RESOURCE_DEBUG;
typedef LPTHREAD_START_ROUTINE PTHREAD_START_ROUTINE;
typedef enum _TOKEN_INFORMATION_CLASS *PTOKEN_INFORMATION_CLASS;
typedef UINT16 *PUINT16;
typedef UINT8 *PUINT8;
typedef struct _RTL_CRITICAL_SECTION_DEBUG RTL_RESOURCE_DEBUG;
typedef struct _SECURITY_DESCRIPTOR_RELATIVE SECURITY_DESCRIPTOR_RELATIVE;
typedef HANDLE *SPHANDLE;
typedef void (*WAITORTIMERCALLBACKFUNC)(PVOID, BOOLEAN);
typedef DWORD WIN32_ERROR_CODE;
typedef void (*WORKERCALLBACKFUNC)(PVOID);
typedef wint_t _TINT;
typedef wchar_t _TSCHAR;
typedef wchar_t _TUCHAR;
typedef wchar_t _TXCHAR;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned short ushort;
struct HHOOK__;
struct HHOOK__ {
    int unused;
};

struct IMPORT_OBJECT_HEADER {
    WORD Sig1;
    WORD Sig2;
    WORD Version;
    WORD Machine;
    DWORD TimeDateStamp;
    DWORD SizeOfData;
    union {
        WORD Ordinal;
        WORD Hint;
    };
    WORD Type : 2;
    WORD NameType : 3;
    WORD Reserved : 11;
};

struct _CEGUID {
    DWORD Data1;
    DWORD Data2;
    DWORD Data3;
    DWORD Data4;
};

struct _CENOTIFICATION {
    DWORD dwSize;
    DWORD dwParam;
    UINT uType;
    CEGUID guid;
    CEOID oid;
    CEOID oidParent;
};

struct _CENOTIFYREQUEST {
    DWORD dwSize;
    HWND hwnd;
    DWORD dwFlags;
    HANDLE hHeap;
    DWORD dwParam;
};

struct _COMMCONFIG;
struct _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
};

struct _DBGPARAM {
    WCHAR lpszName[32];
    WCHAR rglpszZones[16][32];
    ULONG ulZoneMask;
};

struct _EVENTSFORLOGFILE {
    DWORD ulSize;
    WCHAR szLogicalLogFile[256];
    DWORD ulNumRecords;
    EVENTLOGRECORD pEventLogRecords[];
};

struct _FLOAT128 {
    long long LowPart;
    long long HighPart;
};

struct _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY {
    ULONGLONG BeginAddress;
    ULONGLONG EndAddress;
    ULONGLONG ExceptionHandler;
    ULONGLONG HandlerData;
    ULONGLONG PrologEndAddress;
};

struct _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD ExceptionHandler;
    DWORD HandlerData;
    DWORD PrologEndAddress;
};

struct _IMAGE_IA64_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindInfoAddress;
};

struct _IMAGE_STUB_DIRECTORY {
    DWORD SecondaryImportAddressTable;
    WORD ExpectedISA[2];
    DWORD StubAddressTable[2];
};

struct _INT128;
struct _INT128 {
    UINT32 u0;
    UINT32 u1;
    UINT32 u2;
    INT32 u3;
};

struct _ImageArchitectureEntry {
    DWORD FixupInstRVA;
    DWORD NewInst;
};

struct _ImageArchitectureHeader {
    unsigned int AmaskValue : 1;
    int  : 7;
    unsigned int AmaskShift : 8;
    int  : 16;
    DWORD FirstEntryRVA;
};

struct _MEMORY_BASIC_INFORMATION_VLM {
    union {
        PVOID64 BaseAddress;
        ULONGLONG BaseAddressAsUlongLong;
    };
    union {
        PVOID64 AllocationBase;
        ULONGLONG AllocationBaseAsUlongLong;
    };
    ULONGLONG RegionSize;
    DWORD AllocationProtect;
    DWORD State;
    DWORD Protect;
    DWORD Type;
};

struct _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
};

struct _OBJECT_TYPE_LIST {
    WORD Level;
    WORD Sbz;
    GUID *ObjectType;
};

struct _PACKEDEVENTINFO {
    DWORD ulSize;
    DWORD ulNumEventsForLogFile;
    DWORD ulOffsets[];
};

struct _PAINTSTRUCT;
struct _PAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};

struct _POINTL;
struct _POINTL {
    LONG x;
    LONG y;
};

struct _POWER_DEVICE_TIMEOUTS {
    DWORD ConservationIdleTime;
    DWORD PerformanceIdleTime;
};

struct _RECTL;
struct _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

struct _SECURITY_DESCRIPTOR_RELATIVE {
    BYTE Revision;
    BYTE Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    DWORD Owner;
    DWORD Group;
    DWORD Sacl;
    DWORD Dacl;
};

struct _SHELLEXECUTEINFO;
struct _SHELLEXECUTEINFO {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCTSTR lpVerb;
    LPCTSTR lpFile;
    LPCTSTR lpParameters;
    LPCTSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCTSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    HANDLE hIcon;
    HANDLE hProcess;
} __attribute__((packed, aligned(1)));

struct _UINT128;
struct _UINT128 {
    UINT32 u0;
    UINT32 u1;
    UINT32 u2;
    UINT32 u3;
};

struct _tagBITMAPFILEHEADER;
struct _tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((packed, aligned(2)));

struct tagBITMAPCOREINFO;
struct tagBITMAPCOREINFO {
    BITMAPCOREHEADER bmciHeader;
    RGBTRIPLE bmciColors[1];
};

struct tagCHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
};

struct tagDELETITEMSTRUCT;
struct tagDELETITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    HWND hwndItem;
    UINT itemData;
};

struct tagDIBSECTION2 {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD dsOffset;
    DWORD dsAlphaBitfield;
};

struct tagENUMLOGFONT;
struct tagENUMLOGFONT {
    LOGFONTW elfLogFont;
    TCHAR elfFullName[64];
    TCHAR elfStyle[32];
};

struct tagPCMWAVEFORMAT;
struct tagPCMWAVEFORMAT {
    WAVEFORMAT wf;
    WORD wBitsPerSample;
} __attribute__((packed, aligned(1)));

struct tagWAVEINCAPS {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    TCHAR szPname[32];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
} __attribute__((packed, aligned(1)));

struct tagWAVEOUTCAPS {
    WORD wMid;
    WORD wPid;
    MMVERSION vDriverVersion;
    TCHAR szPname[32];
    DWORD dwFormats;
    WORD wChannels;
    WORD wReserved1;
    DWORD dwSupport;
} __attribute__((packed, aligned(1)));

struct tagWINDOWPOS;
struct tagWINDOWPOS {
    HWND hwnd;
    HWND hwndInsertAfter;
    int x;
    int y;
    int cx;
    int cy;
    UINT flags;
};

struct tagWNDCLASSA;
struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

struct tagWNDCLASSW;
struct tagWNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
};


#ifdef __cplusplus
}
#endif

#endif

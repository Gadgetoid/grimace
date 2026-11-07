#ifndef GRIMACE_SDK_RAS_H
#define GRIMACE_SDK_RAS_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Displays a RAS device configuration dialog and returns edited settings.
 *
 * This is the RASCNTL_DEVCONFIGDIALOGEDIT control operation.
 *
 * @param szDeviceName Device name.
 * @param szDeviceType Device type.
 * @param hWndOwner Owner window for the dialog.
 * @param lpDeviceConfigIn Existing device configuration data.
 * @param dwSize Size of the input configuration data, in bytes.
 * @param lpDeviceConfigOut Receives the resulting device configuration.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 and later.
 */
DWORD RasDevConfigDialogEditW(LPCWSTR szDeviceName, LPCWSTR szDeviceType, HWND hWndOwner, LPVOID lpDeviceConfigIn, DWORD dwSize, LPVARSTRING lpDeviceConfigOut);
/**
 * Retrieves the display phone number for a RAS phonebook entry.
 *
 * This is the RASCNTL_GETDISPPHONE control operation.
 *
 * @param szPhonebook Phonebook name.
 * @param szEntry Phonebook entry name.
 * @param szPhoneNum Receives the display phone number.
 * @param dwPhoneNumLen Output buffer capacity, in characters.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 and later.
 */
DWORD RasGetDispPhoneNumW(LPCWSTR szPhonebook, LPCWSTR szEntry, LPWSTR szPhoneNum, DWORD dwPhoneNumLen);
struct _RAS_STATS;
typedef struct _RAS_STATS RAS_STATS;
DWORD RasGetLinkStatistics(HRASCONN hRasConn, DWORD dwSubEntry, RAS_STATS *lpStatistics);
typedef struct tagRASAMBA *LPRASAMB;
struct tagRasCntlDevConfigDlgEdit;
typedef struct tagRasCntlDevConfigDlgEdit *PRASCNTL_DEVCFGDLGED;
typedef struct _RAS_STATS *PRAS_STATS;
typedef struct tagRasCntlDevConfigDlgEdit RASCNTL_DEVCFGDLGED;
struct _RAS_STATS {
    DWORD dwSize;
    DWORD dwBytesXmited;
    DWORD dwBytesRcved;
    DWORD dwFramesXmited;
    DWORD dwFramesRcved;
    DWORD dwCrcErr;
    DWORD dwTimeoutErr;
    DWORD dwAlignmentErr;
    DWORD dwHardwareOverrunErr;
    DWORD dwFramingErr;
    DWORD dwBufferOverrunErr;
    DWORD dwCompressionRatioIn;
    DWORD dwCompressionRatioOut;
    DWORD dwBps;
    DWORD dwConnectDuration;
} __attribute__((packed, aligned(4)));

struct tagRASCONN;
struct tagRASCONN {
    DWORD dwSize;
    HRASCONN hrasconn;
    TCHAR szEntryName[21];
} __attribute__((packed, aligned(4)));

struct tagRASCONNSTATUS;
struct tagRASCONNSTATUS {
    DWORD dwSize;
    RASCONNSTATE rasconnstate;
    DWORD dwError;
    TCHAR szDeviceType[17];
    TCHAR szDeviceName[33];
} __attribute__((packed, aligned(4)));

struct tagRASDIALPARAMS;
struct tagRASDIALPARAMS {
    DWORD dwSize;
    TCHAR szEntryName[21];
    TCHAR szPhoneNumber[129];
    TCHAR szCallbackNumber[49];
    TCHAR szUserName[257];
    TCHAR szPassword[257];
    TCHAR szDomain[16];
} __attribute__((packed, aligned(4)));

struct tagRASENTRYNAME;
struct tagRASENTRYNAME {
    DWORD dwSize;
    TCHAR szEntryName[21];
} __attribute__((packed, aligned(4)));

struct tagRASIPX;
struct tagRASIPX {
    DWORD dwSize;
    DWORD dwError;
    TCHAR szIpxAddress[22];
} __attribute__((packed, aligned(4)));

struct tagRASPPPAddr;
struct tagRASPPPAddr {
    DWORD dwSize;
    DWORD dwError;
    BOOL Valid;
    DWORD IpAddress;
} __attribute__((packed, aligned(4)));

struct tagRASPPPIP;
struct tagRASPPPIP {
    DWORD dwSize;
    DWORD dwError;
    TCHAR szIpAddress[16];
} __attribute__((packed, aligned(4)));

struct tagRNAAppInfo;
struct tagRNAAppInfo {
    DWORD dwSize;
    DWORD hWndRNAApp;
    DWORD Context;
    DWORD ErrorCode;
    TCHAR RasEntryName[21];
} __attribute__((packed, aligned(4)));

struct tagRasCntlDevConfigDlgEdit {
    WCHAR szDeviceName[33];
    WCHAR szDeviceType[17];
    HWND hWndOwner;
    DWORD dwSize;
    BYTE DataBuf[1];
} __attribute__((packed, aligned(4)));

struct tagRasCtryInfo;
struct tagRasCtryInfo {
    DWORD dwSize;
    DWORD dwCountryID;
    DWORD dwNextCountryID;
    DWORD dwCountryCode;
    DWORD dwCountryNameOffset;
} __attribute__((packed, aligned(4)));

struct tagRasDevInfoW;
struct tagRasDevInfoW {
    DWORD dwSize;
    WCHAR szDeviceType[17];
    WCHAR szDeviceName[33];
} __attribute__((packed, aligned(4)));

struct tagRasEntry;
struct tagRasEntry {
    DWORD dwSize;
    DWORD dwfOptions;
    DWORD dwCountryID;
    DWORD dwCountryCode;
    TCHAR szAreaCode[11];
    TCHAR szLocalPhoneNumber[129];
    DWORD dwAlternatesOffset;
    RASIPADDR ipaddr;
    RASIPADDR ipaddrDns;
    RASIPADDR ipaddrDnsAlt;
    RASIPADDR ipaddrWins;
    RASIPADDR ipaddrWinsAlt;
    DWORD dwFrameSize;
    DWORD dwfNetProtocols;
    DWORD dwFramingProtocol;
    TCHAR szScript[260];
    TCHAR szAutoDialDll[260];
    TCHAR szAutoDialFunc[260];
    TCHAR szDeviceType[17];
    TCHAR szDeviceName[33];
    TCHAR szX25PadType[33];
    TCHAR szX25Address[201];
    TCHAR szX25Facilities[201];
    TCHAR szX25UserData[201];
    DWORD dwChannels;
    DWORD dwReserved1;
    DWORD dwReserved2;
} __attribute__((packed, aligned(4)));

struct tagRasIpAddr;
struct tagRasIpAddr {
    BYTE a;
    BYTE b;
    BYTE c;
    BYTE d;
} __attribute__((packed, aligned(1)));

enum tagRasCntlEnum {
    RASCNTL_SET_DEBUG,
    RASCNTL_LOCK_STATUS,
    RASCNTL_PRINT_CS,
    RASCNTL_STATISTICS,
    RASCNTL_ENUMDEV,
    RASCNTL_GETPROJINFO,
    RASCNTL_GETDISPPHONE,
    RASCNTL_DEVCONFIGDIALOGEDIT
};


#ifdef __cplusplus
}
#endif

#endif

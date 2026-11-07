#ifndef _RAS_H
#define _RAS_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _LMCONS_H
#include <lmcons.h>
#endif

/* TODO
include <basetsd.h> from winnt.h so that this typedef is not necessary
*/
#ifndef _BASETSD_H
typedef unsigned long ULONG_PTR, *PULONG_PTR;
#endif

#include <pshpack4.h>

#define RAS_MaxDeviceType     16
#define RAS_MaxPhoneNumber    128
#define RAS_MaxIpAddress      15
#define RAS_MaxIpxAddress     21
#ifdef _WIN32_WCE
#define RAS_MaxEntryName      20
#else
#define RAS_MaxEntryName      256
#endif
#ifdef _WIN32_WCE
#define RAS_MaxDeviceName     32
#else
#define RAS_MaxDeviceName     128
#endif
#ifdef _WIN32_WCE
#define RAS_MaxCallbackNumber 48
#else
#define RAS_MaxCallbackNumber RAS_MaxPhoneNumber
#endif
#define RAS_MaxAreaCode       10
#define RAS_MaxPadType        32
#define RAS_MaxX25Address     200
#define RAS_MaxFacilities     200
#define RAS_MaxUserData       200
#define RAS_MaxReplyMessage   1024
#define RAS_MaxDnsSuffix      256
#define RDEOPT_UsePrefixSuffix           0x00000001
#define RDEOPT_PausedStates              0x00000002
#define RDEOPT_IgnoreModemSpeaker        0x00000004
#define RDEOPT_SetModemSpeaker           0x00000008
#define RDEOPT_IgnoreSoftwareCompression 0x00000010
#define RDEOPT_SetSoftwareCompression    0x00000020
#define RDEOPT_DisableConnectedUI        0x00000040
#define RDEOPT_DisableReconnectUI        0x00000080
#define RDEOPT_DisableReconnect          0x00000100
#define RDEOPT_NoUser                    0x00000200
#define RDEOPT_PauseOnScript             0x00000400
#define RDEOPT_Router                    0x00000800
#define REN_User                         0x00000000
#define REN_AllUsers                     0x00000001
#define VS_Default		                0
#define VS_PptpOnly	                    1
#define VS_PptpFirst	                2
#define VS_L2tpOnly 	                3
#define VS_L2tpFirst	                4
#define RASDIALEVENT                    "RasDialEvent"
/**
 * This message is sent by the OS to a window procedure when a change of
 * state event occurs during a Remote Access Service (RAS) connection
 * process, and a window has been specified to handle notifications of such
 * events by using the notifier parameter of RasDial.
 *
 * @param rasconnstate Equivalent to the rasconnstate parameter of the
 *        RasDialFunc and RasDialFunc1 callback functions. Specifies a
 *        RASCONNSTATE enumerator value that indicates the state the
 *        RasDial RAS connection process is about to enter.
 * @param dwError Equivalent to the dwError parameter of the RasDialFunc
 *        and RasDialFunc1 callback functions. A nonzero value indicates
 *        the error that has occurred, or zero if no error has occurred.
 *        RasDial sends this message with dwError set to zero upon entry to
 *        each connection state. If an error occurs within a state, the
 *        message is sent again for the state, this time with a nonzero
 *        dwError value.
 * @return An application should return TRUE if it processes this message.
 */
#define WM_RASDIALEVENT                 0xCCCD
#define RASEO_UseCountryAndAreaCodes    0x00000001
#define RASEO_SpecificIpAddr            0x00000002
#define RASEO_SpecificNameServers       0x00000004
#define RASEO_IpHeaderCompression       0x00000008
#define RASEO_RemoteDefaultGateway      0x00000010
#define RASEO_DisableLcpExtensions      0x00000020
#define RASEO_TerminalBeforeDial        0x00000040
#define RASEO_TerminalAfterDial         0x00000080
#define RASEO_ModemLights               0x00000100
#define RASEO_SwCompression             0x00000200
#define RASEO_RequireEncryptedPw        0x00000400
#define RASEO_RequireMsEncryptedPw      0x00000800
#define RASEO_RequireDataEncryption     0x00001000
#define RASEO_NetworkLogon              0x00002000
#define RASEO_UseLogonCredentials       0x00004000
#define RASEO_PromoteAlternates         0x00008000
#if (WINVER >= 0x501)
#define RASEO2_SecureFileAndPrint       0x00000001
#define RASEO2_SecureClientForMSNet     0x00000002
#define RASEO2_DontNegotiateMultilink   0x00000004
#define RASEO2_DontUseRasCredentials    0x00000008
#define RASEO2_UsePreSharedKey          0x00000010
#define RASEO2_Internet                 0x00000020
#define RASEO2_DisableNbtOverIP         0x00000040
#define RASEO2_UseGlobalDeviceSettings  0x00000080
#define RASEO2_ReconnectIfDropped       0x00000100
#define RASEO2_SharePhoneNumbers        0x00000200
#endif		
#define RASNP_NetBEUI                   0x00000001
#define RASNP_Ipx                       0x00000002
#define RASNP_Ip                        0x00000004
#define RASFP_Ppp                       0x00000001
#define RASFP_Slip                      0x00000002
#define RASFP_Ras                       0x00000004
#define RASDT_Modem                     TEXT("modem")
#define RASDT_Isdn                      TEXT("isdn")
#define RASDT_X25                       TEXT("x25")
#define RASDT_Vpn                       TEXT("vpn")
#define RASDT_Pad                       TEXT("pad")
#define RASDT_Generic                   TEXT("GENERIC")
#define RASDT_Serial        		TEXT("SERIAL")
#define RASDT_FrameRelay                TEXT("FRAMERELAY")
#define RASDT_Atm                       TEXT("ATM")
#define RASDT_Sonet                     TEXT("SONET")
#define RASDT_SW56                      TEXT("SW56")
#define RASDT_Irda                      TEXT("IRDA")
#define RASDT_Parallel                  TEXT("PARALLEL")
#define RASET_Phone     1
#define RASET_Vpn       2
#define RASET_Direct    3
#define RASET_Internet  4
#if (WINVER >= 0x401)
#define RASEO_SecureLocalFiles  0x00010000
#define RASCN_Connection        0x00000001
#define RASCN_Disconnection     0x00000002
#define RASCN_BandwidthAdded    0x00000004
#define RASCN_BandwidthRemoved  0x00000008
#define RASEDM_DialAll          1
#define RASEDM_DialAsNeeded     2
#define RASIDS_Disabled         0xffffffff
#define RASIDS_UseGlobalValue   0
#define RASADFLG_PositionDlg    0x00000001
#define RASCM_UserName       0x00000001
#define RASCM_Password       0x00000002
#define RASCM_Domain         0x00000004
#define RASADP_DisableConnectionQuery   0
#define RASADP_LoginSessionDisable      1
#define RASADP_SavedAddressesLimit      2
#define RASADP_FailedConnectionTimeout  3
#define RASADP_ConnectionQueryTimeout   4
#endif  /* (WINVER >= 0x401) */
#if (WINVER >= 0x500)
#define RDEOPT_CustomDial   0x00001000
#define RASLCPAP_PAP        0xC023
#define RASLCPAP_SPAP       0xC027
#define RASLCPAP_CHAP       0xC223
#define RASLCPAP_EAP        0xC227
#define RASLCPAD_CHAP_MD5   0x05
#define RASLCPAD_CHAP_MS    0x80
#define RASLCPAD_CHAP_MSV2  0x81
#define RASLCPO_PFC         0x00000001
#define RASLCPO_ACFC        0x00000002
#define RASLCPO_SSHF        0x00000004
#define RASLCPO_DES_56      0x00000008
#define RASLCPO_3_DES       0x00000010
#define RASCCPCA_MPPC       0x00000006
#define RASCCPCA_STAC       0x00000005
#define RASCCPO_Compression         0x00000001
#define RASCCPO_HistoryLess         0x00000002
#define RASCCPO_Encryption56bit     0x00000010
#define RASCCPO_Encryption40bit     0x00000020
#define RASCCPO_Encryption128bit    0x00000040
#define RASEO_RequireEAP            0x00020000
#define RASEO_RequirePAP            0x00040000
#define RASEO_RequireSPAP           0x00080000
#define RASEO_Custom                0x00100000
#define RASEO_PreviewPhoneNumber    0x00200000
#define RASEO_SharedPhoneNumbers    0x00800000
#define RASEO_PreviewUserPw         0x01000000
#define RASEO_PreviewDomain         0x02000000
#define RASEO_ShowDialingProgress   0x04000000
#define RASEO_RequireCHAP           0x08000000
#define RASEO_RequireMsCHAP         0x10000000
#define RASEO_RequireMsCHAP2        0x20000000
#define RASEO_RequireW95MSCHAP      0x40000000
#define RASEO_CustomScript          0x80000000
#define RASIPO_VJ                   0x00000001
#define RCD_SingleUser              0
#define RCD_AllUsers                0x00000001
#define RCD_Eap                     0x00000002
#define RASEAPF_NonInteractive      0x00000002
#define RASEAPF_Logon               0x00000004
#define RASEAPF_Preview             0x00000008
#define ET_40Bit        1
#define ET_128Bit       2
#define ET_None         0
#define ET_Require      1
#define ET_RequireMax   2
#define ET_Optional     3
#endif /* (WINVER >= 0x500) */

#define RASCS_PAUSED 0x1000
#define RASCS_DONE   0x2000
typedef enum tagRASCONNSTATE {
      RASCS_OpenPort = 0,
      RASCS_PortOpened,
      RASCS_ConnectDevice,
      RASCS_DeviceConnected,
      RASCS_AllDevicesConnected,
      RASCS_Authenticate,
      RASCS_AuthNotify,
      RASCS_AuthRetry,
      RASCS_AuthCallback,
      RASCS_AuthChangePassword,
      RASCS_AuthProject,
      RASCS_AuthLinkSpeed,
      RASCS_AuthAck,
      RASCS_ReAuthenticate,
      RASCS_Authenticated,
      RASCS_PrepareForCallback,
      RASCS_WaitForModemReset,
      RASCS_WaitForCallback,
      RASCS_Projected,
      RASCS_StartAuthentication,
      RASCS_CallbackComplete,
      RASCS_LogonNetwork,
      RASCS_SubEntryConnected,
      RASCS_SubEntryDisconnected,
      RASCS_Interactive = RASCS_PAUSED,
      RASCS_RetryAuthentication,
      RASCS_CallbackSetByCaller,
      RASCS_PasswordExpired,
#if (WINVER >= 0x500)
      RASCS_InvokeEapUI,
#endif
      RASCS_Connected = RASCS_DONE,
      RASCS_Disconnected
}  RASCONNSTATE, *LPRASCONNSTATE;

typedef enum tagRASPROJECTION {
    RASP_Amb =      0x10000,
    RASP_PppNbf =   0x803F,
    RASP_PppIpx =   0x802B,
    RASP_PppIp =    0x8021,
#if (WINVER >= 0x500)
    RASP_PppCcp =   0x80FD,
#endif
    RASP_PppLcp =   0xC021,
    RASP_Slip =     0x20000
} RASPROJECTION, *LPRASPROJECTION;

DECLARE_HANDLE (HRASCONN);
typedef  HRASCONN* LPHRASCONN;

typedef struct tagRASCONNW {
    DWORD dwSize;
    HRASCONN hrasconn;
    WCHAR szEntryName[RAS_MaxEntryName + 1];
#if (WINVER >= 0x400) && !defined(_WIN32_WCE)
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
#endif
#if (WINVER >= 0x401) && !defined(_WIN32_WCE)
    WCHAR szPhonebook[MAX_PATH];
    DWORD dwSubEntry;
#endif
#if (WINVER >= 0x500)
    GUID guidEntry;
#endif
#if (WINVER >= 0x501)
    DWORD dwFlags;
    LUID luid;
#endif
} RASCONNW, *LPRASCONNW;

typedef struct tagRASCONNA {
    DWORD dwSize;
    HRASCONN hrasconn;
    CHAR szEntryName[RAS_MaxEntryName + 1];
#if (WINVER >= 0x400) && !defined(_WIN32_WCE)
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
#endif
#if (WINVER >= 0x401) && !defined(_WIN32_WCE)
    CHAR szPhonebook[MAX_PATH];
    DWORD dwSubEntry;
#endif
#if (WINVER >= 0x500)
    GUID guidEntry;
#endif
#if (WINVER >= 0x501)
    DWORD dwFlags;
    LUID luid;
#endif
} RASCONNA, *LPRASCONNA;

typedef struct tagRASCONNSTATUSW {
    DWORD dwSize;
    RASCONNSTATE rasconnstate;
    DWORD dwError;
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
#if (WINVER >= 0x401)
    WCHAR szPhoneNumber[RAS_MaxPhoneNumber + 1];
#endif
} RASCONNSTATUSW, *LPRASCONNSTATUSW;

typedef struct tagRASCONNSTATUSA {
    DWORD dwSize;
    RASCONNSTATE rasconnstate;
    DWORD dwError;
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
#if (WINVER >= 0x401)
    CHAR szPhoneNumber[RAS_MaxPhoneNumber + 1];
#endif
} RASCONNSTATUSA, *LPRASCONNSTATUSA;

typedef struct tagRASDIALPARAMSW {
    DWORD dwSize;
    WCHAR szEntryName[RAS_MaxEntryName + 1];
    WCHAR szPhoneNumber[RAS_MaxPhoneNumber + 1];
    WCHAR szCallbackNumber[RAS_MaxCallbackNumber + 1];
    WCHAR szUserName[UNLEN + 1];
    WCHAR szPassword[PWLEN + 1];
    WCHAR szDomain[DNLEN + 1];
#if (WINVER >= 0x401)
    DWORD dwSubEntry;
    ULONG_PTR dwCallbackId;
#endif
} RASDIALPARAMSW, *LPRASDIALPARAMSW;

typedef struct tagRASDIALPARAMSA {
    DWORD dwSize;
    CHAR szEntryName[RAS_MaxEntryName + 1];
    CHAR szPhoneNumber[RAS_MaxPhoneNumber + 1];
    CHAR szCallbackNumber[RAS_MaxCallbackNumber + 1];
    CHAR szUserName[UNLEN + 1];
    CHAR szPassword[PWLEN + 1];
    CHAR szDomain[DNLEN + 1];
#if (WINVER >= 0x401)
    DWORD dwSubEntry;
    ULONG_PTR dwCallbackId;
#endif
} RASDIALPARAMSA, *LPRASDIALPARAMSA;

#if (WINVER >= 0x500)
typedef struct tagRASEAPINFO {
    DWORD dwSizeofEapInfo;
    BYTE *pbEapInfo;
} RASEAPINFO;
#endif

typedef struct tagRASDIALEXTENSIONS {
    DWORD dwSize;
    DWORD dwfOptions;
    HWND hwndParent;
    ULONG_PTR reserved;
#if (WINVER >= 0x500)
    ULONG_PTR reserved1;
    RASEAPINFO RasEapInfo;
#endif
} RASDIALEXTENSIONS, *LPRASDIALEXTENSIONS;

typedef struct tagRASENTRYNAMEW {
    DWORD dwSize;
    WCHAR szEntryName[RAS_MaxEntryName + 1];
#if (WINVER >= 0x500)
    DWORD dwFlags;
    WCHAR szPhonebookPath[MAX_PATH + 1];
#endif
} RASENTRYNAMEW, *LPRASENTRYNAMEW;

typedef struct tagRASENTRYNAMEA {
    DWORD dwSize;
    CHAR szEntryName[RAS_MaxEntryName + 1];
#if (WINVER >= 0x500)
    DWORD dwFlags;
    CHAR szPhonebookPath[MAX_PATH + 1];
#endif
} RASENTRYNAMEA, *LPRASENTRYNAMEA;

typedef struct tagRASAMBW {
    DWORD dwSize;
    DWORD dwError;
    WCHAR szNetBiosError[NETBIOS_NAME_LEN + 1];
    BYTE bLana;
} RASAMBW, *LPRASAMBW;

typedef struct tagRASAMBA {
    DWORD dwSize;
    DWORD dwError;
#ifdef _WIN32_WCE
    WCHAR szNetBiosError[NETBIOS_NAME_LEN + 1];
#else
    CHAR szNetBiosError[NETBIOS_NAME_LEN + 1];
#endif
    BYTE bLana;
} RASAMBA, *LPRASAMBA;

typedef struct tagRASPPPNBFW {
    DWORD dwSize;
    DWORD dwError;
    DWORD dwNetBiosError;
    WCHAR szNetBiosError[NETBIOS_NAME_LEN + 1];
    WCHAR szWorkstationName[NETBIOS_NAME_LEN + 1];
    BYTE bLana;
} RASPPPNBFW, *LPRASPPPNBFW;

typedef struct tagRASPPPNBFA {
    DWORD dwSize;
    DWORD dwError;
    DWORD dwNetBiosError;
    CHAR szNetBiosError[NETBIOS_NAME_LEN + 1];
    CHAR szWorkstationName[NETBIOS_NAME_LEN + 1];
    BYTE bLana;
} RASPPPNBFA, *LPRASPPPNBFA;

typedef struct tagRASIPXW {
    DWORD dwSize;
    DWORD dwError;
    WCHAR szIpxAddress[RAS_MaxIpxAddress + 1];
} RASPPPIPXW, *LPRASPPPIPXW;

typedef struct tagRASIPXA {
    DWORD dwSize;
    DWORD dwError;
    CHAR szIpxAddress[RAS_MaxIpxAddress + 1];
} RASPPPIPXA, *LPRASPPPIPXA;

typedef struct tagRASPPPIPW {
    DWORD dwSize;
    DWORD dwError;
    WCHAR szIpAddress[RAS_MaxIpAddress + 1];
#if !defined(WINNT35COMPATIBLE) && !defined(_WIN32_WCE)
    WCHAR szServerIpAddress[RAS_MaxIpAddress + 1];
#endif
#if (WINVER >= 0x500)
    DWORD dwOptions;
    DWORD dwServerOptions;
#endif
} RASPPPIPW, *LPRASPPPIPW;

typedef struct tagRASPPPIPA {
    DWORD dwSize;
    DWORD dwError;
    CHAR szIpAddress[RAS_MaxIpAddress + 1];
#if !defined(WINNT35COMPATIBLE) && !defined(_WIN32_WCE)
    CHAR szServerIpAddress[RAS_MaxIpAddress + 1];
#endif
#if (WINVER >= 0x500)
    DWORD dwOptions;
    DWORD dwServerOptions;
#endif
} RASPPPIPA, *LPRASPPPIPA;

typedef struct tagRASPPPLCPW {
    DWORD dwSize;
    BOOL fBundled;
#if (WINVER >= 0x500)
    DWORD dwError;
    DWORD dwAuthenticationProtocol;
    DWORD dwAuthenticationData;
    DWORD dwEapTypeId;
    DWORD dwServerAuthenticationProtocol;
    DWORD dwServerAuthenticationData;
    DWORD dwServerEapTypeId;
    BOOL fMultilink;
    DWORD dwTerminateReason;
    DWORD dwServerTerminateReason;
    WCHAR szReplyMessage[RAS_MaxReplyMessage];
    DWORD dwOptions;
    DWORD dwServerOptions;
#endif
} RASPPPLCPW, *LPRASPPPLCPW;

typedef struct tagRASPPPLCPA {
    DWORD dwSize;
    BOOL fBundled;
#if (WINVER >= 0x500)
    DWORD dwError;
    DWORD dwAuthenticationProtocol;
    DWORD dwAuthenticationData;
    DWORD dwEapTypeId;
    DWORD dwServerAuthenticationProtocol;
    DWORD dwServerAuthenticationData;
    DWORD dwServerEapTypeId;
    BOOL fMultilink;
    DWORD dwTerminateReason;
    DWORD dwServerTerminateReason;
    CHAR szReplyMessage[RAS_MaxReplyMessage];
    DWORD dwOptions;
    DWORD dwServerOptions;
#endif
} RASPPPLCPA, *LPRASPPPLCPA;

typedef struct tagRASSLIPW {
    DWORD dwSize;
    DWORD dwError;
    WCHAR szIpAddress[RAS_MaxIpAddress + 1];
} RASSLIPW, *LPRASSLIPW;


typedef struct tagRASSLIPA {
    DWORD dwSize;
    DWORD dwError;
    CHAR szIpAddress[RAS_MaxIpAddress + 1];
} RASSLIPA, *LPRASSLIPA;

typedef struct tagRASDEVINFOW {
    DWORD dwSize;
#if defined(_WIN32_WCE) && _WIN32_WCE < 0x300
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
} RASDEVINFOW, *LPRASDEVINFOW;
#else
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
} RASDEVINFOW, *LPRASDEVINFOW;
#endif

typedef struct tagRASDEVINFOA {
    DWORD dwSize;
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
} RASDEVINFOA, *LPRASDEVINFOA;

typedef struct tagRASCTRYINFO {
    DWORD dwSize;
    DWORD dwCountryID;
    DWORD dwNextCountryID;
    DWORD dwCountryCode;
    DWORD dwCountryNameOffset;
} RASCTRYINFO, *LPRASCTRYINFO;

typedef RASCTRYINFO  RASCTRYINFOW, *LPRASCTRYINFOW;
typedef RASCTRYINFO  RASCTRYINFOA, *LPRASCTRYINFOA;

typedef struct tagRASIPADDR {
    BYTE a;
    BYTE b;
    BYTE c;
    BYTE d;
} RASIPADDR;

typedef struct tagRASENTRYW {
    DWORD dwSize;
    DWORD dwfOptions;
    DWORD dwCountryID;
    DWORD dwCountryCode;
    WCHAR szAreaCode[RAS_MaxAreaCode + 1];
    WCHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
    RASIPADDR ipaddr;
    RASIPADDR ipaddrDns;
    RASIPADDR ipaddrDnsAlt;
    RASIPADDR ipaddrWins;
    RASIPADDR ipaddrWinsAlt;
    DWORD dwFrameSize;
    DWORD dwfNetProtocols;
    DWORD dwFramingProtocol;
    WCHAR szScript[MAX_PATH];
    WCHAR szAutodialDll[MAX_PATH];
    WCHAR szAutodialFunc[MAX_PATH];
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
    WCHAR szX25PadType[RAS_MaxPadType + 1];
    WCHAR szX25Address[RAS_MaxX25Address + 1];
    WCHAR szX25Facilities[RAS_MaxFacilities + 1];
    WCHAR szX25UserData[RAS_MaxUserData + 1];
    DWORD dwChannels;
    DWORD dwReserved1;
    DWORD dwReserved2;
#if (WINVER >= 0x401)
    DWORD dwSubEntries;
    DWORD dwDialMode;
    DWORD dwDialExtraPercent;
    DWORD dwDialExtraSampleSeconds;
    DWORD dwHangUpExtraPercent;
    DWORD dwHangUpExtraSampleSeconds;
    DWORD dwIdleDisconnectSeconds;
#endif
#if (WINVER >= 0x500)
    DWORD dwType;
    DWORD dwEncryptionType;
    DWORD dwCustomAuthKey;
    GUID guidId;
    WCHAR szCustomDialDll[MAX_PATH];
    DWORD dwVpnStrategy;
#endif
#if (WINVER >= 0x501)
	DWORD dwfOptions2;
	DWORD dwfOptions3;
	WCHAR szDnsSuffix[RAS_MaxDnsSuffix];
	DWORD dwTcpWindowSize;
	WCHAR szPrerequisitePbk[MAX_PATH];
	WCHAR szPrerequisiteEntry[RAS_MaxEntryName + 1];
	DWORD dwRedialCount;
	DWORD dwRedialPause;
#endif	
} RASENTRYW, *LPRASENTRYW;

typedef struct tagRASENTRYA {
    DWORD dwSize;
    DWORD dwfOptions;
    DWORD dwCountryID;
    DWORD dwCountryCode;
    CHAR szAreaCode[RAS_MaxAreaCode + 1];
    CHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
    RASIPADDR ipaddr;
    RASIPADDR ipaddrDns;
    RASIPADDR ipaddrDnsAlt;
    RASIPADDR ipaddrWins;
    RASIPADDR ipaddrWinsAlt;
    DWORD dwFrameSize;
    DWORD dwfNetProtocols;
    DWORD dwFramingProtocol;
    CHAR szScript[MAX_PATH];
    CHAR szAutodialDll[MAX_PATH];
    CHAR szAutodialFunc[MAX_PATH];
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
    CHAR szX25PadType[RAS_MaxPadType + 1];
    CHAR szX25Address[RAS_MaxX25Address + 1];
    CHAR szX25Facilities[RAS_MaxFacilities + 1];
    CHAR szX25UserData[RAS_MaxUserData + 1];
    DWORD dwChannels;
    DWORD dwReserved1;
    DWORD dwReserved2;
#if (WINVER >= 0x401)
    DWORD dwSubEntries;
    DWORD dwDialMode;
    DWORD dwDialExtraPercent;
    DWORD dwDialExtraSampleSeconds;
    DWORD dwHangUpExtraPercent;
    DWORD dwHangUpExtraSampleSeconds;
    DWORD dwIdleDisconnectSeconds;
#endif
#if (WINVER >= 0x500)
    DWORD dwType;
    DWORD dwEncryptionType;
    DWORD dwCustomAuthKey;
    GUID guidId;
    CHAR szCustomDialDll[MAX_PATH];
    DWORD dwVpnStrategy;
#endif
#if (WINVER >= 0x501)
	DWORD dwfOptions2;
	DWORD dwfOptions3;
	CHAR szDnsSuffix[RAS_MaxDnsSuffix];
	DWORD dwTcpWindowSize;
	CHAR szPrerequisitePbk[MAX_PATH];
	CHAR szPrerequisiteEntry[RAS_MaxEntryName + 1];
	DWORD dwRedialCount;
	DWORD dwRedialPause;
#endif		
} RASENTRYA, *LPRASENTRYA;


#if (WINVER >= 0x401)
typedef struct tagRASADPARAMS {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
} RASADPARAMS, *LPRASADPARAMS;

typedef struct tagRASSUBENTRYW {
    DWORD dwSize;
    DWORD dwfFlags;
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
    WCHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
} RASSUBENTRYW, *LPRASSUBENTRYW;

typedef struct tagRASSUBENTRYA {
    DWORD dwSize;
    DWORD dwfFlags;
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
    CHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
} RASSUBENTRYA, *LPRASSUBENTRYA;

typedef struct tagRASCREDENTIALSW {
    DWORD dwSize;
    DWORD dwMask;
    WCHAR szUserName[UNLEN + 1];
    WCHAR szPassword[PWLEN + 1];
    WCHAR szDomain[DNLEN + 1];
} RASCREDENTIALSW, *LPRASCREDENTIALSW;

typedef struct tagRASCREDENTIALSA {
    DWORD dwSize;
    DWORD dwMask;
    CHAR szUserName[UNLEN + 1];
    CHAR szPassword[PWLEN + 1];
    CHAR szDomain[DNLEN + 1];
} RASCREDENTIALSA, *LPRASCREDENTIALSA;

typedef struct tagRASAUTODIALENTRYW {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDialingLocation;
    WCHAR szEntry[RAS_MaxEntryName + 1];
} RASAUTODIALENTRYW, *LPRASAUTODIALENTRYW;

typedef struct tagRASAUTODIALENTRYA {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDialingLocation;
    CHAR szEntry[RAS_MaxEntryName + 1];
} RASAUTODIALENTRYA, *LPRASAUTODIALENTRYA;
#endif /* (WINVER >= 0x401) */

#if (WINVER >= 0x500)
typedef struct tagRASPPPCCP {
    DWORD dwSize;
    DWORD dwError;
    DWORD dwCompressionAlgorithm;
    DWORD dwOptions;
    DWORD dwServerCompressionAlgorithm;
    DWORD dwServerOptions;
} RASPPPCCP, *LPRASPPPCCP;

typedef struct tagRASEAPUSERIDENTITYW {
    WCHAR szUserName[UNLEN + 1];
    DWORD dwSizeofEapInfo;
    BYTE pbEapInfo[1];
} RASEAPUSERIDENTITYW, *LPRASEAPUSERIDENTITYW;

typedef struct tagRASEAPUSERIDENTITYA {
    CHAR szUserName[UNLEN + 1];
    DWORD dwSizeofEapInfo;
    BYTE pbEapInfo[1];
} RASEAPUSERIDENTITYA, *LPRASEAPUSERIDENTITYA;

typedef struct tagRAS_STATS {
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
} RAS_STATS, *PRAS_STATS;
#endif /* (WINVER >= 0x500) */


/* UNICODE typedefs for structures*/
#ifdef UNICODE
typedef RASCONNW RASCONN, *LPRASCONN;
typedef RASENTRYW  RASENTRY, *LPRASENTRY;
typedef RASCONNSTATUSW RASCONNSTATUS, *LPRASCONNSTATUS;
typedef RASDIALPARAMSW RASDIALPARAMS, *LPRASDIALPARAMS;
typedef RASAMBW RASAMB, *LPRASAM;
typedef RASPPPNBFW RASPPPNBF, *LPRASPPPNBF;
typedef RASPPPIPXW RASPPPIPX, *LPRASPPPIPX;
typedef RASPPPIPW RASPPPIP, *LPRASPPPIP; 
typedef RASPPPLCPW RASPPPLCP, *LPRASPPPLCP;
typedef RASSLIPW RASSLIP, *LPRASSLIP;
typedef RASDEVINFOW  RASDEVINFO, *LPRASDEVINFO;
typedef RASENTRYNAMEW RASENTRYNAME, *LPRASENTRYNAME;

#if (WINVER >= 0x401)
typedef RASSUBENTRYW RASSUBENTRY, *LPRASSUBENTRY;
typedef RASCREDENTIALSW RASCREDENTIALS, *LPRASCREDENTIALS;
typedef RASAUTODIALENTRYW RASAUTODIALENTRY, *LPRASAUTODIALENTRY;
#endif /* (WINVER >= 0x401) */

#if (WINVER >= 0x500)
typedef RASEAPUSERIDENTITYW RASEAPUSERIDENTITY, *LPRASEAPUSERIDENTITY;
#endif /* (WINVER >= 0x500) */

#else  /* ! defined UNICODE */
typedef RASCONNA RASCONN, *LPRASCONN;
typedef RASENTRYA  RASENTRY, *LPRASENTRY;
typedef RASCONNSTATUSA RASCONNSTATUS, *LPRASCONNSTATUS;
typedef RASDIALPARAMSA RASDIALPARAMS, *LPRASDIALPARAMS;
typedef RASAMBA RASAMB, *LPRASAM;
typedef RASPPPNBFA RASPPPNBF, *LPRASPPPNBF;
typedef RASPPPIPXA RASPPPIPX, *LPRASPPPIPX;
typedef RASPPPIPA RASPPPIP, *LPRASPPPIP;
typedef RASPPPLCPA RASPPPLCP, *LPRASPPPLCP;
typedef RASSLIPA RASSLIP, *LPRASSLIP;
typedef RASDEVINFOA  RASDEVINFO, *LPRASDEVINFO;
typedef RASENTRYNAMEA RASENTRYNAME, *LPRASENTRYNAME;

#if (WINVER >= 0x401)
typedef RASSUBENTRYA RASSUBENTRY, *LPRASSUBENTRY;
typedef RASCREDENTIALSA RASCREDENTIALS, *LPRASCREDENTIALS;
typedef RASAUTODIALENTRYA RASAUTODIALENTRY, *LPRASAUTODIALENTRY;
#endif /*(WINVER >= 0x401)*/
#if (WINVER >= 0x500)
typedef RASEAPUSERIDENTITYA RASEAPUSERIDENTITY, *LPRASEAPUSERIDENTITY;
#endif /* (WINVER >= 0x500) */
#endif /* ! UNICODE */

/* Callback prototypes */
typedef BOOL (WINAPI * ORASADFUNC) (HWND, LPSTR, DWORD, LPDWORD); /* deprecated */
typedef VOID (WINAPI * RASDIALFUNC) (UINT, RASCONNSTATE, DWORD);
typedef VOID (WINAPI * RASDIALFUNC1) (HRASCONN, UINT, RASCONNSTATE, DWORD,
					DWORD);
typedef DWORD (WINAPI * RASDIALFUNC2) (ULONG_PTR, DWORD, HRASCONN, UINT,
					RASCONNSTATE, DWORD, DWORD);

/* External functions */
DWORD APIENTRY RasDialA (LPRASDIALEXTENSIONS, LPCSTR, LPRASDIALPARAMSA,
	    		DWORD, LPVOID, LPHRASCONN);
/**
 * Starts a RAS connection.
 *
 * With a notifier window it returns at once and reports progress to the
 * window. On Windows CE 3.0, with lpvNotifier NULL it blocks until the
 * connection succeeds or fails; on Windows CE 1.0 and 2.0 it is always
 * asynchronous. Doesn't prompt for logon details: the application must
 * collect them. Paused states such as RASCS_CallbackSetByCaller are not
 * supported. Detect later failures with RasGetConnectStatusW.
 *
 * @param lpRasDialExtensions Ignored: must be NULL.
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpRasDialParams RASDIALPARAMS with dwSize set and the entry,
 *        user name and password. szPhoneNumber and szCallbackNumber are
 *        unused: set them to empty strings.
 * @param dwNotifierType 0xFFFFFFFF: lpvNotifier is a window. On Windows
 *        CE 3.0, ignored when lpvNotifier is NULL.
 * @param lpvNotifier Window that receives WM_RASDIALEVENT (or the message
 *        registered as RASDIALEVENT) with the RASCONNSTATE in wParam and
 *        an error in lParam, or on Windows CE 3.0 NULL to dial
 *        synchronously. Notifications end on RASCS_Connected, on an error
 *        or on RasHangUpW.
 * @param lphRasConn Receives the connection handle. Set *lphRasConn to
 *        NULL first. If a handle is returned, always call RasHangUpW on
 *        it, even when RasDialW fails.
 * @return 0 on success (with a window, 0 if dialling started), or a RAS
 *        error or ERROR_NOT_ENOUGH_MEMORY. ERROR_CANNOT_FIND_PHONEBOOK_ENTRY
 *        is never returned.
 */
DWORD APIENTRY RasDialW (LPRASDIALEXTENSIONS lpRasDialExtensions, LPCWSTR lpszPhonebook, LPRASDIALPARAMSW lpRasDialParams,
    	        DWORD dwNotifierType, LPVOID lpvNotifier, LPHRASCONN lphRasConn);
DWORD APIENTRY RasEnumConnectionsA (LPRASCONNA, LPDWORD, LPDWORD);
/**
 * Lists active RAS connections, with their handles and entry names.
 *
 * @param lprasconn Buffer for an array of RASCONN. Set the first
 *        element's dwSize to sizeof(RASCONN).
 * @param lpcb Size of the buffer in bytes. Receives the size needed.
 * @param lpcConnections Receives the number of RASCONN written.
 * @return 0 on success, or an error such as ERROR_BUFFER_TOO_SMALL.
 */
DWORD APIENTRY RasEnumConnectionsW (LPRASCONNW lprasconn, LPDWORD lpcb, LPDWORD lpcConnections);
DWORD APIENTRY RasEnumEntriesA (LPCSTR, LPCSTR, LPRASENTRYNAMEA, LPDWORD,
				LPDWORD);
/**
 * Lists the phone book entry names.
 *
 * @param reserved Must be NULL.
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasentryname Buffer for an array of RASENTRYNAME. Set the first
 *        element's dwSize to sizeof(RASENTRYNAME).
 * @param lpcb Size of the buffer in bytes. Receives the size needed.
 * @param lpcEntries Receives the number of entries written.
 * @return 0 on success, or an error such as ERROR_BUFFER_TOO_SMALL.
 */
DWORD APIENTRY RasEnumEntriesW (LPCWSTR reserved, LPCWSTR lpszPhonebook, LPRASENTRYNAMEW lprasentryname, LPDWORD lpcb,
				LPDWORD lpcEntries);
DWORD APIENTRY RasGetConnectStatusA (HRASCONN, LPRASCONNSTATUSA);
/**
 * Returns the state of a RAS connection.
 *
 * Use it to see whether an asynchronous RasDialW has finished or failed.
 *
 * @param hRasConn Connection from RasDialW or RasEnumConnectionsW.
 * @param lpRasConnStatus RASCONNSTATUS with dwSize set. Receives the
 *        state, any error and the device.
 * @return 0 on success, or a RAS error or ERROR_INVALID_HANDLE.
 */
DWORD APIENTRY RasGetConnectStatusW (HRASCONN hRasConn, LPRASCONNSTATUSW lpRasConnStatus);
DWORD APIENTRY RasGetErrorStringA (UINT, LPSTR, DWORD);
DWORD APIENTRY RasGetErrorStringW (UINT, LPWSTR, DWORD);
DWORD APIENTRY RasHangUpA (HRASCONN);
/**
 * Ends a RAS connection and frees its resources.
 *
 * Works even if RasDialW hasn't finished. The handle is invalid
 * afterwards. If called from the RasDialW notification handler, the hang
 * up happens when the handler returns.
 *
 * @param hRasConn Connection from RasDialW or RasEnumConnectionsW.
 * @return 0 on success, or a RAS error or ERROR_INVALID_HANDLE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD APIENTRY RasHangUpW (HRASCONN hRasConn);
DWORD APIENTRY RasGetProjectionInfoA (HRASCONN, RASPROJECTION, LPVOID,
 				LPDWORD);
/**
 * Retrieves negotiated protocol information for a RAS connection.
 *
 * For `RASP_PppIp`, the output is a RASPPPIP structure. On return, `lpcb`
 * receives the required buffer size. OEM support may vary.
 *
 * @param hrasconn Connection handle from RasDial or RasEnumConnections.
 * @param rasprojection Protocol whose projection information is requested.
 * @param lpprojection Receives the protocol-specific information.
 * @param lpcb Input buffer size and output required size, in bytes.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 only.
 */
DWORD APIENTRY RasGetProjectionInfoW (HRASCONN hrasconn, RASPROJECTION rasprojection, LPVOID lpprojection,
				LPDWORD lpcb);
DWORD APIENTRY RasCreatePhonebookEntryA (HWND, LPCSTR);
DWORD APIENTRY RasCreatePhonebookEntryW (HWND, LPCWSTR);
DWORD APIENTRY RasEditPhonebookEntryA (HWND, LPCSTR, LPCSTR);
DWORD APIENTRY RasEditPhonebookEntryW (HWND, LPCWSTR, LPCWSTR);
DWORD APIENTRY RasSetEntryDialParamsA (LPCSTR, LPRASDIALPARAMSA, BOOL);
/**
 * Saves the dial parameters for a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasdialparams RASDIALPARAMS with dwSize, szEntryName and the
 *        parameters to save. szPhoneNumber and szCallbackNumber aren't
 *        used.
 * @param fRemovePassword TRUE to delete the saved password for
 *        szUserName.
 * @return 0 on success, or ERROR_BUFFER_INVALID,
 *         ERROR_CANNOT_OPEN_PHONEBOOK or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
DWORD APIENTRY RasSetEntryDialParamsW (LPCWSTR lpszPhonebook, LPRASDIALPARAMSW lprasdialparams, BOOL fRemovePassword);
DWORD APIENTRY RasGetEntryDialParamsA (LPCSTR, LPRASDIALPARAMSA, LPBOOL);
/**
 * Returns the dial parameters saved for a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasdialparams RASDIALPARAMS with dwSize and szEntryName set.
 *        Receives the saved parameters. szPhoneNumber and
 *        szCallbackNumber aren't used.
 * @param lpfPassword Receives TRUE if the saved password was returned in
 *        szPassword.
 * @return 0 on success, or ERROR_BUFFER_INVALID,
 *         ERROR_CANNOT_OPEN_PHONEBOOK or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
DWORD APIENTRY RasGetEntryDialParamsW (LPCWSTR lpszPhonebook, LPRASDIALPARAMSW lprasdialparams, LPBOOL lpfPassword);
DWORD APIENTRY RasEnumDevicesA (LPRASDEVINFOA, LPDWORD, LPDWORD);
/**
 * Retrieves the names and types of RAS-capable devices.
 *
 * Set `dwSize` in the first RASDEVINFOW structure before calling. On
 * return, `lpcb` receives the required buffer size in bytes. OEM support
 * may vary.
 *
 * @param lpRasDevinfo Receives an array of RASDEVINFOW structures.
 * @param lpcb Input buffer size and output required size, in bytes.
 * @param lpcDevices Receives the number of structures written.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 only.
 */
DWORD APIENTRY RasEnumDevicesW (LPRASDEVINFOW lpRasDevinfo, LPDWORD lpcb, LPDWORD lpcDevices);
DWORD APIENTRY RasGetCountryInfoA (LPRASCTRYINFOA, LPDWORD);
DWORD APIENTRY RasGetCountryInfoW (LPRASCTRYINFOW, LPDWORD);
DWORD APIENTRY RasGetEntryPropertiesA (LPCSTR, LPCSTR, LPRASENTRYA, LPDWORD,
				 LPBYTE, LPDWORD);
/**
 * Returns the properties of a phone book entry.
 *
 * Pass lpRasEntry as NULL and *lpdwEntryInfoSize as 0 to get the size
 * needed. On Windows CE 3.0 the alternate phone number list is not used.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry Entry name, or L"" for default values.
 * @param lpRasEntry RASENTRY with dwSize set, or NULL. On Windows CE 1.0
 *        and 2.0, follow it with room for any alternate numbers.
 * @param lpdwEntryInfoSize Size of lpRasEntry in bytes. Receives the size
 *        needed. May be NULL if lpRasEntry is NULL.
 * @param lpbDeviceInfo Receives the opaque TAPI device configuration (see
 *        lineGetDevConfig), or NULL. On Windows CE 1.0, ignored: must be
 *        NULL (use RasGetEntryDevConfig).
 * @param lpdwDeviceInfoSize Size of lpbDeviceInfo in bytes. Receives the
 *        size needed. May be NULL if lpbDeviceInfo is NULL. On Windows CE
 *        1.0, must be NULL.
 * @return 0 on success, or ERROR_INVALID_PARAMETER, ERROR_INVALID_SIZE,
 *        ERROR_BUFFER_INVALID, ERROR_BUFFER_TOO_SMALL,
 *        ERROR_CANNOT_OPEN_PHONEBOOK or ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
DWORD APIENTRY RasGetEntryPropertiesW (LPCWSTR lpszPhonebook, LPCWSTR lpszEntry, LPRASENTRYW lpRasEntry,
				 LPDWORD lpdwEntryInfoSize, LPBYTE lpbDeviceInfo, LPDWORD lpdwDeviceInfoSize);
DWORD APIENTRY RasSetEntryPropertiesA (LPCSTR, LPCSTR, LPRASENTRYA, DWORD,
				 LPBYTE, DWORD);
/**
 * Changes a phone book entry, or creates it if it doesn't exist.
 *
 * Check new names with RasValidateEntryNameW first. On Windows CE 3.0 the
 * alternate phone number list is not used.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry Entry name.
 * @param lpRasEntry RASENTRY with the new settings. On Windows CE 1.0 and
 *        2.0 it may be followed by double-null-terminated alternate
 *        numbers at dwAlternateOffset.
 * @param dwEntryInfoSize Size of lpRasEntry in bytes.
 * @param lpbDeviceInfo Opaque TAPI device configuration (see
 *        lineGetDevConfig), or NULL. On Windows CE 1.0, ignored: must be
 *        NULL (use RasSetEntryDevConfig).
 * @param dwDeviceInfoSize Size of lpbDeviceInfo in bytes. On Windows CE
 *        1.0, must be 0.
 * @return 0 on success, or ERROR_BUFFER_INVALID or
 *        ERROR_CANNOT_OPEN_PHONEBOOK.
 */
DWORD APIENTRY RasSetEntryPropertiesW (LPCWSTR lpszPhonebook, LPCWSTR lpszEntry, LPRASENTRYW lpRasEntry, DWORD dwEntryInfoSize,
				 LPBYTE lpbDeviceInfo, DWORD dwDeviceInfoSize);
DWORD APIENTRY RasRenameEntryA (LPCSTR, LPCSTR, LPCSTR);
/**
 * Renames a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszOldEntry Existing entry name.
 * @param lpszNewEntry New name. Check it first with RasValidateEntryNameW.
 * @return 0 on success, or ERROR_INVALID_NAME, ERROR_ALREADY_EXISTS or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
DWORD APIENTRY RasRenameEntryW (LPCWSTR lpszPhonebook, LPCWSTR lpszOldEntry, LPCWSTR lpszNewEntry);
DWORD APIENTRY RasDeleteEntryA (LPCSTR, LPCSTR);
/**
 * Deletes a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL. Windows CE keeps entries in
 *        the registry.
 * @param lpszEntry Name of the entry to delete.
 * @return 0 on success, or ERROR_CANNOT_OPEN_PHONEBOOK, ERROR_INVALID_NAME
 *         or a RegDeleteKey error.
 */
DWORD APIENTRY RasDeleteEntryW (LPCWSTR lpszPhonebook, LPCWSTR lpszEntry);
DWORD APIENTRY RasValidateEntryNameA (LPCSTR, LPCSTR);
/**
 * Checks whether a name is valid for a new phone book entry.
 *
 * The name must contain at least one alphanumeric character, be a valid
 * registry key name and not start with a backslash.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry The name to check.
 * @return 0 if valid, ERROR_INVALID_NAME, or ERROR_ALREADY_EXISTS.
 */
DWORD APIENTRY RasValidateEntryNameW (LPCWSTR lpszPhonebook, LPCWSTR lpszEntry);

#if (WINVER >= 0x401)
typedef BOOL (WINAPI * RASADFUNCA) (LPSTR, LPSTR, LPRASADPARAMS, LPDWORD);
typedef BOOL (WINAPI * RASADFUNCW) (LPWSTR, LPWSTR, LPRASADPARAMS, LPDWORD);

DWORD APIENTRY RasGetSubEntryHandleA (HRASCONN, DWORD, LPHRASCONN);
DWORD APIENTRY RasGetSubEntryHandleW (HRASCONN, DWORD, LPHRASCONN);
DWORD APIENTRY RasGetCredentialsA (LPCSTR, LPCSTR, LPRASCREDENTIALSA);
DWORD APIENTRY RasGetCredentialsW (LPCWSTR, LPCWSTR, LPRASCREDENTIALSW);
DWORD APIENTRY RasSetCredentialsA (LPCSTR, LPCSTR, LPRASCREDENTIALSA, BOOL);
DWORD APIENTRY RasSetCredentialsW (LPCWSTR, LPCWSTR, LPRASCREDENTIALSW, BOOL);
DWORD APIENTRY RasConnectionNotificationA (HRASCONN, HANDLE, DWORD);
DWORD APIENTRY RasConnectionNotificationW (HRASCONN, HANDLE, DWORD);
DWORD APIENTRY RasGetSubEntryPropertiesA (LPCSTR, LPCSTR, DWORD,
					LPRASSUBENTRYA, LPDWORD, LPBYTE, LPDWORD);
DWORD APIENTRY RasGetSubEntryPropertiesW (LPCWSTR, LPCWSTR, DWORD,
					LPRASSUBENTRYW, LPDWORD, LPBYTE, LPDWORD);
DWORD APIENTRY RasSetSubEntryPropertiesA (LPCSTR, LPCSTR, DWORD,
					LPRASSUBENTRYA, DWORD, LPBYTE, DWORD);
DWORD APIENTRY RasSetSubEntryPropertiesW (LPCWSTR, LPCWSTR, DWORD,
					LPRASSUBENTRYW, DWORD, LPBYTE, DWORD);
DWORD APIENTRY RasGetAutodialAddressA (LPCSTR, LPDWORD, LPRASAUTODIALENTRYA,
			        LPDWORD, LPDWORD);
DWORD APIENTRY RasGetAutodialAddressW (LPCWSTR, LPDWORD,
					LPRASAUTODIALENTRYW, LPDWORD, LPDWORD);
DWORD APIENTRY RasSetAutodialAddressA (LPCSTR, DWORD, LPRASAUTODIALENTRYA,
					DWORD, DWORD);
DWORD APIENTRY RasSetAutodialAddressW (LPCWSTR, DWORD, LPRASAUTODIALENTRYW,
					DWORD, DWORD);
DWORD APIENTRY RasEnumAutodialAddressesA (LPSTR *, LPDWORD, LPDWORD);
DWORD APIENTRY RasEnumAutodialAddressesW (LPWSTR *, LPDWORD, LPDWORD);
DWORD APIENTRY RasGetAutodialEnableA (DWORD, LPBOOL);
DWORD APIENTRY RasGetAutodialEnableW (DWORD, LPBOOL);
DWORD APIENTRY RasSetAutodialEnableA (DWORD, BOOL);
DWORD APIENTRY RasSetAutodialEnableW (DWORD, BOOL);
DWORD APIENTRY RasGetAutodialParamA (DWORD, LPVOID, LPDWORD);
DWORD APIENTRY RasGetAutodialParamW (DWORD, LPVOID, LPDWORD);
DWORD APIENTRY RasSetAutodialParamA (DWORD, LPVOID, DWORD);
DWORD APIENTRY RasSetAutodialParamW (DWORD, LPVOID, DWORD);
#endif

#if (WINVER >= 0x500)
typedef DWORD (WINAPI * RasCustomHangUpFn) (HRASCONN);
typedef DWORD (WINAPI * RasCustomDeleteEntryNotifyFn) (LPCTSTR,	LPCTSTR, DWORD);
typedef DWORD (WINAPI * RasCustomDialFn) (HINSTANCE, LPRASDIALEXTENSIONS,
				LPCTSTR, LPRASDIALPARAMS, DWORD, LPVOID, LPHRASCONN, DWORD);

DWORD APIENTRY RasInvokeEapUI (HRASCONN, DWORD, LPRASDIALEXTENSIONS, HWND);
/**
 * Retrieves statistics for a RAS connection subentry.
 *
 * The RAS_STATS structure includes byte and frame counts, error counts,
 * compression ratios, bits per second and connection duration.
 *
 * @param hRasConn RAS connection handle.
 * @param dwSubEntry Subentry whose statistics to retrieve.
 * @param lpStatistics Receives the RAS_STATS structure.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 only.
 */
DWORD APIENTRY RasGetLinkStatistics (HRASCONN hRasConn, DWORD dwSubEntry, RAS_STATS*lpStatistics);
DWORD APIENTRY RasGetConnectionStatistics (HRASCONN, RAS_STATS*);
DWORD APIENTRY RasClearLinkStatistics (HRASCONN, DWORD);
DWORD APIENTRY RasClearConnectionStatistics (HRASCONN);
DWORD APIENTRY RasGetEapUserDataA (HANDLE, LPCSTR, LPCSTR, BYTE*, DWORD*);
DWORD APIENTRY RasGetEapUserDataW (HANDLE, LPCWSTR, LPCWSTR, BYTE*, DWORD*);
DWORD APIENTRY RasSetEapUserDataA (HANDLE, LPCSTR, LPCSTR, BYTE*, DWORD);
DWORD APIENTRY RasSetEapUserDataW (HANDLE, LPCWSTR, LPCWSTR, BYTE*, DWORD);
DWORD APIENTRY RasGetCustomAuthDataA (LPCSTR,	LPCSTR,	BYTE*,	DWORD*);
DWORD APIENTRY RasGetCustomAuthDataW (LPCWSTR, LPCWSTR, BYTE*, DWORD*);
DWORD APIENTRY RasSetCustomAuthDataA (LPCSTR,	LPCSTR,	BYTE*,	DWORD);
DWORD APIENTRY RasSetCustomAuthDataW (LPCWSTR, LPCWSTR, BYTE*, DWORD);
DWORD APIENTRY RasGetEapUserIdentityW (LPCWSTR, LPCWSTR, DWORD, HWND, LPRASEAPUSERIDENTITYW*);
DWORD APIENTRY RasGetEapUserIdentityA (LPCSTR, LPCSTR, DWORD, HWND, LPRASEAPUSERIDENTITYA*);
VOID APIENTRY RasFreeEapUserIdentityW (LPRASEAPUSERIDENTITYW);
VOID APIENTRY RasFreeEapUserIdentityA (LPRASEAPUSERIDENTITYA);
#endif  /* (WINVER >= 0x500) */


/* UNICODE defines for functions */
#ifdef UNICODE
/**
 * Starts a RAS connection.
 *
 * With a notifier window it returns at once and reports progress to the
 * window. On Windows CE 3.0, with lpvNotifier NULL it blocks until the
 * connection succeeds or fails; on Windows CE 1.0 and 2.0 it is always
 * asynchronous. Doesn't prompt for logon details: the application must
 * collect them. Paused states such as RASCS_CallbackSetByCaller are not
 * supported. Detect later failures with RasGetConnectStatusW.
 *
 * @param lpRasDialExtensions Ignored: must be NULL.
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpRasDialParams RASDIALPARAMS with dwSize set and the entry,
 *        user name and password. szPhoneNumber and szCallbackNumber are
 *        unused: set them to empty strings.
 * @param dwNotifierType 0xFFFFFFFF: lpvNotifier is a window. On Windows
 *        CE 3.0, ignored when lpvNotifier is NULL.
 * @param lpvNotifier Window that receives WM_RASDIALEVENT (or the message
 *        registered as RASDIALEVENT) with the RASCONNSTATE in wParam and
 *        an error in lParam, or on Windows CE 3.0 NULL to dial
 *        synchronously. Notifications end on RASCS_Connected, on an error
 *        or on RasHangUpW.
 * @param lphRasConn Receives the connection handle. Set *lphRasConn to
 *        NULL first. If a handle is returned, always call RasHangUpW on
 *        it, even when RasDialW fails.
 * @return 0 on success (with a window, 0 if dialling started), or a RAS
 *        error or ERROR_NOT_ENOUGH_MEMORY. ERROR_CANNOT_FIND_PHONEBOOK_ENTRY
 *        is never returned.
 */
#define RasDial RasDialW
/**
 * Lists active RAS connections, with their handles and entry names.
 *
 * @param lprasconn Buffer for an array of RASCONN. Set the first
 *        element's dwSize to sizeof(RASCONN).
 * @param lpcb Size of the buffer in bytes. Receives the size needed.
 * @param lpcConnections Receives the number of RASCONN written.
 * @return 0 on success, or an error such as ERROR_BUFFER_TOO_SMALL.
 */
#define RasEnumConnections RasEnumConnectionsW
/**
 * Lists the phone book entry names.
 *
 * @param reserved Must be NULL.
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasentryname Buffer for an array of RASENTRYNAME. Set the first
 *        element's dwSize to sizeof(RASENTRYNAME).
 * @param lpcb Size of the buffer in bytes. Receives the size needed.
 * @param lpcEntries Receives the number of entries written.
 * @return 0 on success, or an error such as ERROR_BUFFER_TOO_SMALL.
 */
#define RasEnumEntries RasEnumEntriesW
/**
 * Returns the state of a RAS connection.
 *
 * Use it to see whether an asynchronous RasDialW has finished or failed.
 *
 * @param hRasConn Connection from RasDialW or RasEnumConnectionsW.
 * @param lpRasConnStatus RASCONNSTATUS with dwSize set. Receives the
 *        state, any error and the device.
 * @return 0 on success, or a RAS error or ERROR_INVALID_HANDLE.
 */
#define RasGetConnectStatus RasGetConnectStatusW
#define RasGetErrorString RasGetErrorStringW
/**
 * Ends a RAS connection and frees its resources.
 *
 * Works even if RasDialW hasn't finished. The handle is invalid
 * afterwards. If called from the RasDialW notification handler, the hang
 * up happens when the handler returns.
 *
 * @param hRasConn Connection from RasDialW or RasEnumConnectionsW.
 * @return 0 on success, or a RAS error or ERROR_INVALID_HANDLE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define RasHangUp RasHangUpW
/**
 * Retrieves negotiated protocol information for a RAS connection.
 *
 * For `RASP_PppIp`, the output is a RASPPPIP structure. On return, `lpcb`
 * receives the required buffer size. OEM support may vary.
 *
 * @param hrasconn Connection handle from RasDial or RasEnumConnections.
 * @param rasprojection Protocol whose projection information is requested.
 * @param lpprojection Receives the protocol-specific information.
 * @param lpcb Input buffer size and output required size, in bytes.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 only.
 */
#define RasGetProjectionInfo RasGetProjectionInfoW
#define RasCreatePhonebookEntry RasCreatePhonebookEntryW
#define RasEditPhonebookEntry RasEditPhonebookEntryW
/**
 * Saves the dial parameters for a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasdialparams RASDIALPARAMS with dwSize, szEntryName and the
 *        parameters to save. szPhoneNumber and szCallbackNumber aren't
 *        used.
 * @param fRemovePassword TRUE to delete the saved password for
 *        szUserName.
 * @return 0 on success, or ERROR_BUFFER_INVALID,
 *         ERROR_CANNOT_OPEN_PHONEBOOK or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
#define RasSetEntryDialParams RasSetEntryDialParamsW
/**
 * Returns the dial parameters saved for a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lprasdialparams RASDIALPARAMS with dwSize and szEntryName set.
 *        Receives the saved parameters. szPhoneNumber and
 *        szCallbackNumber aren't used.
 * @param lpfPassword Receives TRUE if the saved password was returned in
 *        szPassword.
 * @return 0 on success, or ERROR_BUFFER_INVALID,
 *         ERROR_CANNOT_OPEN_PHONEBOOK or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
#define RasGetEntryDialParams RasGetEntryDialParamsW
/**
 * Retrieves the names and types of RAS-capable devices.
 *
 * Set `dwSize` in the first RASDEVINFOW structure before calling. On
 * return, `lpcb` receives the required buffer size in bytes. OEM support
 * may vary.
 *
 * @param lpRasDevinfo Receives an array of RASDEVINFOW structures.
 * @param lpcb Input buffer size and output required size, in bytes.
 * @param lpcDevices Receives the number of structures written.
 * @return Zero on success, or a RAS error code.
 *
 * @note Windows CE 3.0 only.
 */
#define RasEnumDevices RasEnumDevicesW
#define RasGetCountryInfo RasGetCountryInfoW
/**
 * Returns the properties of a phone book entry.
 *
 * Pass lpRasEntry as NULL and *lpdwEntryInfoSize as 0 to get the size
 * needed. On Windows CE 3.0 the alternate phone number list is not used.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry Entry name, or L"" for default values.
 * @param lpRasEntry RASENTRY with dwSize set, or NULL. On Windows CE 1.0
 *        and 2.0, follow it with room for any alternate numbers.
 * @param lpdwEntryInfoSize Size of lpRasEntry in bytes. Receives the size
 *        needed. May be NULL if lpRasEntry is NULL.
 * @param lpbDeviceInfo Receives the opaque TAPI device configuration (see
 *        lineGetDevConfig), or NULL. On Windows CE 1.0, ignored: must be
 *        NULL (use RasGetEntryDevConfig).
 * @param lpdwDeviceInfoSize Size of lpbDeviceInfo in bytes. Receives the
 *        size needed. May be NULL if lpbDeviceInfo is NULL. On Windows CE
 *        1.0, must be NULL.
 * @return 0 on success, or ERROR_INVALID_PARAMETER, ERROR_INVALID_SIZE,
 *        ERROR_BUFFER_INVALID, ERROR_BUFFER_TOO_SMALL,
 *        ERROR_CANNOT_OPEN_PHONEBOOK or ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
#define RasGetEntryProperties RasGetEntryPropertiesW
/**
 * Changes a phone book entry, or creates it if it doesn't exist.
 *
 * Check new names with RasValidateEntryNameW first. On Windows CE 3.0 the
 * alternate phone number list is not used.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry Entry name.
 * @param lpRasEntry RASENTRY with the new settings. On Windows CE 1.0 and
 *        2.0 it may be followed by double-null-terminated alternate
 *        numbers at dwAlternateOffset.
 * @param dwEntryInfoSize Size of lpRasEntry in bytes.
 * @param lpbDeviceInfo Opaque TAPI device configuration (see
 *        lineGetDevConfig), or NULL. On Windows CE 1.0, ignored: must be
 *        NULL (use RasSetEntryDevConfig).
 * @param dwDeviceInfoSize Size of lpbDeviceInfo in bytes. On Windows CE
 *        1.0, must be 0.
 * @return 0 on success, or ERROR_BUFFER_INVALID or
 *        ERROR_CANNOT_OPEN_PHONEBOOK.
 */
#define RasSetEntryProperties RasSetEntryPropertiesW
/**
 * Renames a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszOldEntry Existing entry name.
 * @param lpszNewEntry New name. Check it first with RasValidateEntryNameW.
 * @return 0 on success, or ERROR_INVALID_NAME, ERROR_ALREADY_EXISTS or
 *         ERROR_CANNOT_FIND_PHONEBOOK_ENTRY.
 */
#define RasRenameEntry RasRenameEntryW
/**
 * Deletes a phone book entry.
 *
 * @param lpszPhonebook Ignored: must be NULL. Windows CE keeps entries in
 *        the registry.
 * @param lpszEntry Name of the entry to delete.
 * @return 0 on success, or ERROR_CANNOT_OPEN_PHONEBOOK, ERROR_INVALID_NAME
 *         or a RegDeleteKey error.
 */
#define RasDeleteEntry RasDeleteEntryW
/**
 * Checks whether a name is valid for a new phone book entry.
 *
 * The name must contain at least one alphanumeric character, be a valid
 * registry key name and not start with a backslash.
 *
 * @param lpszPhonebook Ignored: must be NULL.
 * @param lpszEntry The name to check.
 * @return 0 if valid, ERROR_INVALID_NAME, or ERROR_ALREADY_EXISTS.
 */
#define RasValidateEntryName RasValidateEntryNameW
#if (WINVER >= 0x401)
#define RASADFUNC RASADFUNCW
#define RasGetSubEntryHandle RasGetSubEntryHandleW
#define RasConnectionNotification RasConnectionNotificationW
#define RasGetSubEntryProperties RasGetSubEntryPropertiesW
#define RasSetSubEntryProperties RasSetSubEntryPropertiesW
#define RasGetCredentials RasGetCredentialsW
#define RasSetCredentials RasSetCredentialsW
#define RasGetAutodialAddress RasGetAutodialAddressW
#define RasSetAutodialAddress RasSetAutodialAddressW
#define RasEnumAutodialAddresses RasEnumAutodialAddressesW
#define RasGetAutodialEnable RasGetAutodialEnableW
#define RasSetAutodialEnable RasSetAutodialEnableW
#define RasGetAutodialParam RasGetAutodialParamW
#define RasSetAutodialParam RasSetAutodialParamW
#endif /* (WINVER >= 0x401) */
#if (WINVER >= 0x500)
#define RasGetEapUserData RasGetEapUserDataW
#define RasSetEapUserData RasSetEapUserDataW
#define RasGetCustomAuthData RasGetCustomAuthDataW
#define RasSetCustomAuthData RasSetCustomAuthDataW
#define RasGetEapUserIdentity RasGetEapUserIdentityW
#define RasFreeEapUserIdentity RasFreeEapUserIdentityW
#endif /* (WINVER >= 0x500) */

#else  /* ! defined UNICODE */
#define RasDial RasDialA
#define RasEnumConnections RasEnumConnectionsA
#define RasEnumEntries RasEnumEntriesA
#define RasGetConnectStatus RasGetConnectStatusA
#define RasGetErrorString RasGetErrorStringA
#define RasHangUp RasHangUpA
#define RasGetProjectionInfo RasGetProjectionInfoA
#define RasCreatePhonebookEntry RasCreatePhonebookEntryA
#define RasEditPhonebookEntry RasEditPhonebookEntryA
#define RasSetEntryDialParams RasSetEntryDialParamsA
#define RasGetEntryDialParams RasGetEntryDialParamsA
#define RasEnumDevices RasEnumDevicesA
#define RasGetCountryInfo RasGetCountryInfoA
#define RasGetEntryProperties RasGetEntryPropertiesA
#define RasSetEntryProperties RasSetEntryPropertiesA
#define RasRenameEntry RasRenameEntryA
#define RasDeleteEntry RasDeleteEntryA
#define RasValidateEntryName RasValidateEntryNameA

#if (WINVER >= 0x401)
#define RASADFUNC RASADFUNCA
#define RasGetSubEntryHandle RasGetSubEntryHandleA
#define RasConnectionNotification RasConnectionNotificationA
#define RasGetSubEntryProperties RasGetSubEntryPropertiesA
#define RasSetSubEntryProperties RasSetSubEntryPropertiesA
#define RasGetCredentials RasGetCredentialsA
#define RasSetCredentials RasSetCredentialsA
#define RasGetAutodialAddress RasGetAutodialAddressA
#define RasSetAutodialAddress RasSetAutodialAddressA
#define RasEnumAutodialAddressesRasEnumAutodialAddressesA
#define RasGetAutodialEnable RasGetAutodialEnableA
#define RasSetAutodialEnable RasSetAutodialEnableA
#define RasGetAutodialParam RasGetAutodialParamA
#define RasSetAutodialParam RasSetAutodialParamA
#endif /*(WINVER >= 0x401)*/

#if (WINVER >= 0x500)
#define RasGetEapUserData RasGetEapUserDataA
#define RasSetEapUserData RasSetEapUserDataA
#define RasGetCustomAuthData RasGetCustomAuthDataA
#define RasSetCustomAuthData RasSetCustomAuthDataA
#define RasGetEapUserIdentity RasGetEapUserIdentityA
#define RasFreeEapUserIdentity RasFreeEapUserIdentityA
#endif /* (WINVER >= 0x500) */
#endif /* ! UNICODE */

#ifdef __cplusplus
}
#endif
#include <poppack.h>
#endif /* _RAS_H */ 

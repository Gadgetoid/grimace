#if GRIMACE_CE == 1
#ifdef _WINDEF_H
typedef short * LPSHORT;
#endif
#ifdef _WINNT_H
typedef const CHAR * PCCH;
#endif
#ifdef _WINNT_H
typedef DWORD KSPIN_LOCK;
#endif
#ifdef _WINDEF_H
typedef HANDLE * SPHANDLE;
#endif
#ifdef _WINDEF_H
typedef DWORD * LPCOLORREF;
#endif
#ifdef _WINDEF_H
typedef RECT * NPRECT;
#endif
#ifdef _WINDEF_H
typedef POINT * NPPOINT;
#endif
#ifdef _WINDEF_H
typedef INT8 * PINT8;
#endif
#ifdef _WINDEF_H
typedef UINT8 * PUINT8;
#endif
#ifdef _WINDEF_H
typedef INT16 * PINT16;
#endif
#ifdef _WINDEF_H
typedef UINT16 * PUINT16;
#endif
#ifdef _WINDEF_H
typedef void ** PPVOID;
#endif
#ifdef _WINDEF_H
typedef unsigned char uchar;
#endif
#ifdef _WINDEF_H
typedef unsigned short ushort;
#endif
#ifdef _WINDEF_H
typedef unsigned int uint;
#endif
#ifdef _WINDEF_H
typedef unsigned long ulong;
#endif
#ifdef _WINDEF_H
typedef void (*PFNVOID)();
#endif
#ifdef _WINDEF_H
typedef CHAR * LPCHAR;
#endif
#ifdef _WINDEF_H
typedef HANDLE HPROCESS;
#endif
#ifdef _WINDEF_H
typedef HANDLE HTHREAD;
#endif
#ifdef _WINDEF_H
typedef LPCRECT PCRECT;
#endif
#ifdef _WINDEF_H
typedef DWORD WIN32_ERROR_CODE;
#endif
#ifdef _WINBASE_H
typedef LPTHREAD_START_ROUTINE PTHREAD_START_ROUTINE;
#endif
#ifdef _WINBASE_H
typedef BY_HANDLE_FILE_INFORMATION * PBY_HANDLE_FILE_INFORMATION;
#endif
#ifdef _WINGDI_H
typedef RGNDATAHEADER * PRGNDATAHEADER;
#endif
#ifdef _WINGDI_H
typedef RGNDATA * NPRGNDATA;
#endif
#ifdef _WINGDI_H
typedef LOGBRUSH * NPLOGBRUSH;
#endif
#ifdef _WINGDI_H
typedef LOGPEN * NPLOGPEN;
#endif
#ifdef _WINGDI_H
typedef LOGFONTA * NPLOGFONTA;
#endif
#ifdef _WINGDI_H
typedef LOGFONTW * NPLOGFONTW;
#endif
#ifdef _WINGDI_H
typedef TEXTMETRICA * NPTEXTMETRICA;
#endif
#ifdef _WINGDI_H
typedef TEXTMETRICW * NPTEXTMETRICW;
#endif
#ifdef _WINGDI_H
typedef NPTEXTMETRICW NPTEXTMETRIC;
#endif
#ifdef _WINGDI_H
typedef NEWTEXTMETRICA * NPNEWTEXTMETRICA;
#endif
#ifdef _WINGDI_H
typedef NEWTEXTMETRICW * NPNEWTEXTMETRICW;
#endif
#ifdef _WINGDI_H
typedef NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
#endif
#ifdef _WINGDI_H
typedef HANDLETABLE * PHANDLETABLE;
#endif
#ifdef _WINGDI_H
typedef DIBSECTION * LPDIBSECTION;
#endif
#ifdef _WINGDI_H
typedef DIBSECTION * PDIBSECTION;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEFORMAT * NPWAVEFORMAT;
#endif
#ifdef _MMSYSTEM_H
typedef const WAVEFORMAT * LPCWAVEFORMAT;
#endif
#ifdef _MMSYSTEM_H
typedef PCMWAVEFORMAT * NPPCMWAVEFORMAT;
#endif
#ifdef _WINUSER_H
typedef MSG * NPMSG;
#endif
#ifdef _WINUSER_H
typedef CREATESTRUCTA * PCREATESTRUCTA;
#endif
#ifdef _WINUSER_H
typedef CREATESTRUCTW * PCREATESTRUCTW;
#endif
#ifdef _WINUSER_H
typedef PAINTSTRUCT * PPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const PAINTSTRUCT * LPCPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const PAINTSTRUCT * PCPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef COMPAREITEMSTRUCT * PCOMPAREITEMSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const DLGTEMPLATE * LPCDLGTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef const DLGTEMPLATE * LPCDLGTEMPLATEW;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * PDLGITEMTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * PDLGITEMTEMPLATEW;
#endif
#ifdef _WINUSER_H
typedef PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * LPDLGITEMTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * LPDLGITEMTEMPLATEW;
#endif
#ifdef _COMMCTRL_H
typedef struct _HD_HITTESTINFO HDHITTESTINFO;
#endif
#ifdef _COMMCTRL_H
typedef TBSAVEPARAMSA * LPTBSAVEPARAMSA;
#endif
#ifdef _COMMCTRL_H
typedef TBSAVEPARAMSW * LPTBSAVEPARAMW;
#endif
#ifdef _RAS_H
typedef RASAMB * LPRASAMB;
#endif
#endif

#if GRIMACE_CE == 2
#ifdef _WINDEF_H
typedef short * LPSHORT;
#endif
#ifdef _WINNT_H
typedef const CHAR * PCCH;
#endif
#ifdef _WINNT_H
typedef DWORD KSPIN_LOCK;
#endif
#ifdef _WINDEF_H
typedef HANDLE * SPHANDLE;
#endif
#ifdef _WINDEF_H
typedef DWORD * LPCOLORREF;
#endif
#ifdef _WINDEF_H
typedef RECT * NPRECT;
#endif
#ifdef _WINDEF_H
typedef POINT * NPPOINT;
#endif
#ifdef _WINDEF_H
typedef INT8 * PINT8;
#endif
#ifdef _WINDEF_H
typedef UINT8 * PUINT8;
#endif
#ifdef _WINDEF_H
typedef INT16 * PINT16;
#endif
#ifdef _WINDEF_H
typedef UINT16 * PUINT16;
#endif
#ifdef _WINDEF_H
typedef void ** PPVOID;
#endif
#ifdef _WINDEF_H
typedef unsigned char uchar;
#endif
#ifdef _WINDEF_H
typedef unsigned short ushort;
#endif
#ifdef _WINDEF_H
typedef unsigned int uint;
#endif
#ifdef _WINDEF_H
typedef unsigned long ulong;
#endif
#ifdef _WINDEF_H
typedef void (*PFNVOID)();
#endif
#ifdef _WINDEF_H
typedef CHAR * LPCHAR;
#endif
#ifdef _WINDEF_H
typedef HANDLE HPROCESS;
#endif
#ifdef _WINDEF_H
typedef HANDLE HTHREAD;
#endif
#ifdef _WINDEF_H
typedef LPCRECT PCRECT;
#endif
#ifdef _WINDEF_H
typedef DWORD WIN32_ERROR_CODE;
#endif
#ifdef _WINBASE_H
typedef LPTHREAD_START_ROUTINE PTHREAD_START_ROUTINE;
#endif
#ifdef _WINBASE_H
typedef BY_HANDLE_FILE_INFORMATION * PBY_HANDLE_FILE_INFORMATION;
#endif
#ifdef _WINGDI_H
typedef LOGFONTA * NPLOGFONTA;
#endif
#ifdef _WINGDI_H
typedef LOGFONTW * NPLOGFONTW;
#endif
#ifdef _WINGDI_H
typedef HANDLETABLE * PHANDLETABLE;
#endif
#ifdef _WINGDI_H
typedef COLORADJUSTMENT * PCOLORADJUSTMENT;
#endif
#ifdef _WINGDI_H
typedef DEVMODEA * NPDEVMODEA;
#endif
#ifdef _WINGDI_H
typedef NPDEVMODEW NPDEVMODE;
#endif
#ifdef _WINGDI_H
typedef LOGBRUSH * NPLOGBRUSH;
#endif
#ifdef _WINGDI_H
typedef LOGPEN * NPLOGPEN;
#endif
#ifdef _WINGDI_H
typedef RGNDATAHEADER * PRGNDATAHEADER;
#endif
#ifdef _WINGDI_H
typedef RGNDATA * NPRGNDATA;
#endif
#ifdef _WINGDI_H
typedef TEXTMETRICA * NPTEXTMETRICA;
#endif
#ifdef _WINGDI_H
typedef TEXTMETRICW * NPTEXTMETRICW;
#endif
#ifdef _WINGDI_H
typedef NPTEXTMETRICW NPTEXTMETRIC;
#endif
#ifdef _WINGDI_H
typedef NEWTEXTMETRICA * NPNEWTEXTMETRICA;
#endif
#ifdef _WINGDI_H
typedef NEWTEXTMETRICW * NPNEWTEXTMETRICW;
#endif
#ifdef _WINGDI_H
typedef NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
#endif
#ifdef _WINGDI_H
typedef DIBSECTION * LPDIBSECTION;
#endif
#ifdef _WINGDI_H
typedef DIBSECTION * PDIBSECTION;
#endif
#ifdef _MMSYSTEM_H
typedef MMTIME * NPMMTIME;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEFORMAT * NPWAVEFORMAT;
#endif
#ifdef _MMSYSTEM_H
typedef const WAVEFORMAT * LPCWAVEFORMAT;
#endif
#ifdef _MMSYSTEM_H
typedef PCMWAVEFORMAT * NPPCMWAVEFORMAT;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEHDR * NPWAVEHDR;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEOUTCAPS * NPWAVEOUTCAPS;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEINCAPS * NPWAVEINCAPS;
#endif
#ifdef _MMSYSTEM_H
typedef WAVEFORMATEX * NPWAVEFORMATEX;
#endif
#ifdef _WINUSER_H
typedef MSG * NPMSG;
#endif
#ifdef _WINUSER_H
typedef CREATESTRUCTA * PCREATESTRUCTA;
#endif
#ifdef _WINUSER_H
typedef CREATESTRUCTW * PCREATESTRUCTW;
#endif
#ifdef _WINUSER_H
typedef PAINTSTRUCT * PPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const PAINTSTRUCT * LPCPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const PAINTSTRUCT * PCPAINTSTRUCT;
#endif
#ifdef _WINUSER_H
typedef MOUSEINPUT * LPMOUSEINPUT;
#endif
#ifdef _WINUSER_H
typedef KEYBDINPUT * LPKEYBDINPUT;
#endif
#ifdef _WINUSER_H
typedef HARDWAREINPUT * LPHARDWAREINPUT;
#endif
#ifdef _WINUSER_H
typedef COMPAREITEMSTRUCT * PCOMPAREITEMSTRUCT;
#endif
#ifdef _WINUSER_H
typedef const DLGTEMPLATE * LPCDLGTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef const DLGTEMPLATE * LPCDLGTEMPLATEW;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * PDLGITEMTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * PDLGITEMTEMPLATEW;
#endif
#ifdef _WINUSER_H
typedef PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * LPDLGITEMTEMPLATEA;
#endif
#ifdef _WINUSER_H
typedef DLGITEMTEMPLATE * LPDLGITEMTEMPLATEW;
#endif
#ifdef _WINNT_H
typedef const TCHAR * PCTSTR;
#endif
#ifdef EXCPT_H
typedef EXCEPTION_POINTERS * Exception_info_ptr;
#endif
#ifdef _COMMCTRL_H
typedef NMMOUSE NMCLICK;
#endif
#ifdef _COMMCTRL_H
typedef LPNMMOUSE LPNMCLICK;
#endif
#ifdef _COMMCTRL_H
typedef struct _HD_HITTESTINFO HDHITTESTINFO;
#endif
#ifdef _COMMCTRL_H
typedef const COMMANDBANDSRESTOREINFO * LPCCOMMANDBANDSRESTOREINFO;
#endif
#ifdef _COMMCTRL_H
typedef NMSELCHANGE NMSELECT;
#endif
#ifdef _COMMCTRL_H
typedef NMSELCHANGE * LPNMSELECT;
#endif
#ifdef _MSACM_H
typedef ACMDRIVERDETAILS * PACMDRIVERDETAILS;
#endif
#ifdef _MSACM_H
typedef ACMFORMATTAGDETAILS * PACMFORMATTAGDETAILS;
#endif
#ifdef _MSACM_H
typedef ACMFORMATDETAILS * PACMFORMATDETAILS;
#endif
#ifdef _MSACM_H
typedef ACMSTREAMHEADER * PACMSTREAMHEADER;
#endif
#ifdef _RAS_H
typedef RASAMB * LPRASAMB;
#endif
#endif

#if GRIMACE_WCE == 101
#ifdef EXCPT_H
typedef EXCEPTION_POINTERS * Exception_info_ptr;
#endif
#endif

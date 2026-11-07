#ifndef _COMMDLG_H
#define _COMMDLG_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push,1)

#define LBSELCHSTRINGA  "commdlg_LBSelChangedNotify"
#define SHAREVISTRINGA  "commdlg_ShareViolation"
#define FILEOKSTRINGA   "commdlg_FileNameOK"
#define COLOROKSTRINGA  "commdlg_ColorOK"
#define SETRGBSTRINGA   "commdlg_SetRGBColor"
#define HELPMSGSTRINGA  "commdlg_help"
#define FINDMSGSTRINGA  "commdlg_FindReplace"
#define LBSELCHSTRINGW  L"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGW  L"commdlg_ShareViolation"
#define FILEOKSTRINGW   L"commdlg_FileNameOK"
#define COLOROKSTRINGW  L"commdlg_ColorOK"
#define SETRGBSTRINGW   L"commdlg_SetRGBColor"
#define HELPMSGSTRINGW  L"commdlg_help"
#define FINDMSGSTRINGW  L"commdlg_FindReplace"
#ifndef CDN_FIRST
#define CDN_FIRST	((UINT)-601) /* also in commctrl.h */
#define CDN_LAST	((UINT)-699)
#endif
#define CDN_INITDONE	CDN_FIRST
#define CDN_SELCHANGE	(CDN_FIRST-1U)
#define CDN_FOLDERCHANGE	(CDN_FIRST-2U)
#define CDN_SHAREVIOLATION	(CDN_FIRST-3U)
#define CDN_HELP	(CDN_FIRST-4U)
#define CDN_FILEOK	(CDN_FIRST-5U)
/**
 * This notification message is sent by an Explorer-style Open or Save As
 * common dialog box when the user selects a new file type from the file
 * types combo box. Your OFNHookProc hook procedure receives this message
 * in the form of a WM_NOTIFY message.
 *
 * The system sends this notification only if the dialog box was created
 * using the OFN_EXPLORER value.
 *
 * @param lpon Long pointer to an OFNOTIFY structure. The OFNOTIFY
 *        structure contains an NMHDR structure whose code member indicates
 *        the CDN_TYPECHANGE notification code. The OFNOTIFY structure also
 *        contains a pointer to an OPENFILENAME structure whose
 *        nFilterIndex member indicates the one-based index of the newly
 *        selected file type filter.
 * @return The return value is ignored.
 */
#define CDN_TYPECHANGE	(CDN_FIRST-6U)
#define CDM_FIRST	(WM_USER+100)
#define CDM_LAST	(WM_USER+200)
#define CDM_GETSPEC	CDM_FIRST
#define CDM_GETFILEPATH	(CDM_FIRST+1)
#define CDM_GETFOLDERPATH (CDM_FIRST+2)
#define CDM_GETFOLDERIDLIST	(CDM_FIRST+3)
#define CDM_SETCONTROLTEXT	(CDM_FIRST+4)
#define CDM_HIDECONTROL	(CDM_FIRST+5)
/**
 * This message sets the default filename extension for an Explorer-style
 * Open or Save As common dialog box. The dialog box must have been created
 * with the OFN_EXPLORER flag; otherwise, the message fails.
 *
 * @param hdlg Handle to the common dialog box window to receive the
 *        message.
 * @param pszext Pointer to the null-terminated string that contains the
 *        new file name extension. Must not include a period (.).
 * @return None.
 */
#define CDM_SETDEFEXT	(CDM_FIRST+6)
#define CC_RGBINIT	1
#define CC_FULLOPEN	2
#define CC_PREVENTFULLOPEN	4
#define CC_SHOWHELP	8
#define CC_ENABLEHOOK	16
#define CC_ENABLETEMPLATE	32
#define CC_ENABLETEMPLATEHANDLE	64
#define CC_SOLIDCOLOR	128
#define CC_ANYCOLOR	256
#define CF_SCREENFONTS	1
#define CF_PRINTERFONTS	2
#define CF_BOTH	3
#define CF_SHOWHELP	4
#define CF_ENABLEHOOK	8
#define CF_ENABLETEMPLATE	16
#define CF_ENABLETEMPLATEHANDLE	32
#define CF_INITTOLOGFONTSTRUCT	64
#define CF_USESTYLE	128
#define CF_EFFECTS	256
#define CF_APPLY	512
#define CF_ANSIONLY	1024
#define CF_SCRIPTSONLY	CF_ANSIONLY
#define CF_NOVECTORFONTS	2048
#define CF_NOOEMFONTS	2048
#define CF_NOSIMULATIONS	4096
#define CF_LIMITSIZE	8192
#define CF_FIXEDPITCHONLY	16384
#define CF_WYSIWYG	32768
#define CF_FORCEFONTEXIST	65536
#define CF_SCALABLEONLY	131072
#define CF_TTONLY	262144
#define CF_NOFACESEL	 524288
#define CF_NOSTYLESEL	 1048576
#define CF_NOSIZESEL	 2097152
#define CF_SELECTSCRIPT	 4194304
#define CF_NOSCRIPTSEL	 8388608
#define CF_NOVERTFONTS	0x1000000
#define SIMULATED_FONTTYPE	0x8000
#define PRINTER_FONTTYPE	0x4000
#define SCREEN_FONTTYPE	0x2000
#define BOLD_FONTTYPE	0x100
#define ITALIC_FONTTYPE	0x0200
#define REGULAR_FONTTYPE	0x0400
#define WM_CHOOSEFONT_GETLOGFONT	(WM_USER+1)
#define WM_CHOOSEFONT_SETLOGFONT	(WM_USER+101)
#define WM_CHOOSEFONT_SETFLAGS	(WM_USER+102)
#define OFN_ALLOWMULTISELECT 512
#define OFN_CREATEPROMPT 0x2000
#define OFN_ENABLEHOOK 32
#define OFN_ENABLESIZING 0x800000
#define OFN_ENABLETEMPLATE 64
#define OFN_ENABLETEMPLATEHANDLE 128
#define OFN_EXPLORER 0x80000
#define OFN_EXTENSIONDIFFERENT 0x400
#define OFN_FILEMUSTEXIST 0x1000
#define OFN_HIDEREADONLY 4
#define OFN_LONGNAMES 0x200000
#define OFN_NOCHANGEDIR 8
#define OFN_NODEREFERENCELINKS 0x100000
#define OFN_NOLONGNAMES 0x40000
#define OFN_NONETWORKBUTTON 0x20000
#define OFN_NOREADONLYRETURN 0x8000
#define OFN_NOTESTFILECREATE 0x10000
#define OFN_NOVALIDATE 256
#define OFN_OVERWRITEPROMPT 2
#define OFN_PATHMUSTEXIST 0x800
#define OFN_READONLY 1
#define OFN_SHAREAWARE 0x4000
#define OFN_SHOWHELP 16
#define OFN_SHAREFALLTHROUGH 2
#define OFN_SHARENOWARN 1
#define OFN_SHAREWARN 0
#define OFN_NODEREFERENCELINKS 0x100000
#if (_WIN32_WINNT >= 0x0500)
#define OFN_DONTADDTORECENT 0x02000000
#endif
#define FR_DIALOGTERM 64
#define FR_DOWN 1
#define FR_ENABLEHOOK 256
#define FR_ENABLETEMPLATE 512
#define FR_ENABLETEMPLATEHANDLE 0x2000
#define FR_FINDNEXT 8
#define FR_HIDEUPDOWN 0x4000
#define FR_HIDEMATCHCASE 0x8000
#define FR_HIDEWHOLEWORD 0x10000
#define FR_MATCHALEFHAMZA	0x80000000
#define FR_MATCHCASE 4
#define FR_MATCHDIAC	0x20000000
#define FR_MATCHKASHIDA	0x40000000
#define FR_NOMATCHCASE 0x800
#define FR_NOUPDOWN 0x400
#define FR_NOWHOLEWORD 4096
#define FR_REPLACE 16
#define FR_REPLACEALL 32
#define FR_SHOWHELP 128
#define FR_WHOLEWORD 2
#ifdef _WIN32_WCE
#define PD_SELECTALLPAGES 0x00000001
#define PD_SELECTSELECTION 0x00000002
#define PD_SELECTDRAFTMODE 0x00000008
#define PD_SELECTA4 0x00000010
#define PD_SELECTLETTER 0x00000020
#define PD_SELECTINFRARED 0x00000040
#define PD_SELECTSERIAL 0x00000080
#define PD_DISABLEPAPERSIZE 0x00000100
#define PD_DISABLEPRINTRANGE 0x00000200
#define PD_DISABLEMARGINS 0x00000400
#define PD_DISABLEORIENTATION 0x00000800
#define PD_RETURNDEFAULTDC 0x00002000
#define PD_ENABLEPRINTHOOK 0x00004000
#define PD_ENABLEPRINTTEMPLATE 0x00008000
#define PD_ENABLEPRINTTEMPLATEHANDLE 0x00010000
#define PD_TITLE 0x00020000
#define PD_SELECTPORTRAIT 0x00040000
#define PD_SELECTLANDSCAPE 0x00080000
#define PD_MARGINS 0x00100000
#define PD_INTHOUSANDTHSOFINCHES 0x00200000
#define PD_INHUNDREDTHSOFMILLIMETERS 0x00400000
#define PD_MINMARGINS 0x00800000
#else
#define PD_ALLPAGES	0x00000000
#define PD_SELECTION	0x00000001
#define PD_PAGENUMS	0x00000002
#define PD_NOSELECTION	0x00000004
#define PD_NOPAGENUMS	0x00000008
#define PD_COLLATE	0x00000010
#define PD_PRINTTOFILE	0x00000020
#define PD_PRINTSETUP	0x00000040
#define PD_NOWARNING	0x00000080
#define PD_RETURNDC	0x00000100
#define PD_RETURNIC	0x00000200
#define PD_RETURNDEFAULT	0x00000400
#define PD_SHOWHELP	0x00000800
#define PD_ENABLEPRINTHOOK	0x00001000
#define PD_ENABLESETUPHOOK	0x00002000
#define PD_ENABLEPRINTTEMPLATE	0x00004000
#define PD_ENABLESETUPTEMPLATE 0x00008000
#define PD_ENABLEPRINTTEMPLATEHANDLE 0x00010000
#define PD_ENABLESETUPTEMPLATEHANDLE 0x00020000
#define PD_USEDEVMODECOPIES	0x00040000
#define PD_USEDEVMODECOPIESANDCOLLATE	0x00040000
#define PD_DISABLEPRINTTOFILE	0x00080000
#define PD_HIDEPRINTTOFILE	0x00100000
#define PD_NONETWORKBUTTON	0x00200000
#if (_WIN32_WINNT >= 0x0500)
#define PD_CURRENTPAGE	0x00400000
#define PD_NOCURRENTPAGE	0x00800000
#define PD_EXCLUSIONFLAGS	0x01000000 
#define PD_USELARGETEMPLATE	0x10000000
#endif
#define PD_RESULT_CANCEL	0
#define PD_RESULT_PRINT	1
#define PD_RESULT_APPLY	2
#define START_PAGE_GENERAL	0XFFFFFFFF
#endif
#define PSD_DEFAULTMINMARGINS	0
#define PSD_INWININIINTLMEASURE	0
#define PSD_MINMARGINS	1
#define PSD_MARGINS	2
#define PSD_INTHOUSANDTHSOFINCHES	4
#define PSD_INHUNDREDTHSOFMILLIMETERS	8
#define PSD_DISABLEMARGINS	16
#define PSD_DISABLEPRINTER	32
#define PSD_NOWARNING	128
#define PSD_DISABLEORIENTATION	256
#define PSD_DISABLEPAPER	512
#define PSD_RETURNDEFAULT	1024
#define PSD_SHOWHELP	2048
#define PSD_ENABLEPAGESETUPHOOK 8192
#define PSD_ENABLEPAGESETUPTEMPLATE	0x8000
#define PSD_ENABLEPAGESETUPTEMPLATEHANDLE	0x20000
#define PSD_ENABLEPAGEPAINTHOOK	0x40000
#define PSD_DISABLEPAGEPAINTING	0x80000
#define WM_PSD_PAGESETUPDLG	WM_USER
#define WM_PSD_FULLPAGERECT	(WM_USER+1)
#define WM_PSD_MINMARGINRECT	(WM_USER+2)
#define WM_PSD_MARGINRECT	(WM_USER+3)
#define WM_PSD_GREEKTEXTRECT	(WM_USER+4)
#define WM_PSD_ENVSTAMPRECT	(WM_USER+5)
#define WM_PSD_YAFULLPAGERECT	(WM_USER+6)
#define CD_LBSELNOITEMS (-1)
#define CD_LBSELCHANGE   0
#define CD_LBSELSUB      1
#define CD_LBSELADD      2
#define DN_DEFAULTPRN	1
#if (_WIN32_WINNT >= 0x0500)
#define OPENFILENAME_SIZE_VERSION_400  76
#endif

#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif /* ifndef SNDMSG */

#define CommDlg_OpenSave_GetSpec(d,s,m) ((int)SNDMSG((d),CDM_GETSPEC,(m),(LPARAM)(s)))
#define CommDlg_OpenSave_GetSpecA CommDlg_OpenSave_GetSpec
#define CommDlg_OpenSave_GetSpecW CommDlg_OpenSave_GetSpec
#define CommDlg_OpenSave_GetFilePath(d,s,m) ((int)SNDMSG((d),CDM_GETFILEPATH,(m),(LPARAM)(s)))
#define CommDlg_OpenSave_GetFilePathA CommDlg_OpenSave_GetFilePath
#define CommDlg_OpenSave_GetFilePathW CommDlg_OpenSave_GetFilePath
#define CommDlg_OpenSave_GetFolderPath(d,s,m) ((int)SNDMSG((d),CDM_GETFOLDERPATH,(m),(LPARAM)(LPSTR)(s)))
#define CommDlg_OpenSave_GetFolderPathA CommDlg_OpenSave_GetFolderPath
#define CommDlg_OpenSave_GetFolderPathW CommDlg_OpenSave_GetFolderPath
#define CommDlg_OpenSave_GetFolderIDList(d,i,m) ((int)SNDMSG((d),CDM_GETFOLDERIDLIST,(m),(LPARAM)(i)))
#define CommDlg_OpenSave_SetControlText(d,i,t) ((void)SNDMSG((d),CDM_SETCONTROLTEXT,(i),(LPARAM)(t)))
#define CommDlg_OpenSave_HideControl(d,i) ((void)SNDMSG((d),CDM_HIDECONTROL,(i),0))
#define CommDlg_OpenSave_SetDefExt(d,e) ((void)SNDMSG((d),CDM_SETDEFEXT,0,(LPARAM)(e)))

typedef UINT (APIENTRY *__CDHOOKPROC)(HWND,UINT,WPARAM,LPARAM);
typedef __CDHOOKPROC LPCCHOOKPROC;
typedef __CDHOOKPROC LPCFHOOKPROC;
typedef __CDHOOKPROC LPFRHOOKPROC;
typedef __CDHOOKPROC LPOFNHOOKPROC;
typedef __CDHOOKPROC LPPAGEPAINTHOOK;
typedef __CDHOOKPROC LPPAGESETUPHOOK;
typedef __CDHOOKPROC LPSETUPHOOKPROC;
typedef __CDHOOKPROC LPPRINTHOOKPROC;
typedef struct tagCHOOSECOLORA {
	DWORD	lStructSize;
	HWND	hwndOwner;
	HWND	hInstance;
	COLORREF	rgbResult;
	COLORREF*	lpCustColors;
	DWORD	Flags;
	LPARAM	lCustData;
	LPCCHOOKPROC	lpfnHook;
	LPCSTR	lpTemplateName;
} CHOOSECOLORA,*LPCHOOSECOLORA;
typedef struct tagCHOOSECOLORW {
	DWORD	lStructSize;
	HWND	hwndOwner;
#if (_WIN32_WCE >= 0x0200)
	HINSTANCE	hInstance;
#else
	HWND	hInstance;
#endif
	COLORREF	rgbResult;
	COLORREF*	lpCustColors;
	DWORD	Flags;
	LPARAM	lCustData;
	LPCCHOOKPROC	lpfnHook;
	LPCWSTR	lpTemplateName;
} CHOOSECOLORW,*LPCHOOSECOLORW;
typedef struct tagCHOOSEFONTA {
	DWORD	lStructSize;
	HWND	hwndOwner;
	HDC	hDC;
	LPLOGFONTA	lpLogFont;
	INT	iPointSize;
	DWORD	Flags;
	DWORD	rgbColors;
	LPARAM	lCustData;
	LPCFHOOKPROC	lpfnHook;
	LPCSTR	lpTemplateName;
	HINSTANCE	hInstance;
	LPSTR	lpszStyle;
	WORD	nFontType;
	WORD	___MISSING_ALIGNMENT__;
	INT	nSizeMin;
	INT	nSizeMax;
} CHOOSEFONTA,*LPCHOOSEFONTA;
typedef struct tagCHOOSEFONTW {
	DWORD	lStructSize;
	HWND	hwndOwner;
	HDC	hDC;
	LPLOGFONTW	lpLogFont;
	INT	iPointSize;
	DWORD	Flags;
	DWORD	rgbColors;
	LPARAM	lCustData;
	LPCFHOOKPROC	lpfnHook;
	LPCWSTR	lpTemplateName;
	HINSTANCE	hInstance;
	LPWSTR	lpszStyle;
	WORD	nFontType;
	WORD	___MISSING_ALIGNMENT__;
	INT	nSizeMin;
	INT	nSizeMax;
} CHOOSEFONTW,*LPCHOOSEFONTW;
/**
 * This structure contains strings that identify the driver, device, and
 * output port names for a printer. The PageSetupDlg function uses these
 * strings to initialize the system-defined Print property sheet or Print
 * dialog box. When the user closes the property sheet or dialog box,
 * information about the selected printer is returned in this structure.
 *
 * The PageSetupDlg function fills this structure with byte offsets rather
 * than character offsets.
 */
typedef struct tagDEVNAMES {
	/**
	 * (In/Out) Specifies the offset in bytes from the
	 * beginning of this structure to a null-terminated string that
	 * contains the file name (without the extension) of the device
	 * driver. On input, this string is used to determine the printer to
	 * display initially in the dialog box.
	 */
	WORD wDriverOffset;
	/**
	 * (In/Out) Specifies the offset in bytes from the
	 * beginning of this structure to the null-terminated string that
	 * contains the name of the device.
	 */
	WORD wDeviceOffset;
	/**
	 * (In/Out) Specifies the offset in bytes from the
	 * beginning of this structure to the null-terminated string that
	 * contains the device name for the physical output medium (output
	 * port).
	 */
	WORD wOutputOffset;
	/**
	 * (In/Out) Specifies whether the strings contained in the
	 * DEVNAMES structure identify the default printer. This string is
	 * used to verify that the default printer has not changed since the
	 * last print operation. If any of the strings do not match, a
	 * warning message is displayed informing the user that the document
	 * may need to be reformatted. On output, the wDefault member is
	 * changed only if the Print Setup dialog box was displayed and the
	 * user chose the OK button. The DN_DEFAULTPRN flag is used if the
	 * default printer was selected. If a specific printer is selected,
	 * the flag is not used. All other flags in this member are reserved
	 * for internal use by the dialog box procedure for the Print
	 * property sheet or Print dialog box.
	 */
	WORD wDefault;
} DEVNAMES,*LPDEVNAMES;
typedef struct {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	DWORD Flags;
	LPSTR lpstrFindWhat;
	LPSTR lpstrReplaceWith;
	WORD wFindWhatLen;
	WORD wReplaceWithLen;
	LPARAM lCustData;
	LPFRHOOKPROC lpfnHook;
	LPCSTR lpTemplateName;
} FINDREPLACEA,*LPFINDREPLACEA;
typedef struct {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	DWORD Flags;
	LPWSTR lpstrFindWhat;
	LPWSTR lpstrReplaceWith;
	WORD wFindWhatLen;
	WORD wReplaceWithLen;
	LPARAM lCustData;
	LPFRHOOKPROC lpfnHook;
	LPCWSTR lpTemplateName;
} FINDREPLACEW,*LPFINDREPLACEW;
typedef struct tagOFNA {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCSTR lpstrFilter;
	LPSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	DWORD nFilterIndex;
	LPSTR lpstrFile;
	DWORD nMaxFile;
	LPSTR lpstrFileTitle;
	DWORD nMaxFileTitle;
	LPCSTR lpstrInitialDir;
	LPCSTR lpstrTitle;
	DWORD Flags;
	WORD nFileOffset;
	WORD nFileExtension;
	LPCSTR lpstrDefExt;
	DWORD lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCSTR lpTemplateName;
#if (_WIN32_WINNT >= 0x0500)
	void * pvReserved;
	DWORD dwReserved;
	DWORD FlagsEx;
#endif /* (_WIN32_WINNT >= 0x0500) */
} OPENFILENAMEA,*LPOPENFILENAMEA;
typedef struct tagOFNW {
	DWORD lStructSize;
	HWND hwndOwner;
	HINSTANCE hInstance;
	LPCWSTR lpstrFilter;
	LPWSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	DWORD nFilterIndex;
	LPWSTR lpstrFile;
	DWORD nMaxFile;
	LPWSTR lpstrFileTitle;
	DWORD nMaxFileTitle;
	LPCWSTR lpstrInitialDir;
	LPCWSTR lpstrTitle;
	DWORD Flags;
	WORD nFileOffset;
	WORD nFileExtension;
	LPCWSTR lpstrDefExt;
	DWORD lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCWSTR lpTemplateName;
#if (_WIN32_WINNT >= 0x0500)
	void * pvReserved;
	DWORD dwReserved;
	DWORD FlagsEx;
#endif /* (_WIN32_WINNT >= 0x0500) */
} OPENFILENAMEW,*LPOPENFILENAMEW;
typedef struct _OFNOTIFYA {
	NMHDR hdr;
	LPOPENFILENAMEA lpOFN;
	LPSTR pszFile;
} OFNOTIFYA,*LPOFNOTIFYA;
typedef struct _OFNOTIFYW {
	NMHDR hdr;
	LPOPENFILENAMEW lpOFN;
	LPWSTR pszFile;
} OFNOTIFYW,*LPOFNOTIFYW;
typedef struct tagPSDA {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	DWORD Flags;
	POINT ptPaperSize;
	RECT rtMinMargin;
	RECT rtMargin;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPAGESETUPHOOK lpfnPageSetupHook;
	LPPAGEPAINTHOOK lpfnPagePaintHook;
	LPCSTR lpPageSetupTemplateName;
	HGLOBAL hPageSetupTemplate;
} PAGESETUPDLGA,*LPPAGESETUPDLGA;
typedef struct tagPSDW {
	DWORD lStructSize;
	HWND hwndOwner;
	HGLOBAL hDevMode;
	HGLOBAL hDevNames;
	DWORD Flags;
	POINT ptPaperSize;
	RECT rtMinMargin;
	RECT rtMargin;
	HINSTANCE hInstance;
	LPARAM lCustData;
	LPPAGESETUPHOOK lpfnPageSetupHook;
	LPPAGEPAINTHOOK lpfnPagePaintHook;
	LPCWSTR lpPageSetupTemplateName;
	HGLOBAL hPageSetupTemplate;
} PAGESETUPDLGW,*LPPAGESETUPDLGW;
typedef struct tagPDA {
	DWORD lStructSize;
	HWND hwndOwner;
	HANDLE hDevMode;
	HANDLE hDevNames;
	HDC hDC;
	DWORD Flags;
	WORD nFromPage;
	WORD nToPage;
	WORD nMinPage;
	WORD nMaxPage;
	WORD nCopies;
	HINSTANCE hInstance;
	DWORD lCustData;
	LPPRINTHOOKPROC lpfnPrintHook;
	LPSETUPHOOKPROC lpfnSetupHook;
	LPCSTR lpPrintTemplateName;
	LPCSTR lpSetupTemplateName;
	HANDLE hPrintTemplate;
	HANDLE hSetupTemplate;
} PRINTDLGA,*LPPRINTDLGA;
#ifdef _WIN32_WCE
typedef struct tagPDW {
	DWORD cbStruct;
	HWND hwndOwner;
	HDC hdc;
	DWORD dwFlags;
	RECT rcMinMargin;
	RECT rcMargin;
	HINSTANCE hinst;
	LPARAM lCustData;
	LPPRINTHOOKPROC pfnPrintHook;
	LPCWSTR pszPrintTemplateName;
	HGLOBAL hglbPrintTemplateResource;
} PRINTDLGW,*LPPRINTDLGW;
#else
typedef struct tagPDW {
	DWORD lStructSize;
	HWND hwndOwner;
	HANDLE hDevMode;
	HANDLE hDevNames;
	HDC hDC;
	DWORD Flags;
	WORD nFromPage;
	WORD nToPage;
	WORD nMinPage;
	WORD nMaxPage;
	WORD nCopies;
	HINSTANCE hInstance;
	DWORD lCustData;
	LPPRINTHOOKPROC lpfnPrintHook;
	LPSETUPHOOKPROC lpfnSetupHook;
	LPCWSTR lpPrintTemplateName;
	LPCWSTR lpSetupTemplateName;
	HANDLE hPrintTemplate;
	HANDLE hSetupTemplate;
} PRINTDLGW,*LPPRINTDLGW;
#endif
#if (WINVER >= 0x0500) && !defined (_OBJC_NO_COM)
#include <unknwn.h>  /* for LPUNKNOWN  */ 
#include <prsht.h>   /* for HPROPSHEETPAGE  */
typedef struct tagPRINTPAGERANGE {
   DWORD  nFromPage;
   DWORD  nToPage;
} PRINTPAGERANGE, *LPPRINTPAGERANGE;
typedef struct tagPDEXA {
   DWORD lStructSize;
   HWND hwndOwner;
   HGLOBAL hDevMode;
   HGLOBAL hDevNames;
   HDC hDC;
   DWORD Flags;
   DWORD Flags2;
   DWORD ExclusionFlags;
   DWORD nPageRanges;
   DWORD nMaxPageRanges;
   LPPRINTPAGERANGE lpPageRanges;
   DWORD nMinPage;
   DWORD nMaxPage;
   DWORD nCopies;
   HINSTANCE hInstance;
   LPCSTR lpPrintTemplateName;
   LPUNKNOWN lpCallback;
   DWORD nPropertyPages;
   HPROPSHEETPAGE *lphPropertyPages;
   DWORD nStartPage;
   DWORD dwResultAction;
} PRINTDLGEXA, *LPPRINTDLGEXA;
typedef struct tagPDEXW {
   DWORD lStructSize;
   HWND hwndOwner;
   HGLOBAL hDevMode;
   HGLOBAL hDevNames;
   HDC hDC;
   DWORD Flags;
   DWORD Flags2;
   DWORD ExclusionFlags;
   DWORD nPageRanges;
   DWORD nMaxPageRanges;
   LPPRINTPAGERANGE lpPageRanges;
   DWORD nMinPage;
   DWORD nMaxPage;
   DWORD nCopies;
   HINSTANCE hInstance;
   LPCWSTR lpPrintTemplateName;
   LPUNKNOWN lpCallback;
   DWORD nPropertyPages;
   HPROPSHEETPAGE *lphPropertyPages;
   DWORD nStartPage;
   DWORD dwResultAction;
} PRINTDLGEXW, *LPPRINTDLGEXW;
#endif /* WINVER >= 0x0500 */

BOOL WINAPI ChooseColorA(LPCHOOSECOLORA);
/**
 * Displays the Color common dialog for choosing an RGB colour.
 *
 * The dialog offers the system colours and dithered versions of them; it
 * doesn't support palettes. On screens narrower than 480 pixels,
 * user-defined colours are unavailable and CC_FULLOPEN and
 * CC_PREVENTFULLOPEN are ignored. To hook the dialog's messages, set
 * CC_ENABLEHOOK in Flags and put a CCHookProc in lpfnHook.
 *
 * @param lpcc CHOOSECOLOR with the dialog settings; on success, rgbResult
 *        receives the selected colour.
 * @return Nonzero if the user accepts. 0 if cancelled or on error; call
 *        CommDlgExtendedError for the error.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL WINAPI _WNAME(ChooseColor)(LPCHOOSECOLORW lpcc);
BOOL WINAPI ChooseFontA(LPCHOOSEFONTA);
BOOL WINAPI ChooseFontW(LPCHOOSEFONTW);
/**
 * Returns the error code from the last failed common dialog call.
 *
 * Covers GetOpenFileNameW, GetSaveFileNameW and the other common dialogs.
 * After a successful call the value is undefined. Windows CE adds
 * CDERR_REGISTRYFAILURE, for a failed registry read, and never returns
 * CDERR_LOADSTRFAILURE, CDERR_MEMLOCKFAILURE or CDERR_REGISTERMSGFAIL.
 *
 * @return A CDERR_* or FNERR_* code, such as CDERR_STRUCTSIZE or
 *        FNERR_BUFFERTOOSMALL, or 0 if the user cancelled without error.
 *
 * @note Windows CE 2.0 and later.
 */
DWORD WINAPI CommDlgExtendedError(void);
HWND WINAPI FindTextA(LPFINDREPLACEA);
HWND WINAPI FindTextW(LPFINDREPLACEW);
short WINAPI GetFileTitleA(LPCSTR,LPSTR,WORD);
short WINAPI GetFileTitleW(LPCWSTR,LPWSTR,WORD);
BOOL WINAPI GetOpenFileNameA(LPOPENFILENAMEA);
/**
 * Shows the system Open dialog and writes the selected full path to
 * lpstrFile.
 *
 * Windows CE ignores the lCustData, lpfnHook and lpTemplateName members,
 * and doesn't support OFN_ALLOWMULTISELECT, OFN_ENABLEHOOK,
 * OFN_ENABLETEMPLATE, OFN_ENABLETEMPLATEHANDLE, OFN_NOREADONLYRETURN,
 * OFN_NOVALIDATE, OFN_READONLY or OFN_SHAREAWARE. Call
 * CommDlgExtendedError to tell a failure from a cancel. GetLastError is
 * only set to ERROR_INVALID_PARAMETER or ERROR_OUTOFMEMORY.
 *
 * @param lpofn Initial settings, with lStructSize, lpstrFile and nMaxFile
 *        set. Receives the selected path and related details.
 * @return TRUE if the user chose a file. FALSE on cancel, error, or if
 *        lpstrFile is too small for the path.
 */
BOOL WINAPI GetOpenFileNameW(LPOPENFILENAMEW lpofn);
BOOL WINAPI GetSaveFileNameA(LPOPENFILENAMEA);
/**
 * Shows the system Save As dialog and writes the chosen full path to
 * lpstrFile.
 *
 * Windows CE ignores the lCustData, lpfnHook and lpTemplateName members,
 * and doesn't support OFN_ALLOWMULTISELECT, OFN_ENABLEHOOK,
 * OFN_ENABLETEMPLATE, OFN_ENABLETEMPLATEHANDLE, OFN_NOREADONLYRETURN,
 * OFN_NOVALIDATE, OFN_READONLY or OFN_SHAREAWARE. Call
 * CommDlgExtendedError to tell a failure from a cancel. GetLastError is
 * only set to ERROR_INVALID_PARAMETER or ERROR_OUTOFMEMORY.
 *
 * @param lpofn Initial settings, with lStructSize, lpstrFile and nMaxFile
 *        set. Receives the chosen path and related details.
 * @return TRUE if the user chose a name. FALSE on cancel, error, or if
 *        lpstrFile is too small for the path.
 */
BOOL WINAPI GetSaveFileNameW(LPOPENFILENAMEW lpofn);
BOOL WINAPI PageSetupDlgA(LPPAGESETUPDLGA);
/**
 * Displays Page Setup to choose paper, source, orientation and margins.
 *
 * The function fills DEVNAMES offsets in bytes, not character units.
 *
 * @param lppsd Input settings for the dialog; receives the user's selections.
 * @return TRUE if the user accepts. FALSE if canceled or an error occurs;
 *         call CommDlgExtendedError to inspect an error.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL WINAPI PageSetupDlgW(LPPAGESETUPDLGW lppsd);
BOOL WINAPI PrintDlgA(LPPRINTDLGA);
/**
 * Displays the Print or Print Setup dialog and returns the user's
 * selections.
 *
 * PRINTDLG has different members on Windows CE than on desktop Windows.
 * PageSetupDlg is the page-setup alternative on Handheld PC 2000. Delete
 * a returned device context with DeleteDC. PD_RETURNDEFAULTDC uses the
 * last saved or default settings and can fail if they are invalid; show
 * the dialog to select a valid printer or destination. A hook procedure
 * in lpfnPrintHook that handles WM_CTLCOLORDLG must return a background
 * brush.
 *
 * @param lppd PRINTDLG with the dialog settings; receives the user's
 *        selections.
 * @return Nonzero if the user accepts. 0 if cancelled or on error; call
 *        CommDlgExtendedError for the error (0 after a cancel).
 *
 * @note Windows CE 2.0 and later.
 */
BOOL WINAPI _WNAME(PrintDlg)(LPPRINTDLGW lppd);
HWND WINAPI ReplaceTextA(LPFINDREPLACEA);
HWND WINAPI ReplaceTextW(LPFINDREPLACEW);
#if (WINVER >= 0x0500) && !defined (_OBJC_NO_COM)
HRESULT WINAPI PrintDlgExA(LPPRINTDLGEXA);
HRESULT WINAPI PrintDlgExW(LPPRINTDLGEXW);
#endif /* WINVER >= 0x0500 */

#ifdef UNICODE
#define LBSELCHSTRING  LBSELCHSTRINGW
#define SHAREVISTRING  SHAREVISTRINGW
#define FILEOKSTRING   FILEOKSTRINGW
#define COLOROKSTRING  COLOROKSTRINGW
#define SETRGBSTRING   SETRGBSTRINGW
#define HELPMSGSTRING  HELPMSGSTRINGW
#define FINDMSGSTRING  FINDMSGSTRINGW
typedef CHOOSECOLORW CHOOSECOLOR,*LPCHOOSECOLOR;
typedef CHOOSEFONTW CHOOSEFONT,*LPCHOOSEFONT;
typedef FINDREPLACEW FINDREPLACE,*LPFINDREPLACE;
typedef OPENFILENAMEW OPENFILENAME,*LPOPENFILENAME;
typedef OFNOTIFYW OFNOTIFY,*LPOFNOTIFY;
typedef PAGESETUPDLGW PAGESETUPDLG,*LPPAGESETUPDLG;
typedef PRINTDLGW PRINTDLG,*LPPRINTDLG;
#define ChooseColor _WNAME(ChooseColor)
#define ChooseFont ChooseFontW
#define FindText FindTextW
#define GetFileTitle GetFileTitleW
/**
 * Shows the system Open dialog and writes the selected full path to
 * lpstrFile.
 *
 * Windows CE ignores the lCustData, lpfnHook and lpTemplateName members,
 * and doesn't support OFN_ALLOWMULTISELECT, OFN_ENABLEHOOK,
 * OFN_ENABLETEMPLATE, OFN_ENABLETEMPLATEHANDLE, OFN_NOREADONLYRETURN,
 * OFN_NOVALIDATE, OFN_READONLY or OFN_SHAREAWARE. Call
 * CommDlgExtendedError to tell a failure from a cancel. GetLastError is
 * only set to ERROR_INVALID_PARAMETER or ERROR_OUTOFMEMORY.
 *
 * @param lpofn Initial settings, with lStructSize, lpstrFile and nMaxFile
 *        set. Receives the selected path and related details.
 * @return TRUE if the user chose a file. FALSE on cancel, error, or if
 *        lpstrFile is too small for the path.
 */
#define GetOpenFileName GetOpenFileNameW
/**
 * Shows the system Save As dialog and writes the chosen full path to
 * lpstrFile.
 *
 * Windows CE ignores the lCustData, lpfnHook and lpTemplateName members,
 * and doesn't support OFN_ALLOWMULTISELECT, OFN_ENABLEHOOK,
 * OFN_ENABLETEMPLATE, OFN_ENABLETEMPLATEHANDLE, OFN_NOREADONLYRETURN,
 * OFN_NOVALIDATE, OFN_READONLY or OFN_SHAREAWARE. Call
 * CommDlgExtendedError to tell a failure from a cancel. GetLastError is
 * only set to ERROR_INVALID_PARAMETER or ERROR_OUTOFMEMORY.
 *
 * @param lpofn Initial settings, with lStructSize, lpstrFile and nMaxFile
 *        set. Receives the chosen path and related details.
 * @return TRUE if the user chose a name. FALSE on cancel, error, or if
 *        lpstrFile is too small for the path.
 */
#define GetSaveFileName GetSaveFileNameW
/**
 * Displays Page Setup to choose paper, source, orientation and margins.
 *
 * The function fills DEVNAMES offsets in bytes, not character units.
 *
 * @param lppsd Input settings for the dialog; receives the user's selections.
 * @return TRUE if the user accepts. FALSE if canceled or an error occurs;
 *         call CommDlgExtendedError to inspect an error.
 *
 * @note Windows CE 3.0 and later.
 */
#define PageSetupDlg PageSetupDlgW
#define PrintDlg _WNAME(PrintDlg)
#define ReplaceText ReplaceTextW
#if (WINVER >= 0x0500) && !defined (_OBJC_NO_COM)
typedef PRINTDLGEXW PRINTDLGEX, *LPPRINTDLGEX;
#define PrintDlgEx PrintDlgExW
#endif /* WINVER >= 0x0500 */
#else /* UNICODE */
#define LBSELCHSTRING  LBSELCHSTRINGA
#define SHAREVISTRING  SHAREVISTRINGA
#define FILEOKSTRING   FILEOKSTRINGA
#define COLOROKSTRING  COLOROKSTRINGA
#define SETRGBSTRING   SETRGBSTRINGA
#define HELPMSGSTRING  HELPMSGSTRINGA
#define FINDMSGSTRING  FINDMSGSTRINGA
typedef CHOOSECOLORA CHOOSECOLOR,*LPCHOOSECOLOR;
typedef CHOOSEFONTA CHOOSEFONT,*LPCHOOSEFONT;
typedef FINDREPLACEA FINDREPLACE,*LPFINDREPLACE;
typedef OPENFILENAMEA OPENFILENAME,*LPOPENFILENAME;
typedef OFNOTIFYA OFNOTIFY,*LPOFNOTIFY;
typedef PAGESETUPDLGA PAGESETUPDLG,*LPPAGESETUPDLG;
typedef PRINTDLGA PRINTDLG,*LPPRINTDLG;
#define ChooseColor ChooseColorA
#define ChooseFont ChooseFontA
#define FindText FindTextA
#define GetFileTitle GetFileTitleA
#define GetOpenFileName GetOpenFileNameA
#define GetSaveFileName GetSaveFileNameA
#define PageSetupDlg PageSetupDlgA
#define PrintDlg PrintDlgA
#define ReplaceText ReplaceTextA
#if (WINVER >= 0x0500) && !defined (_OBJC_NO_COM)
typedef PRINTDLGEXA PRINTDLGEX, *LPPRINTDLGEX;
#define PrintDlgEx PrintDlgExA
#endif /* WINVER >= 0x0500 */
#endif /* UNICODE */
#pragma pack(pop)
#ifdef __cplusplus
}
#endif
#endif

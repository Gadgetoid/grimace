import argparse
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DESTINATION = os.path.join(ROOT, "include", "w32api")
HEADERS = [
    "basetsd.h", "commctrl.h", "commdlg.h", "dbgapi.h", "dde.h", "dlgs.h", "excpt.h", "imm.h", "kfuncs.h", "lmcons.h", "mmsystem.h",
    "msacm.h", "mswsock.h", "notify.h", "poppack.h", "prsht.h", "pshpack2.h", "pshpack4.h", "ras.h", "shellapi.h", "tlhelp32.h", "winbase.h",
    "wincon.h", "windef.h", "windows.h", "winerror.h", "wingdi.h", "winnetwk.h", "winnls.h", "winnt.h", "winreg.h", "winresrc.h",
    "winsock.h", "winsvc.h", "winuser.h", "winver.h", "windowsx.h",
]
CE_PRINT_DIALOG_FLAGS = """#define PD_SELECTALLPAGES 0x00000001
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
#define PD_MINMARGINS 0x00800000"""
CE_PRINT_DIALOG = """typedef struct tagPDW {
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
} PRINTDLGW,*LPPRINTDLGW;"""

SH3_CONTEXT_TAIL = """	ULONG Fir;
	ULONG Psr;

#if !defined(SH3e) && !defined(SH4)
	ULONG	OldStuff[2];
	DEBUG_REGISTERS DebugRegisters;
#else
	ULONG	Fpscr;
	ULONG	Fpul;
	ULONG	FRegs[16];
#if defined(SH4)
	ULONG	xFRegs[16];
#endif
#endif
} CONTEXT;"""
CE_SH3_CONTEXT_TAIL = """	ULONG Fir;
	ULONG Psr;
	ULONG TEA;
	USHORT Expevt;
	USHORT Trapa;
	union {
		DEBUG_REGISTERS DebugRegisters;
		struct {
#if GRIMACE_CE == 1
			HANDLE hProc;
			DWORD akyCur;
			ULONG oldR15;
#if GRIMACE_WCE >= 101
			PULONG pFpuData;
#endif
#else
			DWORD fill[2];
			ULONG oldR15;
			PULONG pFpuData;
#endif
		};
	};
} CONTEXT;"""

X86_DISPATCHER_CONTEXT = """typedef struct _DISPATCHER_CONTEXT {
    unsigned long ControlPc;
    struct _RUNTIME_FUNCTION *FunctionEntry;
    unsigned long EstablisherFrame;
    CONTEXT* ContextRecord;
} DISPATCHER_CONTEXT, *PDISPATCHER_CONTEXT;"""
CE_X86_DISPATCHER_CONTEXT = """typedef struct _DISPATCHER_CONTEXT {
    struct _EXCEPTION_REGISTRATION_RECORD *RegistrationPointer;
    unsigned long ControlPc;
} DISPATCHER_CONTEXT, *PDISPATCHER_CONTEXT;"""


class Vendor:
    def __init__(self):
        self.notes = []

    def edit(self, header, note, original, replacement):
        path = os.path.join(DESTINATION, header)
        text = open(path).read()
        if text.count(original) != 1:
            sys.exit("vendor-w32api: %s: expected one match for %r" % (header, original[:60]))
        open(path, "w").write(text.replace(original, replacement))
        self.notes.append((header, note))

    def ce(self, header, note, original, ce_text):
        self.edit(header, note, original, "#ifdef _WIN32_WCE\n%s\n#else\n%s\n#endif" % (ce_text, original))

    def versions(self, header, note, original, ce1_text, ce2_text):
        self.ce(header, note, original, "#if GRIMACE_CE == 1\n%s\n#else\n%s\n#endif" % (ce1_text, ce2_text))

    def before_ce3(self, header, note, original, ce_text):
        self.edit(header, note, original, "#if defined(_WIN32_WCE) && _WIN32_WCE < 0x300\n%s\n#else\n%s\n#endif" % (ce_text, original))

    def ce3(self, header, note, original, ce3_text):
        self.edit(header, note, original, "#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300\n%s\n#else\n%s\n#endif" % (ce3_text, original))

    def ce1(self, header, note, original, ce1_text):
        self.edit(header, note, original, "#if defined(_WIN32_WCE) && GRIMACE_CE == 1\n%s\n#else\n%s\n#endif" % (ce1_text, original))

    def ce2(self, header, note, original, ce2_text):
        self.edit(header, note, original, "#if defined(_WIN32_WCE) && GRIMACE_CE >= 2\n%s\n#else\n%s\n#endif" % (ce2_text, original))

    def within(self, header, note, start, end, original, replacement):
        path = os.path.join(DESTINATION, header)
        text = open(path).read()
        first = text.index(start)
        last = text.index(end, first)
        block = text[first:last]
        if block.count(original) != 1:
            sys.exit("vendor-w32api: %s: expected one %r between %r and %r" % (header, original, start, end))
        open(path, "w").write(text[:first] + block.replace(original, replacement) + text[last:])
        self.notes.append((header, note))


def patch(vendor):
    vendor.ce("ras.h", "RAS_MaxEntryName is 20 on CE", "#define RAS_MaxEntryName      256", "#define RAS_MaxEntryName      20")
    vendor.ce("ras.h", "RAS_MaxDeviceName is 32 on CE", "#define RAS_MaxDeviceName     128", "#define RAS_MaxDeviceName     32")
    vendor.ce("ras.h", "RAS_MaxCallbackNumber is 48 on CE", "#define RAS_MaxCallbackNumber RAS_MaxPhoneNumber", "#define RAS_MaxCallbackNumber 48")
    for letter in ("W", "A"):
        vendor.within("ras.h", "RASCONN%s has no device or phonebook fields on CE" % letter, "typedef struct tagRASCONN%s {" % letter,
                      "} RASCONN%s," % letter, "#if (WINVER >= 0x400) \n", "#if (WINVER >= 0x400) && !defined(_WIN32_WCE)\n")
        vendor.within("ras.h", "RASCONN%s has no phonebook fields on CE" % letter, "typedef struct tagRASCONN%s {" % letter,
                      "} RASCONN%s," % letter, "#if (WINVER >= 0x401)\n", "#if (WINVER >= 0x401) && !defined(_WIN32_WCE)\n")
        vendor.within("ras.h", "RASPPPIP%s has no server address on CE" % letter, "typedef struct tagRASPPPIP%s {" % letter,
                      "} RASPPPIP%s" % letter, "#ifndef WINNT35COMPATIBLE", "#if !defined(WINNT35COMPATIBLE) && !defined(_WIN32_WCE)")
    vendor.before_ce3("ras.h", "RASDEVINFOW's strings are CHAR on CE 1.0 and 2.0",
              "    WCHAR szDeviceType[RAS_MaxDeviceType + 1];\n    WCHAR szDeviceName[RAS_MaxDeviceName + 1];\n} RASDEVINFOW, *LPRASDEVINFOW;",
              "    CHAR szDeviceType[RAS_MaxDeviceType + 1];\n    CHAR szDeviceName[RAS_MaxDeviceName + 1];\n} RASDEVINFOW, *LPRASDEVINFOW;")
    vendor.within("ras.h", "RASAMBA's szNetBiosError is wide on CE", "typedef struct tagRASAMBA {", "} RASAMBA",
                  "    CHAR szNetBiosError[NETBIOS_NAME_LEN + 1];",
                  "#ifdef _WIN32_WCE\n    WCHAR szNetBiosError[NETBIOS_NAME_LEN + 1];\n#else\n    CHAR szNetBiosError[NETBIOS_NAME_LEN + 1];\n#endif")
    vendor.ce("msacm.h", "ACMFORMATDETAILS_FORMAT_CHARS is 128 on CE", "#define ACMFORMATDETAILS_FORMAT_CHARS 256",
              "#define ACMFORMATDETAILS_FORMAT_CHARS 128")
    vendor.ce("msacm.h", "ACMFORMATTAGDETAILS_FORMATTAG_CHARS is 48 on CE", "#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 256",
              "#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 48")
    vendor.ce("msacm.h", "ACMDRIVERDETAILS_FEATURES_CHARS is 512 on CE", "#define ACMDRIVERDETAILS_FEATURES_CHARS 256",
              "#define ACMDRIVERDETAILS_FEATURES_CHARS 512")
    vendor.versions("winsock.h", "AF_MAX is 23 on CE 1.0 and 24 on CE 2.0", "#define AF_MAX\t33", "#define AF_MAX\t23", "#define AF_MAX\t24")
    vendor.ce("winsock.h", "IOCPARM_MASK is 0x7ff on CE", "#define IOCPARM_MASK\t0x7f", "#define IOCPARM_MASK\t0x7ff")
    vendor.ce("winsock.h", "IPPROTO_GGP is 2 on CE", "#define IPPROTO_GGP 3", "#define IPPROTO_GGP 2")
    vendor.before_ce3("winnls.h", "CTRY_CZECH is 42 on CE 1.0 and 2.0", "#define CTRY_CZECH 420", "#define CTRY_CZECH 42")
    vendor.before_ce3("winnls.h", "CTRY_SLOVAK is 42 on CE 1.0 and 2.0", "#define CTRY_SLOVAK 421", "#define CTRY_SLOVAK 42")
    vendor.ce("winuser.h", "DLGWINDOWEXTRA is 32 on CE", "#define DLGWINDOWEXTRA 30", "#define DLGWINDOWEXTRA 32")
    vendor.before_ce3("winuser.h", "WM_MOUSELAST is WM_MBUTTONDBLCLK on CE 1.0 and 2.0", "#define WM_MOUSELAST 522", "#define WM_MOUSELAST 521")
    vendor.ce("winuser.h", "QS_ALLEVENTS and QS_ALLINPUT have CE's QS_ bits", "#define QS_ALLEVENTS 191\n#define QS_ALLINPUT 255",
              "#define QS_ALLEVENTS 63\n#define QS_ALLINPUT 127")
    vendor.ce("winuser.h", "SW_MAX is 10 on CE", "#define SW_MAX 11", "#define SW_MAX 10")
    vendor.ce("winuser.h", "WS_OVERLAPPED has a border and caption on CE", "#define WS_OVERLAPPED\t0", "#define WS_OVERLAPPED\t(WS_BORDER|WS_CAPTION)")
    vendor.ce("winuser.h", "ACCEL has a pad word on CE", "\tWORD cmd;\n} ACCEL,*LPACCEL;", "\tWORD cmd;\n\tWORD pad;\n} ACCEL,*LPACCEL;")
    vendor.edit("winuser.h", "INPUT and its parts are declared on CE", "#if (_WIN32_WINNT >= 0x0403)\ntypedef struct tagMOUSEINPUT {",
                "#if (_WIN32_WINNT >= 0x0403) || defined(_WIN32_WCE)\ntypedef struct tagMOUSEINPUT {")
    vendor.edit("winuser.h", "SendInput is declared on CE", "#if (_WIN32_WINNT >= 0x0403)\nWINUSERAPI UINT WINAPI SendInput(UINT,LPINPUT,int);",
                "#if (_WIN32_WINNT >= 0x0403) || defined(_WIN32_WCE)\nWINUSERAPI UINT WINAPI SendInput(UINT,LPINPUT,int);")
    vendor.ce("winuser.h", "HARDWAREINPUT has dwExtraInfo on CE", "  WORD wParamH;\n} HARDWAREINPUT,*PHARDWAREINPUT;",
              "  WORD wParamH;\n  DWORD dwExtraInfo;\n} HARDWAREINPUT,*PHARDWAREINPUT;")
    vendor.ce("mmsystem.h", "MAXERRORLENGTH is 128 on CE", "#define MAXERRORLENGTH 256", "#define MAXERRORLENGTH 128")
    vendor.edit("mmsystem.h", "PATCHARRAY and KEYARRAY aren't declared on CE", "typedef WORD PATCHARRAY[MIDIPATCHSIZE];\ntypedef WORD *LPPATCHARRAY;\ntypedef WORD KEYARRAY[MIDIPATCHSIZE];\ntypedef WORD *LPKEYARRAY;",
                "#ifndef _WIN32_WCE\ntypedef WORD PATCHARRAY[MIDIPATCHSIZE];\ntypedef WORD *LPPATCHARRAY;\ntypedef WORD KEYARRAY[MIDIPATCHSIZE];\ntypedef WORD *LPKEYARRAY;\n#endif")
    vendor.edit("wingdi.h", "GetTextExtentPointW and GetTextExtentPoint32W are macros on CE 1.0 too",
                "#elif (_WIN32_WCE >= 0x200)\n#define GetTextExtentPointW(hdc,cstr,len,size)", "#else\n#define GetTextExtentPointW(hdc,cstr,len,size)")
    vendor.ce("winnetwk.h", "RESOURCEUSAGE_ALL has no RESOURCEUSAGE_ATTACHED on CE",
              "#define RESOURCEUSAGE_ALL           (RESOURCEUSAGE_CONNECTABLE | RESOURCEUSAGE_CONTAINER | RESOURCEUSAGE_ATTACHED)",
              "#define RESOURCEUSAGE_ALL           (RESOURCEUSAGE_CONNECTABLE | RESOURCEUSAGE_CONTAINER)")
    vendor.before_ce3("winnt.h", "REG_LEGAL_OPTION is 7 on CE 1.0 and 2.0", "#define REG_LEGAL_OPTION\t15", "#define REG_LEGAL_OPTION\t7")
    vendor.ce("tlhelp32.h", "Heap32First takes the snapshot handle on CE", "BOOL WINAPI Heap32First(LPHEAPENTRY32,DWORD,DWORD);",
              "BOOL WINAPI Heap32First(HANDLE,LPHEAPENTRY32,DWORD,DWORD);")
    vendor.ce("tlhelp32.h", "Heap32Next takes the snapshot handle on CE", "BOOL WINAPI Heap32Next(LPHEAPENTRY32);",
              "BOOL WINAPI Heap32Next(HANDLE,LPHEAPENTRY32);")
    vendor.ce("winnt.h", "SH3 CONTEXT has CE's exception fields and the CE 1.0, 1.01 or 2.0 union after Psr", SH3_CONTEXT_TAIL, CE_SH3_CONTEXT_TAIL)
    vendor.edit("winnt.h", "x86 CONTEXT has no ExtendedRegisters on CE", "\tBYTE\tExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION];\n",
                "#ifndef _WIN32_WCE\n\tBYTE\tExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION];\n#endif\n")
    vendor.edit("winnt.h", "x86 FLOATING_SAVE_AREA has a pointer type, PFLOATING_SAVE_AREA", "} FLOATING_SAVE_AREA;", "} FLOATING_SAVE_AREA,*PFLOATING_SAVE_AREA;")
    vendor.edit("excpt.h", "x86 DISPATCHER_CONTEXT is CE's registration pointer and ControlPc", X86_DISPATCHER_CONTEXT,
                "#if defined(_WIN32_WCE) && defined(_X86_)\n%s\n#else\n%s\n#endif" % (CE_X86_DISPATCHER_CONTEXT, X86_DISPATCHER_CONTEXT))
    vendor.edit("wingdi.h", "DEVMODEW has no dmDisplayOrientation on CE 1.0 and 2.0", "  DWORD  dmDisplayFrequency; \n  DWORD  dmDisplayOrientation;\n} DEVMODEW",
                "  DWORD  dmDisplayFrequency; \n#ifndef _WIN32_WCE\n  DWORD  dmDisplayOrientation;\n#endif\n} DEVMODEW")
    vendor.ce("commctrl.h", "TB_SETTOOLTIPS is WM_USER+81 on CE", "#define TB_SETTOOLTIPS\t(WM_USER+36)", "#define TB_SETTOOLTIPS\t(WM_USER+81)")
    vendor.ce("commctrl.h", "RB_GETBANDINFO is RB_GETBANDINFOW (WM_USER+28) on CE", "#define RB_GETBANDINFO (WM_USER+5)",
              "#define RB_GETBANDINFO (WM_USER+28)")
    vendor.ce2("commctrl.h", "TB_INSERTBUTTON and TB_ADDBUTTONS are the W messages on CE 2.0",
               "#define TB_ADDBUTTONS\t(WM_USER+20)\n#define TB_INSERTBUTTON\t(WM_USER+21)",
               "#define TB_ADDBUTTONS\t(WM_USER+68)\n#define TB_INSERTBUTTON\t(WM_USER+67)")
    vendor.edit("commctrl.h", "DTM_SETFORMATW is DTM_FIRST+50 (w32api had 0x1050)", "#define DTM_SETFORMATW 0x1050", "#define DTM_SETFORMATW 0x1032")
    vendor.ce1("commctrl.h", "CDRF_SKIPDEFAULT is 1 on CE 1.0", "#define CDRF_SKIPDEFAULT 0x04", "#define CDRF_SKIPDEFAULT 0x01")
    vendor.ce1("commctrl.h", "DTN_LAST is -769 on CE 1.0", "#define DTN_LAST\t((UINT)-799)", "#define DTN_LAST\t((UINT)-769)")
    vendor.ce2("commctrl.h", "MCS_NOTODAY is 0x10 on CE 2.0", "#define MCS_NOTODAY\t0x0008", "#define MCS_NOTODAY\t0x0010")
    vendor.edit("commctrl.h", "NMCUSTOMDRAW has no lItemlParam on CE 1.0", "    LPARAM   lItemlParam;\n} NMCUSTOMDRAW",
                "#if !defined(_WIN32_WCE) || GRIMACE_CE >= 2\n    LPARAM   lItemlParam;\n#endif\n} NMCUSTOMDRAW")
    vendor.edit("commctrl.h", "NMLVCUSTOMDRAW has iSubItem on CE 2.0", "    COLORREF     clrTextBk;\n#if _WIN32_IE >= 0x0400\n    int          iSubItem;",
                "    COLORREF     clrTextBk;\n#if _WIN32_IE >= 0x0400 || (defined(_WIN32_WCE) && GRIMACE_CE >= 2)\n    int          iSubItem;")
    vendor.within("commctrl.h", "REBARBANDINFOW has the IE 4.0 fields on CE 2.0", "typedef struct tagREBARBANDINFOW {", "} REBARBANDINFOW",
                  "#if (_WIN32_IE >= 0x0400)", "#if (_WIN32_IE >= 0x0400) || (defined(_WIN32_WCE) && GRIMACE_CE >= 2)")
    for structure in ("PROPSHEETPAGEA", "PROPSHEETPAGEW", "PROPSHEETHEADERA", "PROPSHEETHEADERW"):
        vendor.within("prsht.h", "%s has no IE 4.0 fields on CE" % structure, "typedef struct _%s {" % structure, "} %s," % structure,
                      "#if (_WIN32_IE >= 0x0400)", "#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)")
    for letter in ("A", "W"):
        vendor.within("commctrl.h", "TVINSERTSTRUCT%s has no itemex on CE" % letter, "typedef struct tagTVINSERTSTRUCT%s {" % letter,
                      "} TVINSERTSTRUCT%s" % letter, "#if (_WIN32_IE >= 0x0400)", "#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)")
    vendor.within("commctrl.h", "NMTVCUSTOMDRAW has no iLevel on CE", "typedef struct tagNMTVCUSTOMDRAW {", "} NMTVCUSTOMDRAW",
                  "#if _WIN32_IE >= 0x0400", "#if _WIN32_IE >= 0x0400 && !defined(_WIN32_WCE)")
    vendor.ce("commctrl.h", "NMMOUSE has no dwHitInfo on CE", "\tPOINT pt;\n\tLPARAM dwHitInfo;\n} NMMOUSE, *LPNMMOUSE;",
              "\tPOINT pt;\n} NMMOUSE, *LPNMMOUSE;")
    vendor.ce("commctrl.h", "NMREBAR is CE's layout", "typedef struct tagNMREBAR {\n\tNMHDR hdr;\n\tDWORD dwMask;\n\tUINT uBand;\n\tUINT fStyle;\n\tUINT wID;\n\tLPARAM lParam;\n} NMREBAR,*LPNMREBAR;",
              "typedef struct tagNMREBAR {\n\tNMHDR hdr;\n\tUINT uBand;\n\tUINT wID;\n\tUINT cyChild;\n\tUINT cyBand;\n} NMREBAR,*LPNMREBAR;")
    for note, start, end in (("TB_SETBUTTONWIDTH is WM_USER+52 on CE 1.01", "#define TB_GETBUTTONTEXTW", "#if (_WIN32_IE >= 0x0300)"),
                             ("TB_SETBUTTONWIDTH's IE 3.0 definition too", "#define TB_GETSTYLE", "#define TB_SETMAXTEXTROWS")):
        vendor.within("commctrl.h", note, start, end, "#define TB_SETBUTTONWIDTH\t(WM_USER+59)\n",
                      "#if defined(_WIN32_WCE) && GRIMACE_WCE == 101\n#define TB_SETBUTTONWIDTH\t(WM_USER+52)\n#else\n"
                      "#define TB_SETBUTTONWIDTH\t(WM_USER+59)\n#endif\n")
    vendor.ce("commctrl.h", "SBN_LAST is -900 on CE", "#define SBN_LAST\t((UINT)-899U)", "#define SBN_LAST\t((UINT)-900U)")
    path = os.path.join(DESTINATION, "commdlg.h")
    text = open(path).read()
    flags = text[text.index("#define PD_ALLPAGES"):text.index("#define PD_RESULT_CANCEL")]
    vendor.ce("commdlg.h", "PD_ flags are CE's", flags.rstrip("\n"), CE_PRINT_DIALOG_FLAGS)
    text = open(path).read()
    structure = text[text.index("typedef struct tagPDW {"):text.index("} PRINTDLGW,*LPPRINTDLGW;") + len("} PRINTDLGW,*LPPRINTDLGW;")]
    vendor.ce("commdlg.h", "PRINTDLGW is CE's print dialog structure", structure, CE_PRINT_DIALOG)
    for name, value in (("GMEM_DDESHARE", "0"), ("GMEM_DISCARDABLE", "0xF00"), ("GMEM_LOWER", "0"), ("GMEM_NOT_BANKED", "0"), ("GMEM_NOTIFY", "0"),
                        ("GMEM_SHARE", "0")):
        original = next(line for line in open(os.path.join(DESTINATION, "winbase.h")).read().splitlines() if line.startswith("#define %s " % name))
        vendor.ce3("winbase.h", "%s is %s on CE 3.0" % (name, value), original, "#define %s %s" % (name, value))
    vendor.ce3("winnt.h", "FILE_ATTRIBUTE_ENCRYPTED is 0x40 on CE 3.0", "#define FILE_ATTRIBUTE_ENCRYPTED\t\t0x00004000",
               "#define FILE_ATTRIBUTE_ENCRYPTED\t\t0x00000040")
    vendor.ce3("winnt.h", "HEAP_CREATE_ALIGN_16 is 0x10000 on CE 3.0", "#define HEAP_CREATE_ALIGN_16 0x0000", "#define HEAP_CREATE_ALIGN_16 0x00010000")
    vendor.ce3("winnt.h", "HEAP_TAG_SHIFT is 18 on CE 3.0", "#define HEAP_TAG_SHIFT 16", "#define HEAP_TAG_SHIFT 18")
    vendor.ce3("winnt.h", "IMAGE_SYM_CLASS_END_OF_FUNCTION is a BYTE on CE 3.0", "#define IMAGE_SYM_CLASS_END_OF_FUNCTION\t(-1)",
               "#define IMAGE_SYM_CLASS_END_OF_FUNCTION\t((BYTE)-1)")
    path = os.path.join(DESTINATION, "winnt.h")
    text = open(path).read()
    token_all_access = text[text.index("#define TOKEN_ALL_ACCESS ("):text.index("TOKEN_ADJUST_DEFAULT)", text.index("#define TOKEN_ALL_ACCESS (")) + len("TOKEN_ADJUST_DEFAULT)")]
    vendor.ce3("winnt.h", "TOKEN_ALL_ACCESS includes TOKEN_ADJUST_SESSIONID on CE 3.0", token_all_access,
               "#define TOKEN_ADJUST_SESSIONID 256\n" + token_all_access.replace("TOKEN_ADJUST_DEFAULT)", "TOKEN_ADJUST_SESSIONID   |\\\n                          TOKEN_ADJUST_DEFAULT)"))
    vendor.edit("winnt.h", "ARM CONTEXT has no floating point registers, as on CE 3.0",
                "#define CONTEXT_FLOATING_POINT  (CONTEXT_ARM | 0x00000004L)\n\n#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)\n",
                "\n#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER)\n")
    vendor.edit("winnt.h", "ARM CONTEXT ends at Psr", "\tULONG Psr;\n#define NUM_VFP_REGS            32\n#define NUM_EXTRA_CONTROL_REGS  8\n\t/* Floating point registers */\n"
                "\tULONG Fpscr;\n\tULONG FpExc;\n\tULONG S[NUM_VFP_REGS+1];\n\tULONG FpExtra[NUM_EXTRA_CONTROL_REGS];\n} CONTEXT;", "\tULONG Psr;\n} CONTEXT;")
    for name, value, ce3_value in (("WS_MAXIMIZEBOX", "0x10000", "0x20000"), ("WS_MINIMIZEBOX", "0x20000", "0x10000"), ("DFCS_CAPTIONMIN", "1", "0x20"),
                                   ("DFCS_CAPTIONMAX", "2", "0x40"), ("DFCS_CAPTIONRESTORE", "3", "0x800")):
        vendor.ce3("winuser.h", "%s is %s on CE 3.0" % (name, ce3_value), "#define %s\t%s" % (name, value), "#define %s\t%s" % (name, ce3_value))
    for name, value, ce3_value in (("IDC_ICON", "MAKEINTRESOURCE(32641)", "MAKEINTRESOURCE(32512)"), ("IDC_SIZE", "MAKEINTRESOURCE(32640)", "MAKEINTRESOURCE(32646)"),
                                   ("SW_MAXIMIZE", "3", "12"), ("SW_SHOWMAXIMIZED", "3", "11"), ("SW_RESTORE", "9", "13")):
        vendor.ce3("winuser.h", "%s is %s on CE 3.0" % (name, ce3_value), "#define %s %s" % (name, value), "#define %s %s" % (name, ce3_value))
    vendor.ce3("imm.h", "IMFS_GRAYED is MF_GRAYED on CE 3.0", "#define IMFS_GRAYED MFS_GRAYED", "#define IMFS_GRAYED MF_GRAYED")
    vendor.edit("winuser.h", "IsDlgButtonChecked returns the button's state", "\tSendDlgItemMessageW(h, i, BM_GETCHECK, (WPARAM)(0), 0);",
                "\treturn SendDlgItemMessageW(h, i, BM_GETCHECK, (WPARAM)(0), 0);")


def write_notes(vendor, source):
    lines = [
        "# w32api",
        "",
        "These headers are from CeGCC's w32api (MinGW's Win32 API headers with Windows CE support), as in",
        "https://github.com/Gadgetoid/cegcc-build at 221c9c0, `w32api/include`. They're public domain: see `README.w32api`.",
        "",
        "`tools/vendor-w32api.py` copies them from a CeGCC checkout and applies the patches below, so they match the",
        "Windows CE 1.0, 2.0 and 3.0 (Handheld PC 2000) SDK headers where `tests/check-headers.py` found a difference.",
        "grimace's own headers in `include/` configure and include them, and mark what each target doesn't export.",
        "",
        "`WINVER` stays 0x400 (the CE 3.0 SDK has 0x500), since w32api enables desktop declarations above it.",
        "",
        "Not patched: ANSI (`A`) structures that differ from the SDK's, such as `WIN32_FIND_DATAA` and `REBARBANDINFOA`.",
        "Windows CE has few ANSI functions, and the declarations of those a target lacks are marked unavailable.",
        "",
        "## Patches",
        "",
    ]
    for header, note in vendor.notes:
        lines.append("- `%s`: %s" % (header, note))
    open(os.path.join(DESTINATION, "VENDOR.md"), "w").write("\n".join(lines) + "\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Copy CeGCC's w32api headers into include/w32api and patch them for CE 1.0, 2.0 and 3.0")
    parser.add_argument("source", help="CeGCC's w32api folder (containing include/ and README.w32api)")
    arguments = parser.parse_args()
    for header in HEADERS:
        shutil.copyfile(os.path.join(arguments.source, "include", header), os.path.join(DESTINATION, header))
    shutil.copyfile(os.path.join(arguments.source, "README.w32api"), os.path.join(DESTINATION, "README.w32api"))
    vendor = Vendor()
    patch(vendor)
    write_notes(vendor, arguments.source)
    print("vendor-w32api: %d headers, %d patches" % (len(HEADERS), len(vendor.notes)))

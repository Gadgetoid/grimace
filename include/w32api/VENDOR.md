# w32api

These headers are from CeGCC's w32api (MinGW's Win32 API headers with Windows CE support), as in
https://github.com/Gadgetoid/cegcc-build at 221c9c0, `w32api/include`. They're public domain: see `README.w32api`.

`tools/vendor-w32api.py` copies them from a CeGCC checkout and applies the patches below, so they match the
Windows CE 1.0, 2.0 and 3.0 (Handheld PC 2000) SDK headers where `tests/check-headers.py` found a difference.
grimace's own headers in `include/` configure and include them, and mark what each target doesn't export.

`WINVER` stays 0x400 (the CE 3.0 SDK has 0x500), since w32api enables desktop declarations above it.

Not patched: ANSI (`A`) structures that differ from the SDK's, such as `WIN32_FIND_DATAA` and `REBARBANDINFOA`.
Windows CE has few ANSI functions, and the declarations of those a target lacks are marked unavailable.

## Patches

- `ras.h`: RAS_MaxEntryName is 20 on CE
- `ras.h`: RAS_MaxDeviceName is 32 on CE
- `ras.h`: RAS_MaxCallbackNumber is 48 on CE
- `ras.h`: RASCONNW has no device or phonebook fields on CE
- `ras.h`: RASCONNW has no phonebook fields on CE
- `ras.h`: RASPPPIPW has no server address on CE
- `ras.h`: RASCONNA has no device or phonebook fields on CE
- `ras.h`: RASCONNA has no phonebook fields on CE
- `ras.h`: RASPPPIPA has no server address on CE
- `ras.h`: RASDEVINFOW's strings are CHAR on CE 1.0 and 2.0
- `ras.h`: RASAMBA's szNetBiosError is wide on CE
- `msacm.h`: ACMFORMATDETAILS_FORMAT_CHARS is 128 on CE
- `msacm.h`: ACMFORMATTAGDETAILS_FORMATTAG_CHARS is 48 on CE
- `msacm.h`: ACMDRIVERDETAILS_FEATURES_CHARS is 512 on CE
- `winsock.h`: AF_MAX is 23 on CE 1.0 and 24 on CE 2.0
- `winsock.h`: IOCPARM_MASK is 0x7ff on CE
- `winsock.h`: IPPROTO_GGP is 2 on CE
- `winnls.h`: CTRY_CZECH is 42 on CE 1.0 and 2.0
- `winnls.h`: CTRY_SLOVAK is 42 on CE 1.0 and 2.0
- `winuser.h`: DLGWINDOWEXTRA is 32 on CE
- `winuser.h`: WM_MOUSELAST is WM_MBUTTONDBLCLK on CE 1.0 and 2.0
- `winuser.h`: QS_ALLEVENTS and QS_ALLINPUT have CE's QS_ bits
- `winuser.h`: SW_MAX is 10 on CE
- `winuser.h`: WS_OVERLAPPED has a border and caption on CE
- `winuser.h`: ACCEL has a pad word on CE
- `winuser.h`: INPUT and its parts are declared on CE
- `winuser.h`: SendInput is declared on CE
- `winuser.h`: HARDWAREINPUT has dwExtraInfo on CE
- `mmsystem.h`: MAXERRORLENGTH is 128 on CE
- `mmsystem.h`: PATCHARRAY and KEYARRAY aren't declared on CE
- `wingdi.h`: GetTextExtentPointW and GetTextExtentPoint32W are macros on CE 1.0 too
- `winnetwk.h`: RESOURCEUSAGE_ALL has no RESOURCEUSAGE_ATTACHED on CE
- `winnt.h`: REG_LEGAL_OPTION is 7 on CE 1.0 and 2.0
- `tlhelp32.h`: Heap32First takes the snapshot handle on CE
- `tlhelp32.h`: Heap32Next takes the snapshot handle on CE
- `winbase.h`: GetIdleTime is declared on CE
- `winnt.h`: SH3 CONTEXT has CE's exception fields and the CE 1.0, 1.01 or 2.0 union after Psr
- `winnt.h`: x86 CONTEXT has no ExtendedRegisters on CE
- `winnt.h`: x86 FLOATING_SAVE_AREA has a pointer type, PFLOATING_SAVE_AREA
- `excpt.h`: x86 DISPATCHER_CONTEXT is CE's registration pointer and ControlPc
- `wingdi.h`: DEVMODEW has no dmDisplayOrientation on CE 1.0 and 2.0
- `commctrl.h`: TB_SETTOOLTIPS is WM_USER+81 on CE
- `commctrl.h`: RB_GETBANDINFO is RB_GETBANDINFOW (WM_USER+28) on CE
- `commctrl.h`: TB_INSERTBUTTON and TB_ADDBUTTONS are the W messages on CE 2.0
- `commctrl.h`: DTM_SETFORMATW is DTM_FIRST+50 (w32api had 0x1050)
- `commctrl.h`: CDRF_SKIPDEFAULT is 1 on CE 1.0
- `commctrl.h`: DTN_LAST is -769 on CE 1.0
- `commctrl.h`: MCS_NOTODAY is 0x10 on CE 2.0
- `commctrl.h`: NMCUSTOMDRAW has no lItemlParam on CE 1.0
- `commctrl.h`: NMLVCUSTOMDRAW has iSubItem on CE 2.0
- `commctrl.h`: REBARBANDINFOW has the IE 4.0 fields on CE 2.0
- `prsht.h`: PROPSHEETPAGEA has no IE 4.0 fields on CE
- `prsht.h`: PROPSHEETPAGEW has no IE 4.0 fields on CE
- `prsht.h`: PROPSHEETHEADERA has no IE 4.0 fields on CE
- `prsht.h`: PROPSHEETHEADERW has no IE 4.0 fields on CE
- `commctrl.h`: TVINSERTSTRUCTA has no itemex on CE
- `commctrl.h`: TVINSERTSTRUCTW has no itemex on CE
- `commctrl.h`: NMTVCUSTOMDRAW has no iLevel on CE
- `commctrl.h`: NMMOUSE has no dwHitInfo on CE
- `commctrl.h`: NMREBAR is CE's layout
- `commctrl.h`: TB_SETBUTTONWIDTH is WM_USER+52 on CE 1.01
- `commctrl.h`: TB_SETBUTTONWIDTH's IE 3.0 definition too
- `commctrl.h`: SBN_LAST is -900 on CE
- `commdlg.h`: PD_ flags are CE's
- `commdlg.h`: PRINTDLGW is CE's print dialog structure
- `winbase.h`: GMEM_DDESHARE is 0 on CE 3.0
- `winbase.h`: GMEM_DISCARDABLE is 0xF00 on CE 3.0
- `winbase.h`: GMEM_LOWER is 0 on CE 3.0
- `winbase.h`: GMEM_NOT_BANKED is 0 on CE 3.0
- `winbase.h`: GMEM_NOTIFY is 0 on CE 3.0
- `winbase.h`: GMEM_SHARE is 0 on CE 3.0
- `winnt.h`: FILE_ATTRIBUTE_ENCRYPTED is 0x40 on CE 3.0
- `winnt.h`: HEAP_CREATE_ALIGN_16 is 0x10000 on CE 3.0
- `winnt.h`: HEAP_TAG_SHIFT is 18 on CE 3.0
- `winnt.h`: IMAGE_SYM_CLASS_END_OF_FUNCTION is a BYTE on CE 3.0
- `winnt.h`: TOKEN_ALL_ACCESS includes TOKEN_ADJUST_SESSIONID on CE 3.0
- `winnt.h`: ARM CONTEXT has no floating point registers, as on CE 3.0
- `winnt.h`: ARM CONTEXT ends at Psr
- `winuser.h`: WS_MAXIMIZEBOX is 0x20000 on CE 3.0
- `winuser.h`: WS_MINIMIZEBOX is 0x10000 on CE 3.0
- `winuser.h`: DFCS_CAPTIONMIN is 0x20 on CE 3.0
- `winuser.h`: DFCS_CAPTIONMAX is 0x40 on CE 3.0
- `winuser.h`: DFCS_CAPTIONRESTORE is 0x800 on CE 3.0
- `winuser.h`: IDC_ICON is MAKEINTRESOURCE(32512) on CE 3.0
- `winuser.h`: IDC_SIZE is MAKEINTRESOURCE(32646) on CE 3.0
- `winuser.h`: SW_MAXIMIZE is 12 on CE 3.0
- `winuser.h`: SW_SHOWMAXIMIZED is 11 on CE 3.0
- `winuser.h`: SW_RESTORE is 13 on CE 3.0
- `imm.h`: IMFS_GRAYED is MF_GRAYED on CE 3.0
- `winuser.h`: IsDlgButtonChecked returns the button's state

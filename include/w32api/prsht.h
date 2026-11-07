#ifndef _PRSHT_H
#define _PRSHT_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif /* ifndef SNDMSG */

#ifndef POSTMSG
#ifdef __cplusplus
#define POSTMSG ::PostMessage
#else
#define POSTMSG PostMessage
#endif
#endif /* ifndef POSTMSG */

#ifdef __cplusplus
extern "C" {
#endif

#define MAXPROPPAGES	100
#define PSP_DEFAULT	0
#define PSP_DLGINDIRECT	1
#define PSP_USEHICON	2
#define PSP_USEICONID	4
#define PSP_USETITLE	8
#define PSP_RTLREADING	16
#define PSP_HASHELP	32
#define PSP_USEREFPARENT	64
#define PSP_USECALLBACK	128
#define PSP_PREMATURE	1024
#if (_WIN32_IE >= 0x0400)
#define PSP_HIDEHEADER	2048
#define PSP_USEHEADERTITLE	4096
#define PSP_USEHEADERSUBTITLE	8192
#endif
#define PSPCB_RELEASE	1
#define PSPCB_CREATE	2
#define PSH_DEFAULT	0
#define PSH_PROPTITLE	1
#define PSH_USEHICON	2
#define PSH_USEICONID	4
#define PSH_PROPSHEETPAGE	8
#define PSH_WIZARDHASFINISH	16
#define PSH_WIZARD	32
#define PSH_USEPSTARTPAGE	64
#define PSH_NOAPPLYNOW	128
#define PSH_USECALLBACK	256
#define PSH_HASHELP	512
#define PSH_MODELESS	1024
#define PSH_RTLREADING	2048
#define PSH_WIZARDCONTEXTHELP	4096
#ifdef _WIN32_WCE
#define PSH_MAXIMIZE	8192
#endif
#if (_WIN32_IE >= 0x0400)
#define PSH_WATERMARK	32768
#define PSH_USEHBMWATERMARK	65536
#define PSH_USEHPLWATERMARK	131072
#define PSH_STRETCHWATERMARK	262144
#define PSH_HEADER	524288
#define PSH_USEHBMHEADER	1048576
#define PSH_USEPAGELANG	2097152
#if (_WIN32_IE < 0x0500)
#define PSH_WIZARD97	0x00002000
#else
#define PSH_WIZARD97	0x01000000
#endif
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_IE >= 0x0500)
#define PSH_WIZARD_LITE	0x400000
#define PSH_NOCONTEXTHELP	0x2000000
#endif
#define PSCB_INITIALIZED	1
#define PSCB_PRECREATE	2
#ifdef _WIN32_WCE
/*googling*/
#define PSCB_GETVERSION 3
#endif
/**
 * This message retrieves the handle of the tab control of a property
 * sheet. You can send this message explicitly or by using the
 * PropSheet_GetTabControl macro.
 *
 * @return Returns the handle to the tab control.
 */
#define PSM_GETTABCONTROL	1140
/**
 * This message retrieves a handle to the window of the current page of a
 * property sheet. You can send this message explicitly or by using the
 * PropSheet_GetCurrentPageHwnd macro.
 *
 * @return Returns a handle to the window of the current property sheet
 *        page. Use the PSM_GETCURRENTPAGEHWND message with modeless
 *        property sheets to determine when to destroy the dialog box. When
 *        the user clicks the OK or Cancel button, PSM_GETCURRENTPAGEHWND
 *        returns NULL, and you can then use the DestroyWindow function to
 *        destroy the dialog box.
 */
#define PSM_GETCURRENTPAGEHWND	1142
/**
 * This message passes a message to a property sheet dialog box and
 * indicates whether the dialog processed the message. You can send this
 * message explicitly or by using the PropSheet_IsDialogMessage macro.
 *
 * Your message loop should use the PSM_ISDIALOGMESSAGE message with
 * modeless property sheets to pass messages to the property sheet dialog
 * box.
 *
 * If the return value indicates that the message was processed, it must
 * not be passed to the DispatchMessage function.
 *
 * @param pMsg Pointer to an MSG structure that contains the message to be
 *        checked.
 * @return TRUE indicates that the message has been processed. FALSE
 *        indicates that the message has not been processed.
 */
#define PSM_ISDIALOGMESSAGE	1141
/**
 * This message simulates the choice of a property sheet button. You can
 * send this message explicitly or by using the PropSheet_PressButton
 * macro.
 *
 * @param iButton Index of the button to select. It is one of the following
 *        values: Value Description PSBTN_APPLYNOW Selects the Apply Now
 *        button. PSBTN_BACK Selects the Back button. PSBTN_CANCEL Selects
 *        the Cancel button. PSBTN_FINISH Selects the Finish button.
 *        PSBTN_HELP Selects the Help button. PSBTN_NEXT Selects the Next
 *        button. PSBTN_OK Selects the OK button.
 * @return None.
 */
#define PSM_PRESSBUTTON	1137
/**
 * This message activates the specified page in a property sheet based on
 * the resource identifier of the page. You can send this message
 * explicitly or by using the PropSheet_SetCurSelByID macro.
 *
 * @param id Resource identifier of the page to activate.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define PSM_SETCURSELID	1138
#define PSM_SETFINISHTEXTW	1145
#define PSM_SETFINISHTEXTA	1139
#define PSN_FIRST	(-200)
#define PSN_LAST	(-299)
/**
 * This notification message indicates that the user chose the OK or Apply
 * Now button and wants all changes to take effect. It is sent in the form
 * of a WM_NOTIFY message.
 *
 * To set the return value, the dialog box procedure for the page must use
 * the SetWindowLong function with the DWL_MSGRESULT value, and the dialog
 * box procedure must return TRUE.
 *
 * A page should not call the EndDialog function when processing this
 * notification message.
 *
 * The property sheet is destroyed if the user clicks the OK button and the
 * application returns the PSNRET_NOERROR value in response to this
 * notification.
 *
 * To receive this notification, a page must set the DWL_MSGRESULT value to
 * FALSE in response the PSN_KILLACTIVE notification message.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. The lParam member of this
 *        structure does not contain any information. The hwndFrom member
 *        of the hdr member of this structure contains the handle to the
 *        property sheet.
 * @return Returns the PSNRET_INVALID_NOCHANGEPAGE value to prevent the
 *        changes from taking effect and to return the focus to the page,
 *        or the PSNRET_NOERROR value to accept the changes and allow the
 *        property sheet to be destroyed.
 */
#define PSN_APPLY	(-202)
/**
 * This notification message notifies a page that the user has chosen the
 * Help button. It is sent in the form of a WM_NOTIFY message.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. The lParam member of this
 *        structure does not contain any information. The hwndFrom member
 *        of the hdr member of this structure contains the handle to the
 *        property sheet.
 * @return None.
 */
#define PSN_HELP	(-205)
/**
 * This notification message notifies a page that it is about to lose the
 * activation either because another page is being activated or the user
 * has chosen the OK button. It is sent in the form of a WM_NOTIFY message.
 *
 * An application should validate the information the user has typed.
 *
 * To set the return value, the dialog box procedure for the page must use
 * the SetWindowLong function with the DWL_MSGRESULT value, and the dialog
 * box procedure must return TRUE.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. The lParam member of this
 *        structure does not contain any information. The hwndFrom member
 *        of the hdr member of this structure contains the handle to the
 *        property sheet.
 * @return TRUE to prevents the page from losing the activation. FALSE
 *        allows the page to lose activation.
 */
#define PSN_KILLACTIVE	(-201)
/**
 * This notification message indicates that the user chose the Cancel
 * button. It is sent in the form of a WM_NOTIFY message.
 *
 * A property sheet page can use this notification message to ask the user
 * to verify the cancel operation.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. The lParam member of this
 *        structure does not contain any information. The i member of the
 *        hdr member of this structure contains the handle to the property
 *        sheet.
 * @return TRUE prevents the cancel operation. FALSE allows the cancel
 *        operation.
 */
#define PSN_QUERYCANCEL	(-209)
/**
 * This notification message notifies a page that the user has chosen the
 * Cancel button and the property sheet is about to be destroyed. All
 * changes made since the user last chose the Apply Now button are
 * canceled. It is sent in the form of a WM_NOTIFY message.
 *
 * An application can use this notification message as an opportunity to
 * perform cleanup operations.
 *
 * A page should not call the EndDialog function when processing this
 * notification message.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. If this notification is in
 *        response to the Close button being pressed, the lParam member of
 *        this structure will contain a non-zero value. If this
 *        notification is in response to the Cancel button being pressed,
 *        the lParam member of this structure will contain zero. The
 *        hwndFrom member of the hdr member of this structure contains the
 *        handle to the property sheet.
 * @return None.
 */
#define PSN_RESET	(-203)
/**
 * This notification message notifies a page that it is about to be
 * activated. It is sent in the form of a WM_NOTIFY message.
 *
 * The PSN_SETACTIVE notification message is sent before the page is
 * visible. An application can use this notification to initialize data in
 * the page.
 *
 * To set the return value, the dialog box procedure for the page must use
 * the SetWindowLong function with the DWL_MSGRESULT value, and the dialog
 * box procedure must return TRUE.
 *
 * @param lppsn Long pointer to a PSHNOTIFY structure that contains
 *        information about the notification. The lParam member of this
 *        structure does not contain any information. The hwndFrom member
 *        of the hdr member of this structure contains the handle to the
 *        property sheet.
 * @return Returns zero to accept the activation, or -1 to activate the
 *        next or the previous page (depending on whether the user clicked
 *        the Next or Back button). To set the activation to a particular
 *        page, return the resource identifier of the page.
 */
#define PSN_SETACTIVE	(-200)
#define PSN_WIZBACK	(-206)
#define PSN_WIZFINISH	(-208)
#define PSN_WIZNEXT	(-207)
#define PSNRET_NOERROR	0
#define PSNRET_INVALID	1
#define PSNRET_INVALID_NOCHANGEPAGE	2
#define ID_PSRESTARTWINDOWS	2
#define ID_PSREBOOTSYSTEM 	3
#define WIZ_CXDLG	276
#define WIZ_CYDLG	140
#define WIZ_CXBMP	80
#define WIZ_BODYX	92
#define WIZ_BODYCX	184
#define PROP_SM_CXDLG	212
#define PROP_SM_CYDLG	188
#define PROP_MED_CXDLG	227
#define PROP_MED_CYDLG	215
#define PROP_LG_CXDLG	252
#define PROP_LG_CYDLG	218
#define PSBTN_MAX	6
#define PSBTN_BACK	0
#define PSBTN_NEXT	1
#define PSBTN_FINISH	2
#define PSBTN_OK	3
#define PSBTN_APPLYNOW	4
#define PSBTN_CANCEL	5
#define PSBTN_HELP	6
#define PSWIZB_BACK	1
#define PSWIZB_NEXT	2
#define PSWIZB_FINISH	4
#define PSWIZB_DISABLEDFINISH	8
#define PSM_SETWIZBUTTONS	(WM_USER+112)
/**
 * This message simulates the choice of the Apply Now button, indicating
 * that one or more pages have changed and the changes need to be validated
 * and recorded.
 *
 * The property sheet sends the PSN_KILLACTIVE notification message to the
 * current page. If the current page returns FALSE, the property sheet
 * sends the PSN_APPLY notification message to all pages. You can send the
 * PSM_APPLY message explicitly or by using the PropSheet_Apply macro.
 *
 * @return TRUE indicates that all pages successfully applied the changes.
 *        FALSE indicates failure.
 */
#define PSM_APPLY	(WM_USER+110)
/**
 * This message informs a property sheet that information in a page has
 * reverted to the previously saved state. The property sheet disables the
 * Apply Now button if no other pages have registered changes with the
 * property sheet. You can send this message explicitly or by using the
 * PropSheet_UnChanged macro.
 *
 * @param hwndPage Handle to the page that has reverted to the previously
 *        saved state.
 * @return None.
 */
#define PSM_UNCHANGED	(WM_USER+109)
/**
 * This message is sent to a property sheet, which then forwards the
 * message to each of its pages. If a page returns a nonzero value, the
 * property sheet does not send the message to subsequent pages. You can
 * send this message explicitly or by using the PropSheet_QuerySiblings
 * macro.
 *
 * @param param1 First application-defined parameter.
 * @param param2 Second application-defined parameter.
 * @return Returns the nonzero value from a page in the property sheet, or
 *        zero if no page returns a nonzero value.
 */
#define PSM_QUERYSIBLINGS	(WM_USER+108)
/**
 * This message disables the Cancel button and changes the text of the OK
 * button to "Close." An application sends this message after applying a
 * change that cannot be canceled. You can send this message explicitly or
 * by using the PropSheet_CancelToClose macro.
 *
 * @return None.
 */
#define PSM_CANCELTOCLOSE	(WM_USER+107)
/**
 * This message indicates that system needs to be restarted for the changes
 * to take effect. An application should send this message only in response
 * to the PSN_APPLY or PSN_KILLACTIVE notification message. You can send
 * the PSM_REBOOTSYSTEM message explicitly or by using the
 * PropSheet_RebootSystem macro.
 *
 * This message causes the PropertySheet function to return the
 * ID_PSREBOOTSYSTEM value, but only if the user clicks the OK button to
 * close the property sheet.
 *
 * @return None.
 */
#define PSM_REBOOTSYSTEM	(WM_USER+106)
/**
 * This message indicates that Windows needs to be restarted for the
 * changes to take effect. An application should send this message only in
 * response to the PSN_APPLY or PSN_KILLACTIVE notification message. You
 * can send the PSM_RESTARTWINDOWS message explicitly or by using the
 * PropSheet_RestartWindows macro.
 *
 * @return None.
 */
#define PSM_RESTARTWINDOWS	(WM_USER+105)
/**
 * This message informs a property sheet that information in a page has
 * changed. The property sheet enables the Apply Now button. You can send
 * this message explicitly or by using the PropSheet_Changed macro.
 *
 * @param hwndPage Handle to the page that has changed.
 * @return None.
 */
#define PSM_CHANGED	(WM_USER+104)
/**
 * This message adds a new page to the end of an existing property sheet.
 * You can send this message explicitly or by using the PropSheet_AddPage
 * macro.
 *
 * @param hpage Handle to the page to add. The page must have been created
 *        by a previous call to the CreatePropertySheetPage function.
 * @return None.
 */
#define PSM_ADDPAGE	(WM_USER+103)
/**
 * This message removes a page from a property sheet. You can send this
 * message explicitly or by using the PropSheet_RemovePage macro.
 *
 * An application can specify the index or the handle, or both. If both are
 * specified, hpage takes precedence.
 *
 * @param index Zero-based index of the page to remove.
 * @param hpage Handle of the page to remove.
 * @return None.
 */
#define PSM_REMOVEPAGE	(WM_USER+102)
/**
 * This message activates the specified page in a property sheet. You can
 * send this message explicitly or by using the PropSheet_SetCurSel macro.
 *
 * An application can specify the index or the handle, or both. If both are
 * specified, hpage takes precedence.
 *
 * @param index Zero-based index of the page to activate.
 * @param hpage Handle of the page to activate.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define PSM_SETCURSEL	(WM_USER+101)
#define PSM_SETTITLEA	(WM_USER+111)
#define PSM_SETTITLEW	(WM_USER+120)

#ifndef RC_INVOKED

#pragma pack(push,8)
typedef struct _PROPSHEETPAGEA {
	DWORD	dwSize;
	DWORD	dwFlags;
	HINSTANCE	hInstance;
	_ANONYMOUS_UNION union {
		LPCSTR	pszTemplate;
		LPCDLGTEMPLATE	pResource;
	} DUMMYUNIONNAME;
	_ANONYMOUS_UNION union {
		HICON hIcon;
		LPCSTR pszIcon;
	} DUMMYUNIONNAME2;
	LPCSTR	pszTitle;
	DLGPROC	pfnDlgProc;
	LPARAM	lParam;
	UINT(CALLBACK *pfnCallback)(HWND,UINT,struct _PROPSHEETPAGEA*);
	UINT *pcRefParent;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	LPCSTR pszHeaderTitle;
	LPCSTR pszHeaderSubTitle;
#endif
} PROPSHEETPAGEA,*LPPROPSHEETPAGEA;
typedef const PROPSHEETPAGEA *LPCPROPSHEETPAGEA;
typedef struct _PROPSHEETPAGEW {
	DWORD	dwSize;
	DWORD	dwFlags;
	HINSTANCE	hInstance;
	_ANONYMOUS_UNION union {
		LPCWSTR	pszTemplate;
		LPCDLGTEMPLATE	pResource;
	} DUMMYUNIONNAME;
	_ANONYMOUS_UNION union {
		HICON hIcon;
		LPCWSTR pszIcon;
	} DUMMYUNIONNAME2;
	LPCWSTR	pszTitle;
	DLGPROC	pfnDlgProc;
	LPARAM	lParam;
	UINT(CALLBACK *pfnCallback)(HWND,UINT,struct _PROPSHEETPAGEW*);
	UINT *pcRefParent;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	LPCWSTR pszHeaderTitle;
	LPCWSTR pszHeaderSubTitle;
#endif
} PROPSHEETPAGEW,*LPPROPSHEETPAGEW;
typedef const PROPSHEETPAGEW *LPCPROPSHEETPAGEW;
typedef UINT(CALLBACK *LPFNPSPCALLBACKA)(HWND,UINT,LPPROPSHEETPAGEA);
typedef UINT(CALLBACK *LPFNPSPCALLBACKW)(HWND,UINT,LPPROPSHEETPAGEW);
typedef int(CALLBACK *PFNPROPSHEETCALLBACK)(HWND,UINT,LPARAM);
DECLARE_HANDLE(HPROPSHEETPAGE);
typedef struct _PROPSHEETHEADERA {
	DWORD	dwSize;
	DWORD	dwFlags;
	HWND	hwndParent;
	HINSTANCE	hInstance;
	_ANONYMOUS_UNION union {
		HICON	hIcon;
		LPCSTR	pszIcon;
	}DUMMYUNIONNAME;
	LPCSTR	pszCaption;
	UINT	nPages;
	_ANONYMOUS_UNION union {
		UINT	nStartPage;
		LPCSTR	pStartPage;
	}DUMMYUNIONNAME2;
	_ANONYMOUS_UNION union {
		LPCPROPSHEETPAGEA ppsp;
		HPROPSHEETPAGE *phpage;
	}DUMMYUNIONNAME3;
	PFNPROPSHEETCALLBACK pfnCallback;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	_ANONYMOUS_UNION union {
		HBITMAP hbmWatermark;
		LPCSTR pszbmWatermark;
	} DUMMYUNIONNAME4;
	HPALETTE hplWatermark;
	_ANONYMOUS_UNION union {
		HBITMAP hbmHeader;
		LPCSTR pszbmHeader;
	} DUMMYUNIONNAME5;
#endif
} PROPSHEETHEADERA,*LPPROPSHEETHEADERA;
typedef const PROPSHEETHEADERA *LPCPROPSHEETHEADERA;
typedef struct _PROPSHEETHEADERW {
	DWORD	dwSize;
	DWORD	dwFlags;
	HWND	hwndParent;
	HINSTANCE	hInstance;
	_ANONYMOUS_UNION union {
		HICON	hIcon;
		LPCWSTR	pszIcon;
	}DUMMYUNIONNAME;
	LPCWSTR	pszCaption;
	UINT	nPages;
	_ANONYMOUS_UNION union {
		UINT	nStartPage;
		LPCWSTR	pStartPage;
	}DUMMYUNIONNAME2;
	_ANONYMOUS_UNION union {
		LPCPROPSHEETPAGEW ppsp;
		HPROPSHEETPAGE *phpage;
	}DUMMYUNIONNAME3;
	PFNPROPSHEETCALLBACK pfnCallback;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	_ANONYMOUS_UNION union {
		HBITMAP hbmWatermark;
		LPCWSTR pszbmWatermark;
	} DUMMYUNIONNAME4;
	HPALETTE hplWatermark;
	_ANONYMOUS_UNION union {
		HBITMAP hbmHeader;
		LPCWSTR pszbmHeader;
	} DUMMYUNIONNAME5;
#endif
} PROPSHEETHEADERW,*LPPROPSHEETHEADERW;
typedef const PROPSHEETHEADERW *LPCPROPSHEETHEADERW;
typedef BOOL(CALLBACK *LPFNADDPROPSHEETPAGE)(HPROPSHEETPAGE,LPARAM);
typedef BOOL(CALLBACK *LPFNADDPROPSHEETPAGES)(LPVOID,LPFNADDPROPSHEETPAGE,LPARAM);
/**
 * This structure contains information for the PSN_APPLY and PSN_RESET
 * notification messages.
 */
typedef struct _PSHNOTIFY {
	/**
	 * NMHDR structure that contains additional information about
	 * the notification.
	 */
	NMHDR hdr;
	/**
	 * Additional information about this notification. See the
	 * description of the particular notification message to determine
	 * what, if any, information is contained in this member.
	 */
	LPARAM lParam;
} PSHNOTIFY,*LPPSHNOTIFY;

#pragma pack(pop)

HPROPSHEETPAGE WINAPI CreatePropertySheetPageA(LPCPROPSHEETPAGEA);
/**
 * Creates a property sheet page.
 *
 * Pass the result to PropertySheetW in the header's phpage array, or add
 * it to an open sheet with PSM_ADDPAGE. Pages never given to a sheet must
 * be freed with DestroyPropertySheetPage.
 *
 * @param lppsp PROPSHEETPAGE describing the page, with dwSize set.
 * @return The page, or NULL on failure.
 */
HPROPSHEETPAGE WINAPI CreatePropertySheetPageW(LPCPROPSHEETPAGEW lppsp);
/**
 * Destroys a page made by CreatePropertySheetPageW.
 *
 * Only needed for pages not passed to PropertySheetW: the sheet destroys
 * its own pages.
 *
 * @param hPSPage The page.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI DestroyPropertySheetPage(HPROPSHEETPAGE hPSPage);
int WINAPI PropertySheetA(LPCPROPSHEETHEADERA);
/**
 * Creates and shows a property sheet with the pages in a header.
 *
 * @param lppsph PROPSHEETHEADER describing the frame and its pages, with
 *        dwSize set.
 * @return A positive value on success, or -1 on failure.
 *         ID_PSREBOOTSYSTEM or ID_PSRESTARTWINDOWS mean a page sent
 *         PSM_REBOOTSYSTEM or PSM_RESTARTWINDOWS.
 */
int WINAPI PropertySheetW(LPCPROPSHEETHEADERW lppsph);
/**
 * This macro adds a new page to the end of an existing property sheet. You
 * can use this macro or send the PSM_ADDPAGE message explicitly.
 *
 * The new page should be no larger than the largest page currently in the
 * property sheet because the property sheet is not resized to fit the new
 * page.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param hpage Handle to the page to add. The page must have been created
 *        by a previous call to the CreatePropertySheetPage function.
 * @return None.
 */
#define PropSheet_AddPage(d,p) SNDMSG(d,PSM_ADDPAGE,0,(LPARAM)p)
/**
 * This macro simulates the choice of the Apply Now button, indicating that
 * one or more pages have changed and the changes need to be validated and
 * recorded. The property sheet sends the PSN_KILLACTIVE notification
 * message to the current page. If the current page returns FALSE, the
 * property sheet sends the PSN_APPLY notification message to all pages.
 * You can use this macro or send the PSM_APPLY message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @return TRUE indicates that all pages successfully applied the changes.
 *        FALSE indicates failure.
 */
#define PropSheet_Apply(d) SNDMSG(d,PSM_APPLY,0,0)
/**
 * This macro disables the Cancel button and changes the text of the OK
 * button to Close. An application sends the PSM_CANCELTOCLOSE message
 * after applying a change that cannot be canceled. You can use this macro
 * or send the PSM_CANCELTOCLOSE message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @return None.
 */
#define PropSheet_CancelToClose(d) POSTMSG(d,PSM_CANCELTOCLOSE,0,0)
/**
 * This macro informs a property sheet that information in a page has
 * changed. The property sheet enables the Apply Now button. You can use
 * this macro or send the PSM_CHANGED message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param hwndPage Handle to the page that has changed.
 * @return None.
 */
#define PropSheet_Changed(d,w) SNDMSG(d,PSM_CHANGED,(WPARAM)w,0)
/**
 * This macro retrieves a handle to the window of the current page of a
 * property sheet. You can use this macro or send the
 * PSM_GETCURRENTPAGEHWND message explicitly.
 *
 * Use the PropSheet_GetCurrentPageHwnd macro with modeless property sheets
 * to determine when to destroy the dialog box. When the user clicks the OK
 * or Cancel button, PropSheet_GetCurrentPageHwnd returns NULL, and you can
 * then use the DestroyWindow function to destroy the dialog box.
 *
 * @param hDlg Handle to the property sheet.
 * @return A handle to the window of the current property sheet page
 *        indicates success.
 */
#define PropSheet_GetCurrentPageHwnd(d) (HWND)SNDMSG(d,PSM_GETCURRENTPAGEHWND,0,0)
/**
 * This macro retrieves the handle to the tab control of a property sheet.
 * You can use this macro or send the PSM_GETTABCONTROL message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @return The handle to the tab control indicates success.
 */
#define PropSheet_GetTabControl(d) (HWND)SNDMSG(d,PSM_GETTABCONTROL,0,0)
/**
 * This macro passes a message to a property sheet dialog box and indicates
 * whether the dialog processed the message. You can use this macro or send
 * the PSM_ISDIALOGMESSAGE message explicitly.
 *
 * Your message loop should use the PSM_ISDIALOGMESSAGE message with
 * modeless property sheets to pass messages to the property sheet dialog
 * box.
 *
 * If the return value indicates that the PSM_ISDIALOGMESSAGE message was
 * processed, it must not be passed to the TranslateMessage or
 * DispatchMessage function.
 *
 * @param hDlg Handle to the property sheet.
 * @param pMsg Pointer to an MSG structure that contains the message to be
 *        checked.
 * @return TRUE indicates that the macro has been processed. FALSE
 *        indicates the macro has not been processed.
 */
#define PropSheet_IsDialogMessage(d,m) (BOOL)SNDMSG(d,PSM_ISDIALOGMESSAGE,0,(LPARAM)m)
/**
 * This macro simulates the choice of a property sheet button. You can use
 * this macro or send the PSM_PRESSBUTTON message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param iButton Index of the button to select. It is one of the following
 *        values: Value Description PSBTN_APPLYNOW Selects the Apply Now
 *        button. PSBTN_BACK Selects the Back button. PSBTN_CANCEL Selects
 *        the Cancel button. PSBTN_FINISH Selects the Finish button.
 *        PSBTN_HELP Selects the Help button. PSBTN_NEXT Selects the Next
 *        button. PSBTN_OK Selects the OK button.
 * @return None.
 */
#define PropSheet_PressButton(d,i) POSTMSG(d,PSM_PRESSBUTTON,i,0)
/**
 * This macro causes a property sheet to send the PSM_QUERYSIBLINGS message
 * to each of its pages. If a page returns a nonzero value, the property
 * sheet does not send the message to subsequent pages. You can use this
 * macro or send the PSM_QUERYSIBLINGS message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param param1 First application-defined parameter.
 * @param param2 Second application-defined parameter.
 * @return Returns the nonzero value from a page in the property sheet, or
 *        zero if no page returns a nonzero value.
 */
#define PropSheet_QuerySiblings(d,w,l) SNDMSG(d,PSM_QUERYSIBLINGS,w,l)
/**
 * This macro indicates that the system needs to be restarted for the
 * changes to take effect. You can use this macro or send the
 * PSM_REBOOTSYSTEM message explicitly. An application should send the
 * PSM_REBOOTSYSTEM message only in response to the PSN_APPLY or
 * PSN_KILLACTIVE notification message.
 *
 * This macro causes the PropertySheet function to return the
 * ID_PSREBOOTSYSTEM value, but only if the user clicks the OK button to
 * close the property sheet. It is the application's responsibility to
 * reboot the system.
 *
 * This macro supersedes all PropSheet_RebootSystem macros that precede or
 * follow it.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @return None.
 */
#define PropSheet_RebootSystem(d) SNDMSG(d,PSM_REBOOTSYSTEM,0,0)
/**
 * This macro removes a page from a property sheet. You can use this macro
 * or send the PSM_REMOVEPAGE message explicitly.
 *
 * An application can specify the index or the handle, or both. If both are
 * specified, hpage takes precedence.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param index Zero-based index of the page to remove.
 * @param hpage Handle to the page to remove.
 * @return None.
 */
#define PropSheet_RemovePage(d,i,p) SNDMSG(d,PSM_REMOVEPAGE,i,(LPARAM)p)
/**
 * This macro sends a PSM_RESTARTWINDOWS message indicating that Windows
 * needs to be restarted for changes to take effect. You can use this macro
 * or send the PSM_RESTARTWINDOWS message explicitly. An application should
 * send the PSM_RESTARTWINDOWS message only in response to the PSN_APPLY or
 * PSN_KILLACTIVE notification message.
 *
 * The PSM_RESTARTWINDOWS message causes the PropertySheet function to
 * return the ID_PSRESTARTWINDOWS value, but only if the user clicks the OK
 * button to close the property sheet. It is the application's
 * responsibility to reboot the system.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @return None.
 */
#define PropSheet_RestartWindows(d) SNDMSG(d,PSM_RESTARTWINDOWS,0,0)
/**
 * This macro activates the specified page in a property sheet. You can use
 * this macro or send the PSM_SETCURSEL message explicitly.
 *
 * An application can specify the index or the handle, or both. If both are
 * specified, hpage takes precedence.
 *
 * The window that is losing the activation receives the PSN_KILLACTIVE
 * notification message, and the window that is gaining the activation
 * receives the PSN_SETACTIVE notification message.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param index Zero-based index of the page to activate.
 * @param hpage Handle to the page to activate.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define PropSheet_SetCurSel(d,p,i) SNDMSG(d,PSM_SETCURSEL,i,(LPARAM)p)
/**
 * This macro activates the specified page in a property sheet based on the
 * resource identifier of the page. You can use this macro or send the
 * PSM_SETCURSELID message explicitly.
 *
 * The window that is losing the activation receives the PSN_KILLACTIVE
 * notification message, and the window that is gaining the activation
 * receives the PSN_SETACTIVE notification message.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param id Resource identifier of the page to activate.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define PropSheet_SetCurSelByID(d,i) SNDMSG(d,PSM_SETCURSELID,0,i)
/**
 * This macro sets the text of the Finish button in a wizard property
 * sheet, shows and enables the button, and hides the Next and Back
 * buttons. You can use this macro or explicitly send the PSM_SETFINISHTEXT
 * message.
 *
 * This macro causes the DM_SETDEFID message to be sent to the property
 * sheet dialog box. The wParam parameter specifies the identifier of the
 * Finish button.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param lpszText Long pointer to the new text for the Finish button.
 * @return None.
 */
#define PropSheet_SetFinishText(d,s) SNDMSG(d,PSM_SETFINISHTEXT,0,(LPARAM)s)
/**
 * This macro sets the title of a property sheet. You can use this macro or
 * send the PSM_SETTITLE message explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param dwStyle Indicates whether to include the prefix "Properties for"
 *        with the specified title string. If dwStyle is the PSH_PROPTITLE
 *        value, the prefix is included. Otherwise, the prefix is not used.
 * @param lpszText Long pointer to a buffer that contains the title string.
 *        If the high-order word of this parameter is NULL, the property
 *        sheet loads the string resource specified in the low-order word.
 * @return None.
 */
#define PropSheet_SetTitle(d,w,s) SNDMSG(d,PSM_SETTITLE,w,(LPARAM)s)
/**
 * This macro posts the PSM_SETWIZBUTTON message to a wizard property
 * sheet. The PSM_SETWIZBUTTON message enables or disables the Back, Next,
 * and Finish buttons in a wizard property sheet. You can use this macro or
 * explicitly send or post the PSM_SETWIZBUTTON message.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param dwFlags Specifies the buttons to display and enable. It is one of
 *        the following flags: Value Description PSWIZB_BACK Enables the
 *        Back button. PSWIZB_NEXT Enables the Next button. PSWIZB_FINISH
 *        Displays an enabled Finish button in place of the Next button.
 *        PSWIZB_DISABLEDFINISH Displays a disabled Finish button in place
 *        of the Next button. A wizard property sheet displays the Back
 *        button and either the Next or Finish button, which means that the
 *        PSWIZB_BACK flag is coupled with one of the other three flags.
 * @return None.
 */
#define PropSheet_SetWizButtons(d,f) POSTMSG(d,PSM_SETWIZBUTTONS,0,(LPARAM)f)
/**
 * This macro informs a property sheet that informationin a page has
 * reverted to the previously saved state. The property sheet disables the
 * Apply Now button if no other pages have registered changes with the
 * property sheet. You can use this macro or send the PSM_UNCHANGED message
 * explicitly.
 *
 * @param hPropSheetDlg Handle to the property sheet.
 * @param hwndPage Handle to the page that has reverted to the previously
 *        saved state.
 * @return None.
 */
#define PropSheet_UnChanged(d,w) SNDMSG(d,PSM_UNCHANGED,(WPARAM)w,0)
#endif

#ifdef UNICODE
#define LPFNPSPCALLBACK	LPFNPSPCALLBACKW
/**
 * This structure defines a page in a property sheet.
 *
 * When the PropertySheet function creates the page, the dialog box
 * procedure for the page receives a WM_INITDIALOG message. The lParam
 * parameter of this message points to the PROPSHEETPAGE structure used to
 * create the page.
 */
#define PROPSHEETPAGE	PROPSHEETPAGEW
#define LPPROPSHEETPAGE	LPPROPSHEETPAGEW
#define LPCPROPSHEETPAGE	LPCPROPSHEETPAGEW
/**
 * This structure defines the frame and pages of a property sheet.
 */
#define PROPSHEETHEADER	PROPSHEETHEADERW
#define LPPROPSHEETHEADER	LPPROPSHEETHEADERW
#define LPCPROPSHEETHEADER	LPCPROPSHEETHEADERW
/**
 * This message sets the title of a property sheet. You can send this
 * message explicitly or by using the PropSheet_SetTitle macro.
 *
 * @param dwStyle Indicates whether to include the prefix "Properties for"
 *        with the specified title string. If dwStyle is the PSH_PROPTITLE
 *        value, the prefix is included. Otherwise, the prefix is not used.
 * @param lpszText Long pointer to a buffer that contains the title string.
 *        If the high-order word of this parameter is NULL, the property
 *        sheet loads the string resource specified in the low-order word.
 * @return None.
 */
#define PSM_SETTITLE PSM_SETTITLEW
/**
 * This message sets the text of the Finish button in a wizard property
 * sheet, shows and enables the button, and hides the Next and Back
 * buttons. You can send this message explicitly or by using the
 * PropSheet_SetFinishText macro.
 *
 * @param lpszText Long pointer to the null-terminated string that contains
 *        the new text for the Finish button.
 * @return None.
 */
#define PSM_SETFINISHTEXT PSM_SETFINISHTEXTW
/**
 * Creates a property sheet page.
 *
 * Pass the result to PropertySheetW in the header's phpage array, or add
 * it to an open sheet with PSM_ADDPAGE. Pages never given to a sheet must
 * be freed with DestroyPropertySheetPage.
 *
 * @param lppsp PROPSHEETPAGE describing the page, with dwSize set.
 * @return The page, or NULL on failure.
 */
#define CreatePropertySheetPage CreatePropertySheetPageW
/**
 * Creates and shows a property sheet with the pages in a header.
 *
 * @param lppsph PROPSHEETHEADER describing the frame and its pages, with
 *        dwSize set.
 * @return A positive value on success, or -1 on failure.
 *         ID_PSREBOOTSYSTEM or ID_PSRESTARTWINDOWS mean a page sent
 *         PSM_REBOOTSYSTEM or PSM_RESTARTWINDOWS.
 */
#define PropertySheet PropertySheetW
#else
#define LPFNPSPCALLBACK	LPFNPSPCALLBACKA
#define PROPSHEETPAGE	PROPSHEETPAGEA
#define LPPROPSHEETPAGE	LPPROPSHEETPAGEA
#define LPCPROPSHEETPAGE	LPCPROPSHEETPAGEA
#define PROPSHEETHEADER	PROPSHEETHEADERA
#define LPPROPSHEETHEADER	LPPROPSHEETHEADERA
#define LPCPROPSHEETHEADER	LPCPROPSHEETHEADERA
#define PSM_SETTITLE PSM_SETTITLEA
#define PSM_SETFINISHTEXT PSM_SETFINISHTEXTA
#define CreatePropertySheetPage CreatePropertySheetPageA
#define PropertySheet PropertySheetA
#endif
#ifdef __cplusplus
}
#endif
#endif

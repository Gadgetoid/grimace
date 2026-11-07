#ifndef GRIMACE_EXTRAS_COMMCTRL_H
#define GRIMACE_EXTRAS_COMMCTRL_H

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Checks whether a message is meant for a command bar and, if so, processes
 * it.
 *
 * Undocumented in the Windows CE SDK. The SDK samples call it in the message
 * loop, like IsDialogMessage, and skip TranslateMessage and DispatchMessage
 * when it returns TRUE.
 *
 * @param hwndCB The command bar.
 * @param lpMsg The message from GetMessage.
 * @return TRUE if the message was processed, FALSE otherwise.
 */
BOOL WINAPI IsCommandBarMessage(HWND hwndCB, LPMSG lpMsg);
/**
 * Copies an image from one image list into an image in another, dithering
 * it.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param himlDst Destination image list.
 * @param iDst Index of the destination image.
 * @param xDst Horizontal offset within the destination image.
 * @param yDst Vertical offset within the destination image.
 * @param himlSrc Source image list.
 * @param iSrc Index of the source image.
 * @param fStyle Drawing style, ILD_*.
 */
void WINAPI ImageList_CopyDitherImage(HIMAGELIST himlDst, WORD iDst, int xDst, int yDst, HIMAGELIST himlSrc, int iSrc, UINT fStyle);
/**
 * Creates a colour bitmap of the given size.
 *
 * Undocumented in the Windows CE SDK. Kept in the CE 2.0 headers for
 * compatibility with CE 1.0.
 *
 * @param cx Width, in pixels.
 * @param cy Height, in pixels.
 * @return The bitmap, or NULL on failure. Free with DeleteObject.
 *
 * @note Windows CE 1.0 only.
 */
HBITMAP WINAPI CreateColorBitmap(int cx, int cy);
/**
 * Creates a monochrome bitmap of the given size.
 *
 * Undocumented in the Windows CE SDK. Kept in the CE 2.0 headers for
 * compatibility with CE 1.0.
 *
 * @param cx Width, in pixels.
 * @param cy Height, in pixels.
 * @return The bitmap, or NULL on failure. Free with DeleteObject.
 *
 * @note Windows CE 1.0 only.
 */
HBITMAP WINAPI CreateMonoBitmap(int cx, int cy);

#if GRIMACE_CE == 1
typedef LV_KEYDOWN NMLVKEYDOWN, *LPNMLVKEYDOWN;
#endif
typedef TV_KEYDOWN NMTVKEYDOWN, *LPNMTVKEYDOWN;
typedef TC_KEYDOWN NMTCKEYDOWN;

#if GRIMACE_CE >= 2

/**
 * This structure contains information used with key notification messages.
 */
typedef struct tagNMKEY {
    /**
     * Handle to a NMHDR structure that contains additional
     * information about this notification.
     */
    NMHDR hdr;
    /**
     * Virtual key code of the key that caused the event.
     */
    WORD wVKey;
    /**
     * Flags associated with the key. These are the same flags
     * that are passed in the high-order word of the lParam in the
     * WM_KEYDOWN message.
     */
    UINT flags;
} NMKEY, *LPNMKEY;

typedef struct tagNMTTCUSTOMDRAW {
    NMCUSTOMDRAW nmcd;
    UINT uDrawFlags;
} NMTTCUSTOMDRAW, *LPNMTTCUSTOMDRAW;

typedef struct tagNMDATETIMESTRINGW {
    NMHDR nmhdr;
    LPCWSTR pszUserString;
    SYSTEMTIME st;
    DWORD dwFlags;
} NMDATETIMESTRINGW, *LPNMDATETIMESTRINGW;

typedef struct tagNMDATETIMESTRINGA {
    NMHDR nmhdr;
    LPCSTR pszUserString;
    SYSTEMTIME st;
    DWORD dwFlags;
} NMDATETIMESTRINGA, *LPNMDATETIMESTRINGA;

typedef struct tagNMDATETIMEWMKEYDOWNW {
    NMHDR nmhdr;
    int nVirtKey;
    LPCWSTR pszFormat;
    SYSTEMTIME st;
} NMDATETIMEWMKEYDOWNW, *LPNMDATETIMEWMKEYDOWNW;

typedef struct tagNMDATETIMEWMKEYDOWNA {
    NMHDR nmhdr;
    int nVirtKey;
    LPCSTR pszFormat;
    SYSTEMTIME st;
} NMDATETIMEWMKEYDOWNA, *LPNMDATETIMEWMKEYDOWNA;

typedef struct tagNMDATETIMEFORMATW {
    NMHDR nmhdr;
    LPCWSTR pszFormat;
    SYSTEMTIME st;
    LPCWSTR pszDisplay;
    WCHAR szDisplay[64];
} NMDATETIMEFORMATW, *LPNMDATETIMEFORMATW;

typedef struct tagNMDATETIMEFORMATA {
    NMHDR nmhdr;
    LPCSTR pszFormat;
    SYSTEMTIME st;
    LPCSTR pszDisplay;
    CHAR szDisplay[64];
} NMDATETIMEFORMATA, *LPNMDATETIMEFORMATA;

typedef struct tagNMDATETIMEFORMATQUERYW {
    NMHDR nmhdr;
    LPCWSTR pszFormat;
    SIZE szMax;
} NMDATETIMEFORMATQUERYW, *LPNMDATETIMEFORMATQUERYW;

typedef struct tagNMDATETIMEFORMATQUERYA {
    NMHDR nmhdr;
    LPCSTR pszFormat;
    SIZE szMax;
} NMDATETIMEFORMATQUERYA, *LPNMDATETIMEFORMATQUERYA;

#endif

/**
 * This macro adds ToolTip strings to the command bar. A ToolTip control is
 * a small pop-up window that displays a line of descriptive text giving
 * the purpose of a button on the command bar.
 *
 * Only command-bar buttons can have ToolTip strings; menus and combo boxes
 * cannot.
 *
 * CommandBar_AddtoolTips does not copy the array of ToolTip strings you
 * pass to it. It uses the memory address you pass in the lpToolTips
 * parameter. Do not release the memory allocated for the ToolTip string
 * array until the program exits.
 *
 * @param hwndCB Handle to the command bar's window. This handle is
 *        returned by the CommandBar_Create function when the command bar
 *        is created.
 * @param uNumToolTips Unsigned integer that contains the number of ToolTip
 *        strings in the array specified in the lpToolTips parameter.
 * @param lpToolTips Array of long pointers to strings that are displayed
 *        when the ToolTip control is active. The array must contain the
 *        same number of elements as specified in the uNumToolTips
 *        parameter.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define CommandBar_AddToolTips(hwndCB, cbToolTips, lpToolTipsStrings) \
    SendMessage((hwndCB), TB_SETTOOLTIPS, (WPARAM)(cbToolTips), (LPARAM)(lpToolTipsStrings))
#define LPHDITEM LPHDITEMW
#define LPLVCOLUMN LPLVCOLUMNW
#define NM_FINDITEM NMLVFINDITEM
#define PNM_FINDITEM LPNMLVFINDITEM
#define LPNM_FINDITEM LPNMLVFINDITEM

#if GRIMACE_CE == 1
#define OVERLAYMASKTOINDEX(i) ((((i) >> 8) & (ILD_OVERLAYMASK >> 8)) - 1)
#define STATEIMAGEMASKTOINDEX(i) (((i) & LVIS_STATEIMAGEMASK) >> 12)
#define TabCtrl_GetBkColor(hwnd) (COLORREF)SendMessage((hwnd), TCM_GETBKCOLOR, 0, 0L)
#define TabCtrl_SetBkColor(hwnd, clrBk) (BOOL)SendMessage((hwnd), TCM_SETBKCOLOR, 0, (LPARAM)(COLORREF)(clrBk))
#define PropSheet_SetWizButtonsNow(hDlg, dwFlags) PropSheet_SetWizButtons(hDlg, dwFlags)
#else
#define CommandBands_IsVisible(hwndCmdBands) IsWindowVisible((hwndCmdBands))
/**
 * This macro changes the color of a divider between header items to
 * indicate the destination of an external drag-and-drop operation.
 *
 * A header control set to the HDS_DRAGDROP style produces this effect
 * automatically. This message is intended to be used when the owner of the
 * control handles drag-and-drop operations manually.
 *
 * @param hwndHD Handle to a header control.
 * @param flag Boolean value that specifies how dwInputValue is to be
 *        interpreted.
 * @param dwInputValue Value held here is interpreted depending on the
 *        value of flag. If flag is TRUE, then dwInputValue represents the
 *        x- and y- client coordinates of the pointer. The x-coordinate is
 *        in the low-order word, and the y-coordinate is in the high-order
 *        word. Upon receiving the message, the header control highlights
 *        the appropriate divider based on the dwInputValue coordinates. If
 *        flag is FALSE, then dwInputValue represents the integer index of
 *        the divider that will be highlighted.
 * @return Returns the index of the divider that the control highlighted.
 */
#define Header_SetHotDivider(hwnd, fPos, dw) (int)SendMessage((hwnd), HDM_SETHOTDIVIDER, (WPARAM)(fPos), (LPARAM)(dw))
#define LPLVITEM LPLVITEMW
/**
 * This structure contains information specific to an edit operation that
 * has taken place in a date and time picker (DTP) control. This message is
 * used with the DTN_USERSTRING notification message.
 */
#define NMDATETIMESTRING NMDATETIMESTRINGW
#define LPNMDATETIMESTRING LPNMDATETIMESTRINGW
/**
 * This structure carries information used to describe and handle a
 * DTN_WMKEYDOWN notification message.
 */
#define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNW
#define LPNMDATETIMEWMKEYDOWN LPNMDATETIMEWMKEYDOWNW
/**
 * This structure is used with the DTN_FORMAT notification message.
 *
 * The NMDATETIMEFORMAT structure contains information about a portion of
 * the format string that defines a callback field within a date and time
 * picker (DTP) control. It carries the substring that defines the callback
 * field and contains a buffer to receive the string that will be displayed
 * in the callback field.
 */
#define NMDATETIMEFORMAT NMDATETIMEFORMATW
#define LPNMDATETIMEFORMAT LPNMDATETIMEFORMATW
/**
 * This structure is used with the DTN_FORMATQUERY notification message.
 *
 * The NMDATETIMEFORMATQUERY structure contains information about a date
 * and time picker (DTP) control callback field. It contains a substring
 * (taken from the control's format string) that defines a callback field.
 * The structure receives the maximum allowable size of the text that will
 * be displayed in the callback field.
 */
#define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYW
#define LPNMDATETIMEFORMATQUERY LPNMDATETIMEFORMATQUERYW
#define NM_ODSTATECHANGE NMLVODSTATECHANGE
#define PNM_ODSTATECHANGE LPNMLVODSTATECHANGE
#define LPNM_ODSTATECHANGE LPNMLVODSTATECHANGE
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif

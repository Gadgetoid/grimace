#ifndef _COMMCTRL_H
#define _COMMCTRL_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#include <prsht.h>
#ifdef __cplusplus
extern "C" {
#endif
#ifndef _WIN32_IE
/* define _WIN32_IE if you really want it */
#if 0
#define _WIN32_IE	0x0300
#endif
#endif

#ifndef COMMCTRLAPI
#ifdef __W32API_USE_DLLIMPORT__
#define COMMCTRLAPI DECLSPEC_IMPORT
#else
#define COMMCTRLAPI
#endif
#endif


#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif /* ifndef SNDMSG */

#define DRAGLISTMSGSTRING TEXT("commctrl_DragListMsg")
#define HOTKEY_CLASSA	"msctls_hotkey32"
#define HOTKEY_CLASSW	L"msctls_hotkey32"
#define PROGRESS_CLASSA	"msctls_progress32"
#define PROGRESS_CLASSW	L"msctls_progress32"
#define STATUSCLASSNAMEA	"msctls_statusbar32"
#define STATUSCLASSNAMEW	L"msctls_statusbar32"
#define TOOLBARCLASSNAMEA	"ToolbarWindow32"
#define TOOLBARCLASSNAMEW	L"ToolbarWindow32"
#define TOOLTIPS_CLASSA	"tooltips_class32"
#define TOOLTIPS_CLASSW	L"tooltips_class32"
#define TRACKBAR_CLASSA	"msctls_trackbar32"
#define TRACKBAR_CLASSW	L"msctls_trackbar32"
#define UPDOWN_CLASSA	"msctls_updown32"
#define UPDOWN_CLASSW	L"msctls_updown32"
#define ANIMATE_CLASSA	"SysAnimate32"
#define ANIMATE_CLASSW	L"SysAnimate32"
#define DATETIMEPICK_CLASSW L"SysDateTimePick32"
#define DATETIMEPICK_CLASSA "SysDateTimePick32"
#define MONTHCAL_CLASSW L"SysMonthCal32"
#define MONTHCAL_CLASSA "SysMonthCal32"
#define REBARCLASSNAMEW L"ReBarWindow32"
#define REBARCLASSNAMEA "ReBarWindow32"
#define WC_COMBOBOXEXW	L"ComboBoxEx32"
#define WC_COMBOBOXEXA	"ComboBoxEx32"
#define WC_IPADDRESSW	L"SysIPAddress32"
#define WC_IPADDRESSA	"SysIPAddress32"
#define WC_LISTVIEWA	"SysListView32"
#define WC_LISTVIEWW	L"SysListView32"
#define WC_TABCONTROLA	"SysTabControl32"
#define WC_TABCONTROLW	L"SysTabControl32"
#define WC_TREEVIEWA	"SysTreeView32"
#define WC_TREEVIEWW	L"SysTreeView32"
#define WC_HEADERA	"SysHeader32"
#define WC_HEADERW 	L"SysHeader32"
#define WC_PAGESCROLLERW	L"SysPager"
#define WC_PAGESCROLLERA	"SysPager"
#define WC_NATIVEFONTCTLW	L"NativeFontCtl"
#define WC_NATIVEFONTCTLA	"NativeFontCtl"
#define WC_BUTTONA	"Button"
#define WC_BUTTONW	L"Button"
#define WC_STATICA	"Static"
#define WC_STATICW	L"Static"
#define WC_EDITA	"Edit"
#define WC_EDITW	L"Edit"
#define WC_LISTBOXA	"ListBox"
#define WC_LISTBOXW	L"ListBox"
#define WC_COMBOBOXA	"ComboBox"
#define WC_COMBOBOXW	L"ComboBox"
#define WC_SCROLLBARA	"ScrollBar"
#define WC_SCROLLBARW	L"ScrollBar"
#define WC_LINKA	"SysLink"
#define WC_LINKW	L"SysLink"

#ifdef UNICODE
#define HOTKEY_CLASS HOTKEY_CLASSW
#define PROGRESS_CLASS PROGRESS_CLASSW
#define STATUSCLASSNAME STATUSCLASSNAMEW
#define TOOLBARCLASSNAME TOOLBARCLASSNAMEW
#define TOOLTIPS_CLASS TOOLTIPS_CLASSW
#define TRACKBAR_CLASS TRACKBAR_CLASSW
#define UPDOWN_CLASS UPDOWN_CLASSW
#define ANIMATE_CLASS ANIMATE_CLASSW
#define DATETIMEPICK_CLASS DATETIMEPICK_CLASSW
#define MONTHCAL_CLASS MONTHCAL_CLASSW
#define REBARCLASSNAME REBARCLASSNAMEW
#define WC_COMBOBOXEX WC_COMBOBOXEXW
#define WC_HEADER WC_HEADERW
#define WC_IPADDRESS WC_IPADDRESSW
#define WC_LISTVIEW WC_LISTVIEWW
#define WC_TABCONTROL WC_TABCONTROLW
#define WC_TREEVIEW WC_TREEVIEWW
#define WC_PAGESCROLLER WC_PAGESCROLLERW
#define WC_NATIVEFONTCTL WC_NATIVEFONTCTLW
#define WC_BUTTON WC_BUTTONW
#define WC_STATIC WC_STATICW
#define WC_EDIT WC_EDITW
#define WC_LISTBOX WC_LISTBOXW
#define WC_COMBOBOX WC_COMBOBOXW
#define WC_SCROLLBAR WC_SCROLLBARW
#define WC_LINK WC_LINKW
#else
#define ANIMATE_CLASS ANIMATE_CLASSA
#define HOTKEY_CLASS HOTKEY_CLASSA
#define PROGRESS_CLASS PROGRESS_CLASSA
#define STATUSCLASSNAME STATUSCLASSNAMEA
#define TOOLBARCLASSNAME TOOLBARCLASSNAMEA
#define TOOLTIPS_CLASS TOOLTIPS_CLASSA
#define TRACKBAR_CLASS TRACKBAR_CLASSA
#define UPDOWN_CLASS UPDOWN_CLASSA
#define DATETIMEPICK_CLASS DATETIMEPICK_CLASSA
#define MONTHCAL_CLASS MONTHCAL_CLASSA
#define REBARCLASSNAME REBARCLASSNAMEA
#define WC_COMBOBOXEX WC_COMBOBOXEXA
#define WC_HEADER WC_HEADERA
#define WC_IPADDRESS WC_IPADDRESSA
#define WC_LISTVIEW WC_LISTVIEWA
#define WC_TABCONTROL WC_TABCONTROLA
#define WC_TREEVIEW WC_TREEVIEWA
#define WC_PAGESCROLLER WC_PAGESCROLLERA
#define WC_NATIVEFONTCTL WC_NATIVEFONTCTLA
#define WC_BUTTON WC_BUTTONA
#define WC_STATIC WC_STATICA
#define WC_EDIT WC_EDITA
#define WC_LISTBOX WC_LISTBOXA
#define WC_COMBOBOX WC_COMBOBOXA
#define WC_SCROLLBAR WC_SCROLLBARA
#define WC_LINK WC_LINKA
#endif

#ifdef _WIN32_WCE
/*http://yta.blogzine.jp/weblog/2010/12/propertysheet.html*/
/*also google for +COMCTL32_VERSION windowsmobile*/
#define COMCTL32_VERSION 0x210
#else
#if (_WIN32_IE >= 0x0500)
#if (_WIN32_WINNT >= 0x0501)
#define COMCTL32_VERSION 6
#else
#define COMCTL32_VERSION 5
#endif
#endif
#endif

#define LVM_FIRST 0x1000
#define TV_FIRST 0x1100
#define HDM_FIRST 0x1200
#define ACM_OPENA	(WM_USER+100)
#define ACM_PLAY	(WM_USER+101)
#define ACM_STOP	(WM_USER+102)
#define ACM_OPENW	(WM_USER+103)
#define ACN_START	1
#define ACN_STOP	2
#define CBEIF_TEXT	0x00000001
#define CBEIF_IMAGE	0x00000002
#define CBEIF_SELECTEDIMAGE	0x00000004
#define CBEIF_OVERLAY	0x00000008
#define CBEIF_INDENT	0x00000010
#define CBEIF_LPARAM	0x00000020
#define CBEIF_DI_SETITEM	0x10000000
#define CBEN_INSERTITEM	(CBEN_FIRST - 1)
#define CBEN_DELETEITEM	(CBEN_FIRST - 2)
#define CBEN_BEGINEDIT	(CBEN_FIRST - 4)
#define CBEN_ENDEDITA	(CBEN_FIRST - 5)
#define CBEN_ENDEDITW	(CBEN_FIRST - 6)
#define CBENF_KILLFOCUS	1
#define CBENF_RETURN	2
#define CBENF_ESCAPE	3
#define CBENF_DROPDOWN	4
#define CBEMAXSTRLEN 260
#define DL_BEGINDRAG	1157
#define DL_CANCELDRAG	1160
#define DL_DRAGGING	1158
#define DL_DROPPED	1159
#define DL_CURSORSET	0
#define DL_STOPCURSOR	1
#define DL_COPYCURSOR	2
#define DL_MOVECURSOR	3
#define CCS_TOP	1
#define CCS_NOMOVEY	2
#define CCS_BOTTOM	3
#define CCS_NORESIZE	4
#define CCS_NOPARENTALIGN	8
#define CCS_ADJUSTABLE	32
#define CCS_NODIVIDER	64
#if (_WIN32_IE >= 0x0300)
#define CCS_VERT 128
#define CCS_LEFT 129
#define CCS_NOMOVEX 130
#define CCS_RIGHT 131
#endif
#define ACS_CENTER	0x0001
#define ACS_TRANSPARENT	0x0002
#define ACS_AUTOPLAY	0x0004
#define ACS_TIMER	0x0008
#define PGS_VERT	0x00000000
#define PGS_HORZ	0x00000001
#define PGS_AUTOSCROLL	0x00000002
#define PGS_DRAGNDROP	0x00000004
#define CMB_MASKED	2
#define MINSYSCOMMAND	SC_SIZE
#define SBT_OWNERDRAW	0x1000
#define SBT_NOBORDERS	256
#define SBT_POPOUT	512
#define SBT_RTLREADING	1024
#define SB_SETTEXTA	(WM_USER+1)
#define SB_SETTEXTW	(WM_USER+11)
#define SB_GETTEXTA	(WM_USER+2)
#define SB_GETTEXTW	(WM_USER+13)
#define SB_GETTEXTLENGTHA	(WM_USER+3)
#define SB_GETTEXTLENGTHW	(WM_USER+12)
/**
 * This message sets the number of parts in a status window and the
 * coordinate of the right edge of each part.
 *
 * @param nParts Number of parts to set (cannot be greater than 255).
 * @param aWidths Address of an integer array that has the same number of
 *        elements as parts specified by nParts. Each element in the array
 *        specifies the position, in client coordinates, of the right edge
 *        of the corresponding part. If an element is -1, the position of
 *        the right edge for that part extends to the right edge of the
 *        window.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define SB_SETPARTS	(WM_USER+4)
/**
 * This message retrieves a count of the parts in a status window. The
 * message also retrieves the coordinate of the right edge of the specified
 * number of parts.
 *
 * @param nParts Number of parts for which to retrieve coordinates. If this
 *        parameter is greater than the number of parts in the window, the
 *        message retrieves coordinates for existing parts only.
 * @param aRightCoord Address of an integer array that has the same number
 *        of elements as parts specified by nParts. Each element in the
 *        array receives the client coordinate of the right edge of the
 *        corresponding part. If an element is set to -1, the position of
 *        the right edge for that part extends to the right edge of the
 *        window. To retrieve the current number of parts, set this
 *        parameter to zero.
 * @return The number of parts in the window indicates success. Zero
 *        indicates failure.
 */
#define SB_GETPARTS	(WM_USER+6)
/**
 * This message retrieves the current widths of the horizontal and vertical
 * borders of a status window.
 *
 * @param aBorders Address of an integer array that has three elements. The
 *        first element receives the width of the horizontal border, the
 *        second receives the width of the vertical border, and the third
 *        receives the width of the border between rectangles.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define SB_GETBORDERS	(WM_USER+7)
/**
 * This message sets the minimum height of a status window's drawing area.
 *
 * @param minHeight Minimum height, in pixels, of the window.
 * @return None.
 */
#define SB_SETMINHEIGHT	(WM_USER+8)
/**
 * This message specifies whether a status window displays simple text or
 * displays all window parts set by a previous SB_SETPARTS message.
 *
 * @param fSimple Boolean value that is set to TRUE if the window displays
 *        simple text, or to FALSE if it displays multiple parts.
 * @return FALSE indicates that an error has occurred.
 */
#define SB_SIMPLE	(WM_USER+9)
/**
 * This message retrieves the bounding rectangle of a part in a status
 * window.
 *
 * @param iPart Zero-based index of the part whose bounding rectangle is to
 *        be retrieved.
 * @param lprc Long pointer to a RECT structure that receives the bounding
 *        rectangle.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define SB_GETRECT	(WM_USER+10)
#define MSGF_COMMCTRL_BEGINDRAG	0x4200
#define MSGF_COMMCTRL_SIZEHEADER	0x4201
#define MSGF_COMMCTRL_DRAGSELECT	0x4202
#define MSGF_COMMCTRL_TOOLBARCUST	0x4203
#define ILC_COLOR 0
#define ILC_COLOR4 4
#define ILC_COLOR8 8
#define ILC_COLOR16 16
#define ILC_COLOR24 24
#define ILC_COLOR32 32
#define ILC_COLORDDB 254
#define ILC_MASK 1
#define ILC_PALETTE 2048
#define ILCF_MOVE 0
#define ILCF_SWAP 1
#define ILS_NORMAL 0
#define ILS_GLOW 1
#define ILS_SHADOW 2
#define ILS_SATURATE 4
#define ILS_ALPHA 8
#define ILD_BLEND25 2
#define ILD_BLEND50 4
#define ILD_SELECTED 4
#define ILD_BLEND 4
#define ILD_FOCUS 2
#define ILD_MASK 16
#define ILD_NORMAL 0
#define ILD_TRANSPARENT 1
#define ILD_IMAGE 0x0020
#define ILD_ROP 0x0040
#define ILD_OVERLAYMASK 0x0F00
#define ILD_PRESERVEALPHA 0x1000
#define ILD_SCALE 0x2000
#define ILD_DPISCALE 0x4000
#define HDS_HORZ	0
#define HDS_BUTTONS	2
#define HDS_HIDDEN	8
#if (_WIN32_IE > 0x0300)
#define HDS_HOTTRACK	4
#define HDS_DRAGDROP	0x0040
#define HDS_FULLDRAG	0x0080
#endif /* _WIN32_IE > 0x0300 */
#if (_WIN32_IE >= 0x0500)
#define HDS_FILTERBAR	0x0100
#endif /* _WIN32_IE >= 0x0500 */
#define NM_FIRST	0
#define NM_LAST	((UINT)-99)
#define LVN_FIRST	((UINT)-100)
#define LVN_LAST	((UINT)-199)
#define HDN_FIRST	((UINT)-300)
#define HDN_LAST	((UINT)-399)
#define TVN_FIRST	((UINT)-400)
#define TVN_LAST	((UINT)-499)
#define TTN_FIRST	((UINT)-520)
#define TTN_LAST	((UINT)-549)
#define TCN_FIRST	((UINT)-550)
#define TCN_LAST	((UINT)-580)
#ifndef CDN_FIRST
#define CDN_FIRST	((UINT)-601) /* also in commdlg.h */
#define CDN_LAST	((UINT)-699)
#endif
#define TBN_FIRST	((UINT)-700)
#define TBN_LAST	((UINT)-720)
#define UDN_FIRST	((UINT)-721)
#define UDN_LAST	((UINT)-740)
#if (_WIN32_IE >= 0x0300)
#define RBN_FIRST	((UINT)-831)
#define RBN_LAST	((UINT)-859)
#define MCN_FIRST	((UINT)-750)
#define MCN_LAST	((UINT)-759)
#define DTN_FIRST	((UINT)-760)
#if defined(_WIN32_WCE) && GRIMACE_CE == 1
#define DTN_LAST	((UINT)-769)
#else
#define DTN_LAST	((UINT)-799)
#endif
#define CBEN_FIRST	((UINT)-800)
#define CBEN_LAST	((UINT)-830)
#endif /* _WIN32_IE */
#if (_WIN32_IE >= 0x0400)
#define IPN_FIRST	((UINT)-860)
#define IPN_LAST	((UINT)-879)
#define IPN_FIELDCHANGED	(IPN_FIRST-0)
#define SBN_FIRST	((UINT)-880U)
#ifdef _WIN32_WCE
#define SBN_LAST	((UINT)-900U)
#else
#define SBN_LAST	((UINT)-899U)
#endif
#define PGN_FIRST	((UINT)-900U)
#define PGN_LAST	((UINT)-950U)
#define PGN_SCROLL	(PGN_FIRST-1)
#define PGN_CALCSIZE	(PGN_FIRST-2)
#endif /* _WIN32_IE >= 0x0400 */
#define HDI_WIDTH	1
#define HDI_HEIGHT	1
#define HDI_TEXT	2
#define HDI_FORMAT	4
#define HDI_LPARAM	8
#define HDI_BITMAP	16
#if (_WIN32_IE >= 0x0300)
#define HDI_IMAGE	32
#define HDI_DI_SETITEM	64
#define HDI_ORDER	128
#endif
#define CBES_EX_NOEDITIMAGE	0x00000001
#define CBES_EX_NOEDITIMAGEINDENT	0x00000002
#define CBES_EX_PATHWORDBREAKPROC	0x00000004
#if (_WIN32_IE >= 0x0400)
#define CBES_EX_NOSIZELIMIT	0x00000008
#define CBES_EX_CASESENSITIVE	0x00000010
#define CBEN_GETDISPINFOA	(CBEN_FIRST - 0)
#define CBEN_GETDISPINFOW	(CBEN_FIRST - 7)
#define CBEN_DRAGBEGINA	(CBEN_FIRST - 8)
#define CBEN_DRAGBEGINW	(CBEN_FIRST - 9)
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_IE >= 0x0500)
#define HDI_FILTER	256
#endif
#define HDF_LEFT	0
#define HDF_RIGHT	1
#define HDF_CENTER	2
#define HDF_JUSTIFYMASK	3
#define HDF_RTLREADING	4
#define HDF_OWNERDRAW	0x8000
#define HDF_STRING	0x4000
#define HDF_BITMAP	0x2000
#if (_WIN32_IE >= 0x0300)
#define HDF_BITMAP_ON_RIGHT	0x1000
#define HDF_IMAGE	0x0800
#endif
/**
 * This message retrieves a count of the items in a header control. You can
 * send this message explicitly or use the Header_GetItemCount macro.
 *
 * @return The number of items indicates success. -1 indicates failure.
 */
#define HDM_GETITEMCOUNT	HDM_FIRST
#define HDM_INSERTITEMA	(HDM_FIRST+1)
#define HDM_INSERTITEMW	(HDM_FIRST+10)
/**
 * This message deletes an item from a header control. You can send this
 * message explicitly or use the Header_DeleteItem macro.
 *
 * @param index Index of the item to delete
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define HDM_DELETEITEM	(HDM_FIRST+2)
#define HDM_GETITEMA	(HDM_FIRST+3)
#define HDM_GETITEMW	(HDM_FIRST+11)
#define HDM_SETITEMA	(HDM_FIRST+4)
#define HDM_SETITEMW	(HDM_FIRST+12)
/**
 * Retrieves the correct header control size and position within the parent
 * window. This message retrieves the header control size and position
 * within a specified rectangle. This message is used to determine the
 * appropriate dimensions for a new header control to occupy the specified
 * rectangle. You can send this message explicitly or use the Header_Layout
 * macro.
 *
 * @param playout Pointer to an HDLAYOUT structure. The prc member
 *        specifies the rectangle coordinates, and the pwpos member
 *        receives the size and position for the header control within the
 *        rectangle.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define HDM_LAYOUT	(HDM_FIRST+5)
#if (_WIN32_IE >= 0x0300)
/**
 * This message retrieves the bounding rectangle for a specified item in a
 * header control.
 *
 * @param iIndex Zero-based index of the header control item for which to
 *        retrieve the bounding rectangle
 * @param lpItemRect Long pointer to a RECT structure that receives the
 *        bounding rectangle data
 * @return Nonzero indicates success. Zero indicates failure
 */
#define HDM_GETITEMRECT (HDM_FIRST+7)
/**
 * This message assigns an image list to an existing header control.
 *
 * @param himl Handle to an image list
 * @return Returns the handle to the image list previously associated with
 *        the control. The message returns NULL upon failure, or if no
 *        image list was set previously.
 */
#define HDM_SETIMAGELIST	(HDM_FIRST+8)
/**
 * This message retrieves the handle to the image list that has been set
 * for an existing header control.
 *
 * @return Returns a handle to the image list set for the header control
 */
#define HDM_GETIMAGELIST	(HDM_FIRST+9)
/**
 * This message retrieves an index value for an item based on its order in
 * the header control.
 *
 * @param iOrder Order in which the item appears within the header control,
 *        from left to right. For example, the index value of the item in
 *        the far left column would be 0. The value for the next item to
 *        the right would be 1, and so on.
 * @return Returns INT that indicates the item index. If iOrder is invalid
 *        (negative or too large), the return value equals iOrder.
 */
#define HDM_ORDERTOINDEX	(HDM_FIRST+15)
/**
 * This message creates a transparent version of an item's image within an
 * existing header control.
 *
 * @param iIndex Zero-based index of the item within the header control.
 *        The image assigned to this item is the basis for the transparent
 *        image.
 * @return Returns a handle to an image list that contains the new image as
 *        its only element
 */
#define HDM_CREATEDRAGIMAGE	(HDM_FIRST+16)
/**
 * This message retrieves the current left-to-right order of items in a
 * header control.
 *
 * @param iSize Size of the buffer at lpiArray, in elements. This value
 *        must equal the value returned by HDM_GETITEMCOUNT.
 * @param lpiArray Long pointer to the buffer that receives the index
 *        values for items in the header. The buffer must be large enough
 *        to hold the total number of header items * sizeof(int). The
 *        following code example shows how to reserve enough memory to hold
 *        the index values.
 * @return Returns nonzero if successful, and the buffer at lpiArray
 *        receives the item number for each item in the header control, in
 *        the order in which they appear from left to right. Otherwise, the
 *        message returns zero.
 */
#define HDM_GETORDERARRAY	(HDM_FIRST+17)
/**
 * This message sets the left-to-right order of header items.
 *
 * @param iSize Size of the buffer at lpiArray, in elements. This value
 *        must equal the value returned by HDM_GETITEMCOUNT.
 * @param lpiArray Long pointer to an array that specifies the order in
 *        which items should be displayed, from left to right. For example,
 *        if the contents of the array are {2,0,1}, the control displays
 *        item 2, item 0, and item 1 in that order, from left to right.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define HDM_SETORDERARRAY	(HDM_FIRST+18)
/**
 * This message changes the divider color between header items to indicate
 * the destination of an external drag-and-drop operation.
 *
 * This message creates an effect that a header control automatically
 * produces when it has the HDS_DRAGDROP style. The HDM_SETHOTDIVIDER
 * message is intended for use when the owner of the control manually
 * handles drag-and-drop operations.
 *
 * @param flag Specifies the type of value represented by dwInputValue. It
 *        is one of the following values: Value Description TRUE Indicates
 *        that dwInputValue holds the client coordinates of the pointer
 *        FALSE Indicates that dwInputValue holds a divider index value
 * @param dwInputValue Value held in dwInputValue is interpreted based upon
 *        the value of flag. If flag is TRUE, dwInputValue represents the
 *        x- and y-coordinates of the pointer. The x-coordinate is in the
 *        low-order word, and the y-coordinate is in the high-order word.
 *        When the header control receives the message, it highlights the
 *        appropriate divider based on the dwInputValue coordinates. If
 *        flag is FALSE, dwInputValue represents the integer index of the
 *        divider highlighted.
 * @return Returns a value equal to the index of the divider that the
 *        control highlighted
 */
#define HDM_SETHOTDIVIDER	(HDM_FIRST+19)
#endif
#if (_WIN32_IE >= 0x0400)
#define HDM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#define HDM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#endif
#define HHT_NOWHERE	1
#define HHT_ONHEADER	2
#define HHT_ONDIVIDER	4
#define HHT_ONDIVOPEN	8
#define HHT_ABOVE	256
#define HHT_BELOW	512
#define HHT_TORIGHT	1024
#define HHT_TOLEFT	2048
/**
 * This message tests a point to determine which header item, if any, is at
 * the specified point.
 *
 * @param phdhti Pointer to an HDHITTESTINFO structure that contains the
 *        position to test and receive test result data.
 * @return The index of the item at the specified position, if any,
 *        indicates success. -1 indicates failure.
 */
#define HDM_HITTEST	(HDM_FIRST+6)
#define HDN_ITEMCHANGINGA	(HDN_FIRST-0)
#define HDN_ITEMCHANGINGW	(HDN_FIRST-20)
#define HDN_ITEMCHANGEDA	(HDN_FIRST-1)
#define HDN_ITEMCHANGEDW	(HDN_FIRST-21)
#define HDN_ITEMCLICKA	(HDN_FIRST-2)
#define HDN_ITEMCLICKW	(HDN_FIRST-22)
#define HDN_ITEMDBLCLICKA	(HDN_FIRST-3)
#define HDN_ITEMDBLCLICKW	(HDN_FIRST-23)
#define HDN_DIVIDERDBLCLICKA	(HDN_FIRST-5)
#define HDN_DIVIDERDBLCLICKW	(HDN_FIRST-25)
#define HDN_BEGINTRACKA	(HDN_FIRST-6)
#define HDN_BEGINTRACKW	(HDN_FIRST-26)
#define HDN_ENDTRACKA	(HDN_FIRST-7)
#define HDN_ENDTRACKW	(HDN_FIRST-27)
#define HDN_TRACKA	(HDN_FIRST-8)
#define HDN_TRACKW	(HDN_FIRST-28)
#if _WIN32_IE >= 0x0300
/**
 * This notification message is sent by a header control when a drag
 * operation has ended on one of its items. It is sent only by header
 * controls set to the HDS_DRAGDROP style, and is sent as a WM_NOTIFY
 * message.
 *
 * If the owner is performing external (manual) drag-and-drop management,
 * it must return FALSE. The owner then must reorder header items manually
 * by sending HDM_SETITEM or HDM_SETORDERARRAY.
 *
 * @param pNMHeader Pointer to an NMHEADER structure that contains data
 *        about the header item dragged
 * @return To enable the control to automatically place and reorder the
 *        item, return FALSE. Return TRUE to prevent the item from being
 *        placed.
 */
#define HDN_ENDDRAG	(HDN_FIRST-11)
/**
 * This notification message is sent by a header control when a drag
 * operation has begun on one of its items. It is sent only by header
 * controls set to the HDS_DRAGDROP style, and is sent as a WM_NOTIFY
 * message.
 *
 * A header control defaults to automatically managing drag-and-drop
 * reordering. Returning TRUE to indicate external (manual) drag-and-drop
 * management enables the owner of the control to provide custom services
 * as part of the drag-and-drop process.
 *
 * @param pNMHeader Pointer to an NMHEADER structure that contains data
 *        about the header item dragged
 * @return To enable the header control to automatically manage
 *        drag-and-drop operations, return FALSE. If the owner of the
 *        control is manually performing drag-and-drop reordering, return
 *        TRUE.
 */
#define HDN_BEGINDRAG	(HDN_FIRST-10)
#define HDN_GETDISPINFOA (HDN_FIRST-9)
#define HDN_GETDISPINFOW (HDN_FIRST-29)
#endif
#if (_WIN32_IE >= 0x0400)
#define HICF_OTHER 0x00
#define HICF_MOUSE 0x01
#define HICF_ARROWKEYS 0x02
#define HICF_ACCELERATOR 0x04
#define HICF_DUPACCEL 0x08
#define HICF_ENTERING 0x10
#define HICF_LEAVING 0x20
#define HICF_RESELECT 0x40
#define HICF_LMOUSE 0x80
#define HICF_TOGGLEDROPDOWN 0x100
#endif /* _WIN32_IE >= 0x0400 */
#define IPM_CLEARADDRESS	(WM_USER+100)
#define IPM_SETADDRESS	(WM_USER+101)
#define IPM_GETADDRESS	(WM_USER+102)
#define IPM_SETRANGE	(WM_USER+103)
#define IPM_SETFOCUS	(WM_USER+104)
#define IPM_ISBLANK	(WM_USER+105)
#if (_WIN32_IE >= 0x0500) || (_WIN32_WCE >= 0x300)
#define I_INDENTCALLBACK (-1)
#define I_IMAGENONE (-2)
#endif
#define CMB_MASKED 2
#define TBSTATE_CHECKED	1
#define TBSTATE_PRESSED	2
#define TBSTATE_ENABLED	4
#define TBSTATE_HIDDEN	8
#define TBSTATE_INDETERMINATE	16
#define TBSTATE_WRAP	32
#if (_WIN32_IE >= 0x0300)
#define TBSTATE_ELLIPSES 0x40
#endif
#if (_WIN32_IE >= 0x0400)
#define TBSTATE_MARKED	0x0080
#endif
#define TBSTYLE_BUTTON	0
#define TBSTYLE_SEP	1
#define TBSTYLE_CHECK	2
#define TBSTYLE_GROUP	4
#define TBSTYLE_CHECKGROUP	(TBSTYLE_GROUP|TBSTYLE_CHECK)
#if (_WIN32_IE >= 0x0300)
#define TBSTYLE_DROPDOWN	8
#endif
#if (_WIN32_IE >= 0x0400)
#define TBSTYLE_AUTOSIZE	16
#define TBSTYLE_NOPREFIX	32
#endif
#define TBSTYLE_TOOLTIPS	256
#define TBSTYLE_WRAPABLE	512
#define TBSTYLE_ALTDRAG	1024
#if (_WIN32_IE >= 0x0300)
#define TBSTYLE_FLAT 2048
#define TBSTYLE_LIST 4096
#define TBSTYLE_CUSTOMERASE 8192
#endif
#if (_WIN32_IE >= 0x0400)
#define TBSTYLE_REGISTERDROP	0x4000
#define TBSTYLE_TRANSPARENT	0x8000
#define TBSTYLE_EX_DRAWDDARROWS	0x00000001
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_IE >= 0x0501)
#define TBSTYLE_EX_MIXEDBUTTONS 8
#define TBSTYLE_EX_HIDECLIPPEDBUTTONS 16
#endif /* _WIN32_IE >= 0x0501 */
#if (_WIN32_WINNT >= 0x0501)
#define TBSTYLE_EX_DOUBLEBUFFER	0x80
#endif /* _WIN32_WINNT >= 0x0501 */
#if (_WIN32_IE >= 0x0500)
#define BTNS_BUTTON	TBSTYLE_BUTTON
#define BTNS_SEP	TBSTYLE_SEP
#define BTNS_CHECK	TBSTYLE_CHECK
#define BTNS_GROUP	TBSTYLE_GROUP
#define BTNS_CHECKGROUP	TBSTYLE_CHECKGROUP
#define BTNS_DROPDOWN	TBSTYLE_DROPDOWN
#define BTNS_AUTOSIZE	TBSTYLE_AUTOSIZE
#define BTNS_NOPREFIX	TBSTYLE_NOPREFIX
#define BTNS_WHOLEDROPDOWN	0x0080
#endif  /* _WIN32_IE >= 0x0500 */
#if _WIN32_IE >= 0x0501
#define BTNS_SHOWTEXT	0x0040
#endif
#if (_WIN32_IE >= 0x0400)
#define TBCDRF_NOEDGES	0x10000
#define TBCDRF_HILITEHOTTRACK	0x20000
#define TBCDRF_NOOFFSET	0x40000
#define TBCDRF_NOMARK	0x80000
#define TBCDRF_NOETCHEDEFFECT	0x100000
#endif /* _WIN32_IE >= 0x0400 */
#define HINST_COMMCTRL	((HINSTANCE)-1)
#define IDB_STD_SMALL_COLOR	0
#define IDB_STD_LARGE_COLOR	1
#define IDB_VIEW_SMALL_COLOR	4
#define IDB_VIEW_LARGE_COLOR	5
#if (_WIN32_IE >= 0x0300)
#define IDB_HIST_SMALL_COLOR	8
#define IDB_HIST_LARGE_COLOR	9
#endif
#define STD_CUT	0
#define STD_COPY	1
#define STD_PASTE	2
#define STD_UNDO	3
#define STD_REDOW	4
#define STD_DELETE	5
#define STD_FILENEW	6
#define STD_FILEOPEN	7
#define STD_FILESAVE	8
#define STD_PRINTPRE	9
#define STD_PROPERTIES	10
#define STD_HELP	11
#define STD_FIND	12
#define STD_REPLACE	13
#define STD_PRINT	14
#define VIEW_LARGEICONS	0
#define VIEW_SMALLICONS	1
#define VIEW_LIST	2
#define VIEW_DETAILS	3
#define VIEW_SORTNAME	4
#define VIEW_SORTSIZE	5
#define VIEW_SORTDATE	6
#define VIEW_SORTTYPE	7
#define VIEW_PARENTFOLDER	8
#define VIEW_NETCONNECT	9
#define VIEW_NETDISCONNECT	10
#define VIEW_NEWFOLDER	11
/**
 * This message enables or disables the specified button in a toolbar.
 *
 * @param idButton Command identifier of the button to enable or disable.
 * @param fEnable Enable flag. If set to TRUE, the button is enabled. If
 *        set to FALSE, the button is disabled.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_ENABLEBUTTON	(WM_USER+1)
/**
 * This message checks or unchecks a specified button in a toolbar.
 *
 * @param idButton Command identifier of the button to check.
 * @param fCheck Check flag. If set to TRUE, the check is added. If set to
 *        FALSE, the check is removed.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_CHECKBUTTON	(WM_USER+2)
/**
 * This message releases the specified button in a toolbar.
 *
 * @param idButton Command identifier of the button to press or release.
 * @param fPress Press flag. If set to TRUE, the button is pressed. If set
 *        to FALSE, the button is released.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_PRESSBUTTON	(WM_USER+3)
/**
 * This message hides or shows the specified button in a toolbar.
 *
 * @param idButton Command identifier of the button to hide or show.
 * @param fShow Show flag. If set to TRUE, the button is hidden. If set to
 *        FALSE, the button is shown.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_HIDEBUTTON	(WM_USER+4)
/**
 * This message sets or clears the indeterminate state of the specified
 * button in a toolbar.
 *
 * @param idButton Command identifier of the button for which indeterminate
 *        state is to be set or cleared.
 * @param fIndeterminate Indeterminate flag. If set to TRUE, the
 *        indeterminate state is set. If set to FALSE, the state is
 *        cleared.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_INDETERMINATE	(WM_USER+5)
#if (_WIN32_IE >= 0x0400)
#define TB_MARKBUTTON           (WM_USER+6)
#endif
/**
 * This message determines whether the specified button in a toolbar is
 * enabled.
 *
 * @param idButton Command identifier of the button.
 * @return Nonzero indicates that the button is enables. Zero indicates
 *        that the button is disabled.
 */
#define TB_ISBUTTONENABLED	(WM_USER+9)
/**
 * This message determines whether the specified button in a toolbar is
 * checked.
 *
 * @param idButton Command identifier of the button.
 * @return Nonzero indicates that the button is checked. Zero indicates
 *        otherwise.
 */
#define TB_ISBUTTONCHECKED	(WM_USER+10)
/**
 * This message determines whether the specified button in a toolbar is
 * pressed.
 *
 * @param idButton Command identifier of the button.
 * @return Nonzero indicates that the button is pressed. Zero indicates
 *        otherwise.
 */
#define TB_ISBUTTONPRESSED	(WM_USER+11)
/**
 * This message determines whether the specified button in a toolbar is
 * hidden.
 *
 * @param idButton Command identifier of the button.
 * @return Nonzero indicates that the button is hidden. Zero indicates
 *        otherwise.
 */
#define TB_ISBUTTONHIDDEN	(WM_USER+12)
/**
 * This message determines whether the specified button in a toolbar is
 * indeterminate.
 *
 * @param idButton Command identifier of the button.
 * @return Nonzero indicates that the button is indeterminate. Zero
 *        indicates otherwise.
 */
#define TB_ISBUTTONINDETERMINATE	(WM_USER+13)
#if (_WIN32_IE >= 0x0400)
/**
 * This message checks the highlight state of a toolbar button.
 *
 * @param idButton Command identifier for a toolbar button.
 * @return Nonzero indicates that the button is highlighted. Zero indicates
 *        otherwise.
 */
#define TB_ISBUTTONHIGHLIGHTED	(WM_USER+14)
#endif
/**
 * This message sets the state for the specified button in a toolbar.
 *
 * @param idButton Command identifier of the button.
 * @param fState State flags. This parameter can be a combination of
 *        values. For information about toolbar button state values, see
 *        the Windows CE User Interface Services Guide.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_SETSTATE	(WM_USER+17)
/**
 * This message retrieves information about the state of the specified
 * button in a toolbar, such as whether it is enabled, pressed, or checked.
 *
 * @param idButton Command identifier of the button for which to retrieve
 *        information.
 * @return The button state information indicates success. -1 indicates
 *        failure. The button state information can be a combination of
 *        values. For information about toolbar button state values, see
 *        the Windows CE User Interface Services Guide.
 */
#define TB_GETSTATE	(WM_USER+18)
/**
 * This message adds one or more images to the list of button images
 * available for a toolbar.
 *
 * The bitmap specified in the lptbab parameter can contain multiple
 * images. The number of images in the bitmap must be specified in the
 * nButtons parameter.
 *
 * The bitmap width should be nButtons multiplied by the image width, and
 * the bitmap height should be equal to the image height.
 *
 * The default image width is 16 pixels and the default image height is 15
 * pixels. The default image width and height can be changed using
 * TB_SETBITMAPSIZE. If the size of the bitmap is not the default or if you
 * have multiple images in a bitmap, you must call TB_SETBITMAPSIZE to
 * change the default size settings.
 *
 * @param nButtons Number of button images in the bitmap. If lptbab
 *        specifies a system-defined bitmap, this parameter is ignored.
 * @param lptbab Long pointer to a TBADDBITMAP structure that contains the
 *        identifier of a bitmap resource and the handle to the module
 *        instance with the executable file that contains the bitmap
 *        resource.
 * @return The index of the first new image indicates success. -1 indicates
 *        failure.
 */
#define TB_ADDBITMAP	(WM_USER+19)
#if (_WIN32_IE >= 0x0400)
#define TB_ADDBUTTONSA	(WM_USER+20)
#define TB_INSERTBUTTONA	(WM_USER+21)
#else
#if defined(_WIN32_WCE) && GRIMACE_CE >= 2
/**
 * This message adds one or more buttons to a toolbar.
 *
 * @param uNumButtons Number of buttons to add.
 * @param lpButtons Long pointer to an array of TBBUTTON structures that
 *        contain information about the buttons to add. There must be the
 *        same number of elements in the array as buttons specified by
 *        uNumButtons.
 * @return True indicates success. FALSE indicates failure.
 */
#define TB_ADDBUTTONS	(WM_USER+68)
/**
 * This message inserts a button in a toolbar.
 *
 * @param iButton Zero-based index of a button. The message inserts the new
 *        button to the left of this button.
 * @param lpButton Long pointer to a TBBUTTON structure that contains
 *        information about the button to insert.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_INSERTBUTTON	(WM_USER+67)
#else
#define TB_ADDBUTTONS	(WM_USER+20)
#define TB_INSERTBUTTON	(WM_USER+21)
#endif
#endif
/**
 * This message deletes a button from the toolbar.
 *
 * @param iButton Zero-based index of the button to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_DELETEBUTTON	(WM_USER+22)
/**
 * This message retrieves information about the specified button in a
 * toolbar.
 *
 * @param iButton Zero-based index of the button for which to retrieve
 *        information.
 * @param lpButton Long pointer to the TBBUTTON structure that receives the
 *        button information.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_GETBUTTON	(WM_USER+23)
/**
 * This message retrieves a count of the buttons currently in the toolbar.
 *
 * @return The count of the buttons indicates success.
 */
#define TB_BUTTONCOUNT	(WM_USER+24)
/**
 * This message retrieves the zero-based index for the button associated
 * with the specified command identifier.
 *
 * @param idButton Command identifier associated with the button.
 * @return The zero-based index for the button indicates success.
 */
#define TB_COMMANDTOINDEX	(WM_USER+25)
#define TB_SAVERESTOREA	(WM_USER+26)
#define TB_SAVERESTOREW	(WM_USER+76)
#define TB_CUSTOMIZE	(WM_USER+27)
#define TB_ADDSTRINGA	(WM_USER+28)
#define TB_ADDSTRINGW	(WM_USER+77)
/**
 * This message retrieves the bounding rectangle of a button in a toolbar.
 *
 * @param iButton Zero-based index of the button for which to retrieve
 *        information.
 * @param lprc Long pointer to a RECT structure that receives the
 *        coordinates of the bounding rectangle.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_GETITEMRECT	(WM_USER+29)
/**
 * This message specifies the size of the TBBUTTON structure.
 *
 * The system uses the size to determine which version of the common
 * control dynamic-link library (DLL) is being used.
 *
 * @param cb Size, in bytes, of the TBBUTTON structure.
 * @return None.
 */
#define TB_BUTTONSTRUCTSIZE	(WM_USER+30)
/**
 * This message sets the size of the buttons to be added to a toolbar.
 *
 * @param dxButton Specifies the width, in pixels, of the buttons.
 * @param dyButton Specifies the height, in pixels, of the buttons.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_SETBUTTONSIZE	(WM_USER+31)
/**
 * This message sets the size of the bitmapped images to be added to a
 * toolbar.
 *
 * The default image width is 16 pixels and the default image height is 15
 * pixels. If the size of the bitmap is not the default or if you have
 * multiple images in a bitmap, you must call TB_SETBITMAPSIZE to change
 * the default size settings. Otherwise, the bitmap or image is truncated
 * or is not displayed.
 *
 * @param dxBitmap Specifies the width, in pixels, of the bitmapped images.
 * @param dyBitmap Specifies the height, in pixels, of the bitmapped
 *        images.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_SETBITMAPSIZE	(WM_USER+32)
/**
 * This message causes a toolbar to be resized.
 *
 * @return None.
 */
#define TB_AUTOSIZE	(WM_USER+33)
/**
 * This message retrieves the handle to the ToolTip control, if any,
 * associated with the toolbar.
 *
 * @return Returns the handle to the ToolTip control, or NULL if the
 *        toolbar has no associated ToolTip.
 */
#define TB_GETTOOLTIPS	(WM_USER+35)
#ifdef _WIN32_WCE
/**
 * This message adds an array of ToolTip strings to a toolbar.
 *
 * The TB_SETTOOLTIPS message in Windows CE is different from the
 * TB_SETTOOLTIPS message in Windows 95 and Windows NT.
 *
 * Windows CE does not support ToolTip controls, so instead of taking a
 * handle to a ToolTip control as its sole parameter, the TB_SETTOOLTIPS
 * message in Windows CE takes both a wParam and an lParam. The wParam
 * represents the number of ToolTip strings to associate with the toolbar,
 * and the lParam is the array of strings to be displayed as ToolTips.
 *
 * In Windows CE, only toolbar buttons can have ToolTip strings; menus and
 * combo boxes cannot.
 *
 * The TB_SETTOOLTIPS message uses the memory address passed in the
 * lpToolTips parameter. Do not release the memory allocated for the
 * ToolTip string array until the program exits.
 *
 * @param hwndToolTip Handle to the ToolTip control.
 * @return None.
 */
#define TB_SETTOOLTIPS	(WM_USER+81)
#else
#define TB_SETTOOLTIPS	(WM_USER+36)
#endif
/**
 * This message sets the parent window for a toolbar.
 *
 * @param hwndParent Handle to the window to receive notification messages.
 * @return The return value is a handle to the previous notification
 *        window, or NULL if there is no previous notification window.
 */
#define TB_SETPARENT	(WM_USER+37)
/**
 * This message sets the number of rows of buttons in a toolbar.
 *
 * @param cRows Number of rows requested. The minimum number of rows is
 *        one, and the maximum number of rows is equal to the number of
 *        buttons in the toolbar.
 * @param fLarger Flag that indicates whether to create more rows than
 *        requested when the system cannot create the number of rows
 *        specified by cRows. If set to TRUE, the system creates more rows.
 *        If set to FALSE, the system creates fewer rows.
 * @param lprc Long pointer to a RECT structure that receives the bounding
 *        rectangle of the toolbar after the rows are set.
 * @return None.
 */
#define TB_SETROWS	(WM_USER+39)
/**
 * This message retrieves the number of rows of buttons in a toolbar with
 * the TBSTYLE_WRAPABLE style.
 *
 * @return The number of rows indicates success.
 */
#define TB_GETROWS	(WM_USER+40)
/**
 * This message retrieves the flags for the current bitmap.
 *
 * @return Returns a DWORD value that contains the bitmap flags. If this
 *        value is zero, the toolbar is using a small bitmap. If the
 *        TBBF_LARGE flag is set, the toolbar is using a large bitmap.
 */
#define TB_GETBITMAPFLAGS	(WM_USER+41)
/**
 * This message sets the command identifier of a toolbar button.
 *
 * @param index Zero-based index of the button for which the command
 *        identifier is to be set.
 * @param cmdId Command identifier.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_SETCMDID	(WM_USER+42)
/**
 * This message changes the bitmap for a button in a toolbar.
 *
 * @param idButton Command identifier of the button that is to receive a
 *        new bitmap.
 * @param iBitmap Zero-based index of an image in the toolbar's image list.
 *        The system displays the specified image in the button.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TB_CHANGEBITMAP	(WM_USER+43)
/**
 * This message retrieves the index of the bitmap associated with a button
 * in a toolbar.
 *
 * @param idButton Command identifier of the button whose bitmap index is
 *        to be retrieved.
 * @return The index of the bitmap indicates success. Zero indicates
 *        failure.
 */
#define TB_GETBITMAP	(WM_USER+44)
#define TB_GETBUTTONTEXTA	(WM_USER+45)
#define TB_GETBUTTONTEXTW	(WM_USER+75)
/**
 * This message replaces an existing bitmap with a new bitmap.
 *
 * @param ptbrb Pointer to a TBREPLACEBITMAP structure that contains the
 *        information of the bitmap to be replaced and the new bitmap.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_REPLACEBITMAP	(WM_USER+46)
/**
 * This message retrieves the current width and height of toolbar buttons,
 * in pixels.
 *
 * @return Returns a DWORD value that contains the width and height values
 *        in the low-order word and high-order word, respectively.
 */
#define TB_GETBUTTONSIZE	(WM_USER+58)
#if defined(_WIN32_WCE) && GRIMACE_WCE == 101
/**
 * This message sets the minimum and maximum button widths in the toolbar
 * control.
 *
 * @param cxMin Minimum button width, in pixels. Toolbar buttons are never
 *        narrower than this value.
 * @param cxMax Maximum button width, in pixels. If button text is too
 *        wide, the control displays it with ellipsis points.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_SETBUTTONWIDTH	(WM_USER+52)
#else
#define TB_SETBUTTONWIDTH	(WM_USER+59)
#endif
#if (_WIN32_IE >= 0x0300)
/**
 * This message sets the indentation for the first button in a toolbar
 * control.
 *
 * @param iIndent Specifies the indentation, in pixels.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_SETINDENT	(WM_USER+47)
/**
 * This message sets the image list that the toolbar will use to display
 * buttons that are in their default state.
 *
 * A toolbar control uses himlNew to display buttons in their default
 * state; that is, when they are not hot or disabled.
 *
 * @param himlNew Handle to the image list that will be set. If this
 *        parameter is NULL, no images are displayed in the buttons.
 * @return Returns the handle to the image list previously used to display
 *        buttons in their default state, or NULL if no image list was
 *        previously set.
 */
#define TB_SETIMAGELIST	(WM_USER+48)
/**
 * This message retrieves the image list that a toolbar control uses to
 * display buttons in their default state. A toolbar control uses this
 * image list to display buttons in their default state; that is, when they
 * are not hot or disabled.
 *
 * @return Returns the handle to the image list or NULL if no image list is
 *        set.
 */
#define TB_GETIMAGELIST	(WM_USER+49)
/**
 * This message loads bitmaps into a toolbar control's image list.
 *
 * If your application specifies HINST_COMMCTRL, then you must use the
 * proper image index values when you prepare TBBUTTON structures prior to
 * sending the TB_ADDBUTTONS message. For a list of image index values for
 * these preset bitmaps, see "Toolbar Standard Button Image Index Values."
 *
 * Windows CE does not support IDB_HIST_LARGE_COLOR and
 * IDB_HIST_SMALL_COLOR values for the iBitmapID parameter.
 *
 * @param iBitmapID Identifier of a bitmap that contains the images to be
 *        loaded. If hinst is HINST_COMMCTRL, this parameter specifies a
 *        set of standard toolbar button bitmaps, shown in the following
 *        list. Otherwise, this parameter must be the identifier of a
 *        bitmap resource that will be added to the image list as a single
 *        image. Value Description IDB_STD_LARGE_COLOR Standard bitmaps in
 *        large size IDB_STD_SMALL_COLOR Standard bitmaps in small size
 *        IDB_VIEW_LARGE_COLOR View bitmaps in large size
 *        IDB_VIEW_SMALL_COLOR View bitmaps in small size
 * @param hinst Program instance handle to the calling application. This
 *        parameter can be HINST_COMMCTRL to load a standard image list.
 * @return Returns an INT value that represents the count of images in the
 *        image list, not including the one just added. Returns zero if the
 *        toolbar has no image list or if the existing image list is empty.
 */
#define TB_LOADIMAGES	(WM_USER+50)
/**
 * This message retrieves the bounding rectangle for a specified toolbar
 * button.
 *
 * @param iID Button identifier.
 * @param lprc Returns nonzero if successful, or zero otherwise. A RECT
 *        structure that receives the bounding rectangle information.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_GETRECT	(WM_USER+51)
#define TB_SETHOTIMAGELIST	(WM_USER+52)
#define TB_GETHOTIMAGELIST	(WM_USER+53)
/**
 * This message sets the image list that the toolbar control will use to
 * display disabled buttons.
 *
 * @param himlNewDisabled Handle to the image list to be set.
 * @return Returns the handle to the image list previously used to display
 *        disabled buttons, or NULL if no image list was previously set.
 */
#define TB_SETDISABLEDIMAGELIST (WM_USER+54)
/**
 * This message retrieves the image list that a toolbar control uses to
 * display disabled buttons.
 *
 * @return Returns the handle to the disabled image list or NULL if no
 *        disabled image list is set.
 */
#define TB_GETDISABLEDIMAGELIST	(WM_USER+55)
/**
 * This message sets the style for a toolbar control.
 *
 * @param dwStyle Specifies the styles to be set for the control. It can be
 *        a combination of toolbar control styles.
 */
#define TB_SETSTYLE	(WM_USER+56)
/**
 * This message retrieves the styles currently in use for a toolbar
 * control.
 *
 * @return Returns a DWORD value that is a combination of toolbar control
 *        styles.
 */
#define TB_GETSTYLE	(WM_USER+57)
#define TB_GETBUTTONSIZE	(WM_USER+58)
#if defined(_WIN32_WCE) && GRIMACE_WCE == 101
#define TB_SETBUTTONWIDTH	(WM_USER+52)
#else
#define TB_SETBUTTONWIDTH	(WM_USER+59)
#endif
/**
 * This message sets the maximum number of text rows displayed on a toolbar
 * button.
 *
 * @param iMaxRows Maximum number of rows to be set.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_SETMAXTEXTROWS	(WM_USER+60)
/**
 * This message retrieves the maximum number of text rows that can be
 * displayed on a toolbar button.
 *
 * @return Returns an INT value representing the maximum number of text
 *        rows that the control displays for a button.
 */
#define TB_GETTEXTROWS	(WM_USER+61)
#endif
#if _WIN32_IE >= 0x400
#define TB_GETOBJECT	(WM_USER+62)
#define TB_GETBUTTONINFOW	(WM_USER+63)
#define TB_SETBUTTONINFOW	(WM_USER+64)
#define TB_GETBUTTONINFOA	(WM_USER+65)
#define TB_SETBUTTONINFOA	(WM_USER+66)
#define TB_INSERTBUTTONW	(WM_USER+67)
#define TB_ADDBUTTONSW	(WM_USER+68)
#define TB_HITTEST	(WM_USER+69)
#define TB_SETEXTENDEDSTYLE	(WM_USER+84)
#define TB_GETEXTENDEDSTYLE	(WM_USER+85)
/**
 * This message sets the text drawing flags for the toolbar.
 *
 * The dwMask parameter allows you to specify which flags will be used when
 * drawing the text, even if these flags are turned off. For example, if
 * you do not want the DT_CENTER flag used when drawing text, you would add
 * the DT_CENTER flag to dwMask and not specify the DT_CENTER flag in
 * dwDTFlags. This prevents the control from passing the DT_CENTER flag to
 * DrawText.
 *
 * @param dwMask A combination of one or more of the DT_* flags, specified
 *        in DrawText, that specifies which bits in dwDTFlags are used when
 *        drawing the text.
 * @param dwDTFlags A combination of one or more of the DT_* flags,
 *        specified in DrawText, that specify how the button text will be
 *        drawn. This value is passed to DrawText when the button text is
 *        drawn.
 * @return Returns the previous text drawing flags.
 */
#define TB_SETDRAWTEXTFLAGS	(WM_USER+70)
#define TB_GETHOTITEM	(WM_USER+71)
#define TB_SETHOTITEM	(WM_USER+72)
#define TB_SETANCHORHIGHLIGHT	(WM_USER+73)
#define TB_GETANCHORHIGHLIGHT	(WM_USER+74)
#define TB_MAPACCELERATORA	(WM_USER+78)
#define TB_GETINSERTMARK	(WM_USER+79)
#define TB_SETINSERTMARK	(WM_USER+80)
#define TB_INSERTMARKHITTEST	(WM_USER+81)
#define TB_MOVEBUTTON		(WM_USER+82)
#define TB_GETMAXSIZE		(WM_USER+83)
#define TB_SETEXTENDEDSTYLE	(WM_USER+84)
#define TB_GETEXTENDEDSTYLE	(WM_USER+85)
#define TB_GETPADDING		(WM_USER+86)
#define TB_SETPADDING		(WM_USER+87)
#define TB_SETINSERTMARKCOLOR	(WM_USER+88)
#define TB_GETINSERTMARKCOLOR	(WM_USER+89)
#define TB_MAPACCELERATORW	(WM_USER+90)
#define TB_GETSTRINGW		(WM_USER+91)
#define TB_GETSTRINGA		(WM_USER+92)
#define TB_SETCOLORSCHEME	CCM_SETCOLORSCHEME
#define TB_GETCOLORSCHEME	CCM_GETCOLORSCHEME
#define TB_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#define TB_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#endif
#define TBBF_LARGE 1
#define TBN_GETBUTTONINFOA	(TBN_FIRST-0)
/**
 * This notification message notifies a toolbar's parent window that the
 * user has begun dragging a button in a toolbar. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * @param lpnmtb Long pointer to an NMTOOLBAR structure. The iItem member
 *        contains the command identifier of the button being dragged.
 * @return None.
 */
#define TBN_BEGINDRAG	(TBN_FIRST-1)
/**
 * This notification message notifies the toolbar's parent window that the
 * user has stopped dragging a button in a toolbar. It is sent in the form
 * of a WM_NOTIFY message.
 *
 * @param lpnmtb Long pointer to an NMTOOLBAR structure. The iItem member
 *        contains the command identifier of the button being dragged.
 * @return None.
 */
#define TBN_ENDDRAG	(TBN_FIRST-2)
#define TBN_BEGINADJUST	(TBN_FIRST-3)
#define TBN_ENDADJUST	(TBN_FIRST-4)
#define TBN_RESET	(TBN_FIRST-5)
#define TBN_QUERYINSERT	(TBN_FIRST-6)
#define TBN_QUERYDELETE	(TBN_FIRST-7)
#define TBN_TOOLBARCHANGE	(TBN_FIRST-8)
#define TBN_CUSTHELP	(TBN_FIRST-9)
#if (_WIN32_IE >= 0x0300)
/**
 * This notification message sent by a toolbar control when the user clicks
 * a button that uses the TBSTYLE_DROPDOWN style. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * @param lpnmtb Long pointer to an NMTOOLBAR structure that contains
 *        information about this notification. For this notification
 *        message, only the hdr and iItem members of this structure are
 *        valid.
 * @return Returns FALSE to allow the toolbar control to display the
 *        drop-down list; returns TRUE to prevent the control from
 *        displaying the list.
 */
#define TBN_DROPDOWN	(TBN_FIRST-10)
#endif
#if (_WIN32_IE >= 0x0400)
#define TBN_HOTITEMCHANGE	(TBN_FIRST-13)
#define TBN_DRAGOUT	(TBN_FIRST-14)
#define TBN_DELETINGBUTTON	(TBN_FIRST-15)
#define TBN_GETDISPINFOA	(TBN_FIRST-16)
#define TBN_GETDISPINFOW	(TBN_FIRST-17)
#define TBN_GETINFOTIPA	(TBN_FIRST-18)
#define TBN_GETINFOTIPW	(TBN_FIRST-19)
#define TBN_GETBUTTONINFOW	(TBN_FIRST-20)
#endif
#if (_WIN32_IE >= 0x0500)
#define TBN_RESTORE	(TBN_FIRST-21)
#define TBN_SAVE	(TBN_FIRST-22)
#define TBN_INITCUSTOMIZE	(TBN_FIRST-23)
#define TBNRF_HIDEHELP	1
#define TBNRF_ENDCUSTOMIZE	2
#define TBNF_IMAGE	1
#define TBNF_TEXT	2
#define TBNF_DI_SETITEM	0x10000000
#endif /* _WIN32_IE >= 0x0500 */
#define TTS_ALWAYSTIP	1
#define TTS_NOPREFIX	2
#if( _WIN32_IE >= 0x0500 )
#define TTS_NOANIMATE	0x10
#define TTS_NOFADE	0x20
#define TTS_BALLOON	0x40
#define TTS_CLOSE	0x80
#endif /* _WIN32_IE >= 0x0500 */
#define TTF_IDISHWND	1
#define TTF_CENTERTIP	2
#define TTF_RTLREADING	4
#define TTF_SUBCLASS	16
#if (_WIN32_IE >= 0x0300)
#define TTF_TRACK 0x0020
#define TTF_ABSOLUTE 0x0080
#define TTF_TRANSPARENT 0x0100
#if (_WIN32_IE >= 0x0501)
#define TTF_PARSELINKS 0x1000
#endif
#define TTF_DI_SETITEM 0x8000
#define TBCD_TICS 1
#define TBCD_THUMB 2
#define TBCD_CHANNEL 3
#endif /* _WIN32_IE >= 0x0300 */
#if (_WIN32_IE >= 0x0400)
#define TBDDRET_DEFAULT 0
#define TBDDRET_NODEFAULT 1
#define TBDDRET_TREATPRESSED 2
#define TBIMHT_AFTER 1
#define TBIMHT_BACKGROUND 2
#endif
#define TTDT_AUTOMATIC	0
#define TTDT_RESHOW	1
#define TTDT_AUTOPOP	2
#define TTDT_INITIAL	3
#define TTM_ACTIVATE	(WM_USER+1)
#define TTM_SETDELAYTIME	(WM_USER+3)
#define TTM_ADDTOOLA	(WM_USER+4)
#define TTM_ADDTOOLW	(WM_USER+50)
#define TTM_DELTOOLA	(WM_USER+5)
#define TTM_DELTOOLW	(WM_USER+51)
#define TTM_NEWTOOLRECTA	(WM_USER+6)
#define TTM_NEWTOOLRECTW	(WM_USER+52)
#define TTM_RELAYEVENT	(WM_USER+7)
#define TTM_GETTOOLINFOA	(WM_USER+8)
#define TTM_GETTOOLINFOW	(WM_USER+53)
#define TTM_SETTOOLINFOA	(WM_USER+9)
#define TTM_SETTOOLINFOW	(WM_USER+54)
#define TTM_HITTESTA	(WM_USER+10)
#define TTM_HITTESTW	(WM_USER+55)
#define TTM_GETTEXTA	(WM_USER+11)
#define TTM_GETTEXTW	(WM_USER+56)
#define TTM_UPDATETIPTEXTA	(WM_USER+12)
#define TTM_UPDATETIPTEXTW	(WM_USER+57)
#define TTM_GETTOOLCOUNT	(WM_USER+13)
#define TTM_ENUMTOOLSA	(WM_USER+14)
#define TTM_ENUMTOOLSW	(WM_USER+58)
#define TTM_GETCURRENTTOOLA	(WM_USER+15)
#define TTM_GETCURRENTTOOLW	(WM_USER+59)
#define TTM_WINDOWFROMPOINT	(WM_USER+16)
#if (_WIN32_IE >= 0x0300)
#define TTM_TRACKACTIVATE	  (WM_USER+17)  
#define TTM_TRACKPOSITION	  (WM_USER+18)  
#define TTM_SETTIPBKCOLOR	  (WM_USER+19)
#define TTM_SETTIPTEXTCOLOR	(WM_USER+20)
#define TTM_GETDELAYTIME	   (WM_USER+21)
#define TTM_GETTIPBKCOLOR	  (WM_USER+22)
#define TTM_GETTIPTEXTCOLOR	(WM_USER+23)
#define TTM_SETMAXTIPWIDTH	 (WM_USER+24)
#define TTM_GETMAXTIPWIDTH	 (WM_USER+25)
#define TTM_SETMARGIN		 (WM_USER+26)  
#define TTM_GETMARGIN		 (WM_USER+27)  
#define TTM_POP			  (WM_USER+28)
#endif /* _WIN32_IE */
#if (_WIN32_IE >= 0x0400)			/* IE4.0 ??? */
#define TTM_UPDATE		    (WM_USER+29)
#define TTM_GETBUBBLESIZE	(WM_USER+30)
#define TTM_ADJUSTRECT	(WM_USER+31)
#define TTM_SETTITLEA	(WM_USER+32)
#define TTM_SETTITLEW	(WM_USER+33)
#endif
#define TTN_GETDISPINFOA    (TTN_FIRST - 0)
#define TTN_GETDISPINFOW    (TTN_FIRST - 10)
#define TTN_NEEDTEXTA	TTN_GETDISPINFOA
#define TTN_NEEDTEXTW	TTN_GETDISPINFOW
#define TTN_SHOW	(TTN_FIRST-1)
#define TTN_POP	(TTN_FIRST-2)
#define UD_MAXVAL	0x7fff
#define UD_MINVAL	(-UD_MAXVAL)
/**
 * This notification message is sent by the OS to the parent window of an
 * up-down control when the position of the control is about to change.
 * This happens when the user requests a change in the value by pressing
 * the control's up or down arrow. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * The UDN_DELTAPOS notification is sent before the WM_HSCROLL message,
 * which actually changes the control's position. This enables you to
 * examine, accept, modify, or reject the change.
 *
 * @param lpnmud Long pointer to an NMUPDOWN structure that contains
 *        information about the position change. The iPos member of this
 *        structure contains the current position of the control. The
 *        iDelta member of the structure is a signed integer that contains
 *        the proposed change in position. If the user has clicked the up
 *        button, this is a positive value. If the user has clicked the
 *        down button, this is a negative value.
 * @return Nonzero prevents the change in the control's position. Zero
 *        accepts the change.
 */
#define UDN_DELTAPOS (UDN_FIRST-1)
#define UDS_WRAP	1
#define UDS_SETBUDDYINT	2
#define UDS_ALIGNRIGHT	4
#define UDS_ALIGNLEFT	8
#define UDS_AUTOBUDDY	16
#define UDS_ARROWKEYS	32
#define UDS_HORZ	64
#define UDS_NOTHOUSANDS	128
#if ( _WIN32_IE >= 0x0300 )
#define UDS_HOTTRACK	0x0100
#endif /* _WIN32_IE >= 0x0300 */
/**
 * This message sets the minimum and maximum positions, or the range, for a
 * up-down control.
 *
 * @param nUpper and nLower Maximum position and minimum position for the
 *        up-down control. Neither position can be greater than the
 *        UD_MAXVAL value or less than the UD_MINVAL value. In addition,
 *        the difference between the two positions cannot exceed UD_MAXVAL.
 * @return None
 */
#define UDM_SETRANGE	(WM_USER+101)
/**
 * This message retrieves the minimum and maximum positions, or the range,
 * for an up-down control.
 *
 * @return The return value is a 32-bit value that contains the minimum and
 *        maximum positions. The low-order word is the maximum position for
 *        the control, and the high-order word is the minimum position.
 */
#define UDM_GETRANGE	(WM_USER+102)
/**
 * This message sets the current position for an up-down control.
 *
 * @param nPos New position for the up-down control. This parameter must be
 *        in the range specified by the upper and lower limits for the
 *        control.
 * @return The previous position indicates success.
 */
#define UDM_SETPOS	(WM_USER+103)
/**
 * This message retrieves the current position of an up-down control.
 *
 * @return The return value is the current position in the low-order word.
 *        If an error occurred, the high-order word is nonzero.
 */
#define UDM_GETPOS	(WM_USER+104)
/**
 * This message sets the buddy window for an up-down control.
 *
 * If hwndBuddy is not NULL, it must specify an edit control because
 * up/down controls can only be buddied with edit controls.
 *
 * @param hwndBuddy Handle to the new buddy window.
 * @return The handle to the previous buddy window indicates success.
 */
#define UDM_SETBUDDY	(WM_USER+105)
/**
 * This message retrieves the handle of the current buddy window.
 *
 * @return The handle to the current buddy window indicates success.
 */
#define UDM_GETBUDDY	(WM_USER+106)
/**
 * This message sets the acceleration for an up-down control.
 *
 * @param nAccels Number of UDACCEL structures specified by aAccels.
 * @param aAccels Pointer to an array of UDACCEL structures that contain
 *        acceleration information. Elements should be sorted in ascending
 *        order based on the nSec member.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define UDM_SETACCEL	(WM_USER+107)
/**
 * This message retrieves acceleration information for an up-down control.
 *
 * @param cAccels Number of elements in the array specified by paAccels.
 * @param paAccels Pointer to an array of UDACCEL structures that receive
 *        acceleration information.
 * @return The return value is the number of accelerator structures
 *        retrieved. If the cAccels parameter is zero and the paAccels
 *        parameter is NULL, the return value is the number of accelerators
 *        currently set for the control.
 */
#define UDM_GETACCEL	(WM_USER+108)
/**
 * This message sets the radix base for an up-down control. The base value
 * determines whether the buddy window displays numbers in decimal or
 * hexadecimal digits. Hexadecimal numbers are always unsigned, and decimal
 * numbers are signed.
 *
 * @param nBase New base value for the control. This parameter can be 10
 *        for decimal or 16 for hexadecimal.
 * @return The previous base value indicates success. Zero indicates that
 *        an invalid base was given.
 */
#define UDM_SETBASE	(WM_USER+109)
/**
 * The UDM_GETBASE message retrieves the current radix base-that is, either
 * base 10 or 16-for an up-down control.
 *
 * @return The current base value indicates success.
 */
#define UDM_GETBASE	(WM_USER+110)
#if (_WIN32_IE >= 0x0400)
/**
 * This message sets the 32-bit range of an up-down control.
 *
 * @param iLow Integer value that represents the new lower limit of the
 *        up-down control range.
 * @param iHigh Integer value that represents the new upper limit of the
 *        up-down control range.
 * @return None
 */
#define UDM_SETRANGE32	(WM_USER+111)
/**
 * This message retrieves the 32-bit range of an up-down control.
 *
 * @param pLow Pointer to an integer that receives the lower limit of the
 *        up-down control range. This parameter may be NULL.
 * @param pHigh Pointer to an integer that receives the upper limit of the
 *        up-down control range. This parameter may be NULL.
 * @return None
 */
#define UDM_GETRANGE32	(WM_USER+112)
#define UDM_SETPOS32	(WM_USER+113)
#define UDM_GETPOS32	(WM_USER+114)
#endif
#if (_WIN32_IE >= 0x0500)
#define UDM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#define UDM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#endif
#define SB_SETTEXTA	(WM_USER+1)
#define SB_SETTEXTW	(WM_USER+11)
#define SB_GETTEXTA	(WM_USER+2)
#define SB_GETTEXTW	(WM_USER+13)
#define SB_GETTEXTLENGTHA	(WM_USER+3)
#define SB_GETTEXTLENGTHW	(WM_USER+12)
#define SB_SETPARTS	(WM_USER+4)
#define SB_GETPARTS	(WM_USER+6)
#define SB_GETBORDERS	(WM_USER+7)
#define SB_SETMINHEIGHT	(WM_USER+8)
#define SB_SIMPLE	(WM_USER+9)
#define SB_GETRECT	(WM_USER+10)
#define SBT_OWNERDRAW	0x1000
#define SBT_NOBORDERS	256
#define SBT_POPOUT	512
#define SBT_RTLREADING	1024
#if( _WIN32_IE >= 0x0400 )
#define SBT_TOOLTIPS	0x0800
/**
 * This notification message sent by a status window control when the
 * simple mode changes due to a SB_SIMPLE message. The SBN_SIMPLEMODECHANGE
 * notification message is sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmh Long pointer to an NMHDR structure that contains
 *        information about the notification.
 */
#define SBN_SIMPLEMODECHANGE	(SBN_FIRST)
#endif /* _WIN32_IE >= 0x0400 */
#define TBS_AUTOTICKS	1
#define TBS_VERT	2
#define TBS_HORZ	0
#define TBS_TOP	4
#define TBS_BOTTOM	0
#define TBS_LEFT	4
#define TBS_RIGHT	0
#define TBS_BOTH	8
#define TBS_NOTICKS	16
#define TBS_ENABLESELRANGE	32
#define TBS_FIXEDLENGTH	64
#define TBS_NOTHUMB	128
#if (_WIN32_IE >= 0x0300)
#define TBS_TOOLTIPS 0x0100
#define TBTS_TOP 0
#define TBTS_LEFT 1
#define TBTS_BOTTOM 2
#define TBTS_RIGHT 3
#endif
#if (_WIN32_IE >= 0x0500)
#define TBS_REVERSED 0x0200
#endif
#if (_WIN32_IE >= 0x0501)
#define TBS_DOWNISLEFT 0x0400
#endif
#if _WIN32_IE >= 0x400
#define TBIF_BYINDEX 0x80000000
#define TBIF_COMMAND 32
#define TBIF_IMAGE 1
#define TBIF_LPARAM 16
#define TBIF_SIZE 64
#define TBIF_STATE 4
#define TBIF_STYLE 8
#define TBIF_TEXT 2
#endif
/**
 * This message retrieves the current position of the slider in a trackbar.
 *
 * @return Returns a 32-bit value that specifies the current logical
 *        position of the trackbar's slider.
 */
#define TBM_GETPOS	(WM_USER)
/**
 * This message retrieves the minimum position for the slider in a
 * trackbar.
 *
 * @return Returns a 32-bit value that specifies the minimum position in
 *        the trackbar's range of minimum to maximum slider positions.
 */
#define TBM_GETRANGEMIN	(WM_USER+1)
/**
 * This message retrieves the maximum position for the slider in a
 * trackbar.
 *
 * @return Returns a 32-bit value that specifies the maximum position in
 *        the trackbar's range of minimum to maximum slider positions.
 */
#define TBM_GETRANGEMAX	(WM_USER+2)
/**
 * This message retrieves the position of a tick mark in a trackbar.
 *
 * @param iTic Zero-based index that identifies a tick mark. Valid indexes
 *        are in the range from zero to two less than the tick count
 *        returned by the TBM_GETNUMTICS message.
 * @return The logical position of the specified tick mark indicates
 *        success. -1 indicates that iTic does not specify a valid index.
 */
#define TBM_GETTIC	(WM_USER+3)
/**
 * This message sets the position of a tick mark in a trackbar.
 *
 * A trackbar creates its own first and last tick marks. Do not use this
 * message to set the first and last tick marks.
 *
 * @param lPosition Position of the tick mark. This parameter can be any of
 *        the integer values in the trackbar's range of minimum to maximum
 *        slider positions.
 * @return TRUE indicates that the tick mark is set. FALSE indicates
 *        otherwise.
 */
#define TBM_SETTIC	(WM_USER+4)
/**
 * This message sets the current position of the slider in a trackbar.
 *
 * @param fPosition Redraw flag. If set to TRUE, the message redraws the
 *        control with the slider at the position given by lPosition. If
 *        set to FALSE, the message does not redraw the slider at the new
 *        position. The message sets the value of the slider position (as
 *        returned by the TBM_GETPOS message) regardless of the fPosition
 *        parameter.
 * @param lPosition New logical position of the slider. Valid logical
 *        positions are the integer values in the trackbar's range of
 *        minimum to maximum slider positions. If this value is outside the
 *        control's maximum and minimum range, the position is set to the
 *        maximum or minimum value.
 * @return None.
 */
#define TBM_SETPOS	(WM_USER+5)
/**
 * This message sets the range-minimum and maximum positions-for the slider
 * in a trackbar.
 *
 * If the current slider position is outside the new range, the
 * TBM_SETRANGE message sets the slider position to the new maximum or
 * minimum value.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the trackbar is redrawn
 *        after the range is set. If set to FALSE, the message sets the
 *        range but does not redraw the trackbar.
 * @param lMinimum Minimum position for the slider.
 * @param lMaximum Maximum position for the slider.
 * @return None.
 */
#define TBM_SETRANGE	(WM_USER+6)
/**
 * This message sets the minimum position for the slider in a trackbar.
 *
 * If the current slider position is less than the new minimum, the
 * TBM_SETRANGEMIN message sets the slider position to the new minimum
 * value.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the message redraws the
 *        trackbar after the range is set. If set to FALSE, the message
 *        sets the range but does not redraw the trackbar.
 * @param lMinimum Minimum position for the slider.
 * @return None.
 */
#define TBM_SETRANGEMIN	(WM_USER+7)
/**
 * This message sets the maximum position for the slider in a trackbar.
 *
 * If the current slider position is greater than the new maximum, the
 * TBM_SETRANGEMAX message sets the slider position to the new maximum
 * value.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the trackbar is redrawn
 *        after the range is set. If set to FALSE, the message sets the
 *        range but does not redraw the trackbar.
 * @param lMaximum Maximum position for the slider.
 * @return None.
 */
#define TBM_SETRANGEMAX	(WM_USER+8)
/**
 * This message removes the current tick marks from a trackbar. This
 * message does not remove the first and last tick marks, which are created
 * automatically by the trackbar.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the trackbar is redrawn
 *        after the tick marks are cleared. If set to FALSE, the message
 *        clears the tick marks but does not redraw the trackbar.
 * @return None.
 */
#define TBM_CLEARTICS	(WM_USER+9)
/**
 * This message sets the starting and ending positions for the current
 * selection in a trackbar. This message is ignored if the trackbar does
 * not have the TBS_ENABLESELRANGE style.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the message redraws the
 *        trackbar after the selection range is set. If set to FALSE, the
 *        message sets the selection range but does not redraw the
 *        trackbar.
 * @param lMinimum Starting logical position for the selection range.
 * @param lMaximum Ending logical position for the selection range.
 * @return None.
 */
#define TBM_SETSEL	(WM_USER+10)
/**
 * This message sets the starting position of the current selection in a
 * trackbar. This message is ignored if the trackbar does not have the
 * TBS_ENABLESELRANGE style.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the message redraws the
 *        trackbar after the selection range is set. If set to FALSE, the
 *        message sets the selection range but does not redraw the
 *        trackbar.
 * @param lStart Starting position of the selection range.
 * @return None.
 */
#define TBM_SETSELSTART	(WM_USER+11)
/**
 * This message sets the ending position of the current selection in a
 * trackbar. This message is ignored if the trackbar does not have the
 * TBS_ENABLESELRANGE style.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the message redraws the
 *        trackbar after the selection range is set. If set to FALSE, the
 *        message sets the selection range but does not redraw the
 *        trackbar.
 * @param lEnd Ending logical position of the selection range.
 * @return None.
 */
#define TBM_SETSELEND	(WM_USER+12)
/**
 * This message retrieves the address of the array that contains the
 * positions of tick marks for a trackbar.
 *
 * @return Returns the address of an array of DWORD values. The elements of
 *        the array specify the logical positions of the trackbar's tick
 *        marks, not including the first and last tick marks created by the
 *        trackbar. The logical positions can be any of the integer values
 *        in the trackbar's range of minimum to maximum slider positions.
 */
#define TBM_GETPTICS	(WM_USER+14)
/**
 * This message retrieves the current physical position of a tick mark in a
 * trackbar.
 *
 * @param iTic Zero-based index that identifies a tick mark. Valid indexes
 *        are in the range from zero to two less than the tick count
 *        returned by the TBM_GETNUMTICS message.
 * @return Returns the distance, in client coordinates, from the left or
 *        top of the trackbar's client area to the specified tick mark. The
 *        return value is the x-coordinate of the tick mark for a
 *        horizontal trackbar or the y-coordinate for a vertical trackbar.
 *        -1 indicates that iTic is not a valid index.
 */
#define TBM_GETTICPOS	(WM_USER+15)
/**
 * This message retrieves the number of tick marks in a trackbar.
 *
 * @return The number of tick marks indicates success.
 */
#define TBM_GETNUMTICS	(WM_USER+16)
/**
 * This message retrieves the starting position of the current selection in
 * a trackbar.
 *
 * A trackbar can have a selection range only if you specified the
 * TBS_ENABLESELRANGE style when you created it.
 *
 * @return Returns a 32-bit value that specifies the starting position of
 *        the current selection range.
 */
#define TBM_GETSELSTART	(WM_USER+17)
/**
 * This message retrieves the ending position of the current selection in a
 * trackbar.
 *
 * A trackbar can have a selection range only if you specified the
 * TBS_ENABLESELRANGE style when you created it.
 *
 * @return Returns a 32-bit value that specifies the ending position of the
 *        current selection range.
 */
#define TBM_GETSELEND	(WM_USER+18)
/**
 * This message clears the current selection in a trackbar.
 *
 * A trackbar can have a selection range only if you specified the
 * TBS_ENABLESELRANGE style when you created it.
 *
 * @param fRedraw Redraw flag. If set to TRUE, the trackbar is redrawn
 *        after the selection is cleared.
 * @return None.
 */
#define TBM_CLEARSEL	(WM_USER+19)
/**
 * This message sets the interval frequency for tick marks in a trackbar.
 * For example, if the frequency is set to two, a tick mark is displayed
 * for every other increment in the trackbar's range. The default setting
 * for the frequency is one; that is, every increment in the range is
 * associated with a tick mark.
 *
 * @param wFreq Frequency of the tick marks.
 * @return None.
 */
#define TBM_SETTICFREQ	(WM_USER+20)
/**
 * This message sets the size of the page for a trackbar. The page size
 * affects how much the slider moves for the TB_PAGEUP and TB_PAGEDOWN
 * notification messages.
 *
 * The trackbar also sends the TB_PAGEUP and TB_PAGEDOWN notification
 * messages to its parent window when it receives keyboard or mouse input
 * that scrolls the page.
 *
 * @param lPageSize New page size.
 * @return Returns a 32-bit value that specifies the previous page size.
 */
#define TBM_SETPAGESIZE	(WM_USER+21)
/**
 * This message retrieves the size of the page for a trackbar. The page
 * size affects how much the slider moves for the TB_PAGEUP and TB_PAGEDOWN
 * notification messages.
 *
 * The trackbar also sends the TB_PAGEUP and TB_PAGEDOWN notification
 * messages to its parent window when it receives keyboard or mouse input
 * that scrolls the page.
 *
 * @return Returns a 32-bit value that specifies the page size for the
 *        trackbar.
 */
#define TBM_GETPAGESIZE	(WM_USER+22)
/**
 * This message sets the size of the line for a trackbar. The line size
 * affects how much the slider moves for the TB_LINEUP and TB_LINEDOWN
 * notification messages.
 *
 * The default setting for the line size is 1.
 *
 * The trackbar also sends the TB_LINEUP and TB_LINEDOWN notification
 * messages to its parent window when the user presses the arrow keys.
 *
 * @param lLineSize New line size.
 * @return Returns a 32-bit value that specifies the previous line size.
 */
#define TBM_SETLINESIZE	(WM_USER+23)
/**
 * This message retrieves the size of the line for a trackbar. The line
 * size affects how much the slider moves for the TB_LINEUP and TB_LINEDOWN
 * notification messages.
 *
 * The default setting for the line size is 1.
 *
 * The trackbar also sends the TB_LINEUP and TB_LINEDOWN notification
 * messages to its parent window when the user presses the arrow keys.
 *
 * @return Returns a 32-bit value that specifies the line size for the
 *        trackbar.
 */
#define TBM_GETLINESIZE	(WM_USER+24)
/**
 * This message retrieves the size and position of the bounding rectangle
 * for the slider in a trackbar.
 *
 * @param lprc Long pointer to a RECT structure. The message fills this
 *        structure with the bounding rectangle of the trackbar's slider,
 *        in client coordinates of the trackbar's window.
 * @return None.
 */
#define TBM_GETTHUMBRECT	(WM_USER+25)
/**
 * This message retrieves the size and position of the bounding rectangle
 * for a trackbar's channel. The channel is the area over which the slider
 * moves. It contains the highlight when a range is selected.
 *
 * @param lprc Long pointer to a RECT structure. The message fills this
 *        structure with the channel's bounding rectangle, in client
 *        coordinates of the trackbar's window.
 * @return None.
 */
#define TBM_GETCHANNELRECT	(WM_USER+26)
/**
 * This message sets the length of the slider in a trackbar. This message
 * is ignored if the trackbar does not have the TBS_FIXEDLENGTH style.
 *
 * @param iLength Length, in pixels, of the slider.
 * @return None.
 */
#define TBM_SETTHUMBLENGTH	(WM_USER+27)
/**
 * This message retrieves the length of the slider in a trackbar.
 *
 * @return The length, in pixels, of the slider indicates success.
 */
#define TBM_GETTHUMBLENGTH	(WM_USER+28)
#define TBM_SETTOOLTIPS	(WM_USER+29)
#define TBM_GETTOOLTIPS	(WM_USER+30)
#define TBM_SETTIPSIDE	(WM_USER+31)
/**
 * This message assigns a window as the buddy window for a trackbar
 * control. Trackbar buddy windows are automatically displayed in a
 * location relative to the control's orientation, horizontal or vertical.
 *
 * Trackbar controls support up to two buddy windows. This can be useful
 * when you must display text or images at each end of the control.
 *
 * @param fLocation Boolean that specifies the location at which to display
 *        the buddy window. It is one of the following values: Value
 *        Description TRUE The buddy appears to the left of the trackbar if
 *        the trackbar control uses the TBS_HORZ style. If the trackbar
 *        uses the TBS_VERT style, the buddy appears above the trackbar
 *        control. FALSE The buddy appears to the right of the trackbar if
 *        the trackbar control uses the TBS_HORZ style. If the trackbar
 *        uses the TBS_VERT style, the buddy appears below the trackbar
 *        control.
 * @param hwndBuddy Handle to the window to be set as the trackbar
 *        control's buddy.
 * @return Returns the handle to the window that was previously assigned to
 *        the control at that location.
 */
#define TBM_SETBUDDY	(WM_USER+32)
/**
 * This message retrieves the handle to a trackbar control buddy window at
 * a specified location. The specified location is relative to the
 * control's orientation, horizontal or vertical.
 *
 * @param fLocation Boolean that specifies which buddy window handle is
 *        retrieved, by relative location. It is one of the following
 *        values: Value Description TRUE Retrieves the handle to the buddy
 *        to the left of the trackbar. If the trackbar control uses the
 *        TBS_VERT style, the message will retrieve the buddy above the
 *        trackbar. FALSE Retrieves the handle to the buddy to the right of
 *        the trackbar. If the trackbar control uses the TBS_VERT style,
 *        the message will retrieve the buddy below the trackbar.
 * @return Returns the handle to the buddy window at the location specified
 *        by fLocation, or NULL if no buddy exists at that location.
 */
#define TBM_GETBUDDY	(WM_USER+33)
#define TBM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT 
#define TBM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#define TB_LINEUP	0
#define TB_LINEDOWN	1
#define TB_PAGEUP	2
#define TB_PAGEDOWN	3
#define TB_THUMBPOSITION	4
#define TB_THUMBTRACK	5
#define TB_TOP	6
#define TB_BOTTOM	7
#define TB_ENDTRACK	8
#define HOTKEYF_SHIFT	1
#define HOTKEYF_CONTROL	2
#define HOTKEYF_ALT	4
#define HOTKEYF_EXT	8
#define HKCOMB_NONE	1
#define HKCOMB_S	2
#define HKCOMB_C	4
#define HKCOMB_A	8
#define HKCOMB_SC	16
#define HKCOMB_SA	32
#define HKCOMB_CA	64
#define HKCOMB_SCA	128
#define HKM_SETHOTKEY	(WM_USER+1)
#define HKM_GETHOTKEY	(WM_USER+2)
#define HKM_SETRULES	(WM_USER+3)
/**
 * This message sets the minimum and maximum values for a progress bar and
 * redraws the bar to reflect the new range.
 *
 * @param nMinRange Minimum range value. By default, the minimum value is
 *        zero.
 * @param nMaxRange Maximum range value. By default, the maximum value is
 *        100.
 * @return The previous range values indicate success. Zero indicates
 *        otherwise. The low-order word specifies the previous minimum
 *        value, and the high-order word specifies the previous maximum
 *        value.
 */
#define PBM_SETRANGE	(WM_USER+1)
/**
 * This message sets the current position for a progress bar and redraws
 * the bar to reflect the new position.
 *
 * @param nNewPos Signed integer that becomes the new position.
 * @return The previous position indicates success.
 */
#define PBM_SETPOS	(WM_USER+2)
/**
 * This message advances the current position of a progress bar by a
 * specified increment and redraws the bar to reflect the new position.
 *
 * @param nIncrement Amount to advance the position.
 * @return The previous position indicates success.
 */
#define PBM_DELTAPOS	(WM_USER+3)
/**
 * This message specifies the step increment for a progress bar. The step
 * increment is the amount by which the progress bar increases its current
 * position whenever it receives a PBM_STEPIT message. By default, the step
 * increment is set to 10.
 *
 * @param nStepInc New step increment.
 * @return The previous step increment indicates success.
 */
#define PBM_SETSTEP	(WM_USER+4)
/**
 * This message advances the current position for a progress bar by the
 * step increment and redraws the bar to reflect the new position. An
 * application sets the step increment by sending the PBM_SETSTEP message.
 *
 * @return The previous position indicates success.
 */
#define PBM_STEPIT	(WM_USER+5)
/**
 * This message sets the range of a progress bar control to a 32-bit value.
 *
 * To retrieve the entire high and low 32-bit values, use the PBM_GETRANGE
 * message.
 *
 * @param iLowLim Specifies a 32-bit value that represents the low limit to
 *        be set for the progress bar control.
 * @param iHighLim Specifies a 32-bit value that represents the high limit
 *        to be set for the progress bar control.
 * @return Returns a DWORD that holds the previous 16-bit low limit in its
 *        low-order word, and the previous 16-bit high limit in its
 *        high-order word. If the previous ranges were 32-bit values, the
 *        return value consists of the low-order words of both 32-bit
 *        limits.
 */
#define PBM_SETRANGE32	1030
/**
 * This message retrieves information about the current high and low limits
 * of a specified progress bar control.
 *
 * @param fWhichLimit Boolean that specifies which limit value is to be
 *        used as the message's return value. It is one of the following
 *        values: Value Description TRUE Return the low limit. FALSE Return
 *        the high limit.
 * @param ppBRange Pointer to a pointer to a PBRANGE structure that is to
 *        be filled with the high and low limits of the progress bar
 *        control. If this parameter is set to NULL, the control will
 *        return only the limit specified by fWhichLimit.
 * @return Returns an INT that represents the limit value specified by
 *        fWhichLimit. If lParam is not NULL, lParam must point to a
 *        PBRANGE structure that is to be filled with both limit values.
 */
#define PBM_GETRANGE	1031
/**
 * This message retrieves the current position of the progress bar.
 *
 * @return Returns a UINT that represents the current position of the
 *        progress bar.
 */
#define PBM_GETPOS	1032
#define PBM_SETBARCOLOR	1033
#define PBM_SETBKCOLOR	CCM_SETBKCOLOR
#define PBS_SMOOTH	1
#define PBS_VERTICAL	4
#define LVS_ICON	0
#define LVS_REPORT	1
#define LVS_SMALLICON	2
#define LVS_LIST	3
#define LVS_TYPEMASK	3
#define LVS_SINGLESEL	4
#define LVS_SHOWSELALWAYS	8
#define LVS_SORTASCENDING	16
#define LVS_SORTDESCENDING	32
#define LVS_SHAREIMAGELISTS	64
#define LVS_NOLABELWRAP	128
#define LVS_AUTOARRANGE	256
#define LVS_EDITLABELS	512
#define LVS_NOSCROLL	0x2000
#define LVS_TYPESTYLEMASK	0xfc00
#define LVS_ALIGNTOP	0
#define LVS_ALIGNLEFT	0x800
#define LVS_ALIGNMASK	0xc00
#define LVS_OWNERDRAWFIXED	0x400
#define LVS_NOCOLUMNHEADER	0x4000
#define LVS_NOSORTHEADER	0x8000
#if (_WIN32_IE >= 0x0300)
#define CDIS_CHECKED 8
#define CDIS_DEFAULT 32
#define CDIS_DISABLED 4
#define CDIS_FOCUS 16
#define CDIS_GRAYED 2
#define CDIS_HOT 64
#define CDIS_SELECTED 1
#define CDIS_MARKED 128
#define CDIS_INDETERMINATE 256
#if (_WIN32_WINNT >= 0x0501)
#define CDIS_SHOWKEYBOARDCUES 512
#endif
#define CDDS_POSTERASE 4
#define CDDS_POSTPAINT 2
#define CDDS_PREERASE 3
#define CDDS_PREPAINT 1
#define CDDS_ITEM 65536
#define CDDS_ITEMPOSTERASE 65540
#define CDDS_ITEMPOSTPAINT 65538
#define CDDS_ITEMPREERASE 65539
#define CDDS_ITEMPREPAINT 65537
#if (_WIN32_IE >= 0x0400)
#define CDDS_SUBITEM 0x20000
#endif
#define CDRF_DODEFAULT 0x00
#define CDRF_NOTIFYITEMDRAW 0x20
#define CDRF_NOTIFYSUBITEMDRAW 0x20
#define CDRF_NOTIFYITEMERASE 0x80
#define CDRF_NOTIFYPOSTERASE 0x40
#define CDRF_NOTIFYPOSTPAINT 0x10
#define CDRF_NEWFONT 0x02
#if defined(_WIN32_WCE) && GRIMACE_CE == 1
#define CDRF_SKIPDEFAULT 0x01
#else
#define CDRF_SKIPDEFAULT 0x04
#endif
#if (_WIN32_IE >= 0x0400)
#define LVBKIF_SOURCE_NONE      0x00000000
#define LVBKIF_SOURCE_HBITMAP   0x00000001
#define LVBKIF_SOURCE_URL       0x00000002
#define LVBKIF_SOURCE_MASK      0x00000003
#define LVBKIF_STYLE_NORMAL     0x00000000
#define LVBKIF_STYLE_TILE       0x00000010
#define LVBKIF_STYLE_MASK       0x00000010
#endif /* _WIN32_IE >=0x0400 */
#if (_WIN32_WINNT >= 0x501)
#define LVBKIF_FLAG_TILEOFFSET  0x00000100
#define LVBKIF_TYPE_WATERMARK   0x10000000
#endif /* _WIN32_WINNT >= 0x501 */
#define LVS_OWNERDATA 4096
#define LVS_EX_CHECKBOXES 4
#define LVS_EX_FULLROWSELECT 32
#define LVS_EX_GRIDLINES 1
#define LVS_EX_HEADERDRAGDROP 16
#define LVS_EX_ONECLICKACTIVATE 64
#define LVS_EX_SUBITEMIMAGES 2
#define LVS_EX_TRACKSELECT 8
#define LVS_EX_TWOCLICKACTIVATE 128
#define LVSICF_NOINVALIDATEALL	0x00000001
#define LVSICF_NOSCROLL	0x00000002
#if( _WIN32_IE >= 0x0400 )
#define LVS_EX_FLATSB	0x00000100
#define LVS_EX_REGIONAL	0x00000200
#define LVS_EX_INFOTIP	0x00000400
#define LVS_EX_UNDERLINEHOT	0x00000800
#define LVS_EX_UNDERLINECOLD	0x00001000
#define LVS_EX_MULTIWORKAREAS	0x00002000
#endif /* _WIN32_IE >=0x0400 */
#if( _WIN32_IE >= 0x0500 )
#define LVS_EX_LABELTIP	0x00004000
#define LVS_EX_BORDERSELECT	0x00008000
#endif  /* _WIN32_IE >= 0x0500 */
#endif  /* _WIN32_IE >= 0x0300 */
#define LVSIL_NORMAL	0
#define LVSIL_SMALL	1
#define LVSIL_STATE	2
/**
 * This message retrieves the background color of a list view control. You
 * can send this message explicitly or by using the ListView_GetBkColor
 * macro.
 *
 * @return The background color of the list view control indicates success.
 */
#define LVM_GETBKCOLOR	LVM_FIRST
/**
 * This message sets the background color of a list view control. You can
 * send this message explicitly or by using the ListView_SetBkColor macro.
 *
 * @param clrBk Background color to set or the CLR_NONE value for no
 *        background color. List view controls with background colors
 *        redraw themselves significantly faster than those without
 *        background colors.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETBKCOLOR	(LVM_FIRST+1)
/**
 * This message retrieves the handle of an image list used for drawing list
 * view items. You can send this message explicitly or by using the
 * ListView_GetImageList macro.
 *
 * Windows CE supports a new value for the iImageList parameter (WPARAM).
 * The LVSIL_HEADER constant specifies that the image list to be retrieved
 * is the image list displayed in the list view's header control in report
 * view.
 *
 * @param iImageList Image list to retrieve. It is one of the following
 *        values: Value Description LVSIL_NORMAL Image list with large
 *        icons. LVSIL_SMALL Image list with small icons. LVSIL_STATE Image
 *        list with state images.
 * @return The handle to the specified image list indicates success. NULL
 *        indicates otherwise.
 */
#define LVM_GETIMAGELIST	(LVM_FIRST+2)
/**
 * This message assigns a new image list to a list view control. You can
 * send this message explicitly or by using the ListView_SetImageList
 * macro.
 *
 * Windows CE supports a new value for the iImageList parameter (WPARAM).
 * The LVSIL_HEADER constant specifies that, in report view, the image list
 * will be displayed in the list view's header control.
 *
 * @param iImageList Type of image list. It is one of the following values:
 *        Value Description LVSIL_NORMAL Image list with large icons
 *        LVSIL_SMALL Image list with small icons LVSIL_STATE Image list
 *        with state images
 * @param himl Handle to the image list to assign
 * @return The handle to the image list previously associated with the
 *        control indicates success. NULL indicates otherwise.
 */
#define LVM_SETIMAGELIST	(LVM_FIRST+3)
/**
 * This message retrieves the number of items in a list view control. You
 * can send this message explicitly or by using the ListView_GetItemCount
 * macro.
 *
 * @return The number of items indicates success.
 */
#define LVM_GETITEMCOUNT	(LVM_FIRST+4)
#define LVM_SORTITEMSEX		(LVM_FIRST+81)
#if (_WIN32_WINNT >= 0x501)
#define LVM_SETSELECTEDCOLUMN	(LVM_FIRST+140)
#endif
#define LVM_SETVIEW		(LVM_FIRST+142)
#define LVM_GETVIEW		(LVM_FIRST+143)
#define LVM_INSERTGROUP		(LVM_FIRST+145)
#define LVM_SETGROUPINFO	(LVM_FIRST+147)
#define LVM_GETGROUPINFO	(LVM_FIRST+149)
#define LVM_REMOVEGROUP		(LVM_FIRST+150)
#define LVM_MOVEGROUP		(LVM_FIRST+151)
#define LVM_SETGROUPMETRICS	(LVM_FIRST+155)
#define LVM_GETGROUPMETRICS	(LVM_FIRST+156)
#define LVM_ENABLEGROUPVIEW	(LVM_FIRST+157)
#define LVM_SORTGROUPS		(LVM_FIRST+158)
#define LVM_INSERTGROUPSORTED	(LVM_FIRST+159)
#define LVM_REMOVEALLGROUPS	(LVM_FIRST+160)
#define LVM_HASGROUP		(LVM_FIRST+161)
#define LVM_SETTILEVIEWINFO	(LVM_FIRST+162)
#define LVM_GETTILEVIEWINFO	(LVM_FIRST+163)
#define LVM_SETTILEINFO		(LVM_FIRST+164)
#define LVM_GETTILEINFO		(LVM_FIRST+165)
#define LVM_SETINSERTMARK	(LVM_FIRST+166)
#define LVM_GETINSERTMARK	(LVM_FIRST+167)
#define LVM_INSERTMARKHITTEST	(LVM_FIRST+168)
#define LVM_GETINSERTMARKRECT	(LVM_FIRST+169)
#define LVM_SETINSERTMARKCOLOR	(LVM_FIRST+170)
#define LVM_GETINSERTMARKCOLOR	(LVM_FIRST+171)
#define LVM_SETINFOTIP		(LVM_FIRST+173)
#define LVM_GETSELECTEDCOLUMN	(LVM_FIRST+174)
#define LVM_ISGROUPVIEWENABLED	(LVM_FIRST+175)
#define LVM_GETOUTLINECOLOR	(LVM_FIRST+176)
#define LVM_SETOUTLINECOLOR	(LVM_FIRST+177)
#define LVM_CANCELEDITLABEL	(LVM_FIRST+179)
#define LVM_MAPIDTOINDEX	(LVM_FIRST+181)
#define LVIF_TEXT	1
#define LVIF_IMAGE	2
#define LVIF_PARAM	4
#define LVIF_STATE	8
#if (_WIN32_IE >= 0x0300)
#define LVIF_INDENT 16
#define LVIF_NORECOMPUTE 2048
#endif
#if (_WIN32_WINNT >= 0x0501)
#define LVIF_GROUPID 256
#define LVIF_COLUMNS 512
#endif
#define LVIS_FOCUSED	1
#define LVIS_SELECTED	2
#define LVIS_CUT	4
#define LVIS_DROPHILITED	8
#define LVIS_OVERLAYMASK	0xF00
#define LVIS_STATEIMAGEMASK	0xF000
#define LPSTR_TEXTCALLBACKW	((LPWSTR)-1)
#define LPSTR_TEXTCALLBACKA	((LPSTR)-1)
#define I_IMAGECALLBACK	(-1)
#define LVM_GETITEMA	(LVM_FIRST+5)
#define LVM_GETITEMW	(LVM_FIRST+75)
#define LVM_SETITEMA	(LVM_FIRST+6)
#define LVM_SETITEMW	(LVM_FIRST+76)
#define LVM_INSERTITEMA	(LVM_FIRST+7)
#define LVM_INSERTITEMW	(LVM_FIRST+77)
/**
 * This message removes an item from a list view control. You can send this
 * message explicitly or by using the ListView_DeleteItem macro.
 *
 * @param iItem Index of the list view item to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_DELETEITEM	(LVM_FIRST+8)
/**
 * This message removes all items from a list view control. You can send
 * this message explicitly or by using the ListView_DeleteAllItems macro.
 *
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_DELETEALLITEMS	(LVM_FIRST+9)
/**
 * This message retrieves the callback mask for a list view control. You
 * can send this message explicitly or by using the
 * ListView_GetCallbackMask macro.
 *
 * @return The callback mask indicates success.
 */
#define LVM_GETCALLBACKMASK	(LVM_FIRST+10)
/**
 * This message sets the callback mask for a list view control. You can
 * send this message explicitly or by using the ListView_SetCallbackMask
 * macro.
 *
 * @param mask Value of the callback mask. The bits of the mask indicate
 *        the item states or images for which the application stores the
 *        current state data. It can be any combination of the following
 *        constants: Constant Description LVIS_CUT The item is marked for a
 *        cut-and-paste operation. LVIS_DROPHILITED The item is highlighted
 *        as a drag-and-drop target. LVIS_FOCUSED The item has the focus.
 *        LVIS_SELECTED The item is selected. LVIS_OVERLAYMASK The
 *        application stores the image list index of the current overlay
 *        image for each item. LVIS_STATEIMAGEMASK The application stores
 *        the image list index of the current state image for each item.
 *        The callback mask of a list view control is a set of bit flags
 *        that specify the item states for which the application, rather
 *        than the control, stores the current data. The callback mask
 *        applies to all of the control items, unlike the callback item
 *        designation, which applies to a specific item. The callback mask
 *        is zero by default, meaning that the list view control stores all
 *        item state data. After creating a list view control and
 *        initializing its items, you can send the LVM_SETCALLBACKMASK
 *        message to change the callback mask. To get the current callback
 *        mask, send the LVM_GETCALLBACKMASK message. For more information
 *        about overlay images and state images, see List View Image Lists.
 *        For more information on overlay images, state images, and list
 *        view callbacks, see the Windows CE User Interface Services Guide.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETCALLBACKMASK	(LVM_FIRST+11)
#if( _WIN32_IE >= 0x0400 )
#define LVM_SETBKIMAGEA	(LVM_FIRST + 68)
#define LVM_SETBKIMAGEW	(LVM_FIRST + 138)
#define LVM_GETBKIMAGEA	(LVM_FIRST + 69)
#define LVM_GETBKIMAGEW	(LVM_FIRST + 139)
#define LV_MAX_WORKAREAS	16
#define LVM_SETWORKAREAS	(LVM_FIRST+65)
#define LVM_GETWORKAREAS	(LVM_FIRST+70)
#define LVM_GETNUMBEROFWORKAREAS	(LVM_FIRST+73)
/**
 * This message retrieves the selection mark from a list view control.
 *
 * The selection mark is the item index from which a multiple selection
 * starts.
 *
 * @return Returns the zero-based selection mark, or -1 if there is no
 *        selection mark.
 */
#define LVM_GETSELECTIONMARK	(LVM_FIRST+66)
/**
 * This message sets the selection mark in a list view control.
 *
 * @param iIndex Zero-based index of the new selection mark The selection
 *        mark is the item index from which a multiple selection starts.
 *        This message does not affect the selection state of the item.
 * @return Returns the previous selection mark, or -1 if there is no
 *        previous selection mark.
 */
#define LVM_SETSELECTIONMARK	(LVM_FIRST+67)
#define LVM_SETHOVERTIME	(LVM_FIRST+71)
#define LVM_GETHOVERTIME	(LVM_FIRST+72)
#define LVM_SETTOOLTIPS	(LVM_FIRST+74)
#define LVM_GETTOOLTIPS	(LVM_FIRST+78)
#define LVM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define LVM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#endif /* _WIN32_IE >= 0x0400 */
#define LVNI_ALL	0
#define LVNI_FOCUSED	1
#define LVNI_SELECTED	2
#define LVNI_CUT	4
#define LVNI_DROPHILITED	8
#define LVNI_ABOVE	256
#define LVNI_BELOW	512
#define LVNI_TOLEFT	1024
#define LVNI_TORIGHT	2048
/**
 * This message searches for a list view item that has the specified
 * properties and bears the specified relationship to a specified item. You
 * can send this message explicitly or by using the ListView_GetNextItem
 * macro.
 *
 * @param iStart Index of the item to begin the search with, or -1 to find
 *        the first item that matches the specified flags. The specified
 *        item itself is excluded from the search.
 * @param flags Specifies the relationship to the item specified in iStart.
 *        This is the following value: Value Description LVNI_ALL Searches
 *        for a subsequent item by index (the default value). The physical
 *        relationship to iStart is specified with one of the following
 *        values: Value Description LVNI_ABOVE Searches for an item that is
 *        above the specified item. LVNI_BELOW Searches for an item that is
 *        below the specified item. LVNI_TOLEFT Searches for an item to the
 *        left of the specified item. LVNI_TORIGHT Searches for an item to
 *        the right of the specified item. The state of the item to find is
 *        specified with one or a combination of the following values:
 *        Value Description LVNI_CUT The item has the LVIS_CUT state flag
 *        set. LVNI_DROPHILITED The item has the LVIS_DROPHILITED state
 *        flag set. LVNI_FOCUSED The item has the LVIS_FOCUSED state flag
 *        set. LVNI_SELECTED The item has the LVIS_SELECTED state flag set.
 *        If an item does not have all of the specified state flags set,
 *        the search continues with the next item.
 * @return The index of the next item indicates success. -1 indicates
 *        failure.
 */
#define LVM_GETNEXTITEM	(LVM_FIRST+12)
#define LVFI_PARAM	1
#define LVFI_STRING	2
#define LVFI_PARTIAL	8
#define LVFI_WRAP	32
#define LVFI_NEARESTXY	64
#define LVIF_DI_SETITEM	0x1000
#define LVM_FINDITEMA	(LVM_FIRST+13)
#define LVM_FINDITEMW	(LVM_FIRST+83)
#define LVIR_BOUNDS	0
#define LVIR_ICON	1
#define LVIR_LABEL	2
#define LVIR_SELECTBOUNDS	3
/**
 * This message retrieves the bounding rectangle for all or part of an item
 * in the current view. You can send this message explicitly or by using
 * the ListView_GetItemRect macro.
 *
 * @param i Index of the list view item.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle. When the message is sent, the left member of this
 *        structure is used to determine the portion of the list view item
 *        for which to retrieve the bounding rectangle. This will be one of
 *        the code values defined in ListView_GetItemRect.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_GETITEMRECT	(LVM_FIRST+14)
/**
 * This message moves an item to a specified position in a list view
 * control, which must be in icon or small icon view. You can send this
 * message explicitly or by using the ListView_SetItemPosition macro.
 *
 * @param i Index of the list view item
 * @param x and y Specifies the new position of the item's upper-left
 *        corner, in view coordinates
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETITEMPOSITION	(LVM_FIRST+15)
/**
 * This message retrieves the position of a list view item. You can send
 * this message explicitly or by using the ListView_GetItemPosition macro.
 *
 * @param i Index of the list view item.
 * @param ppt Pointer to a POINT structure that receives the position of
 *        the item's upper-left corner, in view coordinates.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_GETITEMPOSITION	(LVM_FIRST+16)
#define LVM_GETSTRINGWIDTHA	(LVM_FIRST+17)
#define LVM_GETSTRINGWIDTHW	(LVM_FIRST+87)
#define LVHT_NOWHERE	1
#define LVHT_ONITEMICON	2
#define LVHT_ONITEMLABEL	4
#define LVHT_ONITEMSTATEICON	8
#define LVHT_ONITEM	(LVHT_ONITEMICON|LVHT_ONITEMLABEL|LVHT_ONITEMSTATEICON)
#define LVHT_ABOVE	8
#define LVHT_BELOW	16
#define LVHT_TORIGHT	32
#define LVHT_TOLEFT	64
/**
 * This message determines which list view item, if any, is at a specified
 * position. You can send this message explicitly or by using the
 * ListView_HitTest macro.
 *
 * @param pinfo Pointer to an LVHITTESTINFO structure that contains the
 *        position to hit test and receives hit test result data.
 * @return The index of the item at the specified position, if any,
 *        indicates success. -1 indicates failure.
 */
#define LVM_HITTEST	(LVM_FIRST+18)
/**
 * This message ensures that a list view item is entirely or at least
 * partially visible, scrolling the list view control if necessary. You can
 * send this message explicitly or by using the ListView_EnsureVisible
 * macro.
 *
 * @param i Index of the list view item.
 * @param fPartialOK Boolean that specifies whether the item must be
 *        entirely visible. If set to TRUE, no scrolling occurs if the item
 *        is at least partially visible.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_ENSUREVISIBLE	(LVM_FIRST+19)
/**
 * This message scrolls the content of a list view control. You can send
 * this message explicitly or by using the ListView_Scroll macro.
 *
 * @param dx Specifies the amount of horizontal scrolling in pixels. If the
 *        list view control is in list view, this value specifies the
 *        number of columns to scroll.
 * @param dy Specifies the amount of vertical scrolling in pixels
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SCROLL	(LVM_FIRST+20)
/**
 * This message forces a list view control to redraw a range of items. You
 * can send this message explicitly or by using the ListView_RedrawItems
 * macro.
 *
 * @param iFirst Index of the first item to redraw
 * @param iLast Index of the last item to redraw
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_REDRAWITEMS	(LVM_FIRST+21)
#define LVA_DEFAULT	0
#define LVA_ALIGNLEFT	1
#define LVA_ALIGNTOP	2
#define LVA_SNAPTOGRID	5
/**
 * This message arranges items in icon view. You can send this message
 * explicitly or by using the ListView_Arrange macro.
 *
 * @param code Specifies alignment. It is one of the following values:
 *        Value Description LVA_ALIGNLEFT Not supported. LVA_ALIGNTOP Not
 *        supported. LVA_DEFAULT Aligns items according to the list view
 *        control current alignment styles (the default value).
 *        LVA_SNAPTOGRID Snaps all icons to the nearest grid position.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_ARRANGE	(LVM_FIRST+22)
#define LVM_EDITLABELA	(LVM_FIRST+23)
#define LVM_EDITLABELW	(LVM_FIRST+118)
/**
 * This message retrieves the handle of the edit control being used to edit
 * a list view item's text. You can send this message explicitly or by
 * using the ListView_GetEditControl macro.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but you should not destroy it. To cancel editing, you can
 * send the list view control a WM_CANCELMODE message.
 *
 * @return The handle to the edit control indicates success. NULL indicates
 *        otherwise. If no label is being edited, the return value is NULL.
 *        The edit control is not created until after the
 *        LVN_BEGINLABELEDIT notification message is sent.
 */
#define LVM_GETEDITCONTROL	(LVM_FIRST+24)
#define LVCF_FMT	1
#define LVCF_WIDTH	2
#define LVCF_TEXT	4
#define LVCF_SUBITEM	8
#if (_WIN32_IE >= 0x0300) || (_WIN32_WCE >= 0x200)
#define LVCF_IMAGE 16
#define LVCF_ORDER 32
#endif
#define LVCFMT_LEFT	0
#define LVCFMT_RIGHT	1
#define LVCFMT_CENTER	2
#define LVCFMT_JUSTIFYMASK	3
#if (_WIN32_IE >= 0x0300)
#define LVCFMT_BITMAP_ON_RIGHT 4096
#define LVCFMT_COL_HAS_IMAGES  32768
#define LVCFMT_IMAGE 2048 
#endif
#define LVM_GETCOLUMNA	(LVM_FIRST+25)
#define LVM_GETCOLUMNW	(LVM_FIRST+95)
#define LVM_SETCOLUMNA	(LVM_FIRST+26)
#define LVM_SETCOLUMNW	(LVM_FIRST+96)
#define LVM_INSERTCOLUMNA	(LVM_FIRST+27)
#define LVM_INSERTCOLUMNW	(LVM_FIRST+97)
/**
 * This message removes a column from a list view control. You can send
 * this message explicitly or by using the ListView_DeleteColumn macro.
 *
 * @param iCol Index of the column to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_DELETECOLUMN	(LVM_FIRST+28)
/**
 * This message retrieves the width of a column in report or list view. You
 * can send this message explicitly or by using the ListView_GetColumnWidth
 * macro.
 *
 * @param iCol Index of the column. This parameter is ignored in list view.
 * @return The column width indicates success. Zero indicates failure. If
 *        this message is sent to a list view control with the LVS_REPORT
 *        style and the specified column doesn't exist, the return value is
 *        undefined.
 */
#define LVM_GETCOLUMNWIDTH	(LVM_FIRST+29)
#define LVSCW_AUTOSIZE	(-1)
#define LVSCW_AUTOSIZE_USEHEADER	(-2)
/**
 * This message changes the width of a column in report or list view. You
 * can send this message explicitly or by using the ListView_SetColumnWidth
 * macro.
 *
 * @param iCol Index of the column. In list view, the iCol parameter must
 *        be -1.
 * @param cx New width of the column, in list view coordinates, or one of
 *        the following values: Value Description LVSCW_AUTOSIZE
 *        Automatically sizes the column LVSCW_AUTOSIZE_USEHEADER
 *        Automatically sizes the column to fit the header text
 */
#define LVM_SETCOLUMNWIDTH	(LVM_FIRST+30)
/**
 * This message creates a drag image list for the specified item. You can
 * send this message explicitly or by using the ListView_CreateDragImage
 * macro.
 *
 * @param iItem Index of the item.
 * @param lpptUpLeft Long pointer to a POINT structure that receives the
 *        initial location of the upper-left corner of the image, in view
 *        coordinates.
 * @return The handle to the drag image list indicates success. NULL
 *        indicates otherwise.
 */
#define LVM_CREATEDRAGIMAGE	(LVM_FIRST+33)
/**
 * This message retrieves the bounding rectangle of all items in the list
 * view control. The list view must be in icon or small icon view. You can
 * send this message explicitly or by using the ListView_GetViewRect macro.
 *
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle. All coordinates are relative to the visible area of
 *        the list view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_GETVIEWRECT	(LVM_FIRST+34)
/**
 * This message retrieves the text color of a list view control. You can
 * send this message explicitly or by using the ListView_GetTextColor
 * macro.
 *
 * @return Returns the text color
 */
#define LVM_GETTEXTCOLOR	(LVM_FIRST+35)
/**
 * This message sets the text color of a list view control. You can send
 * this message explicitly or by using the ListView_SetTextColor macro.
 *
 * @param clrText New text color
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETTEXTCOLOR	(LVM_FIRST+36)
/**
 * This message retrieves the text background color of a list view control.
 * You can send this message explicitly or by using the
 * ListView_GetTextBkColor macro.
 *
 * @return Returns the background color of the text
 */
#define LVM_GETTEXTBKCOLOR	(LVM_FIRST+37)
/**
 * This message sets the background color of text in a list view control.
 * You can send this message explicitly or by using the
 * ListView_SetTextBkColor macro.
 *
 * @param clrText New text color
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETTEXTBKCOLOR	(LVM_FIRST+38)
/**
 * This message retrieves the index of the topmost visible item when in
 * list or report view. You can send this message explicitly or by using
 * the ListView_GetTopIndex macro.
 *
 * @return The index of the item indicates success. Zero indicates the list
 *        view control is in icon or small icon view.
 */
#define LVM_GETTOPINDEX	(LVM_FIRST+39)
/**
 * This message calculates the number of items that can fit vertically in
 * the visible area of a list view control when in list or report view.
 * Only fully visible items are counted. You can send this message
 * explicitly or by using the ListView_GetCountPerPage macro.
 *
 * @return The number of fully visible items indicates success. If the
 *        current view is icon or small icon view, the return value is the
 *        total number of items in the list view control.
 */
#define LVM_GETCOUNTPERPAGE	(LVM_FIRST+40)
/**
 * This message retrieves the current view origin for a list view control.
 * You can send this message explicitly or by using the ListView_GetOrigin
 * macro.
 *
 * @param lpptOrg Long pointer to a POINT structure that receives the view
 *        origin
 * @return TRUE indicates success. FALSE indicates that the current view is
 *        list or report view.
 */
#define LVM_GETORIGIN	(LVM_FIRST+41)
#define LVM_GETORIGIN	(LVM_FIRST+41)
/**
 * This message updates a list view item. If the list view control has the
 * LVS_AUTOARRANGE style, this macro causes the list view control to be
 * arranged. You can send this message explicitly or by using the
 * ListView_Update macro.
 *
 * @param iItem Index of the item to update
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_UPDATE	(LVM_FIRST+42)
/**
 * This message changes the state of an item in a list view control. You
 * can send this message explicitly or by using the ListView_SetItemState
 * macro.
 *
 * @param i Index of the list view item. If this parameter is -1, then the
 *        state change is applied to all items.
 * @param pitem Pointer to an LVITEM structure. The stateMask member
 *        specifies which state bits to change, and the state member
 *        contains the new values for those bits. The other members are
 *        ignored.
 * @return If you send this message explicitly, TRUE indicates success.
 *        FALSE indicates failure.
 */
#define LVM_SETITEMSTATE	(LVM_FIRST+43)
/**
 * This message retrieves the state of a list view item. You can send this
 * message explicitly or by using the ListView_GetItemState macro.
 *
 * @param i Index of the list view item.
 * @param mask State data to retrieve. It is a combination of the following
 *        values: Value Description LVIS_CUT The item is marked for a
 *        cut-and-paste operation. LVIS_DROPHILITED The item is highlighted
 *        as a drag-and-drop target. LVIS_FOCUSED The item has the focus,
 *        so it is surrounded by a standard focus rectangle. Although more
 *        than one item may be selected, only one item can have the focus.
 *        LVIS_SELECTED The item is selected. The appearance of a selected
 *        item depends on whether it has the focus and also on the system
 *        colors used for selection. LVIS_OVERLAYMASK Use this mask to
 *        retrieve the item's overlay image index. LVIS_STATEIMAGEMASK Use
 *        this mask to retrieve the item's state image index. An item's
 *        state data includes a set of bit flags as well as image list
 *        indexes that indicate the item's state image and overlay image.
 * @return Returns the current state for the specified item. The only valid
 *        bits in the return value are those that correspond to the bits
 *        set in the mask parameter.
 */
#define LVM_GETITEMSTATE	(LVM_FIRST+44)
#define LVM_GETITEMTEXTA	(LVM_FIRST+45)
#define LVM_GETITEMTEXTW	(LVM_FIRST+115)
#define LVM_SETITEMTEXTA	(LVM_FIRST+46)
#define LVM_SETITEMTEXTW	(LVM_FIRST+116)
/**
 * This message prepares a list view control for adding a large number of
 * items. In a regular list view control, it causes the control to allocate
 * memory for the specified number of items. In a virtual list view
 * control, available in Windows CE versions 2.0 and later, it sets the
 * number of virtual items in the control. You can send this message
 * explicitly or use the ListView_SetItemCount or ListView_SetItemCountEx
 * macros.
 *
 * Windows CE versions 2.0 and later support virtual list views, which you
 * create using the LVS_OWNERDATA style. In a virtual list view, this
 * function sets the number of items in the virtual list view, but does not
 * allocate any memory.
 *
 * The dwFlags parameter is intended only for list view controls that use
 * the LVS_OWNERDATA and either LVS_REPORT or LVS_LIST styles.
 *
 * @param cItems Number of items the list view control will ultimately
 *        contain
 * @param dwFlags Version 4.70. Specifies the behavior of the list view
 *        control after resetting the item count. It can be a combination
 *        of the following values: Value Description LVSICF_NOINVALIDATEALL
 *        The list view control will not repaint unless affected items are
 *        currently in view. LVSICF_NOSCROLL The list view control will not
 *        change the scroll position when the item count changes. If the
 *        list view control was created without the LVS_OWNERDATA style,
 *        sending this message causes the control to allocate its internal
 *        data structures for the specified number of items. This prevents
 *        the control from having to allocate the data structures every
 *        time an item is added. If the list view control was created with
 *        the LVS_OWNERDATA style (a virtual list view), sending this
 *        message sets the virtual number of items that the control
 *        contains.
 * @param cItems Number of items that the list view control will ultimately
 *        contain
 * @param dwFlags For Windows CE version 1.0, set this value to 0. For
 *        Windows CE versions 2.0 and later, this value specifies the
 *        behavior of the list view control after resetting the item count.
 *        This value can be a combination of the following: Value
 *        Description LVSICF_NOINVALIDATEALL The list view control will not
 *        repaint unless affected items are currently in view.
 *        LVSICF_NOSCROLL The list view control will not change the scroll
 *        position when the item count changes.
 * @return In Windows CE version 1.0, this message has no return value. In
 *        Windows CE versions 2.0 and later, nonzero indicates success.
 *        Zero indicates failure.
 */
#define LVM_SETITEMCOUNT	(LVM_FIRST+47)
/**
 * This message sorts list view items using an application-defined
 * comparison function. The index of each item changes to reflect the new
 * sequence. You can send this message explicitly or by using the
 * ListView_SortItems macro.
 *
 * The comparison function has the following form:
 *
 *     int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2,
 *         LPARAM lParamSort);
 *
 * The lParam1 parameter is the 32-bit value associated with the first item
 * being compared, and the lParam2 parameter is the value associated with
 * the second item. These are the values specified in the lParam member of
 * the items' LVITEM structure when they were inserted into the list. The
 * lParamSort parameter is the same value passed to the LVM_SORTITEMS
 * message.
 *
 * @param lParamSort Application-defined value passed to the comparison
 *        function.
 * @param pfnCompare Pointer to the application-defined comparison
 *        function. The comparison function is called during the sort
 *        operation each time the relative order of two list items needs to
 *        be compared.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SORTITEMS	(LVM_FIRST+48)
/**
 * This message moves an item to a specified position in a list view
 * control, which must be in icon or small icon view. This message differs
 * from the LVM_SETITEMPOSITION message in that it uses 32-bit coordinates.
 * You can send this message explicitly or by using the
 * ListView_SetItemPosition32 macro.
 *
 * @param iItem Index of the list view item for which to set the position
 * @param lpptNewPos Long pointer a POINT structure that contains the new
 *        position of the item, in list view coordinates
 * @return None
 */
#define LVM_SETITEMPOSITION32	(LVM_FIRST+49)
/**
 * This message determines the number of selected items in a list view
 * control. You can send this message explicitly or by using the
 * ListView_GetSelectedCount macro.
 *
 * @return Returns the number of selected items
 */
#define LVM_GETSELECTEDCOUNT	(LVM_FIRST+50)
/**
 * This message determines the spacing between items in a list view
 * control. You can send this message explicitly or by using the
 * ListView_GetItemSpacing macro.
 *
 * @param fSmall Boolean that specifies the view for which to retrieve the
 *        item spacing. Set to TRUE for small icon view, or to FALSE for
 *        icon view.
 * @return Returns the amount of spacing between items. The horizontal
 *        spacing is contained in the low-order word and the vertical
 *        spacing is contained in the high-order word.
 */
#define LVM_GETITEMSPACING	(LVM_FIRST+51)
#define LVM_GETISEARCHSTRINGA	(LVM_FIRST+52)
#define LVM_GETISEARCHSTRINGW	(LVM_FIRST+117)
#if (_WIN32_IE >= 0x0300)
/**
 * This message calculates the approximate width and height required to
 * display a specified number of items.
 *
 * Setting the size of the list view control based on the dimensions
 * provided by this message can optimize redraw and reduce flicker.
 *
 * @param iCount Number of items to be displayed in the control. If this
 *        parameter is set to -1, the message uses the total number of
 *        items in the control.
 * @param cx and cy Specify the proposed dimensions of the control, in
 *        pixels. Either parameter can beset to -1 to allow the message to
 *        use the current width or height value.
 * @return Returns a DWORD value that holds the approximate width and
 *        height needed to display the items, in pixels.
 */
#define LVM_APPROXIMATEVIEWRECT (LVM_FIRST+64)
/**
 * This message sets extended styles in list view controls. It does not
 * return a value.
 *
 * For backward compatibility reasons, the
 * ListView_SetExtendedListViewStyle macro has not been updated to use
 * dwExMask.
 *
 * @param dwExMask Specifies which styles in dwExStyle are to be affected.
 *        Only the extended styles in dwExMask will be changed. All other
 *        styles will be maintained as is. If this parameter is zero, then
 *        all of the styles in dwExStyle will be affected.
 * @param dwExStyle Specifies the extended list view control style. This
 *        parameter can be a combination of extended styles The dwExMask
 *        parameter allows you to modify one or more extended styles
 *        without having to retrieve the existing styles first. For
 *        example: if you pass LVS_EX_FULLROWSELECT for dwExMask and 0 for
 *        dwExStyle, the LVS_EX_FULLROWSELECT style will be cleared, but
 *        all other styles will remain the same.
 * @return Returns a DWORD value that contains the previous extended list
 *        view control styles
 */
#define LVM_SETEXTENDEDLISTVIEWSTYLE (LVM_FIRST+54)
/**
 * This message retrieves the extended styles that are currently in use for
 * a specified list view control.
 *
 * @return Returns a DWORD that represents the styles currently in use for
 *        a specified list view control. This value can be a combination of
 *        extended styles.
 */
#define LVM_GETEXTENDEDLISTVIEWSTYLE (LVM_FIRST+55)
/**
 * This message sets the left-to-right order of columns in a list view
 * control.
 *
 * @param iCount Size, in elements, of the buffer at lpiArray
 * @param lpiArray Long pointer to an array that specifies the order in
 *        which columns should be displayed, in left-to-right order. For
 *        example, if the contents of the array are {2,0,1}, the control
 *        displays column 2, column 0, and column 1 in that order.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define LVM_SETCOLUMNORDERARRAY (LVM_FIRST+58)
/**
 * This message retrieves the current left-to-right order of columns in a
 * list view control.
 *
 * @param iCount Number of columns in the list view control.
 * @param lpiArray Long pointer to a buffer that receives the index values
 *        of the columns in the list view control. The buffer must be large
 *        enough to hold the total number of columns * sizeof(int).
 * @return If successful, returns nonzero and the buffer at lpiArray
 *        receives the column index of each column in the control, in the
 *        order they appear from left to right. Otherwise, the return value
 *        is zero.
 */
#define LVM_GETCOLUMNORDERARRAY (LVM_FIRST+59)
/**
 * This message retrieves the handle to the header control used by the list
 * view control.
 *
 * @return Returns the handle to the header control.
 */
#define LVM_GETHEADER (LVM_FIRST+31)
#define LVM_GETHOTCURSOR (LVM_FIRST+63)
#define LVM_GETHOTITEM (LVM_FIRST+61)
/**
 * This message retrieves data about the bounding rectangle for a subitem
 * in a list view control. This message is intended to be used only with
 * list view controls that use the LVS_REPORT style.
 *
 * @param iItem Index of the subitem parent item
 * @param lpRect Long pointer to a RECT structure that receives the subitem
 *        bounding rectangle data. The members of RECT must be initialized
 *        according to the member and value relationships shown in the
 *        following table. Member Value top The one-based index of the
 *        subitem left Flag value (see following). Indicates the portion of
 *        the list view subitem for which to retrieve the bounding
 *        rectangle. Value Description LVIR_BOUNDS Returns the bounding
 *        rectangle of the entire item, including the icon and label.
 *        LVIR_ICON Returns the bounding rectangle of the icon or small
 *        icon LVIR_LABEL Returns the bounding rectangle of the entire
 *        item, including the icon and label. This is identical to
 *        LVIR_BOUNDS.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define LVM_GETSUBITEMRECT (LVM_FIRST+56)
#define LVM_SETHOTCURSOR (LVM_FIRST+62)
#define LVM_SETHOTITEM (LVM_FIRST+60)
/**
 * This message sets the spacing between icons in list view controls that
 * have the LVS_ICON style.
 *
 * Values for cx and cy are relative to the upper-left corner of an icon
 * bitmap. Therefore, to set spacing between icons that do not overlap, the
 * cx or cy values must include the size of the icon, plus the amount of
 * empty space desired between icons. Values that do not include the width
 * of the icon will result in overlaps.
 *
 * @param cx Distance, in pixels, to set between icons on the x-axis.
 *        Setting this value to -1 resets the cx parameter to default
 *        spacing.
 * @param cy Distance, in pixels, to set between icons on the y-axis.
 *        Setting this value to -1 resets the cy parameter to default
 *        spacing.
 * @return Returns a DWORD value that contains the previous cx in the
 *        low-order word, and the previous cy in the high-order word.
 */
#define LVM_SETICONSPACING (LVM_FIRST+53)
/**
 * This message determines which list view item or subitem is at a
 * specified position.
 *
 * @param pInfo Pointer to an LVHITTESTINFO structure. The POINT structure
 *        within LVHITTESTINFO should be set to the client coordinates to
 *        be hit-tested.
 * @return Returns the index of the item or subitem tested, if any, or -1
 *        otherwise. If an item or subitem is at the specified coordinates,
 *        the members of the LVHITTESTINFO structure will be filled with
 *        the applicable hit data.
 */
#define LVM_SUBITEMHITTEST (LVM_FIRST+57)
#endif
/**
 * This notification message notifies a list view control parent window
 * that an item is changing. It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure that identifies the item
 *        and specifies which of its attributes are changing.
 * @return TRUE prevents the change. FALSE accepts the change.
 */
#define LVN_ITEMCHANGING	LVN_FIRST
/**
 * This notification message notifies a list view control parent window
 * that an item has changed. It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure that identifies the item
 *        and specifies which of its attributes have changed.
 * @return None
 */
#define LVN_ITEMCHANGED	(LVN_FIRST-1)
/**
 * This notification message notifies a list view control parent window
 * that a new item was inserted. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure. The iItem member
 *        identifies the new item, and the other members are zero.
 * @return None
 */
#define LVN_INSERTITEM	(LVN_FIRST-2)
/**
 * This notification message notifies a list view control parent window
 * that an item was deleted. It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure. The iItem member
 *        identifies the item being deleted. All other members of this
 *        structure are zero.
 * @return None
 */
#define LVN_DELETEITEM	(LVN_FIRST-3)
/**
 * This notification message notifies a list view control parent window
 * that all items in the control were deleted. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure. The iItem member is -1,
 *        and the other members are zero. A list view control sends the
 *        LVN_DELETEALLITEMS notification message when it is destroyed or
 *        when it receives the LVM_DELETEALLITEMS message. If
 *        LVN_DELETEALLITEMS does not return TRUE, the control will also
 *        send an LVN_DELETEITEM notification message as each item is
 *        deleted.
 * @return To suppress subsequent LVN_DELETEITEM notification messages,
 *        return TRUE. To receive subsequent LVN_DELETEITEM notification
 *        messages, return FALSE.
 */
#define LVN_DELETEALLITEMS	(LVN_FIRST-4)
#define LVN_BEGINLABELEDITA	(LVN_FIRST-5)
#define LVN_BEGINLABELEDITW	(LVN_FIRST-75)
#define LVN_ENDLABELEDITA	(LVN_FIRST-6)
#define LVN_ENDLABELEDITW	(LVN_FIRST-76)
/**
 * This notification message notifies a list view control parent window
 * that a column was tapped. It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure. The iItem member is -1,
 *        and the iSubItem member identifies the column. All other members
 *        are zero.
 * @return None
 */
#define LVN_COLUMNCLICK	(LVN_FIRST-8)
/**
 * This notification message notifies a list view control parent window
 * that a drag and drop operation is being initiated. It is sent in the
 * form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLISTVIEW structure. The iItem member
 *        identifies the item being dragged, and the other members are
 *        zero.
 * @return None
 */
#define LVN_BEGINDRAG	(LVN_FIRST-9)
#define LVN_BEGINRDRAG	(LVN_FIRST-11)
#define LVN_GETDISPINFOA	(LVN_FIRST-50)
#define LVN_GETDISPINFOW	(LVN_FIRST-77)
#define LVN_SETDISPINFOA	(LVN_FIRST-51)
#define LVN_SETDISPINFOW	(LVN_FIRST-78)
/**
 * This notification message notifies a list view control parent window
 * that a key has been pressed. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param pnkd Pointer to an NMLVKEYDOWN structure.
 * @return None
 */
#define LVN_KEYDOWN	(LVN_FIRST-55)
#if (_WIN32_IE >= 0x0400)
/**
 * This message notifies a list view control parent window that a bounding
 * box, or marquee, selection has begun. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * A "bounding box selection" is the process of clicking the list view
 * window's client area and dragging to select multiple items
 * simultaneously.
 *
 * @param pnmv Pointer to an NMHDR structure.
 * @return To accept the notification message, return zero. To quit the
 *        bounding box selection, return nonzero.
 */
#define LVN_MARQUEEBEGIN  (LVN_FIRST-56)
#define LVN_GETINFOTIPA	(LVN_FIRST-57)
#define LVN_GETINFOTIPW	(LVN_FIRST-58)
#define LVKF_ALT	0x0001
#define LVKF_CONTROL	0x0002
#define LVKF_SHIFT	0x0004
#define LVGIT_UNFOLDED  1
#endif
#define TVS_HASBUTTONS	1
#define TVS_HASLINES	2
#define TVS_LINESATROOT	4
#define TVS_EDITLABELS	8
#define TVS_DISABLEDRAGDROP	16
#define TVS_SHOWSELALWAYS	32
#if (_WIN32_IE >= 0x0300)
#define TVS_CHECKBOXES 256
#define TVS_NOTOOLTIPS 128
#define TVS_RTLREADING 64
#define TVS_TRACKSELECT 512
#endif
#if (_WIN32_IE >= 0x0400)
#define TVS_FULLROWSELECT 4096
#define TVS_INFOTIP 2048
#define TVS_NONEVENHEIGHT 16384
#define TVS_NOSCROLL 8192
#define TVS_SINGLEEXPAND 1024
#endif
#if( _WIN32_IE >= 0x0500 )
#define TVS_NOHSCROLL	0x8000
#endif /* _WIN32_IE >= 0x0500 */
#define TVIF_TEXT	1
#define TVIF_IMAGE	2
#define TVIF_PARAM	4
#define TVIF_STATE	8
#define TVIF_HANDLE	16
#define TVIF_SELECTEDIMAGE	32
#define TVIF_CHILDREN	64
#if (_WIN32_IE >= 0x0400)
#define TVIF_INTEGRAL	0x0080
#endif /* _WIN32_IE >= 0x0400 */
#define TVIS_FOCUSED	1
#define TVIS_SELECTED	2
#define TVIS_CUT	4
#define TVIS_DROPHILITED	8
#define TVIS_BOLD	16
#define TVIS_EXPANDED	32
#define TVIS_EXPANDEDONCE	64
#define TVIS_OVERLAYMASK	0xF00
#define TVIS_STATEIMAGEMASK	0xF000
#define TVIS_USERMASK	0xF000
#define I_CHILDRENCALLBACK	(-1)
#define TVI_ROOT	((HTREEITEM)0xFFFF0000)
#define TVI_FIRST	((HTREEITEM)0xFFFF0001)
#define TVI_LAST	((HTREEITEM)0xFFFF0002)
#define TVI_SORT	((HTREEITEM)0xFFFF0003)
#define TVSIL_NORMAL	0
#define TVSIL_STATE	2
#define TVM_INSERTITEMA	TV_FIRST
#define TVM_INSERTITEMW	(TV_FIRST+50)
/**
 * This message removes an item from a tree view control. You can send this
 * message explicitly or by using the TreeView_DeleteItem or
 * TreeView_DeleteAllItems macro.
 *
 * @param hitem Handle to the item to delete. If hitem is the TVI_ROOT
 *        value, all items are deleted from the tree view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_DELETEITEM	(TV_FIRST+1)
/**
 * This message expands or collapses the list of child items, if any,
 * associated with the specified parent item. You can send this message
 * explicitly or by using the TreeView_Expand macro.
 *
 * In Windows CE versions 2.0 and later, you can use the new
 * TVE_EXPANDPARTIAL flag in the flag parameter.
 *
 * When the TVE_EXPANDPARTIAL flag is set, the child items are visible and
 * parent item's plus symbol is displayed. This flag must be used in
 * combination with the TVE_EXPAND flag.
 *
 * The TVM_EXPAND message will cause the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages to be generated if the item being
 * expanded does not have the TVIS_EXPANDEDONCE state bit set. This state
 * gets set when a parent item is expanded for the first time. Using
 * TVE_COLLAPSE and TVE_COLLAPSERESET with TVM_EXPAND will cause the
 * TVIS_EXPANDEDONCE state to be reset.
 *
 * @param flag Action flag. It is one or more of the following values:
 *        Value Description TVE_COLLAPSE Collapses the list.
 *        TVE_COLLAPSERESET Collapses the list and removes the child items.
 *        This flag must be used with the TVE_COLLAPSE flag. TVE_EXPAND
 *        Expands the list. TVE_EXPANDPARTIAL Version 4.70. Partially
 *        expands the list. In this state, the child items are visible and
 *        the parent item's plus symbol is displayed. This flag must be
 *        used in combination with the TVE_EXPAND flag. TVE_TOGGLE
 *        Collapses the list if it is expanded or expands it if it is
 *        collapsed.
 * @param hItem Handle to the parent item to expand or collapse.
 * @return Nonzero indicates that a change took place. Zero indicates
 *        otherwise.
 */
#define TVM_EXPAND	(TV_FIRST+2)
/**
 * This message retrieves the bounding rectangle for a tree view item and
 * indicates whether the item is visible. You can send this message
 * explicitly or by using the TreeView_GetItemRect macro.
 *
 * When sending this message, the prc parameter contains the handle of the
 * item that the rectangle is being retrieved for. The handle is placed in
 * prc as shown in the following code example:
 *
 *     RECT rc;
 *     *(HTREEITEM*)&rc = hTreeItem;
 *     SendMessage(hwndTreeView, TVM_GETITEMRECT, FALSE, (LPARAM)&rc);
 *
 * @param fItemRect Boolean value that specifies the portion of the item
 *        for which to retrieve the bounding rectangle. If set to TRUE, the
 *        bounding rectangle includes only the text of the item. If set to
 *        FALSE, it includes the entire line that the item occupies in the
 *        tree view control.
 * @param prc Pointer to a RECT structure that, when sending the message,
 *        contains the handle of the item to retrieve the rectangle for.
 *        For more information on how to place the item handle in this
 *        parameter, see the Remarks section. After returning from the
 *        message, this parameter contains the bounding rectangle. The
 *        coordinates are relative to the upper-left corner of the tree
 *        view control.
 * @return TRUE indicates that the item is visible and the bounding
 *        rectangle was successfully retrieved. Otherwise, the message
 *        returns FALSE and does not retrieve the bounding rectangle.
 */
#define TVM_GETITEMRECT	(TV_FIRST+4)
/**
 * This message retrieves a count of the items in a tree view control. You
 * can send this message explicitly or by using the TreeView_GetCount
 * macro.
 *
 * @return Returns the count of items.
 */
#define TVM_GETCOUNT	(TV_FIRST+5)
/**
 * This message retrieves the amount, in pixels, that child items are
 * indented relative to their parent items. You can send this message
 * explicitly or by using the TreeView_GetIndent macro.
 *
 * @return Returns the amount of indentation.
 */
#define TVM_GETINDENT	(TV_FIRST+6)
/**
 * This message sets the width of indentation for a tree view control and
 * redraws the control to reflect the new width. You can send this message
 * explicitly or by using the TreeView_SetIndent macro.
 *
 * @param indent Width, in pixels, of the indentation. If this parameter is
 *        less than the system-defined minimum width, the new width is set
 *        to the system-defined minimum.
 * @return The return value is not used.
 */
#define TVM_SETINDENT	(TV_FIRST+7)
/**
 * This message retrieves the handle of the normal or state image list
 * associated with a tree view control. You can send this message
 * explicitly or by using the TreeView_GetImageList macro.
 *
 * @param iImage Type of image list to retrieve. It is one of the following
 *        values: Value Description TVSIL_NORMAL Indicates the normal image
 *        list, which contains selected, nonselected, and overlay images
 *        for the items of a tree view control. TVSIL_STATE Indicates the
 *        state image list. You can use state images to indicate
 *        application-defined item states. A state image is displayed to
 *        the left of an item's selected or nonselected image.
 * @return Returns an HIMAGELIST handle to the specified image list.
 */
#define TVM_GETIMAGELIST	(TV_FIRST+8)
/**
 * This message sets the normal or state image list for a tree view control
 * and redraws the control using the new images. You can send this message
 * explicitly or by using the TreeView_SetImageList macro.
 *
 * @param iImage Type of image list to set. It is one of the following
 *        values: Value Description TVSIL_NORMAL Indicates the normal image
 *        list, which contains selected, nonselected, and overlay images
 *        for the items of a tree view control. TVSIL_STATE Indicates the
 *        state image list. You can use state images to indicate
 *        application-defined item states. A state image is displayed to
 *        the left of an item's selected or nonselected image.
 * @param himl Handle to the image list. If himl is NULL, the message
 *        removes the specified image list from the tree view control.
 * @return The handle to the previous image list, if any, indicates
 *        success. NULL indicates otherwise.
 */
#define TVM_SETIMAGELIST	(TV_FIRST+9)
/**
 * This message retrieves the tree view item that bears the specified
 * relationship to a specified item. You can send this message explicitly
 * or by using the TreeView_GetNextItem macro or one of the related macros.
 *
 * @param flag Specifies the item to retrieve. It is one of the following
 *        values: Value Description TVGN_CARET Retrieves the currently
 *        selected item. You can use the TreeView_GetSelection macro to
 *        send this message. TVGN_CHILD Retrieves the first child item of
 *        the item specified by the hitem parameter. You can use the
 *        TreeView_GetChild macro to send this message. TVGN_DROPHILITE
 *        Retrieves the item that is the target of a drag-and-drop
 *        operation. You can use the TreeView_GetDropHilight macro to send
 *        this message. TVGN_FIRSTVISIBLE Retrieves the first item that is
 *        visible in the tree view window. You can use the
 *        TreeView_GetFirstVisible macro to send this message.
 *        TVGN_LASTVISIBLE Version 4.71. Retrieves the last expanded item
 *        in the tree. This does not retrieve the last item visible in the
 *        tree view window. You can use the TreeView_GetLastVisible macro
 *        to send this message. TVGN_NEXT Retrieves the next sibling item.
 *        You can use the TreeView_GetNextSibling macro to send this
 *        message. TVGN_NEXTVISIBLE Retrieves the next visible item that
 *        follows the specified item. The specified item must be visible.
 *        Use the TVM_GETITEMRECT message to determine whether an item is
 *        visible. You can use the TreeView_GetNextVisible macro to send
 *        this message. TVGN_PARENT Retrieves the parent of the specified
 *        item. You can use the TreeView_GetParent macro to send this
 *        message. TVGN_PREVIOUS Retrieves the previous sibling item. You
 *        can use the TreeView_GetPrevSibling macro to send this message.
 *        TVGN_PREVIOUSVISIBLE Retrieves the first visible item that
 *        precedes the specified item. The specified item must be visible.
 *        Use the TVM_GETITEMRECT message to determine whether an item is
 *        visible. You can use the TreeView_GetPrevVisible macro to send
 *        this message. TVGN_ROOT Retrieves the topmost or very first item
 *        of the tree view control. You can use the TreeView_GetRoot macro
 *        to send this message.
 * @param hitem Handle to an item.
 * @return The handle to the item indicates success. NULL indicates
 *        otherwise.
 */
#define TVM_GETNEXTITEM	(TV_FIRST+10)
/**
 * This message selects the specified tree view item, scrolls the item into
 * view, or redraws the item in the style used to indicate the target of a
 * drag and drop operation. You can send this message explicitly or by
 * using the TreeView_Select, TreeView_SelectItem, or
 * TreeView_SelectDropTarget macro.
 *
 * If the specified item is the child of a collapsed parent item, the
 * parent's list of child items is expanded to reveal the specified item.
 * In this case, the control's parent window receives the TVN_ITEMEXPANDING
 * and TVN_ITEMEXPANDED notification messages.
 *
 * @param flag Action flag. It is one of the following values: Value
 *        Description TVGN_CARET Sets the selection to the specified item.
 *        The tree view control's parent window receives the
 *        TVN_SELCHANGING and TVN_SELCHANGED notification messages.
 *        TVGN_DROPHILITE Redraws the specified item in the style used to
 *        indicate the target of a drag-and-drop operation.
 *        TVGN_FIRSTVISIBLE Ensures that the specified item is visible,
 *        and, if possible, displays it at the top of the control's window.
 *        Tree view controls display as many items as will fit in the
 *        window. If the specified item is near the bottom of the control's
 *        hierarchy of items, it might not become the first visible item,
 *        depending on how many items fit in the window.
 * @param hitem Handle to an item. If hitem is NULL, the control is set to
 *        have no selected item.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_SELECTITEM	(TV_FIRST+11)
#define TVM_GETITEMA	(TV_FIRST+12)
#define TVM_GETITEMW	(TV_FIRST+62)
#define TVM_SETITEMA	(TV_FIRST+13)
#define TVM_SETITEMW	(TV_FIRST+63)
#define TVM_EDITLABELA	(TV_FIRST+14)
#define TVM_EDITLABELW	(TV_FIRST+65)
/**
 * This message retrieves the handle of the edit control being used to edit
 * a tree view item's text. You can send this message explicitly or by
 * using the TreeView_GetEditControl macro.
 *
 * @return The handle to the edit control indicates success. NULL indicates
 *        otherwise.
 */
#define TVM_GETEDITCONTROL	(TV_FIRST+15)
/**
 * This message retrieves the number of items that can be fully visible in
 * the client window of the tree-view control. You can send this message
 * explicitly or by using the TreeView_GetVisibleCount macro.
 *
 * The number of items that can be fully visible may be greater than the
 * number of items in the control. The control calculates this value by
 * dividing the height of the client window by the height of an item.
 *
 * Note that the return value is the number of items that can be fully
 * visible. If you can see all of 20 items and part of one more item, the
 * return value is 20.
 *
 * @return Returns the number of items that can be fully visible in the
 *        client window of the tree view control.
 */
#define TVM_GETVISIBLECOUNT	(TV_FIRST+16)
/**
 * This message determines the location of the specified point relative to
 * the client area of a tree view control. You can send this message
 * explicitly or by using the TreeView_HitTest macro.
 *
 * @param lpht Long pointer to a TVHITTESTINFO structure. When the message
 *        is sent, the pt member specifies the coordinates of the point to
 *        test. When the message returns, the hItem member is the handle to
 *        the item at the specified point or NULL if no item occupies the
 *        point. Also, when the message returns, the flags member is a hit
 *        test value that indicates the location of the specified point.
 *        For a list of hit test values, see the description of the
 *        TVHITTESTINFO structure.
 * @return The handle to the tree view item that occupies the specified
 *        point indicates success. NULL indicates that no item occupies the
 *        point.
 */
#define TVM_HITTEST	(TV_FIRST+17)
/**
 * This message creates a dragging bitmap for the specified item in a tree
 * view control, creates an image list for the bitmap, and adds the bitmap
 * to the image list. An application can display the image when dragging
 * the item by using the image list functions. You can send this message
 * explicitly or by using the TreeView_CreateDragImage macro.
 *
 * @param hitem Handle to the item that receives the new dragging bitmap.
 * @return The handle to the image list to which the dragging bitmap was
 *        added indicates success. NULL indicates otherwise.
 */
#define TVM_CREATEDRAGIMAGE	(TV_FIRST+18)
/**
 * This message sorts the child items of the specified parent item in a
 * tree view control. You can send this message explicitly or by using the
 * TreeView_SortChildren macro.
 *
 * @param fRecurse Reserved for future use; set to zero.
 * @param hitem Handle to the parent item whose child items are to be
 *        sorted.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_SORTCHILDREN	(TV_FIRST+19)
/**
 * This message ensures that a tree view item is visible, expanding the
 * parent item or scrolling the tree view control, if necessary. You can
 * send this message explicitly or by using the TreeView_EnsureVisible
 * macro.
 *
 * @param hitem Handle to the item.
 * @return Nonzero indicates that the system scrolled the items in the tree
 *        view control and no items were expanded. Zero indicates
 *        otherwise.
 */
#define TVM_ENSUREVISIBLE	(TV_FIRST+20)
/**
 * This message sorts tree view items using an application-defined callback
 * function that compares the items. You can send this message explicitly
 * or by using the TreeView_SortChildrenCB macro.
 *
 * @param fRecurse Reserved for future use; set to zero.
 * @param psort Pointer a TVSORTCB structure. The lpfnCompare member is the
 *        address of the application-defined callback function, which is
 *        called during the sort operation each time the relative order of
 *        two list items needs to be compared. For more information about
 *        the callback function, see the description of TVSORTCB.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_SORTCHILDRENCB	(TV_FIRST+21)
/**
 * This message ends the editing of a tree view item's label. You can send
 * this message explicitly or by using the TreeView_EndEditLabelNow macro.
 *
 * @param fCancel Boolean value that indicates whether the editing is
 *        canceled without being saved to the label. If set to TRUE, the
 *        system cancels editing without saving the changes. If set to
 *        FALSE, the system saves the changes to the label.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_ENDEDITLABELNOW	(TV_FIRST+22)
#define TVM_GETISEARCHSTRINGA	(TV_FIRST+23)
#define TVM_GETISEARCHSTRINGW	(TV_FIRST+64)
#if (_WIN32_IE >= 0x0300)
#define TVM_GETTOOLTIPS (TV_FIRST+25)
#define TVM_SETTOOLTIPS (TV_FIRST+24)
#endif
#if (_WIN32_IE >= 0x0400)
#define TVM_GETBKCOLOR (TV_FIRST+31)
#define TVM_GETINSERTMARKCOLOR (TV_FIRST+38)
#define TVM_GETITEMHEIGHT (TV_FIRST+28)
#define TVM_GETSCROLLTIME (TV_FIRST+34)
#define TVM_GETTEXTCOLOR (TV_FIRST+32)
#define TVM_SETBKCOLOR (TV_FIRST+29)
#define TVM_SETINSERTMARK (TV_FIRST+26)
#define TVM_SETINSERTMARKCOLOR (TV_FIRST+37)
#define TVM_SETITEMHEIGHT (TV_FIRST+27)
#define TVM_SETSCROLLTIME (TV_FIRST+33)
#define TVM_SETTEXTCOLOR (TV_FIRST+30)
#define TVM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define TVM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#endif
#if (_WIN32_IE >= 0x0500)
#define TVM_GETITEMSTATE (TV_FIRST+39)
#define TVM_SETLINECOLOR (TV_FIRST+40)
#define TVM_GETLINECOLOR (TV_FIRST+41)
#endif
#define TVE_COLLAPSE	1
#define TVE_EXPAND	2
#define TVE_TOGGLE	3
#define TVE_COLLAPSERESET	0x8000
#if (_WIN32_IE >= 0x0300)
#define TVE_EXPANDPARTIAL	0x4000
#endif
#define TVC_UNKNOWN	0
#define TVC_BYMOUSE	1
#define TVC_BYKEYBOARD	2
#define TVGN_ROOT	0
#define TVGN_NEXT	1
#define TVGN_PREVIOUS	2
#define TVGN_PARENT	3
#define TVGN_CHILD	4
#define TVGN_FIRSTVISIBLE	5
#define TVGN_NEXTVISIBLE	6
#define TVGN_PREVIOUSVISIBLE	7
#define TVGN_DROPHILITE	8
#define TVGN_CARET	9
#if (_WIN32_IE >= 0x0400)
#define TVGN_LASTVISIBLE	10
#endif
#define TVN_SELCHANGINGA	(TVN_FIRST-1)
#define TVN_SELCHANGINGW	(TVN_FIRST-50)
#define TVN_SELCHANGEDA	(TVN_FIRST-2)
#define TVN_SELCHANGEDW	(TVN_FIRST-51)
#define TVN_GETDISPINFOA	(TVN_FIRST-3)
#define TVN_GETDISPINFOW	(TVN_FIRST-52)
#define TVN_SETDISPINFOA	(TVN_FIRST-4)
#define TVN_SETDISPINFOW	(TVN_FIRST-53)
#define TVN_ITEMEXPANDINGA	(TVN_FIRST-5)
#define TVN_ITEMEXPANDINGW	(TVN_FIRST-54)
#define TVN_ITEMEXPANDEDA	(TVN_FIRST-6)
#define TVN_ITEMEXPANDEDW	(TVN_FIRST-55)
#define TVN_BEGINDRAGA	(TVN_FIRST-7)
#define TVN_BEGINDRAGW	(TVN_FIRST-56)
#define TVN_BEGINRDRAGA	(TVN_FIRST-8)
#define TVN_BEGINRDRAGW	(TVN_FIRST-57)
#define TVN_DELETEITEMA	(TVN_FIRST-9)
#define TVN_DELETEITEMW	(TVN_FIRST-58)
#define TVN_BEGINLABELEDITA	(TVN_FIRST-10)
#define TVN_BEGINLABELEDITW	(TVN_FIRST-59)
#define TVN_ENDLABELEDITA	(TVN_FIRST-11)
#define TVN_ENDLABELEDITW	(TVN_FIRST-60)
/**
 * This notification message notifies a tree view control's parent window
 * that the user pressed a key and the tree view control has the input
 * focus. It is sent in the form of a WM_NOTIFY message.
 *
 * @param ptvkd Pointer to an NMTVKEYDOWN structure. The wVKey member
 *        specifies the virtual-key code.
 * @return If the wVKey member of ptvkd is a character key code, the
 *        character will be used as part of an incremental search. Return
 *        nonzero to exclude the character from the incremental search, or
 *        zero to include the character in the search. For all other keys,
 *        the return value is ignored.
 */
#define TVN_KEYDOWN	(TVN_FIRST-12)
#if (_WIN32_IE >= 0x0400)
#define TVN_GETINFOTIPA	(TVN_FIRST-13)
#define TVN_GETINFOTIPW	(TVN_FIRST-14)
#define TVN_SINGLEEXPAND	(TVN_FIRST-15)
#define TVNRET_DEFAULT 0
#define TVNRET_SKIPOLD 1
#define TVNRET_SKIPNEW 2
#endif /* _WIN32_IE >= 0x0400 */
#define TVIF_DI_SETITEM	0x1000
#define TVHT_NOWHERE	1
#define TVHT_ONITEMICON	2
#define TVHT_ONITEMLABEL	4
#define TVHT_ONITEM	(TVHT_ONITEMICON|TVHT_ONITEMLABEL|TVHT_ONITEMSTATEICON)
#define TVHT_ONITEMINDENT	8
#define TVHT_ONITEMBUTTON	16
#define TVHT_ONITEMRIGHT	32
#define TVHT_ONITEMSTATEICON	64
#define TVHT_ABOVE	256
#define TVHT_BELOW	512
#define TVHT_TORIGHT	1024
#define TVHT_TOLEFT	2048
#define TCHT_NOWHERE	1
#define TCHT_ONITEMICON	2
#define TCHT_ONITEMLABEL	4
#define TCHT_ONITEM	(TCHT_ONITEMICON|TCHT_ONITEMLABEL)
#define TCS_FORCEICONLEFT	16
#define TCS_FORCELABELLEFT	32
#define TCS_TABS	0
#define TCS_BUTTONS	256
#define TCS_SINGLELINE	0
#define TCS_MULTILINE	512
#define TCS_RIGHTJUSTIFY	0
#define TCS_FIXEDWIDTH	1024
#define TCS_RAGGEDRIGHT	2048
#define TCS_FOCUSONBUTTONDOWN	0x1000
#define TCS_OWNERDRAWFIXED	0x2000
#define TCS_TOOLTIPS	0x4000
#define TCS_FOCUSNEVER	0x8000
#if (_WIN32_IE >= 0x0300)
#define TCS_BOTTOM	2
#define TCS_RIGHT	2
#define TCS_VERTICAL	128
#define TCS_SCROLLOPPOSITE	0x0001
#define TCS_HOTTRACK	0x0040
#define TCS_MULTISELECT	0x0004
#endif
#if( _WIN32_IE >= 0x0400 )
#define TCS_FLATBUTTONS	0x0008
#define TCS_EX_FLATSEPARATORS	0x00000001
#define TCS_EX_REGISTERDROP	0x00000002
#endif /* _WIN32_IE >= 0x0400 */
#define TCIF_TEXT	1
#define TCIF_IMAGE	2
#define TCIF_RTLREADING	4
#define TCIF_PARAM	8
#if (_WIN32_IE >= 0x0400)
#define TCIF_STATE	16
#endif
#define TCIS_BUTTONPRESSED 1
#if (_WIN32_IE >= 0x0400)
#define TCIS_HIGHLIGHTED 2
#endif
#define TCM_FIRST	0x1300
/**
 * This message retrieves the image list associated with a tab control. You
 * can send this message explicitly or by using the TabCtrl_GetImageList
 * macro.
 *
 * @return The handle to the image list indicates success. NULL indicates
 *        otherwise.
 */
#define TCM_GETIMAGELIST	(TCM_FIRST+2)
/**
 * This message assigns an image list to a tab control. You can send this
 * message explicitly or by using the TabCtrl_SetImageList macro.
 *
 * @param himl Handle to the image list to assign to the tab control.
 * @return The handle to the previous image list indicates success. NULL
 *        indicates that there is no previous image list.
 */
#define TCM_SETIMAGELIST	(TCM_FIRST+3)
/**
 * This message retrieves the number of tabs in the tab control. You can
 * send this message explicitly or by using the TabCtrl_GetItemCount macro.
 *
 * @return The number of items indicates success. Zero indicates otherwise.
 */
#define TCM_GETITEMCOUNT	(TCM_FIRST+4)
#define TCM_GETITEMA	(TCM_FIRST+5)
#define TCM_GETITEMW	(TCM_FIRST+60)
#define TCM_SETITEMA	(TCM_FIRST+6)
#define TCM_SETITEMW	(TCM_FIRST+61)
#define TCM_INSERTITEMA	(TCM_FIRST+7)
#define TCM_INSERTITEMW	(TCM_FIRST+62)
/**
 * This message removes an item from a tab control. You can send this
 * message explicitly or by using the TabCtrl_DeleteItem macro.
 *
 * @param iItem Index of the item to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_DELETEITEM	(TCM_FIRST+8)
/**
 * This message removes all items from a tab control. You can send this
 * message explicitly or by using the TabCtrl_DeleteAllItems macro.
 *
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_DELETEALLITEMS	(TCM_FIRST+9)
/**
 * This message retrieves the bounding rectangle for a tab in a tab
 * control. You can send this message explicitly or by using the
 * TabCtrl_GetItemRect macro.
 *
 * @param iItem Index of the tab.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle of the tab, in viewport coordinates.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_GETITEMRECT	(TCM_FIRST+10)
/**
 * This message determines the currently selected tab in a tab control. You
 * can send this message explicitly or by using the TabCtrl_GetCurSel
 * macro.
 *
 * @return The index of the selected tab indicates success. -1 indicates
 *        that no tab is selected.
 */
#define TCM_GETCURSEL	(TCM_FIRST+11)
/**
 * This message selects a tab in a tab control. You can send this message
 * explicitly or by using the TabCtrl_SetCurSel macro.
 *
 * @param iItem Index of the tab to select.
 * @return The index of the previously selected tab indicates success. -1
 *        indicates otherwise.
 */
#define TCM_SETCURSEL	(TCM_FIRST+12)
/**
 * This message determines which tab, if any, is at a specified screen
 * position. You can send this message explicitly or by using the
 * TabCtrl_HitTest macro.
 *
 * @param pinfo Pointer to a TCHITTESTINFO structure that specifies the
 *        screen position to test.
 * @return The index of the tab indicates success. -1 indicates that no tab
 *        is at the specified position.
 */
#define TCM_HITTEST	(TCM_FIRST+13)
/**
 * This message sets the number of bytes per tab reserved for
 * application-defined data in a tab control. You can send this message
 * explicitly or by using the TabCtrl_SetItemExtra macro.
 *
 * By default, the number of extra bytes is four. An application that
 * changes the number of extra bytes cannot use the TCITEM structure to
 * retrieve and set the application-defined data for a tab. Instead, you
 * must define a new structure that consists of the TCITEMHEADER structure
 * followed by application-defined members.
 *
 * @param cb Number of extra bytes.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_SETITEMEXTRA	(TCM_FIRST+14)

/**
 * This message calculates a tab control's display area specified a window
 * rectangle or calculates the window rectangle that would correspond to a
 * specified display area. You can send this message explicitly or by using
 * the TabCtrl_AdjustRect macro.
 *
 * @param fLarger Operation to perform. If set to TRUE, prc specifies a
 *        display rectangle and receives the corresponding window
 *        rectangle. If set to FALSE, prc specifies a window rectangle and
 *        receives the corresponding display area.
 * @param prc Pointer to a RECT structure that specifies the specified
 *        rectangle and receives the calculated rectangle.
 * @return None.
 */
#define TCM_ADJUSTRECT	(TCM_FIRST+40)
/**
 * This message sets the width and height of tabs in a fixed-width or
 * owner-drawn tab control. You can send this message explicitly or by
 * using the TabCtrl_SetItemSize macro.
 *
 * @param cx and cy New width and height, in pixels.
 * @return Returns the old width and height. The width is in the low-order
 *        word of the return value, and the height is in the high-order
 *        word.
 */
#define TCM_SETITEMSIZE	(TCM_FIRST+41)
/**
 * This message removes an image from a tab control's image list. You can
 * send this message explicitly or by using the TabCtrl_RemoveImage macro.
 *
 * @param iImage Index of the image to remove.
 * @return None.
 */
#define TCM_REMOVEIMAGE	(TCM_FIRST+42)
/**
 * This message sets the amount of space (padding) around each tab's icon
 * and label in a tab control. You can send this message explicitly or by
 * using the TabCtrl_SetPadding macro.
 *
 * @param cx and cy Amount of horizontal and vertical padding, in pixels.
 * @return None.
 */
#define TCM_SETPADDING	(TCM_FIRST+43)
/**
 * This message retrieves the current number of rows of tabs in a tab
 * control. You can send this message explicitly or by using the
 * TabCtrl_GetRowCount macro.
 *
 * @return Returns the number of rows of tabs.
 */
#define TCM_GETROWCOUNT	(TCM_FIRST+44)
#define TCM_GETTOOLTIPS	(TCM_FIRST+45)
#define TCM_SETTOOLTIPS	(TCM_FIRST+46)
/**
 * This message returns the index of the item that has the focus in a tab
 * control. You can send this message explicitly or by using the
 * TabCtrl_GetCurFocus macro.
 *
 * @return Returns the index of the tab item that has the focus.
 */
#define TCM_GETCURFOCUS	(TCM_FIRST+47)
/**
 * This message sets the focus to a specified tab in a tab control. You can
 * send this message explicitly or by using the TabCtrl_SetCurFocus macro.
 *
 * If the tab control has the TCS_BUTTONS style (button mode), the tab with
 * the focus may be different from the selected tab. For example, when a
 * tab is selected, the user can press the arrow keys to set the focus to a
 * different tab without changing the selected tab. In button mode,
 * TCM_SETCURFOCUS sets the input focus to the button associated with the
 * specified tab, but it does not change the selected tab.
 *
 * If the tab control does not have the TCS_BUTTONS style, changing the
 * focus also changes the selected tab. In this case, the tab control sends
 * the TCN_SELCHANGING and TCN_SELCHANGE notification messages to its
 * parent window.
 *
 * @param iItem Index of the tab that gets the focus.
 * @return None.
 */
#define TCM_SETCURFOCUS	(TCM_FIRST+48)
/**
 * This message sets the minimum width of items in a tab control.
 *
 * @param cx Minimum width to be set for a tab control item. If this
 *        parameter is set to -1, the control uses the default tab width.
 * @return Returns an INT value that represents the previous minimum tab
 *        width.
 */
#define TCM_SETMINTABWIDTH	(TCM_FIRST + 49)
/**
 * This message resets items in a tab control, clearing any that were set
 * to the TCIS_BUTTONPRESSED state.
 *
 * @param fExcludeFocus Boolean that specifies the scope of the item
 *        deselection. If this parameter is set to FALSE, all tab buttons
 *        are reset. If it is set to TRUE, then all tab items except for
 *        the one currently selected are reset.
 * @return The return value for this message is not used.
 */
#define TCM_DESELECTALL	(TCM_FIRST + 50)
#if (_WIN32_IE >=0x0400)
/**
 * This message sets the highlight state of a tab item.
 *
 * @param idItem Zero-based index of a tab control item.
 * @param fHighlight Boolean that specifies whether the highlight state is
 *        to be set. If this value is TRUE, the tab is highlighted; if
 *        FALSE, the tab is set to its default state.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TCM_HIGHLIGHTITEM	(TCM_FIRST + 51)
/**
 * This message sets the extended styles that the tab control will use.
 *
 * @param dwExMask Specifies which styles in dwExStyle are to be affected.
 *        Only the extended styles in dwExMask will be changed. All other
 *        styles will be maintained as is. If this parameter is zero, then
 *        all of the styles in dwExStyle will be affected.
 * @param dwExStyle Specifies the extended tab control styles. This value
 *        is a combination of Tab Control extended styles.
 * @param dwExMask Allows you to modify one or more extended styles without
 *        having to retrieve the existing styles first. For example: if you
 *        pass TCS_EX_FLATSEPARATORS for dwExMask and 0 for dwExStyle, the
 *        TCS_EX_FLATSEPARATORS style will be cleared, but all other styles
 *        will remain the same. For backward compatibility reasons, the
 *        TabCtrl_SetExtendedStyle macro has not been updated to use
 *        dwExMask.
 * @return Returns a DWORD value that contains the previous tab control
 *        extended styles.
 */
#define TCM_SETEXTENDEDSTYLE	(TCM_FIRST + 52)
/**
 * This message retrieves the extended styles that are currently in use for
 * the tab control.
 *
 * @return Returns a DWORD value that represents the extended styles
 *        currently in use for the tab control. This value is a combination
 *        of tab control extended styles.
 */
#define TCM_GETEXTENDEDSTYLE	(TCM_FIRST + 53)
#define TCM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#define TCM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#endif /* _WIN32_IE >=0x0400 */
/**
 * This notification message notifies a tab control's parent window that a
 * key has been pressed. It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnm Pointer to an NMTCKEYDOWN structure.
 * @return None.
 */
#define TCN_KEYDOWN	TCN_FIRST
/**
 * This notification message notifies a tab control's parent window that
 * the currently selected tab has changed. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * To determine the currently selected tab, use the TabCtrl_GetCurSel
 * macro.
 *
 * @param lpnmhdr Long pointer to an NMHDR structure. The hwndFrom member
 *        is the handle to the tab control. The idFrom member is the child
 *        window identifier of the tab control. The code member is
 *        TCN_SELCHANGE.
 * @return None.
 */
#define TCN_SELCHANGE	(TCN_FIRST-1)
/**
 * This notification message notifies a tab control's parent window that
 * the currently selected tab is about to change. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * To determine the currently selected tab, use the TabCtrl_GetCurSel
 * macro.
 *
 * @param lpnmhdr Long pointer to an NMHDR structure. The hwndFrom member
 *        is the handle to the tab control. The idFrom member is the child
 *        window identifier of the tab control. The code member is
 *        TCN_SELCHANGING.
 * @return TRUE prevents the selection from changing. FALSE allows the
 *        selection to change.
 */
#define TCN_SELCHANGING	(TCN_FIRST-2)
#define NM_OUTOFMEMORY (NM_FIRST-1)
/**
 * This notification message is sent by a list view control when the user
 * clicks an item with the left mouse button. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * This notification is identical to the standard NM_CLICK notification
 * except that the list view supplies a NMLISTVIEW structure instead of an
 * NMHDR structure for the lParam.
 *
 * @param lpnmlv Long pointer to an NMLISTVIEW structure that contains
 *        additional information about this notification message. The
 *        iItem, iSubItem and ptAction members of this structure contain
 *        information about the item.
 * @return The return value for this notification is not used.
 */
#define NM_CLICK (NM_FIRST-2)
#define NM_DBLCLK (NM_FIRST-3)
#define NM_RETURN (NM_FIRST-4)
#define NM_RCLICK (NM_FIRST-5)
#define NM_RDBLCLK (NM_FIRST-6)
#define NM_SETFOCUS (NM_FIRST-7)
#define NM_KILLFOCUS (NM_FIRST-8)
/**
 * This notification message is sent by some common controls to notify
 * their parent windows about drawing operations. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * Currently header, list view, rebar, toolbar, trackbar, and tree view
 * controls support Custom Draw functionality.
 *
 * @param lpNMCustomDraw Long pointer to a Custom Draw-related structure
 *        that contains information about the drawing operation. List view
 *        controls use the NMLVCUSTOMDRAW structure, and all other
 *        supported controls use the NMCUSTOMDRAW structure.
 * @return The value your application can return depends on the current
 *        drawing stage. The dwDrawStage member of the associated
 *        NMCUSTOMDRAW structure holds a value that specifies the drawing
 *        stage. You must return one of the following values. When
 *        dwDrawStage equals CDDS_PREPAINT: CDRF_DODEFAULT: The control
 *        will draw itself. It will not send any additional NM_CUSTOMDRAW
 *        messages for this paint cycle. CDRF_NOTIFYITEMDRAW: The control
 *        will notify the parent of any item-related drawing operations. It
 *        will send NM_CUSTOMDRAW notification messages before and after
 *        drawing items. CDRF_NOTIFYITEMERASE: The control will notify the
 *        parent when an item will be erased. It will send NM_CUSTOMDRAW
 *        notification messages before and after erasing items.
 *        CDRF_NOTIFYPOSTERASE: The control will notify the parent after
 *        erasing an item. CDRF_NOTIFYPOSTPAINT: The control will notify
 *        the parent after painting an item. When dwDrawStage equals
 *        CDDS_ITEMPREPAINT: CDRF_NEWFONT: Your application specified a new
 *        font for the item; the control will use the new font. For more
 *        information on changing fonts, see Changing Fonts And Colors.
 *        CDRF_SKIPDEFAULT: Your application drew the item manually. The
 *        control will not draw the item.
 */
#define NM_CUSTOMDRAW (NM_FIRST-12)
#define NM_HOVER (NM_FIRST-13)
#define NM_NCHITTEST (NM_FIRST-14)
/**
 * This notification message is sent by a control when the control has the
 * keyboard focus and the user presses a key. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * This notification is not sent by all controls. Currently, only the
 * toolbar sends this notification.
 *
 * @param lpnmk Long pointer to an NMKEY structure that contains additional
 *        information about the key that caused the notification message.
 * @return Return nonzero to prevent the control from processing the key or
 *        zero otherwise.
 */
#define NM_KEYDOWN (NM_FIRST-15)
#define NM_RELEASEDCAPTURE (NM_FIRST-16)
#define NM_SETCURSOR (NM_FIRST-17)
#define NM_CHAR (NM_FIRST-18)
#define NM_TOOLTIPSCREATED (NM_FIRST-19)
#define SBARS_SIZEGRIP 256
#define CCM_FIRST 0x2000
#define CCM_LAST (CCM_FIRST+0x200)
#define CCM_SETBKCOLOR 8193
#define CCM_SETCOLORSCHEME 8194
#define CCM_GETCOLORSCHEME 8195
#define CCM_GETDROPTARGET 8196
#define CCM_SETUNICODEFORMAT 8197
#define CCM_GETUNICODEFORMAT 8198
#define CCM_SETVERSION 0x2007
#define CCM_GETVERSION 0x2008
#define CCM_SETNOTIFYWINDOW 0x2009
#if (_WIN32_WINNT >= 0x0501)
#define CCM_SETWINDOWTHEME 0x200b
#define CCM_DPISCALE 0x200c
#endif 
#define ICC_LISTVIEW_CLASSES 1
#define ICC_TREEVIEW_CLASSES 2
#define ICC_BAR_CLASSES	4
#define ICC_TAB_CLASSES      8
#define ICC_UPDOWN_CLASS 16
#define ICC_PROGRESS_CLASS 32
#define ICC_HOTKEY_CLASS 64
#define ICC_ANIMATE_CLASS 128
#define ICC_WIN95_CLASSES 255
#define ICC_DATE_CLASSES 256
#define ICC_USEREX_CLASSES 512
#define ICC_COOL_CLASSES 1024
#if (_WIN32_IE >= 0x0400)
#define ICC_INTERNET_CLASSES 2048
#define ICC_PAGESCROLLER_CLASS 4096
#define ICC_NATIVEFNTCTL_CLASS 8192
#define INFOTIPSIZE 1024
#endif /* _WIN32_IE */
#if (_WIN32_WINNT >= 0x501)
#define ICC_STANDARD_CLASSES	0x00004000
#define ICC_LINK_CLASS		0x00008000
#endif
#define GDTR_MIN 1
#define GDTR_MAX 2
#define GMR_VISIBLE 0
#define GMR_DAYSTATE 1
#define GDT_ERROR -1
#define GDT_VALID 0
#define GDT_NONE 1
#define DTS_UPDOWN 1
#define DTS_SHOWNONE 2
#define DTS_SHORTDATEFORMAT 0
#define DTS_LONGDATEFORMAT 4
#define DTS_TIMEFORMAT 9
#define DTS_APPCANPARSE 16
#define DTS_RIGHTALIGN 32
#if ( _WIN32_IE >= 0x500 )
#define DTS_SHORTDATECENTURYFORMAT	0x000C
#endif /* _WIN32_IE >= 0x500 */
#define MCS_DAYSTATE 1
#define MCS_MULTISELECT 2
#define MCS_WEEKNUMBERS 4
#if (_WIN32_IE >= 0x0400)
#define MCS_NOTODAYCIRCLE	0x0008
#define MCS_NOTODAY	0x0010
#else /* _WIN32_IE >= 0x0400 */
#if defined(_WIN32_WCE) && GRIMACE_CE >= 2
#define MCS_NOTODAY	0x0010
#else
#define MCS_NOTODAY	0x0008
#endif
#endif /* _WIN32_IE >= 0x0400 */
/**
 * This message retrieves the currently selected time from a date and time
 * picker (DTP) control and places it in a specified SYSTEMTIME structure.
 *
 * @param lpSysTime Long pointer to the SYSTEMTIME structure that receives
 *        the system time information. This parameter must be a valid
 *        address and cannot be NULL.
 * @return Returns GDT_VALID if the time information was placed
 *        successfully in the specified structure; or the message can
 *        return GDT_NONE if the control was set to the DTS_SHOWNONE style
 *        and the control check box was not selected.
 */
#define DTM_GETSYSTEMTIME 0x1001
/**
 * This message sets the time in a date and time picker (DTP) control.
 *
 * @param flag Specifies the action that should be performed. It is one of
 *        the following values: Value Description GDT_VALID Sets the DTP
 *        control according to the data within the structure that lpSysTime
 *        points to. GDT_NONE Sets the DTP control to "no date" and clear
 *        its check box. lpSysTime is ignored when this flag is specified.
 *        This flag applies only to DTP controls that are set to the
 *        DTS_SHOWNONE style.
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the system time used to set the DTP control.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define DTM_SETSYSTEMTIME 0x1002
/**
 * This message retrieves the current minimum and maximum allowable system
 * times for a date and time picker (DTP) control.
 *
 * The first element of the SYSTEMTIME array contains the minimum allowable
 * time if GDTR_MIN is set. The second element of the SYSTEMTIME array
 * contains the maximum allowable time if GDTR_MAX is set.
 *
 * @param lpSysTimeArray Long pointer to a two-element array of SYSTEMTIME
 *        structures.
 * @return Returns a DWORD value that is a combination of GDTR_MIN or
 *        GDTR_MAX.
 */
#define DTM_GETRANGE 0x1003
/**
 * This message sets the minimum and maximum allowable system times for a
 * date and time picker (DTP) control.
 *
 * @param flags Specifies which range values are valid. It can be a
 *        combination of the following values: Value Description GDTR_MIN
 *        The first element in the SYSTEMTIME structure array is valid and
 *        will be used to set the minimum allowable system time. GDTR_MAX
 *        The second element in the SYSTEMTIME structure array is valid and
 *        will be used to set the maximum allowable system time.
 * @param lpSysTimeArray Long pointer to a two-element array of SYSTEMTIME
 *        structures. The first element of the SYSTEMTIME array contains
 *        the minimum allowable time. The second element of the SYSTEMTIME
 *        array contains the maximum allowable time. It is not necessary to
 *        fill an array element that is not specified in the flags
 *        parameter.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define DTM_SETRANGE 0x1004
#define DTM_SETFORMATA 0x1005
#define DTM_SETFORMATW 0x1032
/**
 * This message sets the color for a specified portion of the month
 * calendar within a date and time picker (DTP) control.
 *
 * @param iColor Specifies which month calendar color to set. It is one of
 *        the following values: Value Description MCSC_BACKGROUND Sets the
 *        background color displayed between months. MCSC_MONTHBK Sets the
 *        background color displayed within the month. MCSC_TEXT Sets the
 *        color used to display text within a month. MCSC_TITLEBK Sets the
 *        background color displayed in the calendar's title.
 *        MCSC_TITLETEXT Sets the color used to display text within the
 *        calendar's title. MCSC_TRAILINGTEXT Sets the color used to
 *        display header and trailing-day text. Header and trailing days
 *        are the days from the previous and following months that appear
 *        on the current calendar.
 * @param clr COLORREF value that represents the color that is set for the
 *        specified area of the month calendar.
 * @return Returns a COLORREF value that represents the previous color
 *        setting for the specified portion of the month calendar control
 *        if successful. Otherwise, the message returns -1.
 */
#define DTM_SETMCCOLOR 0x1006
/**
 * This message retrieves the color for a specified portion of the month
 * calendar within a date and time picker (DTP) control.
 *
 * @param iColor Specifies which month calendar color to retrieve. It is
 *        one of the following values: Value Description MCSC_BACKGROUND
 *        Retrieves the background color displayed between months.
 *        MCSC_MONTHBK Retrieves the background color displayed within the
 *        month. MCSC_TEXT Retrieves the color used to display text within
 *        a month. MCSC_TITLEBK Retrieves the background color displayed in
 *        the calendar's title. MCSC_TITLETEXT Retrieves the color used to
 *        display text within the calendar's title. MCSC_TRAILINGTEXT
 *        Retrieves the color used to display header and trailing-day text.
 *        Header and trailing days are the days from the previous and
 *        following months that appear on the current calendar.
 * @return Returns a COLORREF value that represents the color setting for
 *        the specified portion of the month calendar control if
 *        successful. The message returns -1 if unsuccessful.
 */
#define DTM_GETMCCOLOR 0x1007
/**
 * This message retrieves the handle to a date and time picker's (DTP)
 * child month calendar control.
 *
 * DTP controls create a child month calendar control when the user clicks
 * the drop-down arrow. When the month calendar is no longer needed, it is
 * destroyed. Therefore, your application must not rely on a static handle
 * to the DTP control's child month calendar.
 *
 * @return Returns the handle to a DTP control's child month calendar
 *        control upon success. The message returns NULL upon failure.
 */
#define DTM_GETMONTHCAL 0x1008
/**
 * This message sets the font to be used by the date and time picker (DTP)
 * control's child month calendar control.
 *
 * @param hFont Handle to the font to be set.
 * @param fRedraw Boolean that specifies whether the control should be
 *        redrawn immediately upon setting the font. Setting this parameter
 *        to TRUE causes the control to redraw itself.
 * @return The return value for this message is not used.
 */
#define DTM_SETMCFONT	0x1009
/**
 * This message retrieves the font that the date and time picker (DTP)
 * control's child month calendar control is currently using.
 *
 * @return Returns an HFONT value that is the handle to the current font.
 */
#define DTM_GETMCFONT	0x100a
#define DTN_USERSTRINGA  ((UINT)-758)
#define DTN_USERSTRINGW  ((UINT)-745)
#define DTN_WMKEYDOWNA  ((UINT)-757)
#define DTN_WMKEYDOWNW  ((UINT)-744)
#define DTN_FORMATA  ((UINT)-756) 
#define DTN_FORMATW  ((UINT)-743)
#define DTN_FORMATQUERYA  ((UINT)-755) 
#define DTN_FORMATQUERYW ((UINT)-742)
/**
 * This notification message is sent by a date and time picker (DTP)
 * control when the user activates the drop-down month calendar.
 *
 * DTP controls do not maintain a static child month calendar control. The
 * DTP control creates a new month calendar control before sending this
 * notification message. Additionally, the DTP control destroys the child
 * control when it is not active (visible). Therefore, your application
 * must not rely on a static window handle for the control's child month
 * calendar.
 *
 * @param lpNmhdr Long pointer to an NMHDR structure that contains
 *        information about the notification message.
 * @return The return value for this notification is not used.
 */
#define DTN_DROPDOWN    ((UINT)-754) 
/**
 * This notification message is sent by a date and time picker (DTP)
 * control when the user closes the drop-down month calendar. The month
 * calendar is closed when the user chooses a date from the month calendar
 * or clicks the drop-down arrow while the calendar is open.
 *
 * DTP controls do not maintain a static child month calendar control. The
 * DTP control destroys the child month calendar control prior to sending
 * this notification. Therefore, your application must not rely on a static
 * window handle for the control's child month calendar.
 *
 * @param lpNmhdr Long pointer to an NMHDR structure that contains
 *        information about the notification message.
 * @return The return value for this notification is not used.
 */
#define DTN_CLOSEUP	((UINT)-753) 
/**
 * This notification message is sent by a date and time picker (DTP)
 * control whenever a change occurs. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param lpChange Long pointer to an NMDATETIMECHANGE structure that
 *        contains information about the change that took place in the
 *        control.
 * @return The owner of the control must return zero.
 */
#define DTN_DATETIMECHANGE ((UINT)-759) 
/**
 * This message retrieves the system time portrayed by the currently
 * selected date.
 *
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that receives
 *        the system time information. The time members of this structure
 *        are not modified.
 * @return Nonzero indicates success. Zero indicates otherwise. This
 *        message always fails when applied to month calendar controls set
 *        to the MCS_MULTISELECT style.
 */
#define MCM_GETCURSEL	0x1001
/**
 * This message sets the currently selected date for a month calendar
 * control. If the specified date is not in view, the control updates the
 * display to bring it into view.
 *
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the date to be set as the current selection. The time members of
 *        this structure are ignored.
 * @return Nonzero indicates success. Zero indicates otherwise. This
 *        message fails if applied to a month calendar control that uses
 *        the MCS_MULTISELECT style.
 */
#define MCM_SETCURSEL	0x1002
/**
 * This message retrieves the maximum selectable date range that is set for
 * a month calendar control.
 *
 * You can change the selectable date range using the MCM_SETMAXSELCOUNT
 * message.
 *
 * @return Returns an INT value that represents the total number of days
 *        that can be selected for the control.
 */
#define MCM_GETMAXSELCOUNT 0x1003
/**
 * This message sets the maximum number of days that can be selected in a
 * month calendar control.
 *
 * @param iMax INT value that is set to represent the maximum number of
 *        selectable days.
 * @return Returns nonzero if successful, and returns zero otherwise. This
 *        message fails if applied to a month calendar control that does
 *        not use the MCS_MULTISELECT style.
 */
#define MCM_SETMAXSELCOUNT 0x1004
/**
 * This message retrieves date information that represents the upper and
 * lower limits of the date range currently selected by the user
 *
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that receives the lower and upper limits of
 *        the user's selection. The lower and upper limits are placed in
 *        lprgSysTimeArray[0] and lprgSysTimeArray[1], respectively. The
 *        time members of these structures are not modified.
 * @return Nonzero indicates success. Zero indicates otherwise.
 *        MCM_GETSELRANGE fails if applied to a month calendar control that
 *        does not use the MCS_MULTISELECT style.
 */
#define MCM_GETSELRANGE	0x1005
/**
 * This message sets the selection for a month calendar control to a
 * specified date range.
 *
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that contains date information representing
 *        the selection limits. The first selected date must be specified
 *        in lpSysTimeArray[0], and the last selected date must be
 *        specified in lpSysTimeArray[1]. The time members of these
 *        structures are ignored.
 * @return Nonzero indicates success. Zero indicates otherwise. This
 *        message fails if applied to a month calendar control that does
 *        not use the MCS_MULTISELECT style.
 */
#define MCM_SETSELRANGE	0x1006
/**
 * This message, using SYSTEMTIME structures, retrieves date information
 * that represents the high and low limits of a month calendar control's
 * display.
 *
 * @param dwFlag Specifies the scope of the range limits to be retrieved.
 *        It is one of the following values: Value Description GMR_DAYSTATE
 *        Includes preceding and trailing months of visible range that are
 *        only partially displayed. GMR_VISIBLE Includes only those months
 *        that are entirely displayed.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that receives the lower and upper limits of
 *        the scope specified by dwFlag. The lower and upper limits are
 *        placed in lprgSysTimeArray[0] and lprgSysTimeArray[1],
 *        respectively. The time members of these structures are not
 *        modified.
 * @return Returns an INT that represents the range, in months, spanned by
 *        the two limits returned at lprgSysTimeArray.
 */
#define MCM_GETMONTHRANGE 0x1007
/**
 * This message sets the display for days in all months that are currently
 * visible within a month calendar control.
 *
 * Keep in mind that the array at lpDayStateArray must contain
 * MONTHDAYSTATE values that correspond with all months currently in the
 * control's display, in chronological order. This includes the two months
 * only partially displayed before the first month and after the last
 * month. For more information about preparing your array, see "Preparing
 * the MONTHDAYSTATE Array."
 *
 * @param iMonths Indicates how many elements are in the array that
 *        lpDayStateArray points to.
 * @param lpDayStateArray Long pointer to an array of MONTHDAYSTATE values
 *        that define how the month calendar control will draw each day in
 *        its display. The array at lpDayStateArray must contain as many
 *        elements as the value returned by the following macro.
 * @return Sets the month calendar's display and returns nonzero if
 *        successful. Otherwise it returns zero.
 */
#define MCM_SETDAYSTATE	0x1008
/**
 * This message retrieves the minimum size required to display a full month
 * in a month calendar control. Size information is presented in the form
 * of a RECT structure.
 *
 * The top and left members of lpRectInfo will always be zero. The right
 * and bottom members represent the minimum cx and cy required for the
 * control.
 *
 * The minimum required window size for a month calendar control depends on
 * the currently selected font.
 *
 * @param lpRectInfo Long pointer to a RECT structure that receives
 *        bounding rectangle information.
 * @return Returns nonzero and lpRectInfo receives the applicable bounding
 *        information if successful. The message returns zero upon failure.
 */
#define MCM_GETMINREQRECT 0x1009
/**
 * This message sets the color for a specified portion of a month calendar
 * control.
 *
 * @param iColor Specifies which month calendar color to set. It is one of
 *        the following values: Value Description MCSC_BACKGROUND Retrieves
 *        the background color displayed between months. MCSC_MONTHBK
 *        Retrieves the background color displayed within the month.
 *        MCSC_TEXT Retrieves the color used to display text within a
 *        month. MCSC_TITLEBK Retrieves the background color displayed in
 *        the calendar's title. MCSC_TITLETEXT Retrieves the color used to
 *        display text within the calendar's title. MCSC_TRAILINGTEXT
 *        Retrieves the color used to display header and trailing-day text.
 *        Header and trailing days are the days from the previous and
 *        following months that appear on the current calendar.
 * @param clr COLORREF value that represents the color that is set for the
 *        specified area of the month calendar.
 * @return Returns a COLORREF value that represents the previous color
 *        setting for the specified portion of the month calendar control
 *        if successful. Otherwise, this message returns -1.
 */
#define MCM_SETCOLOR 0x100a
/**
 * This message retrieves the color for a specified portion of a month
 * calendar control.
 *
 * @param iColor Specifies which month calendar color to retrieve. It is
 *        one of the following values: Value Description MCSC_BACKGROUND
 *        Retrieves the background color displayed between months.
 *        MCSC_MONTHBK Retrieves the background color displayed within the
 *        month. MCSC_TEXT Retrieves the color used to display text within
 *        a month. MCSC_TITLEBK Retrieves the background color displayed in
 *        the calendar's title. MCSC_TITLETEXT Retrieves the color used to
 *        display text within the calendar's title. MCSC_TRAILINGTEXT
 *        Retrieves the color used to display header and trailing-day text.
 *        Header and trailing days are the days from the previous and
 *        following months that appear on the current calendar.
 * @return Returns a COLORREF value that represents the color setting for
 *        the specified portion of the month calendar control if
 *        successful. Otherwise, this message returns -1.
 */
#define MCM_GETCOLOR 0x100b
/**
 * This message sets the "today" selection for a month calendar control.
 *
 * The control will not automatically update the "today" selection when the
 * time passes midnight for the current day.
 *
 * The control will not automatically update its display based on locale
 * changes.
 *
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the date to be set as the "today" selection for the control. If
 *        this parameter is set to NULL, the control returns to the default
 *        setting. The time members of this structure are ignored. If the
 *        "today" selection is set to any date other than the default, the
 *        following conditions apply.
 * @return The return value for this message is not used.
 */
#define MCM_SETTODAY 0x100c
/**
 * This message retrieves the date information for the date specified as
 * "today" for a month calendar control.
 *
 * @param lpToday Long pointer to a SYSTEMTIME structure that receives the
 *        date information. The time members of this structure are not
 *        modified.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define MCM_GETTODAY 0x100d
/**
 * This message determines which portion of a month calendar control is at
 * a specified point on the screen.
 *
 * The uHit member of the MCHITTESTINFO structure at pMCHitTest will equal
 * the return value.
 *
 * @param pMCHitTest Pointer to an MCHITTESTINFO structure. Upon sending
 *        the message, the cbSize member must equal sizeof(MCHITTESTINFO),
 *        and pt must be set to the point you want to hit test.
 * @return Sets values in members of the MCHITTESTINFO structure at
 *        pMCHitTest and returns a DWORD value that is one of the following
 *        values: MCHT_CALENDAR: The specified point was within the
 *        calendar. MCHT_CALENDARBK: The specified point was in the
 *        calendar's background. MCHT_CALENDARDATE: The specified point was
 *        on a particular date within the calendar. The SYSTEMTIME
 *        structure at lpMCHitTest->st is set to the date at the specified
 *        point. MCHT_CALENDARDATENEXT: The specified point was over a date
 *        from the next month (partially displayed at the end of the
 *        currently displayed month). If the user clicks here, the month
 *        calendar will scroll its display to the next month or set of
 *        months. MCHT_CALENDARDATEPREV: The specified point was over a
 *        date from the previous month (partially displayed at the end of
 *        the currently displayed month). If the user clicks here, the
 *        month calendar will scroll its display to the previous month or
 *        set of months. MCHT_CALENDARDAY: The specified point was over a
 *        day abbreviation ("Fri"). The SYSTEMTIME structure at
 *        lpMCHitTest->st is set to the corresponding date in the top row.
 *        MCHT_CALENDARWEEKNUM: The specified point was over a week number
 *        (The MCS_WEEKNUMBERS style only.) The SYSTEMTIME structure at
 *        lpMCHitTest->st is set to the corresponding date in the leftmost
 *        column. MCHT_NEXT: The specified point was over the button at the
 *        top right corner of the control. If the user clicks here, the
 *        month calendar will scroll its display to the next month or set
 *        of months. MCHT_NOWHERE: The specified point was either not on
 *        the month calendar control, or in an inactive portion of the
 *        control. MCHT_PREV: The specified point was over the button at
 *        the top left corner of the control. If the user clicks here, the
 *        month calendar will scroll its display to the previous month or
 *        set of months. MCHT_TITLE: The specified point was over a month's
 *        title. MCHT_TITLEBK: The specified point was over the background
 *        of a month's title. MCHT_TITLEBTNNEXT: The specified point was
 *        over the button at the top right corner of the control. If the
 *        user clicks here, the month calendar will scroll its display to
 *        the next month or set of months. MCHT_TITLEBTNPREV: The specified
 *        point was over the button at the top left corner of the control.
 *        If the user clicks here, the month calendar will scroll its
 *        display to the previous month or set of months. MCHT_TITLEMONTH:
 *        The specified point was in the a month's title bar, over a month
 *        name. MCHT_TITLEYEAR: The specified point was in a month's title
 *        bar, over the year value. MCHT_TODAYLINK: The specified point was
 *        on the "today" link at the bottom of the month calendar control.
 */
#define MCM_HITTEST 0x100e
/**
 * This message sets the first day of the week for a month calendar
 * control.
 *
 * If the first day of the week is set to anything other than the default
 * (LOCALE_IFIRSTDAYOFWEEK), the control will not automatically update
 * first-day-of-the-week changes based on locale changes.
 *
 * @param iDay INT value representing which day is to be set as the first
 *        day of the week. It is one of the following values: Value Day of
 *        the week 0 Sunday 1 Monday 2 Tuesday 3 Wednesday 4 Thursday 5
 *        Friday 6 Saturday
 * @return Returns a DWORD value that contains two values. The high-order
 *        word is a BOOL that is nonzero if the previous first day of the
 *        week did not equal LOCALE_IFIRSTDAYOFWEEK, or zero otherwise. The
 *        low-order word is an INT value that represents the previous day
 *        of the week number (see list under iDay).
 */
#define MCM_SETFIRSTDAYOFWEEK 0x100f
/**
 * This message retrieves the first day of the week for a month calendar
 * control.
 *
 * @return Returns a DWORD value that contains two values. The high-order
 *        word is a BOOL that is nonzero if the first day of the week is
 *        set to something other than LOCALE_IFIRSTDAYOFWEEK, or zero
 *        otherwise. The low-order word is an INT value that represents the
 *        first day of the week, as shown in the following table. Value Day
 *        of the week 0 Sunday 1 Monday 2 Tuesday 3 Wednesday 4 Thursday 5
 *        Friday 6 Saturday
 */
#define MCM_GETFIRSTDAYOFWEEK 0x1010
/**
 * This message retrieves the minimum and maximum allowable dates set for a
 * month calendar control.
 *
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that receives the date limit information.
 *        The minimum limit is set in lprgSysTimeArray[0], and
 *        lprgSysTimeArray[1] receives the maximum limit. If either element
 *        is set to all zeros, then no corresponding limit is set for the
 *        month calendar control. The time members of these structures are
 *        not modified.
 * @return Returns a DWORD that can be zero (no limits are set) or a
 *        combination of the following values that specify limit
 *        information: GDTR_MAX: A maximum limit is set for the control;
 *        lprgSysTimeArray[0] is valid and contains the applicable date
 *        information. GDTR_MIN: A minimum limit is set for the control;
 *        lprgSysTimeArray[1] is valid and contains the applicable date
 *        information.
 */
#define MCM_GETRANGE 0x1011
/**
 * This message sets the minimum and maximum allowable dates for a month
 * calendar control.
 *
 * @param fWhichLimit Specifies which limit dates are being set. It is one
 *        or both of the following values: Value Description GDTR_MAX The
 *        maximum allowable date is being set. The SYSTEMTIME structure at
 *        lprgSysTimeArray[1] must contain date information. GDTR_MIN The
 *        minimum allowable date is being set. The SYSTEMTIME structure at
 *        lprgSysTimeArray[0] must contain date information.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that contains date limit information. The
 *        maximum limit must be in lpSysTimeArray[1] if GDTR_MAX is
 *        specified, and lpSysTimeArray[0] must contain the minimum limit
 *        if GDTR_MIN is specified. The time members of these structures
 *        are ignored.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define MCM_SETRANGE 0x1012
/**
 * This message retrieves the "scroll rate" for a month calendar control.
 * The scroll rate is the number of months that the control moves its
 * display when the user clicks a scroll button.
 *
 * @return If the month delta was previously set using the
 *        MCM_SETMONTHDELTA message, returns an INT value that represents
 *        the month calendar's current scroll rate. If the month delta was
 *        not previously set using the MCM_SETMONTHDELTA message or the
 *        month delta was reset to the default, returns an INT value that
 *        represents the current number of months visible.
 */
#define MCM_GETMONTHDELTA 0x1013
/**
 * This message sets the "scroll rate" for a month calendar control. The
 * scroll rate is the number of months that a month calendar control moves
 * its display when the user clicks a scroll button.
 *
 * @param iDelta Number of months to be set as the control's scroll rate.
 *        If this value is zero, the month delta is reset to the default,
 *        which is the number of months displayed in the control.
 * @return Returns an INT value that represents the previous scroll rate.
 *        If the scroll rate has not been previously set, the return value
 *        is zero.
 */
#define MCM_SETMONTHDELTA 0x1014
/**
 * This message retrieves the maximum width of the "Today" string in a
 * month calendar control. This includes the label text and the date text.
 *
 * @return Returns the width of the "Today" string, in pixels.
 */
#define MCM_GETMAXTODAYWIDTH 0x1015
#define MCM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define MCM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
/**
 * This notification message is sent by a month calendar control whenever
 * the currently selected date or range of dates changes. It is sent in the
 * form of a WM_NOTIFY message.
 *
 * This notification message is similar to MCN_SELECT, but is sent in
 * response to any selection change, whereas MCN_SELECT is sent only for an
 * explicit date selection.
 *
 * @param lpNMSelChange Long pointer to an NMSELCHANGE structure that
 *        contains information about the currently selected date range.
 */
#define MCN_SELCHANGE	  ((UINT)-749)
/**
 * This notification message is sent by a month calendar control to request
 * information about how individual days should be displayed. It is sent
 * only by month calendar controls that use the MCS_DAYSTATE style, and is
 * sent in the form of a WM_NOTIFY message.
 *
 * Handling this notification message allows your application to customize
 * its display by specifying that certain days be displayed in bold. For
 * more information about processing this message, see "Processing the
 * MCN_GETDAYSTATE Notification Message."
 *
 * @param lpNMDayState Long pointer to an NMDAYSTATE structure. The
 *        structure contains information about the time frame for which the
 *        control needs information, and receives the address of an array
 *        that provides such data.
 */
#define MCN_GETDAYSTATE	((UINT)-747)
/**
 * This notification message is sent by a month calendar control whenever
 * the user makes an explicit date selection within a month calendar
 * control. It is sent in the form of a WM_NOTIFY message.
 *
 * This notification message is similar to MCN_SELCHANGE, but is sent only
 * in response to a user's explicit date selections, whereas MCN_SELCHANGE
 * applies to any selection change.
 *
 * @param lpNMSelChange Long pointer to an NMSELCHANGE structure that
 *        contains information about the currently selected date range.
 */
#define MCN_SELECT		((UINT)-746)
#define ODT_HEADER 100
#define ODT_TAB 101
#define ODT_LISTVIEW 102
#define SB_SETBKCOLOR	0x2001
#if (_WIN32_IE >= 0x0300)
/**
 * This message checks a status window control to determine if it is in
 * simple mode.
 *
 * @return Returns nonzero if the status window control is in simple mode,
 *        or zero otherwise.
 */
#define SB_ISSIMPLE 1038
#define MCSC_BACKGROUND 0
#define MCSC_TEXT 1
#define MCSC_TITLEBK 2
#define MCSC_TITLETEXT 3
#define MCSC_MONTHBK 4
#define MCSC_TRAILINGTEXT 5
#endif
#if (_WIN32_IE >= 0x0400)
#define MCHT_TITLE 0x10000
#define MCHT_CALENDAR 0x20000
#define MCHT_TODAYLINK 0x30000
#define MCHT_NEXT 0x1000000
#define MCHT_PREV 0x2000000
#define MCHT_NOWHERE 0x00
#define MCHT_TITLEBK (MCHT_TITLE)
#define MCHT_TITLEMONTH (MCHT_TITLE | 0x0001)
#define MCHT_TITLEYEAR (MCHT_TITLE | 0x0002)
#define MCHT_TITLEBTNNEXT (MCHT_TITLE | MCHT_NEXT | 0x0003)
#define MCHT_TITLEBTNPREV (MCHT_TITLE | MCHT_PREV | 0x0003)
#define MCHT_CALENDARBK (MCHT_CALENDAR)
#define MCHT_CALENDARDATE (MCHT_CALENDAR | 0x0001)
#define MCHT_CALENDARDATENEXT (MCHT_CALENDARDATE | MCHT_NEXT)
#define MCHT_CALENDARDATEPREV (MCHT_CALENDARDATE | MCHT_PREV)
#define MCHT_CALENDARDAY (MCHT_CALENDAR | 0x0002)
#define MCHT_CALENDARWEEKNUM (MCHT_CALENDAR | 0x0003)
#endif /* _WIN32_IE >= 0x0400 */
#define RBS_TOOLTIPS 256
#define RBS_VARHEIGHT 512
#define RBS_BANDBORDERS 1024
#define RBS_FIXEDORDER 2048
#define RBIM_IMAGELIST 1
#define RB_SETCOLORSCHEME CCM_SETCOLORSCHEME
#define RB_GETCOLORSCHEME CCM_GETCOLORSCHEME
#define RBBS_BREAK	0x0001
#define RBBS_FIXEDSIZE	0x0002
#define RBBS_CHILDEDGE	0x0004
#define RBBS_HIDDEN	0x0008
#define RBBS_NOVERT	0x0010
#define RBBS_FIXEDBMP	0x0020
#define RBBS_VARIABLEHEIGHT	0x0040
#define RBBS_GRIPPERALWAYS	0x0080
#define RBBS_NOGRIPPER	0x0100
#if (_WIN32_IE >= 0x0500)
#define RBBS_USECHEVRON	0x0200
#if (_WIN32_IE >= 0x0501)
#define RBBS_HIDETITLE	0x0400
#define RBBS_TOPALIGN	0x0800
#endif /* _WIN32_IE >= 0x0501 */
#endif /* _WIN32_IE >= 0x0500 */
#define RBBIM_STYLE 1
#define RBBIM_COLORS 2
#define RBBIM_TEXT 4
#define RBBIM_IMAGE 8
#define RBBIM_CHILD 16
#define RBBIM_CHILDSIZE 32
#define RBBIM_SIZE 64
#define RBBIM_BACKGROUND 128
#define RBBIM_ID 256
#define RB_INSERTBANDA (WM_USER+1)
#define RB_INSERTBANDW (WM_USER+10)
/**
 * This message deletes a band from a rebar control.
 *
 * @param uBand Zero-based index of the band to be deleted.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_DELETEBAND (WM_USER+2)
/**
 * This message retrieves information about the rebar control and the image
 * list it uses.
 *
 * @param lprbi Long pointer to a REBARINFO structure that receives the
 *        rebar control information. Set the cbSize member of this
 *        structure to sizeof(REBARINFO) before sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_GETBARINFO (WM_USER+3)
/**
 * This message sets the characteristics of a rebar control.
 *
 * When the fMask member of the REBARINFO structure specifies an invalid
 * value, this message returns TRUE when it should return FALSE.
 *
 * @param lprbi Long pointer to a REBARINFO structure that contains the
 *        information to be set. Set the cbSize member of this structure to
 *        sizeof(REBARINFO) before sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_SETBARINFO (WM_USER+4)
/**
 * This message retrieves the count of bands currently in the rebar
 * control.
 *
 * @return Returns a UINT value that represents the number of bands
 *        assigned to the control.
 */
#define RB_GETBANDCOUNT (WM_USER+12)
/**
 * This message retrieves the number of band rows in a rebar control.
 *
 * @return Returns a UINT value that represents the number of band rows in
 *        the control.
 */
#define RB_GETROWCOUNT (WM_USER+13)
/**
 * This message retrieves the height of a specified row in a rebar control.
 *
 * To retrieve the number of rows in a rebar control, use the
 * RB_GETROWCOUNT message.
 *
 * @param uRow Zero-based index of a band. The height of the row that
 *        contains the specified band will be retrieved.
 * @return Returns a UINT value that represents the row height, in pixels.
 */
#define RB_GETROWHEIGHT (WM_USER+14)
#define RB_SETBANDINFOA (WM_USER+6)
#define RB_SETBANDINFOW (WM_USER+11)
/**
 * This message sets a rebar control's parent window.
 *
 * The rebar control sends notification messages to the window you specify
 * with this message. This message does not change the actual parent that
 * was set when the control was created.
 *
 * @param hwndParent Handle to the parent window to be set.
 * @return Returns the handle to the previous parent window, or NULL if
 *        there is no previous parent.
 */
#define RB_SETPARENT (WM_USER+7)
/**
 * This notification message is sent by a rebar control when its height has
 * changed. It is sent in the form of a WM_NOTIFY message.
 *
 * Rebar controls that use the CCS_VERT style send this notification
 * message when their width changes.
 *
 * @param lpnmhdr Long pointer to an NMHDR structure that contains
 *        additional information about this notification message.
 * @return The return value for this notification is not used.
 */
#define RBN_HEIGHTCHANGE RBN_FIRST
#if (_WIN32_IE >= 0x0300)
/**
 * This notification message is sent by a virtual list view control when
 * the contents of its display area have changed. For example, a list view
 * control sends this notification when the user scrolls the control
 * display. This message is sent in the form of a WM_NOTIFY message.
 *
 * Handling this message allows the application to update the item data
 * held in cache so that it is readily available when an LVN_GETDISPINFO
 * notification message is sent.
 *
 * Note that this message is not always an exact representation of the
 * items that will be requested by LVN_GETDISPINFO. Therefore, if the
 * requested item is not cached while handling LVN_GETDISPINFO, the
 * application must be prepared to supply the requested data from a source
 * outside the cache.
 *
 * @param pCachehint Pointer to an NMLVCACHEHINT structure that contains
 *        data about the range of items to be cached.
 * @return The application receiving this notification must return zero.
 */
#define LVN_ODCACHEHINT (LVN_FIRST-13)
#define LVN_ODFINDITEMA (LVN_FIRST-52)
#define LVN_ODFINDITEMW (LVN_FIRST-79)
/**
 * This notification message is sent by a list view control when the user
 * activates an item. It is sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmlv Long pointer to an NMLISTVIEW structure that contains
 *        notification data. The iItem, iSubItem and ptAction members
 *        contain data about the activated item. If the item was activated
 *        from the keyboard, the ptAction member will contain -1 in its x
 *        and y members.
 * @return The application receiving this notification must return zero.
 */
#define LVN_ITEMACTIVATE (LVN_FIRST-14)
/**
 * This notification message is sent by a list view control when the state
 * of an item or range of items has changed. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * @param lpStateChange Long pointer to an NMLVODSTATECHANGE structure that
 *        contains data about the item or items that have changed
 * @return The application receiving this notification must return zero.
 */
#define LVN_ODSTATECHANGED (LVN_FIRST-15)
#ifdef UNICODE
/**
 * This notification message is sent by a virtual list view control when it
 * needs the owner to find a particular callback item. For example, the
 * control will send this notification when the it receives shortcut
 * keyboard input, or when it receives an LVM_FINDITEM message.
 *
 * Search data is sent in the form of an LVFINDINFO structure, which is a
 * member of the NMLVFINDITEM structure.
 *
 * @param pFindInfo Pointer to an NMLVFINDITEM structure that includes data
 *        used for the search.
 * @return Return the index of the item found, or -1 if no item is found
 */
#define LVN_ODFINDITEM LVN_ODFINDITEMW
#else
#define LVN_ODFINDITEM LVN_ODFINDITEMA
#endif
#endif /* _WIN32_IE */
#if (_WIN32_IE >= 0x0400)
#define SB_SETICON 1039
#define SB_SETTIPTEXTA	1040
#define SB_SETTIPTEXTW	1041
#define SB_GETTIPTEXTA	1042
#define SB_GETTIPTEXTW	1043
#define SB_GETICON	1044
#define SB_SETUNICODEFORMAT	0x2005
#define SB_GETUNICODEFORMAT	0x2006
#define PGF_INVISIBLE 0
#define PGF_NORMAL 1
#define PGF_GRAYED 2
#define PGF_DEPRESSED 4
#define PGF_HOT 8
#define PGB_TOPORLEFT 0
#define PGB_BOTTOMORRIGHT 1
#define PGF_SCROLLUP 1
#define PGF_SCROLLDOWN 2
#define PGF_SCROLLLEFT 4
#define PGF_SCROLLRIGHT 8
#define PGK_SHIFT 1
#define PGK_CONTROL 2
#define PGK_MENU 4
#define PGF_CALCWIDTH 1
#define PGF_CALCHEIGHT 2
#define PGM_FIRST 0x1400
#define PGM_SETCHILD (PGM_FIRST+1)
#define PGM_RECALCSIZE (PGM_FIRST+2)
#define PGM_FORWARDMOUSE (PGM_FIRST+3)
#define PGM_SETBKCOLOR (PGM_FIRST+4)
#define PGM_GETBKCOLOR (PGM_FIRST+5)
#define PGM_SETBORDER (PGM_FIRST+6)
#define PGM_GETBORDER (PGM_FIRST+7)
#define PGM_SETPOS (PGM_FIRST+8)
#define PGM_GETPOS (PGM_FIRST+9)
#define PGM_SETBUTTONSIZE (PGM_FIRST+10)
#define PGM_GETBUTTONSIZE (PGM_FIRST+11)
#define PGM_GETBUTTONSTATE (PGM_FIRST+12)
#define PGM_GETDROPTARGET CCM_GETDROPTARGET
#define RBS_REGISTERDROP 4096
#define RBS_AUTOSIZE 8192
#define RBS_VERTICALGRIPPER 16384
#define RBS_DBLCLKTOGGLE  32768
#define RBBIM_IDEALSIZE 512
#define RBBIM_LPARAM 1024
#define RBBIM_HEADERSIZE 2048
/**
 * This message determines which portion of a rebar band is at a specified
 * point on the screen, if a rebar band exists at that point.
 *
 * @param lprbht Long pointer to an RBHITTESTINFO structure. Before sending
 *        the message, the pt member of this structure must be initialized
 *        to the point that is hit tested, in client coordinates.
 * @return Returns the zero-based index of the band at the specified point,
 *        or -1 if no rebar band was at the point.
 */
#define RB_HITTEST (WM_USER+8)
/**
 * This message retrieves the bounding rectangle for a specified band in a
 * rebar control.
 *
 * @param iBand Zero-based index of a band in the rebar control.
 * @param lprc Long pointer to a RECT structure that receives the bounds of
 *        the rebar band.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_GETRECT (WM_USER+9)
/**
 * This message converts a band identifier to a band index in a rebar
 * control.
 *
 * @param uBandID Application-defined identifier of the band in question.
 *        This is the value that is passed in the wID member of the
 *        REBARBANDINFO structure when the band was inserted.
 * @return Returns the zero-based band index if successful, or -1
 *        otherwise. If duplicate band IDs exist, the first one is
 *        returned.
 */
#define RB_IDTOINDEX (WM_USER+16)
#define RB_GETTOOLTIPS (WM_USER+17)
#define RB_SETTOOLTIPS (WM_USER+18)
/**
 * This message sets a rebar control's default background color.
 *
 * The rebar control's default background color is used to draw the
 * background in a rebar control and all bands that are added after this
 * message has been sent. The default background color for a particular
 * band can be overridden by setting the RBBIM_COLORS flag in fMask and
 * setting clrBack in the REBARBANDINFO structure when a band is added or
 * modified.
 *
 * @param clrBk COLORREF value that represents the new default background
 *        color.
 * @return Returns a COLORREF value that represents the previous default
 *        background color.
 */
#define RB_SETBKCOLOR (WM_USER+19)
/**
 * This message retrieves a rebar control's default background color.
 *
 * @return Returns a COLORREF value that represent the current default
 *        background color.
 */
#define RB_GETBKCOLOR (WM_USER+20)
/**
 * This message sets a rebar control's default text color.
 *
 * The rebar control's default text color is used to draw the text in a
 * rebar control and all bands that are added after this message has been
 * sent. The default text color for a particular band can be overridden by
 * setting the RBBIM_COLORS flag in fMask and setting clrFore in the
 * REBARBANDINFO structure when a band is added or modified.
 *
 * @param clrText COLORREF value that represents the new default text
 *        color.
 * @return Returns a COLORREF value that represents the previous default
 *        text color.
 */
#define RB_SETTEXTCOLOR (WM_USER+21)
/**
 * This message retrieves a rebar control's default text color.
 *
 * @return Returns a COLORREF value that represent the current default text
 *        color.
 */
#define RB_GETTEXTCOLOR (WM_USER+22)
/**
 * This message tries to fit a rebar control to a specified rectangle.
 *
 * The rebar bands will be wrapped as necessary to fit the rectangle. Bands
 * that have the RBBS_VARIABLEHEIGHT style will be resized as evenly as
 * possible to fit the rectangle.
 *
 * @param prc Pointer to a RECT structure that specifies the rectangle that
 *        the rebar control should be sized to.
 * @return Returns nonzero if a layout change occurred, or zero otherwise.
 */
#define RB_SIZETORECT (WM_USER+23)
#define RB_BEGINDRAG (WM_USER+24)
#define RB_ENDDRAG (WM_USER+25)
#define RB_DRAGMOVE (WM_USER+26)
/**
 * This message retrieves the height the rebar control.
 *
 * @return Returns a UINT value that represents the height, in pixels, of
 *        the control.
 */
#define RB_GETBARHEIGHT (WM_USER+27)
#define RB_GETBANDINFOW (WM_USER+28)
#define RB_GETBANDINFOA (WM_USER+29)
/**
 * This message resizes a band in a rebar control to its smallest size.
 *
 * @param uBand Zero-based index of the band to be minimized.
 * @return The return value is not used.
 */
#define RB_MINIMIZEBAND (WM_USER+30)
/**
 * This message resizes a band in a rebar control to its ideal or largest
 * size.
 *
 * @param uBand Zero-based index of the band to be maximized.
 * @param fIdeal Boolean that specifies whether the ideal width of the band
 *        should be used when the band is maximized. If this value is
 *        nonzero, the ideal width is used. If this value is zero, the band
 *        is made as large as possible.
 * @return The return value is not used.
 */
#define RB_MAXIMIZEBAND (WM_USER+31)
#define RB_GETDROPTARGET CCM_GETDROPTARGET
/**
 * This message retrieves the borders of a band. The result of this message
 * can be used to calculate the usable area in a band.
 *
 * @param uBand Zero-based index of the band for which the borders will be
 *        retrieved.
 * @param lprc Long pointer to a RECT structure that receives the band
 *        borders. If the rebar control has the RBS_BANDBORDERS style, each
 *        member of this structure will receive the number of pixels on the
 *        corresponding side of the band that are used by the band. If the
 *        rebar control does not have the RBS_BANDBORDERS style, only the
 *        left member of this structure receives valid information.
 * @return The return value is not used.
 */
#define RB_GETBANDBORDERS (WM_USER+34)
/**
 * This message shows or hides a specified band in a rebar control.
 *
 * @param iBand Zero-based index of a band in the rebar control.
 * @param fShow Boolean that indicates if the band should be shown or
 *        hidden. If this value is nonzero, the band is shown. Otherwise,
 *        the band is hidden.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_SHOWBAND (WM_USER+35)
#define RB_SETPALETTE (WM_USER+37)
#define RB_GETPALETTE (WM_USER+38)
#define RB_MOVEBAND (WM_USER+39)
#define RB_SETUNICODEFORMAT     CCM_SETUNICODEFORMAT
#define RB_GETUNICODEFORMAT     CCM_GETUNICODEFORMAT
#define RBN_GETOBJECT (RBN_FIRST-1)
/**
 * This notification message is sent by a rebar control when you change the
 * layout of the control's bands. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param lpnmhdr Long pointer to an NMHDR structure that contains
 *        additional information about this notification message.
 * @return The return value for this notification is not used.
 */
#define RBN_LAYOUTCHANGED (RBN_FIRST-2)
/**
 * This message is sent to the parent by a rebar control created with the
 * RBS_AUTOSIZE style when the rebar automatically resizes itself. It is
 * sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmas Long pointer to a NMRBAUTOSIZE structure that contains
 *        information about the resize operation.
 * @return The return value for this notification is not used.
 */
#define RBN_AUTOSIZE (RBN_FIRST-3)
/**
 * This message is sent by a rebar control when the user begins dragging a
 * band. It is sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmrb Long pointer to a NMREBAR structure that contains
 *        information about the notification.
 * @return Return zero to allow the rebar to continue the drag operation or
 *        nonzero to abort the drag operation.
 */
#define RBN_BEGINDRAG (RBN_FIRST-4)
/**
 * This message is sent by a rebar control when the user stops dragging a
 * band. It is sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmrb Long pointer to a NMREBAR structure that contains
 *        information about the notification.
 * @return The return value for this notification is not used.
 */
#define RBN_ENDDRAG (RBN_FIRST-5)
#define RBN_DELETINGBAND (RBN_FIRST-6)
#define RBN_DELETEDBAND (RBN_FIRST-7)
#define RBN_CHILDSIZE (RBN_FIRST-8)
#define RBNM_ID 1
#define RBNM_STYLE 2
#define RBNM_LPARAM 4
#define RBHT_NOWHERE 1
#define RBHT_CAPTION 2
#define RBHT_CLIENT 3
#define RBHT_GRABBER 4
#ifdef UNICODE
#define SB_SETTIPTEXT	SB_SETTIPTEXTW
#define SB_GETTIPTEXT	SB_GETTIPTEXTW
/**
 * This message retrieves information about a specified band in a rebar
 * control.
 *
 * @param uBand Zero-based index of the band for which the information is
 *        retrieved.
 * @param lprbbi Long pointer to a REBARBANDINFO structure that receives
 *        the requested band information. Set the cbSize member of this
 *        structure to sizeof(REBARBANDINFO) and set the fMask parameter to
 *        the items you want to retrieve before sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_GETBANDINFO	RB_GETBANDINFOW
#else
#define SB_SETTIPTEXT	SB_SETTIPTEXTA
#define SB_GETTIPTEXT	SB_GETTIPTEXTA
#define RB_GETBANDINFO	RB_GETBANDINFOA
#endif
#else
#ifdef _WIN32_WCE
#define RB_GETBANDINFO (WM_USER+28)
#else
#define RB_GETBANDINFO (WM_USER+5)
#endif
#endif /* _WIN32_IE >= 0x0400 */
#define CBEM_INSERTITEMA	(WM_USER + 1)
#define CBEM_SETIMAGELIST	(WM_USER + 2)
#define CBEM_GETIMAGELIST	(WM_USER + 3)
#define CBEM_GETITEMA	(WM_USER + 4)
#define CBEM_SETITEMA	(WM_USER + 5)
#define CBEM_DELETEITEM	CB_DELETESTRING
#define CBEM_GETCOMBOCONTROL	(WM_USER + 6)
#define CBEM_GETEDITCONTROL	(WM_USER + 7)
#define CBEM_SETEXSTYLE	(WM_USER + 8)
#define CBEM_GETEXSTYLE	(WM_USER + 9)
#if (_WIN32_IE >= 0x0400)
#define CBEM_SETEXTENDEDSTYLE	(WM_USER + 14)
#define CBEM_GETEXTENDEDSTYLE	(WM_USER + 9)
#define CBEM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#define CBEM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#endif /* _WIN32_IE >= 0x0400 */
#define CBEM_HASEDITCHANGED	(WM_USER + 10)
#define CBEM_INSERTITEMW	(WM_USER + 11)
#define CBEM_SETITEMW	(WM_USER + 12)
#define CBEM_GETITEMW	(WM_USER + 13)
#define DA_LAST	0x7fffffff
#define DPA_APPEND	0x7fffffff
#define DPA_ERR	-1
#define DSA_APPEND	0x7fffffff
#define DSA_ERR	-1
#define DPAS_SORTED	1
#define DPAS_INSERTBEFORE	2
#define DPAS_INSERTAFTER	4
#if (_WIN32_IE >= 0x400)
#define WSB_PROP_CYVSCROLL	1
#define WSB_PROP_CXHSCROLL	2
#define WSB_PROP_CYHSCROLL	4
#define WSB_PROP_CXVSCROLL	8
#define WSB_PROP_CXHTHUMB	16
#define WSB_PROP_CYVTHUMB	32
#define WSB_PROP_VBKGCOLOR	64
#define WSB_PROP_HBKGCOLOR	128
#define WSB_PROP_VSTYLE	256
#define WSB_PROP_HSTYLE	512
#define WSB_PROP_WINSTYLE	1024
#define WSB_PROP_PALETTE	2048
#define WSB_PROP_MASK	0xfff
#define FSB_FLAT_MODE	2
#define FSB_ENCARTA_MODE	1
#define FSB_REGULAR_MODE	0
#endif /* _WIN32_IE >= 0x400 */
#if (_WIN32_WINNT >= 0x0501)
#define LIF_ITEMINDEX	0x00000001
#define LIF_STATE	0x00000002
#define LIF_ITEMID	0x00000004
#define LIF_URL	0x00000008
#define LIS_FOCUSED	0x00000001
#define LIS_ENABLED	0x00000002
#define LIS_VISITED	0x00000004
#define LM_HITTEST	(WM_USER + 768)
#define LM_GETIDEALHEIGHT	(WM_USER + 769)
#define LM_SETITEM	(WM_USER + 770)
#define LM_GETITEM	(WM_USER + 771)
#define MAX_LINKID_TEXT	48
#define L_MAX_URL_LENGTH	2084
#endif

#ifndef RC_INVOKED
typedef struct tagCOMBOBOXEXITEMA{
	UINT mask;
	int iItem;
	LPSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int iOverlay;
	int iIndent;
	LPARAM lParam;
} COMBOBOXEXITEMA, *PCOMBOBOXEXITEMA;
typedef COMBOBOXEXITEMA CONST *PCCOMBOEXITEMA;
typedef struct tagCOMBOBOXEXITEMW{
	UINT mask;
	int iItem;
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int iOverlay;
	int iIndent;
	LPARAM lParam;
} COMBOBOXEXITEMW, *PCOMBOBOXEXITEMW;
typedef COMBOBOXEXITEMW CONST *PCCOMBOEXITEMW;
#if (_WIN32_IE >= 0x0400)
typedef struct {
	NMHDR hdr;
	COMBOBOXEXITEMA ceItem;
} NMCOMBOBOXEXA, *PNMCOMBOBOXEXA;
typedef struct {
	NMHDR hdr;
	COMBOBOXEXITEMW ceItem;
} NMCOMBOBOXEXW, *PNMCOMBOBOXEXW;
typedef struct {
	NMHDR   hdr;
	int iItemid;
	WCHAR   szText[CBEMAXSTRLEN];
}NMCBEDRAGBEGINW, *LPNMCBEDRAGBEGINW, *PNMCBEDRAGBEGINW;
typedef struct {
	NMHDR   hdr;
	int iItemid;
	char    szText[CBEMAXSTRLEN];
}NMCBEDRAGBEGINA, *LPNMCBEDRAGBEGINA, *PNMCBEDRAGBEGINA;
typedef struct tagNMIPADDRESS{
	NMHDR hdr;
	int iField;
	int iValue;
} NMIPADDRESS, *LPNMIPADDRESS;
/**
 * This structure that contains information used in processing the
 * LVN_KEYDOWN notification message.
 */
typedef struct tagLVKEYDOWN {
	/**
	 * NMHDR structure that contains additional information about
	 * the notification message.
	 */
	NMHDR hdr;
	/**
	 * Virtual-key code.
	 */
	WORD wVKey;
	/**
	 * Set to zero.
	 */
	UINT flags;
} NMLVKEYDOWN, *LPNMLVKEYDOWN;
typedef struct {
	NMHDR hdr;
	DWORD dwFlag;
	int iWidth;
	int iHeight;
} NMPGCALCSIZE, *LPNMPGCALCSIZE;
typedef struct {
	NMHDR hdr;
	BOOL fwKeys;
	RECT rcParent;
	int iDir;
	int iXpos;
	int iYpos;
	int iScroll;
} NMPGSCROLL, *LPNMPGSCROLL;
/**
 * This structure carries information required to process the MCN_SELCHANGE
 * notification message.
 */
typedef struct tagNMSELCHANGE {
	/**
	 * NMHDR structure that contains information about this
	 * notification message.
	 */
	NMHDR nmhdr;
	/**
	 * SYSTEMTIME structure that contains the date for the
	 * first day in the user's selection range.
	 */
	SYSTEMTIME stSelStart;
	/**
	 * SYSTEMTIME structure that contains the date for the
	 * last day in the user's selection range.
	 */
	SYSTEMTIME stSelEnd;
} NMSELCHANGE, *LPNMSELCHANGE;
typedef struct tagNMTBHOTITEM {
	NMHDR hdr;
	int idOld;
	int idNew;
	DWORD dwFlags;
} NMTBHOTITEM, *LPNMTBHOTITEM;
typedef struct {
	NMHDR hdr;
	DWORD dwMask;
	int idCommand;
	DWORD_PTR lParam;
	int iImage;
	LPSTR pszText;
	int cchText;
} NMTBDISPINFOA, *LPNMTBDISPINFOA;
typedef struct {
	NMHDR hdr;
	DWORD dwMask;
	int idCommand;
	DWORD_PTR lParam;
	int iImage;
	LPWSTR pszText;
	int cchText;
} NMTBDISPINFOW, *LPNMTBDISPINFOW;
typedef struct tagNMTBGETINFOTIPA
{
	NMHDR hdr;
	LPSTR pszText;
	int cchTextMax;
	int iItem;
	LPARAM lParam;
} NMTBGETINFOTIPA, *LPNMTBGETINFOTIPA;
typedef struct tagNMTBGETINFOTIPW
{
	NMHDR hdr;
	LPWSTR pszText;
	int cchTextMax;
	int iItem;
	LPARAM lParam;
} NMTBGETINFOTIPW, *LPNMTBGETINFOTIPW;
/**
 * This structure contains information used with mouse notification
 * messages.
 */
typedef struct tagNMMOUSE {
	/**
	 * Handle to a NMHDR structure that contains additional
	 * information about this notification.
	 */
	NMHDR hdr;
	/**
	 * Specifies the control-specific item identifier.
	 */
	DWORD_PTR dwItemSpec;
	/**
	 * Specifies control-specific item data.
	 */
	DWORD_PTR dwItemData;
#ifdef _WIN32_WCE
	/**
	 * POINT structure that contains the screen coordinates of the
	 * mouse when the click occurred.
	 */
	POINT pt;
} NMMOUSE, *LPNMMOUSE;
#else
	POINT pt;
	LPARAM dwHitInfo;
} NMMOUSE, *LPNMMOUSE;
#endif
#endif /*_WIN32_IE >= 0x0400 */
#if (_WIN32_IE >= 0x0401)
typedef struct tagNMTOOLTIPSCREATED
{
	NMHDR hdr;
	HWND hwndToolTips;
} NMTOOLTIPSCREATED, *LPNMTOOLTIPSCREATED;
#endif
/**
 * This structure contains information about a change that has taken place
 * in a date and time picker (DTP) control. This structure is used with the
 * DTN_DATETIMECHANGE notification message.
 */
typedef struct tagNMDATETIMECHANGE
{
	/**
	 * NMHDR structure that contains information about the
	 * notification message.
	 */
	NMHDR nmhdr;
	/**
	 * Specifies if the control was set to "no date" status
	 * (for DTS_SHOWNONE only). Also specifies whether the contents of
	 * the st member are valid and contain current time information. It
	 * is one of the following values: Value Description GDT_NONE The
	 * control is set to "no date" status. The "no date" status applies
	 * only to controls that are set to the DTS_SHOWNONE style.
	 * GDT_VALID The control is not set to the "no date" status. The st
	 * member contains the current date and time.
	 */
	DWORD dwFlags;
	/**
	 * SYSTEMTIME structure that contains information about the
	 * current system date and time.
	 */
	SYSTEMTIME st;
} NMDATETIMECHANGE, *LPNMDATETIMECHANGE;
typedef struct {
	NMHDR hdr;
	BOOL fChanged;
	int iNewSelection;
	WCHAR szText[CBEMAXSTRLEN];
	int iWhy;
} NMCBEENDEDITW, *LPNMCBEENDEDITW, *PNMCBEENDEDITW;
typedef struct {
	NMHDR hdr;
	BOOL fChanged;
	int iNewSelection;
	char szText[CBEMAXSTRLEN];
	int iWhy;
} NMCBEENDEDITA, *LPNMCBEENDEDITA,*PNMCBEENDEDITA;
typedef struct _COLORMAP {
	COLORREF from;
	COLORREF to;
} COLORMAP,*LPCOLORMAP;
typedef struct {
	UINT uNotification;
	HWND hWnd;
	POINT ptCursor;
} DRAGLISTINFO,*LPDRAGLISTINFO;
/**
 * This structure contains information about a button in a toolbar.
 */
typedef struct _TBBUTTON {
	/**
	 * Zero-based index of the button image.
	 */
	int iBitmap;
	/**
	 * Command identifier associated with the button. This
	 * identifier is used in a WM_COMMAND message when the button is
	 * chosen.
	 */
	int idCommand;
	/**
	 * Button state flags. It can be a combination of the
	 * values listed in Toolbar Button States.
	 */
	BYTE fsState;
	/**
	 * Button style. It can be a combination of the button
	 * style values listed in Toolbar Control Button Styles.
	 */
	BYTE fsStyle;
	BYTE bReserved[2];
	/**
	 * Specifies an application-defined value.
	 */
	DWORD dwData;
	/**
	 * Zero-based index of the button string.
	 */
	int iString;
} TBBUTTON,*PTBBUTTON,*LPTBBUTTON;
typedef const TBBUTTON *LPCTBBUTTON;
#if _WIN32_IE >= 0x400
typedef struct {
	UINT cbSize;
	DWORD dwMask;
	int idCommand;
	int iImage;
	BYTE fsState;
	BYTE fsStyle;
	WORD cx;
	DWORD lParam;
	LPSTR pszText;
	int cchText;
} TBBUTTONINFOA, *LPTBBUTTONINFOA;
typedef struct {
	UINT cbSize;
	DWORD dwMask;
	int idCommand;
	int iImage;
	BYTE fsState;
	BYTE fsStyle;
	WORD cx;
	DWORD lParam;
	LPWSTR pszText;
	int cchText;
} TBBUTTONINFOW, *LPTBBUTTONINFOW;
typedef struct {
	int iButton;
	DWORD dwFlags;
} TBINSERTMARK, *LPTBINSERTMARK;
typedef struct tagLVBKIMAGEA {
	ULONG ulFlags;              
	HBITMAP hbm;
	LPSTR pszImage;
	UINT cchImageMax;
	int xOffsetPercent;
	int yOffsetPercent;
} LVBKIMAGEA, *LPLVBKIMAGEA;
typedef struct tagLVBKIMAGEW {
	ULONG ulFlags;             
	HBITMAP hbm;
	LPWSTR pszImage;
	UINT cchImageMax;
	int xOffsetPercent;
	int yOffsetPercent;
} LVBKIMAGEW, *LPLVBKIMAGEW;
#endif /* _WIN32_IE >= 0x400 */
/**
 * This structure contains information used to process notification
 * messages from a toolbar, and is superseded by the NMTOOLBAR structure.
 */
typedef struct {
	/**
	 * NMHDR structure that contains additional information about
	 * the notification message.
	 */
	NMHDR hdr;
	/**
	 * Command identifier of the button associated with the
	 * notification.
	 */
	int iItem;
	/**
	 * TBBUTTON structure that contains information about the
	 * toolbar button associated with the notification.
	 */
	TBBUTTON tbButton;
	/**
	 * Count of characters in the button text.
	 */
	int cchText;
	/**
	 * Pointer to a character buffer that contains the button
	 * text.
	 */
	LPTSTR pszText;
} TBNOTIFY,*LPTBNOTIFY;
typedef struct {
	HKEY hkr;
	LPCTSTR pszSubKey;
	LPCTSTR pszValueName;
} TBSAVEPARAMS;
/**
 * This structure contains information about an image in an image list.
 * This structure is used with the ImageList_GetImageInfo function.
 */
typedef struct _IMAGEINFO {
	/**
	 * Handle to the bitmap that contains the images.
	 */
	HBITMAP hbmImage;
	/**
	 * Handle to a monochrome bitmap that contains the masks
	 * for the images. If the image list does not contain a mask, this
	 * member is NULL.
	 */
	HBITMAP hbmMask;
	/**
	 * Not used; set to zero.
	 */
	int Unused1;
	/**
	 * Not used; set to zero.
	 */
	int Unused2;
	/**
	 * Bounding rectangle of the specified image within the
	 * bitmap specified by hbmImage.
	 */
	RECT rcImage;
} IMAGEINFO, *LPIMAGEINFO;
typedef struct _IMAGELIST *HIMAGELIST;
typedef struct _HDITEMA {
	UINT mask;
	int cxy;
	LPSTR pszText;
	HBITMAP hbm;
	int cchTextMax;
	int fmt;
	LPARAM lParam;
#if (_WIN32_IE >= 0x0300)
	int iImage;
	int iOrder;
#endif
#if (_WIN32_IE >= 0x0500)
	UINT type;
	LPVOID pvFilter;
#endif
} HDITEMA, * LPHDITEMA;
typedef struct _HDITEMW {
	UINT mask;
	int cxy;
	LPWSTR pszText;
	HBITMAP hbm;
	int cchTextMax;
	int fmt;
	LPARAM lParam;
#if (_WIN32_IE >= 0x0300)
	int iImage;
	int iOrder;
#endif
#if (_WIN32_IE >= 0x0500)
	UINT type;
	LPVOID pvFilter;
#endif
} HDITEMW, * LPHDITEMW;
/* for backward compatibility */
#define HD_ITEMA HDITEMA
#define HD_ITEMW HDITEMW
/**
 * This structure contains information about an item in a header control.
 * This structure is superseded by the HDITEM structure.
 *
 * The header control can display text, an image, and a bitmap for an item
 * all at the same time. The alignment flags determine the order in which
 * they appear. With HDF_LEFT or HDF_CENTER, the order is image, text, and
 * then bitmap. With HDF_RIGHT the order is bitmap, image, and then text.
 */
#define HD_ITEM HDITEM
/**
 * This structure contains information used to set the size and position of
 * a header control. This structure is used with the HDM_LAYOUT message.
 */
typedef struct _HD_LAYOUT {
	/**
	 * Pointer to a RECT structure that contains the coordinates of
	 * a rectangle that the header control will occupy.
	 */
	RECT *prc;
	/**
	 * Pointer to a WINDOWPOS structure that receives information
	 * about the appropriate size and position of the header control.
	 */
	WINDOWPOS *pwpos;
} HDLAYOUT, *LPHDLAYOUT;
/**
 * This structure contains information used to set the size and position of
 * a header control, and is superseded by the HDLAYOUT structure.
 */
#define HD_LAYOUT HDLAYOUT /*  backward compatibility */
/**
 * This structure contains information about a hit test, and is superseded
 * by the HD_HITTESTINFO structure.
 */
typedef struct _HD_HITTESTINFO {
	/**
	 * POINT structure that contains the point to be hit test, in
	 * client coordinates.
	 */
	POINT pt;
	/**
	 * Receives information about the results of a hit test. It
	 * can be one or more of the following values: Value Description
	 * HHT_NOWHERE The point is inside the header control's bounding
	 * rectangle but is not over a header item. HHT_ONDIVIDER The point
	 * is on the divider between two header items. HHT_ONDIVOPEN The
	 * point is on the divider of an item that has a width of zero.
	 * Dragging the divider reveals the item instead of resizing the
	 * item to the left of the divider. HHT_ONHEADER The point is inside
	 * the header control's bounding rectangle. HHT_TOLEFT The point is
	 * to the left of the header control's bounding rectangle.
	 * HHT_TORIGHT The point is to the right of the header control's
	 * bounding rectangle. Two of these values can be combined, such as
	 * when the position is above and to the left of the client area.
	 */
	UINT flags;
	/**
	 * If the hit test is successful, this member contains the
	 * index of the item at the hit test point.
	 */
	int iItem;
} HD_HITTESTINFO, *LPHDHITTESTINFO;
typedef struct _HD_NOTIFYA {
	NMHDR hdr;
	int iItem;
	int iButton;
	HD_ITEMA *pitem;
} HD_NOTIFYA;
typedef struct _HD_NOTIFYW {
	NMHDR hdr;
	int iItem;
	int iButton;
	HD_ITEMW *pitem;
} HD_NOTIFYW;
/* FIXME: NMHEADER structure (base for all events of the comctl controls)
   is the same as HD_NOTIFY depending on the value of _WIN32_IE macro.
   I'm defining both for now. */
typedef struct _NMHEADERA {
    NMHDR   hdr;
    int     iItem;
    int     iButton;
    HD_ITEMA* pitem;
}  NMHEADERA, *LPNMHEADERA;

typedef struct _NMHEADERW {
    NMHDR   hdr;
    int     iItem;
    int     iButton;
    HD_ITEMW* pitem;
}  NMHEADERW, *LPNMHEADERW;
#ifdef UNICODE
/**
 * This structure contains information about header control notification
 * messages. This structure supersedes the HD_NOTIFY structure.
 */
#define NMHEADER NMHEADERW
#define LPNMHEADER LPNMHEADERW
#else
#define NMHEADER NMHEADERA
#define LPNMHEADER LPNMHEADERA
#endif
/* End FIXME. */
typedef struct tagNMHDDISPINFOA {
    NMHDR   hdr;
    int     iItem;
    UINT    mask;
    LPSTR   pszText;
    int     cchTextMax;
    int     iImage;
    LPARAM  lParam;
} NMHDDISPINFOA, *LPNMHDDISPINFOA;
typedef struct tagNMHDDISPINFOW {
    NMHDR   hdr;
    int     iItem;
    UINT    mask;
    LPWSTR  pszText;
    int     cchTextMax;
    int     iImage;
    LPARAM  lParam;
} NMHDDISPINFOW, *LPNMHDDISPINFOW;
/**
 * This structure contains information specific to an NM_CUSTOMDRAW
 * notification message.
 */
typedef struct tagNMCUSTOMDRAWINFO {
    /**
     * Handle to a NMHDR structure that contains information about
     * this notification message.
     */
    NMHDR    hdr;
    /**
     * Specifies the current drawing stage. It is one of
     * the following values. Global Drawstage values: Value Description
     * CDDS_POSTERASE After the erasing cycle is complete.
     * CDDS_POSTPAINT After the painting cycle is complete.
     * CDDS_PREERASE Before the erasing cycle begins. CDDS_PREPAINT
     * Before the painting cycle begins. Item-Specific Drawstage values:
     * Value Description CDDS_ITEM Indicates that the dwItemSpec,
     * uItemState, and lItemParam members are valid. CDDS_ITEMPOSTERASE
     * After an item has been erased CDDS_ITEMPOSTPAINT After an item
     * has been drawn CDDS_ITEMPREERASE Before an item is erased
     * CDDS_ITEMPREPAINT Before an item is drawn
     */
    DWORD    dwDrawStage;
    /**
     * Handle to the control's device context. Use this HDC to
     * perform any GDI functions.
     */
    HDC      hdc;
    /**
     * RECT structure that describes the bounding rectangle of the
     * area being drawn.
     */
    RECT     rc;
    /**
     * Specifies the item number. This value is control
     * specific, using the item-referencing convention for that control.
     * Additionally, trackbar controls use the following values to
     * identify portions of control: Value Description TBCD_CHANNEL
     * Identifies the channel that the trackbar control's thumb marker
     * slides along. TBCD_THUMB Identifies the trackbar control's thumb
     * marker. This is the portion of the control that the user moves.
     * TBCD_TICS Identifies the increment tic marks that appear along
     * the edge of the trackbar control.
     */
    DWORD    dwItemSpec;
    /**
     * Specifies the current item state. It can be a
     * combination of the following values: Value Description
     * CDIS_CHECKED The item is checked. CDIS_DEFAULT The item is in its
     * default state. CDIS_DISABLED The item is disabled. CDIS_FOCUS The
     * item is in focus. CDIS_GRAYED The item is grayed. CDIS_HOT The
     * item is currently under the pointer ("hot"). CDIS_SELECTED The
     * item is selected.
     */
    UINT     uItemState;
#if !defined(_WIN32_WCE) || GRIMACE_CE >= 2
    /**
     * Application-defined item data.
     */
    LPARAM   lItemlParam;
#endif
} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;
/**
 * This structure contains information specific to an NM_CUSTOMDRAW
 * notification message sent by a list view control.
 */
typedef struct tagNMLVCUSTOMDRAW {
    /**
     * NMCUSTOMDRAW structure that contains general Custom Draw
     * information.
     */
    NMCUSTOMDRAW nmcd;
    /**
     * COLORREF value that represents the color that is used to
     * display text foreground in the list view control.
     */
    COLORREF     clrText;
    /**
     * COLORREF value that represents the color that is used
     * to display text background in the list view control.
     */
    COLORREF     clrTextBk;
#if _WIN32_IE >= 0x0400 || (defined(_WIN32_WCE) && GRIMACE_CE >= 2)
    int          iSubItem;
#endif
} NMLVCUSTOMDRAW, *LPNMLVCUSTOMDRAW;
#if (_WIN32_IE >= 0x0400)
typedef struct tagNMLVGETINFOTIPA
{
	NMHDR hdr;
	DWORD dwFlags;
	LPSTR pszText;
	int cchTextMax;
	int iItem;
	int iSubItem;
	LPARAM lParam;
} NMLVGETINFOTIPA, *LPNMLVGETINFOTIPA;
typedef struct tagNMLVGETINFOTIPW
{
	NMHDR hdr;
	DWORD dwFlags;
	LPWSTR pszText;
	int cchTextMax;
	int iItem;
	int iSubItem;
	LPARAM lParam;
} NMLVGETINFOTIPW, *LPNMLVGETINFOTIPW;
#endif /* _WIN32_IE >= 0x0400 */
/**
 * This structure contains information specific to an NM_CUSTOMDRAW
 * notification message sent by a tree view control.
 */
typedef struct tagNMTVCUSTOMDRAW {
    /**
     * NMCUSTOMDRAW structure that contains general Custom Draw
     * information.
     */
    NMCUSTOMDRAW nmcd;
    /**
     * COLORREF value that represents the color that is used to
     * display text foreground in the list view control.
     */
    COLORREF     clrText;
    /**
     * COLORREF value that represents the color that is used
     * to display text background in the list view control.
     */
    COLORREF     clrTextBk;
#if _WIN32_IE >= 0x0400 && !defined(_WIN32_WCE)
    int          iLevel;
#endif
} NMTVCUSTOMDRAW, *LPNMTVCUSTOMDRAW;
#if (_WIN32_IE >= 0x400)
typedef struct _NMTBCUSTOMDRAW {
	NMCUSTOMDRAW nmcd;
	HBRUSH hbrMonoDither;
	HBRUSH hbrLines;
	HPEN hpenLines;
	COLORREF clrText;
	COLORREF clrMark;
	COLORREF clrTextHighlight;
	COLORREF clrBtnFace;
	COLORREF clrBtnHighlight;
	COLORREF clrHighlightHotTrack;
	RECT rcText;
	int nStringBkMode;
	int nHLStringBkMode;
#if (_WIN32_WINNT >= 0x0501)
	int iListGap;
#endif
} NMTBCUSTOMDRAW, * LPNMTBCUSTOMDRAW;
typedef struct tagNMITEMACTIVATE {
	NMHDR hdr;
	int iItem;
	int iSubItem;
	UINT uNewState;
	UINT uOldState;
	UINT uChanged;
	POINT ptAction;
	LPARAM lParam;
	UINT uKeyFlags;
} NMITEMACTIVATE, *LPNMITEMACTIVATE;
#endif /* _WIN32_IE >= 0x0400 */
/**
 * This structure adds a bitmap that contains button images to a toolbar.
 *
 * The TBADDBITMAP structure is used with the TB_ADDBITMAP message.
 */
typedef struct tagTBADDBITMAP {
	/**
	 * Handle to the module instance with the executable file
	 * that contains a bitmap resource. You can add the system-defined
	 * button bitmaps to the list by specifying HINST_COMMCTRL as the
	 * hInst member and one of the following values as the nID member:
	 * Value Description IDB_STD_LARGE_COLOR Adds large, color standard
	 * bitmaps. IDB_STD_SMALL_COLOR Adds small, color standard bitmaps.
	 * IDB_VIEW_LARGE_COLOR Adds large, color view bitmaps.
	 * IDB_VIEW_SMALL_COLOR Adds small, color view bitmaps.
	 */
	HINSTANCE hInst;
	/**
	 * Resource identifier of the bitmap resource that contains the
	 * button images. If hInst is NULL, this parameter must be the
	 * handle to a bitmap that contains the button images. The Windows
	 * header files provide the following values to be used as indexes
	 * to the standard and view bitmaps: Value Description STD_COPY
	 * Specifies the copy image. STD_CUT Specifies the cut image.
	 * STD_DELETE Specifies the delete image. STD_FILENEW Specifies the
	 * new file image. STD_FILEOPEN Specifies the open file image.
	 * STD_FILESAVE Specifies the save file image. STD_FIND Specifies
	 * the find image. STD_HELP Specifies the help image. STD_PASTE
	 * Specifies the paste image. STD_PRINT Specifies the print image.
	 * STD_PRINTPRE Specifies the print preview image. STD_PROPERTIES
	 * Specifies the properties image. STD_REDOW Specifies the redo
	 * image. STD_REPLACE Specifies the replace image. STD_UNDO
	 * Specifies the undo image. VIEW_DETAILS Specifies the view details
	 * image. VIEW_LARGEICONS Specifies the view large icons image.
	 * VIEW_LIST Specifies the view list image. VIEW_SMALLICONS
	 * Specifies the view small icons image. VIEW_SORTDATE Specifies the
	 * sort by date image. VIEW_SORTNAME Specifies the sort by name
	 * image. VIEW_SORTSIZE Specifies the sort by size image.
	 * VIEW_SORTTYPE Specifies the sort by type image.
	 */
	UINT nID;
} TBADDBITMAP,*LPTBADDBITMAP;
typedef struct tagTBSAVEPARAMSA {
	HKEY hkr;
	LPCSTR pszSubKey;
	LPCSTR pszValueName;
} TBSAVEPARAMSA;
typedef struct tagTBSAVEPARAMSW {
	HKEY hkr;
	LPCWSTR pszSubKey;
	LPCWSTR pszValueName;
} TBSAVEPARAMSW;
/**
 * This structure is used with the TB_REPLACEBITMAP message to replace one
 * toolbar bitmap with another.
 */
typedef struct {
	/**
	 * Module instance handle of the bitmap resource being
	 * replaced.
	 */
	HINSTANCE hInstOld;
	/**
	 * Resource identifier of the bitmap being replaced.
	 */
	UINT nIDOld;
	/**
	 * Module instance handle that contains the new bitmap
	 * resource.
	 */
	HINSTANCE hInstNew;
	/**
	 * Resource identifier of the new bitmap.
	 */
	UINT nIDNew;
	/**
	 * Number of button images contained in the new bitmap.
	 */
	int nButtons;
} TBREPLACEBITMAP,*LPTBREPLACEBITMAP;
typedef struct tagNMTOOLBARA {
	NMHDR hdr;
	int iItem;
	TBBUTTON tbButton;
	int cchText;
	LPSTR pszText;
#if (_WIN32_IE >= 0x500)
	RECT    rcButton;
#endif
} NMTOOLBARA, *LPNMTOOLBARA;
#define TBNOTIFYA NMTOOLBARA
#define LPTBNOTIFYA LPNMTOOLBARA
typedef struct tagNMTOOLBARW {
	NMHDR hdr;
	int iItem;
	TBBUTTON tbButton;
	int cchText;
	LPWSTR pszText;
#if (_WIN32_IE >= 0x500)
	RECT    rcButton;
#endif
} NMTOOLBARW, *LPNMTOOLBARW;
#define TBNOTIFYW NMTOOLBARW
#define LPTBNOTIFYW LPNMTOOLBARW
typedef struct tagTOOLINFOA {
	UINT cbSize;
	UINT uFlags;
	HWND hwnd;
	UINT uId;
	RECT rect;
	HINSTANCE hinst;
	LPSTR lpszText;
#if (_WIN32_IE >= 0x0300)
	LPARAM lParam;
#endif
} TTTOOLINFOA,*LPTTTOOLINFOA,*PTOOLINFOA;
#define TOOLINFOA TTTOOLINFOA
#define LPTOOLINFOA LPTTTOOLINFOA
#define TTTOOLINFOA_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOA, lpszText)
#define TTTOOLINFOA_V2_SIZE CCSIZEOF_STRUCT(TTTOOLINFOA, lParam)
#define TTTOOLINFOA_V3_SIZE CCSIZEOF_STRUCT(TTTOOLINFOA, lpReserved)
typedef struct tagTOOLINFOW {
	UINT cbSize;
	UINT uFlags;
	HWND hwnd;
	UINT uId;
	RECT rect;
	HINSTANCE hinst;
	LPWSTR lpszText;
#if (_WIN32_IE >= 0x0300)
	LPARAM lParam;
#endif
} TTTOOLINFOW,*LPTTTOOLINFOW,*PTOOLINFOW;
#define TOOLINFOW TTTOOLINFOW
#define LPTOOLINFOW LPTTTOOLINFOW
#define TTTOOLINFOW_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOW, lpszText)
#define TTTOOLINFOW_V2_SIZE CCSIZEOF_STRUCT(TTTOOLINFOW, lParam)
#define TTTOOLINFOW_V3_SIZE CCSIZEOF_STRUCT(TTTOOLINFOW, lpReserved)
typedef struct _TT_HITTESTINFOA {
	HWND hwnd;
	POINT pt;
	TOOLINFOA ti;
} TTHITTESTINFOA,*LPTTHITTESTINFOA;
#define LPHITTESTINFOA    LPTTHITTESTINFOA
typedef struct _TT_HITTESTINFOW {
	HWND hwnd;
	POINT pt;
	TOOLINFOW ti;
} TTHITTESTINFOW,*LPTTHITTESTINFOW;
#define LPHITTESTINFOW    LPTTHITTESTINFOW
typedef struct tagNMTTDISPINFOA {
	NMHDR hdr;
	LPSTR lpszText;
	char szText[80];
	HINSTANCE hinst;
	UINT uFlags;
#if (_WIN32_IE >= 0x0300)
	LPARAM lParam;
#endif
} NMTTDISPINFOA, *LPNMTTDISPINFOA;
#define TOOLTIPTEXTA	NMTTDISPINFOA
#define LPTOOLTIPTEXTA	LPNMTTDISPINFOA
typedef struct tagNMTTDISPINFOW {
 	NMHDR hdr;
 	LPWSTR lpszText;
 	WCHAR szText[80];
 	HINSTANCE hinst;
 	UINT uFlags;
#if (_WIN32_IE >= 0x0300)
	LPARAM lParam;
#endif
} NMTTDISPINFOW, *LPNMTTDISPINFOW;
#define TOOLTIPTEXTW	NMTTDISPINFOW
#define LPTOOLTIPTEXTW	LPNMTTDISPINFOW
/**
 * This structure contains acceleration information for an up-down control.
 */
typedef struct _UDACCEL {
	/**
	 * Amount of elapsed time, in seconds, before the position
	 * change increment specified by nInc is used.
	 */
	UINT nSec;
	/**
	 * Position change increment to use after the time specified
	 * by nSec elapses.
	 */
	UINT nInc;
} UDACCEL,*LPUDACCEL;
/**
 * This structure contains information specific to up-down control
 * notification messages. It is identical to and replaces the NM_UPDOWN
 * structure.
 *
 * The address of this structure is specified as the lParam parameter of
 * the WM_NOTIFY message that is used to send the UDN_DELTAPOS notification
 * message.
 */
typedef struct _NM_UPDOWN {
	/**
	 * NMHDR structure that contains additional information about
	 * the notification message.
	 */
	NMHDR hdr;
	/**
	 * Signed integer value that represents the up-down control's
	 * current position.
	 */
	int iPos;
	/**
	 * Signed integer value that represents the proposed change
	 * in the up-down control's position.
	 */
	int iDelta;
} NMUPDOWN,*LPNMUPDOWN;
/* for backward compatibility */
/**
 * This structure contains information about an up-down control
 * notification message. This structure is identical to the NMUPDOWN
 * structure, but was renamed to follow current naming conventions.
 *
 * In Windows CE version 2.0, this structure has been renamed NMUPDOWN.
 */
#define NM_UPDOWN NMUPDOWN 
#define LPNM_UPDOWN LPNMUPDOWN 
typedef struct _LVITEMA {
	UINT mask;
	int iItem;
	int iSubItem;
	UINT state;
	UINT stateMask;
	LPSTR pszText;
	int cchTextMax;
	int iImage;
	LPARAM lParam;
#if (_WIN32_IE >= 0x0300)
	int iIndent;
#endif
#if (_WIN32_WINNT >= 0x0501)
	int iGroupId;
	UINT cColumns;
	PUINT puColumns;
#endif
} LVITEMA, FAR *LPLVITEMA;
#define _LV_ITEMA _LVITEMA
#define LV_ITEMA LVITEMA
typedef struct _LVITEMW {
	UINT mask;
	int iItem;
	int iSubItem;
	UINT state;
	UINT stateMask;
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
	LPARAM lParam;
#if (_WIN32_IE >= 0x0300)
	int iIndent;
#endif
#if (_WIN32_WINNT >= 0x0501)
	int iGroupId;
	UINT cColumns;
	PUINT puColumns;
#endif
} LVITEMW, FAR *LPLVITEMW;
#define _LV_ITEMW _LVITEMW
#define LV_ITEMW LVITEMW
typedef struct tagLVFINDINFOA {
	UINT flags;
	LPCSTR psz;
	LPARAM lParam;
	POINT pt;
	UINT vkDirection;
} LVFINDINFOA, FAR* LPFINDINFOA;
#define _LV_FINDINFOA tagLVFINDINFOA
#define LV_FINDINFOA LVFINDINFOA
typedef struct tagLVFINDINFOW {
	UINT flags;
	LPCWSTR psz;
	LPARAM lParam;
	POINT pt;
	UINT vkDirection;
} LVFINDINFOW, FAR* LPFINDINFOW;
#define _LV_FINDINFOW tagLVFINDINFOW
#define LV_FINDINFOW LVFINDINFOW
typedef struct tagNMLVFINDITEMA {
	NMHDR hdr;
	int iStart;
	LVFINDINFOA lvfi;
} NMLVFINDITEMA, *PNMLVFINDITEMA, FAR *LPNMLVFINDITEMA;
#define _NMLVFINDITEMA tagNMLVFINDITEMA
typedef struct tagNMLVFINDITEMW {
	NMHDR hdr;
	int iStart;
	LVFINDINFOW lvfi;
} NMLVFINDITEMW, *PNMLVFINDITEMW, FAR *LPNMLVFINDITEMW;
#define _NMLVFINDITEMW tagNMLVFINDITEMW
/**
 * This structure has been extended to accommodate subitem hit-testing. The
 * LVHITTESTINFO structure contains information about a hit test. It is
 * used in association with the LVM_HITTEST and LVM_SUBITEMHITTEST messages
 * and their related macros.
 *
 * This structure supersedes the LV_HITTESTINFO structure.
 */
typedef struct _LVHITTESTINFO {
	/**
	 * Position to hit test, in client coordinates.
	 */
	POINT pt;
	/**
	 * Receives information about the results of a hit test. It
	 * can be one or more of the following values. Value Description
	 * LVHT_ABOVE The position is above the control's client area.
	 * LVHT_BELOW The position is below the control's client area.
	 * LVHT_NOWHERE The position is inside the list view control's
	 * client window, but it is not over a list item. LVHT_ONITEMICON
	 * The position is over a list view item's icon. LVHT_ONITEMLABEL
	 * The position is over a list view item's text.
	 * LVHT_ONITEMSTATEICON The position is over the state image of a
	 * list view item. LVHT_TOLEFT The position is to the left of the
	 * list view control's client area. LVHT_TORIGHT The position is to
	 * the right of the list view control's client area. You can use
	 * LVHT_ABOVE, LVHT_BELOW, LVHT_TOLEFT, and LVHT_TORIGHT to
	 * determine whether to scroll the contents of a list view control.
	 * Two of these values may be combined. For example, if the position
	 * is above and to the left of the client area, you could use both
	 * LVHT_ABOVE and LVHT_TO LEFT. You can test for LVHT_ONITEM to
	 * determine whether a specified position is over a list view item.
	 * This value is a bitwise-OR operation on LVHT_ONITEMICON,
	 * LVHT_ONITEMLABEL, and LVHT_ONITEMSTATEICON.
	 */
	UINT flags;
	/**
	 * Receives the index of the matching item. Or if hit-testing
	 * a subitem, this value represents the subitem's parent item.
	 */
	int iItem;
#if (_WIN32_IE >= 0x0300)
	/**
	 * Receives the index of the matching subitem. When
	 * hit-testing an item, this member will be zero.
	 */
	int iSubItem;
#endif
} LVHITTESTINFO, FAR *LPLVHITTESTINFO;
#define _LV_HITTESTINFO _LVHITTESTINFO
/**
 * This structure contains information about a hit test, and is superseded
 * by the LVHITTESTINFO structure.
 */
#define LV_HITTESTINFO LVHITTESTINFO
typedef struct _LVCOLUMNA {
	UINT mask;
	int fmt;
	int cx;
	LPSTR pszText;
	int cchTextMax;
	int iSubItem;
#if (_WIN32_IE >= 0x0300)
	int iImage;
	int iOrder;
#endif
} LVCOLUMNA, FAR *LPLVCOLUMNA;
#define _LV_COLUMNA _LVCOLUMNA
#define LV_COLUMNA LVCOLUMNA
typedef struct _LVCOLUMNW {
	UINT mask;
	int fmt;
	int cx;
	LPWSTR pszText;
	int cchTextMax;
	int iSubItem;
#if (_WIN32_IE >= 0x0300) || (_WIN32_WCE >= 0x200)
	int iImage;
	int iOrder;
#endif
} LVCOLUMNW, FAR *LPLVCOLUMNW;
#define _LV_COLUMNW _LVCOLUMNW
#define LV_COLUMNW LVCOLUMNW
typedef int(CALLBACK *PFNLVCOMPARE)(LPARAM,LPARAM,LPARAM);
/**
 * This structure contains information about a list view notification
 * message. This structure is the same as the NM_LISTVIEW structure, but
 * has been renamed to fit standard naming conventions.
 */
typedef struct tagNMLISTVIEW {
	/**
	 * NMHDR structure that contains information about this
	 * notification message.
	 */
	NMHDR hdr;
	/**
	 * Identifier of the list view item, or ?1 if not used.
	 */
	int iItem;
	/**
	 * Identifier of the subitem, or zero if none.
	 */
	int iSubItem;
	/**
	 * Specifies the new item state. This member is zero for
	 * notification messages that do not use it.
	 */
	UINT uNewState;
	/**
	 * Specifies the old item state. This member is zero for
	 * notification messages that do not use it.
	 */
	UINT uOldState;
	/**
	 * Set of flags that indicate the item attributes that
	 * have changed. This member is zero for notification messages that
	 * do not use it. Otherwise, it can have the same values as the mask
	 * member of the LVITEM structure.
	 */
	UINT uChanged;
	/**
	 * Specifies a POINT structure that indicates the location
	 * at which the event occurred. This member is undefined for
	 * notification messages that do not use it.
	 */
	POINT ptAction;
	/**
	 * Specifies the item's application-defined 32-bit value.
	 * This member is undefined for notification messages that do not
	 * use it.
	 */
	LPARAM lParam;
} NMLISTVIEW, *LPNMLISTVIEW;
/* for backward compatibility */
#define _NM_LISTVIEW  tagNMLISTVIEW
/**
 * This structure contains information about a list view notification
 * message. This structure is identical to the NMLISTVIEW structure, but
 * was renamed to fit standard naming conventions.
 */
#define NM_LISTVIEW NMLISTVIEW
#define LPNM_LISTVIEW LPNMLISTVIEW
typedef struct tagNMLVDISPINFOA {
	NMHDR hdr;
	LV_ITEMA item;
} NMLVDISPINFOA, FAR *LPNMLVDISPINFOA;
#define _LV_DISPINFOA tagNMLVDISPINFOA
#define LV_DISPINFOA NMLVDISPINFOA
typedef struct tagNMLVDISPINFOW {
	NMHDR hdr;
	LV_ITEMW item;
} NMLVDISPINFOW, FAR *LPNMLVDISPINFOW;
#define _LV_DISPINFOW tagNMLVDISPINFOW
#define LV_DISPINFOW NMLVDISPINFOW
/**
 * This structure contains information about a keyboard event in a list
 * view control. This structure is identical to the NMLVKEYDOWN structure,
 * but was renamed to fit standard naming conventions.
 */
typedef struct _LV_KEYDOWN {
	/**
	 * NMHDR structure that contains additional information about
	 * the notification message.
	 */
	NMHDR hdr;
	/**
	 * Virtual key code.
	 */
	WORD wVKey;
	/**
	 * Set to zero.
	 */
	UINT flags;
} LV_KEYDOWN;
/**
 * This structure contains information used to update the cached item
 * information for use with a virtual list view.
 */
typedef struct tagNMLVCACHEHINT {
	/**
	 * NMHDR structure that contains information about this
	 * notification message.
	 */
	NMHDR hdr;
	/**
	 * Starting index of the requested range of items. This value
	 * is inclusive.
	 */
	int iFrom;
	/**
	 * Ending index of the requested range of items. This value is
	 * inclusive.
	 */
	int iTo;
} NMLVCACHEHINT, *LPNMLVCACHEHINT;
#define NM_CACHEHINT NMLVCACHEHINT
#define PNM_CACHEHINT LPNMLVCACHEHINT
#define LPNM_CACHEHINT LPNMLVCACHEHINT

typedef struct _TREEITEM *HTREEITEM;
typedef struct tagTVITEMA {
	UINT mask;
	HTREEITEM hItem;
	UINT state;
	UINT stateMask;
	LPSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int cChildren;
	LPARAM lParam;
} TVITEMA,*LPTVITEMA;
#define _TV_ITEMA tagTVITEMA
#define TV_ITEMA TVITEMA
#define LPTV_ITEMA LPTVITEMA
typedef struct tagTVITEMW {
	UINT mask;
	HTREEITEM hItem;
	UINT state;
	UINT stateMask;
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int cChildren;
	LPARAM lParam;
} TVITEMW,*LPTVITEMW;
#define _TV_ITEMW tagTVITEMW
#define TV_ITEMW TVITEMW
#define LPTV_ITEMW LPTVITEMW
#if (_WIN32_IE >= 0x0400)
typedef struct tagTVITEMEXA {
	UINT mask;
	HTREEITEM hItem;
	UINT state;
	UINT stateMask;
	LPSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int cChildren;
	LPARAM lParam;
	int iIntegral;
} TVITEMEXA, *LPTVITEMEXA;
typedef struct tagTVITEMEXW {
	UINT mask;
	HTREEITEM hItem;
	UINT state;
	UINT stateMask;
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
	int iSelectedImage;
	int cChildren;
	LPARAM lParam;
	int iIntegral;
} TVITEMEXW, *LPTVITEMEXW;
#endif /* _WIN32_IE >= 0x0400 */
typedef struct tagTVINSERTSTRUCTA {
	HTREEITEM hParent;
	HTREEITEM hInsertAfter;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	_ANONYMOUS_UNION union {
	TVITEMEXA itemex;
	TV_ITEMA item;
	} DUMMYUNIONNAME;
#else
	TV_ITEMA item;
#endif
} TVINSERTSTRUCTA,*LPTVINSERTSTRUCTA;
#define _TV_INSERTSTRUCTA tagTVINSERTSTRUCTA
#define TV_INSERTSTRUCTA TVINSERTSTRUCTA
#define LPTV_INSERTSTRUCTA LPTVINSERTSTRUCTA
typedef struct tagTVINSERTSTRUCTW {
	HTREEITEM hParent;
	HTREEITEM hInsertAfter;
#if (_WIN32_IE >= 0x0400) && !defined(_WIN32_WCE)
	_ANONYMOUS_UNION union {
	  TVITEMEXW itemex;
	  TV_ITEMW  item;
	} DUMMYUNIONNAME;
#else
	TV_ITEMW item;
#endif
} TVINSERTSTRUCTW,*LPTVINSERTSTRUCTW;
#define _TV_INSERTSTRUCTW tagTVINSERTSTRUCTW
#define TV_INSERTSTRUCTW TVINSERTSTRUCTW
#define LPTV_INSERTSTRUCTW LPTVINSERTSTRUCTW
typedef struct tagTVHITTESTINFO {
	POINT pt;
 	UINT flags;
	HTREEITEM hItem;
} TVHITTESTINFO, *LPTVHITTESTINFO;
#define _TV_HITTESTINFO tagTVHITTESTINFO
/**
 * This structure contains information used to determine the location of a
 * point relative to a tree view control. This structure is identical to
 * the TVHITTESTINFO structure, but was renamed to follow standard naming
 * conventions.
 */
#define TV_HITTESTINFO TVHITTESTINFO
#define LPTV_HITTESTINFO LPTVHITTESTINFO
typedef int(CALLBACK *PFNTVCOMPARE)(LPARAM,LPARAM,LPARAM);
typedef struct tagTVSORTCB {
	HTREEITEM hParent;
	PFNTVCOMPARE lpfnCompare;
	LPARAM lParam;
} TVSORTCB,*LPTVSORTCB;
#define _TV_SORTCB tagTVSORTCB
/**
 * This structure contains information used to sort child items in a tree
 * view control. This structure is identical to the TVSORTCB structure, but
 * was renamed to follow standard naming conventions.
 */
#define TV_SORTCB TVSORTCB
#define LPTV_SORTCB LPTVSORTCB
typedef struct tagNMTREEVIEWA {
	NMHDR hdr;
	UINT action;
	TV_ITEMA itemOld;
	TV_ITEMA itemNew;
	POINT ptDrag;
} NMTREEVIEWA,*LPNMTREEVIEWA;
#define _NM_TREEVIEWA tagNMTREEVIEWA
#define NM_TREEVIEWA NMTREEVIEWA
#define LPNM_TREEVIEWA LPNMTREEVIEWA
typedef struct tagNMTREEVIEWW {
	NMHDR hdr;
	UINT action;
	TV_ITEMW itemOld;
	TV_ITEMW itemNew;
	POINT ptDrag;
} NMTREEVIEWW,*LPNMTREEVIEWW;
#define _NM_TREEVIEWW tagNMTREEVIEWW
#define NM_TREEVIEWW NMTREEVIEWW
#define LPNM_TREEVIEWW LPNMTREEVIEWW
typedef struct tagNMTVDISPINFOA {
	NMHDR hdr;
	TVITEMA item;
} NMTVDISPINFOA, *LPNMTVDISPINFOA;
#define _TV_DISPINFOA tagNMTVDISPINFOA
#define TV_DISPINFOA NMTVDISPINFOA
typedef struct tagNMTVDISPINFOW {
	NMHDR hdr;
	TVITEMW item;
} NMTVDISPINFOW, *LPNMTVDISPINFOW;
#define _TV_DISPINFOW tagNMTVDISPINFOW
#define TV_DISPINFOW NMTVDISPINFOW
#if (_WIN32_IE >= 0x0400)
typedef struct tagNMTVGETINFOTIPA {
	NMHDR hdr;
	LPSTR pszText;
	int cchTextMax;
	HTREEITEM hItem;
	LPARAM lParam;
} NMTVGETINFOTIPA, *LPNMTVGETINFOTIPA;
typedef struct tagNMTVGETINFOTIPW {
	NMHDR hdr;
	LPWSTR pszText;
	int cchTextMax;
	HTREEITEM hItem;
	LPARAM lParam;
} NMTVGETINFOTIPW, *LPNMTVGETINFOTIPW;
#endif
/**
 * This structure contains information about a keyboard event in a tree
 * view control. This structure is identical to the NMTVKEYDOWN structure,
 * but was renamed to follow standard naming conventions.
 */
typedef struct _TV_KEYDOWN {
	/**
	 * NMHDR structure that contains information about this
	 * notification message.
	 */
	NMHDR hdr;
	/**
	 * Virtual key code.
	 */
	WORD wVKey;
	/**
	 * Set to zero.
	 */
	UINT flags;
} TV_KEYDOWN;
typedef struct tagTCITEMHEADERA {
	UINT mask;
	UINT lpReserved1;
	UINT lpReserved2;
	LPSTR pszText;
	int cchTextMax;
	int iImage;
} TCITEMHEADERA, *LPTCITEMHEADERA;
#define TC_ITEMHEADERA TCITEMHEADERA
typedef struct tagTCITEMHEADERW {
	UINT mask;
	UINT lpReserved1;
	UINT lpReserved2;
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
} TCITEMHEADERW, *LPTCITEMHEADERW;
#define TC_ITEMHEADERW TCITEMHEADERW
typedef struct tagTCITEMA {
	UINT mask;
#if (_WIN32_IE >= 0x0300)
	DWORD dwState;
	DWORD dwStateMask;
#else
 	UINT lpReserved1;
 	UINT lpReserved2;
#endif
	LPSTR pszText;
	int cchTextMax;
	int iImage;
	LPARAM lParam;
} TCITEMA, *LPTCITEMA;
#define TC_ITEMA TCITEMA
typedef struct tagTCITEMW {
	UINT mask;
#if (_WIN32_IE >= 0x0300)
	DWORD dwState;
	DWORD dwStateMask;
#else
 	UINT lpReserved1;
 	UINT lpReserved2;
#endif
	LPWSTR pszText;
	int cchTextMax;
	int iImage;
	LPARAM lParam;
} TCITEMW, *LPTCITEMW;
#define TC_ITEMW TCITEMW
typedef struct tagTCHITTESTINFO {
	POINT pt;
	UINT flags;
} TCHITTESTINFO, *LPTCHITTESTINFO;
/**
 * This structure contains information about a hit test, and is superseded
 * by the TCHITTESTINFO structure.
 */
#define TC_HITTESTINFO TCHITTESTINFO
#define LPTC_HITTESTINFO LPTCHITTESTINFO
/**
 * This structure contains information about a key press in a tab control,
 * and is superseded by the NMTCKEYDOWN structure.
 */
typedef struct _TC_KEYDOWN {
	/**
	 * NMHDR structure that contains information about the
	 * notification message.
	 */
	NMHDR hdr;
	/**
	 * Virtual key code.
	 */
	WORD wVKey;
	/**
	 * Value that is identical to the lParam parameter of the
	 * WM_KEYDOWN message.
	 */
	UINT flags;
} TC_KEYDOWN;
#if (_WIN32_IE >= 0x0300)
/**
 * This structure carries information used to load common control classes
 * from the dynamic-link library (DLL). This structure is used with the
 * InitCommonControlsEx function.
 *
 * Windows CE does not support the ICC_ANIMATE_CLASS, ICC_HOTKEY_CLASS,
 * ICC_INTERNET_CLASSES, or ICC_USEREX_CLASSES flags in the dwICC member.
 */
typedef struct tagINITCOMMONCONTROLSEX {
	/**
	 * Specifies the size of the structure, in bytes.
	 */
	DWORD dwSize;
	/**
	 * Indicates which common control classes will be loaded from
	 * the DLL. It can be a combination of the following values: Value
	 * Description ICC_BAR_CLASSES Loads toolbar, status bar, trackbar
	 * and command bar classes. ICC_COOL_CLASSES Loads rebar control
	 * class. ICC_DATE_CLASSES Loads date and time-picker control class.
	 * ICC_LISTVIEW_CLASSES Loads list view and header control classes.
	 * ICC_PROGRESS_CLASS Loads progress bar control class.
	 * ICC_TAB_CLASSES Loads tab control classes. ICC_TREEVIEW_CLASSES
	 * Loads tree view control classes. ICC_UPDOWN_CLASS Loads Up-Down
	 * control class.
	 */
	DWORD dwICC;
} INITCOMMONCONTROLSEX,*LPINITCOMMONCONTROLSEX;
#endif
/**
 * This structure contains information about the high and low limits of a
 * progress bar control. This structure is used with the PBM_GETRANGE
 * message.
 */
typedef struct tagPBRANGE {
	/**
	 * Specifies the current low limit for the progress bar
	 * control.
	 */
	int iLow;
	/**
	 * Specifies the current high limit for the progress bar
	 * control.
	 */
	int iHigh;
} PBRANGE,*PPBRANGE;
typedef struct tagCOLORSCHEME {
	DWORD dwSize;
	COLORREF clrBtnHighlight;
	COLORREF clrBtnShadow;
} COLORSCHEME,*LPCOLORSCHEME;
/**
 * This structure carries information specific to hit-testing points for a
 * month calendar control. This structure is used with the MCM_HITTEST
 * message and the corresponding MonthCal_HitTest macro.
 */
typedef struct tagMCHITTESTINFO {
	/**
	 * Size of this structure, in bytes.
	 */
	UINT cbSize;
	/**
	 * POINT structure that contains information about the point to
	 * be hit-tested.
	 */
	POINT pt;
	/**
	 * Output member that receives a bit flag representing the
	 * result of the hit-test operation. It is one of the following
	 * values: Value Description MCHT_CALENDARBK The specified point was
	 * in the calendar's background. MCHT_CALENDARDATE The specified
	 * point was on a particular date within the calendar. The
	 * SYSTEMTIME structure at lpMCHitTest->st is set to the date at the
	 * given point. MCHT_CALENDARDATENEXT The specified point was over a
	 * date from the next month (partially displayed at the end of the
	 * currently displayed month). If the user clicks here, the month
	 * calendar will scroll its display to the next month or set of
	 * months. MCHT_CALENDARDATEPREV The specified point was over a date
	 * from the previous month (partially displayed at the end of the
	 * currently displayed month). If the user clicks here, the month
	 * calendar will scroll its display to the previous month or set of
	 * months. MCHT_CALENDARDAY The specified point was over a day
	 * abbreviation ("Fri"). The SYSTEMTIME structure at lpMCHitTest->st
	 * is set to the corresponding date in the top row.
	 * MCHT_CALENDARWEEKNUM The specified point was over a week number
	 * (MCS_WEEKNUMBERS only). The SYSTEMTIME structure at
	 * lpMCHitTest->st is set to the corresponding date in the leftmost
	 * column. MCHT_NOWHERE The specified point was either not on the
	 * month calendar control, or in an inactive portion of the control.
	 * MCHT_TITLEBK The specified point was over the background of a
	 * month's title. MCHT_TITLEBTNNEXT The specified point was over the
	 * button at the top right corner of the control. If the user clicks
	 * here, the month calendar will scroll its display to the next
	 * month or set of months. MCHT_TITLEBTNPREV The specified point was
	 * over the button at the top left corner of the control. If the
	 * user clicks here, the month calendar will scroll its display to
	 * the previous month or set of months. MCHT_TITLEMONTH The
	 * specified point was in a month's title bar, over a month name.
	 * MCHT_TITLEYEAR The specified point was in a month's title bar,
	 * over the year value.
	 */
	UINT uHit;
	/**
	 * SYSTEMTIME structure that receives date and time information
	 * specific to the location that was hit-tested.
	 */
	SYSTEMTIME st;
}MCHITTESTINFO, *PMCHITTESTINFO;
typedef DWORD MONTHDAYSTATE;
typedef MONTHDAYSTATE *LPMONTHDAYSTATE;
/**
 * This structure carries information required to process the
 * MCN_GETDAYSTATE notification message. All members of this structure are
 * for input, except prgDayState, which the user must set when processing
 * MCN_GETDAYSTATE.
 */
typedef struct tagNMDAYSTATE {
	/**
	 * NMHDR structure that contains information about this
	 * notification message.
	 */
	NMHDR nmhdr;
	/**
	 * SYSTEMTIME structure that contains the starting date.
	 */
	SYSTEMTIME stStart;
	/**
	 * Value that specifies the total number of elements that
	 * must be in the array at prgDayState.
	 */
	int cDayState;
	/**
	 * Pointer to an array of MONTHDAYSTATE values. This
	 * must be set to point to an array that contains as many elements
	 * as specified in cDayState. The first element in the array
	 * corresponds to the date in stStart.
	 */
	LPMONTHDAYSTATE prgDayState;
}NMDAYSTATE,*LPNMDAYSTATE;
/**
 * This structure contains information that describes rebar control
 * characteristics.
 */
typedef struct tagREBARINFO {
	/**
	 * Size of this structure, in bytes. Your application must
	 * fill this member before sending any messages that use the address
	 * of this structure as a parameter.
	 */
	UINT cbSize;
	/**
	 * Flag values that describe characteristics of the rebar
	 * control. Currently, rebar controls support only one value. Value
	 * Description RBIM_IMAGELIST The himl member is valid or must be
	 * filled.
	 */
	UINT fMask;
	/**
	 * Handle to an image list. The rebar control will use the
	 * specified image list to obtain images.
	 */
	HIMAGELIST himl;
} REBARINFO,*LPREBARINFO;
typedef struct tagREBARBANDINFOA {
	UINT cbSize;
	UINT fMask;
	UINT fStyle;
	COLORREF clrFore;
	COLORREF clrBack;
	LPSTR lpText;
	UINT cch;
	int iImage;
	HWND hwndChild;
	UINT cxMinChild;
	UINT cyMinChild;
	UINT cx;
	HBITMAP hbmBack;
	UINT wID;
#if (_WIN32_IE >= 0x0400)
	UINT cyChild;
	UINT cyMaxChild;
	UINT cyIntegral;
	UINT cxIdeal;
	LPARAM lParam;
#if !defined(_WIN32_WCE)
	UINT cxHeader;
#endif
#endif
} REBARBANDINFOA,*LPREBARBANDINFOA;
typedef struct tagREBARBANDINFOW {
	UINT cbSize;
	UINT fMask;
	UINT fStyle;
	COLORREF clrFore;
	COLORREF clrBack;
	LPWSTR lpText;
	UINT cch;
	int iImage;
	HWND hwndChild;
	UINT cxMinChild;
	UINT cyMinChild;
	UINT cx;
	HBITMAP hbmBack;
	UINT wID;
#if (_WIN32_IE >= 0x0400) || (defined(_WIN32_WCE) && GRIMACE_CE >= 2)
	UINT cyChild;
	UINT cyMaxChild;
	UINT cyIntegral;
	UINT cxIdeal;
	LPARAM lParam;
#if !defined(_WIN32_WCE)
	UINT cxHeader;
#endif
#endif
} REBARBANDINFOW,*LPREBARBANDINFOW;
typedef REBARBANDINFOA const *LPCREBARBANDINFOA;
typedef REBARBANDINFOW const *LPCREBARBANDINFOW;
#define REBARBANDINFOA_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOA,wID)
#define REBARBANDINFOW_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOW, wID)
#if (_WIN32_IE >= 0x0300) || (_WIN32_WCE >= 0x0200)
/**
 * This structure that contains information for use in processing the
 * LVN_ODSTATECHANGED notification message.
 */
typedef struct tagNMLVODSTATECHANGE {
  /**
   * NMHDR structure that contains additional information about
   * the notification message.
   */
  NMHDR hdr;
  /**
   * Zero-based index of the first item in the range of items.
   */
  int iFrom;
  /**
   * Zero-based index of the last item in the range of items.
   */
  int iTo;
  UINT uNewState;
  UINT uOldState;
} NMLVODSTATECHANGE, *LPNMLVODSTATECHANGE;
/**
 * This structure contains information about an image list draw operation
 * and is used with the ImageList_DrawIndirect function.
 *
 * An overlay image is an image that is drawn on top of the primary image
 * specified in the i member of this structure. To specify an overlay
 * image, logically OR the fStyle member with the INDEXTOOVERLAYMASK macro,
 * passing the one-based index of the overlay image in the macro. This
 * image must have been previously specified as an overlay image using the
 * ImageList_SetOverlayImage API.
 *
 * To extract the overlay image from the fStyle member, use the logical AND
 * to combine fStyle with the ILD_OVERLAYMASK value.
 */
typedef struct tagIMAGELISTDRAWPARAMS {
	/**
	 * Size of this structure, in bytes.
	 */
	DWORD cbSize;
	/**
	 * Handle to the image list that contains the image to be
	 * drawn.
	 */
	HIMAGELIST himl;
	/**
	 * Zero-based index of the image to be drawn.
	 */
	int i;
	/**
	 * Handle to the destination device context.
	 */
	HDC hdcDst;
	int x;
	int y;
	int cx;
	int cy;
	int xBitmap;        
	int yBitmap;        
	/**
	 * Image background color. It can be an application-defined
	 * RGB value or one of the following values: Value Description
	 * CLR_DEFAULT Default background color. The image is drawn using
	 * the image list background color. CLR_NONE No background color.
	 * The image is drawn transparently. This parameter is used only if
	 * the image list identified by himl was created with the ILC_MASK
	 * value.
	 */
	COLORREF rgbBk;
	/**
	 * Image foreground color. It is an application-defined RGB
	 * value or one of the following values: Value Description
	 * CLR_DEFAULT Default foreground color. The image is drawn using
	 * the system highlight color as the foreground color. CLR_NONE No
	 * blend color. The image is blended with the color of the
	 * destination device context. This parameter is used only if fStyle
	 * includes the ILD_BLEND25 or ILD_BLEND50 flag.
	 */
	COLORREF rgbFg;
	/**
	 * Flag that specifies the drawing style and, optionally,
	 * the overlay image. It can be a combination of one or more of the
	 * following values: Value Description ILD_BLEND25 Draws the image,
	 * blending 25 percent with the blend color specified by rgbFg. This
	 * value has no effect if the image list does not contain a mask.
	 * ILD_FOCUS Same as ILD_BLEND25. ILD_BLEND50 Draws the image,
	 * blending 50 percent with the blend color specified by rgbFg. This
	 * value has no effect if the image list does not contain a mask.
	 * ILD_SELECTED Same as ILD_BLEND50. ILD_BLEND Same as ILD_BLEND50.
	 * ILD_MASK Draws the mask. ILD_NORMAL Draws the image using the
	 * background color for the image list. If the background color is
	 * the CLR_NONE value, the image is drawn transparently using the
	 * mask. ILD_ROP Draws the image using the raster-operation code
	 * specified by the dwRop member. ILD_TRANSPARENT Draws the image
	 * transparently using the mask, regardless of the background color.
	 * This value has no effect if the image list does not contain a
	 * mask.
	 */
	UINT fStyle;
	/**
	 * Specifies a raster-operation code. These codes define how
	 * the color data for the source rectangle will be combined with the
	 * color data for the destination rectangle to achieve the final
	 * color. This member is ignored if the fStyle member does not
	 * include the ILD_ROP flag. Some common raster operation codes are
	 * listed below: Value Description BLACKNESS Fills the destination
	 * rectangle using the color associated with index 0 in the physical
	 * palette. (This color is black for the default physical palette.)
	 * DSTINVERT Inverts the destination rectangle. MERGECOPY Merges the
	 * source rectangle colors with the specified pattern by using the
	 * Boolean AND operator. MERGEPAINT Merges the inverted source
	 * rectangle colors with the destination rectangle colors by using
	 * the Boolean OR operator. NOTSRCCOPY Copies the inverted source
	 * rectangle to the destination. NOTSRCERASE Combines the source and
	 * destination rectangle colors by using the Boolean OR operator.
	 * Inverts the resultant color. PATCOPY Copies the specified pattern
	 * into the destination bitmap. PATINVERT Combines the specified
	 * pattern colors with the destination rectangle colors by using the
	 * Boolean XOR operator. PATPAINT Combines the pattern colors with
	 * the inverted source rectangle colors by using the Boolean OR
	 * operator. Combines the result with the destination rectangle
	 * colors by using the Boolean OR operator. SRCAND Combines the
	 * source and destination rectangle colors by using the Boolean AND
	 * operator. SRCCOPY Copies the source rectangle directly to the
	 * destination rectangle. SRCERASE Combines the destination
	 * rectangle's inverted colors with the source rectangle colors by
	 * using the Boolean AND operator. SRCINVERT Combines the source and
	 * destination rectangle colors by using the Boolean XOR operator.
	 * SRCPAINT Combines the source and destination rectangle colors by
	 * using the Boolean OR operator. WHITENESS Fills the destination
	 * rectangle using the color associated with index 1 in the physical
	 * palette. (This color is white for the default physical palette.)
	 */
	DWORD dwRop;
#if (_WIN32_WINNT >= 0x0501) && !defined (_WIN32_WCE)
	DWORD fState;
	DWORD Frame;
	COLORREF crEffect;
#endif
} IMAGELISTDRAWPARAMS,*LPIMAGELISTDRAWPARAMS;
#endif /* (_WIN32_IE >= 0x0300) || (_WIN32_WCE >= 0x0200) */
#if (_WIN32_IE >= 0x0400)
typedef struct tagNMREBARCHILDSIZE {
	NMHDR hdr;
	UINT uBand;
	UINT wID;
	RECT rcChild;
	RECT rcBand;
} NMREBARCHILDSIZE,*LPNMREBARCHILDSIZE;
#ifdef _WIN32_WCE
typedef struct tagNMREBAR {
	NMHDR hdr;
	UINT uBand;
	UINT wID;
	UINT cyChild;
	UINT cyBand;
} NMREBAR,*LPNMREBAR;
#else
typedef struct tagNMREBAR {
	NMHDR hdr;
	DWORD dwMask;
	UINT uBand;
	UINT fStyle;
	UINT wID;
	LPARAM lParam;
} NMREBAR,*LPNMREBAR;
#endif
typedef struct tagNMRBAUTOSIZE {
	NMHDR hdr;
	BOOL fChanged;
	RECT rcTarget;
	RECT rcActual;
} NMRBAUTOSIZE,*LPNMRBAUTOSIZE;
#if (_WIN32_IE >= 0x0500)
typedef struct tagNMREBARCHEVRON {
	NMHDR hdr;
	UINT uBand;
	UINT wID;
	LPARAM lParam;
	RECT rc;
	LPARAM lParamNM;
} NMREBARCHEVRON, *LPNMREBARCHEVRON;
#endif
/**
 * This structure contains information specific to a hit test operation.
 * This structure is used with the RB_HITTEST message.
 */
typedef struct _RB_HITTESTINFO {
	/**
	 * POINT structure that describes the point to be hit tested, in
	 * client coordinates.
	 */
	POINT pt;
	/**
	 * Receives a flag value indicating the rebar band's
	 * component located at the point described by pt. It is one of the
	 * following values: Value Description RBHT_CAPTION The point was in
	 * the rebar band's caption. RBHT_CLIENT The point was in the rebar
	 * band's client area. RBHT_GRABBER The point was in the rebar
	 * band's grabber. RBHT_NOWHERE The point was not in a rebar band.
	 */
	UINT flags;
	/**
	 * Receives the rebar band's index at the point described by
	 * pt. This value is the zero-based index of the band or -1 if no
	 * band was at the hit-tested point.
	 */
	int iBand;
} RBHITTESTINFO,*LPRBHITTESTINFO;
#endif
typedef struct _DSA *HDSA;
typedef struct _DPA *HDPA;
typedef INT (CALLBACK *PFNDPAENUMCALLBACK)(PVOID,PVOID);
typedef INT (CALLBACK *PFNDSAENUMCALLBACK)(PVOID,PVOID);
typedef INT (CALLBACK *PFNDPACOMPARE)(PVOID,PVOID,LPARAM);
#if (_WIN32_WINNT >= 0x0501)
typedef LRESULT (CALLBACK *SUBCLASSPROC)(HWND,UINT,WPARAM,LPARAM,UINT_PTR,DWORD_PTR);
typedef struct tagLITEM {
	UINT mask;
	int iLink;
	UINT state;
	UINT stateMask;
	WCHAR szID[MAX_LINKID_TEXT];
	WCHAR szUrl[L_MAX_URL_LENGTH];
} LITEM,*PLITEM;
typedef struct tagLHITTESTINFO {
	POINT pt;
	LITEM item;
} LHITTESTINFO,*PLHITTESTINFO;
typedef struct tagNMLINK {
	NMHDR hdr;
	LITEM item;
} NMLINK,*PNMLINK;
#endif /* _WIN32_WINNT >= 0x0501 */

/**
 * This macro prepares the index of an overlay mask so that the
 * ImageList_Draw or ImageList_DrawEx function can use it.
 *
 * The INDEXTOOVERLAYMASK macro is defined as follows:
 *
 *     #define INDEXTOOVERLAYMASK(i) ((i) << 8)
 *
 * @param iOverlay Index of an overlay mask.
 */
#define INDEXTOOVERLAYMASK(i) ((i)<<8)
/**
 * This macro prepares the index of a state image so that a tree-view
 * control or list-view control can use the index to retrieve the state
 * image for an item.
 *
 * The INDEXTOSTATEIMAGEMASK macro is defined as follows:
 *
 *     #define INDEXTOSTATEIMAGEMASK(i) ((i) << 12)
 *
 * @param i Index of a state image.
 */
#define INDEXTOSTATEIMAGEMASK(i) ((i)<<12)
/**
 * This macro calls a function that processes the WM_NOTIFY message.
 *
 * The HANDLE_WM_NOTIFY macro is defined as follows:
 *
 *     #define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
 *         (fn)((hwnd), (int)(wParam), (NMHDR FAR*)(lParam))
 *
 * @param hwnd Handle to the window that received WM_NOTIFY.
 * @param wParam First parameter of WM_NOTIFY.
 * @param lParam Second parameter of WM_NOTIFY.
 * @param fn Function that is to process WM_NOTIFY.
 * @return The meaning of the value depends on the fn parameter.
 */
#define HANDLE_WM_NOTIFY(h,w,l,f) (f)((h),(int)(w),(NMHDR*)(l))
/**
 * This macro sends or posts the WM_NOTIFY message.
 *
 * The FORWARD_WM_NOTIFY macro is defined as follows:
 *
 *     #define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
 *         (void)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(id), \
 *         (LPARAM)(NMHDR FAR*)(pnmhdr))
 *
 * @param hwnd Handle to the window that receives the WM_NOTIFY message.
 * @param idFrom Identifier of the control sending the message.
 * @param pnmhdr Pointer to an NMHDR structure that contains the
 *        notification code and additional information. For some
 *        notification messages, this parameter points to a larger
 *        structure that has the NMHDR structure as its first member.
 * @param fn Function that sends or posts the WM_NOTIFY message. It can be
 *        either the SendMessage or PostMessage function.
 * @return The meaning of the value depends on the fn parameter.
 */
#define FORWARD_WM_NOTIFY(h,i,p,f) (LRESULT)(f)((h),WM_NOTIFY,(WPARAM)(int)(i),(LPARAM)(NMHDR*)(p))
#define CCSIZEOF_STRUCT(s,m) (((int)((PBYTE)(&((s*)0)->m)-((PBYTE)((s*)0))))+sizeof(((s*)0)->m))
#define MAKEIPADDRESS(b1,b2,b3,b4) ((LPARAM)(((DWORD)(b1)<<24)+((DWORD)(b2)<<16)+((DWORD)(b3)<<8)+((DWORD)(b4))))
#define MAKEIPRANGE(low,high) ((LPARAM)(WORD)(((BYTE)(high)<<8)+(BYTE)(low)))
#define FIRST_IPADDRESS(a) ((a>>24) & 0xff)
#define SECOND_IPADDRESS(a) ((a>>16) & 0xff)
#define THIRD_IPADDRESS(a)  ((a>>8) & 0xff)
#define FOURTH_IPADDRESS(a) (a & 0xff)
#define Animate_Create(w,i,s,hI) CreateWindow(ANIMATE_CLASS,NULL,s,0,0,0,0,w,(HMENU)(i),hI,NULL)
#define Animate_Open(w,f) (BOOL)SNDMSG(w,ACM_OPEN,0,(LPARAM)f)
#define Animate_OpenEx(w,h,s) (BOOL)SNDMSG(w,ACM_OPEN,(WPARAM)h,(LPARAM)(LPTSTR)(s))
#define Animate_Play(w,f,t,r) (BOOL)SNDMSG(w,ACM_PLAY,(r),(LPARAM)MAKELONG(f,t))
#define Animate_Stop(w)	(BOOL)SNDMSG(w,ACM_STOP,0,0)
#define Animate_Close(w)	Animate_Open(w,NULL)
#define Animate_Seek(w,f)	Animate_Play(w,f,f,1)
HBITMAP WINAPI CreateMappedBitmap(HINSTANCE,int,UINT,LPCOLORMAP,int);
HWND WINAPI CreateStatusWindowA(LONG,LPCSTR,HWND,UINT);
/**
 * Creates a status bar, normally along the bottom of the parent window.
 *
 * A wrapper for CreateWindow with default position and size.
 *
 * @param style Window styles. Must include WS_CHILD and normally WS_VISIBLE.
 * @param lpszText Text for the first part.
 * @param hwndParent Parent window.
 * @param wID Control identifier, used in notifications to the parent.
 * @return The status bar, or NULL on failure.
 */
HWND WINAPI CreateStatusWindowW(LONG style,LPCWSTR lpszText,HWND hwndParent,UINT wID);
/**
 * Creates a toolbar and adds buttons and their images to it.
 *
 * @param hwnd Parent window.
 * @param ws Window and toolbar styles. Include WS_CHILD.
 * @param wID Control identifier.
 * @param nBitmaps Number of images in the bitmap.
 * @param hBMInst Module containing the bitmap resource, HINST_COMMCTRL for
 *        the system images, or NULL if wBMID is an HBITMAP.
 * @param wBMID Bitmap resource identifier, or a bitmap handle.
 * @param lpButtons Array of TBBUTTON structures.
 * @param iNumButtons Number of entries in lpButtons.
 * @param dxButton Button width, in pixels, or 0 for the default.
 * @param dyButton Button height, in pixels, or 0 for the default.
 * @param dxBitmap Image width, in pixels, or 0 for the default.
 * @param dyBitmap Image height, in pixels, or 0 for the default.
 * @param uStructSize sizeof(TBBUTTON).
 * @return The toolbar, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
HWND WINAPI CreateToolbarEx(HWND hwnd,DWORD ws,UINT wID,int nBitmaps,HINSTANCE hBMInst,UINT wBMID,LPCTBBUTTON lpButtons,int iNumButtons,int dxButton,int dyButton,int dxBitmap,int dyBitmap,UINT uStructSize);
/**
 * Creates an up-down (spin) control.
 *
 * On Windows CE the buddy window can only be an edit control.
 *
 * @param dwStyle Window styles, normally WS_CHILD, WS_BORDER and WS_VISIBLE,
 *        plus UDS_* styles.
 * @param x Left edge, in client coordinates.
 * @param y Top edge, in client coordinates.
 * @param cx Width, in pixels.
 * @param cy Height, in pixels.
 * @param hwndParent Parent window.
 * @param nID Control identifier.
 * @param hinst Application instance.
 * @param hwndBuddy Edit control to pair it with, or NULL for none.
 * @param nUpper Upper limit of the range.
 * @param nLower Lower limit of the range.
 * @param nPos Initial position.
 * @return The control, or NULL on failure.
 */
HWND WINAPI CreateUpDownControl(DWORD dwStyle,int x,int y,int cx,int cy,HWND hwndParent,int nID,HINSTANCE hinst,HWND hwndBuddy,int nUpper,int nLower,int nPos);
/**
 * This macro retrieves the handle to a date and time picker's (DTP) child
 * month calendar control.
 *
 * DTP controls create a child month calendar control when the user clicks
 * the drop-down arrow. When the month calendar is no longer needed, it is
 * destroyed. Therefore, your application must not rely on a static handle
 * to the DTP's child month calendar.
 *
 * @param hwndDP Handle to a DTP control.
 * @return Returns the handle to a DTP control's child month calendar
 *        control.
 */
#define DateTime_GetMonthCal(hwnd) SNDMSG(hwnd, DTM_GETMONTHCAL, 0, 0)
/**
 * This macro retrieves the color for a specified portion of the month
 * calendar within a date and time picker (DTP) control.
 *
 * @param hwndDP Handle to a DTP control.
 * @param iColor INT value that specifies which month calendar color to
 *        retrieve. It is one of the following values: Value Description
 *        MCSC_BACKGROUND Retrieves the background color displayed between
 *        months. MCSC_MONTHBK Retrieves the background color displayed
 *        within the month. MCSC_TEXT Retrieves the color used to display
 *        text within a month. MCSC_TITLEBK Retrieves the background color
 *        displayed in the calendar's title. MCSC_TITLETEXT Retrieves the
 *        color used to display text within the calendar's title.
 *        MCSC_TRAILINGTEXT Retrieves the color used to display header and
 *        trailing-day text. Header and trailing days are the days from the
 *        previous and following months that appear on the current
 *        calendar.
 * @return Returns a COLORREF value that represents the color setting for
 *        the specified portion of the month calendar control if
 *        successful. Otherwise, the macro returns -1.
 */
#define DateTime_GetMonthCalColor(hwnd, icolor) SNDMSG(hwnd, DTM_GETMONTHCAL, (WPARAM)icolor,0)
/**
 * This macro retrieves the font that the date and time picker (DTP)
 * control's child month calendar control is currently using.
 *
 * @param hwndDP Handle to a DTP control.
 * @return Returns an HFONT value that is the handle to the current font.
 */
#define DateTime_GetMonthCalFont(hwnd) SNDMSG(hwnd,DTM_GETMCFONT,0,0)
/**
 * This macro retrieves the current minimum and maximum allowable system
 * times for a date and time picker (DTP) control.
 *
 * @param hwndDT Handle to a DTP control.
 * @param lpSysTimeArray Long pointer to a two-element array of SYSTEMTIME
 *        structures.
 * @return Returns a DWORD value that is a combination of GDTR_MIN or
 *        GDTR_MAX. The first element of the SYSTEMTIME array contains the
 *        minimum allowable time. The second element of the SYSTEMTIME
 *        array contains the maximum allowable time.
 */
#define DateTime_GetRange(hwnd,lpsystimearray) SNDMSG(hwnd,DTM_GETRANGE,0,(LPARAM)lpsystimearray)
/**
 * This macro retrieves the currently selected time from a date and time
 * picker (DTP) control and places it in a specified SYSTEMTIME structure.
 *
 * @param hwndDP Handle to a DTP control.
 * @param lpSysTime Long pointer to the SYSTEMTIME structure that receives
 *        the system time information.
 * @return Returns a DWORD value that equals GDT_VALID if the time
 *        information was successfully placed in the specified structure;
 *        or the message can return GDT_NONE if the control was set to the
 *        DTS_SHOWNONE style and the control check box was not selected.
 */
#define DateTime_GetSystemtime(hwnd,lpsystime) SNDMSG(hwnd,DTM_GETSYSTEMTIME,0,(LPARAM)lpsystime)
/**
 * This macro sets the display of a date and time picker (DTP) control
 * based on a specified format string.
 *
 * It is acceptable to include extra characters within the format string to
 * produce a richer display. However, any nonformat characters must be
 * enclosed within single quotes. For example, the format string " 'Today
 * is: 'hh':'m':'s ddddMMMdd', 'yyy" would produce output like "Today is:
 * 04:22:31 Tuesday Mar 23, 1996".
 *
 * No errors are returned for a bad format string. The function simply
 * forms the best date string that it can. For example, the only year
 * pictures that are valid are L"yyyy" and L"yy" (the 'L' indicates a
 * Unicode (16-bit characters) string). If L"y" is passed in, the function
 * assumes L"yy". If L"yyy" is passed in, the function assumes L"yyyy". If
 * more than 4 date ("dddd") or 4 month (L"MMMM") pictures are passed in,
 * then the function defaults to L"dddd" or L"MMMM".
 *
 * Any text that should remain in its exact form in the date string should
 * be enclosed within single quotation marks in the date format picture.
 * The single quotation mark may also be used as an escape character to
 * allow the single quotation mark itself to be displayed in the date
 * string. However, the escape sequence must be enclosed within two single
 * quotation marks. For example, to display the date as "May '93", the
 * format string would be: L"MMMM ''''yy" The first and last single
 * quotation marks are the enclosing quotation marks. The second and third
 * single quotation marks are the escape sequence to allow the single
 * quotation mark to be displayed before the century.
 *
 * Note A DTP control tracks locale changes when it is using the default
 * format string. If you set a custom format string, it will not be updated
 * in response to locale changes.
 *
 * @param hwndDT Handle to a DTP control.
 * @param lpszFormat Long pointer to a null-terminated format string that
 *        defines the desired display. Setting this parameter to NULL will
 *        reset the control to the default format string for the current
 *        style. The format string is a combination of string fragments. It
 *        is interpreted literally, with the exception of the following
 *        string fragments. Value Description "d" The one- or two-digit
 *        day. "dd" The two-digit day. Single-digit day values are preceded
 *        by a zero. "ddd" The three-character weekday abbreviation. "dddd"
 *        The full weekday name. "h" The one- or two-digit hour in 12-hour
 *        format. "hh" The two-digit hour in 12-hour format. Single-digit
 *        values are preceded by a zero. "H" The one- or two-digit hour in
 *        24-hour format. "HH" The two-digit hour in 24-hour format.
 *        Single-digit values are preceded by a zero. "m" The one- or
 *        two-digit minute. "mm" The two-digit minute. Single-digit values
 *        are preceded by a zero. "M" The one- or two-digit month number.
 *        "MM" The two-digit month number. Single-digit values are preceded
 *        by a zero. "MMM" The three-character month abbreviation. "MMMM"
 *        The full month name. "t" The one-letter AM/PM abbreviation (that
 *        is, "AM" is displayed as "A"). "tt" The two-letter AM/PM
 *        abbreviation (that is, "AM" is displayed as "AM"). "X" A callback
 *        field. The control still uses the other valid format characters,
 *        and queries the owner to fill in the "X" portion. Therefore, the
 *        owner must be prepared to handle the DTN_WMKEYDOWN, DTN_FORMAT,
 *        and DTN_FORMATQUERY notification messages. Multiple "X"
 *        characters can be used to signify unique callback fields. "y" The
 *        year is displayed as the last two digits, but with no leading
 *        zero for years less than 10. "yy" The last two digits of the year
 *        (that is, 1998 would be displayed as "98"). "yyy" The full year
 *        (that is, 1998 would be displayed as "1998").
 * @return Returns TRUE if successful, or FALSE otherwise.
 */
#define DateTime_SetFormat(hwnd,lpszformat) SNDMSG(hwnd,DTM_SETFORMAT,0,(LPARAM)lpszformat)
/**
 * This macro sets the color for a specified portion of the month calendar
 * within a date and time picker (DTP) control.
 *
 * @param hwndDP Handle to a DTP control.
 * @param iColor INT value that specifies which month calendar color to
 *        set. It is one of the following values: Value Description
 *        MCSC_BACKGROUND Sets the background color displayed between
 *        months. MCSC_MONTHBK Sets the background color displayed within
 *        the month. MCSC_TEXT Sets the color used to display text within a
 *        month. MCSC_TITLEBK Sets the background color displayed in the
 *        calendar's title. MCSC_TITLETEXT Sets the color used to display
 *        text within the calendar's title. MCSC_TRAILINGTEXT Sets the
 *        color used to display header and trailing-day text. Header and
 *        trailing days are the days from the previous and following months
 *        that appear on the current calendar.
 * @param clr COLORREF value that represents the color that will be set for
 *        the specified area of the month calendar.
 * @return Returns a COLORREF value that represents the previous color
 *        setting for the specified portion of the month calendar control
 *        if successful. Otherwise, this message returns -1.
 */
#define DateTime_SetMonthCalColor(hwnd,icolor,clr) SNDMSG(hwnd,DTM_SETMCCOLOR,(WPARAM)icolor,(LPARAM)clr)
/**
 * This macro sets the font to be used by the date and time picker (DTP)
 * control's child month calendar control.
 *
 * @param hwndDP Handle to a DTP control.
 * @param hFont Handle to the font that will be set.
 * @param fRedraw Value that specifies whether the control should be
 *        redrawn immediately upon setting the font. If set to TRUE, the
 *        control redraws itself.
 */
#define DateTime_SetMonthCalFont(hwnd,hfont,lparam) SNDMSG(hwnd,DTM_SETMCFONT,(WPARAM)hfont,(LPARAM)lparam)
/**
 * This macro sets the minimum and maximum allowable system times for a
 * date and time picker (DTP) control.
 *
 * @param hwndDT Handle to a DTP control.
 * @param flags Value that specifies which range values are valid. It can
 *        be a combination of the following values: Value Description
 *        GDTR_MIN The first element in the SYSTEMTIME structure array is
 *        valid and will be used to set the minimum allowable system time.
 *        GDTR_MAX The second element in the SYSTEMTIME structure array is
 *        valid and will be used to set the maximum allowable system time.
 * @param lpSysTimeArray Long pointer to a two-element array of SYSTEMTIME
 *        structures. The first element of the SYSTEMTIME array contains
 *        the minimum allowable time. The second element of the SYSTEMTIME
 *        array contains the maximum allowable time. It is not necessary to
 *        fill an array element that is not specified in the flags
 *        parameter.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define DateTime_SetRange(hwnd,flags,lpsystimearray) SNDMSG(hwnd,DTM_SETRANGE,(WPARAM)flags,(LPARAM)lpsystimearray)
/**
 * This macro sets a date and time picker (DTP) control to a specified date
 * and time.
 *
 * @param hwndDT Handle to a DTP control.
 * @param flag Value that specifies the action that should be performed. It
 *        is one of the following values: Value Description GDT_VALID Set
 *        the DTP control according to the data within the SYSTEMTIME
 *        structure pointed to by lpSysTime. GDT_NONE Set the DTP control
 *        to "no date" and clear its check box. lpSysTime is ignored when
 *        this flag is specified. This flag applies only to DTP controls
 *        that are set to the DTS_SHOWNONE style.
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the system time information by which to set the DTP control.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define DateTime_SetSystemtime(hwnd,flag,lpsystime) SNDMSG(hwnd,DTM_SETSYSTEMTIME,(WPARAM)flag,(LPARAM)lpsystime)
void WINAPI DrawInsert(HWND,HWND,int);
void WINAPI DrawStatusTextA(HDC,LPRECT,LPCSTR,UINT);
/**
 * Draws text with a border, in the style of a status bar.
 *
 * A tab in the text centres what follows it; two tabs right-align it.
 *
 * @param hdc Device context to draw into.
 * @param lprc Rectangle to draw in, in client coordinates. The border is
 *        drawn just inside it.
 * @param szText The text.
 * @param uFlags 0, SBT_NOBORDERS for no border, or SBT_POPOUT for a raised
 *        border.
 */
void WINAPI DrawStatusTextW(HDC hdc,LPRECT lprc,LPCWSTR szText,UINT uFlags);
void WINAPI GetEffectiveClientRect(HWND,LPRECT,LPINT);
#if (_WIN32_IE >= 0x0500)
LANGID WINAPI GetMUILanguage(VOID);
#endif
/**
 * This macro retrieves a count of the items in a header control. You can
 * use this macro or send the HDM_GETITEMCOUNT message explicitly.
 *
 * The Header_GetItemCount macro is defined as follows:
 *
 *     #define Header_GetItemCount(hwndHD)        \
 *             (int)SendMessage((hwndHD), HDM_GETITEMCOUNT, 0, 0L)
 *
 * @param hwndHD Handle to the header control.
 * @return The number of items indicates success. -1 indicates failure.
 */
#define Header_GetItemCount(w) (int)SNDMSG((w),HDM_GETITEMCOUNT,0,0)
/**
 * This macro inserts a new item into a header control. You can use this
 * macro or send the HDM_INSERTITEM message explicitly.
 *
 * The Header_InsertItem macro is defined as follows:
 *
 *     #define Header_InsertItem(hwndHD, index, phdi)    \
 *         (int)SendMessage((hwndHD), HDM_INSERTITEM, (WPARAM)(int)(index), \
 *         (LPARAM)(const LPHDITEM)(phdi))
 *
 * @param hwndHD Handle to the header control.
 * @param index Index of the item after which the new item is to be
 *        inserted. The new item is inserted at the end of the header
 *        control if index is greater than or equal to the number of items
 *        in the control. If index is zero, the new item is inserted at the
 *        beginning of the header control.
 * @param phdi Pointer to an HDITEM structure that contains information
 *        about the new item.
 * @return The index of the new item indicates success. -1 indicates
 *        failure.
 */
#define Header_InsertItem(w,i,phdi) (int)SNDMSG((w),HDM_INSERTITEM,(WPARAM)(int)(i),(LPARAM)(const HD_ITEM*)(phdi))
/**
 * This macro deletes an item from a header control. You can use this macro
 * or send the HDM_DELETEITEM message explicitly.
 *
 * The Header_DeleteItem macro is defined as follows:
 *
 *     #define Header_DeleteItem(hwndHD, index)        \
 *         (BOOL)SendMessage((hwndHD), HDM_DELETEITEM, (WPARAM)(int)(index), 0L)
 *
 * @param hwndHD Handle to the header control.
 * @param index Index of the item to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define Header_DeleteItem(w,i) (BOOL)SNDMSG((w),HDM_DELETEITEM,(WPARAM)(int)(i),0)
/**
 * This macro retrieves information about an item in a header control. You
 * can use this macro or send the HDM_GETITEM message explicitly.
 *
 * The Header_GetItem macro is defined as follows:
 *
 *     #define Header_GetItem(hwndHD, index, phdi)        \
 *         (BOOL)SendMessage((hwndHD), HDM_GETITEM,        \
 *         (WPARAM)(int)(index), (LPARAM)(LPHDITEM)(phdi))
 *
 * @param hwndHD Handle to the header control.
 * @param index Index of the item for which information is to be retrieved.
 * @param phdi Pointer to an HDITEM structure. When the message is sent,
 *        the mask member indicates the type of information being
 *        requested. When the message returns, the other members receive
 *        the requested information. If the mask member specifies zero, the
 *        message returns TRUE but copies no information to the structure.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define Header_GetItem(w,i,phdi) (BOOL)SNDMSG((w),HDM_GETITEM,(WPARAM)(int)(i),(LPARAM)(HD_ITEM*)(phdi))
/**
 * This macro sets the attributes of the specified item in a header
 * control. You can use this macro or send the HDM_SETITEM message
 * explicitly.
 *
 * In Windows CE version 2.0, this macro supports item order and image list
 * information. By using the iImage and iOrder members of the new HDITEM
 * structure you pass in the phdi parameter, you can control the order in
 * which items are displayed and specify images to appear with items.
 *
 * The HDITEM structure that supports this macro supports item order and
 * image list information. By using these members, you can control the
 * order in which items are displayed and specify images to appear with
 * items.
 *
 * @param hwndHD Handle to a header control.
 * @param iIndex Current index of the item for which attributes are to be
 *        changed.
 * @param phdItem Pointer to an HDITEM structure that contains item
 *        information. When this message is sent, the mask member of the
 *        structure must be set to indicate which attributes are being set.
 * @return Nonzero indicates success. Zero indicates failure.
 */
#define Header_SetItem(w,i,phdi) (BOOL)SNDMSG((w),HDM_SETITEM,(WPARAM)(int)(i),(LPARAM)(const HD_ITEM*)(phdi))
/**
 * This macro retrieves the size and position of a header control within a
 * specified rectangle. This macro is used to determine the appropriate
 * dimensions for a new header control that is to occupy the specified
 * rectangle. You can use this macro or send the HDM_LAYOUT message
 * explicitly.
 *
 * The Header_Layout macro is defined as follows:
 *
 *     #define Header_Layout(hwndHD, playout) \
 *         (BOOL)SendMessage((hwndHD), HDM_LAYOUT, 0, \
 *         (LPARAM)(PLHDLAYOUT)(playout))
 *
 * @param hwndHD Handle to the header control.
 * @param playout Pointer to an HDLAYOUT structure. The prc member
 *        specifies the coordinates of a rectangle, and the pwpos member
 *        receives the size and position for the header control within the
 *        rectangle.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define Header_Layout(w,l) (BOOL)SNDMSG((w),HDM_LAYOUT,0,(LPARAM)(HD_LAYOUT*)(l))
#if (_WIN32_IE >= 0x0300)
/**
 * This macro retrieves an index value for an item based on its order in
 * the header control.
 *
 * @param hwndHD Handle to a header control.
 * @param iOrder Order that the item appears within the header control,
 *        from left to right. The index value of the item in the far left
 *        column would be 0, the next item to the right would be 1, and so
 *        on.
 * @return Returns an INT that specifies the index of the item. If iOrder
 *        is invalid, (that is, negative or too large) the return value
 *        equals iOrder.
 */
#define Header_OrderToIndex(w,o) (int)SNDMSG((w),HDM_ORDERTOINDEX,(WPARAM)(o),0)
/**
 * This macro retrieves the bounding rectangle for a specified item in a
 * header control.
 *
 * @param hwndHD Handle to a header control.
 * @param iIndex Zero-based index of the header control item for which to
 *        retrieve the bounding rectangle.
 * @param lpItemRect Long pointer to a RECT structure that receives the
 *        bounding rectangle information.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define Header_GetItemRect(w,i,r) (BOOL)SNDMSG((w),HDM_GETITEMRECT,(WPARAM)(i),(LPARAM)(r))
/**
 * This macro retrieves the current left-to-right order of items in a
 * header control.
 *
 * @param hwndHD Handle to a header control.
 * @param iSize Size of the buffer at lpiArray, in elements. This value
 *        must equal the value returned by HDM_GETITEMCOUNT.
 * @param lpiArray Long pointer to a buffer that receives the index values
 *        of the items in the header. The buffer should be big enough to
 *        hold the total number of items * sizeof(int). For example, the
 *        following code fragment will reserve enough memory to hold the
 *        index values.
 * @return Returns nonzero if successful, and the buffer at lpiArray
 *        receives the item number of each item in the header control, in
 *        the order in which they appear from left to right. The macro
 *        returns zero otherwise.
 */
#define Header_GetOrderArray(w,l,a) (BOOL)SNDMSG((w),HDM_GETORDERARRAY,(WPARAM)(l),(LPARAM)(a))
/**
 * This macro sets the left-to-right order of header items.
 *
 * @param hwndHD Handle to a header control.
 * @param iSize Size of the buffer at lpiArray, in elements. This value
 *        must equal the value returned by HDM_GETITEMCOUNT.
 * @param lpiArray Long pointer to an array that specifies the order in
 *        which items should be displayed, from left to right. For example,
 *        if the contents of the array are {2,0,1}, the control displays
 *        item 2, item 0, and item 1 in that order.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define Header_SetOrderArray(w,l,a) (BOOL)SNDMSG((w),HDM_SETORDERARRAY,(WPARAM)(l),(LPARAM)(a))
/**
 * This macro creates a transparent version of an item image within an
 * existing header control.
 *
 * @param hwndHD Handle to a header control.
 * @param iIndex Zero-based index of the item within the header control.
 *        The image assigned to this item is used as the basis for the
 *        transparent image.
 * @return Returns a handle to an image list that contains the new image as
 *        its only element.
 */
#define Header_CreateDragImage(w, i) (HIMAGELIST)SNDMSG((w), HDM_CREATEDRAGIMAGE, (WPARAM)i, 0)
/**
 * This macro assigns an image list to an existing header control.
 *
 * @param hwndHD Handle to a header control.
 * @param himl Handle to an image list.
 * @return Returns the handle to the image list previously assigned to the
 *        header control, or NULL if there is no previous image list.
 */
#define Header_SetImageList(w,l) (HIMAGELIST)SNDMSG((w), HDM_SETIMAGELIST, 0, (LPARAM)l)
/**
 * This macro retrieves the handle to the image list that has been set for
 * an existing header control.
 *
 * @param hwndHD Handle to a header control.
 * @return Returns the handle to the image list that is set for the header
 *        control.
 */
#define Header_GetImageList(w) (HIMAGELIST)SNDMSG((w),HDM_GETIMAGELIST,0,0)
#endif
#if (_WIN32_IE >= 0x0400)
#define Header_GetUnicodeFormat(w) (BOOL)SNDMSG((w),HDM_GETUNICODEFORMAT,0,0)
#define Header_SetUnicodeFormat(w,f) (BOOL)SNDMSG((w),HDM_SETUNICODEFORMAT,(WPARAM)(f),0)
#endif
/**
 * Creates a dynamic structure array, holding fixed-size items by value.
 *
 * Undocumented in the Windows CE SDK. Free with DSA_Destroy.
 *
 * @param cbItem Size of each item, in bytes.
 * @param cItemGrow Number of items to grow by when the array is full.
 * @return The array, or NULL on failure.
 */
HDSA WINAPI DSA_Create(INT cbItem,INT cItemGrow);
/**
 * Frees a dynamic structure array and the items it holds.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param hdsa The array.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI DSA_Destroy(HDSA hdsa);
VOID WINAPI DSA_DestroyCallback(HDSA,PFNDSAENUMCALLBACK,PVOID);
/**
 * Returns a pointer to an item in a dynamic structure array.
 *
 * Undocumented in the Windows CE SDK. The pointer becomes invalid when the
 * array grows or shrinks.
 *
 * @param hdsa The array.
 * @param i Zero-based index of the item.
 * @return Pointer to the item, or NULL if i is out of range.
 */
PVOID WINAPI DSA_GetItemPtr(HDSA hdsa,INT i);
/**
 * Inserts a copy of an item into a dynamic structure array.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param hdsa The array.
 * @param i Index to insert at. An index past the end, such as DA_LAST,
 *        appends.
 * @param pitem The item to copy in.
 * @return Index of the new item, or -1 on failure.
 */
INT WINAPI DSA_InsertItem(HDSA hdsa,INT i,PVOID pitem);
HDPA WINAPI DPA_Create(INT);
/**
 * Frees a dynamic pointer array.
 *
 * Undocumented in the Windows CE SDK. Frees only the array: free the items
 * it points to first.
 *
 * @param hdpa The array.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI DPA_Destroy(HDPA hdpa);
PVOID WINAPI DPA_DeletePtr(HDPA,INT);
BOOL WINAPI DPA_DeleteAllPtrs(HDPA);
VOID WINAPI DPA_EnumCallback(HDPA,PFNDPAENUMCALLBACK,PVOID);
VOID WINAPI DPA_DestroyCallback(HDPA,PFNDPAENUMCALLBACK,PVOID);
BOOL WINAPI DPA_SetPtr(HDPA,INT,PVOID);
INT WINAPI DPA_InsertPtr(HDPA,INT,PVOID);
/**
 * Returns an item from a dynamic pointer array.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param hdpa The array.
 * @param i Zero-based index of the item.
 * @return The item, or NULL if i is out of range.
 */
PVOID WINAPI DPA_GetPtr(HDPA hdpa,INT_PTR i);
BOOL WINAPI DPA_Sort(HDPA,PFNDPACOMPARE,LPARAM);
INT WINAPI DPA_Search(HDPA,PVOID,INT,PFNDPACOMPARE,LPARAM,UINT);
/**
 * Replaces a dynamically allocated string with a newly allocated copy of
 * another.
 *
 * Undocumented in the Windows CE SDK. In desktop comctl32 the old string
 * is freed, so passing NULL for psz frees the string and sets *ppsz to
 * NULL.
 *
 * @param ppsz The string pointer to update. Must be NULL or a string
 *        previously set by Str_SetPtrW.
 * @param psz The string to copy, or NULL.
 * @return TRUE on success, FALSE if allocation fails.
 */
BOOL WINAPI Str_SetPtrW(LPWSTR*ppsz,LPCWSTR psz);
#if (_WIN32_IE >= 0x0400)
BOOL WINAPI FlatSB_EnableScrollBar(HWND,INT,UINT);
BOOL WINAPI FlatSB_ShowScrollBar(HWND,INT,BOOL);
BOOL WINAPI FlatSB_GetScrollRange(HWND,INT,LPINT,LPINT);
BOOL WINAPI FlatSB_GetScrollInfo(HWND,INT,LPSCROLLINFO);
INT WINAPI FlatSB_GetScrollPos(HWND,INT);
BOOL WINAPI FlatSB_GetScrollProp(HWND,INT,LPINT);
#ifdef _WIN64
BOOL WINAPI FlatSB_GetScrollPropPtr(HWND,INT,PINT_PTR);
#else
#define FlatSB_GetScrollPropPtr FlatSB_GetScrollProp
#endif
INT WINAPI FlatSB_SetScrollPos(HWND,INT,INT,BOOL);
INT WINAPI FlatSB_SetScrollInfo(HWND,INT,LPSCROLLINFO,BOOL);
INT WINAPI FlatSB_SetScrollRange(HWND,INT,INT,INT,BOOL);
BOOL WINAPI FlatSB_SetScrollProp(HWND,UINT,INT_PTR,BOOL);
#define FlatSB_SetScrollPropPtr FlatSB_SetScrollProp
BOOL WINAPI InitializeFlatSB(HWND);
HRESULT WINAPI UninitializeFlatSB(HWND);
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_WINNT >= 0x0501)
BOOL WINAPI SetWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR,DWORD_PTR);
BOOL WINAPI GetWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR,DWORD_PTR*);
BOOL WINAPI RemoveWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR);
LRESULT WINAPI DefSubclassProc(HWND,UINT,WPARAM,LPARAM);
INT WINAPI DrawShadowText(HDC,LPCWSTR,UINT,RECT*,DWORD,COLORREF,COLORREF,INT,INT);
#endif /* _WIN32_WINNT >= 0x0501 */
/**
 * Adds one or more images to an image list.
 *
 * The bitmaps are copied, so delete them with DeleteObject afterwards.
 *
 * @param himl The image list.
 * @param hbmImage Bitmap with the images side by side. The number of images
 *        comes from its width.
 * @param hbmMask Mask bitmap. Ignored if the list has no mask.
 * @return Index of the first new image, or -1 on failure.
 */
int WINAPI ImageList_Add(HIMAGELIST himl,HBITMAP hbmImage,HBITMAP hbmMask);
/**
 * This macro adds an icon to an image list. ImageList_AddIcon calls the
 * ImageList_ReplaceIcon function.
 *
 * In Windows CE, you can only use this macro with icons, not cursors.
 *
 * Because the system does not save hicon, you can destroy it after the
 * macro returns if the icon was created by the CreateIcon function. You do
 * not need to destroy hicon if it was loaded by the LoadIcon function; the
 * system automatically frees an icon resource when it is no longer needed.
 *
 * The ImageList_AddIcon macro is defined as follows:
 *
 *     #define ImageList_AddIcon(himl, hicon) ImageList_ReplaceIcon(himl, -1, hicon)
 *
 * @param himl Handle to the image list. If this parameter identifies a
 *        masked image list, the macro copies both the image and mask
 *        bitmaps of the icon or cursor. If this parameter identifies a
 *        nonmasked image list, the macro copies only the image bitmap.
 * @param hicon Handle to the icon or cursor that contains the bitmap and
 *        mask for the new image.
 * @return The index of the new image indicates success. -1 indicates
 *        failure.
 */
#define ImageList_AddIcon(l,i) ImageList_ReplaceIcon(l,-1,i)
/**
 * Adds one or more images to an image list, making the mask from a colour.
 *
 * Pixels of crMask colour are set to black in the image and transparent in
 * the mask. The bitmap is copied, so delete it with DeleteObject afterwards.
 *
 * @param himl The image list.
 * @param hbmImage Bitmap with the images side by side. The number of images
 *        comes from its width.
 * @param crMask The transparent colour.
 * @return Index of the first new image, or -1 on failure.
 */
int WINAPI ImageList_AddMasked(HIMAGELIST himl,HBITMAP hbmImage,COLORREF crMask);
/**
 * Starts dragging an image.
 *
 * Creates a temporary drag image list. Show it with ImageList_DragEnter, move
 * it with ImageList_DragMove on WM_MOUSEMOVE and finish with
 * ImageList_EndDrag.
 *
 * @param himlTrack The image list.
 * @param iTrack Index of the image to drag.
 * @param dxHotspot Hot spot x, relative to the image's top left.
 * @param dyHotspot Hot spot y, relative to the image's top left.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_BeginDrag(HIMAGELIST himlTrack,int iTrack,int dxHotspot,int dyHotspot);
/**
 * Creates an image list.
 *
 * Destroy with ImageList_Destroy.
 *
 * @param cx Width of each image, in pixels.
 * @param cy Height of each image, in pixels.
 * @param flags ILC_COLOR or ILC_COLORDDB, optionally with ILC_MASK for a
 *        monochrome mask. ILC_COLOR on Windows CE 1.0 is a 2bpp DIB; on
 *        later versions it picks the display driver's default, usually 4
 *        bits per pixel, or a device-dependent bitmap on older drivers.
 *        ILC_COLOR4, ILC_COLOR8, ILC_COLOR16, ILC_COLOR24 and ILC_COLOR32
 *        aren't supported.
 * @param cInitial Number of images to allocate space for initially.
 * @param cGrow Number of images to grow by when the list is full.
 * @return The image list, or NULL on failure.
 */
HIMAGELIST WINAPI ImageList_Create(int cx,int cy,UINT flags,int cInitial,int cGrow);
/**
 * Destroys an image list.
 *
 * @param himl The image list.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_Destroy(HIMAGELIST himl);
/**
 * Locks a window against updates during a drag and shows the drag image in
 * it.
 *
 * Start the drag with ImageList_BeginDrag first.
 *
 * @param hwndLock Window to show the drag image in.
 * @param x Position of the drag image, relative to the window's top left,
 *        not its client area.
 * @param y Position of the drag image, relative to the window's top left,
 *        not its client area.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_DragEnter(HWND hwndLock,int x,int y);
/**
 * Hides the drag image and unlocks the window so it can update.
 *
 * @param hwndLock Window passed to ImageList_DragEnter.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_DragLeave(HWND hwndLock);
/**
 * Moves the drag image, typically on WM_MOUSEMOVE.
 *
 * @param x New x position, as for ImageList_DragEnter.
 * @param y New y position, as for ImageList_DragEnter.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_DragMove(int x,int y);
/**
 * Shows or hides the drag image without locking the window.
 *
 * @param fShow TRUE to show, FALSE to hide.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_DragShowNolock(BOOL fShow);
/**
 * Draws an image from an image list.
 *
 * @param himl The image list.
 * @param iDraw Index of the image.
 * @param hdcDst Destination device context.
 * @param x Left edge in hdcDst.
 * @param y Top edge in hdcDst.
 * @param fStyle ILD_NORMAL, ILD_TRANSPARENT, ILD_BLEND25 (ILD_FOCUS),
 *        ILD_BLEND50 (ILD_SELECTED), ILD_MASK or ILD_IMAGE, optionally with
 *        an overlay from INDEXTOOVERLAYMASK. Blending and transparency need
 *        a masked list.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_Draw(HIMAGELIST himl,int iDraw,HDC hdcDst,int x,int y,UINT fStyle);
/**
 * Draws an image from an image list, with given background and blend
 * colours.
 *
 * @param himl The image list.
 * @param iDraw Index of the image.
 * @param hdcDst Destination device context.
 * @param x Left edge in hdcDst.
 * @param y Top edge in hdcDst.
 * @param cx Width of the part of the image to draw, or 0 for all of it.
 *        Not validated.
 * @param cy Height of the part of the image to draw, or 0 for all of it.
 *        Not validated.
 * @param rgbBk Background colour, CLR_NONE for transparent or CLR_DEFAULT
 *        for the list's background colour. Only used with ILC_MASK lists.
 * @param rgbFg Blend colour, CLR_NONE to blend with the destination, or
 *        CLR_DEFAULT (CLR_HILIGHT) for the highlight colour. Only used with
 *        ILD_BLEND25 or ILD_BLEND50.
 * @param fStyle Drawing style, as for ImageList_Draw.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_DrawEx(HIMAGELIST himl,int iDraw,HDC hdcDst,int x,int y,int cx,int cy,COLORREF rgbBk,COLORREF rgbFg,UINT fStyle);
/**
 * Ends a drag started with ImageList_BeginDrag.
 */
void WINAPI ImageList_EndDrag(VOID);
/**
 * This macro calls the ImageList_GetIcon function to create an icon based
 * on an image and mask in an image list.
 *
 * In Windows CE, you can only use the ImageList_ExtractIcon macro to
 * create an icon, not a cursor.
 *
 * ImageList_ExtractIcon is not supported for emulation.
 *
 * @param hi [in] Not used; set to 0.
 * @param himl [in] Handle to the image list.
 * @param i [in] Index of the image.
 * @return The handle of the icon indicates success. NULL indicates
 *        failure.
 */
#define ImageList_ExtractIcon(h,l,i) ImageList_GetIcon(l,i,0)
/**
 * Returns the background color of an image list.
 *
 * @param himl The image list.
 * @return The background color, or CLR_NONE if images are drawn
 *         transparently using the mask.
 */
COLORREF WINAPI ImageList_GetBkColor(HIMAGELIST himl);
/**
 * Returns the temporary image list used for the current drag image, and
 * the drag position and hot spot offset.
 *
 * The image list is destroyed by ImageList_EndDrag. Don't destroy it
 * yourself.
 *
 * @param ppt Receives the current drag position, or NULL.
 * @param pptHotspot Receives the offset of the drag image from the drag
 *        position, or NULL.
 * @return The drag image list, or NULL if no drag is in progress.
 */
HIMAGELIST WINAPI ImageList_GetDragImage(LPPOINT ppt,LPPOINT pptHotspot);
/**
 * Creates an icon from an image and its mask in an image list.
 *
 * Windows CE can create only icons this way, not cursors. Destroy the
 * result with DestroyIcon.
 *
 * @param himl The image list.
 * @param iImage Index of the image.
 * @param fStyle Drawing style, ILD_* as for ImageList_Draw.
 * @return The new icon, or NULL on failure.
 */
HICON WINAPI ImageList_GetIcon(HIMAGELIST himl,int iImage,UINT fStyle);
/**
 * Gets the width and height of the images in an image list.
 *
 * All images in a list are the same size.
 *
 * @param himl The image list.
 * @param cx Receives the width, in pixels.
 * @param cy Receives the height, in pixels.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_GetIconSize(HIMAGELIST himl,int*cx,int*cy);
/**
 * Returns the number of images in an image list.
 *
 * @param himl The image list.
 * @return The number of images.
 */
int WINAPI ImageList_GetImageCount(HIMAGELIST himl);
/**
 * Gets the bitmaps and bounding rectangle of an image.
 *
 * The returned bitmaps belong to the image list. They can be used to draw
 * or modify the image directly, but don't delete them.
 *
 * @param himl The image list.
 * @param iImage Index of the image.
 * @param pImageInfo Receives the image and mask bitmaps and the image's
 *        rectangle within them.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_GetImageInfo(HIMAGELIST himl,int iImage,IMAGEINFO*pImageInfo);
/**
 * This macro calls the ImageList_LoadImage function to create an image
 * list from the specified bitmap resource.
 *
 * This macro is not supported for emulation.
 *
 * @param hi [in] Handle to the instance that contains the bitmap resource.
 *        This parameter is NULL if you are loading an OEM bitmap.
 * @param lpbmp [in] Long pointer to the image to load. If the hi parameter
 *        is non-NULL, lpbmp is the address of a null-terminated string
 *        that contains the name of the image resource in the hi module. If
 *        hi is NULL, the low-order word of this parameter must be the
 *        identifier of an OEM bitmap to load. To create this value, use
 *        the MAKEINTRESOURCE macro with one of the OEM bitmap identifiers
 *        defined in WINUSER.H. These identifiers have the OBM_ prefix.
 * @param cx [in] Width of each image. The height of each image and the
 *        initial number of images are inferred by the dimensions of the
 *        specified bitmap.
 * @param cGrow [in] Number of images by which the image list can grow when
 *        the system needs to make room for new images. This parameter
 *        represents the number of new images that the resized image list
 *        can contain.
 * @param crMask [in] Color used to generate a mask. Each pixel of this
 *        color in the specified bitmap is changed to black, and the
 *        corresponding bit in the mask is set to 1. If this parameter is
 *        the CLR_NONE value, no mask is generated.
 * @return The handle to the image list indicates success. NULL indicates
 *        failure.
 */
#define ImageList_LoadBitmap(h,l,x,G,M) ImageList_LoadImage(h,l,x,G,M,IMAGE_BITMAP,0)
HIMAGELIST WINAPI ImageList_LoadImageA(HINSTANCE,LPCSTR,int,int,COLORREF,UINT,UINT);
/**
 * Creates an image list from a bitmap or icon resource.
 *
 * Only icons are supported, not cursors. OEM support may vary.
 *
 * @param hi Instance containing the image, or NULL for an OEM image.
 * @param lpbmp Resource name in hi; with LR_LOADFROMFILE a file name; or,
 *        if hi is NULL, an OEM image identifier (OBM_* or OIC_*) made
 *        with MAKEINTRESOURCE.
 * @param cx Width of each image. The height and initial number of images
 *        are inferred from the resource.
 * @param cGrow Number of images to add when the list grows.
 * @param crMask Colour used to create the mask: its pixels become black
 *        and set in the mask. CLR_NONE for no mask, CLR_DEFAULT to use the
 *        top-left pixel's colour.
 * @param uType IMAGE_BITMAP or IMAGE_ICON.
 * @param uFlags Unsupported; set to 0.
 * @return Image-list handle, or NULL on failure.
 */
HIMAGELIST WINAPI _WNAME(ImageList_LoadImage)(HINSTANCE hi,LPCWSTR lpbmp,int cx,int cGrow,COLORREF crMask,UINT uType,UINT uFlags);
/**
 * Creates a new image list holding one image made by drawing one image
 * transparently over another.
 *
 * The new mask is the OR of the two source masks. Destroy the result with
 * ImageList_Destroy.
 *
 * @param himl1 Image list holding the background image.
 * @param iImage1 Index of the background image.
 * @param himl2 Image list holding the image to draw on top.
 * @param iImage2 Index of the image to draw on top.
 * @param dx Horizontal offset of the second image from the first.
 * @param dy Vertical offset of the second image from the first.
 * @return The new image list, or NULL on failure.
 */
HIMAGELIST WINAPI ImageList_Merge(HIMAGELIST himl1,int iImage1,HIMAGELIST himl2,int iImage2,int dx,int dy);
/**
 * Removes an image, or all images, from an image list.
 *
 * Images after the removed one move down an index.
 *
 * @param himl The image list.
 * @param iRemove Index of the image, or -1 for all images.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_Remove(HIMAGELIST himl,int iRemove);
/**
 * This function removes an image from an image list. ImageList_RemoveAll
 * is a function that calls the ImageList_Remove function.
 *
 * @param himl [in] Handle to the image list, and the index of the image to
 *        remove.
 * @return Nonzero indicates success. Zero indicates failure.
 */
#define ImageList_RemoveAll(l) ImageList_Remove(l,-1)
/**
 * Replaces an image in an image list with new image and mask bitmaps.
 *
 * The bitmaps are copied, so delete them with DeleteObject afterwards.
 *
 * @param himl The image list.
 * @param iReplace Index of the image to replace.
 * @param hbmImage The new image bitmap.
 * @param hbmMask The new mask bitmap. Ignored if the list has no mask.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_Replace(HIMAGELIST himl,int iReplace,HBITMAP hbmImage,HBITMAP hbmMask);
/**
 * Replaces an image with an icon, or appends the icon to the list.
 *
 * Takes icons only, not cursors. The icon is copied, so an icon you
 * created can be destroyed afterwards. Icons from LoadIcon needn't be.
 *
 * @param himl The image list.
 * @param iReplace Index of the image to replace, or -1 to append.
 * @param hicon The icon, providing both the image and mask.
 * @return Index of the image, or -1 on failure.
 */
int WINAPI ImageList_ReplaceIcon(HIMAGELIST himl,int iReplace,HICON hicon);
/**
 * Sets the background color used when drawing an image list's images.
 *
 * @param himl The image list.
 * @param clrBk The background color, or CLR_NONE to draw images
 *        transparently using the mask.
 * @return The previous background color, or CLR_NONE on failure.
 */
COLORREF WINAPI ImageList_SetBkColor(HIMAGELIST himl,COLORREF clrBk);
/**
 * Combines an image with the current drag image to make a new drag
 * image.
 *
 * Typically used to add a cursor-like image to the drag image during a
 * drag started with ImageList_BeginDrag.
 *
 * @param himlDrag Image list holding the image to combine.
 * @param iDrag Index of the image to combine.
 * @param dxHotspot Horizontal position of the hot spot within the image.
 * @param dyHotspot Vertical position of the hot spot within the image.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_SetDragCursorImage(HIMAGELIST himlDrag,int iDrag,int dxHotspot,int dyHotspot);
/**
 * Sets the size of the images in an image list, removing all images.
 *
 * @param himl The image list.
 * @param cx New image width, in pixels.
 * @param cy New image height, in pixels.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_SetIconSize(HIMAGELIST himl,int cx,int cy);
/**
 * Makes an image available as one of up to four overlay masks.
 *
 * To draw an image with an overlay, pass INDEXTOOVERLAYMASK(iOverlay) in
 * the style flags of ImageList_Draw or ImageList_DrawEx.
 *
 * @param himl The image list.
 * @param iImage Index of the image to use as an overlay.
 * @param iOverlay Overlay number, 1 to 4.
 * @return TRUE on success, FALSE on failure.
 */
BOOL WINAPI ImageList_SetOverlayImage(HIMAGELIST himl,int iImage,int iOverlay);
#ifdef _OBJIDL_H
HIMAGELIST WINAPI ImageList_Read(LPSTREAM);
BOOL WINAPI ImageList_Write(HIMAGELIST,LPSTREAM);
#endif
#if (_WIN32_IE >= 0x0400) || (_WIN32_WCE >= 0x0200)
/**
 * Creates a copy of an image list, with all its images and settings.
 *
 * @param himl The image list to copy.
 * @return The new image list, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
HIMAGELIST WINAPI ImageList_Duplicate(HIMAGELIST himl);
#endif
/**
 * Loads the common controls DLL and registers its window classes.
 *
 * Call it before creating any common control, or use InitCommonControlsEx
 * to register only the classes you need.
 */
void WINAPI InitCommonControls(void);
#if (_WIN32_IE >= 0x0300)
/**
 * Registers chosen common control window classes.
 *
 * @param lpInitCtrls Structure with dwSize set and dwICC holding ICC_*
 *        flags: ICC_BAR_CLASSES (toolbar, status bar, trackbar, command
 *        bar), ICC_COOL_CLASSES, ICC_DATE_CLASSES, ICC_LISTVIEW_CLASSES,
 *        ICC_PROGRESS_CLASS, ICC_TAB_CLASSES, ICC_TREEVIEW_CLASSES and
 *        ICC_UPDOWN_CLASS. Windows CE doesn't support ICC_ANIMATE_CLASS,
 *        ICC_HOTKEY_CLASS, ICC_INTERNET_CLASSES or ICC_USEREX_CLASSES.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL WINAPI InitCommonControlsEx(LPINITCOMMONCONTROLSEX lpInitCtrls);
#endif
#if (_WIN32_IE >= 0x0500)
VOID WINAPI InitMUILanguage(LANGID);
#endif
int WINAPI LBItemFromPt(HWND,POINT,BOOL);
/**
 * This macro retrieves the background color of a list view control. You
 * can use this macro or send the LVM_GETBKCOLOR message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the background color of the list view control.
 */
#define ListView_GetBkColor(w) (COLORREF)SNDMSG((w),LVM_GETBKCOLOR,0,0)
/**
 * This macro retrieves the handle to an image list used for drawing list
 * view items. You can use this macro or send the LVM_GETIMAGELIST message
 * explicitly.
 *
 * Windows CE supports a new value for the iImageList parameter. The
 * LVSIL_HEADER constant specifies that the image list to be retrieved is
 * the image list displayed in the list view's header control in report
 * view.
 *
 * @param hwnd Handle to the list view control.
 * @param iImageList Image list to retrieve. It is one of the following
 *        values: Value Description LVSIL_NORMAL Image list with large
 *        icons. LVSIL_SMALL Image list with small icons. LVSIL_STATE Image
 *        list with state images.
 * @return The handle to the specified image list indicates success. NULL
 *        indicates failure.
 */
#define ListView_GetImageList(w,i) (HIMAGELIST)SNDMSG((w),LVM_GETIMAGELIST,(i),0)
/**
 * This macro retrieves the number of items in a list view control. You can
 * use this macro or send the LVM_GETITEMCOUNT message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the number of items.
 */
#define ListView_GetItemCount(w) (int)SNDMSG((w),LVM_GETITEMCOUNT,0,0)
/**
 * This macro retrieves some or all of a list view item's attributes. You
 * can use this macro or send the LVM_GETITEM message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param pitem Pointer to an LVITEM structure that specifies the
 *        information to retrieve and receives information about the list
 *        view item. When the LVM_GETITEM message is sent, the iItem and
 *        iSubItem members identify the item or subitem to retrieve
 *        information about and the mask member specifies which attributes
 *        to retrieve. For a list of possible values, see the description
 *        of the LVITEM structure. If the mask member specifies the
 *        LVIF_TEXT value, the pszText member must contain the address of
 *        the buffer that receives the item text, and the cchTextMax member
 *        must specify the size of the buffer. If the mask member specifies
 *        the LVIF_STATE value, the stateMask member must specify the item
 *        state bits to retrieve. On output, the state member contains the
 *        values of the specified state bits.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_GetItem(w,i) (BOOL)SNDMSG((w),LVM_GETITEM,0,(LPARAM)(i))
/**
 * This macro sets the background color a list view control. You can use
 * this macro or send the LVM_SETBKCOLOR message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param clrBk Background color to set or the CLR_NONE value for no
 *        background color. List view controls with background colors
 *        redraw themselves significantly faster than those without
 *        background colors.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetBkColor(w,c) (BOOL)SNDMSG((w),LVM_SETBKCOLOR,0,(LPARAM)c)
/**
 * This macro assigns an image list to a list view control. You can use
 * this macro or send the LVM_SETIMAGELIST message explicitly.
 *
 * Windows CE supports a new value for the iImageList parameter. The
 * LVSIL_HEADER constant specifies that, in report view, the image list
 * will be displayed in the list view's header control.
 *
 * @param hwnd Handle to the list view control.
 * @param himl Handle to the image list to assign.
 * @param iImageList Type of image list. It is one of the following values:
 *        Value Description LVSIL_NORMAL Image list with large icons.
 *        LVSIL_SMALL Image list with small icons. LVSIL_STATE Image list
 *        with state images.
 * @return The handle to the image list previously associated with the
 *        control indicates success. NULL indicates failure.
 */
#define ListView_SetImageList(w,h,i) (HIMAGELIST)(UINT)SNDMSG((w),LVM_SETIMAGELIST,(i),(LPARAM)(h))
/**
 * This macro sets some or all of a list view item's attributes. You can
 * also use ListView_SetItem to set the text of a subitem. You can use this
 * macro or send the LVM_SETITEM message explicitly.
 *
 * To set the attributes of a list view item, set the iItem member of the
 * LVITEM structure to the index of the item, and set the iSubItem member
 * to zero. For an item, you can use the state, pszText, iImage, and lParam
 * members of the LVITEM structure to modify these item parameters.
 *
 * To set the text of a subitem, set the iItem and iSubItem members to
 * indicate the specific subitem, and use the pszText member to specify the
 * text. Alternatively, you can use the ListView_SetItemText macro to set
 * the text of a subitem. You cannot set the state or lParam members for
 * subitems because subitems do not have these attributes. In version 4.70
 * and later, you can set the iImage member for subitems. The subitem image
 * will be displayed if the list view control has the LVS_EX_SUBITEMIMAGES
 * extended style. Previous versions will ignore the subitem image.
 *
 * @param hwnd Handle to the list view control.
 * @param pitem Pointer to an LVITEM structure that contains the new item
 *        attributes. The iItem and iSubItem members identify the item or
 *        subitem, and the mask member specifies which attributes to set.
 *        If the mask member specifies the LVIF_TEXT value, the pszText
 *        member is the address of a null-terminated string and the
 *        cchTextMax member is ignored. If the mask member specifies the
 *        LVIF_STATE value, the stateMask member specifies which item
 *        states to change, and the state member contains the values for
 *        those states.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetItem(w,i) (BOOL)SNDMSG((w),LVM_SETITEM,0,(LPARAM)(const LV_ITEM*)(i))
/**
 * This macro inserts a new item in a list view control. You can use this
 * macro or send the LVM_INSERTITEM message explicitly.
 *
 * If a list view control has either the LVS_SORTASCENDING or
 * LVS_SORTDESCENDING window style, an LVM_INNSETITEM message will fail if
 * you try to insert an item that has LPSTR_TEXTCALLBACK as the pszText
 * member of its LVITEM structure.
 *
 * @param hwnd Handle to the list view control.
 * @param pitem Pointer to an LVITEM structure that specifies the
 *        attributes of the list view item. The iItem member of the
 *        structure specifies the index of the new item. You cannot use
 *        ListView_InsertItem or LVM_INSERTITEM to insert subitems; the
 *        iSubItem member of the LVITEM structure must be zero.
 * @return The index of the new item indicates success. -1 indicates
 *        failure.
 */
#define ListView_InsertItem(w,i) (int)SNDMSG((w),LVM_INSERTITEM,0,(LPARAM)(const LV_ITEM*)(i))
/**
 * This macro removes an item from a list view control. You can use this
 * macro or send the LVM_DELETEITEM message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem Index of the list view item to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_DeleteItem(w,i) (BOOL)SNDMSG((w),LVM_DELETEITEM,i,0)
/**
 * This macro removes all items from a list view control. You can use this
 * macro or send the LVM_DELETEALLITEMS message explicitly.
 *
 * When a list view control receives the LVM_DELETEALLITEMS message, it
 * sends the LVN_DELETEALLITEMS notification message to its parent window.
 *
 * @param hwnd Handle to the list view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_DeleteAllItems(w) (BOOL)SNDMSG((w),LVM_DELETEALLITEMS,0,0)
/**
 * This macro retrieves the callback mask for a list view control. You can
 * use this macro or send the LVM_GETCALLBACKMASK message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the callback mask.
 */
#define ListView_GetCallbackMask(w) (UINT)SNDMSG((w),LVM_GETCALLBACKMASK,0,0)
/**
 * This macro changes the callback mask for a list view control. You can
 * use this macro or send the LVM_SETCALLBACKMASK message explicitly.
 *
 * The callback mask of a list view control is a set of bit flags that
 * specify the item states for which the application, rather than the
 * control, stores the current data. The callback mask applies to all of
 * the control's items, unlike the callback item designation, which applies
 * to a specific item. The callback mask is zero by default, meaning that
 * the list view control stores all item state information. After creating
 * a list view control and initializing its items, you can use the
 * ListView_SetCallbackMask macro or LVM_SETCALLBACKMASK message to change
 * the callback mask. To get the current callback mask, send the
 * LVM_GETCALLBACKMASK message.
 *
 * @param hwnd Handle to the list view control.
 * @param mask Value of the callback mask. The bits of the mask indicate
 *        the item states or images for which the application stores the
 *        current state data. It can be any combination of the following
 *        constants: Value Description LVIS_CUT The item is marked for a
 *        cut-and-paste operation. LVIS_DROPHILITED The item is highlighted
 *        as a drag-and-drop target. LVIS_FOCUSED The item has the focus.
 *        LVIS_SELECTED The item is selected. LVIS_OVERLAYMASK The
 *        application stores the image list index of the current overlay
 *        image for each item. LVIS_STATEIMAGEMASK The application stores
 *        the image list index of the current state image for each item.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetCallbackMask(w,m) (BOOL)SNDMSG((w),LVM_SETCALLBACKMASK,m,0)
/**
 * This macro searches for a list view item that has the specified
 * properties and bears the specified relationship to a specified item. You
 * can use this macro or send the LVM_GETNEXTITEM message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iStart Index of the item with which to begin the search, or -1 to
 *        find the first item that matches the specified flags. The
 *        specified item itself is excluded from the search.
 * @param flags Geometric relation of the requested item to the specified
 *        item and, if specified, the state of the requested item. For a
 *        list of possible values, see the description of the flags
 *        parameter in the LVM_GETNEXTITEM message. If an item does not
 *        have all of the specified state flags set, the search continues
 *        with the next item.
 * @return The index of the next item indicates success. -1 indicates
 *        failure.
 */
#define ListView_GetNextItem(w,i,f) (int)SNDMSG((w),LVM_GETNEXTITEM,i,MAKELPARAM((f),0))
/**
 * This macro searches for a list view item with the specified
 * characteristics. You can use this macro or send the LVM_FINDITEM message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iStart Index of the item after which to begin the search, or -1
 *        to start from the beginning.
 * @param plvfi Pointer to an LVFINDINFO structure that contains
 *        information about what to search for.
 * @return The index of the item indicates success. -1 indicates failure.
 */
#define ListView_FindItem(w,i,p) (int)SNDMSG((w), LVM_FINDITEM,(WPARAM)i,(LPARAM)(const LV_FINDINFO*)(p))
/**
 * This macro retrieves the bounding rectangle for all or part of an item
 * in the current view. You can use this macro or send the LVM_GETITEMRECT
 * message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle. When the LVM_GETITEMRECT message is sent, the left
 *        member of this structure contains the value of the code
 *        parameter.
 * @param code Portion of the list view item for which to retrieve the
 *        bounding rectangle. It is one of the following values: Value
 *        Description LVIR_BOUNDS Returns the bounding rectangle of the
 *        entire item, including the icon and label. LVIR_ICON Returns the
 *        bounding rectangle of the icon or small icon. LVIR_LABEL Returns
 *        the bounding rectangle of the item text. LVIR_SELECTBOUNDS
 *        Returns the union of the LVIR_ICON and LVIR_LABEL rectangles, but
 *        excludes columns in details view.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_GetItemRect(w,i,p,c) (BOOL)SNDMSG((w),LVM_GETITEMRECT,i,((p)?(((LPRECT)(p))->left=(c),(LPARAM)(LPRECT)(p)):0))
/**
 * This macro moves an item to a specified position in a list view control,
 * which must be in icon or small icon view. You can use this macro or send
 * the LVM_SETITEMPOSITION message explicitly.
 *
 * If the list view control has the LVS_AUTOARRANGE style, the list view
 * control is arranged after the position of the item is set.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param x and y New position of the item's upper-left corner, in view
 *        coordinates.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetItemPosition(w,i,x,y) (BOOL)SNDMSG((w),LVM_SETITEMPOSITION,i,MAKELPARAM(x,y))
/**
 * This macro retrieves the position of a list view item. You can use this
 * macro or send the LVM_GETITEMPOSITION message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param ppt Pointer to a POINT structure that receives the position of
 *        the item's upper-left corner, in view coordinates.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_GetItemPosition(w,i,p) (BOOL)SNDMSG((w),LVM_GETITEMPOSITION,i,(LPARAM)p)
/**
 * This macro determines the spacing between items in a list view control.
 * You can use this macro or send the LVM_GETITEMSPACING message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param fSmall Boolean value that specifies the view for which to
 *        retrieve the item spacing. Set to TRUE for small icon view, or to
 *        FALSE for icon view.
 * @return Returns the amount of spacing between items.
 */
#define ListView_GetItemSpacing(w,f) (DWORD)SNDMSG((w),LVM_GETITEMSPACING,f,0)
/**
 * This macro determines the width of a specified string, using the
 * specified list view control's current font. You can use this macro or
 * send the LVM_GETSTRINGWIDTH message explicitly.
 *
 * The ListView_GetStringWidth macro returns the exact width, in pixels, of
 * the specified string. If you use the returned string width as the column
 * width in a call to the ListView_SetColumnWidth macro, the string will be
 * truncated. To get the column width that can contain the string without
 * truncating it, you must add padding to the returned string width.
 *
 * @param hwnd Handle to the list view control.
 * @param psz Pointer to a null-terminated string.
 * @return The string width indicates success. Zero indicates failure.
 */
#define ListView_GetStringWidth(w,s) (int)SNDMSG((w),LVM_GETSTRINGWIDTH,0,(LPARAM)s)
/**
 * This macro determines which list view item, if any, is at a specified
 * position. You can use this macro or send the LVM_HITTEST message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param pinfo Pointer to an LVHITTESTINFO structure that contains the
 *        position to hit test and receives information about the results
 *        of the hit test.
 * @return The index of the item at the specified position, if any,
 *        indicates success. -1 indicates failure.
 */
#define ListView_HitTest(w,p) (int)SNDMSG((w),LVM_HITTEST,0,(LPARAM)(LV_HITTESTINFO*)(p))
/**
 * This macro ensures that a list view item is either entirely or partially
 * visible, scrolling the list view control if necessary. You can use this
 * macro or send the LVM_ENSUREVISIBLE message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param fPartialOK Boolean value that specifies whether the item must be
 *        entirely visible. If set to TRUE, no scrolling occurs if the item
 *        is at least partially visible.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_EnsureVisible(w,i,f) (BOOL)SNDMSG((w),LVM_ENSUREVISIBLE,i,MAKELPARAM((f),0))
/**
 * This macro scrolls the content of a list view control. You can use this
 * macro or send the LVM_SCROLL message explicitly.
 *
 * When the list view control is in report view, the control can only be
 * scrolled vertically in whole line increments. Therefore, the dy
 * parameter will be rounded to the nearest number of pixels that form a
 * whole line increment. For example, if the height of a line is 16 pixels
 * and 8 is passed for dy, the list will be scrolled by 16 pixels (1 line).
 * If 7 is passed for dy, the list will be scrolled 0 pixels (0 lines).
 *
 * @param hwnd Handle to the list view control.
 * @param dx Specifies the amount of horizontal scrolling in pixels. If the
 *        list view control is in list view, this value specifies the
 *        number of columns to scroll.
 * @param dy Specifies the amount of vertical scrolling in pixels.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_Scroll(w,x,y) (BOOL)SNDMSG((w),LVM_SCROLL,x,y)
/**
 * This macro forces a list view control to redraw a range of items. You
 * can use this macro or send the LVM_REDRAWITEMS message explicitly.
 *
 * The specified items are not actually redrawn until the list view window
 * receives a WM_PAINT message to repaint. To repaint immediately, call the
 * UpdateWindow function after using this macro.
 *
 * @param hwnd Handle to the list view control.
 * @param iFirst Index of the first item to redraw.
 * @param iLast Index of the last item to redraw.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_RedrawItems(w,f,l) (BOOL)SNDMSG((w),LVM_REDRAWITEMS,f,l)
/**
 * This macro arranges items in icon view. You can use this macro or send
 * the LVM_ARRANGE message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param code Specifies alignment. It is one of the following values:
 *        Value Description LVA_ALIGNLEFT Aligns items along the left edge
 *        of the window. LVA_ALIGNTOP Aligns items along the top edge of
 *        the window. LVA_DEFAULT Aligns items according to the list view
 *        control's current alignment styles (the default value).
 *        LVA_SNAPTOGRID Snaps all icons to the nearest grid position.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_Arrange(w,c) (BOOL)SNDMSG((w),LVM_ARRANGE,c,0)
/**
 * This macro begins in-place editing of the specified list view item's
 * text. The message implicitly selects and focuses the specified item. You
 * can use this macro or send the LVM_EDITLABEL message explicitly.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but you should not destroy it.
 *
 * The control must have the focus before you send this message to the
 * control. Focus can be set using the SetFocus function.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem Index of the list view item. To cancel editing, set iItem
 *        to -1.
 * @return The handle to the edit control that is used to edit the item
 *        text indicates success. NULL indicates failure.
 */
#define ListView_EditLabel(w,i) (HWND)SNDMSG((w),LVM_EDITLABEL,i,0)
/**
 * This macro retrieves the handle to the edit control being used to edit a
 * list view item's text. You can use this macro or send the
 * LVM_GETEDITCONTROL message explicitly.
 *
 * If no label is being edited, the return value is NULL. The edit control
 * is not created until after the LVN_BEGINLABELEDIT notification message
 * is sent.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but you should not destroy it. To cancel editing, you can
 * send the list view control a WM_CANCELMODE message.
 *
 * The list view item being edited is the currently focused item-that is,
 * the item in the focused state. To find an item based on its state, use
 * the LVM_GETNEXTITEM message.
 *
 * @param hwnd Handle to the list view control.
 * @return The handle to the edit control indicates success. NULL indicates
 *        failure.
 */
#define ListView_GetEditControl(w) (HWND)SNDMSG((w),LVM_GETEDITCONTROL,0,0)
/**
 * This macro retrieves the attributes of a list view control's column. You
 * can use this macro or send the LVM_GETCOLUMN message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the column.
 * @param pcol Pointer to an LVCOLUMN structure that specifies the
 *        information to retrieve and receives information about the
 *        column. The mask member specifies which column attributes to
 *        retrieve. If the mask member specifies the LVCF_TEXT value, the
 *        pszText member must contain the address of the buffer that
 *        receives the item text, and the cchTextMax member must specify
 *        the size of the buffer.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_GetColumn(w,i,p) (BOOL)SNDMSG((w),LVM_GETCOLUMN,i,(LPARAM)(LV_COLUMN*)(p))
/**
 * This macro sets the attributes of a list view column. You can use this
 * macro or send the LVM_SETCOLUMN message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the column.
 * @param pcol Pointer to an LVCOLUMN structure that contains the new
 *        column attributes. The mask member specifies which column
 *        attributes to set. If the mask member specifies the LVCF_TEXT
 *        value, the pszText member is the address of a null-terminated
 *        string and the cchTextMax member is ignored.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetColumn(w,i,p) (BOOL)SNDMSG((w),LVM_SETCOLUMN,i,(LPARAM)(const LV_COLUMN*)(p))
/**
 * This macro inserts a new column in a list view control. You can use this
 * macro or send the LVM_INSERTCOLUMN message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the new column.
 * @param pcol Pointer to an LVCOLUMN structure that contains the
 *        attributes of the new column.
 * @return The index of the new column indicates success. -1 indicates
 *        failure.
 */
#define ListView_InsertColumn(w,i,p) (int)SNDMSG((w),LVM_INSERTCOLUMN,i,(LPARAM)(const LV_COLUMN*)(p))
/**
 * This macro removes a column from a list view control. You can use this
 * macro or send the LVM_DELETECOLUMN message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the column to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_DeleteColumn(w,i) (BOOL)SNDMSG((w),LVM_DELETECOLUMN,i,0)
/**
 * This macro retrieves the width of a column in report or list view. You
 * can use this macro or send the LVM_GETCOLUMNWIDTH message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the column. This parameter is ignored in list view.
 * @return The column width indicates success. Zero indicates failure. If
 *        this macro is used on a list view control with the LVS_REPORT
 *        style and the specified column does not exist, the return value
 *        is undefined.
 */
#define ListView_GetColumnWidth(w,i) (int)SNDMSG((w),LVM_GETCOLUMNWIDTH,i,0)
/**
 * This macro changes the width of a column in report or list view. You can
 * use this macro or send the LVM_SETCOLUMNWIDTH message explicitly.
 *
 * ListView_SetColumnWidth converts the cx parameter to a 16-bit value.
 *
 * @param hwnd Handle to the list view control.
 * @param iCol Index of the column. In list view, the iCol parameter must
 *        be -1.
 * @param cx New width of the column, in list view coordinates, or one of
 *        the following values: Value Description LVSCW_AUTOSIZE
 *        Automatically sizes the column. LVSCW_AUTOSIZE_USEHEADER
 *        Automatically sizes the column to fit the header text.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetColumnWidth(w,i,x) (BOOL)SNDMSG((w),LVM_SETCOLUMNWIDTH,i,MAKELPARAM((x),0))
/**
 * This macro creates a drag image list for the specified item. You can use
 * this macro or send the LVM_CREATEDRAGIMAGE message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem Index of the item.
 * @param lpptUpLeft Long pointer to a POINT structure that receives the
 *        initial location of the upper-left corner of the image, in view
 *        coordinates.
 * @return The handle to the drag image list indicates success. NULL
 *        indicates failure.
 */
#define ListView_CreateDragImage(w,i,p) (HIMAGELIST)SNDMSG((w),LVM_CREATEDRAGIMAGE,i,(LPARAM)(LPPOINT)(p))
/**
 * This macro retrieves the bounding rectangle of all items in the list
 * view control. The list view must be in icon or small icon view. You can
 * use this macro or send the LVM_GETVIEWRECT message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle. All coordinates are relative to the visible area of
 *        the list view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_GetViewRect(w,p) (BOOL)SNDMSG((w),LVM_GETVIEWRECT,0,(LPARAM)(LPRECT)(p))
/**
 * This macro retrieves the text color of a list view control. You can use
 * this macro or send the LVM_GETTEXTCOLOR message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the text color.
 */
#define ListView_GetTextColor(w) (COLORREF)SNDMSG((w),LVM_GETTEXTCOLOR,0,0)
/**
 * This macro sets the text color of a list view control. You can use this
 * macro or send the LVM_SETTEXTCOLOR message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param clrText New text color.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetTextColor(w,c) (BOOL)SNDMSG((w),LVM_SETTEXTCOLOR,0,(LPARAM)(COLORREF)(c))
/**
 * This macro retrieves the text background color of a list view control.
 * You can use this macro or send the LVM_GETTEXTBKCOLOR message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the background color of the text.
 */
#define ListView_GetTextBkColor(w) (COLORREF)SNDMSG((w),LVM_GETTEXTBKCOLOR,0,0)
/**
 * This macro sets the background color of text in a list view control. You
 * can use this macro or send the LVM_SETTEXTBKCOLOR message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param clrText New text color.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetTextBkColor(w,c) (BOOL)SNDMSG((w),LVM_SETTEXTBKCOLOR,0,(LPARAM)(COLORREF)(c))
/**
 * This macro retrieves the index of the topmost visible item when in list
 * or report view. You can use this macro or send the LVM_GETTOPINDEX
 * message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return The index of the item indicates success. Zero indicates that the
 *        list view control is in icon or small icon view.
 */
#define ListView_GetTopIndex(w) (int)SNDMSG((w),LVM_GETTOPINDEX,0,0)
/**
 * This macro calculates the number of items that can fit vertically in the
 * visible area of a list view control when in list or report view. Only
 * fully visible items are counted. You can use this macro or send the
 * LVM_GETCOUNTPERPAGE message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return The number of fully visible items indicates success. The total
 *        number of items in the list view control indicates that the
 *        current view is icon or small icon view.
 */
#define ListView_GetCountPerPage(w) (int)SNDMSG((w),LVM_GETCOUNTPERPAGE,0,0)
/**
 * This macro retrieves the current view origin for a list view control.
 * You can use this macro or send the LVM_GETORIGIN message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param lpptOrg Long pointer to a POINT structure that receives the view
 *        origin.
 * @return TRUE indicates success. FALSE indicates that the current view is
 *        list or report view.
 */
#define ListView_GetOrigin(w,p) (BOOL)SNDMSG((w),LVM_GETORIGIN,0,(LPARAM)(POINT*)(p))
#define ListView_GetOrigin(w,p) (BOOL)SNDMSG((w),LVM_GETORIGIN,0,(LPARAM)(POINT*)(p))
/**
 * This macro updates a list view item. If the list view control has the
 * LVS_AUTOARRANGE style, this macro causes the list view control to be
 * arranged. You can use this macro or send the LVM_UPDATE message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_Update(w,i) (BOOL)SNDMSG((w),LVM_UPDATE,(WPARAM)(i),0)
/**
 * This macro changes the state of an item in a list view control. You can
 * use this macro or send the LVM_SETITEMSTATE message explicitly.
 *
 * An item's state value includes a set of bit flags that indicate the
 * item's state. The state value can also include image list indexes that
 * indicate the item's state image and overlay image.
 *
 * The mask parameter specifies the state bits you want to modify, and the
 * state parameter specifies the new value for those bits. To set a bit in
 * the item's internal state, set it in both the mask and state parameters.
 * To clear a bit in the item's internal state, set it in the mask
 * parameter and clear it in the state parameter. To leave a bit unchanged
 * in the item's internal state, clear it in the mask parameter.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item. If this parameter is -1, then the
 *        state change is applied to all items.
 * @param state New state bits for the item. The mask parameter indicates
 *        the valid bits of the state parameter. The macro ignores bits in
 *        the state parameter if the corresponding bit is not set in the
 *        mask parameter. The low-order byte contains a set of bit flags
 *        that indicate the item's state. This byte can be a combination of
 *        the following values: Value Description LVIS_CUT The item is
 *        marked for a cut-and-paste operation. LVIS_DROPHILITED The item
 *        is highlighted as a drag-and-drop target. LVIS_FOCUSED The item
 *        has the focus, so it is surrounded by a standard focus rectangle.
 *        Although more than one item may be selected, only one item can
 *        have the focus. LVIS_SELECTED The item is selected. The
 *        appearance of a selected item depends on whether it has the focus
 *        and also on the system colors used for selection. Bits 8 through
 *        11 of the state parameter specify the one-based index of an
 *        overlay image in the control's image lists. Both the full-sized
 *        icon image list and the small icon image list can have overlay
 *        images. The overlay image is superimposed over the item's icon
 *        image. If these bits are zero, the item has no overlay image. To
 *        isolate these bits, use the LVIS_OVERLAYMASK mask. To specify an
 *        overlay index, use the INDEXTOOVERLAYMASK macro. Bits 12 through
 *        15 of the state parameter specify the one-based index of an image
 *        in the control's state image list. The state image is displayed
 *        next to an item's icon to indicate an application-defined state.
 *        If these bits are zero, the item has no state image. To isolate
 *        these bits, use the LVIS_STATEIMAGEMASK mask. To specify a state
 *        image index, use the INDEXTOSTATEIMAGEMASK macro.
 * @param mask Bits of the state parameter that you want to set or clear.
 *        You can use ListView_SetItemState both to set and to clear bits.
 *        To set an item's overlay image index, set the LVIS_OVERLAYMASK
 *        bits. To set an item's state image index, set the
 *        LVIS_STATEIMAGEMASK bits.
 * @return None.
 */
#define ListView_SetItemState(w,i,d,m) \
{ \
	LV_ITEM _lvi;\
	_lvi.stateMask=m;\
	_lvi.state=d;\
	SNDMSG((w),LVM_SETITEMSTATE,i,(LPARAM)(LV_ITEM*)&_lvi);\
}
/**
 * This macro retrieves the state of a list view item. You can use this
 * macro or send the LVM_GETITEMSTATE message explicitly.
 *
 * An item's state information includes a set of bit flags as well as image
 * list indexes that indicate the item's state image and overlay image.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param mask State information to retrieve. It can be a combination of
 *        the following values: Value Description LVIS_CUT The item is
 *        marked for a cut-and-paste operation. LVIS_DROPHILITED The item
 *        is highlighted as a drag-and-drop target. LVIS_FOCUSED The item
 *        has the focus, so it is surrounded by a standard focus rectangle.
 *        Although more than one item may be selected, only one item can
 *        have the focus. LVIS_SELECTED The item is selected. The
 *        appearance of a selected item depends on whether it has the focus
 *        and also on the system colors used for selection.
 *        LVIS_OVERLAYMASK Use this mask to retrieve the item's overlay
 *        image index. LVIS_STATEIMAGEMASK Use this mask to retrieve the
 *        item's state image index.
 * @return Returns the current state for the specified item. The only valid
 *        bits in the return value are those that correspond to the bits
 *        set in the mask parameter.
 */
#define ListView_GetItemState(w,i,m) (UINT)SNDMSG((w),LVM_GETITEMSTATE,i,m)
/**
 * This macro retrieves the text of a list view item or subitem. You can
 * use this macro or send the LVM_GETITEMTEXT message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem Index of the list view item.
 * @param iSubItem Index of the subitem, or zero to retrieve the item
 *        label.
 * @param pszText Pointer to the buffer that receives the item or subitem
 *        text.
 * @param cchTextMax Size of the buffer, in bytes.
 * @return The ListView_GetItemText macro does not return a value. If you
 *        send the LVM_GETITEMNEXT message explicitly, it returns the
 *        length of the retrieved string.
 */
#define ListView_GetItemText(w,i,iS,s,n) \
{ \
	LV_ITEM _lvi;\
	_lvi.iSubItem=iS;\
	_lvi.cchTextMax=n;\
	_lvi.pszText=s;\
	SNDMSG((w),LVM_GETITEMTEXT,i,(LPARAM)(LV_ITEM*)&_lvi);\
}
/**
 * This macro changes the text of a list view item or subitem. You can use
 * this macro or send the LVM_SETITEMTEXT message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param i Index of the list view item.
 * @param iSubItem Index of the subitem. To set the item label, set
 *        iSubItem to zero.
 * @param pszText Pointer to a null-terminated string that contains the new
 *        text. This parameter can be LPSTR_TEXTCALLBACK to indicate a
 *        callback item for which the parent window stores the text. In
 *        this case, the list view control sends the parent an
 *        LVN_GETDISPINFO notification message when it needs the text. This
 *        parameter can be NULL.
 * @return None.
 */
#define ListView_SetItemText(w,i,iS,s) \
{ \
	LV_ITEM _lvi;\
	_lvi.iSubItem=iS;\
	_lvi.pszText=s;\
	SNDMSG((w),LVM_SETITEMTEXT,i,(LPARAM)(LV_ITEM*)&_lvi);\
}
/**
 * This macro prepares a list view control for adding a large number of
 * items. You can use this macro or send the LVM_SETITEMCOUNT message
 * explicitly.
 *
 * If the list view control was created without the LVS_OWNERDATA style,
 * this macro causes the control to allocate its internal data structures
 * for the specified number of items. This prevents the control from having
 * to allocate the data structures every time an item is added.
 *
 * If the list view control was created with the LVS_OWNERDATA style , the
 * ListView_SetItemCountEx macro should be used.
 *
 * In Windows CE versions 2.0 and later, if the list view control is a
 * virtual list view (has the LVS_OWNERDATA style), use the
 * ListView_SetItemCountEx macro instead.
 *
 * @param hwndLV Handle to a list view control.
 * @param cItems Number of items for which the list view control should
 *        allocate memory.
 * @return None.
 */
#define ListView_SetItemCount(w,n) (void)SNDMSG((w),LVM_SETITEMCOUNT,n,0)
/**
 * This macro uses an application-defined comparison function to sort the
 * items of a list view control. The index of each item changes to reflect
 * the new sequence. You can use this macro or send the LVM_SORTITEMS
 * message explicitly.
 *
 * The comparison function has the following form:
 *
 *     int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2,
 *         LPARAM lParamSort);
 *
 * The lParam1 parameter is the 32-bit value associated with the first item
 * being compared; and the lParam2 parameter is the value associated with
 * the second item. These are the values that were specified in the lParam
 * member of the items' LVITEM structure when they were inserted into the
 * list. The lParamSort parameter is the same value passed to the
 * LVM_SORTITEMS message.
 *
 * The comparison function must return a negative value if the first item
 * should precede the second, a positive value if the first item should
 * follow the second, or zero if the two items are equivalent.
 *
 * @param hwnd Handle to the list view control.
 * @param pfnCompare Pointer to the application-defined comparison
 *        function. The comparison function is called during the sort
 *        operation each time the relative order of two list items needs to
 *        be compared.
 * @param lParamSort Application-defined value that is passed to the
 *        comparison function.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SortItems(w,f,l) (BOOL)SNDMSG((w),LVM_SORTITEMS,l,(LPARAM)f)
/**
 * This macro moves an item to a specified position in a list view control,
 * which must be in icon or small icon view. This macro differs from the
 * ListView_SetItemPosition macro in that it uses 32-bit coordinates. You
 * can use this macro or send the LVM_SETITEMPOSITION32 message explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @param iItem Index of the list view item for which to set the position.
 * @param x and y New horizontal and vertical coordinates of the item.
 * @return None.
 */
#define ListView_SetItemPosition32(w,i,x,y) \
{ \
	POINT p={x,y}; \
	SNDMSG((w),LVM_SETITEMPOSITION32,i,(LPARAM)&p);\
}
/**
 * This macro determines the number of selected items in a list view
 * control. You can use this macro or send the LVM_GETSELECTEDCOUNT message
 * explicitly.
 *
 * @param hwnd Handle to the list view control.
 * @return Returns the number of selected items.
 */
#define ListView_GetSelectedCount(w) (UINT)SNDMSG((w),LVM_GETSELECTEDCOUNT,0,0)
/**
 * This macro determines if an item in a list view control is selected.
 * This should be used only for list view controls that have the
 * LVS_EX_CHECKBOXES style.
 *
 * @param hwndLV Handle to a list view control.
 * @param iIndex Index of the item for which to retrieve the check state.
 * @return Returns nonzero if the specified item is selected, or zero
 *        otherwise. If this macro is applied to a list view control that
 *        does not have check boxes enabled, the return value is not
 *        reliable.
 */
#define ListView_GetCheckState(w,i) ((((UINT)(SNDMSG((w),LVM_GETITEMSTATE,(WPARAM)(i),LVIS_STATEIMAGEMASK)))>>12)-1)
#define ListView_SetCheckState(w,i,f) ListView_SetItemState(w,i,INDEXTOSTATEIMAGEMASK((f)+1),LVIS_STATEIMAGEMASK)
/**
 * This macro retrieves the incremental search string of a list-view
 * control. You can use this macro or send the LVM_GETISEARCHSTRING message
 * explicitly.
 *
 * The incremental search string is the character sequence that the user
 * types while the list view has the input focus. Each time the user types
 * a character, the system appends the character to the search string and
 * then searches for a matching item. If the system finds a match, it
 * selects the item and, if necessary, scrolls it into view.
 *
 * A time-out period is associated with each character that the user types.
 * If the time-out period elapses before the user types another character,
 * the incremental search string is reset.
 *
 * @param hwnd Handle to the list view control.
 * @param lpsz Long pointer to a buffer that receives the incremental
 *        search string.
 * @return Returns the number of characters in the incremental search
 *        string, or zero if the list view control is not in incremental
 *        search mode.
 */
#define ListView_GetISearchString(w,lpsz) (BOOL)SNDMSG((w),LVM_GETISEARCHSTRING,0,(LPARAM)(LPTSTR)(lpsz)) 
#define ListView_CancelEditLabel(w) (VOID)SNDMSG((w),LVM_CANCELEDITLABEL,0,0)
#define ListView_EnableGroupView(w,i) (int)SNDMSG((w),LVM_ENABLEGROUPVIEW,(WPARAM)(i),0)
#define ListView_GetGroupInfo(w,i,p) (int)SNDMSG((w),LVM_GETGROUPINFO,(WPARAM)(i),(LPARAM)(p))
#define ListView_GetGroupMetrics(w,p) SNDMSG((w),LVM_GETGROUPMETRICS,0,(LPARAM)(p))
#define ListView_GetInsertMark(w,p) (BOOL)SNDMSG((w),LVM_GETINSERTMARK,0,(LPARAM)(p))
#define ListView_GetInsertMarkColor(w) (COLORREF)SNDMSG((w),LVM_GETINSERTMARKCOLOR,0,0)
#define ListView_GetInsertMarkRect(w,p) (int)SNDMSG((w),LVM_GETINSERTMARKRECT,0,(LPARAM)(p))
#define ListView_GetOutlineColor(w) (COLORREF)SNDMSG((w),LVM_GETOUTLINECOLOR,0,0)
#define ListView_GetSelectedColumn(w) (UINT)SNDMSG((w),LVM_GETSELECTEDCOLUMN,0,0)
#define ListView_GetTileInfo(w,p) SNDMSG((w),LVM_GETTILEINFO,0,(LPARAM)(p))
#define ListView_GetTileViewInfo(w,p) SNDMSG((w),LVM_GETTILEVIEWINFO,0,(LPARAM)(p))
#define ListView_GetView(w) (DWORD)SNDMSG((w),LVM_GETVIEW,0,0)
#define ListView_HasGroup(w,i) (BOOL)SNDMSG((w),LVM_HASGROUP,(WPARAM)(i),0)
#define ListView_InsertGroup(w,i,p) (int)SNDMSG((w),LVM_INSERTGROUP,(WPARAM)(i),(LPARAM)(p))
#define ListView_InsertGroupSorted(w,p) SNDMSG((w),LVM_INSERTGROUPSORTED,(WPARAM)(p),0)
#define ListView_InsertMarkHitTest(w,p,t) (BOOL)SNDMSG((w),LVM_INSERTMARKHITTEST,(WPARAM)(p),(LPARAM)(t))
#define ListView_IsGroupViewEnabled(w) (BOOL)SNDMSG((w),LVM_ISGROUPVIEWENABLED,0,0)
#define ListView_MapIDToIndex(w,i) (UINT)SNDMSG((w),LVM_MAPIDTOINDEX,(WPARAM)(i),0)
#define ListView_MoveGroup(w,i,t) SNDMSG((w),LVM_MOVEGROUP,(WPARAM)(i),(LPARAM)(t))
#define ListView_RemoveAllGroups(w) SNDMSG((w),LVM_REMOVEALLGROUPS,0,0)
#define ListView_RemoveGroup(w,i) (int)SNDMSG((w),LVM_REMOVEGROUP,(WPARAM)(i),0)
#define ListView_SetGroupInfo(w,i,p) (int)SNDMSG((w),LVM_SETGROUPINFO,(WPARAM)(i),(LPARAM)(p))
#define ListView_SetGroupMetrics(w,p) SNDMSG((w),LVM_SETGROUPMETRICS,0,(LPARAM)(p))
#define ListView_SetInfoTip(w,p) (BOOL)SNDMSG((w),LVM_SETINFOTIP,0,(LPARAM)(p))
#define ListView_SetInsertMark(w,p) (BOOL)SNDMSG((w),LVM_SETINSERTMARK,0,(LPARAM)(p))
#define ListView_SetInsertMarkColor(w,c) (COLORREF)SNDMSG((w),LVM_SETINSERTMARKCOLOR,0,(LPARAM)(c))
#define ListView_SetOutlineColor(w,c) (COLORREF)SNDMSG((w),LVM_SETOUTLINECOLOR,0,(LPARAM)(c))
#if (_WIN32_WINNT >= 0x0501)
#define ListView_SetSelectedColumn(w,i) SNDMSG((w),LVM_SETSELECTEDCOLUMN,(WPARAM)i,0)
#endif
#define ListView_SetTileInfo(w,p) (BOOL)SNDMSG((w),LVM_SETTILEINFO,0,(LPARAM)(p))
#define ListView_SetTileViewInfo(w,p) (BOOL)SNDMSG((w),LVM_SETTILEVIEWINFO,0,(LPARAM)(p))
#define ListView_SetView(w,i) (int)SNDMSG((w),LVM_SETVIEW,(WPARAM)(i),0)
#define ListView_SortGroups(w,c,p) (int)SNDMSG((w),LVM_SORTGROUPS,(WPARAM)(c),(LPARAM)(p))
#define ListView_SortItemsEx(w,c,p) (BOOL)SNDMSG((w),LVM_SORTITEMSEX,(WPARAM)(p),(LPARAM)(c))

#if (_WIN32_WINNT >= 0x0501)
#define ComboBox_SetMinVisible(w,i) (BOOL)SNDMSG((w), CB_SETMINVISIBLE,(WPARAM)(i),0);
#define ComboBox_GetMinVisible(w) (INT)SNDMSG((w),CB_GETMINVISIBLE,0,0);
#endif

BOOL WINAPI MakeDragList(HWND);
void WINAPI MenuHelp(UINT,WPARAM,LPARAM,HMENU,HINSTANCE,HWND,PUINT);
/**
 * This macro retrieves the color for a specified portion of a month
 * calendar control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iColor INT value that specifies which month calendar color to
 *        retrieve. It is one of the following values: Value Description
 *        MCSC_BACKGROUND Retrieves the background color displayed between
 *        months. MCSC_MONTHBK Retrieves the background color displayed
 *        within the month. MCSC_TEXT Retrieves the color used to display
 *        text within a month. MCSC_TITLEBK Retrieves the background color
 *        displayed in the calendar's title. MCSC_TITLETEXT Retrieves the
 *        color used to display text within the calendar's title.
 *        MCSC_TRAILINGTEXT Retrieves the color used to display header and
 *        trailing-day text. Header and trailing days are the days from the
 *        previous and following months that appear on the current
 *        calendar.
 * @return Upon success, this macro returns a COLORREF value that
 *        represents the color setting for the specified portion of the
 *        month calendar control. The macro returns -1 upon failure.
 */
#define MonthCal_GetColor(hwnd,icolor) SNDMSG(hwnd,MCM_GETCOLOR,(WPARAM)icolor,(LPARAM)0)
/**
 * This macro retrieves the system time portrayed by the currently selected
 * date.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that will
 *        receive the system time information.
 * @return Nonzero indicates success. Zero indicates otherwise. This macro
 *        will always fail when applied to month calendar controls that are
 *        set to the MCS_MULTISELECT style.
 */
#define MonthCal_GetCurSel(hwnd,lpsystime) SNDMSG(hwnd,MCM_GETCURSEL,0,(LPARAM)lpsystime)
/**
 * This macro retrieves the first day of the week for a month calendar
 * control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @return Returns a DWORD value that contains two values. The high-order
 *        word is a BOOL that is nonzero if the first day of the week is
 *        set to something other than LOCALE_IFIRSTDAYOFWEEK, or zero
 *        otherwise. The low-order word is an INT value that represents the
 *        first day of the week. The low-order word will be one of the
 *        values shown in the following table. Value Day 0 Monday 1 Tuesday
 *        2 Wednesday 3 Thursday 4 Friday 5 Saturday 6 Sunday
 */
#define MonthCal_GetFirstDayOfWeek(hwnd) SNDMSG(hwnd,MCM_GETFIRSTDAYOFWEEK,0,0)
/**
 * This macro retrieves the maximum selectable date range that is set for a
 * month calendar control. You can use this macro or send the
 * MCM_GETMAXSELCOUNT message explicitly.
 *
 * @param hwndMC Handle to a month calendar control.
 * @return You can change the selectable date range using the
 *        MCM_SETMAXSELCOUNT message. Returns an INT value that represents
 *        the total number of days that can be selected for the control.
 */
#define MonthCal_GetMaxSelCount(hwnd) SNDMSG(hwnd,MCM_GETMAXSELCOUNT,0,0)
/**
 * This macro retrieves the maximum width of the "Today" string in a month
 * calendar control. This includes the label text and the date text.
 *
 * @param hwndMC Handle to a month calendar control.
 * @return Returns the width of the "Today" string, in pixels.
 */
#define MonthCal_GetMaxTodayWidth(hwnd) SNDMSG(hwnd,MCM_GETMAXTODAYWIDTH,0,0)
/**
 * This macro retrieves the minimum size required to display a full month
 * in a month calendar control. Size information is presented in the form
 * of a RECT structure.
 *
 * The top and left members of the RECT structure specified by lpRectInfo
 * will always be zero. The right and i members represent the minimum cx
 * and cy required for the control.
 *
 * The minimum required window size for a month calendar control depends on
 * the currently selected font.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lpRectInfo Long pointer to a RECT structure that will receive
 *        bounding rectangle information.
 * @return Returns nonzero and lpRectInfo receives the applicable bounding
 *        information if successful. Otherwise, the macro returns zero.
 */
#define MonthCal_GetMinReqRect(hwnd,lpRectInfo) SNDMSG(hwnd,MCM_GETMINREQRECT,0,(LPARAM)lpRectInfo)
/**
 * This macro retrieves the "scroll rate" for a month calendar control. The
 * scroll rate is the number of months that the control moves its display
 * when the user clicks a scroll button.
 *
 * @param hwndMC Handle to a month calendar control.
 * @return If the month delta was previously set using the
 *        MonthCal_SetMonthDelta macro, returns an INT value that
 *        represents the month calendar's current scroll rate. If the month
 *        delta was not previously set using the MonthCal_SetMonthDelta
 *        macro or the month delta was reset to the default, returns an INT
 *        value that represents the current number of months visible.
 */
#define MonthCal_GetMonthDelta(hwnd) SNDMSG(hwnd,MCM_GETMONTHDELTA,0,0)
/**
 * This macro retrieves date information (using SYSTEMTIME structures) that
 * represents the high and low limits of a month calendar control's
 * display.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param dwFlag Specifies the scope of the range limits to be retrieved.
 *        It is one of the following values: Value Description GMR_DAYSTATE
 *        Include preceding and trailing months of visible range that are
 *        only partially displayed. GMR_VISIBLE Include only those months
 *        that are entirely displayed.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that will receive the lower and upper
 *        limits of the scope specified by dwFlag. The lower and upper
 *        limits are placed in lprgSysTimeArray[0] and lprgSysTimeArray[1],
 *        respectively. The time members of these structure are not
 *        modified.
 * @return Returns an INT that represents the range, in months, spanned by
 *        the two limits returned at lprgSysTimeArray.
 */
#define MonthCal_GetMonthRange(hwnd,flag,systimearray) SNDMSG(hwnd,MCM_GETMONTHRANGE,(WPARAM)flag,(LPARAM)systimearray)
/**
 * This macro retrieves the minimum and maximum allowable dates set for a
 * month calendar control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that will receive the date limit
 *        information. The minimum limit is set in lprgSysTimeArray[0], and
 *        lprgSysTimeArray[1] receives the maximum limit. If either element
 *        is set to all zeros, then no corresponding limit is set for the
 *        month calendar control. The time members of these structures are
 *        not modified.
 * @return Returns a DWORD that can be zero (no limits are set) or a
 *        combination of the following values that specify limit
 *        information: GDTR_MAX: There is a maximum limit set for the
 *        control; lprgSysTimeArray[0] is valid and contains the applicable
 *        date information. GDTR_MIN: There is a minimum limit set for the
 *        control; lprgSysTimeArray[1] is valid and contains the applicable
 *        date information.
 */
#define MonthCal_GetRange(hwnd,systimearray) SNDMSG(hwnd,MCM_GETRANGE,0,(LPARAM)systimearray)
/**
 * This macro retrieves date information that represents the upper and
 * lower limits of the date range currently selected by the user.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that will receive the lower and upper
 *        limits of the user's selection. The lower and upper limits are
 *        placed in lprgSysTimeArray[0] and lprgSysTimeArray[1],
 *        respectively. The time members of these structures will not be
 *        modified.
 * @return Nonzero indicates success. Zero indicates otherwise.
 *        MonthCal_GetSelRange will fail if applied to a month calendar
 *        control that does not use the MCS_MULTISELECT style.
 */
#define MonthCal_GetSelRange(hwnd,systimearray) SNDMSG(hwnd,MCM_GETSELRANGE,0,(LPARAM)systimearray)
/**
 * This macro retrieves the date information for the date specified as
 * "today" for a month calendar control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lpToday Long pointer to a SYSTEMTIME structure that will receive
 *        the date information.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define MonthCal_GetToday(hwnd,systime) SNDMSG(hwnd,MCM_GETTODAY,0,(LPARAM)systime)
#define MonthCal_GetUnicodeFormat(hwnd) SNDMSG(hwnd,MCM_GETUNICODEFORMAT,0,0)
/**
 * This macro determines which portion of a month calendar control is at a
 * specified point on the screen.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param pMCHitTest Pointer to an MCHITTESTINFO structure. Upon sending
 *        the macro, the cbSize member must equal sizeof(MCHITTESTINFO),
 *        and pt must be set to the point you want to hit test.
 * @return Sets values in members of the MCHITTESTINFO structure at
 *        pMCHitTest and returns one of the following DWORD values:
 *        MCHT_CALENDARBK: The specified point was in the calendar's
 *        background. MCHT_CALENDARDATE: The specified point was on a
 *        particular date within the calendar. The SYSTEMTIME structure at
 *        lpMCHitTest->st is set to the date at the specified point.
 *        MCHT_CALENDARDATENEXT: The specified point was over a date from
 *        the next month (partially displayed at the end of the currently
 *        displayed month). If the user clicks here, the month calendar
 *        will scroll its display to the next month or set of months.
 *        MCHT_CALENDARDATEPREV: The specified point was over a date from
 *        the previous month (partially displayed at the end of the
 *        currently displayed month). If the user clicks here, the month
 *        calendar will scroll its display to the previous month or set of
 *        months. MCHT_CALENDARDAY: The specified point was over a day
 *        abbreviation ("Fri"). The SYSTEMTIME structure at lpMCHitTest->st
 *        is set to the corresponding date in the top row.
 *        MCHT_CALENDARWEEKNUM: The specified point was over a week number
 *        (the MCS_WEEKNUMBERS style only). The SYSTEMTIME structure at
 *        lpMCHitTest->st is set to the corresponding date in the leftmost
 *        column. MCHT_NOWHERE: The specified point was either not on the
 *        month calendar control, or in an inactive portion of the control.
 *        MCHT_TITLEBK: The specified point was over the background of a
 *        month's title. MCHT_TITLEBTNNEXT: The specified point was over
 *        the button at the top right corner of the control. If the user
 *        clicks here, the month calendar will scroll its display to the
 *        next month or set of months. MCHT_TITLEBTNPREV: The specified
 *        point was over the button at the top left corner of the control.
 *        If the user clicks here, the month calendar will scroll its
 *        display to the previous month or set of months. MCHT_TITLEMONTH:
 *        The specified point was in a month's title bar, over a month
 *        name. MCHT_TITLEYEAR: The specified point was in a month's title
 *        bar, over the year value. The uHit member of the MCHITTESTINFO
 *        structure at pMCHitTest will equal the return value.
 */
#define MonthCal_HitTest(hwnd,pmchittest) SNDMSG(hwnd,MCM_HITTEST,0,(LPARAM)pmchittest)
/**
 * This macro sets the color for a specified portion of a month calendar
 * control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iColor INT value that specifies which month calendar color to
 *        set. It is one of the following values: Value Description
 *        MCSC_BACKGROUND Retrieves the background color displayed between
 *        months. MCSC_MONTHBK Retrieves the background color displayed
 *        within the month. MCSC_TEXT Retrieves the color used to display
 *        text within a month. MCSC_TITLEBK Retrieves the background color
 *        displayed in the calendar's title. MCSC_TITLETEXT Retrieves the
 *        color used to display text within the calendar's title.
 *        MCSC_TRAILINGTEXT Retrieves the color used to display header and
 *        trailing-day text. Header and trailing days are the days from the
 *        previous and following months that appear on the current
 *        calendar.
 * @param clr COLORREF value that represents the color that will be set for
 *        the specified area of the month calendar.
 * @return Returns a COLORREF value that represents the previous color
 *        setting for the specified portion of the month calendar control
 *        if successful. Otherwise, this macro returns -1.
 */
#define MonthCal_SetColor(hwnd,icolor,clr) SNDMSG(hwnd,MCM_SETCOLOR,(WPARAM)icolor,(LPARAM)clr)
/**
 * This macro sets the currently selected date for a month calendar
 * control. If the specified date is not in view, the control updates the
 * display to bring it into view.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the date to be set as the current selection. The time members of
 *        this structure are ignored.
 * @return Nonzero indicates success. Zero indicates otherwise. This macro
 *        will fail if applied to a month calendar control that uses the
 *        MCS_MULTISELECT style.
 */
#define MonthCal_SetCurSel(hwnd,lpsystime) SNDMSG(hwnd,MCM_SETCURSEL,0,(LPARAM)lpsystime)
/**
 * This macro sets the display for days in all months that are currently
 * visible within a month calendar control.
 *
 * The array at lpDayStateArray must contain as many elements as the value
 * returned by the following macro:
 *
 * MonthCal_GetMonthRange(hwndMC, GMR_DAYSTATE, NULL);
 *
 * The preceding macro returns the total number of months that are in
 * complete or partial view within the month calendar's display.
 *
 * Keep in mind that the array at lpDayStateArray must contain
 * MONTHDAYSTATE values that correspond with all months currently in the
 * control's display, in chronological order. This includes the two months
 * only partially displayed before the first month and after the last
 * month.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iMonths INT value that indicates how many elements are in the
 *        array that lpDayStateArray points to.
 * @param lpDayStateArray Long pointer to an array of MONTHDAYSTATE values
 *        that define how the month calendar control will draw each day in
 *        its display.
 * @return Nonzero if successful. If the macro fails, it returns zero.
 */
#define MonthCal_SetDayState(hwnd,imonths,lpdatestatearray) SNDMSG(hwnd,MCM_SETDAYSTATE,(WPARAM)imonths,(LPARAM)lpdatestatearray)
/**
 * This macro sets the first day of the week for a month calendar control.
 *
 * If the first day of the week is set to anything other than the default
 * (LOCALE_IFIRSTDAYOFWEEK), the control will not automatically update
 * first-day-of-the-week changes based on locale changes.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iDay INT value that specified which day is to be set as the first
 *        day of the week. It is one of the following values: Value Day 0
 *        Monday 1 Tuesday 2 Wednesday 3 Thursday 4 Friday 5 Saturday 6
 *        Sunday
 * @return Returns a DWORD value that contains two values. The high-order
 *        word is a BOOL that is nonzero if the previous first day of the
 *        week did not equal LOCALE_IFIRSTDAYOFWEEK, or zero otherwise. The
 *        low-order word is an INT value that represents the previous
 *        day-of-the-week number (see list under iDay).
 */
#define MonthCal_SetFirstDayOfWeek(hwnd,iday) SNDMSG(hwnd,MCM_SETFIRSTDAYOFWEEK,0,(LPARAM)iday)
/**
 * This macro sets the maximum number of days that can be selected in a
 * month calendar control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iMax INT value that will be set to represent the maximum number
 *        of selectable days.
 * @return Nonzero indicates success. Zero indicates otherwise. This macro
 *        will fail if applied to a month calendar control that does not
 *        use the MCS_MULTISELECT style.
 */
#define MonthCal_SetMaxSelCount(hwnd,imax) SNDMSG(hwnd,MCM_SETMAXSELCOUNT,(WPARAM)imax,0)
/**
 * This macro sets the "scroll rate" for a month calendar control. The
 * scroll rate is the number of months that a month calendar control moves
 * its display when the user clicks a scroll button.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param iDelta Value representing the number of months to be set as the
 *        control's scroll rate. If this value is zero, the month delta is
 *        reset to the default, which is the number of months displayed in
 *        the control.
 * @return Returns an INT value that represents the previous scroll rate.
 *        If the scroll rate has not been previously set, the return value
 *        is zero.
 */
#define MonthCal_SetMonthDelta(hwnd,idelta) SNDMSG(hwnd,MCM_SETMONTHDELTA,(WPARAM)idelta,0)
/**
 * This macro sets the selection for a month calendar control to a
 * specified date range.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that contains date information representing
 *        the selection limits. The first selected date must be specified
 *        in lpSysTimeArray[0], and the last selected date must be
 *        specified in lpSysTimeArray[1]. The time members of these
 *        structures are ignored.
 * @return Nonzero indicates success. Zero indicates otherwise. This macro
 *        will fail if applied to a month calendar control that does not
 *        use the MCS_MULTISELECT style.
 */
#define MonthCal_SetSelRange(hwnd,systimearray) SNDMSG(hwnd,MCM_SETSELRANGE,0,(LPARAM)systimearray)
/**
 * This macro sets the "today" selection for a month calendar control,
 * because the control does not automatically update the "today" selection
 * when the time passes midnight for the current day.
 *
 * The control will not automatically update its display based on locale
 * changes.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param lpSysTime Long pointer to a SYSTEMTIME structure that contains
 *        the date to be set as the "today" selection for the control. If
 *        this parameter is set to NULL, the control returns to the default
 *        setting. The time members of this structure are ignored. If the
 *        "today" selection is set to any date other than the default, the
 *        following conditions apply.
 */
#define MonthCal_SetToday(hwnd,systime) SNDMSG(hwnd,MCM_SETTODAY,0,(LPARAM)systime)
#define MonthCal_SetUnicodeFormat(hwnd,unicode) SNDMSG(hwnd,MCM_SETUNICODEFORMAT,(WPARAM)unicode,0)
/**
 * This macro sets the minimum and maximum allowable dates for a month
 * calendar control.
 *
 * @param hwndMC Handle to a month calendar control.
 * @param fWhichLimit Values that specify which limit dates are being set.
 *        It is one or both of the following values: Value Description
 *        GDTR_MAX The maximum allowable date is being set. The SYSTEMTIME
 *        structure at lprgSysTimeArray[1] must contain date information.
 *        GDTR_MIN The minimum allowable date is being set. The SYSTEMTIME
 *        structure at lprgSysTimeArray[0] must contain date information.
 * @param lprgSysTimeArray Long pointer to a two-element array of
 *        SYSTEMTIME structures that contains date limit information. The
 *        maximum limit must be in lpSysTimeArray[1] if GDTR_MAX is
 *        specified, and lpSysTimeArray[0] must contain the minimum limit
 *        if GDTR_MIN is specified. The time members of these structure are
 *        ignored.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define MonthCal_SetRange(w,f,st) (BOOL)SNDMSG((w),MCM_SETRANGE,(WPARAM)(f),(LPARAM)(st))
BOOL WINAPI ShowHideMenuCtl(HWND,UINT,PINT);
/**
 * This macro retrieves information about a tab in a tab control. You can
 * use this macro or send the TCM_GETITEM message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the tab.
 * @param pitem Pointer to a TCITEM structure that specifies the
 *        information to retrieve and receives information about the tab.
 *        When the message is sent, the mask member specifies which
 *        attributes to return. If the mask member specifies the TCIF_TEXT
 *        value, the pszText member must contain the address of the buffer
 *        that receives the item text, and the cchTextMax member must
 *        specify the size of the buffer.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_GetItem(w,i,p) (BOOL)SNDMSG((w),TCM_GETITEM,i,(LPARAM)(TC_ITEM*)(p))
/**
 * This macro sets some or all of a tab's attributes. You can use this
 * macro or send the TCM_SETITEM message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the item.
 * @param pitem Pointer to a TCITEM structure that contains the new item
 *        attributes. The mask member specifies which attributes to set. If
 *        the mask member specifies the LVIF_TEXT value, the pszText member
 *        is the address of a null-terminated string and the cchTextMax
 *        member is ignored.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_SetItem(w,i,p) (BOOL)SNDMSG((w),TCM_SETITEM,i,(LPARAM)(TC_ITEM*)(p))
/**
 * This macro inserts a new tab in a tab control. You can use this macro or
 * send the TCM_INSERTITEM message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the new tab.
 * @param pitem Pointer to a TCITEM structure that specifies the attributes
 *        of the tab. The dwState and dwStateMask members of this structure
 *        are ignored by this message.
 * @return The index of the new tab indicates success. -1 indicates
 *        failure.
 */
#define TabCtrl_InsertItem(w,i,p) (int)SNDMSG((w),TCM_INSERTITEM,i,(LPARAM)(const TC_ITEM*)(p))
/**
 * This macro removes an item from a tab control. You can use this macro or
 * send the TCM_DELETEITEM message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the item to delete.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_DeleteItem(w,i) (BOOL)SNDMSG((w),TCM_DELETEITEM,i,0)
/**
 * This macro removes all items from a tab control. You can use this macro
 * or send the TCM_DELETEALLITEMS message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_DeleteAllItems(w) (BOOL)SNDMSG((w),TCM_DELETEALLITEMS,0,0)
/**
 * This macro retrieves the bounding rectangle for a tab in a tab control.
 * You can use this macro or send the TCM_GETITEMRECT message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the tab.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle of the tab, in viewport coordinates.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_GetItemRect(w,i,p) (BOOL)SNDMSG((w),TCM_GETITEMRECT,i,(LPARAM)(LPRECT)(p))
/**
 * This macro determines the currently selected tab in a tab control. You
 * can use this macro or send the TCM_GETCURSEL message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @return The index of the selected tab indicates success. -1 indicates
 *        that no tab is selected.
 */
#define TabCtrl_GetCurSel(w) (int)SNDMSG((w),TCM_GETCURSEL,0,0)
/**
 * This macro selects a tab in a tab control. You can use this macro or
 * send the TCM_SETCURSEL message explicitly.
 *
 * A tab control does not send a TCN_SELCHANGING or TCN_SELCHANGE
 * notification message when a tab is selected using the TCM_SETCUSEL
 * message.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Index of the tab to select.
 * @return The index of the previously selected tab indicates success. -1
 *        indicates failure.
 */
#define TabCtrl_SetCurSel(w,i) (int)SNDMSG((w),TCM_SETCURSEL,i,0)
/**
 * This macro determines which tab, if any, is at a specified screen
 * position. You can use this macro or send the TCM_HITTEST message
 * explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param pinfo Pointer to a TCHITTESTINFO structure that specifies the
 *        screen position to test.
 * @return The index of the tab indicates success. -1 indicates that no tab
 *        is at the specified position.
 */
#define TabCtrl_HitTest(w,p) (int)SNDMSG((w),TCM_HITTEST,0,(LPARAM)(TC_HITTESTINFO*)(p))
/**
 * This macro sets the number of bytes per tab reserved for
 * application-defined data in a tab control. You can use this macro or
 * send the TCM_SETITEMEXTRA message explicitly.
 *
 * By default, the number of extra bytes is four. An application that
 * changes the number of extra bytes cannot use the TCITEM structure to
 * retrieve and set the application-defined data for a tab. Instead, you
 * must define a new structure that consists of the TCITEMHEADER structure
 * followed by application-defined members.
 *
 * An application should only change the number of extra bytes when a tab
 * control does not contain any tabs.
 *
 * @param hwnd Handle to the tab control.
 * @param cb Number of extra bytes.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TabCtrl_SetItemExtra(w,c) (BOOL)SNDMSG((w),TCM_SETITEMEXTRA,c,0)
/**
 * This macro calculates a tab control's display area Nonzero indicates
 * success. Zero indicates otherwise. a window rectangle, or calculates the
 * window rectangle that would correspond to a specified display area. You
 * can use this macro or send the TCM_ADJUSTRECT message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param fLarger Boolean value that specifies the operation to perform. If
 *        set to TRUE, prc specifies a display rectangle and receives the
 *        corresponding window rectangle. If set to FALSE, prc specifies a
 *        window rectangle and receives the corresponding display area.
 * @param prc Pointer to a RECT structure that specifies the Nonzero
 *        indicates success. Zero indicates otherwise. rectangle and
 *        receives the calculated rectangle.
 * @return None.
 */
#define TabCtrl_AdjustRect(w,b,p) (int)SNDMSG((w),TCM_ADJUSTRECT,b,(LPARAM)(LPRECT)p)
/**
 * This macro sets the width and height of tabs in a fixed-width or
 * owner-drawn tab control. You can use this macro or send the
 * TCM_SETITEMSIZE message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param cx and cy New width and height, in pixels.
 * @return Returns the old width and height. The width is in the low-order
 *        word of the return value, and the height is in the high-order
 *        word.
 */
#define TabCtrl_SetItemSize(w,x,y) (DWORD)SNDMSG((w),TCM_SETITEMSIZE,0,MAKELPARAM(x,y))
/**
 * This macro removes an image from a tab control's image list. You can use
 * this macro or send the TCM_REMOVEIMAGE message explicitly.
 *
 * The tab control updates each tab's image index, so each tab remains
 * associated with the same image as before. If a tab is using the image
 * being removed, the tab will be set to have no image.
 *
 * @param hwnd Handle to the tab control.
 * @param iImage Index of the image to remove.
 * @return None.
 */
#define TabCtrl_RemoveImage(w,i) (void)SNDMSG((w),TCM_REMOVEIMAGE,i,0)
/**
 * This macro sets the amount of space (padding) around each tab's icon and
 * label in a tab control. You can use this macro or send the
 * TCM_SETPADDING message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param cx and cy Amount of horizontal and vertical padding, in pixels.
 * @return None.
 */
#define TabCtrl_SetPadding(w,x,y) (void)SNDMSG((w),TCM_SETPADDING,0,MAKELPARAM(x,y))
/**
 * This macro retrieves the current number of rows of tabs in a tab
 * control. You can use this macro or send the TCM_GETROWCOUNT message
 * explicitly.
 *
 * Only tab controls that have the TCS_MUTLILINE style can have multiple
 * rows of tabs.
 *
 * @param hwnd Handle to the tab control.
 * @return Returns the number of rows of tabs.
 */
#define TabCtrl_GetRowCount(w) (int)SNDMSG((w),TCM_GETROWCOUNT,0,0)
#define TabCtrl_GetToolTips(w) (HWND)SNDMSG((w),TCM_GETTOOLTIPS,0,0)
#define TabCtrl_SetToolTips(w,t) (void)SNDMSG((w),TCM_SETTOOLTIPS,(WPARAM)t,0)
/**
 * This macro returns the index of the item that has the focus in a tab
 * control. You can use this macro or send the TCM_GETCURFOCUS message
 * explicitly.
 *
 * The item that has the focus may be different from the selected item.
 *
 * @param hwnd Handle to the tab control.
 * @return The index of the tab item that has the focus indicates success.
 */
#define TabCtrl_GetCurFocus(w) (int)SNDMSG((w),TCM_GETCURFOCUS,0,0)
/**
 * This macro sets the focus to a specified tab in a tab control. You can
 * use this macro or send the TCM_SETCURFOCUS message explicitly.
 *
 * If the tab control has the TCS_BUTTONS style (button mode), the tab with
 * the focus may be different from the selected tab. For example, when a
 * tab is selected, the user can press the arrow keys to set the focus to a
 * different tab without changing the selected tab. In button mode, the
 * TabCtrl_SetCurFocus macro sets the input focus to the button associated
 * with the specified tab, but it does not change the selected tab.
 *
 * If the tab control does not have the TCS_BUTTONS style, changing the
 * focus also changes the selected tab. In this case, the tab control sends
 * the TCN_SELCHANGING and TCN_SELCHANGE notification messages to its
 * parent window.
 *
 * @param hwnd Handle to the tab control.
 * @param iItem Zero-based index of the tab that gets the focus.
 * @return None.
 */
#define TabCtrl_SetCurFocus(w,i) (void)SNDMSG((w),TCM_SETCURFOCUS,i,0)
/**
 * This macro retrieves the image list associated with a tab control. You
 * can use this macro or send the TCM_GETIMAGELIST message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @return The handle to the image list indicates success. NULL indicates
 *        failure.
 */
#define TabCtrl_GetImageList(w) (HIMAGELIST)SNDMSG((w),TCM_GETIMAGELIST,0,0)
/**
 * This macro assigns an image list to a tab control. You can use this
 * macro or send the TCM_SETIMAGELIST message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @param himl Handle to the image list to assign to the tab control.
 * @return The handle to the previous image list indicates success. NULL
 *        indicates that there is no previous image list.
 */
#define TabCtrl_SetImageList(w,h) (HIMAGELIST)SNDMSG((w),TCM_SETIMAGELIST,0,(LPARAM)(UINT)(h))
/**
 * This macro retrieves the number of tabs in the tab control. You can use
 * this macro or send the TCM_GETITEMCOUNT message explicitly.
 *
 * @param hwnd Handle to the tab control.
 * @return The number of tabs indicates success. Zero indicates failure.
 */
#define TabCtrl_GetItemCount(w) (int)SNDMSG((w),TCM_GETITEMCOUNT,0,0)
BOOL WINAPI _TrackMouseEvent(LPTRACKMOUSEEVENT);
/**
 * This macro inserts a new item in a tree-view control. You can use this
 * macro or send the TVM_INSERTITEM message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param lpis Long pointer to a TVINSERTSTRUCT structure that specifies
 *        the attributes of the tree view item.
 * @return The handle to the new item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_InsertItem(w,i) (HTREEITEM)SNDMSG((w),TVM_INSERTITEM,0,(LPARAM)(LPTV_INSERTSTRUCT)(i))
/**
 * This macro removes an item from a tree-view control. You can use this
 * macro, the TreeView_DeleteAllItems macro, or send the TVM_DELETEITEM
 * message explicitly.
 *
 * If the item label is being edited, the edit operation is canceled and
 * the parent window receives the TVN_ENDLABELEDIT notification message.
 * The parent window receives a TVN_DELETEITEM notification message when
 * the item is removed.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the item to delete. If hitem is the TVI_ROOT
 *        value, all items are deleted from the tree view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_DeleteItem(w,i) (BOOL)SNDMSG((w),TVM_DELETEITEM,0,(LPARAM)(HTREEITEM)(i))
/**
 * This macro removes an item from a tree-view control. You can use this
 * macro, the TreeView_DeleteItem macro, or send the TVM_DELETEITEM message
 * explicitly.
 *
 * If the item label is being edited, the edit operation is canceled and
 * the parent window receives the TVN_ENDLABELEDIT notification message.
 * The parent window receives a TVN_DELETEITEM notification message when
 * the item is removed.
 *
 * @param hwndTV Handle to the tree view control.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_DeleteAllItems(w) (BOOL)SNDMSG((w),TVM_DELETEITEM,0,(LPARAM)TVI_ROOT)
/**
 * This macro expands or collapses the list of child items, if any,
 * associated with the specified parent item. You can use this macro or
 * send the TVM_EXPAND message explicitly.
 *
 * The TreeView_Expand macro will cause the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages to be generated if the item being
 * expanded does not have the TVIS_EXPANDEDONCE state bit set. This state
 * gets set when a parent item is expanded for the first time. Using
 * TVE_COLLAPSE and TVE_COLLAPSERESET with TreeView_Expand will cause the
 * TVIS_EXPANDEDONCE state to be reset.
 *
 * If the item already has the TVIS_EXPANDEDONCE state set, the
 * TreeView_Expand macro will not cause the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages to be generated.
 *
 * @param hwndTV Handle to a tree view control.
 * @param hItem Handle to the parent item that will be expanded or
 *        collapsed.
 * @param flag Action flag. For a list of possible values, see the
 *        description of the flag parameter in TVM_EXPAND. Value
 *        Description TVE_EXPANDPARTIAL Child items are visible and parent
 *        item's plus symbol is displayed. This flag must be used in
 *        combination with the TVE_EXPAND flag.
 * @return Nonzero indicates that a change took place. Zero indicates
 *        otherwise.
 */
#define TreeView_Expand(w,i,c) (BOOL)SNDMSG((w),TVM_EXPAND,c,(LPARAM)(HTREEITEM)(i))
/**
 * This macro retrieves the bounding rectangle for a tree-view item and
 * indicates whether the item is visible. You can use this macro or send
 * the TVM_GETITEMRECT message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the tree view item.
 * @param prc Pointer to a RECT structure that receives the bounding
 *        rectangle. The coordinates are relative to the upper-left corner
 *        of the tree view control.
 * @param fItemRect Value that specifies the portion of the item for which
 *        to retrieve the bounding rectangle. If set to TRUE, the bounding
 *        rectangle includes only the text of the item. If set to FALSE, it
 *        includes the entire line that the item occupies in the tree view
 *        control.
 * @return TRUE indicates that the item is visible and the bounding
 *        rectangle is successfully retrieved. FALSE indicates that the
 *        TVM_GETITEMRECT message does not retrieve the bounding rectangle.
 */
#define TreeView_GetItemRect(w,i,p,c) (*(HTREEITEM*)p=(i),(BOOL)SNDMSG((w),TVM_GETITEMRECT,c,(LPARAM)(LPRECT)(p)))
/**
 * This macro retrieves a count of the items in a tree-view control. You
 * can use this macro or send the TVM_GETCOUNT message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @return Returns the count of items.
 */
#define TreeView_GetCount(w) (UINT)SNDMSG((w),TVM_GETCOUNT,0,0)
/**
 * This macro retrieves the amount, in pixels, that child items are
 * indented relative to their parent items. You can use this macro or send
 * the TVM_GETINDENT message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @return Returns the amount of indentation.
 */
#define TreeView_GetIndent(w) (UINT)SNDMSG((w),TVM_GETINDENT,0,0)
/**
 * This macro sets the width of indentation for a tree-view control and
 * redraws the control to reflect the new width. You can use this macro or
 * send the TVM_SETINDENT message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param indent Width, in pixels, of the indentation. If this parameter is
 *        less than the system-defined minimum width, the new width is set
 *        to the system-defined minimum.
 * @return The return value is not used.
 */
#define TreeView_SetIndent(w,i) (BOOL)SNDMSG((w),TVM_SETINDENT,i,0)
/**
 * This macro retrieves the handle to the normal or state image list
 * associated with a tree-view control. You can use this macro or send the
 * TVM_GETIMAGELIST message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param iImage Type of image list to retrieve. It is one of the following
 *        values: Value Description TVSIL_NORMAL Indicates the normal image
 *        list, which contains selected, nonselected, and overlay images
 *        for the items of a tree view control. TVSIL_STATE Indicates the
 *        state image list. You can use state images to indicate
 *        application-defined item states. A state image is displayed to
 *        the left of an item's selected or nonselected image.
 * @return Returns an HIMAGELIST handle to the specified image list.
 */
#define TreeView_GetImageList(w,i) (HIMAGELIST)SNDMSG((w),TVM_GETIMAGELIST,i,0)
/**
 * This macro sets the normal or state image list for a tree-view control
 * and redraws the control using the new images. You can use this macro or
 * send the TVM_SETIMAGELIST message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param himl Handle to the image list. If himl is NULL, the message
 *        removes the specified image list from the tree view control.
 * @param iImage Type of image list to set. It is one of the following
 *        values: Value Description TVSIL_NORMAL Indicates the normal image
 *        list, which contains selected, nonselected, and overlay images
 *        for the items of a tree view control. TVSIL_STATE Indicates the
 *        state image list. You can use state images to indicate
 *        application-defined item states. A state image is displayed to
 *        the left of an item's selected or nonselected image.
 * @return The HIMAGELIST handle to the previous image list, if any,
 *        indicates success. NULL indicates failure.
 */
#define TreeView_SetImageList(w,h,i) (HIMAGELIST)SNDMSG((w),TVM_SETIMAGELIST,i,(LPARAM)(HIMAGELIST)(h))
/**
 * This macro retrieves the tree-view item that bears the specified
 * relationship to a specified item. You can use this macro, use one of the
 * TreeView_Get macros described below, or send the TVM_GETNEXTITEM message
 * explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item.
 * @param flag Flag that specifies the item to retrieve. It is one of the
 *        following values: Value Description TVGN_CARET Retrieves the
 *        currently selected item. You can use the TreeView_GetSelection
 *        macro to send this message. TVGN_CHILD Retrieves the first child
 *        item of the item specified by the hitem parameter. You can use
 *        the TreeView_GetChild macro to send this message. TVGN_DROPHILITE
 *        Retrieves the item that is the target of a drag-and-drop
 *        operation. You can use the TreeView_GetDropHilight macro to send
 *        this message. TVGN_FIRSTVISIBLE Retrieves the first visible item.
 *        You can use the TreeView_GetFirstVisible macro to send this
 *        message. TVGN_NEXT Retrieves the next sibling item. You can use
 *        the TreeView_GetNextSibling macro to send this message.
 *        TVGN_NEXTVISIBLE Retrieves the next visible item that follows the
 *        specified item. The specified item must be visible. Use the
 *        TVM_GETITEMRECT message to determine whether an item is visible.
 *        You can use the TreeView_GetNextVisible macro to send this
 *        message. TVGN_PARENT Retrieves the parent of the specified item.
 *        You can use the TreeView_GetParent macro to send this message.
 *        TVGN_PREVIOUS Retrieves the previous sibling item. You can use
 *        the TreeVIew_GetPrevSibling macro to send this message.
 *        TVGN_PREVIOUSVISIBLE Retrieves the first visible item that
 *        precedes the specified item. The specified item must be visible.
 *        Use the TVM_GETITEMRECT message to determine whether an item is
 *        visible. You can use the TreeView_GetPrevVisible macro to send
 *        this message. TVGN_ROOT Retrieves the topmost or very first item
 *        of the tree view control. You can use the TreeView_GetRoot macro
 *        to send this message.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetNextItem(w,i,c) (HTREEITEM)SNDMSG((w),TVM_GETNEXTITEM,c,(LPARAM)(HTREEITEM)(i))
/**
 * This macro retrieves the first child item of the specified tree-view
 * item. You can use this macro, or you can explicitly send the
 * TVM_GETNEXTITEM message with the TVGN_CHILD flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to a tree view item.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetChild(w,i)	TreeView_GetNextItem(w,i,TVGN_CHILD)
/**
 * This macro retrieves the next sibling item of a specified item in a
 * tree-view control. You can use this macro, or you can explicitly send
 * the TVM_GETNEXTITEM message with the TVGN_NEXT flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetNextSibling(w,i)	TreeView_GetNextItem(w,i,TVGN_NEXT)
/**
 * This macro retrieves the previous sibling item of a specified item in a
 * tree-view control. You can use this macro, or you can explicitly send
 * the TVM_GETNEXTITEM message with the TVGN_PREVIOUS flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetPrevSibling(w,i)	TreeView_GetNextItem(w,i,TVGN_PREVIOUS)
/**
 * This macro retrieves the parent item of the specified tree-view item.
 * You can use this macro, or you can explicitly send the TVM_GETNEXTITEM
 * message with the TVGN_PARENT flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetParent(w,i)	TreeView_GetNextItem(w,i,TVGN_PARENT)
/**
 * This macro retrieves the first visible item in a tree-view control. You
 * can use this macro, or you can explicitly send the TVM_GETNEXTITEM
 * message with the TVGN_FIRSTVISIBLE flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetFirstVisible(w)	TreeView_GetNextItem(w,NULL,TVGN_FIRSTVISIBLE)
/**
 * This macro retrieves the next visible item that follows a specified item
 * in a tree-view control. You can use this macro, or you can explicitly
 * send the TVM_GETNEXTITEM message with the TVGN_NEXTVISIBLE flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. The specified item must be visible. Use
 *        the TVM_GETITEMRECT message to determine whether an item is
 *        visible.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetNextVisible(w,i)	TreeView_GetNextItem(w,i,TVGN_NEXTVISIBLE)
/**
 * This macro retrieves the first visible item that precedes a specified
 * item in a tree-view control. You can use this macro, or you can
 * explicitly send the TVM_GETNEXTITEM message with the
 * TVGN_PREVIOUSVISIBLE flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. The specified item must be visible. Use
 *        the TVM_GETITEMRECT message to determine whether an item is
 *        visible.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetPrevVisible(w,i)	TreeView_GetNextItem(w,i,TVGN_PREVIOUSVISIBLE)
/**
 * This macro retrieves the currently selected item in a tree-view control.
 * You can use this macro, or you can explicitly send the TVM_GETNEXTITEM
 * message with the TVGN_CARET flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetSelection(w)	TreeView_GetNextItem(w,NULL,TVGN_CARET)
#define TreeView_GetDropHilight(w)	TreeView_GetNextItem(w,NULL,TVGN_DROPHILITE)
/**
 * This macro retrieves the topmost or very first item of the tree-view
 * control. You can use this macro, or you can explicitly send the
 * TVM_GETNEXTITEM message with the TVGN_ROOT flag.
 *
 * @param hwndTV Handle to the tree view control.
 * @return The handle to the item indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetRoot(w)	TreeView_GetNextItem(w,NULL,TVGN_ROOT)
/**
 * This macro selects the specified tree-view item, scrolls the item into
 * the view, or redraws the item in the style used to indicate the target
 * of a drag-and-drop operation. You can use this macro or the
 * TreeView_SelectItem, TreeView_SelectSetFirstVisible, or
 * treeView_SelectDropTarget macros, or you can send the TVM_SELECTITEM
 * message explicitly.
 *
 * If the specified item is the child of a collapsed parent item, the
 * parent's list of child items is expanded to reveal the specified item.
 * In this case, the parent window receives the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. If the hitem parameter is NULL, the
 *        control is set to have no selected item.
 * @param flag Action flag. It is one of the following values: Value
 *        Description TVGN_CARET Sets the selection to the Nonzero
 *        indicates success. Zero indicates otherwise. item. The control's
 *        parent window receives the TVN_SELCHANGING and TVN_SELCHANGED
 *        notification messages. TVGN_DROPHILITE Redraws the Nonzero
 *        indicates success. Zero indicates otherwise. item in the style
 *        used to indicate the target of a drag-and-drop operation.
 *        TVGN_FIRSTVISIBLE Ensures that the specified item is visible,
 *        and, if possible, displays it at the top of the control's window.
 *        Tree view controls display as many items as will fit in the
 *        window. If the specified item is near the bottom of the control's
 *        hierarchy of items, it might not become the first visible item,
 *        depending on how many items fit in the window.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_Select(w,i,c) (BOOL)SNDMSG((w),TVM_SELECTITEM,c,(LPARAM)(HTREEITEM)(i))
/**
 * This macro selects the specified tree-view item. You can use this macro
 * or the TreeView_Select macro, or you can send the TVM_SELECTITEM message
 * explicitly.
 *
 * When you call the TreeView_SelectItem macro, the control's parent window
 * receives the TVN_SELCHANGING and TVN_SELCHANGED notification messages.
 * Also, if the specified item is the child of a collapsed parent item, the
 * parent's list of child items is expanded to reveal the specified item.
 * In this case, the parent window receives the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages.
 *
 * Using the TreeView_SelectItem macro is equivalent to sending the
 * TVM_SELECTITEM message with its flag parameter set to the TVGN_CARET
 * value.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. If the hitem parameter is NULL, the
 *        control is set to have no selected item.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_SelectItem(w,i)	TreeView_Select(w,i,TVGN_CARET)
/**
 * This macro redraws a specified tree-view control item in the style used
 * to indicate the target of a drag-and-drop operation. You can use this
 * macro or the TreeView_Select macro, or you can send the TVM_SELECTITM
 * message explicitly.
 *
 * If the specified item is the child of a collapsed parent item, the
 * parent's list of child items is expanded to reveal the specified item.
 * In this case, the parent window receives the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages.
 *
 * Using the TreeView_SelectDropTarget macro is equivalent to sending the
 * TVM_SELECTITEM message with its flag parameter set to the
 * TVGN_DROPHILITE value.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. If the hitem parameter is NULL, the
 *        control is set to have no selected item.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_SelectDropTarget(w,i)	TreeView_Select(w,i,TVGN_DROPHILITE)
/**
 * This macro scrolls the tree-view control vertically to ensure that the
 * specified item is visible. If possible, the specified item becomes the
 * first visible item at the top of the control's window. You can use this
 * macro or the TreeView_Select macro, or you can send the TVM_SELECTITEM
 * message explicitly.
 *
 * Tree view controls display as many items as will fit in the window. If
 * the specified item is near the bottom of the control's hierarchy of
 * items, it might not become the first visible item, depending on how many
 * items fit in the window.
 *
 * If the specified item is the child of a collapsed parent item, the
 * parent's list of child items is expanded to reveal the specified item.
 * In this case, the parent window receives the TVN_ITEMEXPANDING and
 * TVN_ITEMEXPANDED notification messages.
 *
 * Using the TreeView_SelectSetFirstVisible macro is equivalent to sending
 * the TVM_SELECTITEM message with its flag parameter set to the
 * TVGN_FIRSTVISIBLE value.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to an item. If the hitem parameter is NULL, the
 *        control is set to have no selected item.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_SelectSetFirstVisible(w,i)	TreeView_Select(w,i,TVGN_FIRSTVISIBLE)
/**
 * This macro retrieves some or all of a tree-view item's attributes. You
 * can use this macro or send the TVM_GETITEM message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param pitem Pointer to a TVITEM structure that specifies the
 *        information to retrieve and receives information about the item.
 *        When the TVM_GETITEM message is sent, the hItem member identifies
 *        the item to retrieve information about, and the mask member
 *        specifies the attributes to retrieve. If the mask member
 *        specifies the TVIF_TEXT value, the pszText member must contain
 *        the address of the buffer that receives the item text and the
 *        cchTextMax member must specify the size of the buffer. If the
 *        mask member specifies the TVIF_STATE value, the stateMask member
 *        must specify the item state bits to retrieve. On output, the
 *        state member contains the values of the specified state bits.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_GetItem(w,i) (BOOL)SNDMSG((w),TVM_GETITEM,0,(LPARAM)(TV_ITEM*)(i))
/**
 * This macro sets some or all of a tree-view item's attributes. You can
 * use this macro or send the TVM_SETITEM message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param pitem Pointer to a TVITEM structure that contains the new item
 *        attributes. The hItem member identifies the item, and the mask
 *        member specifies which attributes to set. If mask specifies the
 *        TVIF_TEXT value, the pszText member is the address of a
 *        null-terminated string and the cchTextMax member is ignored. If
 *        mask specifies the TVIF_STATE value, the stateMask member
 *        indicates which item states to change and the state member
 *        contains the values for those states.
 * @return Zero indicates success. -1 indicates failure.
 */
#define TreeView_SetItem(w,i) (BOOL)SNDMSG((w),TVM_SETITEM,0,(LPARAM)(const TV_ITEM*)(i))
/**
 * This macro begins in-place editing of the specified item's text,
 * replacing the text of the item with a single-line edit control
 * containing the text. This macro implicitly selects and focuses the
 * specified item. You can use this macro or send the TVM_EDITLABEL message
 * explicitly.
 *
 * This macro sends a TVN_BEGINLABELEDIT notification message to the parent
 * of the tree view control.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but do not destroy it.
 *
 * The control must have the focus before you call this macro. Focus can be
 * set using the SetFocus function.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the item to edit.
 * @return The handle to the edit control used to edit the item text
 *        indicates success. NULL indicates failure.
 */
#define TreeView_EditLabel(w,i) (HWND)SNDMSG((w),TVM_EDITLABEL,0,(LPARAM)(HTREEITEM)(i))
/**
 * This macro retrieves the handle to the edit control being used to edit a
 * tree-view item's text. You can use this macro or send the
 * TVM_GETEDITCONTROL message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @return The handle to the edit control indicates success. NULL indicates
 *        failure.
 */
#define TreeView_GetEditControl(w) (HWND)SNDMSG((w),TVM_GETEDITCONTROL,0,0)
/**
 * This macro obtains the number of items that can be fully visible in the
 * client window of a tree-view control. You can use this macro or send the
 * TVM_GETVISIBLECOUNT message explicitly.
 *
 * The number of items that can be fully visible may be greater than the
 * number of items in the control. The control calculates this value by
 * dividing the height of the client window by the height of an item.
 *
 * Note that the return value is the number of items that can be fully
 * visible. If you can see all of 20 items and part of one more item, the
 * return value is 20.
 *
 * @param hwndTV Handle to the tree view control.
 * @return Returns the number of items that can be fully visible in the
 *        client window of the tree view control.
 */
#define TreeView_GetVisibleCount(w) (UINT)SNDMSG((w),TVM_GETVISIBLECOUNT,0,0)
/**
 * This macro determines the location of the specified point relative to
 * the client area of a tree-view control. You can use this macro or send
 * the TVM_HITTEST message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param lpht Long pointer to a TVHITTESTINFO structure. When the message
 *        is sent, the pt member specifies the coordinates of the point to
 *        test. When the message returns, the hItem member is the handle to
 *        the item at the specified point or NULL if no item occupies the
 *        point. Also, when the message returns, the flags member is a hit
 *        test value that indicates the location of the specified point.
 *        For a list of hit test values, see the description of the
 *        TVHITTESTINFO structure.
 * @return The handle to the tree view item that occupies the specified
 *        point indicates success. NULL indicates that no item occupies the
 *        point.
 */
#define TreeView_HitTest(w,p) (HTREEITEM)SNDMSG((w),TVM_HITTEST,0,(LPARAM)(LPTV_HITTESTINFO)(p))
/**
 * This macro creates a dragging bitmap for the specified item in a
 * tree-view control, creates an image list for the bitmap, and adds the
 * bitmap to the image list. An application can display the image when
 * dragging the item by using the image list functions. You can use this
 * macro or send the TVM_CREATEDRAGIMAGE message explicitly.
 *
 * If you create a tree view control without an associated image list, you
 * cannot use the TreeView_CreateDragImage macro to create the image to
 * display during a drag operation. You must implement your own method of
 * creating a drag cursor.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the item that receives the new dragging bitmap.
 * @return The handle to the image list to which the dragging bitmap was
 *        added indicates success. NULL indicates failure.
 */
#define TreeView_CreateDragImage(w,i) (HIMAGELIST)SNDMSG((w),TVM_CREATEDRAGIMAGE,0,(LPARAM)(HTREEITEM)(i))
/**
 * This macro sorts the child items of the specified parent item in a
 * tree-view control. You can use this macro or send the TVM_SORTCHILDREN
 * message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the parent item whose child items are to be
 *        sorted.
 * @param fRecurse Reserved for future use; set to zero.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_SortChildren(w,i,r) (BOOL)SNDMSG((w),TVM_SORTCHILDREN,r,(LPARAM)(HTREEITEM)(i))
/**
 * This macro ensures that a tree-view item is visible, expanding the
 * parent item or scrolling the tree-view control, if necessary. You can
 * use this macro or send the TVM_ENSUREVISIBLE message explicitly.
 *
 * If the TreeView_EnsureVisible macro expands the parent item, the parent
 * window receives the TVN_ITEMEXPANDING and TVN_ITEMEXPANDED notification
 * messages.
 *
 * @param hwndTV Handle to the tree view control.
 * @param hitem Handle to the item.
 * @return Nonzero indicates that the system scrolled the items in the tree
 *        view control and no items were expanded. Zero indicates
 *        otherwise.
 */
#define TreeView_EnsureVisible(w,i) (BOOL)SNDMSG((w),TVM_ENSUREVISIBLE,0,(LPARAM)(HTREEITEM)(i))
/**
 * This macro sorts tree-view items using an application-defined callback
 * function that compares the items. You can use this macro or send the
 * TVM_SORTCHILDRENCB message explicitly.
 *
 * @param hwndTV Handle to the tree view control.
 * @param psort Pointer to a TVSORTCB structure. The lpfnCompare member is
 *        the address of the application-defined callback function, which
 *        is called during the sort operation each time the relative order
 *        of two list items needs to be compared. For more information
 *        about the callback function, see the description of TVSORTCB.
 * @param fRecurse Reserved for future use; set to zero.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_SortChildrenCB(w,s,r) (BOOL)SNDMSG((w),TVM_SORTCHILDRENCB,r,(LPARAM)(LPTVSORTCB)(s))
/**
 * This macro ends the editing of a tree-view item's label. You can use
 * this macro or send the TVM_ENDEDITLABELNOW message explicitly.
 *
 * This macro causes the TVN_ENDLABELEDIT notification message to be sent
 * to the parent window of the tree view control.
 *
 * @param hwndTV Handle to the tree view control.
 * @param fCancel Variable that indicates whether the editing is canceled
 *        without being saved to the label. If set to is TRUE, the system
 *        cancels editing without saving the changes. If set to FALSE, the
 *        system saves the changes to the label.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TreeView_EndEditLabelNow(w,f) (BOOL)SNDMSG((w),TVM_ENDEDITLABELNOW,f,0)
/**
 * This macro retrieves the incremental search string for a tree-view
 * control. The tree-view control uses the incremental search string to
 * select an item based on characters typed by the user. You can use this
 * macro or send the TVM_GETISEARCHSTRING message explicitly.
 *
 * If the tree view control is not in incremental search mode, the return
 * value is zero.
 *
 * @param hwndTV Handle to the tree view control.
 * @param lpsz Long pointer to the buffer that receives the incremental
 *        search string.
 * @return Returns the number of characters in the incremental search
 *        string.
 */
#define TreeView_GetISearchString(w,s) (BOOL)SNDMSG((w),TVM_GETISEARCHSTRING,0,(LPARAM)s)
#if (_WIN32_IE >= 0x0300)
/**
 * This macro calculates the approximate width and height required to
 * display a specified number of items.
 *
 * @param hwndLV Handle to a list view control.
 * @param iCount Number of items to be displayed in the control. If this
 *        parameter is -1, the message uses the total number of items in
 *        the control.
 * @param cx and cy Proposed dimensions of the control, in pixels. Either
 *        parameter can be -1 to allow the message to use the current width
 *        or height value.
 * @return Returns a DWORD value that holds the approximate width and
 *        height needed to display the items, in pixels.
 */
#define ListView_ApproximateViewRect(w,iw,ih,i) (DWORD)SNDMSG((w),LVM_APPROXIMATEVIEWRECT,(i),MAKELPARAM((iw),(ih)))
/**
 * This macro sets extended styles for list view controls.
 *
 * @param hwndLV Handle to the list view control that will receive the
 *        style change.
 * @param dwExStyle Specifies the extended list view control style. This
 *        parameter can be a combination of extended styles.
 */
#define ListView_SetExtendedListViewStyle(w,s) (DWORD)SNDMSG((w),LVM_SETEXTENDEDLISTVIEWSTYLE,0,(s))
/**
 * This macro retrieves the extended styles that are currently in use for a
 * specified list view control.
 *
 * @param hwndLV Handle to a list view control.
 * @return Returns a DWORD value that represents the styles currently in
 *        use for a specified list view control. This can be a combination
 *        of extended styles.
 */
#define ListView_GetExtendedListViewStyle(w) (DWORD)SNDMSG((w),LVM_GETEXTENDEDLISTVIEWSTYLE,0,0)
/**
 * This macro sets the left-to-right order of columns in a list view
 * control.
 *
 * @param hwndLV Handle to a list view control.
 * @param iCount Number of columns in the list view control.
 * @param lpiArray Long pointer to an array that specifies the order in
 *        which columns should be displayed, in left-to-right order. For
 *        example, if the contents of the array are {2,0,1}, the control
 *        displays column 2, column 0, and column 1 in that order.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define ListView_SetColumnOrderArray(w,i,a) (BOOL)SNDMSG((w),LVM_SETCOLUMNORDERARRAY,(WPARAM)(i),(LPARAM)(LPINT)(a))
/**
 * This macro retrieves the current left-to-right order of columns in a
 * list view control.
 *
 * @param hwndLV Handle to a list view control.
 * @param iCount Number of columns in the list view control.
 * @param lpiArray Long pointer to a buffer that will receive the index
 *        values of the columns in the list view control. The buffer must
 *        be large enough to hold the total number of columns *
 *        sizeof(int).
 * @return Returns nonzero and the buffer at lpiArray receives the column
 *        index of each column in the control, in the order they appear
 *        from left to right if successful. Otherwise, the return value is
 *        zero.
 */
#define ListView_GetColumnOrderArray(w,i,a) (BOOL)SNDMSG((w),LVM_GETCOLUMNORDERARRAY,(WPARAM)(i),(LPARAM)(LPINT)(a))
/**
 * This macro retrieves the handle to the header control used by a list
 * view control.
 *
 * @param hwndLV Handle to a list view control.
 * @return Returns the handle to the header control.
 */
#define ListView_GetHeader(w) (HWND)SNDMSG((w),LVM_GETHEADER,0,0)
#define ListView_GetHotCursor(w) (HCURSOR)SNDMSG((w),LVM_GETHOTCURSOR,0,0)
#define ListView_GetHotItem(w) (INT)SNDMSG((w),LVM_GETHOTITEM,0,0)
/**
 * This macro retrieves information about the rectangle that surrounds a
 * subitem in a list view control. This macro is intended to be used only
 * on list view controls that use the LVS_REPORT style.
 *
 * @param hwndLV Handle to a list view control.
 * @param iItem Index of the subitem's parent item.
 * @param iSubItem One-based index of the subitem.
 * @param code Portion of the list view subitem for which to retrieve the
 *        bounding rectangle information. It is one of the following
 *        values: Value Description LVIR_BOUNDS Returns the bounding
 *        rectangle of the entire item, including the icon and label.
 *        LVIR_ICON Returns the bounding rectangle of the icon or small
 *        icon. LVIR_LABEL Returns the bounding rectangle of the entire
 *        item, including the icon and label. This is identical to
 *        LVIR_BOUNDS.
 * @param lpRect Long pointer to a RECT structure that receives the subitem
 *        bounding rectangle information.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define ListView_GetSubItemRect(w,i,is,c,p) (BOOL)SNDMSG((w),LVM_GETSUBITEMRECT,(WPARAM)(int)(i),((p)?(((LPRECT)(p))->left=(c),(((LPRECT)(p))->top=(is)),(LPARAM)(LPRECT)(p)):0))
#define ListView_SetHotCursor(w,c) (HCURSOR)SNDMSG((w),LVM_SETHOTCURSOR,0,(LPARAM)(c))
#define ListView_SetHotItem(w,i) (int)SNDMSG((w),LVM_SETHOTITEM,(WPARAM)(i),0)
/**
 * This macro sets the spacing between icons in list view controls set to
 * the LVS_ICON style.
 *
 * The cx and cy parameters are relative to the upper-left corner of an
 * icon bitmap. Therefore, to set spacing between icons that do not
 * overlap, the cx or cy values must include the size of the icon, plus the
 * amount of empty space desired between icons. Values that do not include
 * the width of the icon will result in overlaps.
 *
 * @param hwndLV Handle to a list view control.
 * @param cx Distance, in pixels, to set between icons on the x-axis.
 * @param cy Distance, in pixels, to set between icons on the y-axis.
 * @return Returns a DWORD value that contains the previous cx in the
 *        low-order word, and the previous cy in the high-order word.
 */
#define ListView_SetIconSpacing(w,x,y) (DWORD)SNDMSG((w),LVM_SETICONSPACING,0,MAKELONG(x,y))
/**
 * This macro determines which list view item or subitem is located at a
 * specified position.
 *
 * @param hwndLV Handle to the list view control that will be hit-tested.
 * @param pInfo Pointer to an LVHITTESTINFO structure. The POINT structure
 *        within LVHITTESTINFO must be set to the client coordinates to be
 *        hit-tested.
 * @return Returns the index of the item or subitem tested, if any, or -1
 *        otherwise. If an item or subitem is at the specified coordinates,
 *        the fields of the LVHITTESTINFO structure will be filled with the
 *        applicable hit information.
 */
#define ListView_SubItemHitTest(w,p) (INT)SNDMSG((w),LVM_SUBITEMHITTEST,0,(LPARAM)(LPLVHITTESTINFO)(p))
/**
 * This macro sets the virtual number of items in a virtual list view
 * control.
 *
 * This macro is intended only for list view controls that use the
 * LVS_OWNERDATA and LVS_REPORT or LVS_LIST styles.
 *
 * If the list view control was created with the LVS_OWNERDATA style, this
 * macro sets the virtual number of items that the control contains.
 *
 * If the list view control was created without the LVS_OWNERDATA style,
 * the ListView_SetItemCount macro should be used.
 *
 * @param hwndLV Handle to a virtual list view control.
 * @param cItems Number of items that the list view control will contain.
 * @param dwFlags Specifies the behavior of the list view control after
 *        resetting the item count. It can be one or a combination of the
 *        following values: Value Description LVSICF_NOINVALIDATEALL The
 *        list view control will not repaint unless affected items are
 *        currently in view. LVSICF_NOSCROLL The list view control will not
 *        change the scroll position when the item count changes.
 */
#define ListView_SetItemCountEx(w,i,f) (void)SNDMSG((w),LVM_SETITEMCOUNT,(WPARAM)(i),(LPARAM)(f))
#endif
#if (_WIN32_IE >= 0x0300) || (_WIN32_WCE >= 0x200)
/**
 * Grows or shrinks an image list to a given number of images.
 *
 * Images cut off by shrinking are freed. New slots made by growing hold
 * no valid image: fill them with ImageList_Replace before drawing them.
 *
 * @param himl The image list.
 * @param uNewCount The new number of images.
 * @return Nonzero on success, zero on failure.
 *
 * @note Windows CE 2.0 and later.
 */
WINBOOL WINAPI ImageList_SetImageCount(HIMAGELIST himl,UINT uNewCount);
/**
 * Copies or swaps images within an image list.
 *
 * @param himlDst The image list. Must be the same as himlSrc.
 * @param iDst Zero-based index of the destination image.
 * @param himlSrc The image list. Must be the same as himlDst.
 * @param iSrc Zero-based index of the source image.
 * @param uFlags ILCF_MOVE to copy the source over the destination, or
 *        ILCF_SWAP to exchange them.
 * @return Nonzero on success, zero on failure.
 *
 * @note Windows CE 2.0 and later.
 */
WINBOOL WINAPI ImageList_Copy(HIMAGELIST himlDst,int iDst,HIMAGELIST himlSrc,int iSrc,UINT uFlags);
/**
 * Draws an image from an image list, with the settings in a structure.
 *
 * @param pimldp The draw settings. Set cbSize first.
 * @return Nonzero on success, zero on failure.
 */
WINBOOL WINAPI ImageList_DrawIndirect(IMAGELISTDRAWPARAMS*pimldp);
#endif
#if (_WIN32_IE >= 0x0300)
/**
 * This macro sets the minimum width of items in a tab control.
 *
 * @param hwndTab Handle to the tab control.
 * @param cx Minimum width to be set for a tab control item. If this
 *        parameter is set to -1, the control will use the default tab
 *        width.
 * @return Integer that represents the previous minimum tab width.
 */
#define TabCtrl_SetMinTabWidth(hwnd,x) SNDMSG((hwnd),TCM_SETMINTABWIDTH,0,x)
/**
 * This macro resets items in a tab control, clearing any that were set to
 * the TCIS_BUTTONPRESSED state.
 *
 * @param hwndTab Handle to the tab control.
 * @param fExcludeFocus Value that specifies the scope of the item
 *        deselection. If set to FALSE, all tab items will be reset. If set
 *        to TRUE, all but the currently selected tab item will be reset.
 */
#define TabCtrl_DeselectAll(hwnd,fExcludeFocus) SNDMSG((hwnd),TCM_DESELECTALL,fExcludeFocus,0)
#define TreeView_GetToolTips(w) (HWND)SNDMSG((w),TVM_GETTOOLTIPS,0,0)
#define TreeView_SetToolTips(w,wt) (HWND)SNDMSG((w),TVM_SETTOOLTIPS,(WPARAM)(wt),0)
#endif
#if (_WIN32_IE >= 0x0400)
#define ListView_GetBkImage(h,plvbki) (BOOL)SNDMSG((h),LVM_GETBKIMAGE,0,(LPARAM)(plvbki))
#define ListView_SetBkImage(h,plvbki) (BOOL)SNDMSG((h),LVM_SETBKIMAGE,0,(LPARAM)(plvbki))
#define ListView_SetExtendedListViewStyleEx(w,m,s) (DWORD)SNDMSG((w),LVM_SETEXTENDEDLISTVIEWSTYLE,(m),(s))
#define ListView_SetWorkAreas(w,n,r) (BOOL)SNDMSG((w),LVM_SETWORKAREAS,(WPARAM)(n),(LPARAM)(RECT *)(r))
#define ListView_GetWorkAreas(w,n,r) (BOOL)SNDMSG((w),LVM_GETWORKAREAS,(WPARAM)(n),(LPARAM)(RECT *)(r))
#define ListView_GetNumberOfWorkAreas(w,n) (BOOL)SNDMSG((w),LVM_GETNUMBEROFWORKAREAS,0,(LPARAM)(UINT *)(n))
#define ListView_SetHoverTime(w,t) (DWORD)SNDMSG((w),LVM_SETHOVERTIME,0,(LPARAM)(t))
#define ListView_GetHoverTime(w) (DWORD)SNDMSG((w),LVM_GETHOVERTIME,0,0)
/**
 * This macro retrieves the selection mark from a list view control.
 *
 * The selection mark is the item index from which a multiple selection
 * starts.
 *
 * @param hwndLV Handle to a list view control.
 * @return Returns the zero-based selection mark, or -1 if there is no
 *        selection mark.
 */
#define ListView_GetSelectionMark(w) (INT)SNDMSG((w),LVM_GETSELECTIONMARK,0,0)
/**
 * This macro sets the selection mark in a list view control.
 *
 * The selection mark is the item index from which a multiple selection
 * starts. This macro does not affect the selection state of the item.
 *
 * @param hwndLV Handle to a list view control.
 * @param iIndex Zero-based index of the list view item to be selected.
 * @return Returns the previous selection mark, or -1 if there is no
 *        previous selection mark.
 */
#define ListView_SetSelectionMark(w,i) (INT)SNDMSG((w),LVM_SETSELECTIONMARK,0,(LPARAM)(i))
#define ListView_SetToolTips(w,n) (HWND)SNDMSG((w),LVM_SETTOOLTIPS,(WPARAM)(n),0)
#define ListView_GetToolTips(w) (HWND)SNDMSG((w),LVM_GETTOOLTIPS,0,0)
#define ListView_SetUnicodeFormat(w,f) (BOOL)SNDMSG((w),LVM_SETUNICODEFORMAT,(WPARAM)(f),0)
#define ListView_GetUnicodeFormat(w) (BOOL)SNDMSG((w),LVM_GETUNICODEFORMAT,0,0)
/**
 * This macro sets the highlight state of a tab item.
 *
 * @param hwndTab Handle to the tab control.
 * @param idItem Zero-based index of a tab control item.
 * @param fHighlight Value that specifies the highlight state to be set. If
 *        this value is nonzero, the tab is highlighted. If this value is
 *        zero, the tab is set to its default state.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TabCtrl_HighlightItem(w,i,fHighlight) SNDMSG((w),TCM_HIGHLIGHTITEM,(WPARAM)i,(LPARAM)MAKELONG(fHighlight,0))
/**
 * This macro sets the extended styles that the tab control will use.
 *
 * @param hwndTab Handle to the tab control.
 * @param dwExStyle Contains the new tab control extended styles. It is a
 *        combination of tab control extended styles.
 * @return DWORD that contains the previous tab control extended styles.
 */
#define TabCtrl_SetExtendedStyle(w,dw) SNDMSG((w),TCM_SETEXTENDEDSTYLE,0,dw)
/**
 * This macro retrieves the extended styles that are currently in use for
 * the tab control. You can use this macro or send the TCM_GETEXTENDEDSTYLE
 * message explicitly.
 *
 * @param hwndTab Handle to the tab control.
 * @return Returns a DWORD that represents the extended styles currently in
 *        use for the tab control. This value is a combination of tab
 *        control extended styles.
 */
#define TabCtrl_GetExtendedStyle(w) SNDMSG((w),TCM_GETEXTENDEDSTYLE,0,0)
#define TabCtrl_SetUnicodeFormat(w,u) SNDMSG((w),TCM_SETUNICODEFORMAT,(WPARAM)(u),0)
#define TabCtrl_GetUnicodeFormat(w) SNDMSG((w),TCM_GETUNICODEFORMAT,0,0)
#define TreeView_GetBkColor(w) (COLORREF)SNDMSG((w),TVM_GETBKCOLOR,0,0)
#define TreeView_GetInsertMarkColor(w) (COLORREF)SNDMSG((w),TVM_GETINSERTMARKCOLOR,0,0)
#define TreeView_GetItemHeight(w) (int)SNDMSG((w),TVM_GETITEMHEIGHT,0,0)
#define TreeView_GetScrollTime(w) (UINT)SNDMSG((w),TVM_GETSCROLLTIME,0,0)
#define TreeView_GetTextColor(w) (COLORREF)SNDMSG((w),TVM_GETTEXTCOLOR,0,0)
#define TreeView_SetBkColor(w,c) (COLORREF)SNDMSG((w),TVM_SETBKCOLOR,0,(LPARAM)(c))
#define TreeView_SetInsertMarkColor(w,c) (COLORREF)SNDMSG((w),TVM_SETINSERTMARKCOLOR,0,(LPARAM)(c))
#define TreeView_SetItemHeight(w,h) (int)SNDMSG((w),TVM_SETITEMHEIGHT,(WPARAM)(h),0)
#define TreeView_SetScrollTime(w,t) (UINT)SNDMSG((w),TVM_SETSCROLLTIME,(WPARAM)(UINT)(t),0)
#define TreeView_SetTextColor(w,c) (COLORREF)SNDMSG((w),TVM_SETTEXTCOLOR,0,(LPARAM)(c))
#define TreeView_SetInsertMark(w,i,a) (BOOL)SNDMSG((w),TVM_SETINSERTMARK,(WPARAM)(a),(LPARAM)(i))
#define TreeView_SetUnicodeFormat(w,u) (BOOL)SNDMSG((w),TVM_SETUNICODEFORMAT,(WPARAM)(u),0)
#define TreeView_GetUnicodeFormat(w) (BOOL)SNDMSG((w),TVM_GETUNICODEFORMAT,0,0)
#define TreeView_GetLastVisible(w) TreeView_GetNextItem(w,NULL,TVGN_LASTVISIBLE)
#endif
#if (_WIN32_IE >= 0x0500)
#define TreeView_GetItemState(w,i,m) (UINT)SNDMSG((w),TVM_GETITEMSTATE,(WPARAM)(i),(LPARAM)(m))
#define TreeView_SetItemState(w,i,d,m) \
{ \
	TVITEM _tvi;\
	_tvi.mask=TVIF_STATE;\
	_tvi.hItem=i; \
	_tvi.stateMask=m;\
	_tvi.state=d;\
	SNDMSG((w),TVM_SETITEM,0,(LPARAM)(TVITEM*)&_tvi);\
}
#endif

#ifdef UNICODE
typedef HDITEMW HDITEM;
typedef TOOLINFOW TOOLINFO,*PTOOLINFO,*LPTOOLINFO;
typedef TTHITTESTINFOW TTHITTESTINFO,*LPHITTESTINFO,*LPTTHITTESTINFO;
typedef TOOLTIPTEXTW TOOLTIPTEXT,*LPTOOLTIPTEXT;
typedef NMTTDISPINFOW NMTTDISPINFO, *LPNMTTDISPINFO;
typedef TV_ITEMW TV_ITEM,*LPTV_ITEM;
typedef TVITEMW TVITEM,*LPTVITEM;
#if (_WIN32_IE >= 0x0400)
typedef TVITEMEXW TVITEMEX,*LPTVITEMEX;
#endif
typedef TV_INSERTSTRUCTW TV_INSERTSTRUCT,*LPTV_INSERTSTRUCT;
typedef TVINSERTSTRUCTW TVINSERTSTRUCT,*LPTVINSERTSTRUCT;
typedef NM_TREEVIEWW NM_TREEVIEW,*LPNM_TREEVIEW;
typedef NMTREEVIEWW NMTREEVIEW,*LPNMTREEVIEW;
typedef NMHDDISPINFOW NMHDDISPINFO, *LPNMHDDISPINFO;
#define ACM_OPEN ACM_OPENW
#define COMBOBOXEXITEM	COMBOBOXEXITEMW
#define PCOMBOBOXEXITEM	PCOMBOBOXEXITEMW
#define PCCOMBOBOXEXITEM	PCCOMBOBOXEXITEMW
#define CBEM_INSERTITEM	CBEM_INSERTITEMW
#define CBEM_SETITEM	CBEM_SETITEMW
#define CBEM_GETITEM	CBEM_GETITEMW
#define CBEN_ENDEDIT	CBEN_ENDEDITW
#define NMCBEENDEDIT	NMCBEENDEDITW
#define LPNMCBEENDEDIT	LPNMCBEENDEDITW
#define PNMCBEENDEDIT	PNMCBEENDEDITW
#if _WIN32_IE >= 0x0400
#define NMCOMBOBOXEX	NMCOMBOBOXEXW
#define PNMCOMBOBOXEX	PNMCOMBOBOXEXW
#define CBEN_GETDISPINFO	CBEN_GETDISPINFOW
#define CBEN_DRAGBEGIN	CBEN_DRAGBEGINW
#define NMCBEDRAGBEGIN	NMCBEDRAGBEGINW
#define LPNMCBEDRAGBEGIN	LPNMCBEDRAGBEGINW
#define PNMCBEDRAGBEGIN PNMCBEDRAGBEGINW
#endif /* _WIN32_IE >= 0x0400 */
/**
 * This message retrieves the text from the specified part of a status
 * window.
 *
 * @param iPart Zero-based index of the part from which to retrieve text.
 * @param szText Address of the buffer that receives the text. This
 *        parameter is a null-terminated string.
 * @return Returns a 32-bit value that consists of two 16-bit values. The
 *        low word specifies the length, in characters, of the text. The
 *        high word specifies the type of operation used to draw the text.
 *        The type can be one of the following values: Value Description 0
 *        The text is drawn with a border to appear lower than the plane of
 *        the window. SBT_NOBORDERS The text is drawn without borders.
 *        SBT_POPOUT The text is drawn with a border to appear higher than
 *        the plane of the window. SBT_RTLREADING Displays text using
 *        right-to-left reading order on Hebrew or Arabic systems.
 */
#define SB_GETTEXT	SB_GETTEXTW
/**
 * This message sets the text in the specified part of a status window.
 *
 * @param iPart Zero-based index of the part to set. If this value is 255,
 *        the status window is assumed to be a simple window having only
 *        one part.
 * @param uType Type of drawing operation. It is one of the following
 *        values: Value Description 0 The text is drawn with a border to
 *        appear lower than the plane of the window. SBT_NOBORDERS The text
 *        is drawn without borders. SBT_OWNERDRAW The text is drawn by the
 *        parent window. SBT_POPOUT The text is drawn with a border to
 *        appear higher than the plane of the window. SBT_RTLREADING
 *        Displays text using right-to-left reading order on Hebrew or
 *        Arabic systems.
 * @param szText Null-terminated string that specifies the text to set. If
 *        uType is SBT_OWNERDRAW, this parameter represents 32 bits of
 *        data. The parent window must interpret the data and draw the text
 *        when it receives the WM_DRAWITEM message. The text for each part
 *        is limited to 127 characters.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define SB_SETTEXT	SB_SETTEXTW
/**
 * This message retrieves the length, in characters, of the text from the
 * specified part of a status window.
 *
 * @param iPart Zero-based index of the part from which to retrieve text.
 * @return Returns a 32-bit value that consists of two 16-bit values. The
 *        low word specifies the length, in characters, of the text. The
 *        high word specifies the type of operation used to draw the text.
 *        The type can be one of the following values: Value Description 0
 *        The text is drawn with a border to appear lower than the plane of
 *        the window. SBT_NOBORDERS The text is drawn without borders.
 *        SBT_OWNERDRAW The text is drawn by the parent window. SBT_POPOUT
 *        The text is drawn with a border to appear higher than the plane
 *        of the window. SBT_RTLREADING Displays text using right-to-left
 *        reading order on Hebrew or Arabic systems.
 */
#define SB_GETTEXTLENGTH	SB_GETTEXTLENGTHW
/**
 * This message inserts a new item into a header control. You can send this
 * message explicitly or use the Header_InsertItem macro.
 *
 * @param index Index of the item after which the new item is inserted. The
 *        new item is inserted at the end of the header control if index is
 *        greater than or equal to the number of items in the control. If
 *        index is zero, the new item is inserted at the beginning of the
 *        header control.
 * @param phdi Pointer to an HDITEM structure that contains data about the
 *        new item
 * @return The index of the new item indicates success. -1 indicates
 *        failure.
 */
#define HDM_INSERTITEM HDM_INSERTITEMW
/**
 * This message retrieves data about an item in a header control. You can
 * send this message explicitly or use the Header_GetItem macro.
 *
 * @param index Index of the item for which data is retrieved
 * @param phdi Pointer to an HDITEM structure. When the message is sent,
 *        the mask member indicates the type of data requested. When the
 *        message returns, the other members receive the requested data. If
 *        the mask member specifies zero, the message returns TRUE, but
 *        copies no data to the structure.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define HDM_GETITEM HDM_GETITEMW
/**
 * This message sets the specified item attributes in a header control. You
 * can send this message explicitly or use the Header_SetItem macro.
 *
 * @param iIndex Current index of the item whose attributes are changed
 * @param phdItem Pointer to an HDITEM structure that contains item data.
 *        When this message is sent, the mask member of the structure must
 *        be set to indicate which attributes are set.
 * @return Nonzero indicates success. Zero indicates failure.
 */
#define HDM_SETITEM HDM_SETITEMW
/**
 * This notification message notifies a header control parent window the
 * header item attributes are about to change. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * @param phdr Pointer to an NMHEADER structure that contains data about
 *        the header control and the header item, including the attributes
 *        about to change.
 * @return TRUE prevents the changes. FALSE accepts the changes.
 */
#define HDN_ITEMCHANGING	HDN_ITEMCHANGINGW
/**
 * This notification message notifies a header control parent window the
 * header item attributes have changed. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * @param phdr Pointer to an NMHEADER structure that contains data about
 *        the header control, including attributes that have changed.
 * @return None
 */
#define HDN_ITEMCHANGED	HDN_ITEMCHANGEDW
/**
 * This notification message notifies a header control parent window that
 * the user tapped the control. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param phdr Pointer to an NMHEADER structure that identifies the header
 *        control and specifies the index of the header item clicked and
 *        the mouse button used to click the item. The pItem member is set
 *        to NULL.
 * @return None
 */
#define HDN_ITEMCLICK	HDN_ITEMCLICKW
/**
 * This notification message notifies a header control parent window that
 * the user double-tapped the control. It is sent in the form of a
 * WM_NOTIFY message. Only header controls with the HDS_BUTTONS style send
 * this notification.
 *
 * @param pnmhdr Pointer to an NMHEADER structure that contains data about
 *        this notification.
 * @return None
 */
#define HDN_ITEMDBLCLICK	HDN_ITEMDBLCLICKW
/**
 * This notification message notifies a header control's parent window that
 * the user double-tapped the divider area of the control. It is sent in
 * the form of a WM_NOTIFY message.
 *
 * @param phdn Pointer to an NMHEADER structure that contains data about
 *        the header control and the item whose divider was double-clicked
 * @return None
 */
#define HDN_DIVIDERDBLCLICK	HDN_DIVIDERDBLCLICKW
/**
 * This notification message notifies a header control parent window the
 * user has begun dragging a divider in the control; that is, the user has
 * pressed the stylus to the touch screen over a divider in the header
 * control. It is sent in the form of a WM_NOTIFY message.
 *
 * @param phdn Pointer to an NMHEADER structure that contains data about
 *        the header control and the item whose divider is dragged.
 * @return TRUE prevents tracking. FALSE enables tracking of the divider.
 */
#define HDN_BEGINTRACK	HDN_BEGINTRACKW
/**
 * This notification message notifies a header control parent window that
 * the user has finished dragging a divider. It sent in the form of a
 * WM_NOTIFY message.
 *
 * @param phdn Pointer to an NMHEADER structure that contains data about
 *        the header control and the item whose divider was dragged
 * @return None
 */
#define HDN_ENDTRACK	HDN_ENDTRACKW
/**
 * This notification message notifies a header control parent window the
 * user is dragging a divider in the header control. It is sent in the form
 * of a WM_NOTIFY message.
 *
 * @param phdr Pointer to an NMHEADER structure that contains data about
 *        the header control and the item whose divider is dragged
 * @return TRUE ends tracking. FALSE continues tracking.
 */
#define HDN_TRACK	HDN_TRACKW
#if (_WIN32_IE >= 0x0300)
/**
 * This notification message is sent to the owner of a header control when
 * the control needs data about a callback header item. It is sent as a
 * WM_NOTIFY message.
 *
 * Fill the appropriate members of the structure to return the requested
 * data to the header control. If your message handler sets the mask member
 * of the NMHDDISPINFO structure to HDI_DI_SETITEM, the header control
 * stores the data and will not request it again.
 *
 * @param pDispInfo Pointer to an NMHDDISPINFO structure. On input, the
 *        members of the structure specify what data is required and the
 *        item of interest.
 */
#define HDN_GETDISPINFO HDN_GETDISPINFOW
#endif
/**
 * This structure contains information used to process notification
 * messages from a header control. This structure is superseded by the
 * NMHEADER structure.
 */
#define HD_NOTIFY HD_NOTIFYW
#define TBSAVEPARAMS TBSAVEPARAMSW
/**
 * This message retrieves the text of a button in a toolbar.
 *
 * @param idButton Command identifier of the button for which to retrieve
 *        text.
 * @param lpszText Long pointer to a buffer that receives the button text.
 * @return The length-in characters and not including the terminating null
 *        character-of the string copied to the specified buffer indicates
 *        success. -1 indicates failure.
 */
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
#define TB_SAVERESTORE TB_SAVERESTOREW
/**
 * This message adds a new string to the list of strings available for a
 * toolbar.
 *
 * The resource identifier in the idString parameter has to reference a
 * single string without substrings or separators.
 *
 * @param hinst Handle to the module instance with an executable file that
 *        contains the string resource. If idString points to one or more
 *        strings to add, this parameter is zero.
 * @param idString Resource identifier of the string resource, or the
 *        address of a buffer that contains one or more null-terminated
 *        strings to add to the list, depending on the value of hinst. The
 *        last string must be terminated with two null characters.
 * @return The index of the first new string indicates success. -1
 *        indicates failure.
 */
#define TB_ADDSTRING TB_ADDSTRINGW
/**
 * This notification message retrieves toolbar customization information
 * and notifies the toolbar's parent window of any changes being made to
 * the toolbar. It is sent in the form of a WM_NOTIFY message.
 *
 * @param lpnmtb Long pointer to an NMTOOLBAR structure. The iItem member
 *        specifies a zero-based index that provides a count of the buttons
 *        the Customize Toolbar dialog box displays as both available and
 *        present on the toolbar. The pszText member specifies the address
 *        of the current button text, and cchText specifies its length in
 *        characters. The application should fill the structure with
 *        information about the button.
 * @return TRUE indicates that button information was copied to the
 *        specified structure. FALSE indicates otherwise.
 */
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
#if _WIN32_IE >= 0x400
/**
 * This message retrieves the information for a button in a toolbar.
 *
 * @param iID Button identifier.
 * @param lptbbi Long pointer to a TBBUTTONINFO structure that receives the
 *        button information. The cbSize and dwMask members of this
 *        structure must be filled in prior to sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_GETBUTTONINFO TB_GETBUTTONINFOW
/**
 * This message sets the information for an existing button in a toolbar.
 *
 * @param iID Button identifier.
 * @param lptbbi Long pointer to a TBBUTTONINFO structure that contains the
 *        new button information. The cbSize and dwMask members of this
 *        structure must be filled in prior to sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define TB_SETBUTTONINFO TB_SETBUTTONINFOW
#define TB_INSERTBUTTON TB_INSERTBUTTONW
#define TB_ADDBUTTONS TB_ADDBUTTONSW
#define TB_MAPACCELERATOR TB_MAPACCELERATORW
#define TB_GETSTRING TB_GETSTRINGW
/**
 * This structure contains or receives information for a specific button in
 * a toolbar.
 */
#define TBBUTTONINFO TBBUTTONINFOW
#define LPTBBUTTONINFO LPTBBUTTONINFOW
#define TBN_GETDISPINFO TBN_GETDISPINFOW
#define NMTBDISPINFO NMTBDISPINFOW
#define LPNMTBDISPINFO LPNMTBDISPINFOW
#define NMTBGETINFOTIP NMTBGETINFOTIPW
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPW
#endif
#define TBNOTIFY TBNOTIFYW
#define LPTBNOTIFY LPTBNOTIFYW
/**
 * This structure contains information used to process toolbar notification
 * messages. It is identical to the TBNOTIFY structure.
 */
#define NMTOOLBAR NMTOOLBARW
#define LPNMTOOLBAR LPNMTOOLBARW
#define TTM_ADDTOOL	TTM_ADDTOOLW
#define TTM_DELTOOL	TTM_DELTOOLW
#define TTM_NEWTOOLRECT	TTM_NEWTOOLRECTW
#define TTM_GETTOOLINFO	TTM_GETTOOLINFOW
#define TTM_SETTOOLINFO	TTM_SETTOOLINFOW
#define TTM_HITTEST	TTM_HITTESTW
#define TTM_GETTEXT	TTM_GETTEXTW
#define TTM_UPDATETIPTEXT	TTM_UPDATETIPTEXTW
#define TTM_ENUMTOOLS	TTM_ENUMTOOLSW
#define TTM_GETCURRENTTOOL	TTM_GETCURRENTTOOLW
#define TTN_NEEDTEXT TTN_NEEDTEXTW
#define TTN_GETDISPINFO TTN_GETDISPINFOW
#define SB_GETTEXT	SB_GETTEXTW
#define SB_SETTEXT	SB_SETTEXTW
#define SB_GETTEXTLENGTH	SB_GETTEXTLENGTHW
/**
 * This structure specifies or receives the attributes of a list view item,
 * and is superceded by the LVITEM structure.
 *
 * The LV_ITEM structure is used with a number of messages, including
 * LVM_GETITEM, LVM_SETITEM, LVM_INSERTITEM, and LVM_DELETEITEM.
 */
#define LV_ITEM LV_ITEMW
/**
 * This structure that specifies or receives the attributes of a list view
 * item. It has been updated to support a new mask value (LVIF_INDENT) that
 * enables item indenting.
 *
 * The LVITEM structure is used with a number of messages, including
 * LVM_GETITEM, LVM_SETITEM, LVM_INSERTITEM, and LVM_DELETEITEM.
 *
 * This structure supersedes the LV_ITEM structure.
 *
 * Size of the buffer pointed to by the pszText member if the structure is
 * receiving item attributes. This member is ignored if the structure
 * specifies item attributes.
 */
#define LVITEM LVITEMW
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKW
#if _WIN32_IE >= 0x0400
#define LVBKIMAGE	LVBKIMAGEW
#define LPLVBKIMAGE	LPLVBKIMAGEW
#define LVM_SETBKIMAGE	LVM_SETBKIMAGEW
#define LVM_GETBKIMAGE	LVM_GETBKIMAGEW
#endif /* _WIN32_IE >= 0x400 */
/**
 * This message retrieves some or all of a list view item's attributes. You
 * can send this message explicitly or by using the ListView_GetItem macro.
 *
 * @param pitem Pointer to an LVITEM structure that specifies the data to
 *        retrieve and receives data about the list view item. When the
 *        message is sent, the iItem and iSubItem members identify the item
 *        or subitem to retrieve data about, and the mask member specifies
 *        which attributes to retrieve. For a list of possible values, see
 *        the description of the LVITEM structure. If the mask member
 *        specifies the LVIF_TEXT value, the pszText member must contain
 *        the address of the buffer that receives the item text, and the
 *        cchTextMax member must specify the size of the buffer. If the
 *        mask member specifies the LVIF_STATE value, the stateMask member
 *        must specify the item state bits to retrieve. On output, the
 *        state member contains the values of the specified state bits.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_GETITEM	LVM_GETITEMW
/**
 * This message sets some or all of a list view item's attributes. You can
 * send this message explicitly or by using the ListView_SetItem macro.
 *
 * If the mask member specifies the LVIF_TEXT value, the pszText member is
 * the address of a null-terminated string and the cchTextMax member is
 * ignored.
 *
 * If the mask member specifies the LVIF_STATE value, the stateMask member
 * specifies which item states to change and the state member contains the
 * values for those states.
 *
 * To set the attributes of a list view item, set the iItem member of the
 * LVITEM structure to the index of the item, and set the iSubItem member
 * to zero. For an item, you can set the state, pszText, iImage, and lParam
 * members of the LVITEM structure.
 *
 * @param pitem Pointer to an LVITEM structure that contains the new item
 *        attributes. The iItem and iSubItem members identify the item or
 *        subitem, and the mask member specifies which attributes to set.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETITEM LVM_SETITEMW
/**
 * This message inserts a new item in a list view control. You can send
 * this message explicitly or by using the ListView_InsertItem macro.
 *
 * @param pitem Pointer to an LVITEM structure that specifies the
 *        attributes of the list view item. The iItem member specifies the
 *        index of the new item. You cannot use ListView_InsertItem or
 *        LVM_INSERTITEM to insert subitems; the iSubItem member of the
 *        LVITEM structure must be zero.
 * @return The index of the new item indicates success. -1 indicates
 *        failure.
 */
#define LVM_INSERTITEM LVM_INSERTITEMW
/**
 * This structure contains information used to search for a list view item.
 * This structure is identical to the LVFINDINFO structure, but was renamed
 * to fit standard naming conventions.
 */
#define LV_FINDINFO LV_FINDINFOW
/**
 * This structure that contains information used to search for a list view
 * item.
 *
 * This structure supersedes the LV_FINDINFO structure.
 */
#define LVFINDINFO LVFINDINFOW
#define LPFINDINFO LPFINDINFOW
/**
 * This structure that contains information the owner needs to find items
 * requested by a virtual list view control. This structure is sent to the
 * owner during notification using the LVN_ODFINDITEM message.
 */
#define NMLVFINDITEM NMLVFINDITEMW
#define PNMLVFINDITEM PNMLVFINDITEMW
#define LPNMLVFINDITEM LPNMLVFINDITEMW
/**
 * This message searches for a list view item with the specified
 * characteristics. You can send this message explicitly or by using the
 * ListView_FindItem macro.
 *
 * @param iStart Index of the item to begin the search with or -1 to start
 *        from the beginning. The specified item is itself excluded from
 *        the search.
 * @param plvfi Pointer to an LVFINDINFO structure that contains data about
 *        what to search for.
 * @return The index of the item indicates success. -1 indicates failure.
 */
#define LVM_FINDITEM LVM_FINDITEMW
/**
 * This message determines the width of a specified string, using the
 * specified list view control's current font. You can send this message
 * explicitly or by using the ListView_GetStringWidth macro.
 *
 * @param psz Pointer to a null-terminated string
 * @return The string width indicates success. Zero indicates failure.
 */
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
/**
 * This message begins in-place editing of the specified list view item's
 * text. The message implicitly selects and focuses the specified item. You
 * can send this message explicitly or by using the ListView_EditLabel
 * macro.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but you should not destroy it.
 *
 * The control must have the focus before you send this message to the
 * control. Focus can be set using the SetFocus function.
 *
 * @param iItem Index of the list view item. To cancel editing, set iItem
 *        to -1.
 * @return The handle to the edit control that is used to edit the item
 *        text indicates success. NULL indicates otherwise.
 */
#define LVM_EDITLABEL LVM_EDITLABELW
/**
 * This structure contains information about a column in report view. This
 * structure is also used to receive information about a column, and is
 * superseded by the LVCOLUMN structure.
 *
 * This structure is used with the LVM_GETCOLUMN, LVM_SETCOLUMN,
 * LVM_INSERTCOLUMN, and LVM_DELETECOLUMN messages.
 */
#define LV_COLUMN LV_COLUMNW
/**
 * This structure contains information about a column in report view. This
 * structure is used both for creating columns and manipulating them using
 * messages. The structure was extended to support new mask values. Two new
 * members, iOrder and iImage, were added to support the new mask values.
 *
 * This structure supersedes the LV_COLUMN structure.
 *
 * This structure is used with the LVM_GETCOLUMN, LVM_SETCOLUMN,
 * LVM_INSERTCOLUMN, and LVM_DELETECOLUMN messages.
 */
#define LVCOLUMN LVCOLUMNW
/**
 * This message retrieves the attributes of a list view control column. You
 * can send this message explicitly or by using the ListView_GetColumn
 * macro.
 *
 * @param iCol Index of the column.
 * @param pcol Pointer to an LVCOLUMN structure that specifies the data to
 *        retrieve and receives data about the column. The mask member
 *        specifies which column attributes to retrieve. If the mask member
 *        specifies the LVCF_TEXT value, the pszText member must contain
 *        the address of the buffer that receives the item text and the
 *        cchTextMax member must specify the size of the buffer.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_GETCOLUMN LVM_GETCOLUMNW
/**
 * This message sets the attributes of a list view column. You can send
 * this message explicitly or by using the ListView_SetColumn macro.
 *
 * @param iCol Index of the column
 * @param pcol Pointer to an LVCOLUMN structure that contains the new
 *        column attributes. The mask member specifies which column
 *        attributes to set. If the mask member specifies the LVCF_TEXT
 *        value, the pszText member is the address of a null-terminated
 *        string and the cchTextMax member is ignored.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define LVM_SETCOLUMN LVM_SETCOLUMNW
/**
 * This message inserts a new column in a list view control. You can send
 * this message explicitly or by using the ListView_InsertColumn macro.
 *
 * @param iCol Index of the new column
 * @param pcol Pointer to an LVCOLUMN structure that contains the
 *        attributes of the new column
 * @return The index of the new column indicates success. -1 indicates
 *        failure.
 */
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNW
/**
 * This message retrieves the text of a list view item or subitem. You can
 * send this message explicitly or by using the ListView_GetItemText macro.
 *
 * @param iItem Index of the list view item.
 * @param pitem Pointer to an LVITEM structure. The iSubItem member
 *        specifies the index of a subitem, or it can be zero to get the
 *        item label. The pszText member points to a buffer that receives
 *        the text, and the cchTextMax member specifies the size of the
 *        buffer.
 * @return If you send this message explicitly, it returns the length of
 *        the retrieved string. If you can send this message implicitly by
 *        using the ListView_GetItemText macro, there is no return value.
 */
#define LVM_GETITEMTEXT LVM_GETITEMTEXTW
/**
 * This message changes the text of a list view item or subitem. You can
 * send this message explicitly or by using the ListView_SetItemText macro.
 *
 * @param i Index of the list view item
 * @param pitem Pointer to an LVITEM structure. The iSubItem member is the
 *        index of the subitem, or it can be zero to set the item label.
 *        The pszText member is the address of a null-terminated string
 *        containing the new text; it can also be NULL. The pszText member
 *        can also be LPSTR_TEXTCALLBACK to indicate a callback item for
 *        which the parent window stores the text. In this case, the list
 *        view control sends the parent an LVN_GETDISPINFO notification
 *        message when it needs the text.
 * @return If you send this message explicitly, TRUE indicates success.
 *        FALSE indicates failure.
 */
#define LVM_SETITEMTEXT LVM_SETITEMTEXTW
/**
 * This message retrieves the incremental search string of a list view
 * control. You can send this message explicitly or by using the
 * ListView_GetISearchString macro.
 *
 * @param lpsz Long pointer to a buffer that receives the incremental
 *        search string. The incremental search string is the character
 *        sequence that the user types while the list view has the input
 *        focus. Each time the user types a character, the system appends
 *        the character to the search string and then searches for a
 *        matching item. If the system finds a match, it selects the item
 *        and, if necessary, scrolls it into view.
 * @return The number of characters in the incremental search string
 *        indicates success. Zero indicates that the list view control is
 *        not in incremental search mode.
 */
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
/**
 * This notification message notifies a list view control parent window
 * about the start of label editing for an item. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * @param pdi Pointer to an NMLVDISPINFO structure. The item member of this
 *        structure is an LVITEM structure whose iItem member identifies
 *        the item being edited.
 * @return TRUE prevents the user from editing the label. FALSE enables the
 *        user to edit the label.
 */
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
/**
 * This notification message notifies a list view control parent window
 * about the end of label editing for an item. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * @param pdi Pointer to an NMLVDISPINFO structure. The item member of this
 *        structure is an LVITEM structure whose iItem member identifies
 *        the item being edited. The pszText member of item contains a
 *        valid value when the LVN_ENDLABELEDIT message is sent, regardless
 *        of whether the LVIF_TEXT flag is set in the mask member of the
 *        LVITEM structure. If the user cancels editing, the pszText member
 *        of the LVITEM structure is NULL; otherwise, pszText is the
 *        address of the edited text.
 * @return If the pszText member of the LVITEM structure is non-NULL,
 *        return TRUE to set the item's label to the edited text. Return
 *        FALSE to reject the edited text and revert to the original label.
 *        If the pszText member of the LVITEM structure is NULL, the return
 *        value is ignored.
 */
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
/**
 * This notification message requests a list view control parent window to
 * provide data needed to display or sort an item. It is sent in the form
 * of a WM_NOTIFY message.
 *
 * A list view control sends the LVN_GETDISPINFO notification to retrieve
 * item data stored by the application rather than the control. The data
 * can be text or icon data for an item. It can also be item state data.
 * See the LVM_SETCALLBACKMASK message for more information on implementing
 * item state on a callback basis.
 *
 * For more information on list view callbacks, see the Windows CE User
 * Interface Services Guide.
 *
 * @param pnmv Pointer to an NMLVDISPINFO structure. On input, the LVITEM
 *        structure contained in this structure specifies the type of data
 *        required and identifies the item or subitem of interest. Use the
 *        LVITEM structure to return the requested data to the control. If
 *        your message handler sets the LVIF_DI_SETITEM flag in the mask
 *        member of the LVITEM structure, the list view control stores the
 *        requested data and will not ask for it again.
 * @return None
 */
#define LVN_GETDISPINFO LVN_GETDISPINFOW
/**
 * This notification message notifies a list view control parent window
 * that it must update the data it maintains for an item. It is sent in the
 * form of a WM_NOTIFY message.
 *
 * @param pnmv Pointer to an NMLVDISPINFO structure that specifies data for
 *        the changed item. The item member of this structure is an LVITEM
 *        structure that contains data about the item that was changed. The
 *        pszText member of item contains a valid value, regardless of
 *        whether the LVIF_TEXT flag is set in the mask member of this
 *        structure.
 * @return None
 */
#define LVN_SETDISPINFO LVN_SETDISPINFOW
#define LVN_GETINFOTIP LVN_GETINFOTIPW
#define NMLVGETINFOTIP NMLVGETINFOTIPW
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPW
/**
 * This structure contains information needed to display an owner-drawn
 * item in a list view control. This structure is identical to the
 * NMLVDISPINFO structure, but was renamed to fit standard naming
 * conventions.
 */
#define LV_DISPINFO LV_DISPINFOW
#define NMLVDISPINFO NMLVDISPINFOW
#define LPNMLVDISPINFO LPNMLVDISPINFOW
/**
 * This message inserts a new item in a tree view control. You can send
 * this message explicitly or by using the TreeView_InsertItem macro.
 *
 * @param lpis Long pointer to a TVINSERTSTRUCT structure that specifies
 *        the attributes of the tree view item.
 * @return The handle to the new item indicates success. NULL indicates
 *        otherwise.
 */
#define TVM_INSERTITEM TVM_INSERTITEMW
/**
 * This message retrieves some or all of a tree view item's attributes. You
 * can send this message explicitly or by using the TreeView_GetItem macro.
 *
 * @param pitem Pointer to a TVITEM structure that specifies the
 *        information to retrieve and receives information about the item.
 *        When the message is sent, the hItem member identifies the item to
 *        retrieve information about and the mask member specifies the
 *        attributes to retrieve. If the mask member specifies the
 *        TVIF_TEXT value, the pszText member must contain the address of
 *        the buffer that receives the item text and the cchTextMax member
 *        must specify the size of the buffer. If the mask member specifies
 *        the TVIF_STATE value, the stateMask member must specify the item
 *        state bits to retrieve. On output, the state member contains the
 *        values of the specified state bits.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TVM_GETITEM TVM_GETITEMW
/**
 * This message sets some or all of a tree view item's attributes. You can
 * send this message explicitly or by using the TreeView_SetItem macro.
 *
 * @param pitem Pointer to a TVITEM structure that contains the new item
 *        attributes. The hItem member identifies the item, and the mask
 *        member specifies which attributes to set. If mask specifies the
 *        TVIF_TEXT value, the pszText member is the address of a
 *        null-terminated string and the cchTextMax member is ignored. If
 *        mask specifies the TVIF_STATE value, the stateMask member
 *        indicates which item states to change and the state member
 *        contains the values for those states.
 * @return TRUE indicates success. FALSE indicates success.
 */
#define TVM_SETITEM TVM_SETITEMW
/**
 * This message begins in-place editing of the specified item's text,
 * replacing the text of the item with a single-line edit control
 * containing the text. This message implicitly selects and focuses the
 * specified item. You can send this message explicitly or by using the
 * TreeView_EditLabel macro.
 *
 * This message sends a TVN_BEGINLABELEDIT notification message to the
 * parent of the tree view control.
 *
 * When the user completes or cancels editing, the edit control is
 * destroyed and the handle is no longer valid. You can safely subclass the
 * edit control, but do not destroy it.
 *
 * @param hitem Handle to the item to edit.
 * @return The handle to the edit control used to edit the item text
 *        indicates success. NULL indicates otherwise.
 */
#define TVM_EDITLABEL TVM_EDITLABELW
/**
 * This message retrieves the incremental search string for a tree view
 * control. The tree view control uses the incremental search string to
 * select an item based on characters entered by the user. You can send
 * this message explicitly or by using the TreeView_GetISearchString macro.
 *
 * @param lpsz Long pointer to the buffer that receives the incremental
 *        search string.
 * @return Returns the number of characters in the incremental search
 *        string.
 */
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
/**
 * This structure contains and retrieves 6/30, a-laurha: "retrieves and
 * sets" is the CE purpose statement; "contains and retrieves" was the
 * Win32 purpose statement; which is correct?and sets information about a
 * tree view item. This structure is identical to the NMTVDISPINFO
 * structure, but was renamed to follow standard naming conventions.
 */
#define TV_DISPINFO NMTVDISPINFOW
#define NMTVDISPINFO NMTVDISPINFOW
#define LPNMTVDISPINFO LPNMTVDISPINFOW
#if (_WIN32_IE >= 0x0400)
#define NMTVGETINFOTIP NMTVGETINFOTIPW
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPW
#define TVN_GETINFOTIP TVN_GETINFOTIPW
#endif
/**
 * This notification message notifies a tree view control's parent window
 * that the selection is about to change from one item to another. It is
 * sent in the form of a WM_NOTIFY message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemOld and itemNew
 *        members contain valid information about the currently selected
 *        item and the newly selected item. The action member indicates
 *        whether a mouse or keyboard action is causing the selection to
 *        change. For a list of possible values, see the description of the
 *        TVN_SELCHANGED notification message.
 * @return TRUE prevents the selection from changing.
 */
#define TVN_SELCHANGING TVN_SELCHANGINGW
/**
 * This notification message notifies a tree view control's parent window
 * that the selection has changed from one item to another. It is sent in
 * the form of a WM_NOTIFY message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemOld and itemNew
 *        members of the NMTREEVIEW structure are TVITEM structures that
 *        contain information about the previously selected item and the
 *        newly selected item. Only the mask, hItem, state, and lParam
 *        members of these structures are valid. The stateMask members of
 *        the TVITEM structures specified by itemOld and itemNew are
 *        undefined on input. The action member of the NMTREEVIEW structure
 *        indicates the type of action that caused the selection to change.
 *        It is one of the following values: Value Description
 *        TVC_BYKEYBOARD By a keystroke. TVC_BYMOUSE By a mouse click.
 *        TVC_UNKNOWN Unknown.
 * @return The return value is ignored.
 */
#define TVN_SELCHANGED TVN_SELCHANGEDW
/**
 * This notification message requests that a tree view control's parent
 * window provide information needed to display or sort an item. It is sent
 * in the form of a WM_NOTIFY message.
 *
 * This notification is sent under the following circumstances:
 *
 * If the pszText member of the item's TVITEM structure is the
 * LPSTR_TEXTCALLBACK value, the control sends this notification to
 * retrieve the item's text. In this case, the mask member of lptvdi will
 * have the TVIF_TEXT flag set.
 *
 * If the iImage or iSelectedImage member of the item's TVITEM structure is
 * the I_IMAGECALLBACK value, the control sends this notification to
 * retrieve the index of an item's icons in the control's image list. In
 * this case, if the item is selected, the mask member of lptvdi will have
 * the TVIF_SELECTEDIMAGE flag set. If the item is not selected, the mask
 * member of lptvdi will have the TVIF_IMAGE flag set.
 *
 * If the cChildren member of the item's TVITEM structure is the
 * I_CHILDRENCALLBACK value, the control sends this notification to
 * retrieve a value that indicates whether the item has child items. In
 * this case, the mask member of lptvdi will have the TVIF_CHILDREN flag
 * set.
 *
 * @param lptvdi Long pointer to an NMTVDISPINFO structure. The item member
 *        is a TVITEM structure whose mask, hItem, state, and lParam
 *        members specify the type of information required. You must fill
 *        the members of the structure with the appropriate information.
 * @return The return value is ignored.
 */
#define TVN_GETDISPINFO TVN_GETDISPINFOW
/**
 * This notification message notifies a tree view control's parent window
 * that it must update the information it maintains about an item. It is
 * sent in the form of a WM_NOTIFY message.
 *
 * @param lptvdi Long pointer to an NMTVDISPINFO structure. The itemOld and
 *        itemNew members contain valid information about the currently
 *        selected item and the newly selected item. The action member
 *        indicates whether a mouse or keyboard action is causing the
 *        selection to change. For a list of possible values, see the
 *        description of the TVN_SELCHANGED notification message.
 * @return The return value is ignored.
 */
#define TVN_SETDISPINFO TVN_SETDISPINFOW
/**
 * This notification message notifies a tree view control's parent window
 * that a parent item's list of child items is about to expand or collapse.
 * It is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemNew member is a
 *        TVITEM structure that contains valid information about the parent
 *        item in the hItem, state, and lParam members. The action member
 *        indicates whether the list is to expand or collapse. For a list
 *        of possible values, see the description of the TVM_EXPAND
 *        message.
 * @return TRUE prevents the list from expanding or collapsing.
 */
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
/**
 * This notification message notifies a tree view control's parent window
 * that a parent item's list of child items has expanded or collapsed. It
 * is sent in the form of a WM_NOTIFY message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemNew member is a
 *        TVITEM structure that contains valid information about the parent
 *        item in the hItem, state, and lParam members. The action member
 *        indicates whether the list expanded or collapsed. For a list of
 *        possible values, see the description of the TVM_EXPAND message.
 * @return The return value is ignored.
 */
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
/**
 * This notification message notifies a tree view control's parent window
 * that a drag-and-drop operation is being initiated. It is sent in the
 * form of a WM_NOTIFY message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemNew member is a
 *        TVITEM structure that contains valid information about the item
 *        being dragged in the hItem, state, and lParam members. The ptDrag
 *        member specifies the current screen coordinates of the mouse.
 * @return The return value is ignored.
 */
#define TVN_BEGINDRAG TVN_BEGINDRAGW
#define TVN_BEGINRDRAG TVN_BEGINRDRAGW
/**
 * This notification message notifies a tree view control's parent window
 * that an item has been deleted. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * @param pnmtv Pointer to an NMTREEVIEW structure. The itemOld member is a
 *        TVITEM structure whose hItem and lParam members contain valid
 *        information about the item being deleted.
 * @return The return value is ignored.
 */
#define TVN_DELETEITEM TVN_DELETEITEMW
/**
 * This notification message notifies a tree view control's parent window
 * about the start of label editing for an item. It is sent in the form of
 * a WM_NOTIFY message.
 *
 * @param ptvdi Pointer to an NMTVDISPINFO structure. The item member is a
 *        TVITEM structure that contains valid information about the item
 *        being edited in the hItem, state, lParam, and pszText members.
 * @return TRUE cancels label editing.
 */
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
/**
 * This notification message notifies a tree view control's parent window
 * about the end of label editing for an item. It is sent in the form of a
 * WM_NOTIFY message.
 *
 * If the pszText member is NULL, the return value is ignored.
 *
 * @param ptvdi Pointer to an NMTVDISPINFO structure. The item member of
 *        this structure is a TVITEM structure whose hItem, lParam, and
 *        pszText members contain valid information about the item that was
 *        edited. If label editing was canceled, the pszText member of the
 *        TVITEM structure is NULL; otherwise, pszText is the address of
 *        the edited text.
 * @return If the pszText member is non-NULL, return TRUE to set the item's
 *        label to the edited text. Return FALSE to reject the edited text
 *        and revert to the original label.
 */
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
/**
 * This structure specifies or receives the attributes of a tab, and is
 * superseded by the TCITEMHEADER structure.
 *
 * This structure is the same as the TC_ITEM structure, except that it does
 * not include an lParam member for application-defined data.
 */
#define TC_ITEMHEADER TC_ITEMHEADERW
/**
 * This structure specifies or receives the attributes of a tab. It is used
 * with the TCM_INSERTITEM, TCM_GETITEM, and TCM_SETITEM messages.
 *
 * This structure supersedes the TC_ITEMHEADER structure.
 */
#define TCITEMHEADER TCITEMHEADERW
#define LPTCITEMHEADER LPTCITEMHEADERW
/**
 * This structure specifies or receives the attributes of a tab, and is
 * superseded by the TCITEM structure.
 */
#define TC_ITEM TC_ITEMW
/**
 * This structure specifies or receives the attributes of a tab item. It is
 * used with the TCM_INSERTITEM, TCM_GETITEM, and TCM_SETITEM messages.
 *
 * This structure supersedes the TC_ITEM structure.
 */
#define TCITEM TCITEMW
#define LPTCITEM LPTCITEMW
/**
 * This message retrieves information about a tab in a tab control. You can
 * send this message explicitly or by using the TabCtrl_GetItem macro.
 *
 * @param iItem Index of the tab.
 * @param pitem Pointer to a TCITEM structure that specifies the
 *        information to retrieve and receives information about the tab.
 *        When the message is sent, the mask member specifies which
 *        attributes to return. If the mask member specifies the TCIF_TEXT
 *        value, the pszText member must contain the address of the buffer
 *        that receives the item text, and the cchTextMax member must
 *        specify the size of the buffer.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_GETITEM TCM_GETITEMW
/**
 * This message sets some or all of a tab's attributes. You can send this
 * message explicitly or by using the TabCtrl_SetItem macro.
 *
 * @param iItem Index of the item.
 * @param pitem Pointer to a TCITEM structure that contains the new item
 *        attributes. The mask member specifies which attributes to set. If
 *        the mask member specifies the LVIF_TEXT value, the pszText member
 *        is the address of a null-terminated string and the cchTextMax
 *        member is ignored.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define TCM_SETITEM TCM_SETITEMW
/**
 * This message inserts a new tab in a tab control. You can send this
 * message explicitly or by using the TabCtrl_InsertItem macro.
 *
 * @param iItem Index of the new tab.
 * @param pitem Pointer to a TCITEM structure that specifies the attributes
 *        of the tab. The dwState and dwStateMask members of this structure
 *        are ignored by this message.
 * @return The index of the new tab indicates success. -1 indicates
 *        otherwise.
 */
#define TCM_INSERTITEM TCM_INSERTITEMW
/**
 * Creates a status bar, normally along the bottom of the parent window.
 *
 * A wrapper for CreateWindow with default position and size.
 *
 * @param style Window styles. Must include WS_CHILD and normally WS_VISIBLE.
 * @param lpszText Text for the first part.
 * @param hwndParent Parent window.
 * @param wID Control identifier, used in notifications to the parent.
 * @return The status bar, or NULL on failure.
 */
#define CreateStatusWindow CreateStatusWindowW
/**
 * Draws text with a border, in the style of a status bar.
 *
 * A tab in the text centres what follows it; two tabs right-align it.
 *
 * @param hdc Device context to draw into.
 * @param lprc Rectangle to draw in, in client coordinates. The border is
 *        drawn just inside it.
 * @param szText The text.
 * @param uFlags 0, SBT_NOBORDERS for no border, or SBT_POPOUT for a raised
 *        border.
 */
#define DrawStatusText DrawStatusTextW
#define ImageList_LoadImage _WNAME(ImageList_LoadImage)
/**
 * This message sets the display of a date and time picker (DTP) control
 * based on a specified format string.
 *
 * It is acceptable to include extra characters within the format string to
 * produce a richer display. However, any nonformat characters must be
 * enclosed within single quotes. For example, the format string "'Today
 * is: 'hh':'m':'s ddddMMMdd', 'yyy" would produce output like "Today is:
 * 04:22:31 Tuesday Mar 23, 1996".
 *
 * No errors are returned for a bad format string. The function simply
 * forms the best date string that it can. For example, the only year
 * pictures that are valid are L"yyyy" and L"yy" (the 'L' indicates a
 * Unicode (16-bit characters) string). If L"y" is passed in, the function
 * assumes L"yy". If L"yyy" is passed in, the function assumes L"yyyy". If
 * more than 4 date (L"dddd") or 4 month (L"MMMM") pictures are passed in,
 * then the function defaults to L"dddd" or L"MMMM".
 *
 * Any text that should remain in its exact form in the date string should
 * be enclosed within single quotation marks in the date format picture.
 * The single quotation mark may also be used as an escape character to
 * allow the single quotation mark itself to be displayed in the date
 * string. However, the escape sequence must be enclosed within two single
 * quotation marks. For example, to display the date as "May '93", the
 * format string would be: L"MMMM ''''yy" The first and last single
 * quotation marks are the enclosing quotation marks. The second and third
 * single quotation marks are the escape sequence to allow the single
 * quotation mark to be displayed before the century.
 *
 * Note A DTP control tracks locale changes when it is using the default
 * format string. If you set a custom format string, it will not be updated
 * in response to locale changes.
 *
 * @param lpszFormat Long pointer to a null-terminated format string that
 *        defines the desired display. Setting this parameter to NULL will
 *        reset the control to the default format string for the current
 *        style. The format string is a combination of string fragments. It
 *        is interpreted literally, with the exception of the following
 *        string fragments: Value Description "d" The one- or two-digit
 *        day. "dd" The two-digit day. Single-digit day values are preceded
 *        by a zero. "ddd" The three-character weekday abbreviation. "dddd"
 *        The full weekday name. "h" The one- or two-digit hour in 12-hour
 *        format. "hh" The two-digit hour in 12-hour format. Single-digit
 *        values are preceded by a zero. "H" The one- or two-digit hour in
 *        24-hour format. "HH" The two-digit hour in 24-hour format.
 *        Single-digit values are preceded by a zero. "m" The one- or
 *        two-digit minute. "mm" The two-digit minute. Single-digit values
 *        are preceded by a zero. "M" The one- or two-digit month number.
 *        "MM" The two-digit month number. Single-digit values are preceded
 *        by a zero. "MMM" The three-character month abbreviation. "MMMM"
 *        The full month name. "t" The one-letter AM/PM abbreviation; that
 *        is, "AM" is displayed as "A." "tt" The two-letter AM/PM
 *        abbreviation; that is, "AM" is displayed as "AM." "X" A callback
 *        field. The control still uses the other valid format characters,
 *        and queries the owner to fill in the "X" portion. Therefore, the
 *        owner must be prepared to handle the DTN_WMKEYDOWN, DTN_FORMAT,
 *        and DTN_FORMATQUERY notification messages. Multiple "X"
 *        characters can be used in series to signify unique callback
 *        fields. "y" The year is displayed as the last two digits, but
 *        with no leading zero for years less than 10. "yy" The last two
 *        digits of the year; that is, 1996 would be displayed as "96."
 *        "yyyy" The full year; that is, 1996 would be displayed as "1996."
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define DTM_SETFORMAT DTM_SETFORMATW
/**
 * This notification message is sent by a date and time picker (DTP)
 * control when a user completes editing a string in the control. It is
 * only sent by DTP controls that are set to the DTS_APPCANPARSE style.
 *
 * This message is sent in the form of a WM_NOTIFY message.
 *
 * The owner of the control must return zero.
 *
 * Handling this message allows the owner to provide custom responses to
 * strings entered into the control by the user. The owner must be prepared
 * to parse the input string and take action if necessary.
 *
 * @param lpDTstring Long pointer to an NMDATETIMESTRING structure that
 *        contains information about the instance of the notification
 *        message.
 */
#define DTN_USERSTRING DTN_USERSTRINGW
/**
 * This message is sent by a date and time picker (DTP) control when the
 * user types in a callback field. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * Handling this message allows the owner of the control to provide
 * specific responses to keystrokes within the callback fields of the
 * control.
 *
 * @param lpDTKeystroke Long pointer to an NMDATETIMEWMKEYDOWN structure
 *        that contains information about this instance of the
 *        notification. The structure includes information about the key
 *        that the user typed, the substring that defines the callback
 *        field, and the current system date and time.
 * @return The owner of the control must return zero.
 */
#define DTN_WMKEYDOWN DTN_WMKEYDOWNW
/**
 * This notification message is sent by a date and time picker (DTP)
 * control to request text to be displayed in a callback field. It is sent
 * in the form of a WM_NOTIFY message.
 *
 * Handling this message allows the owner of the control to provide a
 * custom string that the control will display. For additional information
 * about callback fields, see Callback Fields.
 *
 * @param lpNMFormat Long pointer to an NMDATETIMEFORMAT structure that
 *        contains information regarding this instance of the notification
 *        message. The structure contains the substring that defines the
 *        callback field and receives the formatted string that the control
 *        will display.
 * @return The owner of the control must return zero.
 */
#define DTN_FORMAT DTN_FORMATW
/**
 * This notification message is sent by a date and time picker (DTP)
 * control to retrieve the maximum allowable size of the string that will
 * be displayed in callback field. It is sent in the form of a WM_NOTIFY
 * message.
 *
 * The owner of the control must calculate the maximum possible width of
 * the text that will be displayed in the callback field, set the szMax
 * member of the NMDATETIMEFORMATQUERY structure, and return zero.
 *
 * Handling this message prepares the control to adjust for the maximum
 * size of the string that will be displayed in a particular callback
 * field. This enables the control to properly display output at all times,
 * reducing flicker within the control's display. For additional
 * information about callback fields, see Callback Fields.
 *
 * @param lpDTFormatQuery Long pointer to an NMDATETIMEFORMATQUERY
 *        structure that contains information about the callback field. The
 *        structure contains a substring that defines a callback field and
 *        receives the maximum allowable size of the of string that will be
 *        displayed in the callback field.
 */
#define DTN_FORMATQUERY DTN_FORMATQUERYW
typedef REBARBANDINFOW REBARBANDINFO,*LPREBARBANDINFO;
#define LPCREBARBANDINFO LPCREBARBANDINFOW
#define REBARBANDINFO_V3_SIZE REBARBANDINFOW_V3_SIZE
/**
 * This message inserts a new band in a rebar control.
 *
 * @param uIndex Zero-based index of the location where the band will be
 *        inserted. If you set this parameter to -1, the control will add
 *        the new band at the last location.
 * @param lprbbi Long pointer to a REBARBANDINFO structure that defines the
 *        band to be inserted. Set the cbSize member of this structure to
 *        sizeof(REBARBANDINFO) before sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_INSERTBAND RB_INSERTBANDW
/**
 * This message sets characteristics of an existing band in a rebar
 * control.
 *
 * @param uBand Zero-based index of the band to receive the new settings.
 * @param lprbbi Long pointer to a REBARBANDINFO structure that contains
 *        the new settings. Set the cbSize member of this structure to
 *        sizeof(REBARBANDINFO) before sending this message.
 * @return Nonzero indicates success. Zero indicates otherwise.
 */
#define RB_SETBANDINFO RB_SETBANDINFOW
#else /* UNICODE */
typedef HDITEMA HDITEM;
typedef TOOLINFOA TOOLINFO,*PTOOLINFO,*LPTOOLINFO;
typedef TTHITTESTINFOA TTHITTESTINFO,*LPHITTESTINFO,*LPTTHITTESTINFO;
typedef TOOLTIPTEXTA TOOLTIPTEXT,*LPTOOLTIPTEXT;
typedef NMTTDISPINFOA NMTTDISPINFO, *LPNMTTDISPINFO;
typedef TV_ITEMA TV_ITEM,*LPTV_ITEM;
typedef TVITEMA TVITEM,*LPTVITEM;
#if (_WIN32_IE >= 0x0400)
typedef TVITEMEXA TVITEMEX,*LPTVITEMEX;
#endif
typedef TV_INSERTSTRUCTA TV_INSERTSTRUCT,*LPTV_INSERTSTRUCT;
typedef TVINSERTSTRUCTA TVINSERTSTRUCT,*LPTVINSERTSTRUCT;
typedef NM_TREEVIEWA NM_TREEVIEW,*LPNM_TREEVIEW;
typedef NMTREEVIEWA NMTREEVIEW,*LPNMTREEVIEW;
typedef NMHDDISPINFOW NMHDDISPINFO, *LPNMHDDISPINFO;
#define ACM_OPEN ACM_OPENA
#define COMBOBOXEXITEM	COMBOBOXEXITEMA
#define PCOMBOBOXEXITEM	PCOMBOBOXEXITEMA
#define PCCOMBOBOXEXITEM	PCCOMBOBOXEXITEMA
#define CBEM_INSERTITEM	CBEM_INSERTITEMA
#define CBEM_SETITEM	CBEM_SETITEMA
#define CBEM_GETITEM	CBEM_GETITEMA
#define CBEN_ENDEDIT	CBEN_ENDEDITA
#define NMCBEENDEDIT	NMCBEENDEDITA
#define LPNMCBEENDEDIT	LPNMCBEENDEDITA
#define PNMCBEENDEDIT	PNMCBEENDEDITA
#if _WIN32_IE >= 0x0400
#define TB_GETBUTTONINFO TB_GETBUTTONINFOA
#define TB_SETBUTTONINFO TB_SETBUTTONINFOA
#define TB_INSERTBUTTON TB_INSERTBUTTONA
#define TB_ADDBUTTONS TB_ADDBUTTONSA
#define TB_MAPACCELERATOR TB_MAPACCELERATORA
#define TB_GETSTRING TB_GETSTRINGA
#define NMCOMBOBOXEX	NMCOMBOBOXEXA
#define PNMCOMBOBOXEX	PNMCOMBOBOXEXA
#define CBEN_DRAGBEGIN	CBEN_DRAGBEGINA
#define CBEN_GETDISPINFO	CBEN_GETDISPINFOA
#define NMCBEDRAGBEGIN	NMCBEDRAGBEGINA
#define LPNMCBEDRAGBEGIN	LPNMCBEDRAGBEGINA
#define PNMCBEDRAGBEGIN	PNMCBEDRAGBEGINA
#define TBN_GETDISPINFO TBN_GETDISPINFOA
#define NMTBDISPINFO NMTBDISPINFOA
#define LPNMTBDISPINFO LPNMTBDISPINFOA
#define NMTBGETINFOTIP NMTBGETINFOTIPA
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPA
#endif /* _WIN32_IE >= 0x0400 */
#define SB_GETTEXT	SB_GETTEXTA
#define SB_SETTEXT	SB_SETTEXTA
#define SB_GETTEXTLENGTH	SB_GETTEXTLENGTHA
#define HDM_INSERTITEM HDM_INSERTITEMA
#define HDM_GETITEM HDM_GETITEMA
#define HDM_SETITEM HDM_SETITEMA
#define HDN_ITEMCHANGING	HDN_ITEMCHANGINGA
#define HDN_ITEMCHANGED	HDN_ITEMCHANGEDA
#define HDN_ITEMCLICK	HDN_ITEMCLICKA
#define HDN_ITEMDBLCLICK	HDN_ITEMDBLCLICKA
#define HDN_DIVIDERDBLCLICK	HDN_DIVIDERDBLCLICKA
#define HDN_BEGINTRACK	HDN_BEGINTRACKA
#define HDN_ENDTRACK	HDN_ENDTRACKA
#define HDN_TRACK	HDN_TRACKA
#if (_WIN32_IE >= 0x0300)
#define HDN_GETDISPINFO HDN_GETDISPINFOA
#endif
#define HD_NOTIFY HD_NOTIFYA
#define TBSAVEPARAMS TBSAVEPARAMSA
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
#define TB_SAVERESTORE TB_SAVERESTOREA
#define TB_ADDSTRING TB_ADDSTRINGA
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
#if _WIN32_IE >= 0x400
#define TBBUTTONINFO TBBUTTONINFOA
#define LPTBBUTTONINFO LPTBBUTTONINFOA
#endif
#define TBNOTIFY TBNOTIFYA
#define LPTBNOTIFY LPTBNOTIFYA
#define NMTOOLBAR NMTOOLBARA
#define LPNMTOOLBAR LPNMTOOLBARA
#define TTM_ADDTOOL	TTM_ADDTOOLA
#define TTM_DELTOOL	TTM_DELTOOLA
#define TTM_NEWTOOLRECT	TTM_NEWTOOLRECTA
#define TTM_GETTOOLINFO	TTM_GETTOOLINFOA
#define TTM_SETTOOLINFO	TTM_SETTOOLINFOA
#define TTM_HITTEST	TTM_HITTESTA
#define TTM_GETTEXT	TTM_GETTEXTA
#define TTM_UPDATETIPTEXT	TTM_UPDATETIPTEXTA
#define TTM_ENUMTOOLS	TTM_ENUMTOOLSA
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
#define TTN_NEEDTEXT TTN_NEEDTEXTA
#define TTN_GETDISPINFO TTN_GETDISPINFOA
#define SB_GETTEXT	SB_GETTEXTA
#define SB_SETTEXT	SB_SETTEXTA
#define SB_GETTEXTLENGTH	SB_GETTEXTLENGTHA
#define LV_ITEM LV_ITEMA
#define LVITEM LVITEMA
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKA
#if _WIN32_IE >= 0x0400
#define LVBKIMAGE	LVBKIMAGEA
#define LPLVBKIMAGE	LPLVBKIMAGEA
#define LVM_SETBKIMAGE	LVM_SETBKIMAGEA
#define LVM_GETBKIMAGE	LVM_GETBKIMAGEA
#endif /* _WIN32_IE >= 0x0400 */
#define LVM_GETITEM	LVM_GETITEMA
#define LVM_SETITEM LVM_SETITEMA
#define LVM_INSERTITEM LVM_INSERTITEMA
#define LV_FINDINFO LV_FINDINFOA
#define LVFINDINFO LVFINDINFOA
#define LPFINDINFO LPFINDINFOA
#define NMLVFINDITEM NMLVFINDITEMA
#define PNMLVFINDITEM PNMLVFINDITEMA
#define LPNMLVFINDITEM LPNMLVFINDITEMA
#define LVM_FINDITEM LVM_FINDITEMA
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
#define LVM_EDITLABEL LVM_EDITLABELA
#define LV_COLUMN LV_COLUMNA
#define LVCOLUMN LVCOLUMNA
#define LVM_GETCOLUMN LVM_GETCOLUMNA
#define LVM_SETCOLUMN LVM_SETCOLUMNA
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNA
#define LVM_GETITEMTEXT LVM_GETITEMTEXTA
#define LVM_SETITEMTEXT LVM_SETITEMTEXTA
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
#define LVN_GETDISPINFO LVN_GETDISPINFOA
#define LVN_SETDISPINFO LVN_SETDISPINFOA
#define LVN_GETINFOTIP LVN_GETINFOTIPA
#define NMLVGETINFOTIP NMLVGETINFOTIPA
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPA
#define LV_DISPINFO LV_DISPINFOA
#define NMLVDISPINFO NMLVDISPINFOA
#define LPNMLVDISPINFO LPNMLVDISPINFOA
#define TVM_INSERTITEM TVM_INSERTITEMA
#define TVM_GETITEM TVM_GETITEMA
#define TVM_SETITEM TVM_SETITEMA
#define TVM_EDITLABEL TVM_EDITLABELA
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
#define TV_DISPINFO NMTVDISPINFOA
#define NMTVDISPINFO NMTVDISPINFOA
#define LPNMTVDISPINFO LPNMTVDISPINFOA
#if (_WIN32_IE >= 0x0400)
#define NMTVGETINFOTIP NMTVGETINFOTIPA
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPA
#define TVN_GETINFOTIP TVN_GETINFOTIPA
#endif
#define TVN_SELCHANGING TVN_SELCHANGINGA
#define TVN_SELCHANGED TVN_SELCHANGEDA
#define TVN_GETDISPINFO TVN_GETDISPINFOA
#define TVN_SETDISPINFO TVN_SETDISPINFOA
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
#define TVN_BEGINDRAG TVN_BEGINDRAGA
#define TVN_BEGINRDRAG TVN_BEGINRDRAGA
#define TVN_DELETEITEM TVN_DELETEITEMA
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
#define TC_ITEMHEADER TC_ITEMHEADERA
#define TCITEMHEADER TCITEMHEADERA
#define LPTCITEMHEADER LPTCITEMHEADERA
#define TC_ITEM TC_ITEMA
#define TCITEM TCITEMA
#define LPTCITEM LPTCITEMA
#define TCM_GETITEM TCM_GETITEMA
#define TCM_SETITEM TCM_SETITEMA
#define TCM_INSERTITEM TCM_INSERTITEMA
#define CreateStatusWindow CreateStatusWindowA
#define DrawStatusText DrawStatusTextA
#define ImageList_LoadImage ImageList_LoadImageA
#define DTM_SETFORMAT	  DTM_SETFORMATA
#define DTN_USERSTRING DTN_USERSTRINGA
#define DTN_WMKEYDOWN DTN_WMKEYDOWNA
#define DTN_FORMAT DTN_FORMATA
#define DTN_FORMATQUERY DTN_FORMATQUERYA
typedef REBARBANDINFOA REBARBANDINFO,*LPREBARBANDINFO;
#define LPCREBARBANDINFO LPCREBARBANDINFOA
#define REBARBANDINFO_V3_SIZE REBARBANDINFOA_V3_SIZE
#define RB_INSERTBAND RB_INSERTBANDA
#define RB_SETBANDINFO RB_SETBANDINFOA
#endif

#if (_WIN32_WCE >= 0x200)

#define CMDBAR_HELP 0x000B
#define CMDBAR_OK 0xF000

/**
 * This structure contains information necessary to restore a band to its
 * current state.
 */
typedef struct tagCOMMANDBANDSRESTOREINFO {
	UINT cbSize;
	/**
	 * Identifier of the band. This member corresponds to the wID
	 * member of the REBARBANDINFO structure, and is filled in by the
	 * CommandBands_GetRestoreInformation function.
	 */
	UINT wID;
	/**
	 * Flags that specify the band style. This member
	 * corresponds to the fStyle member of the REBARBANDINFO structure,
	 * and is filled in by the CommandBands_GetRestoreInformation
	 * function. It can be a combination of the following values: Value
	 * Description RBBS_BREAK The band is on a new line. RBBS_CHILDEDGE
	 * The band has an edge at the top and bottom of the child window.
	 * RBBS_FIXEDBMP The background bitmap does not move when the band
	 * is resized. RBBS_FIXEDSIZE The band cannot be sized. With this
	 * style, the sizing grip is not displayed on the band.
	 * RBBS_GRIPPERALWAYS The band will always have sizing grip, even if
	 * it is the only band in the rebar. RBBS_HIDDEN The band will not
	 * be visible. RBBS_NOVERT The band is not displayed when the rebar
	 * control uses the CCS_VERT style. RBBS_VARIABLEHEIGHT The band can
	 * be resized by the rebar control. The cyIntegral and cyMaxChild
	 * members affect how the rebar will resize the band.
	 */
	UINT fStyle;
	/**
	 * Restored width of the band, in pixels. The restored
	 * width is the width of the band after the user has dragged it. If
	 * the user has never dragged it, it is the initial size of the
	 * band. This member corresponds to the cx member of the
	 * REBARBANDINFO structure, and is filled in by the
	 * CommandBands_GetRestoreInformation function.
	 */
	UINT cxRestored;
	/**
	 * Indicates whether the band is maximized. Only one
	 * band in a row can be maximized at a time. This member corresponds
	 * to the fStyle member of the REBARBANDINFO structure, and is
	 * filled in by the CommandBands_GetRestoreInformation function.
	 */
	BOOL fMaximized;
} COMMANDBANDSRESTOREINFO, *LPCOMMANDBANDSRESTOREINFO;
#endif /* _WIN32_WCE >= 0x200 */

#endif /* RC_INVOKED */

#ifdef _WIN32_WCE               /* these are PPC only */

/**
 * Creates an empty command bar along the top of a window.
 *
 * The command bar takes the place of the menu bar and sits inside the
 * parent's client area: offset your layout by CommandBar_Height. Destroy with
 * CommandBar_Destroy.
 *
 * @param hInst Application instance.
 * @param hwndParent Parent window.
 * @param idCmdBar Control identifier.
 * @return The command bar, or NULL on failure.
 */
COMMCTRLAPI HWND WINAPI CommandBar_Create(HINSTANCE hInst, HWND hwndParent, int idCmdBar); 
/**
 * Shows or hides a command bar.
 *
 * Command bars start visible. To hide one before the window first appears,
 * call this before ShowWindow on the parent.
 *
 * @param hwndCB The command bar.
 * @param fShow TRUE to show, FALSE to hide.
 * @return TRUE if the command bar was visible before, FALSE if hidden.
 */
COMMCTRLAPI BOOL WINAPI CommandBar_Show(HWND hwndCB, BOOL fShow); 
/**
 * Adds button images to a command bar from a bitmap.
 *
 * Images should be 16x16. For the system images, pass HINST_COMMCTRL with
 * IDB_STD_SMALL_COLOR or IDB_VIEW_SMALL_COLOR, then index them with STD_*
 * or VIEW_* offset by the returned index. On Windows CE 1.0 the display is
 * 2bpp greyscale, so images aren't shown in colour.
 *
 * @param hwndCB The command bar.
 * @param hInst Module containing the bitmap, HINST_COMMCTRL, or NULL if
 *        idBitmap is an HBITMAP.
 * @param idBitmap Bitmap resource identifier, IDB_* for HINST_COMMCTRL, or
 *        a bitmap handle.
 * @param iNumImages Number of images in the bitmap. May be 0 for the
 *        system bitmaps.
 * @param iImageWidth Width of each image: 16. Reserved on Windows CE 1.0.
 * @param iImageHeight Height of each image: 16. Reserved on Windows CE
 *        1.0.
 * @return Index of the first new image, or -1 on failure.
 */
COMMCTRLAPI int WINAPI CommandBar_AddBitmap(HWND hwndCB, HINSTANCE hInst, int idBitmap, int iNumImages, int iImageWidth, int iImageHeight); 
/**
 * Inserts a combo box into a command bar.
 *
 * @param hwndCB The command bar.
 * @param hInst Application instance.
 * @param iWidth Width, in pixels.
 * @param dwStyle Combo box and window styles. WS_CHILD and WS_VISIBLE are
 *        added automatically. On Windows CE 1.0, only CBS_DROPDOWNLIST and
 *        WS_VSCROLL are supported.
 * @param idComboBox Control identifier.
 * @param iButton Zero-based index of the button to insert it before.
 * @return The combo box, or NULL on failure.
 */
COMMCTRLAPI HWND WINAPI CommandBar_InsertComboBox(HWND hwndCB, HINSTANCE hInst, int iWidth, UINT dwStyle, WORD idComboBox, WORD iButton); 
/**
 * Inserts a menu bar, loaded from a resource, into a command bar.
 *
 * Use the same kind of menu resource as a desktop application's main menu.
 * Get the menu afterwards with CommandBar_GetMenu.
 *
 * @param hwndCB The command bar.
 * @param hInst Module containing the menu resource.
 * @param idMenu Menu resource identifier.
 * @param iButton Zero-based index of the button to insert it before.
 * @return TRUE on success, FALSE on failure.
 */
COMMCTRLAPI BOOL WINAPI CommandBar_InsertMenubar(HWND hwndCB, HINSTANCE hInst, WORD idMenu, WORD iButton);
/**
 * Inserts a menu bar into a command bar, from a resource or a menu handle.
 *
 * @param hwndCB The command bar.
 * @param hInst Module containing the menu resource, or NULL if pszMenu is a
 *        menu handle.
 * @param pszMenu Menu resource name (or MAKEINTRESOURCE identifier), or an
 *        HMENU.
 * @param iButton Zero-based index of the button to insert it before.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBar_InsertMenubarEx(HWND hwndCB, HINSTANCE hInst, LPTSTR pszMenu, WORD iButton);
/**
 * Repositions and redraws a command bar after one of its menus has changed.
 *
 * Call it after modifying a command bar menu, instead of DrawMenuBar. Don't
 * use 0xFFFFFFFF as a button or separator command identifier: the command bar
 * reserves it.
 *
 * @param hwndCB The command bar.
 * @param iButton Zero-based index of the menu bar within the command bar.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBar_DrawMenuBar(HWND hwndCB, WORD iButton); 
/**
 * Returns the menu held by a command bar's menu bar.
 *
 * @param hwndCB The command bar.
 * @param iButton Zero-based index of the button holding the menu bar.
 * @return The menu, or NULL on failure, including when the button has no
 *         menu.
 */
COMMCTRLAPI HMENU WINAPI CommandBar_GetMenu(HWND hwndCB, WORD iButton); 
/**
 * Adds the Close button, and optionally Help and OK buttons, to a command
 * bar.
 *
 * Close posts WM_CLOSE, Help posts WM_HELP and OK posts WM_COMMAND with IDOK.
 * Call it after adding everything else (menus, buttons, combo boxes).
 *
 * @param hwndCB The command bar.
 * @param dwFlags 0, or CMDBAR_HELP and/or CMDBAR_OK.
 * @param dwReserved Reserved; must be zero.
 * @return TRUE on success, FALSE on failure.
 */
COMMCTRLAPI BOOL WINAPI CommandBar_AddAdornments(HWND hwndCB, DWORD dwFlags, DWORD dwReserved); 
/**
 * Returns the height of a command bar.
 *
 * The command bar covers the top of the parent's client area, so use this to
 * find where the usable client area starts.
 *
 * @param hwndCB The command bar.
 * @return The height, in pixels.
 */
COMMCTRLAPI int WINAPI CommandBar_Height(HWND hwndCB); 

/* These two are not in the DLL */
/**
 * This macro inserts a button into the command bar.
 *
 * @param hwndCB Handle to the command bar's window. This handle is
 *        returned by the CommandBar_Create function when the command bar
 *        is created.
 * @param iButton Zero-based index of a button in the command bar.
 *        CommandBar_InsertButton inserts the new button to the left of
 *        this button.
 * @param lpButton Long pointer to a TBBUTTON structure that contains
 *        information about the button to insert.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define CommandBar_InsertButton(hwnd,i,lptbbutton)              \
    ((BOOL)SendMessage((hwnd),TB_INSERTBUTTON,(i),(lptbbutton)))
/**
 * This macro destroys the command bar.
 *
 * The CommandBar_Destroy function calls the DestroyWindow function to
 * destroy the command bar. If the command bar's parent window is being
 * destroyed, it is not necessary to call CommandBar_Destroy.
 *
 * @param hwndCB Handle to the command bar's window. This handle is
 *        returned by the CommandBar_Create function when the command bar
 *        is created.
 * @return None.
 */
#define CommandBar_Destroy(hwnd)                                \
    DestroyWindow(hwnd)
/**
 * This macro adds one or more buttons to the command bar.
 *
 * @param hwndCB Handle to the command bar's window. This handle is
 *        returned by the CommandBar_Create function when the command bar
 *        is created.
 * @param uNumButtons Unsigned integer that contains the number of buttons
 *        to add.
 * @param lpButtons Long pointer to an array of TBBUTTON structures that
 *        contain information about the buttons to add. There must be the
 *        same number of elements in the array as specified in the
 *        uNumButtons parameter.
 * @return TRUE indicates success. FALSE indicates failure.
 */
#define CommandBar_AddButtons(h, cb, lp)                        \
    SendMessage((h), TB_ADDBUTTONS, (WPARAM)(cb), (LPARAM)(lp))
/**
 * This macro ascertains whether or not the command bar is visible.
 *
 * Because this macro only determines whether the window has the WS_VISIBLE
 * style, it may return TRUE even if the window is obscured by other
 * windows.
 *
 * @param hwndCB Handle to the command bar's window. This handle is
 *        returned by the CommandBar_Create function when the command bar
 *        is created.
 * @return TRUE indicates that the command bar's parent window has the
 *        WS_VISIBLE style. FALSE indicates that the command bar is hidden.
 */
#define CommandBar_IsVisible(hwnd)                              \
    IsWindowVisible(hwnd)


#endif /* _WIN32_WCE */

#if (_WIN32_WCE >= 0x0200)

/**
 * Adds a band holding the Close button, and optionally Help and OK buttons,
 * to a command bands control.
 *
 * Close posts WM_CLOSE, Help posts WM_HELP and OK posts WM_COMMAND with IDOK.
 * The band's identifier is 0xFFFFFFFF unless prbbi sets another.
 *
 * @param hwndCmdBands The control, from CommandBands_Create.
 * @param hinst Application instance.
 * @param dwFlags 0, or CMDBAR_HELP and/or CMDBAR_OK.
 * @param prbbi Settings for the adornments band, or NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBands_AddAdornments(HWND hwndCmdBands,HINSTANCE hinst,DWORD dwFlags,LPREBARBANDINFO prbbi);
/**
 * Adds bands to a command bands control.
 *
 * Each band gets a command bar, which CommandBands_GetCommandBar returns. To
 * put another control in a band, set RBBIM_CHILD in fMask and the control in
 * hwndChild.
 *
 * @param hwndCmdBands The control, from CommandBands_Create.
 * @param hinst Application instance.
 * @param cBands Number of bands to add.
 * @param prbbi Array of cBands REBARBANDINFO structures.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBands_AddBands(HWND hwndCmdBands,HINSTANCE hinst,UINT cBands,LPREBARBANDINFO prbbi);
/**
 * Creates a command bands control: a rebar whose bands hold command bars.
 *
 * Add bands with CommandBands_AddBands, then CommandBands_AddAdornments.
 *
 * @param hinst Application instance.
 * @param hwndParent Parent window.
 * @param wID Control identifier, used in rebar notifications.
 * @param dwStyles Rebar styles, RBS_*.
 * @param himl Image list for band images, or NULL.
 * @return The control, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI HWND WINAPI CommandBands_Create(HINSTANCE hinst,HWND hwndParent,UINT wID,DWORD dwStyles,HIMAGELIST himl);
/**
 * Returns the command bar in a band of a command bands control.
 *
 * The user may have moved the bands, so get the index from the band's
 * identifier with RB_IDTOINDEX.
 *
 * @param hwndCmdBands The control, from CommandBands_Create.
 * @param uBand Zero-based index of the band.
 * @return The command bar, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI HWND WINAPI CommandBands_GetCommandBar(HWND hwndCmdBands,UINT uBand);
/**
 * Retrieves a band's current state, to restore the layout next time the
 * application runs.
 *
 * Save the result, for example in the registry, before the window closes.
 * When restoring, pass its fStyle and cxRestored to CommandBands_AddBands in
 * REBARBANDINFO's fStyle and cx, then send RB_MAXIMIZEBAND for any band with
 * fMaximized set.
 *
 * @param hwndCmdBands The control, from CommandBands_Create.
 * @param uBand Zero-based index of the band. Use RB_IDTOINDEX to find it.
 * @param pcbr Receives the state. Set cbSize first.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBands_GetRestoreInformation(HWND hwndCmdBands,UINT uBand,LPCOMMANDBANDSRESTOREINFO pcbr);
/**
 * Shows or hides a command bands control.
 *
 * @param hwndCmdBands The control, from CommandBands_Create.
 * @param fShow TRUE to show, FALSE to hide.
 * @return The previous visibility.
 *
 * @note Windows CE 2.0 and later.
 */
COMMCTRLAPI BOOL WINAPI CommandBands_Show(HWND hwndCmdBands,BOOL fShow);

/**
 * This macro retrieves the height in pixels of a command bands control.
 *
 * Because the command bar occupies part of the client area of an
 * application's main window, you should call this macro to determine the
 * actual size of the client area.
 *
 * @param hwndCmdBand Window handle to the command bands control. This
 *        handle is returned when the command bands control is created by
 *        the CommandBands_Create function.
 * @return The height, in pixels, of the command bands control.
 */
#define CommandBands_Height(hwnd) ((UINT)SendMessage((hwnd),RB_GETBARHEIGHT,0,0))

#endif /* _WIN32_WCE >= 0x200 */

#ifdef __cplusplus
}
#endif
#endif

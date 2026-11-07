#ifndef _IMM_H
#define _IMM_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define WM_CONVERTREQUESTEX 0x108
/**
 * This message is sent immediately before the IME generates composition
 * string as a result of a key stroke. The message is a notification to an
 * IME window to open its composition window. An application should process
 * this message if it displays composition characters itself.
 *
 * Windows CE applications cannot create IME windows.
 *
 * @return None
 */
#define WM_IME_STARTCOMPOSITION 0x10D
/**
 * This message is sent to an application when the IME ends composition. An
 * application should process this message if it displays composition
 * characters itself.
 *
 * Windows CE applications cannot create IME windows.
 *
 * The wParam and lParam parameters are not used.
 *
 * If an application has created an IME window, it should pass this message
 * to that window. The DefWindowProc function processes this message by
 * passing it to default IME window.
 *
 * @return None
 */
#define WM_IME_ENDCOMPOSITION 0x10E
/**
 * This message is sent to an application when the IME changes composition
 * status as a result of a key stroke. An application should process this
 * message if it displays composition characters itself. Otherwise, it
 * should send the message to the IME window.
 *
 * Windows CE applications cannot create IME windows.
 *
 * For more information about these values, see the "IME Composition String
 * Values" table in Input Method Editor Constants.Windows CE applications
 * cannot create IME windows.
 *
 * The fFlags parameter can also be a combination of the following values:
 *
 * CS_INSERTCHAR: Specifies that the given composition character should be
 * inserted at the current insertion point. An application should display
 * the composition character if it processes this message.
 *
 * CS_NOMOVECARET: Specifies that the application must not move the caret
 * position as a result of processing the message. For example, if an IME
 * specifies a combination of CS_INSERTCHAR and CS_NOMOVECARET, the
 * application should insert the given character at the current caret
 * position but should not move caret to the next position. A subsequent
 * WM_IME_COMPOSITION message with GCS_RESULTSTR will replace this
 * character.
 *
 * If the application has created an IME window, it should pass this
 * message to that window. The DefWindowProc function processes this
 * message by passing it to the default IME window. The IME window
 * processes this message by updating its appearance based on the change
 * flag given. An application can call ImmGetCompositionString to retrieve
 * the new composition status.
 *
 * If none of the GCS_* values are set, the message indicates that the
 * current composition has been canceled and applications that draw the
 * composition string should delete the string.
 *
 * @param chDBCS DBCS character that represents the latest change to the
 *        composition string.
 * @param fFlags Change flag that indicates how the composition string or
 *        character changed. It can be one or more of the following values:
 *        GCS_COMPSTR GCS_SETCURSORPOS GCS_COMPATTR GCS_RESULTSTR
 *        GCS_COMPCLAUSE GCS_RESULTCLAUSE GCS_COMPREADSTR GCS_RESULTREADSTR
 *        GCS_COMPREADATTR GCS_RESULTREADCLAUSE GCS_COMPREADCLAUSE
 *        GCR_ERRORSTR GCS_TYPINGINFO GCR_INFOSTR
 * @return None
 */
#define WM_IME_COMPOSITION 0x10F
#define WM_IME_KEYLAST 0x10F
/**
 * This message is sent to an application when a window of the application
 * is activated.
 *
 * Windows CE applications should pass this message to the DefWindowProc
 * function.
 *
 * @param fSet Boolean that is set to TRUE if the input context is active,
 *        or to a FALSE, the context is inactive.
 * @param iShow Show flags. It can be a combination of the following
 *        values: Value Description ISC_SHOWUICOMPOSITIONWINDOW Shows the
 *        composition window by UI window. ISC_SHOWUIGUIDWINDOW Shows the
 *        guide window by UI window ISC_SHOWUISOFTKBD Shows the soft
 *        keyboard by UI window ISC_SHOWUICANDIDATEWINDOW Shows the
 *        candidate window of Index 0 by UI window.
 *        ISC_SHOWUICANDIDATEWINDOW << 1 Shows the candidate window of
 *        Index 1 by UI window. ISC_SHOWUICANDIDATEWINDOW << 2 Shows the
 *        candidate window of Index 2 by UI window.
 *        ISC_SHOWUICANDIDATEWINDOW << 3 Shows the candidate window of
 *        Index 3 by UI window.
 * @return Returns the value returned by DefWindowProc or ImmIsUIMessage.
 */
#define WM_IME_SETCONTEXT 0x281
/**
 * This message is sent to an application to notify it of changes to the
 * IME window. An application processes this message if it is responsible
 * for managing the IME window.
 *
 * Windows CE supports the following values for the dwCommand parameter:
 *
 * IMN_CHANGECANDIDATE IMN_SETCANDIDATEPOS IMN_CLOSECANDIDATE
 * IMN_SETCOMPOSITIONWINDOW IMN_OPENCANDIDATE IMN_SETCONVERSIONMODE
 * IMN_PRIVATE IMN_SETOPENSTATUS IMN_SETSENTENCEMODE
 *
 * @param dwCommand Specifies one of the following command values:
 *        IMN_CHANGECANDIDATE IMN_SETCANDIDATEPOS IMN_CLOSECANDIDATE
 *        IMN_SETCOMPOSITIONFONT IMN_CLOSESTATUSWINDOW
 *        IMN_SETCOMPOSITIONWINDOW IMN_GUIDELINE IMN_SETCONVERSIONMODE
 *        IMN_OPENCANDIDATE IMN_SETOPENSTATUS IMN_OPENSTATUSWINDOW
 *        IMN_SETSENTENCEMODE IMN_PRIVATE IMN_SETSTATUSWINDOWPOS For more
 *        information about these commands, see the corresponding
 *        descriptions.
 * @param dwData Specifies a command-specific value.
 * @return Returns a command-specific value. IMN_CHANGECANDIDATE,
 *        IMN_OPENCANDIDATE, IMN_OPENSTATUSWINDOW, IMN_SETCANDIDATEPOS,
 *        IMN_SETCOMPOSITIONFONT, IMN_SETCOMPOSITIONWINDOW,
 *        IMN_SETCONVERSIONMODE, IMN_SETOPENSTATUS, IMN_SETSENTENCEMODE,
 *        IMN_SETSTATUSWINDOWPOS
 */
#define WM_IME_NOTIFY 0x282
/**
 * This message directs the IME window to carry out the requested command.
 * An application uses this message to control the IME window created by
 * the application.
 *
 * @param dwCommand Specifies a command value. It is of the following
 *        values: IMC_GETCANDIDATEPOS IMC_OPENSTATUSWINDOW
 *        IMC_GETCOMPOSITIONFONT IMC_SETCANDIDATEPOS
 *        IMC_GETCOMPOSITIONWINDOW IMC_SETCOMPOSITIONFONT
 *        IMC_GETCONVERSIONMODE IMC_SETCOMPOSITIONWINDOW IMC_GETOPENSTATUS
 *        IMC_SETCONVERSIONMODE IMC_GETSENTENCEMODE IMC_SETOPENSTATUS
 *        IMC_GETSTATUSWINDOWPOS IMC_SETSENTENCEMODE IMC_CLOSESTATUSWINDOW
 *        IMC_SETSTATUSWINDOWPOS For more information about these commands,
 *        see the individual descriptions.
 * @param dwData Specifies a command-specific value.
 * @return Returns a command-specific value
 */
#define WM_IME_CONTROL 0x283
/**
 * This message is sent to an application when the IME window finds no
 * space to extend the area for the composition window. The application
 * should use the IMC_SETCOMPOSITIONWINDOW message to specify how to
 * display the window.
 *
 * The wParam and lParam Parameters are not used. The IME window, not the
 * IME, sends this notification message by using the SendMessage message.
 *
 * @return None
 */
#define WM_IME_COMPOSITIONFULL 0x284
/**
 * This message is sent to an application when the system is about to
 * change the current IME. An application that has created an IME window
 * should pass this message to that window so that it can retrieve the
 * keyboard layout handle for the newly selected IME.
 *
 * The DefWindowProc function processes this message by passing the
 * information to the default IME window.
 *
 * @param fSelect Boolean that is set to TRUE if the specified IME is
 *        selected, or to FALSE if the specified IME is no longer selected.
 * @param hKL Handle to the keyboard layout associated with the IME.
 * @return None
 */
#define WM_IME_SELECT 0x285
/**
 * This message is sent to an application when the IME gets a character of
 * the conversion result. Unlike the WM_CHAR message, this message can
 * include double-byte as well as single-byte character values.
 *
 * If the WM_IME_CHAR message includes a double-byte character and the
 * application passes this message to DefWindowProc, the IME converts this
 * message into two WM_CHAR messages, each containing one byte of the
 * double-byte character.
 *
 * @param chCharCode1 and chCharCode2 (For double-byte character sets)
 *        Single- or double-byte character value. For a double-byte
 *        character, chCharCode1 contains the lead byte.
 * @param chCharCode1 (For Unicode) Unicode character value.
 * @param lKeyData Repeat count, scan code, extended-key flag, context
 *        code, previous key-state flag, and transition-state flag, as
 *        shown following: Value Description 0-15 Repeat count: Since the
 *        first byte and second byte is continuous, this is always 1. 16-23
 *        Scan Code: Scan code for a complete FE character. 24-28 Not used.
 *        29 Context code. 31 Conversion state.
 */
#define WM_IME_CHAR 0x286
/**
 * This message is sent to an application by the IME to notify the
 * application of a key press. The Parameters and return value for this
 * message are identical to the WM_KEYDOWN message. An application can
 * process this message or pass it to the DefWindowProc function to
 * generate a matching WM_KEYDOWN message. This message is usually
 * generated by the IME to keep message order.
 *
 * @param nVirtKey Virtual-key code.
 * @param lKeyData Key data.
 */
#define WM_IME_KEYDOWN 0x290
/**
 * This message is sent to an application by the IME to notify the
 * application of a key release. The Parameters and return value for this
 * message are identical to the WM_KEYUP message. An application can
 * process this message or pass it to the DefWindowProc function to
 * generate a matching WM_KEYUP message. This message is usually generated
 * by the IME to keep message order.
 *
 * @param nVirtKey Virtual-key code.
 * @param lKeyData Key data.
 */
#define WM_IME_KEYUP 0x291
#if (_WIN32_WINNT >= 0x0500)
/**
 * This message requests information about the state of the IME.
 *
 * @param dwRequest Specifies a request value. It is of the following
 *        values: IMR_CANDIDATEFORM IMR_DOCUMENTFEED IMR_COMPOSITIONFONT
 *        IMR_QUERYCHARPOSITION IMR_COMPOSITIONFORM IMR_RECONVERTSTRING
 *        IMR_CONFIRMRECONVERTSTRING
 * @param dwData Specifies request-specific data. For more information
 *        about this data, see the description for each request value.
 * @return Returns a request-specific value. For more information about
 *        this data, see the description for each request value.
 */
#define WM_IME_REQUEST 0x0288
#endif
/**
 * This message is sent by an application to an IME window to get the
 * position of the candidate window. Because the IME may adjust the
 * candidate window position, an application uses this message to get the
 * actual position to decide whether to reposition the window.
 *
 * The returned position is in window coordinates relative to the window
 * having the current input focus.
 *
 * @param &CandForm Pointer to the CANDIDATEFORM structure that receives
 *        the position of the candidate window
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_GETCANDIDATEPOS 7
/**
 * This message is sent by an application to an IME window to set the
 * position of the candidate window. This message is intended for
 * applications that display composition characters on their own but use
 * the IME window to display candidates.
 *
 * @param &CandForm Pointer to the CANDIDATEFORM structure that contains
 *        the x- and y-coordinates for the candidate window. The
 *        application should set the dwIndex member in the structure.
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_SETCANDIDATEPOS 8
/**
 * An application sends the IMC_GETCOMPOSITIONFONT message to an IME window
 * to retrieve the logical font used for displaying intermediate characters
 * in the composition window.
 *
 * @param &LogFont Pointer to the LOGFONT structure that receives data
 *        about the logical font
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_GETCOMPOSITIONFONT 9
/**
 * This message is sent by an application to an IME window to specify the
 * logical font to use for displaying intermediate characters in the
 * composition window.
 *
 * When processing this message, the IME window changes the current
 * selected font in the input context.
 *
 * @param &LogFont Pointer to the LOGFONT structure that contains data
 *        about the logical font
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_SETCOMPOSITIONFONT 10
/**
 * This message is sent by an application to an input method editor (IME)
 * window to get the position of the composition window. Because the IME
 * may adjust the composition window position, an application uses this
 * message to get the actual position to decide whether to reposition the
 * window.
 *
 * The returned position is in window coordinates relative to the window
 * having the current input focus.
 *
 * @param &CompForm Pointer to the COMPOSITIONFORM structure that receives
 *        the position of the composition window
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_GETCOMPOSITIONWINDOW 11
/**
 * This message is sent by an application to an input method editor (IME)
 * window to set the style of the composition window. The message set this
 * style in the current input context and the style is subsequently applied
 * to each IME window that receives that input context.
 *
 * By default, the IME window has the CFS_POINT style. This means the IME
 * window uses the current caret position and window client area when it
 * opens a composition window.
 *
 * @param &CompForm Pointer to the COMPOSITIONFORM structure that contains
 *        the style data
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_SETCOMPOSITIONWINDOW 12
/**
 * This message is sent by an application to an IME window to get the
 * position of the status window.
 *
 * @return A POINTS structure that contains the x- and y-coordinates of the
 *        status window position indicates success.
 */
#define IMC_GETSTATUSWINDOWPOS 15
/**
 * This message is sent by an application to an IME window to set the
 * position of the status window.
 *
 * @param &pts Pointer to a POINTS structure that contains the x- and
 *        y-coordinates of the status window position.
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_SETSTATUSWINDOWPOS 16
/**
 * This message is sent by an application to the input method editor (IME)
 * window to hide the status window.
 *
 * When the status window of IME is hidden, this message does nothing.
 * Although an application may send this message to the IME window, the
 * application does not receive the corresponding IMN_CLOSESTATUSWINDOW
 * message.
 *
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_CLOSESTATUSWINDOW 0x21
/**
 * This message is sent by an application to the IME window to show the
 * status window. This message is ignored if the system is not in the show
 * IME status mode. The user can set or clear the show IME status mode from
 * the taskbar.
 *
 * If the status window is already shown, this message does nothing.
 * Although the application may send this message to the IME window, the
 * application does not receive the corresponding IMN_OPENSTATUSWINDOW
 * message.
 *
 * @return Zero indicates success. Nonzero indicates failure.
 */
#define IMC_OPENSTATUSWINDOW 0x22
/**
 * This message is sent to the application when an input method editor
 * (IME) is about to close the status window. An application should process
 * this notification message if it displays the status window for the IME.
 * The application receives this notification message through the
 * WM_IME_NOTIFY message.
 *
 * The IME window closes the status window when it processes this message.
 *
 * @return None
 */
#define IMN_CLOSESTATUSWINDOW 1
/**
 * This message is sent when an IME is about to create the status window.
 * An application processes this message to display the status window for
 * the IME by itself. The application receives this notification message
 * through the WM_IME_NOTIFY message.
 *
 * The IME window creates a status window when it processes this message
 * and sets the strings to display in the window into the input context.
 * Applications can get data about the status window by using the
 * ImmGetConversionStatus function.
 *
 * @return None
 */
#define IMN_OPENSTATUSWINDOW 2
/**
 * This message is sent to the application when an IME is about to change
 * the content of the candidate window. An application should process this
 * notification message if it displays candidates itself. The application
 * receives this notification message through the WM_IME_NOTIFY message.
 *
 * The IME window changes the appearance of the candidate window when it
 * processes this message. An application can get data about the system
 * window with the ImmGetCandidateListCount and ImmGetCandidateList
 * functions.
 *
 * @param fCandidates Candidate lists flag. Each bit corresponds to a
 *        candidate list: bit 0 to the first list, bit 1 to the second, and
 *        so on. If a specified bit is 1, the corresponding candidate
 *        window is about to be changed.
 * @return None
 */
#define IMN_CHANGECANDIDATE 3
/**
 * This message is sent to the application when an IME is about to close
 * the candidate window. An application should process this message if it
 * displays candidates. The application receives this notification message
 * through the WM_IME_NOTIFY message.
 *
 * By default, the IME window destroys a candidate window when it processes
 * this message.
 *
 * @param fCandidates Candidate lists flag. Each bit corresponds to a
 *        candidate list: bit 0 to the first list, bit 1 to the second, and
 *        so on. If a specified bit is 1, the corresponding candidate
 *        window is about to be closed.
 * @return None
 */
#define IMN_CLOSECANDIDATE 4
/**
 * This message is sent to the application when an IME is about to open the
 * candidate window. An application should process this message if it
 * displays candidates. The application can retrieve a list of candidates
 * to display by using the ImmGetCandidateList function. The application
 * receives this notification message through the WM_IME_NOTIFY message.
 *
 * By default, the IME window creates a candidate window when it processes
 * this message.
 *
 * @param fCandidates Candidate lists flag. Each bit corresponds to a
 *        candidate list: bit 0 to the first list, bit 1 to the second, and
 *        so on. If a specified bit is 1, the corresponding candidate
 *        window is about to be opened.
 * @return None
 */
#define IMN_OPENCANDIDATE 5
/**
 * This message is sent when the conversion mode of the input context is
 * updated. The application receives this notification message through the
 * WM_IME_NOTIFY message.
 *
 * The application can get conversion mode data by using the
 * ImmGetConversionStatus function.
 *
 * @return None
 */
#define IMN_SETCONVERSIONMODE 6
/**
 * This message is sent when the sentence mode of the input context is
 * updated. The application receives this notification message through the
 * WM_IME_NOTIFY message.
 *
 * The application can get data about the sentence mode by using the
 * ImmGetConversionStatus function.
 *
 * @return None
 */
#define IMN_SETSENTENCEMODE 7
/**
 * This message is sent when the open status of the input context is
 * updated. The application receives this notification message through the
 * WM_IME_NOTIFY message.
 *
 * The application can get data about the open status by using the
 * ImmGetOpenStatus function.
 *
 * @return None
 */
#define IMN_SETOPENSTATUS 8
/**
 * This message is sent when the IME is about to move the candidate window.
 * An application should process this message if it displays the candidate
 * window itself. The application receives this notification message
 * through the WM_IME_NOTIFY message.
 *
 * The IME window moves the candidate window when it processes this
 * message.
 *
 * @param fCandidates Candidate lists flag. Each bit corresponds to a
 *        candidate list: bit 0 to the first list, bit 1 to the second, and
 *        so on. If a specified bit is 1, the corresponding candidate
 *        window is about to be moved.
 * @return None
 */
#define IMN_SETCANDIDATEPOS 9
/**
 * This message is sent when the font of the input context is updated. The
 * application receives this notification message through the WM_IME_NOTIFY
 * message.
 *
 * The application can get font data by using the ImmGetCompositionFont
 * function. The IME window subsequently uses the font to draw the
 * composition string.
 *
 * @return None
 */
#define IMN_SETCOMPOSITIONFONT 10
/**
 * This message is sent when the style or position of the composition
 * window is updated. The application receives this notification message
 * through the WM_IME_NOTIFY message.
 *
 * The application can get data about the composition form by using the
 * IMC_GETCOMPOSITIONWINDOW message.
 *
 * @return None
 */
#define IMN_SETCOMPOSITIONWINDOW 11
/**
 * This message is sent when the status window position in the input
 * context is updated. The application receives this notification message
 * through the WM_IME_NOTIFY message.
 *
 * The application can get data about the status window position by using
 * the IMC_GETSTATUSWINDOWPOS message.
 *
 * @return None
 */
#define IMN_SETSTATUSWINDOWPOS 12
/**
 * This message is sent when an IME is about to show an error message or
 * other data. The application receives this notification message through
 * the WM_IME_NOTIFY message.
 *
 * The IME window displays the error message or data string in an
 * information window.
 *
 * @return None
 */
#define IMN_GUIDELINE 13
#define IMN_PRIVATE 14
#define NI_OPENCANDIDATE 16
#define NI_CLOSECANDIDATE 17
#define NI_SELECTCANDIDATESTR 18
#define NI_CHANGECANDIDATELIST 19
#define NI_FINALIZECONVERSIONRESULT 20
#define NI_COMPOSITIONSTR 21
#define NI_SETCANDIDATE_PAGESTART 22
#define NI_SETCANDIDATE_PAGESIZE 23
#define NI_IMEMENUSELECTED 24
#define ISC_SHOWUICANDIDATEWINDOW 1
#define ISC_SHOWUICOMPOSITIONWINDOW 0x80000000
#define ISC_SHOWUIGUIDELINE 0x40000000
#define ISC_SHOWUIALLCANDIDATEWINDOW 15
#define ISC_SHOWUIALL 0xC000000F
#define CPS_COMPLETE 1
#define CPS_CONVERT 2
#define CPS_REVERT 3
#define CPS_CANCEL 4
#define IME_CHOTKEY_IME_NONIME_TOGGLE 16
#define IME_CHOTKEY_SHAPE_TOGGLE 17
#define IME_CHOTKEY_SYMBOL_TOGGLE 18
#define IME_JHOTKEY_CLOSE_OPEN 0x30
#define IME_KHOTKEY_SHAPE_TOGGLE 0x50
#define IME_KHOTKEY_HANJACONVERT 0x51
#define IME_KHOTKEY_ENGLISH 0x52
#define IME_THOTKEY_IME_NONIME_TOGGLE 0x70
#define IME_THOTKEY_SHAPE_TOGGLE 0x71
#define IME_THOTKEY_SYMBOL_TOGGLE 0x72
#define IME_HOTKEY_DSWITCH_FIRST 256
#define IME_HOTKEY_DSWITCH_LAST 0x11F
#define IME_ITHOTKEY_RESEND_RESULTSTR 512
#define IME_ITHOTKEY_PREVIOUS_COMPOSITION 513
#define IME_ITHOTKEY_UISTYLE_TOGGLE 514
#define GCS_COMPREADSTR 1
#define GCS_COMPREADATTR 2
#define GCS_COMPREADCLAUSE 4
#define GCS_COMPSTR 8
#define GCS_COMPATTR 16
#define GCS_COMPCLAUSE 32
#define GCS_CURSORPOS 128
#define GCS_DELTASTART 256
#define GCS_RESULTREADSTR 512
#define GCS_RESULTREADCLAUSE 1024
#define GCS_RESULTSTR 2048
#define GCS_RESULTCLAUSE 4096
#define CS_INSERTCHAR 0x2000
#define CS_NOMOVECARET 0x4000
#define IMEVER_0310 0x3000A
#define IMEVER_0400 0x40000
#define IME_PROP_AT_CARET 0x10000
#define IME_PROP_SPECIAL_UI 0x20000
#define IME_PROP_CANDLIST_START_FROM_1 0x40000
#define IME_PROP_UNICODE 0x80000
#define UI_CAP_2700 1
#define UI_CAP_ROT90 2
#define UI_CAP_ROTANY 4
#define SCS_CAP_COMPSTR 1
#define SCS_CAP_MAKEREAD 2
#define SELECT_CAP_CONVERSION 1
#define SELECT_CAP_SENTENCE 2
#define GGL_LEVEL 1
#define GGL_INDEX 2
#define GGL_STRING 3
#define GGL_PRIVATE 4
#define GL_LEVEL_NOGUIDELINE 0
#define GL_LEVEL_FATAL 1
#define GL_LEVEL_ERROR 2
#define GL_LEVEL_WARNING 3
#define GL_LEVEL_INFORMATION 4
#define GL_ID_UNKNOWN 0
#define GL_ID_NOMODULE 1
#define GL_ID_NODICTIONARY 16
#define GL_ID_CANNOTSAVE 17
#define GL_ID_NOCONVERT 32
#define GL_ID_TYPINGERROR 33
#define GL_ID_TOOMANYSTROKE 34
#define GL_ID_READINGCONFLICT 35
#define GL_ID_INPUTREADING 36
#define GL_ID_INPUTRADICAL 37
#define GL_ID_INPUTCODE 38
#define GL_ID_INPUTSYMBOL 39
#define GL_ID_CHOOSECANDIDATE 40
#define GL_ID_REVERSECONVERSION 41
#define GL_ID_PRIVATE_FIRST 0x8000
#define GL_ID_PRIVATE_LAST 0xFFFF
#define IGP_GETIMEVERSION (DWORD)(-4)
#define IGP_PROPERTY 4
#define IGP_CONVERSION 8
#define IGP_SENTENCE 12
#define IGP_UI 16
#define IGP_SETCOMPSTR 0x14
#define IGP_SELECT 0x18
#define SCS_SETSTR (GCS_COMPREADSTR|GCS_COMPSTR)
#define SCS_CHANGEATTR (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)
#define ATTR_INPUT 0
#define ATTR_TARGET_CONVERTED 1
#define ATTR_CONVERTED 2
#define ATTR_TARGET_NOTCONVERTED 3
#define ATTR_INPUT_ERROR 4
#define ATTR_FIXEDCONVERTED 5
#define CFS_DEFAULT 0
#define CFS_RECT 1
#define CFS_POINT 2
#define CFS_SCREEN 4
#define CFS_FORCE_POSITION 32
#define CFS_CANDIDATEPOS 64
#define CFS_EXCLUDE 128
#define GCL_CONVERSION 1
#define GCL_REVERSECONVERSION 2
#define GCL_REVERSE_LENGTH 3
#define IME_CMODE_ALPHANUMERIC 0
#define IME_CMODE_NATIVE 1
#define IME_CMODE_CHINESE IME_CMODE_NATIVE
#define IME_CMODE_HANGEUL IME_CMODE_NATIVE
#define IME_CMODE_HANGUL IME_CMODE_NATIVE
#define IME_CMODE_JAPANESE IME_CMODE_NATIVE
#define IME_CMODE_KATAKANA 2
#define IME_CMODE_LANGUAGE 3
#define IME_CMODE_FULLSHAPE 8
#define IME_CMODE_ROMAN 16
#define IME_CMODE_CHARCODE 32
#define IME_CMODE_HANJACONVERT 64
#define IME_CMODE_SOFTKBD 128
#define IME_CMODE_NOCONVERSION 256
#define IME_CMODE_EUDC 512
#define IME_CMODE_SYMBOL 1024
#define IME_CMODE_FIXED 2048
#define IME_SMODE_NONE 0
#define IME_SMODE_PLAURALCLAUSE 1
#define IME_SMODE_SINGLECONVERT 2
#define IME_SMODE_AUTOMATIC 4
#define IME_SMODE_PHRASEPREDICT 8
#define IME_CAND_UNKNOWN 0
#define IME_CAND_READ 1
#define IME_CAND_CODE 2
#define IME_CAND_MEANING 3
#define IME_CAND_RADICAL 4
#define IME_CAND_STROKE 5
#define IMM_ERROR_NODATA (-1)
#define IMM_ERROR_GENERAL (-2)
#define IME_CONFIG_GENERAL 1
#define IME_CONFIG_REGISTERWORD 2
#define IME_CONFIG_SELECTDICTIONARY 3
#define IME_ESC_QUERY_SUPPORT 3
#define IME_ESC_RESERVED_FIRST 4
#define IME_ESC_RESERVED_LAST 0x7FF
#define IME_ESC_PRIVATE_FIRST 0x800
#define IME_ESC_PRIVATE_LAST 0xFFF
#define IME_ESC_SEQUENCE_TO_INTERNAL 0x1001
#define IME_ESC_GET_EUDC_DICTIONARY 0x1003
#define IME_ESC_SET_EUDC_DICTIONARY 0x1004
#define IME_ESC_MAX_KEY 0x1005
#define IME_ESC_IME_NAME 0x1006
#define IME_ESC_SYNC_HOTKEY 0x1007
#define IME_ESC_HANJA_MODE 0x1008
#define IME_ESC_AUTOMATA 0x1009
#define IME_REGWORD_STYLE_EUDC 1
#define IME_REGWORD_STYLE_USER_FIRST 0x80000000
#define IME_REGWORD_STYLE_USER_LAST 0xFFFFFFFF
/**
 * This message is sent to the application through the WM_IME_REQUEST
 * message when a selected IME needs a string for reconversion.
 *
 * @param lpRECONVERTSTRING Long pointer to a buffer that contains the
 *        RECONVERTSTRING structure and strings
 * @return Returns the required size of the RECONVERTSTRING if the
 *        application filled the RECONVERTSTRING structure in lParam.
 *        Otherwise, returns zero. However, if lParam is NULL, the
 *        application must return the required size of the RECONVERTSTRING.
 */
#define IMR_RECONVERTSTRING 4
#define IMR_QUERYCHARPOSITION 6
#define SOFTKEYBOARD_TYPE_T1 1
#define SOFTKEYBOARD_TYPE_C1 2
#define IMEMENUITEM_STRING_SIZE 80
#define MOD_ALT 1
#define MOD_CONTROL 2
#define MOD_SHIFT 4
#define MOD_WIN 8
#define MOD_IGNORE_ALL_MODIFIER 1024
#define MOD_ON_KEYUP  2048
#define MOD_RIGHT 16384
#define MOD_LEFT 32768
#define IACE_CHILDREN 1
#define IACE_DEFAULT 16
#define IACE_IGNORENOCONTEXT 32
#define IGIMIF_RIGHTMENU 1
#define IGIMII_CMODE 1
#define IGIMII_SMODE 2
#define IGIMII_CONFIGURE 4
#define IGIMII_TOOLS 8
#define IGIMII_HELP 16
#define IGIMII_OTHER 32
#define IGIMII_INPUTTOOLS 64
#define IMFT_RADIOCHECK 1
#define IMFT_SEPARATOR 2
#define IMFT_SUBMENU 4
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define IMFS_GRAYED MF_GRAYED
#else
#define IMFS_GRAYED MFS_GRAYED
#endif
#define IMFS_DISABLED MFS_DISABLED
#define IMFS_CHECKED MFS_CHECKED
#define IMFS_HILITE MFS_HILITE
#define IMFS_ENABLED MFS_ENABLED
#define IMFS_UNCHECKED MFS_UNCHECKED
#define IMFS_UNHILITE MFS_UNHILITE
#define IMFS_DEFAULT MFS_DEFAULT
#ifndef VK_PROCESSKEY
#define VK_PROCESSKEY 0x0E5
#endif
#define STYLE_DESCRIPTION_SIZE 32
typedef DWORD HIMC;
typedef DWORD HIMCC;
typedef HKL *LPHKL;
/**
 * This structure contains position information for a composition window.
 */
typedef struct tagCOMPOSITIONFORM {
	/**
	 * Specifies the position style. It must be the following
	 * values: Value Description CFS_DEFAULT Moves the composition
	 * window to the default position. The input method editor (IME)
	 * window can display the composition window outside the client
	 * area, such as in a floating window.
	 */
	DWORD dwStyle;
	/**
	 * Coordinates of the upper-left corner of the
	 * composition window.
	 */
	POINT ptCurrentPos;
	/**
	 * Coordinates of the upper-left and lower-right corners of
	 * the composition window.
	 */
	RECT rcArea;
} COMPOSITIONFORM,*PCOMPOSITIONFORM,*LPCOMPOSITIONFORM;
/**
 * This structure contains position information for the candidate window.
 *
 * In Japanese versions 1.0 and later, the ImmSetCandidateWindow function
 * allows an index range from 0 through 4 for the dwIndex member of the
 * CANDIDATEFORM structure. In Windows CE versions 2.10 and later, an index
 * range from 0 through 3 is allowed.
 */
typedef struct tagCANDIDATEFORM {
	/**
	 * Specifies the candidate list identifier. Can be 0 for
	 * the first list, 1 for the second, and so on. The maximum index is
	 * 31.
	 */
	DWORD dwIndex;
	/**
	 * Specifies the position style. It is one of the following
	 * values: Value Description CFS_CANDIDATEPOS Displays the
	 * upper-left corner of the candidate list window at the position
	 * given by ptCurrentPos. The coordinates are relative to the
	 * upper-left corner of the window that contains the list window,
	 * and are subject to adjustment by the system. CFS_EXCLUDE Excludes
	 * the candidate window from the area specified by rcArea. The
	 * ptCurrentPos member specifies the coordinates of the current
	 * point of interest, typically the caret position.
	 */
	DWORD dwStyle;
	/**
	 * Coordinates of the upper-left corner of the
	 * candidate window or the caret position, depending on the value of
	 * dwStyle.
	 */
	POINT ptCurrentPos;
	/**
	 * Coordinates of the upper-left and lower-right corners of
	 * the exclusion area.
	 */
	RECT rcArea;
} CANDIDATEFORM,*PCANDIDATEFORM,*LPCANDIDATEFORM;
/**
 * This structure contains information about a candidate list.
 *
 * The candidate strings immediately follow the last offset in the dwOffset
 * array.
 */
typedef struct tagCANDIDATELIST {
	/**
	 * Specifies the size, in bytes, of the structure, the
	 * offset array, and all candidate strings
	 */
	DWORD dwSize;
	/**
	 * Specifies candidate style values. It can be one or more
	 * of the following values: Value Description IME_CAND_UNKNOWN
	 * Candidates are in a style other than listed here. IME_CAND_READ
	 * Candidates are in same reading. IME_CAND_CODE Candidates are in a
	 * code range. IME_CAND_MEANING Candidates are in same meaning.
	 * IME_CAND_RADICAL Candidates use the same radical character.
	 * IME_CAND_STROKES Candidates are in same number of strokes. For
	 * the IME_CAND_CODE style, the candidate list has a special
	 * structure depending on the value of the dwCount member. If
	 * dwCount is 1, the dwOffset member contains a single DBCS
	 * character rather than an offset, and no candidate string is
	 * provided. If the dwCount member is greater than 1, the dwOffset
	 * member contains valid offsets, and the candidate strings are text
	 * representations of individual DBCS character values in
	 * hexadecimal notation.
	 */
	DWORD dwStyle;
	/**
	 * Specifies the number of candidate strings.
	 */
	DWORD dwCount;
	/**
	 * Specifies the index of the selected candidate
	 * string.
	 */
	DWORD dwSelection;
	/**
	 * Specifies the index of the first candidate string in
	 * the candidate window. This varies as the user presses the PAGE UP
	 * and PAGE DOWN keys.
	 */
	DWORD dwPageStart;
	/**
	 * Specifies the number of candidate strings to be shown
	 * in one page in the candidate window. The user can move to the
	 * next page by pressing IME-defined keys, such as the PAGE UP or
	 * PAGE DOWN key. If this number is zero, an application can define
	 * a proper value by itself.
	 */
	DWORD dwPageSize;
	/**
	 * Specifies the offset to the start of the first
	 * candidate string, relative to the start of this structure. The
	 * offsets for subsequent strings immediately follow this member,
	 * forming an array of 32-bit offsets.
	 */
	DWORD dwOffset[1];
} CANDIDATELIST,*PCANDIDATELIST,*LPCANDIDATELIST;
typedef struct tagIMECHARPOSITION {
  DWORD  dwSize;
  DWORD  dwCharPos;
  POINT  pt;
  UINT   cLineHeight;
  RECT   rcDocument;
} IMECHARPOSITION, *PIMECHARPOSITION;
/**
 * This structure defines the strings for IME reconversion. It is the first
 * item in a memory block that contains the strings for reconversion.
 */
typedef struct tagRECONVERTSTRING {
  /**
   * Specifies the size of this structure and the memory block
   * it heads.
   */
  DWORD dwSize;
  /**
   * Specifies the version number. Must be zero.
   */
  DWORD dwVersion;
  /**
   * Specifies the length of the string that contains the
   * composition string.
   */
  DWORD dwStrLen;
  /**
   * Specifies the offset from the start position of this
   * structure.
   */
  DWORD dwStrOffset;
  /**
   * Specifies the length of the string that will be the
   * composition string.
   */
  DWORD dwCompStrLen;
  /**
   * Specifies the offset of the string that will be
   * the composition string.
   */
  DWORD dwCompStrOffset;
  /**
   * Specifies the length of the string that is
   * related to the target clause in the composition string.
   */
  DWORD dwTargetStrLen;
  /**
   * Specifies the offset of the target string.
   */
  DWORD dwTargetStrOffset;
} RECONVERTSTRING, *PRECONVERTSTRING;
typedef struct tagREGISTERWORDA {
	LPSTR lpReading;
	LPSTR lpWord;
} REGISTERWORDA,*PREGISTERWORDA,*LPREGISTERWORDA;
typedef struct tagREGISTERWORDW {
	LPWSTR lpReading;
	LPWSTR lpWord;
} REGISTERWORDW,*PREGISTERWORDW,*LPREGISTERWORDW;
typedef struct tagSTYLEBUFA {
	DWORD dwStyle;
	CHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFA,*PSTYLEBUFA,*LPSTYLEBUFA;
typedef struct tagSTYLEBUFW {
	DWORD dwStyle;
	WCHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFW,*PSTYLEBUFW,*LPSTYLEBUFW;
typedef struct tagIMEMENUITEMINFOA {
	UINT cbSize;
	UINT fType;
	UINT fState;
	UINT wID;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	DWORD dwItemData;
	CHAR szString[IMEMENUITEM_STRING_SIZE];
	HBITMAP hbmpItem;
} IMEMENUITEMINFOA,*PIMEMENUITEMINFOA,*LPIMEMENUITEMINFOA;
typedef struct tagIMEMENUITEMINFOW {
	UINT cbSize;
	UINT fType;
	UINT fState;
	UINT wID;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	DWORD dwItemData;
	WCHAR szString[IMEMENUITEM_STRING_SIZE];
	HBITMAP hbmpItem;
} IMEMENUITEMINFOW,*PIMEMENUITEMINFOW,*LPIMEMENUITEMINFOW;
typedef int (CALLBACK *REGISTERWORDENUMPROCA)(LPCSTR, DWORD, LPCSTR, LPVOID);
typedef int (CALLBACK *REGISTERWORDENUMPROCW)(LPCWSTR, DWORD, LPCWSTR, LPVOID);
#ifdef UNICODE
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCW
typedef REGISTERWORDW REGISTERWORD,*PREGISTERWORD,*LPREGISTERWORD;
typedef STYLEBUFW STYLEBUF,*PSTYLEBUF,*LPSTYLEBUF;
typedef IMEMENUITEMINFOW IMEMENUITEMINFO,*PIMEMENUITEMINFO,*LPIMEMENUITEMINFO;
#else
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCA
typedef REGISTERWORDA REGISTERWORD,*PREGISTERWORD,*LPREGISTERWORD;
typedef STYLEBUFA STYLEBUF,*PSTYLEBUF,*LPSTYLEBUF;
typedef IMEMENUITEMINFOA IMEMENUITEMINFO,*PIMEMENUITEMINFO,*LPIMEMENUITEMINFO;
#endif
HKL WINAPI ImmInstallIMEA(LPCSTR,LPCSTR);
HKL WINAPI ImmInstallIMEW(LPCWSTR,LPCWSTR);
/**
 * Returns the default IME window.
 *
 * The system creates a single default IME window. Windows CE doesn't
 * support the IME window class.
 *
 * @param hWnd A window, used to find the IME window.
 * @return The default IME window, or NULL.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HWND WINAPI ImmGetDefaultIMEWnd(HWND hWnd);
UINT WINAPI ImmGetDescriptionA(HKL,LPSTR,UINT);
/**
 * Gets an IME's description string.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszDescription Receives the description, or NULL.
 * @param uBufLen Buffer size in characters, or 0 to query the length.
 * @return Characters copied, not counting the terminator, or the length
 *         needed when uBufLen is 0.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
UINT WINAPI ImmGetDescriptionW(HKL hKL,LPWSTR lpszDescription,UINT uBufLen);
UINT WINAPI ImmGetIMEFileNameA(HKL,LPSTR,UINT);
/**
 * Retrieves the file name of the IME associated with a keyboard handle.
 *
 * CE uses the handle to distinguish locale-specific IMEs rather than as a
 * true keyboard layout. A zero `uBufLen` queries the required size. Counts
 * are in bytes and exclude the terminating null. OEM support may vary.
 *
 * @param hKL Handle identifying the locale-specific IME.
 * @param lpszFileName Receives the file name.
 * @param uBufLen Output capacity, in bytes.
 * @return Bytes copied or required, excluding the terminator.
 *
 * @note Windows CE 3.0 only.
 */
UINT WINAPI ImmGetIMEFileNameW(HKL hKL,LPWSTR lpszFileName,UINT uBufLen);
/**
 * Gets the properties and capabilities of an IME.
 *
 * @param hKL Keyboard layout. Must be NULL on Windows CE.
 * @param fdwIndex IGP_PROPERTY, IGP_CONVERSION, IGP_SENTENCE, IGP_UI,
 *        IGP_SETCOMPSTR, IGP_SELECT or IGP_GETIMEVERSION.
 * @return The requested property flags or value.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI ImmGetProperty(HKL hKL,DWORD fdwIndex);
/**
 * Checks whether a keyboard layout handle identifies an IME.
 *
 * @param hKL Keyboard layout handle to check.
 * @return Nonzero if it identifies an IME, zero otherwise.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI ImmIsIME(HKL hKL);
/**
 * Acts as if the user pressed an IME hot key in a window.
 *
 * Windows CE supports only IME_JHOTKEY_CLOSE_OPEN, which toggles the
 * Japanese IME open and closed.
 *
 * @param hWnd The window.
 * @param dwHotKeyID The hot key, IME_JHOTKEY_CLOSE_OPEN.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSimulateHotKey(HWND hWnd,DWORD dwHotKeyID);
/**
 * Creates and initializes an input method context.
 *
 * Destroy the context with ImmDestroyContext. OEM support may vary.
 *
 * @return Input-context handle, or NULL on failure.
 *
 * @note Windows CE 3.0 only.
 */
HIMC WINAPI ImmCreateContext(void);
/**
 * Destroys an input method context and frees its associated memory.
 *
 * Call this, before terminating, for contexts created with
 * ImmCreateContext. OEM support may vary.
 *
 * @param hIMC Input-context handle.
 * @return Nonzero on success, zero on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI ImmDestroyContext(HIMC hIMC);
/**
 * Returns the input context associated with a window.
 *
 * Release it with ImmReleaseContext.
 *
 * @param hWnd The window.
 * @return The input context, or NULL if the window has none.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HIMC WINAPI ImmGetContext(HWND hWnd);
/**
 * Releases an input context from ImmGetContext.
 *
 * Call once for every ImmGetContext.
 *
 * @param hWnd The window passed to ImmGetContext.
 * @param hIMC The input context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmReleaseContext(HWND hWnd,HIMC hIMC);
/**
 * Associates an input context with a window.
 *
 * Each window gets the default input context when created. On Windows CE
 * the only contexts an application can pass are the default one and
 * NULL.
 *
 * @param hWnd The window.
 * @param hIMC The default input context, or NULL to remove the window's
 *        association.
 * @return The window's previous input context.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HIMC WINAPI ImmAssociateContext(HWND hWnd,HIMC hIMC);
LONG WINAPI ImmGetCompositionStringA(HIMC,DWORD,PVOID,DWORD);
/**
 * Gets part of the composition or result string, or its attributes.
 *
 * Usually called on WM_IME_COMPOSITION with GCS_RESULTSTR to collect the
 * finished text.
 *
 * @param hIMC The input context.
 * @param dwIndex What to get: GCS_COMPSTR, GCS_COMPATTR, GCS_COMPCLAUSE,
 *        GCS_COMPREADSTR, GCS_RESULTSTR, GCS_RESULTCLAUSE, GCS_CURSORPOS
 *        and so on.
 * @param lpBuf Receives the data. Strings aren't null-terminated.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return Bytes copied, or needed when dwBufLen is 0. For GCS_CURSORPOS,
 *         the cursor position. IMM_ERROR_NODATA or IMM_ERROR_GENERAL on
 *         failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LONG WINAPI ImmGetCompositionStringW(HIMC hIMC,DWORD dwIndex,PVOID lpBuf,DWORD dwBufLen);
BOOL WINAPI ImmSetCompositionStringA(HIMC,DWORD,PCVOID,DWORD,PCVOID,DWORD);
/**
 * Sets the composition and reading strings, or their attributes or
 * clauses.
 *
 * @param hIMC The input context.
 * @param dwIndex SCS_SETSTR, SCS_CHANGEATTR or SCS_CHANGECLAUSE.
 * @param lpComp Composition data, or NULL.
 * @param dwCompLen Size of lpComp, in bytes.
 * @param lpRead Reading data, or NULL.
 * @param dwReadLen Size of lpRead, in bytes.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetCompositionStringW(HIMC hIMC,DWORD dwIndex,PCVOID lpComp,DWORD dwCompLen,PCVOID lpRead,DWORD dwReadLen);
DWORD WINAPI ImmGetCandidateListCountA(HIMC,PDWORD);
/**
 * Gets the number of candidate lists and the buffer size needed for all
 * of them.
 *
 * @param hIMC The input context.
 * @param lpdwListCount Receives the number of candidate lists.
 * @return Bytes needed to hold all the lists, or 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI ImmGetCandidateListCountW(HIMC hIMC,PDWORD lpdwListCount);
DWORD WINAPI ImmGetCandidateListA(HIMC,DWORD,PCANDIDATELIST,DWORD);
/**
 * Copies a candidate list into a buffer.
 *
 * @param hIMC The input context.
 * @param dwIndex Index of the candidate list.
 * @param lpCandList Receives the CANDIDATELIST and its strings.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return Bytes copied, or needed when dwBufLen is 0. 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI ImmGetCandidateListW(HIMC hIMC,DWORD dwIndex,PCANDIDATELIST lpCandList,DWORD dwBufLen);
DWORD WINAPI ImmGetGuideLineA(HIMC,DWORD,LPSTR,DWORD);
/**
 * Gets the IME's error or guidance information.
 *
 * @param hIMC The input context.
 * @param dwIndex GGL_LEVEL, GGL_INDEX, GGL_STRING or GGL_PRIVATE.
 * @param lpBuf Receives the string or private data. Unused for GGL_LEVEL
 *        and GGL_INDEX.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return For GGL_LEVEL a GL_LEVEL_* value, for GGL_INDEX a GL_ID_*
 *         value, otherwise bytes copied or needed.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI ImmGetGuideLineW(HIMC hIMC,DWORD dwIndex,LPWSTR lpBuf,DWORD dwBufLen);
/**
 * Gets the current conversion and sentence modes.
 *
 * @param hIMC The input context.
 * @param lpfdwConversion Receives IME_CMODE_* flags.
 * @param lpfdwSentence Receives an IME_SMODE_* value.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmGetConversionStatus(HIMC hIMC,LPDWORD lpfdwConversion,PDWORD lpfdwSentence);
/**
 * Sets the conversion and sentence modes.
 *
 * @param hIMC The input context.
 * @param fdwConversion IME_CMODE_* flags.
 * @param fdwSentence An IME_SMODE_* value.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetConversionStatus(HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence);
/**
 * Returns whether the IME is open.
 *
 * @param hIMC The input context.
 * @return TRUE if open, FALSE if closed.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmGetOpenStatus(HIMC hIMC);
/**
 * Opens or closes the IME.
 *
 * @param hIMC The input context.
 * @param fOpen TRUE to open, FALSE to close.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetOpenStatus(HIMC hIMC,BOOL fOpen);
#ifndef NOGDI
BOOL WINAPI ImmGetCompositionFontA(HIMC,LPLOGFONTA);
/**
 * Gets the font used to show the composition string.
 *
 * @param hIMC The input context.
 * @param lplf Receives the font.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmGetCompositionFontW(HIMC hIMC,LPLOGFONTW lplf);
BOOL WINAPI ImmSetCompositionFontA(HIMC,LPLOGFONTA);
/**
 * Sets the font used to show the composition string.
 *
 * @param hIMC The input context.
 * @param lplf The font.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetCompositionFontW(HIMC hIMC,LPLOGFONTW lplf);
#endif
BOOL WINAPI ImmConfigureIMEA(HKL,HWND,DWORD,PVOID);
/**
 * Shows an IME's configuration dialog.
 *
 * @param hKL Keyboard layout of the IME.
 * @param hWnd Parent window for the dialog.
 * @param dwMode IME_CONFIG_GENERAL, IME_CONFIG_REGISTERWORD or
 *        IME_CONFIG_SELECTDICTIONARY.
 * @param lpData A REGISTERWORDW for IME_CONFIG_REGISTERWORD, otherwise
 *        NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmConfigureIMEW(HKL hKL,HWND hWnd,DWORD dwMode,PVOID lpData);
LRESULT WINAPI ImmEscapeA(HKL,HIMC,UINT,PVOID);
/**
 * Sends an IME-specific escape to an IME.
 *
 * @param hKL Keyboard layout of the IME.
 * @param hIMC The input context.
 * @param uEscape Escape code, IME_ESC_*.
 * @param lpData Escape-specific data.
 * @return Escape-specific, 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LRESULT WINAPI ImmEscapeW(HKL hKL,HIMC hIMC,UINT uEscape,PVOID lpData);
DWORD WINAPI ImmGetConversionListA(HKL,HIMC,LPCSTR,PCANDIDATELIST,DWORD,UINT);
/**
 * Gets the conversion results for a character or word without changing
 * the input context.
 *
 * @param hKL Keyboard layout. Must be NULL on Windows CE.
 * @param hIMC The input context.
 * @param lpSrc The string to convert.
 * @param lpDst Receives a CANDIDATELIST of results.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @param uFlag GCL_CONVERSION, GCL_REVERSECONVERSION or
 *        GCL_REVERSE_LENGTH.
 * @return Bytes copied, or needed when dwBufLen is 0. 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI ImmGetConversionListW(HKL hKL,HIMC hIMC,LPCWSTR lpSrc,PCANDIDATELIST lpDst,DWORD dwBufLen,UINT uFlag);
/**
 * Tells the IME about a change to an input context, or asks it to act on
 * the composition or candidates.
 *
 * @param hIMC The input context.
 * @param dwAction NI_COMPOSITIONSTR, NI_OPENCANDIDATE, NI_CLOSECANDIDATE,
 *        NI_SELECTCANDIDATESTR, NI_CHANGECANDIDATELIST,
 *        NI_SETCANDIDATE_PAGESIZE or NI_SETCANDIDATE_PAGESTART.
 * @param dwIndex Action-specific: for NI_COMPOSITIONSTR, CPS_COMPLETE,
 *        CPS_CANCEL, CPS_CONVERT or CPS_REVERT. Otherwise usually the
 *        candidate list index.
 * @param dwValue Action-specific, such as the candidate index.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmNotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
/**
 * Retrieves the IME status-window position in screen coordinates.
 *
 * @param hIMC Input-context handle.
 * @param lpptPos Receives the position relative to the screen's upper-left
 *        corner.
 * @return Nonzero on success, zero on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI ImmGetStatusWindowPos(HIMC hIMC,LPPOINT lpptPos);
/**
 * Moves the IME status window.
 *
 * @param hIMC The input context.
 * @param lpptPos New position, in screen coordinates.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetStatusWindowPos(HIMC hIMC,LPPOINT lpptPos);
/**
 * Gets the position and style of the composition window.
 *
 * @param hIMC The input context.
 * @param lpCompForm Receives the COMPOSITIONFORM.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmGetCompositionWindow(HIMC hIMC,PCOMPOSITIONFORM lpCompForm);
/**
 * Sets the position and style of the composition window.
 *
 * @param hIMC The input context.
 * @param lpCompForm The COMPOSITIONFORM to apply.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetCompositionWindow(HIMC hIMC,PCOMPOSITIONFORM lpCompForm);
/**
 * Gets the position and style of a candidate window.
 *
 * @param hIMC The input context.
 * @param dwIndex Index of the candidate window.
 * @param lpCandidate Receives the CANDIDATEFORM.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmGetCandidateWindow(HIMC hIMC,DWORD dwIndex,PCANDIDATEFORM lpCandidate);
/**
 * Sets the position and style of a candidate window.
 *
 * The dwIndex member of CANDIDATEFORM can be 0 to 4 on Windows CE.
 *
 * @param hIMC The input context.
 * @param lpCandidate The CANDIDATEFORM to apply.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmSetCandidateWindow(HIMC hIMC,PCANDIDATEFORM lpCandidate);
BOOL WINAPI ImmIsUIMessageA(HWND,UINT,WPARAM,LPARAM);
/**
 * Checks whether a message is meant for the IME window, and passes it on
 * if so.
 *
 * @param hWndIME The default IME window, from ImmGetDefaultIMEWnd.
 * @param msg The message.
 * @param wParam The message's wParam.
 * @param lParam The message's lParam.
 * @return TRUE if the message belongs to the IME window, otherwise FALSE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmIsUIMessageW(HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
/**
 * Retrieves the original virtual key for a key message processed by the
 * IME.
 *
 * The IME replaces the virtual key with VK_PROCESSKEY; use this only for
 * messages containing VK_PROCESSKEY.
 *
 * @param hWnd Window that received the key message.
 * @return Original virtual-key code.
 *
 * @note Windows CE 3.0 only.
 */
UINT WINAPI ImmGetVirtualKey(HWND hWnd);
BOOL WINAPI ImmRegisterWordA(HKL,LPCSTR,DWORD,LPCSTR);
/**
 * Adds a word to an IME's dictionary.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszReading Reading of the word.
 * @param dwStyle Word style, IME_REGWORD_STYLE_* or an IME-specific
 *        value.
 * @param lpszRegister The word.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmRegisterWordW(HKL hKL,LPCWSTR lpszReading,DWORD dwStyle,LPCWSTR lpszRegister);
BOOL WINAPI ImmUnregisterWordA(HKL,LPCSTR,DWORD,LPCSTR);
/**
 * Removes a word from an IME's dictionary.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszReading Reading of the word.
 * @param dwStyle Word style, as passed to ImmRegisterWordW.
 * @param lpszUnregister The word.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI ImmUnregisterWordW(HKL hKL,LPCWSTR lpszReading,DWORD dwStyle,LPCWSTR lpszUnregister);
UINT WINAPI ImmGetRegisterWordStyleA(HKL,UINT,PSTYLEBUFA);
/**
 * Gets the word styles an IME supports.
 *
 * @param hKL Keyboard layout of the IME.
 * @param nItem Number of STYLEBUFW entries in lpStyleBuf, or 0 to query
 *        the count.
 * @param lpStyleBuf Receives the styles.
 * @return Styles copied, or the number available when nItem is 0.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
UINT WINAPI ImmGetRegisterWordStyleW(HKL hKL,UINT nItem,PSTYLEBUFW lpStyleBuf);
UINT WINAPI ImmEnumRegisterWordA(HKL,REGISTERWORDENUMPROCA,LPCSTR,DWORD,LPCSTR,PVOID);
/**
 * Enumerates the words registered with an IME that match a reading,
 * style and string.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpfnEnumProc Callback, called once per matching word.
 * @param lpszReading Reading to match, or NULL for any.
 * @param dwStyle Style to match, or 0 for any.
 * @param lpszRegister Word to match, or NULL for any.
 * @param lpData Passed through to the callback.
 * @return The last value returned by the callback, or 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
UINT WINAPI ImmEnumRegisterWordW(HKL hKL,REGISTERWORDENUMPROCW lpfnEnumProc,LPCWSTR lpszReading,DWORD dwStyle,LPCWSTR lpszRegister,PVOID lpData);
/**
 * Enables or disables text output using end-user-defined characters.
 *
 * Enabled by default during GWES initialization. From Windows CE 2.01,
 * EUDC is supported with TrueType fonts, not raster fonts.
 *
 * @param fEnableEUDC TRUE to enable EUDC, FALSE to disable it.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI EnableEUDC(BOOL fEnableEUDC);
/**
 * Disables the IME for the current thread.
 *
 * Call this before creating the thread's first top-level window. OEM
 * support may vary.
 *
 * @param idThread 0 for the current thread. Before Windows CE 2.10, -1
 *        disables the IME for all threads in the process; from 2.10 it
 *        must be 0.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI ImmDisableIME(DWORD idThread);
DWORD WINAPI ImmGetImeMenuItemsA(HIMC,DWORD,DWORD,LPIMEMENUITEMINFOA,LPIMEMENUITEMINFOA,DWORD);
/**
 * Retrieves menu items registered by an IME.
 *
 * Set `lpImeParentMenu` to NULL for top-level items. Set `lpImeMenu` to
 * NULL to query the number of registered items. `dwSize` is the size of
 * each IMEMENUITEMINFOW structure. OEM support may vary.
 *
 * @param hIMC Input-context handle.
 * @param dwFlags Menu flags, including IGIMIF_RIGHTMENU.
 * @param dwType Combination of IGIMII_* menu-item types.
 * @param lpImeParentMenu Optional parent submenu item.
 * @param lpImeMenu Receives the menu-item array, or NULL to query the count.
 * @param dwSize Size of each IMEMENUITEMINFOW structure, in bytes.
 * @return Number of menu items copied, or registered when querying the count.
 *
 * @note Windows CE 3.0 only.
 */
DWORD WINAPI ImmGetImeMenuItemsW(HIMC hIMC,DWORD dwFlags,DWORD dwType,LPIMEMENUITEMINFOW lpImeParentMenu,LPIMEMENUITEMINFOW lpImeMenu,DWORD dwSize);

#ifdef UNICODE
/**
 * Enumerates the words registered with an IME that match a reading,
 * style and string.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpfnEnumProc Callback, called once per matching word.
 * @param lpszReading Reading to match, or NULL for any.
 * @param dwStyle Style to match, or 0 for any.
 * @param lpszRegister Word to match, or NULL for any.
 * @param lpData Passed through to the callback.
 * @return The last value returned by the callback, or 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmEnumRegisterWord ImmEnumRegisterWordW
/**
 * Gets the word styles an IME supports.
 *
 * @param hKL Keyboard layout of the IME.
 * @param nItem Number of STYLEBUFW entries in lpStyleBuf, or 0 to query
 *        the count.
 * @param lpStyleBuf Receives the styles.
 * @return Styles copied, or the number available when nItem is 0.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleW
/**
 * Removes a word from an IME's dictionary.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszReading Reading of the word.
 * @param dwStyle Word style, as passed to ImmRegisterWordW.
 * @param lpszUnregister The word.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmUnregisterWord ImmUnregisterWordW
/**
 * Adds a word to an IME's dictionary.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszReading Reading of the word.
 * @param dwStyle Word style, IME_REGWORD_STYLE_* or an IME-specific
 *        value.
 * @param lpszRegister The word.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmRegisterWord ImmRegisterWordW
#define ImmInstallIME ImmInstallIMEW
/**
 * Checks whether a message is meant for the IME window, and passes it on
 * if so.
 *
 * @param hWndIME The default IME window, from ImmGetDefaultIMEWnd.
 * @param msg The message.
 * @param wParam The message's wParam.
 * @param lParam The message's lParam.
 * @return TRUE if the message belongs to the IME window, otherwise FALSE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmIsUIMessage ImmIsUIMessageW
/**
 * Gets the conversion results for a character or word without changing
 * the input context.
 *
 * @param hKL Keyboard layout. Must be NULL on Windows CE.
 * @param hIMC The input context.
 * @param lpSrc The string to convert.
 * @param lpDst Receives a CANDIDATELIST of results.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @param uFlag GCL_CONVERSION, GCL_REVERSECONVERSION or
 *        GCL_REVERSE_LENGTH.
 * @return Bytes copied, or needed when dwBufLen is 0. 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetConversionList ImmGetConversionListW
/**
 * Sends an IME-specific escape to an IME.
 *
 * @param hKL Keyboard layout of the IME.
 * @param hIMC The input context.
 * @param uEscape Escape code, IME_ESC_*.
 * @param lpData Escape-specific data.
 * @return Escape-specific, 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmEscape ImmEscapeW
/**
 * Shows an IME's configuration dialog.
 *
 * @param hKL Keyboard layout of the IME.
 * @param hWnd Parent window for the dialog.
 * @param dwMode IME_CONFIG_GENERAL, IME_CONFIG_REGISTERWORD or
 *        IME_CONFIG_SELECTDICTIONARY.
 * @param lpData A REGISTERWORDW for IME_CONFIG_REGISTERWORD, otherwise
 *        NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmConfigureIME ImmConfigureIMEW
#ifndef NOGDI
/**
 * Sets the font used to show the composition string.
 *
 * @param hIMC The input context.
 * @param lplf The font.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmSetCompositionFont ImmSetCompositionFontW
/**
 * Gets the font used to show the composition string.
 *
 * @param hIMC The input context.
 * @param lplf Receives the font.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetCompositionFont ImmGetCompositionFontW
#endif
/**
 * Gets the IME's error or guidance information.
 *
 * @param hIMC The input context.
 * @param dwIndex GGL_LEVEL, GGL_INDEX, GGL_STRING or GGL_PRIVATE.
 * @param lpBuf Receives the string or private data. Unused for GGL_LEVEL
 *        and GGL_INDEX.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return For GGL_LEVEL a GL_LEVEL_* value, for GGL_INDEX a GL_ID_*
 *         value, otherwise bytes copied or needed.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetGuideLine ImmGetGuideLineW
/**
 * Copies a candidate list into a buffer.
 *
 * @param hIMC The input context.
 * @param dwIndex Index of the candidate list.
 * @param lpCandList Receives the CANDIDATELIST and its strings.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return Bytes copied, or needed when dwBufLen is 0. 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetCandidateList ImmGetCandidateListW
/**
 * Gets the number of candidate lists and the buffer size needed for all
 * of them.
 *
 * @param hIMC The input context.
 * @param lpdwListCount Receives the number of candidate lists.
 * @return Bytes needed to hold all the lists, or 0 on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetCandidateListCount ImmGetCandidateListCountW
/**
 * Sets the composition and reading strings, or their attributes or
 * clauses.
 *
 * @param hIMC The input context.
 * @param dwIndex SCS_SETSTR, SCS_CHANGEATTR or SCS_CHANGECLAUSE.
 * @param lpComp Composition data, or NULL.
 * @param dwCompLen Size of lpComp, in bytes.
 * @param lpRead Reading data, or NULL.
 * @param dwReadLen Size of lpRead, in bytes.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmSetCompositionString ImmSetCompositionStringW
/**
 * Gets part of the composition or result string, or its attributes.
 *
 * Usually called on WM_IME_COMPOSITION with GCS_RESULTSTR to collect the
 * finished text.
 *
 * @param hIMC The input context.
 * @param dwIndex What to get: GCS_COMPSTR, GCS_COMPATTR, GCS_COMPCLAUSE,
 *        GCS_COMPREADSTR, GCS_RESULTSTR, GCS_RESULTCLAUSE, GCS_CURSORPOS
 *        and so on.
 * @param lpBuf Receives the data. Strings aren't null-terminated.
 * @param dwBufLen Buffer size in bytes, or 0 to query the size needed.
 * @return Bytes copied, or needed when dwBufLen is 0. For GCS_CURSORPOS,
 *         the cursor position. IMM_ERROR_NODATA or IMM_ERROR_GENERAL on
 *         failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetCompositionString ImmGetCompositionStringW
/**
 * Gets an IME's description string.
 *
 * @param hKL Keyboard layout of the IME.
 * @param lpszDescription Receives the description, or NULL.
 * @param uBufLen Buffer size in characters, or 0 to query the length.
 * @return Characters copied, not counting the terminator, or the length
 *         needed when uBufLen is 0.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define ImmGetDescription ImmGetDescriptionW
/**
 * Retrieves the file name of the IME associated with a keyboard handle.
 *
 * CE uses the handle to distinguish locale-specific IMEs rather than as a
 * true keyboard layout. A zero `uBufLen` queries the required size. Counts
 * are in bytes and exclude the terminating null. OEM support may vary.
 *
 * @param hKL Handle identifying the locale-specific IME.
 * @param lpszFileName Receives the file name.
 * @param uBufLen Output capacity, in bytes.
 * @return Bytes copied or required, excluding the terminator.
 *
 * @note Windows CE 3.0 only.
 */
#define ImmGetIMEFileName ImmGetIMEFileNameW
/**
 * Retrieves menu items registered by an IME.
 *
 * Set `lpImeParentMenu` to NULL for top-level items. Set `lpImeMenu` to
 * NULL to query the number of registered items. `dwSize` is the size of
 * each IMEMENUITEMINFOW structure. OEM support may vary.
 *
 * @param hIMC Input-context handle.
 * @param dwFlags Menu flags, including IGIMIF_RIGHTMENU.
 * @param dwType Combination of IGIMII_* menu-item types.
 * @param lpImeParentMenu Optional parent submenu item.
 * @param lpImeMenu Receives the menu-item array, or NULL to query the count.
 * @param dwSize Size of each IMEMENUITEMINFOW structure, in bytes.
 * @return Number of menu items copied, or registered when querying the count.
 *
 * @note Windows CE 3.0 only.
 */
#define ImmGetImeMenuItems ImmGetImeMenuItemsW
#else
#define ImmEnumRegisterWord ImmEnumRegisterWordA
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleA
#define ImmUnregisterWord ImmUnregisterWordA
#define ImmRegisterWord ImmRegisterWordA
#define ImmInstallIME ImmInstallIMEA
#define ImmIsUIMessage ImmIsUIMessageA
#define ImmGetConversionList ImmGetConversionListA
#define ImmEscape ImmEscapeA
#define ImmConfigureIME ImmConfigureIMEA
#ifndef NOGDI
#define ImmSetCompositionFont ImmSetCompositionFontA
#define ImmGetCompositionFont ImmGetCompositionFontA
#endif
#define ImmGetGuideLine ImmGetGuideLineA
#define ImmGetCandidateList ImmGetCandidateListA
#define ImmGetCandidateListCount ImmGetCandidateListCountA
#define ImmSetCompositionString ImmSetCompositionStringA
#define ImmGetCompositionString ImmGetCompositionStringA
#define ImmGetDescription ImmGetDescriptionA
#define ImmGetIMEFileName ImmGetIMEFileNameA
#define ImmGetImeMenuItems ImmGetImeMenuItemsW
#endif
#ifdef __cplusplus
}
#endif
#endif

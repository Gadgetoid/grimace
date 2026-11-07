#ifndef GRIMACE_SDK_IMM_H
#define GRIMACE_SDK_IMM_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Associates an input context with a window or its child windows.
 *
 * Use IACE_CHILDREN for the current child windows of the calling thread;
 * later-created children are unaffected. IACE_DEFAULT restores the
 * window's default context and ignores `hIMC`. OEM support may vary.
 *
 * @param hWnd Window whose input-context association changes.
 * @param hIMC Input context to associate.
 * @param dwFlags IACE_CHILDREN, IACE_DEFAULT or IACE_IGNORENOCONTEXT.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL ImmAssociateContextEx(HWND hWnd, HIMC hIMC, DWORD dwFlags);
/**
 * Creates a zero-initialized IMC component of the specified size.
 *
 * OEM support may vary.
 *
 * @param dwSize Component size, in bytes.
 * @return IMC-component handle, or zero on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HIMCC ImmCreateIMCC(DWORD dwSize);
/**
 * Destroys an IMC component.
 *
 * OEM support may vary.
 *
 * @param hIMCC IMC-component handle.
 * @return NULL on success, or the handle on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HIMCC ImmDestroyIMCC(HIMCC hIMCC);
/**
 * Posts the IME messages stored in the input context's message buffer.
 *
 * Typically called by an IME after changing the context without user
 * keystroke activity. OEM support may vary.
 *
 * @param hIMC Input-context handle containing the messages.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmGenerateMessage(HIMC hIMC);
/**
 * Retrieves the modifiers, virtual key and IME associated with a hot key.
 *
 * CE does not support true keyboard layouts; the returned handle identifies
 * the current IME and locale. OEM support may vary.
 *
 * @param dwHotKeyID Hot-key identifier.
 * @param lpuModifiers Receives the modifier keys.
 * @param lpuVKey Receives the virtual-key code.
 * @param lphKL Receives the associated keyboard handle.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmGetHotKey(DWORD dwHotKeyID, LPUINT lpuModifiers, LPUINT lpuVKey, LPHKL lphKL);
/**
 * Retrieves the lock count of an IMC component.
 *
 * @param hIMCC IMC-component handle.
 * @return Component lock count.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD ImmGetIMCCLockCount(HIMCC hIMCC);
/**
 * Retrieves the size of an IMC component.
 *
 * @param hIMCC IMC-component handle.
 * @return Component size, in bytes.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD ImmGetIMCCSize(HIMCC hIMCC);
/**
 * Retrieves the lock count of an input method context.
 *
 * @param hIMC Input-context handle.
 * @return Lock count, or zero if the context is invalid.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD ImmGetIMCLockCount(HIMC hIMC);
struct tagINPUTCONTEXT;
typedef struct tagINPUTCONTEXT *LPINPUTCONTEXT;
/**
 * Locks an input context and returns its INPUTCONTEXT pointer.
 *
 * The call increments the context lock count; call ImmUnlockIMC when
 * finished. OEM support may vary.
 *
 * @param hIMC Input-context handle.
 * @return INPUTCONTEXT pointer, or NULL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LPINPUTCONTEXT ImmLockIMC(HIMC hIMC);
/**
 * Returns a pointer to an IMC component.
 *
 * Windows CE does not use the component lock count. OEM support may vary.
 *
 * @param hIMCC IMC-component handle.
 * @return Component pointer, or NULL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LPVOID ImmLockIMCC(HIMCC hIMCC);
/**
 * Changes the size of an IMC component.
 *
 * Use the returned handle, which may differ from the input handle. OEM
 * support may vary.
 *
 * @param hIMCC IMC-component handle.
 * @param dwSize New component size, in bytes.
 * @return Resized component handle, or zero on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HIMCC ImmReSizeIMCC(HIMCC hIMCC, DWORD dwSize);
/**
 * Generates a WM_IME_REQUEST message for an input method.
 *
 * The operation and result are specified by the WM_IME_REQUEST message
 * parameters.
 *
 * @param hIMC Input context for the request.
 * @param wParam WM_IME_REQUEST operation.
 * @param lParam Operation-specific value.
 * @return Operation-specific result, or zero on failure.
 *
 * @note Windows CE 3.0 only.
 */
LRESULT ImmRequestMessageW(HIMC hIMC, WPARAM wParam, LPARAM lParam);
/**
 * Queries or changes input-panel state and location.
 *
 * `dwCmd` selects the operation; `pValue` points to its command-specific
 * data. The reference documents this API for Japanese builds, so do not
 * assume it is implemented on other OEM images.
 *
 * @param dwCmd SIP_QUERY_LOCATION, SIP_QUERY_STATE, SIP_SET_LOCATION or
 *        SIP_INPUT_ATTRIBUTES.
 * @param pValue Command-specific input or output data.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmSIPanelState(UINT dwCmd, LPVOID pValue);
/**
 * Sets an IME hot key.
 *
 * CE uses `hKL` to associate the hot key with an IME and locale, not a
 * true keyboard layout. OEM support may vary.
 *
 * @param dwHotKeyID Hot-key identifier.
 * @param uModifiers Modifier-key flags.
 * @param uVKey Virtual-key code.
 * @param hKL Handle identifying the IME and locale.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmSetHotKey(DWORD dwHotKeyID, UINT uModifiers, UINT uVKey, HKL hKL);
/**
 * Reduces the lock count of an input method context.
 *
 * The return value is FALSE when the count reaches zero, TRUE otherwise.
 *
 * @param hIMC Input-context handle.
 * @return FALSE if the count reaches zero, TRUE otherwise.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmUnlockIMC(HIMC hIMC);
/**
 * Reduces the lock count of an IMC component.
 *
 * The return value is FALSE when the count reaches zero, TRUE otherwise.
 *
 * @param hIMCC IMC-component handle.
 * @return FALSE if the count reaches zero, TRUE otherwise.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL ImmUnlockIMCC(HIMCC hIMCC);
struct tagCANDIDATEINFO;
typedef struct tagCANDIDATEINFO CANDIDATEINFO;
struct tagCOMPOSITIONSTRING;
typedef struct tagCOMPOSITIONSTRING COMPOSITIONSTRING;
struct tagGUIDELINE;
typedef struct tagGUIDELINE GUIDELINE;
struct _tagHWXRESULT;
typedef struct _tagHWXRESULT HWXRESULT;
struct tagIMEINFO;
typedef struct tagIMEINFO IMEINFO;
typedef struct tagINPUTCONTEXT INPUTCONTEXT;
typedef struct tagCANDIDATEINFO *LPCANDIDATEINFO;
typedef struct tagCOMPOSITIONSTRING *LPCOMPOSITIONSTRING;
typedef struct tagGUIDELINE *LPGUIDELINE;
typedef struct tagIMECHARPOSITION *LPIMECHARPOSITION;
typedef struct tagIMEINFO *LPIMEINFO;
typedef struct tagRECONVERTSTRING *LPRECONVERTSTRING;
struct tagSOFTKBDDATA;
typedef struct tagSOFTKBDDATA *LPSOFTKBDDATA;
struct _MYCANDLIST;
typedef struct _MYCANDLIST MYCANDLIST;
typedef struct tagCANDIDATEFORM *NPCANDIDATEFORM;
typedef struct tagCANDIDATEINFO *NPCANDIDATEINFO;
typedef struct tagCANDIDATELIST *NPCANDIDATELIST;
typedef struct tagCOMPOSITIONFORM *NPCOMPOSITIONFORM;
typedef struct tagCOMPOSITIONSTRING *NPCOMPOSITIONSTRING;
typedef struct tagGUIDELINE *NPGUIDELINE;
typedef struct tagIMECHARPOSITION *NPIMECHARPOSITION;
typedef struct tagIMEINFO *NPIMEINFO;
typedef struct tagIMEMENUITEMINFOW *NPIMEMENUITEMINFOW;
typedef NPIMEMENUITEMINFOW NPIMEMENUITEMINFO;
typedef struct tagIMEMENUITEMINFOA *NPIMEMENUITEMINFOA;
typedef struct tagINPUTCONTEXT *NPINPUTCONTEXT;
typedef struct tagRECONVERTSTRING *NPRECONVERTSTRING;
typedef struct tagREGISTERWORDW *NPREGISTERWORDW;
typedef NPREGISTERWORDW NPREGISTERWORD;
typedef struct tagREGISTERWORDA *NPREGISTERWORDA;
typedef struct tagSOFTKBDDATA *NPSOFTKBDDATA;
typedef struct tagSTYLEBUFW *NPSTYLEBUFW;
typedef NPSTYLEBUFW NPSTYLEBUF;
typedef struct tagSTYLEBUFA *NPSTYLEBUFA;
typedef struct tagCANDIDATEINFO *PCANDIDATEINFO;
typedef struct tagCOMPOSITIONSTRING *PCOMPOSITIONSTRING;
typedef struct tagGUIDELINE *PGUIDELINE;
typedef struct _tagHWXRESULT *PHWXRESULT;
typedef struct tagIMEINFO *PIMEINFO;
typedef struct tagINPUTCONTEXT *PINPUTCONTEXT;
typedef struct tagSOFTKBDDATA *PSOFTKBDDATA;
typedef struct tagSOFTKBDDATA SOFTKBDDATA;
struct _MYCANDLIST {
    HWND ParentWnd;
    LPCANDIDATELIST CandList;
};

struct _tagHWXRESULT {
    WORD cbCount;
    WORD iSelection;
    WORD iPosition;
    TCHAR chCandidate[1];
};

struct tagCANDIDATEINFO {
    DWORD dwSize;
    DWORD dwCount;
    DWORD dwOffset[32];
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
};

struct tagCOMPOSITIONSTRING {
    DWORD dwSize;
    DWORD dwCompReadAttrLen;
    DWORD dwCompReadAttrOffset;
    DWORD dwCompReadClauseLen;
    DWORD dwCompReadClauseOffset;
    DWORD dwCompReadStrLen;
    DWORD dwCompReadStrOffset;
    DWORD dwCompAttrLen;
    DWORD dwCompAttrOffset;
    DWORD dwCompClauseLen;
    DWORD dwCompClauseOffset;
    DWORD dwCompStrLen;
    DWORD dwCompStrOffset;
    DWORD dwCursorPos;
    DWORD dwDeltaStart;
    DWORD dwResultReadClauseLen;
    DWORD dwResultReadClauseOffset;
    DWORD dwResultReadStrLen;
    DWORD dwResultReadStrOffset;
    DWORD dwResultClauseLen;
    DWORD dwResultClauseOffset;
    DWORD dwResultStrLen;
    DWORD dwResultStrOffset;
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
};

struct tagGUIDELINE {
    DWORD dwSize;
    DWORD dwLevel;
    DWORD dwIndex;
    DWORD dwStrLen;
    DWORD dwStrOffset;
    DWORD dwPrivateSize;
    DWORD dwPrivateOffset;
};

struct tagIMEINFO {
    DWORD dwPrivateDataSize;
    DWORD fdwProperty;
    DWORD fdwConversionCaps;
    DWORD fdwSentenceCaps;
    DWORD fdwUICaps;
    DWORD fdwSCSCaps;
    DWORD fdwSelectCaps;
};

struct tagINPUTCONTEXT {
    HWND hWnd;
    BOOL fOpen;
    DWORD fdwClient;
    HWND hwndImeInUse;
    POINT ptStatusWndPos;
    POINT ptSoftKbdPos;
    DWORD fdwConversion;
    DWORD fdwSentence;
    union {
        LOGFONTA A;
        LOGFONTW W;
    } lfFont;
    COMPOSITIONFORM cfCompForm;
    CANDIDATEFORM cfCandForm[4];
    HIMCC hCompStr;
    HIMCC hCandInfo;
    HIMCC hGuideLine;
    HIMCC hPrivate;
    DWORD dwNumMsgBuf;
    HIMCC hMsgBuf;
    DWORD fdwInit;
    DWORD dwReserve[3];
    UINT uSavedVKey;
    BOOL fChgMsg;
    DWORD fdwFlags;
    DWORD fdw31Compat;
    DWORD dwRefCount;
};

struct tagSOFTKBDDATA {
    UINT uCount;
    WORD wCode[1][256];
};


#ifdef __cplusplus
}
#endif

#endif

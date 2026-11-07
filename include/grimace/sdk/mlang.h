#ifndef GRIMACE_SDK_MLANG_H
#define GRIMACE_SDK_MLANG_H

#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

HRESULT ConvertINetMultiByteToUnicode(LPDWORD lpdwMode, DWORD dwEncoding, LPCSTR lpSrcStr, LPINT lpnMultiCharCount, LPWSTR lpDstStr, LPINT lpnWideCharCount);
HRESULT ConvertINetString(LPDWORD lpdwMode, DWORD dwSrcEncoding, DWORD dwDstEncoding, LPCSTR lpSrcStr, LPINT lpnSrcSize, LPSTR lpDstStr, LPINT lpnDstSize);
HRESULT ConvertINetUnicodeToMultiByte(LPDWORD lpdwMode, DWORD dwEncoding, LPCWSTR lpSrcStr, LPINT lpnWideCharCount, LPSTR lpDstStr, LPINT lpnMultiCharCount);
HRESULT IsConvertINetStringAvailable(DWORD dwSrcEncoding, DWORD dwDstEncoding);
/**
 * Converts a locale identifier to an RFC 1766 language tag, such as
 * "en-us".
 *
 * @param Locale The locale.
 * @param pszRfc1766 Receives the null-terminated tag.
 * @param nChar Size of pszRfc1766 in characters.
 * @return S_OK on success, or an error HRESULT.
 *
 * @note Windows CE 3.0 only.
 */
HRESULT LcidToRfc1766W(LCID Locale, LPWSTR pszRfc1766, int nChar);
/**
 * Converts an RFC 1766 language tag, such as "en-us", to a locale
 * identifier.
 *
 * @param pLocale Receives the locale.
 * @param pszRfc1766 The tag.
 * @return S_OK on success, or an error HRESULT.
 *
 * @note Windows CE 3.0 only.
 */
HRESULT Rfc1766ToLcidW(LCID *pLocale, LPCWSTR pszRfc1766);
typedef struct {

} CMLangConvertCharset;

typedef struct {

} CMLangString;

typedef struct {

} CMultiLanguage;

struct IEnumCodePage;
typedef struct IEnumCodePage IEnumCodePage;
struct IEnumCodePageVtbl;
typedef struct IEnumCodePageVtbl IEnumCodePageVtbl;
struct IEnumRfc1766;
typedef struct IEnumRfc1766 IEnumRfc1766;
struct IEnumRfc1766Vtbl;
typedef struct IEnumRfc1766Vtbl IEnumRfc1766Vtbl;
struct IMLangCodePages;
typedef struct IMLangCodePages IMLangCodePages;
struct IMLangCodePagesVtbl;
typedef struct IMLangCodePagesVtbl IMLangCodePagesVtbl;
struct IMLangConvertCharset;
typedef struct IMLangConvertCharset IMLangConvertCharset;
struct IMLangConvertCharsetVtbl;
typedef struct IMLangConvertCharsetVtbl IMLangConvertCharsetVtbl;
struct IMLangFontLink;
typedef struct IMLangFontLink IMLangFontLink;
struct IMLangFontLinkVtbl;
typedef struct IMLangFontLinkVtbl IMLangFontLinkVtbl;
struct IMLangLineBreakConsole;
typedef struct IMLangLineBreakConsole IMLangLineBreakConsole;
struct IMLangLineBreakConsoleVtbl;
typedef struct IMLangLineBreakConsoleVtbl IMLangLineBreakConsoleVtbl;
struct IMLangString;
typedef struct IMLangString IMLangString;
struct IMLangStringAStr;
typedef struct IMLangStringAStr IMLangStringAStr;
struct IMLangStringAStrVtbl;
typedef struct IMLangStringAStrVtbl IMLangStringAStrVtbl;
struct IMLangStringBufA;
typedef struct IMLangStringBufA IMLangStringBufA;
struct IMLangStringBufAVtbl;
typedef struct IMLangStringBufAVtbl IMLangStringBufAVtbl;
struct IMLangStringBufW;
typedef struct IMLangStringBufW IMLangStringBufW;
struct IMLangStringBufWVtbl;
typedef struct IMLangStringBufWVtbl IMLangStringBufWVtbl;
struct IMLangStringVtbl;
typedef struct IMLangStringVtbl IMLangStringVtbl;
struct IMLangStringWStr;
typedef struct IMLangStringWStr IMLangStringWStr;
struct IMLangStringWStrVtbl;
typedef struct IMLangStringWStrVtbl IMLangStringWStrVtbl;
struct IMultiLanguage;
typedef struct IMultiLanguage IMultiLanguage;
struct IMultiLanguageVtbl;
typedef struct IMultiLanguageVtbl IMultiLanguageVtbl;
typedef IEnumCodePage *LPENUMCODEPAGE;
typedef IEnumRfc1766 *LPENUMRFC1766;
typedef IMLangConvertCharset *LPMLANGCONVERTCHARSET;
typedef IMultiLanguage *LPMULTILANGUAGE;
enum tagMIMECONTF {
    MIMECONTF_MAILNEWS = 1,
    MIMECONTF_BROWSER = 2,
    MIMECONTF_MINIMAL = 4,
    MIMECONTF_SAVABLE_MAILNEWS = 256,
    MIMECONTF_SAVABLE_BROWSER = 512,
    MIMECONTF_PRIVCONVERTER = 65536,
    MIMECONTF_VALID = 131072
};

typedef enum tagMIMECONTF MIMECONTF;
struct tagMIMECPINFO;
typedef struct tagMIMECPINFO MIMECPINFO;
struct tagMIMECSETINFO;
typedef struct tagMIMECSETINFO MIMECSETINFO;
enum tagMLCONVCHARF {
    MLCONVCHARF_AUTODETECT = 1,
    MLCONVCHARF_ENTITIZE = 2
};

typedef enum tagMLCONVCHARF MLCONVCHAR;
enum tagMLSTR_FLAGS {
    MLSTR_READ = 1,
    MLSTR_WRITE = 2
};

typedef enum tagMLSTR_FLAGS MLSTR_FLAGS;
typedef struct tagMIMECPINFO *PMIMECPINFO;
typedef struct tagMIMECSETINFO *PMIMECSETINFO;
typedef IMLangCodePages *PMLANGCODEPAGES;
typedef IMLangFontLink *PMLANGFONTLINK;
struct tagRFC1766INFO;
typedef struct tagRFC1766INFO *PRFC1766INFO;
typedef struct tagRFC1766INFO RFC1766INFO;
struct IEnumCodePage {
    struct IEnumCodePageVtbl *lpVtbl;
};

struct IEnumCodePageVtbl {
    HRESULT (*QueryInterface)(IEnumCodePage *, const IID *const, void **);
    ULONG (*AddRef)(IEnumCodePage *);
    ULONG (*Release)(IEnumCodePage *);
    HRESULT (*Clone)(IEnumCodePage *, IEnumCodePage **);
    HRESULT (*Next)(IEnumCodePage *, ULONG, PMIMECPINFO, ULONG *);
    HRESULT (*Reset)(IEnumCodePage *);
    HRESULT (*Skip)(IEnumCodePage *, ULONG);
};

struct IEnumRfc1766 {
    struct IEnumRfc1766Vtbl *lpVtbl;
};

struct IEnumRfc1766Vtbl {
    HRESULT (*QueryInterface)(IEnumRfc1766 *, const IID *const, void **);
    ULONG (*AddRef)(IEnumRfc1766 *);
    ULONG (*Release)(IEnumRfc1766 *);
    HRESULT (*Clone)(IEnumRfc1766 *, IEnumRfc1766 **);
    HRESULT (*Next)(IEnumRfc1766 *, ULONG, PRFC1766INFO, ULONG *);
    HRESULT (*Reset)(IEnumRfc1766 *);
    HRESULT (*Skip)(IEnumRfc1766 *, ULONG);
};

struct IMLangCodePages {
    struct IMLangCodePagesVtbl *lpVtbl;
};

struct IMLangCodePagesVtbl {
    HRESULT (*QueryInterface)(IMLangCodePages *, const IID *const, void **);
    ULONG (*AddRef)(IMLangCodePages *);
    ULONG (*Release)(IMLangCodePages *);
    HRESULT (*GetCharCodePages)(IMLangCodePages *, WCHAR, DWORD *);
    HRESULT (*GetStrCodePages)(IMLangCodePages *, const WCHAR *, long, DWORD, DWORD *, long *);
    HRESULT (*CodePageToCodePages)(IMLangCodePages *, UINT, DWORD *);
    HRESULT (*CodePagesToCodePage)(IMLangCodePages *, DWORD, UINT, UINT *);
};

struct IMLangConvertCharset {
    struct IMLangConvertCharsetVtbl *lpVtbl;
};

struct IMLangConvertCharsetVtbl {
    HRESULT (*QueryInterface)(IMLangConvertCharset *, const IID *const, void **);
    ULONG (*AddRef)(IMLangConvertCharset *);
    ULONG (*Release)(IMLangConvertCharset *);
    HRESULT (*Initialize)(IMLangConvertCharset *, UINT, UINT, DWORD);
    HRESULT (*GetSourceCodePage)(IMLangConvertCharset *, UINT *);
    HRESULT (*GetDestinationCodePage)(IMLangConvertCharset *, UINT *);
    HRESULT (*GetProperty)(IMLangConvertCharset *, DWORD *);
    HRESULT (*DoConversion)(IMLangConvertCharset *, BYTE *, UINT *, BYTE *, UINT *);
    HRESULT (*DoConversionToUnicode)(IMLangConvertCharset *, CHAR *, UINT *, WCHAR *, UINT *);
    HRESULT (*DoConversionFromUnicode)(IMLangConvertCharset *, WCHAR *, UINT *, CHAR *, UINT *);
};

struct IMLangFontLink {
    struct IMLangFontLinkVtbl *lpVtbl;
};

struct IMLangFontLinkVtbl {
    HRESULT (*QueryInterface)(IMLangFontLink *, const IID *const, void **);
    ULONG (*AddRef)(IMLangFontLink *);
    ULONG (*Release)(IMLangFontLink *);
    HRESULT (*GetCharCodePages)(IMLangFontLink *, WCHAR, DWORD *);
    HRESULT (*GetStrCodePages)(IMLangFontLink *, const WCHAR *, long, DWORD, DWORD *, long *);
    HRESULT (*CodePageToCodePages)(IMLangFontLink *, UINT, DWORD *);
    HRESULT (*CodePagesToCodePage)(IMLangFontLink *, DWORD, UINT, UINT *);
    HRESULT (*GetFontCodePages)(IMLangFontLink *, HDC, HFONT, DWORD *);
    HRESULT (*MapFont)(IMLangFontLink *, HDC, DWORD, HFONT, HFONT *);
    HRESULT (*ReleaseFont)(IMLangFontLink *, HFONT);
    HRESULT (*ResetFontMapping)(IMLangFontLink *);
};

struct IMLangLineBreakConsole {
    struct IMLangLineBreakConsoleVtbl *lpVtbl;
};

struct IMLangLineBreakConsoleVtbl {
    HRESULT (*QueryInterface)(IMLangLineBreakConsole *, const IID *const, void **);
    ULONG (*AddRef)(IMLangLineBreakConsole *);
    ULONG (*Release)(IMLangLineBreakConsole *);
    HRESULT (*BreakLineML)(IMLangLineBreakConsole *, IMLangString *, long, long, long, long, long *, long *);
    HRESULT (*BreakLineW)(IMLangLineBreakConsole *, LCID, const WCHAR *, long, long, long *, long *);
    HRESULT (*BreakLineA)(IMLangLineBreakConsole *, LCID, UINT, const CHAR *, long, long, long *, long *);
};

struct IMLangString {
    struct IMLangStringVtbl *lpVtbl;
};

struct IMLangStringAStr {
    struct IMLangStringAStrVtbl *lpVtbl;
};

struct IMLangStringAStrVtbl {
    HRESULT (*QueryInterface)(IMLangStringAStr *, const IID *const, void **);
    ULONG (*AddRef)(IMLangStringAStr *);
    ULONG (*Release)(IMLangStringAStr *);
    HRESULT (*Sync)(IMLangStringAStr *, BOOL);
    HRESULT (*GetLength)(IMLangStringAStr *, long *);
    HRESULT (*SetMLStr)(IMLangStringAStr *, long, long, IUnknown *, long, long);
    HRESULT (*GetMLStr)(IMLangStringAStr *, long, long, IUnknown *, DWORD, const IID *, IUnknown **, long *, long *);
    HRESULT (*SetAStr)(IMLangStringAStr *, long, long, UINT, const CHAR *, long, long *, long *);
    HRESULT (*SetStrBufA)(IMLangStringAStr *, long, long, UINT, IMLangStringBufA *, long *, long *);
    HRESULT (*GetAStr)(IMLangStringAStr *, long, long, UINT, UINT *, CHAR *, long, long *, long *);
    HRESULT (*GetStrBufA)(IMLangStringAStr *, long, long, UINT *, IMLangStringBufA **, long *);
    HRESULT (*LockAStr)(IMLangStringAStr *, long, long, long, UINT, long, UINT *, CHAR **, long *, long *);
    HRESULT (*UnlockAStr)(IMLangStringAStr *, const CHAR *, long, long *, long *);
    HRESULT (*SetLocale)(IMLangStringAStr *, long, long, LCID);
    HRESULT (*GetLocale)(IMLangStringAStr *, long, long, LCID *, long *, long *);
};

struct IMLangStringBufA {
    struct IMLangStringBufAVtbl *lpVtbl;
};

struct IMLangStringBufAVtbl {
    HRESULT (*QueryInterface)(IMLangStringBufA *, const IID *const, void **);
    ULONG (*AddRef)(IMLangStringBufA *);
    ULONG (*Release)(IMLangStringBufA *);
    HRESULT (*GetStatus)(IMLangStringBufA *, long *, long *);
    HRESULT (*LockBuf)(IMLangStringBufA *, long, long, CHAR **, long *);
    HRESULT (*UnlockBuf)(IMLangStringBufA *, const CHAR *, long, long);
    HRESULT (*Insert)(IMLangStringBufA *, long, long, long *);
    HRESULT (*Delete)(IMLangStringBufA *, long, long);
};

struct IMLangStringBufW {
    struct IMLangStringBufWVtbl *lpVtbl;
};

struct IMLangStringBufWVtbl {
    HRESULT (*QueryInterface)(IMLangStringBufW *, const IID *const, void **);
    ULONG (*AddRef)(IMLangStringBufW *);
    ULONG (*Release)(IMLangStringBufW *);
    HRESULT (*GetStatus)(IMLangStringBufW *, long *, long *);
    HRESULT (*LockBuf)(IMLangStringBufW *, long, long, WCHAR **, long *);
    HRESULT (*UnlockBuf)(IMLangStringBufW *, const WCHAR *, long, long);
    HRESULT (*Insert)(IMLangStringBufW *, long, long, long *);
    HRESULT (*Delete)(IMLangStringBufW *, long, long);
};

struct IMLangStringVtbl {
    HRESULT (*QueryInterface)(IMLangString *, const IID *const, void **);
    ULONG (*AddRef)(IMLangString *);
    ULONG (*Release)(IMLangString *);
    HRESULT (*Sync)(IMLangString *, BOOL);
    HRESULT (*GetLength)(IMLangString *, long *);
    HRESULT (*SetMLStr)(IMLangString *, long, long, IUnknown *, long, long);
    HRESULT (*GetMLStr)(IMLangString *, long, long, IUnknown *, DWORD, const IID *, IUnknown **, long *, long *);
};

struct IMLangStringWStr {
    struct IMLangStringWStrVtbl *lpVtbl;
};

struct IMLangStringWStrVtbl {
    HRESULT (*QueryInterface)(IMLangStringWStr *, const IID *const, void **);
    ULONG (*AddRef)(IMLangStringWStr *);
    ULONG (*Release)(IMLangStringWStr *);
    HRESULT (*Sync)(IMLangStringWStr *, BOOL);
    HRESULT (*GetLength)(IMLangStringWStr *, long *);
    HRESULT (*SetMLStr)(IMLangStringWStr *, long, long, IUnknown *, long, long);
    HRESULT (*GetMLStr)(IMLangStringWStr *, long, long, IUnknown *, DWORD, const IID *, IUnknown **, long *, long *);
    HRESULT (*SetWStr)(IMLangStringWStr *, long, long, const WCHAR *, long, long *, long *);
    HRESULT (*SetStrBufW)(IMLangStringWStr *, long, long, IMLangStringBufW *, long *, long *);
    HRESULT (*GetWStr)(IMLangStringWStr *, long, long, WCHAR *, long, long *, long *);
    HRESULT (*GetStrBufW)(IMLangStringWStr *, long, long, IMLangStringBufW **, long *);
    HRESULT (*LockWStr)(IMLangStringWStr *, long, long, long, long, WCHAR **, long *, long *);
    HRESULT (*UnlockWStr)(IMLangStringWStr *, const WCHAR *, long, long *, long *);
    HRESULT (*SetLocale)(IMLangStringWStr *, long, long, LCID);
    HRESULT (*GetLocale)(IMLangStringWStr *, long, long, LCID *, long *, long *);
};

struct IMultiLanguage {
    struct IMultiLanguageVtbl *lpVtbl;
};

struct IMultiLanguageVtbl {
    HRESULT (*QueryInterface)(IMultiLanguage *, const IID *const, void **);
    ULONG (*AddRef)(IMultiLanguage *);
    ULONG (*Release)(IMultiLanguage *);
    HRESULT (*GetNumberOfCodePageInfo)(IMultiLanguage *, UINT *);
    HRESULT (*GetCodePageInfo)(IMultiLanguage *, UINT, PMIMECPINFO);
    HRESULT (*GetFamilyCodePage)(IMultiLanguage *, UINT, UINT *);
    HRESULT (*EnumCodePages)(IMultiLanguage *, DWORD, IEnumCodePage **);
    HRESULT (*GetCharsetInfo)(IMultiLanguage *, BSTR, PMIMECSETINFO);
    HRESULT (*IsConvertible)(IMultiLanguage *, DWORD, DWORD);
    HRESULT (*ConvertString)(IMultiLanguage *, DWORD *, DWORD, DWORD, BYTE *, UINT *, BYTE *, UINT *);
    HRESULT (*ConvertStringToUnicode)(IMultiLanguage *, DWORD *, DWORD, CHAR *, UINT *, WCHAR *, UINT *);
    HRESULT (*ConvertStringFromUnicode)(IMultiLanguage *, DWORD *, DWORD, WCHAR *, UINT *, CHAR *, UINT *);
    HRESULT (*ConvertStringReset)(IMultiLanguage *);
    HRESULT (*GetRfc1766FromLcid)(IMultiLanguage *, LCID, BSTR *);
    HRESULT (*GetLcidFromRfc1766)(IMultiLanguage *, LCID *, BSTR);
    HRESULT (*EnumRfc1766)(IMultiLanguage *, IEnumRfc1766 **);
    HRESULT (*GetRfc1766Info)(IMultiLanguage *, LCID, PRFC1766INFO);
    HRESULT (*CreateConvertCharset)(IMultiLanguage *, UINT, UINT, DWORD, IMLangConvertCharset **);
};

struct tagMIMECPINFO {
    DWORD dwFlags;
    UINT uiCodePage;
    UINT uiFamilyCodePage;
    WCHAR wszDescription[64];
    WCHAR wszWebCharset[50];
    WCHAR wszHeaderCharset[50];
    WCHAR wszBodyCharset[50];
    WCHAR wszFixedWidthFont[32];
    WCHAR wszProportionalFont[32];
    BYTE bGDICharset;
};

struct tagMIMECSETINFO {
    UINT uiCodePage;
    UINT uiInternetEncoding;
    WCHAR wszCharset[50];
};

struct tagRFC1766INFO {
    LCID lcid;
    WCHAR wszRfc1766[6];
    WCHAR wszLocaleName[32];
};


#ifdef __cplusplus
}
#endif

#endif

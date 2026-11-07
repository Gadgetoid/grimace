#ifndef GRIMACE_SDK_TNEFAPI_H
#define GRIMACE_SDK_TNEFAPI_H

#include <grimace/sdk/msgstore.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Converts a modified UTF-7 string to Unicode.
 *
 * The input length is in bytes and the output capacity is in wide characters.
 * The returned count includes the terminating null. Zero indicates failure.
 * OEM support may vary.
 *
 * @param lpMultiByteStr Modified UTF-7 input string.
 * @param cchMultiByte Number of input bytes.
 * @param lpWideCharStr Receives the null-terminated Unicode string.
 * @param cchWideChar Output buffer capacity in wide characters.
 * @return Character count including the terminator, or zero on failure.
 *
 * @note Windows CE 3.0 only.
 */
int ModifiedUTF7ToUnicode(LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
struct _tnefinfo;
typedef struct _tnefinfo TNEFINFO;
/**
 * Creates an encoded TNEF file from message properties and attachments.
 *
 * The output file name comes from `pti->szTnefFileName`. The documented
 * implementation supports meeting request properties. OEM support may vary.
 *
 * @param pti TNEF file information, including the output file name.
 * @param szSubject Null-terminated message subject.
 * @param lpnii Non-IPM message properties.
 * @param lpmaa Attachment information.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL TnefBuildInfo(const TNEFINFO *pti, LPWSTR szSubject, MailNonIpmInfo *lpnii, MailAttArray *lpmaa);
/**
 * Converts a string from a supported code page to Unicode.
 *
 * Documented code pages are 1250-1258, 20866, 21886, 28592-28600, 28604,
 * 28605, 65000 and 65001. `MB_PRECOMPOSED` is the default; `MB_COMPOSITE`
 * is mutually exclusive with it. `MB_ERR_INVALID_CHARS` makes invalid input
 * fail with `ERROR_NO_UNICODE_TRANSLATION`; `MB_USEGLYPHCHARS` selects glyph
 * characters instead of control characters. If `cchWideChar` is zero, the
 * return value is the required output size. OEM support may vary.
 *
 * @param CodePage Source code page identifier.
 * @param dwFlags Character conversion flags.
 * @param lpMultiByteStr Input string.
 * @param cchMultiByte Number of input characters.
 * @param lpWideCharStr Receives the converted string.
 * @param cchWideChar Output capacity in wide characters, or zero to query size.
 * @return Number of wide characters written or required, or zero on failure.
 *
 * @note Windows CE 3.0 only.
 */
int TnefConvertToUnicode(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
typedef enum {
    CODE_NONE = 0,
    CODE_UU,
    CODE_B64,
    CODE_QP,
    CODE_QPH,
    CODE_QP_SIZE
} INETENCODE;

/**
 * Decodes a Base64, quoted-printable or UUEncoded buffer.
 *
 * `puiLength` supplies the output buffer capacity in bytes and receives the
 * decoded size. If the buffer is too small, it receives the required size.
 * Use `TransportError` or `TransportErrorMsg` for extended error information.
 * OEM support may vary.
 *
 * @param EncodeType Encoding format.
 * @param BufToDecode Encoded input buffer.
 * @param DecodedBuf Receives the decoded bytes.
 * @param puiLength Input capacity and output decoded size, in bytes.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL TnefDecodeBuffer(INETENCODE EncodeType, LPSTR BufToDecode, BYTE *DecodedBuf, UINT *puiLength);
/**
 * Decodes a Base64, quoted-printable or UUEncoded file.
 *
 * On success, the decoded file is written to `DecodedFileName`; delete it
 * when it is no longer needed. OEM support may vary.
 *
 * @param EncodeType Encoding format.
 * @param FileToDecode Input file name.
 * @param DecodedFileName Output file name.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL TnefDecodeFile(INETENCODE EncodeType, LPWSTR FileToDecode, LPWSTR DecodedFileName);
/**
 * Encodes a buffer as Base64, quoted-printable or UUEncode.
 *
 * `pcbOut` supplies the output buffer capacity and receives the encoded size.
 * The call fails if the output buffer is too small. OEM support may vary.
 *
 * @param EncodeType Encoding format.
 * @param cbIn Input size, in bytes.
 * @param BufToEncode Data to encode.
 * @param pcbOut Input output capacity and output encoded size, in bytes.
 * @param EncodedBuf Receives the encoded data.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL TnefEncodeBuffer(INETENCODE EncodeType, UINT cbIn, BYTE *BufToEncode, UINT *pcbOut, LPSTR EncodedBuf);
/**
 * Encodes a file as Base64, quoted-printable or UUEncode.
 *
 * The input file is unchanged. The returned file name is allocated and must
 * be released with `LocalFree`; delete the encoded file when finished. OEM
 * support may vary.
 *
 * @param FileToEncode Input file name.
 * @param EncodeType Encoding format.
 * @return Name of the encoded file, or NULL on failure.
 *
 * @note Windows CE 3.0 only.
 */
LPWSTR TnefEncodeFile(LPWSTR FileToEncode, INETENCODE EncodeType);
/**
 * Extracts message properties and optional attachment information from a TNEF file.
 *
 * The file named by `pti` is deleted whether the call succeeds or fails.
 * OEM support may vary.
 *
 * @param pti Information describing the TNEF file.
 * @param lplpnii Receives the non-IPM message properties.
 * @param lplpmaa Optionally receives attachment information.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL TnefGetInfo(const TNEFINFO *pti, MailNonIpmInfo **lplpnii, MailAttArray **lplpmaa);
/**
 * Converts a Unicode string to modified UTF-7.
 *
 * The input count and output capacity are character counts. A return value
 * equal to `cchIn` indicates success; a smaller value indicates failure.
 * OEM support may vary.
 *
 * @param wszIn Unicode input string.
 * @param cchIn Number of input characters.
 * @param pchOut Receives the modified UTF-7 string.
 * @param cchOut Output buffer capacity in characters.
 * @return Number of input characters translated; `cchIn` indicates success.
 *
 * @note Windows CE 3.0 only.
 */
int UnicodeToModifiedUTF7(LPCWSTR wszIn, int cchIn, LPSTR pchOut, int cchOut);
typedef int (*LPFNMODIFIEDUTF7TOUNICODE)(LPCSTR, int, LPWSTR, int);
typedef BOOL (*LPFNTNEFBUILDINFO)(const TNEFINFO *, LPWSTR, MailNonIpmInfo *, MailAttArray *);
typedef BOOL (*LPFNTNEFCHARSETTOCODEPAGE)(LPWSTR, UINT *);
typedef BOOL (*LPFNTNEFCODEPAGETOCHARSET)(UINT, LPWSTR, UINT);
typedef int (*LPFNTNEFCONVERTFROMUNICODE)(UINT, DWORD, LPCWSTR, int, LPSTR, int);
typedef int (*LPFNTNEFCONVERTTOUNICODE)(UINT, DWORD, LPCSTR, int, LPWSTR, int);
typedef int (*LPFNTNEFCONVERTTOUNICODEEX)(UINT, DWORD, LPCSTR, int, LPWSTR, int, UINT *);
typedef BOOL (*LPFNTNEFDECODEBUFFER)(INETENCODE, LPSTR, BYTE *, UINT *);
typedef BOOL (*LPFNTNEFDECODEFILE)(INETENCODE, LPWSTR, LPWSTR);
typedef BOOL (*LPFNTNEFDETECTTEXTCODEPAGE)(LPWSTR, UINT *, BOOL *);
typedef BOOL (*LPFNTNEFENCODEBUFFER)(INETENCODE, UINT, BYTE *, UINT *, LPSTR);
typedef LPWSTR (*LPFNTNEFENCODEFILE)(LPWSTR, INETENCODE);
typedef void (*LPFNTNEFFREECODEPAGEENUM)(HANDLE);
typedef BOOL (*LPFNTNEFGETFIRSTCODEPAGE)(HANDLE *, UINT *, LPWSTR, UINT);
typedef BOOL (*LPFNTNEFGETINFO)(const TNEFINFO *, MailNonIpmInfo **, MailAttArray **);
typedef BOOL (*LPFNTNEFGETNEXTCODEPAGE)(HANDLE, UINT *, LPWSTR, UINT);
typedef int (*LPFNUNICODETOMODIFIEDUTF7)(LPCWSTR, int, LPSTR, int);
struct _tnefinfo {
    INETENCODE wContentEncoding;
    BOOL fAttHdrs;
    HANDLE hHeap;
    LPWSTR szTnefCorrelator;
    WCHAR szTnefFileName[260];
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

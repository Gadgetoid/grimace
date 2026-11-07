#ifndef GRIMACE_SDK_MSACM_H
#define GRIMACE_SDK_MSACM_H


#ifdef __cplusplus
extern "C" {
#endif

struct tACMFILTERCHOOSE;
typedef struct tACMFILTERCHOOSE *LPACMFILTERCHOOSE;
/**
 * Displays an ACM dialog for selecting a waveform-audio filter.
 *
 * Initialize `cbStruct`. `pwfltr` must point to the output filter buffer,
 * and `cbwfltr` must give its size in bytes. On success, the structure
 * contains the selected filter. OEM dialog support may vary.
 *
 * @param pafltrc Filter-choice settings and output selection.
 * @return MMSYSERR_NOERROR, ACMERR_CANCELED, ACMERR_NOTPOSSIBLE or an
 *        MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFilterChoose(LPACMFILTERCHOOSE pafltrc);
struct tACMFILTERDETAILS;
typedef struct tACMFILTERDETAILS *LPACMFILTERDETAILS;
/**
 * Retrieves details for a waveform-audio filter.
 *
 * Initialize `cbStruct`, `pwfltr` and `cbwfltr`. Use
 * ACM_FILTERDETAILSF_FILTER to describe a filter structure, or
 * ACM_FILTERDETAILSF_INDEX to retrieve a driver's filter by index. The
 * index query requires a driver handle; a NULL `had` selects the first
 * suitable driver for the filter query.
 *
 * @param had ACM driver to query, or NULL to search suitable drivers.
 * @param pafd Filter query and output details.
 * @param fdwDetails ACM_FILTERDETAILSF_FILTER or ACM_FILTERDETAILSF_INDEX.
 * @return MMSYSERR_NOERROR, ACMERR_NOTPOSSIBLE or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFilterDetails(HACMDRIVER had, LPACMFILTERDETAILS pafd, DWORD fdwDetails);
typedef BOOL (*ACMFILTERENUMCB)(HACMDRIVERID, LPACMFILTERDETAILS, DWORD, DWORD);
/**
 * Enumerates waveform-audio filters, optionally restricted to a filter tag.
 *
 * Initialize `pafd->cbStruct`, `pwfltr` and `cbwfltr`; set
 * `dwFilterTag` to WAVE_FILTER_UNKNOWN or a specific tag. Set
 * ACM_FILTERENUMF_DWFILTERTAG to enumerate only that tag. Enumeration
 * stops when the callback returns FALSE. With no suitable driver, the
 * function succeeds without calling the callback.
 *
 * @param had ACM driver to query, or NULL to search suitable drivers.
 * @param pafd Filter details used for the query and callback.
 * @param fnCallback Called for each matching filter.
 * @param dwInstance Value passed to each callback invocation.
 * @param fdwEnum ACM_FILTERENUMF_DWFILTERTAG, or zero for all filters.
 * @return MMSYSERR_NOERROR, ACMERR_NOTPOSSIBLE or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFilterEnum(HACMDRIVER had, LPACMFILTERDETAILS pafd, ACMFILTERENUMCB fnCallback, DWORD dwInstance, DWORD fdwEnum);
struct tACMFILTERTAGDETAILS;
typedef struct tACMFILTERTAGDETAILS *LPACMFILTERTAGDETAILS;
/**
 * Retrieves details for a waveform-audio filter tag.
 *
 * Initialize `paftd->cbStruct`. Use ACM_FILTERTAGDETAILSF_FILTERTAG to
 * query a specified tag, ACM_FILTERTAGDETAILSF_INDEX to query a tag by
 * driver index, or ACM_FILTERTAGDETAILSF_LARGESTSIZE to find the tag with
 * the largest filter size. The index query requires a driver handle; a
 * NULL `had` searches suitable drivers for the other query types.
 *
 * @param had ACM driver to query, or NULL to search suitable drivers.
 * @param paftd Filter-tag query and output details.
 * @param fdwDetails ACM_FILTERTAGDETAILSF_* query type.
 * @return MMSYSERR_NOERROR, ACMERR_NOTPOSSIBLE or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFilterTagDetails(HACMDRIVER had, LPACMFILTERTAGDETAILS paftd, DWORD fdwDetails);
typedef BOOL (*ACMFILTERTAGENUMCB)(HACMDRIVERID, LPACMFILTERTAGDETAILS, DWORD, DWORD);
/**
 * Enumerates waveform-audio filter tags supported by an ACM driver.
 *
 * Initialize `paftd->cbStruct` and set `fdwEnum` to zero. Enumeration
 * stops when the callback returns FALSE. With no suitable driver, the
 * function succeeds without calling the callback.
 *
 * @param had ACM driver to query, or NULL to search suitable drivers.
 * @param paftd Filter-tag details passed to the callback.
 * @param fnCallback Called for each filter tag.
 * @param dwInstance Value passed to each callback invocation.
 * @param fdwEnum Reserved; set to zero.
 * @return MMSYSERR_NOERROR or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFilterTagEnum(HACMDRIVER had, LPACMFILTERTAGDETAILS paftd, ACMFILTERTAGENUMCB fnCallback, DWORD dwInstance, DWORD fdwEnum);
struct tACMFORMATCHOOSE;
typedef struct tACMFORMATCHOOSE *LPACMFORMATCHOOSE;
/**
 * Displays an ACM dialog for selecting a waveform-audio format.
 *
 * Initialize `cbStruct`. `pwfx` must point to the output format buffer,
 * and `cbwfx` must give its size in bytes. On success, the structure
 * contains the selected format. OEM dialog support may vary.
 *
 * @param pafmtc Format-choice settings and output selection.
 * @return MMSYSERR_NOERROR, ACMERR_CANCELED, ACMERR_NOTPOSSIBLE or an
 *        MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT acmFormatChoose(LPACMFORMATCHOOSE pafmtc);
typedef LRESULT (*ACMDRIVERPROC)(DWORD, HACMDRIVERID, UINT, LPARAM, LPARAM);
typedef struct tACMFILTERCHOOSE ACMFILTERCHOOSE;
typedef UINT (*ACMFILTERCHOOSEHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
typedef struct tACMFILTERDETAILS ACMFILTERDETAILS;
typedef struct tACMFILTERTAGDETAILS ACMFILTERTAGDETAILS;
typedef struct tACMFORMATCHOOSE ACMFORMATCHOOSE;
typedef UINT (*ACMFORMATCHOOSEHOOKPROC)(HWND, UINT, WPARAM, LPARAM);
typedef ACMDRIVERPROC *LPACMDRIVERPROC;
struct tACMDRIVERDETAILS;
typedef struct tACMDRIVERDETAILS *PACMDRIVERDETAILS;
typedef struct tACMFILTERCHOOSE *PACMFILTERCHOOSE;
typedef struct tACMFILTERDETAILS *PACMFILTERDETAILS;
typedef struct tACMFILTERTAGDETAILS *PACMFILTERTAGDETAILS;
typedef struct tACMFORMATCHOOSE *PACMFORMATCHOOSE;
struct tACMFORMATDETAILS;
typedef struct tACMFORMATDETAILS *PACMFORMATDETAILS;
struct tACMFORMATTAGDETAILSW;
typedef struct tACMFORMATTAGDETAILSW *PACMFORMATTAGDETAILS;
struct tACMSTREAMHEADER;
typedef struct tACMSTREAMHEADER *PACMSTREAMHEADER;
struct tACMDRIVERDETAILS {
    DWORD cbStruct;
    FOURCC fccType;
    FOURCC fccComp;
    WORD wMid;
    WORD wPid;
    DWORD vdwACM;
    DWORD vdwDriver;
    DWORD fdwSupport;
    DWORD cFormatTags;
    DWORD cFilterTags;
    HICON hicon;
    WCHAR szShortName[32];
    WCHAR szLongName[128];
    WCHAR szCopyright[80];
    WCHAR szLicensing[128];
    WCHAR szFeatures[512];
} __attribute__((packed, aligned(1)));

struct tACMFILTERCHOOSE {
    DWORD cbStruct;
    DWORD fdwStyle;
    HWND hwndOwner;
    LPWAVEFILTER pwfltr;
    DWORD cbwfltr;
    LPCWSTR pszTitle;
    WCHAR szFilterTag[48];
    WCHAR szFilter[128];
    LPWSTR pszName;
    DWORD cchName;
    DWORD fdwEnum;
    LPWAVEFILTER pwfltrEnum;
    HINSTANCE hInstance;
    LPCWSTR pszTemplateName;
    LPARAM lCustData;
    ACMFILTERCHOOSEHOOKPROC pfnHook;
} __attribute__((packed, aligned(1)));

struct tACMFILTERDETAILS {
    DWORD cbStruct;
    DWORD dwFilterIndex;
    DWORD dwFilterTag;
    DWORD fdwSupport;
    LPWAVEFILTER pwfltr;
    DWORD cbwfltr;
    WCHAR szFilter[128];
} __attribute__((packed, aligned(1)));

struct tACMFILTERTAGDETAILS {
    DWORD cbStruct;
    DWORD dwFilterTagIndex;
    DWORD dwFilterTag;
    DWORD cbFilterSize;
    DWORD fdwSupport;
    DWORD cStandardFilters;
    WCHAR szFilterTag[48];
} __attribute__((packed, aligned(1)));

struct tACMFORMATCHOOSE {
    DWORD cbStruct;
    DWORD fdwStyle;
    HWND hwndOwner;
    LPWAVEFORMATEX pwfx;
    DWORD cbwfx;
    LPCWSTR pszTitle;
    WCHAR szFormatTag[48];
    WCHAR szFormat[128];
    LPWSTR pszName;
    DWORD cchName;
    DWORD fdwEnum;
    LPWAVEFORMATEX pwfxEnum;
    HINSTANCE hInstance;
    LPCWSTR pszTemplateName;
    LPARAM lCustData;
    ACMFORMATCHOOSEHOOKPROC pfnHook;
} __attribute__((packed, aligned(1)));

struct tACMFORMATDETAILS {
    DWORD cbStruct;
    DWORD dwFormatIndex;
    DWORD dwFormatTag;
    DWORD fdwSupport;
    LPWAVEFORMATEX pwfx;
    DWORD cbwfx;
    WCHAR szFormat[128];
} __attribute__((packed, aligned(1)));

struct tACMFORMATTAGDETAILSW {
    DWORD cbStruct;
    DWORD dwFormatTagIndex;
    DWORD dwFormatTag;
    DWORD cbFormatSize;
    DWORD fdwSupport;
    DWORD cStandardFormats;
    WCHAR szFormatTag[48];
} __attribute__((packed, aligned(1)));

struct tACMSTREAMHEADER {
    DWORD cbStruct;
    DWORD fdwStatus;
    DWORD dwUser;
    LPBYTE pbSrc;
    DWORD cbSrcLength;
    DWORD cbSrcLengthUsed;
    DWORD dwSrcUser;
    LPBYTE pbDst;
    DWORD cbDstLength;
    DWORD cbDstLengthUsed;
    DWORD dwDstUser;
    DWORD dwReservedDriver[10];
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

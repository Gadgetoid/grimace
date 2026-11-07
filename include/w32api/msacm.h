/*author: Adrian Sandor
  written for MinGW*/
#ifndef _MSACM_H
#define _MSACM_H

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

DECLARE_HANDLE(HACMDRIVERID);
typedef HACMDRIVERID *PHACMDRIVERID;
typedef HACMDRIVERID *LPHACMDRIVERID;
DECLARE_HANDLE(HACMDRIVER);
typedef HACMDRIVER *PHACMDRIVER;
typedef HACMDRIVER *LPHACMDRIVER;
DECLARE_HANDLE(HACMSTREAM);
typedef HACMSTREAM *PHACMSTREAM;
typedef HACMSTREAM *LPHACMSTREAM;
DECLARE_HANDLE(HACMOBJ);
typedef HACMOBJ *PHACMOBJ;
typedef HACMOBJ *LPHACMOBJ;

/*found through experimentation*/
#define ACMDRIVERDETAILS_SHORTNAME_CHARS 32
#define ACMDRIVERDETAILS_LONGNAME_CHARS 128
#define ACMDRIVERDETAILS_COPYRIGHT_CHARS 80
#define ACMDRIVERDETAILS_LICENSING_CHARS 128

/*I don't know the right values for these macros*/
#ifdef _WIN32_WCE
#define ACMFORMATDETAILS_FORMAT_CHARS 128
#else
#define ACMFORMATDETAILS_FORMAT_CHARS 256
#endif
#ifdef _WIN32_WCE
#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 48
#else
#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 256
#endif
#ifdef _WIN32_WCE
#define ACMDRIVERDETAILS_FEATURES_CHARS 512
#else
#define ACMDRIVERDETAILS_FEATURES_CHARS 256
#endif

/* via googling */
#define ACM_FORMATSUGGESTF_WFORMATTAG 0x00010000
#define ACM_STREAMOPENF_NONREALTIME 4
#define ACM_STREAMSIZEF_DESTINATION 1

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformatdetails_str.asp*/
typedef struct {
	DWORD          cbStruct;
	DWORD          dwFormatIndex;
	DWORD          dwFormatTag;
	DWORD          fdwSupport;
	LPWAVEFORMATEX pwfx;
	DWORD          cbwfx;
	char szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSA, *LPACMFORMATDETAILSA;
typedef struct {
	DWORD          cbStruct;
	DWORD          dwFormatIndex;
	DWORD          dwFormatTag;
	DWORD          fdwSupport;
	LPWAVEFORMATEX pwfx;
	DWORD          cbwfx;
	WCHAR szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSW, *LPACMFORMATDETAILSW;

/*msdn.microsoft.com/en-us/library/dd742926%28VS.85%29.aspx*/
typedef struct {
  DWORD     cbStruct;
  DWORD     fdwStatus;
  DWORD_PTR dwUser;
  LPBYTE    pbSrc;
  DWORD     cbSrcLength;
  DWORD     cbSrcLengthUsed;
  DWORD_PTR dwSrcUser;
  LPBYTE    pbDst;
  DWORD     cbDstLength;
  DWORD     cbDstLengthUsed;
  DWORD_PTR dwDstUser;
  DWORD     dwReservedDriver[10];
} ACMSTREAMHEADER, *LPACMSTREAMHEADER;

/*msdn.microsoft.com/en-us/library/dd757711%28v=VS.85%29.aspx*/
typedef struct {
  DWORD cbStruct;
  DWORD dwFilterTag;
  DWORD fdwFilter;
  DWORD dwReserved[5];
} WAVEFILTER, *LPWAVEFILTER;

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformattagdetails_str.asp*/
typedef struct {
	DWORD cbStruct;
	DWORD dwFormatTagIndex;
	DWORD dwFormatTag;
	DWORD cbFormatSize;
	DWORD fdwSupport;
	DWORD cStandardFormats;
	char szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSA, *LPACMFORMATTAGDETAILSA;
typedef struct {
	DWORD cbStruct;
	DWORD dwFormatTagIndex;
	DWORD dwFormatTag;
	DWORD cbFormatSize;
	DWORD fdwSupport;
	DWORD cStandardFormats;
	WCHAR szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSW, *LPACMFORMATTAGDETAILSW;

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriverdetails_str.asp*/
typedef struct {
	DWORD  cbStruct;
	FOURCC fccType;
	FOURCC fccComp;
	WORD   wMid;
	WORD   wPid;
	DWORD  vdwACM;
	DWORD  vdwDriver;
	DWORD  fdwSupport;
	DWORD  cFormatTags;
	DWORD  cFilterTags;
	HICON  hicon;
	char  szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
	char  szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
	char  szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
	char  szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
	char  szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSA, *LPACMDRIVERDETAILSA;
typedef struct {
	DWORD  cbStruct;
	FOURCC fccType;
	FOURCC fccComp;
	WORD   wMid;
	WORD   wPid;
	DWORD  vdwACM;
	DWORD  vdwDriver;
	DWORD  fdwSupport;
	DWORD  cFormatTags;
	DWORD  cFilterTags;
	HICON  hicon;
	WCHAR  szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
	WCHAR  szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
	WCHAR  szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
	WCHAR  szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
	WCHAR  szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSW, *LPACMDRIVERDETAILSW;

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformatenumcallback.asp*/
typedef BOOL (CALLBACK *ACMFORMATENUMCBA) (
	HACMDRIVERID        hadid,
	LPACMFORMATDETAILSA pafd,
	DWORD_PTR           dwInstance,
	DWORD               fdwSupport
);
typedef BOOL (CALLBACK *ACMFORMATENUMCBW) (
	HACMDRIVERID        hadid,
	LPACMFORMATDETAILSW pafd,
	DWORD_PTR           dwInstance,
	DWORD               fdwSupport
);

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformattagenumcallback.asp*/
typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBA) (
	HACMDRIVERID           hadid,
	LPACMFORMATTAGDETAILSA paftd,
	DWORD_PTR              dwInstance,
	DWORD                  fdwSupport
);
typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBW) (
	HACMDRIVERID           hadid,
	LPACMFORMATTAGDETAILSW paftd,
	DWORD_PTR              dwInstance,
	DWORD                  fdwSupport
);

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriverenumcallback.asp*/
typedef BOOL (CALLBACK *ACMDRIVERENUMCB) (
	HACMDRIVERID hadid,
	DWORD_PTR    dwInstance,
	DWORD        fdwSupport
);

/*and now the functions...*/

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriveropen.asp*/
/**
 * Opens an ACM driver, giving an instance to pass to other ACM calls.
 *
 * Close with acmDriverClose.
 *
 * @param phad Receives the driver instance.
 * @param hadid The driver identifier.
 * @param fdwOpen Reserved. Must be 0.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_NOTENABLED or
 *         MMSYSERR_NOMEM.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverOpen(LPHACMDRIVER phad, HACMDRIVERID hadid, DWORD fdwOpen);
/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriverenum.asp*/
/**
 * Enumerates the available ACM drivers.
 *
 * Enumeration continues until there are no more drivers or the callback
 * returns FALSE.
 *
 * @param fnCallback Called once per driver.
 * @param dwInstance Passed through to the callback.
 * @param fdwEnum 0, or ACM_DRIVERENUMF_DISABLED to include disabled
 *        drivers and ACM_DRIVERENUMF_NOLOCAL to leave out local ones.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALPARAM.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverEnum(ACMDRIVERENUMCB fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformatenum.asp*/
MMRESULT WINAPI acmFormatEnumA(HACMDRIVER had, LPACMFORMATDETAILSA pafd, ACMFORMATENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
/**
 * Enumerates the wave formats a driver or the ACM supports.
 *
 * Calls fnCallback once per format. The callback returns TRUE to continue
 * or FALSE to stop.
 *
 * @param had Driver to query, or NULL to query all drivers.
 * @param pafd ACMFORMATDETAILS with cbStruct, dwFormatTag, pwfx and cbwfx
 *        set. pwfx must be large enough for any format (see acmMetrics
 *        with ACM_METRIC_MAX_SIZE_FORMAT).
 * @param fnCallback Function called for each format found.
 * @param dwInstance Value passed through to the callback.
 * @param fdwEnum ACM_FORMATENUMF_* flags restricting the formats returned
 *        (WFORMATTAG, NCHANNELS, NSAMPLESPERSEC, WBITSPERSAMPLE, CONVERT,
 *        SUGGEST, INPUT, OUTPUT and so on), or 0 for all.
 * @return MMSYSERR_NOERROR (0), or an MMSYSERR_* or ACMERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmFormatEnumW(HACMDRIVER had, LPACMFORMATDETAILSW pafd, ACMFORMATENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
/*http://msdn.microsoft.com/en-us/library/dd742916(VS.85).aspx*/
/**
 * Suggests a destination format that a source format can be converted to.
 *
 * @param had Driver to ask, or NULL to let the ACM search all drivers.
 * @param pwfxSrc The source format.
 * @param pwfxDst Receives the suggested format. Fields named by fdwSuggest
 *        must be filled in on input.
 * @param cbwfxDst Size of the pwfxDst buffer, in bytes.
 * @param fdwSuggest ACM_FORMATSUGGESTF_* flags (WFORMATTAG, NCHANNELS,
 *        NSAMPLESPERSEC, WBITSPERSAMPLE) fixing those fields of pwfxDst,
 *        or 0.
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_NOTPOSSIBLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmFormatSuggest(HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, DWORD cbwfxDst, DWORD fdwSuggest);

/*msdn.microsoft.com/en-us/library/dd742885%28VS.85%29.aspx*/
MMRESULT WINAPI acmDriverAddA(LPHACMDRIVERID phadid, HINSTANCE hinstModule, LPARAM lParam, DWORD dwPriority, DWORD fdwAdd);
/**
 * Adds an ACM driver to the list of available drivers.
 *
 * The driver is local to the calling process. Remove it with
 * acmDriverRemove.
 *
 * @param phadid Receives the driver identifier.
 * @param hinstModule Module containing the driver.
 * @param lParam With ACM_DRIVERADDF_FUNCTION, the driver's entry point.
 *        With ACM_DRIVERADDF_NOTIFYHWND, the window to notify of driver
 *        changes.
 * @param dwPriority With ACM_DRIVERADDF_NOTIFYHWND, the message to send.
 *        Otherwise 0.
 * @param fdwAdd ACM_DRIVERADDF_FUNCTION or ACM_DRIVERADDF_NOTIFYHWND,
 *        optionally with ACM_DRIVERADDF_GLOBAL.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALPARAM or
 *         MMSYSERR_NOMEM.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverAddW(LPHACMDRIVERID phadid, HINSTANCE hinstModule, LPARAM lParam, DWORD dwPriority, DWORD fdwAdd);

/*msdn.microsoft.com/en-us/library/dd742897%28v=VS.85%29.aspx*/
/**
 * Removes a driver added with acmDriverAddW.
 *
 * @param hadid The driver identifier.
 * @param fdwRemove Reserved. Must be 0.
 * @return MMSYSERR_NOERROR, or an error such as ACMERR_BUSY or
 *         MMSYSERR_INVALHANDLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverRemove(HACMDRIVERID hadid, DWORD fdwRemove);

/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriverclose.asp*/
/**
 * Closes an ACM driver instance opened with acmDriverOpen.
 *
 * @param had The driver instance.
 * @param fdwClose Reserved. Must be 0.
 * @return MMSYSERR_NOERROR, or an error such as ACMERR_BUSY or
 *         MMSYSERR_INVALHANDLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverClose(HACMDRIVER had, DWORD fdwClose);
/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmdriverdetails.asp*/
MMRESULT WINAPI acmDriverDetailsA(HACMDRIVERID hadid, LPACMDRIVERDETAILSA padd, DWORD fdwDetails);
/**
 * Gets details of an ACM driver, such as its name and capabilities.
 *
 * @param hadid The driver identifier.
 * @param padd Receives the details. Set cbStruct before calling.
 * @param fdwDetails Reserved. Must be 0.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALHANDLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmDriverDetailsW(HACMDRIVERID hadid, LPACMDRIVERDETAILSW padd, DWORD fdwDetails);
/*msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_acmformattagenum.asp*/
MMRESULT WINAPI acmFormatTagEnumA(HACMDRIVER had, LPACMFORMATTAGDETAILSA paftd, ACMFORMATTAGENUMCBA fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);
/**
 * Enumerates the wave format tags (such as WAVE_FORMAT_PCM) a driver or
 * the ACM supports.
 *
 * Calls fnCallback once per tag. The callback returns TRUE to continue or
 * FALSE to stop.
 *
 * @param had Driver to query, or NULL to query all drivers.
 * @param paftd ACMFORMATTAGDETAILS with cbStruct set. Passed to the
 *        callback with each tag's details.
 * @param fnCallback Function called for each format tag.
 * @param dwInstance Value passed through to the callback.
 * @param fdwEnum Must be 0.
 * @return MMSYSERR_NOERROR (0), or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmFormatTagEnumW(HACMDRIVER had, LPACMFORMATTAGDETAILSW paftd, ACMFORMATTAGENUMCBW fnCallback, DWORD_PTR dwInstance, DWORD fdwEnum);

/*msdn.microsoft.com/en-us/library/dd742922(VS.85).aspx*/
/**
 * Returns a metric of the ACM or of a driver, stream or driver ID.
 *
 * @param hao Object to query, or NULL for the ACM as a whole.
 * @param uMetric ACM_METRIC_* value, such as ACM_METRIC_COUNT_DRIVERS or
 *        ACM_METRIC_MAX_SIZE_FORMAT.
 * @param pMetric Receives the value. Its type depends on uMetric, usually
 *        a DWORD.
 * @return MMSYSERR_NOERROR (0), or an error such as
 *         MMSYSERR_NOTSUPPORTED.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmMetrics(HACMOBJ hao, UINT uMetric, LPVOID pMetric);

/*msdn.microsoft.com/en-us/library/dd742928%28VS.85%29.aspx*/
/**
 * Opens a conversion stream between two wave formats.
 *
 * With ACM_STREAMOPENF_QUERY, only checks whether the conversion is
 * possible. Close with acmStreamClose.
 *
 * @param phas Receives the stream handle. May be NULL with
 *        ACM_STREAMOPENF_QUERY.
 * @param had Driver to use, or NULL to let the ACM pick one.
 * @param pwfxSrc The source format.
 * @param pwfxDst The destination format.
 * @param pwfltr Filter to apply, or NULL for a format conversion.
 * @param dwCallback Window, function or event to notify, per the
 *        CALLBACK_* flag in fdwOpen, or 0.
 * @param dwInstance Value passed to a callback function.
 * @param fdwOpen ACM_STREAMOPENF_QUERY, ACM_STREAMOPENF_NONREALTIME,
 *        ACM_STREAMOPENF_ASYNC and CALLBACK_WINDOW, CALLBACK_FUNCTION or
 *        CALLBACK_EVENT, or 0.
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_NOTPOSSIBLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamOpen(LPHACMSTREAM phas, HACMDRIVER had, LPWAVEFORMATEX pwfxSrc, LPWAVEFORMATEX pwfxDst, LPWAVEFILTER pwfltr, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen);

/*msdn.microsoft.com/en-us/library/dd742931%28VS.85%29.aspx*/
/**
 * Estimates the buffer size needed on one side of a stream for a given
 * size on the other.
 *
 * @param has The stream.
 * @param cbInput Size in bytes of the source or destination buffer.
 * @param pdwOutputBytes Receives the size in bytes needed on the other
 *        side.
 * @param fdwSize ACM_STREAMSIZEF_SOURCE (cbInput is the source size) or
 *        ACM_STREAMSIZEF_DESTINATION (cbInput is the destination size).
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_NOTPOSSIBLE.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamSize(HACMSTREAM has, DWORD cbInput, LPDWORD pdwOutputBytes, DWORD fdwSize);

/*msdn.microsoft.com/en-us/library/dd742929%28VS.85%29.aspx*/
/**
 * Prepares a stream header for use with acmStreamConvert.
 *
 * Undo with acmStreamUnprepareHeader before freeing the buffers.
 *
 * @param has The stream.
 * @param pash ACMSTREAMHEADER with cbStruct, pbSrc, cbSrcLength, pbDst and
 *        cbDstLength set.
 * @param fdwPrepare Must be 0.
 * @return MMSYSERR_NOERROR (0), or an error such as MMSYSERR_NOMEM.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamPrepareHeader(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwPrepare);

/*msdn.microsoft.com/en-us/library/dd742932%28VS.85%29.aspx*/
/**
 * Releases the preparation of a stream header made by
 * acmStreamPrepareHeader.
 *
 * Call before freeing the header's buffers and before acmStreamClose.
 *
 * @param has The stream.
 * @param pash The prepared header.
 * @param fdwUnprepare Must be 0.
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_BUSY.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamUnprepareHeader(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwUnprepare);

/*msdn.microsoft.com/en-us/library/dd742930%28VS.85%29.aspx*/
/**
 * Stops conversions on a stream and marks pending buffers as done.
 *
 * Only meaningful for asynchronous streams.
 *
 * @param has The stream.
 * @param fdwReset Must be 0.
 * @return MMSYSERR_NOERROR (0), or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamReset(HACMSTREAM has, DWORD fdwReset);

/*msdn.microsoft.com/en-us/library/dd742923%28VS.85%29.aspx*/
/**
 * Closes a conversion stream opened with acmStreamOpen.
 *
 * Unprepare all headers with acmStreamUnprepareHeader first.
 *
 * @param has The stream.
 * @param fdwClose Must be 0.
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_BUSY.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamClose(HACMSTREAM has, DWORD fdwClose);

/*msdn.microsoft.com/en-us/library/dd742924%28VS.85%29.aspx*/
/**
 * Converts the data in a prepared stream header.
 *
 * Synchronous unless the stream was opened with a callback, in which case
 * completion is signalled through it and ACMSTREAMHEADER_STATUSF_DONE.
 * Check cbSrcLengthUsed and cbDstLengthUsed for the amounts processed.
 *
 * @param has The stream.
 * @param pash Header prepared with acmStreamPrepareHeader.
 * @param fdwConvert ACM_STREAMCONVERTF_BLOCKALIGN, ACM_STREAMCONVERTF_START
 *        (first buffer after open or reset), ACM_STREAMCONVERTF_END (last
 *        buffer, flushes remaining data), or 0.
 * @return MMSYSERR_NOERROR (0), or an error such as ACMERR_UNPREPARED.
 *
 * @note Windows CE 2.0 and later.
 */
MMRESULT WINAPI acmStreamConvert(HACMSTREAM has, LPACMSTREAMHEADER pash, DWORD fdwConvert);

#ifdef UNICODE

typedef ACMFORMATDETAILSW ACMFORMATDETAILS, *LPACMFORMATDETAILS;
typedef ACMFORMATTAGDETAILSW ACMFORMATTAGDETAILS, *LPACMFORMATTAGDETAILS;
typedef ACMDRIVERDETAILSW ACMDRIVERDETAILS, *LPACMDRIVERDETAILS;
typedef ACMFORMATENUMCBW ACMFORMATENUMCB;
typedef ACMFORMATTAGENUMCBW ACMFORMATTAGENUMCB;
/**
 * Enumerates the wave formats a driver or the ACM supports.
 *
 * Calls fnCallback once per format. The callback returns TRUE to continue
 * or FALSE to stop.
 *
 * @param had Driver to query, or NULL to query all drivers.
 * @param pafd ACMFORMATDETAILS with cbStruct, dwFormatTag, pwfx and cbwfx
 *        set. pwfx must be large enough for any format (see acmMetrics
 *        with ACM_METRIC_MAX_SIZE_FORMAT).
 * @param fnCallback Function called for each format found.
 * @param dwInstance Value passed through to the callback.
 * @param fdwEnum ACM_FORMATENUMF_* flags restricting the formats returned
 *        (WFORMATTAG, NCHANNELS, NSAMPLESPERSEC, WBITSPERSAMPLE, CONVERT,
 *        SUGGEST, INPUT, OUTPUT and so on), or 0 for all.
 * @return MMSYSERR_NOERROR (0), or an MMSYSERR_* or ACMERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
#define acmFormatEnum acmFormatEnumW
/**
 * Gets details of an ACM driver, such as its name and capabilities.
 *
 * @param hadid The driver identifier.
 * @param padd Receives the details. Set cbStruct before calling.
 * @param fdwDetails Reserved. Must be 0.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALHANDLE.
 *
 * @note Windows CE 2.0 and later.
 */
#define acmDriverDetails acmDriverDetailsW
/**
 * Enumerates the wave format tags (such as WAVE_FORMAT_PCM) a driver or
 * the ACM supports.
 *
 * Calls fnCallback once per tag. The callback returns TRUE to continue or
 * FALSE to stop.
 *
 * @param had Driver to query, or NULL to query all drivers.
 * @param paftd ACMFORMATTAGDETAILS with cbStruct set. Passed to the
 *        callback with each tag's details.
 * @param fnCallback Function called for each format tag.
 * @param dwInstance Value passed through to the callback.
 * @param fdwEnum Must be 0.
 * @return MMSYSERR_NOERROR (0), or an MMSYSERR_* error.
 *
 * @note Windows CE 2.0 and later.
 */
#define acmFormatTagEnum acmFormatTagEnumW
/**
 * Adds an ACM driver to the list of available drivers.
 *
 * The driver is local to the calling process. Remove it with
 * acmDriverRemove.
 *
 * @param phadid Receives the driver identifier.
 * @param hinstModule Module containing the driver.
 * @param lParam With ACM_DRIVERADDF_FUNCTION, the driver's entry point.
 *        With ACM_DRIVERADDF_NOTIFYHWND, the window to notify of driver
 *        changes.
 * @param dwPriority With ACM_DRIVERADDF_NOTIFYHWND, the message to send.
 *        Otherwise 0.
 * @param fdwAdd ACM_DRIVERADDF_FUNCTION or ACM_DRIVERADDF_NOTIFYHWND,
 *        optionally with ACM_DRIVERADDF_GLOBAL.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALPARAM or
 *         MMSYSERR_NOMEM.
 *
 * @note Windows CE 2.0 and later.
 */
#define acmDriverAdd acmDriverAddW

#else /*ifdef UNICODE*/

typedef ACMFORMATDETAILSA ACMFORMATDETAILS, *LPACMFORMATDETAILS;
typedef ACMFORMATTAGDETAILSA ACMFORMATTAGDETAILS, *LPACMFORMATTAGDETAILS;
typedef ACMDRIVERDETAILSA ACMDRIVERDETAILS, *LPACMDRIVERDETAILS;
typedef ACMFORMATENUMCBA ACMFORMATENUMCB;
typedef ACMFORMATTAGENUMCBA ACMFORMATTAGENUMCB;
#define acmFormatEnum acmFormatEnumA
#define acmDriverDetails acmDriverDetailsA
#define acmFormatTagEnum acmFormatTagEnumA
#define acmDriverAdd acmDriverAddA

#endif /*ifdef UNICODE*/

#ifdef __cplusplus
}
#endif

#endif

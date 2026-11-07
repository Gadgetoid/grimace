#ifndef GRIMACE_EXTRAS_MSACM_H
#define GRIMACE_EXTRAS_MSACM_H

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns the version of the Audio Compression Manager.
 *
 * @return The version as 0xAABBCCCC: major in the high byte, minor in the
 *         next, build in the low word.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI acmGetVersion(void);
/**
 * Returns the driver identifier for an open ACM driver, stream or other ACM
 * object.
 *
 * @param hao The ACM object, such as an HACMDRIVER or HACMSTREAM.
 * @param phadid Receives the driver identifier.
 * @param fdwDriverID Reserved; must be zero.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALHANDLE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
MMRESULT WINAPI acmDriverID(HACMOBJ hao, LPHACMDRIVERID phadid, DWORD fdwDriverID);
/**
 * Sets the priority of an ACM driver, and enables or disables it.
 *
 * @param hadid The driver identifier.
 * @param dwPriority New priority, 1 being highest, or 0 to keep the current
 *        one.
 * @param fdwPriority ACM_DRIVERPRIORITYF_ENABLE or ACM_DRIVERPRIORITYF_DISABLE,
 *        or ACM_DRIVERPRIORITYF_BEGIN and ACM_DRIVERPRIORITYF_END to defer
 *        change notifications over several calls.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALHANDLE or
 *         MMSYSERR_INVALFLAG.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
MMRESULT WINAPI acmDriverPriority(HACMDRIVERID hadid, DWORD dwPriority, DWORD fdwPriority);
/**
 * Sends a driver-defined or configuration message to an ACM driver.
 *
 * @param had The open driver, from acmDriverOpen.
 * @param uMsg ACMDM_USER or above, DRV_QUERYCONFIGURE or DRV_CONFIGURE.
 * @param lParam1 Message-specific.
 * @param lParam2 Message-specific.
 * @return Message-specific result from the driver.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LRESULT WINAPI acmDriverMessage(HACMDRIVER had, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
/**
 * Sends a driver-defined message to an ACM conversion stream.
 *
 * @param has The stream, from acmStreamOpen.
 * @param uMsg ACMDM_USER or above.
 * @param lParam1 Message-specific.
 * @param lParam2 Message-specific.
 * @return MMSYSERR_NOERROR, or an error such as MMSYSERR_INVALHANDLE or
 *         MMSYSERR_NOTSUPPORTED.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
MMRESULT WINAPI acmStreamMessage(HACMSTREAM has, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
/**
 * Retrieves details of a waveform format for a format tag.
 *
 * Set pafd->cbStruct, dwFormatTag, pwfx and cbwfx before calling.
 *
 * @param had An open driver, or NULL to ask all drivers.
 * @param pafd ACMFORMATDETAILS structure to fill.
 * @param fdwDetails ACM_FORMATDETAILSF_INDEX to look up by
 *        pafd->dwFormatIndex, or ACM_FORMATDETAILSF_FORMAT to look up the
 *        format in pafd->pwfx.
 * @return MMSYSERR_NOERROR, or an error such as ACMERR_NOTPOSSIBLE or
 *         MMSYSERR_INVALPARAM.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
MMRESULT WINAPI acmFormatDetails(HACMDRIVER had, LPACMFORMATDETAILSW pafd, DWORD fdwDetails);
/**
 * Retrieves details of a waveform format tag.
 *
 * Set paftd->cbStruct before calling.
 *
 * @param had An open driver, or NULL to ask all drivers.
 * @param paftd ACMFORMATTAGDETAILS structure to fill.
 * @param fdwDetails ACM_FORMATTAGDETAILSF_INDEX (by dwFormatTagIndex),
 *        ACM_FORMATTAGDETAILSF_FORMATTAG (by dwFormatTag) or
 *        ACM_FORMATTAGDETAILSF_LARGESTSIZE (the tag with the largest
 *        format).
 * @return MMSYSERR_NOERROR, or an error such as ACMERR_NOTPOSSIBLE or
 *         MMSYSERR_INVALPARAM.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
MMRESULT WINAPI acmFormatTagDetails(HACMDRIVER had, LPACMFORMATTAGDETAILSW paftd, DWORD fdwDetails);

#ifdef __cplusplus
}
#endif

#endif

#endif

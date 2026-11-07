#ifndef GRIMACE_SDK_SIPAPI_H
#define GRIMACE_SDK_SIPAPI_H

#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct tagIMENUMINFO;
typedef struct tagIMENUMINFO IMENUMINFO;
typedef int (*IMENUMPROC)(IMENUMINFO *);
/**
 * Enumerates the available input methods.
 *
 * Pass NULL to retrieve the count without callbacks. Enumeration stops
 * when the callback returns zero. This call does not initialize the input
 * panel environment.
 *
 * @param pEnumIMProc Callback for each input method, or NULL to get the count.
 * @return Number of available input methods, or -1 on error.
 *
 * @note Windows CE 3.0 only.
 */
int SipEnumIM(IMENUMPROC pEnumIMProc);
/**
 * Retrieves the CLSID of the current input method.
 *
 * @param pClsid Receives the CLSID.
 * @return TRUE on success, FALSE on failure; use GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipGetCurrentIM(CLSID *pClsid);
struct tagSIPINFO;
typedef struct tagSIPINFO SIPINFO;
/**
 * Retrieves input-panel state, position, unobscured desktop area and IM data.
 *
 * Set dwImDataSize to 0 unless the current IM provides data you can use;
 * requesting unavailable IM data causes failure.
 *
 * @param pSipInfo Receives input-panel information.
 * @return TRUE on success, FALSE on failure; use GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipGetInfo(SIPINFO *pSipInfo);
/**
 * Registers a window to receive input-panel notifications.
 *
 * Only one application can register. The registration remains until a
 * warm or cold reboot. This call does not initialize the input-panel
 * environment.
 *
 * @param hWnd Window that receives notifications.
 * @return TRUE on success, FALSE on failure; use GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipRegisterNotification(HWND hWnd);
/**
 * Requests an input method by CLSID.
 *
 * If the requested IM cannot be loaded, the default IM is loaded instead.
 * Call SipGetCurrentIM afterward to verify which IM is active.
 *
 * @param pClsid CLSID of the requested input method.
 * @return TRUE on success; on failure, the reference specifies an HRESULT
 *         error code.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipSetCurrentIM(CLSID *pClsid);
/**
 * Sets the default size and position of the input panel.
 *
 * The new default takes effect after an application loads a new input
 * method. This call does not initialize the input-panel environment.
 *
 * @param pRect Default input-panel rectangle.
 * @return TRUE on success, FALSE on failure; use GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipSetDefaultRect(RECT *pRect);
/**
 * Sets the input-panel state, position and unobscured desktop area.
 *
 * Clear the SIPINFO structure before setting the fields to pass to this
 * function.
 *
 * @param pSipInfo Input-panel settings to apply.
 * @return TRUE on success, FALSE on failure; use GetLastError for details.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipSetInfo(SIPINFO *pSipInfo);
/**
 * Shows or hides the current input panel.
 *
 * Use SIPF_ON to show it and SIPF_OFF to hide it.
 *
 * @param dwFlag SIPF_ON or SIPF_OFF.
 * @return TRUE on success; on failure, the reference specifies an HRESULT
 *         error code.
 *
 * @note Windows CE 3.0 only.
 */
BOOL SipShowIM(DWORD dwFlag);
/**
 * Reports whether the input-panel environment is installed.
 *
 * This call does not initialize the input-panel environment.
 *
 * @return SIP_STATUS_AVAILABLE or SIP_STATUS_UNAVAILABLE.
 *
 * @note Windows CE 3.0 only.
 */
DWORD SipStatus(void);
struct tagIMWINDOWPOS;
typedef struct tagIMWINDOWPOS IMWINDOWPOS;
typedef struct tagIMENUMINFO *PIMENUMINFO;
struct tagIMENUMINFO {
    TCHAR szName[260];
    CLSID clsid;
};

struct tagIMWINDOWPOS {
    int x;
    int y;
    int cx;
    int cy;
};

struct tagSIPINFO {
    DWORD cbSize;
    DWORD fdwFlags;
    RECT rcVisibleDesktop;
    RECT rcSipRect;
    DWORD dwImDataSize;
    void *pvImData;
};


#ifdef __cplusplus
}
#endif

#endif

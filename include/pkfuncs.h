#ifndef GRIMACE_PKFUNCS_H
#define GRIMACE_PKFUNCS_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Passes an IOCTL to the OEM adaptation layer (OAL) in the kernel.
 *
 * The kernel doesn't process the call: it hands the parameters to the
 * OAL's OEMIoControl, as DeviceIoControl does for a driver. Which codes
 * work depends on the device's OAL.
 *
 * @param dwIoControlCode The IOCTL.
 * @param lpInBuf Input buffer, or NULL.
 * @param nInBufSize Size of lpInBuf in bytes.
 * @param lpOutBuf Output buffer, or NULL.
 * @param nOutBufSize Size of lpOutBuf in bytes.
 * @param lpBytesReturned Receives the number of bytes written to lpOutBuf.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and later.
 */
BOOL KernelIoControl(DWORD dwIoControlCode, LPVOID lpInBuf, DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize, LPDWORD lpBytesReturned);
/**
 * Registers an event for a hardware interrupt and enables the interrupt.
 *
 * Call it before waiting on hEvent: the kernel signals hEvent when the
 * interrupt's ISR returns idInt. Wait on hEvent only with
 * WaitForSingleObject; WaitForMultipleObjects fails with it, and waiting
 * before this call makes this call fail. The kernel passes pvData to the
 * OAL's OEMInterruptEnable.
 *
 * @param idInt SYSINTR identifier of the interrupt.
 * @param hEvent Event, from CreateEvent, for the interrupt service thread
 *        to wait on.
 * @param pvData Data for OEMInterruptEnable, or NULL.
 * @param cbData Size of pvData in bytes.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InterruptInitialize(DWORD idInt, HANDLE hEvent, LPVOID pvData, DWORD cbData);
/**
 * Tells the kernel the driver has finished with an interrupt.
 *
 * Call it after handling each interrupt, before waiting on the event
 * again: it unmasks the interrupt, through the OAL's OEMInterruptDone.
 *
 * @param idInt SYSINTR identifier of the interrupt.
 *
 * @note Windows CE 2.0 and later.
 */
VOID InterruptDone(DWORD idInt);
/**
 * Disables a hardware interrupt and unregisters its event.
 *
 * Call it before closing the event InterruptInitialize registered. The
 * kernel calls the OAL's OEMInterruptDisable.
 *
 * @param idInt SYSINTR identifier of the interrupt.
 *
 * @note Windows CE 2.0 and later.
 */
VOID InterruptDisable(DWORD idInt);

#ifdef __cplusplus
}
#endif

#endif

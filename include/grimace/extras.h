#ifndef GRIMACE_EXTRAS_H
#define GRIMACE_EXTRAS_H

#ifndef IDC_STATIC
#define IDC_STATIC (-1)
#endif

#define SYS_COLOR_INDEX_FLAG 0x40000000
#define COLOR_INDEX_MASK SYS_COLOR_INDEX_FLAG

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Checks a string against the system password.
 *
 * @param lpszPassword The string to check.
 * @return TRUE if it matches, FALSE otherwise.
 */
BOOL WINAPI CheckPassword(LPWSTR lpszPassword);
/**
 * A DLL's entry point, which you write. Windows CE calls it when a process
 * loads or frees the DLL, and when the process starts or ends a thread.
 *
 * Declared here so a C++ DLL's DllMain has C linkage.
 *
 * @param hinstDLL The DLL's instance handle.
 * @param fdwReason DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH,
 *        DLL_THREAD_ATTACH or DLL_THREAD_DETACH.
 * @param lpvReserved Reserved.
 * @return For DLL_PROCESS_ATTACH, TRUE to load or FALSE to fail the load.
 *         Ignored for the other reasons.
 */
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
/**
 * Retrieves clipboard data as a copy owned by the calling process.
 *
 * Like GetClipboardData, but saves the copy you'd otherwise make with
 * LocalAlloc. Open the clipboard first with OpenClipboard. Free the result
 * with LocalFree. Windows CE only.
 *
 * @param uFormat Clipboard format, CF_* or a registered format.
 * @return The data, or NULL on failure (see GetLastError).
 */
HANDLE WINAPI GetClipboardDataAlloc(UINT uFormat);
/**
 * Retrieves the current time as a FILETIME.
 *
 * Undocumented in the Windows CE SDK. The SDK headers describe it as
 * internal to the file system: prefer GetSystemTime with
 * SystemTimeToFileTime.
 *
 * @param lpFileTime Receives the time.
 */
void WINAPI GetCurrentFT(LPFILETIME lpFileTime);
/**
 * Atomically sets a variable to a new value if it currently equals a given
 * value.
 *
 * Note the argument order differs from InterlockedCompareExchange.
 *
 * @param Target The variable to test and set.
 * @param oldValue Value to compare with.
 * @param newValue Value to store if *Target equals oldValue.
 * @return The value of *Target before the call. The exchange happened if
 *         this equals oldValue.
 */
LONG WINAPI InterlockedTestExchange(LPLONG Target, LONG oldValue, LONG newValue);
/**
 * Returns a pseudo-random number.
 *
 * @return A random DWORD.
 */
DWORD WINAPI Random(void);
/**
 * Adds a document to the shell's recent documents list, or clears the list.
 *
 * Windows CE keeps at most ten documents in the list.
 *
 * @param uFlags SHARD_PATH if pv is a path, SHARD_PIDL if it's an item
 *        identifier list.
 * @param pv The document, or NULL to clear the list.
 */
void WINAPI SHAddToRecentDocs(UINT uFlags, LPCVOID pv);
/**
 * Shows the system's out of memory dialog.
 *
 * @param hwndOwner Owner of the dialog.
 * @param grfFlags Reserved; must be zero.
 * @return Not defined; ignore it.
 */
int WINAPI SHShowOutOfMemory(HWND hwndOwner, UINT grfFlags);

/**
 * Tells the battery driver about a system clock change, so its battery life
 * tracking stays accurate.
 *
 * Call straight after SetSystemTime.
 *
 * @param fForward TRUE if the clock moved forward, FALSE if back.
 * @param pftDelta Size of the change, as a FILETIME interval.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
void WINAPI BatteryNotifyOfTimeChange(BOOL fForward, FILETIME *pftDelta);
/**
 * Copies a file's contents over another file, then deletes the source.
 *
 * Works only on the RAM-based object store file system.
 *
 * @param lpszDestFile The file to overwrite. Can't be NULL.
 * @param lpszSourceFile The file to copy from and delete. Can't be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI DeleteAndRenameFile(LPCWSTR lpszDestFile, LPCWSTR lpszSourceFile);
/**
 * Enables or disables the hardware keyboard.
 *
 * Useful while the user writes on the touch screen, so a hand resting on the
 * keyboard doesn't type. Menus, tabs, buttons and static controls repaint so
 * they can update how they show keyboard accelerators.
 *
 * @param fEnable TRUE to enable, FALSE to disable.
 * @return Always TRUE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI EnableHardwareKeyboard(BOOL fEnable);
/**
 * Returns the status and capabilities of the hardware keyboard.
 *
 * @return A combination of KBDI_KEYBOARD_PRESENT, KBDI_KEYBOARD_ENABLED,
 *         KBDI_KEYBOARD_ENTER_ESC (has Enter and Escape keys or
 *         equivalents) and KBDI_KEYBOARD_ALPHA_NUM (has letter and number
 *         keys).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
DWORD WINAPI GetKeyboardStatus(void);
/**
 * Returns the source of the keyboard message being processed.
 *
 * Call while handling WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN or WM_SYSKEYUP to
 * tell a hardware keyboard from a software one. Input from the keyboard
 * driver or keybd_event counts as hardware; PostMessage counts as software.
 * Windows CE only.
 *
 * @return MSGSRC_HARDWARE_KEYBOARD, MSGSRC_SOFTWARE_POST or
 *         MSGSRC_UNKNOWN.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
UINT WINAPI GetMessageSource(void);
/**
 * Retrieves the stylus points for the current stroke, including ones that
 * were coalesced because the application couldn't keep up with
 * WM_MOUSEMOVE.
 *
 * Points are at higher than screen resolution, for smoother ink. It only
 * collects points: drawing them is up to the caller. Not supported in the
 * emulator.
 *
 * @param pptBuf Receives the points.
 * @param nBufPoints Size of pptBuf, in points.
 * @param pnPointsRetrieved Receives the number of points stored.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
BOOL WINAPI GetMouseMovePoints(PPOINT pptBuf, UINT nBufPoints, UINT *pnPointsRetrieved);
/**
 * Returns the process that owns the current thread.
 *
 * Undocumented in the Windows CE SDK. Useful in a server or driver called
 * from another process, together with MapPtrToProcess.
 *
 * @return The owning process.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HANDLE WINAPI GetOwnerProcess(void);
/**
 * Loads an installable file system driver for a block device.
 *
 * Undocumented in the Windows CE SDK. Used by block device drivers.
 *
 * @param hDevice The device, as registered with RegisterDevice.
 * @param lpFSDName File name of the file system driver DLL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI LoadFSD(HANDLE hDevice, LPCWSTR lpFSDName);
/**
 * Maps a pointer into the address space slot of a given process, so it can
 * be used from another process.
 *
 * Undocumented in the Windows CE SDK. Used by servers and drivers to access
 * buffers passed by a caller, with GetOwnerProcess or GetCallerProcess.
 *
 * @param lpv The pointer to map.
 * @param hProc The process the pointer belongs to.
 * @return The mapped pointer, or NULL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LPVOID WINAPI MapPtrToProcess(LPVOID lpv, HANDLE hProc);
/**
 * Maps a file into memory uncompressed and returns its address.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param pwszFileName Path of the file.
 * @param pLen Receives the length of the mapping.
 * @return The address of the mapping, or NULL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
LPVOID WINAPI MapUncompressedFileW(LPCWSTR pwszFileName, LPDWORD pLen);
/**
 * Posts a key press and the characters it produces to a window, as if typed.
 *
 * Undocumented in the Windows CE SDK. Used by input methods and software
 * keyboards.
 *
 * @param hwnd Target window, or (HWND)-1 for the window with the focus.
 * @param VKey Virtual key code.
 * @param KeyStateFlags Key state, KeyStateDownFlag and the other KeyState*
 *        flags.
 * @param cCharacters Number of characters in the buffers.
 * @param pShiftStateBuffer Key state for each character.
 * @param pCharacterBuffer The characters.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI PostKeybdMessage(HWND hwnd, UINT VKey, UINT KeyStateFlags, UINT cCharacters, UINT *pShiftStateBuffer, UINT *pCharacterBuffer);
/**
 * Sets the system's ANSI code page.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param uiACP Code page identifier.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI SetACP(UINT uiACP);
/**
 * Sets the system's OEM code page.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param uiOEMCP Code page identifier.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI SetOEMCP(UINT uiOEMCP);
/**
 * Sets the system default locale.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param Locale The locale identifier.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI SetSystemDefaultLCID(LCID Locale);
/**
 * Tells the system whether daylight saving time is in effect.
 *
 * Windows CE doesn't switch to and from daylight saving time by itself: call
 * this with 1 when it starts and 0 when it ends.
 *
 * @param dst 1 for daylight saving time, 0 for standard time.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
void WINAPI SetDaylightTime(DWORD dst);
/**
 * Tells the system that an application started from the registry Init key
 * has finished initialising, so applications that depend on it can start.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param dw The sequence number passed to the application on its command
 *        line.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
void WINAPI SignalStarted(DWORD dw);
/**
 * Maps existing pages, virtual or physical, into a reserved region of the
 * calling process, without copying them.
 *
 * A kernel function for drivers, not in the SDK headers. Reserve the
 * destination first with VirtualAlloc(MEM_RESERVE, PAGE_NOACCESS); the
 * pages then alias the source. Unmap them with VirtualFree(MEM_DECOMMIT)
 * or by releasing the region. Mapping a view of a pagefile-backed shared
 * mapping into the calling process works on the Jornada 720.
 *
 * @param lpvDest Page-aligned address inside the reserved region. For a
 *        virtual source it must sit at the same offset within a 64 KB
 *        block as lpvSrc, or the call fails with ERROR_INVALID_PARAMETER.
 * @param lpvSrc Page-aligned virtual address of the source, at the same
 *        offset within a 64 KB block as lpvDest, or with PAGE_PHYSICAL in
 *        fdwProtect, a physical address shifted right by 8.
 * @param cbSize Bytes to map, a multiple of the page size.
 * @param fdwProtect PAGE_* protection for the new mapping, such as
 *        PAGE_READWRITE or PAGE_EXECUTE_READ, optionally with
 *        PAGE_NOCACHE, and PAGE_PHYSICAL for a physical source.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI VirtualCopy(LPVOID lpvDest, LPVOID lpvSrc, DWORD cbSize, DWORD fdwProtect);
/**
 * Copies a bitmap, stretching it as needed, leaving out pixels of a given
 * colour.
 *
 * @param hdcDest Destination device context.
 * @param nXDest Left of the destination rectangle, in logical units.
 * @param nYDest Top of the destination rectangle, in logical units.
 * @param nWidthDest Width of the destination rectangle, in logical units.
 * @param nHeightDest Height of the destination rectangle, in logical units.
 * @param hImgSrc Source device context or bitmap. A bitmap must not be
 *        selected into a device context.
 * @param nXSrc Left of the source rectangle, in logical units.
 * @param nYSrc Top of the source rectangle, in logical units.
 * @param nWidthSrc Width of the source rectangle, in logical units.
 * @param nHeightSrc Height of the source rectangle, in logical units.
 * @param crTransparentColor Source colour to leave out.
 * @return Nonzero on success, zero on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL WINAPI TransparentImage(HDC hdcDest, int nXDest, int nYDest, int nWidthDest, int nHeightDest, HANDLE hImgSrc, int nXSrc, int nYSrc,
                             int nWidthSrc, int nHeightSrc, COLORREF crTransparentColor);

#ifndef NPLOGFONT
#define NPLOGFONT NPLOGFONTW
#endif
#ifndef EnumDateFormats
#define EnumDateFormats EnumDateFormatsW
#endif
#ifndef GetStringType
#define GetStringType GetStringTypeW
#endif
#ifndef MapUncompressedFile
/**
 * Maps a file into memory uncompressed and returns its address.
 *
 * Undocumented in the Windows CE SDK.
 *
 * @param pwszFileName Path of the file.
 * @param pLen Receives the length of the mapping.
 * @return The address of the mapping, or NULL on failure.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define MapUncompressedFile MapUncompressedFileW
#endif
#ifndef EIRESID
#define EIRESID(x) (-1 * (int)(x))
#endif

#if GRIMACE_CE == 1
#define lstrcmpW wcscmp
#define lstrcmpiW _wcsicmp
#define IsCharAlphaW iswalpha
#define IsCharAlphaNumericW iswalnum
#define IsCharLowerW iswlower
#define IsCharUpperW iswupper
#else
#define PALETTEINDEX2BPP(i) (((i) == 0) ? 0x00000000 : (((i) == 1) ? 0x00808080 : (((i) == 2) ? 0x00C0C0C0 : 0x00FFFFFF)))
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif

/*
	tlhelp32.h - Include file for Tool help functions.

	Written by Mumit Khan <khan@nanotech.wisc.edu>

	This file is part of a free library for the Win32 API. 

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/
#ifndef _TLHELP32_H
#define _TLHELP32_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define HF32_DEFAULT	1
#define HF32_SHARED	2
#define LF32_FIXED	0x1
#define LF32_FREE	0x2
#define LF32_MOVEABLE	0x4
#define MAX_MODULE_NAME32	255
#define TH32CS_SNAPHEAPLIST	0x1
#define TH32CS_SNAPPROCESS	0x2
#define TH32CS_SNAPTHREAD	0x4
#define TH32CS_SNAPMODULE	0x8
#define TH32CS_GETALLMODS      0x80000000
#define TH32CS_SNAPALL	(TH32CS_SNAPHEAPLIST|TH32CS_SNAPPROCESS|TH32CS_SNAPTHREAD|TH32CS_SNAPMODULE)
#define TH32CS_INHERIT	0x80000000
/**
 * This structure describes an entry from a list that enumerates the heaps
 * used by a specified process.
 */
typedef struct tagHEAPLIST32 {
	/**
	 * Specifies the length, in bytes, of the structure. Before
	 * calling the Heap32ListFirst function, set this member to
	 * sizeof(HEAPLIST32). If you do not initialize dwSize, Heap32First
	 * will fail.
	 */
	DWORD dwSize;
	/**
	 * Identifier of the process to examine. The contents
	 * of this member can be used by Win32 API elements.
	 */
	DWORD th32ProcessID;
	/**
	 * Heap identifier in the owning process context. The
	 * contents of this member has meaning only to the tool help
	 * functions. It is not a handle, nor is it usable by Win32 API
	 * elements.
	 */
	DWORD th32HeapID;
	/**
	 * Specifies a bitmask of flags. The following flag is
	 * currently defined: Value Description HF32_DEFAULT Process's
	 * default heap.
	 */
	DWORD dwFlags;
} HEAPLIST32,*PHEAPLIST32,*LPHEAPLIST32;
/**
 * This structure describes one entry (block) of a heap that is being
 * examined.
 *
 * Windows CE does not support movable blocks.
 */
typedef struct tagHEAPENTRY32 {
	/**
	 * Specifies the length, in bytes, of the structure. Before
	 * calling the Heap32First function, set this member to
	 * sizeof(HEAPENTRY32). If you do not initialize dwSize, Heap32First
	 * will fail.
	 */
	DWORD dwSize;
	/**
	 * Handle to the heap block.
	 */
	HANDLE hHandle;
	/**
	 * Specifies the linear address of the start of the
	 * block.
	 */
	DWORD dwAddress;
	/**
	 * Specifies the size, in bytes, of the heap block.
	 */
	DWORD dwBlockSize;
	/**
	 * Specifies a bitmask of fags. It is one of the following
	 * values: Value Description LF32_BIGBLOCK A large piece of memory
	 * that has been virtually allocated. LF32_DECOMMIT Decommited
	 * memory block. LF32_FIXED The memory block has a fixed (unmovable)
	 * location. LF32_FREE The memory block is not used.
	 */
	DWORD dwFlags;
	/**
	 * Specifies the lock count on the memory block. The
	 * lock count is incremented each time the LocalLock function is
	 * called on the block either by the application or the DLL that the
	 * heap belongs to.
	 */
	DWORD dwLockCount;
	/**
	 * Reserved; do not use.
	 */
	DWORD dwResvd;
	/**
	 * Identifier of the process to examine. The contents
	 * of this member can be used by Win32 API elements.
	 */
	DWORD th32ProcessID;
	/**
	 * Heap identifier in the owning process context. The
	 * contents of this member has meaning only to the tool help
	 * functions. It is not a handle, nor is it usable by Win32 API
	 * elements.
	 */
	DWORD th32HeapID;
} HEAPENTRY32,*PHEAPENTRY32,*LPHEAPENTRY32;
typedef struct tagPROCESSENTRY32W {
	DWORD dwSize;
	DWORD cntUsage;
	DWORD th32ProcessID;
	DWORD th32DefaultHeapID;
	DWORD th32ModuleID;
	DWORD cntThreads;
	DWORD th32ParentProcessID;
	LONG pcPriClassBase;
	DWORD dwFlags;
	WCHAR szExeFile[MAX_PATH];
} PROCESSENTRY32W,*PPROCESSENTRY32W,*LPPROCESSENTRY32W;
/**
 * This structure describes an entry from a list that enumerates the
 * processes residing in the system address space when a snapshot was
 * taken.
 *
 * All strings are Unicode.
 */
typedef struct tagPROCESSENTRY32 {
	/**
	 * Specifies the length, in bytes, of the structure. Before
	 * calling the Process32First function, set this member to
	 * sizeof(PROCESSENTRY32). If you do not initialize dwSize,
	 * Process32First will fail.
	 */
	DWORD dwSize;
	/**
	 * Number of references to the process. Must be 1.
	 */
	DWORD cntUsage;
	/**
	 * Identifier of the process. The contents of this
	 * member can be used by Win32 API elements.
	 */
	DWORD th32ProcessID;
	/**
	 * Identifier of the default heap for the
	 * process. The contents of this member has meaning only to the tool
	 * help functions. It is not a handle, nor is it usable by Win32 API
	 * elements.
	 */
	DWORD th32DefaultHeapID;
	/**
	 * Module identifier of the process. Must be 0.
	 */
	DWORD th32ModuleID;
	/**
	 * Number of execution threads started by the process.
	 */
	DWORD cntThreads;
	/**
	 * Identifier of the process that created the
	 * process being examined. Must be 0.
	 */
	DWORD th32ParentProcessID;
	/**
	 * Base priority of any threads created by this
	 * process. Value is always THREAD_PRIORITY_NORMAL
	 */
	LONG pcPriClassBase;
	/**
	 * Reserved; do not use.
	 */
	DWORD dwFlags;
#ifdef _WIN32_WCE
	/**
	 * Null-terminated string that contains the path and file
	 * name of the executable file for the process.
	 */
	WCHAR szExeFile[MAX_PATH];
	DWORD th32MemoryBase;
	/**
	 * Array of bits. Each bit signifies permission to
	 * see the address space of one process. For the PROCESSENTRY32
	 * structure, the key contains the bit required to see that address
	 * space.
	 */
	DWORD th32AccessKey;
#else
	CHAR  szExeFile[MAX_PATH];
#endif
} PROCESSENTRY32,*PPROCESSENTRY32,*LPPROCESSENTRY32;
/**
 * This structure describes an entry from a list that enumerates the
 * threads executing in the system when a snapshot was taken.
 *
 * Windows CE supports the following additional members:
 *
 * th32AccessKey: Array of bits. Each bit signifies permission to see the
 * address space of one process. In the THREADENTRY32 structure, the key
 * contains the bits the thread currently has, thus defining the processes
 * it can currently see.
 *
 * th32CurrentProcessID: Process identifier where the thread is executing.
 */
typedef struct tagTHREADENTRY32 {
	/**
	 * Specifies the length, in bytes, of the structure. Before
	 * calling the Thread32First function, set this member to
	 * sizeof(THREADENTRY32). If you do not initialize dwSize,
	 * Thread32First will fail.
	 */
	DWORD dwSize;
	/**
	 * Number of references to the thread. A thread exists as
	 * long as its usage count is nonzero. As soon as its usage count
	 * becomes zero, a thread terminates.
	 */
	DWORD cntUsage;
	/**
	 * Identifier of the thread. This identifier is
	 * compatible with the thread identifier returned by the
	 * CreateProcess function.
	 */
	DWORD th32ThreadID;
	/**
	 * Identifier of the process that created the
	 * thread. The contents of this member can be used by Win32 API
	 * elements.
	 */
	DWORD th32OwnerProcessID;
	/**
	 * Initial priority level assigned to a thread. This
	 * member can be one of the following values: THREAD_PRIORITY_IDLE:
	 * Indicates a base priority level of 1 for IDLE_PRIORITY_CLASS,
	 * NORMAL_PRIORITY_CLASS, or HIGH_PRIORITY_CLASS processes, and a
	 * base priority level of 16 for REALTIME_PRIORITY_CLASS processes.
	 * THREAD_PRIORITY_LOWEST: Indicates 2 points below normal priority
	 * for the priority class. THREAD_PRIORITY_BELOW_NORMAL: Indicates 1
	 * point below normal priority for the priority class.
	 * THREAD_PRIORITY_NORMAL: Indicates normal priority for the
	 * priority class. THREAD_PRIORITY_ABOVE_NORMAL: Indicates 1 point
	 * above normal priority for the priority class.
	 * THREAD_PRIORITY_HIGHEST: Indicates 2 points above normal priority
	 * for the priority class. THREAD_PRIORITY_TIME_CRITICAL: Indicates
	 * a base priority level of 15 for IDLE_PRIORITY_CLASS,
	 * NORMAL_PRIORITY_CLASS, or HIGH_PRIORITY_CLASS processes, and a
	 * base priority level of 31 for REALTIME_PRIORITY_CLASS processes.
	 */
	LONG tpBasePri;
	/**
	 * Change in the priority level of a thread. This value
	 * is a signed delta from the base priority level assigned to the
	 * thread.
	 */
	LONG tpDeltaPri;
	/**
	 * Reserved; do not use.
	 */
	DWORD dwFlags;
#ifdef _WIN32_WCE
	DWORD th32AccessKey;
	DWORD th32CurrentProcessID;
#endif
} THREADENTRY32,*PTHREADENTRY32,*LPTHREADENTRY32;
typedef struct tagMODULEENTRY32W {
	DWORD dwSize;
	DWORD th32ModuleID;
	DWORD th32ProcessID;
	DWORD GlblcntUsage;
	DWORD ProccntUsage;
	BYTE *modBaseAddr;
	DWORD modBaseSize;
	HMODULE hModule; 
	WCHAR szModule[MAX_MODULE_NAME32 + 1];
	WCHAR szExePath[MAX_PATH];
} MODULEENTRY32W,*PMODULEENTRY32W,*LPMODULEENTRY32W;
/**
 * This structure describes an entry from a list that enumerates the
 * modules used by a specified process.
 *
 * The modBaseAddr and hModule members are valid only in the context of the
 * process specified by th32ProcessID.
 */
typedef struct tagMODULEENTRY32 {
	/**
	 * Specifies the length, in bytes, of the structure. Before
	 * calling the Module32First function, set this member to
	 * sizeof(MODULEENTRY32). If you do not initialize dwSize,
	 * Module32First will fail.
	 */
	DWORD dwSize;
	/**
	 * Module identifier in the context of the owning
	 * process. The contents of this member has meaning only to the tool
	 * help functions. It is not a handle, nor is it usable by Win32 API
	 * elements.
	 */
	DWORD th32ModuleID;
	/**
	 * Identifier of the process being examined. The
	 * contents of this member can be used by Win32 API elements.
	 */
	DWORD th32ProcessID;
	/**
	 * Global usage count on the module.
	 */
	DWORD GlblcntUsage;
	/**
	 * Module usage count in the context of the owning
	 * process.
	 */
	DWORD ProccntUsage;
	/**
	 * Base address of the module in the context of the
	 * owning process.
	 */
	BYTE *modBaseAddr;
	/**
	 * Size, in bytes, of the module.
	 */
	DWORD modBaseSize;
	/**
	 * Handle to the module in the context of the owning
	 * process.
	 */
	HMODULE hModule;
#ifdef _WIN32_WCE
       /**
        * Null-terminated string that contains the module name.
        */
       WCHAR szModule[MAX_PATH];
	/**
	 * Null-terminated string that contains the location
	 * (path) of the module.
	 */
	WCHAR szExePath[MAX_PATH];
	/**
	 * Reserved.
	 */
	DWORD dwFlags;
#else
	CHAR szModule[MAX_MODULE_NAME32 + 1];
	CHAR szExePath[MAX_PATH];
#endif
} MODULEENTRY32,*PMODULEENTRY32,*LPMODULEENTRY32;
#ifdef _WIN32_WCE
/**
 * Retrieves the first block in a process heap.
 *
 * Set lphe->dwSize to the size of HEAPENTRY32 before calling. It's changed
 * to the number of bytes written, which may be smaller; don't rely on
 * members beyond it. Use Heap32Next to continue through the heap.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot containing heap
 *        information.
 * @param lphe Receives the heap entry.
 * @param th32ProcessID Process that owns the heap.
 * @param th32HeapID Heap identifier.
 * @return TRUE when an entry is copied; FALSE on failure. GetLastError
 *        returns ERROR_NO_MORE_FILES for an invalid or empty heap.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Heap32First(HANDLE hSnapshot,LPHEAPENTRY32 lphe,DWORD th32ProcessID,DWORD th32HeapID);
#else
BOOL WINAPI Heap32First(LPHEAPENTRY32,DWORD,DWORD);
#endif
/**
 * Retrieves the first heap in a process heap list.
 *
 * Set lphl->dwSize to the size of HEAPLIST32 before calling. It's changed
 * to the number of bytes written, which may be smaller; don't rely on
 * members beyond it. Use Heap32ListNext to enumerate more heaps.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot containing heap
 *        information.
 * @param lphl Receives the heap list entry.
 * @return TRUE when an entry is copied; FALSE on failure. GetLastError
 *        returns ERROR_NO_MORE_FILES if there is no heap list or the
 *        snapshot has no heap list information.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Heap32ListFirst(HANDLE hSnapshot,LPHEAPLIST32 lphl);
/**
 * Retrieves the next heap in a snapshot's heap list.
 *
 * Set lphl->dwSize as for Heap32ListFirst, which retrieves the first
 * entry.
 *
 * @param hSnapshot Snapshot containing the heap list.
 * @param lphl Receives the next heap entry.
 * @return TRUE when an entry is copied; FALSE when no more entries exist
 *        or an error occurs. GetLastError returns ERROR_NO_MORE_FILES at
 *        the end.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Heap32ListNext(HANDLE hSnapshot,LPHEAPLIST32 lphl);
#ifdef _WIN32_WCE
/**
 * Retrieves the next block in a heap.
 *
 * Call Heap32First to retrieve the first block.
 *
 * @param hSnapshot Snapshot containing the heap.
 * @param lphe Receives the next heap block.
 * @return TRUE when an entry is copied; FALSE when no more blocks exist
 *        or an error occurs. GetLastError returns ERROR_NO_MORE_FILES at
 *        the end and ERROR_INVALID_DATA if the heap is corrupt or was
 *        modified so that the walk can't continue.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Heap32Next(HANDLE hSnapshot,LPHEAPENTRY32 lphe);
#else
BOOL WINAPI Heap32Next(LPHEAPENTRY32);
#endif
/**
 * Retrieves the first module recorded for a process in a snapshot.
 *
 * Set lpme->dwSize to the size of MODULEENTRY32 before calling. It's
 * changed to the number of bytes written, which may be smaller; don't rely
 * on members beyond it. Use Module32Next to continue the enumeration.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot containing module
 *        information.
 * @param lpme Receives the module entry.
 * @return TRUE when an entry is copied; FALSE on failure. GetLastError
 *        returns ERROR_NO_MORE_FILES if the snapshot has no modules.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Module32First(HANDLE hSnapshot,LPMODULEENTRY32 lpme);
BOOL WINAPI Module32FirstW(HANDLE,LPMODULEENTRY32W);
/**
 * Retrieves the next module in a snapshot.
 *
 * Call Module32First to retrieve the first entry.
 *
 * @param hSnapshot Snapshot containing module information.
 * @param lpme Receives the next module entry.
 * @return TRUE when an entry is copied; FALSE when no more modules exist
 *        or an error occurs. GetLastError returns ERROR_NO_MORE_FILES at
 *        the end.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Module32Next(HANDLE hSnapshot,LPMODULEENTRY32 lpme);
BOOL WINAPI Module32NextW(HANDLE,LPMODULEENTRY32W);
/**
 * Retrieves the first process recorded in a system snapshot.
 *
 * Set lppe->dwSize to the size of PROCESSENTRY32 before calling. It's
 * changed to the number of bytes written, which may be smaller; don't rely
 * on members beyond it. Use Process32Next to continue the enumeration.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot containing
 *        process information.
 * @param lppe Receives the process entry.
 * @return TRUE when an entry is copied; FALSE on failure. GetLastError
 *        returns ERROR_NO_MORE_FILES if the snapshot has no processes.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Process32First(HANDLE hSnapshot,LPPROCESSENTRY32 lppe);
BOOL WINAPI Process32FirstW(HANDLE,LPPROCESSENTRY32W);
/**
 * Retrieves the next process in a system snapshot.
 *
 * Call Process32First to retrieve the first entry.
 *
 * @param hSnapshot Snapshot containing process information.
 * @param lppe Receives the next process entry.
 * @return TRUE when an entry is copied; FALSE when no more processes exist
 *        or an error occurs. GetLastError returns ERROR_NO_MORE_FILES at
 *        the end.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Process32Next(HANDLE hSnapshot,LPPROCESSENTRY32 lppe);
BOOL WINAPI Process32NextW(HANDLE,LPPROCESSENTRY32W);
/**
 * Retrieves the first thread recorded in a system snapshot.
 *
 * Set lpte->dwSize to the size of THREADENTRY32 before calling. It's
 * changed to the number of bytes written, which may be smaller; don't rely
 * on members beyond it. Use Thread32Next to continue the enumeration.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot containing
 *        thread information.
 * @param lpte Receives the thread entry.
 * @return TRUE when an entry is copied; FALSE on failure. GetLastError
 *        returns ERROR_NO_MORE_FILES if the snapshot has no threads.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Thread32First(HANDLE hSnapshot,LPTHREADENTRY32 lpte);
/**
 * Retrieves the next thread in a system snapshot.
 *
 * Call Thread32First to retrieve the first entry.
 *
 * @param hSnapshot Snapshot containing thread information.
 * @param lpte Receives the next thread entry.
 * @return TRUE when an entry is copied; FALSE when no more threads exist
 *        or an error occurs. GetLastError returns ERROR_NO_MORE_FILES at
 *        the end.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Thread32Next(HANDLE hSnapshot,LPTHREADENTRY32 lpte);
/**
 * Copies bytes from a process address space into the caller's buffer.
 *
 * The system verifies the entire requested range is readable before
 * copying, and fails otherwise.
 *
 * @param th32ProcessID Process to read, or 0 for the current process.
 * @param lpBaseAddress Address in the target process.
 * @param lpBuffer Receives the copied bytes.
 * @param cbRead Number of bytes to read.
 * @param lpNumberOfBytesRead Receives the number copied, or NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI Toolhelp32ReadProcessMemory(DWORD th32ProcessID,LPCVOID lpBaseAddress,LPVOID lpBuffer,DWORD cbRead,LPDWORD lpNumberOfBytesRead);
/**
 * Captures a read-only snapshot of processes, threads, modules or heaps.
 *
 * The snapshot is a copy of the system state, read by the other Tool Help
 * functions. Close it with CloseToolhelp32Snapshot, not CloseHandle.
 *
 * @param dwFlags TH32CS_SNAPPROCESS, TH32CS_SNAPTHREAD, TH32CS_SNAPMODULE
 *        and/or TH32CS_SNAPHEAPLIST, or TH32CS_SNAPALL for all four.
 *        THCS_GETALLMODES lists all modules loaded in the system.
 * @param th32ProcessID Process to snapshot for heap or module data, or 0
 *        for the current process. Ignored otherwise.
 * @return Snapshot handle, or INVALID_HANDLE_VALUE on failure (see
 *        GetLastError).
 *
 * @note Windows CE 3.0 only.
 */
HANDLE WINAPI CreateToolhelp32Snapshot(DWORD dwFlags,DWORD th32ProcessID);
#if (_WIN32_WCE >= 0x200)
/**
 * Closes a Tool Help snapshot and releases its system resources.
 *
 * @param hSnapshot Snapshot from CreateToolhelp32Snapshot.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL WINAPI CloseToolhelp32Snapshot(HANDLE hSnapshot);
#endif
#if defined(UNICODE) && !defined(_WIN32_WCE)
#define LPMODULEENTRY32 LPMODULEENTRY32W
#define LPPROCESSENTRY32 LPPROCESSENTRY32W
#define MODULEENTRY32 MODULEENTRY32W
#define Module32First Module32FirstW
#define Module32Next Module32NextW
#define PMODULEENTRY32 PMODULEENTRY32W
#define PPROCESSENTRY32 PPROCESSENTRY32W
#define PROCESSENTRY32 PROCESSENTRY32W
#define Process32First Process32FirstW
#define Process32Next Process32NextW
#endif /* UNICODE && !_WIN32_WCE */
#ifdef __cplusplus
}
#endif
#endif /* _TLHELP32_H */


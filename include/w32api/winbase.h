#ifndef _WINBASE_H
#define _WINBASE_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef WINBASEAPI
#ifdef __W32API_USE_DLLIMPORT__
#define WINBASEAPI DECLSPEC_IMPORT
#else
#define WINBASEAPI
#endif
#endif

#ifndef WINADVAPI
#ifdef __W32API_USE_DLLIMPORT__
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SP_SERIALCOMM 1
#define PST_UNSPECIFIED	0
#define PST_RS232	1
#define PST_PARALLELPORT	2
#define PST_RS422	3
#define PST_RS423	4
#define PST_RS449	5
#define PST_MODEM	6
#define PST_FAX	0x21
#define PST_SCANNER	0x22
#define PST_NETWORK_BRIDGE	0x100
#define PST_LAT	0x101
#define PST_TCPIP_TELNET	0x102
#define PST_X25	0x103
#define BAUD_075	1
#define BAUD_110	2
#define BAUD_134_5	4
#define BAUD_150	8
#define BAUD_300	16
#define BAUD_600	32
#define BAUD_1200	64
#define BAUD_1800	128
#define BAUD_2400	256
#define BAUD_4800	512
#define BAUD_7200	1024
#define BAUD_9600	2048
#define BAUD_14400	4096
#define BAUD_19200	8192
#define BAUD_38400	16384
#define BAUD_56K	32768
#define BAUD_128K	65536
#define BAUD_115200	131072
#define BAUD_57600	262144
#define BAUD_USER	0x10000000
#define PCF_DTRDSR	1
#define PCF_RTSCTS	2
#define PCF_RLSD	4
#define PCF_PARITY_CHECK	8
#define PCF_XONXOFF	16
#define PCF_SETXCHAR	32
#define PCF_TOTALTIMEOUTS	64
#define PCF_INTTIMEOUTS	128
#define PCF_SPECIALCHARS	256
#define PCF_16BITMODE	512
#define SP_PARITY	1
#define SP_BAUD	2
#define SP_DATABITS	4
#define SP_STOPBITS	8
#define SP_HANDSHAKING	16
#define SP_PARITY_CHECK	32
#define SP_RLSD	64
#define DATABITS_5	1
#define DATABITS_6	2
#define DATABITS_7	4
#define DATABITS_8	8
#define DATABITS_16	16
#define DATABITS_16X	32
#define STOPBITS_10	1
#define STOPBITS_15	2
#define STOPBITS_20	4
#define PARITY_NONE	256
#define PARITY_ODD	512
#define PARITY_EVEN	1024
#define PARITY_MARK	2048
#define PARITY_SPACE	4096
#define EXCEPTION_DEBUG_EVENT	1
#define CREATE_THREAD_DEBUG_EVENT	2
#define CREATE_PROCESS_DEBUG_EVENT	3
#define EXIT_THREAD_DEBUG_EVENT	4
#define EXIT_PROCESS_DEBUG_EVENT	5
#define LOAD_DLL_DEBUG_EVENT	6
#define UNLOAD_DLL_DEBUG_EVENT	7
#define OUTPUT_DEBUG_STRING_EVENT	8
#define RIP_EVENT	9
#define HFILE_ERROR ((HFILE)-1)
#define FILE_BEGIN	0
#define FILE_CURRENT	1
#define FILE_END	2
#define INVALID_SET_FILE_POINTER	((DWORD)-1)
#define OF_READ 0
#define OF_READWRITE	2
#define OF_WRITE	1
#define OF_SHARE_COMPAT	0
#define OF_SHARE_DENY_NONE	64
#define OF_SHARE_DENY_READ	48
#define OF_SHARE_DENY_WRITE	32
#define OF_SHARE_EXCLUSIVE	16
#define OF_CANCEL	2048
#define OF_CREATE	4096
#define OF_DELETE	512
#define OF_EXIST	16384
#define OF_PARSE	256
#define OF_PROMPT	8192
#define OF_REOPEN	32768
#define OF_VERIFY	1024
#define NMPWAIT_NOWAIT	1
#define NMPWAIT_WAIT_FOREVER	((DWORD)-1)
#define NMPWAIT_USE_DEFAULT_WAIT	0
#define CE_BREAK	16
#define CE_DNS	2048
#define CE_FRAME	8
#define CE_IOE	1024
#define CE_MODE	32768
#define CE_OOP	4096
#define CE_OVERRUN	2
#define CE_PTO	512
#define CE_RXOVER	1
#define CE_RXPARITY	4
#define CE_TXFULL	256
#define PROGRESS_CONTINUE	0
#define PROGRESS_CANCEL	1
#define PROGRESS_STOP	2
#define PROGRESS_QUIET	3
#define CALLBACK_CHUNK_FINISHED	0
#define CALLBACK_STREAM_SWITCH	1
#define COPY_FILE_FAIL_IF_EXISTS              0x0001
#define COPY_FILE_RESTARTABLE                 0x0002
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE       0x0004
#if (_WIN32_WINNT > 0x0500)
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x0008
#if (_WIN32_WINNT > 0x0501)
#define COPY_FILE_COPY_SYMLINK                0x0800
#define COPY_FILE_NO_BUFFERING                0x1000
#endif
#endif
#define OFS_MAXPATHNAME 128
#define FILE_MAP_ALL_ACCESS     0xf001f
#define FILE_MAP_READ   4
#define FILE_MAP_WRITE  2
#define FILE_MAP_COPY   1
#define MUTEX_ALL_ACCESS	0x1f0001
#define MUTEX_MODIFY_STATE	1
#define SEMAPHORE_ALL_ACCESS	0x1f0003
#define SEMAPHORE_MODIFY_STATE	2
#define EVENT_ALL_ACCESS	0x1f0003
#define EVENT_MODIFY_STATE	2
#define PIPE_ACCESS_DUPLEX      3
#define PIPE_ACCESS_INBOUND     1
#define PIPE_ACCESS_OUTBOUND    2
#define PIPE_TYPE_BYTE	0
#define PIPE_TYPE_MESSAGE	4
#define PIPE_READMODE_BYTE	0
#define PIPE_READMODE_MESSAGE	2
#define PIPE_WAIT	0
#define PIPE_NOWAIT	1
#define PIPE_CLIENT_END 0
#define PIPE_SERVER_END 1
#define PIPE_UNLIMITED_INSTANCES 255
#define DEBUG_PROCESS			0x00000001
#define DEBUG_ONLY_THIS_PROCESS		0x00000002
#define CREATE_SUSPENDED		0x00000004
#ifndef _WIN32_WCE
#define DETACHED_PROCESS		0x00000008
#endif
#define CREATE_NEW_CONSOLE		0x00000010
#define NORMAL_PRIORITY_CLASS		0x00000020
#define IDLE_PRIORITY_CLASS		0x00000040
#define HIGH_PRIORITY_CLASS		0x00000080
#define REALTIME_PRIORITY_CLASS		0x00000100
#ifndef _WIN32_WCE
#define CREATE_NEW_PROCESS_GROUP	0x00000200
#define CREATE_UNICODE_ENVIRONMENT	0x00000400
#endif
#define CREATE_SEPARATE_WOW_VDM		0x00000800
#define CREATE_SHARED_WOW_VDM		0x00001000
#define CREATE_FORCEDOS			0x00002000
#define BELOW_NORMAL_PRIORITY_CLASS	0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS	0x00008000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x00010000
#define CREATE_BREAKAWAY_FROM_JOB	0x01000000
#define CREATE_WITH_USERPROFILE		0x02000000
#define CREATE_DEFAULT_ERROR_MODE	0x04000000
#define CREATE_NO_WINDOW		0x08000000
#define PROFILE_USER			0x10000000
#define PROFILE_KERNEL			0x20000000
#define PROFILE_SERVER			0x40000000
#define CONSOLE_TEXTMODE_BUFFER 1
#define CREATE_NEW	1
#define CREATE_ALWAYS	2
#define OPEN_EXISTING	3
#define OPEN_ALWAYS	4
#define TRUNCATE_EXISTING	5
#define FILE_FLAG_WRITE_THROUGH	0x80000000
#define FILE_FLAG_OVERLAPPED	1073741824
#define FILE_FLAG_NO_BUFFERING	536870912
#define FILE_FLAG_RANDOM_ACCESS	268435456
#define FILE_FLAG_SEQUENTIAL_SCAN	134217728
#define FILE_FLAG_DELETE_ON_CLOSE	67108864
#define FILE_FLAG_BACKUP_SEMANTICS	33554432
#define FILE_FLAG_POSIX_SEMANTICS	16777216
#define FILE_FLAG_OPEN_REPARSE_POINT	2097152
#define FILE_FLAG_OPEN_NO_RECALL	1048576
#if (_WIN32_WINNT >= 0x0500)
#define FILE_FLAG_FIRST_PIPE_INSTANCE	524288
#endif
#define SYMBOLIC_LINK_FLAG_DIRECTORY	0x1
#define CLRDTR 6
#define CLRRTS 4
#define SETDTR 5
#define SETRTS 3
#define SETXOFF 1
#define SETXON 2
#define SETBREAK 8
#define CLRBREAK 9
#define STILL_ACTIVE 0x103
#define FIND_FIRST_EX_CASE_SENSITIVE 1
#define SCS_32BIT_BINARY 0
#define SCS_64BIT_BINARY 6
#define SCS_DOS_BINARY 1
#define SCS_OS216_BINARY 5
#define SCS_PIF_BINARY 3
#define SCS_POSIX_BINARY 4
#define SCS_WOW_BINARY 2
#define MAX_COMPUTERNAME_LENGTH 15
#define HW_PROFILE_GUIDLEN	39
#define MAX_PROFILE_LEN	80
#define DOCKINFO_UNDOCKED	1
#define DOCKINFO_DOCKED	2
#define DOCKINFO_USER_SUPPLIED	4
#define DOCKINFO_USER_UNDOCKED	(DOCKINFO_USER_SUPPLIED|DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED	(DOCKINFO_USER_SUPPLIED|DOCKINFO_DOCKED)
#define DRIVE_REMOVABLE 2
#define DRIVE_FIXED 3
#define DRIVE_REMOTE 4
#define DRIVE_CDROM 5
#define DRIVE_RAMDISK 6
#define DRIVE_UNKNOWN 0
#define DRIVE_NO_ROOT_DIR 1
#define FILE_TYPE_UNKNOWN 0
#define FILE_TYPE_DISK 1
#define FILE_TYPE_CHAR 2
#define FILE_TYPE_PIPE 3
#define FILE_TYPE_REMOTE 0x8000
/* also in ddk/ntapi.h */
#define HANDLE_FLAG_INHERIT		0x01
#define HANDLE_FLAG_PROTECT_FROM_CLOSE	0x02
/* end ntapi.h */
#define STD_INPUT_HANDLE (DWORD)(0xfffffff6)
#define STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)
#define STD_ERROR_HANDLE (DWORD)(0xfffffff4)
#define INVALID_HANDLE_VALUE (HANDLE)(-1)
#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1
#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1
#ifdef _WIN32_WCE
#define THREAD_PRIORITY_TIME_CRITICAL 0
#define THREAD_PRIORITY_HIGHEST 1
#define THREAD_PRIORITY_ABOVE_NORMAL 2
#define THREAD_PRIORITY_NORMAL 3
#define THREAD_PRIORITY_BELOW_NORMAL 4
#define THREAD_PRIORITY_LOWEST 5
#define THREAD_PRIORITY_ABOVE_IDLE 6
#define THREAD_PRIORITY_IDLE 7
#else
#define THREAD_PRIORITY_ABOVE_NORMAL 1
#define THREAD_PRIORITY_BELOW_NORMAL (-1)
#define THREAD_PRIORITY_HIGHEST 2
#define THREAD_PRIORITY_IDLE (-15)
#define THREAD_PRIORITY_LOWEST (-2)
#define THREAD_PRIORITY_NORMAL 0
#define THREAD_PRIORITY_TIME_CRITICAL 15
#endif
#define THREAD_PRIORITY_ERROR_RETURN 2147483647
#define TIME_ZONE_ID_UNKNOWN 0
#define TIME_ZONE_ID_STANDARD 1
#define TIME_ZONE_ID_DAYLIGHT 2
#define TIME_ZONE_ID_INVALID 0xFFFFFFFF
#define FS_CASE_IS_PRESERVED 2
#define FS_CASE_SENSITIVE 1
#define FS_UNICODE_STORED_ON_DISK 4
#define FS_PERSISTENT_ACLS 8
#define FS_FILE_COMPRESSION 16
#define FS_VOL_IS_COMPRESSED 32768
#define GMEM_FIXED 0
#define GMEM_MOVEABLE 2
#define GMEM_MODIFY 128
#define GPTR 64
#define GHND 66
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_DDESHARE 0
#else
#define GMEM_DDESHARE 8192
#endif
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_DISCARDABLE 0xF00
#else
#define GMEM_DISCARDABLE 256
#endif
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_LOWER 0
#else
#define GMEM_LOWER 4096
#endif
#define GMEM_NOCOMPACT 16
#define GMEM_NODISCARD 32
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_NOT_BANKED 0
#else
#define GMEM_NOT_BANKED 4096
#endif
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_NOTIFY 0
#else
#define GMEM_NOTIFY 16384
#endif
#if defined(_WIN32_WCE) && _WIN32_WCE >= 0x300
#define GMEM_SHARE 0
#else
#define GMEM_SHARE 8192
#endif
#define GMEM_ZEROINIT 64
#define GMEM_DISCARDED 16384
#define GMEM_INVALID_HANDLE 32768
#define GMEM_LOCKCOUNT 255
#define GMEM_VALID_FLAGS 32626
#define STATUS_WAIT_0 0
#define STATUS_ABANDONED_WAIT_0 0x80
#define STATUS_USER_APC 0xC0
#define STATUS_TIMEOUT 0x102
#define STATUS_PENDING 0x103
#define STATUS_SEGMENT_NOTIFICATION 0x40000005
#define STATUS_GUARD_PAGE_VIOLATION 0x80000001
#define STATUS_DATATYPE_MISALIGNMENT 0x80000002
#define STATUS_BREAKPOINT 0x80000003
#define STATUS_SINGLE_STEP 0x80000004
#define STATUS_ACCESS_VIOLATION 0xC0000005
#define STATUS_IN_PAGE_ERROR 0xC0000006
#define STATUS_INVALID_HANDLE 0xC0000008L
#define STATUS_NO_MEMORY 0xC0000017
#define STATUS_ILLEGAL_INSTRUCTION 0xC000001D
#define STATUS_NONCONTINUABLE_EXCEPTION 0xC0000025
#define STATUS_INVALID_DISPOSITION 0xC0000026
#define STATUS_ARRAY_BOUNDS_EXCEEDED 0xC000008C
#define STATUS_FLOAT_DENORMAL_OPERAND 0xC000008D
#define STATUS_FLOAT_DIVIDE_BY_ZERO 0xC000008E
#define STATUS_FLOAT_INEXACT_RESULT 0xC000008F
#define STATUS_FLOAT_INVALID_OPERATION 0xC0000090
#define STATUS_FLOAT_OVERFLOW 0xC0000091
#define STATUS_FLOAT_STACK_CHECK 0xC0000092
#define STATUS_FLOAT_UNDERFLOW 0xC0000093
#define STATUS_INTEGER_DIVIDE_BY_ZERO 0xC0000094
#define STATUS_INTEGER_OVERFLOW 0xC0000095
#define STATUS_PRIVILEGED_INSTRUCTION 0xC0000096
#define STATUS_STACK_OVERFLOW 0xC00000FD
#define STATUS_CONTROL_C_EXIT 0xC000013A
#define STATUS_DLL_INIT_FAILED 0xC0000142
#define STATUS_DLL_INIT_FAILED_LOGOFF 0xC000026B
#define EXCEPTION_ACCESS_VIOLATION	STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT	STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT	STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP	STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED	STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND	STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO	STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT	STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION	STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW	STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK	STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW	STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO	STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW	STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION	STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR	STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION	STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION	STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW	STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION	STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE	STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE	STATUS_INVALID_HANDLE
#define CONTROL_C_EXIT	STATUS_CONTROL_C_EXIT
#define PROCESS_HEAP_REGION 1
#define PROCESS_HEAP_UNCOMMITTED_RANGE 2
#define PROCESS_HEAP_ENTRY_BUSY 4
#define PROCESS_HEAP_ENTRY_MOVEABLE 16
#define PROCESS_HEAP_ENTRY_DDESHARE 32
#define DONT_RESOLVE_DLL_REFERENCES 1
#define LOAD_LIBRARY_AS_DATAFILE 2
#define LOAD_WITH_ALTERED_SEARCH_PATH 8
#define LMEM_FIXED 0
#define LMEM_MOVEABLE 2
#define LMEM_NONZEROLHND 2
#define LMEM_NONZEROLPTR 0
#define LMEM_DISCARDABLE 3840
#define LMEM_NOCOMPACT 16
#define LMEM_NODISCARD 32
#define LMEM_ZEROINIT 64
#define LMEM_DISCARDED 16384
#define LMEM_MODIFY 128
#define LMEM_INVALID_HANDLE 32768
#define LMEM_LOCKCOUNT 255
#define LPTR 64
#define LHND 66
#define NONZEROLHND 2
#define NONZEROLPTR 0
#define LOCKFILE_FAIL_IMMEDIATELY 1
#define LOCKFILE_EXCLUSIVE_LOCK 2
#define LOGON32_PROVIDER_DEFAULT	0
#define LOGON32_PROVIDER_WINNT35	1
#if (_WIN32_WINNT >= 0x0400)
#define LOGON32_PROVIDER_WINNT40	2
#endif
#if (_WIN32_WINNT >= 0x0500)
#define LOGON32_PROVIDER_WINNT50	3
#endif
#define LOGON32_LOGON_INTERACTIVE	2
#define LOGON32_LOGON_NETWORK	3
#define LOGON32_LOGON_BATCH	4
#define LOGON32_LOGON_SERVICE	5
#define LOGON32_LOGON_UNLOCK	7
#if (_WIN32_WINNT >= 0x0500)
#define LOGON32_LOGON_NETWORK_CLEARTEXT	8
#define LOGON32_LOGON_NEW_CREDENTIALS	9
#endif
#define MOVEFILE_REPLACE_EXISTING 1
#define MOVEFILE_COPY_ALLOWED 2
#define MOVEFILE_DELAY_UNTIL_REBOOT 4
#define MOVEFILE_WRITE_THROUGH 8
#define MAXIMUM_WAIT_OBJECTS 64
#define MAXIMUM_SUSPEND_COUNT 0x7F
#define WAIT_OBJECT_0 0
#define WAIT_ABANDONED_0 128
#ifndef WAIT_TIMEOUT /* also in winerror.h */
#define WAIT_TIMEOUT 258
#endif
#define WAIT_IO_COMPLETION 0xC0
#define WAIT_ABANDONED 128
#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
#define PURGE_TXABORT 1
#define PURGE_RXABORT 2
#define PURGE_TXCLEAR 4
#define PURGE_RXCLEAR 8
#define EVENTLOG_SUCCESS 0
#define EVENTLOG_FORWARDS_READ 4
#define EVENTLOG_BACKWARDS_READ 8
#define EVENTLOG_SEEK_READ 2
#define EVENTLOG_SEQUENTIAL_READ 1
#define EVENTLOG_ERROR_TYPE 1
#define EVENTLOG_WARNING_TYPE 2
#define EVENTLOG_INFORMATION_TYPE 4
#define EVENTLOG_AUDIT_SUCCESS 8
#define EVENTLOG_AUDIT_FAILURE 16
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 256
#define FORMAT_MESSAGE_IGNORE_INSERTS 512
#define FORMAT_MESSAGE_FROM_STRING 1024
#define FORMAT_MESSAGE_FROM_HMODULE 2048
#define FORMAT_MESSAGE_FROM_SYSTEM 4096
#define FORMAT_MESSAGE_ARGUMENT_ARRAY 8192
#define FORMAT_MESSAGE_MAX_WIDTH_MASK 255
#define EV_BREAK 64
#define EV_CTS 8
#define EV_DSR 16
#define EV_ERR 128
#define EV_EVENT1 2048
#define EV_EVENT2 4096
#define EV_PERR 512
#define EV_RING 256
#define EV_RLSD 32
#define EV_RX80FULL 1024
#define EV_RXCHAR 1
#define EV_RXFLAG 2
#define EV_TXEMPTY 4
/* also in ddk/ntapi.h */
/* To restore default error mode, call SetErrorMode (0).  */ 
#define SEM_FAILCRITICALERRORS		0x0001
#define SEM_NOGPFAULTERRORBOX		0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT	0x0004
#define SEM_NOOPENFILEERRORBOX		0x8000
/* end ntapi.h */
#define SLE_ERROR 1
#define SLE_MINORERROR 2
#define SLE_WARNING 3
#define SHUTDOWN_NORETRY 1
#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_EXECUTION (-1)
#define EXCEPTION_CONTINUE_SEARCH 0
#define MAXINTATOM 0xC000
#define INVALID_ATOM ((ATOM)0)
#define IGNORE	0
#define INFINITE	0xFFFFFFFF
#define NOPARITY	0
#define ODDPARITY	1
#define EVENPARITY	2
#define MARKPARITY	3
#define SPACEPARITY	4
#define ONESTOPBIT	0
#define ONE5STOPBITS	1
#define TWOSTOPBITS	2
#define CBR_110	110
#define CBR_300	300
#define CBR_600	600
#define CBR_1200	1200
#define CBR_2400	2400
#define CBR_4800	4800
#define CBR_9600	9600
#define CBR_14400	14400
#define CBR_19200	19200
#define CBR_38400	38400
#define CBR_56000	56000
#define CBR_57600	57600
#define CBR_115200	115200
#define CBR_128000	128000
#define CBR_256000	256000
#define BACKUP_INVALID	0
#define BACKUP_DATA 1
#define BACKUP_EA_DATA 2
#define BACKUP_SECURITY_DATA 3
#define BACKUP_ALTERNATE_DATA 4
#define BACKUP_LINK 5
#define BACKUP_PROPERTY_DATA 6
#define BACKUP_OBJECT_ID 7
#define BACKUP_REPARSE_DATA 8
#define BACKUP_SPARSE_BLOCK 9
#define STREAM_NORMAL_ATTRIBUTE 0
#define STREAM_MODIFIED_WHEN_READ 1
#define STREAM_CONTAINS_SECURITY 2
#define STREAM_CONTAINS_PROPERTIES 4
#define STARTF_USESHOWWINDOW 1
#define STARTF_USESIZE 2
#define STARTF_USEPOSITION 4
#define STARTF_USECOUNTCHARS 8
#define STARTF_USEFILLATTRIBUTE 16
#define STARTF_RUNFULLSCREEN 32
#define STARTF_FORCEONFEEDBACK 64
#define STARTF_FORCEOFFFEEDBACK 128
#define STARTF_USESTDHANDLES 256
#define STARTF_USEHOTKEY 512
#define TC_NORMAL 0
#define TC_HARDERR 1
#define TC_GP_TRAP 2
#define TC_SIGNAL 3
#define AC_LINE_OFFLINE 0
#define AC_LINE_ONLINE 1
#define AC_LINE_BACKUP_POWER 2
#define AC_LINE_UNKNOWN 255
#define BATTERY_FLAG_HIGH 1
#define BATTERY_FLAG_LOW 2
#define BATTERY_FLAG_CRITICAL 4
#define BATTERY_FLAG_CHARGING 8
#define BATTERY_FLAG_NO_BATTERY 128
#define BATTERY_FLAG_UNKNOWN 255
#define BATTERY_PERCENTAGE_UNKNOWN 255
#define BATTERY_LIFE_UNKNOWN 0xFFFFFFFF
#define DDD_RAW_TARGET_PATH 1
#define DDD_REMOVE_DEFINITION 2
#define DDD_EXACT_MATCH_ON_REMOVE 4
#define HINSTANCE_ERROR 32
#define MS_CTS_ON 16
#define MS_DSR_ON 32
#define MS_RING_ON 64
#define MS_RLSD_ON 128
#define DTR_CONTROL_DISABLE 0
#define DTR_CONTROL_ENABLE 1
#define DTR_CONTROL_HANDSHAKE 2
#define RTS_CONTROL_DISABLE 0
#define RTS_CONTROL_ENABLE 1
#define RTS_CONTROL_HANDSHAKE 2
#define RTS_CONTROL_TOGGLE 3
#define SECURITY_ANONYMOUS (SecurityAnonymous<<16)
#define SECURITY_IDENTIFICATION (SecurityIdentification<<16)
#define SECURITY_IMPERSONATION (SecurityImpersonation<<16)
#define SECURITY_DELEGATION (SecurityDelegation<<16)
#define SECURITY_CONTEXT_TRACKING 0x40000
#define SECURITY_EFFECTIVE_ONLY 0x80000
#define SECURITY_SQOS_PRESENT 0x100000
#define SECURITY_VALID_SQOS_FLAGS 0x1F0000
#define INVALID_FILE_SIZE 0xFFFFFFFF
#define TLS_OUT_OF_INDEXES (DWORD)0xFFFFFFFF
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS 0x00000004
#define GET_MODULE_HANDLE_EX_FLAG_PIN 0x00000001
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT 0x00000002
#if (_WIN32_WINNT >= 0x0501)
#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x00000001
#define ACTCTX_FLAG_LANGID_VALID 0x00000002
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x00000004
#define ACTCTX_FLAG_RESOURCE_NAME_VALID 0x00000008
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT 0x00000010
#define ACTCTX_FLAG_APPLICATION_NAME_VALID 0x00000020
#define ACTCTX_FLAG_HMODULE_VALID 0x00000080
#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION 0x00000001
#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX 0x00000001
#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 0x00000004
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x00000008
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 0x00000010
#endif /* (_WIN32_WINNT >= 0x0501) */
#if (_WIN32_WINNT >= 0x0500)
#define REPLACEFILE_WRITE_THROUGH 0x00000001
#define REPLACEFILE_IGNORE_MERGE_ERRORS 0x00000002
#endif /* (_WIN32_WINNT >= 0x0500) */
#define WRITE_WATCH_FLAG_RESET 1
#if (_WIN32_WINNT >= 0x0601)
#define PROCESS_DEP_ENABLE 1
#define PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION 2
#endif
#if (_WIN32_WINNT >= 0x0600)
/* http://msdn.microsoft.com/en-us/library/aa363866%28VS.85%29.aspx */
#define SYMBOLIC_LINK_FLAG_DIRECTORY 0x1
/* http://msdn.microsoft.com/en-us/library/aa364962%28VS.85%29.aspx */
#define FILE_NAME_NORMALIZED 0x0
#define FILE_NAME_OPENED 0x8
#define VOLUME_NAME_DOS 0x0
#define VOLUME_NAME_GUID 0x1
#define VOLUME_NAME_NONE 0x4
#define VOLUME_NAME_NT 0x2
#endif /* (_WIN32_WINNT >= 0x0600) */

#ifndef RC_INVOKED
/**
 * This structure is a 64-bit value representing the number of
 * 100-nanosecond intervals since January 1, 1601.
 *
 * The FILETIME data structure is used in the time conversion functions
 * between MS-DOS and Win32.
 */
typedef struct _FILETIME {
	/**
	 * Specifies the low 32 bits of the Win32 date/time
	 * value.
	 */
	DWORD dwLowDateTime;
	/**
	 * Specifies the upper 32 bits of the Win32
	 * date/time value.
	 */
	DWORD dwHighDateTime;
} FILETIME,*PFILETIME,*LPFILETIME;
/**
 * This structure contains information retrieved by the
 * GetFileInformationByHandle function.
 */
typedef struct _BY_HANDLE_FILE_INFORMATION {
	/**
	 * Specifies file attributes. It can be one or
	 * more of the following values: Value Description
	 * FILE_ATTRIBUTE_ARCHIVE The file or directory is an archive file.
	 * Applications use this attribute to mark files for backup or
	 * removal. FILE_ATTRIBUTE_COMPRESSED The file or directory is
	 * compressed. For a file, this means that all of the data in the
	 * file is compressed. For a directory, this means that compression
	 * is the default for newly created files and subdirectories.
	 * FILE_ATTRIBUTE_DIRECTORY The handle identifies a directory.
	 * FILE_ATTRIBUTE_ENCRYPTED The file or directory is encrypted. For
	 * a file, this means that all of the data streams are encrypted.
	 * For a directory, this means that encryption is the default for
	 * newly created files and directories. FILE_ATTRIBUTE_HIDDEN The
	 * file or directory is hidden. It is not included in an ordinary
	 * directory listing. FILE_ATTRIBUTE_INROM This file is an operating
	 * system file stored in ROM. These files are read-only; they cannot
	 * be modified. FILE_ATTRIBUTE_NORMAL The file has no other
	 * attributes. This attribute is valid only if used alone.
	 * FILE_ATTRIBUTE_OFFLINE The file data is not immediately
	 * available. Indicates that the file data has been physically moved
	 * to offline storage. FILE_ATTRIBUTE_READONLY The file or directory
	 * is read-only. Applications can read the file but cannot write to
	 * it or delete it. In the case of a directory, applications cannot
	 * delete it. FILE_ATTRIBUTE_REPARSE_POINT The file has an
	 * associated reparse point. FILE_ATTRIBUTE_ROMMODULE This file is
	 * an operating system file stored in ROM, designed to execute in
	 * place. In other words, code from this file is executed directly
	 * from ROM, rather than being first copied to RAM. The CreateFile
	 * function cannot be used to access this file, instead the
	 * LoadLibrary and CreateProcess functions must be used.
	 * FILE_ATTRIBUTE_ROMSTATICREF The DLL module is statically linked
	 * to another module in the ROM file system. This prevents the DLL
	 * module from being replaced by a RAM version of the DLL.
	 * FILE_ATTRIBUTE_SPARSE_FILE The file is a sparse file.
	 * FILE_ATTRIBUTE_SYSTEM The file or directory is part of the
	 * operating system or is used exclusively by the operating system.
	 * FILE_ATTRIBUTE_TEMPORARY The file is being used for temporary
	 * storage. File systems attempt to keep all the data in memory for
	 * quicker access, rather than flushing the data back to mass
	 * storage. A temporary file should be deleted by the application as
	 * soon as it is no longer needed.
	 */
	DWORD	dwFileAttributes;
	/**
	 * Specifies the time the file was created. If the
	 * underlying file system does not support this time member,
	 * ftCreationTime is zero.
	 */
	FILETIME	ftCreationTime;
	/**
	 * Specifies the time the file was last accessed.
	 * If the underlying file system does not support this time member,
	 * ftLastAccessTime is zero.
	 */
	FILETIME	ftLastAccessTime;
	/**
	 * Specifies the last time the file was written to.
	 */
	FILETIME	ftLastWriteTime;
	/**
	 * Specifies the serial number of the volume
	 * that contains the file.
	 */
	DWORD	dwVolumeSerialNumber;
	/**
	 * Specifies the high-order word of the file size.
	 */
	DWORD	nFileSizeHigh;
	/**
	 * Specifies the low-order word of the file size.
	 */
	DWORD	nFileSizeLow;
	/**
	 * Specifies the number of links to this file. For
	 * the FAT file system this member is always 1. For NTFS, it may be
	 * more than 1.
	 */
	DWORD	nNumberOfLinks;
	/**
	 * Specifies the high-order word of a unique
	 * identifier associated with the file.
	 */
	DWORD	nFileIndexHigh;
	/**
	 * Specifies the low-order word of a unique
	 * identifier associated with the file. This identifier and the
	 * volume serial number uniquely identify a file. This number may
	 * change when the system is restarted or when the file is opened.
	 * After a process opens a file, the identifier is constant until
	 * the file is closed. An application can use this identifier and
	 * the volume serial number to determine whether two handles refer
	 * to the same file.
	 */
	DWORD	nFileIndexLow;
#ifdef _WIN32_WCE
	DWORD	dwOID;
#endif
} BY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;
#if (_WIN32_WINNT >= 0x0600)
/* http://msdn.microsoft.com/en-us/library/aa364217%28VS.85%29.aspx */
typedef struct _FILE_BASIC_INFO {
	LARGE_INTEGER	CreationTime;
	LARGE_INTEGER	LastAccessTime;
	LARGE_INTEGER	LastWriteTime;
	LARGE_INTEGER	ChangeTime;
	DWORD	FileAttributes;
} FILE_BASIC_INFO,*PFILE_BASIC_INFO,*LPFILE_BASIC_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364401%28VS.85%29.aspx */
typedef struct _FILE_STANDARD_INFO {
	LARGE_INTEGER	AllocationSize;
	LARGE_INTEGER	EndOfFile;
	DWORD	NumberOfLinks;
	BOOL	DeletePending;
	BOOL	Directory;
} FILE_STANDARD_INFO,*PFILE_STANDARD_INFO,*LPFILE_STANDARD_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364388%28v=VS.85%29.aspx */
typedef struct _FILE_NAME_INFO {
	DWORD	FileNameLength;
	WCHAR	FileName[1];
} FILE_NAME_INFO,*PFILE_NAME_INFO,*LPFILE_NAME_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364406%28v=VS.85%29.aspx */
typedef struct _FILE_STREAM_INFO {
	DWORD	NextEntryOffset;
	DWORD	StreamNameLength;
	LARGE_INTEGER	StreamSize;
	LARGE_INTEGER	StreamAllocationSize;
	WCHAR	StreamName[1];
} FILE_STREAM_INFO,*PFILE_STREAM_INFO,*LPFILE_STREAM_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364220%28v=VS.85%29.aspx */
typedef struct _FILE_COMPRESSION_INFO {
	LARGE_INTEGER	CompressedFileSize;
	WORD	CompressionFormat;
	UCHAR	CompressionUnitShift;
	UCHAR	ChunkShift;
	UCHAR	ClusterShift;
	UCHAR	Reserved[3];
} FILE_COMPRESSION_INFO,*PFILE_COMPRESSION_INFO,*LPFILE_COMPRESSION_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364216%28v=VS.85%29.aspx */
typedef struct _FILE_ATTRIBUTE_TAG_INFO {
	DWORD	FileAttributes;
	DWORD	ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO,*PFILE_ATTRIBUTE_TAG_INFO,*LPFILE_ATTRIBUTE_TAG_INFO;
/* http://msdn.microsoft.com/en-us/library/aa364226%28v=VS.85%29.aspx */
typedef struct _FILE_ID_BOTH_DIR_INFO {
	DWORD	NextEntryOffset;
	DWORD	FileIndex;
	LARGE_INTEGER	CreationTime;
	LARGE_INTEGER	LastAccessTime;
	LARGE_INTEGER	LastWriteTime;
	LARGE_INTEGER	ChangeTime;
	LARGE_INTEGER	EndOfFile;
	LARGE_INTEGER	AllocationSize;
	DWORD	FileAttributes;
	DWORD	FileNameLength;
	DWORD	EaSize;
	CCHAR	ShortNameLength;
	WCHAR	ShortName[12];
	LARGE_INTEGER	FileId;
	WCHAR	FileName[1];
} FILE_ID_BOTH_DIR_INFO,*PFILE_ID_BOTH_DIR_INFO,*LPFILE_ID_BOTH_DIR_INFO;
/* http://msdn.microsoft.com/en-us/library/dd979524%28v=VS.85%29.aspx */
typedef struct _FILE_REMOTE_PROTOCOL_INFO {
	USHORT StructureVersion;
	USHORT StructureSize;
	ULONG  Protocol;
	USHORT ProtocolMajorVersion;
	USHORT ProtocolMinorVersion;
	USHORT ProtocolRevision;
	USHORT Reserved;
	ULONG  Flags;
	struct {
		ULONG	Reserved[8];
	} GenericReserved;
	struct {
		ULONG	Reserved[16];
	} ProtocolSpecificReserved;
} FILE_REMOTE_PROTOCOL_INFO,*PFILE_REMOTE_PROTOCOL_INFO,*LPFILE_REMOTE_PROTOCOL_INFO;
#endif /* (_WIN32_WINNT >= 0x0600) */
/**
 * This structure defines the control setting for a serial communications
 * device.
 *
 * For device driver developers: the COM_Open function in the sample serial
 * port MDD driver does not support the fErrorChar, fNull, and fAbortOnChar
 * members of the DCB structure. You are expected to add support for this
 * functionality in your PDD layer, if appropriate for your serial port
 * hardware.
 *
 * The sample serial port MDD driver is found in
 * Public\Common\Oak\Drivers\Serial.
 */
typedef struct _DCB {
	/**
	 * Specifies the DCB structure length, in bytes.
	 */
	DWORD DCBlength;
	/**
	 * Specifies the baud rate at which the communication
	 * device operates. It is an actual baud rate value, or one of the
	 * following baud rate indexes: CBR_110 CBR_19200 CBR_300 CBR_38400
	 * CBR_600 CBR_56000 CBR_1200 CBR_57600 CBR_2400 CBR_115200 CBR_4800
	 * CBR_128000 CBR_9600 CBR_256000 CBR_14400
	 */
	DWORD BaudRate;
	/**
	 * Specifies if binary mode is enabled. The Win32 API does
	 * not support nonbinary mode transfers, so this member must be
	 * TRUE. Using FALSE will not work.
	 */
	DWORD fBinary:1;
	/**
	 * Specifies if parity checking is enabled. If this member
	 * is TRUE, parity checking is performed and errors are reported.
	 */
	DWORD fParity:1;
	/**
	 * Specifies if the CTS (clear-to-send) signal is
	 * monitored for output flow control. If this member is TRUE and CTS
	 * is turned off, output is suspended until CTS is sent again.
	 */
	DWORD fOutxCtsFlow:1;
	/**
	 * Specifies if the DSR (data-set-ready) signal is
	 * monitored for output flow control. If this member is TRUE and DSR
	 * is turned off, output is suspended until DSR is sent again.
	 */
	DWORD fOutxDsrFlow:1;
	/**
	 * Specifies the DTR (data-terminal-ready) flow
	 * control. This member can be one of the following values: Value
	 * Description DTR_CONTROL_DISABLE Disables the DTR line when the
	 * device is opened and leaves it disabled. DTR_CONTROL_ENABLE
	 * Enables the DTR line when the device is opened and leaves it on.
	 * DTR_CONTROL_HANDSHAKE Enables DTR handshaking. If handshaking is
	 * enabled, it is an error for the application to adjust the line by
	 * using the EscapeCommFunction function.
	 */
	DWORD fDtrControl:2;
	/**
	 * Specifies if the communications driver is
	 * sensitive to the state of the DSR signal. If this member is TRUE,
	 * the driver ignores any bytes received, unless the DSR modem input
	 * line is high.
	 */
	DWORD fDsrSensitivity:1;
	/**
	 * Specifies if transmission stops when the input
	 * buffer is full and the driver has transmitted the XoffChar
	 * character. If this member is TRUE, transmission continues after
	 * the input buffer has come within XoffLim bytes of being full and
	 * the driver has transmitted the XoffChar character to stop
	 * receiving bytes. If this member is FALSE, transmission does not
	 * continue until the input buffer is within XonLim bytes of being
	 * empty and the driver has transmitted the XonChar character to
	 * resume reception.
	 */
	DWORD fTXContinueOnXoff:1;
	/**
	 * Specifies if XON/XOFF flow control is used during
	 * transmission. If this member is TRUE, transmission stops when the
	 * XoffChar character is received and starts again when the XonChar
	 * character is received.
	 */
	DWORD fOutX:1;
	/**
	 * Specifies if XON/XOFF flow control is used during
	 * reception. If this member is TRUE, the XoffChar character is sent
	 * when the input buffer comes within XoffLim bytes of being full,
	 * and the XonChar character is sent when the input buffer comes
	 * within XonLim bytes of being empty.
	 */
	DWORD fInX:1;
	/**
	 * Specifies if bytes received with parity errors are
	 * replaced with the character specified by the ErrorChar member. If
	 * this member is TRUE and the fParity member is TRUE, replacement
	 * occurs.
	 */
	DWORD fErrorChar:1;
	/**
	 * Specifies if null bytes are discarded. If this member is
	 * TRUE, null bytes are discarded when received.
	 */
	DWORD fNull:1;
	/**
	 * Specifies the RTS (request-to-send) flow control. If
	 * this value is zero, the default is RTS_CONTROL_HANDSHAKE. This
	 * member can be one of the following values: Value Description
	 * RTS_CONTROL_DISABLE Disables the RTS line when the device is
	 * opened and leaves it disabled. RTS_CONTROL_ENABLE Enables the RTS
	 * line when the device is opened and leaves it on.
	 * RTS_CONTROL_HANDSHAKE Enables RTS handshaking. The driver raises
	 * the RTS line when the "type-ahead" (input) buffer is less than
	 * one-half full and lowers the RTS line when the buffer is more
	 * than three-quarters full. If handshaking is enabled, it is an
	 * error for the application to adjust the line by using the
	 * EscapeCommFunction function. RTS_CONTROL_TOGGLE Specifies that
	 * the RTS line will be high if bytes are available for
	 * transmission. After all buffered bytes have been sent, the RTS
	 * line will be low.
	 */
	DWORD fRtsControl:2;
	/**
	 * Specifies if read and write operations are
	 * terminated if an error occurs. If this member is TRUE, the driver
	 * terminates all read and write operations with an error status if
	 * an error occurs. The driver will not accept any further
	 * communications operations until the application has acknowledged
	 * the error by calling the ClearCommError function.
	 */
	DWORD fAbortOnError:1;
	/**
	 * Reserved; do not use.
	 */
	DWORD fDummy2:17;
	/**
	 * Not used; set to zero.
	 */
	WORD wReserved;
	/**
	 * Specifies the minimum number of bytes accepted in the
	 * input buffer before the XON character is sent.
	 */
	WORD XonLim;
	/**
	 * Specifies the maximum number of bytes accepted in the
	 * input buffer before the XOFF character is sent. The maximum
	 * number of bytes accepted is calculated by subtracting this value
	 * from the size, in bytes, of the input buffer.
	 */
	WORD XoffLim;
	/**
	 * Specifies the number of bits in the bytes transmitted
	 * and received.
	 */
	BYTE ByteSize;
	/**
	 * Specifies the parity scheme to be used. It is one of the
	 * following values: Value Description EVENPARITY Even MARKPARITY
	 * Mark NOPARITY No parity ODDPARITY Odd SPACEPARITY Space
	 */
	BYTE Parity;
	/**
	 * Specifies the number of stop bits to be used. It is one
	 * of the following values: Value Description ONESTOPBIT 1 stop bit
	 * ONE5STOPBITS 1.5 stop bits TWOSTOPBITS 2 stop bits
	 */
	BYTE StopBits;
	/**
	 * Specifies the value of the XON character for both
	 * transmission and reception.
	 */
	char XonChar;
	/**
	 * Specifies the value of the XOFF character for both
	 * transmission and reception.
	 */
	char XoffChar;
	/**
	 * Specifies the value of the character used to replace
	 * bytes received with a parity error.
	 */
	char ErrorChar;
	/**
	 * Specifies the value of the character used to signal the
	 * end of data.
	 */
	char EofChar;
	/**
	 * Specifies the value of the character used to signal an
	 * event.
	 */
	char EvtChar;
	/**
	 * Reserved; do not use.
	 */
	WORD wReserved1;
} DCB,*LPDCB;
typedef struct _COMM_CONFIG {
	DWORD dwSize;
	WORD  wVersion;
	WORD  wReserved;
	DCB   dcb;
	DWORD dwProviderSubType;
	DWORD dwProviderOffset;
	DWORD dwProviderSize;
	WCHAR wcProviderData[1];
} COMMCONFIG,*LPCOMMCONFIG;
/**
 * This structure is used by the GetCommProperties function to return
 * specific communication support driver data.
 *
 * The contents of the dwProvSpec1, dwProvSpec2, and wcProvChar members
 * depend on the provider subtype; this is specified by the dwProvSubType
 * member.
 *
 * If the provider subtype is PST_MODEM, these members are used as follows:
 *
 * Value Description dwProvSpec1 Not used dwProvSpec2 Not used wcProvChar
 * Contains a MODEMDEVCAPS structure
 */
typedef struct _COMMPROP {
	/**
	 * Specifies the size, in bytes, of the entire data
	 * packet, regardless of the amount of data requested.
	 */
	WORD	wPacketLength;
	/**
	 * Specifies the version of the structure.
	 */
	WORD	wPacketVersion;
	/**
	 * Specifies a bitmask indicating which services are
	 * implemented by this provider. The SP_SERIALCOMM value is always
	 * specified for communications providers, including modem
	 * providers.
	 */
	DWORD	dwServiceMask;
	/**
	 * Reserved; do not use.
	 */
	DWORD	dwReserved1;
	/**
	 * Specifies the maximum size, in bytes, of the
	 * driver's internal output buffer. A value of zero indicates that
	 * no maximum value is imposed by the serial provider.
	 */
	DWORD	dwMaxTxQueue;
	/**
	 * Specifies the maximum size, in bytes, of the
	 * driver's internal input buffer. A value of zero indicates that no
	 * maximum value is imposed by the serial provider.
	 */
	DWORD	dwMaxRxQueue;
	/**
	 * Specifies the maximum acceptable baud rate, in bits
	 * per second (bps). It is one of the following values: Value
	 * Description BAUD_075 75 bps BAUD_110 110 bps BAUD_134_5 134.5 bps
	 * BAUD_150 150 bps BAUD_300 300 bps BAUD_600 600 bps BAUD_1200 1200
	 * bps BAUD_1800 1800 bps BAUD_2400 2400 bps BAUD_4800 4800 bps
	 * BAUD_7200 7200 bps BAUD_9600 9600 bps BAUD_14400 14400 bps
	 * BAUD_19200 19200 bps BAUD_38400 38400 bps BAUD_56K 56K bps
	 * BAUD_57600 57600 bps BAUD_115200 115200 bps BAUD_128K 128K bps
	 * BAUD_USER Programmable baud rates available
	 */
	DWORD	dwMaxBaud;
	/**
	 * Specifies the specific communications provider
	 * type. It is one of the following values: Value Description
	 * PST_FAX FAX device PST_LAT LAT protocol PST_MODEM Modem device
	 * PST_NETWORK_BRIDGE Unspecified network bridge PST_PARALLELPORT
	 * Parallel port PST_RS232 RS-232 serial port PST_RS422 RS-422 port
	 * PST_RS423 RS-423 port PST_RS449 RS-449 port PST_SCANNER Scanner
	 * device PST_TCPIP_TELNET TCP/IP Telnet(R) protocol PST_UNSPECIFIED
	 * Unspecified PST_X25 X.25 standards
	 */
	DWORD	dwProvSubType;
	/**
	 * Indicates the capabilities offered by the
	 * provider. It is one of the following values: Value Description
	 * PCF_16BITMODE Special 16-bit mode is supported. PCF_DTRDSR DTR
	 * (Data Terminal Ready) and DSR (Data Set Ready) are supported.
	 * PCF_INTTIMEOUTS Interval time-outs are supported.
	 * PCF_PARITY_CHECK Parity checking is supported. PCF_RLSD RLSD
	 * (Receive Line Signal Detect) is supported. PCF_RTSCTS RTS
	 * (Request to Send) and CTS (Clear to Send) are supported.
	 * PCF_SETXCHAR XON and XOFF are supported. PCF_SPECIALCHARS Special
	 * character support is provided. PCF_TOTALTIMEOUTS Total, elapsed,
	 * time-outs are supported. PCF_XONXOFF XON and XOFF flow control
	 * are supported.
	 */
	DWORD	dwProvCapabilities;
	/**
	 * Indicates the communication parameter that can
	 * be changed. It is one of the following values: Value Description
	 * SP_BAUD Baud rate SP_DATABITS Data bits SP_HANDSHAKING
	 * Handshaking (flow control) SP_PARITY Parity SP_PARITY_CHECK
	 * Parity checking SP_RLSD Receive Line Signal Detect SP_STOPBITS
	 * Stop bits
	 */
	DWORD	dwSettableParams;
	/**
	 * Indicates the baud rates that can be used. For
	 * values, see the dwMaxBaud member.
	 */
	DWORD	dwSettableBaud;
	/**
	 * Indicates the number of data bits that can be set.
	 * It is one of the following values: Value Description DATABITS_5 5
	 * data bits DATABITS_6 6 data bits DATABITS_7 7 data bits
	 * DATABITS_8 8 data bits DATABITS_16 16 data bits DATABITS_16X
	 * Special wide path through serial hardware lines
	 */
	WORD	wSettableData;
	/**
	 * Indicates the stop bit and parity settings
	 * that can be selected. It is one of the following values: Value
	 * Description PARITY_EVEN Even parity PARITY_MARK Mark parity
	 * PARITY_NONE No parity PARITY_ODD Odd parity PARITY_SPACE Space
	 * parity STOPBITS_10 1 stop bit STOPBITS_15 1.5 stop bits
	 * STOPBITS_20 2 stop bits
	 */
	WORD	wSettableStopParity;
	/**
	 * Specifies the size, in bytes, of the driver's
	 * internal output buffer. A value of zero indicates that the value
	 * is unavailable.
	 */
	DWORD	dwCurrentTxQueue;
	/**
	 * Specifies the size, in bytes, of the driver's
	 * internal input buffer. A value of zero indicates that the value
	 * is unavailable.
	 */
	DWORD	dwCurrentRxQueue;
	/**
	 * Specifies provider-specific data. Applications
	 * should ignore this member unless specific data about the data
	 * format required by the provider is available. Set this member to
	 * COMMPROP_INITIALIZED before calling the GetCommProperties
	 * function to indicate that the wPacketLength member is already
	 * valid.
	 */
	DWORD	dwProvSpec1;
	/**
	 * Specifies provider-specific data. Applications
	 * should ignore this member unless specific data about the data
	 * format required by the provider is available.
	 */
	DWORD	dwProvSpec2;
	/**
	 * Specifies provider-specific data. Applications should
	 * ignore this member unless specific data about the data format
	 * required by the provider is available.
	 */
	WCHAR	wcProvChar[1];
} COMMPROP,*LPCOMMPROP;
/**
 * This structure is used in the SetCommTimeouts and GetCommTimeouts
 * functions to set and query the time-out parameters for a communication
 * device. The parameters determine the behavior of the ReadFile and
 * WriteFile function operations on the device.
 *
 * If an application sets ReadIntervalTimeout and
 * ReadTotalTimeoutMultiplier to MAXDWORD and sets ReadTotalTimeoutConstant
 * to a value greater than zero and less than MAXDWORD, one of the
 * following occurs when the ReadFile function is called:
 *
 * If there are any characters in the input buffer, ReadFile returns
 * immediately with the characters in the buffer.
 *
 * If there are no characters in the input buffer, ReadFile waits until a
 * character arrives and then returns immediately.
 *
 * If no characters arrive within the time specified by
 * ReadTotalTimeoutConstant, ReadFile times out.
 */
typedef struct _COMMTIMEOUTS {
	/**
	 * Specifies the maximum acceptable time, in
	 * milliseconds, to elapse between the arrival of two characters on
	 * the communication line. During a ReadFile operation, the time
	 * period begins when the first character is received. If the
	 * interval between the arrival of any two characters exceeds this
	 * amount, the ReadFile operation is completed and any buffered data
	 * is returned. A value of zero indicates that interval time-outs
	 * are not used.
	 */
	DWORD ReadIntervalTimeout;
	/**
	 * Specifies the multiplier, in
	 * milliseconds, used to calculate the total time-out period for
	 * read operations. For each read operation, this value is
	 * multiplied by the requested number of bytes to be read.
	 */
	DWORD ReadTotalTimeoutMultiplier;
	/**
	 * Specifies the constant, in
	 * milliseconds, used to calculate the total time-out period for
	 * read operations. For each read operation, this value is added to
	 * the product of the ReadTotalTimeoutMultiplier member and the
	 * requested number of bytes. A value of zero for both the
	 * ReadTotalTimeoutMultiplier and ReadTotalTimeoutConstant members
	 * indicates that total time-outs are not used for read operations.
	 */
	DWORD ReadTotalTimeoutConstant;
	/**
	 * Specifies the multiplier, in
	 * milliseconds, used to calculate the total time-out period for
	 * write operations. For each write operation, this value is
	 * multiplied by the number of bytes to be written.
	 */
	DWORD WriteTotalTimeoutMultiplier;
	/**
	 * Specifies the constant, in
	 * milliseconds, used to calculate the total time-out period for
	 * write operations. For each write operation, this value is added
	 * to the product of the WriteTotalTimeoutMultiplier member and the
	 * number of bytes to be written. A value of zero for both the
	 * WriteTotalTimeoutMultiplier and WriteTotalTimeoutConstant members
	 * indicates that total time-outs are not used for write operations.
	 */
	DWORD WriteTotalTimeoutConstant;
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;
/**
 * This structure contains communication device data. This structure is
 * filled by the ClearCommError function.
 */
typedef struct _COMSTAT {
	/**
	 * Specifies if the transmission is waiting to receive the
	 * CTS (Clear to Send) signal. If this member is TRUE, the
	 * transmission is waiting.
	 */
	DWORD fCtsHold:1;
	/**
	 * Specifies if the transmission is waiting to receive the
	 * DSR (Data Set Ready) signal. If this member is TRUE, the
	 * transmission is waiting.
	 */
	DWORD fDsrHold:1;
	/**
	 * Specifies if the transmission is waiting to receive
	 * the RLSD (Receive Line Signal Detect) signal. If this member is
	 * TRUE, the transmission is waiting.
	 */
	DWORD fRlsdHold:1;
	/**
	 * Specifies if the transmission is waiting because the
	 * XOFF character was received. If this member is TRUE, the
	 * transmission is waiting.
	 */
	DWORD fXoffHold:1;
	/**
	 * Specifies if the transmission is waiting because the
	 * XOFF character was transmitted. If this member is TRUE, the
	 * transmission is waiting. Transmission halts when the XOFF
	 * character is transmitted to a system that takes the next
	 * character as XON, regardless of the actual character.
	 */
	DWORD fXoffSent:1;
	/**
	 * Specifies if the End of File (EOF) character has been
	 * received. If this member is TRUE, the EOF character has been
	 * received.
	 */
	DWORD fEof:1;
	/**
	 * If this member is TRUE, there is a character queued for
	 * transmission that has come to the communication device by way of
	 * the TransmitCommChar function. The communication device transmits
	 * such a character ahead of other characters in the device's output
	 * buffer.
	 */
	DWORD fTxim:1;
	/**
	 * Reserved; do not use.
	 */
	DWORD fReserved:25;
	/**
	 * Specifies the number of bytes received by the serial
	 * provider, but not yet read by a ReadFile operation.
	 */
	DWORD cbInQue;
	/**
	 * Specifies the number of bytes of user data remaining to
	 * be transmitted for all write operations. This value will be zero
	 * for a nonoverlapped write.
	 */
	DWORD cbOutQue;
} COMSTAT,*LPCOMSTAT;
typedef DWORD (WINAPI *LPTHREAD_START_ROUTINE)(LPVOID);
/**
 * This structure contains process creation information that can be used by
 * a debugger.
 *
 * The lpImageName member is a pointer into the address space of the
 * process that is being debugged. To retrieve the actual image name, use
 * the ReadProcessMemory function in the following manner.
 *
 *     ReadProcessMemory( hProcess, lpImageName, lpBuffer, nSize,
 *        &NumberOfBytesRead );
 *
 * For the DebugActiveProcess function, if the dwDebugEventCode member of
 * the DEBUG_EVENT structure has a value of CREATE_PROCESS_DEBUG_EVENT or
 * CREATE_THREAD_DEBUG_EVENT, the lpStartAddress member is NULL.
 *
 * The lpThreadLocalBase member points directly to the Thread Local Storage
 * (TLS) data block of the process that is being debugged. To obtain the
 * TLS data for a slot, call the ReadProcessMemory function and pass the
 * following calculated value for the lpBaseAddress parameter:
 * lpThreadLocalBase+4*<slot number>.
 */
typedef struct _CREATE_PROCESS_DEBUG_INFO {
	/**
	 * Handle to the process's image file. In Windows CE, this
	 * member is always NULL.
	 */
	HANDLE hFile;
	/**
	 * Handle to the process. If this member is NULL, the
	 * handle is not valid. Otherwise, the debugger can use the member
	 * to read from and write to the process's memory.
	 */
	HANDLE hProcess;
	/**
	 * Handle to the initial thread of the process identified
	 * by the hProcess member. If hThread is NULL, the handle is not
	 * valid. Otherwise, the debugger has THREAD_GET_CONTEXT,
	 * THREAD_SET_CONTEXT, and THREAD_SUSPEND_RESUME access to the
	 * thread, allowing the debugger to read from and write to the
	 * registers of the thread and to control execution of the thread.
	 */
	HANDLE hThread;
	/**
	 * Pointer to the base address of the executable
	 * image that the process is running.
	 */
	LPVOID lpBaseOfImage;
	/**
	 * Specifies the offset to the debugging
	 * information in the file identified by the hFile member. This
	 * member is always set to zero.
	 */
	DWORD dwDebugInfoFileOffset;
	/**
	 * Specifies the size, in bytes, of the debugging
	 * information in the file. This member is always set to zero.
	 */
	DWORD nDebugInfoSize;
	/**
	 * Pointer to a block of data. At offset 0x2C
	 * into this block is another pointer, called
	 * ThreadLocalStoragePointer, that points to an array of per-module
	 * thread local storage blocks. This gives a debugger access to
	 * per-thread data in the threads of the process being debugged
	 * using the same algorithms that a compiler would use.
	 */
	LPVOID lpThreadLocalBase;
	/**
	 * Pointer to the starting address of the thread.
	 * This value may only be an approximation of the thread's starting
	 * address, because any application with appropriate access to the
	 * thread can change the thread's context by using the
	 * SetThreadContext function.
	 */
	LPTHREAD_START_ROUTINE lpStartAddress;
	/**
	 * Pointer to the file name associated with the hFile
	 * member. This member may be NULL, or it may contain the address of
	 * a string pointer in the address space of the process being
	 * debugged. That address may, in turn, either be NULL or point to
	 * the actual filename. If fUnicode is a nonzero value, the name
	 * string is Unicode; otherwise, it is ANSI. This member is strictly
	 * optional. Debuggers must be prepared to handle the case where
	 * lpImageName is NULL or *lpImageName (in the address space of the
	 * process being debugged) is NULL. Specifically, the system does
	 * not provide an image name for a create process event, and will
	 * not likely pass an image name for the first DLL event. The system
	 * also does not provide this information in the case of debug
	 * events that originate from a call to the DebugActiveProcess
	 * function.
	 */
	LPVOID lpImageName;
	/**
	 * Indicates whether a file name specified by the
	 * lpImageName member is Unicode or ANSI. A nonzero value indicates
	 * Unicode; zero indicates ANSI.
	 */
	WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;
/**
 * This structure contains thread-creation information that can be used by
 * a debugger.
 */
typedef struct _CREATE_THREAD_DEBUG_INFO {
	/**
	 * Handle to the thread whose creation caused the debugging
	 * event. If this member is NULL, the handle is not valid.
	 * Otherwise, the debugger has THREAD_GET_CONTEXT,
	 * THREAD_SET_CONTEXT, and THREAD_SUSPEND_RESUME access to the
	 * thread, allowing the debugger to read from and write to the
	 * registers of the thread and control execution of the thread.
	 */
	HANDLE hThread;
	/**
	 * Pointer to a block of data. At offset 0x2C
	 * into this block is another pointer, called
	 * ThreadLocalStoragePointer, that points to an array of per-module
	 * thread local storage blocks. This gives a debugger access to
	 * per-thread data in the threads of the process being debugged
	 * using the same algorithms that a compiler would use.
	 */
	LPVOID lpThreadLocalBase;
	/**
	 * Pointer to the starting address of the thread.
	 * This value may only be an approximation of the thread's starting
	 * address, because any application with appropriate access to the
	 * thread can change the thread's context by using the
	 * SetThreadContext function.
	 */
	LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;
/**
 * This structure contains exception information that can be used by a
 * debugger.
 */
typedef struct _EXCEPTION_DEBUG_INFO {
	/**
	 * Contains an EXCEPTION_RECORD structure with
	 * information specific to the exception. This includes the
	 * exception code, flags, address, a pointer to a related exception,
	 * extra parameters, and so on.
	 */
	EXCEPTION_RECORD ExceptionRecord;
	/**
	 * Indicates whether the debugger has previously
	 * encountered the exception specified by the ExceptionRecord
	 * member. If the dwFirstChance member is nonzero, this is the first
	 * time the debugger has encountered the exception. Debuggers
	 * typically handle breakpoint and single-step exceptions when they
	 * are first encountered. If this member is zero, the debugger has
	 * previously encountered the exception. This occurs only if, during
	 * the search for structured exception handlers, either no handler
	 * was found or the exception was continued.
	 */
	DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;
/**
 * This structure contains an exiting thread's exit code.
 */
typedef struct _EXIT_THREAD_DEBUG_INFO {
	/**
	 * Specifies the exit code for the thread.
	 */
	DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;
/**
 * This structure contains an exiting process's exit code.
 */
typedef struct _EXIT_PROCESS_DEBUG_INFO {
	/**
	 * Specifies the exit code for the process.
	 */
	DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;
/**
 * This structure contains information about a dynamic-link library (DLL)
 * that has just been loaded.
 */
typedef struct _LOAD_DLL_DEBUG_INFO {
	/**
	 * Ignored. Set to NULL.
	 */
	HANDLE hFile;
	/**
	 * Long pointer to the base address of the DLL in the
	 * address space of the process loading the DLL.
	 */
	LPVOID lpBaseOfDll;
	/**
	 * Ignored. Must be 0.
	 */
	DWORD dwDebugInfoFileOffset;
	/**
	 * Ignored. Must be 0.
	 */
	DWORD nDebugInfoSize;
	/**
	 * Long pointer to the address space of the process
	 * that is being debugged. Use the ReadProcessMemory function to
	 * retrieve the actual image name. This member is strictly optional.
	 * Debuggers must be prepared to handle the case where lpImageName
	 * is NULL or *lpImageName (in the address space of the process
	 * being debugged) is NULL. Specifically, the system will never
	 * provide an image name for a create process event, and it will not
	 * likely pass an image name for the first DLL event. The system
	 * will also never provide this information in the case of debugging
	 * events that originate from a call to the DebugActiveProcess
	 * function.
	 */
	LPVOID lpImageName;
	/**
	 * Indicates whether a filename specified by lpImageName
	 * is Unicode or ANSI. A nonzero value for this member indicates
	 * Unicode; zero indicates ANSI.
	 */
	WORD fUnicode;
} LOAD_DLL_DEBUG_INFO,*LPLOAD_DLL_DEBUG_INFO;
/**
 * This structure contains information about a dynamic-link library (DLL)
 * that has just been unloaded.
 */
typedef struct _UNLOAD_DLL_DEBUG_INFO {
	/**
	 * Long pointer to the base address of the DLL in the
	 * address space of the process unloading the DLL.
	 */
	LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;
/**
 * This structure contains the address, format, and length, in bytes, of a
 * debugging string.
 */
typedef struct _OUTPUT_DEBUG_STRING_INFO {
	/**
	 * Pointer to the debugging string in the calling
	 * process's address space. The debugger can use the
	 * ReadProcessMemory function to retrieve the value of the string.
	 */
	LPSTR lpDebugStringData;
	/**
	 * Specifies the format of the debugging string. If this
	 * member is zero, the debugging string is 8-bit ASCII; if it is
	 * nonzero, the string is 16-bit Unicode(TM).
	 */
	WORD fUnicode;
	/**
	 * Specifies the length, in bytes, of the
	 * debugging string. The length includes the string's terminating
	 * null character.
	 */
	WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;
typedef struct _RIP_INFO {
	DWORD dwError;
	DWORD dwType;
} RIP_INFO,*LPRIP_INFO;
/**
 * This structure describes a debugging event.
 *
 * If the WaitForDebugEvent function succeeds, it fills in the members of a
 * DEBUG_EVENT structure.
 */
typedef struct _DEBUG_EVENT {
	/**
	 * Specifies a debugging event code that
	 * identifies the type of debugging event. It is one of the
	 * following values: Value Description EXCEPTION_DEBUG_EVENT Reports
	 * an exception debugging event. The value of u.Exception specifies
	 * an EXCEPTION_DEBUG_INFO structure. CREATE_THREAD_DEBUG_EVENT
	 * Reports a create-thread debugging event. The value of
	 * u.CreateThread specifies a CREATE_THREAD_DEBUG_INFO structure.
	 * CREATE_PROCESS_DEBUG_EVENT Reports a create-process debugging
	 * event. The value of u.CreateProcessInfo specifies a
	 * CREATE_PROCESS_DEBUG_INFO structure. EXIT_THREAD_DEBUG_EVENT
	 * Reports an exit-thread debugging event. The value of u.ExitThread
	 * specifies an EXIT_THREAD_DEBUG_INFO structure.
	 * EXIT_PROCESS_DEBUG_EVENT Reports an exit-process debugging event.
	 * The value of u.ExitProcess specifies an EXIT_PROCESS_DEBUG_INFO
	 * structure. LOAD_DLL_DEBUG_EVENT Reports a
	 * load-dynamic-link-library (DLL) debugging event. The value of
	 * u.LoadDll specifies a LOAD_DLL_DEBUG_INFO structure.
	 * UNLOAD_DLL_DEBUG_EVENT Reports an unload-DLL debugging event. The
	 * value of u.UnloadDll specifies an UNLOAD_DLL_DEBUG_INFO
	 * structure. OUTPUT_DEBUG_STRING_EVENT Reports an
	 * output-debugging-string debugging event. The value of
	 * u.DebugString specifies an OUTPUT_DEBUG_STRING_INFO structure.
	 */
	DWORD dwDebugEventCode;
	/**
	 * Specifies the identifier of the process in which the
	 * debugging event occurred. A debugger uses this value to locate
	 * the debugger's per-process structure. These values are not
	 * necessarily small integers that can be used as table indices.
	 */
	DWORD dwProcessId;
	/**
	 * Specifies the identifier of the thread in which the
	 * debugging event occurred. A debugger uses this value to locate
	 * the debugger's per-thread structure. These values are not
	 * necessarily small integers that can be used as table indices.
	 */
	DWORD dwThreadId;
	union {
		EXCEPTION_DEBUG_INFO Exception;
		CREATE_THREAD_DEBUG_INFO CreateThread;
		CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
		EXIT_THREAD_DEBUG_INFO ExitThread;
		EXIT_PROCESS_DEBUG_INFO ExitProcess;
		LOAD_DLL_DEBUG_INFO LoadDll;
		UNLOAD_DLL_DEBUG_INFO UnloadDll;
		OUTPUT_DEBUG_STRING_INFO DebugString;
		RIP_INFO RipInfo;
	/**
	 * Specifies additional information relating to the debugging
	 * event. This union takes on the type and value appropriate to the
	 * type of debugging event, as described in the dwDebugEventCode
	 * member.
	 */
	} u;
} DEBUG_EVENT,*LPDEBUG_EVENT;
typedef struct _OVERLAPPED {
	ULONG_PTR Internal;
	ULONG_PTR InternalHigh;
	union {
		struct {
	DWORD Offset;
	DWORD OffsetHigh;
	};
	PVOID Pointer;
	};
	HANDLE hEvent;
} OVERLAPPED,*POVERLAPPED,*LPOVERLAPPED;
typedef struct _STARTUPINFOA {
	DWORD	cb;
	LPSTR	lpReserved;
	LPSTR	lpDesktop;
	LPSTR	lpTitle;
	DWORD	dwX;
	DWORD	dwY;
	DWORD	dwXSize;
	DWORD	dwYSize;
	DWORD	dwXCountChars;
	DWORD	dwYCountChars;
	DWORD	dwFillAttribute;
	DWORD	dwFlags;
	WORD	wShowWindow;
	WORD	cbReserved2;
	PBYTE	lpReserved2;
	HANDLE	hStdInput;
	HANDLE	hStdOutput;
	HANDLE	hStdError;
} STARTUPINFOA,*LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
	DWORD	cb;
	LPWSTR	lpReserved;
	LPWSTR	lpDesktop;
	LPWSTR	lpTitle;
	DWORD	dwX;
	DWORD	dwY;
	DWORD	dwXSize;
	DWORD	dwYSize;
	DWORD	dwXCountChars;
	DWORD	dwYCountChars;
	DWORD	dwFillAttribute;
	DWORD	dwFlags;
	WORD	wShowWindow;
	WORD	cbReserved2;
	PBYTE	lpReserved2;
	HANDLE	hStdInput;
	HANDLE	hStdOutput;
	HANDLE	hStdError;
} STARTUPINFOW,*LPSTARTUPINFOW;
/**
 * This structure is filled in by the CreateProcess function with
 * information about a newly created process and its primary thread.
 */
typedef struct _PROCESS_INFORMATION {
	/**
	 * Returns a handle to the newly created process. The
	 * handle is used to specify the process in all functions that
	 * perform operations on the process object.
	 */
	HANDLE hProcess;
	/**
	 * Returns a handle to the primary thread of the newly
	 * created process. The handle is used to specify the thread in all
	 * functions that perform operations on the thread object.
	 */
	HANDLE hThread;
	/**
	 * Returns a global process identifier that can be used
	 * to identify a process. The value is valid from the time the
	 * process is created until the time the process is terminated.
	 */
	DWORD dwProcessId;
	/**
	 * Returns a global thread identifier that can be used
	 * to identify a thread. The value is valid from the time the thread
	 * is created until the time the thread is terminated.
	 */
	DWORD dwThreadId;
} PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;
typedef struct _CRITICAL_SECTION_DEBUG {
	WORD Type;
	WORD CreatorBackTraceIndex;
	struct _CRITICAL_SECTION *CriticalSection;
	LIST_ENTRY ProcessLocksList;
	DWORD EntryCount;
	DWORD ContentionCount;
	DWORD Spare [2];
} CRITICAL_SECTION_DEBUG,*PCRITICAL_SECTION_DEBUG;
#ifdef _WIN32_WCE
typedef struct _CRITICAL_SECTION {
	DWORD LockCount;
	HANDLE OwnerThread;
	HANDLE hCrit;
	DWORD needtrap;
	DWORD dwContentions;
} CRITICAL_SECTION,*PCRITICAL_SECTION,*LPCRITICAL_SECTION;
#else
typedef struct _CRITICAL_SECTION {
	PCRITICAL_SECTION_DEBUG DebugInfo;
	LONG LockCount;
	LONG RecursionCount;
	HANDLE OwningThread;
	HANDLE LockSemaphore;
	DWORD SpinCount;
} CRITICAL_SECTION,*PCRITICAL_SECTION,*LPCRITICAL_SECTION;
#endif
/**
 * This structure represents a date and time using individual members for
 * the month, day, year, weekday, hour, minute, second, and millisecond.
 *
 * It is not recommended that you add and subtract values from the
 * SYSTEMTIME structure to obtain relative times. Instead, you should
 *
 * Convert the SYSTEMTIME structure to a FILETIME structure.
 *
 * Copy the resulting FILETIME structure to a ULARGE_INTEGER structure.
 *
 * Use normal 64-bit arithmetic on the ULARGE_INTEGER value.
 */
typedef struct _SYSTEMTIME {
	/**
	 * Specifies the current year.
	 */
	WORD wYear;
	/**
	 * Specifies the current month; January = 1, February = 2,
	 * and so on.
	 */
	WORD wMonth;
	/**
	 * Specifies the current day of the week; Sunday = 0,
	 * Monday = 1, and so on.
	 */
	WORD wDayOfWeek;
	/**
	 * Specifies the current day of the month.
	 */
	WORD wDay;
	/**
	 * Specifies the current hour.
	 */
	WORD wHour;
	/**
	 * Specifies the current minute.
	 */
	WORD wMinute;
	/**
	 * Specifies the current second.
	 */
	WORD wSecond;
	/**
	 * Specifies the current millisecond.
	 */
	WORD wMilliseconds;
} SYSTEMTIME,*LPSYSTEMTIME;
typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
	DWORD	dwFileAttributes;
	FILETIME	ftCreationTime;
	FILETIME	ftLastAccessTime;
	FILETIME	ftLastWriteTime;
	DWORD	nFileSizeHigh;
	DWORD	nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA,*LPWIN32_FILE_ATTRIBUTE_DATA;
typedef struct _WIN32_FIND_DATAA {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
#ifdef _WIN32_WCE
    DWORD dwOID; 
#else
	DWORD dwReserved0;
	DWORD dwReserved1;
#endif
	CHAR cFileName[MAX_PATH];
#ifndef _WIN32_WCE
	CHAR cAlternateFileName[14];
#endif
} WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
#ifdef _WIN32_WCE
    DWORD dwOID; 
#else
	DWORD dwReserved0;
	DWORD dwReserved1;
#endif
	WCHAR cFileName[MAX_PATH];
#ifndef _WIN32_WCE
	WCHAR cAlternateFileName[14];
#endif
} WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;
typedef struct _WIN32_STREAM_ID {
	DWORD dwStreamId;
	DWORD dwStreamAttributes;
	LARGE_INTEGER Size;
	DWORD dwStreamNameSize;
	WCHAR cStreamName[ANYSIZE_ARRAY];
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID;
typedef enum _FINDEX_INFO_LEVELS {
	FindExInfoStandard,
	FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;
typedef enum _FINDEX_SEARCH_OPS {
	FindExSearchNameMatch,
	FindExSearchLimitToDirectories,
	FindExSearchLimitToDevices,
	FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;
typedef enum _ACL_INFORMATION_CLASS {
	AclRevisionInformation=1,
	AclSizeInformation
} ACL_INFORMATION_CLASS;
typedef struct tagHW_PROFILE_INFOA {
	DWORD dwDockInfo;
	CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
	CHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;
typedef struct tagHW_PROFILE_INFOW {
	DWORD dwDockInfo;
	WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
	WCHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;
typedef enum _GET_FILEEX_INFO_LEVELS {
	GetFileExInfoStandard,
	GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;
/**
 * This structure contains information about the current computer system.
 * This includes the processor type, page size, original equipment
 * manufacturer (OEM) identifier, and other such information.
 */
typedef struct _SYSTEM_INFO {
	_ANONYMOUS_UNION union {
		/**
		 * An obsolete member that is not used by Windows CE.
		 */
		DWORD dwOemId;
		_ANONYMOUS_STRUCT struct {
			/**
			 * Specifies the system's processor
			 * architecture. It is no longer relevant. Use the
			 * wProcessorArchitecture, wProcessorLevel, and wProcessorRevision
			 * members to determine the type of processor.
			 * PROCESSOR_ARCHITECTURE_INTEL PROCESSOR_ARCHITECTURE_MIPS
			 * PROCESSOR_ARCHITECTURE_ALPHA PROCESSOR_ARCHITECTURE_PPC
			 * PROCESSOR_ARCHITECTURE_UNKNOWN
			 */
			WORD wProcessorArchitecture;
			WORD wReserved;
		} DUMMYSTRUCTNAME;
	} DUMMYUNIONNAME;
	/**
	 * Specifies the page size and the granularity of page
	 * protection and commitment. This is the page size used by the
	 * VirtualAlloc function.
	 */
	DWORD dwPageSize;
	/**
	 * Pointer to the lowest memory address
	 * accessible to applications and dynamic-link libraries (DLLs).
	 */
	PVOID lpMinimumApplicationAddress;
	/**
	 * Pointer to the highest memory
	 * address accessible to applications and DLLs.
	 */
	PVOID lpMaximumApplicationAddress;
	/**
	 * Specifies a mask representing the set of
	 * processors configured into the system. Bit 0 is processor 0; bit
	 * 31 is processor 31.
	 */
	DWORD dwActiveProcessorMask;
	/**
	 * Specifies the number of processors in the
	 * system.
	 */
	DWORD dwNumberOfProcessors;
	/**
	 * Specifies the type of processor in the system.
	 * This member is no longer relevant. Use the
	 * wProcessorArchitecture, wProcessorLevel, and wProcessorRevision
	 * members to determine the type of processor. This member is one of
	 * the following values: PROCESSOR_INTEL_386 PROCESSOR_INTEL_486
	 * PROCESSOR_INTEL_PENTIUM PROCESSOR_INTEL_486 PROCESSOR_MIPS_R3000
	 * PROCESSOR_MIPS_R4000 PROCESSOR_HITACHI_SH3 PROCESSOR_HITACHI_SH4
	 * PROCESSOR_PPC_403 PROCESSOR_PPC_821 PROCESSOR_STRONGARM
	 * PROCESSOR_ARM720
	 */
	DWORD dwProcessorType;
	/**
	 * Specifies the granularity with which
	 * virtual memory is allocated. For example, a VirtualAlloc request
	 * to allocate 1 byte will reserve an address space of
	 * dwAllocationGranularity bytes. This value was hard coded as 64K
	 * in the past, but other hardware architectures may require
	 * different values.
	 */
	DWORD dwAllocationGranularity;
	/**
	 * Specifies the system's architecture-dependent
	 * processor level. If wProcessorArchitecture is
	 * PROCESSOR_ARCHITECTURE_INTEL, wProcessorLevel can be one of the
	 * following values: 4: Intel 80486 5: Pentium If
	 * wProcessorArchitecture is PROCESSOR_ARCHITECTURE_MIPS,
	 * wProcessorLevel is of the form 00XX, where XX is an 8-bit
	 * implementation number (bits 8-15 of the PRId register). The
	 * member can be the following value: 3: MIPS R3000 0004: MIPS R4000
	 * If wProcessorArchitecture is PROCESSOR_ARCHITECTURE_PPC,
	 * wProcessorLevel is of the form XXXX, where XXXXis a 16-bit
	 * processor version number (the high-order 16 bits of the Processor
	 * Version Register).
	 */
	WORD wProcessorLevel;
	/**
	 * Specifies an architecture-dependent processor
	 * revision. The following table shows how the revision value is
	 * assembled for each type of processor architecture. Intel 80386 or
	 * 80486: A value of the form xxyz. If xx is equal to 0xFF, y - 0xA
	 * is the model number, and z is the stepping identifier. For
	 * example, an Intel 80486-D0 system returns 0xFFD0. If xx is not
	 * equal to 0xFF, xx + 'A' is the stepping letter and yz is the
	 * minor stepping. Intel Pentium, Cyrix, or NextGen 586: A value of
	 * the form xxyy, where xx is the model number and yy is the
	 * stepping. For example, a value of 0x0201 indicates Model 2,
	 * Stepping 1. MIPS: A value of the form 00xx, where xx is the 8-bit
	 * revision number of the processor (the low-order 8 bits of the
	 * PRId register). ALPHA: A value of the form xxyy, where xxyy is
	 * the low-order 16 bits of the processor revision number from the
	 * firmware. Display this value as follows: Model 'A'+xx, Pass yy
	 * PPC: A value of the form xxyy, where xxyy is the low-order 16
	 * bits of the Processor Version Register. Display this value as a
	 * fixed point number: xx.yy
	 */
	WORD wProcessorRevision;
} SYSTEM_INFO,*LPSYSTEM_INFO;
#ifndef _WIN32_WCE
typedef struct _SYSTEM_POWER_STATUS {
	BYTE ACLineStatus;
	BYTE BatteryFlag;
	BYTE BatteryLifePercent;
	BYTE Reserved1;
	DWORD BatteryLifeTime;
	DWORD BatteryFullLifeTime;
} SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;
#endif
#ifdef _WIN32_WCE
/**
 * This structure contains information about the power status of the
 * system.
 */
typedef struct _SYSTEM_POWER_STATUS_EX {
  /**
   * AC power status. It is one of the following values:
   * 0: Offline 1: Online 255: Unknown status All other values are
   * reserved.
   */
  BYTE ACLineStatus;
  /**
   * Battery charge status. It can be a combination of
   * the following values: 1: High 2: Low 4: Critical 8: Charging 128:
   * No system battery 255: Unknown status All other values are
   * reserved.
   */
  BYTE BatteryFlag;
  /**
   * Percentage of full battery charge remaining.
   * This member can be a value in the range 0 to 100, or 255 if
   * status is unknown. All other values are reserved.
   */
  BYTE BatteryLifePercent;
  /**
   * Reserved; set to zero.
   */
  BYTE Reserved1;
  /**
   * Number of seconds of battery life remaining, or
   * 0xFFFFFFFF if remaining seconds are unknown.
   */
  DWORD BatteryLifeTime;
  /**
   * Number of seconds of battery life when at
   * full charge, or 0xFFFFFFFF if full lifetime is unknown.
   */
  DWORD BatteryFullLifeTime;
  /**
   * Reserved; set to zero.
   */
  BYTE Reserved2;
  /**
   * Backup battery charge status. It is one of the
   * following values: BATTERY_FLAG_HIGH BATTERY_FLAG_CRITICAL
   * BATTERY_FLAG_CHARGING BATTERY_FLAG_NO_BATTERY
   * BATTERY_FLAG_UNKNOWN BATTERY_FLAG_LOW
   */
  BYTE BackupBatteryFlag;
  /**
   * Percentage of full backup battery
   * charge remaining. Must be in the range 0 to 100, or
   * BATTERY_PERCENTAGE_UNKNOWN.
   */
  BYTE BackupBatteryLifePercent;
  /**
   * Reserved; set to zero
   */
  BYTE Reserved3;
  /**
   * Number of seconds of backup battery life
   * remaining, or BATTERY_LIFE_UNKNOWN if remaining seconds are
   * unknown.
   */
  DWORD BackupBatteryLifeTime;
  /**
   * Number of seconds of backup battery
   * life when at full charge, or BATTERY_LIFE_UNKNOWN if full
   * lifetime is unknown.
   */
  DWORD BackupBatteryFullLifeTime;
} SYSTEM_POWER_STATUS_EX, *PSYSTEM_POWER_STATUS_EX, *LPSYSTEM_POWER_STATUS_EX;
/**
 * This structure contains information about the power status of the
 * system.
 */
typedef struct _SYSTEM_POWER_STATUS_EX2 {
  /**
   * AC power status. It is one of the following values:
   * AC_LINE_OFFLINE AC_LINE_ONLINE AC_LINE_BACKUP_POWER
   * AC_LINE_UNKNOWN
   */
  BYTE ACLineStatus;
  /**
   * Battery charge status. It is one of the following
   * values: BATTERY_FLAG_HIGH BATTERY_FLAG_LOW BATTERY_FLAG_CRITICAL
   * BATTERY_FLAG_CHARGING BATTERY_FLAG_NO_BATTERY
   * BATTERY_FLAG_UNKNOWN
   */
  BYTE BatteryFlag;
  /**
   * Percentage of full battery charge remaining.
   * Must be in the range 0 to 100, or BATTERY_PERCENTAGE_UNKNOWN if
   * percentage of battery life remaining is unknown.
   */
  BYTE BatteryLifePercent;
  /**
   * Must be zero.
   */
  BYTE Reserved1;
  /**
   * Number of seconds of battery life remaining, or
   * BATTERY_LIFE_UNKNOWN if number of seconds of battery life
   * remaining is unknown.
   */
  DWORD BatteryLifeTime;
  /**
   * Number of seconds of battery life when at
   * full charge, or BATTERY_LIFE_UNKNOWN if full lifetime of battery
   * is unknown.
   */
  DWORD BatteryFullLifeTime;
  /**
   * Must be zero.
   */
  BYTE Reserved2;
  /**
   * Backup battery charge status. It is one of the
   * following values: BATTERY_FLAG_HIGH BATTERY_FLAG_LOW
   * BATTERY_FLAG_CRITICAL BATTERY_FLAG_CHARGING
   * BATTERY_FLAG_NO_BATTERY BATTERY_FLAG_UNKNOWN
   */
  BYTE BackupBatteryFlag;
  /**
   * Percentage of full backup battery
   * charge remaining. Must be in the range 0 to 100, or
   * BATTERY_PERCENTAGE_UNKNOWN if percentage of backup battery life
   * remaining is unknown.
   */
  BYTE BackupBatteryLifePercent;
  /**
   * Must be zero.
   */
  BYTE Reserved3;
  /**
   * Number of seconds of backup battery life
   * when at full charge, or BATTERY_LIFE_UNKNOWN if number of seconds
   * of backup battery life remaining is unknown.
   */
  DWORD BackupBatteryLifeTime;
  /**
   * Number of seconds of backup battery
   * life when at full charge, or BATTERY_LIFE_UNKNOWN if full
   * lifetime of backup battery is unknown.
   */
  DWORD BackupBatteryFullLifeTime;
  /**
   * Number of millivolts (mV) of battery voltage. It
   * can range from 0 to 65535.
   */
  DWORD BatteryVoltage;
  /**
   * Number of milliamps (mA) of instantaneous current
   * drain. It can range from 0 to 32767 for charge and 0 to -32768
   * for discharge.
   */
  DWORD BatteryCurrent;
  /**
   * Average number of milliamps of short term
   * device current drain. It can range from 0 to 32767 for charge and
   * 0 to -32768 for discharge.
   */
  DWORD BatteryAverageCurrent;
  /**
   * Number of milliseconds (mS) that is the
   * time constant interval used in reporting BatteryAverageCurrent.
   */
  DWORD BatteryAverageInterval;
  /**
   * Average number of milliamp hours (mAh) of
   * long-term cumulative average discharge. It can range from 0 to
   * -32768. This value is reset when the batteries are charged or
   * changed.
   */
  DWORD BatterymAHourConsumed;
  /**
   * Battery temperature reported in 0.1 degree
   * Celsius increments. It can range from -3276.8 to 3276.7.
   */
  DWORD BatteryTemperature;
  /**
   * Number of millivolts (mV) of backup battery
   * voltage. It can range from 0 to 65535.
   */
  DWORD BackupBatteryVoltage;
  /**
   * Type of battery. It can be one of the following
   * values: BATTERY_CHEMISTRY_ALKALINE BATTERY_CHEMISTRY_NICD
   * BATTERY_CHEMISTRY_NIMH BATTERY_CHEMISTRY_LION
   * BATTERY_CHEMISTRY_LIPOLY BATTERY_CHEMISTRY_UNKNOWN
   */
  BYTE BatteryChemistry;
} SYSTEM_POWER_STATUS_EX2, *PSYSTEM_POWER_STATUS_EX2, *LPSYSTEM_POWER_STATUS_EX2;
#endif
/**
 * This structure specifies information specific to the time zone.
 */
typedef struct _TIME_ZONE_INFORMATION {
	/**
	 * Specifies the current bias, in minutes, for local time
	 * translation on this computer. The bias is the difference, in
	 * minutes, between Coordinated Universal Time (UTC) and local time.
	 * All translations between UTC and local time are based on the
	 * following formula: This member is required.
	 */
	LONG Bias;
	/**
	 * Specifies a null-terminated string associated with
	 * standard time on this operating system. For example, this member
	 * could contain "EST" to indicate Eastern Standard Time. This
	 * string is not used by the operating system, so anything stored
	 * there by using the SetTimeZoneInformation function is returned
	 * unchanged by the GetTimeZoneInformation function. This string can
	 * be empty.
	 */
	WCHAR StandardName[32];
	/**
	 * Specifies a SYSTEMTIME structure that contains a
	 * date and local time when the transition from daylight time to
	 * standard time occurs on this operating system. If this date is
	 * not specified, the wMonth member in the SYSTEMTIME structure must
	 * be zero. If this date is specified, the DaylightDate value in the
	 * TIME_ZONE_INFORMATION structure must also be specified. This
	 * member supports two date formats. Absolute format specifies an
	 * exact date and time when standard time begins. In this form, the
	 * wYear, wMonth, wDay, wHour, wMinute, wSecond, and wMilliseconds
	 * members of the SYSTEMTIME structure are used to specify an exact
	 * date. Day-in-month format is specified by setting the wYear
	 * member to zero, setting the wDayOfWeek member to an appropriate
	 * weekday, and using a wDay value in the range 1 through 5 to
	 * select the correct day in the month. Using this notation, the
	 * first Sunday in April can be specified, as can the last Thursday
	 * in October (5 is equal to "the last").
	 */
	SYSTEMTIME StandardDate;
	/**
	 * Specifies a bias value to be used during local time
	 * translations that occur during standard time. This member is
	 * ignored if a value for the StandardDate member is not supplied.
	 * This value is added to the value of the Bias member to form the
	 * bias used during standard time. In most time zones, the value of
	 * this member is zero.
	 */
	LONG StandardBias;
	/**
	 * Specifies a null-terminated string associated with
	 * daylight time on this operating system. For example, this member
	 * could contain "PDT" to indicate Pacific Daylight Time. This
	 * string is not used by the operating system, so anything stored
	 * there by using the SetTimeZoneInformation function is returned
	 * unchanged by the GetTimeZoneInformation function. This string can
	 * be empty.
	 */
	WCHAR DaylightName[32];
	/**
	 * Specifies a SYSTEMTIME structure that contains a
	 * date and local time when the transition from standard time to
	 * daylight time occurs on this operating system. If this date is
	 * not specified, the wMonth member in the SYSTEMTIME structure must
	 * be zero. If this date is specified, the StandardDate value in the
	 * TIME_ZONE_INFORMATION structure must also be specified. This
	 * member supports the absolute and day-in-month time formats
	 * described for the StandardDate member.
	 */
	SYSTEMTIME DaylightDate;
	/**
	 * Specifies a bias value to be used during local time
	 * translations that occur during daylight time. This member is
	 * ignored if a value for the DaylightDate member is not supplied.
	 * This value is added to the value of the Bias member to form the
	 * bias used during daylight time. In most time zones, the value of
	 * this member is -60.
	 */
	LONG DaylightBias;
} TIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;
/**
 * This structure contains information about current memory availability.
 * The GlobalMemoryStatus function uses this structure.
 */
typedef struct _MEMORYSTATUS {
	/**
	 * Specifies the size, in bytes, of the MEMORYSTATUS data
	 * structure. You do not need to set this member before calling the
	 * GlobalMemoryStatus function; the function sets it.
	 */
	DWORD dwLength;
	/**
	 * Specifies a number between 0 and 100 that gives a
	 * general idea of current memory utilization, in which 0 indicates
	 * no memory use and 100 indicates full memory use.
	 */
	DWORD dwMemoryLoad;
	/**
	 * Indicates the total number of bytes of physical
	 * memory.
	 */
	DWORD dwTotalPhys;
	/**
	 * Indicates the number of bytes of physical memory
	 * available.
	 */
	DWORD dwAvailPhys;
	/**
	 * Indicates the total number of bytes that can be
	 * stored in the paging file. Note that this number does not
	 * represent the actual physical size of the paging file on disk.
	 */
	DWORD dwTotalPageFile;
	/**
	 * Indicates the number of bytes available in the
	 * paging file.
	 */
	DWORD dwAvailPageFile;
	/**
	 * Indicates the total number of bytes that can be
	 * described in the user mode portion of the virtual address space
	 * of the calling process.
	 */
	DWORD dwTotalVirtual;
	/**
	 * Indicates the number of bytes of unreserved and
	 * uncommitted memory in the user mode portion of the virtual
	 * address space of the calling process.
	 */
	DWORD dwAvailVirtual;
} MEMORYSTATUS,*LPMEMORYSTATUS;

#if (_WIN32_WCE >= 0x0500)
typedef enum {
  DeviceSearchByLegacyName,
  DeviceSearchByDeviceName,
  DeviceSearchByBusName,
  DeviceSearchByGuid,
  DeviceSearchByParent
} DeviceSearchType;
typedef struct _DevmgrDeviceInformation_tag {
  DWORD dwSize;
  HANDLE hDevice;
  HANDLE hParentDevice;
  WCHAR szLegacyName[6];
  WCHAR szDeviceKey[MAX_PATH];
  WCHAR szDeviceName[MAX_PATH];
  WCHAR szBusName[MAX_PATH];
} DEVMGR_DEVICE_INFORMATION, *PDEVMGR_DEVICE_INFORMATION;
#endif
#if (_WIN32_WINNT >= 0x0500)
typedef struct _MEMORYSTATUSEX {
	DWORD dwLength;
	DWORD dwMemoryLoad;
	DWORDLONG ullTotalPhys;
	DWORDLONG ullAvailPhys;
	DWORDLONG ullTotalPageFile;
	DWORDLONG ullAvailPageFile;
	DWORDLONG ullTotalVirtual;
	DWORDLONG ullAvailVirtual;
	DWORDLONG ullAvailExtendedVirtual;
} MEMORYSTATUSEX,*LPMEMORYSTATUSEX;
#endif
typedef struct _LDT_ENTRY {
	WORD LimitLow;
	WORD BaseLow;
	union {
		struct {
			BYTE BaseMid;
			BYTE Flags1;
			BYTE Flags2;
			BYTE BaseHi;
		} Bytes;
		struct {
			DWORD BaseMid:8;
			DWORD Type:5;
			DWORD Dpl:2;
			DWORD Pres:1;
			DWORD LimitHi:4;
			DWORD Sys:1;
			DWORD Reserved_0:1;
			DWORD Default_Big:1;
			DWORD Granularity:1;
			DWORD BaseHi:8;
		} Bits;
	} HighWord;
} LDT_ENTRY,*PLDT_ENTRY,*LPLDT_ENTRY;
typedef struct _PROCESS_HEAP_ENTRY {
	PVOID lpData;
	DWORD cbData;
	BYTE cbOverhead;
	BYTE iRegionIndex;
	WORD wFlags;
	_ANONYMOUS_UNION union {
		struct {
			HANDLE hMem;
			DWORD dwReserved[3];
		} Block;
		struct {
			DWORD dwCommittedSize;
			DWORD dwUnCommittedSize;
			LPVOID lpFirstBlock;
			LPVOID lpLastBlock;
		} Region;
	} DUMMYUNIONNAME;
} PROCESS_HEAP_ENTRY,*LPPROCESS_HEAP_ENTRY;
typedef struct _OFSTRUCT {
	BYTE cBytes;
	BYTE fFixedDisk;
	WORD nErrCode;
	WORD Reserved1;
	WORD Reserved2;
	CHAR szPathName[OFS_MAXPATHNAME];
} OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;
typedef struct _WIN_CERTIFICATE {
      DWORD dwLength;
      WORD wRevision;
      WORD wCertificateType;
      BYTE bCertificate[1];
} WIN_CERTIFICATE, *LPWIN_CERTIFICATE;
#if (_WIN32_WINNT >= 0x0501)
typedef struct tagACTCTXA {
	ULONG cbSize;
	DWORD dwFlags;
	LPCSTR lpSource;
	USHORT wProcessorArchitecture;
	LANGID wLangId;
	LPCSTR lpAssemblyDirectory;
	LPCSTR lpResourceName;
	LPCSTR lpApplicationName;
	HMODULE hModule;
} ACTCTXA,*PACTCTXA;
typedef const ACTCTXA *PCACTCTXA;
typedef struct tagACTCTXW {
	ULONG cbSize;
	DWORD dwFlags;
	LPCWSTR lpSource;
	USHORT wProcessorArchitecture;
	LANGID wLangId;
	LPCWSTR lpAssemblyDirectory;
	LPCWSTR lpResourceName;
	LPCWSTR lpApplicationName;
	HMODULE hModule;
} ACTCTXW,*PACTCTXW;
typedef const ACTCTXW *PCACTCTXW;
typedef struct tagACTCTX_SECTION_KEYED_DATA {
	ULONG cbSize;
	ULONG ulDataFormatVersion;
	PVOID lpData;
	ULONG ulLength;
	PVOID lpSectionGlobalData;
	ULONG ulSectionGlobalDataLength;
	PVOID lpSectionBase;
	ULONG ulSectionTotalLength;
	HANDLE hActCtx;
	HANDLE ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA,*PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;
typedef enum {
	LowMemoryResourceNotification ,
	HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;
#endif
#if (_WIN32_WINNT >= 0x0500)
typedef enum _COMPUTER_NAME_FORMAT {
	ComputerNameNetBIOS, 
	ComputerNameDnsHostname, 
	ComputerNameDnsDomain, 
	ComputerNameDnsFullyQualified, 
	ComputerNamePhysicalNetBIOS, 
	ComputerNamePhysicalDnsHostname, 
	ComputerNamePhysicalDnsDomain, 
	ComputerNamePhysicalDnsFullyQualified, 
	ComputerNameMax
} COMPUTER_NAME_FORMAT;
#endif
#if (_WIN32_WINNT >= 0x0500 || _WIN32_WINDOWS >= 0x0410)
typedef DWORD EXECUTION_STATE;
#endif
#if (_WIN32_WINNT >= 0x0600)
typedef enum _DEP_SYSTEM_POLICY_TYPE {
	AlwaysOn,
	AlwaysOff,
	OptIn,
	OptOut 
} DEP_SYSTEM_POLICY_TYPE;
/* http://msdn.microsoft.com/en-us/library/aa364228%28v=VS.85%29.aspx */
typedef enum _FILE_INFO_BY_HANDLE_CLASS {
  FileBasicInfo,
  FileStandardInfo,
  FileNameInfo,
  FileRenameInfo,
  FileDispositionInfo,
  FileAllocationInfo,
  FileEndOfFileInfo,
  FileStreamInfo,
  FileCompressionInfo,
  FileAttributeTagInfo,
  FileIdBothDirectoryInfo,
  FileIdBothDirectoryRestartInfo,
  FileIoPriorityHintInfo,
  FileRemoteProtocolInfo,
  MaximumFileInfoByHandlesClass
} FILE_INFO_BY_HANDLE_CLASS,*PFILE_INFO_BY_HANDLE_CLASS;
#endif

typedef DWORD(WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER,LARGE_INTEGER,LARGE_INTEGER,LARGE_INTEGER,DWORD,DWORD,HANDLE,HANDLE,LPVOID);
typedef void(WINAPI *LPFIBER_START_ROUTINE)(PVOID);
typedef BOOL(CALLBACK *ENUMRESLANGPROCA)(HMODULE,LPCSTR,LPCSTR,WORD,LONG);
typedef BOOL(CALLBACK *ENUMRESLANGPROCW)(HMODULE,LPCWSTR,LPCWSTR,WORD,LONG);
#ifdef UNICODE
#define ENUMRESLANGPROC ENUMRESLANGPROCW
#else
#define ENUMRESLANGPROC ENUMRESLANGPROCA
#endif
typedef BOOL(CALLBACK *ENUMRESNAMEPROCA)(HMODULE,LPCSTR,LPSTR,LONG);
typedef BOOL(CALLBACK *ENUMRESNAMEPROCW)(HMODULE,LPCWSTR,LPWSTR,LONG);
#ifdef UNICODE
#define ENUMRESNAMEPROC ENUMRESNAMEPROCW
#else
#define ENUMRESNAMEPROC ENUMRESNAMEPROCA
#endif
typedef BOOL(CALLBACK *ENUMRESTYPEPROCA)(HMODULE,LPSTR,LONG);
typedef BOOL(CALLBACK *ENUMRESTYPEPROCW)(HMODULE,LPWSTR,LONG);
#ifdef UNICODE
#define ENUMRESTYPEPROC ENUMRESTYPEPROCW
#else
#define ENUMRESTYPEPROC ENUMRESTYPEPROCA
#endif
typedef void(CALLBACK *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD,DWORD,LPOVERLAPPED);
typedef LONG(CALLBACK *PTOP_LEVEL_EXCEPTION_FILTER)(LPEXCEPTION_POINTERS);
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;
typedef void(APIENTRY *PAPCFUNC)(ULONG_PTR);
typedef void(CALLBACK *PTIMERAPCROUTINE)(PVOID,DWORD,DWORD);
#if (_WIN32_WINNT >= 0x0500)
typedef void(CALLBACK *WAITORTIMERCALLBACK)(PVOID,BOOLEAN);   
#endif
#define MAKEINTATOM(i) (LPTSTR)((DWORD)((WORD)(i)))
/* Functions */
#ifndef UNDER_CE
int APIENTRY WinMain(HINSTANCE,HINSTANCE,LPSTR,int);
#else
int APIENTRY WinMain(HINSTANCE,HINSTANCE,LPWSTR,int);
#endif
int APIENTRY wWinMain(HINSTANCE,HINSTANCE,LPWSTR,int);
WINBASEAPI long WINAPI _hread(HFILE,LPVOID,long);
WINBASEAPI long WINAPI _hwrite(HFILE,LPCSTR,long);
WINBASEAPI HFILE WINAPI _lclose(HFILE);
WINBASEAPI HFILE WINAPI _lcreat(LPCSTR,int);
WINBASEAPI LONG WINAPI _llseek(HFILE,LONG,int);
WINBASEAPI HFILE WINAPI _lopen(LPCSTR,int);
WINBASEAPI UINT WINAPI _lread(HFILE,LPVOID,UINT);
WINBASEAPI UINT WINAPI _lwrite(HFILE,LPCSTR,UINT);
/**
 * This function indicates whether the try block of a try-finally statement
 * terminated normally. This function can be called only from within the
 * finally block of a try-finally statement.
 *
 * The Excpt.h file has to be explicitly included in order to use this
 * function.
 *
 * The try block terminates normally only if execution leaves the block
 * sequentially after executing the last statement in the block. Statements
 * (such as return, goto, continue, or break) that cause execution to leave
 * the try block result in abnormal termination of the block. This is the
 * case even if such a statement is the last statement in the try block.
 *
 * Abnormal termination of a try block causes the system to search backward
 * through all stack frames to determine whether any termination handlers
 * must be called. This can result in the execution of hundreds of
 * instructions, so it is important to avoid abnormal termination of a try
 * block due to a return, goto, continue, or break statement. Note that
 * these statements do not generate an exception, even though the
 * termination is abnormal.
 *
 * To avoid abnormal termination of the try-finally block, execution should
 * continue to the end of the block. You can also execute the leave
 * statement. The leave statement allows for immediate termination of the
 * try block without causing abnormal termination and its performance
 * penalty. Check your compiler documentation to determine if the leave
 * statement is supported.
 *
 * @return Nonzero indicates that the try block of the try-finally
 *        statement terminated abnormally. Zero indicates that the try
 *        block of the try-finally statement terminated normally.
 */
#define AbnormalTermination() FALSE
WINBASEAPI BOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR,HANDLE,DWORD,PGENERIC_MAPPING,PPRIVILEGE_SET,PDWORD,PDWORD,PBOOL);
WINBASEAPI BOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR,LPVOID,LPSTR,LPSTR,PSECURITY_DESCRIPTOR,DWORD,PGENERIC_MAPPING,BOOL,PDWORD,PBOOL,PBOOL);
WINBASEAPI BOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR,LPVOID,LPWSTR,LPWSTR,PSECURITY_DESCRIPTOR,DWORD,PGENERIC_MAPPING,BOOL,PDWORD,PBOOL,PBOOL);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI ActivateActCtx(HANDLE,ULONG_PTR*);
#endif
WINBASEAPI BOOL WINAPI AddAccessAllowedAce(PACL,DWORD,DWORD,PSID);
WINBASEAPI BOOL WINAPI AddAccessDeniedAce(PACL,DWORD,DWORD,PSID);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI AddAccessAllowedAceEx(PACL,DWORD,DWORD,DWORD,PSID);
WINBASEAPI BOOL WINAPI AddAccessDeniedAceEx(PACL,DWORD,DWORD,DWORD,PSID);
#endif
WINBASEAPI BOOL WINAPI AddAce(PACL,DWORD,DWORD,PVOID,DWORD);
WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR);
WINBASEAPI BOOL WINAPI AddAuditAccessAce(PACL,DWORD,DWORD,PSID,BOOL,BOOL);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI void WINAPI AddRefActCtx(HANDLE);
#endif
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler(ULONG,PVECTORED_EXCEPTION_HANDLER);
#endif
WINBASEAPI BOOL WINAPI AdjustTokenGroups(HANDLE,BOOL,PTOKEN_GROUPS,DWORD,PTOKEN_GROUPS,PDWORD);
WINBASEAPI BOOL WINAPI AdjustTokenPrivileges(HANDLE,BOOL,PTOKEN_PRIVILEGES,DWORD,PTOKEN_PRIVILEGES,PDWORD);
WINBASEAPI BOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY,BYTE,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,PSID*);
WINBASEAPI BOOL WINAPI AllocateLocallyUniqueId(PLUID);
WINBASEAPI BOOL WINAPI AreAllAccessesGranted(DWORD,DWORD);
WINBASEAPI BOOL WINAPI AreAnyAccessesGranted(DWORD,DWORD);
WINBASEAPI BOOL WINAPI AreFileApisANSI(void);
WINBASEAPI BOOL WINAPI BackupEventLogA(HANDLE,LPCSTR);
WINBASEAPI BOOL WINAPI BackupEventLogW(HANDLE,LPCWSTR);
WINBASEAPI BOOL WINAPI BackupRead(HANDLE,LPBYTE,DWORD,LPDWORD,BOOL,BOOL,LPVOID*);
WINBASEAPI BOOL WINAPI BackupSeek(HANDLE,DWORD,DWORD,LPDWORD,LPDWORD,LPVOID*);
WINBASEAPI BOOL WINAPI BackupWrite(HANDLE,LPBYTE,DWORD,LPDWORD,BOOL,BOOL,LPVOID*);
WINBASEAPI BOOL WINAPI Beep(DWORD,DWORD);
WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR,BOOL);
WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR,BOOL);
WINBASEAPI BOOL WINAPI BuildCommDCBA(LPCSTR,LPDCB);
WINBASEAPI BOOL WINAPI BuildCommDCBW(LPCWSTR,LPDCB);
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR,LPDCB,LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR,LPDCB,LPCOMMTIMEOUTS);
WINBASEAPI BOOL WINAPI CallNamedPipeA(LPCSTR,PVOID,DWORD,PVOID,DWORD,PDWORD,DWORD);
WINBASEAPI BOOL WINAPI CallNamedPipeW(LPCWSTR,PVOID,DWORD,PVOID,DWORD,PDWORD,DWORD);
WINBASEAPI BOOL WINAPI CancelDeviceWakeupRequest(HANDLE);
WINBASEAPI BOOL WINAPI CancelIo(HANDLE);
WINBASEAPI BOOL WINAPI CancelWaitableTimer(HANDLE);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI ChangeTimerQueueTimer(HANDLE,HANDLE,ULONG,ULONG);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR,LPSTR,DWORD,PBOOL,PBOOL);
WINBASEAPI BOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR,LPSTR,DWORD,PBOOL,PBOOL);
WINBASEAPI BOOL WINAPI CheckRemoteDebuggerPresent(HANDLE,PBOOL);
#endif
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI CheckTokenMembership(HANDLE,PSID,PBOOL);
#endif
/**
 * Takes a serial port out of the break state and resumes transmission.
 *
 * The break state is set with SetCommBreak or EscapeCommFunction.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI ClearCommBreak(HANDLE hFile);
/**
 * Returns and clears a serial port's error state, and optionally its
 * status.
 *
 * If the DCB has fAbortOnError set, reads and writes fail after an error
 * until this is called.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpErrors Receives CE_* error flags: CE_BREAK, CE_FRAME, CE_IOE,
 *        CE_MODE, CE_OVERRUN, CE_RXOVER, CE_RXPARITY, CE_TXFULL and so
 *        on.
 * @param lpStat Receives a COMSTAT with queue counts and flow control
 *        state, or NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI ClearCommError(HANDLE hFile,PDWORD lpErrors,LPCOMSTAT lpStat);
WINBASEAPI BOOL WINAPI ClearEventLogA(HANDLE,LPCSTR);
WINBASEAPI BOOL WINAPI ClearEventLogW(HANDLE,LPCWSTR);
WINBASEAPI BOOL WINAPI CloseEventLog(HANDLE);
/**
 * Closes an object handle.
 *
 * The object is destroyed when its last handle closes. Use FindClose for
 * FindFirstFileW handles and FreeLibrary for modules. Closing an invalid
 * handle, or the same handle twice, can raise an exception. Process and
 * thread handles from CreateProcessW must both be closed.
 *
 * @param hObject Handle to a file, event, mutex, process, thread or
 *        other kernel object.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI CloseHandle(HANDLE hObject);
WINBASEAPI BOOL WINAPI CommConfigDialogA(LPCSTR,HWND,LPCOMMCONFIG);
WINBASEAPI BOOL WINAPI CommConfigDialogW(LPCWSTR,HWND,LPCOMMCONFIG);
/**
 * Compares two FILETIMEs.
 *
 * @param lpFileTime1 First time.
 * @param lpFileTime2 Second time.
 * @return -1 if the first is earlier, 0 if equal, +1 if the first is
 *         later.
 */
WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME*lpFileTime1,CONST FILETIME*lpFileTime2);
WINBASEAPI BOOL WINAPI ConnectNamedPipe(HANDLE,LPOVERLAPPED);
/**
 * Resumes a thread that reported a debug event.
 *
 * Call after handling each event from WaitForDebugEvent.
 *
 * @param dwProcessId Process ID from the DEBUG_EVENT.
 * @param dwThreadId Thread ID from the DEBUG_EVENT.
 * @param dwContinueStatus DBG_CONTINUE, or DBG_EXCEPTION_NOT_HANDLED to
 *        pass an exception on to the thread's handlers.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dwContinueStatus);
#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI BOOL WINAPI ConvertFiberToThread(void);
#endif
WINBASEAPI PVOID WINAPI ConvertThreadToFiber(PVOID);
WINBASEAPI BOOL WINAPI CopyFileA(LPCSTR,LPCSTR,BOOL);
/**
 * Copies a file.
 *
 * The file attributes are copied too.
 *
 * @param lpExistingFileName Source path.
 * @param lpNewFileName Destination path.
 * @param bFailIfExists TRUE to fail if the destination exists, FALSE to
 *        overwrite it.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,BOOL bFailIfExists);
WINBASEAPI BOOL WINAPI CopyFileExA(LPCSTR,LPCSTR,LPPROGRESS_ROUTINE,LPVOID,LPBOOL,DWORD);
WINBASEAPI BOOL WINAPI CopyFileExW(LPCWSTR,LPCWSTR,LPPROGRESS_ROUTINE,LPVOID,LPBOOL,DWORD);
#define RtlMoveMemory memmove
#define RtlCopyMemory memcpy
#define RtlFillMemory(d,l,f) memset((d), (f), (l))
#define RtlZeroMemory(d,l) RtlFillMemory((d),(l),0)
#define MoveMemory RtlMoveMemory
#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory
WINBASEAPI BOOL WINAPI CopySid(DWORD,PSID,PSID);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA);
WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW);
#endif
WINBASEAPI BOOL WINAPI CreateDirectoryA(LPCSTR,LPSECURITY_ATTRIBUTES);
/**
 * Creates a directory.
 *
 * Doesn't create missing parent directories.
 *
 * @param lpPathName Path of the new directory, up to MAX_PATH characters.
 * @param lpSecurityAttributes Ignored: must be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI BOOL WINAPI CreateDirectoryExA(LPCSTR,LPCSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateDirectoryExW(LPCWSTR,LPCWSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCSTR);
/**
 * Creates an event object.
 *
 * Set with SetEvent, clear with ResetEvent, wait with
 * WaitForSingleObject. A manual-reset event stays signalled until reset.
 * An auto-reset event releases one waiting thread and then resets. Close
 * with CloseHandle.
 *
 * @param lpEventAttributes Must be NULL.
 * @param bManualReset TRUE for manual reset, FALSE for auto reset.
 * @param bInitialState TRUE to start signalled.
 * @param lpName The SDK reference says named events are not supported and
 *        this must be NULL.
 * @return The event, or NULL on failure (see GetLastError).
 */
WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,LPCWSTR lpName);
WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T,LPFIBER_START_ROUTINE,LPVOID);
#if (_WIN32_WINNT >= 0x0400)
WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T,SIZE_T,DWORD,LPFIBER_START_ROUTINE,LPVOID);
#endif
WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
/**
 * Creates or opens a file or device.
 *
 * Devices are named with a colon, e.g. L"COM1:", and need OPEN_EXISTING.
 * Can't create directories (use CreateDirectoryW). Close with
 * CloseHandle.
 *
 * @param lpFileName Path or device name, up to MAX_PATH characters.
 * @param dwDesiredAccess GENERIC_READ and/or GENERIC_WRITE, or 0 to query
 *        device attributes only.
 * @param dwShareMode 0, FILE_SHARE_READ and/or FILE_SHARE_WRITE.
 * @param lpSecurityAttributes Ignored: should be NULL.
 * @param dwCreationDisposition CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING,
 *        OPEN_ALWAYS or TRUNCATE_EXISTING.
 * @param dwFlagsAndAttributes FILE_ATTRIBUTE_* values and
 *        FILE_FLAG_WRITE_THROUGH or FILE_FLAG_RANDOM_ACCESS. Windows CE
 *        doesn't support FILE_ATTRIBUTE_OFFLINE, FILE_ATTRIBUTE_TEMPORARY,
 *        FILE_FLAG_OVERLAPPED, FILE_FLAG_SEQUENTIAL_SCAN,
 *        FILE_FLAG_NO_BUFFERING, FILE_FLAG_DELETE_ON_CLOSE,
 *        FILE_FLAG_BACKUP_SEMANTICS, FILE_FLAG_POSIX_SEMANTICS or
 *        SECURITY_SQOS_PRESENT.
 * @param hTemplateFile Ignored.
 * @return The handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError). GetLastError returns ERROR_ALREADY_EXISTS on
 *         success if CREATE_ALWAYS or OPEN_ALWAYS found an existing file.
 */
WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
#ifdef _WIN32_WCE
/**
 * Opens or creates a file for use with CreateFileMappingW.
 *
 * Windows CE specific. Use this instead of CreateFileW for files to be
 * mapped: the kernel opens the file, so other processes can share the
 * mapping. Don't use the handle for ReadFile or WriteFile. Once passed to
 * CreateFileMappingW the kernel owns the handle and CloseHandle on it
 * fails. Only one process should open a shared file this way; others map
 * it by name with CreateFileMappingW.
 *
 * @param lpFileName Path of the file, up to MAX_PATH characters.
 * @param dwDesiredAccess GENERIC_READ, GENERIC_READ | GENERIC_WRITE, or 0
 *        for attribute queries. The Windows CE 2.0 reference lists only
 *        0 and GENERIC_READ.
 * @param dwShareMode 0, FILE_SHARE_READ and/or FILE_SHARE_WRITE.
 * @param lpSecurityAttributes Must be NULL.
 * @param dwCreationDisposition CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING,
 *        OPEN_ALWAYS or TRUNCATE_EXISTING.
 * @param dwFlagsAndAttributes FILE_ATTRIBUTE_* values, plus
 *        FILE_FLAG_WRITE_THROUGH and FILE_FLAG_RANDOM_ACCESS.
 * @param hTemplateFile Ignored.
 * @return The file handle, or INVALID_HANDLE_VALUE on failure (see
 *        GetLastError). GetLastError returns ERROR_ALREADY_EXISTS on
 *        success if CREATE_ALWAYS or OPEN_ALWAYS found an existing file.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HANDLE CreateFileForMappingW(LPCTSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
#endif
WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCSTR);
/**
 * Creates or opens a file-mapping object.
 *
 * Map views with MapViewOfFile. To free it, unmap all views with
 * UnmapViewOfFile and close the handle. Views of one mapping are
 * coherent, but not with ReadFile or WriteFile on the same file. Doesn't
 * work on devices without page-in support.
 *
 * @param hFile Handle from CreateFileForMappingW, or INVALID_HANDLE_VALUE
 *        for a mapping backed by memory instead of a file (the size must
 *        then be given).
 * @param lpFileMappingAttributes Must be NULL.
 * @param flProtect PAGE_READONLY, PAGE_READWRITE or PAGE_WRITECOPY,
 *        optionally with SEC_COMMIT or SEC_RESERVE. The file's access
 *        must allow it.
 * @param dwMaximumSizeHigh High 32 bits of the maximum size.
 * @param dwMaximumSizeLow Low 32 bits of the maximum size. With
 *        dwMaximumSizeHigh 0 too, the current file size is used. A larger
 *        size grows the file.
 * @param lpName Name for sharing between processes, or NULL. Must not
 *        contain a backslash.
 * @return The mapping, or NULL on failure (see GetLastError). If the name
 *         already existed, the existing mapping is returned and
 *         GetLastError returns ERROR_ALREADY_EXISTS.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCWSTR lpName);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI CreateHardLinkA(LPCSTR,LPCSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreateHardLinkW(LPCWSTR,LPCWSTR,LPSECURITY_ATTRIBUTES);
#endif
WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE,HANDLE,ULONG_PTR,DWORD);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES,LPCSTR);
WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES,LPCWSTR);
WINBASEAPI BOOL WINAPI TerminateJobObject(HANDLE,UINT);
WINBASEAPI BOOL WINAPI AssignProcessToJobObject(HANDLE,HANDLE);
WINBASEAPI BOOL WINAPI SetInformationJobObject(HANDLE, JOBOBJECTINFOCLASS, LPVOID, DWORD);
WINBASEAPI BOOL WINAPI QueryInformationJobObject(HANDLE, JOBOBJECTINFOCLASS, LPVOID, DWORD, LPDWORD);
#endif
WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE);
#endif
WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);
/**
 * Creates or opens a mutex.
 *
 * Acquire with a wait function and release with ReleaseMutex, once per
 * successful wait. Close with CloseHandle. Events, mutexes, semaphores
 * and file mappings share one namespace.
 *
 * @param lpMutexAttributes Must be NULL.
 * @param bInitialOwner TRUE to own the mutex on return. Ignored if it
 *        already existed.
 * @param lpName Case-sensitive name, up to MAX_PATH characters and no
 *        backslash, or NULL for an unnamed mutex.
 * @return The mutex, or NULL on failure (see GetLastError). If the name
 *         already existed, GetLastError returns ERROR_ALREADY_EXISTS.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCWSTR lpName);
WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL WINAPI CreatePipe(PHANDLE,PHANDLE,LPSECURITY_ATTRIBUTES,DWORD);
WINBASEAPI BOOL WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,BOOL,HANDLE,PGENERIC_MAPPING);
WINBASEAPI BOOL WINAPI CreateProcessA(LPCSTR,LPSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,PVOID,LPCSTR,LPSTARTUPINFOA,LPPROCESS_INFORMATION);
/**
 * Starts a program in a new process.
 *
 * Close both handles in lpProcessInformation with CloseHandle when no
 * longer needed. There are no priority classes, environment blocks or
 * current directories. Don't call it from DllMain. On Windows CE 3.0 the
 * SystemPath value under HKEY_LOCAL_MACHINE\Loader adds search folders,
 * after a reset.
 *
 * @param lpApplicationName The module to run. Must not be NULL, and the
 *        module can't be named in lpCommandLine instead. .exe is assumed
 *        if there is no extension. Without a path, Windows CE 1.0 and 2.0
 *        search the root of a PC Card, \Windows and \; Windows CE 3.0
 *        searches \Windows, then \, then an OEM-dependent folder.
 * @param lpCommandLine Arguments, or NULL.
 * @param lpProcessAttributes Must be NULL.
 * @param lpThreadAttributes Must be NULL.
 * @param bInheritHandles Must be FALSE.
 * @param dwCreationFlags 0 or CREATE_SUSPENDED. Windows CE 2.0 and later
 *        also support DEBUG_PROCESS and DEBUG_ONLY_THIS_PROCESS, and
 *        Windows CE 3.0 CREATE_NEW_CONSOLE. With the debug flags, only the
 *        calling thread can call WaitForDebugEvent.
 * @param lpEnvironment Must be NULL.
 * @param lpCurrentDirectory Must be NULL.
 * @param lpStartupInfo Must be NULL.
 * @param lpProcessInformation Receives the process and primary thread
 *        handles and IDs.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,PVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
WINBASEAPI BOOL WINAPI CreateProcessAsUserA(HANDLE,LPCSTR,LPSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,PVOID,LPCSTR,LPSTARTUPINFOA,LPPROCESS_INFORMATION);
WINBASEAPI BOOL WINAPI CreateProcessAsUserW(HANDLE,LPCWSTR,LPWSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,PVOID,LPCWSTR,LPSTARTUPINFOW,LPPROCESS_INFORMATION);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI CreateProcessWithLogonW (LPCWSTR,LPCWSTR,LPCWSTR,DWORD,
						LPCWSTR,LPWSTR,DWORD,LPVOID,
						LPCWSTR,LPSTARTUPINFOW,
						LPPROCESS_INFORMATION);
#define LOGON_WITH_PROFILE 0x00000001
#define LOGON_NETCREDENTIALS_ONLY 0x00000002
#endif
WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,LPTHREAD_START_ROUTINE,LPVOID,DWORD,LPDWORD);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI CreateRestrictedToken(HANDLE,DWORD,DWORD,PSID_AND_ATTRIBUTES,DWORD,PLUID_AND_ATTRIBUTES,DWORD,PSID_AND_ATTRIBUTES,PHANDLE);
#define DISABLE_MAX_PRIVILEGE 1
#define SANDBOX_INERT 2
#define LUA_TOKEN 4
#define WRITE_RESTRICTED 8
#endif
WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES,LONG,LONG,LPCSTR);
/**
 * Creates or opens a named or unnamed semaphore.
 *
 * The initial count must be between zero and lMaximumCount; the maximum
 * must be greater than zero. Use wait functions to decrement the count
 * and ReleaseSemaphore to increment it. Close the handle when finished.
 * CE has no OpenSemaphore; use this function to open a named semaphore.
 *
 * @param lpSemaphoreAttributes Must be NULL.
 * @param lInitialCount Initial semaphore count.
 * @param lMaximumCount Maximum semaphore count.
 * @param lpName Optional name, or NULL for an unnamed semaphore.
 * @return Semaphore handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCWSTR lpName);
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI BOOL WINAPI CreateSymbolicLinkA(LPCSTR,LPCSTR,DWORD);
WINBASEAPI BOOL WINAPI CreateSymbolicLinkW(LPCWSTR,LPCWSTR,DWORD);
#endif
WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE,DWORD,DWORD,DWORD);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI HANDLE WINAPI CreateTimerQueue(void);
WINBASEAPI BOOL WINAPI CreateTimerQueueTimer(PHANDLE,HANDLE,WAITORTIMERCALLBACK,PVOID,DWORD,DWORD,ULONG);
#endif
/**
 * Creates a thread in the calling process.
 *
 * The stack size is the same as the primary thread's. Close the handle
 * with CloseHandle when no longer needed.
 *
 * @param lpThreadAttributes Must be NULL.
 * @param dwStackSize Must be 0.
 * @param lpStartAddress Thread function.
 * @param lpParameter Value passed to the thread function.
 * @param dwCreationFlags 0, or CREATE_SUSPENDED to wait for ResumeThread.
 * @param lpThreadId Receives the thread ID.
 * @return The thread handle, or NULL on failure (see GetLastError).
 */
WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,DWORD dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,PVOID lpParameter,DWORD dwCreationFlags,PDWORD lpThreadId);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES,BOOL,LPCWSTR);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI DeactivateActCtx(DWORD,ULONG_PTR);
#endif
/**
 * Attaches the calling thread as debugger to a running process.
 *
 * Then receive events with WaitForDebugEvent: CREATE_PROCESS_DEBUG_EVENT
 * for the primary thread and CREATE_THREAD_DEBUG_EVENT for each other
 * thread. Close the thread handles they carry. No initial breakpoint is
 * raised. Windows CE 2.0 and later can also launch a just-in-time debugger
 * named by the JITDebugger value under HKEY_LOCAL_MACHINE\Debug, after a
 * warm reset; it gets the process ID on its command line.
 *
 * @param dwProcessId The process to debug.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI DebugActiveProcessStop(DWORD);
#endif
#if defined (_WIN32_WCE)
/* defined as macro in kfuncs.h */
#else
WINBASEAPI void WINAPI DebugBreak(void);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI DebugBreakProcess(HANDLE);
WINBASEAPI BOOL WINAPI DebugSetProcessKillOnExit(BOOL);
#endif
WINBASEAPI BOOL WINAPI DefineDosDeviceA(DWORD,LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI DefineDosDeviceW(DWORD,LPCWSTR,LPCWSTR);
#define DefineHandleTable(w) ((w),TRUE)
WINBASEAPI BOOL WINAPI DeleteAce(PACL,DWORD);
WINBASEAPI ATOM WINAPI DeleteAtom(ATOM);
/**
 * Frees the resources of a critical section that is no longer used.
 *
 * The critical section must not be owned. Reinitialise with
 * InitializeCriticalSection before reusing it.
 *
 * @param lpCriticalSection The critical section.
 */
WINBASEAPI void WINAPI DeleteCriticalSection(PCRITICAL_SECTION lpCriticalSection);
WINBASEAPI void WINAPI DeleteFiber(PVOID);
WINBASEAPI BOOL WINAPI DeleteFileA(LPCSTR);
/**
 * Deletes a file.
 *
 * Fails for open files and read-only files.
 *
 * @param lpFileName Path of the file.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI DeleteTimerQueue(HANDLE);
WINBASEAPI BOOL WINAPI DeleteTimerQueueEx(HANDLE,HANDLE);
WINBASEAPI BOOL WINAPI DeleteTimerQueueTimer(HANDLE,HANDLE,HANDLE);
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointA(LPCSTR);
WINBASEAPI BOOL WINAPI DeleteVolumeMountPointW(LPCWSTR);
#endif
WINBASEAPI BOOL WINAPI DeregisterEventSource(HANDLE);
WINBASEAPI BOOL WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR*);
/**
 * Sends a control code to a device driver.
 *
 * Windows CE defines no standard codes here: drivers define their own
 * with CTL_CODE.
 *
 * @param hDevice Device handle from CreateFileW.
 * @param dwIoControlCode Driver-defined control code.
 * @param lpInBuffer Input data, or NULL if none.
 * @param nInBufferSize Size of lpInBuffer in bytes.
 * @param lpOutBuffer Receives output data, or NULL if none.
 * @param nOutBufferSize Size of lpOutBuffer in bytes.
 * @param lpBytesReturned Receives the bytes written to lpOutBuffer. Must
 *        not be NULL.
 * @param lpOverlapped Ignored: should be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,PVOID lpInBuffer,DWORD nInBufferSize,PVOID lpOutBuffer,DWORD nOutBufferSize,PDWORD lpBytesReturned,POVERLAPPED lpOverlapped);
/**
 * Disables DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications.
 *
 * Use this in DLL_PROCESS_ATTACH when the DLL does not need per-thread
 * notifications. CE has no static thread-local storage.
 *
 * @param hLibModule DLL module handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameA(LPCSTR,LPSTR,LPDWORD);
WINBASEAPI BOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR,LPWSTR,LPDWORD);
#endif
WINBASEAPI BOOL WINAPI DisconnectNamedPipe(HANDLE);
WINBASEAPI BOOL WINAPI DosDateTimeToFileTime(WORD,WORD,LPFILETIME);
WINBASEAPI BOOL WINAPI DuplicateHandle(HANDLE,HANDLE,HANDLE,PHANDLE,DWORD,BOOL,DWORD);
WINBASEAPI BOOL WINAPI DuplicateToken(HANDLE,SECURITY_IMPERSONATION_LEVEL,PHANDLE);
WINBASEAPI BOOL WINAPI DuplicateTokenEx(HANDLE,DWORD,LPSECURITY_ATTRIBUTES,SECURITY_IMPERSONATION_LEVEL,TOKEN_TYPE,PHANDLE);
WINBASEAPI BOOL WINAPI EncryptFileA(LPCSTR);
WINBASEAPI BOOL WINAPI EncryptFileW(LPCWSTR);
WINBASEAPI BOOL WINAPI EndUpdateResourceA(HANDLE,BOOL);
WINBASEAPI BOOL WINAPI EndUpdateResourceW(HANDLE,BOOL);
/**
 * Waits for and takes ownership of a critical section.
 *
 * A thread may enter a critical section it already owns, and must call
 * LeaveCriticalSection once for each entry.
 *
 * @param lpCriticalSection Critical section set up with
 *        InitializeCriticalSection.
 */
WINBASEAPI void WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
#if (_WIN32_WCE >= 0x0500)
WINBASEAPI BOOL WINAPI EnumDeviceInterfaces(HANDLE, DWORD, GUID*, LPWSTR, LPDWORD);
WINBASEAPI DWORD EnumDevices(LPTSTR lpszDevList, LPDWORD lpBuflen);
#endif
WINBASEAPI BOOL WINAPI EnumResourceLanguagesA(HMODULE,LPCSTR,LPCSTR,ENUMRESLANGPROCA,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceLanguagesW(HMODULE,LPCWSTR,LPCWSTR,ENUMRESLANGPROCW,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceNamesA(HMODULE,LPCSTR,ENUMRESNAMEPROCA,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceNamesW(HMODULE,LPCWSTR,ENUMRESNAMEPROCW,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceTypesA(HMODULE,ENUMRESTYPEPROCA,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumResourceTypesW(HMODULE,ENUMRESTYPEPROCW,LONG_PTR);
WINBASEAPI BOOL WINAPI EqualPrefixSid(PSID,PSID);
WINBASEAPI BOOL WINAPI EqualSid(PSID,PSID);
WINBASEAPI DWORD WINAPI EraseTape(HANDLE,DWORD,BOOL);
/**
 * Performs an extended function on a serial port.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param dwFunc SETDTR, CLRDTR, SETRTS, CLRRTS, SETXON, SETXOFF, SETBREAK
 *        or CLRBREAK. Windows CE adds SETIR (infrared mode) and CLRIR
 *        (normal serial mode).
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);

/**
 * Forcibly ends a process and all of its threads.
 *
 * For emergencies only: DLLs aren't notified, so their shared state may be
 * left inconsistent. The process's handles are closed; child processes
 * keep running. A process can't terminate itself, nor a protected server
 * library (PSL).
 *
 * @param hProcess The process.
 * @param uExitCode Ignored: Windows CE doesn't support process exit codes.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI TerminateProcess(HANDLE hProcess,UINT uExitCode);
#include <kfuncs.h>
#ifdef _WIN32_WCE
static inline void ExitProcess(UINT code)
{
/**
 * This function returns a pseudohandle for the current process.
 *
 * A pseudohandle is a special constant that is interpreted as the current
 * process handle. The calling process can use this handle to specify its
 * own process whenever a process handle is required.
 *
 * This handle has the maximum possible access to the process object. A
 * process can also use the OpenProcess function to open a real handle to
 * itself.
 *
 * The pseudohandle need not be closed when it is no longer needed. Calling
 * the CloseHandle function with a pseudohandle has no effect.
 *
 * @return A pseudohandle to the current process indicates success.
 */
	TerminateProcess(GetCurrentProcess(), code);
	while (1);
}
// #define ExitProcess(CODE) do { TerminateProcess(GetCurrentProcess(), CODE); while (1); } while (0)
#else
DECLSPEC_NORETURN WINBASEAPI void WINAPI ExitProcess(UINT);
#endif
/**
 * Ends the calling thread.
 *
 * On Windows CE, calling this from the primary thread ends the
 * application.
 *
 * @param dwExitCode Exit code, read with GetExitCodeThread.
 */
DECLSPEC_NORETURN WINBASEAPI void WINAPI ExitThread(DWORD dwExitCode);
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR,LPWSTR,DWORD);
WINBASEAPI void WINAPI FatalAppExitA(UINT,LPCSTR);
WINBASEAPI void WINAPI FatalAppExitW(UINT,LPCWSTR);
WINBASEAPI void WINAPI FatalExit(int);
WINBASEAPI BOOL WINAPI FileEncryptionStatusA(LPCSTR,LPDWORD);
WINBASEAPI BOOL WINAPI FileEncryptionStatusW(LPCWSTR,LPDWORD);
WINBASEAPI BOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *,LPWORD,LPWORD);
/**
 * Converts a UTC file time to local time.
 *
 * Uses the current time zone and daylight saving setting.
 *
 * @param lpFileTime UTC time.
 * @param lpLocalFileTime Receives the local time. Must not be the same as
 *        lpFileTime.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
/**
 * Converts a FILETIME to a SYSTEMTIME.
 *
 * No time zone conversion is made.
 *
 * @param lpFileTime The file time.
 * @param lpSystemTime Receives the date and time.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI FindActCtxSectionGuid(DWORD,const GUID*,ULONG,const GUID*,PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI BOOL WINAPI FindActCtxSectionStringA(DWORD,const GUID*,ULONG,LPCSTR,PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI BOOL WINAPI FindActCtxSectionStringW(DWORD,const GUID*,ULONG,LPCWSTR,PACTCTX_SECTION_KEYED_DATA);
#endif
WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR);
/**
 * Closes a search handle from FindFirstFileW.
 *
 * @param hFindFile The search handle.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI FindClose(HANDLE hFindFile);
WINBASEAPI BOOL WINAPI FindCloseChangeNotification(HANDLE);
WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR,BOOL,DWORD);
WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR,BOOL,DWORD);
#if (_WIN32_WCE >= 0x0500)
WINBASEAPI HANDLE WINAPI FindFirstDevice(DeviceSearchType,LPCVOID,PDEVMGR_DEVICE_INFORMATION);
WINBASEAPI BOOL   WINAPI FindNextDevice(HANDLE,PDEVMGR_DEVICE_INFORMATION);
#endif
WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR,LPWIN32_FIND_DATAA);
/**
 * Starts a search for files and directories matching a name pattern.
 *
 * Continue with FindNextFileW and close with FindClose, not CloseHandle.
 * Matches on names only, not attributes.
 *
 * @param lpFileName Path and pattern, which may contain * and ?. Only the
 *        first MAX_PATH characters are used.
 * @param lpFindFileData Receives the first match.
 * @return The search handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError).
 */
WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lpFindFileData);
WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR,FINDEX_INFO_LEVELS,PVOID,FINDEX_SEARCH_OPS,PVOID,DWORD);
/**
 * Starts a file search using a name pattern and information level.
 *
 * Pass NULL for lpSearchFilter and zero for dwAdditionalFlags. If the file
 * system cannot perform the requested filter, the call fails with
 * ERROR_NOT_SUPPORTED. Continue with FindNextFile and close with FindClose.
 *
 * @param lpFileName Path and file-name pattern; wildcards are allowed.
 * @param fInfoLevelId Information level for the returned data.
 * @param lpFindFileData Receives the matching file information.
 * @param fSearchOp Additional search filter.
 * @param lpSearchFilter Reserved; set to NULL.
 * @param dwAdditionalFlags Unsupported; set to zero.
 * @return Search handle, or INVALID_HANDLE_VALUE on failure.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,PVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,PVOID lpSearchFilter,DWORD dwAdditionalFlags);
WINBASEAPI BOOL WINAPI FindFirstFreeAce(PACL,PVOID*);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPCSTR,DWORD);
WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPCWSTR,DWORD);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPSTR,LPSTR,DWORD);
WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPWSTR,LPWSTR,DWORD);
#endif
WINBASEAPI BOOL WINAPI FindNextChangeNotification(HANDLE);
WINBASEAPI BOOL WINAPI FindNextFileA(HANDLE,LPWIN32_FIND_DATAA);
/**
 * Returns the next match of a search started with FindFirstFileW.
 *
 * @param hFindFile The search handle.
 * @param lpFindFileData Receives the match.
 * @return TRUE on success, FALSE on failure. GetLastError returns
 *         ERROR_NO_MORE_FILES at the end of the search.
 */
WINBASEAPI BOOL WINAPI FindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI FindNextVolumeA(HANDLE,LPCSTR,DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeW(HANDLE,LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointA(HANDLE,LPSTR,DWORD);
WINBASEAPI BOOL WINAPI FindNextVolumeMountPointW(HANDLE,LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI FindVolumeClose(HANDLE);
WINBASEAPI BOOL WINAPI FindVolumeMountPointClose(HANDLE);
#endif
WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE,LPCSTR,LPCSTR);
/**
 * Locates a resource in a module.
 *
 * Load it with LoadResource. RT_ANICURSOR and RT_ANIICON are not
 * supported.
 *
 * @param hModule Module containing the resource. Must not be NULL.
 * @param lpName Resource name, or an ID from MAKEINTRESOURCE. ID 0 doesn't
 *        work.
 * @param lpType Resource type, such as RT_RCDATA, or a custom type name.
 * @return The resource, or NULL on failure (see GetLastError).
 */
WINBASEAPI HRSRC WINAPI FindResourceW(HINSTANCE hModule,LPCWSTR lpName,LPCWSTR lpType);
WINBASEAPI HRSRC WINAPI FindResourceExA(HINSTANCE,LPCSTR,LPCSTR,WORD);
WINBASEAPI HRSRC WINAPI FindResourceExW(HINSTANCE,LPCWSTR,LPCWSTR,WORD);
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR,LPCSTR,PVOID,DWORD);
WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR,LPCWSTR,PVOID,DWORD);
#endif
/**
 * Writes any buffered data for a file to the device.
 *
 * @param hFile File handle with GENERIC_WRITE access.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI FlushFileBuffers(HANDLE hFile);
/**
 * Flushes the instruction cache for a process.
 *
 * Call after writing code to memory, e.g. setting breakpoints, before it
 * runs.
 *
 * @param hProcess The process.
 * @param lpBaseAddress Start of the modified region, or NULL to flush the
 *        whole cache.
 * @param dwSize Size of the region in bytes.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI FlushInstructionCache(HANDLE hProcess,PCVOID lpBaseAddress,DWORD dwSize);
/**
 * Writes modified pages in a range of a mapped view back to the file.
 *
 * @param lpBaseAddress Start of the range, within a view from
 *        MapViewOfFile.
 * @param dwNumberOfBytesToFlush Bytes to flush, or 0 for the rest of the
 *        mapping.
 * @return Nonzero on success, 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI FlushViewOfFile(PCVOID lpBaseAddress,DWORD dwNumberOfBytesToFlush);
WINBASEAPI DWORD WINAPI FormatMessageA(DWORD,PCVOID,DWORD,DWORD,LPSTR,DWORD,va_list*);
/**
 * Formats a message from a string, a module's message table or the system
 * message table.
 *
 * Inserts use %1, %2 and so on, with optional printf-style formats such as
 * %1!d!. With FORMAT_MESSAGE_ALLOCATE_BUFFER, free the buffer with
 * LocalFree.
 *
 * @param dwFlags FORMAT_MESSAGE_FROM_STRING, _FROM_HMODULE or
 *        _FROM_SYSTEM, plus _ALLOCATE_BUFFER, _IGNORE_INSERTS and
 *        _ARGUMENT_ARRAY. The low byte sets the maximum line width
 *        (FORMAT_MESSAGE_MAX_WIDTH_MASK).
 * @param lpSource Format string or module handle, depending on dwFlags.
 *        Otherwise ignored.
 * @param dwMessageId Message ID. Ignored with FORMAT_MESSAGE_FROM_STRING.
 * @param dwLanguageId Language ID, or 0 for the default search.
 *        Ignored with FORMAT_MESSAGE_FROM_STRING.
 * @param lpBuffer Output buffer, or, with FORMAT_MESSAGE_ALLOCATE_BUFFER,
 *        a pointer to an LPWSTR that receives the allocated buffer.
 * @param nSize Size of lpBuffer in characters, or the minimum to allocate.
 * @param Arguments Insert values, as a va_list, or an array of 32-bit
 *        values with FORMAT_MESSAGE_ARGUMENT_ARRAY. May be NULL.
 * @return Characters written, excluding the terminator, or 0 on failure
 *         (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,PCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,DWORD nSize,va_list*Arguments);
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsA(LPSTR);
WINBASEAPI BOOL WINAPI FreeEnvironmentStringsW(LPWSTR);
/**
 * Decrements a DLL's reference count, unloading it when it reaches zero.
 *
 * Call once for each LoadLibrary.
 *
 * @param hLibModule Module handle from LoadLibrary.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI FreeLibrary(HMODULE hLibModule);
/**
 * Releases a DLL as FreeLibrary does, then ends the calling thread as
 * ExitThread does.
 *
 * Use it from a thread running code inside the DLL: calling FreeLibrary
 * then ExitThread there would return into an unloaded DLL.
 *
 * @param hLibModule The DLL, from LoadLibrary.
 * @param dwExitCode Exit code for the thread.
 *
 * @note Windows CE 3.0 only.
 */
DECLSPEC_NORETURN WINBASEAPI void WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dwExitCode);
#define FreeModule(m) FreeLibrary(m)
#define FreeProcInstance(p) (void)(p)
#ifndef XFree86Server
WINBASEAPI BOOL WINAPI FreeResource(HGLOBAL);
#endif /* ndef XFree86Server */
WINBASEAPI PVOID WINAPI FreeSid(PSID);
WINBASEAPI BOOL WINAPI GetAce(PACL,DWORD,LPVOID*);
WINBASEAPI BOOL WINAPI GetAclInformation(PACL,PVOID,DWORD,ACL_INFORMATION_CLASS);
WINBASEAPI UINT WINAPI GetAtomNameA(ATOM,LPSTR,int);
WINBASEAPI UINT WINAPI GetAtomNameW(ATOM,LPWSTR,int);
WINBASEAPI BOOL WINAPI GetBinaryTypeA(LPCSTR,PDWORD);
WINBASEAPI BOOL WINAPI GetBinaryTypeW(LPCWSTR,PDWORD);
WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
/**
 * Returns the current process's Unicode command-line string.
 *
 * @return Pointer to the command-line string.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
WINBASEAPI BOOL WINAPI GetCommConfig(HANDLE,LPCOMMCONFIG,PDWORD);
/**
 * Returns the event mask of a serial port.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpEvtMask Receives EV_* flags, as set by SetCommMask. Windows CE
 *        doesn't support EV_EVENT1, EV_EVENT2, EV_RX80FULL or EV_PERR.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetCommMask(HANDLE hFile,PDWORD lpEvtMask);
/**
 * Returns the modem control line states of a serial port.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpModemStat Receives MS_CTS_ON, MS_DSR_ON, MS_RING_ON and
 *        MS_RLSD_ON flags.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetCommModemStatus(HANDLE hFile,PDWORD lpModemStat);
/**
 * Returns the capabilities a serial port driver supports.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpCommProp Receives a COMMPROP with supported baud rates, data
 *        bits, buffer sizes and so on.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
/**
 * Returns the current settings of a serial port.
 *
 * Modify the result and pass it to SetCommState to change settings.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpDCB Receives the DCB.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
/**
 * Returns the read and write timeouts of a serial port.
 *
 * @param hFile Serial port handle from CreateFileW.
 * @param lpCommTimeouts Receives the COMMTIMEOUTS.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR,PDWORD);
WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR,PDWORD);
WINBASEAPI BOOL WINAPI GetComputerNameA(LPSTR,PDWORD);
WINBASEAPI BOOL WINAPI GetComputerNameW(LPWSTR,PDWORD);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT,LPSTR,LPDWORD);
WINBASEAPI BOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT,LPWSTR,LPDWORD);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetCurrentActCtx(HANDLE*);
#endif
WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD,LPSTR);
WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD,LPWSTR);
WINBASEAPI BOOL WINAPI GetCurrentHwProfileA(LPHW_PROFILE_INFOA);
WINBASEAPI BOOL WINAPI GetCurrentHwProfileW(LPHW_PROFILE_INFOW);
#ifndef _WIN32_WCE
/* These are defined in kfuncs.h.  */
WINBASEAPI HANDLE WINAPI GetCurrentProcess(void);
/**
 * This function returns the process identifier of the calling process.
 *
 * Until the process terminates, the process identifier uniquely identifies
 * the process throughout the system. In Windows CE, the processor
 * identifier returned from this function is the same as the process
 * handle.
 *
 * @return The identifier of the calling process indicates success.
 */
WINBASEAPI DWORD WINAPI GetCurrentProcessId(void);
/**
 * This function returns a pseudohandle for the current thread.
 *
 * A pseudohandle is a special constant that is interpreted as the current
 * thread handle. The calling thread can use this handle to specify itself
 * whenever a thread handle is required.
 *
 * This handle has the maximum possible access to the thread object.
 *
 * The function cannot be used by one thread to create a handle that can be
 * used by other threads to refer to the first thread. The handle is always
 * interpreted as referring to the thread that is using it. A thread can
 * create a "real" handle to itself that can be used by other threads, or
 * inherited by other processes, by specifying the pseudohandle as the
 * source handle in a call to the DuplicateHandle function.
 *
 * The pseudohandle need not be closed when it is no longer needed. Calling
 * the CloseHandle function with this handle has no effect.
 *
 * @return A pseudohandle for the current thread indicates success.
 */
WINBASEAPI HANDLE WINAPI GetCurrentThread(void);
/**
 * This function returns the thread identifier, which is used as a handle
 * of the calling thread.
 *
 * Until the thread terminates, the thread identifier uniquely identifies
 * the thread throughout the system. This identifier is also the handle of
 * the thread.
 *
 * @return The thread identifier of the calling thread indicates success.
 */
WINBASEAPI DWORD WINAPI GetCurrentThreadId(void);
#endif
#define GetCurrentTime GetTickCount
WINBASEAPI BOOL WINAPI GetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,PDWORD);
WINBASEAPI BOOL WINAPI GetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,PDWORD);
WINBASEAPI BOOL WINAPI GetDevicePowerState(HANDLE, BOOL*);
#if (_WIN32_WCE >= 0x0500)
WINBASEAPI BOOL WINAPI GetDeviceInformationByDeviceHandle(HANDLE,PDEVMGR_DEVICE_INFORMATION);
WINBASEAPI BOOL WINAPI GetDeviceInformationByFileHandle(HANDLE,PDEVMGR_DEVICE_INFORMATION);
#endif
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceA(LPCSTR,PDWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceW(LPCWSTR,PDWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExA(LPCSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);
/**
 * Returns the total and free space on a volume.
 *
 * Values are 64-bit: don't truncate them.
 *
 * @param lpDirectoryName Any directory on the volume, e.g. L"\\PC Card",
 *        or NULL for the object store.
 * @param lpFreeBytesAvailableToCaller Receives the free bytes available
 *        to the caller. Without quotas, the same as the total free.
 * @param lpTotalNumberOfBytes Receives the volume size.
 * @param lpTotalNumberOfFreeBytes Receives the free bytes, or NULL.
 * @return Nonzero on success, 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD,LPSTR);
WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD,LPWSTR);
#endif
WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR);
WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR);
WINBASEAPI LPCH WINAPI GetEnvironmentStrings(void);
WINBASEAPI LPCH WINAPI GetEnvironmentStringsA(void);
WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(void);
WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR,LPWSTR,DWORD);
/**
 * Returns a process's exit code.
 *
 * @param hProcess The process.
 * @param lpExitCode Receives STILL_ACTIVE if the process is running,
 *        otherwise the code from ExitThread, TerminateProcess, WinMain's
 *        return, or the unhandled exception.
 * @return Nonzero on success, 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetExitCodeProcess(HANDLE hProcess,PDWORD lpExitCode);
/**
 * Returns a thread's exit code.
 *
 * @param hThread The thread.
 * @param lpExitCode Receives STILL_ACTIVE if the thread is running,
 *        otherwise its exit code.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetExitCodeThread(HANDLE hThread,PDWORD lpExitCode);
WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR);
/**
 * Returns the attributes of a file or directory.
 *
 * @param lpFileName Path of the file or directory.
 * @return FILE_ATTRIBUTE_* flags, or 0xFFFFFFFF on failure (see
 *         GetLastError). Windows CE adds FILE_ATTRIBUTE_INROM for
 *         read-only ROM files, and FILE_ATTRIBUTE_ROMMODULE for
 *         execute-in-place ROM modules, which can't be opened with
 *         CreateFileW.
 */
WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);
WINBASEAPI BOOL WINAPI GetFileAttributesExA(LPCSTR,GET_FILEEX_INFO_LEVELS,PVOID);
/**
 * Retrieves standard attributes for a file or directory.
 *
 * Wildcards and the \\?\ path prefix are not supported. Paths are limited
 * to MAX_PATH characters.
 *
 * @param lpFileName File or directory path.
 * @param fInfoLevelId Attribute information level.
 * @param lpFileInformation Receives the requested information.
 * @return Nonzero on success, zero on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,PVOID lpFileInformation);
/**
 * Returns attributes, times, size and other information for an open file.
 *
 * @param hFile The file.
 * @param lpFileInformation Receives a BY_HANDLE_FILE_INFORMATION.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
#if (_WIN32_WINNT >= 0x0600)
/* http://msdn.microsoft.com/en-us/library/aa364953%28VS.85%29.aspx */
WINBASEAPI BOOL WINAPI GetFileInformationByHandleEx(HANDLE,FILE_INFO_BY_HANDLE_CLASS,LPVOID,DWORD);
#endif
WINBASEAPI BOOL WINAPI GetFileSecurityA(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetFileSecurityW(LPCWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
/**
 * Returns the size of a file.
 *
 * Not for non-seeking devices such as serial ports.
 *
 * @param hFile File handle with GENERIC_READ or GENERIC_WRITE access.
 * @param lpFileSizeHigh Receives the high 32 bits of the size, or NULL.
 * @return The low 32 bits of the size, or 0xFFFFFFFF on failure. When
 *         lpFileSizeHigh is non-NULL, 0xFFFFFFFF may be a valid size:
 *         check that GetLastError returns NO_ERROR.
 */
WINBASEAPI DWORD WINAPI GetFileSize(HANDLE hFile,PDWORD lpFileSizeHigh);
#if (_WIN32_WINNT >= 0x0500) 
WINBASEAPI BOOL WINAPI GetFileSizeEx(HANDLE,PLARGE_INTEGER);
#endif
/**
 * Returns a file's creation, last access and last write times, in UTC.
 *
 * @param hFile The file.
 * @param lpCreationTime Receives the creation time, or NULL.
 * @param lpLastAccessTime Receives the last access time, or NULL.
 * @param lpLastWriteTime Receives the last write time, or NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lpLastAccessTime,LPFILETIME lpLastWriteTime);
WINBASEAPI DWORD WINAPI GetFileType(HANDLE);
#if (_WIN32_WINNT >= 0x0600)
/* http://msdn.microsoft.com/en-us/library/aa364962%28VS.85%29.aspx */
WINBASEAPI DWORD WINAPI GetFinalPathNameByHandleA(HANDLE,LPSTR,DWORD,DWORD);
WINBASEAPI DWORD WINAPI GetFinalPathNameByHandleW(HANDLE,LPWSTR,DWORD,DWORD);
#endif
#define GetFreeSpace(w) (0x100000L)
WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR,DWORD,LPSTR,LPSTR*);
WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR,DWORD,LPWSTR,LPWSTR*);
WINBASEAPI BOOL WINAPI GetHandleInformation(HANDLE,PDWORD);
WINBASEAPI BOOL WINAPI GetKernelObjectSecurity(HANDLE,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
/**
 * Returns the calling thread's last error code.
 *
 * Call it straight away after a failed call, as other calls may change
 * it.
 *
 * @return The error code, such as ERROR_FILE_NOT_FOUND.
 */
WINBASEAPI DWORD WINAPI GetLastError(void);
WINBASEAPI DWORD WINAPI GetLengthSid(PSID);
/**
 * Returns the current local date and time.
 *
 * @param lpSystemTime Receives the local time.
 */
WINBASEAPI void WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
WINBASEAPI DWORD WINAPI GetLogicalDrives(void);
WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD,LPSTR);
WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD,LPWSTR);
#if (_WIN32_WINNT >= 0x0500 || _WIN32_WINDOWS >= 0x0410)
WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR,LPWSTR,DWORD);
#endif
WINBASEAPI BOOL WINAPI GetMailslotInfo(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI DWORD WINAPI GetModuleFileNameA(HINSTANCE,LPSTR,DWORD);
/**
 * Returns the full path of a loaded module.
 *
 * @param hModule Module handle, or NULL for the calling process's
 *        executable.
 * @param lpFilename Receives the path.
 * @param nSize Size of lpFilename in characters.
 * @return Characters copied, excluding the terminator, or 0 on failure
 *         (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI DWORD WINAPI GetModuleFileNameW(HINSTANCE hModule,LPWSTR lpFilename,DWORD nSize);
WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR);
/**
 * Gets the handle of a module already mapped into the current process.
 *
 * Only the file name is used; paths are ignored. If the extension is
 * omitted, .DLL is appended. The returned handle does not increment the
 * module reference count.
 *
 * @param lpModuleName DLL or CPL file name, or NULL for the process image.
 * @return Module handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GetModuleHandleExA(DWORD,LPCSTR,HMODULE*);
WINBASEAPI BOOL WINAPI GetModuleHandleExW(DWORD,LPCWSTR,HMODULE*);
#endif
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateA(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD,LPSTR,DWORD);
WINBASEAPI BOOL WINAPI GetNamedPipeHandleStateW(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD,LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI GetNamedPipeInfo(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO);
#endif
WINBASEAPI BOOL WINAPI GetNumberOfEventLogRecords(HANDLE,PDWORD);
WINBASEAPI BOOL WINAPI GetOldestEventLogRecord(HANDLE,PDWORD);
WINBASEAPI BOOL WINAPI GetOverlappedResult(HANDLE,LPOVERLAPPED,PDWORD,BOOL);
WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE);
WINBASEAPI BOOL WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR,LPCSTR,INT,LPCSTR);
WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR,LPCWSTR,INT,LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR,LPSTR,DWORD,LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR,LPWSTR,DWORD,LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR,DWORD,LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR,DWORD,LPCWSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPSTR,DWORD,LPCSTR);
WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,DWORD,LPCWSTR);
WINBASEAPI BOOL WINAPI GetPrivateProfileStructA(LPCSTR,LPCSTR,LPVOID,UINT,LPCSTR);
WINBASEAPI BOOL WINAPI GetPrivateProfileStructW(LPCWSTR,LPCWSTR,LPVOID,UINT,LPCWSTR);
#ifdef _WIN32_WCE
#if (_WIN32_WCE >= 0x300)
/**
 * Returns the address of an exported function using an ANSI export name.
 *
 * The name must match the DLL's export spelling and case. An ordinal may be
 * passed in the low word with the high word set to zero.
 *
 * @param hModule Module handle.
 * @param lpProcName ANSI export name or ordinal.
 * @return Function address, or NULL on failure; see GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI FARPROC WINAPI GetProcAddressA(HINSTANCE hModule,LPCSTR lpProcName);
#endif
/**
 * Returns the address of a function exported by a DLL.
 *
 * On Windows CE, the name is a Unicode string. Desktop Win32's
 * GetProcAddress takes an ANSI name.
 *
 * @param hModule Module handle from LoadLibrary.
 * @param lpProcName Export name, matching the case of the EXPORTS entry,
 *        or an ordinal in the low word with a zero high word.
 * @return The function address, or NULL on failure (see GetLastError).
 */
WINBASEAPI FARPROC WINAPI GetProcAddressW(HINSTANCE hModule,LPCWSTR lpProcName);
#else
WINBASEAPI FARPROC WINAPI GetProcAddress(HINSTANCE,LPCSTR);
#endif
WINBASEAPI BOOL WINAPI GetProcessAffinityMask(HANDLE,PDWORD,PDWORD);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI GetProcessDEPPolicy (HANDLE, LPDWORD, PBOOL);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetProcessHandleCount(HANDLE,PDWORD);
#endif
/**
 * Returns the calling process's default heap.
 *
 * Use with HeapAlloc, HeapFree and so on. Don't destroy it.
 *
 * @return The heap, or NULL on failure (see GetLastError).
 */
WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD,PHANDLE);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI DWORD WINAPI GetProcessId(HANDLE);
#endif
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GetProcessIoCounters(HANDLE,PIO_COUNTERS);
#endif
WINBASEAPI BOOL WINAPI GetProcessPriorityBoost(HANDLE,PBOOL);
WINBASEAPI BOOL WINAPI GetProcessShutdownParameters(PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetProcessTimes(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME,LPFILETIME);
/**
 * Returns the Windows version a process's executable was built for.
 *
 * @param ProcessId The process, or 0 for the calling process.
 * @return The major version in the high word and the minor in the low
 *         word, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD ProcessId);
WINBASEAPI HWINSTA WINAPI GetProcessWindowStation(void);
WINBASEAPI BOOL WINAPI GetProcessWorkingSetSize(HANDLE,PSIZE_T,PSIZE_T);
WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR,LPCSTR,INT);
WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR,LPCWSTR,INT);
WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR,LPWSTR,DWORD);
WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI GetQueuedCompletionStatus(HANDLE,PDWORD,PULONG_PTR,LPOVERLAPPED*,DWORD);
WINBASEAPI BOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR_CONTROL,PDWORD);
WINBASEAPI BOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR,LPBOOL,PACL*,LPBOOL);
WINBASEAPI BOOL WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR,PSID*,LPBOOL);
WINBASEAPI DWORD WINAPI GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR);
WINBASEAPI BOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR,PSID*,LPBOOL);
WINBASEAPI BOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR,LPBOOL,PACL*,LPBOOL);
WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR,LPWSTR,DWORD);
WINBASEAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID);
WINBASEAPI DWORD WINAPI GetSidLengthRequired(UCHAR);
WINBASEAPI PDWORD WINAPI GetSidSubAuthority(PSID,DWORD);
WINBASEAPI PUCHAR WINAPI GetSidSubAuthorityCount(PSID);
WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA);
WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW);
WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI DEP_SYSTEM_POLICY_TYPE WINAPI GetSystemDEPPolicy (void);
#endif
WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR,UINT);
WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR,UINT);
/**
 * Returns information about the system, such as processor type, page
 * size and address range.
 *
 * @param lpSystemInfo Receives a SYSTEM_INFO.
 */
WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
#ifndef _WIN32_WCE
WINBASEAPI BOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS);
#else
/**
 * Retrieves extended battery and power status.
 *
 * @param pSystemPowerStatusEx2 Receives the power status.
 * @param dwLen Buffer size in bytes.
 * @param fUpdate TRUE to refresh from the driver, FALSE to use cached data
 *        that may be several seconds old.
 * @return Number of bytes returned, or 0 on failure.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI DWORD GetSystemPowerStatusEx2(PSYSTEM_POWER_STATUS_EX2 pSystemPowerStatusEx2,DWORD dwLen,BOOL fUpdate);
/**
 * Returns the power status: AC or battery, charging state and the
 * remaining life of the main and backup batteries.
 *
 * Windows CE specific. Not supported under emulation.
 *
 * @param pstatus Receives a SYSTEM_POWER_STATUS_EX.
 * @param fUpdate TRUE to read fresh values from the driver, FALSE for
 *        cached values that may be a few seconds old.
 * @return TRUE on success, FALSE on failure.
 */
WINBASEAPI BOOL GetSystemPowerStatusEx(PSYSTEM_POWER_STATUS_EX pstatus,BOOL fUpdate);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetSystemRegistryQuota(PDWORD,PDWORD);
#endif
/**
 * Returns the current date and time in UTC.
 *
 * @param lpSystemTime Receives the UTC time.
 */
WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetSystemTimes(LPFILETIME,LPFILETIME,LPFILETIME);
#endif
WINBASEAPI BOOL WINAPI GetSystemTimeAdjustment(PDWORD,PDWORD,PBOOL);
WINBASEAPI void WINAPI GetSystemTimeAsFileTime(LPFILETIME);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR,UINT);
WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR,UINT);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR,UINT);
WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR,UINT);
#endif
WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE,DWORD,PDWORD,PVOID);
WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE,DWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE);
WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR,LPCSTR,UINT,LPSTR);
/**
 * Creates a temporary-file name in a directory.
 *
 * The prefix uses its first three characters. With nonzero uUnique, the
 * function does not create the file or check uniqueness. With zero, it
 * creates and closes a unique empty file. CE pads the hexadecimal suffix
 * to four digits; power-down does not delete these files.
 *
 * @param lpPathName Directory for the file; must not be NULL.
 * @param lpPrefixString Prefix string.
 * @param uUnique Nonzero suffix to use, or 0 to generate one and create the file.
 * @param lpTempFileName Receives the path in a MAX_PATH-sized buffer.
 * @return Numeric suffix used, or 0 on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI UINT WINAPI GetTempFileNameW(LPCWSTR lpPathName,LPCWSTR lpPrefixString,UINT uUnique,LPWSTR lpTempFileName);
WINBASEAPI DWORD WINAPI GetTempPathA(DWORD,LPSTR);
/**
 * Returns the directory for temporary files.
 *
 * The path ends with a backslash.
 *
 * @param nBufferLength Size of lpBuffer in characters.
 * @param lpBuffer Receives the path.
 * @return Characters copied, excluding the terminator. If the buffer is
 *         too small, the size needed. 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI DWORD WINAPI GetTempPathW(DWORD nBufferLength,LPWSTR lpBuffer);
/**
 * Returns the register context of a thread.
 *
 * For debuggers. Suspend the thread first, and set ContextFlags to choose
 * which registers to read.
 *
 * @param hThread The thread.
 * @param lpContext CONTEXT with ContextFlags set. Receives the registers.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetThreadIOPendingFlag(HANDLE,PBOOL);
#endif
/**
 * Returns a thread's priority level.
 *
 * Windows CE has no priority classes: threads are scheduled by thread
 * priority alone. A THREAD_PRIORITY_TIME_CRITICAL thread runs until it
 * yields, so can starve the rest of the system.
 *
 * @param hThread The thread.
 * @return THREAD_PRIORITY_TIME_CRITICAL, _HIGHEST, _ABOVE_NORMAL, _NORMAL,
 *         _BELOW_NORMAL, _LOWEST, _ABOVE_IDLE or _IDLE, or
 *         THREAD_PRIORITY_ERROR_RETURN on failure.
 */
WINBASEAPI int WINAPI GetThreadPriority(HANDLE hThread);
WINBASEAPI BOOL WINAPI GetThreadPriorityBoost(HANDLE,PBOOL);
WINBASEAPI BOOL WINAPI GetThreadSelectorEntry(HANDLE,DWORD,LPLDT_ENTRY);
/**
 * Retrieves creation, exit, kernel and user time for a thread.
 *
 * Times are FILETIME values in 100-nanosecond units. Creation and exit
 * times count from 1 January 1601; the exit time is undefined until the
 * thread exits. On Windows CE 1.0 and 2.0 only lpUserTime is supported:
 * it receives the thread's total running time, with no split between
 * user and kernel mode, and isn't valid once the thread exits. The other
 * times are unsupported and set to zero.
 *
 * @param hThread Thread handle with THREAD_QUERY_INFORMATION access.
 * @param lpCreationTime Receives the creation time.
 * @param lpExitTime Receives the exit time.
 * @param lpKernelTime Receives time spent in kernel mode.
 * @param lpUserTime Receives time spent in user mode.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
/**
 * Returns the number of milliseconds since the device was started.
 *
 * Wraps to zero after about 49.7 days. The count stops while the device is
 * switched off and carries on from the same value when it's switched back
 * on, so it only resets on a reboot. Use it for intervals, not wall-clock
 * time.
 *
 * @return Milliseconds elapsed since boot.
 */
WINBASEAPI DWORD WINAPI GetTickCount(VOID);
/**
 * Gets the current time-zone settings used to convert between UTC and local
 * time.
 *
 * UTC = local time + bias, with the bias in minutes. Windows CE always
 * returns TIME_ZONE_ID_UNKNOWN, never TIME_ZONE_ID_STANDARD or
 * TIME_ZONE_ID_DAYLIGHT, so don't use the return value to tell whether
 * daylight saving is in effect.
 *
 * @param lpTimeZoneInformation TIME_ZONE_INFORMATION that receives the
 *        settings.
 * @return TIME_ZONE_ID_UNKNOWN, or 0xFFFFFFFF on failure (see
 *         GetLastError).
 */
WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
WINBASEAPI BOOL WINAPI GetTokenInformation(HANDLE,TOKEN_INFORMATION_CLASS,PVOID,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetUserNameA (LPSTR,PDWORD);
WINBASEAPI BOOL WINAPI GetUserNameW(LPWSTR,PDWORD);
WINBASEAPI DWORD WINAPI GetVersion(void);
WINBASEAPI BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA);
/**
 * Gets the operating system version.
 *
 * Set dwOSVersionInfoSize to sizeof(OSVERSIONINFOW) before calling.
 * dwPlatformId is VER_PLATFORM_WIN32_CE. The Japanese Windows CE 2.01
 * reports itself as version 2.0. Prefer checking for a needed feature
 * directly when possible.
 *
 * @param lpVersionInformation OSVERSIONINFOW that receives the version,
 *        with dwOSVersionInfoSize set.
 * @return TRUE on success, FALSE on failure, such as dwOSVersionInfoSize
 *        being too small (see GetLastError).
 */
WINBASEAPI BOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
WINBASEAPI BOOL WINAPI GetVolumeInformationA(LPCSTR,LPSTR,DWORD,PDWORD,PDWORD,PDWORD,LPSTR,DWORD);
WINBASEAPI BOOL WINAPI GetVolumeInformationW(LPCWSTR,LPWSTR,DWORD,PDWORD,PDWORD,PDWORD,LPWSTR,DWORD);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR,LPSTR,DWORD);
WINBASEAPI BOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR,LPWSTR,DWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNameW(LPCWSTR,LPWSTR,DWORD);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR,LPSTR,DWORD,PDWORD);
WINBASEAPI BOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR,LPWSTR,DWORD,PDWORD);
#endif
WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR,UINT);
WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR,UINT);
/**
 * Gets the identifiers of the thread and process that created a window.
 *
 * @param hWnd The window.
 * @param lpdwProcessId Receives the process identifier, or NULL if not
 *        needed.
 * @return The identifier of the thread that created the window.
 */
WINBASEAPI DWORD WINAPI GetWindowThreadProcessId(HWND hWnd,PDWORD lpdwProcessId);
WINBASEAPI UINT WINAPI GetWriteWatch(DWORD,PVOID,SIZE_T,PVOID*,PULONG_PTR,PULONG);
WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI GlobalAddAtomW( LPCWSTR);
WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD); /* Obsolete: Has no effect. */
WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM);
#define GlobalDiscard(hMem) GlobalReAlloc((hMem), 0, GMEM_MOVEABLE)
WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR);
WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR);
WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL); /* Obsolete: Has no effect. */
WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM,LPSTR,int);
WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM,LPWSTR,int);
#ifndef _WIN32_WCE
WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT,DWORD);
WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL);
WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL,DWORD,UINT);
WINBASEAPI HGLOBAL WINAPI GlobalHandle(PCVOID);
WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL);
WINBASEAPI BOOL WINAPI GlobalUnlock(HGLOBAL); 
WINBASEAPI DWORD WINAPI GlobalSize(HGLOBAL);
WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL); /* Obsolete: Has no effect. */
#else
# define GlobalAlloc(flags, cb) LocalAlloc(flags, cb)
# define GlobalFree(h) LocalFree(h)
# define GlobalReAlloc(h, cb, flags) LocalReAlloc(h, cb, flags)
# define GlobalHandle(lp) LocalHandle(lp)
# define GlobalLock(lp) LocalLock(lp)
# define GlobalUnlock(lp) LocalUnlock(lp)
# define GlobalSize(lp) LocalSize(lp)
# define GlobalFlags(lp) LocalFlags(lp)
#endif
/**
 * Gets the amount of physical and virtual memory in use and available.
 *
 * Set dwLength to sizeof(MEMORYSTATUS) before calling.
 *
 * @param lpmst MEMORYSTATUS that receives the figures.
 */
WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpmst);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX);
#endif
WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL); /* Obsolete: Has no effect. */
WINBASEAPI BOOL WINAPI GlobalUnWire(HGLOBAL); /* Obsolete: Has no effect. */
WINBASEAPI PVOID WINAPI GlobalWire(HGLOBAL); /* Obsolete: Has no effect. */
#define HasOverlappedIoCompleted(lpOverlapped)  ((lpOverlapped)->Internal != STATUS_PENDING)
/**
 * Allocates a fixed (non-movable) block from a heap.
 *
 * The block may be larger than requested; HeapSize gives the real size.
 * Memory isn't zeroed unless HEAP_ZERO_MEMORY is given. Free with HeapFree.
 *
 * @param hHeap Heap from HeapCreate or GetProcessHeap.
 * @param dwFlags 0, or HEAP_NO_SERIALIZE and/or HEAP_ZERO_MEMORY. These
 *        override the heap's own options. Windows CE doesn't support
 *        HEAP_GENERATE_EXCEPTIONS.
 * @param dwBytes Size in bytes.
 * @return The block, or NULL on failure.
 */
WINBASEAPI PVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,DWORD dwBytes);
SIZE_T WINAPI HeapCompact(HANDLE,DWORD);
/**
 * Creates a private heap for the calling process.
 *
 * Reserves dwMaximumSize of address space and commits dwInitialSize up
 * front, committing more as allocations need it. Both sizes are rounded up
 * to a whole page. Some of the heap goes on bookkeeping, so a block as big
 * as the maximum size won't fit. A heap created by a DLL belongs to the
 * process that called it. Destroy with HeapDestroy.
 *
 * @param flOptions 0, or HEAP_NO_SERIALIZE to skip locking when only one
 *        thread uses the heap. Windows CE doesn't support
 *        HEAP_GENERATE_EXCEPTIONS.
 * @param dwInitialSize Bytes to commit initially.
 * @param dwMaximumSize Bytes to reserve, or 0 for a heap limited only by
 *        available memory.
 * @return The heap, or NULL on failure.
 */
WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,DWORD dwInitialSize,DWORD dwMaximumSize);
/**
 * Destroys a private heap and releases all of its memory.
 *
 * Blocks still allocated from the heap don't need freeing first.
 *
 * @param hHeap Heap from HeapCreate.
 * @return TRUE on success, FALSE on failure.
 */
WINBASEAPI BOOL WINAPI HeapDestroy(HANDLE hHeap);
/**
 * Frees a block allocated with HeapAlloc or HeapReAlloc.
 *
 * @param hHeap The heap the block came from.
 * @param dwFlags 0, or HEAP_NO_SERIALIZE.
 * @param lpMem The block.
 * @return TRUE on success, FALSE on failure.
 */
WINBASEAPI BOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,PVOID lpMem);
WINBASEAPI BOOL WINAPI HeapLock(HANDLE);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI HeapQueryInformation(HANDLE,HEAP_INFORMATION_CLASS,PVOID,SIZE_T,PSIZE_T);
#endif
/**
 * Resizes a block allocated from a heap.
 *
 * The block may move when it grows unless HEAP_REALLOC_IN_PLACE_ONLY is
 * given, so use the returned pointer. On failure the original block is
 * left as it was. Free with HeapFree.
 *
 * @param hHeap The heap the block came from.
 * @param dwFlags 0, or any of HEAP_NO_SERIALIZE, HEAP_REALLOC_IN_PLACE_ONLY
 *        (fail rather than move) and HEAP_ZERO_MEMORY (zero the added
 *        bytes). Windows CE doesn't support HEAP_GENERATE_EXCEPTIONS.
 * @param lpMem Block from HeapAlloc or HeapReAlloc.
 * @param dwBytes New size in bytes, larger or smaller.
 * @return The resized block, or NULL on failure.
 */
WINBASEAPI PVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,PVOID lpMem,DWORD dwBytes);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI HeapSetInformation(HANDLE,HEAP_INFORMATION_CLASS,PVOID,SIZE_T);
#endif
/**
 * Returns the size of a block allocated from a heap.
 *
 * The size may be more than was asked for.
 *
 * @param hHeap The heap the block came from.
 * @param dwFlags 0, or HEAP_NO_SERIALIZE.
 * @param lpMem Block from HeapAlloc or HeapReAlloc.
 * @return The size in bytes, or 0xFFFFFFFF on failure. Failure doesn't set
 *         the last error.
 */
WINBASEAPI DWORD WINAPI HeapSize(HANDLE hHeap,DWORD dwFlags,PCVOID lpMem);
WINBASEAPI BOOL WINAPI HeapUnlock(HANDLE);
/**
 * Checks a heap, or one block in it, for corruption.
 *
 * @param hHeap The heap to check.
 * @param dwFlags 0, or HEAP_NO_SERIALIZE.
 * @param lpMem A block to check, or NULL to check the whole heap.
 * @return TRUE if the heap or block is valid, FALSE if not.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,PCVOID lpMem);
WINBASEAPI BOOL WINAPI HeapWalk(HANDLE,LPPROCESS_HEAP_ENTRY);
WINBASEAPI BOOL WINAPI ImpersonateLoggedOnUser(HANDLE);
WINBASEAPI BOOL WINAPI ImpersonateNamedPipeClient(HANDLE);
WINBASEAPI BOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL);
WINBASEAPI BOOL WINAPI InitAtomTable(DWORD);
WINBASEAPI BOOL WINAPI InitializeAcl(PACL,DWORD,DWORD);
/**
 * Initialises a critical section object.
 *
 * Call once before EnterCriticalSection or LeaveCriticalSection, and
 * release with DeleteCriticalSection. Critical sections work between
 * threads of one process only; use a mutex across processes. Treat the
 * structure as opaque and don't move or copy it.
 *
 * @param lpCriticalSection The critical section, allocated by the caller.
 */
WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI BOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION,DWORD);
WINBASEAPI DWORD WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION,DWORD);
WINBASEAPI BOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR,DWORD);
WINBASEAPI BOOL WINAPI InitializeSid (PSID,PSID_IDENTIFIER_AUTHORITY,BYTE);

#if !(__USE_NTOSKRNL__)
/* CAREFUL: These are exported from ntoskrnl.exe and declared in winddk.h
   as __fastcall functions, but are  exported from kernel32.dll as __stdcall */
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI VOID WINAPI InitializeSListHead(PSLIST_HEADER);
#endif
#ifndef __INTERLOCKED_DECLARED
#define __INTERLOCKED_DECLARED
LONG WINAPI InterlockedCompareExchange(LONG volatile *,LONG,LONG);
/* PVOID WINAPI InterlockedCompareExchangePointer(PVOID*,PVOID,PVOID); */
#define InterlockedCompareExchangePointer(d,e,c) \
    (PVOID)InterlockedCompareExchange((LONG volatile *)(d),(LONG)(e),(LONG)(c))
/**
 * Atomically decrements a 32-bit variable.
 *
 * Safe against other Interlocked* calls on the same variable, including
 * from other processes if it's in shared memory. The variable must be
 * 32-bit aligned.
 *
 * @param lpAddend The variable to decrement.
 * @return Zero if the result is zero, otherwise a value with the same sign
 *         as the result. It isn't guaranteed to equal the result.
 */
LONG WINAPI InterlockedDecrement(LONG volatile *lpAddend);
/**
 * Atomically sets a 32-bit variable and returns its previous value.
 *
 * The variable must be 32-bit aligned.
 *
 * @param Target The variable to set.
 * @param Value The new value.
 * @return The previous value.
 */
LONG WINAPI InterlockedExchange(LONG volatile *Target,LONG Value);
/* PVOID WINAPI InterlockedExchangePointer(PVOID*,PVOID); */
#define InterlockedExchangePointer(t,v) \
    (PVOID)InterlockedExchange((LONG volatile *)(t),(LONG)(v))
LONG WINAPI InterlockedExchangeAdd(LONG volatile *,LONG);
#if (_WIN32_WINNT >= 0x0501)
PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER);
#endif
/**
 * Atomically increments a 32-bit variable.
 *
 * Safe against other Interlocked* calls on the same variable, including
 * from other processes if it's in shared memory. The variable must be
 * 32-bit aligned.
 *
 * @param lpAddend The variable to increment.
 * @return Zero if the result is zero, otherwise a value with the same sign
 *         as the result. It isn't guaranteed to equal the result.
 */
LONG WINAPI InterlockedIncrement(LONG volatile *lpAddend);
#if (_WIN32_WINNT >= 0x0501)
PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER);
PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER,PSLIST_ENTRY);
#endif
#endif /* __INTERLOCKED_DECLARED */
#endif /*  __USE_NTOSKRNL__ */

/**
 * Checks whether the calling process can read memory at an address.
 *
 * Only the single address is checked. Another thread can change access at
 * any time, so use structured exception handling when it matters.
 *
 * @param lpfn The address to check.
 * @return FALSE if the memory is readable, TRUE if not.
 */
WINBASEAPI BOOL WINAPI IsBadCodePtr(FARPROC lpfn);
WINBASEAPI BOOL WINAPI IsBadHugeReadPtr(PCVOID,UINT);
WINBASEAPI BOOL WINAPI IsBadHugeWritePtr(PVOID,UINT);
/**
 * Checks whether the calling process can read a range of memory.
 *
 * Another thread can change access at any time, so use structured
 * exception handling when it matters.
 *
 * @param lp Start of the range.
 * @param ucb Size of the range in bytes. 0 always gives FALSE.
 * @return FALSE if every byte is readable, TRUE if any isn't.
 */
WINBASEAPI BOOL WINAPI IsBadReadPtr(PCVOID lp,UINT ucb);
WINBASEAPI BOOL WINAPI IsBadStringPtrA(LPCSTR,UINT);
WINBASEAPI BOOL WINAPI IsBadStringPtrW(LPCWSTR,UINT);
/**
 * Checks whether the calling process can write to a range of memory.
 *
 * Another thread can change access at any time, so use structured
 * exception handling when it matters.
 *
 * @param lp Start of the range.
 * @param ucb Size of the range in bytes. 0 always gives FALSE.
 * @return FALSE if every byte is writable, TRUE if any isn't.
 */
WINBASEAPI BOOL WINAPI IsBadWritePtr(PVOID lp,UINT ucb);
WINBASEAPI BOOL WINAPI IsDebuggerPresent(void);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL IsProcessInJob(HANDLE,HANDLE,PBOOL);
#endif
WINBASEAPI BOOL WINAPI IsProcessorFeaturePresent(DWORD);
WINBASEAPI BOOL WINAPI IsSystemResumeAutomatic(void);
WINBASEAPI BOOL WINAPI IsTextUnicode(PCVOID,int,LPINT);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI IsTokenRestricted(HANDLE);
#endif
WINBASEAPI BOOL WINAPI IsValidAcl(PACL);
WINBASEAPI BOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR);
WINBASEAPI BOOL WINAPI IsValidSid(PSID);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI IsWow64Process(HANDLE,PBOOL);
#endif
/**
 * Releases a critical section held by the calling thread.
 *
 * Call once for each EnterCriticalSection. Leaving a critical section the
 * thread doesn't own can leave other threads waiting forever.
 *
 * @param lpCriticalSection The critical section.
 */
WINBASEAPI void WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
#define LimitEmsPages(n)
WINBASEAPI HINSTANCE WINAPI LoadLibraryA(LPCSTR);
WINBASEAPI HINSTANCE WINAPI LoadLibraryExA(LPCSTR,HANDLE,DWORD);
/**
 * Maps a DLL or executable module into the calling process.
 *
 * hFile must be NULL. DONT_RESOLVE_DLL_REFERENCES skips DllMain and
 * loading referenced modules; LOAD_LIBRARY_AS_DATAFILE maps a module for
 * resource access without executing it. LOAD_WITH_ALTERED_SEARCH_PATH is
 * unsupported. The first load's flags govern later loads of the same module.
 *
 * @param lpLibFileName Module file name or path.
 * @param hFile Reserved; set to NULL.
 * @param dwFlags Loading behavior flags, or 0 for LoadLibrary behavior.
 * @return Module handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI HINSTANCE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
/**
 * Loads a DLL or other executable module into the calling process.
 *
 * Without a path, Windows CE looks in the root of a PC Card RAM expansion
 * card (if any), then \Windows, then the root directory; there's no way to
 * set a search path. Without a path or extension, ".dll" is appended. Only
 * the base name identifies a module: once Sample.dll is loaded, loading
 * Sample.cpl or \MyDir\Sample.dll returns the same module. Loading an
 * already loaded module increments its reference count. Release with
 * FreeLibrary; get exports with GetProcAddress. An .exe can be loaded for
 * its resources.
 *
 * @param lpLibFileName File name of the module.
 * @return The module handle, or NULL on failure (see GetLastError).
 */
WINBASEAPI HINSTANCE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
WINBASEAPI DWORD WINAPI LoadModule(LPCSTR,PVOID);
/**
 * Loads a resource and returns a handle to its data.
 *
 * The data is freed by the system. On Windows CE hModule must not be NULL.
 *
 * @param hModule Module containing the resource. Must not be NULL.
 * @param hResInfo Resource from FindResource.
 * @return The resource data, or NULL on failure (see GetLastError).
 */
WINBASEAPI HGLOBAL WINAPI LoadResource(HINSTANCE hModule,HRSRC hResInfo);
/**
 * Allocates a block from the process's local heap.
 *
 * Windows CE only supports fixed memory: the handle is a pointer to the
 * block. The local heap is limited to 1MB; use HeapCreate for more, each
 * heap again up to 1MB. The block may be larger than requested (see
 * LocalSize). Free with LocalFree.
 *
 * @param uFlags LMEM_FIXED (or 0), optionally with LMEM_ZEROINIT, or LPTR
 *        for both. Windows CE doesn't support LMEM_MOVEABLE, LHND,
 *        NONZEROLHND, NONZEROLPTR, LMEM_DISCARDABLE, LMEM_NOCOMPACT or
 *        LMEM_NODISCARD.
 * @param uBytes Size in bytes.
 * @return The block, or NULL on failure (see GetLastError).
 */
WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,SIZE_T uBytes);
WINBASEAPI SIZE_T WINAPI LocalCompact(UINT); /* Obsolete: Has no effect. */
WINBASEAPI HLOCAL LocalDiscard(HLOCAL);
/**
 * Converts a local file time to UTC.
 *
 * @param lpLocalFileTime The local time.
 * @param lpFileTime Receives the UTC time. Must not be the same structure
 *        as lpLocalFileTime.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
#ifndef _WIN32_WCE
WINBASEAPI UINT WINAPI LocalFlags(HLOCAL); /* Obsolete: Has no effect. */
#else
# define LocalFlags(H) ((UINT)0)
#endif
/**
 * Frees a block allocated with LocalAlloc or LocalReAlloc.
 *
 * @param hMem The block, or NULL to do nothing.
 * @return NULL on success, or hMem on failure (see GetLastError).
 */
WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
#ifndef _WIN32_WCE
WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID);
#else
# define LocalHandle(H) ((HLOCAL)(H))
#endif
#ifndef _WIN32_WCE
WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL);
#else
# define LocalLock(H) ((LPVOID)(H))
#endif
/**
 * Resizes a block allocated with LocalAlloc.
 *
 * The block only moves if LMEM_MOVEABLE is given, so without it growing a
 * block may fail. Use the returned handle. On the device, hMem may be NULL
 * to allocate a new block; the emulator and Windows NT reject that.
 *
 * @param hMem Block from LocalAlloc or LocalReAlloc.
 * @param uBytes New size in bytes, larger or smaller.
 * @param uFlags LMEM_MOVEABLE to allow the block to move and LMEM_ZEROINIT
 *        to zero the added bytes. Windows CE doesn't support
 *        LMEM_DISCARDABLE or LMEM_NOCOMPACT.
 * @return The resized block, or NULL on failure (see GetLastError).
 */
WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,SIZE_T uBytes,UINT uFlags);
WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL,UINT);  /* Obsolete: Has no effect. */
/**
 * Returns the size of a block allocated with LocalAlloc or LocalReAlloc.
 *
 * The size may be more than was asked for.
 *
 * @param hMem The block.
 * @return The size in bytes, or 0 if the handle isn't valid (see
 *         GetLastError).
 */
WINBASEAPI UINT WINAPI LocalSize(HLOCAL hMem);
#ifndef _WIN32_WCE
WINBASEAPI BOOL WINAPI LocalUnlock(HLOCAL);
#else
# define LocalUnlock(H) ((BOOL)0)
#endif
WINBASEAPI BOOL WINAPI LockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
WINBASEAPI BOOL WINAPI LockFileEx(HANDLE,DWORD,DWORD,DWORD,DWORD,LPOVERLAPPED);
#ifdef _WIN32_WCE
#define LockResource(h) ((PVOID)(h))
#else
WINBASEAPI PVOID WINAPI LockResource(HGLOBAL);
#endif
#define LockSegment(w) GlobalFix((HANDLE)(w)) /* Obsolete: Has no effect. */
WINBASEAPI BOOL WINAPI LogonUserA(LPSTR,LPSTR,LPSTR,DWORD,DWORD,PHANDLE);
WINBASEAPI BOOL WINAPI LogonUserW(LPWSTR,LPWSTR,LPWSTR,DWORD,DWORD,PHANDLE);
WINBASEAPI BOOL WINAPI LookupAccountNameA(LPCSTR,LPCSTR,PSID,PDWORD,LPSTR,PDWORD,PSID_NAME_USE);
WINBASEAPI BOOL WINAPI LookupAccountNameW(LPCWSTR,LPCWSTR,PSID,PDWORD,LPWSTR,PDWORD,PSID_NAME_USE);
WINBASEAPI BOOL WINAPI LookupAccountSidA(LPCSTR,PSID,LPSTR,PDWORD,LPSTR,PDWORD,PSID_NAME_USE);
WINBASEAPI BOOL WINAPI LookupAccountSidW(LPCWSTR,PSID,LPWSTR,PDWORD,LPWSTR,PDWORD,PSID_NAME_USE);
WINBASEAPI BOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR,LPCSTR,LPSTR,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR,LPCWSTR,LPWSTR,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI LookupPrivilegeNameA(LPCSTR,PLUID,LPSTR,PDWORD);
WINBASEAPI BOOL WINAPI LookupPrivilegeNameW(LPCWSTR,PLUID,LPWSTR,PDWORD);
WINBASEAPI BOOL WINAPI LookupPrivilegeValueA(LPCSTR,LPCSTR,PLUID);
WINBASEAPI BOOL WINAPI LookupPrivilegeValueW(LPCWSTR,LPCWSTR,PLUID);
WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR,LPCSTR);
WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR,LPCWSTR);
WINBASEAPI int WINAPI lstrcmpA(LPCSTR,LPCSTR);
WINBASEAPI int WINAPI lstrcmpiA(LPCSTR,LPCSTR);
/**
 * Compares two strings, ignoring case, using locale word sort rules.
 *
 * @param lpString1 First string.
 * @param lpString2 Second string.
 * @return Negative if lpString1 sorts first, 0 if equal, positive if
 *         lpString2 sorts first.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI lstrcmpiW( LPCWSTR lpString1,LPCWSTR lpString2);
/**
 * Compares two strings, case-sensitively, using locale word sort rules.
 *
 * @param lpString1 First string.
 * @param lpString2 Second string.
 * @return Negative if lpString1 sorts first, 0 if equal, positive if
 *         lpString2 sorts first.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR,LPCSTR);
WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR,LPCSTR,int);
WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR,LPCWSTR,int);
WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR,LPCWSTR);
WINBASEAPI int WINAPI lstrlenA(LPCSTR);
WINBASEAPI int WINAPI lstrlenW(LPCWSTR);
WINBASEAPI BOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PDWORD,PACL,PDWORD,PACL,PDWORD,PSID,PDWORD,PSID,PDWORD);
#define MakeProcInstance(p,i) (p)
WINBASEAPI BOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PDWORD);
WINBASEAPI VOID WINAPI MapGenericMask(PDWORD,PGENERIC_MAPPING);
/**
 * Maps a view of a file-mapping object into the calling process.
 *
 * The file stays open until the last view is unmapped, even if its handle
 * is closed. Unmap with UnmapViewOfFile.
 *
 * @param hFileMappingObject Mapping from CreateFileMapping.
 * @param dwDesiredAccess FILE_MAP_READ (mapping created with PAGE_READONLY
 *        or PAGE_READWRITE) or FILE_MAP_WRITE (PAGE_READWRITE).
 *        FILE_MAP_ALL_ACCESS is the same as FILE_MAP_WRITE.
 * @param dwFileOffsetHigh High 32 bits of the file offset to start at.
 * @param dwFileOffsetLow Low 32 bits of the file offset. The offset must be
 *        a multiple of the allocation granularity (see GetSystemInfo).
 * @param dwNumberOfBytesToMap Bytes to map, or 0 for the whole file.
 * @return Start address of the view, or NULL on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI PVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,DWORD dwNumberOfBytesToMap);
WINBASEAPI PVOID WINAPI MapViewOfFileEx(HANDLE,DWORD,DWORD,DWORD,DWORD,PVOID);
WINBASEAPI BOOL WINAPI MoveFileA(LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI MoveFileExA(LPCSTR,LPCSTR,DWORD);
WINBASEAPI BOOL WINAPI MoveFileExW(LPCWSTR,LPCWSTR,DWORD);
/**
 * Renames or moves a file or a directory with its contents.
 *
 * Files can move between volumes; directories can't.
 *
 * @param lpExistingFileName Existing file or directory.
 * @param lpNewFileName New name. Must not already exist.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI MoveFileWithProgressA(LPCSTR,LPCSTR,LPPROGRESS_ROUTINE,LPVOID,DWORD);
WINBASEAPI BOOL WINAPI MoveFileWithProgressW(LPCWSTR,LPCWSTR,LPPROGRESS_ROUTINE,LPVOID,DWORD);
#endif
WINBASEAPI int WINAPI MulDiv(int,int,int);
WINBASEAPI BOOL WINAPI NotifyChangeEventLog(HANDLE,HANDLE);
WINBASEAPI BOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR,PVOID,BOOL);
WINBASEAPI BOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR,PVOID,BOOL);
WINBASEAPI BOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR,PVOID,BOOL);
WINBASEAPI BOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR,PVOID,BOOL);
WINBASEAPI BOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR,PVOID,LPSTR,LPSTR,PSECURITY_DESCRIPTOR,HANDLE,DWORD,DWORD,PPRIVILEGE_SET,BOOL,BOOL,PBOOL);
WINBASEAPI BOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR,PVOID,LPWSTR,LPWSTR,PSECURITY_DESCRIPTOR,HANDLE,DWORD,DWORD,PPRIVILEGE_SET,BOOL,BOOL,PBOOL);
WINBASEAPI BOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR,PVOID,HANDLE,DWORD,PPRIVILEGE_SET,BOOL);
WINBASEAPI BOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR,PVOID,HANDLE,DWORD,PPRIVILEGE_SET,BOOL);
WINBASEAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR,LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenEventA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenEventLogA (LPCSTR,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenEventLogW(LPCWSTR,LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenEventW(DWORD,BOOL,LPCWSTR);
WINBASEAPI HFILE WINAPI OpenFile(LPCSTR,LPOFSTRUCT,UINT);
WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD,BOOL,LPCWSTR);
WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD,BOOL,LPCWSTR);
/**
 * Opens a handle to an existing process.
 *
 * Windows CE doesn't support handle inheritance or per-handle access
 * rights. Close the handle with CloseHandle.
 *
 * @param dwDesiredAccess Access rights. Not supported on Windows CE: pass
 *        0.
 * @param bInheritHandle Not supported on Windows CE: pass FALSE.
 * @param dwProcessId Identifier of the process to open.
 * @return The process handle, or NULL on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwProcessId);
WINBASEAPI BOOL WINAPI OpenProcessToken(HANDLE,DWORD,PHANDLE);
WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD,BOOL,LPCWSTR);
#if (_WIN32_WINNT >= 0x0500) || (_WIN32_WINDOWS >= 0x0490)
WINBASEAPI HANDLE WINAPI OpenThread(DWORD,BOOL,DWORD);
#endif
WINBASEAPI BOOL WINAPI OpenThreadToken(HANDLE,DWORD,BOOL,PHANDLE);
WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD,BOOL,LPCWSTR);
WINBASEAPI void WINAPI OutputDebugStringA(LPCSTR);
/**
 * Sends a string to the debugger.
 *
 * Windows CE only has the Unicode version.
 *
 * @param lpszOutputString The string to send.
 */
WINBASEAPI void WINAPI OutputDebugStringW(LPCWSTR lpszOutputString);
WINBASEAPI BOOL WINAPI PeekNamedPipe(HANDLE,PVOID,DWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI PostQueuedCompletionStatus(HANDLE,DWORD,ULONG_PTR,LPOVERLAPPED);
WINBASEAPI DWORD WINAPI PrepareTape(HANDLE,DWORD,BOOL);
WINBASEAPI BOOL WINAPI PrivilegeCheck (HANDLE,PPRIVILEGE_SET,PBOOL);
WINBASEAPI BOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR,LPCSTR,HANDLE,PPRIVILEGE_SET,BOOL);
WINBASEAPI BOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR,LPCWSTR,HANDLE,PPRIVILEGE_SET,BOOL);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI ProcessIdToSessionId(DWORD,DWORD*);
#endif
// inlined in kfuncs.h WINBASEAPI BOOL WINAPI PulseEvent(HANDLE);
/**
 * Discards a serial port's buffers and/or cancels pending reads and writes.
 *
 * Discarded output is never sent. To wait for output to be sent instead,
 * use FlushFileBuffers.
 *
 * @param hFile Serial port from CreateFile.
 * @param dwFlags Any of PURGE_TXABORT and PURGE_RXABORT (end pending writes
 *        or reads at once), and PURGE_TXCLEAR and PURGE_RXCLEAR (empty the
 *        driver's output or input buffer).
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI QueryActCtxW(DWORD,HANDLE,PVOID,ULONG,PVOID,SIZE_T,SIZE_T*);
#endif
WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR,LPWSTR,DWORD);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI QueryMemoryResourceNotification(HANDLE,PBOOL);
#endif
/**
 * Gets the current value of the high-resolution performance counter.
 *
 * Convert to time with QueryPerformanceFrequency.
 *
 * @param lpPerformanceCount Receives the counter value.
 * @return TRUE on success, FALSE if there's no high-resolution counter.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI QueryPerformanceCounter(PLARGE_INTEGER lpPerformanceCount);
/**
 * Gets the frequency of the high-resolution performance counter.
 *
 * @param lpFrequency Receives the frequency in counts per second.
 * @return TRUE on success, FALSE if there's no high-resolution counter.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI QueryPerformanceFrequency(PLARGE_INTEGER lpFrequency);
WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC,HANDLE,ULONG_PTR);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE,PVOID,ULONG);
#endif
/**
 * Raises a software exception in the calling thread.
 *
 * The debugger gets the first chance, then frame-based handlers on the
 * stack, then the debugger again, then the default handling. Handlers can
 * read the code and arguments with GetExceptionCode and
 * GetExceptionInformation.
 *
 * @param dwExceptionCode Application-defined code. Bit 28 is reserved and
 *        is cleared by the system.
 * @param dwExceptionFlags 0 for a continuable exception, or
 *        EXCEPTION_NONCONTINUABLE.
 * @param nNumberOfArguments Number of entries in lpArguments, at most
 *        EXCEPTION_MAXIMUM_PARAMETERS. Ignored if lpArguments is NULL.
 * @param lpArguments Array of values to pass to the handler, or NULL.
 */
WINBASEAPI void WINAPI RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD nNumberOfArguments,const DWORD*lpArguments);
WINBASEAPI BOOL WINAPI ReadDirectoryChangesW(HANDLE,PVOID,DWORD,BOOL,DWORD,PDWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL WINAPI ReadEventLogA(HANDLE,DWORD,DWORD,PVOID,DWORD,DWORD *,DWORD *);
WINBASEAPI BOOL WINAPI ReadEventLogW(HANDLE,DWORD,DWORD,PVOID,DWORD,DWORD *,DWORD *);
/**
 * Reads from a file or device at the current file pointer and advances
 * it.
 *
 * Windows CE has no overlapped I/O: reads always complete before
 * returning. hFile can't be a socket. On a serial port, how long a read
 * waits is governed by SetCommTimeouts; set them, or results are
 * unpredictable. TRUE with zero bytes read means end of file.
 *
 * @param hFile File or device opened with GENERIC_READ.
 * @param lpBuffer Receives the data.
 * @param nNumberOfBytesToRead Number of bytes to read.
 * @param lpNumberOfBytesRead Receives the number of bytes read.
 * @param lpOverlapped Must be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI ReadFile(HANDLE hFile,PVOID lpBuffer,DWORD nNumberOfBytesToRead,PDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI ReadFileEx(HANDLE,PVOID,DWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL WINAPI ReadFileScatter(HANDLE,FILE_SEGMENT_ELEMENT*,DWORD,LPDWORD,LPOVERLAPPED);
/**
 * Reads memory from another process.
 *
 * The whole range must be readable or the call fails.
 *
 * @param hProcess The process, from OpenProcess or CreateProcess.
 * @param lpBaseAddress Address to read from in that process.
 * @param lpBuffer Receives the data.
 * @param nSize Number of bytes to read.
 * @param lpNumberOfBytesRead Receives the number of bytes read, or NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI ReadProcessMemory(HANDLE hProcess,PCVOID lpBaseAddress,PVOID lpBuffer,DWORD nSize,PDWORD lpNumberOfBytesRead);
WINBASEAPI HANDLE WINAPI RegisterEventSourceA (LPCSTR,LPCSTR);
WINBASEAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR,LPCWSTR);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI RegisterWaitForSingleObject(PHANDLE,HANDLE,WAITORTIMERCALLBACK,PVOID,ULONG,ULONG);
WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE,WAITORTIMERCALLBACK,PVOID,ULONG,ULONG);
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI void WINAPI ReleaseActCtx(HANDLE);
#endif
/**
 * Releases a mutex held by the calling thread.
 *
 * A thread acquires a mutex through a wait function, or by creating it
 * with ownership. Release once for each wait it satisfied.
 *
 * @param hMutex Mutex from CreateMutex.
 * @return TRUE on success, FALSE on failure, including when the thread
 *         doesn't own the mutex (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI ReleaseMutex(HANDLE hMutex);
/**
 * Increases a semaphore's count and releases waiting threads as applicable.
 *
 * lReleaseCount must be positive and must not raise the count above its
 * maximum. A waiting thread decrements the count when released.
 *
 * @param hSemaphore Semaphore handle.
 * @param lReleaseCount Positive count increment.
 * @param lpPreviousCount Receives the previous count, or NULL.
 * @return Nonzero on success, zero on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG lReleaseCount,LPLONG lpPreviousCount);
WINBASEAPI BOOL WINAPI RemoveDirectoryA(LPCSTR);
/**
 * Deletes an empty directory.
 *
 * @param lpPathName Path of the directory. It must be empty.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID);
#endif
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE,DWORD,DWORD,DWORD);
#endif
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI ReplaceFileA(LPCSTR,LPCSTR,LPCSTR,DWORD,LPVOID,LPVOID);
WINBASEAPI BOOL WINAPI ReplaceFileW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,LPVOID,LPVOID);
#endif
WINBASEAPI BOOL WINAPI ReportEventA(HANDLE,WORD,WORD,DWORD,PSID,WORD,DWORD,LPCSTR*,PVOID);
WINBASEAPI BOOL WINAPI ReportEventW(HANDLE,WORD,WORD,DWORD,PSID,WORD,DWORD,LPCWSTR*,PVOID);
#ifdef _WIN32_WCE
// inlined in kfuncs.h extern BOOL ResetEvent(HANDLE);
#else
/**
 * This function sets the state of the specified event object to
 * nonsignaled.
 *
 * ResetEvent returns FALSE if the handle to the event object is invalid.
 *
 * The state of an event object remains nonsignaled until it is explicitly
 * set to signaled by the SetEvent or PulseEvent function. This nonsignaled
 * state blocks the execution of any threads that have specified the event
 * object in a call to one of the wait functions.
 *
 * The ResetEvent function is used primarily for manual-reset event
 * objects, which must be set explicitly to the nonsignaled state.
 * Auto-reset event objects automatically change from signaled to
 * nonsignaled after a single waiting thread is released.
 *
 * @param hEvent Handle to the event object. The CreateEvent function
 *        returns this handle.
 * @return Nonzero indicates success. Zero indicates failure. To get
 *        extended error information, call GetLastError.
 */
WINBASEAPI BOOL WINAPI ResetEvent(HANDLE hEvent);
#endif
WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID,SIZE_T);
#if (_WIN32_WINNT >= 0x0510)
WINBASEAPI VOID WINAPI RestoreLastError(DWORD);
#endif
/**
 * Decrements a thread's suspend count, resuming it when it reaches zero.
 *
 * @param hThread The thread.
 * @return The previous suspend count: 0 means it wasn't suspended, 1 that
 *         it's now running, and more that it's still suspended. 0xFFFFFFFF
 *         on failure (see GetLastError).
 */
WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);
WINBASEAPI BOOL WINAPI RevertToSelf(void);
WINBASEAPI DWORD WINAPI SearchPathA(LPCSTR,LPCSTR,LPCSTR,DWORD,LPSTR,LPSTR*);
WINBASEAPI DWORD WINAPI SearchPathW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,LPWSTR,LPWSTR*);
WINBASEAPI BOOL WINAPI SetAclInformation(PACL,PVOID,DWORD,ACL_INFORMATION_CLASS);
/**
 * Puts a serial line into the break state and stops sending.
 *
 * Data waiting to be sent is kept. End the break with ClearCommBreak.
 *
 * @param hFile Serial port from CreateFile.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetCommBreak(HANDLE hFile);
WINBASEAPI BOOL WINAPI SetCommConfig(HANDLE,LPCOMMCONFIG,DWORD);
/**
 * Sets which serial port events WaitCommEvent waits for.
 *
 * Calling it while another thread is in WaitCommEvent makes that call
 * return with an event mask of 0. Read the mask back with GetCommMask.
 *
 * @param hFile Serial port from CreateFile.
 * @param dwEvtMask 0 to disable all events, or any of EV_BREAK, EV_CTS,
 *        EV_DSR, EV_ERR, EV_RING, EV_RLSD, EV_RXCHAR, EV_RXFLAG, EV_TXEMPTY
 *        and, on Windows CE, EV_POWER.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
/**
 * Configures a serial port from a DCB.
 *
 * Resets the hardware and control settings but keeps queued data. Fill
 * the DCB with GetCommState first and change only what's needed. Fails if
 * XonChar equals XoffChar. On 8250-type UARTs ByteSize must be 5 to 8, and
 * 5 data bits with 2 stop bits, or 6 to 8 with 1.5, is invalid.
 *
 * @param hFile Serial port from CreateFile.
 * @param lpDCB The new settings.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
/**
 * Sets the read and write timeouts of a serial port.
 *
 * Set these before using ReadFile or WriteFile on the port.
 *
 * @param hFile Serial port from CreateFile.
 * @param lpCommTimeouts The new timeouts.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
WINBASEAPI BOOL WINAPI SetComputerNameA(LPCSTR);
WINBASEAPI BOOL WINAPI SetComputerNameW(LPCWSTR);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT,LPCSTR);
WINBASEAPI BOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT,LPCWSTR);
#endif
WINBASEAPI BOOL WINAPI SetCurrentDirectoryA(LPCSTR);
WINBASEAPI BOOL WINAPI SetCurrentDirectoryW(LPCWSTR);
WINBASEAPI BOOL WINAPI SetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,DWORD);
WINBASEAPI BOOL WINAPI SetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,DWORD);
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI BOOL WINAPI SetDllDirectoryA(LPCSTR);
WINBASEAPI BOOL WINAPI SetDllDirectoryW(LPCWSTR);
#endif
/**
 * Truncates or extends a file to the current file pointer.
 *
 * Bytes added by extending a file are undefined.
 *
 * @param hFile File opened with GENERIC_WRITE.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetEndOfFile(HANDLE hFile);
WINBASEAPI BOOL WINAPI SetEnvironmentVariableA(LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI SetEnvironmentVariableW(LPCWSTR,LPCWSTR);
WINBASEAPI UINT WINAPI SetErrorMode(UINT);
#ifdef _WIN32_WCE
// inlined in kfuncs.h extern BOOL SetEvent(HANDLE);
#else
/**
 * This function sets the state of the specified event object to signaled.
 *
 * The state of a manual-reset event object remains signaled until it is
 * set explicitly to the nonsignaled state by the ResetEvent function. Any
 * number of waiting threads, or threads that subsequently begin wait
 * operations for the specified event object by calling one of the wait
 * functions, can be released while the object's state is signaled.
 *
 * The state of an auto-reset event object remains signaled until a single
 * waiting thread is released, at which time the system automatically sets
 * the state to nonsignaled. If no threads are waiting, the event object's
 * state remains signaled.
 *
 * @param hEvent Handle to the event object. The CreateEvent function
 *        returns this handle.
 * @return Nonzero indicates success. Zero indicates failure. To get
 *        extended error information, call GetLastError.
 */
WINBASEAPI BOOL WINAPI SetEvent(HANDLE hEvent);
#endif
WINBASEAPI VOID WINAPI SetFileApisToANSI(void);
WINBASEAPI VOID WINAPI SetFileApisToOEM(void);
WINBASEAPI BOOL WINAPI SetFileAttributesA(LPCSTR,DWORD);
/**
 * Sets a file's attributes.
 *
 * Can't change compression: FILE_ATTRIBUTE_COMPRESSED is ignored.
 *
 * @param lpFileName The file.
 * @param dwFileAttributes Any of FILE_ATTRIBUTE_ARCHIVE,
 *        FILE_ATTRIBUTE_HIDDEN, FILE_ATTRIBUTE_READONLY,
 *        FILE_ATTRIBUTE_SYSTEM and FILE_ATTRIBUTE_TEMPORARY, or
 *        FILE_ATTRIBUTE_NORMAL on its own.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);
/**
 * Moves a file's read/write position.
 *
 * Doesn't work on devices that can't seek, such as serial ports. With
 * lpDistanceToMoveHigh set, 0xFFFFFFFF can be a valid position, so check
 * GetLastError for NO_ERROR. Protect the position with a lock when
 * threads share a handle.
 *
 * @param hFile File opened with GENERIC_READ or GENERIC_WRITE.
 * @param lDistanceToMove Low 32 bits of the signed distance in bytes.
 * @param lpDistanceToMoveHigh High 32 bits of the distance, updated with
 *        the high 32 bits of the new position, or NULL for 32-bit offsets.
 * @param dwMoveMethod FILE_BEGIN, FILE_CURRENT or FILE_END.
 * @return Low 32 bits of the new position, or 0xFFFFFFFF on failure (see
 *         GetLastError).
 */
WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
WINBASEAPI BOOL WINAPI SetFilePointerEx(HANDLE,LARGE_INTEGER,PLARGE_INTEGER,DWORD);
WINBASEAPI BOOL WINAPI SetFileSecurityA(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
WINBASEAPI BOOL WINAPI SetFileSecurityW(LPCWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI SetFileShortNameA(HANDLE,LPCSTR);
WINBASEAPI BOOL WINAPI SetFileShortNameW(HANDLE,LPCWSTR);
#endif
/**
 * Sets a file's creation, last access and last write times.
 *
 * @param hFile File opened with GENERIC_WRITE.
 * @param lpCreationTime New creation time, or NULL to leave it.
 * @param lpLastAccessTime New last access time, or NULL to leave it.
 * @param lpLastWriteTime New last write time, or NULL to leave it.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetFileTime(HANDLE hFile,const FILETIME*lpCreationTime,const FILETIME*lpLastAccessTime,const FILETIME*lpLastWriteTime);
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI SetFileValidData(HANDLE,LONGLONG);
#endif
#if (_WIN32_WINNT >= 0x0502)
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR,LPCSTR,PVOID,DWORD);
WINBASEAPI BOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR,LPCWSTR,PVOID,DWORD);
#endif
WINBASEAPI UINT WINAPI SetHandleCount(UINT);
WINBASEAPI BOOL WINAPI SetHandleInformation(HANDLE,DWORD,DWORD);
WINBASEAPI BOOL WINAPI SetKernelObjectSecurity(HANDLE,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
/**
 * Sets the calling thread's last-error code.
 *
 * Mainly for DLLs to report errors the way system functions do. Set bit 29
 * on application-defined codes so they can't clash with system codes.
 *
 * @param dwErrCode The error code.
 */
WINBASEAPI void WINAPI SetLastError(DWORD dwErrCode);
WINBASEAPI void WINAPI SetLastErrorEx(DWORD,DWORD);
/**
 * Sets the current local date and time.
 *
 * @param lpSystemTime The new local time. wDayOfWeek is ignored.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetLocalTime(const SYSTEMTIME*lpSystemTime);
WINBASEAPI BOOL WINAPI SetMailslotInfo(HANDLE,DWORD);
WINBASEAPI BOOL WINAPI SetNamedPipeHandleState(HANDLE,PDWORD,PDWORD,PDWORD);
WINBASEAPI BOOL WINAPI SetPriorityClass(HANDLE,DWORD);
WINBASEAPI BOOL WINAPI SetPrivateObjectSecurity(SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR *,PGENERIC_MAPPING,HANDLE);
WINBASEAPI BOOL WINAPI SetProcessAffinityMask(HANDLE,DWORD);
#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI BOOL WINAPI SetProcessDEPPolicy (DWORD);
#endif
WINBASEAPI BOOL WINAPI SetProcessPriorityBoost(HANDLE,BOOL);
WINBASEAPI BOOL WINAPI SetProcessShutdownParameters(DWORD,DWORD);
WINBASEAPI BOOL WINAPI SetProcessWorkingSetSize(HANDLE,SIZE_T,SIZE_T);
WINBASEAPI BOOL WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR,SECURITY_DESCRIPTOR_CONTROL,SECURITY_DESCRIPTOR_CONTROL);
WINBASEAPI BOOL WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR,BOOL,PACL,BOOL);
WINBASEAPI BOOL WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR,PSID,BOOL);
WINBASEAPI BOOL WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR,PSID,BOOL);
WINBASEAPI BOOL WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR,BOOL,PACL,BOOL);
WINBASEAPI BOOL WINAPI SetStdHandle(DWORD,HANDLE);
#define SetSwapAreaSize(w) (w)
#if !defined (_WIN32_WCE)
WINBASEAPI BOOL WINAPI SetSystemPowerState(BOOL,BOOL);
#endif
/**
 * Sets the current date and time in UTC.
 *
 * @param lpSystemTime The new UTC time. wDayOfWeek is ignored.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetSystemTime(const SYSTEMTIME*lpSystemTime);
WINBASEAPI BOOL WINAPI SetSystemTimeAdjustment(DWORD,BOOL);
WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE,DWORD,PVOID);
WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE,DWORD,DWORD,DWORD,DWORD,BOOL);
WINBASEAPI DWORD WINAPI SetThreadAffinityMask(HANDLE,DWORD);
/**
 * Sets the registers of a thread.
 *
 * Intended for debuggers. Suspend the thread first, and fill the CONTEXT
 * with GetThreadContext, setting ContextFlags to the register groups to
 * write. CONTEXT is processor-specific.
 *
 * @param hThread The thread.
 * @param lpContext The new register values.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI SetThreadContext(HANDLE hThread,const CONTEXT*lpContext);
#if (_WIN32_WINNT >= 0x0500 || _WIN32_WINDOWS >= 0x0410)
WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE);
#endif
WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE,DWORD);
/**
 * Sets a thread's priority.
 *
 * Windows CE has no priority classes: threads are scheduled round-robin by
 * priority alone, and lower levels only run when nothing above is ready.
 * The THREAD_PRIORITY_* values differ from desktop Win32: they run from 0
 * (time critical) to 7 (idle). A THREAD_PRIORITY_TIME_CRITICAL thread runs
 * until it yields, even to others at that level, and can stall the
 * system, including disk cache flushing and the pen: it must yield
 * regularly.
 *
 * @param hThread The thread.
 * @param nPriority THREAD_PRIORITY_TIME_CRITICAL, _HIGHEST, _ABOVE_NORMAL,
 *        _NORMAL, _BELOW_NORMAL, _LOWEST, _ABOVE_IDLE or _IDLE. The
 *        Windows CE 1.0 reference doesn't list THREAD_PRIORITY_ABOVE_IDLE.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetThreadPriority(HANDLE hThread,int nPriority);
WINBASEAPI BOOL WINAPI SetThreadPriorityBoost(HANDLE,BOOL);
WINBASEAPI BOOL WINAPI SetThreadToken (PHANDLE,HANDLE);
/**
 * Sets the time-zone settings used to convert between UTC and local time.
 *
 * UTC = local time + bias, with the bias in minutes.
 *
 * @param lpTimeZoneInformation The new settings.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetTimeZoneInformation(const TIME_ZONE_INFORMATION *lpTimeZoneInformation);
WINBASEAPI BOOL WINAPI SetTokenInformation(HANDLE,TOKEN_INFORMATION_CLASS,PVOID,DWORD);
WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER);
/**
 * Recommends input and output buffer sizes for a serial port.
 *
 * The driver may use any buffering it likes, and may fail if the sizes are
 * too large. Without this call the defaults apply.
 *
 * @param hFile Serial port from CreateFile.
 * @param dwInQueue Recommended input buffer size in bytes.
 * @param dwOutQueue Recommended output buffer size in bytes.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
WINBASEAPI BOOL WINAPI SetVolumeLabelA(LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI SetVolumeLabelW(LPCWSTR,LPCWSTR);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI SetVolumeMountPointA(LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI SetVolumeMountPointW(LPCWSTR,LPCWSTR);
#endif
WINBASEAPI BOOL WINAPI SetWaitableTimer(HANDLE,const LARGE_INTEGER*,LONG,PTIMERAPCROUTINE,PVOID,BOOL);
WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE,HANDLE,DWORD,BOOL);
/**
 * Returns the size of a resource.
 *
 * Padding for alignment may make it larger than the actual data.
 *
 * @param hModule Module containing the resource.
 * @param hResInfo Resource from FindResource.
 * @return The size in bytes, or 0 on failure (see GetLastError).
 */
WINBASEAPI DWORD WINAPI SizeofResource(HINSTANCE hModule,HRSRC hResInfo);
/**
 * Suspends the calling thread for a time.
 *
 * @param dwMilliseconds Time in milliseconds. 0 gives up the rest of the
 *        time slice to a ready thread of equal priority, returning at once
 *        if there is none. INFINITE never returns.
 */
WINBASEAPI void WINAPI Sleep(DWORD dwMilliseconds);
WINBASEAPI DWORD WINAPI SleepEx(DWORD,BOOL);
/**
 * Suspends a thread by incrementing its suspend count.
 *
 * The thread runs again when ResumeThread brings the count back to zero.
 * The count can't go above MAXIMUM_SUSPEND_COUNT.
 *
 * @param hThread The thread.
 * @return The previous suspend count, or 0xFFFFFFFF on failure (see
 *         GetLastError).
 */
WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
WINBASEAPI void WINAPI SwitchToFiber(PVOID);
WINBASEAPI BOOL WINAPI SwitchToThread(void);
/**
 * Converts a SYSTEMTIME to a FILETIME.
 *
 * No time-zone conversion is done.
 *
 * @param lpSystemTime The time to convert. wDayOfWeek is ignored.
 * @param lpFileTime Receives the converted time.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME*lpSystemTime,LPFILETIME lpFileTime);
#if (_WIN32_WINNT >= 0x501)
WINBASEAPI BOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION,LPSYSTEMTIME,LPSYSTEMTIME);
#endif
WINBASEAPI BOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION,LPSYSTEMTIME,LPSYSTEMTIME);
/**
 * Forcibly ends a thread.
 *
 * The thread gets no chance to clean up: locks it holds stay held and DLLs
 * aren't notified. Prefer having the thread return or call ExitThread.
 *
 * @param hThread The thread.
 * @param dwExitCode Exit code for the thread (see GetExitCodeThread).
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI TerminateThread(HANDLE hThread,DWORD dwExitCode);
#ifndef _WIN32_WCE
/* In kfuncs.h */
/**
 * This function allocates a thread local storage (TLS) index. Any thread
 * of the process can subsequently use this index to store and retrieve
 * values that are local to the thread.
 *
 * The threads of the process can use the TLS index in subsequent calls to
 * the TlsFree, TlsSetValue, or TlsGetValue functions.
 *
 * TLS indexes are typically allocated during process or dynamic-link
 * library (DLL) initialization. Once allocated, each thread of the process
 * can use a TLS index to access its own TLS storage slot. To store a value
 * in its slot, a thread specifies the index in a call to TlsSetValue. The
 * thread specifies the same index in a subsequent call to TlsGetValue, to
 * retrieve the stored value.
 *
 * The constant TLS_MINIMUM_AVAILABLE defines the minimum number of TLS
 * indexes available in each process. This minimum is guaranteed to be at
 * least 64 for all systems.
 *
 * TLS indexes are not valid across process boundaries. A DLL cannot assume
 * that an index assigned in one process is valid in another process.
 *
 * A DLL might use TlsAlloc, TlsSetValue, TlsGetValue, and TlsFree as
 * follows:
 *
 * When a DLL attaches to a process, the DLL uses TlsAlloc to allocate a
 * TLS index. The DLL then allocates some dynamic storage and uses the TLS
 * index in a call to TlsSetValue to store the address in the TLS slot.
 * This concludes the per-thread initialization for the initial thread of
 * the process. The TLS index is stored in a global or static variable of
 * the DLL.
 *
 * Each time the DLL attaches to a new thread of the process, the DLL
 * allocates some dynamic storage for the new thread and uses the TLS index
 * in a call to TlsSetValue to store the address in the TLS slot. This
 * concludes the per-thread initialization for the new thread.
 *
 * Each time an initialized thread makes a DLL call requiring the data in
 * its dynamic storage, the DLL uses the TLS index in a call to TlsGetValue
 * to retrieve the address of the dynamic storage for that thread.
 *
 * For additional information on thread local storage, see Writing
 * Memory-Efficient Applications.
 *
 * @return A TLS index indicates success. 0xFFFFFFFF indicates failure. To
 *        get extended error information, call GetLastError.
 */
WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
/**
 * This function releases a thread local storage (TLS) index, making it
 * available for reuse.
 *
 * If the threads of the process have allocated dynamic storage and used
 * the TLS index to store pointers to this storage, they should free the
 * storage before calling TlsFree. The TlsFree function does not free any
 * dynamic storage that has been associated with the TLS index. It is
 * expected that DLLs call this function (if at all) only during their
 * process detach routine.
 *
 * For a brief discussion of typical uses of the TLS functions, see the
 * Remarks section of the TlsAlloc function.
 *
 * @param dwTlsIndex Specifies a TLS index that was allocated by the
 *        TlsAlloc function.
 * @return Nonzero indicates success. Zero indicates failure. To get
 *        extended error information, call GetLastError.
 */
WINBASEAPI BOOL WINAPI TlsFree(DWORD dwTlsIndex);
#endif
/**
 * Returns the calling thread's value in a thread local storage slot.
 *
 * Each slot starts as NULL. The index is barely checked: any value below
 * TLS_MINIMUM_AVAILABLE succeeds. Clears the last error on success, so a
 * 0 result with GetLastError returning NO_ERROR is a stored 0.
 *
 * @param dwTlsIndex Index from TlsAlloc.
 * @return The stored value, or 0 on failure (see GetLastError).
 */
WINBASEAPI PVOID WINAPI TlsGetValue(DWORD dwTlsIndex);
/**
 * Stores a value in the calling thread's thread local storage slot.
 *
 * The index is barely checked: any value below TLS_MINIMUM_AVAILABLE
 * succeeds.
 *
 * @param dwTlsIndex Index from TlsAlloc.
 * @param lpTlsValue The value to store.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI TlsSetValue(DWORD dwTlsIndex,PVOID lpTlsValue);
WINBASEAPI BOOL WINAPI TransactNamedPipe(HANDLE,PVOID,DWORD,PVOID,DWORD,PDWORD,LPOVERLAPPED);
/**
 * Sends a character on a serial port ahead of any queued output.
 *
 * Useful for an interrupt character such as Ctrl+C. Flow control still
 * applies. Fails if the previous character sent this way hasn't gone yet.
 *
 * @param hFile Serial port from CreateFile.
 * @param cChar The character.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI TransmitCommChar(HANDLE hFile,char cChar);
/**
 * Attempts to enter a critical section without blocking.
 *
 * Initialize the critical section first. The caller must leave it once
 * for each successful entry.
 *
 * @param lpCriticalSection Critical section to enter.
 * @return Nonzero if entered or already owned by this thread; zero if
 *         another thread owns it.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
WINBASEAPI LONG WINAPI UnhandledExceptionFilter(LPEXCEPTION_POINTERS);
WINBASEAPI BOOL WINAPI UnlockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
WINBASEAPI BOOL WINAPI UnlockFileEx(HANDLE,DWORD,DWORD,DWORD,LPOVERLAPPED);
#define UnlockResource(h) (h)
#define UnlockSegment(w) GlobalUnfix((HANDLE)(w)) /* Obsolete: Has no effect. */
/**
 * Unmaps a view mapped with MapViewOfFile.
 *
 * Modified pages are written back to the file lazily.
 *
 * @param lpBaseAddress Address returned by MapViewOfFile.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI UnregisterWait(HANDLE);
WINBASEAPI BOOL WINAPI UnregisterWaitEx(HANDLE,HANDLE);
#endif
WINBASEAPI BOOL WINAPI UpdateResourceA(HANDLE,LPCSTR,LPCSTR,WORD,PVOID,DWORD);
WINBASEAPI BOOL WINAPI UpdateResourceW(HANDLE,LPCWSTR,LPCWSTR,WORD,PVOID,DWORD);
WINBASEAPI BOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA,DWORD,DWORDLONG);
WINBASEAPI BOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW,DWORD,DWORDLONG);
/**
 * Reserves and/or commits pages in the calling process's address space.
 *
 * Committed memory is zeroed. Reserve a range first and commit pages as
 * needed to save physical memory; committing an already committed page
 * succeeds. Release with VirtualFree.
 *
 * @param lpAddress Start address, or NULL to let the system choose.
 *        Rounded down to 64KB when reserving and to a page when
 *        committing.
 * @param dwSize Size in bytes. Covers every page the range touches.
 * @param flAllocationType MEM_RESERVE, MEM_COMMIT or both, optionally with
 *        MEM_TOP_DOWN.
 * @param flProtect PAGE_READONLY, PAGE_READWRITE, PAGE_EXECUTE,
 *        PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE or PAGE_NOACCESS,
 *        optionally with PAGE_GUARD (not with PAGE_NOACCESS) or
 *        PAGE_NOCACHE.
 * @return Base address of the region, or NULL on failure (see
 *         GetLastError).
 */
WINBASEAPI PVOID WINAPI VirtualAlloc(PVOID lpAddress,DWORD dwSize,DWORD flAllocationType,DWORD flProtect);
WINBASEAPI PVOID WINAPI VirtualAllocEx(HANDLE,PVOID,DWORD,DWORD,DWORD);
/**
 * Decommits or releases pages allocated with VirtualAlloc.
 *
 * A release must cover the whole region originally reserved, with all of
 * its pages in the same state: decommit any committed pages first if only
 * some are committed. Decommitted pages stay reserved.
 *
 * @param lpAddress Start of the range. For MEM_RELEASE, the base address
 *        VirtualAlloc returned when reserving.
 * @param dwSize Size in bytes, covering every page the range touches. Must
 *        be 0 for MEM_RELEASE.
 * @param dwFreeType MEM_DECOMMIT or MEM_RELEASE, not both.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI VirtualFree(PVOID lpAddress,DWORD dwSize,DWORD dwFreeType);
WINBASEAPI BOOL WINAPI VirtualFreeEx(HANDLE,PVOID,DWORD,DWORD);
WINBASEAPI BOOL WINAPI VirtualLock(PVOID,DWORD);
/**
 * Changes the access protection of committed pages.
 *
 * Fails without changing anything if any page in the range isn't
 * committed.
 *
 * @param lpAddress Start of the range.
 * @param dwSize Size in bytes. Covers every page the range touches.
 * @param flNewProtect A PAGE_* protection such as PAGE_READONLY or
 *        PAGE_EXECUTE_READWRITE, optionally with PAGE_GUARD or PAGE_NOCACHE.
 * @param lpflOldProtect Receives the previous protection of the first page.
 *        Must not be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI VirtualProtect(PVOID lpAddress,DWORD dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
WINBASEAPI BOOL WINAPI VirtualProtectEx(HANDLE,PVOID,DWORD,DWORD,PDWORD);
/**
 * Describes the run of pages starting at an address that share the same
 * state and protection.
 *
 * @param lpAddress Address to query, rounded down to a page.
 * @param lpBuffer MEMORY_BASIC_INFORMATION that receives the description.
 * @param dwLength Size of lpBuffer in bytes.
 * @return Number of bytes written to lpBuffer, or 0 on failure.
 */
WINBASEAPI DWORD WINAPI VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,DWORD dwLength);
WINBASEAPI DWORD WINAPI VirtualQueryEx(HANDLE,LPCVOID,PMEMORY_BASIC_INFORMATION,DWORD);
WINBASEAPI BOOL WINAPI VirtualUnlock(PVOID,DWORD);
/**
 * Waits for one of the events set with SetCommMask on a serial port.
 *
 * Always blocks until an event or error: Windows CE doesn't support an
 * overlapped wait. Calling SetCommMask from another thread ends the wait
 * with a mask of 0. EV_RXFLAG isn't supported on all devices.
 *
 * @param hFile Serial port from CreateFile.
 * @param lpEvtMask Receives the event that occurred (EV_*), or 0 on error.
 *        Windows CE adds EV_POWER, signalled when the device powers on.
 * @param lpOverlapped Ignored. Pass NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI WaitCommEvent(HANDLE hFile,PDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
/**
 * Waits for a debug event in a process being debugged.
 *
 * Call from the debugger thread, and resume the debuggee with
 * ContinueDebugEvent after handling each event.
 *
 * @param lpDebugEvent DEBUG_EVENT that receives the event.
 * @param dwMilliseconds Timeout in milliseconds, 0 or INFINITE.
 * @return TRUE if an event arrived, FALSE on timeout or failure (see
 *         GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
/**
 * Waits until one of several objects is signalled or the timeout elapses.
 *
 * Can wait on events, mutexes, processes and threads. Windows CE can't
 * wait on semaphores, change notifications, console input or timers. A
 * satisfied wait resets an auto-reset event and takes ownership of a
 * mutex. A thread that owns windows must keep processing messages, so
 * avoid long waits on such threads.
 *
 * @param nCount Number of handles, at most MAXIMUM_WAIT_OBJECTS.
 * @param lpHandles The handles, which may be of different types.
 * @param bWaitAll Must be FALSE on Windows CE.
 * @param dwMilliseconds Timeout in milliseconds, 0 to test and return at
 *        once, or INFINITE.
 * @return WAIT_OBJECT_0 plus the index of the lowest signalled handle,
 *         WAIT_ABANDONED_0 plus the index of an abandoned mutex,
 *         WAIT_TIMEOUT, or WAIT_FAILED on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD nCount,const HANDLE*lpHandles,BOOL bWaitAll,DWORD dwMilliseconds);
WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD,const HANDLE*,BOOL,DWORD,BOOL);
/**
 * Waits until an object is signalled or the timeout elapses.
 *
 * Can wait on events and, from Windows CE 1.01, mutexes, processes and
 * threads; Windows CE 3.0 adds semaphores. Windows CE 1.0 and 2.0 can't
 * wait on semaphores, change notifications, console input or timers. A
 * satisfied wait resets an auto-reset event, takes ownership of a mutex or
 * decrements a semaphore. A thread that owns windows shouldn't wait
 * forever; use MsgWaitForMultipleObjects to keep processing messages.
 *
 * @param hHandle The object. An invalid handle gives WAIT_FAILED.
 * @param dwMilliseconds Timeout in milliseconds, 0 to test and return at
 *        once, or INFINITE.
 * @return WAIT_OBJECT_0 if signalled, WAIT_TIMEOUT, WAIT_ABANDONED for an
 *        abandoned mutex, or WAIT_FAILED on failure (see GetLastError).
 */
WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE,DWORD,BOOL);
WINBASEAPI BOOL WINAPI WaitNamedPipeA(LPCSTR,DWORD);
WINBASEAPI BOOL WINAPI WaitNamedPipeW(LPCWSTR,DWORD);
WINBASEAPI BOOL WINAPI WinLoadTrustProvider(GUID*);
/**
 * Writes to a file or device at the current file pointer and advances
 * it.
 *
 * Windows CE has no overlapped I/O: writes always complete before
 * returning. Writing 0 bytes changes nothing but the timestamp; it doesn't
 * truncate or extend the file (use SetEndOfFile).
 *
 * @param hFile File or device opened with GENERIC_WRITE.
 * @param lpBuffer The data.
 * @param nNumberOfBytesToWrite Number of bytes to write.
 * @param lpNumberOfBytesWritten Receives the number of bytes written.
 * @param lpOverlapped Ignored. Pass NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI WriteFile(HANDLE hFile,PCVOID lpBuffer,DWORD nNumberOfBytesToWrite,PDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
WINBASEAPI BOOL WINAPI WriteFileEx(HANDLE,PCVOID,DWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL WINAPI WriteFileGather(HANDLE,FILE_SEGMENT_ELEMENT*,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionA(LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileSectionW(LPCWSTR,LPCWSTR,LPCWSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStructA(LPCSTR,LPCSTR,LPVOID,UINT,LPCSTR);
WINBASEAPI BOOL WINAPI WritePrivateProfileStructW(LPCWSTR,LPCWSTR,LPVOID,UINT,LPCWSTR);
/**
 * Writes memory in another process.
 *
 * The whole range must be writable or the call fails.
 *
 * @param hProcess Process handle with full access, from OpenProcess.
 * @param lpBaseAddress Address to write to in that process.
 * @param lpBuffer The data.
 * @param nSize Number of bytes to write.
 * @param lpNumberOfBytesWritten Receives the number of bytes written, or
 *        NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI WriteProcessMemory(HANDLE hProcess,LPVOID lpBaseAddress,LPCVOID lpBuffer,SIZE_T nSize,SIZE_T*lpNumberOfBytesWritten);
WINBASEAPI BOOL WINAPI WriteProfileSectionA(LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI WriteProfileSectionW(LPCWSTR,LPCWSTR);
WINBASEAPI BOOL WINAPI WriteProfileStringA(LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL WINAPI WriteProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR);
WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE,DWORD,DWORD,BOOL);
#define Yield()
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI ZombifyActCtx(HANDLE);
#endif
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI AllocateUserPhysicalPages(HANDLE,PULONG_PTR,PULONG_PTR);
WINBASEAPI BOOL WINAPI FreeUserPhysicalPages(HANDLE,PULONG_PTR,PULONG_PTR);
WINBASEAPI BOOL WINAPI MapUserPhysicalPages(PVOID,ULONG_PTR,PULONG_PTR);
WINBASEAPI BOOL WINAPI MapUserPhysicalPagesScatter(PVOID*,ULONG_PTR,PULONG_PTR);
#endif

#ifdef _WIN32_WCE
/**
 * This structure contains the size of the object store and the amount of
 * free space currently in the object store.
 */
typedef struct STORE_INFORMATION {
  /**
   * Specifies the size, in bytes, of the object store.
   */
  DWORD dwStoreSize;
  /**
   *
   */
  DWORD dwFreeSize;
} STORE_INFORMATION, *LPSTORE_INFORMATION;
/**
 * Returns the size and free space of the object store.
 *
 * Windows CE specific.
 *
 * @param lpsi Receives a STORE_INFORMATION.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL GetStoreInformation(LPSTORE_INFORMATION lpsi);
#endif

#if (_WIN32_WCE >= 0x300)
/**
 * Sets a thread's time quantum in milliseconds.
 *
 * The default quantum is 100 ms. A value of zero lets the thread run until
 * it yields. The quantum applies only while no higher-priority thread is
 * ready to run.
 *
 * @param hThread Thread handle.
 * @param dwTime Quantum in milliseconds, or 0 to run until yielding.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL CeSetThreadQuantum(HANDLE hThread, DWORD dwTime);
#endif

#if (_WIN32_WCE >= 0x500)
/**
 * Sets a real-time thread's priority.
 *
 * Priority ranges from 0 (highest) through 255. Raising a blocked thread's
 * priority takes effect immediately; lowering it takes effect after the
 * thread is no longer blocked.
 *
 * @param hThread Thread handle.
 * @param nPriority Priority from 0 through 255.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI CeSetThreadPriority(HANDLE hThread, int nPriority);
/**
 * Gets the priority of a real-time thread.
 *
 * Priorities range from 0 (highest) through 255.
 *
 * @param hThread Thread handle.
 * @return Thread priority, or THREAD_PRIORITY_ERROR_RETURN on failure.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI int WINAPI CeGetThreadPriority(HANDLE hThread);
#endif

#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO,*LPSTARTUPINFO;
typedef WIN32_FIND_DATAW WIN32_FIND_DATA,*PWIN32_FIND_DATA,*LPWIN32_FIND_DATA;
typedef HW_PROFILE_INFOW HW_PROFILE_INFO,*LPHW_PROFILE_INFO;
#if (_WIN32_WINNT >= 0x0501)
typedef ACTCTXW ACTCTX,*PACTCTX;
typedef PCACTCTXW PCACTCTX;
#endif
#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#define AddAtom AddAtomW
#define BackupEventLog BackupEventLogW
#define BeginUpdateResource BeginUpdateResourceW
#define BuildCommDCB BuildCommDCBW
#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#define CallNamedPipe CallNamedPipeW
#if (_WIN32_WINNT >= 0x0501)
#define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#endif
#define ClearEventLog ClearEventLogW
#define CommConfigDialog CommConfigDialogW
/**
 * Copies a file.
 *
 * The file attributes are copied too.
 *
 * @param lpExistingFileName Source path.
 * @param lpNewFileName Destination path.
 * @param bFailIfExists TRUE to fail if the destination exists, FALSE to
 *        overwrite it.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define CopyFile CopyFileW
#define CopyFileEx CopyFileExW
#if (_WIN32_WINNT >= 0x0501)
#define CreateActCtx CreateActCtxW
#endif
/**
 * Creates a directory.
 *
 * Doesn't create missing parent directories.
 *
 * @param lpPathName Path of the new directory, up to MAX_PATH characters.
 * @param lpSecurityAttributes Ignored: must be NULL.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define CreateDirectory CreateDirectoryW
#define CreateDirectoryEx CreateDirectoryExW
/**
 * Creates an event object.
 *
 * Set with SetEvent, clear with ResetEvent, wait with
 * WaitForSingleObject. A manual-reset event stays signalled until reset.
 * An auto-reset event releases one waiting thread and then resets. Close
 * with CloseHandle.
 *
 * @param lpEventAttributes Must be NULL.
 * @param bManualReset TRUE for manual reset, FALSE for auto reset.
 * @param bInitialState TRUE to start signalled.
 * @param lpName The SDK reference says named events are not supported and
 *        this must be NULL.
 * @return The event, or NULL on failure (see GetLastError).
 */
#define CreateEvent CreateEventW
/**
 * Creates or opens a file or device.
 *
 * Devices are named with a colon, e.g. L"COM1:", and need OPEN_EXISTING.
 * Can't create directories (use CreateDirectoryW). Close with
 * CloseHandle.
 *
 * @param lpFileName Path or device name, up to MAX_PATH characters.
 * @param dwDesiredAccess GENERIC_READ and/or GENERIC_WRITE, or 0 to query
 *        device attributes only.
 * @param dwShareMode 0, FILE_SHARE_READ and/or FILE_SHARE_WRITE.
 * @param lpSecurityAttributes Ignored: should be NULL.
 * @param dwCreationDisposition CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING,
 *        OPEN_ALWAYS or TRUNCATE_EXISTING.
 * @param dwFlagsAndAttributes FILE_ATTRIBUTE_* values and
 *        FILE_FLAG_WRITE_THROUGH or FILE_FLAG_RANDOM_ACCESS. Windows CE
 *        doesn't support FILE_ATTRIBUTE_OFFLINE, FILE_ATTRIBUTE_TEMPORARY,
 *        FILE_FLAG_OVERLAPPED, FILE_FLAG_SEQUENTIAL_SCAN,
 *        FILE_FLAG_NO_BUFFERING, FILE_FLAG_DELETE_ON_CLOSE,
 *        FILE_FLAG_BACKUP_SEMANTICS, FILE_FLAG_POSIX_SEMANTICS or
 *        SECURITY_SQOS_PRESENT.
 * @param hTemplateFile Ignored.
 * @return The handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError). GetLastError returns ERROR_ALREADY_EXISTS on
 *         success if CREATE_ALWAYS or OPEN_ALWAYS found an existing file.
 */
#define CreateFile CreateFileW
#ifdef _WIN32_WCE
/**
 * Opens or creates a file for use with CreateFileMappingW.
 *
 * Windows CE specific. Use this instead of CreateFileW for files to be
 * mapped: the kernel opens the file, so other processes can share the
 * mapping. Don't use the handle for ReadFile or WriteFile. Once passed to
 * CreateFileMappingW the kernel owns the handle and CloseHandle on it
 * fails. Only one process should open a shared file this way; others map
 * it by name with CreateFileMappingW.
 *
 * @param lpFileName Path of the file, up to MAX_PATH characters.
 * @param dwDesiredAccess GENERIC_READ, GENERIC_READ | GENERIC_WRITE, or 0
 *        for attribute queries. The Windows CE 2.0 reference lists only
 *        0 and GENERIC_READ.
 * @param dwShareMode 0, FILE_SHARE_READ and/or FILE_SHARE_WRITE.
 * @param lpSecurityAttributes Must be NULL.
 * @param dwCreationDisposition CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING,
 *        OPEN_ALWAYS or TRUNCATE_EXISTING.
 * @param dwFlagsAndAttributes FILE_ATTRIBUTE_* values, plus
 *        FILE_FLAG_WRITE_THROUGH and FILE_FLAG_RANDOM_ACCESS.
 * @param hTemplateFile Ignored.
 * @return The file handle, or INVALID_HANDLE_VALUE on failure (see
 *        GetLastError). GetLastError returns ERROR_ALREADY_EXISTS on
 *        success if CREATE_ALWAYS or OPEN_ALWAYS found an existing file.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define CreateFileForMapping CreateFileForMappingW
#endif
/**
 * Creates or opens a file-mapping object.
 *
 * Map views with MapViewOfFile. To free it, unmap all views with
 * UnmapViewOfFile and close the handle. Views of one mapping are
 * coherent, but not with ReadFile or WriteFile on the same file. Doesn't
 * work on devices without page-in support.
 *
 * @param hFile Handle from CreateFileForMappingW, or INVALID_HANDLE_VALUE
 *        for a mapping backed by memory instead of a file (the size must
 *        then be given).
 * @param lpFileMappingAttributes Must be NULL.
 * @param flProtect PAGE_READONLY, PAGE_READWRITE or PAGE_WRITECOPY,
 *        optionally with SEC_COMMIT or SEC_RESERVE. The file's access
 *        must allow it.
 * @param dwMaximumSizeHigh High 32 bits of the maximum size.
 * @param dwMaximumSizeLow Low 32 bits of the maximum size. With
 *        dwMaximumSizeHigh 0 too, the current file size is used. A larger
 *        size grows the file.
 * @param lpName Name for sharing between processes, or NULL. Must not
 *        contain a backslash.
 * @return The mapping, or NULL on failure (see GetLastError). If the name
 *         already existed, the existing mapping is returned and
 *         GetLastError returns ERROR_ALREADY_EXISTS.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define CreateFileMapping CreateFileMappingW
#if (_WIN32_WINNT >= 0x0500)
#define CreateHardLink CreateHardLinkW
#define CreateJobObject CreateJobObjectW
#endif
#define CreateMailslot CreateMailslotW
/**
 * Creates or opens a mutex.
 *
 * Acquire with a wait function and release with ReleaseMutex, once per
 * successful wait. Close with CloseHandle. Events, mutexes, semaphores
 * and file mappings share one namespace.
 *
 * @param lpMutexAttributes Must be NULL.
 * @param bInitialOwner TRUE to own the mutex on return. Ignored if it
 *        already existed.
 * @param lpName Case-sensitive name, up to MAX_PATH characters and no
 *        backslash, or NULL for an unnamed mutex.
 * @return The mutex, or NULL on failure (see GetLastError). If the name
 *         already existed, GetLastError returns ERROR_ALREADY_EXISTS.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define CreateMutex CreateMutexW
#define CreateNamedPipe CreateNamedPipeW
/**
 * Starts a program in a new process.
 *
 * Close both handles in lpProcessInformation with CloseHandle when no
 * longer needed. There are no priority classes, environment blocks or
 * current directories. Don't call it from DllMain. On Windows CE 3.0 the
 * SystemPath value under HKEY_LOCAL_MACHINE\Loader adds search folders,
 * after a reset.
 *
 * @param lpApplicationName The module to run. Must not be NULL, and the
 *        module can't be named in lpCommandLine instead. .exe is assumed
 *        if there is no extension. Without a path, Windows CE 1.0 and 2.0
 *        search the root of a PC Card, \Windows and \; Windows CE 3.0
 *        searches \Windows, then \, then an OEM-dependent folder.
 * @param lpCommandLine Arguments, or NULL.
 * @param lpProcessAttributes Must be NULL.
 * @param lpThreadAttributes Must be NULL.
 * @param bInheritHandles Must be FALSE.
 * @param dwCreationFlags 0 or CREATE_SUSPENDED. Windows CE 2.0 and later
 *        also support DEBUG_PROCESS and DEBUG_ONLY_THIS_PROCESS, and
 *        Windows CE 3.0 CREATE_NEW_CONSOLE. With the debug flags, only the
 *        calling thread can call WaitForDebugEvent.
 * @param lpEnvironment Must be NULL.
 * @param lpCurrentDirectory Must be NULL.
 * @param lpStartupInfo Must be NULL.
 * @param lpProcessInformation Receives the process and primary thread
 *        handles and IDs.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define CreateProcess CreateProcessW
#define CreateProcessAsUser CreateProcessAsUserW
/**
 * Creates or opens a named or unnamed semaphore.
 *
 * The initial count must be between zero and lMaximumCount; the maximum
 * must be greater than zero. Use wait functions to decrement the count
 * and ReleaseSemaphore to increment it. Close the handle when finished.
 * CE has no OpenSemaphore; use this function to open a named semaphore.
 *
 * @param lpSemaphoreAttributes Must be NULL.
 * @param lInitialCount Initial semaphore count.
 * @param lMaximumCount Maximum semaphore count.
 * @param lpName Optional name, or NULL for an unnamed semaphore.
 * @return Semaphore handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
#define CreateSemaphore CreateSemaphoreW
#if (_WIN32_WINNT >= 0x0600)
#define CreateSymbolicLink CreateSymbolicLinkW
#endif
#define CreateWaitableTimer CreateWaitableTimerW
#define DefineDosDevice DefineDosDeviceW
/**
 * Deletes a file.
 *
 * Fails for open files and read-only files.
 *
 * @param lpFileName Path of the file.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define DeleteFile DeleteFileW
#if (_WIN32_WINNT >= 0x0500)
#define DeleteVolumeMountPoint DeleteVolumeMountPointW
#define DnsHostnameToComputerName DnsHostnameToComputerNameW
#endif
#define EncryptFile EncryptFileW
#define EndUpdateResource EndUpdateResourceW
#define EnumResourceLanguages EnumResourceLanguagesW
#define EnumResourceNames EnumResourceNamesW
#define EnumResourceTypes EnumResourceTypesW
#define ExpandEnvironmentStrings ExpandEnvironmentStringsW
#define FatalAppExit FatalAppExitW
#define FileEncryptionStatus FileEncryptionStatusW
#if (_WIN32_WINNT >= 0x0501)
#define FindActCtxSectionString FindActCtxSectionStringW
#endif
#define FindAtom FindAtomW
#define FindFirstChangeNotification FindFirstChangeNotificationW
/**
 * Starts a search for files and directories matching a name pattern.
 *
 * Continue with FindNextFileW and close with FindClose, not CloseHandle.
 * Matches on names only, not attributes.
 *
 * @param lpFileName Path and pattern, which may contain * and ?. Only the
 *        first MAX_PATH characters are used.
 * @param lpFindFileData Receives the first match.
 * @return The search handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError).
 */
#define FindFirstFile FindFirstFileW
/**
 * Starts a file search using a name pattern and information level.
 *
 * Pass NULL for lpSearchFilter and zero for dwAdditionalFlags. If the file
 * system cannot perform the requested filter, the call fails with
 * ERROR_NOT_SUPPORTED. Continue with FindNextFile and close with FindClose.
 *
 * @param lpFileName Path and file-name pattern; wildcards are allowed.
 * @param fInfoLevelId Information level for the returned data.
 * @param lpFindFileData Receives the matching file information.
 * @param fSearchOp Additional search filter.
 * @param lpSearchFilter Reserved; set to NULL.
 * @param dwAdditionalFlags Unsupported; set to zero.
 * @return Search handle, or INVALID_HANDLE_VALUE on failure.
 *
 * @note Windows CE 3.0 only.
 */
#define FindFirstFileEx FindFirstFileExW
#if (_WIN32_WINNT >= 0x0500)
#define FindFirstVolume FindFirstVolumeW
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#endif
/**
 * Returns the next match of a search started with FindFirstFileW.
 *
 * @param hFindFile The search handle.
 * @param lpFindFileData Receives the match.
 * @return TRUE on success, FALSE on failure. GetLastError returns
 *         ERROR_NO_MORE_FILES at the end of the search.
 */
#define FindNextFile FindNextFileW
#if (_WIN32_WINNT >= 0x0500)
#define FindNextVolume FindNextVolumeW
#define FindNextVolumeMountPoint  FindNextVolumeMountPointW
#endif
/**
 * Locates a resource in a module.
 *
 * Load it with LoadResource. RT_ANICURSOR and RT_ANIICON are not
 * supported.
 *
 * @param hModule Module containing the resource. Must not be NULL.
 * @param lpName Resource name, or an ID from MAKEINTRESOURCE. ID 0 doesn't
 *        work.
 * @param lpType Resource type, such as RT_RCDATA, or a custom type name.
 * @return The resource, or NULL on failure (see GetLastError).
 */
#define FindResource FindResourceW
#define FindResourceEx FindResourceExW
/**
 * Formats a message from a string, a module's message table or the system
 * message table.
 *
 * Inserts use %1, %2 and so on, with optional printf-style formats such as
 * %1!d!. With FORMAT_MESSAGE_ALLOCATE_BUFFER, free the buffer with
 * LocalFree.
 *
 * @param dwFlags FORMAT_MESSAGE_FROM_STRING, _FROM_HMODULE or
 *        _FROM_SYSTEM, plus _ALLOCATE_BUFFER, _IGNORE_INSERTS and
 *        _ARGUMENT_ARRAY. The low byte sets the maximum line width
 *        (FORMAT_MESSAGE_MAX_WIDTH_MASK).
 * @param lpSource Format string or module handle, depending on dwFlags.
 *        Otherwise ignored.
 * @param dwMessageId Message ID. Ignored with FORMAT_MESSAGE_FROM_STRING.
 * @param dwLanguageId Language ID, or 0 for the default search.
 *        Ignored with FORMAT_MESSAGE_FROM_STRING.
 * @param lpBuffer Output buffer, or, with FORMAT_MESSAGE_ALLOCATE_BUFFER,
 *        a pointer to an LPWSTR that receives the allocated buffer.
 * @param nSize Size of lpBuffer in characters, or the minimum to allocate.
 * @param Arguments Insert values, as a va_list, or an array of 32-bit
 *        values with FORMAT_MESSAGE_ARGUMENT_ARRAY. May be NULL.
 * @return Characters written, excluding the terminator, or 0 on failure
 *         (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define FormatMessage FormatMessageW
#define FreeEnvironmentStrings FreeEnvironmentStringsW
#define GetAtomName GetAtomNameW
#define GetBinaryType GetBinaryTypeW
/**
 * Returns the current process's Unicode command-line string.
 *
 * @return Pointer to the command-line string.
 *
 * @note Windows CE 3.0 only.
 */
#define GetCommandLine GetCommandLineW
#define GetCompressedFileSize GetCompressedFileSizeW
#define GetComputerName GetComputerNameW
#if (_WIN32_WINNT >= 0x0500)
#define GetComputerNameEx GetComputerNameExW
#endif
#define GetCurrentDirectory GetCurrentDirectoryW
#define GetDefaultCommConfig GetDefaultCommConfigW
#define GetDiskFreeSpace GetDiskFreeSpaceW
/**
 * Returns the total and free space on a volume.
 *
 * Values are 64-bit: don't truncate them.
 *
 * @param lpDirectoryName Any directory on the volume, e.g. L"\\PC Card",
 *        or NULL for the object store.
 * @param lpFreeBytesAvailableToCaller Receives the free bytes available
 *        to the caller. Without quotas, the same as the total free.
 * @param lpTotalNumberOfBytes Receives the volume size.
 * @param lpTotalNumberOfFreeBytes Receives the free bytes, or NULL.
 * @return Nonzero on success, 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#if (_WIN32_WINNT >= 0x0502)
#define GetDllDirectory GetDllDirectoryW
#endif
#define GetDriveType GetDriveTypeW
#define GetEnvironmentStrings GetEnvironmentStringsW
#define GetEnvironmentVariable GetEnvironmentVariableW
/**
 * Returns the attributes of a file or directory.
 *
 * @param lpFileName Path of the file or directory.
 * @return FILE_ATTRIBUTE_* flags, or 0xFFFFFFFF on failure (see
 *         GetLastError). Windows CE adds FILE_ATTRIBUTE_INROM for
 *         read-only ROM files, and FILE_ATTRIBUTE_ROMMODULE for
 *         execute-in-place ROM modules, which can't be opened with
 *         CreateFileW.
 */
#define GetFileAttributes GetFileAttributesW
#define GetFileSecurity GetFileSecurityW
/**
 * Retrieves standard attributes for a file or directory.
 *
 * Wildcards and the \\?\ path prefix are not supported. Paths are limited
 * to MAX_PATH characters.
 *
 * @param lpFileName File or directory path.
 * @param fInfoLevelId Attribute information level.
 * @param lpFileInformation Receives the requested information.
 * @return Nonzero on success, zero on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
#define GetFileAttributesEx GetFileAttributesExW
#if (_WIN32_WINNT >= 0x0600)
#define GetFinalPathNameByHandle GetFinalPathNameByHandleW
#endif
#define GetFullPathName GetFullPathNameW
#define GetLogicalDriveStrings GetLogicalDriveStringsW
#if (_WIN32_WINNT >= 0x0500 || _WIN32_WINDOWS >= 0x0410)
#define GetLongPathName GetLongPathNameW
#endif
/**
 * Returns the full path of a loaded module.
 *
 * @param hModule Module handle, or NULL for the calling process's
 *        executable.
 * @param lpFilename Receives the path.
 * @param nSize Size of lpFilename in characters.
 * @return Characters copied, excluding the terminator, or 0 on failure
 *         (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define GetModuleFileName GetModuleFileNameW
/**
 * Gets the handle of a module already mapped into the current process.
 *
 * Only the file name is used; paths are ignored. If the extension is
 * omitted, .DLL is appended. The returned handle does not increment the
 * module reference count.
 *
 * @param lpModuleName DLL or CPL file name, or NULL for the process image.
 * @return Module handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
#define GetModuleHandle GetModuleHandleW
#if (_WIN32_WINNT >= 0x0500)
#define GetModuleHandleEx GetModuleHandleExW
#endif
#define GetNamedPipeHandleState GetNamedPipeHandleStateW
#define GetPrivateProfileInt GetPrivateProfileIntW
#define GetPrivateProfileSection GetPrivateProfileSectionW
#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#define GetPrivateProfileString GetPrivateProfileStringW
#define GetPrivateProfileStruct GetPrivateProfileStructW
#ifdef _WIN32_WCE
/**
 * Returns the address of a function exported by a DLL.
 *
 * On Windows CE, the name is a Unicode string. Desktop Win32's
 * GetProcAddress takes an ANSI name.
 *
 * @param hModule Module handle from LoadLibrary.
 * @param lpProcName Export name, matching the case of the EXPORTS entry,
 *        or an ordinal in the low word with a zero high word.
 * @return The function address, or NULL on failure (see GetLastError).
 */
#define GetProcAddress GetProcAddressW
#endif
#define GetProfileInt GetProfileIntW
#define GetProfileSection GetProfileSectionW
#define GetProfileString GetProfileStringW
#define GetShortPathName GetShortPathNameW
#define GetStartupInfo GetStartupInfoW
#define GetSystemDirectory GetSystemDirectoryW
#if (_WIN32_WINNT >= 0x0500)
#define GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#endif
#if (_WIN32_WINNT >= 0x0501)
#define GetSystemWow64Directory GetSystemWow64DirectoryW
#endif
/**
 * Creates a temporary-file name in a directory.
 *
 * The prefix uses its first three characters. With nonzero uUnique, the
 * function does not create the file or check uniqueness. With zero, it
 * creates and closes a unique empty file. CE pads the hexadecimal suffix
 * to four digits; power-down does not delete these files.
 *
 * @param lpPathName Directory for the file; must not be NULL.
 * @param lpPrefixString Prefix string.
 * @param uUnique Nonzero suffix to use, or 0 to generate one and create the file.
 * @param lpTempFileName Receives the path in a MAX_PATH-sized buffer.
 * @return Numeric suffix used, or 0 on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
#define GetTempFileName GetTempFileNameW
/**
 * Returns the directory for temporary files.
 *
 * The path ends with a backslash.
 *
 * @param nBufferLength Size of lpBuffer in characters.
 * @param lpBuffer Receives the path.
 * @return Characters copied, excluding the terminator. If the buffer is
 *         too small, the size needed. 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define GetTempPath GetTempPathW
#define GetUserName GetUserNameW
/**
 * Gets the operating system version.
 *
 * Set dwOSVersionInfoSize to sizeof(OSVERSIONINFOW) before calling.
 * dwPlatformId is VER_PLATFORM_WIN32_CE. The Japanese Windows CE 2.01
 * reports itself as version 2.0. Prefer checking for a needed feature
 * directly when possible.
 *
 * @param lpVersionInformation OSVERSIONINFOW that receives the version,
 *        with dwOSVersionInfoSize set.
 * @return TRUE on success, FALSE on failure, such as dwOSVersionInfoSize
 *        being too small (see GetLastError).
 */
#define GetVersionEx GetVersionExW
#define GetVolumeInformation GetVolumeInformationW
#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#define GetVolumePathName GetVolumePathNameW
#define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#define GetWindowsDirectory GetWindowsDirectoryW
#define GlobalAddAtom GlobalAddAtomW
#define GlobalFindAtom GlobalFindAtomW
#define GlobalGetAtomName GlobalGetAtomNameW
#define IsBadStringPtr IsBadStringPtrW
/**
 * Loads a DLL or other executable module into the calling process.
 *
 * Without a path, Windows CE looks in the root of a PC Card RAM expansion
 * card (if any), then \Windows, then the root directory; there's no way to
 * set a search path. Without a path or extension, ".dll" is appended. Only
 * the base name identifies a module: once Sample.dll is loaded, loading
 * Sample.cpl or \MyDir\Sample.dll returns the same module. Loading an
 * already loaded module increments its reference count. Release with
 * FreeLibrary; get exports with GetProcAddress. An .exe can be loaded for
 * its resources.
 *
 * @param lpLibFileName File name of the module.
 * @return The module handle, or NULL on failure (see GetLastError).
 */
#define LoadLibrary LoadLibraryW
/**
 * Maps a DLL or executable module into the calling process.
 *
 * hFile must be NULL. DONT_RESOLVE_DLL_REFERENCES skips DllMain and
 * loading referenced modules; LOAD_LIBRARY_AS_DATAFILE maps a module for
 * resource access without executing it. LOAD_WITH_ALTERED_SEARCH_PATH is
 * unsupported. The first load's flags govern later loads of the same module.
 *
 * @param lpLibFileName Module file name or path.
 * @param hFile Reserved; set to NULL.
 * @param dwFlags Loading behavior flags, or 0 for LoadLibrary behavior.
 * @return Module handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 only.
 */
#define LoadLibraryEx LoadLibraryExW
#define LogonUser LogonUserW
#define LookupAccountName LookupAccountNameW
#define LookupAccountSid LookupAccountSidW
#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#define LookupPrivilegeName LookupPrivilegeNameW
#define LookupPrivilegeValue LookupPrivilegeValueW
#define lstrcat lstrcatW
/**
 * Compares two strings, case-sensitively, using locale word sort rules.
 *
 * @param lpString1 First string.
 * @param lpString2 Second string.
 * @return Negative if lpString1 sorts first, 0 if equal, positive if
 *         lpString2 sorts first.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define lstrcmp lstrcmpW
/**
 * Compares two strings, ignoring case, using locale word sort rules.
 *
 * @param lpString1 First string.
 * @param lpString2 Second string.
 * @return Negative if lpString1 sorts first, 0 if equal, positive if
 *         lpString2 sorts first.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define lstrcmpi lstrcmpiW
#define lstrcpy lstrcpyW
#define lstrcpyn lstrcpynW
#define lstrlen lstrlenW
/**
 * Renames or moves a file or a directory with its contents.
 *
 * Files can move between volumes; directories can't.
 *
 * @param lpExistingFileName Existing file or directory.
 * @param lpNewFileName New name. Must not already exist.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define MoveFile MoveFileW
#define MoveFileEx MoveFileExW
#if (_WIN32_WINNT >= 0x0500)
#define MoveFileWithProgress MoveFileWithProgressW
#endif
#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#define OpenBackupEventLog OpenBackupEventLogW
#define OpenEvent OpenEventW
#define OpenEventLog OpenEventLogW
#define OpenFileMapping OpenFileMappingW
#define OpenMutex OpenMutexW
#define OpenSemaphore OpenSemaphoreW
/**
 * Sends a string to the debugger.
 *
 * Windows CE only has the Unicode version.
 *
 * @param lpszOutputString The string to send.
 */
#define OutputDebugString OutputDebugStringW
#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#define QueryDosDevice QueryDosDeviceW
#define ReadEventLog ReadEventLogW
#define RegisterEventSource RegisterEventSourceW
/**
 * Deletes an empty directory.
 *
 * @param lpPathName Path of the directory. It must be empty.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define RemoveDirectory RemoveDirectoryW
#if (_WIN32_WINNT >= 0x0500)
#define ReplaceFile ReplaceFileW
#endif
#define ReportEvent ReportEventW
#define SearchPath SearchPathW
#define SetComputerName SetComputerNameW
#define SetCurrentDirectory SetCurrentDirectoryW
#define SetDefaultCommConfig SetDefaultCommConfigW
#if (_WIN32_WINNT >= 0x0502)
#define SetDllDirectory SetDllDirectoryW
#endif
#define SetEnvironmentVariable SetEnvironmentVariableW
/**
 * Sets a file's attributes.
 *
 * Can't change compression: FILE_ATTRIBUTE_COMPRESSED is ignored.
 *
 * @param lpFileName The file.
 * @param dwFileAttributes Any of FILE_ATTRIBUTE_ARCHIVE,
 *        FILE_ATTRIBUTE_HIDDEN, FILE_ATTRIBUTE_READONLY,
 *        FILE_ATTRIBUTE_SYSTEM and FILE_ATTRIBUTE_TEMPORARY, or
 *        FILE_ATTRIBUTE_NORMAL on its own.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define SetFileAttributes SetFileAttributesW
#define SetFileSecurity SetFileSecurityW
#if (_WIN32_WINNT >= 0x0501)
#define SetFileShortName SetFileShortNameW
#endif
#if (_WIN32_WINNT >= 0x0502)
#define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
#endif
#define SetVolumeLabel SetVolumeLabelW
#define SetVolumeMountPoint SetVolumeMountPointW
#define UpdateResource UpdateResourceW
#define VerifyVersionInfo VerifyVersionInfoW
#define WaitNamedPipe WaitNamedPipeW
#define WritePrivateProfileSection WritePrivateProfileSectionW
#define WritePrivateProfileString WritePrivateProfileStringW
#define WritePrivateProfileStruct WritePrivateProfileStructW
#define WriteProfileSection WriteProfileSectionW
#define WriteProfileString WriteProfileStringW
#else
typedef STARTUPINFOA STARTUPINFO,*LPSTARTUPINFO;
typedef WIN32_FIND_DATAA WIN32_FIND_DATA,*PWIN32_FIND_DATA,*LPWIN32_FIND_DATA;
typedef HW_PROFILE_INFOA HW_PROFILE_INFO,*LPHW_PROFILE_INFO;
#if (_WIN32_WINNT >= 0x0501)
typedef ACTCTXA ACTCTX,*PACTCTX;
typedef PCACTCTXA PCACTCTX;
#endif
#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#define AddAtom AddAtomA
#define BackupEventLog BackupEventLogA
#define BeginUpdateResource BeginUpdateResourceA
#define BuildCommDCB BuildCommDCBA
#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#define CallNamedPipe CallNamedPipeA
#if (_WIN32_WINNT >= 0x0501)
#define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#endif
#define ClearEventLog ClearEventLogA
#define CommConfigDialog CommConfigDialogA
#define CopyFile CopyFileA
#define CopyFileEx CopyFileExA
#if (_WIN32_WINNT >= 0x0501)
#define CreateActCtx CreateActCtxA
#endif
#define CreateDirectory CreateDirectoryA
#define CreateDirectoryEx CreateDirectoryExA
#define CreateEvent CreateEventA
#define CreateFile CreateFileA
#define CreateFileMapping CreateFileMappingA
#if (_WIN32_WINNT >= 0x0500)
#define CreateHardLink CreateHardLinkA
#define CreateJobObject CreateJobObjectA
#endif
#define CreateMailslot CreateMailslotA
#define CreateMutex CreateMutexA
#define CreateNamedPipe CreateNamedPipeA
#define CreateProcess CreateProcessA
#define CreateProcessAsUser CreateProcessAsUserA
#define CreateSemaphore CreateSemaphoreA
#if (_WIN32_WINNT >= 0x0600)
#define CreateSymbolicLink CreateSymbolicLinkA
#endif
#define CreateWaitableTimer CreateWaitableTimerA
#define DefineDosDevice DefineDosDeviceA
#define DeleteFile DeleteFileA
#if (_WIN32_WINNT >= 0x0500)
#define DeleteVolumeMountPoint DeleteVolumeMountPointA
#define DnsHostnameToComputerName DnsHostnameToComputerNameA
#endif
#define EncryptFile EncryptFileA
#define EndUpdateResource EndUpdateResourceA
#define EnumResourceLanguages EnumResourceLanguagesA
#define EnumResourceNames EnumResourceNamesA
#define EnumResourceTypes EnumResourceTypesA
#define ExpandEnvironmentStrings ExpandEnvironmentStringsA
#define FatalAppExit FatalAppExitA
#define FileEncryptionStatus FileEncryptionStatusA
#if (_WIN32_WINNT >= 0x0501)
#define FindActCtxSectionString FindActCtxSectionStringA
#endif
#define FindAtom FindAtomA
#define FindFirstChangeNotification FindFirstChangeNotificationA
#define FindFirstFile FindFirstFileA
#define FindFirstFileEx FindFirstFileExA
#if (_WIN32_WINNT >= 0x0500)
#define FindFirstVolume FindFirstVolumeA
#define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#endif
#define FindNextFile FindNextFileA
#if (_WIN32_WINNT >= 0x0500)
#define FindNextVolume FindNextVolumeA
#define FindNextVolumeMountPoint FindNextVolumeMountPointA
#endif
#define FindResource FindResourceA
#define FindResourceEx FindResourceExA
#define FormatMessage FormatMessageA
#define FreeEnvironmentStrings FreeEnvironmentStringsA
#define GetAtomName GetAtomNameA
#define GetBinaryType GetBinaryTypeA
#define GetCommandLine GetCommandLineA
#define GetComputerName GetComputerNameA
#if (_WIN32_WINNT >= 0x0500)
#define GetComputerNameEx GetComputerNameExA
#endif
#define GetCompressedFileSize GetCompressedFileSizeA
#define GetCurrentDirectory GetCurrentDirectoryA
#define GetDefaultCommConfig GetDefaultCommConfigA
#define GetDiskFreeSpace GetDiskFreeSpaceA
#define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#if (_WIN32_WINNT >= 0x0502)
#define GetDllDirectory GetDllDirectoryA
#endif
#define GetDriveType GetDriveTypeA
#define GetEnvironmentVariable GetEnvironmentVariableA
#define GetFileAttributes GetFileAttributesA
#define GetFileSecurity GetFileSecurityA
#define GetFileAttributesEx GetFileAttributesExA
#if (_WIN32_WINNT >= 0x0600)
#define GetFinalPathNameByHandle GetFinalPathNameByHandleA
#endif
#define GetFullPathName GetFullPathNameA
#define GetLogicalDriveStrings GetLogicalDriveStringsA
#if (_WIN32_WINNT >= 0x0500 || _WIN32_WINDOWS >= 0x0410)
#define GetLongPathName GetLongPathNameA
#endif
#define GetNamedPipeHandleState GetNamedPipeHandleStateA
#define GetModuleHandle GetModuleHandleA
#if (_WIN32_WINNT >= 0x0500)
#define GetModuleHandleEx GetModuleHandleExA
#endif
#define GetModuleFileName GetModuleFileNameA
#define GetPrivateProfileInt GetPrivateProfileIntA
#define GetPrivateProfileSection GetPrivateProfileSectionA
#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#define GetPrivateProfileString GetPrivateProfileStringA
#define GetPrivateProfileStruct GetPrivateProfileStructA
#define GetProfileInt GetProfileIntA
#define GetProfileSection GetProfileSectionA
#define GetProfileString GetProfileStringA
#define GetShortPathName GetShortPathNameA
#define GetStartupInfo GetStartupInfoA
#define GetSystemDirectory GetSystemDirectoryA
#if (_WIN32_WINNT >= 0x0500)
#define GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#endif
#if (_WIN32_WINNT >= 0x0501)
#define GetSystemWow64Directory GetSystemWow64DirectoryA
#endif
#define GetTempFileName GetTempFileNameA
#define GetTempPath GetTempPathA
#define GetUserName GetUserNameA
#define GetVersionEx GetVersionExA
#define GetVolumeInformation GetVolumeInformationA
#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#define GetVolumePathName GetVolumePathNameA
#define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#define GetWindowsDirectory GetWindowsDirectoryA
#define GlobalAddAtom GlobalAddAtomA
#define GlobalFindAtom GlobalFindAtomA
#define GlobalGetAtomName GlobalGetAtomNameA
#define IsBadStringPtr IsBadStringPtrA
#define LoadLibrary LoadLibraryA
#define LoadLibraryEx LoadLibraryExA
#define LogonUser LogonUserA
#define LookupAccountName LookupAccountNameA
#define LookupAccountSid LookupAccountSidA
#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#define LookupPrivilegeName LookupPrivilegeNameA
#define LookupPrivilegeValue LookupPrivilegeValueA
#define lstrcat lstrcatA
#define lstrcmp lstrcmpA
#define lstrcmpi lstrcmpiA
#define lstrcpy lstrcpyA
#define lstrcpyn lstrcpynA
#define lstrlen lstrlenA
#define MoveFile MoveFileA
#define MoveFileEx MoveFileExA
#if (_WIN32_WINNT >= 0x0500)
#define MoveFileWithProgress MoveFileWithProgressA
#endif
#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#define OpenBackupEventLog OpenBackupEventLogA
#define OpenEvent OpenEventA
#define OpenEventLog OpenEventLogA
#define OpenFileMapping OpenFileMappingA
#define OpenMutex OpenMutexA
#define OpenSemaphore OpenSemaphoreA
#define OutputDebugString OutputDebugStringA
#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#define QueryDosDevice QueryDosDeviceA
#define ReadEventLog ReadEventLogA
#define RegisterEventSource RegisterEventSourceA
#define RemoveDirectory RemoveDirectoryA
#if (_WIN32_WINNT >= 0x0500)
#define ReplaceFile ReplaceFileA
#endif
#define ReportEvent ReportEventA
#define SearchPath SearchPathA
#define SetComputerName SetComputerNameA
#define SetCurrentDirectory SetCurrentDirectoryA
#define SetDefaultCommConfig SetDefaultCommConfigA
#if (_WIN32_WINNT >= 0x0502)
#define SetDllDirectory SetDllDirectoryA
#endif
#define SetEnvironmentVariable SetEnvironmentVariableA
#define SetFileAttributes SetFileAttributesA
#define SetFileSecurity SetFileSecurityA
#if (_WIN32_WINNT >= 0x0501)
#define SetFileShortName SetFileShortNameA
#endif
#if (_WIN32_WINNT >= 0x0502)
#define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
#endif
#define SetVolumeLabel SetVolumeLabelA
#define SetVolumeMountPoint SetVolumeMountPointA
#define UpdateResource UpdateResourceA
#define VerifyVersionInfo VerifyVersionInfoA
#define WaitNamedPipe WaitNamedPipeA
#define WritePrivateProfileSection WritePrivateProfileSectionA
#define WritePrivateProfileString WritePrivateProfileStringA
#define WritePrivateProfileStruct WritePrivateProfileStructA
#define WriteProfileSection WriteProfileSectionA
#define WriteProfileString WriteProfileStringA
#endif
#endif

#ifdef _WIN32_WCE
#include <kfuncs.h>

#define	lstrcpyW wcscpy
#define	lstrcpynW wcsncpy
#define lstrcatW wcscat
#define lstrlenW wcslen

/**
 * Loads a device driver from its registry key and activates the device.
 *
 * The key is under HKLM and contains the driver configuration. The
 * returned handle can be passed to DeactivateDevice.
 *
 * @param lpszDevKey Registry path of the device's driver key.
 * @param dwClientInfo Per-instance value stored in the active key.
 * @return Device handle, or NULL on failure.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI HANDLE WINAPI ActivateDevice(LPCWSTR lpszDevKey, DWORD dwClientInfo);
WINBASEAPI HANDLE WINAPI ActivateDeviceEx(LPCWSTR, LPCVOID, DWORD, LPVOID);
/**
 * Unloads a device driver activated by ActivateDevice.
 *
 * Also removes the active registry key and sends device-change notifications.
 *
 * @param hDevice Handle returned by ActivateDevice.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
WINBASEAPI BOOL WINAPI DeactivateDevice(HANDLE hDevice);
/**
 * Unloads a device driver loaded with RegisterDevice.
 *
 * Windows CE specific. Use when the device is removed or shut down.
 *
 * @param hDevice Handle from RegisterDevice.
 * @return TRUE on success, FALSE on failure.
 */
WINBASEAPI BOOL DeregisterDevice(HANDLE hDevice);
/**
 * Loads a stream device driver and gives it a device name such as COM1:.
 *
 * Applications then open the device with CreateFile. The driver DLL exports
 * its entry points with the prefix as their names' start, such as
 * COM_Init, so one DLL can implement several device types. Unregister with
 * DeregisterDevice.
 *
 * @param lpszType Three-character device prefix, such as L"COM".
 * @param dwIndex Device index, 0 to 9: 2 makes COM2:.
 * @param lpszLib File name of the driver DLL.
 * @param dwInfo Value passed to the driver's Init entry point, such as a
 *        port address.
 * @return The device handle, or 0 on failure.
 */
WINBASEAPI HANDLE RegisterDevice(LPCWSTR lpszType, DWORD dwIndex, LPCWSTR lpszLib, DWORD dwInfo);
#endif /* _WIN32_WCE */

#ifdef __cplusplus
}
#endif
#endif /* _WINBASE_H */

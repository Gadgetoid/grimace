#ifndef _WINREG_H
#define _WINREG_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef WINADVAPI
#define WINADVAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define HKEY_CLASSES_ROOT	((HKEY)0x80000000)
#define HKEY_CURRENT_USER	((HKEY)0x80000001)
#define HKEY_LOCAL_MACHINE	((HKEY)0x80000002)
#define HKEY_USERS	((HKEY)0x80000003)
#define HKEY_PERFORMANCE_DATA	((HKEY)0x80000004)
#define HKEY_CURRENT_CONFIG	((HKEY)0x80000005)
#define HKEY_DYN_DATA	((HKEY)0x80000006)
#define REG_OPTION_VOLATILE 1
#define REG_OPTION_NON_VOLATILE 0
#define REG_CREATED_NEW_KEY 1
#define REG_OPENED_EXISTING_KEY 2
#define REG_NONE 0
#define REG_SZ 1
#define REG_EXPAND_SZ 2
#define REG_BINARY 3
#define REG_DWORD_LITTLE_ENDIAN 4
#define REG_DWORD 4
#define REG_DWORD_BIG_ENDIAN 5
#define REG_LINK 6
#define REG_MULTI_SZ 7
#define REG_RESOURCE_LIST 8
#define REG_FULL_RESOURCE_DESCRIPTOR 9
#define REG_RESOURCE_REQUIREMENTS_LIST 10
#define REG_QWORD_LITTLE_ENDIAN 11
#define REG_QWORD 11
#define REG_NOTIFY_CHANGE_NAME 1
#define REG_NOTIFY_CHANGE_ATTRIBUTES 2
#define REG_NOTIFY_CHANGE_LAST_SET 4
#define REG_NOTIFY_CHANGE_SECURITY 8

#ifndef RC_INVOKED
typedef ACCESS_MASK REGSAM;
typedef struct value_entA {
	LPSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD ve_valueptr;
	DWORD ve_type;
} VALENTA,*PVALENTA;
typedef struct value_entW {
	LPWSTR ve_valuename;
	DWORD ve_valuelen;
	DWORD ve_valueptr;
	DWORD ve_type;
} VALENTW,*PVALENTW;
WINADVAPI BOOL WINAPI AbortSystemShutdownA(LPCSTR);
WINADVAPI BOOL WINAPI AbortSystemShutdownW(LPCWSTR);
WINADVAPI BOOL WINAPI InitiateSystemShutdownA(LPSTR,LPSTR,DWORD,BOOL,BOOL);
WINADVAPI BOOL WINAPI InitiateSystemShutdownW(LPWSTR,LPWSTR,DWORD,BOOL,BOOL);
/**
 * Closes a registry key handle.
 *
 * Windows CE writes changes to the registry before returning. On Windows
 * CE 1.0 and 2.0 there is no RegFlushKey to call; on later platforms with
 * persistent registry storage, RegFlushKey can request a flush to
 * storage, depending on the OEM.
 *
 * @param hKey Key opened with RegOpenKeyExW or RegCreateKeyExW.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegCloseKey(HKEY hKey);
WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR,HKEY,PHKEY);
WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR,HKEY,PHKEY);
WINADVAPI LONG WINAPI RegCreateKeyA(HKEY,LPCSTR,PHKEY);
WINADVAPI LONG WINAPI RegCreateKeyExA(HKEY,LPCSTR,DWORD,LPSTR,DWORD,REGSAM,LPSECURITY_ATTRIBUTES,PHKEY,PDWORD);
/**
 * Creates a registry key, or opens it if it exists.
 *
 * The new key has no values: add them with RegSetValueExW. Close the
 * handle with RegCloseKey.
 *
 * @param hKey Open key, or HKEY_CLASSES_ROOT, HKEY_CURRENT_USER,
 *        HKEY_LOCAL_MACHINE or HKEY_USERS.
 * @param lpszSubKey Subkey name, relative to hKey. Not NULL, and must not
 *        start with a backslash.
 * @param Reserved Must be 0.
 * @param lpszClass Class string for a new key, or NULL. Ignored if the key
 *        exists.
 * @param dwOptions Ignored on Windows CE. Pass 0.
 * @param samDesired Ignored on Windows CE. Pass 0.
 * @param lpSecurityAttributes Not supported. Pass NULL.
 * @param phkResult Receives the key handle.
 * @param lpdwDisposition Receives REG_CREATED_NEW_KEY or
 *        REG_OPENED_EXISTING_KEY, or NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegCreateKeyExW(HKEY hKey,LPCWSTR lpszSubKey,DWORD Reserved,LPWSTR lpszClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,PDWORD lpdwDisposition);
WINADVAPI LONG WINAPI RegCreateKeyW(HKEY,LPCWSTR,PHKEY);
WINADVAPI LONG WINAPI RegDeleteKeyA(HKEY,LPCSTR);
/**
 * Deletes a registry key, with its values and subkeys.
 *
 * Windows CE won't delete a key that is open.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszSubKey Name of the subkey to delete, relative to hKey. Not
 *        NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegDeleteKeyW(HKEY hKey,LPCWSTR lpszSubKey);
#if (WINVER >= 0x0502)
WINADVAPI LONG WINAPI RegDeleteKeyExA(HKEY,LPCSTR,REGSAM,DWORD);
WINADVAPI LONG WINAPI RegDeleteKeyExW(HKEY,LPCWSTR,REGSAM,DWORD);
#endif
WINADVAPI LONG WINAPI RegDeleteValueA(HKEY,LPCSTR);
/**
 * Deletes a value from a registry key.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, or NULL or L"" for the key's default
 *        value.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegDeleteValueW(HKEY hKey,LPCWSTR lpszValueName);
WINADVAPI LONG WINAPI RegEnumKeyA(HKEY,DWORD,LPSTR,DWORD);
WINADVAPI LONG WINAPI RegEnumKeyW(HKEY,DWORD,LPWSTR,DWORD);
WINADVAPI LONG WINAPI RegEnumKeyExA(HKEY,DWORD,LPSTR,PDWORD,PDWORD,LPSTR,PDWORD,PFILETIME);
/**
 * Returns the name of one subkey of a registry key, by index.
 *
 * Call with dwIndex from 0 upwards until it returns ERROR_NO_MORE_ITEMS.
 * Order is arbitrary. Don't modify the key while enumerating.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param dwIndex Subkey index.
 * @param lpszName Receives the subkey name (not the full path).
 * @param lpcchName In: buffer size in characters, including the terminator.
 *        Out: characters stored, excluding the terminator.
 * @param lpReserved Must be NULL.
 * @param lpszClass Receives the subkey's class, or NULL.
 * @param lpcchClass In/out size of lpszClass in characters. NULL only if
 *        lpszClass is NULL.
 * @param lpftLastWriteTime Not used on Windows CE.
 * @return ERROR_SUCCESS, ERROR_NO_MORE_ITEMS at the end, or an error code.
 */
WINADVAPI LONG WINAPI RegEnumKeyExW(HKEY hKey,DWORD dwIndex,LPWSTR lpszName,PDWORD lpcchName,PDWORD lpReserved,LPWSTR lpszClass,PDWORD lpcchClass,PFILETIME lpftLastWriteTime);
WINADVAPI LONG WINAPI RegEnumValueA(HKEY,DWORD,LPSTR,PDWORD,PDWORD,PDWORD,LPBYTE,PDWORD);
/**
 * Returns the name, type and data of one value of a registry key, by
 * index.
 *
 * Call with dwIndex from 0 upwards until it returns ERROR_NO_MORE_ITEMS.
 * Order is arbitrary. RegQueryInfoKeyW gives the largest name and data
 * sizes for sizing buffers.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param dwIndex Value index.
 * @param lpszValueName Receives the value name.
 * @param lpcchValueName In: buffer size in characters, including the
 *        terminator. Out: characters stored, excluding the terminator.
 * @param lpReserved Must be NULL.
 * @param lpType Receives the type (REG_SZ, REG_DWORD, REG_BINARY,
 *        REG_MULTI_SZ and so on), or NULL.
 * @param lpData Receives the data, or NULL.
 * @param lpcbData In: size of lpData in bytes. Out: bytes stored. NULL
 *        only if lpData is NULL.
 * @return ERROR_SUCCESS, ERROR_NO_MORE_ITEMS at the end, or an error code.
 */
WINADVAPI LONG WINAPI RegEnumValueW(HKEY hKey,DWORD dwIndex,LPWSTR lpszValueName,PDWORD lpcchValueName,PDWORD lpReserved,PDWORD lpType,LPBYTE lpData,PDWORD lpcbData);
/**
 * Requests that the registry be flushed to platform-supported storage.
 *
 * Returns only when the data has been written. On Windows CE 2.1 and
 * later this may flush the entire registry, not just the specified key.
 * Whether persistent storage or flushing is supported depends on the OEM:
 * without it, or if the OEM fails the request, the call fails. There is
 * no lazy flush by default, so call it to save important settings, after
 * a group of changes rather than every individual change; frequent
 * flushes hurt performance.
 *
 * @param hKey Open key or a predefined HKEY_* root. Validated but ignored.
 * @return ERROR_SUCCESS, or an error code.
 *
 * @note Windows CE 2.0 and later.
 */
WINADVAPI LONG WINAPI RegFlushKey(HKEY hKey);
WINADVAPI LONG WINAPI RegGetKeySecurity(HKEY,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,PDWORD);
WINADVAPI LONG WINAPI RegLoadKeyA(HKEY,LPCSTR,LPCSTR);
WINADVAPI LONG WINAPI RegLoadKeyW(HKEY,LPCWSTR,LPCWSTR);
WINADVAPI LONG WINAPI RegNotifyChangeKeyValue(HKEY,BOOL,DWORD,HANDLE,BOOL);
WINADVAPI LONG WINAPI RegOpenKeyA(HKEY,LPCSTR,PHKEY);
WINADVAPI LONG WINAPI RegOpenKeyExA(HKEY,LPCSTR,DWORD,REGSAM,PHKEY);
/**
 * Opens an existing registry key.
 *
 * Doesn't create the key: use RegCreateKeyExW for that. Close the handle
 * with RegCloseKey.
 *
 * @param hKey Open key, or HKEY_CLASSES_ROOT, HKEY_CURRENT_USER,
 *        HKEY_LOCAL_MACHINE or HKEY_USERS.
 * @param lpszSubKey Subkey path relative to hKey, e.g. L"Software\\Vendor",
 *        or NULL or L"" for a new handle to hKey itself.
 * @param ulOptions Reserved. Must be 0.
 * @param samDesired Ignored on Windows CE: any access is allowed. Pass 0.
 * @param phkResult Receives the key handle.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegOpenKeyExW(HKEY hKey,LPCWSTR lpszSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
WINADVAPI LONG WINAPI RegOpenKeyW(HKEY,LPCWSTR,PHKEY);
WINADVAPI LONG WINAPI RegQueryInfoKeyA(HKEY,LPSTR,PDWORD,PDWORD,PDWORD,PDWORD,PDWORD,PDWORD,PDWORD,PDWORD,PDWORD,PFILETIME);
/**
 * Returns a registry key's class, subkey and value counts, and the longest
 * name and data sizes.
 *
 * Lengths in characters exclude the terminator.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszClass Receives the key's class, or NULL.
 * @param lpcchClass In/out size of lpszClass in characters. ERROR_MORE_DATA
 *        if too small. Can be NULL if lpszClass is NULL.
 * @param lpReserved Must be NULL.
 * @param lpcSubKeys Receives the number of subkeys.
 * @param lpcchMaxSubKeyLen Receives the longest subkey name length.
 * @param lpcchMaxClassLen Receives the longest subkey class length.
 * @param lpcValues Receives the number of values.
 * @param lpcchMaxValueNameLen Receives the longest value name length, or
 *        NULL.
 * @param lpcbMaxValueData Not supported on Windows CE. Pass NULL.
 * @param lpcbSecurityDescriptor Not supported. Pass NULL.
 * @param lpftLastWriteTime Not supported. Pass NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegQueryInfoKeyW(HKEY hKey,LPWSTR lpszClass,PDWORD lpcchClass,PDWORD lpReserved,PDWORD lpcSubKeys,PDWORD lpcchMaxSubKeyLen,PDWORD lpcchMaxClassLen,PDWORD lpcValues,PDWORD lpcchMaxValueNameLen,PDWORD lpcbMaxValueData,PDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
WINADVAPI LONG WINAPI RegQueryMultipleValuesA(HKEY,PVALENTA,DWORD,LPSTR,LPDWORD);
WINADVAPI LONG WINAPI RegQueryMultipleValuesW(HKEY,PVALENTW,DWORD,LPWSTR,LPDWORD);
WINADVAPI LONG WINAPI RegQueryValueA(HKEY,LPCSTR,LPSTR,PLONG);
WINADVAPI LONG WINAPI RegQueryValueExA(HKEY,LPCSTR,LPDWORD,LPDWORD,LPBYTE,LPDWORD);
/**
 * Reads the type and data of a registry value.
 *
 * Pass lpData as NULL to get the size needed in *lpcbData. REG_EXPAND_SZ
 * data isn't expanded.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, or NULL or L"" for the default value.
 * @param lpReserved Must be NULL.
 * @param lpType Receives the type (REG_SZ, REG_DWORD, REG_BINARY,
 *        REG_MULTI_SZ and so on), or NULL.
 * @param lpData Receives the data, or NULL.
 * @param lpcbData In: size of lpData in bytes. Out: bytes stored,
 *        including any string terminator. NULL only if lpData is NULL.
 * @return ERROR_SUCCESS, ERROR_MORE_DATA if lpData is too small (the size
 *         needed is stored in *lpcbData), or an error code such as
 *         ERROR_FILE_NOT_FOUND.
 */
WINADVAPI LONG WINAPI RegQueryValueExW(HKEY hKey,LPCWSTR lpszValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
WINADVAPI LONG WINAPI RegQueryValueW(HKEY,LPCWSTR,LPWSTR,PLONG);
WINADVAPI LONG WINAPI RegReplaceKeyA(HKEY,LPCSTR,LPCSTR,LPCSTR);
WINADVAPI LONG WINAPI RegReplaceKeyW(HKEY,LPCWSTR,LPCWSTR,LPCWSTR);
WINADVAPI LONG WINAPI RegRestoreKeyA(HKEY,LPCSTR,DWORD);
WINADVAPI LONG WINAPI RegRestoreKeyW(HKEY,LPCWSTR,DWORD);
WINADVAPI LONG WINAPI RegSaveKeyA(HKEY,LPCSTR,LPSECURITY_ATTRIBUTES);
WINADVAPI LONG WINAPI RegSaveKeyW(HKEY,LPCWSTR,LPSECURITY_ATTRIBUTES);
WINADVAPI LONG WINAPI RegSetKeySecurity(HKEY,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
WINADVAPI LONG WINAPI RegSetValueA(HKEY,LPCSTR,DWORD,LPCSTR,DWORD);
WINADVAPI LONG WINAPI RegSetValueExA(HKEY,LPCSTR,DWORD,DWORD,const BYTE*,DWORD);
/**
 * Creates or replaces a value in a registry key.
 *
 * Keep values small: store anything over about 2 KB, and icons, bitmaps
 * or executables, in a file and put its name in the registry.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, up to 255 characters, or NULL or L"" for
 *        the default value.
 * @param Reserved Must be 0.
 * @param dwType REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ, REG_DWORD,
 *        REG_BINARY, REG_NONE and so on.
 * @param lpData The data. Strings are WCHAR.
 * @param cbData Size of lpData in bytes, including the terminator(s) for
 *        string types. At most about 3.7 KB on Windows CE.
 * @return ERROR_SUCCESS, or an error code.
 */
WINADVAPI LONG WINAPI RegSetValueExW(HKEY hKey,LPCWSTR lpszValueName,DWORD Reserved,DWORD dwType,const BYTE*lpData,DWORD cbData);
WINADVAPI LONG WINAPI RegSetValueW(HKEY,LPCWSTR,DWORD,LPCWSTR,DWORD);
WINADVAPI LONG WINAPI RegUnLoadKeyA(HKEY,LPCSTR);
WINADVAPI LONG WINAPI RegUnLoadKeyW(HKEY,LPCWSTR);

#ifdef UNICODE
typedef VALENTW VALENT,*PVALENT;
#define AbortSystemShutdown AbortSystemShutdownW
#define InitiateSystemShutdown InitiateSystemShutdownW
#define RegConnectRegistry RegConnectRegistryW
#define RegCreateKey RegCreateKeyW
/**
 * Creates a registry key, or opens it if it exists.
 *
 * The new key has no values: add them with RegSetValueExW. Close the
 * handle with RegCloseKey.
 *
 * @param hKey Open key, or HKEY_CLASSES_ROOT, HKEY_CURRENT_USER,
 *        HKEY_LOCAL_MACHINE or HKEY_USERS.
 * @param lpszSubKey Subkey name, relative to hKey. Not NULL, and must not
 *        start with a backslash.
 * @param Reserved Must be 0.
 * @param lpszClass Class string for a new key, or NULL. Ignored if the key
 *        exists.
 * @param dwOptions Ignored on Windows CE. Pass 0.
 * @param samDesired Ignored on Windows CE. Pass 0.
 * @param lpSecurityAttributes Not supported. Pass NULL.
 * @param phkResult Receives the key handle.
 * @param lpdwDisposition Receives REG_CREATED_NEW_KEY or
 *        REG_OPENED_EXISTING_KEY, or NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegCreateKeyEx RegCreateKeyExW
/**
 * Deletes a registry key, with its values and subkeys.
 *
 * Windows CE won't delete a key that is open.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszSubKey Name of the subkey to delete, relative to hKey. Not
 *        NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegDeleteKey RegDeleteKeyW
#if (WINVER >= 0x0502)
#define RegDeleteKeyEx RegDeleteKeyExW
#endif
/**
 * Deletes a value from a registry key.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, or NULL or L"" for the key's default
 *        value.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegDeleteValue RegDeleteValueW
#define RegEnumKey RegEnumKeyW
/**
 * Returns the name of one subkey of a registry key, by index.
 *
 * Call with dwIndex from 0 upwards until it returns ERROR_NO_MORE_ITEMS.
 * Order is arbitrary. Don't modify the key while enumerating.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param dwIndex Subkey index.
 * @param lpszName Receives the subkey name (not the full path).
 * @param lpcchName In: buffer size in characters, including the terminator.
 *        Out: characters stored, excluding the terminator.
 * @param lpReserved Must be NULL.
 * @param lpszClass Receives the subkey's class, or NULL.
 * @param lpcchClass In/out size of lpszClass in characters. NULL only if
 *        lpszClass is NULL.
 * @param lpftLastWriteTime Not used on Windows CE.
 * @return ERROR_SUCCESS, ERROR_NO_MORE_ITEMS at the end, or an error code.
 */
#define RegEnumKeyEx RegEnumKeyExW
/**
 * Returns the name, type and data of one value of a registry key, by
 * index.
 *
 * Call with dwIndex from 0 upwards until it returns ERROR_NO_MORE_ITEMS.
 * Order is arbitrary. RegQueryInfoKeyW gives the largest name and data
 * sizes for sizing buffers.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param dwIndex Value index.
 * @param lpszValueName Receives the value name.
 * @param lpcchValueName In: buffer size in characters, including the
 *        terminator. Out: characters stored, excluding the terminator.
 * @param lpReserved Must be NULL.
 * @param lpType Receives the type (REG_SZ, REG_DWORD, REG_BINARY,
 *        REG_MULTI_SZ and so on), or NULL.
 * @param lpData Receives the data, or NULL.
 * @param lpcbData In: size of lpData in bytes. Out: bytes stored. NULL
 *        only if lpData is NULL.
 * @return ERROR_SUCCESS, ERROR_NO_MORE_ITEMS at the end, or an error code.
 */
#define RegEnumValue RegEnumValueW
#define RegLoadKey RegLoadKeyW
#define RegOpenKey RegOpenKeyW
/**
 * Opens an existing registry key.
 *
 * Doesn't create the key: use RegCreateKeyExW for that. Close the handle
 * with RegCloseKey.
 *
 * @param hKey Open key, or HKEY_CLASSES_ROOT, HKEY_CURRENT_USER,
 *        HKEY_LOCAL_MACHINE or HKEY_USERS.
 * @param lpszSubKey Subkey path relative to hKey, e.g. L"Software\\Vendor",
 *        or NULL or L"" for a new handle to hKey itself.
 * @param ulOptions Reserved. Must be 0.
 * @param samDesired Ignored on Windows CE: any access is allowed. Pass 0.
 * @param phkResult Receives the key handle.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegOpenKeyEx RegOpenKeyExW
/**
 * Returns a registry key's class, subkey and value counts, and the longest
 * name and data sizes.
 *
 * Lengths in characters exclude the terminator.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszClass Receives the key's class, or NULL.
 * @param lpcchClass In/out size of lpszClass in characters. ERROR_MORE_DATA
 *        if too small. Can be NULL if lpszClass is NULL.
 * @param lpReserved Must be NULL.
 * @param lpcSubKeys Receives the number of subkeys.
 * @param lpcchMaxSubKeyLen Receives the longest subkey name length.
 * @param lpcchMaxClassLen Receives the longest subkey class length.
 * @param lpcValues Receives the number of values.
 * @param lpcchMaxValueNameLen Receives the longest value name length, or
 *        NULL.
 * @param lpcbMaxValueData Not supported on Windows CE. Pass NULL.
 * @param lpcbSecurityDescriptor Not supported. Pass NULL.
 * @param lpftLastWriteTime Not supported. Pass NULL.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegQueryInfoKey RegQueryInfoKeyW
#define RegQueryMultipleValues RegQueryMultipleValuesW
#define RegQueryValue RegQueryValueW
/**
 * Reads the type and data of a registry value.
 *
 * Pass lpData as NULL to get the size needed in *lpcbData. REG_EXPAND_SZ
 * data isn't expanded.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, or NULL or L"" for the default value.
 * @param lpReserved Must be NULL.
 * @param lpType Receives the type (REG_SZ, REG_DWORD, REG_BINARY,
 *        REG_MULTI_SZ and so on), or NULL.
 * @param lpData Receives the data, or NULL.
 * @param lpcbData In: size of lpData in bytes. Out: bytes stored,
 *        including any string terminator. NULL only if lpData is NULL.
 * @return ERROR_SUCCESS, ERROR_MORE_DATA if lpData is too small (the size
 *         needed is stored in *lpcbData), or an error code such as
 *         ERROR_FILE_NOT_FOUND.
 */
#define RegQueryValueEx RegQueryValueExW
#define RegReplaceKey RegReplaceKeyW
#define RegRestoreKey RegRestoreKeyW
#define RegSaveKey RegSaveKeyW
#define RegSetValue RegSetValueW
/**
 * Creates or replaces a value in a registry key.
 *
 * Keep values small: store anything over about 2 KB, and icons, bitmaps
 * or executables, in a file and put its name in the registry.
 *
 * @param hKey Open key, or a predefined HKEY_* root.
 * @param lpszValueName Value name, up to 255 characters, or NULL or L"" for
 *        the default value.
 * @param Reserved Must be 0.
 * @param dwType REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ, REG_DWORD,
 *        REG_BINARY, REG_NONE and so on.
 * @param lpData The data. Strings are WCHAR.
 * @param cbData Size of lpData in bytes, including the terminator(s) for
 *        string types. At most about 3.7 KB on Windows CE.
 * @return ERROR_SUCCESS, or an error code.
 */
#define RegSetValueEx RegSetValueExW
#define RegUnLoadKey RegUnLoadKeyW
#else
typedef VALENTA VALENT,*PVALENT;
#define AbortSystemShutdown AbortSystemShutdownA
#define InitiateSystemShutdown InitiateSystemShutdownA
#define RegConnectRegistry RegConnectRegistryA
#define RegCreateKey RegCreateKeyA
#define RegCreateKeyEx RegCreateKeyExA
#define RegDeleteKey RegDeleteKeyA
#if (WINVER >= 0x0502)
#define RegDeleteKeyEx RegDeleteKeyExA
#endif
#define RegDeleteValue RegDeleteValueA
#define RegEnumKey RegEnumKeyA
#define RegEnumKeyEx RegEnumKeyExA
#define RegEnumValue RegEnumValueA
#define RegLoadKey RegLoadKeyA
#define RegOpenKey RegOpenKeyA
#define RegOpenKeyEx RegOpenKeyExA
#define RegQueryInfoKey RegQueryInfoKeyA
#define RegQueryMultipleValues RegQueryMultipleValuesA
#define RegQueryValue RegQueryValueA
#define RegQueryValueEx RegQueryValueExA
#define RegReplaceKey RegReplaceKeyA
#define RegRestoreKey RegRestoreKeyA
#define RegSaveKey RegSaveKeyA
#define RegSetValue RegSetValueA
#define RegSetValueEx RegSetValueExA
#define RegUnLoadKey RegUnLoadKeyA
#endif
#endif
#ifdef __cplusplus
}
#endif
#endif

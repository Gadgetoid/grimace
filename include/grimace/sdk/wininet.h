#ifndef GRIMACE_SDK_WININET_H
#define GRIMACE_SDK_WININET_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Commits a local file to the Internet cache under a URL.
 * This ANSI string variant follows the CE behavior of `CommitUrlCacheEntryW` and uses ANSI text.
 *
 * Use the local file name returned by CreateUrlCacheEntryA. Supply at
 * least "HTTP/1.0 200 OK\r\n\r\n" in the headers for entries consumed
 * by WinInet. Set dwReserved to zero.
 *
 * @param lpszUrlName Unique source URL, without escape characters.
 * @param lpszLocalFileName Local file holding the cached data.
 * @param ExpireTime Expiration time, or zero if unknown.
 * @param LastModifiedTime Last modification time, or zero if unknown.
 * @param CacheEntryType Cache type flags.
 * @param lpHeaderInfo Optional header data.
 * @param dwHeaderSize Header size in bytes.
 * @param lpszFileExtension Extension metadata for the cache.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL CommitUrlCacheEntryA(LPCSTR lpszUrlName, LPCSTR lpszLocalFileName, FILETIME ExpireTime, FILETIME LastModifiedTime, DWORD CacheEntryType, LPBYTE lpHeaderInfo, DWORD dwHeaderSize, LPCSTR lpszFileExtension, DWORD dwReserved);
/**
 * Commits a local file to the Internet cache under a URL.
 *
 * Use the local file name returned by CreateUrlCacheEntryW. Supply at
 * least "HTTP/1.0 200 OK\r\n\r\n" in the headers for entries consumed
 * by WinInet. Set dwReserved to zero.
 *
 * @param lpszUrlName Unique source URL, without escape characters.
 * @param lpszLocalFileName Local file holding the cached data.
 * @param ExpireTime Expiration time, or zero if unknown.
 * @param LastModifiedTime Last modification time, or zero if unknown.
 * @param CacheEntryType Cache type flags.
 * @param lpHeaderInfo Optional header data.
 * @param dwHeaderSize Header size in bytes.
 * @param lpszFileExtension Extension metadata for the cache.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL CommitUrlCacheEntryW(LPCWSTR lpszUrlName, LPCWSTR lpszLocalFileName, FILETIME ExpireTime, FILETIME LastModifiedTime, DWORD CacheEntryType, LPWSTR lpHeaderInfo, DWORD dwHeaderSize, LPCWSTR lpszFileExtension, DWORD dwReserved);
/**
 * Creates a local cache-file name for a URL.
 * This ANSI string variant follows the CE behavior of `CreateUrlCacheEntryW` and uses ANSI text.
 *
 * The output buffer should hold MAX_PATH characters. Write the data to
 * the returned file, then commit it with CommitUrlCacheEntryA. Set
 * dwReserved to zero.
 *
 * @param lpszUrlName Unique source URL, without escape characters.
 * @param dwExpectedFileSize Expected file size, or zero if unknown.
 * @param lpszFileExtension Extension metadata for the cache.
 * @param lpszFileName Receives the local file name.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL CreateUrlCacheEntryA(LPCSTR lpszUrlName, DWORD dwExpectedFileSize, LPCSTR lpszFileExtension, LPSTR lpszFileName, DWORD dwReserved);
/**
 * Creates a local cache-file name for a URL.
 *
 * The output buffer should hold MAX_PATH characters. Write the data to
 * the returned file, then commit it with CommitUrlCacheEntryW. Set
 * dwReserved to zero.
 *
 * @param lpszUrlName Unique source URL, without escape characters.
 * @param dwExpectedFileSize Expected file size, or zero if unknown.
 * @param lpszFileExtension Extension metadata for the cache.
 * @param lpszFileName Receives the local file name.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL CreateUrlCacheEntryW(LPCWSTR lpszUrlName, DWORD dwExpectedFileSize, LPCWSTR lpszFileExtension, LPWSTR lpszFileName, DWORD dwReserved);
typedef LONGLONG GROUPID;
/**
 * Creates a cache group or generates a group identifier.
 *
 * CACHEGROUP_FLAG_GIDONLY returns a unique ID without creating a physical
 * group. Set lpReserved to NULL.
 *
 * @param dwFlags CACHEGROUP_FLAG_GIDONLY or zero.
 * @param lpReserved Reserved; set to NULL.
 * @return Group ID, or zero on failure.
 *
 * @note Windows CE 3.0 and later.
 */
GROUPID CreateUrlCacheGroup(DWORD dwFlags, LPVOID lpReserved);
/**
 * Removes a URL and its associated file from the cache.
 * This ANSI string variant follows the CE behavior of `DeleteUrlCacheEntryW` and uses ANSI text.
 *
 * @param lpszUrlName Cache entry URL, without escape characters.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL DeleteUrlCacheEntryA(LPCSTR lpszUrlName);
/**
 * Removes a URL and its associated file from the cache.
 *
 * @param lpszUrlName Cache entry URL, without escape characters.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL DeleteUrlCacheEntryW(LPCWSTR lpszUrlName);
/**
 * Deletes a cache group and optionally its associated entries.
 *
 * CACHEGROUP_FLAG_FLUSHURL_ONDELETE deletes entries not shared by another
 * group. Set lpReserved to NULL.
 *
 * @param GroupId Cache group identifier.
 * @param dwFlags CACHEGROUP_FLAG_FLUSHURL_ONDELETE or zero.
 * @param lpReserved Reserved; set to NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL DeleteUrlCacheGroup(GROUPID GroupId, DWORD dwFlags, LPVOID lpReserved);
/**
 * Closes a URL-cache enumeration handle.
 *
 * @param hEnumHandle Handle returned by a cache enumeration function.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FindCloseUrlCache(HANDLE hEnumHandle);
struct _INTERNET_CACHE_ENTRY_INFOA;
typedef struct _INTERNET_CACHE_ENTRY_INFOA *LPINTERNET_CACHE_ENTRY_INFOA;
/**
 * Begins enumeration of Internet cache entries matching a pattern.
 * This ANSI string variant follows the CE behavior of `FindFirstUrlCacheEntryW` and uses ANSI text.
 *
 * A NULL pattern searches all entries. If the buffer is too small,
 * ERROR_INSUFFICIENT_BUFFER is returned and the required size is written
 * to the size parameter. Close the enumeration with FindCloseUrlCache.
 *
 * @param lpszUrlSearchPattern URL pattern, "cookie:", "visited:", or NULL.
 * @param lpFirstCacheEntryInfo Receives the first entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @return Enumeration handle, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
HANDLE FindFirstUrlCacheEntryA(LPCSTR lpszUrlSearchPattern, LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize);
/**
 * Begins a filtered enumeration of Internet cache entries.
 * This ANSI string variant follows the CE behavior of `FindFirstUrlCacheEntryExW` and uses ANSI text.
 *
 * A NULL pattern searches all entries. Set dwFlags to zero and all
 * reserved parameters to NULL. GroupId zero selects entries in no group.
 * Close the returned handle with FindCloseUrlCache.
 *
 * @param lpszUrlSearchPattern URL pattern, "cookie:", "visited:", or NULL.
 * @param dwFlags Reserved; set to zero.
 * @param dwFilter Cache entry types to include.
 * @param GroupId Group to enumerate, or zero for ungrouped entries.
 * @param lpFirstCacheEntryInfo Receives the first entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @param lpGroupAttributes Reserved; set to NULL.
 * @param pcbGroupAttributes Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @return Enumeration handle, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
HANDLE FindFirstUrlCacheEntryExA(LPCSTR lpszUrlSearchPattern, DWORD dwFlags, DWORD dwFilter, GROUPID GroupId, LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize, LPVOID lpGroupAttributes, LPDWORD pcbGroupAttributes, LPVOID lpReserved);
struct _INTERNET_CACHE_ENTRY_INFOW;
typedef struct _INTERNET_CACHE_ENTRY_INFOW *LPINTERNET_CACHE_ENTRY_INFOW;
/**
 * Begins a filtered enumeration of Internet cache entries.
 *
 * A NULL pattern searches all entries. Set dwFlags to zero and all
 * reserved parameters to NULL. GroupId zero selects entries in no group.
 * Close the returned handle with FindCloseUrlCache.
 *
 * @param lpszUrlSearchPattern URL pattern, "cookie:", "visited:", or NULL.
 * @param dwFlags Reserved; set to zero.
 * @param dwFilter Cache entry types to include.
 * @param GroupId Group to enumerate, or zero for ungrouped entries.
 * @param lpFirstCacheEntryInfo Receives the first entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @param lpGroupAttributes Reserved; set to NULL.
 * @param pcbGroupAttributes Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @return Enumeration handle, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
HANDLE FindFirstUrlCacheEntryExW(LPCWSTR lpszUrlSearchPattern, DWORD dwFlags, DWORD dwFilter, GROUPID GroupId, LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize, LPVOID lpGroupAttributes, LPDWORD pcbGroupAttributes, LPVOID lpReserved);
/**
 * Begins enumeration of Internet cache entries matching a pattern.
 *
 * A NULL pattern searches all entries. If the buffer is too small,
 * ERROR_INSUFFICIENT_BUFFER is returned and the required size is written
 * to the size parameter. Close the enumeration with FindCloseUrlCache.
 *
 * @param lpszUrlSearchPattern URL pattern, "cookie:", "visited:", or NULL.
 * @param lpFirstCacheEntryInfo Receives the first entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @return Enumeration handle, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
HANDLE FindFirstUrlCacheEntryW(LPCWSTR lpszUrlSearchPattern, LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize);
/**
 * Retrieves the next entry in a cache enumeration.
 * This ANSI string variant follows the CE behavior of `FindNextUrlCacheEntryW` and uses ANSI text.
 *
 * If the entry buffer is too small, the size parameter receives the
 * required byte count.
 *
 * @param hEnumHandle Enumeration handle from FindFirstUrlCacheEntryA.
 * @param lpNextCacheEntryInfo Receives the next entry.
 * @param lpdwNextCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @return TRUE when an entry is retrieved, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FindNextUrlCacheEntryA(HANDLE hEnumHandle, LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo, LPDWORD lpdwNextCacheEntryInfoBufferSize);
/**
 * Retrieves the next entry in a filtered cache enumeration.
 * This ANSI string variant follows the CE behavior of `FindNextUrlCacheEntryExW` and uses ANSI text.
 *
 * Set reserved parameters to NULL. Call FindCloseUrlCache when done.
 *
 * @param hEnumHandle Enumeration handle from FindFirstUrlCacheEntryExA.
 * @param lpFirstCacheEntryInfo Receives the next entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @param lpGroupAttributes Reserved; set to NULL.
 * @param pcbGroupAttributes Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @return TRUE when an entry is retrieved, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FindNextUrlCacheEntryExA(HANDLE hEnumHandle, LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize, LPVOID lpGroupAttributes, LPDWORD pcbGroupAttributes, LPVOID lpReserved);
/**
 * Retrieves the next entry in a filtered cache enumeration.
 *
 * Set reserved parameters to NULL. Call FindCloseUrlCache when done.
 *
 * @param hEnumHandle Enumeration handle from FindFirstUrlCacheEntryExW.
 * @param lpFirstCacheEntryInfo Receives the next entry.
 * @param lpdwFirstCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @param lpGroupAttributes Reserved; set to NULL.
 * @param pcbGroupAttributes Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @return TRUE when an entry is retrieved, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FindNextUrlCacheEntryExW(HANDLE hEnumHandle, LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo, LPDWORD lpdwFirstCacheEntryInfoBufferSize, LPVOID lpGroupAttributes, LPDWORD pcbGroupAttributes, LPVOID lpReserved);
/**
 * Retrieves the next entry in a cache enumeration.
 *
 * If the entry buffer is too small, the size parameter receives the
 * required byte count.
 *
 * @param hEnumHandle Enumeration handle from FindFirstUrlCacheEntryW.
 * @param lpNextCacheEntryInfo Receives the next entry.
 * @param lpdwNextCacheEntryInfoBufferSize Input size and output bytes
 *        copied or required.
 * @return TRUE when an entry is retrieved, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FindNextUrlCacheEntryW(HANDLE hEnumHandle, LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo, LPDWORD lpdwNextCacheEntryInfoBufferSize);
typedef LPVOID HINTERNET;
/**
 * Creates a directory on an FTP server.
 * This ANSI string variant follows the CE behavior of `FtpCreateDirectoryW` and uses ANSI text.
 *
 * The directory may be relative to the server's current directory or a
 * qualified path. Use FtpGetCurrentDirectoryA rather than assuming the
 * server's directory layout. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszDirectory Remote directory to create.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpCreateDirectoryA(HINTERNET hConnect, LPCSTR lpszDirectory);
/**
 * Creates a directory on an FTP server.
 *
 * The directory may be relative to the server's current directory or a
 * qualified path. Use FtpGetCurrentDirectoryW rather than assuming the
 * server's directory layout. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszDirectory Remote directory to create.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpCreateDirectoryW(HINTERNET hConnect, LPCWSTR lpszDirectory);
/**
 * Deletes a file on an FTP server.
 * This ANSI string variant follows the CE behavior of `FtpDeleteFileW` and uses ANSI text.
 *
 * The name may be relative to the server's current directory or qualified.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszFileName Remote file to delete.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpDeleteFileA(HINTERNET hConnect, LPCSTR lpszFileName);
/**
 * Deletes a file on an FTP server.
 *
 * The name may be relative to the server's current directory or qualified.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszFileName Remote file to delete.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpDeleteFileW(HINTERNET hConnect, LPCWSTR lpszFileName);
/**
 * Starts enumerating files and directories in an FTP directory.
 * This ANSI string variant follows the CE behavior of `FtpFindFirstFileW` and uses ANSI text.
 *
 * Use InternetFindNextFileA to continue and InternetCloseHandle to end the
 * search. Only one enumeration can be active per FTP session. The SDK
 * lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszSearchFile File or directory pattern, or NULL for current directory.
 * @param lpFindFileData Receives the first entry.
 * @param dwFlags Cache and transfer options.
 * @param dwContext Application context passed to the status callback.
 * @return Enumeration handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
HINTERNET FtpFindFirstFileA(HINTERNET hConnect, LPCSTR lpszSearchFile, LPWIN32_FIND_DATAA lpFindFileData, DWORD dwFlags, DWORD dwContext);
/**
 * Starts enumerating files and directories in an FTP directory.
 *
 * Use InternetFindNextFileW to continue and InternetCloseHandle to end the
 * search. Only one enumeration can be active per FTP session. The SDK
 * lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszSearchFile File or directory pattern, or NULL for current directory.
 * @param lpFindFileData Receives the first entry.
 * @param dwFlags Cache and transfer options.
 * @param dwContext Application context passed to the status callback.
 * @return Enumeration handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
HINTERNET FtpFindFirstFileW(HINTERNET hConnect, LPCWSTR lpszSearchFile, LPWIN32_FIND_DATAW lpFindFileData, DWORD dwFlags, DWORD dwContext);
/**
 * Retrieves the current directory for an FTP session.
 * This ANSI string variant follows the CE behavior of `FtpGetCurrentDirectoryW` and uses ANSI text.
 *
 * The length includes space for the terminating null. If the buffer is
 * too small, the length parameter receives the required size. The SDK
 * lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszCurrentDirectory Receives the remote directory.
 * @param lpdwCurrentDirectory Input buffer size and output characters
 *        copied or required.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpGetCurrentDirectoryA(HINTERNET hConnect, LPSTR lpszCurrentDirectory, LPDWORD lpdwCurrentDirectory);
/**
 * Retrieves the current directory for an FTP session.
 *
 * The length includes space for the terminating null. If the buffer is
 * too small, the length parameter receives the required size. The SDK
 * lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszCurrentDirectory Receives the remote directory.
 * @param lpdwCurrentDirectory Input buffer size and output characters
 *        copied or required.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpGetCurrentDirectoryW(HINTERNET hConnect, LPWSTR lpszCurrentDirectory, LPDWORD lpdwCurrentDirectory);
/**
 * Downloads a remote FTP file to a local file.
 * This ANSI string variant follows the CE behavior of `FtpGetFileW` and uses ANSI text.
 *
 * Binary transfer is the default; select ASCII for text translation.
 * Use FtpOpenFileA with InternetReadFile for direct control over a
 * transfer. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszRemoteFile Remote file to retrieve.
 * @param lpszNewFile Local file to create.
 * @param fFailIfExists TRUE to fail if the local file exists.
 * @param dwFlagsAndAttributes Attributes for the local file.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpGetFileA(HINTERNET hConnect, LPCSTR lpszRemoteFile, LPCSTR lpszNewFile, BOOL fFailIfExists, DWORD dwFlagsAndAttributes, DWORD dwFlags, DWORD dwContext);
/**
 * Downloads a remote FTP file to a local file.
 *
 * Binary transfer is the default; select ASCII for text translation.
 * Use FtpOpenFileW with InternetReadFile for direct control over a
 * transfer. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszRemoteFile Remote file to retrieve.
 * @param lpszNewFile Local file to create.
 * @param fFailIfExists TRUE to fail if the local file exists.
 * @param dwFlagsAndAttributes Attributes for the local file.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpGetFileW(HINTERNET hConnect, LPCWSTR lpszRemoteFile, LPCWSTR lpszNewFile, BOOL fFailIfExists, DWORD dwFlagsAndAttributes, DWORD dwFlags, DWORD dwContext);
/**
 * Opens a remote FTP file for reading or writing.
 * This ANSI string variant follows the CE behavior of `FtpOpenFileW` and uses ANSI text.
 *
 * Use InternetReadFile or InternetWriteFile for data. Only one file may
 * be open per FTP session; close the returned handle with InternetCloseHandle.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszFileName Remote file name.
 * @param dwAccess GENERIC_READ or GENERIC_WRITE, not both.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return Internet handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
HINTERNET FtpOpenFileA(HINTERNET hConnect, LPCSTR lpszFileName, DWORD dwAccess, DWORD dwFlags, DWORD dwContext);
/**
 * Opens a remote FTP file for reading or writing.
 *
 * Use InternetReadFile or InternetWriteFile for data. Only one file may
 * be open per FTP session; close the returned handle with InternetCloseHandle.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszFileName Remote file name.
 * @param dwAccess GENERIC_READ or GENERIC_WRITE, not both.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return Internet handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
HINTERNET FtpOpenFileW(HINTERNET hConnect, LPCWSTR lpszFileName, DWORD dwAccess, DWORD dwFlags, DWORD dwContext);
/**
 * Uploads a local file to an FTP server.
 * This ANSI string variant follows the CE behavior of `FtpPutFileW` and uses ANSI text.
 *
 * Use FtpOpenFileA and InternetWriteFile for direct transfer control.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszLocalFile Local file to send.
 * @param lpszNewRemoteFile Remote file to create.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpPutFileA(HINTERNET hConnect, LPCSTR lpszLocalFile, LPCSTR lpszNewRemoteFile, DWORD dwFlags, DWORD dwContext);
/**
 * Uploads a local file to an FTP server.
 *
 * Use FtpOpenFileW and InternetWriteFile for direct transfer control.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszLocalFile Local file to send.
 * @param lpszNewRemoteFile Remote file to create.
 * @param dwFlags Transfer type and cache options.
 * @param dwContext Application context passed to the status callback.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpPutFileW(HINTERNET hConnect, LPCWSTR lpszLocalFile, LPCWSTR lpszNewRemoteFile, DWORD dwFlags, DWORD dwContext);
/**
 * Removes a directory from an FTP server.
 * This ANSI string variant follows the CE behavior of `FtpRemoveDirectoryW` and uses ANSI text.
 *
 * Use FtpGetCurrentDirectoryA rather than assuming the server's directory
 * layout. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszDirectory Remote directory to remove.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpRemoveDirectoryA(HINTERNET hConnect, LPCSTR lpszDirectory);
/**
 * Removes a directory from an FTP server.
 *
 * Use FtpGetCurrentDirectoryW rather than assuming the server's directory
 * layout. The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszDirectory Remote directory to remove.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpRemoveDirectoryW(HINTERNET hConnect, LPCWSTR lpszDirectory);
/**
 * Renames a file on an FTP server.
 * This ANSI string variant follows the CE behavior of `FtpRenameFileW` and uses ANSI text.
 *
 * The names may be relative to the server's current directory or qualified.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszExisting Current remote file name.
 * @param lpszNew New remote file name.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpRenameFileA(HINTERNET hConnect, LPCSTR lpszExisting, LPCSTR lpszNew);
/**
 * Renames a file on an FTP server.
 *
 * The names may be relative to the server's current directory or qualified.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszExisting Current remote file name.
 * @param lpszNew New remote file name.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpRenameFileW(HINTERNET hConnect, LPCWSTR lpszExisting, LPCWSTR lpszNew);
/**
 * Changes the current directory for an FTP session.
 * This ANSI string variant follows the CE behavior of `FtpSetCurrentDirectoryW` and uses ANSI text.
 *
 * Use FtpGetCurrentDirectoryA to query the server's actual current path.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectA.
 * @param lpszDirectory Directory to select.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpSetCurrentDirectoryA(HINTERNET hConnect, LPCSTR lpszDirectory);
/**
 * Changes the current directory for an FTP session.
 *
 * Use FtpGetCurrentDirectoryW to query the server's actual current path.
 * The SDK lists Inetftp.dll only for Intel x86.
 *
 * @param hConnect FTP session from InternetConnectW.
 * @param lpszDirectory Directory to select.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL FtpSetCurrentDirectoryW(HINTERNET hConnect, LPCWSTR lpszDirectory);
/**
 * Retrieves information about a URL cache entry.
 * This ANSI string variant follows the CE behavior of `GetUrlCacheEntryInfoW` and uses ANSI text.
 *
 * The URL is matched as stored; anchors are not parsed. The size
 * parameter is the input buffer size and receives the bytes copied or
 * required.
 *
 * @param lpszUrlName Cache entry name without escape characters.
 * @param lpCacheEntryInfo Receives cache entry information.
 * @param lpdwCacheEntryInfoBufferSize Buffer size in bytes; receives
 *        bytes copied or required.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL GetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufferSize);
/**
 * Retrieves cache information for a URL after applying cached redirects.
 * This ANSI string variant follows the CE behavior of `GetUrlCacheEntryInfoExW` and uses ANSI text.
 *
 * Set all reserved parameters and dwFlags to zero. The size parameter is
 * the input buffer size and receives the bytes copied.
 *
 * @param lpszUrl Cache URL, without escape characters.
 * @param lpCacheEntryInfo Receives cache entry information.
 * @param lpdwCacheEntryInfoBufSize Input size and output bytes copied or required.
 * @param lpszReserved Reserved; set to NULL.
 * @param lpdwReserved Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE if the URL is found, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL GetUrlCacheEntryInfoExA(LPCSTR lpszUrl, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufSize, LPSTR lpszReserved, LPDWORD lpdwReserved, LPVOID lpReserved, DWORD dwFlags);
/**
 * Retrieves cache information for a URL after applying cached redirects.
 *
 * Set all reserved parameters and dwFlags to zero. The size parameter is
 * the input buffer size and receives the bytes copied.
 *
 * @param lpszUrl Cache URL, without escape characters.
 * @param lpCacheEntryInfo Receives cache entry information.
 * @param lpdwCacheEntryInfoBufSize Input size and output bytes copied or required.
 * @param lpszReserved Reserved; set to NULL.
 * @param lpdwReserved Reserved; set to NULL.
 * @param lpReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE if the URL is found, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL GetUrlCacheEntryInfoExW(LPCWSTR lpszUrl, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufSize, LPWSTR lpszReserved, LPDWORD lpdwReserved, LPVOID lpReserved, DWORD dwFlags);
/**
 * Retrieves information about a URL cache entry.
 *
 * The URL is matched as stored; anchors are not parsed. The size
 * parameter is the input buffer size and receives the bytes copied or
 * required.
 *
 * @param lpszUrlName Cache entry name without escape characters.
 * @param lpCacheEntryInfo Receives cache entry information.
 * @param lpdwCacheEntryInfoBufferSize Buffer size in bytes; receives
 *        bytes copied or required.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL GetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufferSize);
/**
 * Adds or updates headers on an HTTP request.
 * This ANSI string variant follows the CE behavior of `HttpAddRequestHeadersW` and uses ANSI text.
 *
 * Terminate each header with CR-LF. Use HTTP_ADDREQ_FLAG_* to append,
 * replace or coalesce headers.
 *
 * @param hRequest Open request from HttpOpenRequestA.
 * @param lpszHeaders Header lines to add.
 * @param dwHeadersLength Header length in characters, or -1 for a
 *        null-terminated string.
 * @param dwModifiers HTTP_ADDREQ_FLAG_* options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpAddRequestHeadersA(HINTERNET hRequest, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers);
/**
 * Adds or updates headers on an HTTP request.
 *
 * Terminate each header with CR-LF. Use HTTP_ADDREQ_FLAG_* to append,
 * replace or coalesce headers.
 *
 * @param hRequest Open request from HttpOpenRequestW.
 * @param lpszHeaders Header lines to add.
 * @param dwHeadersLength Header length in characters, or -1 for a
 *        null-terminated string.
 * @param dwModifiers HTTP_ADDREQ_FLAG_* options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpAddRequestHeadersW(HINTERNET hRequest, LPCWSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwModifiers);
struct _INTERNET_BUFFERSA;
typedef struct _INTERNET_BUFFERSA *LPINTERNET_BUFFERSA;
/**
 * Finishes a request started with HttpSendRequestExA.
 * This ANSI string variant follows the CE behavior of `HttpEndRequestW` and uses ANSI text.
 *
 * @param hRequest Request handle.
 * @param lpBuffersOut Optional output buffers.
 * @param dwFlags HSR_* request flags.
 * @param dwContext Application callback context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL HttpEndRequestA(HINTERNET hRequest, LPINTERNET_BUFFERSA lpBuffersOut, DWORD dwFlags, DWORD dwContext);
struct _INTERNET_BUFFERSW;
typedef struct _INTERNET_BUFFERSW *LPINTERNET_BUFFERSW;
/**
 * Finishes a request started with HttpSendRequestExW.
 *
 * @param hRequest Request handle.
 * @param lpBuffersOut Optional output buffers.
 * @param dwFlags HSR_* request flags.
 * @param dwContext Application callback context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL HttpEndRequestW(HINTERNET hRequest, LPINTERNET_BUFFERSW lpBuffersOut, DWORD dwFlags, DWORD dwContext);
/**
 * Creates an HTTP request handle on a connected session.
 * This ANSI string variant follows the CE behavior of `HttpOpenRequestW` and uses ANSI text.
 *
 * NULL verb defaults to GET; NULL version defaults to HTTP/1.0. Use
 * InternetCloseHandle to close the request. WinInet requests complete
 * synchronously on CE.
 *
 * @param hConnect HTTP session from InternetConnectA.
 * @param lpszVerb Request method, or NULL for GET.
 * @param lpszObjectName Target path or object.
 * @param lpszVersion HTTP version, or NULL for HTTP/1.0.
 * @param lpszReferrer Referring URL, or NULL.
 * @param lplpszAcceptTypes Null-terminated accepted content types, or NULL.
 * @param dwFlags HTTP request flags.
 * @param dwContext Application callback context.
 * @return Request handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET HttpOpenRequestA(HINTERNET hConnect, LPCSTR lpszVerb, LPCSTR lpszObjectName, LPCSTR lpszVersion, LPCSTR lpszReferrer, LPCSTR *lplpszAcceptTypes, DWORD dwFlags, DWORD dwContext);
/**
 * Creates an HTTP request handle on a connected session.
 *
 * NULL verb defaults to GET; NULL version defaults to HTTP/1.0. Use
 * InternetCloseHandle to close the request. WinInet requests complete
 * synchronously on CE.
 *
 * @param hConnect HTTP session from InternetConnectW.
 * @param lpszVerb Request method, or NULL for GET.
 * @param lpszObjectName Target path or object.
 * @param lpszVersion HTTP version, or NULL for HTTP/1.0.
 * @param lpszReferrer Referring URL, or NULL.
 * @param lplpszAcceptTypes Null-terminated accepted content types, or NULL.
 * @param dwFlags HTTP request flags.
 * @param dwContext Application callback context.
 * @return Request handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET HttpOpenRequestW(HINTERNET hConnect, LPCWSTR lpszVerb, LPCWSTR lpszObjectName, LPCWSTR lpszVersion, LPCWSTR lpszReferrer, LPCWSTR *lplpszAcceptTypes, DWORD dwFlags, DWORD dwContext);
/**
 * Queries an HTTP response or request header.
 * This ANSI string variant follows the CE behavior of `HttpQueryInfoW` and uses ANSI text.
 *
 * Use HTTP_QUERY_* with optional flags such as HTTP_QUERY_FLAG_NUMBER or
 * HTTP_QUERY_FLAG_SYSTEMTIME. For repeated headers, use lpdwIndex to
 * select and advance through values. The length is in characters for
 * string results.
 *
 * @param hRequest Open HTTP request handle.
 * @param dwInfoLevel Header to retrieve and result format.
 * @param lpBuffer Receives the header value.
 * @param lpdwBufferLength Input buffer size and output length or required
 *        size.
 * @param lpdwIndex Index for repeated headers; receives the next index.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpQueryInfoA(HINTERNET hRequest, DWORD dwInfoLevel, LPVOID lpBuffer, LPDWORD lpdwBufferLength, LPDWORD lpdwIndex);
/**
 * Queries an HTTP response or request header.
 *
 * Use HTTP_QUERY_* with optional flags such as HTTP_QUERY_FLAG_NUMBER or
 * HTTP_QUERY_FLAG_SYSTEMTIME. For repeated headers, use lpdwIndex to
 * select and advance through values. The length is in characters for
 * string results.
 *
 * @param hRequest Open HTTP request handle.
 * @param dwInfoLevel Header to retrieve and result format.
 * @param lpBuffer Receives the header value.
 * @param lpdwBufferLength Input buffer size and output length or required
 *        size.
 * @param lpdwIndex Index for repeated headers; receives the next index.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpQueryInfoW(HINTERNET hRequest, DWORD dwInfoLevel, LPVOID lpBuffer, LPDWORD lpdwBufferLength, LPDWORD lpdwIndex);
/**
 * Sends an HTTP request and optional body to the server.
 * This ANSI string variant follows the CE behavior of `HttpSendRequestW` and uses ANSI text.
 *
 * Optional data is commonly used with POST or PUT. On CE its buffer must
 * be smaller than 32 bytes or larger than about 150 bytes, and begin with
 * CR-LF. Read the response before reusing the request handle.
 *
 * @param hRequest Open HTTP request handle.
 * @param lpszHeaders Additional headers, or NULL.
 * @param dwHeadersLength Header length in characters, or -1 for a
 *        null-terminated string.
 * @param lpOptional Optional request body, or NULL.
 * @param dwOptionalLength Body length in bytes.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpSendRequestA(HINTERNET hRequest, LPCSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength);
/**
 * Begins sending a request body, including chunked transfers.
 * This ANSI string variant follows the CE behavior of `HttpSendRequestExW` and uses ANSI text.
 *
 * Use HttpEndRequestA to finish the operation.
 *
 * @param hRequest Request handle from HttpOpenRequestA.
 * @param lpBuffersIn Optional input buffers.
 * @param lpBuffersOut Optional output buffers.
 * @param dwFlags HSR_* transfer flags.
 * @param dwContext Application callback context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL HttpSendRequestExA(HINTERNET hRequest, LPINTERNET_BUFFERSA lpBuffersIn, LPINTERNET_BUFFERSA lpBuffersOut, DWORD dwFlags, DWORD dwContext);
/**
 * Begins sending a request body, including chunked transfers.
 *
 * Use HttpEndRequestW to finish the operation.
 *
 * @param hRequest Request handle from HttpOpenRequestW.
 * @param lpBuffersIn Optional input buffers.
 * @param lpBuffersOut Optional output buffers.
 * @param dwFlags HSR_* transfer flags.
 * @param dwContext Application callback context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL HttpSendRequestExW(HINTERNET hRequest, LPINTERNET_BUFFERSW lpBuffersIn, LPINTERNET_BUFFERSW lpBuffersOut, DWORD dwFlags, DWORD dwContext);
/**
 * Sends an HTTP request and optional body to the server.
 *
 * Optional data is commonly used with POST or PUT. On CE its buffer must
 * be smaller than 32 bytes or larger than about 150 bytes, and begin with
 * CR-LF. Read the response before reusing the request handle.
 *
 * @param hRequest Open HTTP request handle.
 * @param lpszHeaders Additional headers, or NULL.
 * @param dwHeadersLength Header length in characters, or -1 for a
 *        null-terminated string.
 * @param lpOptional Optional request body, or NULL.
 * @param dwOptionalLength Body length in bytes.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL HttpSendRequestW(HINTERNET hRequest, LPCWSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength);
/**
 * Canonicalizes a URL, escaping unsafe characters and removing meta segments.
 * This ANSI string variant follows the CE behavior of `InternetCanonicalizeUrlW` and uses ANSI text.
 *
 * Use ICU_DECODE with ICU_NO_ENCODE to decode without re-encoding. CE
 * reports lengths in characters; on insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpszUrl URL to canonicalize.
 * @param lpszBuffer Receives the canonical URL.
 * @param lpdwBufferLength Buffer size in characters; receives result
 *        length or required size.
 * @param dwFlags ICU_* canonicalization options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCanonicalizeUrlA(LPCSTR lpszUrl, LPSTR lpszBuffer, LPDWORD lpdwBufferLength, DWORD dwFlags);
/**
 * Canonicalizes a URL, escaping unsafe characters and removing meta segments.
 *
 * Use ICU_DECODE with ICU_NO_ENCODE to decode without re-encoding. CE
 * reports lengths in characters; on insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpszUrl URL to canonicalize.
 * @param lpszBuffer Receives the canonical URL.
 * @param lpdwBufferLength Buffer size in characters; receives result
 *        length or required size.
 * @param dwFlags ICU_* canonicalization options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCanonicalizeUrlW(LPCWSTR lpszUrl, LPWSTR lpszBuffer, LPDWORD lpdwBufferLength, DWORD dwFlags);
/**
 * Closes an Internet handle and its child handles.
 *
 * Closing cancels pending operations and discards outstanding data. With
 * asynchronous requests, completion callbacks may arrive before the final
 * INTERNET_STATUS_HANDLE_CLOSING callback.
 *
 * @param hInternet Handle to close.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCloseHandle(HINTERNET hInternet);
/**
 * Combines a base URL and relative URL into a canonical URL.
 * This ANSI string variant follows the CE behavior of `InternetCombineUrlW` and uses ANSI text.
 *
 * CE reports lengths in characters. On insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpszBaseUrl Base URL.
 * @param lpszRelativeUrl Relative URL.
 * @param lpszBuffer Receives the combined URL.
 * @param lpdwBufferLength Buffer size in characters; receives result
 *        length or required size.
 * @param dwFlags ICU_* canonicalization options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCombineUrlA(LPCSTR lpszBaseUrl, LPCSTR lpszRelativeUrl, LPSTR lpszBuffer, LPDWORD lpdwBufferLength, DWORD dwFlags);
/**
 * Combines a base URL and relative URL into a canonical URL.
 *
 * CE reports lengths in characters. On insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpszBaseUrl Base URL.
 * @param lpszRelativeUrl Relative URL.
 * @param lpszBuffer Receives the combined URL.
 * @param lpdwBufferLength Buffer size in characters; receives result
 *        length or required size.
 * @param dwFlags ICU_* canonicalization options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCombineUrlW(LPCWSTR lpszBaseUrl, LPCWSTR lpszRelativeUrl, LPWSTR lpszBuffer, LPDWORD lpdwBufferLength, DWORD dwFlags);
typedef WORD INTERNET_PORT;
/**
 * Opens an FTP or HTTP session to a server.
 * This ANSI string variant follows the CE behavior of `InternetConnectW` and uses ANSI text.
 *
 * CE supports FTP and HTTP, not Gopher; INTERNET_FLAG_SECURE is not
 * supported here. FTP may use INTERNET_FLAG_PASSIVE. Use
 * InternetCloseHandle to close the session. Requests complete
 * synchronously on CE.
 *
 * @param hInternet Internet session from InternetOpenA.
 * @param lpszServerName Host name or dotted-decimal address.
 * @param nServerPort Service port, or INTERNET_INVALID_PORT_NUMBER for default.
 * @param lpszUserName User name, or NULL for the service default.
 * @param lpszPassword Password, or NULL for the service default.
 * @param dwService INTERNET_SERVICE_FTP or INTERNET_SERVICE_HTTP.
 * @param dwFlags Service flags, including INTERNET_FLAG_PASSIVE for FTP.
 * @param dwContext Application callback context.
 * @return Connection handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetConnectA(HINTERNET hInternet, LPCSTR lpszServerName, INTERNET_PORT nServerPort, LPCSTR lpszUserName, LPCSTR lpszPassword, DWORD dwService, DWORD dwFlags, DWORD dwContext);
/**
 * Opens an FTP or HTTP session to a server.
 *
 * CE supports FTP and HTTP, not Gopher; INTERNET_FLAG_SECURE is not
 * supported here. FTP may use INTERNET_FLAG_PASSIVE. Use
 * InternetCloseHandle to close the session. Requests complete
 * synchronously on CE.
 *
 * @param hInternet Internet session from InternetOpenW.
 * @param lpszServerName Host name or dotted-decimal address.
 * @param nServerPort Service port, or INTERNET_INVALID_PORT_NUMBER for default.
 * @param lpszUserName User name, or NULL for the service default.
 * @param lpszPassword Password, or NULL for the service default.
 * @param dwService INTERNET_SERVICE_FTP or INTERNET_SERVICE_HTTP.
 * @param dwFlags Service flags, including INTERNET_FLAG_PASSIVE for FTP.
 * @param dwContext Application callback context.
 * @return Connection handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetConnectW(HINTERNET hInternet, LPCWSTR lpszServerName, INTERNET_PORT nServerPort, LPCWSTR lpszUserName, LPCWSTR lpszPassword, DWORD dwService, DWORD dwFlags, DWORD dwContext);
typedef enum {
    INTERNET_SCHEME_PARTIAL = -2,
    INTERNET_SCHEME_UNKNOWN = -1,
    INTERNET_SCHEME_DEFAULT = 0,
    INTERNET_SCHEME_FTP,
    INTERNET_SCHEME_GOPHER,
    INTERNET_SCHEME_HTTP,
    INTERNET_SCHEME_HTTPS,
    INTERNET_SCHEME_FILE,
    INTERNET_SCHEME_NEWS,
    INTERNET_SCHEME_MAILTO,
    INTERNET_SCHEME_SOCKS,
    INTERNET_SCHEME_JAVASCRIPT,
    INTERNET_SCHEME_VBSCRIPT,
    INTERNET_SCHEME_FIRST = 1,
    INTERNET_SCHEME_LAST = 10
} INTERNET_SCHEME;

typedef struct {
    DWORD dwStructSize;
    LPSTR lpszScheme;
    DWORD dwSchemeLength;
    INTERNET_SCHEME nScheme;
    LPSTR lpszHostName;
    DWORD dwHostNameLength;
    INTERNET_PORT nPort;
    LPSTR lpszUserName;
    DWORD dwUserNameLength;
    LPSTR lpszPassword;
    DWORD dwPasswordLength;
    LPSTR lpszUrlPath;
    DWORD dwUrlPathLength;
    LPSTR lpszExtraInfo;
    DWORD dwExtraInfoLength;
} URL_COMPONENTSA;

typedef URL_COMPONENTSA *LPURL_COMPONENTSA;
/**
 * Splits a URL into components described by URL_COMPONENTS.
 * This ANSI string variant follows the CE behavior of `InternetCrackUrlW` and uses ANSI text.
 *
 * Set dwStructSize in the structure. For each component, supply a buffer
 * and its capacity to receive a copy, or a null buffer and nonzero length
 * to receive a pointer into the input URL. ICU_DECODE and ICU_ESCAPE
 * require component buffers.
 *
 * @param lpszUrl Null-terminated URL to parse.
 * @param dwUrlLength URL length, or zero for a null-terminated string.
 * @param dwFlags ICU_DECODE and/or ICU_ESCAPE.
 * @param lpUrlComponents Receives the components; initialize dwStructSize.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCrackUrlA(LPCSTR lpszUrl, DWORD dwUrlLength, DWORD dwFlags, LPURL_COMPONENTSA lpUrlComponents);
typedef struct {
    DWORD dwStructSize;
    LPWSTR lpszScheme;
    DWORD dwSchemeLength;
    INTERNET_SCHEME nScheme;
    LPWSTR lpszHostName;
    DWORD dwHostNameLength;
    INTERNET_PORT nPort;
    LPWSTR lpszUserName;
    DWORD dwUserNameLength;
    LPWSTR lpszPassword;
    DWORD dwPasswordLength;
    LPWSTR lpszUrlPath;
    DWORD dwUrlPathLength;
    LPWSTR lpszExtraInfo;
    DWORD dwExtraInfoLength;
} URL_COMPONENTSW;

typedef URL_COMPONENTSW *LPURL_COMPONENTSW;
/**
 * Splits a URL into components described by URL_COMPONENTS.
 *
 * Set dwStructSize in the structure. For each component, supply a buffer
 * and its capacity to receive a copy, or a null buffer and nonzero length
 * to receive a pointer into the input URL. ICU_DECODE and ICU_ESCAPE
 * require component buffers.
 *
 * @param lpszUrl Null-terminated URL to parse.
 * @param dwUrlLength URL length, or zero for a null-terminated string.
 * @param dwFlags ICU_DECODE and/or ICU_ESCAPE.
 * @param lpUrlComponents Receives the components; initialize dwStructSize.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCrackUrlW(LPCWSTR lpszUrl, DWORD dwUrlLength, DWORD dwFlags, LPURL_COMPONENTSW lpUrlComponents);
/**
 * Builds a URL from URL_COMPONENTS.
 * This ANSI string variant follows the CE behavior of `InternetCreateUrlW` and uses ANSI text.
 *
 * CE reports lengths in characters; on insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpUrlComponents URL parts to combine.
 * @param dwFlags ICU_ESCAPE and/or ICU_USERNAME.
 * @param lpszUrl Receives the URL.
 * @param lpdwUrlLength Buffer size in characters; receives result length
 *        or required size.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCreateUrlA(LPURL_COMPONENTSA lpUrlComponents, DWORD dwFlags, LPSTR lpszUrl, LPDWORD lpdwUrlLength);
/**
 * Builds a URL from URL_COMPONENTS.
 *
 * CE reports lengths in characters; on insufficient buffer, the required
 * length includes the terminator.
 *
 * @param lpUrlComponents URL parts to combine.
 * @param dwFlags ICU_ESCAPE and/or ICU_USERNAME.
 * @param lpszUrl Receives the URL.
 * @param lpdwUrlLength Buffer size in characters; receives result length
 *        or required size.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetCreateUrlW(LPURL_COMPONENTSW lpUrlComponents, DWORD dwFlags, LPWSTR lpszUrl, LPDWORD lpdwUrlLength);
/**
 * Displays the appropriate dialog for an Internet request error.
 *
 * FLAGS_ERROR_UI_FILTER_FOR_ERRORS can inspect response headers for
 * authentication errors hidden by HttpSendRequest. Results can request
 * the request be retried.
 *
 * @param hWnd Parent window, or NULL.
 * @param hRequest Internet request handle.
 * @param dwError Error to display.
 * @param dwFlags Error-dialog options.
 * @param lppvData Error-specific data, or NULL when unused.
 * @return ERROR_SUCCESS, ERROR_CANCELLED or ERROR_INTERNET_FORCE_RETRY.
 *
 * @note Windows CE 2.0 and later.
 */
DWORD InternetErrorDlg(HWND hWnd, HINTERNET hRequest, DWORD dwError, DWORD dwFlags, LPVOID *lppvData);
/**
 * Retrieves the next file or directory in an Internet enumeration.
 * This ANSI string variant follows the CE behavior of `InternetFindNextFileW` and uses ANSI text.
 *
 * For FTP, lpvFindData receives WIN32_FIND_DATA. FALSE with
 * ERROR_NO_MORE_FILES indicates the enumeration is complete.
 *
 * @param hFind Enumeration handle from FtpFindFirstFileA or a directory URL.
 * @param lpvFindData Receives the next entry.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetFindNextFileA(HINTERNET hFind, LPVOID lpvFindData);
/**
 * Retrieves the next file or directory in an Internet enumeration.
 *
 * For FTP, lpvFindData receives WIN32_FIND_DATA. FALSE with
 * ERROR_NO_MORE_FILES indicates the enumeration is complete.
 *
 * @param hFind Enumeration handle from FtpFindFirstFileW or a directory URL.
 * @param lpvFindData Receives the next entry.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetFindNextFileW(HINTERNET hFind, LPVOID lpvFindData);
/**
 * Checks whether the local system has an Internet connection.
 *
 * lpdwFlags can identify configured, LAN, modem, offline, proxy or RAS
 * state. Set dwReserved to zero.
 *
 * @param lpdwFlags Receives INTERNET_CONNECTION_* and INTERNET_RAS_INSTALLED flags.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE if connected, FALSE otherwise.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetGetConnectedState(LPDWORD lpdwFlags, DWORD dwReserved);
/**
 * Retrieves cookies associated with a URL.
 * This ANSI string variant follows the CE behavior of `InternetGetCookieW` and uses ANSI text.
 *
 * lpszCookieName is not implemented. Set lpCookieData to NULL to query
 * the required size. Persistent cookies come from the cookies directory;
 * session cookies are available only in the process that set them.
 *
 * @param lpszUrl URL associated with the cookies.
 * @param lpszCookieName Unimplemented; pass NULL.
 * @param lpCookieData Receives cookie data, or NULL to query size.
 * @param lpdwSize Buffer size and output bytes required or copied.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetGetCookieA(LPCSTR lpszUrl, LPCSTR lpszCookieName, LPSTR lpCookieData, LPDWORD lpdwSize);
/**
 * Retrieves cookies associated with a URL.
 *
 * lpszCookieName is not implemented. Set lpCookieData to NULL to query
 * the required size. Persistent cookies come from the cookies directory;
 * session cookies are available only in the process that set them.
 *
 * @param lpszUrl URL associated with the cookies.
 * @param lpszCookieName Unimplemented; pass NULL.
 * @param lpCookieData Receives cookie data, or NULL to query size.
 * @param lpdwSize Buffer size and output bytes required or copied.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetGetCookieW(LPCWSTR lpszUrl, LPCWSTR lpszCookieName, LPWSTR lpCookieData, LPDWORD lpdwSize);
/**
 * Retrieves extended error text from the last Internet operation on this thread.
 * This ANSI string variant follows the CE behavior of `InternetGetLastResponseInfoW` and uses ANSI text.
 *
 * Use after GetLastError returns ERROR_INTERNET_EXTENDED_ERROR. The output
 * length excludes the terminator; ERROR_INSUFFICIENT_BUFFER reports the
 * required size.
 *
 * @param lpdwError Receives the Internet error code.
 * @param lpszBuffer Receives the null-terminated text.
 * @param lpdwBufferLength Buffer size and output characters copied.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetGetLastResponseInfoA(LPDWORD lpdwError, LPSTR lpszBuffer, LPDWORD lpdwBufferLength);
/**
 * Retrieves extended error text from the last Internet operation on this thread.
 *
 * Use after GetLastError returns ERROR_INTERNET_EXTENDED_ERROR. The output
 * length excludes the terminator; ERROR_INSUFFICIENT_BUFFER reports the
 * required size.
 *
 * @param lpdwError Receives the Internet error code.
 * @param lpszBuffer Receives the null-terminated text.
 * @param lpdwBufferLength Buffer size and output characters copied.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetGetLastResponseInfoW(LPDWORD lpdwError, LPWSTR lpszBuffer, LPDWORD lpdwBufferLength);
/**
 * Prompts the user for permission to connect to a URL.
 *
 * Set dwFlags to zero.
 *
 * @param lpszURL URL to connect to.
 * @param hwndParent Parent window for the prompt.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetGoOnline(LPTSTR lpszURL, HWND hwndParent, DWORD dwFlags);
/**
 * Locks the cache file associated with an Internet handle.
 *
 * Unlock it with InternetUnlockRequestFile when finished. With
 * NO_CACHE_WRITE or DONT_CACHE, a temporary file is created unless the
 * resource is HTTPS; locking HTTPS resources in that case fails.
 *
 * @param hInternet Handle from FtpOpenFile, HttpOpenRequest or InternetOpenUrl.
 * @param lphLockRequestInfo Receives the lock handle.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetLockRequestFile(HINTERNET hInternet, HANDLE *lphLockRequestInfo);
/**
 * Initializes WinInet and returns a session handle.
 * This ANSI string variant follows the CE behavior of `InternetOpenW` and uses ANSI text.
 *
 * CE supports direct, proxy and preconfigured proxy access, but only one
 * proxy and no bypass list. Only InternetReadFile and
 * InternetQueryDataAvailable can complete asynchronously. Close the
 * session with InternetCloseHandle.
 *
 * @param lpszAgent User-agent string.
 * @param dwAccessType INTERNET_OPEN_TYPE_DIRECT, _PROXY or _PRECONFIG.
 * @param lpszProxy Proxy setting, or NULL to read the registry.
 * @param lpszProxyBypass Unsupported; set to NULL.
 * @param dwFlags Internet session flags.
 * @return Internet session handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetOpenA(LPCSTR lpszAgent, DWORD dwAccessType, LPCSTR lpszProxy, LPCSTR lpszProxyBypass, DWORD dwFlags);
/**
 * Opens an FTP, HTTP or HTTPS URL for reading without InternetConnect.
 * This ANSI string variant follows the CE behavior of `InternetOpenUrlW` and uses ANSI text.
 *
 * CE supports only RAW_DATA, RELOAD and SECURE among the general flags.
 * Use InternetReadFile for data or InternetFindNextFile for directory
 * entries, then close the handle with InternetCloseHandle. Operations
 * complete synchronously on CE.
 *
 * @param hInternet Session from InternetOpenA.
 * @param lpszUrl FTP, HTTP or HTTPS URL.
 * @param lpszHeaders Optional HTTP headers.
 * @param dwHeadersLength Header length in characters, or -1 for
 *        null-terminated headers.
 * @param dwFlags Supported Internet flags.
 * @param dwContext Application callback context.
 * @return URL handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetOpenUrlA(HINTERNET hInternet, LPCSTR lpszUrl, LPCSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwFlags, DWORD dwContext);
/**
 * Opens an FTP, HTTP or HTTPS URL for reading without InternetConnect.
 *
 * CE supports only RAW_DATA, RELOAD and SECURE among the general flags.
 * Use InternetReadFile for data or InternetFindNextFile for directory
 * entries, then close the handle with InternetCloseHandle. Operations
 * complete synchronously on CE.
 *
 * @param hInternet Session from InternetOpenW.
 * @param lpszUrl FTP, HTTP or HTTPS URL.
 * @param lpszHeaders Optional HTTP headers.
 * @param dwHeadersLength Header length in characters, or -1 for
 *        null-terminated headers.
 * @param dwFlags Supported Internet flags.
 * @param dwContext Application callback context.
 * @return URL handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetOpenUrlW(HINTERNET hInternet, LPCWSTR lpszUrl, LPCWSTR lpszHeaders, DWORD dwHeadersLength, DWORD dwFlags, DWORD dwContext);
/**
 * Initializes WinInet and returns a session handle.
 *
 * CE supports direct, proxy and preconfigured proxy access, but only one
 * proxy and no bypass list. Only InternetReadFile and
 * InternetQueryDataAvailable can complete asynchronously. Close the
 * session with InternetCloseHandle.
 *
 * @param lpszAgent User-agent string.
 * @param dwAccessType INTERNET_OPEN_TYPE_DIRECT, _PROXY or _PRECONFIG.
 * @param lpszProxy Proxy setting, or NULL to read the registry.
 * @param lpszProxyBypass Unsupported; set to NULL.
 * @param dwFlags Internet session flags.
 * @return Internet session handle, or NULL on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
HINTERNET InternetOpenW(LPCWSTR lpszAgent, DWORD dwAccessType, LPCWSTR lpszProxy, LPCWSTR lpszProxyBypass, DWORD dwFlags);
/**
 * Reports bytes available for the next InternetReadFile call.
 *
 * The call waits until data is available or the file ends. For a request
 * sent with HttpSendRequestExW, call HttpEndRequestW first.
 *
 * @param hFile Internet file handle.
 * @param lpdwNumberOfBytesAvailable Receives available bytes, or NULL.
 * @param dwFlags Reserved; set to zero.
 * @param dwContext Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetQueryDataAvailable(HINTERNET hFile, LPDWORD lpdwNumberOfBytesAvailable, DWORD dwFlags, DWORD dwContext);
/**
 * Retrieves an option from an Internet handle.
 * This ANSI string variant follows the CE behavior of `InternetQueryOptionW` and uses ANSI text.
 *
 * CE supports connection, timeout, buffer-size, credential, proxy,
 * user-agent, callback, context and handle-type options.
 *
 * @param hInternet Internet handle to query.
 * @param dwOption INTERNET_OPTION_* value.
 * @param lpBuffer Receives the option data.
 * @param lpdwBufferLength Input buffer size and output length or required size.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetQueryOptionA(HINTERNET hInternet, DWORD dwOption, LPVOID lpBuffer, LPDWORD lpdwBufferLength);
/**
 * Retrieves an option from an Internet handle.
 *
 * CE supports connection, timeout, buffer-size, credential, proxy,
 * user-agent, callback, context and handle-type options.
 *
 * @param hInternet Internet handle to query.
 * @param dwOption INTERNET_OPTION_* value.
 * @param lpBuffer Receives the option data.
 * @param lpdwBufferLength Input buffer size and output length or required size.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetQueryOptionW(HINTERNET hInternet, DWORD dwOption, LPVOID lpBuffer, LPDWORD lpdwBufferLength);
/**
 * Reads data from an Internet file or request handle.
 *
 * Continue until the call succeeds with zero bytes read, which indicates
 * end of data. Read through end-of-file so cached data is committed. Close
 * the handle when finished.
 *
 * @param hFile Handle from InternetOpenUrl, FtpOpenFile or HttpOpenRequest.
 * @param lpBuffer Receives the data.
 * @param dwNumberOfBytesToRead Maximum bytes to read.
 * @param lpdwNumberOfBytesRead Receives bytes read; set to zero on entry.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetReadFile(HINTERNET hFile, LPVOID lpBuffer, DWORD dwNumberOfBytesToRead, LPDWORD lpdwNumberOfBytesRead);
/**
 * Reads data from a handle opened by InternetOpenUrl, FtpOpenFile or HttpOpenRequest.
 *
 * `IRF_ASYNC`, `IRF_SYNC` and `IRF_USE_CONTEXT` match the corresponding
 * WinInet API flags. `IRF_NO_WAIT` returns available data without waiting.
 * OEM support may vary.
 *
 * @param hFile Handle returned by InternetOpenUrl, FtpOpenFile or HttpOpenRequest.
 * @param lpBuffersOut Receives downloaded data in an INTERNET_BUFFERSA structure.
 * @param dwFlags Flags controlling the read.
 * @param dwContext Context value for asynchronous operations.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetReadFileExA(HINTERNET hFile, LPINTERNET_BUFFERSA lpBuffersOut, DWORD dwFlags, DWORD dwContext);
/**
 * Sets a cookie associated with a URL.
 * This ANSI string variant follows the CE behavior of `InternetSetCookieW` and uses ANSI text.
 *
 * Cookies without an expiration date remain in memory and are available
 * only to the process that set them. Persistent cookies are stored in the
 * cookies directory.
 *
 * @param lpszUrl URL associated with the cookie.
 * @param lpszCookieName Optional cookie name, or NULL.
 * @param lpszCookieData Cookie data.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetSetCookieA(LPCSTR lpszUrl, LPCSTR lpszCookieName, LPCSTR lpszCookieData);
/**
 * Sets a cookie associated with a URL.
 *
 * Cookies without an expiration date remain in memory and are available
 * only to the process that set them. Persistent cookies are stored in the
 * cookies directory.
 *
 * @param lpszUrl URL associated with the cookie.
 * @param lpszCookieName Optional cookie name, or NULL.
 * @param lpszCookieData Cookie data.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetSetCookieW(LPCWSTR lpszUrl, LPCWSTR lpszCookieName, LPCWSTR lpszCookieData);
/**
 * Moves the read position in a cached Internet file.
 *
 * The handle must not use NO_CACHE_WRITE or DONT_CACHE. Set pReserved and
 * dwContext to zero/NULL as required. Seeking is unreliable for unknown
 * content lengths or chunked transfers, and unavailable after end-of-file.
 *
 * @param hFile Cached HTTP or HTTPS file handle.
 * @param lDistanceToMove Signed byte offset.
 * @param pReserved Reserved; set to NULL.
 * @param dwMoveMethod FILE_BEGIN, FILE_CURRENT or FILE_END.
 * @param dwContext Context value.
 * @return New position, or -1 on failure.
 *
 * @note Windows CE 2.0 and later.
 */
DWORD InternetSetFilePointer(HINTERNET hFile, LONG lDistanceToMove, PVOID pReserved, DWORD dwMoveMethod, DWORD dwContext);
/**
 * Sets an option on an Internet handle.
 * This ANSI string variant follows the CE behavior of `InternetSetOptionW` and uses ANSI text.
 *
 * CE supports context, connection and data timeouts, buffer sizes,
 * credentials, proxy settings and user-agent options.
 *
 * @param hInternet Internet handle to update.
 * @param dwOption INTERNET_OPTION_* value.
 * @param lpBuffer Option data.
 * @param dwBufferLength Size of lpBuffer in bytes.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetSetOptionA(HINTERNET hInternet, DWORD dwOption, LPVOID lpBuffer, DWORD dwBufferLength);
/**
 * Sets an option on an Internet handle.
 *
 * CE supports context, connection and data timeouts, buffer sizes,
 * credentials, proxy settings and user-agent options.
 *
 * @param hInternet Internet handle to update.
 * @param dwOption INTERNET_OPTION_* value.
 * @param lpBuffer Option data.
 * @param dwBufferLength Size of lpBuffer in bytes.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetSetOptionW(HINTERNET hInternet, DWORD dwOption, LPVOID lpBuffer, DWORD dwBufferLength);
typedef void (*INTERNET_STATUS_CALLBACK)(HINTERNET, DWORD, DWORD, LPVOID, DWORD);
/**
 * Registers or replaces a callback for Internet-operation status.
 *
 * Callbacks are inherited by child handles. On CE, only
 * InternetReadFile and InternetQueryDataAvailable can complete
 * asynchronously; asynchronous operations require a callback.
 *
 * @param hInternet Internet handle.
 * @param lpfnInternetCallback Callback, or NULL to remove the callback.
 * @return Previous callback, NULL if none, or INTERNET_INVALID_STATUS_CALLBACK.
 *
 * @note Windows CE 2.0 and later.
 */
INTERNET_STATUS_CALLBACK InternetSetStatusCallback(HINTERNET hInternet, INTERNET_STATUS_CALLBACK lpfnInternetCallback);
/**
 * Formats a SYSTEMTIME as an HTTP date string.
 * This ANSI string variant follows the CE behavior of `InternetTimeFromSystemTimeW` and uses ANSI text.
 *
 * INTERNET_RFC1123_FORMAT is the only supported format. cbTime is a
 * character count and the output buffer should be INTERNET_RFC1123_BUFSIZE.
 *
 * @param pst Date and time to format.
 * @param dwRFC INTERNET_RFC1123_FORMAT.
 * @param lpszTime Receives the formatted string.
 * @param cbTime Buffer size in characters.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetTimeFromSystemTimeA(const SYSTEMTIME *pst, DWORD dwRFC, LPSTR lpszTime, DWORD cbTime);
/**
 * Formats a SYSTEMTIME as an HTTP date string.
 *
 * INTERNET_RFC1123_FORMAT is the only supported format. cbTime is a
 * character count and the output buffer should be INTERNET_RFC1123_BUFSIZE.
 *
 * @param pst Date and time to format.
 * @param dwRFC INTERNET_RFC1123_FORMAT.
 * @param lpszTime Receives the formatted string.
 * @param cbTime Buffer size in characters.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetTimeFromSystemTimeW(const SYSTEMTIME *pst, DWORD dwRFC, LPWSTR lpszTime, DWORD cbTime);
/**
 * Parses an HTTP date string into a SYSTEMTIME.
 * This ANSI string variant follows the CE behavior of `InternetTimeToSystemTimeW` and uses ANSI text.
 *
 * Set dwReserved to zero.
 *
 * @param lpszTime Null-terminated date/time string.
 * @param pst Receives the parsed date and time.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetTimeToSystemTimeA(LPCSTR lpszTime, SYSTEMTIME *pst, DWORD dwReserved);
/**
 * Parses an HTTP date string into a SYSTEMTIME.
 *
 * Set dwReserved to zero.
 *
 * @param lpszTime Null-terminated date/time string.
 * @param pst Receives the parsed date and time.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetTimeToSystemTimeW(LPCWSTR lpszTime, SYSTEMTIME *pst, DWORD dwReserved);
/**
 * Unlocks a cache file locked by InternetLockRequestFile.
 *
 * After unlocking, the cache manager may delete the entry.
 *
 * @param hLockRequestInfo Lock handle returned by InternetLockRequestFile.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL InternetUnlockRequestFile(HANDLE hLockRequestInfo);
/**
 * Writes data to an open FTP or HTTP request.
 *
 * Call InternetCloseHandle to end the transfer.
 *
 * @param hFile Handle from FtpOpenFile or HttpSendRequestExW.
 * @param lpBuffer Data to write.
 * @param dwNumberOfBytesToWrite Number of bytes to write.
 * @param lpdwNumberOfBytesWritten Receives bytes written; set to zero on entry.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL InternetWriteFile(HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpdwNumberOfBytesWritten);
/**
 * Retrieves and locks the file associated with a cache URL.
 * This ANSI string variant follows the CE behavior of `RetrieveUrlCacheEntryFileW` and uses ANSI text.
 *
 * Unlock the file after use. The cache manager may copy packed cache data
 * to a temporary file. This function does not parse URL anchors. Set
 * dwReserved to zero.
 *
 * @param lpszUrlName Cache entry URL without escape characters.
 * @param lpCacheEntryInfo Receives cache information.
 * @param lpdwCacheEntryInfoBufferSize Input size and output bytes copied
 *        or required.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL RetrieveUrlCacheEntryFileA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufferSize, DWORD dwReserved);
/**
 * Retrieves and locks the file associated with a cache URL.
 *
 * Unlock the file after use. The cache manager may copy packed cache data
 * to a temporary file. This function does not parse URL anchors. Set
 * dwReserved to zero.
 *
 * @param lpszUrlName Cache entry URL without escape characters.
 * @param lpCacheEntryInfo Receives cache information.
 * @param lpdwCacheEntryInfoBufferSize Input size and output bytes copied
 *        or required.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL RetrieveUrlCacheEntryFileW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, LPDWORD lpdwCacheEntryInfoBufferSize, DWORD dwReserved);
/**
 * Adds a cache entry to a group or removes it from a group.
 * This ANSI string variant follows the CE behavior of `SetUrlCacheEntryGroupW` and uses ANSI text.
 *
 * An entry can belong to multiple groups. Set reserved parameters to
 * NULL/zero.
 *
 * @param lpszUrlName Cache entry URL.
 * @param dwFlags INTERNET_CACHE_GROUP_ADD or INTERNET_CACHE_GROUP_REMOVE.
 * @param GroupId Cache group identifier.
 * @param pbGroupAttributes Reserved; set to NULL.
 * @param cbGroupAttributes Reserved; set to zero.
 * @param lpReserved Reserved; set to NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL SetUrlCacheEntryGroupA(LPCSTR lpszUrlName, DWORD dwFlags, GROUPID GroupId, LPBYTE pbGroupAttributes, DWORD cbGroupAttributes, LPVOID lpReserved);
/**
 * Adds a cache entry to a group or removes it from a group.
 *
 * An entry can belong to multiple groups. Set reserved parameters to
 * NULL/zero.
 *
 * @param lpszUrlName Cache entry URL.
 * @param dwFlags INTERNET_CACHE_GROUP_ADD or INTERNET_CACHE_GROUP_REMOVE.
 * @param GroupId Cache group identifier.
 * @param pbGroupAttributes Reserved; set to NULL.
 * @param cbGroupAttributes Reserved; set to zero.
 * @param lpReserved Reserved; set to NULL.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL SetUrlCacheEntryGroupW(LPCWSTR lpszUrlName, DWORD dwFlags, GROUPID GroupId, LPBYTE pbGroupAttributes, DWORD cbGroupAttributes, LPVOID lpReserved);
/**
 * Updates selected fields of a cache entry.
 * This ANSI string variant follows the CE behavior of `SetUrlCacheEntryInfoW` and uses ANSI text.
 *
 * dwFieldControl selects fields such as access time, attributes,
 * expiration, modification time, hit rate or sync time. Header information
 * is not implemented.
 *
 * @param lpszUrlName Cache entry URL.
 * @param lpCacheEntryInfo New cache-entry values.
 * @param dwFieldControl CACHE_ENTRY_*_FC fields to update.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL SetUrlCacheEntryInfoA(LPCSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, DWORD dwFieldControl);
/**
 * Updates selected fields of a cache entry.
 *
 * dwFieldControl selects fields such as access time, attributes,
 * expiration, modification time, hit rate or sync time. Header information
 * is not implemented.
 *
 * @param lpszUrlName Cache entry URL.
 * @param lpCacheEntryInfo New cache-entry values.
 * @param dwFieldControl CACHE_ENTRY_*_FC fields to update.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL SetUrlCacheEntryInfoW(LPCWSTR lpszUrlName, LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo, DWORD dwFieldControl);
/**
 * Unlocks a cache entry file retrieved by RetrieveUrlCacheEntryFileA.
 * This ANSI string variant follows the CE behavior of `UnlockUrlCacheEntryFileW` and uses ANSI text.
 *
 * Do not access the file after unlocking. The cache manager may delete it.
 * Set dwReserved to zero.
 *
 * @param lpszUrlName Cache entry URL without escape characters.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL UnlockUrlCacheEntryFileA(LPCSTR lpszUrlName, DWORD dwReserved);
/**
 * Unlocks a cache entry file retrieved by RetrieveUrlCacheEntryFileW.
 *
 * Do not access the file after unlocking. The cache manager may delete it.
 * Set dwReserved to zero.
 *
 * @param lpszUrlName Cache entry URL without escape characters.
 * @param dwReserved Reserved; set to zero.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 and later.
 */
BOOL UnlockUrlCacheEntryFileW(LPCWSTR lpszUrlName, DWORD dwReserved);
typedef struct {
    LPCTSTR ShortAbstract;
    LPCTSTR AbstractFile;
} GOPHER_ABSTRACT_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Comment;
    LPCTSTR EmailAddress;
} GOPHER_ADMIN_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR QuestionType;
    LPCTSTR QuestionText;
} GOPHER_ASK_ATTRIBUTE_TYPE;

typedef struct {
    FILETIME DateAndTime;
} GOPHER_MOD_DATE_ATTRIBUTE_TYPE;

typedef struct {
    DWORD Ttl;
} GOPHER_TTL_ATTRIBUTE_TYPE;

typedef struct {
    INT Score;
} GOPHER_SCORE_ATTRIBUTE_TYPE;

typedef struct {
    INT LowerBound;
    INT UpperBound;
} GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Site;
} GOPHER_SITE_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Organization;
} GOPHER_ORGANIZATION_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Location;
} GOPHER_LOCATION_ATTRIBUTE_TYPE;

typedef struct {
    INT DegreesNorth;
    INT MinutesNorth;
    INT SecondsNorth;
    INT DegreesEast;
    INT MinutesEast;
    INT SecondsEast;
} GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE;

typedef struct {
    INT Zone;
} GOPHER_TIMEZONE_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Provider;
} GOPHER_PROVIDER_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Version;
} GOPHER_VERSION_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR ContentType;
    LPCTSTR Language;
    DWORD Size;
} GOPHER_VIEW_ATTRIBUTE_TYPE;

typedef struct {
    BOOL TreeWalk;
} GOPHER_VERONICA_ATTRIBUTE_TYPE;

typedef struct {
    LPCTSTR Text;
} GOPHER_UNKNOWN_ATTRIBUTE_TYPE;

typedef struct {
    DWORD CategoryId;
    DWORD AttributeId;
    union {
        GOPHER_ADMIN_ATTRIBUTE_TYPE Admin;
        GOPHER_MOD_DATE_ATTRIBUTE_TYPE ModDate;
        GOPHER_TTL_ATTRIBUTE_TYPE Ttl;
        GOPHER_SCORE_ATTRIBUTE_TYPE Score;
        GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE ScoreRange;
        GOPHER_SITE_ATTRIBUTE_TYPE Site;
        GOPHER_ORGANIZATION_ATTRIBUTE_TYPE Organization;
        GOPHER_LOCATION_ATTRIBUTE_TYPE Location;
        GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE GeographicalLocation;
        GOPHER_TIMEZONE_ATTRIBUTE_TYPE TimeZone;
        GOPHER_PROVIDER_ATTRIBUTE_TYPE Provider;
        GOPHER_VERSION_ATTRIBUTE_TYPE Version;
        GOPHER_ABSTRACT_ATTRIBUTE_TYPE Abstract;
        GOPHER_VIEW_ATTRIBUTE_TYPE View;
        GOPHER_VERONICA_ATTRIBUTE_TYPE Veronica;
        GOPHER_ASK_ATTRIBUTE_TYPE Ask;
        GOPHER_UNKNOWN_ATTRIBUTE_TYPE Unknown;
    } AttributeType;
} GOPHER_ATTRIBUTE_TYPE;

typedef GOPHER_ATTRIBUTE_TYPE *LPGOPHER_ATTRIBUTE_TYPE;
typedef BOOL (*GOPHER_ATTRIBUTE_ENUMERATOR)(LPGOPHER_ATTRIBUTE_TYPE, DWORD);
typedef struct {
    WCHAR DisplayString[129];
    DWORD GopherType;
    DWORD SizeLow;
    DWORD SizeHigh;
    FILETIME LastModificationTime;
    WCHAR Locator[654];
} GOPHER_FIND_DATAW;

typedef GOPHER_FIND_DATAW GOPHER_FIND_DATA;
typedef struct {
    CHAR DisplayString[129];
    DWORD GopherType;
    DWORD SizeLow;
    DWORD SizeHigh;
    FILETIME LastModificationTime;
    CHAR Locator[654];
} GOPHER_FIND_DATAA;

typedef struct {
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
} HTTP_VERSION_INFO;

typedef struct {
    DWORD dwResult;
    DWORD dwError;
} INTERNET_ASYNC_RESULT;

typedef DWORD (*PFN_AUTH_NOTIFY)(DWORD, DWORD, LPVOID);
typedef struct {
    DWORD cbStruct;
    DWORD dwOptions;
    PFN_AUTH_NOTIFY pfnNotify;
    DWORD dwContext;
} INTERNET_AUTH_NOTIFY_DATA;

typedef struct _INTERNET_BUFFERSW INTERNET_BUFFERSW;
typedef INTERNET_BUFFERSW INTERNET_BUFFERS;
typedef struct _INTERNET_BUFFERSA INTERNET_BUFFERSA;
typedef struct _INTERNET_CACHE_ENTRY_INFOW INTERNET_CACHE_ENTRY_INFOW;
typedef INTERNET_CACHE_ENTRY_INFOW INTERNET_CACHE_ENTRY_INFO;
typedef struct _INTERNET_CACHE_ENTRY_INFOA INTERNET_CACHE_ENTRY_INFOA;
typedef struct {
    FILETIME ftExpiry;
    FILETIME ftStart;
    LPTSTR lpszSubjectInfo;
    LPTSTR lpszIssuerInfo;
    LPTSTR lpszProtocolName;
    LPTSTR lpszSignatureAlgName;
    LPTSTR lpszEncryptionAlgName;
    DWORD dwKeySize;
} INTERNET_CERTIFICATE_INFO;

typedef struct {
    DWORD dwConnectedState;
    DWORD dwFlags;
} INTERNET_CONNECTED_INFO;

typedef struct {
    DWORD dwAccessType;
    LPCWSTR lpszProxy;
    LPCWSTR lpszProxyBypass;
} INTERNET_PROXY_INFOW;

typedef INTERNET_PROXY_INFOW INTERNET_PROXY_INFO;
typedef struct {
    DWORD dwAccessType;
    LPCSTR lpszProxy;
    LPCSTR lpszProxyBypass;
} INTERNET_PROXY_INFOA;

typedef struct {
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
} INTERNET_VERSION_INFO;

typedef GOPHER_ABSTRACT_ATTRIBUTE_TYPE *LPGOPHER_ABSTRACT_ATTRIBUTE_TYPE;
typedef GOPHER_ADMIN_ATTRIBUTE_TYPE *LPGOPHER_ADMIN_ATTRIBUTE_TYPE;
typedef GOPHER_ASK_ATTRIBUTE_TYPE *LPGOPHER_ASK_ATTRIBUTE_TYPE;
typedef GOPHER_FIND_DATAW *LPGOPHER_FIND_DATAW;
typedef LPGOPHER_FIND_DATAW LPGOPHER_FIND_DATA;
typedef GOPHER_FIND_DATAA *LPGOPHER_FIND_DATAA;
typedef GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE *LPGOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE;
typedef GOPHER_LOCATION_ATTRIBUTE_TYPE *LPGOPHER_LOCATION_ATTRIBUTE_TYPE;
typedef GOPHER_MOD_DATE_ATTRIBUTE_TYPE *LPGOPHER_MOD_DATE_ATTRIBUTE_TYPE;
typedef GOPHER_ORGANIZATION_ATTRIBUTE_TYPE *LPGOPHER_ORGANIZATION_ATTRIBUTE_TYPE;
typedef GOPHER_PROVIDER_ATTRIBUTE_TYPE *LPGOPHER_PROVIDER_ATTRIBUTE_TYPE;
typedef GOPHER_SCORE_ATTRIBUTE_TYPE *LPGOPHER_SCORE_ATTRIBUTE_TYPE;
typedef GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE *LPGOPHER_SCORE_RANGE_ATTRIBUTE_TYPE;
typedef GOPHER_SITE_ATTRIBUTE_TYPE *LPGOPHER_SITE_ATTRIBUTE_TYPE;
typedef GOPHER_TIMEZONE_ATTRIBUTE_TYPE *LPGOPHER_TIMEZONE_ATTRIBUTE_TYPE;
typedef GOPHER_TTL_ATTRIBUTE_TYPE *LPGOPHER_TTL_ATTRIBUTE_TYPE;
typedef GOPHER_UNKNOWN_ATTRIBUTE_TYPE *LPGOPHER_UNKNOWN_ATTRIBUTE_TYPE;
typedef GOPHER_VERONICA_ATTRIBUTE_TYPE *LPGOPHER_VERONICA_ATTRIBUTE_TYPE;
typedef GOPHER_VERSION_ATTRIBUTE_TYPE *LPGOPHER_VERSION_ATTRIBUTE_TYPE;
typedef GOPHER_VIEW_ATTRIBUTE_TYPE *LPGOPHER_VIEW_ATTRIBUTE_TYPE;
typedef HINTERNET *LPHINTERNET;
typedef HTTP_VERSION_INFO *LPHTTP_VERSION_INFO;
typedef INTERNET_ASYNC_RESULT *LPINTERNET_ASYNC_RESULT;
typedef LPINTERNET_BUFFERSW LPINTERNET_BUFFERS;
typedef LPINTERNET_CACHE_ENTRY_INFOW LPINTERNET_CACHE_ENTRY_INFO;
typedef INTERNET_CERTIFICATE_INFO *LPINTERNET_CERTIFICATE_INFO;
typedef INTERNET_CONNECTED_INFO *LPINTERNET_CONNECTED_INFO;
typedef INTERNET_PORT *LPINTERNET_PORT;
typedef INTERNET_PROXY_INFOW *LPINTERNET_PROXY_INFOW;
typedef LPINTERNET_PROXY_INFOW LPINTERNET_PROXY_INFO;
typedef INTERNET_PROXY_INFOA *LPINTERNET_PROXY_INFOA;
typedef INTERNET_SCHEME *LPINTERNET_SCHEME;
typedef INTERNET_STATUS_CALLBACK *LPINTERNET_STATUS_CALLBACK;
typedef INTERNET_VERSION_INFO *LPINTERNET_VERSION_INFO;
typedef LPURL_COMPONENTSW LPURL_COMPONENTS;
typedef DWORD (*PFN_DIAL_HANDLER)(HWND, LPCSTR, DWORD, LPDWORD);
typedef URL_COMPONENTSW URL_COMPONENTS;
struct _INTERNET_BUFFERSA {
    DWORD dwStructSize;
    struct _INTERNET_BUFFERSA *Next;
    LPCSTR lpcszHeader;
    DWORD dwHeadersLength;
    DWORD dwHeadersTotal;
    LPVOID lpvBuffer;
    DWORD dwBufferLength;
    DWORD dwBufferTotal;
    DWORD dwOffsetLow;
    DWORD dwOffsetHigh;
} __attribute__((packed, aligned(4)));

struct _INTERNET_BUFFERSW {
    DWORD dwStructSize;
    struct _INTERNET_BUFFERSW *Next;
    LPCWSTR lpcszHeader;
    DWORD dwHeadersLength;
    DWORD dwHeadersTotal;
    LPVOID lpvBuffer;
    DWORD dwBufferLength;
    DWORD dwBufferTotal;
    DWORD dwOffsetLow;
    DWORD dwOffsetHigh;
} __attribute__((packed, aligned(4)));

struct _INTERNET_CACHE_ENTRY_INFOA {
    DWORD dwStructSize;
    LPSTR lpszSourceUrlName;
    LPSTR lpszLocalFileName;
    DWORD CacheEntryType;
    DWORD dwUseCount;
    DWORD dwHitRate;
    DWORD dwSizeLow;
    DWORD dwSizeHigh;
    FILETIME LastModifiedTime;
    FILETIME ExpireTime;
    FILETIME LastAccessTime;
    FILETIME LastSyncTime;
    LPBYTE lpHeaderInfo;
    DWORD dwHeaderInfoSize;
    LPSTR lpszFileExtension;
    union {
        DWORD dwReserved;
        DWORD dwExemptDelta;
    };
} __attribute__((packed, aligned(4)));

struct _INTERNET_CACHE_ENTRY_INFOW {
    DWORD dwStructSize;
    LPWSTR lpszSourceUrlName;
    LPWSTR lpszLocalFileName;
    DWORD CacheEntryType;
    DWORD dwUseCount;
    DWORD dwHitRate;
    DWORD dwSizeLow;
    DWORD dwSizeHigh;
    FILETIME LastModifiedTime;
    FILETIME ExpireTime;
    FILETIME LastAccessTime;
    FILETIME LastSyncTime;
    LPBYTE lpHeaderInfo;
    DWORD dwHeaderInfoSize;
    LPWSTR lpszFileExtension;
    union {
        DWORD dwReserved;
        DWORD dwExemptDelta;
    };
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

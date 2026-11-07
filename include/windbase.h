#include <windows.h>

#ifndef GRIMACE_WINDBASE_H
#define GRIMACE_WINDBASE_H

#ifndef RC_INVOKED

typedef DWORD CEOID;
typedef CEOID *PCEOID;
typedef DWORD CEPROPID;
typedef CEPROPID *PCEPROPID;

/**
 * This structure contains information about a file object.
 */
typedef struct _CEFILEINFO {
    /**
     * Specifies the attributes of the file.
     */
    DWORD dwAttributes;
    /**
     * Object identifier of the parent directory.
     */
    CEOID oidParent;
    /**
     * Null-terminated string that contains the name and
     * path of the file.
     */
    WCHAR szFileName[MAX_PATH];
    /**
     * Time stamp that indicates when the contents of the
     * file were last changed.
     */
    FILETIME ftLastChanged;
    /**
     * Specifies the length, in bytes, of the file.
     */
    DWORD dwLength;
} CEFILEINFO;

/**
 * This structure contains information about a directory object.
 */
typedef struct _CEDIRINFO {
    /**
     * Specifies the attributes of the directory.
     */
    DWORD dwAttributes;
    /**
     * Object identifier of the parent directory.
     */
    CEOID oidParent;
    /**
     * Null-terminated string that contains the name and path
     * of the directory.
     */
    WCHAR szDirName[MAX_PATH];
} CEDIRINFO;

/**
 * This structure contains information about a record object.
 */
typedef struct _CERECORDINFO {
    /**
     * Object identifier of the parent database.
     */
    CEOID oidParent;
} CERECORDINFO;

/**
 * This structure contains information about a sort order in a database.
 *
 * The system supports only simple sorts on a primary key. Records with the
 * same key value are be sorted in arbitrary order.
 */
typedef struct _SORTORDERSPEC {
    /**
     * Identifier of the property to be sorted on. Sorts on
     * binary properties are not allowed.
     */
    CEPROPID propid;
    /**
     * Specifies the sort flags. It is one or a combination of
     * the following flags: CEDB_SORT_DESCENDING: The sort is done in
     * descending order. By default, the sort is done in ascending
     * order. CEDB_SORT_CASEINSENSITIVE: The sort operation is case
     * insensitive. This value is valid only for strings.
     * CEDB_SORT_UNKNOWNFIRST: Records that do not contain this property
     * are placed before all the other records. By default, such records
     * are placed after all other records. CEDB_SORT_GENERICORDER: The
     * default sort order-ascending order, case sensitive-is used.
     * Records that do not contain the sort property are placed at the
     * end of the list.
     */
    DWORD dwFlags;
} SORTORDERSPEC;

#define CEDB_MAXDBASENAMELEN 32
#define CEDB_MAXSORTORDER 4

/**
 * This structure contains information about a database object. This
 * structure is used by the CeSetDatabaseInfo and CeCreateDatabaseEx
 * functions.
 *
 * For Windows CE versions 2.10 and later, dwFlags has additional meaning,
 * but is still compatible with previous versions. The high-order word of
 * dwFlags specifies additional database properties.
 */
typedef struct _CEDBASEINFO {
    /**
     * The low-order word specifies the valid members of this
     * structure. This member is one or a combination of the following
     * flags: Value Description CEDB_VALIDMODTIME The ftLastModified
     * member is valid and should be used. CEDB_VALIDNAME The
     * szDbaseName member is valid and should be used. CEDB_VALIDTYPE
     * The dwDbaseType member is valid and should be used.
     * CEDB_VALIDSORTSPEC The rgSortSpecs member is valid and should be
     * used. CEDB_VALIDDBFLAGS The low-order word of the dwFlags member
     * is valid and should be used. The high-order word specifies the
     * associated database properties. This member is the following
     * flag: Value Description CEDB_NOCOMPRESS The database is not
     * compressed. If this flag is used with CeSetDatabaseInfoEx, a
     * compressed database is uncompressed. If this flag is used with
     * CeCreateDatabaseEx, the database is not compressed. To compress a
     * database, CeSetDatabaseInfoEx or CeCreateDatabaseEx is called
     * with CEDB_VALIDDBFLAGS set and the CEDB_NOCOMPRESS bit cleared.
     * By default, all databases are compressed. If you are going to
     * change the compression, it should be done at creation time.
     */
    DWORD dwFlags;
    /**
     * Null-terminated string that contains the name of the
     * database. The string can have up to 32 characters, including the
     * terminating null character. This member must be set when used for
     * CeCreateDatabaseEx.
     */
    WCHAR szDbaseName[CEDB_MAXDBASENAMELEN];
    /**
     * Specifies the type identifier for the database.
     */
    DWORD dwDbaseType;
    /**
     * Returns the number of records in the database.
     */
    WORD wNumRecords;
    /**
     * Number of sort orders active in the database. Up
     * to four sort orders can be active at a time.
     */
    WORD wNumSortOrder;
    /**
     * Specifies, in bytes, the size of the database.
     */
    DWORD dwSize;
    /**
     * Returns the last time this database was modified.
     */
    FILETIME ftLastModified;
    /**
     * Array containing the sort order descriptions. Only
     * the first n array members are valid, where n is the value
     * specified by the wNumSortOrder member. If no sort orders are
     * specified for CeCreateDatabaseEx or when CEDB_VALIDSORTSPEC is
     * not specified, then a default sort order is assigned to the
     * database.
     */
    SORTORDERSPEC rgSortSpecs[CEDB_MAXSORTORDER];
} CEDBASEINFO;

/**
 * This structure contains information about a Binary Large Object (BLOB)s
 * of data in the object store.
 */
typedef struct _CEBLOB {
    /**
     * Specifies the size, in bytes, of the BLOB.
     */
    DWORD dwCount;
    /**
     * Pointer to the beginning of the BLOB.
     */
    LPBYTE lpb;
} CEBLOB;

/**
 * This union contains a value for a property.
 */
typedef union _CEVALUNION {
    /**
     * Specifies an integer.
     */
    short iVal;
    /**
     * Specifies an unsigned integer.
     */
    USHORT uiVal;
    /**
     * Specifies a long integer.
     */
    long lVal;
    /**
     * Specifies an unsigned long integer.
     */
    ULONG ulVal;
    /**
     * Specifies a FILETIME structure.
     */
    FILETIME filetime;
    /**
     * Pointer to a null-terminated string.
     */
    LPWSTR lpwstr;
    /**
     * Specifies a CEBLOB structure.
     */
    CEBLOB blob;
} CEVALUNION;

/**
 * This structure contains a property value.
 */
typedef struct _CEPROPVAL {
    /**
     * Identifier of the property value. The high-order word is
     * an application-defined identifier, and the low-order word is a
     * predefined constant value that indicates the data type of the
     * value specified by the val member. The low-order word can be one
     * of the following values: Value Description CEVT_BLOB A CEBLOB
     * structure. CEVT_BOOL A Boolean value. CEVT_FILETIME A FILETIME
     * structure. CEVT_I2 A 16-bit signed integer. CEVT_I4 A 32-bit
     * signed integer. CEVT_LPWSTR A null-terminated string. CEVT_R8 A
     * 64-bit signed interger. CEVT_UI2 A 16-bit unsigned integer.
     * CEVT_UI4 A 32-bit unsigned integer.
     */
    CEPROPID propid;
    /**
     * Not used.
     */
    WORD wLenData;
    /**
     * Special flags for the property. It is one of the
     * following values: Value Description CEDB_PROPNOTFOUND Set by the
     * CeReadRecordProps function if the property was not found.
     * CEDB_PROPDELETE If passed to the CeWriteRecordProps function,
     * this flag causes the property to be deleted.
     */
    WORD wFlags;
    /**
     * Actual value for simple types, or a pointer for strings or
     * Binary Large Objects (BLOBs).
     */
    CEVALUNION val;
} CEPROPVAL;
typedef CEPROPVAL *PCEPROPVAL;

/**
 * This structure contains information about an object in the object store
 * or database volume.
 */
typedef struct _CEOIDINFO {
    /**
     * Specifies the type of the object. It is one of the
     * following values: Value Description OBJTYPE_INVALID The object
     * store contains no valid object that has this object identifier.
     * OBJTYPE_FILE The object is a file. OBJTYPE_DIRECTORY The object
     * is a directory. OBJTYPE_DATABASE The object is a database.
     * OBJTYPE_RECORD The object is a record inside a database.
     */
    WORD wObjType;
    /**
     * Aligns the structure on a double-word boundary.
     */
    WORD wPad;
    union {
        /**
         * CEFILEINFO structure that contains information about a
         * file. This member is valid only if wObjType is OBJTYPE_FILE.
         */
        CEFILEINFO infFile;
        /**
         * CEDIRINFO structure that contains information about
         * a directory. This member is valid only if wObjType is
         * OBJTYPE_DIRECTORY.
         */
        CEDIRINFO infDirectory;
        /**
         * CEDBASEINFO structure that contains information
         * about a database. This member is valid only if wObjType is
         * OBJTYPE_DATABASE.
         */
        CEDBASEINFO infDatabase;
        /**
         * CERECORDINFO structure that contains information about
         * a record in a database. This member is valid only if wObjType is
         * OBJTYPE_RECORD.
         */
        CERECORDINFO infRecord;
    };
} CEOIDINFO;

typedef CEOID PEGOID;
typedef PCEOID PPEGOID;
typedef CEPROPID PEGPROPID;
typedef PCEPROPID PPEGPROPID;
typedef CEFILEINFO PEGFILEINFO;
typedef CEDIRINFO PEGDIRINFO;
typedef CERECORDINFO PEGRECORDINFO;
typedef CEDBASEINFO PEGDBASEINFO;
typedef CEBLOB PEGBLOB;
typedef CEVALUNION PEGVALUNION;
typedef CEPROPVAL PEGPROPVAL;
typedef PCEPROPVAL PPEGPROPVAL;
typedef CEOIDINFO PEGOIDINFO;

#endif

/**
 * This macro retrieves the type identifier from a property identifier.
 *
 * The TypeFromPropID macro is defined as follows:
 *
 *     #define TypeFromPropID(propid) LOWORD(propid)
 *
 * @param propid Property identifier from which to retrieve the type
 *        identifier.
 */
#define TypeFromPropID(propid) LOWORD(propid)

/**
 * This message is sent when a new object is created in the object store.
 *
 * When writing applications for Windows CE version 1.0, use the
 * DB_PEGOID_CREATED message.
 *
 * @param oidCreated Identifier of the newly created object.
 * @param oidParent Identifier of the parent object of the newly created
 *        object.
 */
#define DB_CEOID_CREATED (WM_USER + 0x1)
#define DB_CEOID_DATABASE_DELETED (WM_USER + 0x2)
/**
 * This message is sent when a record has been deleted from the object
 * store.
 *
 * @param oidDeletedRec Identifier of the record that was deleted.
 * @param oidParent Identifier of the parent object of the deleted record.
 */
#define DB_CEOID_RECORD_DELETED (WM_USER + 0x3)
#define DB_CEOID_FILE_DELETED (WM_USER + 0x4)
#define DB_CEOID_DIRECTORY_DELETED (WM_USER + 0x5)
/**
 * This message is sent when an object in the object store has been
 * modified.
 *
 * When writing applications for Windows CE version 1.0, use the
 * DB_PEGOID_CHANGED message.
 *
 * @param oidChanged Identifier of the object that was modified.
 * @param oidParent Identifier of the parent object of the modified object.
 */
#define DB_CEOID_CHANGED (WM_USER + 0x6)
/**
 * This message is sent when a new object is created in the object store.
 * See DB_CEOID_CREATED.
 *
 * @param oidCreated Identifier of the newly created object.
 * @param oidParent Identifier of the parent object of the newly created
 *        object.
 */
#define DB_PEGOID_CREATED DB_CEOID_CREATED
/**
 * This message is sent when a record has been deleted from the object
 * store.
 *
 * @param oidDeletedRec Identifier of the record that was deleted.
 * @param oidParent Identifier of the parent object of the deleted record.
 */
#define DB_PEGOID_RECORD_DELETED DB_CEOID_RECORD_DELETED
/**
 * This message is sent when an object in the object store has been
 * modified. See DB_CEOID_CHANGED.
 *
 * @param oidChanged Identifier of the object that was modified.
 * @param oidParent Identifier of the parent object of the modified object.
 */
#define DB_PEGOID_CHANGED DB_CEOID_CHANGED

#define REPL_CHANGE_WILLCLEAR 0x00000001

#define CEDB_SORT_DESCENDING 0x00000001
#define CEDB_SORT_CASEINSENSITIVE 0x00000002
#define CEDB_SORT_UNKNOWNFIRST 0x00000004
#define CEDB_SORT_GENERICORDER 0x00000008
#define CEDB_VALIDNAME 0x0001
#define CEDB_VALIDTYPE 0x0002
#define CEDB_VALIDSORTSPEC 0x0004
#define CEDB_VALIDMODTIME 0x0008
#define CEDB_AUTOINCREMENT 0x00000001
#define CEDB_SEEK_CEOID 0x00000001
#define CEDB_SEEK_BEGINNING 0x00000002
#define CEDB_SEEK_END 0x00000004
#define CEDB_SEEK_CURRENT 0x00000008
#define CEDB_SEEK_VALUESMALLER 0x00000010
#define CEDB_SEEK_VALUEFIRSTEQUAL 0x00000020
#define CEDB_SEEK_VALUEGREATER 0x00000040
#define CEDB_SEEK_VALUENEXTEQUAL 0x00000080
#define CEDB_PROPNOTFOUND 0x0100
#define CEDB_PROPDELETE 0x0200
#define CEDB_MAXDATABLOCKSIZE 4092
#if GRIMACE_CE >= 2
#define CEDB_MAXPROPDATASIZE ((CEDB_MAXDATABLOCKSIZE * 16) - 1)
#else
#define CEDB_MAXPROPDATASIZE (CEDB_MAXDATABLOCKSIZE * 16)
#endif
#define CEDB_MAXRECORDSIZE (128 * 1024)
#define CEDB_ALLOWREALLOC 0x00000001

#define CEVT_I2 2
#define CEVT_UI2 18
#define CEVT_I4 3
#define CEVT_UI4 19
#define CEVT_FILETIME 64
#define CEVT_LPWSTR 31
#define CEVT_BLOB 65

#define OBJTYPE_INVALID 0
#define OBJTYPE_FILE 1
#define OBJTYPE_DIRECTORY 2
#define OBJTYPE_DATABASE 3
#define OBJTYPE_RECORD 4

#define PEGDB_SORT_DESCENDING CEDB_SORT_DESCENDING
#define PEGDB_SORT_CASEINSENSITIVE CEDB_SORT_CASEINSENSITIVE
#define PEGDB_SORT_UNKNOWNFIRST CEDB_SORT_UNKNOWNFIRST
#define PEGDB_SORT_GENERICORDER CEDB_SORT_GENERICORDER
#define PEGDB_MAXDBASENAMELEN CEDB_MAXDBASENAMELEN
#define PEGDB_MAXSORTORDER CEDB_MAXSORTORDER
#define PEGDB_VALIDNAME CEDB_VALIDNAME
#define PEGDB_VALIDTYPE CEDB_VALIDTYPE
#define PEGDB_VALIDSORTSPEC CEDB_VALIDSORTSPEC
#define PEGDB_VALIDMODTIME CEDB_VALIDMODTIME
#define PEGDB_AUTOINCREMENT CEDB_AUTOINCREMENT
#define PEGDB_SEEK_PEGOID CEDB_SEEK_CEOID
#define PEGDB_SEEK_BEGINNING CEDB_SEEK_BEGINNING
#define PEGDB_SEEK_END CEDB_SEEK_END
#define PEGDB_SEEK_CURRENT CEDB_SEEK_CURRENT
#define PEGDB_SEEK_VALUESMALLER CEDB_SEEK_VALUESMALLER
#define PEGDB_SEEK_VALUEFIRSTEQUAL CEDB_SEEK_VALUEFIRSTEQUAL
#define PEGDB_SEEK_VALUEGREATER CEDB_SEEK_VALUEGREATER
#define PEGDB_SEEK_VALUENEXTEQUAL CEDB_SEEK_VALUENEXTEQUAL
#define PEGDB_PROPNOTFOUND CEDB_PROPNOTFOUND
#define PEGDB_PROPDELETE CEDB_PROPDELETE
#define PEGDB_MAXDATABLOCKSIZE CEDB_MAXDATABLOCKSIZE
#define PEGDB_MAXPROPDATASIZE CEDB_MAXPROPDATASIZE
#define PEGDB_MAXRECORDSIZE CEDB_MAXRECORDSIZE
#define PEGDB_ALLOWREALLOC CEDB_ALLOWREALLOC
#define PEGVT_I2 CEVT_I2
#define PEGVT_UI2 CEVT_UI2
#define PEGVT_I4 CEVT_I4
#define PEGVT_UI4 CEVT_UI4
#define PEGVT_FILETIME CEVT_FILETIME
#define PEGVT_LPWSTR CEVT_LPWSTR
#define PEGVT_BLOB CEVT_BLOB

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

#if GRIMACE_CE >= 2

/**
 * Starts an enumeration of the databases in the object store.
 *
 * Step through it with CeFindNextDatabase and close the handle with
 * CloseHandle. This is the later name for PegFindFirstDatabase.
 *
 * @param dwClassID Type of database to enumerate, or 0 for all.
 * @return Enumeration handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError).
 */
HANDLE CeFindFirstDatabase(DWORD dwClassID);
/**
 * Returns the next database in an enumeration.
 *
 * This is the later name for PegFindNextDatabase.
 *
 * @param hEnum Handle from CeFindFirstDatabase.
 * @return The database's object identifier, or 0 when there are no more
 *         (ERROR_NO_MORE_ITEMS) or on failure (see GetLastError).
 */
CEOID CeFindNextDatabase(HANDLE hEnum);
/**
 * Creates a database in the object store.
 *
 * Returns an object identifier, not an open handle: open it with
 * CeOpenDatabase. Each sort order adds cost to every insert and delete,
 * but adding one later with CeSetDatabaseInfo is more expensive still.
 * This is the later name for PegCreateDatabase.
 *
 * @param lpszName Database name, up to 32 characters including the null.
 *        Longer names are truncated.
 * @param dwClassID Application-defined type, used to filter enumeration
 *        with CeFindFirstDatabase. Need not be unique.
 * @param wNumSortOrder Number of sort orders, 0 to 4.
 * @param rgSortSpecs Array of wNumSortOrder SORTORDERSPEC, or NULL if
 *        wNumSortOrder is 0.
 * @return The new database's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_DISK_FULL, ERROR_INVALID_PARAMETER or
 *         ERROR_DUP_NAME).
 */
CEOID CeCreateDatabase(LPWSTR lpszName, DWORD dwClassID, WORD wNumSortOrder, SORTORDERSPEC *rgSortSpecs);
/**
 * Changes a database's name, type or sort orders.
 *
 * Changing sort orders can take minutes on a large database, so warn the
 * user first. This is the later name for PegSetDatabaseInfo.
 *
 * @param oidDbase Object identifier of the database.
 * @param pNewInfo New settings. dwFlags (CEDB_VALID*) selects which
 *        members apply; wNumRecords is ignored.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_DISK_FULL, or ERROR_SHARING_VIOLATION when removing a sort
 *         order an open handle is using).
 */
BOOL CeSetDatabaseInfo(CEOID oidDbase, CEDBASEINFO *pNewInfo);
/**
 * Opens a database by object identifier or name.
 *
 * Close the handle with CloseHandle. There are no transactions: every
 * change is committed as it is made. This is the later name for
 * PegOpenDatabase.
 *
 * @param poid Object identifier of the database, or a pointer to 0 to
 *        open by name and receive the identifier.
 * @param lpszName Database name. Ignored if *poid is nonzero.
 * @param propid Property identifier of the sort order to traverse in, used
 *        by CeSeekDatabase and CeReadRecordProps, or 0 for none.
 * @param dwFlags CEDB_AUTOINCREMENT to advance the seek pointer after each
 *        CeReadRecordProps, or 0.
 * @param hwndNotify Window to receive DB_CEOID_* messages when another
 *        thread changes the database, or NULL.
 * @return Database handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError: ERROR_FILE_NOT_FOUND if no database has the name).
 */
HANDLE CeOpenDatabase(PCEOID poid, LPWSTR lpszName, CEPROPID propid, DWORD dwFlags, HWND hwndNotify);
/**
 * Deletes a database and all its records.
 *
 * This is the later name for PegDeleteDatabase.
 *
 * @param oid Object identifier of the database.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_SHARING_VIOLATION if another thread has it open).
 */
BOOL CeDeleteDatabase(CEOID oid);
/**
 * Moves the seek pointer of an open database.
 *
 * Seeks use the sort order chosen in CeOpenDatabase, and value seeks work
 * only on a sorted property. A failed value seek leaves the pointer at the
 * end of the database. This is the later name for PegSeekDatabase.
 *
 * @param hDatabase Handle from CeOpenDatabase.
 * @param dwSeekType CEDB_SEEK_CEOID (fast), CEDB_SEEK_VALUESMALLER,
 *        CEDB_SEEK_VALUEFIRSTEQUAL, CEDB_SEEK_VALUENEXTEQUAL (one step
 *        forward, to walk equal values), CEDB_SEEK_VALUEGREATER (greater
 *        or equal), CEDB_SEEK_BEGINNING, CEDB_SEEK_CURRENT or
 *        CEDB_SEEK_END. Value seeks other than NEXTEQUAL, backward seeks
 *        and seeks from the end are O(n).
 * @param dwValue An object identifier for CEDB_SEEK_CEOID, a pointer to a
 *        CEPROPVAL for value seeks, or a record count for the others. For
 *        CEDB_SEEK_CURRENT, cast a negative count to seek backwards.
 * @param lpdwIndex Receives the found record's index from the start.
 * @return The object identifier of the record found, or 0 on failure.
 */
CEOID CeSeekDatabase(HANDLE hDatabase, DWORD dwSeekType, DWORD dwValue, LPDWORD lpdwIndex);
/**
 * Deletes a record from an open database.
 *
 * If the deleted record was the current one, the next read fails unless
 * the database was opened with CEDB_AUTOINCREMENT, in which case the seek
 * pointer moves on to the next record. This is the later name for
 * PegDeleteRecord.
 *
 * @param hDatabase Handle from CeOpenDatabase.
 * @param oidRecord Object identifier of the record.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
BOOL CeDeleteRecord(HANDLE hDatabase, CEOID oidRecord);
/**
 * Reads properties from the current record.
 *
 * The buffer receives an array of CEPROPVAL, with string and blob data
 * packed after it, so a single LocalFree releases everything. Read all
 * the properties you need in one call, since each read decompresses the
 * record. With CEDB_AUTOINCREMENT, the seek pointer advances afterwards.
 * Even on failure the buffer may have been allocated or reallocated:
 * free *lplpBuffer if it isn't NULL.
 *
 * @param hDbase Handle from CeOpenDatabase.
 * @param dwFlags 0, or CEDB_ALLOWREALLOC to let the system LocalAlloc or
 *        LocalReAlloc the buffer as needed.
 * @param lpcPropID Number of entries in rgPropID. If rgPropID is NULL,
 *        receives the number of properties read.
 * @param rgPropID Property identifiers to read, or NULL for all.
 * @param lplpBuffer Pointer to the buffer. With CEDB_ALLOWREALLOC it can
 *        point to NULL to have one allocated, and may change.
 * @param lpcbBuffer Size of the buffer in bytes; receives the size used,
 *        or the size needed if too small.
 * @return The record's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_NO_MORE_ITEMS at the end of the database,
 *         ERROR_INSUFFICIENT_BUFFER, ERROR_NO_DATA, ERROR_KEY_DELETED).
 */
CEOID CeReadRecordProps(HANDLE hDbase, DWORD dwFlags, LPWORD lpcPropID, CEPROPID *rgPropID, LPBYTE *lplpBuffer, LPDWORD lpcbBuffer);
/**
 * Writes properties to a record, creating it if needed.
 *
 * Doesn't move the seek pointer. Set CEDB_PROPDELETE in a CEPROPVAL's
 * wFlags to delete that property. Changing sort-order properties costs
 * more. Nothing passed in is freed. This is the later name for
 * PegWriteRecordProps.
 *
 * @param hDbase Handle from CeOpenDatabase.
 * @param oidRecord Record to write, or 0 to create a new one.
 * @param cPropID Number of entries in rgPropVal. Must not be 0.
 * @param rgPropVal Property values to write.
 * @return The record's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_DISK_FULL, ERROR_INVALID_PARAMETER).
 */
CEOID CeWriteRecordProps(HANDLE hDbase, CEOID oidRecord, WORD cPropID, CEPROPVAL *rgPropVal);
/**
 * Retrieves information about an object in the object store.
 *
 * Works for files, directories, databases and records. This is the later
 * name for PegOidGetInfo.
 *
 * @param oid Object identifier.
 * @param oidInfo Receives the object's type and type-specific details.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_INVALID_HANDLE for an unknown identifier).
 */
BOOL CeOidGetInfo(CEOID oid, CEOIDINFO *oidInfo);

#define PegFindFirstDatabase CeFindFirstDatabase
#define PegFindNextDatabase CeFindNextDatabase
#define PegCreateDatabase CeCreateDatabase
#define PegSetDatabaseInfo CeSetDatabaseInfo
#define PegOpenDatabase CeOpenDatabase
#define PegDeleteDatabase CeDeleteDatabase
#define PegSeekDatabase CeSeekDatabase
#define PegDeleteRecord CeDeleteRecord
#define PegReadRecordProps CeReadRecordProps
#define PegWriteRecordProps CeWriteRecordProps
#define PegOidGetInfo CeOidGetInfo

#else

/**
 * Starts an enumeration of the databases in the object store.
 *
 * Step through it with PegFindNextDatabase and close the handle with
 * CloseHandle. Renamed CeFindFirstDatabase in later versions.
 *
 * @param dwClassID Type of database to enumerate, or 0 for all.
 * @return Enumeration handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError).
 */
HANDLE PegFindFirstDatabase(DWORD dwClassID);
/**
 * Returns the next database in an enumeration.
 *
 * Renamed CeFindNextDatabase in later versions.
 *
 * @param hEnum Handle from PegFindFirstDatabase.
 * @return The database's object identifier, or 0 when there are no more
 *         (ERROR_NO_MORE_ITEMS) or on failure (see GetLastError).
 */
PEGOID PegFindNextDatabase(HANDLE hEnum);
/**
 * Creates a database in the object store.
 *
 * Returns an object identifier, not an open handle: open it with
 * PegOpenDatabase. Each sort order adds cost to every insert and delete,
 * but adding one later with PegSetDatabaseInfo is more expensive still.
 * Renamed CeCreateDatabase in later versions.
 *
 * @param lpszName Database name, up to 32 characters including the null.
 *        Longer names are truncated.
 * @param dwClassID Application-defined type, used to filter enumeration
 *        with PegFindFirstDatabase. Need not be unique.
 * @param wNumSortOrder Number of sort orders, 0 to 4.
 * @param rgSortSpecs Array of wNumSortOrder SORTORDERSPEC, or NULL if
 *        wNumSortOrder is 0.
 * @return The new database's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_DISK_FULL, ERROR_INVALID_PARAMETER or
 *         ERROR_DUP_NAME).
 */
PEGOID PegCreateDatabase(LPWSTR lpszName, DWORD dwClassID, WORD wNumSortOrder, SORTORDERSPEC *rgSortSpecs);
/**
 * Changes a database's name, type or sort orders.
 *
 * Changing sort orders can take minutes on a large database, so warn the
 * user first. Renamed CeSetDatabaseInfo in later versions.
 *
 * @param oidDbase Object identifier of the database.
 * @param pNewInfo New settings. dwFlags (PEGDB_VALID*) selects which
 *        members apply; wNumRecords is ignored.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_DISK_FULL, or ERROR_SHARING_VIOLATION when removing a sort
 *         order an open handle is using).
 */
BOOL PegSetDatabaseInfo(PEGOID oidDbase, PEGDBASEINFO *pNewInfo);
/**
 * Opens a database by object identifier or name.
 *
 * Close the handle with CloseHandle. There are no transactions: every
 * change is committed as it is made. Renamed CeOpenDatabase in later
 * versions.
 *
 * @param poid Object identifier of the database, or a pointer to 0 to
 *        open by name and receive the identifier.
 * @param lpszName Database name. Ignored if *poid is nonzero.
 * @param propid Property identifier of the sort order to traverse in, used
 *        by PegSeekDatabase and PegReadRecordProps, or 0 for none.
 * @param dwFlags PEGDB_AUTOINCREMENT to advance the seek pointer after
 *        each PegReadRecordProps, or 0.
 * @param hwndNotify Window to receive DB_PEGOID_* messages when another
 *        thread changes the database, or NULL.
 * @return Database handle, or INVALID_HANDLE_VALUE on failure (see
 *         GetLastError: ERROR_FILE_NOT_FOUND if no database has the name).
 */
HANDLE PegOpenDatabase(PPEGOID poid, LPWSTR lpszName, PEGPROPID propid, DWORD dwFlags, HWND hwndNotify);
/**
 * Deletes a database and all its records.
 *
 * Renamed CeDeleteDatabase in later versions.
 *
 * @param oid Object identifier of the database.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_SHARING_VIOLATION if another thread has it open).
 */
BOOL PegDeleteDatabase(PEGOID oid);
/**
 * Moves the seek pointer of an open database.
 *
 * Seeks use the sort order chosen in PegOpenDatabase, and value seeks work
 * only on a sorted property. A failed value seek leaves the pointer at the
 * end of the database. Renamed CeSeekDatabase in later versions.
 *
 * @param hDatabase Handle from PegOpenDatabase.
 * @param dwSeekType PEGDB_SEEK_PEGOID (fast), PEGDB_SEEK_VALUESMALLER,
 *        PEGDB_SEEK_VALUEFIRSTEQUAL, PEGDB_SEEK_VALUENEXTEQUAL (one step
 *        forward, to walk equal values), PEGDB_SEEK_VALUEGREATER (greater
 *        or equal), PEGDB_SEEK_BEGINNING, PEGDB_SEEK_CURRENT or
 *        PEGDB_SEEK_END. Value seeks other than NEXTEQUAL, backward seeks
 *        and seeks from the end are O(n).
 * @param dwValue An object identifier for PEGDB_SEEK_PEGOID, a pointer to
 *        a PEGPROPVAL for value seeks, or a record count for the others.
 *        For PEGDB_SEEK_CURRENT, cast a negative count to seek backwards.
 * @param lpdwIndex Receives the found record's index from the start.
 * @return The object identifier of the record found, or 0 on failure.
 */
PEGOID PegSeekDatabase(HANDLE hDatabase, DWORD dwSeekType, DWORD dwValue, LPDWORD lpdwIndex);
/**
 * Deletes a record from an open database.
 *
 * If the deleted record was the current one, the next read fails unless
 * the database was opened with PEGDB_AUTOINCREMENT, in which case the seek
 * pointer moves on to the next record. Renamed CeDeleteRecord in later
 * versions.
 *
 * @param hDatabase Handle from PegOpenDatabase.
 * @param oidRecord Object identifier of the record.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
BOOL PegDeleteRecord(HANDLE hDatabase, PEGOID oidRecord);
/**
 * Reads properties from the current record.
 *
 * The buffer receives an array of PEGPROPVAL, with string and blob data
 * packed after it, so a single LocalFree releases everything. Read all
 * the properties you need in one call, since each read decompresses the
 * record. With PEGDB_AUTOINCREMENT, the seek pointer advances afterwards.
 * Even on failure the buffer may have been allocated or reallocated:
 * free *lplpBuffer if it isn't NULL. Renamed CeReadRecordProps in later
 * versions.
 *
 * @param hDbase Handle from PegOpenDatabase.
 * @param dwFlags 0, or PEGDB_ALLOWREALLOC to let the system LocalAlloc or
 *        LocalReAlloc the buffer as needed.
 * @param lpcPropID Number of entries in rgPropID. If rgPropID is NULL,
 *        receives the number of properties read.
 * @param rgPropID Property identifiers to read, or NULL for all.
 * @param lplpBuffer Pointer to the buffer. With PEGDB_ALLOWREALLOC it can
 *        point to NULL to have one allocated, and may change.
 * @param lpcbBuffer Size of the buffer in bytes; receives the size used,
 *        or the size needed if too small.
 * @return The record's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_NO_MORE_ITEMS at the end of the database,
 *         ERROR_INSUFFICIENT_BUFFER, ERROR_NO_DATA, ERROR_KEY_DELETED).
 */
PEGOID PegReadRecordProps(HANDLE hDbase, DWORD dwFlags, LPWORD lpcPropID, PEGPROPID *rgPropID, LPBYTE *lplpBuffer, LPDWORD lpcbBuffer);
/**
 * Writes properties to a record, creating it if needed.
 *
 * Doesn't move the seek pointer. Set PEGDB_PROPDELETE in a PEGPROPVAL's
 * wFlags to delete that property. Changing sort-order properties costs
 * more. Nothing passed in is freed. Renamed CeWriteRecordProps in later
 * versions.
 *
 * @param hDbase Handle from PegOpenDatabase.
 * @param oidRecord Record to write, or 0 to create a new one.
 * @param cPropID Number of entries in rgPropVal. Must not be 0.
 * @param rgPropVal Property values to write.
 * @return The record's object identifier, or 0 on failure (see
 *         GetLastError: ERROR_DISK_FULL, ERROR_INVALID_PARAMETER).
 */
PEGOID PegWriteRecordProps(HANDLE hDbase, PEGOID oidRecord, WORD cPropID, PEGPROPVAL *rgPropVal);
/**
 * Retrieves information about an object in the object store.
 *
 * Works for files, directories, databases and records. Renamed
 * CeOidGetInfo in later versions.
 *
 * @param oid Object identifier.
 * @param oidInfo Receives the object's type and type-specific details.
 * @return TRUE on success, FALSE on failure (see GetLastError:
 *         ERROR_INVALID_HANDLE for an unknown identifier).
 */
BOOL PegOidGetInfo(PEGOID oid, PEGOIDINFO *oidInfo);

#define CeFindFirstDatabase PegFindFirstDatabase
#define CeFindNextDatabase PegFindNextDatabase
#define CeCreateDatabase PegCreateDatabase
#define CeSetDatabaseInfo PegSetDatabaseInfo
#define CeOpenDatabase PegOpenDatabase
#define CeDeleteDatabase PegDeleteDatabase
#define CeSeekDatabase PegSeekDatabase
#define CeDeleteRecord PegDeleteRecord
#define CeReadRecordProps PegReadRecordProps
#define CeWriteRecordProps PegWriteRecordProps
#define CeOidGetInfo PegOidGetInfo

#endif

#ifdef __cplusplus
}
#endif

#endif

#endif

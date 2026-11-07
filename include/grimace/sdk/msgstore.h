#ifndef GRIMACE_SDK_MSGSTORE_H
#define GRIMACE_SDK_MSGSTORE_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Closes a message-store context.
 *
 * @param hMail Message-store context.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailClose(HANDLE hMail);
struct MailMsg_s;
typedef struct MailMsg_s MailMsg;
/**
 * Removes a message from the message store.
 *
 * @param hMail Message-store context.
 * @param pmm Message to delete.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailDelete(HANDLE hMail, MailMsg *pmm);
struct MailAtt_s;
typedef struct MailAtt_s MailAtt;
/**
 * Deletes an attachment from a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message containing the attachment.
 * @param pma Attachment to delete.
 * @param fFullDelete Whether to delete the attachment header as well.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailDeleteAttachment(HANDLE hMail, MailMsg *pmm, MailAtt *pma, BOOL fFullDelete);
/**
 * Retrieves the last message-store error or warning.
 *
 * Negative values indicate errors, positive values warnings, and zero no
 * error.
 *
 * @param hMail Message-store context.
 * @return Last message-store error or warning value.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
int MailError(HANDLE hMail);
/**
 * Retrieves printable text for the last message-store error.
 *
 * @param hMail Message-store context.
 * @param szBuf Receives the error text.
 * @param iBufLen Buffer capacity, in characters.
 * @param piSrcLine Optionally receives the source line of the error.
 * @return Last message-store error value.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
int MailErrorMsg(HANDLE hMail, LPWSTR szBuf, int iBufLen, int *piSrcLine);
/**
 * Retrieves the first message in the message store.
 *
 * @param hMail Message-store context.
 * @param pmm Receives the message.
 * @return TRUE on success, FALSE when no message is available or on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailFirst(HANDLE hMail, MailMsg *pmm);
/**
 * Releases storage returned for a previously retrieved message.
 *
 * @param pmm Message whose storage to release.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailFree(MailMsg *pmm);
/**
 * Retrieves a message from the message store.
 *
 * @param hMail Message-store context.
 * @param pmm Receives the message.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailGet(HANDLE hMail, MailMsg *pmm);
/**
 * Retrieves an attachment for a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message containing the attachment.
 * @param pma Receives the attachment data.
 *
 * @note Windows CE 3.0 only.
 */
INT MailGetAttachment(HANDLE hMail, MailMsg *pmm, MailAtt *pma);
/**
 * Retrieves a header field from a message.
 *
 * Set `fGetName` to retrieve the field name position rather than its value.
 *
 * @param pmm Message to read.
 * @param szName Header field name.
 * @param fGetName Selects the field-name position instead of its value.
 * @return Pointer to the requested header field.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
LPWSTR MailGetField(MailMsg *pmm, LPWSTR szName, BOOL fGetName);
/**
 * Finds a folder ID by folder name.
 *
 * @param hMail Message-store context.
 * @param pbId Receives the folder ID.
 * @param szName Folder name to match.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailGetFolderId(HANDLE hMail, BYTE *pbId, LPWSTR szName);
/**
 * Retrieves a folder name by folder ID.
 *
 * `piId` supplies the folder ID and receives the next used ID, or -1.
 * `piLen` supplies the buffer capacity and receives the required character
 * count including the terminator. Set `szName` to NULL to query the size.
 *
 * @param hMail Message-store context.
 * @param piId Input folder ID and output next used ID.
 * @param piLen Input capacity and output required count.
 * @param szName Receives the folder name, or NULL to query its size.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailGetFolderName(HANDLE hMail, int *piId, int *piLen, LPWSTR szName);
struct _MAILSORTINFO;
typedef struct _MAILSORTINFO *PMAILSORTINFO;
/**
 * Retrieves message-list sort order and direction.
 *
 * @param hMail Message-store context.
 * @param pInfo Receives sort field, direction and message count.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailGetSort(HANDLE hMail, PMAILSORTINFO pInfo);
/**
 * Retrieves a message object ID using its service name and ID.
 *
 * The message object ID and status flags are returned in `pmm`.
 *
 * @param hMail Message-store context.
 * @param pmm Message whose service identifiers are used and object ID is set.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailGetSvcId(HANDLE hMail, MailMsg *pmm);
/**
 * Computes the character count of a message's header string.
 *
 * @param pmm Message whose headers to measure.
 * @return Header length in characters.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
DWORD MailHeaderLen(MailMsg *pmm);
/**
 * Retrieves the local attachment length associated with a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message whose attachment length to retrieve.
 * @return Local attachment length.
 *
 * @note Windows CE 3.0 only.
 */
DWORD MailLocalAttachmentLen(HANDLE hMail, MailMsg *pmm);
/**
 * Retrieves the next message after the message in `pmm`.
 *
 * @param hMail Message-store context.
 * @param pmm Previous message on input; receives the next message.
 * @return TRUE on success, FALSE when no message is available or on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailNext(HANDLE hMail, MailMsg *pmm);
/**
 * Opens the message store and returns its context handle.
 *
 * @param phMail Receives the message-store context.
 * @param fAllowCreate Allows creation of the message-store directory and database.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailOpen(HANDLE *phMail, BOOL fAllowCreate);
/**
 * Opens the message store and enables database notifications to a window.
 *
 * @param phMail Receives the message-store context.
 * @param fAllowCreate Allows creation of the message-store directory and database.
 * @param hwndNotify Window that receives database notifications.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailOpenNotify(HANDLE *phMail, BOOL fAllowCreate, HWND hwndNotify);
/**
 * Creates a message-store entry from a message structure.
 *
 * The `dwMsgId` member is ignored when storing a new message.
 *
 * @param hMail Message-store context.
 * @param pmm Message data to store.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailPut(HANDLE hMail, MailMsg *pmm);
/**
 * Creates an attachment for a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message that receives the attachment.
 * @param pma Attachment data to store.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailPutAttachment(HANDLE hMail, MailMsg *pmm, MailAtt *pma);
/**
 * Sets a folder name; a NULL name deletes the folder.
 *
 * @param hMail Message-store context.
 * @param bId Folder ID.
 * @param szName New folder name, or NULL to delete the folder.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailPutFolder(HANDLE hMail, BYTE bId, LPWSTR szName);
/**
 * Reads extra properties, such as schedule information, from a message.
 *
 * The returned property array is allocated; release it with LocalFree.
 *
 * @param hMail Message-store context.
 * @param pmm Message to read.
 * @param ppPropVal Receives the allocated property array.
 * @param pcPropVal Receives the number of properties.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailReadNonIPMProperties(HANDLE hMail, MailMsg *pmm, CEPROPVAL **ppPropVal, WORD *pcPropVal);
/**
 * Closes a registry key used by message-store emulation or RPC support.
 *
 * @param hKey Registry key handle.
 * @return Zero on success, or a registry error code.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
LONG MailRegCloseKey(HKEY hKey);
/**
 * Enumerates a subkey for message-store emulation or RPC support.
 *
 * @param hKey Registry key handle.
 * @param dwIndex Subkey index.
 * @param lpName Receives the subkey name.
 * @param lpcbName Input name-buffer size and output name length.
 * @param lpReserved Reserved; set to NULL.
 * @param lpClass Receives the class string, if present.
 * @param lpcbClass Input class-buffer size and output class length.
 * @param lpftLastWriteTime Optionally receives the last-write time.
 * @return Zero on success, or a registry error code.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
LONG MailRegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcbName, LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcbClass, PFILETIME lpftLastWriteTime);
/**
 * Opens a Pegasus registry key for message-store emulation or RPC support.
 *
 * @param hKey Handle to an open key.
 * @param lpSubKey Name of the subkey to open.
 * @param ulOptions Reserved; set to zero.
 * @param samDesired Requested access mask.
 * @param phkResult Receives the opened key handle.
 * @return Zero on success, or a registry error code.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
LONG MailRegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
/**
 * Requests or cancels retrieval of a message attachment.
 *
 * @param hMail Message-store context.
 * @param pmm Message containing the attachment.
 * @param pma Attachment to retrieve or cancel.
 * @param bRetrieve TRUE to request retrieval, FALSE to cancel it.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailRequestAttachment(HANDLE hMail, MailMsg *pmm, MailAtt *pma, BOOL bRetrieve);
/**
 * Sets attachment options for a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message whose attachment options to change.
 * @param dwFlags Attachment option flags.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailSetAttachmentOptions(HANDLE hMail, MailMsg *pmm, DWORD dwFlags);
/**
 * Sets a header field in a message; a NULL value deletes the field.
 *
 * @param pmm Message to modify.
 * @param szName Header field name.
 * @param szVal New field value, or NULL to delete the field.
 * @return TRUE on success, FALSE on allocation failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailSetField(MailMsg *pmm, LPWSTR szName, LPCWSTR szVal);
typedef enum {
    MAIL_SORT_FROM,
    MAIL_SORT_SUBJ,
    MAIL_SORT_DATE,
    MAIL_SORT_SIZE
} MAILSORTFIELD;

/**
 * Sets message-list sort order and direction.
 *
 * @param hMail Message-store context.
 * @param iSort MAIL_SORT_FROM, MAIL_SORT_SUBJ, MAIL_SORT_DATE or MAIL_SORT_SIZE.
 * @param fAscending TRUE for ascending order, FALSE for descending.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailSetSort(HANDLE hMail, MAILSORTFIELD iSort, BOOL fAscending);
/**
 * Updates message flags after a message has been retrieved.
 *
 * Set `fDoAll` to TRUE to update the other message fields as well.
 *
 * @param hMail Message-store context.
 * @param pmm Message with updated flags or fields.
 * @param fDoAll Whether to update all other fields.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL MailUpdate(HANDLE hMail, MailMsg *pmm, BOOL fDoAll);
/**
 * Writes extra properties, such as schedule information, to a message.
 *
 * @param hMail Message-store context.
 * @param pmm Message to update.
 * @param pPropVal Property array to write.
 * @param cPropVal Number of properties in the array.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 3.0 only.
 */
BOOL MailWriteNonIPMProperties(HANDLE hMail, MailMsg *pmm, CEPROPVAL *pPropVal, UINT cPropVal);
struct MailNonIpmInfo_s;
typedef struct MailNonIpmInfo_s MailNonIpmInfo;
struct MailAttArray_s;
typedef struct MailAttArray_s MailAttArray;
typedef struct _MAILSORTINFO MAILSORTINFO;
typedef DWORD (*PMAILATTACHMENTLEN)(HANDLE, MailMsg *);
typedef BOOL (*PMAILCLOSE)(HANDLE);
typedef BOOL (*PMAILDELETE)(HANDLE, MailMsg *);
typedef BOOL (*PMAILDELETEATTACHMENT)(HANDLE, MailMsg *, MailAtt *, BOOL);
typedef int (*PMAILERROR)(HANDLE);
typedef int (*PMAILERRORMSG)(HANDLE, LPWSTR, int, int *);
typedef BOOL (*PMAILFIRST)(HANDLE, MailMsg *);
typedef BOOL (*PMAILFREE)(MailMsg *);
typedef BOOL (*PMAILGET)(HANDLE, MailMsg *);
typedef UINT (*PMAILGETATTACHMENT)(HANDLE, MailMsg *, MailAtt *);
typedef LPWSTR (*PMAILGETFIELD)(MailMsg *, LPWSTR, BOOL);
typedef BOOL (*PMAILGETFOLDERID)(HANDLE, BYTE *, LPWSTR);
typedef BOOL (*PMAILGETFOLDERNAME)(HANDLE, int *, int *, LPWSTR);
typedef BOOL (*PMAILGETSORT)(HANDLE, MAILSORTFIELD *, BOOL *);
typedef BOOL (*PMAILGETSVCID)(HANDLE, MailMsg *);
typedef DWORD (*PMAILHEADERLEN)(MailMsg *);
typedef BOOL (*PMAILNEXT)(HANDLE, MailMsg *);
typedef BOOL (*PMAILOPEN)(HANDLE *, BOOL);
typedef BOOL (*PMAILPUT)(HANDLE, MailMsg *);
typedef BOOL (*PMAILPUTATTACHMENT)(HANDLE, MailMsg *, MailAtt *);
typedef BOOL (*PMAILPUTFOLDER)(HANDLE, BYTE, LPWSTR);
typedef BOOL (*PMAILREADNONIPMPROPERTIES)(HANDLE, MailMsg *, CEPROPVAL **, WORD *);
typedef LONG (*PMAILREGCLOSEKEY)(HKEY);
typedef LONG (*PMAILREGENUMKEYEXW)(HKEY, DWORD, LPWSTR, LPDWORD, LPDWORD, LPWSTR, LPDWORD, PFILETIME);
typedef LONG (*PMAILREGOPENKEYEXW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
typedef BOOL (*PMAILREQUESTATTACHMENT)(HANDLE, MailMsg *, MailAtt *, BOOL);
typedef BOOL (*PMAILSETATTACHMENTOPTIONS)(HANDLE, MailMsg *, DWORD);
typedef BOOL (*PMAILSETFIELD)(MailMsg *, LPWSTR, LPCWSTR);
typedef BOOL (*PMAILSETSORT)(HANDLE, MAILSORTFIELD, BOOL);
typedef BOOL (*PMAILUPDATE)(HANDLE, MailMsg *, BOOL);
typedef BOOL (*PMAILWRITENONIPMPROPERTIES)(HANDLE, MailMsg *, CEPROPVAL *, UINT);
typedef struct MailAtt_s *lpMailAtt;
typedef struct MailAttArray_s *lpMailAttArray;
typedef struct MailNonIpmInfo_s *lpMailNonIpmInfo;
struct MailAttArray_s {
    DWORD dwFlags;
    UINT uiAttCount;
    lpMailAtt AttArray[];
};

struct MailAtt_s {
    UINT uiAttachmentNumber;
    DWORD dwFlags;
    ULONG ulCharacterPosition;
    ULONG ulSize;
    LPWSTR szOriginalName;
    LPWSTR szLocalName;
};

struct MailMsg_s {
    DWORD dwMsgId;
    DWORD dwFlags;
    DWORD dwMsgLen;
    WORD wBodyLen;
    FILETIME ftDate;
    LPWSTR szSvcId;
    LPWSTR szSvcNam;
    WCHAR *pwcHeaders;
    LPWSTR szBody;
    CEOID oid;
    HANDLE hHeap;
};

struct MailNonIpmInfo_s {
    LPWSTR szMessageClass;
    UINT uiPropCount;
    CEPROPVAL propArray[];
};

struct _MAILSORTINFO {
    MAILSORTFIELD iSort;
    BOOL fAscending;
    int cMsgs;
};


#ifdef __cplusplus
}
#endif

#endif

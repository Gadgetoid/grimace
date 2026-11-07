#ifndef GRIMACE_SDK_WINSCARD_H
#define GRIMACE_SDK_WINSCARD_H

#include <grimace/sdk/winsmcrd.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef ULONG SCARDHANDLE;
/**
 * Begins a transaction on a connected smart card.
 *
 * Other applications are blocked from accessing the card until the
 * transaction ends. Finish with SCardEndTransaction.
 *
 * @param hCard Connected card handle.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardBeginTransaction(SCARDHANDLE hCard);
typedef ULONG SCARDCONTEXT;
/**
 * Cancels outstanding resource-manager actions that wait for external input.
 *
 * This is useful for interrupting SCardGetStatusChange. The canceled
 * operation returns a status indicating cancellation.
 *
 * @param hContext Resource-manager context from SCardEstablishContext.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardCancel(SCARDCONTEXT hContext);
typedef SCARDHANDLE *LPSCARDHANDLE;
/**
 * Connects to a card in a named reader.
 *
 * Windows CE supports exclusive sharing; shared and direct modes are
 * unsupported. A context can have only one active connection. The
 * preferred T=0 and T=1 protocols can be combined.
 *
 * @param hContext Resource-manager context.
 * @param szReader Reader name from SCardListReadersW.
 * @param dwShareMode SCARD_SHARE_EXCLUSIVE.
 * @param dwPreferredProtocols Bitmask of acceptable SCARD_PROTOCOL_T0/T1 values.
 * @param phCard Receives the card handle.
 * @param pdwActiveProtocol Receives the negotiated protocol.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardConnectW(SCARDCONTEXT hContext, LPCWSTR szReader, DWORD dwShareMode, DWORD dwPreferredProtocols, LPSCARDHANDLE phCard, LPDWORD pdwActiveProtocol);
/**
 * Sends a control request directly to a connected reader.
 *
 * The effect depends on the reader-specific control code.
 *
 * @param hCard Connected card handle.
 * @param dwControlCode Reader control code.
 * @param lpInBuffer Input data, or NULL if none.
 * @param nInBufferSize Input size in bytes.
 * @param lpOutBuffer Receives output, or NULL if none.
 * @param nOutBufferSize Output buffer size in bytes.
 * @param lpBytesReturned Receives the output size in bytes.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardControl(SCARDHANDLE hCard, DWORD dwControlCode, LPCVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned);
/**
 * Disconnects from a smart card.
 *
 * Choose whether to leave, reset, power down or eject the card.
 *
 * @param hCard Connected card handle.
 * @param dwDisposition SCARD_LEAVE_CARD, SCARD_RESET_CARD,
 *        SCARD_UNPOWER_CARD or SCARD_EJECT_CARD.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardDisconnect(SCARDHANDLE hCard, DWORD dwDisposition);
/**
 * Ends a transaction and releases the card for other applications.
 *
 * Choose whether to leave, reset, power down or eject the card.
 *
 * @param hCard Connected card handle with an active transaction.
 * @param dwDisposition SCARD_LEAVE_CARD, SCARD_RESET_CARD,
 *        SCARD_UNPOWER_CARD or SCARD_EJECT_CARD.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardEndTransaction(SCARDHANDLE hCard, DWORD dwDisposition);
typedef SCARDCONTEXT *LPSCARDCONTEXT;
/**
 * Creates a resource-manager context for smart-card operations.
 *
 * Windows CE treats SCARD_SCOPE_USER as SCARD_SCOPE_SYSTEM. Both
 * reserved arguments must be NULL. Release the context with
 * SCardReleaseContext.
 *
 * @param dwScope SCARD_SCOPE_SYSTEM or SCARD_SCOPE_USER.
 * @param pvReserved1 Reserved; set to NULL.
 * @param pvReserved2 Reserved; set to NULL.
 * @param phContext Receives the resource-manager context.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardEstablishContext(DWORD dwScope, LPCVOID pvReserved1, LPCVOID pvReserved2, LPSCARDCONTEXT phContext);
/**
 * Removes a card type from the smart-card database.
 *
 * @param hContext Resource-manager context.
 * @param szCardName Friendly card name previously introduced.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardForgetCardTypeW(SCARDCONTEXT hContext, LPCWSTR szCardName);
/**
 * Removes an introduced reader name from the smart-card database.
 *
 * The name is also removed from any reader groups.
 *
 * @param hContext Resource-manager context.
 * @param szReaderName Friendly reader name.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardForgetReaderW(SCARDCONTEXT hContext, LPCWSTR szReaderName);
/**
 * Retrieves an attribute of a connected reader.
 *
 * Set pbAttr to NULL to query the required buffer size.
 *
 * @param hCard Connected card handle.
 * @param dwAttrId Attribute identifier.
 * @param pbAttr Receives the attribute, or NULL to query its size.
 * @param pcbAttrLen Input buffer size and output length in bytes.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardGetAttrib(SCARDHANDLE hCard, DWORD dwAttrId, LPBYTE pbAttr, LPDWORD pcbAttrLen);
/**
 * Retrieves the provider module name registered for a card type.
 *
 * Provider identifiers include SCARD_PROVIDER_PRIMARY and
 * SCARD_PROVIDER_CSP. The output length includes the terminating NUL.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param szCardName Card type name.
 * @param dwProviderId Provider identifier.
 * @param szProvider Receives the provider name.
 * @param pcchProvider Input capacity and output character count.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardGetCardTypeProviderNameW(SCARDCONTEXT hContext, LPCWSTR szCardName, DWORD dwProviderId, LPWSTR szProvider, LPDWORD pcchProvider);
/**
 * Retrieves the primary service-provider GUID for a card type.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param szCard Introduced card name.
 * @param pguidProviderId Receives the provider GUID.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardGetProviderIdW(SCARDCONTEXT hContext, LPCWSTR szCard, LPGUID pguidProviderId);
typedef struct {
    LPCWSTR szReader;
    LPVOID pvUserData;
    DWORD dwCurrentState;
    DWORD dwEventState;
    DWORD cbAtr;
    BYTE rgbAtr[36];
} SCARD_READERSTATEW;

typedef SCARD_READERSTATEW *LPSCARD_READERSTATEW;
/**
 * Waits for card availability to change in one or more readers.
 *
 * Each SCARD_READERSTATEW entry identifies a reader and receives its new
 * event state. A timeout of zero means wait indefinitely. Use
 * SCardCancel to cancel a pending wait.
 *
 * @param hContext Resource-manager context.
 * @param dwTimeout Maximum wait in milliseconds, or zero for infinite.
 * @param rgReaderStates Reader states to monitor and update.
 * @param cReaders Number of entries in rgReaderStates.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardGetStatusChangeW(SCARDCONTEXT hContext, DWORD dwTimeout, LPSCARD_READERSTATEW rgReaderStates, DWORD cReaders);
typedef const BYTE *LPCBYTE;
/**
 * Registers a card type and its provider, interfaces and optional ATR match.
 *
 * The ATR mask, if supplied, must be the same length as the ATR. A zero
 * ATR length lets the subsystem determine the length from the ATR format.
 *
 * @param hContext Resource-manager context.
 * @param szCardName Friendly card name.
 * @param pguidPrimaryProvider Primary provider GUID.
 * @param rgguidInterfaces Supported interface GUIDs.
 * @param dwInterfaceCount Number of interface GUIDs.
 * @param pbAtr ATR bytes used to match cards.
 * @param pbAtrMask Optional ATR comparison mask.
 * @param cbAtrLen ATR and mask length in bytes, or zero for automatic length.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardIntroduceCardTypeW(SCARDCONTEXT hContext, LPCWSTR szCardName, LPCGUID pguidPrimaryProvider, LPCGUID rgguidInterfaces, DWORD dwInterfaceCount, LPCBYTE pbAtr, LPCBYTE pbAtrMask, DWORD cbAtrLen);
/**
 * Adds a friendly name for an existing smart-card reader.
 *
 * Readers are normally introduced automatically.
 *
 * @param hContext Resource-manager context.
 * @param szReaderName Friendly reader name to add.
 * @param szDeviceName System reader device name, such as "SCReader0".
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardIntroduceReaderW(SCARDCONTEXT hContext, LPCWSTR szReaderName, LPCWSTR szDeviceName);
/**
 * Lists registered card types matching an ATR, interfaces, or both.
 *
 * When both filters are supplied, a card must match the ATR and support
 * all listed interfaces. Set both filters to NULL to list all cards. A
 * NULL output buffer queries the required multi-string length.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param pbAtr ATR to match, or NULL.
 * @param rgquidInterfaces Interface GUIDs required, or NULL.
 * @param cguidInterfaceCount Number of interface GUIDs.
 * @param mszCards Receives a multi-string of card names, or NULL to query size.
 * @param pcchCards Input capacity and output character count including
 *        terminating NUL characters.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardListCardsW(SCARDCONTEXT hContext, LPCBYTE pbAtr, LPCGUID rgquidInterfaces, DWORD cguidInterfaceCount, LPWSTR mszCards, LPDWORD pcchCards);
/**
 * Lists the interfaces registered for a card type.
 *
 * Set the output array to NULL to query the required number of GUIDs.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param szCard Introduced card name.
 * @param pguidInterfaces Receives interface GUIDs, or NULL to query count.
 * @param pcguidInterfaces Input capacity and output number of GUIDs.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardListInterfacesW(SCARDCONTEXT hContext, LPCWSTR szCard, LPGUID pguidInterfaces, LPDWORD pcguidInterfaces);
/**
 * Lists readers in the specified reader groups.
 *
 * Set mszGroups to NULL to list all readers. A NULL output buffer queries
 * the required multi-string length, including all terminating NULs.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param mszGroups Multi-string of groups, or NULL for all readers.
 * @param mszReaders Receives the reader-name multi-string, or NULL to query size.
 * @param pcchReaders Input capacity and output character count.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardListReadersW(SCARDCONTEXT hContext, LPCWSTR mszGroups, LPWSTR mszReaders, LPDWORD pcchReaders);
/**
 * Searches readers for cards matching any name in a multi-string.
 *
 * Reader states receive the match results. If no card matches, use
 * SCardGetStatusChangeW to wait for a change.
 *
 * @param hContext Resource-manager context.
 * @param mszCards Multi-string of card names to find.
 * @param rgReaderStates Readers to search and update.
 * @param cReaders Number of reader-state entries.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardLocateCardsW(SCARDCONTEXT hContext, LPCWSTR mszCards, LPSCARD_READERSTATEW rgReaderStates, DWORD cReaders);
/**
 * Re-establishes a card connection and clears certain error states.
 *
 * Windows CE supports exclusive sharing and T=0/T=1 protocols.
 *
 * @param hCard Connected card handle.
 * @param dwShareMode SCARD_SHARE_EXCLUSIVE.
 * @param dwPreferredProtocols Bitmask of acceptable T=0/T=1 protocols.
 * @param dwInitialization SCARD_LEAVE_CARD, SCARD_RESET_CARD or
 *        SCARD_UNPOWER_CARD.
 * @param pdwActiveProtocol Receives the active protocol.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardReconnect(SCARDHANDLE hCard, DWORD dwShareMode, DWORD dwPreferredProtocols, DWORD dwInitialization, LPDWORD pdwActiveProtocol);
/**
 * Releases a resource-manager context and its associated resources.
 *
 * This also releases card handles and memory allocated with
 * SCARD_AUTOALLOCATE.
 *
 * @param hContext Context from SCardEstablishContext.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardReleaseContext(SCARDCONTEXT hContext);
/**
 * Sets an attribute on a connected reader.
 *
 * Not all reader attributes can be set; support depends on the reader and
 * transport protocol.
 *
 * @param hCard Connected card handle.
 * @param dwAttrId Attribute identifier.
 * @param pbAttr Attribute bytes to set.
 * @param cbAttrLen Attribute length in bytes.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardSetAttrib(SCARDHANDLE hCard, DWORD dwAttrId, LPCBYTE pbAttr, DWORD cbAttrLen);
/**
 * Sets the provider module name registered for a card type.
 *
 * Provider identifiers include SCARD_PROVIDER_PRIMARY and
 * SCARD_PROVIDER_CSP.
 *
 * @param hContext Resource-manager context, or NULL.
 * @param szCardName Card type name.
 * @param dwProviderId Provider identifier.
 * @param szProvider Provider module name.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardSetCardTypeProviderNameW(SCARDCONTEXT hContext, LPCWSTR szCardName, DWORD dwProviderId, LPCWSTR szProvider);
/**
 * Retrieves the current reader, card and protocol status.
 *
 * The ATR buffer can hold at most 32 bytes. The protocol is meaningful
 * when the card is in SCARD_SPECIFICMODE.
 *
 * @param hCard Connected card handle.
 * @param szReaderName Receives the reader name.
 * @param pcchReaderLen Input capacity and output reader-name length in
 *        characters, including the terminator.
 * @param pdwState Receives the SCARD_* card state.
 * @param pdwProtocol Receives the active protocol, if applicable.
 * @param pbAtr Receives the ATR, up to 32 bytes.
 * @param pcbAtrLen Receives the ATR length in bytes.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardStatusW(SCARDHANDLE hCard, LPWSTR szReaderName, LPDWORD pcchReaderLen, LPDWORD pdwState, LPDWORD pdwProtocol, LPBYTE pbAtr, LPDWORD pcbAtrLen);
/**
 * Sends a command to a smart card and receives its response.
 *
 * For T=0, the response includes SW1 and SW2; provide at least two
 * receive bytes. The command buffer layout depends on whether data is
 * sent or received.
 *
 * @param hCard Connected card handle.
 * @param pioSendPci Protocol control information for the command.
 * @param pbSendBuffer Command bytes.
 * @param cbSendLength Command length in bytes.
 * @param pioRecvPci Receives protocol control information, or NULL.
 * @param pbRecvBuffer Receives response data.
 * @param pcbRecvLength Input receive-buffer capacity and output bytes received.
 * @return SCARD_S_SUCCESS, or a smart-card error code.
 *
 * @note Windows CE 3.0 only.
 */
LONG SCardTransmit(SCARDHANDLE hCard, LPCSCARD_IO_REQUEST pioSendPci, LPCBYTE pbSendBuffer, DWORD cbSendLength, LPSCARD_IO_REQUEST pioRecvPci, LPBYTE pbRecvBuffer, LPDWORD pcbRecvLength);
typedef BOOL (*LPOCNCHKPROC)(SCARDCONTEXT, SCARDHANDLE, PVOID);
typedef SCARDHANDLE (*LPOCNCONNPROCA)(SCARDCONTEXT, LPSTR, LPSTR, PVOID);
typedef SCARDHANDLE (*LPOCNCONNPROCW)(SCARDCONTEXT, LPWSTR, LPWSTR, PVOID);
typedef void (*LPOCNDSCPROC)(SCARDCONTEXT, SCARDHANDLE, PVOID);
typedef struct {
    DWORD dwStructSize;
    HWND hwndOwner;
    SCARDCONTEXT hSCardContext;
    LPWSTR lpstrGroupNames;
    DWORD nMaxGroupNames;
    LPWSTR lpstrCardNames;
    DWORD nMaxCardNames;
    LPCGUID rgguidInterfaces;
    DWORD cguidInterfaces;
    LPWSTR lpstrRdr;
    DWORD nMaxRdr;
    LPWSTR lpstrCard;
    DWORD nMaxCard;
    LPCWSTR lpstrTitle;
    DWORD dwFlags;
    LPVOID pvUserData;
    DWORD dwShareMode;
    DWORD dwPreferredProtocols;
    DWORD dwActiveProtocol;
    LPOCNCONNPROCW lpfnConnect;
    LPOCNCHKPROC lpfnCheck;
    LPOCNDSCPROC lpfnDisconnect;
    SCARDHANDLE hCardHandle;
} OPENCARDNAMEW;

typedef OPENCARDNAMEW *LPOPENCARDNAMEW;
typedef LPOPENCARDNAMEW LPOPENCARDNAME;
typedef struct {
    DWORD dwStructSize;
    HWND hwndOwner;
    SCARDCONTEXT hSCardContext;
    LPSTR lpstrGroupNames;
    DWORD nMaxGroupNames;
    LPSTR lpstrCardNames;
    DWORD nMaxCardNames;
    LPCGUID rgguidInterfaces;
    DWORD cguidInterfaces;
    LPSTR lpstrRdr;
    DWORD nMaxRdr;
    LPSTR lpstrCard;
    DWORD nMaxCard;
    LPCSTR lpstrTitle;
    DWORD dwFlags;
    LPVOID pvUserData;
    DWORD dwShareMode;
    DWORD dwPreferredProtocols;
    DWORD dwActiveProtocol;
    LPOCNCONNPROCA lpfnConnect;
    LPOCNCHKPROC lpfnCheck;
    LPOCNDSCPROC lpfnDisconnect;
    SCARDHANDLE hCardHandle;
} OPENCARDNAMEA;

typedef OPENCARDNAMEA *LPOPENCARDNAMEA;
typedef LPSCARD_READERSTATEW LPSCARD_READERSTATE;
typedef struct {
    LPCSTR szReader;
    LPVOID pvUserData;
    DWORD dwCurrentState;
    DWORD dwEventState;
    DWORD cbAtr;
    BYTE rgbAtr[36];
} SCARD_READERSTATEA;

typedef SCARD_READERSTATEA *LPSCARD_READERSTATEA;
typedef OPENCARDNAMEW OPENCARDNAME;
typedef OPENCARDNAMEW *POPENCARDNAMEW;
typedef POPENCARDNAMEW POPENCARDNAME;
typedef OPENCARDNAMEA *POPENCARDNAMEA;
typedef SCARDCONTEXT *PSCARDCONTEXT;
typedef SCARDHANDLE *PSCARDHANDLE;
typedef SCARD_READERSTATEW *PSCARD_READERSTATEW;
typedef PSCARD_READERSTATEW PSCARD_READERSTATE;
typedef SCARD_READERSTATEA *PSCARD_READERSTATEA;
typedef SCARD_READERSTATEW SCARD_READERSTATE;

#ifdef __cplusplus
}
#endif

#endif

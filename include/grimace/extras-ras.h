#ifndef GRIMACE_EXTRAS_RAS_H
#define GRIMACE_EXTRAS_RAS_H

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GRIMACE_VARSTRING
#define GRIMACE_VARSTRING
/**
 * This structure is used for returning variably sized strings. It is used
 * both by the line device class and the phone device class.
 *
 * No extensibility.
 *
 * If a string cannot be returned in a variable structure, the dwStringSize
 * and dwStringOffset members are set in one of these ways:
 *
 * dwStringSize and dwStringOffset members are both set to zero.
 *
 * dwStringOffset is nonzero and dwStringSize is zero.
 *
 * dwStringOffset is nonzero, dwStringSize is 1, and the byte at the given
 * offset is zero.
 */
typedef struct varstring_tag {
    /**
     * Specifies the total size, in bytes, allocated to
     * this data structure.
     */
    DWORD dwTotalSize;
    /**
     * Specifies the size, in bytes, for this data
     * structure that is needed to hold all the returned data.
     */
    DWORD dwNeededSize;
    /**
     * Specifies the size, in bytes, of the portion of this
     * data structure that contains useful data.
     */
    DWORD dwUsedSize;
    /**
     * Specifies the format of the string. This member
     * uses the following STRINGFORMAT_ constants: Value Description
     * STRINGFORMAT_ASCII ASCII string format using one byte per
     * character. The actual string is a NULL-terminated ASCII string
     * with the terminating NULL accounted for in the string size.
     * STRINGFORMAT_DBCS DBCS string format using one or two bytes per
     * character. STRINGFORMAT_UNICODE Unicode string format using two
     * bytes per character. STRINGFORMAT_BINARY An array of unsigned
     * characters that could be used for numeric values.
     */
    DWORD dwStringFormat;
    /**
     *
     */
    DWORD dwStringSize;
    /**
     * Specify the size, in bytes, of the variably sized
     * device field that contains the string data, and the offset, in
     * bytes, from the beginning of this data structure.
     */
    DWORD dwStringOffset;
} VARSTRING, *LPVARSTRING;
#endif

/**
 * Retrieves the TAPI device configuration saved for a phone-book entry
 * with RasSetEntryDevConfig.
 *
 * Call with pDeviceConfig NULL to get the size, allocate, then call again.
 * On Windows CE 2.0 and later, prefer RasGetEntryPropertiesW, which
 * returns the same configuration with the rest of the entry.
 *
 * @param szPhonebook Ignored; pass NULL. Entries are kept in the registry.
 * @param szEntry Name of an existing entry.
 * @param pdwDeviceID Receives the TAPI device identifier.
 * @param pdwSize In: size of pDeviceConfig. Out: size needed.
 * @param pDeviceConfig Receives the configuration, or NULL to query the
 *        size only.
 * @return 0 on success, or ERROR_CANNOT_OPEN_PHONEBOOK,
 *        ERROR_CANNOT_FIND_PHONEBOOK_ENTRY, ERROR_INVALID_PARAMETER or
 *        ERROR_BUFFER_TOO_SMALL.
 */
DWORD WINAPI RasGetEntryDevConfig(LPCWSTR szPhonebook, LPCWSTR szEntry, LPDWORD pdwDeviceID, LPDWORD pdwSize, LPVARSTRING pDeviceConfig);
/**
 * Saves the TAPI device configuration for a phone-book entry.
 *
 * On Windows CE 2.0 and later, prefer RasSetEntryPropertiesW, which can
 * set the same configuration with the rest of the entry.
 *
 * @param szPhonebook Ignored; pass NULL. Entries are kept in the registry.
 * @param szEntry Name of an existing entry.
 * @param dwDeviceID TAPI device identifier.
 * @param lpDeviceConfig Configuration to save, with dwNeededSize set, or
 *        NULL for the device's defaults.
 * @return 0 on success, or ERROR_CANNOT_OPEN_PHONEBOOK,
 *        ERROR_CANNOT_FIND_PHONEBOOK_ENTRY or ERROR_INVALID_PARAMETER.
 */
DWORD WINAPI RasSetEntryDevConfig(LPCWSTR szPhonebook, LPCWSTR szEntry, DWORD dwDeviceID, LPVARSTRING lpDeviceConfig);
/**
 * Ends a RAS connection.
 *
 * Alias of RasHangUp, kept for compatibility.
 *
 * @param Session The connection, from RasDial or RasEnumConnections.
 * @return 0 on success, or a RAS error code.
 */
DWORD WINAPI RasHangup(HRASCONN Session);

#define RASDT_Direct TEXT("direct")

#ifdef __cplusplus
}
#endif

#endif

#endif

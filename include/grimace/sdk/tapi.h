#ifndef GRIMACE_SDK_TAPI_H
#define GRIMACE_SDK_TAPI_H

#include <ras.h>

#ifdef __cplusplus
extern "C" {
#endif

struct HCALL__;
typedef const struct HCALL__ *HCALL;
/**
 * Accepts an offered call before answering it.
 *
 * The application must own the call. User-user data is optional and must
 * include its terminating null in `dwSize`; when the pointer is NULL,
 * `dwSize` is ignored. The request completes asynchronously.
 *
 * @param hCall Offered call handle.
 * @param lpsUserUserInfo Optional null-terminated user-user data.
 * @param dwSize User-user data size in bytes, including the terminator.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineAccept(HCALL hCall, LPCSTR lpsUserUserInfo, DWORD dwSize);
/**
 * Installs a telephony service provider.
 *
 * TAPI calls the provider's TSPI_lineGetProcTable export to retrieve its
 * function table; the provider need export only that entry point.
 *
 * @param lpszProviderFilename Path to the provider.
 * @param hwndOwner Owner window for installation dialogs, or NULL.
 * @param lpdwPermanentProviderID Receives the provider ID, or NULL.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 2.0 and later.
 */
LONG lineAddProvider(LPCWSTR lpszProviderFilename, HWND hwndOwner, LPDWORD lpdwPermanentProviderID);
/**
 * Adds a call to a conference call.
 *
 * The application must own both calls. The conference call must be on
 * hold or on hold pending conference; the added call must be connected,
 * on hold, proceeding or ringing. The request completes asynchronously.
 *
 * @param hConfCall Conference call handle.
 * @param hConsultCall Call to add to the conference.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineAddToConference(HCALL hConfCall, HCALL hConsultCall);
/**
 * Answers an offered call.
 *
 * The application must own the call. User-user data is optional and must
 * include its terminating null in `dwSize`; leave `dwSize` unused when
 * the data pointer is NULL. The request completes asynchronously.
 *
 * @param hCall Offered call handle.
 * @param lpsUserUserInfo Optional null-terminated user-user data.
 * @param dwSize User-user data size in bytes, including the terminator.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineAnswer(HCALL hCall, LPCSTR lpsUserUserInfo, DWORD dwSize);
/**
 * Transfers a call to a destination without creating a consultation call.
 *
 * The application must own a connected call. On completion the call
 * typically becomes idle; release its handle with lineDeallocateCall when
 * no longer needed. The request completes asynchronously.
 *
 * @param hCall Call to transfer.
 * @param lpszDestAddressW Destination address.
 * @param dwCountryCode Country or region code, or zero for the provider default.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineBlindTransfer(HCALL hCall, LPCWSTR lpszDestAddressW, DWORD dwCountryCode);
struct HLINE__;
typedef const struct HLINE__ *HLINE;
/**
 * Closes an open line device and invalidates its handle.
 *
 * Close or drop calls owned on the line first. Closing can revoke
 * ownership and drop calls that the application owns.
 *
 * @param hLine Open line handle to close.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineClose(HLINE hLine);
typedef HCALL *LPHCALL;
/**
 * Completes a transfer using a consultation call, or turns the calls into a conference.
 *
 * The application must own both calls. `hCall` must be on hold or
 * on-hold-pending-transfer; `hConsultCall` must be connected, ringing,
 * busy or proceeding. For LINETRANSFERMODE_CONFERENCE, `lphConfCall`
 * receives the new conference handle. The request completes asynchronously.
 *
 * @param hCall Call to transfer.
 * @param hConsultCall Call connected to the transfer destination.
 * @param lphConfCall Receives the conference handle for conference mode.
 * @param dwTransferMode LINETRANSFERMODE_TRANSFER or
 *         LINETRANSFERMODE_CONFERENCE.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineCompleteTransfer(HCALL hCall, HCALL hConsultCall, LPHCALL lphConfCall, DWORD dwTransferMode);
/**
 * Displays the provider's configuration dialog and returns edited settings.
 *
 * The opaque output can be passed to lineSetDevConfig. Set dwTotalSize in
 * lpDeviceConfigOut before the call; on LINEERR_STRUCTURETOOSMALL,
 * dwNeededSize reports the required size. Editing does not affect active
 * connections by itself.
 *
 * @param dwDeviceID Line device to configure.
 * @param hwndOwner Owner window for the dialog, or NULL.
 * @param lpszDeviceClass Device class to configure, or NULL for the top level.
 * @param lpDeviceConfigIn Existing opaque configuration data.
 * @param dwSize Size of lpDeviceConfigIn in bytes.
 * @param lpDeviceConfigOut Receives the edited configuration.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineConfigDialogEdit(DWORD dwDeviceID, HWND hwndOwner, LPCWSTR lpszDeviceClass, const LPVOID lpDeviceConfigIn, DWORD dwSize, LPVARSTRING lpDeviceConfigOut);
/**
 * Releases the application's handle and resources for a call.
 *
 * This does not change the physical call state. Deallocating the handle
 * also stops further LINE_REPLY processing for that call.
 *
 * @param hCall Call handle to release.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineDeallocateCall(HCALL hCall);
/**
 * Passes an opaque, provider-specific request to a line device.
 *
 * There is no portable meaning for the parameter block or result. Use this
 * only with documentation for the target provider; the CE TAPI reference
 * does not support standard TAPI extensions.
 *
 * @param hLine Line handle.
 * @param dwAddressID Address identifier, if required by the provider.
 * @param hCall Related call handle, if required by the provider.
 * @param lpParams Provider-specific input/output data.
 * @param dwSize Size of the data block in bytes.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineDevSpecific(HLINE hLine, DWORD dwAddressID, HCALL hCall, LPVOID lpParams, DWORD dwSize);
/**
 * Dials an address on an existing call.
 *
 * The application must own a call that is not idle or disconnected. A
 * positive return is an asynchronous request ID; call progress is reported
 * through TAPI messages. Dialing completes when the address is passed to
 * the provider, not when the call connects.
 *
 * @param hCall Call on which to dial.
 * @param lpszDestAddress Null-terminated dialable address.
 * @param dwCountryCode Country or region code, or zero for the provider default.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineDial(HCALL hCall, LPCWSTR lpszDestAddress, DWORD dwCountryCode);
/**
 * Drops or rejects a call owned by the application.
 *
 * Optionally sends user-to-user data during disconnect. The network is
 * not guaranteed to deliver that data. Dropping a conference call can
 * also affect its related calls.
 *
 * @param hCall Call to drop; it cannot be idle.
 * @param lpsUserUserInfo Optional data to send, or NULL.
 * @param dwSize Size of the user-user data in bytes.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineDrop(HCALL hCall, LPCSTR lpsUserUserInfo, DWORD dwSize);
struct lineforwardlist_tag;
typedef struct lineforwardlist_tag *LPLINEFORWARDLIST;
struct linecallparams_tag;
typedef struct linecallparams_tag *LPLINECALLPARAMS;
/**
 * Sets call-forwarding instructions for one or all addresses on a line.
 *
 * The request completes asynchronously; success means the provider
 * accepted the request, not that the switch has activated it. A
 * LINE_ADDRESSSTATE forwarding message reports switch confirmation. Pass
 * NULL for `lpForwardList` to cancel forwarding. `lphConsultCall` must be
 * valid even when no consultation call is created.
 *
 * @param hLine Open line handle.
 * @param bAllAddresses TRUE to forward all addresses; otherwise use `dwAddressID`.
 * @param dwAddressID Address to forward, ignored when `bAllAddresses` is TRUE.
 * @param lpForwardList Forwarding instructions, or NULL to cancel.
 * @param dwNumRingsNoAnswer Rings before applying no-answer forwarding.
 * @param lphConsultCall Receives a consultation call handle, or NULL if unused.
 * @param lpCallParams Optional parameters for a consultation call.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineForward(HLINE hLine, DWORD bAllAddresses, DWORD dwAddressID, const LPLINEFORWARDLIST lpForwardList, DWORD dwNumRingsNoAnswer, LPHCALL lphConsultCall, const LPLINECALLPARAMS lpCallParams);
/**
 * Initiates in-band digit generation on a call.
 *
 * This is for signaling over an established call, not ordinary call
 * dialing. Use one digit mode. A NULL digit string cancels active digit
 * generation; completion is reported by a LINE_GENERATE message.
 *
 * @param hCall Call on which to generate digits.
 * @param dwDigitMode Single LINEDIGITMODE_* value.
 * @param lpszDigits Null-terminated digits, or NULL to cancel.
 * @param dwDuration Digit and inter-digit duration in milliseconds, or zero
 *         for the default.
 * @return 0 when generation starts, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGenerateDigits(HCALL hCall, DWORD dwDigitMode, LPCWSTR lpszDigits, DWORD dwDuration);
struct linegeneratetone_tag;
typedef struct linegeneratetone_tag *LPLINEGENERATETONE;
/**
 * Initiates in-band tone generation on a call.
 *
 * Set one LINETONEMODE_* value; zero cancels tone generation. For
 * LINETONEMODE_CUSTOM, `lpTones` supplies the tone components. Completion
 * is reported by a LINE_GENERATE message.
 *
 * @param hCall Call on which to generate the tone.
 * @param dwToneMode Standard tone mode or LINETONEMODE_CUSTOM.
 * @param dwDuration Tone duration in milliseconds, or zero for the default.
 * @param dwNumTones Number of custom tone components.
 * @param lpTones Custom tone components, ignored for standard tones.
 * @return 0 when generation starts, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGenerateTone(HCALL hCall, DWORD dwToneMode, DWORD dwDuration, DWORD dwNumTones, const LPLINEGENERATETONE lpTones);
struct HLINEAPP__;
typedef const struct HLINEAPP__ *HLINEAPP;
struct lineaddresscaps_tag;
typedef struct lineaddresscaps_tag *LPLINEADDRESSCAPS;
/**
 * Retrieves the capabilities of an address on a line device.
 *
 * Set `lpAddressCaps->dwTotalSize` to the buffer size before calling.
 * Use the API version negotiated for the line; set `dwExtVersion` to zero
 * when not using provider-specific extensions.
 *
 * @param hLineApp TAPI application handle.
 * @param dwDeviceID Line device identifier.
 * @param dwAddressID Address identifier on the line.
 * @param dwAPIVersion Negotiated TAPI version.
 * @param dwExtVersion Provider-specific extension version, or zero.
 * @param lpAddressCaps Receives address capabilities.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetAddressCaps(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAddressID, DWORD dwAPIVersion, DWORD dwExtVersion, LPLINEADDRESSCAPS lpAddressCaps);
/**
 * Maps a dialable address to its address identifier on a line.
 *
 * Use LINEADDRESSMODE_DIALABLEADDR. `dwSize` includes the terminating
 * null character.
 *
 * @param hLine Open line handle.
 * @param lpdwAddressID Receives the address identifier.
 * @param dwAddressMode Must be LINEADDRESSMODE_DIALABLEADDR.
 * @param lpsAddress Null-terminated dialable address.
 * @param dwSize Address size in bytes, including the terminator.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetAddressID(HLINE hLine, LPDWORD lpdwAddressID, DWORD dwAddressMode, LPCWSTR lpsAddress, DWORD dwSize);
struct lineaddressstatus_tag;
typedef struct lineaddressstatus_tag *LPLINEADDRESSSTATUS;
/**
 * Retrieves the current status of an address on a line.
 *
 * Set `lpAddressStatus->dwTotalSize` to the buffer size before calling.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier.
 * @param lpAddressStatus Receives address status information.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetAddressStatus(HLINE hLine, DWORD dwAddressID, LPLINEADDRESSSTATUS lpAddressStatus);
struct lineextensionid_tag;
typedef struct lineextensionid_tag *LPLINEEXTENSIONID;
/**
 * Retrieves an application's position in the TAPI priority list.
 *
 * Specify one media mode, or zero to query MAKECALL request priority.
 * The extension ID and extension-name output are ignored. Priority zero
 * means the application is not in the stored priority list.
 *
 * @param lpszAppFilename Application executable name without a path.
 * @param dwMediaMode One LINEMEDIAMODE_* value, or zero for request mode.
 * @param lpExtensionID Ignored.
 * @param dwRequestMode LINEREQUESTMODE_MAKECALL when `dwMediaMode` is zero.
 * @param lpExtensionName Ignored.
 * @param lpdwPriority Receives the priority; one is highest.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetAppPriority(LPCWSTR lpszAppFilename, DWORD dwMediaMode, LPLINEEXTENSIONID lpExtensionID, DWORD dwRequestMode, LPVARSTRING lpExtensionName, LPDWORD lpdwPriority);
struct linecallinfo_tag;
typedef struct linecallinfo_tag *LPLINECALLINFO;
/**
 * Retrieves call-related information for a call in any state.
 *
 * Set `lpCallInfo->dwTotalSize` to the buffer size before calling. The
 * structure contains primarily fixed information about the call.
 *
 * @param hCall Call to query.
 * @param lpCallInfo Receives call information.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetCallInfo(HCALL hCall, LPLINECALLINFO lpCallInfo);
struct linecallstatus_tag;
typedef struct linecallstatus_tag *LPLINECALLSTATUS;
/**
 * Retrieves the current status of a call.
 *
 * Set `lpCallStatus->dwTotalSize` to the buffer size before calling.
 * The result includes the call state, state-specific details and
 * operations currently available for the call.
 *
 * @param hCall Call to query.
 * @param lpCallStatus Receives call status information.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetCallStatus(HCALL hCall, LPLINECALLSTATUS lpCallStatus);
struct linecalllist_tag;
typedef struct linecalllist_tag *LPLINECALLLIST;
/**
 * Retrieves the calls belonging to the same conference as a call.
 *
 * Set `lpCallList->dwTotalSize` to the buffer size before calling. The
 * first returned call is the conference call; remaining calls are
 * participants. Newly returned handles have monitor privilege.
 *
 * @param hCall Conference call or a conferenced participant call.
 * @param lpCallList Receives the conference and participant call handles.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetConfRelatedCalls(HCALL hCall, LPLINECALLLIST lpCallList);
struct linedevcaps_tag;
typedef struct linedevcaps_tag *LPLINEDEVCAPS;
/**
 * Retrieves the capabilities of a line device.
 *
 * Negotiate the TAPI version first. dwExtVersion is unsupported and must
 * be zero. Set dwTotalSize in lpLineDevCaps before calling; use the
 * returned address count to query each address with lineGetAddressCaps.
 *
 * @param hLineApp TAPI application handle.
 * @param dwDeviceID Line device identifier.
 * @param dwAPIVersion Negotiated TAPI version.
 * @param dwExtVersion Set to zero.
 * @param lpLineDevCaps Receives capabilities; set dwTotalSize first.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineGetDevCaps(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPIVersion, DWORD dwExtVersion, LPLINEDEVCAPS lpLineDevCaps);
/**
 * Retrieves the default opaque configuration for a line device.
 *
 * CE returns a default configuration. Treat the data as opaque: do not
 * modify it, and use lineSetDevConfig to restore it. Set dwTotalSize in
 * the VARSTRING before calling.
 *
 * @param dwDeviceID Line device identifier.
 * @param lpDeviceConfig Receives configuration in a VARSTRING.
 * @param lpszDeviceClass Device class whose configuration is requested.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineGetDevConfig(DWORD dwDeviceID, LPVARSTRING lpDeviceConfig, LPCWSTR lpszDeviceClass);
/**
 * Retrieves a line, address or call's device identifier for a device class.
 *
 * Set exactly one LINECALLSELECT_* flag in dwSelect and initialize the
 * output VARSTRING's dwTotalSize before calling.
 *
 * @param hLine Line handle when selecting a line or address.
 * @param dwAddressID Address identifier when selecting an address.
 * @param hCall Call handle when selecting a call.
 * @param dwSelect LINECALLSELECT_LINE, LINECALLSELECT_ADDRESS or LINECALLSELECT_CALL.
 * @param lpDeviceID Receives the device identifier in a VARSTRING.
 * @param lpszDeviceClass Device class name.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineGetID(HLINE hLine, DWORD dwAddressID, HCALL hCall, DWORD dwSelect, LPVARSTRING lpDeviceID, LPCWSTR lpszDeviceClass);
typedef HICON *LPHICON;
/**
 * Retrieves a provider-supplied icon for a line device.
 *
 * Set `lpszDeviceClass` to NULL or an empty string for the line icon. The
 * returned icon is owned by the provider; copy it if it must outlive the
 * provider resource.
 *
 * @param dwDeviceID Line device identifier.
 * @param lpszDeviceClass Optional device class name.
 * @param lphIcon Receives the icon handle.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetIcon(DWORD dwDeviceID, LPCWSTR lpszDeviceClass, LPHICON lphIcon);
struct linedevstatus_tag;
typedef struct linedevstatus_tag *LPLINEDEVSTATUS;
/**
 * Retrieves the current status of a line device.
 *
 * Set `lpLineDevStatus->dwTotalSize` to the buffer size before calling.
 * The result applies to the entire line; use lineGetAddressStatus for an
 * individual address.
 *
 * @param hLine Open line handle.
 * @param lpLineDevStatus Receives line status information.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetLineDevStatus(HLINE hLine, LPLINEDEVSTATUS lpLineDevStatus);
struct linemessage_tag;
typedef struct linemessage_tag *LPLINEMESSAGE;
LONG lineGetMessage(HLINEAPP hLineApp, LPLINEMESSAGE lpMessage, DWORD dwTimeout);
/**
 * Retrieves handles for calls the application does not already know about.
 *
 * Set `lpCallList->dwTotalSize` to the buffer size before calling. The
 * application receives monitor privilege to newly returned calls.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier when selecting by address.
 * @param dwSelect LINECALLSELECT_* scope for the requested calls.
 * @param lpCallList Receives the selected call handles.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetNewCalls(HLINE hLine, DWORD dwAddressID, DWORD dwSelect, LPLINECALLLIST lpCallList);
/**
 * Retrieves the minimum ring count requested by applications for an address.
 *
 * The value is informational; it does not change the call state. If no
 * application has set a ring count, the returned value is 0xFFFFFFFF.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier.
 * @param lpdwNumRings Receives the minimum requested ring count.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetNumRings(HLINE hLine, DWORD dwAddressID, LPDWORD lpdwNumRings);
struct lineproviderlist_tag;
typedef struct lineproviderlist_tag *LPLINEPROVIDERLIST;
/**
 * Retrieves the telephony service providers installed in the system.
 *
 * Set `lpProviderList->dwTotalSize` to the buffer size before calling.
 *
 * @param dwAPIVersion Highest TAPI version supported by the application.
 * @param lpProviderList Receives the provider list.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetProviderList(DWORD dwAPIVersion, LPLINEPROVIDERLIST lpProviderList);
/**
 * Retrieves which line and address status notifications are enabled.
 *
 * Status reporting is disabled by default; lineSetStatusMessages selects
 * which changes TAPI reports.
 *
 * @param hLine Line handle.
 * @param lpdwLineStates Receives enabled LINEDEVSTATE_* flags.
 * @param lpdwAddressStates Receives enabled LINEADDRESSSTATE_* flags.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineGetStatusMessages(HLINE hLine, LPDWORD lpdwLineStates, LPDWORD lpdwAddressStates);
struct linetranslatecaps_tag;
typedef struct linetranslatecaps_tag *LPLINETRANSLATECAPS;
/**
 * Retrieves TAPI address-translation capabilities.
 *
 * Set `dwTotalSize` in the LINETRANSLATECAPS structure to its buffer size
 * before calling. `hLineApp` may be NULL if lineInitialize has not been
 * called. OEM support may vary.
 *
 * @param hLineApp Application handle from lineInitialize, or NULL.
 * @param dwAPIVersion Highest TAPI version supported by the application.
 * @param lpTranslateCaps Receives the translation capabilities.
 * @return Zero on success, or a negative LINEERR_* value.
 */
LONG lineGetTranslateCaps(HLINEAPP hLineApp, DWORD dwAPIVersion, LPLINETRANSLATECAPS lpTranslateCaps);
/**
 * Hands ownership of a call to another application.
 *
 * Specify the target executable in `lpszFileName`, or set it to NULL to
 * select the highest-priority owner for `dwMediaMode`. This does not change
 * the call's media mode.
 *
 * @param hCall Call whose ownership to transfer.
 * @param lpszFileName Target application name without a path, or NULL.
 * @param dwMediaMode Single LINEMEDIAMODE_* value for indirect handoff.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineHandoff(HCALL hCall, LPCWSTR lpszFileName, DWORD dwMediaMode);
/**
 * Places a connected call on hold.
 *
 * This performs a hard hold, not a consultation call. The request
 * completes asynchronously; retrieve the call with lineUnhold.
 *
 * @param hCall Call to place on hold. The application must own it.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineHold(HCALL hCall);
typedef HLINEAPP *LPHLINEAPP;
typedef void (*LINECALLBACK)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
/**
 * Initializes TAPI and registers the application's callback.
 *
 * The callback receives line, address and call events. TAPI messages go
 * directly to this callback, so a UI thread must not block in GetMessage
 * waiting for a TAPI message; use Sleep(50) followed by PeekMessage.
 * Call lineShutdown when the application no longer uses TAPI.
 *
 * @param lphLineApp Receives the TAPI application handle.
 * @param hInstance Application or DLL instance.
 * @param lpfnCallback Callback for TAPI events.
 * @param lpszAppName Optional displayable ASCII application name, or NULL.
 * @param lpdwNumDevs Receives the number of line devices.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineInitialize(LPHLINEAPP lphLineApp, HINSTANCE hInstance, LINECALLBACK lpfnCallback, LPCWSTR lpszAppName, LPDWORD lpdwNumDevs);
struct lineinitializeexparams_tag;
typedef struct lineinitializeexparams_tag *LPLINEINITIALIZEEXPARAMS;
LONG lineInitializeEx(LPHLINEAPP lphLineApp, HINSTANCE hInstance, LINECALLBACK lpfnCallback, LPCWSTR lpszFriendlyAppName, LPDWORD lpdwNumDevs, LPDWORD lpdwAPIVersion, LPLINEINITIALIZEEXPARAMS lpLineInitializeExParams);
/**
 * Starts a call on a line to a destination address.
 *
 * The request is asynchronous. The call handle is valid after a successful
 * LINE_REPLY. With NULL lpCallParams, TAPI uses default voice-call
 * parameters. The address may be NULL for a non-dialed line.
 *
 * @param hLine Open line on which to place the call.
 * @param lphCall Receives the call handle after successful completion.
 * @param lpszDestAddress Dialable destination, or NULL for a non-dialed address.
 * @param dwCountryCode Destination country code, or 0 for the default.
 * @param lpCallParams Optional call setup parameters, or NULL for defaults.
 * @return Positive request ID for asynchronous completion, or a negative
 *         LINEERR_* code.
 */
LONG lineMakeCall(HLINE hLine, LPHCALL lphCall, LPCWSTR lpszDestAddress, DWORD dwCountryCode, const LPLINECALLPARAMS lpCallParams);
/**
 * Enables unbuffered detection of digits received on a call.
 *
 * Set `dwDigitModes` to zero to stop monitoring. Detected digits are
 * reported through LINE_MONITORDIGITS messages; monitoring ends when the
 * call becomes idle or its handle is deallocated.
 *
 * @param hCall Call to monitor; it cannot be idle or disconnected.
 * @param dwDigitModes LINEDIGITMODE_* flags to monitor.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineMonitorDigits(HCALL hCall, DWORD dwDigitModes);
/**
 * Enables detection of media types on a call.
 *
 * Set `dwMediaModes` to zero to stop monitoring. Detection is reported
 * through TAPI messages and does not change the call's media mode.
 *
 * @param hCall Call to monitor; it cannot be idle.
 * @param dwMediaModes LINEMEDIAMODE_* flags to detect, or zero to cancel.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineMonitorMedia(HCALL hCall, DWORD dwMediaModes);
/**
 * Negotiates a TAPI version supported by the application and line device.
 *
 * The selected version is within the requested range. Extensions are not
 * supported; set lpExtensionID to NULL.
 *
 * @param hLineApp TAPI application handle.
 * @param dwDeviceID Line device identifier.
 * @param dwAPILowVersion Lowest supported TAPI version.
 * @param dwAPIHighVersion Highest supported TAPI version.
 * @param lpdwAPIVersion Receives the negotiated version.
 * @param lpExtensionID Ignored; set to NULL.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineNegotiateAPIVersion(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPILowVersion, DWORD dwAPIHighVersion, LPDWORD lpdwAPIVersion, LPLINEEXTENSIONID lpExtensionID);
LONG lineNegotiateExtVersion(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPIVersion, DWORD dwExtLowVersion, DWORD dwExtHighVersion, LPDWORD lpdwExtVersion);
typedef HLINE *LPHLINE;
/**
 * Opens a line device and returns a handle for later line operations.
 *
 * Set dwExtVersion to zero. dwPrivileges selects outgoing-call-only,
 * monitor, owner, or monitor-and-owner access. dwMediaModes applies when
 * owner privilege is requested.
 *
 * @param hLineApp TAPI application handle.
 * @param dwDeviceID Line device identifier.
 * @param lphLine Receives the open line handle.
 * @param dwAPIVersion Version negotiated with lineNegotiateAPIVersion.
 * @param dwExtVersion Set to zero.
 * @param dwCallbackInstance Application data returned with TAPI messages.
 * @param dwPrivileges LINECALLPRIVILEGE_* access for calls.
 * @param dwMediaModes Media types the application can own.
 * @param lpCallParams Optional call parameters.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineOpen(HLINEAPP hLineApp, DWORD dwDeviceID, LPHLINE lphLine, DWORD dwAPIVersion, DWORD dwExtVersion, DWORD dwCallbackInstance, DWORD dwPrivileges, DWORD dwMediaModes, const LPLINECALLPARAMS lpCallParams);
/**
 * Picks up a call ringing at a destination address or within a group.
 *
 * The returned call handle is initially owned by the application. Set
 * `lpszDestAddress` to NULL for group pickup; some providers require a
 * group identifier. The request completes asynchronously.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier where pickup is initiated.
 * @param lphCall Receives the call handle.
 * @param lpszDestAddress Destination address, or NULL for group pickup.
 * @param lpszGroupID Optional pickup-group identifier.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG linePickup(HLINE hLine, DWORD dwAddressID, LPHCALL lphCall, LPCWSTR lpszDestAddress, LPCWSTR lpszGroupID);
/**
 * Prepares a conference call to add another party.
 *
 * The application must own a connected conference call. The request
 * typically places it on hold and creates a consultation call; add that
 * call with lineAddToConference. Set `lpCallParams` to NULL for defaults.
 *
 * @param hConfCall Connected conference call handle.
 * @param lphConsultCall Receives the consultation call handle.
 * @param lpCallParams Optional consultation-call parameters.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG linePrepareAddToConference(HCALL hConfCall, LPHCALL lphConsultCall, const LPLINECALLPARAMS lpCallParams);
/**
 * Redirects an offered call without answering it.
 *
 * The application must own the offered call. This redirects one call,
 * unlike lineForward, which configures forwarding at an address. The
 * request completes asynchronously.
 *
 * @param hCall Offered call to redirect.
 * @param lpszDestAddress Destination dialable address.
 * @param dwCountryCode Country or region code, or zero for the default.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineRedirect(HCALL hCall, LPCWSTR lpszDestAddress, DWORD dwCountryCode);
/**
 * Allows newer received user-user information to replace the current call information.
 *
 * Call this after processing the current user-user data from LINECALLINFO.
 * The application must own the call.
 *
 * @param hCall Call whose user-user information was processed.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineReleaseUserUserInfo(HCALL hCall);
/**
 * Removes a participant call from its conference.
 *
 * The application must own a call in the conferenced state. Whether the
 * participant remains usable after removal depends on the provider.
 * The request completes asynchronously.
 *
 * @param hCall Conferenced participant call to remove.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineRemoveFromConference(HCALL hCall);
/**
 * Sends user-user information to the remote party on a call.
 *
 * The application must own the call. Delivery depends on network support;
 * the protocol discriminator, if required, is part of the data buffer.
 * The request completes asynchronously.
 *
 * @param hCall Call on which to send the data.
 * @param lpsUserUserInfo User-user data buffer.
 * @param dwSize Data size in bytes.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSendUserUserInfo(HCALL hCall, LPCSTR lpsUserUserInfo, DWORD dwSize);
/**
 * Sets an application's TAPI handoff priority.
 *
 * Specify one media mode, or zero for LINEREQUESTMODE_MAKECALL. The
 * extension parameters are ignored. Set `dwPriority` to one for highest
 * priority or zero to remove the application from the list.
 *
 * @param lpszAppFilename Application executable name without a path.
 * @param dwMediaMode One LINEMEDIAMODE_* value, or zero for request mode.
 * @param lpExtensionID Ignored.
 * @param dwRequestMode LINEREQUESTMODE_MAKECALL when `dwMediaMode` is zero.
 * @param lpszExtensionName Ignored.
 * @param dwPriority One for highest priority, or zero to remove the entry.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetAppPriority(LPCWSTR lpszAppFilename, DWORD dwMediaMode, LPLINEEXTENSIONID lpExtensionID, DWORD dwRequestMode, LPCWSTR lpszExtensionName, DWORD dwPriority);
struct linedialparams_tag;
typedef struct linedialparams_tag *LPLINEDIALPARAMS;
/**
 * Changes the bearer mode or data-rate limits of an existing call.
 *
 * The application must own a call that is not idle or disconnected. Set
 * `dwMinRate` and `dwMaxRate` equal when an exact rate is required; pass
 * NULL for `lpDialParams` to retain the current dialing parameters. The
 * request completes asynchronously.
 *
 * @param hCall Call whose parameters to change.
 * @param dwBearerMode Single LINEBEARERMODE_* value.
 * @param dwMinRate Lowest acceptable data rate.
 * @param dwMaxRate Highest acceptable data rate.
 * @param lpDialParams Optional dialing parameters.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetCallParams(HCALL hCall, DWORD dwBearerMode, DWORD dwMinRate, DWORD dwMaxRate, const LPLINEDIALPARAMS lpDialParams);
/**
 * Changes the application's privilege for a call.
 *
 * Set one LINECALLPRIVILEGE_* value. An application cannot give up sole
 * ownership of an active call by switching directly to monitor privilege.
 *
 * @param hCall Call whose privilege to change.
 * @param dwCallPrivilege LINECALLPRIVILEGE_OWNER or LINECALLPRIVILEGE_MONITOR.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetCallPrivilege(HCALL hCall, DWORD dwCallPrivilege);
/**
 * Sets the current location used for address translation.
 *
 * dwLocation must be a permanent location ID returned by
 * lineGetTranslateCaps.
 *
 * @param hLineApp TAPI application handle, or NULL before initialization.
 * @param dwLocation Permanent location ID.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 2.0 and later.
 */
LONG lineSetCurrentLocation(HLINEAPP hLineApp, DWORD dwLocation);
/**
 * Applies opaque line-device configuration obtained with lineGetDevConfig.
 *
 * Do not inspect or modify the configuration data. It is generally valid
 * only for the device from which it was obtained.
 *
 * @param dwDeviceID Line device identifier.
 * @param lpDeviceConfig Opaque configuration data.
 * @param dwSize Configuration size in bytes.
 * @param lpszDeviceClass Device class name.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineSetDevConfig(DWORD dwDeviceID, const LPVOID lpDeviceConfig, DWORD dwSize, LPCWSTR lpszDeviceClass);
/**
 * Sets the media type associated with a call.
 *
 * The call may be in any state. Set a single media mode, unless
 * LINEMEDIAMODE_UNKNOWN is included to narrow the possible media types.
 *
 * @param hCall Call whose media type to change.
 * @param dwMediaModes LINEMEDIAMODE_* value or permitted combination.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetMediaMode(HCALL hCall, DWORD dwMediaModes);
/**
 * Sets the ring count this application requests before a call is answered.
 *
 * This is informational and does not change call state. lineGetNumRings
 * returns the minimum count requested by all applications.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier.
 * @param dwNumRings Requested ring count.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetNumRings(HLINE hLine, DWORD dwAddressID, DWORD dwNumRings);
/**
 * Selects line and address status changes reported to the application.
 *
 * Reporting is disabled by default. LINEDEVSTATE_REINIT notifications
 * cannot be masked.
 *
 * @param hLine Line device handle.
 * @param dwLineStates LINEDEVSTATE_* notifications to enable.
 * @param dwAddressStates LINEADDRESSSTATE_* notifications to enable.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineSetStatusMessages(HLINE hLine, DWORD dwLineStates, DWORD dwAddressStates);
/**
 * Routes low-level line events to or from a terminal device.
 *
 * `dwSelect` chooses line, address or call scope. The terminal ID and
 * supported modes are provider-defined; check lineGetDevCaps first. The
 * request completes asynchronously.
 *
 * @param hLine Open line handle.
 * @param dwAddressID Address identifier when selecting an address.
 * @param hCall Call handle when selecting a call.
 * @param dwSelect LINECALLSELECT_* scope.
 * @param dwTerminalModes LINETERMMODE_* event classes.
 * @param dwTerminalID Provider-defined terminal identifier.
 * @param bEnable TRUE to route events, FALSE to disable routing.
 * @return Positive request ID, or a negative LINEERR_* code.## lineHandoff(hCall, lpszFileName, dwMediaMode)
 * Hands ownership of a call to another application.
 *
 * Specify the target executable in `lpszFileName`, or set it to NULL to
 * select the highest-priority owner for `dwMediaMode`. This does not change
 * the call's media mode.
 *
 * @param hCall Call whose ownership to transfer.
 * @param lpszFileName Target application name without a path, or NULL.
 * @param dwMediaMode Single LINEMEDIAMODE_* value for indirect handoff.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetTerminal(HLINE hLine, DWORD dwAddressID, HCALL hCall, DWORD dwSelect, DWORD dwTerminalModes, DWORD dwTerminalID, DWORD bEnable);
/**
 * Manipulates the TAPI toll list for a line device.
 *
 * Use the LINETOLLLISTOPTION_* operation. The archived reference does not
 * describe the address string's exact format.
 *
 * @param hLineApp TAPI application handle, or zero before initialization.
 * @param dwDeviceID Line device whose dialing rules apply.
 * @param lpszAddressIn Address for the toll-list operation.
 * @param dwTollListOption LINETOLLLISTOPTION_* operation.
 * @return 0 on success, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetTollList(HLINEAPP hLineApp, DWORD dwDeviceID, LPCWSTR lpszAddressIn, DWORD dwTollListOption);
/**
 * Starts a conference and creates a consultation call for another party.
 *
 * Some providers require an existing connected call in `hCall`; others
 * allow `hCall` to be NULL and use `hLine`. On success, the output
 * parameters receive the conference and consultation handles. The request
 * completes asynchronously.
 *
 * @param hCall Existing connected call, or NULL when starting on a line.
 * @param hLine Line handle used when `hCall` is NULL.
 * @param lphConfCall Receives the conference call handle.
 * @param lphConsultCall Receives the consultation call handle.
 * @param dwNumParties Expected number of conference parties.
 * @param lpCallParams Optional consultation-call parameters.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetupConference(HCALL hCall, HLINE hLine, LPHCALL lphConfCall, LPHCALL lphConsultCall, DWORD dwNumParties, const LPLINECALLPARAMS lpCallParams);
/**
 * Starts a consultation transfer for a connected call.
 *
 * The call is typically placed on hold and a consultation call is created.
 * Complete the transfer with lineCompleteTransfer; pass NULL for default
 * consultation-call parameters. The request completes asynchronously.
 *
 * @param hCall Connected call to transfer; the application must own it.
 * @param lphConsultCall Receives the consultation call handle.
 * @param lpCallParams Optional consultation-call parameters.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSetupTransfer(HCALL hCall, LPHCALL lphConsultCall, const LPLINECALLPARAMS lpCallParams);
/**
 * Shuts down an application's TAPI session.
 *
 * The call handles are deleted, open lines are closed and outstanding
 * asynchronous requests are canceled. Close lines explicitly first when
 * practical.
 *
 * @param hLineApp TAPI application handle.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineShutdown(HLINEAPP hLineApp);
/**
 * Swaps an active call with a call on consultation hold.
 *
 * The application must own both calls. `hActiveCall` must be connected;
 * `hHeldCall` must be on hold, on-hold-pending-transfer or
 * on-hold-pending-conference. The request completes asynchronously.
 *
 * @param hActiveCall Connected call.
 * @param hHeldCall Held consultation call.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineSwapHold(HCALL hActiveCall, HCALL hHeldCall);
struct linetranslateoutput_tag;
typedef struct linetranslateoutput_tag *LPLINETRANSLATEOUTPUT;
/**
 * Translates an address into a dialable string for a line device.
 *
 * dwCard is unsupported and must be zero. Set dwTotalSize in the output
 * LINETRANSLATEOUTPUT before calling. FORCELOCAL can override a toll-list
 * classification when translating a local number.
 *
 * @param hLineApp TAPI application handle, or NULL before initialization.
 * @param dwDeviceID Line device identifier.
 * @param dwAPIVersion Highest TAPI version supported by the application.
 * @param lpszAddressIn Canonical address or dialable digits.
 * @param dwCard Unsupported; set to zero.
 * @param dwTranslateOptions LINETRANSLATEOPTION_* flags.
 * @param lpTranslateOutput Receives the translated address; set dwTotalSize first.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineTranslateAddress(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPIVersion, LPCWSTR lpszAddressIn, DWORD dwCard, DWORD dwTranslateOptions, LPLINETRANSLATEOUTPUT lpTranslateOutput);
/**
 * Displays a dialog for editing location and calling-card settings.
 *
 * After the dialog closes, call lineGetTranslateCaps to retrieve changes
 * and lineTranslateAddress to translate numbers with the new settings.
 *
 * @param hLineApp TAPI application handle.
 * @param dwDeviceID Line device identifier.
 * @param dwAPIVersion Highest TAPI version supported by the application.
 * @param hwndOwner Owner window for the dialog, or NULL.
 * @param lpszAddressIn Optional canonical number to preview, or NULL.
 * @return 0 on success, or a negative LINEERR_* code.
 */
LONG lineTranslateDialog(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPIVersion, HWND hwndOwner, LPCWSTR lpszAddressIn);
/**
 * Retrieves a call from hold.
 *
 * The application must own a call that is on hold,
 * on-hold-pending-transfer or on-hold-pending-conference. The request
 * completes asynchronously.
 *
 * @param hCall Call to retrieve.
 * @return Positive request ID, or a negative LINEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG lineUnhold(HCALL hCall);
struct HPHONE__;
typedef const struct HPHONE__ *HPHONE;
/**
 * Closes an open phone device and invalidates its handle.
 *
 * @param hPhone Open phone handle.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneClose(HPHONE hPhone);
/**
 * Displays the provider's configuration dialog for a phone device.
 *
 * Set `lpszDeviceClass` to NULL or an empty string for the top-level
 * configuration page.
 *
 * @param dwDeviceID Phone device identifier.
 * @param hwndOwner Owner window for the dialog, or NULL.
 * @param lpszDeviceClass Optional device class to configure.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneConfigDialog(DWORD dwDeviceID, HWND hwndOwner, LPCWSTR lpszDeviceClass);
/**
 * Passes an opaque, provider-specific request to a phone device.
 *
 * There is no portable meaning for the parameter block or result. Use this
 * only with documentation for the target provider.
 *
 * @param hPhone Phone handle.
 * @param lpParams Provider-specific input/output data.
 * @param dwSize Data block size, in bytes.
 * @return Positive request ID, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneDevSpecific(HPHONE hPhone, LPVOID lpParams, DWORD dwSize);
struct HPHONEAPP__;
typedef const struct HPHONEAPP__ *HPHONEAPP;
struct phonecaps_tag;
typedef struct phonecaps_tag *LPPHONECAPS;
/**
 * Retrieves the capabilities of a phone device.
 *
 * Negotiate the API version first. Set `lpPhoneCaps->dwTotalSize` to the
 * buffer size before calling. Use zero for `dwExtVersion` when not using
 * provider-specific extensions.
 *
 * @param hPhoneApp TAPI phone-application handle.
 * @param dwDeviceID Phone device identifier.
 * @param dwAPIVersion Negotiated API version.
 * @param dwExtVersion Extension version, or zero.
 * @param lpPhoneCaps Receives phone capabilities.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetDevCaps(HPHONEAPP hPhoneApp, DWORD dwDeviceID, DWORD dwAPIVersion, DWORD dwExtVersion, LPPHONECAPS lpPhoneCaps);
/**
 * Retrieves the microphone gain for a phone hookswitch device.
 *
 * Specify exactly one PHONEHOOKSWITCHDEV_* device. Gain ranges from zero
 * (silence) to 0xFFFF (maximum); the provider determines the granularity.
 *
 * @param hPhone Open phone handle.
 * @param dwHookSwitchDev Hookswitch device whose microphone gain to query.
 * @param lpdwGain Receives the gain value.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetGain(HPHONE hPhone, DWORD dwHookSwitchDev, LPDWORD lpdwGain);
/**
 * Retrieves which phone hookswitch devices are off-hook.
 *
 * The returned bit flags identify the handset, speaker or headset devices
 * that are off-hook.
 *
 * @param hPhone Open phone handle.
 * @param lpdwHookSwitchDevs Receives the off-hook device flags.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetHookSwitch(HPHONE hPhone, LPDWORD lpdwHookSwitchDevs);
/**
 * Retrieves a phone device identifier for a device class.
 *
 * Set `lpDeviceID->dwTotalSize` to the buffer size before calling. The
 * identifier format depends on the requested device class.
 *
 * @param hPhone Open phone handle.
 * @param lpDeviceID Receives the identifier in a VARSTRING.
 * @param lpszDeviceClass Device class whose identifier is requested.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetID(HPHONE hPhone, LPVARSTRING lpDeviceID, LPCWSTR lpszDeviceClass);
/**
 * Retrieves a provider-supplied icon for a phone device.
 *
 * Set `lpszDeviceClass` to NULL or an empty string for the phone icon.
 * The returned icon is owned by the provider; copy it if it must outlive
 * the provider resource.
 *
 * @param dwDeviceID Phone device identifier.
 * @param lpszDeviceClass Optional device class name.
 * @param lphIcon Receives the icon handle.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetIcon(DWORD dwDeviceID, LPCWSTR lpszDeviceClass, LPHICON lphIcon);
struct phonemessage_tag;
typedef struct phonemessage_tag *LPPHONEMESSAGE;
LONG phoneGetMessage(HPHONEAPP hPhoneApp, LPPHONEMESSAGE lpMessage, DWORD dwTimeout);
/**
 * Retrieves the current ringer mode and volume.
 *
 * Ring mode zero indicates that the phone is not ringing. Volume ranges
 * from zero (silence) to 0xFFFF (maximum); the provider determines the
 * granularity.
 *
 * @param hPhone Open phone handle.
 * @param lpdwRingMode Receives the ring mode.
 * @param lpdwVolume Receives the ringer volume.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetRing(HPHONE hPhone, LPDWORD lpdwRingMode, LPDWORD lpdwVolume);
struct phonestatus_tag;
typedef struct phonestatus_tag *LPPHONESTATUS;
/**
 * Retrieves the current status of an open phone device.
 *
 * Set `lpPhoneStatus->dwTotalSize` to the buffer size before calling.
 * The status includes hookswitch devices, ringer, volume, display and lamps.
 *
 * @param hPhone Open phone handle.
 * @param lpPhoneStatus Receives the phone status.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetStatus(HPHONE hPhone, LPPHONESTATUS lpPhoneStatus);
/**
 * Retrieves which phone and button events are enabled for notification.
 *
 * @param hPhone Open phone handle.
 * @param lpdwPhoneStates Receives enabled PHONESTATE_* flags.
 * @param lpdwButtonModes Receives enabled PHONEBUTTONMODE_* flags.
 * @param lpdwButtonStates Receives enabled PHONEBUTTONSTATE_* flags.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetStatusMessages(HPHONE hPhone, LPDWORD lpdwPhoneStates, LPDWORD lpdwButtonModes, LPDWORD lpdwButtonStates);
/**
 * Retrieves the speaker volume for a phone hookswitch device.
 *
 * Volume ranges from zero (silence) to 0xFFFF (maximum); the provider
 * determines the granularity.
 *
 * @param hPhone Open phone handle.
 * @param dwHookSwitchDev Hookswitch device to query.
 * @param lpdwVolume Receives the volume level.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneGetVolume(HPHONE hPhone, DWORD dwHookSwitchDev, LPDWORD lpdwVolume);
typedef HPHONEAPP *LPHPHONEAPP;
typedef void (*PHONECALLBACK)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
struct phoneinitializeexparams_tag;
typedef struct phoneinitializeexparams_tag *LPPHONEINITIALIZEEXPARAMS;
LONG phoneInitializeEx(LPHPHONEAPP lphPhoneApp, HINSTANCE hInstance, PHONECALLBACK lpfnCallback, LPCWSTR lpszFriendlyAppName, LPDWORD lpdwNumDevs, LPDWORD lpdwAPIVersion, LPPHONEINITIALIZEEXPARAMS lpPhoneInitializeExParams);
struct phoneextensionid_tag;
typedef struct phoneextensionid_tag *LPPHONEEXTENSIONID;
/**
 * Negotiates a TAPI API version supported by a phone device.
 *
 * The selected version is within the requested range. The extension
 * identifier is returned for compatibility; CE TAPI extensions are not
 * supported by the current SDK documentation.
 *
 * @param hPhoneApp TAPI phone-application handle.
 * @param dwDeviceID Phone device identifier.
 * @param dwAPILowVersion Lowest API version supported by the application.
 * @param dwAPIHighVersion Highest API version supported by the application.
 * @param lpdwAPIVersion Receives the negotiated version.
 * @param lpExtensionID Receives the device extension identifier.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneNegotiateAPIVersion(HPHONEAPP hPhoneApp, DWORD dwDeviceID, DWORD dwAPILowVersion, DWORD dwAPIHighVersion, LPDWORD lpdwAPIVersion, LPPHONEEXTENSIONID lpExtensionID);
LONG phoneNegotiateExtVersion(HPHONEAPP hPhoneApp, DWORD dwDeviceID, DWORD dwAPIVersion, DWORD dwExtLowVersion, DWORD dwExtHighVersion, LPDWORD lpdwExtVersion);
typedef HPHONE *LPHPHONE;
/**
 * Opens a phone device for control or status monitoring.
 *
 * Only one application can open a device with owner privilege at a time;
 * multiple applications can monitor it. Set `dwExtVersion` to zero.
 *
 * @param hPhoneApp TAPI phone-application handle.
 * @param dwDeviceID Phone device identifier.
 * @param lphPhone Receives the open phone handle.
 * @param dwAPIVersion Negotiated API version.
 * @param dwExtVersion Set to zero.
 * @param dwCallbackInstance Application value passed with phone messages.
 * @param dwPrivilege PHONEPRIVILEGE_OWNER or PHONEPRIVILEGE_MONITOR.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneOpen(HPHONEAPP hPhoneApp, DWORD dwDeviceID, LPHPHONE lphPhone, DWORD dwAPIVersion, DWORD dwExtVersion, DWORD dwCallbackInstance, DWORD dwPrivilege);
/**
 * Sets the microphone gain for a phone hookswitch device.
 *
 * Specify exactly one PHONEHOOKSWITCHDEV_* device. Gain ranges from zero
 * (silence) to 0xFFFF (maximum); out-of-range values are clamped and the
 * provider determines the granularity. The request completes asynchronously.
 *
 * @param hPhone Open phone handle.
 * @param dwHookSwitchDev Hookswitch device whose microphone gain to set.
 * @param dwGain Gain value from zero to 0xFFFF.
 * @return Positive request ID, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneSetGain(HPHONE hPhone, DWORD dwHookSwitchDev, DWORD dwGain);
/**
 * Sets the hookswitch mode for one or more phone devices.
 *
 * The application must own the phone. One hookswitch mode is applied to
 * all selected devices; changes are reported in PHONE_STATE messages.
 *
 * @param hPhone Open phone handle.
 * @param dwHookSwitchDevs PHONEHOOKSWITCHDEV_* device flags.
 * @param dwHookSwitchMode PHONEHOOKSWITCHMODE_* value.
 * @return Positive request ID, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneSetHookSwitch(HPHONE hPhone, DWORD dwHookSwitchDevs, DWORD dwHookSwitchMode);
/**
 * Sets the ringer mode and volume for an open phone device.
 *
 * Ring mode must be supported by the device; query `dwNumRingModes` in
 * PHONECAPS. Volume ranges from zero (silence) to 0xFFFF (maximum); the
 * provider determines the pattern and granularity.
 *
 * @param hPhone Open phone handle; the application must own it.
 * @param dwRingMode Supported ring mode, or zero for silence where allowed.
 * @param dwVolume Ringer volume from zero to 0xFFFF.
 * @return Positive request ID, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneSetRing(HPHONE hPhone, DWORD dwRingMode, DWORD dwVolume);
/**
 * Selects phone and button events reported to the application.
 *
 * All phone status messages are disabled by default. If button modes are
 * selected, at least one button state must also be selected.
 *
 * @param hPhone Open phone handle.
 * @param dwPhoneStates PHONESTATE_* events to enable.
 * @param dwButtonModes PHONEBUTTONMODE_* events to enable.
 * @param dwButtonStates PHONEBUTTONSTATE_* events to enable.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneSetStatusMessages(HPHONE hPhone, DWORD dwPhoneStates, DWORD dwButtonModes, DWORD dwButtonStates);
/**
 * Sets the speaker volume for a phone hookswitch device.
 *
 * The application must own the phone. Volume ranges from zero (silence)
 * to 0xFFFF (maximum); out-of-range values are clamped and the provider
 * determines the granularity. The request completes asynchronously.
 *
 * @param hPhone Open phone handle.
 * @param dwHookSwitchDev Hookswitch device whose speaker volume to set.
 * @param dwVolume Volume level from zero to 0xFFFF.
 * @return Positive request ID, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneSetVolume(HPHONE hPhone, DWORD dwHookSwitchDev, DWORD dwVolume);
/**
 * Shuts down a phone application's TAPI session.
 *
 * Any phone devices still open are closed.
 *
 * @param hPhoneApp TAPI phone-application handle.
 * @return 0 on success, or a negative PHONEERR_* code.
 *
 * @note Windows CE 3.0 and later.
 */
LONG phoneShutdown(HPHONEAPP hPhoneApp);
typedef struct lineaddresscaps_tag LINEADDRESSCAPS;
typedef struct lineaddressstatus_tag LINEADDRESSSTATUS;
typedef struct linecallinfo_tag LINECALLINFO;
typedef struct linecalllist_tag LINECALLLIST;
typedef struct linecallparams_tag LINECALLPARAMS;
typedef struct linecallstatus_tag LINECALLSTATUS;
struct linecalltreatmententry_tag;
typedef struct linecalltreatmententry_tag LINECALLTREATMENTENTRY;
struct linecardentry_tag;
typedef struct linecardentry_tag LINECARDENTRY;
struct linecountryentry_tag;
typedef struct linecountryentry_tag LINECOUNTRYENTRY;
struct linecountrylist_tag;
typedef struct linecountrylist_tag LINECOUNTRYLIST;
typedef struct linedevcaps_tag LINEDEVCAPS;
typedef struct linedevstatus_tag LINEDEVSTATUS;
typedef struct linedialparams_tag LINEDIALPARAMS;
typedef struct lineextensionid_tag LINEEXTENSIONID;
struct lineforward_tag;
typedef struct lineforward_tag LINEFORWARD;
typedef struct lineforwardlist_tag LINEFORWARDLIST;
typedef struct linegeneratetone_tag LINEGENERATETONE;
typedef struct lineinitializeexparams_tag LINEINITIALIZEEXPARAMS;
struct linelocationentry_tag;
typedef struct linelocationentry_tag LINELOCATIONENTRY;
struct linemediacontrolcallstate_tag;
typedef struct linemediacontrolcallstate_tag LINEMEDIACONTROLCALLSTATE;
struct linemediacontroldigit_tag;
typedef struct linemediacontroldigit_tag LINEMEDIACONTROLDIGIT;
struct linemediacontrolmedia_tag;
typedef struct linemediacontrolmedia_tag LINEMEDIACONTROLMEDIA;
struct linemediacontroltone_tag;
typedef struct linemediacontroltone_tag LINEMEDIACONTROLTONE;
typedef struct linemessage_tag LINEMESSAGE;
struct linemonitortone_tag;
typedef struct linemonitortone_tag LINEMONITORTONE;
struct lineproviderentry_tag;
typedef struct lineproviderentry_tag LINEPROVIDERENTRY;
typedef struct lineproviderlist_tag LINEPROVIDERLIST;
struct linetermcaps_tag;
typedef struct linetermcaps_tag LINETERMCAPS;
typedef struct linetranslatecaps_tag LINETRANSLATECAPS;
typedef struct linetranslateoutput_tag LINETRANSLATEOUTPUT;
typedef struct linecalltreatmententry_tag *LPLINECALLTREATMENTENTRY;
typedef struct linecardentry_tag *LPLINECARDENTRY;
typedef struct linecountryentry_tag *LPLINECOUNTRYENTRY;
typedef struct linecountrylist_tag *LPLINECOUNTRYLIST;
typedef struct lineforward_tag *LPLINEFORWARD;
typedef struct linelocationentry_tag *LPLINELOCATIONENTRY;
typedef struct linemediacontrolcallstate_tag *LPLINEMEDIACONTROLCALLSTATE;
typedef struct linemediacontroldigit_tag *LPLINEMEDIACONTROLDIGIT;
typedef struct linemediacontrolmedia_tag *LPLINEMEDIACONTROLMEDIA;
typedef struct linemediacontroltone_tag *LPLINEMEDIACONTROLTONE;
typedef struct linemonitortone_tag *LPLINEMONITORTONE;
typedef struct lineproviderentry_tag *LPLINEPROVIDERENTRY;
typedef struct linetermcaps_tag *LPLINETERMCAPS;
struct phonebuttoninfo_tag;
typedef struct phonebuttoninfo_tag *LPPHONEBUTTONINFO;
typedef struct phonebuttoninfo_tag PHONEBUTTONINFO;
typedef struct phonecaps_tag PHONECAPS;
typedef struct phoneextensionid_tag PHONEEXTENSIONID;
typedef struct phoneinitializeexparams_tag PHONEINITIALIZEEXPARAMS;
typedef struct phonemessage_tag PHONEMESSAGE;
typedef struct phonestatus_tag PHONESTATUS;
struct HCALL__ {
    int unused;
} __attribute__((packed, aligned(1)));

struct HLINEAPP__ {
    int unused;
} __attribute__((packed, aligned(1)));

struct HLINE__ {
    int unused;
} __attribute__((packed, aligned(1)));

struct HPHONEAPP__ {
    int unused;
} __attribute__((packed, aligned(1)));

struct HPHONE__ {
    int unused;
} __attribute__((packed, aligned(1)));

struct lineaddresscaps_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwLineDeviceID;
    DWORD dwAddressSize;
    DWORD dwAddressOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwAddressSharing;
    DWORD dwAddressStates;
    DWORD dwCallInfoStates;
    DWORD dwCallerIDFlags;
    DWORD dwCalledIDFlags;
    DWORD dwConnectedIDFlags;
    DWORD dwRedirectionIDFlags;
    DWORD dwRedirectingIDFlags;
    DWORD dwCallStates;
    DWORD dwDialToneModes;
    DWORD dwBusyModes;
    DWORD dwSpecialInfo;
    DWORD dwDisconnectModes;
    DWORD dwMaxNumActiveCalls;
    DWORD dwMaxNumOnHoldCalls;
    DWORD dwMaxNumOnHoldPendingCalls;
    DWORD dwMaxNumConference;
    DWORD dwMaxNumTransConf;
    DWORD dwAddrCapFlags;
    DWORD dwCallFeatures;
    DWORD dwRemoveFromConfCaps;
    DWORD dwRemoveFromConfState;
    DWORD dwTransferModes;
    DWORD dwParkModes;
    DWORD dwForwardModes;
    DWORD dwMaxForwardEntries;
    DWORD dwMaxSpecificEntries;
    DWORD dwMinFwdNumRings;
    DWORD dwMaxFwdNumRings;
    DWORD dwMaxCallCompletions;
    DWORD dwCallCompletionConds;
    DWORD dwCallCompletionModes;
    DWORD dwNumCompletionMessages;
    DWORD dwCompletionMsgTextEntrySize;
    DWORD dwCompletionMsgTextSize;
    DWORD dwCompletionMsgTextOffset;
    DWORD dwAddressFeatures;
    DWORD dwPredictiveAutoTransferStates;
    DWORD dwNumCallTreatments;
    DWORD dwCallTreatmentListSize;
    DWORD dwCallTreatmentListOffset;
    DWORD dwDeviceClassesSize;
    DWORD dwDeviceClassesOffset;
    DWORD dwMaxCallDataSize;
    DWORD dwCallFeatures2;
    DWORD dwMaxNoAnswerTimeout;
    DWORD dwConnectedModes;
    DWORD dwOfferingModes;
    DWORD dwAvailableMediaModes;
} __attribute__((packed, aligned(1)));

struct lineaddressstatus_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwNumInUse;
    DWORD dwNumActiveCalls;
    DWORD dwNumOnHoldCalls;
    DWORD dwNumOnHoldPendCalls;
    DWORD dwAddressFeatures;
    DWORD dwNumRingsNoAnswer;
    DWORD dwForwardNumEntries;
    DWORD dwForwardSize;
    DWORD dwForwardOffset;
    DWORD dwTerminalModesSize;
    DWORD dwTerminalModesOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
} __attribute__((packed, aligned(1)));

struct linedialparams_tag {
    DWORD dwDialPause;
    DWORD dwDialSpeed;
    DWORD dwDigitDuration;
    DWORD dwWaitForDialtone;
} __attribute__((packed, aligned(1)));

struct linecallinfo_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    HLINE hLine;
    DWORD dwLineDeviceID;
    DWORD dwAddressID;
    DWORD dwBearerMode;
    DWORD dwRate;
    DWORD dwMediaMode;
    DWORD dwAppSpecific;
    DWORD dwCallID;
    DWORD dwRelatedCallID;
    DWORD dwCallParamFlags;
    DWORD dwCallStates;
    DWORD dwMonitorDigitModes;
    DWORD dwMonitorMediaModes;
    LINEDIALPARAMS DialParams;
    DWORD dwOrigin;
    DWORD dwReason;
    DWORD dwCompletionID;
    DWORD dwNumOwners;
    DWORD dwNumMonitors;
    DWORD dwCountryCode;
    DWORD dwTrunk;
    DWORD dwCallerIDFlags;
    DWORD dwCallerIDSize;
    DWORD dwCallerIDOffset;
    DWORD dwCallerIDNameSize;
    DWORD dwCallerIDNameOffset;
    DWORD dwCalledIDFlags;
    DWORD dwCalledIDSize;
    DWORD dwCalledIDOffset;
    DWORD dwCalledIDNameSize;
    DWORD dwCalledIDNameOffset;
    DWORD dwConnectedIDFlags;
    DWORD dwConnectedIDSize;
    DWORD dwConnectedIDOffset;
    DWORD dwConnectedIDNameSize;
    DWORD dwConnectedIDNameOffset;
    DWORD dwRedirectionIDFlags;
    DWORD dwRedirectionIDSize;
    DWORD dwRedirectionIDOffset;
    DWORD dwRedirectionIDNameSize;
    DWORD dwRedirectionIDNameOffset;
    DWORD dwRedirectingIDFlags;
    DWORD dwRedirectingIDSize;
    DWORD dwRedirectingIDOffset;
    DWORD dwRedirectingIDNameSize;
    DWORD dwRedirectingIDNameOffset;
    DWORD dwAppNameSize;
    DWORD dwAppNameOffset;
    DWORD dwDisplayableAddressSize;
    DWORD dwDisplayableAddressOffset;
    DWORD dwCalledPartySize;
    DWORD dwCalledPartyOffset;
    DWORD dwCommentSize;
    DWORD dwCommentOffset;
    DWORD dwDisplaySize;
    DWORD dwDisplayOffset;
    DWORD dwUserUserInfoSize;
    DWORD dwUserUserInfoOffset;
    DWORD dwHighLevelCompSize;
    DWORD dwHighLevelCompOffset;
    DWORD dwLowLevelCompSize;
    DWORD dwLowLevelCompOffset;
    DWORD dwChargingInfoSize;
    DWORD dwChargingInfoOffset;
    DWORD dwTerminalModesSize;
    DWORD dwTerminalModesOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwCallTreatment;
    DWORD dwCallDataSize;
    DWORD dwCallDataOffset;
    DWORD dwSendingFlowspecSize;
    DWORD dwSendingFlowspecOffset;
    DWORD dwReceivingFlowspecSize;
    DWORD dwReceivingFlowspecOffset;
    DWORD dwAddressType;
} __attribute__((packed, aligned(1)));

struct linecalllist_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwCallsNumEntries;
    DWORD dwCallsSize;
    DWORD dwCallsOffset;
} __attribute__((packed, aligned(1)));

struct linecallparams_tag {
    DWORD dwTotalSize;
    DWORD dwBearerMode;
    DWORD dwMinRate;
    DWORD dwMaxRate;
    DWORD dwMediaMode;
    DWORD dwCallParamFlags;
    DWORD dwAddressMode;
    DWORD dwAddressID;
    LINEDIALPARAMS DialParams;
    DWORD dwOrigAddressSize;
    DWORD dwOrigAddressOffset;
    DWORD dwDisplayableAddressSize;
    DWORD dwDisplayableAddressOffset;
    DWORD dwCalledPartySize;
    DWORD dwCalledPartyOffset;
    DWORD dwCommentSize;
    DWORD dwCommentOffset;
    DWORD dwUserUserInfoSize;
    DWORD dwUserUserInfoOffset;
    DWORD dwHighLevelCompSize;
    DWORD dwHighLevelCompOffset;
    DWORD dwLowLevelCompSize;
    DWORD dwLowLevelCompOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwPredictiveAutoTransferStates;
    DWORD dwTargetAddressSize;
    DWORD dwTargetAddressOffset;
    DWORD dwSendingFlowspecSize;
    DWORD dwSendingFlowspecOffset;
    DWORD dwReceivingFlowspecSize;
    DWORD dwReceivingFlowspecOffset;
    DWORD dwDeviceClassSize;
    DWORD dwDeviceClassOffset;
    DWORD dwDeviceConfigSize;
    DWORD dwDeviceConfigOffset;
    DWORD dwCallDataSize;
    DWORD dwCallDataOffset;
    DWORD dwNoAnswerTimeout;
    DWORD dwCallingPartyIDSize;
    DWORD dwCallingPartyIDOffset;
    DWORD dwAddressType;
} __attribute__((packed, aligned(1)));

struct linecallstatus_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwCallState;
    DWORD dwCallStateMode;
    DWORD dwCallPrivilege;
    DWORD dwCallFeatures;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwCallFeatures2;
    SYSTEMTIME tStateEntryTime;
} __attribute__((packed, aligned(1)));

struct linecalltreatmententry_tag {
    DWORD dwCallTreatmentID;
    DWORD dwCallTreatmentNameSize;
    DWORD dwCallTreatmentNameOffset;
} __attribute__((packed, aligned(1)));

struct linecardentry_tag {
    DWORD dwPermanentCardID;
    DWORD dwCardNameSize;
    DWORD dwCardNameOffset;
    DWORD dwCardNumberDigits;
    DWORD dwSameAreaRuleSize;
    DWORD dwSameAreaRuleOffset;
    DWORD dwLongDistanceRuleSize;
    DWORD dwLongDistanceRuleOffset;
    DWORD dwInternationalRuleSize;
    DWORD dwInternationalRuleOffset;
    DWORD dwOptions;
} __attribute__((packed, aligned(1)));

struct linecountryentry_tag {
    DWORD dwCountryID;
    DWORD dwCountryCode;
    DWORD dwNextCountryID;
    DWORD dwCountryNameSize;
    DWORD dwCountryNameOffset;
    DWORD dwSameAreaRuleSize;
    DWORD dwSameAreaRuleOffset;
    DWORD dwLongDistanceRuleSize;
    DWORD dwLongDistanceRuleOffset;
    DWORD dwInternationalRuleSize;
    DWORD dwInternationalRuleOffset;
} __attribute__((packed, aligned(1)));

struct linecountrylist_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwNumCountries;
    DWORD dwCountryListSize;
    DWORD dwCountryListOffset;
} __attribute__((packed, aligned(1)));

struct linedevcaps_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwProviderInfoSize;
    DWORD dwProviderInfoOffset;
    DWORD dwSwitchInfoSize;
    DWORD dwSwitchInfoOffset;
    DWORD dwPermanentLineID;
    DWORD dwLineNameSize;
    DWORD dwLineNameOffset;
    DWORD dwStringFormat;
    DWORD dwAddressModes;
    DWORD dwNumAddresses;
    DWORD dwBearerModes;
    DWORD dwMaxRate;
    DWORD dwMediaModes;
    DWORD dwGenerateToneModes;
    DWORD dwGenerateToneMaxNumFreq;
    DWORD dwGenerateDigitModes;
    DWORD dwMonitorToneMaxNumFreq;
    DWORD dwMonitorToneMaxNumEntries;
    DWORD dwMonitorDigitModes;
    DWORD dwGatherDigitsMinTimeout;
    DWORD dwGatherDigitsMaxTimeout;
    DWORD dwMedCtlDigitMaxListSize;
    DWORD dwMedCtlMediaMaxListSize;
    DWORD dwMedCtlToneMaxListSize;
    DWORD dwMedCtlCallStateMaxListSize;
    DWORD dwDevCapFlags;
    DWORD dwMaxNumActiveCalls;
    DWORD dwAnswerMode;
    DWORD dwRingModes;
    DWORD dwLineStates;
    DWORD dwUUIAcceptSize;
    DWORD dwUUIAnswerSize;
    DWORD dwUUIMakeCallSize;
    DWORD dwUUIDropSize;
    DWORD dwUUISendUserUserInfoSize;
    DWORD dwUUICallInfoSize;
    LINEDIALPARAMS MinDialParams;
    LINEDIALPARAMS MaxDialParams;
    LINEDIALPARAMS DefaultDialParams;
    DWORD dwNumTerminals;
    DWORD dwTerminalCapsSize;
    DWORD dwTerminalCapsOffset;
    DWORD dwTerminalTextEntrySize;
    DWORD dwTerminalTextSize;
    DWORD dwTerminalTextOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwLineFeatures;
    DWORD dwSettableDevStatus;
    DWORD dwDeviceClassesSize;
    DWORD dwDeviceClassesOffset;
    GUID PermanentLineGuid;
    DWORD dwAddressTypes;
    GUID ProtocolGuid;
    DWORD dwAvailableTracking;
} __attribute__((packed, aligned(1)));

struct linedevstatus_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwNumOpens;
    DWORD dwOpenMediaModes;
    DWORD dwNumActiveCalls;
    DWORD dwNumOnHoldCalls;
    DWORD dwNumOnHoldPendCalls;
    DWORD dwLineFeatures;
    DWORD dwNumCallCompletions;
    DWORD dwRingMode;
    DWORD dwSignalLevel;
    DWORD dwBatteryLevel;
    DWORD dwRoamMode;
    DWORD dwDevStatusFlags;
    DWORD dwTerminalModesSize;
    DWORD dwTerminalModesOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwAvailableMediaModes;
    DWORD dwAppInfoSize;
    DWORD dwAppInfoOffset;
} __attribute__((packed, aligned(1)));

struct lineextensionid_tag {
    DWORD dwExtensionID0;
    DWORD dwExtensionID1;
    DWORD dwExtensionID2;
    DWORD dwExtensionID3;
} __attribute__((packed, aligned(1)));

struct lineforward_tag {
    DWORD dwForwardMode;
    DWORD dwCallerAddressSize;
    DWORD dwCallerAddressOffset;
    DWORD dwDestCountryCode;
    DWORD dwDestAddressSize;
    DWORD dwDestAddressOffset;
} __attribute__((packed, aligned(1)));

struct lineforwardlist_tag {
    DWORD dwTotalSize;
    DWORD dwNumEntries;
    LINEFORWARD ForwardList[1];
} __attribute__((packed, aligned(1)));

struct linegeneratetone_tag {
    DWORD dwFrequency;
    DWORD dwCadenceOn;
    DWORD dwCadenceOff;
    DWORD dwVolume;
} __attribute__((packed, aligned(1)));

struct lineinitializeexparams_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwOptions;
    union {
        HANDLE hEvent;
        HANDLE hCompletionPort;
    } Handles;
    DWORD dwCompletionKey;
} __attribute__((packed, aligned(1)));

struct linelocationentry_tag {
    DWORD dwPermanentLocationID;
    DWORD dwLocationNameSize;
    DWORD dwLocationNameOffset;
    DWORD dwCountryCode;
    DWORD dwCityCodeSize;
    DWORD dwCityCodeOffset;
    DWORD dwPreferredCardID;
    DWORD dwLocalAccessCodeSize;
    DWORD dwLocalAccessCodeOffset;
    DWORD dwLongDistanceAccessCodeSize;
    DWORD dwLongDistanceAccessCodeOffset;
    DWORD dwTollPrefixListSize;
    DWORD dwTollPrefixListOffset;
    DWORD dwCountryID;
    DWORD dwOptions;
    DWORD dwCancelCallWaitingSize;
    DWORD dwCancelCallWaitingOffset;
} __attribute__((packed, aligned(1)));

struct linemediacontrolcallstate_tag {
    DWORD dwCallStates;
    DWORD dwMediaControl;
} __attribute__((packed, aligned(1)));

struct linemediacontroldigit_tag {
    DWORD dwDigit;
    DWORD dwDigitModes;
    DWORD dwMediaControl;
} __attribute__((packed, aligned(1)));

struct linemediacontrolmedia_tag {
    DWORD dwMediaModes;
    DWORD dwDuration;
    DWORD dwMediaControl;
} __attribute__((packed, aligned(1)));

struct linemediacontroltone_tag {
    DWORD dwAppSpecific;
    DWORD dwDuration;
    DWORD dwFrequency1;
    DWORD dwFrequency2;
    DWORD dwFrequency3;
    DWORD dwMediaControl;
} __attribute__((packed, aligned(1)));

struct linemessage_tag {
    DWORD hDevice;
    DWORD dwMessageID;
    DWORD dwCallbackInstance;
    DWORD dwParam1;
    DWORD dwParam2;
    DWORD dwParam3;
} __attribute__((packed, aligned(1)));

struct linemonitortone_tag {
    DWORD dwAppSpecific;
    DWORD dwDuration;
    DWORD dwFrequency1;
    DWORD dwFrequency2;
    DWORD dwFrequency3;
} __attribute__((packed, aligned(1)));

struct lineproviderentry_tag {
    DWORD dwPermanentProviderID;
    DWORD dwProviderFilenameSize;
    DWORD dwProviderFilenameOffset;
} __attribute__((packed, aligned(1)));

struct lineproviderlist_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwNumProviders;
    DWORD dwProviderListSize;
    DWORD dwProviderListOffset;
} __attribute__((packed, aligned(1)));

struct linetermcaps_tag {
    DWORD dwTermDev;
    DWORD dwTermModes;
    DWORD dwTermSharing;
} __attribute__((packed, aligned(1)));

struct linetranslatecaps_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwNumLocations;
    DWORD dwLocationListSize;
    DWORD dwLocationListOffset;
    DWORD dwCurrentLocationID;
    DWORD dwNumCards;
    DWORD dwCardListSize;
    DWORD dwCardListOffset;
    DWORD dwCurrentPreferredCardID;
} __attribute__((packed, aligned(1)));

struct linetranslateoutput_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwDialableStringSize;
    DWORD dwDialableStringOffset;
    DWORD dwDisplayableStringSize;
    DWORD dwDisplayableStringOffset;
    DWORD dwCurrentCountry;
    DWORD dwDestCountry;
    DWORD dwTranslateResults;
} __attribute__((packed, aligned(1)));

struct phonebuttoninfo_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwButtonMode;
    DWORD dwButtonFunction;
    DWORD dwButtonTextSize;
    DWORD dwButtonTextOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwButtonState;
} __attribute__((packed, aligned(1)));

struct phonecaps_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwProviderInfoSize;
    DWORD dwProviderInfoOffset;
    DWORD dwPhoneInfoSize;
    DWORD dwPhoneInfoOffset;
    DWORD dwPermanentPhoneID;
    DWORD dwPhoneNameSize;
    DWORD dwPhoneNameOffset;
    DWORD dwStringFormat;
    DWORD dwPhoneStates;
    DWORD dwHookSwitchDevs;
    DWORD dwHandsetHookSwitchModes;
    DWORD dwSpeakerHookSwitchModes;
    DWORD dwHeadsetHookSwitchModes;
    DWORD dwVolumeFlags;
    DWORD dwGainFlags;
    DWORD dwDisplayNumRows;
    DWORD dwDisplayNumColumns;
    DWORD dwNumRingModes;
    DWORD dwNumButtonLamps;
    DWORD dwButtonModesSize;
    DWORD dwButtonModesOffset;
    DWORD dwButtonFunctionsSize;
    DWORD dwButtonFunctionsOffset;
    DWORD dwLampModesSize;
    DWORD dwLampModesOffset;
    DWORD dwNumSetData;
    DWORD dwSetDataSize;
    DWORD dwSetDataOffset;
    DWORD dwNumGetData;
    DWORD dwGetDataSize;
    DWORD dwGetDataOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwDeviceClassesSize;
    DWORD dwDeviceClassesOffset;
    DWORD dwPhoneFeatures;
    DWORD dwSettableHandsetHookSwitchModes;
    DWORD dwSettableSpeakerHookSwitchModes;
    DWORD dwSettableHeadsetHookSwitchModes;
    DWORD dwMonitoredHandsetHookSwitchModes;
    DWORD dwMonitoredSpeakerHookSwitchModes;
    DWORD dwMonitoredHeadsetHookSwitchModes;
    GUID PermanentPhoneGuid;
} __attribute__((packed, aligned(1)));

struct phoneextensionid_tag {
    DWORD dwExtensionID0;
    DWORD dwExtensionID1;
    DWORD dwExtensionID2;
    DWORD dwExtensionID3;
} __attribute__((packed, aligned(1)));

struct phoneinitializeexparams_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwOptions;
    union {
        HANDLE hEvent;
        HANDLE hCompletionPort;
    } Handles;
    DWORD dwCompletionKey;
} __attribute__((packed, aligned(1)));

struct phonemessage_tag {
    DWORD hDevice;
    DWORD dwMessageID;
    DWORD dwCallbackInstance;
    DWORD dwParam1;
    DWORD dwParam2;
    DWORD dwParam3;
} __attribute__((packed, aligned(1)));

struct phonestatus_tag {
    DWORD dwTotalSize;
    DWORD dwNeededSize;
    DWORD dwUsedSize;
    DWORD dwStatusFlags;
    DWORD dwNumOwners;
    DWORD dwNumMonitors;
    DWORD dwRingMode;
    DWORD dwRingVolume;
    DWORD dwHandsetHookSwitchMode;
    DWORD dwHandsetVolume;
    DWORD dwHandsetGain;
    DWORD dwSpeakerHookSwitchMode;
    DWORD dwSpeakerVolume;
    DWORD dwSpeakerGain;
    DWORD dwHeadsetHookSwitchMode;
    DWORD dwHeadsetVolume;
    DWORD dwHeadsetGain;
    DWORD dwDisplaySize;
    DWORD dwDisplayOffset;
    DWORD dwLampModesSize;
    DWORD dwLampModesOffset;
    DWORD dwOwnerNameSize;
    DWORD dwOwnerNameOffset;
    DWORD dwDevSpecificSize;
    DWORD dwDevSpecificOffset;
    DWORD dwPhoneFeatures;
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif

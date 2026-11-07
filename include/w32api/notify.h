/*
 * The notify component supports the Windows CE event notification system.
 */
#ifndef _NOTIFY_H_
#define _NOTIFY_H_

#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef	_WIN32_WCE	/* Valid from Windows CE 1.01 and later */

/**
 * This structure contains information used to initialize the user
 * notifications settings dialog box, and receives the user's notification
 * preferences entered by way of the dialog box. Also used when setting a
 * user notification.
 *
 * The CE_USER_NOTIFICATION structure is passed in the
 * CeGetUserNotificationPreferences function. Initial settings are used to
 * populate the dialog box. If the function returns TRUE, the returned
 * settings should be saved, and considered when calling
 * CeSetUserNotification. Settings for hardware not on the current device
 * will be ignored.
 *
 * It is also used when calling CeSetUserNotification, to describe what
 * should happen when the notification time is reached.
 */
typedef struct UserNotificationType {
	/**
	 * Specifies the action to take when a notification
	 * event occurs. It can be a combination of the following flags:
	 * Value Description PUN_LED Flashes the LED. PUN_VIBRATE Vibrates
	 * the device. PUN_DIALOG Displays the user notification dialog box.
	 * When this structure is passed to the CeSetUserNotification
	 * function, the pwszDialogTitle and pwszDialogText members must
	 * provide the title and text of the dialog box. PUN_SOUND Plays the
	 * sound specified by the pwszSound member. When passed to PSVN, the
	 * pwszSound member must provide the name of the sound file.
	 * PUN_REPEAT Repeats the pwszSound for 10-15 seconds. Only valid if
	 * PUN_SOUND is set. Any flag that is not valid on the current
	 * hardware platform is ignored.
	 */
	DWORD		ActionFlags;
	/**
	 * Pointer to the string that contains the title of
	 * the user notification dialog box. If this member is NULL, no
	 * dialog is displayed. The CeGetUserNotificationPreferences
	 * function ignores this member.
	 */
	wchar_t		*pwszDialogTitle;
	/**
	 * Pointer to the string that contains the text of
	 * the user notification dialog box. If this member is NULL, no
	 * dialog is displayed. The CeGetUserNotificationPreferences
	 * function ignores this member.
	 */
	wchar_t		*pwszDialogText;
	/**
	 * Pointer to a buffer that contains the unqualified name
	 * of a sound file to play. This member is ignored if the
	 * ActionFlags member does not include the PUN_SOUND flag.
	 */
	wchar_t		*pwszSound;
	/**
	 * Specifies the maximum length of the string that the
	 * CeGetUserNotificationPreferences function can copy into the
	 * pwszSound buffer. Because the string may be a path name in a
	 * future release, the buffer must be at least the length derived by
	 * the following expression: PATH_MAX * sizeof(TCHAR). This member
	 * is ignored by the CeSetUserNotification function.
	 */
	DWORD		nMaxSound;
	/**
	 * Reserved; set to zero.
	 */
	DWORD		dwReserved;
} CE_USER_NOTIFICATION, *PCE_USER_NOTIFICATION;

typedef struct UserNotificationTrigger {
	DWORD		dwSize;
	DWORD		dwType;
	DWORD		dwEvent;
	WCHAR		*lpszApplication;
	WCHAR		*lpszArguments;
	SYSTEMTIME	stStartTime;
	SYSTEMTIME	stEndTime;
} CE_NOTIFICATION_TRIGGER, *PCE_NOTIFICATION_TRIGGER;

/* Flags for ActionFlags. Values from forums.microsoft.com. */
#define	PUN_LED		1	/* ? */
#define	PUN_VIBRATE	2	/* ? */
#define	PUN_DIALOG	4	/* ? */
#define	PUN_SOUND	8	/* ? */
#define	PUN_REPEAT	16	/* ? */
#define	PUN_PRIVATE	32	/* ? */

/* Values for lWhichEvent in CeRunAppAtEvent */
#define	NOTIFICATION_EVENT_NONE			0	/* ? */
#define	NOTIFICATION_EVENT_TIME_CHANGE		1	/* ? */
#define	NOTIFICATION_EVENT_SYNC_END		2	/* ? */
#define	NOTIFICATION_EVENT_ON_AC_POWER		3	/* ? */
#define	NOTIFICATION_EVENT_OFF_AC_POWER		4	/* ? */
#define	NOTIFICATION_EVENT_NET_CONNECT		5	/* ? */
#define	NOTIFICATION_EVENT_NET_DISCONNECT	6	/* ? */
#define	NOTIFICATION_EVENT_DEVICE_CHANGE	7	/* ? */
#define	NOTIFICATION_EVENT_IR_DISCOVERED	8	/* ? */
#define	NOTIFICATION_EVENT_RS232_DETECTED	9	/* ? */
#define	NOTIFICATION_EVENT_RESTORE_END		10	/* ? */
#define	NOTIFICATION_EVENT_WAKEUP		11	/* ? */
#define	NOTIFICATION_EVENT_TZ_CHANGE		12	/* ? */
#define	NOTIFICATION_EVENT_MACHINE_NAME_CHANGE	13	/* ? */

/* Command line values */
#define APP_RUN_AFTER_EXTENDED_EVENT	L"AppRunAfterExtendedEvent"
#define APP_RUN_AFTER_SYNC		L"AppRunAfterSync"
#define APP_RUN_AFTER_TZ_CHANGE		L"AppRunAfterTzChange"
#define APP_RUN_AFTER_WAKEUP		L"AppRunAfterWakeup"
#define APP_RUN_AT_AC_POWER_ON		L"AppRunAtAcPowerOn"
#define APP_RUN_AT_AC_POWER_OFF		L"AppRunAtAcPowerOff"
#define APP_RUN_AT_NET_CONNECT		L"AppRunAtNetConnect"
#define APP_RUN_AT_NET_DISCONNECT	L"AppRunAtNetDisconnect"
#define APP_RUN_AT_DEVICE_CHANGE	L"AppRunDeviceChange"
#define APP_RUN_AT_IR_DISCOVERY		L"AppRunAtIrDiscovery"
#define APP_RUN_AT_RS232_DETECT		L"AppRunAtRs232Detect"
#define APP_RUN_AFTER_RESTORE		L"AppRunAfterRestore"

/**
 * Deletes a pending user notification set with CeSetUserNotification.
 *
 * Has no effect on notifications that have already fired: use
 * CeHandleAppNotifications for those. Windows CE 1.0 has
 * PegClearUserNotification instead.
 *
 * @param hNotification Handle from CeSetUserNotification.
 * @return TRUE on success, FALSE on failure.
 */
BOOL CeClearUserNotification (HANDLE hNotification); 
/**
 * Retrieves notification information associated with a notification handle.
 *
 * `pcBytesNeeded` receives the required buffer size in bytes. OEM support
 * may vary.
 *
 * @param hNotification Notification handle.
 * @param cBufferSize Size of `pBuffer`, in bytes.
 * @param pcBytesNeeded Receives the required size, in bytes.
 * @param pBuffer Receives the notification information.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CeGetUserNotification (HANDLE hNotification,
		DWORD cBufferSize,
		LPDWORD pcBytesNeeded,
		LPBYTE pBuffer);
/**
 * Retrieves handles for currently stored user notifications.
 *
 * Counts are numbers of handles, not byte sizes. Pass NULL and zero for
 * `rghNotifications` and `cHandles` to query the required count. OEM
 * support may vary.
 *
 * @param rghNotifications Receives notification handles.
 * @param cHandles Capacity of the handle array.
 * @param pcHandlesNeeded Receives the number of handles required.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CeGetUserNotificationHandles (HANDLE* rghNotifications,
		DWORD cHandles,
		LPDWORD pcHandlesNeeded);
/**
 * Shows the notification options dialog and returns the user's choices.
 *
 * The dialog only offers options the hardware supports. Store the result
 * and pass it to CeSetUserNotification. Windows CE 1.0 has
 * PegGetUserNotificationPreferences instead.
 *
 * @param hWndParent Owner window for the dialog.
 * @param lpNotification CE_USER_NOTIFICATION with the initial settings.
 *        Receives the user's settings.
 * @return TRUE if the user changed the settings, FALSE if not or on
 *        failure.
 */
BOOL CeGetUserNotificationPreferences (HWND hWndParent,
		PCE_USER_NOTIFICATION lpNotification); 
/**
 * Marks all fired notifications owned by an application as handled.
 *
 * Stops the sound, LED and vibration and removes the taskbar annunciator.
 * Windows CE 1.0 has PegHandleAppNotifications instead.
 *
 * @param pwszAppName The owner name passed to CeSetUserNotification.
 * @return TRUE on success, FALSE on failure.
 */
BOOL CeHandleAppNotifications (wchar_t *pwszAppName); 
/**
 * Registers an application to be started when a system event occurs.
 *
 * The application is started with a command line beginning with an
 * APP_RUN_* string matching the event, such as APP_RUN_AFTER_SYNC, and
 * sometimes followed by a parameter. If an instance is already running,
 * the new one should hand over to it and exit. Use sparingly: unexpected
 * programs confuse users and use memory. Windows CE 1.0 has
 * PegRunAppAtEvent instead.
 *
 * @param pwszAppName Path of the application to start.
 * @param lWhichEvent NOTIFICATION_EVENT_SYNC_END, _DEVICE_CHANGE,
 *        _RS232_DETECTED, _TIME_CHANGE or _RESTORE_END, or
 *        NOTIFICATION_EVENT_NONE to remove all of the application's
 *        registrations. Windows CE 3.0 also accepts _TZ_CHANGE and
 *        _WAKEUP. NOTIFICATION_EVENT_ON_AC_POWER, _OFF_AC_POWER,
 *        _NET_CONNECT, _NET_DISCONNECT and _IR_DISCOVERED are not
 *        supported.
 * @return TRUE on success, FALSE on failure.
 */
BOOL CeRunAppAtEvent (wchar_t *pwszAppName, LONG lWhichEvent); 
/**
 * Registers an application to be started at a given time.
 *
 * Replaces any earlier request for the same application. The application
 * gets APP_RUN_AT_TIME as its command line. If an instance is already
 * running, the new one should hand over to it and exit. Windows CE 1.0
 * has PegRunAppAtTime instead.
 *
 * @param pwszAppName Path of the application to start.
 * @param lpTime Local time to start it, or NULL to cancel the request.
 * @return TRUE on success, FALSE on failure.
 */
BOOL CeRunAppAtTime (wchar_t *pwszAppName, SYSTEMTIME* lpTime); 
/**
 * Creates or replaces a user notification (sound, LED, dialog and so on)
 * due at a given time.
 *
 * Where CeSetUserNotificationEx is available it supersedes this function
 * and is the one to use for new code.
 *
 * The application isn't started when the notification fires. If the user
 * picks the annunciator, a new instance starts with a command line of
 * APP_RUN_TO_HANDLE_NOTIFICATION followed by the notification handle. Get
 * the options from the user with CeGetUserNotificationPreferences. Delete
 * a pending notification with CeClearUserNotification. Windows CE 1.0 has
 * PegSetUserNotification instead.
 *
 * @param hNotification Notification to replace, or 0 to create one.
 * @param pwszAppName Owning application. Its icon is used as the taskbar
 *        annunciator.
 * @param lpTime Local time the notification fires.
 * @param lpUserNotification CE_USER_NOTIFICATION with the actions (PUN_*
 *        flags), dialog text and sound.
 * @return The notification handle, or 0 on failure.
 */
HANDLE CeSetUserNotification (HANDLE hNotification,
		wchar_t *pwszAppName,
		SYSTEMTIME* lpTime,
		PCE_USER_NOTIFICATION lpUserNotification); 
/**
 * Creates a user notification or modifies an existing one.
 *
 * OEM support may vary.
 *
 * @param hNotification Existing notification handle, or 0 to add one.
 * @param pcnt Trigger describing the event that activates the
 *        notification.
 * @param pceun Defines the system response when the notification occurs,
 *        such as showing a dialog or starting an application.
 * @return Notification handle on success, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
HANDLE CeSetUserNotificationEx (HANDLE hNotification,
		CE_NOTIFICATION_TRIGGER *pcnt,
		CE_USER_NOTIFICATION* pceun);

#endif	/* _WIN32_WCE */

#ifdef  __cplusplus
}
#endif

#endif	/* _NOTIFY_H_ */

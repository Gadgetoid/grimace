#ifndef GRIMACE_EXTRAS_NOTIFY_H
#define GRIMACE_EXTRAS_NOTIFY_H

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

typedef CE_USER_NOTIFICATION PEG_USER_NOTIFICATION;
typedef PCE_USER_NOTIFICATION PPEG_USER_NOTIFICATION;

#if GRIMACE_CE >= 2
#define PegClearUserNotification CeClearUserNotification
#define PegGetUserNotificationPreferences CeGetUserNotificationPreferences
#define PegHandleAppNotifications CeHandleAppNotifications
#define PegRunAppAtEvent CeRunAppAtEvent
#define PegRunAppAtTime CeRunAppAtTime
#define PegSetUserNotification CeSetUserNotification
#else
/**
 * Deletes a user notification set with PegSetUserNotification.
 *
 * Has no effect on notifications that have already fired: use
 * PegHandleAppNotifications for those. Later versions call this
 * CeClearUserNotification.
 *
 * @param hNotification The notification, from PegSetUserNotification.
 * @return TRUE on success, FALSE on failure.
 */
BOOL PegClearUserNotification(HANDLE hNotification);
/**
 * Shows a dialog letting the user choose notification options supported by
 * the device.
 *
 * Store the result and pass it to PegSetUserNotification. Later versions call
 * this CeGetUserNotificationPreferences.
 *
 * @param hWndParent Owner of the dialog.
 * @param lpNotification In: the initial settings. Out: the user's choices.
 * @return TRUE if the user changed the settings, FALSE if not or on
 *         failure.
 */
BOOL PegGetUserNotificationPreferences(HWND hWndParent, PPEG_USER_NOTIFICATION lpNotification);
/**
 * Marks an application's fired notifications as handled.
 *
 * Stops the sound, LED and vibration and removes the taskbar icon. Later
 * versions call this CeHandleAppNotifications.
 *
 * @param pwszAppName The application, as passed to PegSetUserNotification.
 * @return TRUE on success, FALSE on failure.
 */
BOOL PegHandleAppNotifications(WCHAR *pwszAppName);
/**
 * Registers an application to be started when a system event occurs.
 *
 * The application is started with a command line naming the event, such as
 * APP_RUN_AFTER_SYNC or APP_RUN_AT_RS232_DETECT, sometimes followed by a
 * parameter. If an instance is already running, the new one should pass the
 * event on to it and exit. Later versions call this CeRunAppAtEvent.
 *
 * @param pwszAppName Path of the application to start.
 * @param lWhichEvent NOTIFICATION_EVENT_SYNC_END,
 *        NOTIFICATION_EVENT_DEVICE_CHANGE, NOTIFICATION_EVENT_RS232_DETECTED,
 *        NOTIFICATION_EVENT_TIME_CHANGE or NOTIFICATION_EVENT_RESTORE_END,
 *        or NOTIFICATION_EVENT_NONE to remove the application's
 *        registrations. Windows CE doesn't support the AC power, network or
 *        IR discovery events.
 * @return TRUE on success, FALSE on failure.
 */
BOOL PegRunAppAtEvent(WCHAR *pwszAppName, LONG lWhichEvent);
/**
 * Registers an application to be started at a given time.
 *
 * Replaces any earlier request for the same application. The application is
 * started with APP_RUN_AT_TIME as its command line. If an instance is already
 * running, the new one should notify it and exit. Later versions call this
 * CeRunAppAtTime.
 *
 * @param pwszAppName Path of the application to start.
 * @param lpTime When to start it, or NULL to cancel the existing request.
 * @return TRUE on success, FALSE on failure.
 */
BOOL PegRunAppAtTime(WCHAR *pwszAppName, SYSTEMTIME *lpTime);
/**
 * Creates or replaces a user notification: a sound, LED, vibration or dialog
 * at a given time.
 *
 * The application isn't started when the notification fires. The taskbar
 * shows the application's icon, and tapping it starts the application with
 * APP_RUN_TO_HANDLE_NOTIFICATION followed by the notification handle as its
 * command line. Use PegGetUserNotificationPreferences to let the user choose
 * the options. Later versions call this CeSetUserNotification.
 *
 * @param hNotification Notification to replace, or 0 to create one.
 * @param pwszAppName The owning application.
 * @param lpTime When the notification fires.
 * @param lpUserNotification What happens when it fires.
 * @return The notification handle, or 0 on failure.
 */
HANDLE PegSetUserNotification(HANDLE hNotification, WCHAR *pwszAppName, SYSTEMTIME *lpTime, PPEG_USER_NOTIFICATION lpUserNotification);
#define CeClearUserNotification PegClearUserNotification
#define CeGetUserNotificationPreferences PegGetUserNotificationPreferences
#define CeHandleAppNotifications PegHandleAppNotifications
#define CeRunAppAtEvent PegRunAppAtEvent
#define CeRunAppAtTime PegRunAppAtTime
#define CeSetUserNotification PegSetUserNotification
#endif

#define APP_RUN_AFTER_TIME_CHANGE TEXT("AppRunAfterTimeChange")
#define APP_RUN_AT_TIME TEXT("AppRunAtTime")
#define APP_RUN_TO_HANDLE_NOTIFICATION TEXT("AppRunToHandleNotification")
#define NOTIFY_DEVICE_ADD TEXT("/ADD")
#define NOTIFY_DEVICE_REMOVE TEXT("/REMOVE")

#ifdef __cplusplus
}
#endif

#endif

#endif

#ifndef GRIMACE_SDK_NOTIFY_H
#define GRIMACE_SDK_NOTIFY_H


#ifdef __cplusplus
extern "C" {
#endif

struct UserNotificationInfoHeader;
typedef struct UserNotificationInfoHeader CE_NOTIFICATION_INFO_HEADER;
typedef struct UserNotificationInfoHeader *PCE_NOTIFICATION_INFO_HEADER;
struct UserNotificationInfoHeader {
    HANDLE hNotification;
    DWORD dwStatus;
    CE_NOTIFICATION_TRIGGER *pcent;
    CE_USER_NOTIFICATION *pceun;
};


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_DBT_H
#define GRIMACE_SDK_DBT_H


#ifdef __cplusplus
extern "C" {
#endif

struct _DEV_BROADCAST_DEVICEINTERFACE_W;
typedef struct _DEV_BROADCAST_DEVICEINTERFACE_W DEV_BROADCAST_DEVICEINTERFACE_W;
typedef DEV_BROADCAST_DEVICEINTERFACE_W DEV_BROADCAST_DEVICEINTERFACE;
struct _DEV_BROADCAST_DEVICEINTERFACE_A;
typedef struct _DEV_BROADCAST_DEVICEINTERFACE_A DEV_BROADCAST_DEVICEINTERFACE_A;
struct _DEV_BROADCAST_DEVNODE;
typedef struct _DEV_BROADCAST_DEVNODE DEV_BROADCAST_DEVNODE;
struct _DEV_BROADCAST_HANDLE;
typedef struct _DEV_BROADCAST_HANDLE DEV_BROADCAST_HANDLE;
struct _DEV_BROADCAST_HDR;
typedef struct _DEV_BROADCAST_HDR DEV_BROADCAST_HDR;
typedef DEV_BROADCAST_DEVICEINTERFACE_W DEV_BROADCAST_INTERFACEDEVICE_W;
typedef DEV_BROADCAST_INTERFACEDEVICE_W DEV_BROADCAST_INTERFACEDEVICE;
typedef DEV_BROADCAST_DEVICEINTERFACE_A DEV_BROADCAST_INTERFACEDEVICE_A;
struct _DEV_BROADCAST_NET;
typedef struct _DEV_BROADCAST_NET DEV_BROADCAST_NET;
struct _DEV_BROADCAST_OEM;
typedef struct _DEV_BROADCAST_OEM DEV_BROADCAST_OEM;
struct _DEV_BROADCAST_PORT_W;
typedef struct _DEV_BROADCAST_PORT_W DEV_BROADCAST_PORT_W;
typedef DEV_BROADCAST_PORT_W DEV_BROADCAST_PORT;
struct _DEV_BROADCAST_PORT_A;
typedef struct _DEV_BROADCAST_PORT_A DEV_BROADCAST_PORT_A;
struct _DEV_BROADCAST_VOLUME_W;
typedef struct _DEV_BROADCAST_VOLUME_W DEV_BROADCAST_VOLUME_W;
typedef DEV_BROADCAST_VOLUME_W DEV_BROADCAST_VOLUME;
struct _DEV_BROADCAST_VOLUME_A;
typedef struct _DEV_BROADCAST_VOLUME_A DEV_BROADCAST_VOLUME_A;
typedef struct _DEV_BROADCAST_DEVICEINTERFACE_W *PDEV_BROADCAST_DEVICEINTERFACE_W;
typedef PDEV_BROADCAST_DEVICEINTERFACE_W PDEV_BROADCAST_DEVICEINTERFACE;
typedef struct _DEV_BROADCAST_DEVICEINTERFACE_A *PDEV_BROADCAST_DEVICEINTERFACE_A;
typedef DEV_BROADCAST_DEVNODE *PDEV_BROADCAST_DEVNODE;
typedef struct _DEV_BROADCAST_HANDLE *PDEV_BROADCAST_HANDLE;
typedef DEV_BROADCAST_HDR *PDEV_BROADCAST_HDR;
typedef PDEV_BROADCAST_DEVICEINTERFACE_W PDEV_BROADCAST_INTERFACEDEVICE_W;
typedef PDEV_BROADCAST_INTERFACEDEVICE_W PDEV_BROADCAST_INTERFACEDEVICE;
typedef PDEV_BROADCAST_DEVICEINTERFACE_A PDEV_BROADCAST_INTERFACEDEVICE_A;
typedef DEV_BROADCAST_NET *PDEV_BROADCAST_NET;
typedef DEV_BROADCAST_OEM *PDEV_BROADCAST_OEM;
typedef struct _DEV_BROADCAST_PORT_W *PDEV_BROADCAST_PORT_W;
typedef PDEV_BROADCAST_PORT_W PDEV_BROADCAST_PORT;
typedef struct _DEV_BROADCAST_PORT_A *PDEV_BROADCAST_PORT_A;
typedef struct _DEV_BROADCAST_VOLUME_W *PDEV_BROADCAST_VOLUME_W;
typedef PDEV_BROADCAST_VOLUME_W PDEV_BROADCAST_VOLUME;
typedef struct _DEV_BROADCAST_VOLUME_A *PDEV_BROADCAST_VOLUME_A;
struct VolLockBroadcast;
typedef struct VolLockBroadcast VolLockBroadcast;
typedef VolLockBroadcast *pVolLockBroadcast;
struct _DEV_BROADCAST_HDR {
    DWORD dbch_size;
    DWORD dbch_devicetype;
    DWORD dbch_reserved;
};

struct VolLockBroadcast {
    struct _DEV_BROADCAST_HDR vlb_dbh;
    DWORD vlb_owner;
    BYTE vlb_perms;
    BYTE vlb_lockType;
    BYTE vlb_drive;
    BYTE vlb_flags;
};

struct _DEV_BROADCAST_DEVICEINTERFACE_A {
    DWORD dbcc_size;
    DWORD dbcc_devicetype;
    DWORD dbcc_reserved;
    GUID dbcc_classguid;
    char dbcc_name[1];
};

struct _DEV_BROADCAST_DEVICEINTERFACE_W {
    DWORD dbcc_size;
    DWORD dbcc_devicetype;
    DWORD dbcc_reserved;
    GUID dbcc_classguid;
    wchar_t dbcc_name[1];
};

struct _DEV_BROADCAST_DEVNODE {
    DWORD dbcd_size;
    DWORD dbcd_devicetype;
    DWORD dbcd_reserved;
    DWORD dbcd_devnode;
};

struct _DEV_BROADCAST_HANDLE {
    DWORD dbch_size;
    DWORD dbch_devicetype;
    DWORD dbch_reserved;
    DWORD dbch_handle;
    DWORD dbch_hdevnotify;
    GUID dbch_eventguid;
    LONG dbch_nameoffset;
    BYTE dbch_data[1];
};

struct _DEV_BROADCAST_HEADER;
struct _DEV_BROADCAST_HEADER {
    DWORD dbcd_size;
    DWORD dbcd_devicetype;
    DWORD dbcd_reserved;
};

struct _DEV_BROADCAST_NET {
    DWORD dbcn_size;
    DWORD dbcn_devicetype;
    DWORD dbcn_reserved;
    DWORD dbcn_resource;
    DWORD dbcn_flags;
};

struct _DEV_BROADCAST_OEM {
    DWORD dbco_size;
    DWORD dbco_devicetype;
    DWORD dbco_reserved;
    DWORD dbco_identifier;
    DWORD dbco_suppfunc;
};

struct _DEV_BROADCAST_PORT_A {
    DWORD dbcp_size;
    DWORD dbcp_devicetype;
    DWORD dbcp_reserved;
    char dbcp_name[1];
};

struct _DEV_BROADCAST_PORT_W {
    DWORD dbcp_size;
    DWORD dbcp_devicetype;
    DWORD dbcp_reserved;
    wchar_t dbcp_name[1];
};

struct _DEV_BROADCAST_USERDEFINED;
struct _DEV_BROADCAST_USERDEFINED {
    struct _DEV_BROADCAST_HDR dbud_dbh;
    char dbud_szName[1];
};

struct _DEV_BROADCAST_VOLUME_A {
    DWORD dbcv_size;
    DWORD dbcv_devicetype;
    DWORD dbcv_reserved;
    DWORD dbcv_unitmask;
    WORD dbcv_flags;
    char dbcv_name[1];
};

struct _DEV_BROADCAST_VOLUME_W {
    DWORD dbcv_size;
    DWORD dbcv_devicetype;
    DWORD dbcv_reserved;
    DWORD dbcv_unitmask;
    WORD dbcv_flags;
    wchar_t dbcv_name[1];
};


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_AF_IRDA_H
#define GRIMACE_SDK_AF_IRDA_H

#include <winsock.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef u_long LM_BAUD_RATE;
typedef struct {
    u_long nTXDataBytes;
    u_long nRXDataBytes;
    LM_BAUD_RATE nBaudRate;
    u_long thresholdTime;
    u_long discTime;
    u_short nMSLinkTurn;
    u_char nTXPackets;
    u_char nRXPackets;
} LM_IRPARMS;

struct _WCE_IAS_QUERY;
typedef struct _WCE_IAS_QUERY WCE_IAS_QUERY;
typedef WCE_IAS_QUERY *LPIASQUERY;
typedef struct _SOCKADDR_IRDA *LPSOCKADDR_IRDA;
struct _WINDOWS_DEVICELIST;
typedef struct _WINDOWS_DEVICELIST *LPWINDOWS_DEVICELIST;
struct _WINDOWS_IAS_QUERY;
typedef struct _WINDOWS_IAS_QUERY *LPWINDOWS_IAS_QUERY;
struct _WINDOWS_IAS_SET;
typedef struct _WINDOWS_IAS_SET *LPWINDOWS_IAS_SET;
struct _WINDOWS_IRDA_DEVICE_INFO;
typedef struct _WINDOWS_IRDA_DEVICE_INFO *LPWINDOWS_IRDA_DEVICE_INFO;
typedef LM_IRPARMS *PLM_IRPARMS;
struct _WCE_DEVICELIST;
typedef struct _WCE_DEVICELIST *PWCE_DEVICELIST;
typedef struct _WCE_IAS_QUERY *PWCE_IAS_QUERY;
struct _WCE_IAS_SET;
typedef struct _WCE_IAS_SET *PWCE_IAS_SET;
struct _WCE_IRDA_DEVICE_INFO;
typedef struct _WCE_IRDA_DEVICE_INFO *PWCE_IRDA_DEVICE_INFO;
typedef struct _WINDOWS_DEVICELIST *PWINDOWS_DEVICELIST;
typedef struct _WINDOWS_IAS_QUERY *PWINDOWS_IAS_QUERY;
typedef struct _WINDOWS_IAS_SET *PWINDOWS_IAS_SET;
typedef struct _WINDOWS_IRDA_DEVICE_INFO *PWINDOWS_IRDA_DEVICE_INFO;
typedef struct _WCE_DEVICELIST WCE_DEVICELIST;
typedef struct _WCE_IAS_SET WCE_IAS_SET;
typedef struct _WCE_IRDA_DEVICE_INFO WCE_IRDA_DEVICE_INFO;
typedef struct _WINDOWS_DEVICELIST WINDOWS_DEVICELIST;
typedef struct _WINDOWS_IAS_QUERY WINDOWS_IAS_QUERY;
typedef struct _WINDOWS_IAS_SET WINDOWS_IAS_SET;
typedef struct _WINDOWS_IRDA_DEVICE_INFO WINDOWS_IRDA_DEVICE_INFO;
struct _WCE_IRDA_DEVICE_INFO {
    u_char irdaDeviceID[4];
    char irdaDeviceName[22];
    u_char Reserved[2];
};

struct _WCE_DEVICELIST {
    ULONG numDevice;
    WCE_IRDA_DEVICE_INFO Device[1];
};

struct _WCE_IAS_QUERY {
    u_char irdaDeviceID[4];
    char irdaClassName[61];
    char irdaAttribName[61];
    u_short irdaAttribType;
    union {
        int irdaAttribInt;
        struct {
            int Len;
            u_char OctetSeq[1];
            u_char Reserved[3];
        } irdaAttribOctetSeq;
        struct {
            int Len;
            u_char CharSet;
            u_char UsrStr[1];
            u_char Reserved[2];
        } irdaAttribUsrStr;
    } irdaAttribute;
};

struct _WCE_IAS_SET {
    char irdaClassName[61];
    char irdaAttribName[61];
    u_short irdaAttribType;
    union {
        int irdaAttribInt;
        struct {
            int Len;
            u_char OctetSeq[1];
            u_char Reserved[3];
        } irdaAttribOctetSeq;
        struct {
            int Len;
            u_char CharSet;
            u_char UsrStr[1];
            u_char Reserved[2];
        } irdaAttribUsrStr;
    } irdaAttribute;
};

struct _WINDOWS_IRDA_DEVICE_INFO {
    u_char irdaDeviceID[4];
    char irdaDeviceName[22];
    u_char irdaDeviceHints1;
    u_char irdaDeviceHints2;
    u_char irdaCharSet;
};

struct _WINDOWS_DEVICELIST {
    ULONG numDevice;
    WINDOWS_IRDA_DEVICE_INFO Device[1];
};

struct _WINDOWS_IAS_QUERY {
    u_char irdaDeviceID[4];
    char irdaClassName[64];
    char irdaAttribName[256];
    u_long irdaAttribType;
    union {
        LONG irdaAttribInt;
        struct {
            u_long Len;
            u_char OctetSeq[1024];
        } irdaAttribOctetSeq;
        struct {
            u_long Len;
            u_long CharSet;
            u_char UsrStr[256];
        } irdaAttribUsrStr;
    } irdaAttribute;
};

struct _WINDOWS_IAS_SET {
    char irdaClassName[64];
    char irdaAttribName[256];
    u_long irdaAttribType;
    union {
        LONG irdaAttribInt;
        struct {
            u_short Len;
            u_char OctetSeq[1024];
        } irdaAttribOctetSeq;
        struct {
            u_char Len;
            u_char CharSet;
            u_char UsrStr[256];
        } irdaAttribUsrStr;
    } irdaAttribute;
};


#ifdef __cplusplus
}
#endif

#endif

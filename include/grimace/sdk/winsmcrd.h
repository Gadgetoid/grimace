#ifndef GRIMACE_SDK_WINSMCRD_H
#define GRIMACE_SDK_WINSMCRD_H


#ifdef __cplusplus
extern "C" {
#endif

struct _SCARD_IO_REQUEST;
typedef struct _SCARD_IO_REQUEST SCARD_IO_REQUEST;
typedef const SCARD_IO_REQUEST *LPCSCARD_IO_REQUEST;
typedef struct _SCARD_IO_REQUEST *LPSCARD_IO_REQUEST;
typedef struct {
    BYTE bCla;
    BYTE bIns;
    BYTE bP1;
    BYTE bP2;
    BYTE bP3;
} SCARD_T0_COMMAND;

typedef SCARD_T0_COMMAND *LPSCARD_T0_COMMAND;
struct _SCARD_IO_REQUEST {
    DWORD dwProtocol;
    DWORD cbPciLength;
};

typedef struct {
    SCARD_IO_REQUEST ioRequest;
    BYTE bSw1;
    BYTE bSw2;
    union {
        SCARD_T0_COMMAND CmdBytes;
        BYTE rgbHeader[5];
    };
} SCARD_T0_REQUEST;

typedef SCARD_T0_REQUEST *LPSCARD_T0_REQUEST;
typedef struct {
    SCARD_IO_REQUEST ioRequest;
} SCARD_T1_REQUEST;

typedef SCARD_T1_REQUEST *LPSCARD_T1_REQUEST;
typedef struct _SCARD_IO_REQUEST *PSCARD_IO_REQUEST;
typedef SCARD_T0_REQUEST *PSCARD_T0_REQUEST;
typedef SCARD_T1_REQUEST *PSCARD_T1_REQUEST;
typedef WORD UWORD;

#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_MSGQUEUE_H
#define GRIMACE_MSGQUEUE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MSGQUEUE_NOPRECOMMIT 0x00000001
#define MSGQUEUE_ALLOW_BROKEN 0x00000002
#define MSGQUEUE_MSGALERT 0x00000001

typedef struct MSGQUEUEOPTIONS_OS {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwMaxMessages;
    DWORD cbMaxMessage;
    BOOL bReadAccess;
} MSGQUEUEOPTIONS, *LPMSGQUEUEOPTIONS, *PMSGQUEUEOPTIONS;

typedef struct MSGQUEUEINFO {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwMaxMessages;
    DWORD cbMaxMessage;
    DWORD dwCurrentMessages;
    DWORD dwMaxQueueMessages;
    WORD wNumReaders;
    WORD wNumWriters;
} MSGQUEUEINFO, *LPMSGQUEUEINFO, *PMSGQUEUEINFO;

HANDLE WINAPI CreateMsgQueue(LPCWSTR lpName, LPMSGQUEUEOPTIONS lpOptions);
HANDLE WINAPI OpenMsgQueue(HANDLE hSrcProc, HANDLE hMsgQ, LPMSGQUEUEOPTIONS lpOptions);
BOOL WINAPI ReadMsgQueue(HANDLE hMsgQ, LPVOID lpBuffer, DWORD cbBufferSize, LPDWORD lpNumberOfBytesRead, DWORD dwTimeout, DWORD *pdwFlags);
BOOL WINAPI ReadMsgQueueEx(HANDLE hMsgQ, LPVOID lpBuffer, DWORD cbBufferSize, LPDWORD lpNumberOfBytesRead, DWORD dwTimeout, DWORD *pdwFlags, PHANDLE phTok);
BOOL WINAPI WriteMsgQueue(HANDLE hMsgQ, LPVOID lpBuffer, DWORD cbDataSize, DWORD dwTimeout, DWORD dwFlags);
BOOL WINAPI GetMsgQueueInfo(HANDLE hMsgQ, LPMSGQUEUEINFO lpInfo);
BOOL WINAPI CloseMsgQueue(HANDLE hMsgQ);

#ifdef __cplusplus
}
#endif

#endif

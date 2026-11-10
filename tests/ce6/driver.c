#include <windows.h>
#include <ceddk.h>
#include <msgqueue.h>
#include <pm.h>
#include <string.h>

struct device {
    volatile DWORD *registers;
    HANDLE queue;
    HANDLE notifications;
    BYTE buffer[64];
};

static struct device state;

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    return TRUE;
}

DWORD TST_Init(LPCTSTR context, LPCVOID bus_context) {
    PHYSICAL_ADDRESS address;
    MSGQUEUEOPTIONS options;
    memset(&options, 0, sizeof options);
    options.dwSize = sizeof options;
    options.dwMaxMessages = 4;
    options.cbMaxMessage = sizeof(POWER_BROADCAST) + 64;
    options.bReadAccess = TRUE;
    address.QuadPart = 0x80000000;
    state.registers = MmMapIoSpace(address, 0x1000, FALSE);
    state.queue = CreateMsgQueue(NULL, &options);
    state.notifications = RequestPowerNotifications(state.queue, PBT_TRANSITION | PBT_RESUME);
    CeSetThreadPriority(GetCurrentThread(), 100);
    return (DWORD)&state;
}

BOOL TST_Deinit(DWORD context) {
    StopPowerNotifications(state.notifications);
    CloseMsgQueue(state.queue);
    MmUnmapIoSpace((PVOID)state.registers, 0x1000);
    return TRUE;
}

DWORD TST_Open(DWORD context, DWORD access, DWORD share) {
    return context;
}

BOOL TST_Close(DWORD context) {
    return TRUE;
}

DWORD TST_Read(DWORD context, LPVOID buffer, DWORD count) {
    BYTE message[sizeof(POWER_BROADCAST) + 64];
    DWORD read = 0;
    DWORD flags = 0;
    if (ReadMsgQueue(state.queue, message, sizeof message, &read, 0, &flags)) {
        memcpy(state.buffer, message, read < sizeof state.buffer ? read : sizeof state.buffer);
    }
    count = count < sizeof state.buffer ? count : sizeof state.buffer;
    memcpy(buffer, state.buffer, count);
    return count;
}

DWORD TST_Write(DWORD context, LPCVOID buffer, DWORD count) {
    return count;
}

DWORD TST_Seek(DWORD context, long amount, WORD type) {
    return (DWORD)-1;
}

BOOL TST_IOControl(DWORD context, DWORD code, PBYTE input, DWORD input_size, PBYTE output, DWORD output_size, PDWORD returned) {
    if (returned) {
        *returned = 0;
    }
    return state.registers != NULL;
}

void TST_PowerUp(DWORD context) {
}

void TST_PowerDown(DWORD context) {
}

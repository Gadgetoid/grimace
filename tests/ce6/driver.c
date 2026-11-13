#include <windows.h>
#include <ceddk.h>
#include <msgqueue.h>
#include <pm.h>
#include <pkfuncs.h>
#include <string.h>

struct device {
    volatile DWORD *registers;
    HANDLE queue;
    HANDLE notifications;
    HANDLE interrupt;
    DWORD sysintr;
    ULONG physical;
    PVOID frame;
    BYTE buffer[64];
    BYTE log[65536];
    DWORD idle;
};

static struct device state;

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
    state.interrupt = CreateEventW(NULL, FALSE, FALSE, NULL);
    if (KernelIoControl((DWORD)bus_context, &state.sysintr, sizeof state.sysintr, &state.sysintr, sizeof state.sysintr, NULL)) {
        InterruptInitialize(state.sysintr, state.interrupt, NULL, 0);
    }
    return (DWORD)&state;
}

BOOL TST_Deinit(DWORD context) {
    InterruptDisable(state.sysintr);
    if (state.frame) {
        FreePhysMem(state.frame);
    }
    CloseHandle(state.interrupt);
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
    InterruptDone(state.sysintr);
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
    HANDLE caller = OpenProcess(0, FALSE, GetCallerVMProcessId());
    if (!state.frame) {
        state.frame = AllocPhysMem(0x10000, PAGE_READWRITE, 0, 0, &state.physical);
    }
    if (caller && output_size >= sizeof(PVOID)) {
        PVOID view = VirtualAllocEx(caller, NULL, 0x10000, MEM_RESERVE, PAGE_NOACCESS);
        if (view && VirtualCopyEx(caller, view, GetCurrentProcess(), state.frame, 0x10000, PAGE_READWRITE)) {
            *(PVOID *)output = view;
        } else if (view) {
            VirtualFreeEx(caller, view, 0, MEM_RELEASE);
        }
    }
    if (caller) {
        CloseHandle(caller);
    }
    if (returned) {
        *returned = 0;
    }
    state.idle = GetIdleTime();
    state.log[state.idle % sizeof state.log]++;
    return state.registers != NULL;
}

void TST_PowerUp(DWORD context) {
}

void TST_PowerDown(DWORD context) {
}

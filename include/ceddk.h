#ifndef GRIMACE_CEDDK_H
#define GRIMACE_CEDDK_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef LARGE_INTEGER PHYSICAL_ADDRESS, *PPHYSICAL_ADDRESS;

PVOID MmMapIoSpace(PHYSICAL_ADDRESS PhysicalAddress, ULONG NumberOfBytes, BOOLEAN CacheEnable);
VOID MmUnmapIoSpace(PVOID BaseAddress, ULONG NumberOfBytes);

#ifdef __cplusplus
}
#endif

#endif

#if !defined(GRIMACE_CE)
#error "include windows.h first"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if GRIMACE_WCE == 300 && GRIMACE_ARM && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#endif

#if GRIMACE_WCE == 100 && GRIMACE_MIPS && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#if GRIMACE_WCE == 200 && GRIMACE_MIPS && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#if GRIMACE_WCE == 100 && GRIMACE_SH3 && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#if GRIMACE_WCE == 101 && GRIMACE_SH3 && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#if GRIMACE_WCE == 200 && GRIMACE_SH3 && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#if GRIMACE_WCE == 200 && GRIMACE_X86 && !defined(GRIMACE_DEVICE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#endif

#if GRIMACE_WCE == 300 && GRIMACE_ARM && defined(GRIMACE_DEVICE_JORNADA720)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#endif

#if GRIMACE_WCE == 200 && GRIMACE_X86 && defined(GRIMACE_DEVICE_JOYRIDE)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#endif

#if GRIMACE_WCE == 100 && GRIMACE_MIPS && defined(GRIMACE_DEVICE_VELO1)
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef FindResource
extern __typeof__(FindResourceW) FindResource;
#undef FindResourceW
#define FindResourceW FindResource
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#ifdef _WINUSER_H
#undef GetClassLong
extern __typeof__(GetClassLongW) GetClassLong;
#undef GetClassLongW
#define GetClassLongW GetClassLong
#undef SetClassLong
extern __typeof__(SetClassLongW) SetClassLong;
#undef SetClassLongW
#define SetClassLongW SetClassLong
#endif
#endif

#if GRIMACE_WCE == 200 && GRIMACE_MIPS && defined(GRIMACE_DEVICE_VELO1)
#ifdef _MSACM_H
#undef acmDriverAdd
extern __typeof__(acmDriverAddW) acmDriverAdd;
#undef acmDriverAddW
#define acmDriverAddW acmDriverAdd
#undef acmDriverDetails
extern __typeof__(acmDriverDetailsW) acmDriverDetails;
#undef acmDriverDetailsW
#define acmDriverDetailsW acmDriverDetails
#undef acmFormatEnum
extern __typeof__(acmFormatEnumW) acmFormatEnum;
#undef acmFormatEnumW
#define acmFormatEnumW acmFormatEnum
#undef acmFormatTagEnum
extern __typeof__(acmFormatTagEnumW) acmFormatTagEnum;
#undef acmFormatTagEnumW
#define acmFormatTagEnumW acmFormatTagEnum
#endif
#ifdef _RAS_H
#undef RasDeleteEntry
extern __typeof__(RasDeleteEntryW) RasDeleteEntry;
#undef RasDeleteEntryW
#define RasDeleteEntryW RasDeleteEntry
#undef RasDial
extern __typeof__(RasDialW) RasDial;
#undef RasDialW
#define RasDialW RasDial
#undef RasEnumConnections
extern __typeof__(RasEnumConnectionsW) RasEnumConnections;
#undef RasEnumConnectionsW
#define RasEnumConnectionsW RasEnumConnections
#undef RasEnumEntries
extern __typeof__(RasEnumEntriesW) RasEnumEntries;
#undef RasEnumEntriesW
#define RasEnumEntriesW RasEnumEntries
#undef RasGetConnectStatus
extern __typeof__(RasGetConnectStatusW) RasGetConnectStatus;
#undef RasGetConnectStatusW
#define RasGetConnectStatusW RasGetConnectStatus
#undef RasGetEntryDialParams
extern __typeof__(RasGetEntryDialParamsW) RasGetEntryDialParams;
#undef RasGetEntryDialParamsW
#define RasGetEntryDialParamsW RasGetEntryDialParams
#undef RasGetEntryProperties
extern __typeof__(RasGetEntryPropertiesW) RasGetEntryProperties;
#undef RasGetEntryPropertiesW
#define RasGetEntryPropertiesW RasGetEntryProperties
#undef RasHangUp
extern __typeof__(RasHangUpW) RasHangUp;
#undef RasHangUpW
#define RasHangUpW RasHangUp
#undef RasRenameEntry
extern __typeof__(RasRenameEntryW) RasRenameEntry;
#undef RasRenameEntryW
#define RasRenameEntryW RasRenameEntry
#undef RasSetEntryDialParams
extern __typeof__(RasSetEntryDialParamsW) RasSetEntryDialParams;
#undef RasSetEntryDialParamsW
#define RasSetEntryDialParamsW RasSetEntryDialParams
#undef RasSetEntryProperties
extern __typeof__(RasSetEntryPropertiesW) RasSetEntryProperties;
#undef RasSetEntryPropertiesW
#define RasSetEntryPropertiesW RasSetEntryProperties
#undef RasValidateEntryName
extern __typeof__(RasValidateEntryNameW) RasValidateEntryName;
#undef RasValidateEntryNameW
#define RasValidateEntryNameW RasValidateEntryName
#endif
#ifdef _WINBASE_H
#undef CreateFileForMapping
extern __typeof__(CreateFileForMappingW) CreateFileForMapping;
#undef CreateFileForMappingW
#define CreateFileForMappingW CreateFileForMapping
#undef GetVersionEx
extern __typeof__(GetVersionExW) GetVersionEx;
#undef GetVersionExW
#define GetVersionExW GetVersionEx
#endif
#endif

#ifdef __cplusplus
}
#endif

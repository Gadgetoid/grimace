#ifndef GRIMACE_SDK_IPEXPORT_H
#define GRIMACE_SDK_IPEXPORT_H


#ifdef __cplusplus
extern "C" {
#endif

struct ArpRequestBuffer;
typedef struct ArpRequestBuffer ARP_SEND_REPLY;
struct icmp_echo_reply;
typedef struct icmp_echo_reply ICMP_ECHO_REPLY;
typedef unsigned long IPAddr;
typedef unsigned long IPMask;
struct _IP_ADAPTER_INDEX_MAP;
typedef struct _IP_ADAPTER_INDEX_MAP IP_ADAPTER_INDEX_MAP;
struct _IP_INTERFACE_INFO;
typedef struct _IP_INTERFACE_INFO IP_INTERFACE_INFO;
struct ip_option_information;
typedef struct ip_option_information IP_OPTION_INFORMATION;
typedef unsigned long IP_STATUS;
struct _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS;
typedef struct _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS IP_UNIDIRECTIONAL_ADAPTER_ADDRESS;
typedef struct ArpRequestBuffer *PARP_SEND_REPLY;
typedef struct icmp_echo_reply *PICMP_ECHO_REPLY;
typedef struct _IP_ADAPTER_INDEX_MAP *PIP_ADAPTER_INDEX_MAP;
typedef struct _IP_INTERFACE_INFO *PIP_INTERFACE_INFO;
typedef struct ip_option_information *PIP_OPTION_INFORMATION;
typedef struct _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS *PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS;
struct _TCP_RESERVE_PORT_RANGE;
typedef struct _TCP_RESERVE_PORT_RANGE *PTCP_RESERVE_PORT_RANGE;
typedef struct _TCP_RESERVE_PORT_RANGE TCP_RESERVE_PORT_RANGE;
struct ArpRequestBuffer {
    IPAddr DestAddress;
    IPAddr SrcAddress;
};

struct _IP_ADAPTER_INDEX_MAP {
    ULONG Index;
    WCHAR Name[128];
};

struct _IP_INTERFACE_INFO {
    LONG NumAdapters;
    IP_ADAPTER_INDEX_MAP Adapter[1];
};

struct _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS {
    ULONG NumAdapters;
    IPAddr Address[1];
};

struct _TCP_RESERVE_PORT_RANGE {
    USHORT UpperRange;
    USHORT LowerRange;
};

struct ip_option_information {
    unsigned char Ttl;
    unsigned char Tos;
    unsigned char Flags;
    unsigned char OptionsSize;
    unsigned char *OptionsData;
};

struct icmp_echo_reply {
    IPAddr Address;
    unsigned long Status;
    unsigned long RoundTripTime;
    unsigned short DataSize;
    unsigned short Reserved;
    void *Data;
    struct ip_option_information Options;
};


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_RPCDCEP_H
#define GRIMACE_SDK_RPCDCEP_H

#include <grimace/sdk/rpc.h>
#include <grimace/sdk/rpcdce.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *I_RPC_MUTEX;
struct _RPC_CLIENT_INTERFACE;
typedef struct _RPC_CLIENT_INTERFACE *PRPC_CLIENT_INTERFACE;
struct _RPC_MESSAGE;
typedef struct _RPC_MESSAGE *PRPC_MESSAGE;
typedef void (*RPC_DISPATCH_FUNCTION)(PRPC_MESSAGE);
typedef struct {
    unsigned int DispatchTableCount;
    RPC_DISPATCH_FUNCTION *DispatchTable;
    int Reserved;
} RPC_DISPATCH_TABLE;

typedef RPC_DISPATCH_TABLE *PRPC_DISPATCH_TABLE;
struct _RPC_PROTSEQ_ENDPOINT;
typedef struct _RPC_PROTSEQ_ENDPOINT *PRPC_PROTSEQ_ENDPOINT;
typedef void (*PRPC_RUNDOWN)(void *);
struct _RPC_SERVER_INTERFACE;
typedef struct _RPC_SERVER_INTERFACE *PRPC_SERVER_INTERFACE;
struct _RPC_SYNTAX_IDENTIFIER;
typedef struct _RPC_SYNTAX_IDENTIFIER *PRPC_SYNTAX_IDENTIFIER;
typedef RPC_STATUS (*RPC_BLOCKING_FN)(void *, void *, HANDLE);
typedef struct _RPC_CLIENT_INTERFACE RPC_CLIENT_INTERFACE;
struct _RPC_VERSION;
typedef struct _RPC_VERSION RPC_VERSION;
typedef RPC_STATUS RPC_FORWARD_FUNCTION(UUID *, RPC_VERSION *, UUID *, unsigned char *, void **);
typedef struct _RPC_MESSAGE RPC_MESSAGE;
typedef struct _RPC_PROTSEQ_ENDPOINT RPC_PROTSEQ_ENDPOINT;
typedef struct _RPC_SERVER_INTERFACE RPC_SERVER_INTERFACE;
typedef struct _RPC_SYNTAX_IDENTIFIER RPC_SYNTAX_IDENTIFIER;
struct _RPC_TRANSFER_SYNTAX;
typedef struct _RPC_TRANSFER_SYNTAX RPC_TRANSFER_SYNTAX;
struct _RPC_VERSION {
    unsigned short MajorVersion;
    unsigned short MinorVersion;
} __attribute__((packed, aligned(2)));

struct _RPC_SYNTAX_IDENTIFIER {
    GUID SyntaxGUID;
    RPC_VERSION SyntaxVersion;
} __attribute__((packed, aligned(4)));

struct _RPC_CLIENT_INTERFACE {
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    unsigned long Reserved;
    const void *InterpreterInfo;
    unsigned int Flags;
} __attribute__((packed, aligned(4)));

struct _RPC_MESSAGE {
    RPC_BINDING_HANDLE Handle;
    unsigned long DataRepresentation;
    void *Buffer;
    unsigned int BufferLength;
    unsigned int ProcNum;
    PRPC_SYNTAX_IDENTIFIER TransferSyntax;
    void *RpcInterfaceInformation;
    void *ReservedForRuntime;
    void *ManagerEpv;
    void *ImportContext;
    unsigned long RpcFlags;
} __attribute__((packed, aligned(4)));

struct _RPC_PROTSEQ_ENDPOINT {
    unsigned char *RpcProtocolSequence;
    unsigned char *Endpoint;
} __attribute__((packed, aligned(4)));

struct _RPC_SERVER_INTERFACE {
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    void *DefaultManagerEpv;
    const void *InterpreterInfo;
    unsigned int Flags;
} __attribute__((packed, aligned(4)));

struct _RPC_TRANSFER_SYNTAX {
    UUID Uuid;
    unsigned short VersMajor;
    unsigned short VersMinor;
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

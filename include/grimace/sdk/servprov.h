#ifndef GRIMACE_SDK_SERVPROV_H
#define GRIMACE_SDK_SERVPROV_H

#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct IServiceProvider;
typedef struct IServiceProvider IServiceProvider;
struct IServiceProviderVtbl;
typedef struct IServiceProviderVtbl IServiceProviderVtbl;
typedef IServiceProvider *LPSERVICEPROVIDER;
struct IServiceProvider {
    struct IServiceProviderVtbl *lpVtbl;
};

struct IServiceProviderVtbl {
    HRESULT (*QueryInterface)(IServiceProvider *, const IID *const, void **);
    ULONG (*AddRef)(IServiceProvider *);
    ULONG (*Release)(IServiceProvider *);
    HRESULT (*QueryService)(IServiceProvider *, const GUID *const, const IID *const, void **);
};


#ifdef __cplusplus
}
#endif

#endif

#ifndef GRIMACE_SDK_UNKNWN_H
#define GRIMACE_SDK_UNKNWN_H

#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

struct IUnknown;
typedef struct IUnknown IUnknown;
typedef IUnknown *LPUNKNOWN;
struct IClassFactory;
typedef struct IClassFactory IClassFactory;
struct IClassFactoryVtbl;
typedef struct IClassFactoryVtbl IClassFactoryVtbl;
struct IUnknownVtbl;
typedef struct IUnknownVtbl IUnknownVtbl;
typedef IClassFactory *LPCLASSFACTORY;
struct IClassFactory {
    struct IClassFactoryVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IClassFactoryVtbl {
    HRESULT (*QueryInterface)(IClassFactory *, const IID *const, void **);
    ULONG (*AddRef)(IClassFactory *);
    ULONG (*Release)(IClassFactory *);
    HRESULT (*CreateInstance)(IClassFactory *, IUnknown *, const IID *const, void **);
    HRESULT (*LockServer)(IClassFactory *, BOOL);
} __attribute__((packed, aligned(4)));

struct IUnknown {
    struct IUnknownVtbl *lpVtbl;
} __attribute__((packed, aligned(4)));

struct IUnknownVtbl {
    HRESULT (*QueryInterface)(IUnknown *, const IID *const, void **);
    ULONG (*AddRef)(IUnknown *);
    ULONG (*Release)(IUnknown *);
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif

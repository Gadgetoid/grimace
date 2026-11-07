#ifndef GRIMACE_SDK_SCHNLSP_H
#define GRIMACE_SDK_SCHNLSP_H

#include <grimace/sdk/sslsock.h>
#include <grimace/sdk/wincrypt.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _SCH_CRED;
typedef struct _SCH_CRED *PSCH_CRED;
struct _SCH_CRED_PUBLIC_CERTCHAIN;
typedef struct _SCH_CRED_PUBLIC_CERTCHAIN *PSCH_CRED_PUBLIC_CERTCHAIN;
struct _SCH_CRED_SECRET_CAPI;
typedef struct _SCH_CRED_SECRET_CAPI *PSCH_CRED_SECRET_CAPI;
struct _SCH_CRED_SECRET_PRIVKEY;
typedef struct _SCH_CRED_SECRET_PRIVKEY *PSCH_CRED_SECRET_PRIVKEY;
struct _SCH_CRED_SECRET_WINSOCK2;
typedef struct _SCH_CRED_SECRET_WINSOCK2 *PSCH_CRED_SECRET_WINSOCK2;
struct _SSL_CREDENTIAL_CERTIFICATE;
typedef struct _SSL_CREDENTIAL_CERTIFICATE *PSSL_CREDENTIAL_CERTIFICATE;
struct _SecPkgContext_ConnectionInfo;
typedef struct _SecPkgContext_ConnectionInfo *PSecPkgContext_ConnectionInfo;
struct _SecPkgContext_IssuerListInfo;
typedef struct _SecPkgContext_IssuerListInfo *PSecPkgContext_IssuerListInfo;
struct _SecPkgContext_LocalCredentialInfo;
typedef struct _SecPkgContext_LocalCredentialInfo *PSecPkgContext_LocalCredentialInfo;
struct _SecPkgContext_RemoteCredentialInfo;
typedef struct _SecPkgContext_RemoteCredentialInfo *PSecPkgContext_RemoteCredentialInfo;
struct _SecPkgCred_SupportedProtocols;
typedef struct _SecPkgCred_SupportedProtocols *PSecPkgCred_SupportedProtocols;
struct _X509Certificate;
typedef struct _X509Certificate *PX509Certificate;
struct _PctPublicKey;
typedef struct _PctPublicKey PctPublicKey;
typedef struct _SCH_CRED SCH_CRED;
typedef struct _SCH_CRED_PUBLIC_CERTCHAIN SCH_CRED_PUBLIC_CERTCHAIN;
typedef struct _SCH_CRED_SECRET_CAPI SCH_CRED_SECRET_CAPI;
typedef struct _SCH_CRED_SECRET_PRIVKEY SCH_CRED_SECRET_PRIVKEY;
typedef struct _SCH_CRED_SECRET_WINSOCK2 SCH_CRED_SECRET_WINSOCK2;
typedef BOOL (*SSL_CRACK_CERTIFICATE_FN)(PUCHAR, DWORD, BOOL, PX509Certificate *);
typedef struct _SSL_CREDENTIAL_CERTIFICATE SSL_CREDENTIAL_CERTIFICATE;
typedef void (*SSL_FREE_CERTIFICATE_FN)(PX509Certificate);
typedef DWORD (*SSL_GET_PROTOCOLS_FN)();
typedef BOOL (*SSL_SET_PROTOCOLS_FN)(DWORD);
typedef struct _SecPkgContext_ConnectionInfo SecPkgContext_ConnectionInfo;
typedef struct _SecPkgContext_IssuerListInfo SecPkgContext_IssuerListInfo;
typedef struct _SecPkgContext_LocalCredentialInfo SecPkgContext_LocalCredentialInfo;
typedef struct _SecPkgContext_RemoteCredentialInfo SecPkgContext_RemoteCredentialInfo;
typedef struct _SecPkgCred_SupportedProtocols SecPkgCred_SupportedProtocols;
typedef struct _X509Certificate X509Certificate;
struct _PctPublicKey {
    DWORD Type;
    DWORD cbKey;
    UCHAR pKey[1];
};

struct _HMAPPER;
struct _SCH_CRED {
    DWORD dwVersion;
    DWORD cCreds;
    PVOID *paSecret;
    PVOID *paPublic;
    DWORD cMappers;
    struct _HMAPPER **aphMappers;
};

struct _SCH_CRED_PUBLIC_CERTCHAIN {
    DWORD dwType;
    DWORD cbCertChain;
    PBYTE pCertChain;
};

struct _SCH_CRED_SECRET_CAPI {
    DWORD dwType;
    HCRYPTPROV hProv;
};

struct _SCH_CRED_SECRET_PRIVKEY {
    DWORD dwType;
    PBYTE pPrivateKey;
    DWORD cbPrivateKey;
    PSTR pszPassword;
};

struct _SCH_CRED_SECRET_WINSOCK2 {
    DWORD dwType;
    SSLKEYEXCHANGEFUNC pKeyExchangeHookFunc;
    LPVOID pKeyExchangeHookArg;
    SSLSIGNATUREFUNC pSignatureHookFunc;
    LPVOID pSignatureHookArg;
};

struct _SSL_CREDENTIAL_CERTIFICATE {
    DWORD cbPrivateKey;
    PBYTE pPrivateKey;
    DWORD cbCertificate;
    PBYTE pCertificate;
    PSTR pszPassword;
};

struct _SecPkgContext_ConnectionInfo {
    DWORD dwProtocol;
    ALG_ID aiCipher;
    DWORD dwCipherStrength;
    ALG_ID aiHash;
    DWORD dwHashStrength;
    ALG_ID aiExch;
    DWORD dwExchStrength;
};

struct _SecPkgContext_IssuerListInfo {
    DWORD cbIssuerList;
    PBYTE pIssuerList;
};

struct _SecPkgContext_LocalCredentialInfo {
    DWORD cbCertificateChain;
    PBYTE pbCertificateChain;
    DWORD cCertificates;
    DWORD fFlags;
    DWORD dwBits;
};

struct _SecPkgContext_RemoteCredentialInfo {
    DWORD cbCertificateChain;
    PBYTE pbCertificateChain;
    DWORD cCertificates;
    DWORD fFlags;
    DWORD dwBits;
};

struct _SecPkgCred_SupportedProtocols {
    DWORD grbitProtocol;
};

struct _X509Certificate {
    DWORD Version;
    DWORD SerialNumber[4];
    ALG_ID SignatureAlgorithm;
    FILETIME ValidFrom;
    FILETIME ValidUntil;
    PSTR pszIssuer;
    PSTR pszSubject;
    PctPublicKey *pPublicKey;
};


#ifdef __cplusplus
}
#endif

#endif

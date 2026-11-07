#ifndef GRIMACE_SDK_SSPI_H
#define GRIMACE_SDK_SSPI_H


#ifdef __cplusplus
extern "C" {
#endif

typedef LONG SECURITY_STATUS;
struct _SecHandle;
typedef struct _SecHandle *PSecHandle;
typedef PSecHandle PCredHandle;
typedef PSecHandle PCtxtHandle;
struct _SecBufferDesc;
typedef struct _SecBufferDesc *PSecBufferDesc;
typedef LARGE_INTEGER *PSECURITY_INTEGER;
typedef PSECURITY_INTEGER PTimeStamp;
/**
 * Accepts a client's security token and establishes or continues a server context.
 *
 * The client counterpart is InitializeSecurityContextW. Handshakes may
 * require multiple calls; SEC_I_CONTINUE_NEEDED asks the server to return
 * the output token and continue the exchange.
 *
 * @param phCredential Server credentials from AcquireCredentialsHandleW.
 * @param phContext NULL on the first call; otherwise the partial context.
 * @param pInput Client token, or NULL when the package has no initial token.
 * @param fContextReq Required context attributes.
 * @param TargetDataRep Data representation used by the target.
 * @param phNewContext Receives the new or updated context handle.
 * @param pOutput Receives the token to send to the client.
 * @param pfContextAttr Receives the established context attributes.
 * @param ptsExpiry Receives the context expiration time.
 * @return SEC_E_OK or a continuation status on success; otherwise a
 *         SEC_E_* error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS AcceptSecurityContext(PCredHandle phCredential, PCtxtHandle phContext, PSecBufferDesc pInput, unsigned long fContextReq, unsigned long TargetDataRep, PCtxtHandle phNewContext, PSecBufferDesc pOutput, unsigned long *pfContextAttr, PTimeStamp ptsExpiry);
typedef WCHAR SEC_WCHAR;
typedef void (*SEC_GET_KEY_FN)(void *, void *, unsigned long, void **, SECURITY_STATUS *);
/**
 * Acquires the current user's credentials for a security package.
 *
 * The returned handle can be used to establish contexts. Release it with
 * FreeCredentialsHandle. A NULL principal requests credentials for the
 * current security context; pGetKeyFn may be NULL if the transport has no
 * credential callback.
 *
 * @param pszPrincipal Principal name, or NULL for the current user.
 * @param pszPackage Security package name.
 * @param fCredentialUse Inbound, outbound or both.
 * @param pvLogonId Optional logon identifier.
 * @param pAuthData Package-specific credentials, or NULL for defaults.
 * @param pGetKeyFn Optional callback for retrieving a key.
 * @param pvGetKeyArgument Argument passed to pGetKeyFn.
 * @param phCredential Receives the credential handle.
 * @param ptsExpiry Receives the credential expiration time.
 * @return SEC_E_OK on success, or a SEC_E_* error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS AcquireCredentialsHandleW(SEC_WCHAR *pszPrincipal, SEC_WCHAR *pszPackage, unsigned long fCredentialUse, void *pvLogonId, void *pAuthData, SEC_GET_KEY_FN pGetKeyFn, void *pvGetKeyArgument, PCredHandle phCredential, PTimeStamp ptsExpiry);
/**
 * Applies a control token to a security context.
 *
 * The security package may modify the context in response to the token.
 *
 * @param phContext Context to update.
 * @param pInput Descriptor containing the control token.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS ApplyControlToken(PCtxtHandle phContext, PSecBufferDesc pInput);
/**
 * Deletes a security context and its local data structures.
 *
 * Do not use the context after this call.
 *
 * @param phContext Context handle to delete.
 * @return SEC_E_OK on success, or SEC_E_INVALID_HANDLE for an invalid handle.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS DeleteSecurityContext(PCtxtHandle phContext);
struct _SecPkgInfoW;
typedef struct _SecPkgInfoW *PSecPkgInfoW;
/**
 * Retrieves information about the available security packages.
 *
 * Free the returned package array with FreeContextBuffer. Use a package's
 * Name to select it in AcquireCredentialsHandleW.
 *
 * @param pcPackages Receives the number of packages.
 * @param ppPackageInfo Receives the package information array.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS EnumerateSecurityPackagesW(unsigned long *pcPackages, PSecPkgInfoW *ppPackageInfo);
/**
 * Frees a buffer allocated by a security provider.
 *
 * @param pvContextBuffer Provider-allocated buffer to free.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS FreeContextBuffer(void *pvContextBuffer);
/**
 * Releases credentials acquired by AcquireCredentialsHandleW.
 *
 * @param phCredential Credential handle to release.
 * @return SEC_E_OK on success, or SEC_E_INVALID_HANDLE for an invalid handle.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS FreeCredentialsHandle(PCredHandle phCredential);
SECURITY_STATUS ImpersonateSecurityContext(PCtxtHandle phContext);
struct _SECURITY_FUNCTION_TABLE_A;
typedef struct _SECURITY_FUNCTION_TABLE_A *PSecurityFunctionTableA;
/**
 * Returns the ANSI SSPI dispatch table.
 *
 * @return Pointer to a SecurityFunctionTableA, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
PSecurityFunctionTableA InitSecurityInterfaceA(void);
struct _SECURITY_FUNCTION_TABLE_W;
typedef struct _SECURITY_FUNCTION_TABLE_W *PSecurityFunctionTableW;
/**
 * Returns the SSPI dispatch table for calling security services indirectly.
 *
 * @return Pointer to a SecurityFunctionTable, or NULL on failure.
 *
 * @note Windows CE 3.0 and later.
 */
PSecurityFunctionTableW InitSecurityInterfaceW(void);
/**
 * Creates or continues a client security context with a remote peer.
 *
 * The returned token is opaque and must be sent to the peer. A handshake
 * may require multiple calls. Set both reserved parameters to zero. If
 * ISC_REQ_ALLOCATE_MEMORY is requested, free provider-allocated output
 * with FreeContextBuffer.
 *
 * @param phCredential Credentials from AcquireCredentialsHandleW.
 * @param phContext NULL for the first call; otherwise the partial context.
 * @param pszTargetName Security-package-specific target name.
 * @param fContextReq Required context attributes.
 * @param Reserved1 Reserved; set to zero.
 * @param TargetDataRep Data representation used by the target.
 * @param pInput Optional token received from the peer.
 * @param Reserved2 Reserved; set to zero.
 * @param phNewContext Receives the new or updated context handle.
 * @param pOutput Receives the token to send to the peer.
 * @param pfContextAttr Receives context attributes.
 * @param ptsExpiry Receives the context expiration time.
 * @return SEC_E_OK or a continuation status on success; otherwise a
 *         SEC_E_* error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS InitializeSecurityContextW(PCredHandle phCredential, PCtxtHandle phContext, SEC_WCHAR *pszTargetName, unsigned long fContextReq, unsigned long Reserved1, unsigned long TargetDataRep, PSecBufferDesc pInput, unsigned long Reserved2, PCtxtHandle phNewContext, PSecBufferDesc pOutput, unsigned long *pfContextAttr, PTimeStamp ptsExpiry);
/**
 * Creates a signature for a message using the security context.
 *
 * The message descriptor must include a SECBUFFER_TOKEN buffer for the
 * signature. A sequence number is included when sequence detection is
 * enabled by the context.
 *
 * @param phContext Context used to sign the message.
 * @param fQOP Package-specific quality-of-protection flags.
 * @param pMessage Message buffers and output signature buffer.
 * @param MessageSeqNo Transport-assigned sequence number, or zero if unused.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS MakeSignature(PCtxtHandle phContext, unsigned long fQOP, PSecBufferDesc pMessage, unsigned long MessageSeqNo);
/**
 * Queries attributes of a security context.
 *
 * The structure in pBuffer depends on ulAttribute. The security package
 * may allocate pointers inside it; release those with FreeContextBuffer.
 *
 * @param phContext Context handle to query.
 * @param ulAttribute SECPKG_ATTR_* value selecting the attribute.
 * @param pBuffer Receives the corresponding SecPkgContext_* structure.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS QueryContextAttributesW(PCtxtHandle phContext, unsigned long ulAttribute, void *pBuffer);
/**
 * Retrieves attributes of a credential.
 *
 * ulAttribute must be SECPKG_CRED_ATTR_NAMES. The caller allocates the
 * SecPkgCredentials_Names structure; free provider-allocated strings in
 * it with FreeContextBuffer.
 *
 * @param phCredential Credential handle to query.
 * @param ulAttribute Attribute to retrieve.
 * @param pBuffer Receives the requested attribute structure.
 * @return SEC_E_OK on success, or a SEC_E_* error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS QueryCredentialsAttributesW(PCredHandle phCredential, unsigned long ulAttribute, void *pBuffer);
/**
 * Retrieves information about a security package.
 *
 * Free the returned package information with FreeContextBuffer.
 *
 * @param pszPackageName Null-terminated package name.
 * @param ppPackageInfo Receives the package information.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS QuerySecurityPackageInfoW(SEC_WCHAR *pszPackageName, PSecPkgInfoW *ppPackageInfo);
SECURITY_STATUS RevertSecurityContext(PCtxtHandle phContext);
/**
 * Verifies a message signature using the security context.
 *
 * The message descriptor contains the message and a SECBUFFER_TOKEN
 * signature buffer. Supply the expected sequence number, or zero if the
 * transport does not maintain sequence numbers.
 *
 * @param phContext Context used to verify the signature.
 * @param pMessage Message and signature buffers.
 * @param MessageSeqNo Expected transport sequence number, or zero.
 * @param pfQOP Receives package-specific quality-of-protection flags.
 * @return SEC_E_OK on success, or a nonzero error code.
 *
 * @note Windows CE 3.0 and later.
 */
SECURITY_STATUS VerifySignature(PCtxtHandle phContext, PSecBufferDesc pMessage, unsigned long MessageSeqNo, unsigned long *pfQOP);
typedef SECURITY_STATUS (*ACCEPT_SECURITY_CONTEXT_FN)(PCredHandle, PCtxtHandle, PSecBufferDesc, unsigned long, unsigned long, PCtxtHandle, PSecBufferDesc, unsigned long *, PTimeStamp);
typedef CHAR SEC_CHAR;
typedef SECURITY_STATUS (*ACQUIRE_CREDENTIALS_HANDLE_FN_A)(SEC_CHAR *, SEC_CHAR *, unsigned long, void *, void *, SEC_GET_KEY_FN, void *, PCredHandle, PTimeStamp);
typedef SECURITY_STATUS (*ACQUIRE_CREDENTIALS_HANDLE_FN_W)(SEC_WCHAR *, SEC_WCHAR *, unsigned long, void *, void *, SEC_GET_KEY_FN, void *, PCredHandle, PTimeStamp);
typedef SECURITY_STATUS (*APPLY_CONTROL_TOKEN_FN)(PCtxtHandle, PSecBufferDesc);
typedef SECURITY_STATUS (*COMPLETE_AUTH_TOKEN_FN)(PCtxtHandle, PSecBufferDesc);
typedef struct _SecHandle SecHandle;
typedef SecHandle CredHandle;
typedef SecHandle CtxtHandle;
typedef SECURITY_STATUS (*DECRYPT_MESSAGE_FN)(PCtxtHandle, PSecBufferDesc, unsigned long, unsigned long *);
typedef SECURITY_STATUS (*DELETE_SECURITY_CONTEXT_FN)(PCtxtHandle);
typedef SECURITY_STATUS (*ENCRYPT_MESSAGE_FN)(PCtxtHandle, unsigned long, PSecBufferDesc, unsigned long);
struct _SecPkgInfoA;
typedef struct _SecPkgInfoA *PSecPkgInfoA;
typedef SECURITY_STATUS (*ENUMERATE_SECURITY_PACKAGES_FN_A)(unsigned long *, PSecPkgInfoA *);
typedef SECURITY_STATUS (*ENUMERATE_SECURITY_PACKAGES_FN_W)(unsigned long *, PSecPkgInfoW *);
typedef SECURITY_STATUS (*FREE_CONTEXT_BUFFER_FN)(void *);
typedef SECURITY_STATUS (*FREE_CREDENTIALS_HANDLE_FN)(PCredHandle);
typedef SECURITY_STATUS (*IMPERSONATE_SECURITY_CONTEXT_FN)(PCtxtHandle);
typedef SECURITY_STATUS (*INITIALIZE_SECURITY_CONTEXT_FN_A)(PCredHandle, PCtxtHandle, SEC_CHAR *, unsigned long, unsigned long, unsigned long, PSecBufferDesc, unsigned long, PCtxtHandle, PSecBufferDesc, unsigned long *, PTimeStamp);
typedef SECURITY_STATUS (*INITIALIZE_SECURITY_CONTEXT_FN_W)(PCredHandle, PCtxtHandle, SEC_WCHAR *, unsigned long, unsigned long, unsigned long, PSecBufferDesc, unsigned long, PCtxtHandle, PSecBufferDesc, unsigned long *, PTimeStamp);
typedef PSecurityFunctionTableA (*INIT_SECURITY_INTERFACE_A)(void);
typedef PSecurityFunctionTableW (*INIT_SECURITY_INTERFACE_W)(void);
typedef SECURITY_STATUS (*MAKE_SIGNATURE_FN)(PCtxtHandle, unsigned long, PSecBufferDesc, unsigned long);
struct _SECURITY_STRING;
typedef struct _SECURITY_STRING *PSECURITY_STRING;
struct _SEC_NEGOTIATION_INFO;
typedef struct _SEC_NEGOTIATION_INFO *PSEC_NEGOTIATION_INFO;
struct _SecBuffer;
typedef struct _SecBuffer *PSecBuffer;
enum _SecDelegationType {
    SecFull,
    SecService,
    SecTree,
    SecDirectory,
    SecObject
};

typedef enum _SecDelegationType *PSecDelegationType;
struct _SecPkgContext_AuthorityA;
typedef struct _SecPkgContext_AuthorityA *PSecPkgContext_AuthorityA;
struct _SecPkgContext_AuthorityW;
typedef struct _SecPkgContext_AuthorityW *PSecPkgContext_AuthorityW;
struct _SecPkgContext_DceInfo;
typedef struct _SecPkgContext_DceInfo *PSecPkgContext_DceInfo;
struct _SecPkgContext_Flags;
typedef struct _SecPkgContext_Flags *PSecPkgContext_Flags;
struct _SecPkgContext_GroupNamesW;
typedef struct _SecPkgContext_GroupNamesW *PSecPkgContext_GroupNamesW;
struct _SecPkgContext_KeyInfoA;
typedef struct _SecPkgContext_KeyInfoA *PSecPkgContext_KeyInfoA;
struct _SecPkgContext_KeyInfoW;
typedef struct _SecPkgContext_KeyInfoW *PSecPkgContext_KeyInfoW;
struct _SecPkgContext_Lifespan;
typedef struct _SecPkgContext_Lifespan *PSecPkgContext_Lifespan;
struct _SecPkgContext_NamesA;
typedef struct _SecPkgContext_NamesA *PSecPkgContext_NamesA;
struct _SecPkgContext_NamesW;
typedef struct _SecPkgContext_NamesW *PSecPkgContext_NamesW;
struct _SecPkgContext_NativeNamesA;
typedef struct _SecPkgContext_NativeNamesA *PSecPkgContext_NativeNamesA;
struct _SecPkgContext_NativeNamesW;
typedef struct _SecPkgContext_NativeNamesW *PSecPkgContext_NativeNamesW;
struct _SecPkgContext_NegotiationInfoA;
typedef struct _SecPkgContext_NegotiationInfoA *PSecPkgContext_NegotiationInfoA;
struct _SecPkgContext_NegotiationInfoW;
typedef struct _SecPkgContext_NegotiationInfoW *PSecPkgContext_NegotiationInfoW;
struct _SecPkgContext_PackageInfoA;
typedef struct _SecPkgContext_PackageInfoA *PSecPkgContext_PackageInfoA;
struct _SecPkgContext_PackageInfoW;
typedef struct _SecPkgContext_PackageInfoW *PSecPkgContext_PackageInfoW;
struct _SecPkgContext_PasswordExpiry;
typedef struct _SecPkgContext_PasswordExpiry *PSecPkgContext_PasswordExpiry;
struct _SecPkgContext_ProtoInfoA;
typedef struct _SecPkgContext_ProtoInfoA *PSecPkgContext_ProtoInfoA;
struct _SecPkgContext_ProtoInfoW;
typedef struct _SecPkgContext_ProtoInfoW *PSecPkgContext_ProtoInfoW;
struct _SecPkgContext_SessionKey;
typedef struct _SecPkgContext_SessionKey *PSecPkgContext_SessionKey;
struct _SecPkgContext_Sizes;
typedef struct _SecPkgContext_Sizes *PSecPkgContext_Sizes;
struct _SecPkgContext_StreamSizes;
typedef struct _SecPkgContext_StreamSizes *PSecPkgContext_StreamSizes;
struct _SecPkgContext_UserFlags;
typedef struct _SecPkgContext_UserFlags *PSecPkgContext_UserFlags;
struct _SecPkgCredentials_NamesA;
typedef struct _SecPkgCredentials_NamesA *PSecPkgCredentials_NamesA;
struct _SecPkgCredentials_NamesW;
typedef struct _SecPkgCredentials_NamesW *PSecPkgCredentials_NamesW;
typedef SECURITY_STATUS (*QUERY_CONTEXT_ATTRIBUTES_FN_A)(PCtxtHandle, unsigned long, void *);
typedef SECURITY_STATUS (*QUERY_CONTEXT_ATTRIBUTES_FN_W)(PCtxtHandle, unsigned long, void *);
typedef SECURITY_STATUS (*QUERY_CREDENTIALS_ATTRIBUTES_FN_A)(PCredHandle, unsigned long, void *);
typedef SECURITY_STATUS (*QUERY_CREDENTIALS_ATTRIBUTES_FN_W)(PCredHandle, unsigned long, void *);
typedef SECURITY_STATUS (*QUERY_SECURITY_CONTEXT_TOKEN_FN)(PCtxtHandle, void **);
typedef SECURITY_STATUS (*QUERY_SECURITY_PACKAGE_INFO_FN_A)(SEC_CHAR *, PSecPkgInfoA *);
typedef SECURITY_STATUS (*QUERY_SECURITY_PACKAGE_INFO_FN_W)(SEC_WCHAR *, PSecPkgInfoW *);
typedef SECURITY_STATUS (*REVERT_SECURITY_CONTEXT_FN)(PCtxtHandle);
typedef LARGE_INTEGER SECURITY_INTEGER;
typedef const SEC_WCHAR *SECURITY_PCSTR;
typedef SEC_WCHAR *SECURITY_PSTR;
typedef struct _SECURITY_STRING SECURITY_STRING;
typedef struct _SEC_NEGOTIATION_INFO SEC_NEGOTIATION_INFO;
typedef struct _SecBuffer SecBuffer;
typedef struct _SecBufferDesc SecBufferDesc;
typedef enum _SecDelegationType SecDelegationType;
typedef struct _SecPkgContext_AuthorityA SecPkgContext_AuthorityA;
typedef struct _SecPkgContext_AuthorityW SecPkgContext_AuthorityW;
typedef struct _SecPkgContext_DceInfo SecPkgContext_DceInfo;
typedef struct _SecPkgContext_Flags SecPkgContext_Flags;
typedef struct _SecPkgContext_GroupNamesW SecPkgContext_GroupNamesW;
typedef struct _SecPkgContext_KeyInfoA SecPkgContext_KeyInfoA;
typedef struct _SecPkgContext_KeyInfoW SecPkgContext_KeyInfoW;
typedef struct _SecPkgContext_Lifespan SecPkgContext_Lifespan;
typedef struct _SecPkgContext_NamesA SecPkgContext_NamesA;
typedef struct _SecPkgContext_NamesW SecPkgContext_NamesW;
typedef struct _SecPkgContext_NativeNamesA SecPkgContext_NativeNamesA;
typedef struct _SecPkgContext_NativeNamesW SecPkgContext_NativeNamesW;
typedef struct _SecPkgContext_NegotiationInfoA SecPkgContext_NegotiationInfoA;
typedef struct _SecPkgContext_NegotiationInfoW SecPkgContext_NegotiationInfoW;
typedef struct _SecPkgContext_PackageInfoA SecPkgContext_PackageInfoA;
typedef struct _SecPkgContext_PackageInfoW SecPkgContext_PackageInfoW;
typedef struct _SecPkgContext_PasswordExpiry SecPkgContext_PasswordExpiry;
typedef struct _SecPkgContext_ProtoInfoA SecPkgContext_ProtoInfoA;
typedef struct _SecPkgContext_ProtoInfoW SecPkgContext_ProtoInfoW;
typedef struct _SecPkgContext_SessionKey SecPkgContext_SessionKey;
typedef struct _SecPkgContext_Sizes SecPkgContext_Sizes;
typedef struct _SecPkgContext_StreamSizes SecPkgContext_StreamSizes;
typedef struct _SecPkgContext_UserFlags SecPkgContext_UserFlags;
typedef struct _SecPkgCredentials_NamesA SecPkgCredentials_NamesA;
typedef struct _SecPkgCredentials_NamesW SecPkgCredentials_NamesW;
typedef struct _SecPkgInfoA SecPkgInfoA;
typedef struct _SecPkgInfoW SecPkgInfoW;
typedef struct _SECURITY_FUNCTION_TABLE_A SecurityFunctionTableA;
typedef struct _SECURITY_FUNCTION_TABLE_W SecurityFunctionTableW;
typedef SECURITY_INTEGER TimeStamp;
typedef SECURITY_STATUS (*VERIFY_SIGNATURE_FN)(PCtxtHandle, PSecBufferDesc, unsigned long, unsigned long *);
typedef LARGE_INTEGER _SECURITY_INTEGER;
struct _SECURITY_FUNCTION_TABLE_A {
    unsigned long dwVersion;
    ENUMERATE_SECURITY_PACKAGES_FN_A EnumerateSecurityPackagesA;
    QUERY_CREDENTIALS_ATTRIBUTES_FN_A QueryCredentialsAttributesA;
    ACQUIRE_CREDENTIALS_HANDLE_FN_A AcquireCredentialsHandleA;
    FREE_CREDENTIALS_HANDLE_FN FreeCredentialsHandle;
    void *Reserved2;
    INITIALIZE_SECURITY_CONTEXT_FN_A InitializeSecurityContextA;
    ACCEPT_SECURITY_CONTEXT_FN AcceptSecurityContext;
    COMPLETE_AUTH_TOKEN_FN CompleteAuthToken;
    DELETE_SECURITY_CONTEXT_FN DeleteSecurityContext;
    APPLY_CONTROL_TOKEN_FN ApplyControlToken;
    QUERY_CONTEXT_ATTRIBUTES_FN_A QueryContextAttributesA;
    IMPERSONATE_SECURITY_CONTEXT_FN ImpersonateSecurityContext;
    REVERT_SECURITY_CONTEXT_FN RevertSecurityContext;
    MAKE_SIGNATURE_FN MakeSignature;
    VERIFY_SIGNATURE_FN VerifySignature;
    FREE_CONTEXT_BUFFER_FN FreeContextBuffer;
    QUERY_SECURITY_PACKAGE_INFO_FN_A QuerySecurityPackageInfoA;
    void *Reserved3;
    void *Reserved4;
    void *Reserved5;
    void *Reserved6;
    void *Reserved7;
    void *Reserved8;
    QUERY_SECURITY_CONTEXT_TOKEN_FN QuerySecurityContextToken;
    ENCRYPT_MESSAGE_FN EncryptMessage;
    DECRYPT_MESSAGE_FN DecryptMessage;
};

struct _SECURITY_FUNCTION_TABLE_W {
    unsigned long dwVersion;
    ENUMERATE_SECURITY_PACKAGES_FN_W EnumerateSecurityPackagesW;
    QUERY_CREDENTIALS_ATTRIBUTES_FN_W QueryCredentialsAttributesW;
    ACQUIRE_CREDENTIALS_HANDLE_FN_W AcquireCredentialsHandleW;
    FREE_CREDENTIALS_HANDLE_FN FreeCredentialsHandle;
    void *Reserved2;
    INITIALIZE_SECURITY_CONTEXT_FN_W InitializeSecurityContextW;
    ACCEPT_SECURITY_CONTEXT_FN AcceptSecurityContext;
    COMPLETE_AUTH_TOKEN_FN CompleteAuthToken;
    DELETE_SECURITY_CONTEXT_FN DeleteSecurityContext;
    APPLY_CONTROL_TOKEN_FN ApplyControlToken;
    QUERY_CONTEXT_ATTRIBUTES_FN_W QueryContextAttributesW;
    IMPERSONATE_SECURITY_CONTEXT_FN ImpersonateSecurityContext;
    REVERT_SECURITY_CONTEXT_FN RevertSecurityContext;
    MAKE_SIGNATURE_FN MakeSignature;
    VERIFY_SIGNATURE_FN VerifySignature;
    FREE_CONTEXT_BUFFER_FN FreeContextBuffer;
    QUERY_SECURITY_PACKAGE_INFO_FN_W QuerySecurityPackageInfoW;
    void *Reserved3;
    void *Reserved4;
    void *Reserved5;
    void *Reserved6;
    void *Reserved7;
    void *Reserved8;
    QUERY_SECURITY_CONTEXT_TOKEN_FN QuerySecurityContextToken;
    ENCRYPT_MESSAGE_FN EncryptMessage;
    DECRYPT_MESSAGE_FN DecryptMessage;
};

struct _SECURITY_STRING {
    unsigned short Length;
    unsigned short MaximumLength;
    unsigned short *Buffer;
};

struct _SEC_NEGOTIATION_INFO {
    unsigned long Size;
    unsigned long NameLength;
    SEC_WCHAR *Name;
    void *Reserved;
};

struct _SecBuffer {
    unsigned long cbBuffer;
    unsigned long BufferType;
    void *pvBuffer;
};

struct _SecBufferDesc {
    unsigned long ulVersion;
    unsigned long cBuffers;
    PSecBuffer pBuffers;
};

struct _SecHandle {
    ULONG_PTR dwLower;
    ULONG_PTR dwUpper;
};

struct _SecPkgContext_AuthorityA {
    SEC_CHAR *sAuthorityName;
};

struct _SecPkgContext_AuthorityW {
    SEC_WCHAR *sAuthorityName;
};

struct _SecPkgContext_DceInfo {
    unsigned long AuthzSvc;
    void *pPac;
};

struct _SecPkgContext_Flags {
    unsigned long Flags;
};

struct _SecPkgContext_GroupNamesW {
    SEC_WCHAR *msGroupNames;
};

struct _SecPkgContext_KeyInfoA {
    SEC_CHAR *sSignatureAlgorithmName;
    SEC_CHAR *sEncryptAlgorithmName;
    unsigned long KeySize;
    unsigned long SignatureAlgorithm;
    unsigned long EncryptAlgorithm;
};

struct _SecPkgContext_KeyInfoW {
    SEC_WCHAR *sSignatureAlgorithmName;
    SEC_WCHAR *sEncryptAlgorithmName;
    unsigned long KeySize;
    unsigned long SignatureAlgorithm;
    unsigned long EncryptAlgorithm;
};

struct _SecPkgContext_Lifespan {
    TimeStamp tsStart;
    TimeStamp tsExpiry;
};

struct _SecPkgContext_NamesA {
    SEC_CHAR *sUserName;
};

struct _SecPkgContext_NamesW {
    SEC_WCHAR *sUserName;
};

struct _SecPkgContext_NativeNamesA {
    SEC_CHAR *sClientName;
    SEC_CHAR *sServerName;
};

struct _SecPkgContext_NativeNamesW {
    SEC_WCHAR *sClientName;
    SEC_WCHAR *sServerName;
};

struct _SecPkgContext_NegotiationInfoA {
    PSecPkgInfoA PackageInfo;
    unsigned long NegotiationState;
};

struct _SecPkgContext_NegotiationInfoW {
    PSecPkgInfoW PackageInfo;
    unsigned long NegotiationState;
};

struct _SecPkgContext_PackageInfoA {
    PSecPkgInfoA PackageInfo;
};

struct _SecPkgContext_PackageInfoW {
    PSecPkgInfoW PackageInfo;
};

struct _SecPkgContext_PasswordExpiry {
    TimeStamp tsPasswordExpires;
};

struct _SecPkgContext_ProtoInfoA {
    SEC_CHAR *sProtocolName;
    unsigned long majorVersion;
    unsigned long minorVersion;
};

struct _SecPkgContext_ProtoInfoW {
    SEC_WCHAR *sProtocolName;
    unsigned long majorVersion;
    unsigned long minorVersion;
};

struct _SecPkgContext_SessionKey {
    unsigned long SessionKeyLength;
    unsigned char *SessionKey;
};

struct _SecPkgContext_Sizes {
    unsigned long cbMaxToken;
    unsigned long cbMaxSignature;
    unsigned long cbBlockSize;
    unsigned long cbSecurityTrailer;
};

struct _SecPkgContext_StreamSizes {
    unsigned long cbHeader;
    unsigned long cbTrailer;
    unsigned long cbMaximumMessage;
    unsigned long cBuffers;
    unsigned long cbBlockSize;
};

struct _SecPkgContext_UserFlags {
    unsigned long UserFlags;
};

struct _SecPkgCredentials_NamesA {
    SEC_CHAR *sUserName;
};

struct _SecPkgCredentials_NamesW {
    SEC_WCHAR *sUserName;
};

struct _SecPkgInfoA {
    unsigned long fCapabilities;
    unsigned short wVersion;
    unsigned short wRPCID;
    unsigned long cbMaxToken;
    SEC_CHAR *Name;
    SEC_CHAR *Comment;
};

struct _SecPkgInfoW {
    unsigned long fCapabilities;
    unsigned short wVersion;
    unsigned short wRPCID;
    unsigned long cbMaxToken;
    SEC_WCHAR *Name;
    SEC_WCHAR *Comment;
};


#ifdef __cplusplus
}
#endif

#endif

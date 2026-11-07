#ifndef GRIMACE_SDK_WINCRYPT_H
#define GRIMACE_SDK_WINCRYPT_H


#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long HCRYPTPROV;
/**
 * Acquires a handle to a cryptographic service provider and key container.
 *
 * Use CRYPT_VERIFYCONTEXT with a NULL container when private keys are not
 * needed. Release a successful context with CryptReleaseContext.
 *
 * @param phProv Receives the provider handle.
 * @param pszContainer Key-container name, or NULL for the default.
 * @param pszProvider Provider name, or NULL for the default provider.
 * @param dwProvType Provider type.
 * @param dwFlags Context and key-container options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptAcquireContextW(HCRYPTPROV *phProv, LPCWSTR pszContainer, LPCWSTR pszProvider, DWORD dwProvType, DWORD dwFlags);
/**
 * Increments the reference count of a provider handle.
 *
 * Set the reserved parameters to NULL and zero. Each added reference
 * requires a matching CryptReleaseContext call.
 *
 * @param hProv Provider handle.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptContextAddRef(HCRYPTPROV hProv, DWORD *pdwReserved, DWORD dwFlags);
typedef unsigned int ALG_ID;
typedef unsigned long HCRYPTKEY;
typedef unsigned long HCRYPTHASH;
/**
 * Creates a hash object for the specified algorithm.
 *
 * Pass hKey as zero for an unkeyed hash; keyed algorithms require a key.
 * Add data with CryptHashData or CryptHashSessionKey. Destroy the hash
 * with CryptDestroyHash when finished.
 *
 * @param hProv Provider handle.
 * @param Algid Hash algorithm identifier.
 * @param hKey Key for a keyed hash, or zero for an unkeyed hash.
 * @param dwFlags Reserved; set to zero.
 * @param phHash Receives the hash handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptCreateHash(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH *phHash);
/**
 * Decrypts data in place with the specified key.
 *
 * Set Final for the last block. For block ciphers, non-final data length
 * must be a multiple of the block size. hHash can receive a hash of the
 * decrypted plaintext, or be zero if no hash is needed.
 *
 * @param hKey Decryption key.
 * @param hHash Optional hash handle, or zero.
 * @param Final TRUE for the final block.
 * @param dwFlags Reserved; set to zero.
 * @param pbData Encrypted data; receives plaintext.
 * @param pdwDataLen Input byte count; receives plaintext byte count.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDecrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);
/**
 * Derives a key from the data in a hash object.
 *
 * Create and fill hBaseData first. After this call, the hash is finished;
 * destroy it with CryptDestroyHash. Set CRYPT_EXPORTABLE if the key must
 * be exported.
 *
 * @param hProv Provider handle.
 * @param Algid Algorithm identifier for the new key.
 * @param hBaseData Hash containing the derivation data.
 * @param dwFlags Key options.
 * @param phKey Receives the derived key handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDeriveKey(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY *phKey);
/**
 * Destroys a hash object and releases its resources.
 *
 * @param hHash Hash handle to destroy.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDestroyHash(HCRYPTHASH hHash);
/**
 * Destroys a key handle and releases its resources.
 *
 * Destroy session and imported keys when finished. For a user key pair,
 * this releases the handle but does not destroy the stored key pair.
 *
 * @param hKey Key handle to destroy.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDestroyKey(HCRYPTKEY hKey);
/**
 * Creates an independent copy of a hash object and its current state.
 *
 * Destroy both handles separately with CryptDestroyHash. Set reserved
 * parameters to NULL and zero.
 *
 * @param hHash Hash handle to copy.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @param phHash Receives the duplicate handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDuplicateHash(HCRYPTHASH hHash, DWORD *pdwReserved, DWORD dwFlags, HCRYPTHASH *phHash);
/**
 * Creates an independent copy of a key and its current state.
 *
 * Destroy both handles separately with CryptDestroyKey. Set reserved
 * parameters to NULL and zero.
 *
 * @param hKey Key handle to copy.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @param phKey Receives the duplicate handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptDuplicateKey(HCRYPTKEY hKey, DWORD *pdwReserved, DWORD dwFlags, HCRYPTKEY *phKey);
/**
 * Encrypts data in place with the specified key.
 *
 * Set Final for the last block. For block ciphers, non-final data length
 * must be a multiple of the block size. Set pbData to NULL to query the
 * required output size. hHash can receive a hash of the plaintext.
 *
 * @param hKey Encryption key.
 * @param hHash Optional hash handle, or zero.
 * @param Final TRUE for the final block.
 * @param dwFlags Reserved; set to zero.
 * @param pbData Data to encrypt; receives ciphertext.
 * @param pdwDataLen Input byte count; receives ciphertext byte count.
 * @param dwBufLen Size of pbData in bytes.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptEncrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen, DWORD dwBufLen);
/**
 * Enumerates the cryptographic provider types available on the device.
 *
 * Use CRYPT_FIRST to begin enumeration. Set pszTypeName to NULL to query
 * the required name-buffer size. ERROR_NO_MORE_ITEMS indicates completion.
 *
 * @param dwIndex Index of the provider type to enumerate.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @param pdwProvType Receives the provider type.
 * @param pszTypeName Receives its name, or NULL to query size.
 * @param pcbTypeName Input buffer size and output bytes written.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptEnumProviderTypesW(DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPWSTR pszTypeName, DWORD *pcbTypeName);
/**
 * Enumerates the installed cryptographic service providers.
 *
 * Use CRYPT_FIRST to begin enumeration. Set pszProvName to NULL to query
 * the required name-buffer size. ERROR_NO_MORE_ITEMS indicates completion.
 *
 * @param dwIndex Index of the provider to enumerate.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @param pdwProvType Receives the provider type.
 * @param pszProvName Receives the provider name, or NULL to query size.
 * @param pcbProvName Input buffer size and output bytes written.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptEnumProvidersW(DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPWSTR pszProvName, DWORD *pcbProvName);
/**
 * Exports a key as a key BLOB for storage or transfer.
 *
 * Set pbData to NULL to query the required size. A public-key BLOB does
 * not use hExpKey; other BLOB types may require an export-encryption key.
 * The key must be exportable.
 *
 * @param hKey Key to export.
 * @param hExpKey Key used to encrypt the BLOB, or zero when unused.
 * @param dwBlobType SIMPLEBLOB, PUBLICKEYBLOB, PRIVATEKEYBLOB or OPAQUEBLOB.
 * @param dwFlags Reserved; set to zero.
 * @param pbData Receives the BLOB, or NULL to query size.
 * @param pdwDataLen Input buffer size and output bytes written or required.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptExportKey(HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);
/**
 * Generates a random cryptographic key for an algorithm.
 *
 * Set CRYPT_EXPORTABLE if the key must be exported. For RSA keys, the
 * upper 16 bits of dwFlags can specify the key size in bits.
 *
 * @param hProv Provider handle.
 * @param Algid Algorithm or key specification.
 * @param dwFlags Key size and generation options.
 * @param phKey Receives the key handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGenKey(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY *phKey);
/**
 * Fills a buffer with cryptographically random bytes.
 *
 * The caller can seed the provider by placing additional random data in
 * pbBuffer before calling.
 *
 * @param hProv Provider handle.
 * @param dwLen Number of bytes to generate.
 * @param pbBuffer Buffer that receives the bytes and may contain seed data.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGenRandom(HCRYPTPROV hProv, DWORD dwLen, BYTE *pbBuffer);
/**
 * Retrieves the default provider name for a provider type.
 *
 * Use CRYPT_USER_DEFAULT or CRYPT_MACHINE_DEFAULT. Set pszProvName to
 * NULL to query the required buffer size.
 *
 * @param dwProvType Provider type.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags User or machine default selector.
 * @param pszProvName Receives the provider name, or NULL to query size.
 * @param pcbProvName Input buffer size and output bytes written.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGetDefaultProviderW(DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD *pcbProvName);
/**
 * Retrieves a hash object's algorithm, size or hash value.
 *
 * Set pbData to NULL to query the required size. Reading HP_HASHVAL
 * finalizes the hash; no more data can be added afterward.
 *
 * @param hHash Hash handle.
 * @param dwParam HP_ALGID, HP_HASHSIZE, HP_HASHVAL or a CSP-specific value.
 * @param pbData Receives the parameter data, or NULL to query size.
 * @param pdwDataLen Input buffer size and output bytes written or required.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
/**
 * Retrieves parameters for a key, such as its algorithm, length, mode or IV.
 *
 * Set pbData to NULL to query the required buffer size. Base symmetric
 * key material cannot be retrieved through this function.
 *
 * @param hKey Key handle.
 * @param dwParam Key parameter to retrieve.
 * @param pbData Receives the parameter data, or NULL to query size.
 * @param pdwDataLen Input buffer size and output bytes written or required.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGetKeyParam(HCRYPTKEY hKey, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
/**
 * Retrieves configuration or enumeration data from a provider.
 *
 * PP_ENUMALGS and PP_ENUMCONTAINERS enumerate entries across repeated
 * calls. Use CRYPT_FIRST for the first entry; ERROR_NO_MORE_ITEMS marks
 * the end. Set pbData to NULL to query buffer size.
 *
 * @param hProv Provider handle.
 * @param dwParam Provider parameter to retrieve.
 * @param pbData Receives the parameter data, or NULL to query size.
 * @param pdwDataLen Input buffer size and output bytes written or required.
 * @param dwFlags Enumeration or security-information flags.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGetProvParam(HCRYPTPROV hProv, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
/**
 * Retrieves a handle to a permanent user key pair.
 *
 * dwKeySpec is typically AT_KEYEXCHANGE or AT_SIGNATURE. Destroy the
 * returned handle with CryptDestroyKey when finished.
 *
 * @param hProv Provider handle.
 * @param dwKeySpec Key pair to retrieve.
 * @param phUserKey Receives the key handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptGetUserKey(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY *phUserKey);
/**
 * Adds data to a hash object.
 *
 * Call CryptCreateHash first. Calls can be repeated for chunks of a
 * stream. No more data can be added after the hash has been finalized.
 *
 * @param hHash Hash handle.
 * @param pbData Data to hash.
 * @param dwDataLen Number of bytes to hash.
 * @param dwFlags Hash options.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptHashData(HCRYPTHASH hHash, const BYTE *pbData, DWORD dwDataLen, DWORD dwFlags);
/**
 * Adds a key object to a hash.
 *
 * Call CryptCreateHash first. This can be interleaved with CryptHashData.
 *
 * @param hHash Hash handle.
 * @param hKey Key handle to hash.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptHashSessionKey(HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags);
/**
 * Imports a key from a key BLOB into a provider.
 *
 * hPubKey depends on the BLOB type: it can be zero for an unencrypted
 * public-key BLOB, or a key used to decrypt or verify other BLOB types.
 * Destroy the imported key with CryptDestroyKey.
 *
 * @param hProv Provider handle.
 * @param pbData Key BLOB data.
 * @param dwDataLen BLOB size in bytes.
 * @param hPubKey Key used to decrypt or verify the BLOB, or zero if unused.
 * @param dwFlags Import options such as CRYPT_EXPORTABLE.
 * @param phKey Receives the imported key handle.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptImportKey(HCRYPTPROV hProv, const BYTE *pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY *phKey);
/**
 * Releases a provider context handle.
 *
 * Destroy its session keys and hash objects before release; they become
 * invalid when the context is released. Set dwFlags to zero.
 *
 * @param hProv Provider handle to release.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptReleaseContext(HCRYPTPROV hProv, DWORD dwFlags);
/**
 * Sets a supported parameter on a hash object.
 *
 * Supported parameters include HP_HMAC_INFO and HP_HASHVAL. CSP support
 * varies. Set dwFlags to zero.
 *
 * @param hHash Hash handle.
 * @param dwParam Parameter to set.
 * @param pbData Parameter data.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD dwFlags);
/**
 * Sets a supported parameter on a key, such as its IV, mode or padding.
 *
 * Supported parameters depend on the key and CSP. Set dwFlags to zero.
 *
 * @param hKey Key handle.
 * @param dwParam Key parameter to set.
 * @param pbData Parameter data.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSetKeyParam(HCRYPTKEY hKey, DWORD dwParam, BYTE *pbData, DWORD dwFlags);
/**
 * Sets a supported provider parameter.
 *
 * The Microsoft Cryptographic Providers do not support PP_CLIENT_HWND or
 * PP_KEYSET_SEC_DESCR.
 *
 * @param hProv Provider handle.
 * @param dwParam Provider parameter to set.
 * @param pbData Parameter data.
 * @param dwFlags Security-information flags when applicable.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSetProvParam(HCRYPTPROV hProv, DWORD dwParam, BYTE *pbData, DWORD dwFlags);
/**
 * Sets the user or machine default provider for a provider type.
 *
 * This affects later CryptAcquireContext calls that omit a provider name.
 * Use only with the user's consent. Set pdwReserved to NULL.
 *
 * @param pszProvName Installed provider name.
 * @param dwProvType Provider type.
 * @param pdwReserved Reserved; set to NULL.
 * @param dwFlags CRYPT_USER_DEFAULT or CRYPT_MACHINE_DEFAULT, optionally
 *                 with CRYPT_DELETE_DEFAULT.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSetProviderExW(LPCWSTR pszProvName, DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags);
/**
 * Sets the current user's default provider for a provider type.
 *
 * This affects later CryptAcquireContext calls that omit a provider name.
 * It is intended for administrative applications; use only with the
 * user's consent.
 *
 * @param pszProvName Installed provider name.
 * @param dwProvType Provider type.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSetProviderW(LPCWSTR pszProvName, DWORD dwProvType);
/**
 * Signs a completed hash with a user key pair.
 *
 * Create and fill the hash first. Set sDescription to NULL. Set
 * pbSignature to NULL to query the required size. After signing, only
 * CryptDestroyHash can be called on the hash.
 *
 * @param hHash Hash handle to sign.
 * @param dwKeySpec AT_KEYEXCHANGE or AT_SIGNATURE key pair.
 * @param sDescription Unused; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @param pbSignature Receives the signature, or NULL to query size.
 * @param pdwSigLen Input buffer size and output bytes written or required.
 * @return TRUE on success, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptSignHashW(HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE *pbSignature, DWORD *pdwSigLen);
/**
 * Verifies a signature against a completed hash.
 *
 * Use the public key corresponding to the signing key. Set sDescription
 * to NULL. After verification, only CryptDestroyHash can be called on
 * the hash.
 *
 * @param hHash Hash handle to verify.
 * @param pbSignature Signature data.
 * @param dwSigLen Signature size in bytes.
 * @param hPubKey Public key used to verify the signature.
 * @param sDescription Unused; set to NULL.
 * @param dwFlags Reserved; set to zero.
 * @return TRUE if verified, FALSE on failure; use GetLastError.
 *
 * @note Windows CE 2.0 and later.
 */
BOOL CryptVerifySignatureW(HCRYPTHASH hHash, const BYTE *pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags);
struct _PUBLICKEYSTRUC;
typedef struct _PUBLICKEYSTRUC BLOBHEADER;
struct _CRYPT_OID_INFO;
typedef struct _CRYPT_OID_INFO CRYPT_OID_INFO;
typedef const CRYPT_OID_INFO CCRYPT_OID_INFO;
struct _CERT_ALT_NAME_ENTRY;
typedef struct _CERT_ALT_NAME_ENTRY CERT_ALT_NAME_ENTRY;
struct _CERT_ALT_NAME_INFO;
typedef struct _CERT_ALT_NAME_INFO CERT_ALT_NAME_INFO;
struct _CERT_AUTHORITY_KEY_ID2_INFO;
typedef struct _CERT_AUTHORITY_KEY_ID2_INFO CERT_AUTHORITY_KEY_ID2_INFO;
struct _CERT_AUTHORITY_KEY_ID_INFO;
typedef struct _CERT_AUTHORITY_KEY_ID_INFO CERT_AUTHORITY_KEY_ID_INFO;
struct _CERT_BASIC_CONSTRAINTS2_INFO;
typedef struct _CERT_BASIC_CONSTRAINTS2_INFO CERT_BASIC_CONSTRAINTS2_INFO;
struct _CERT_BASIC_CONSTRAINTS_INFO;
typedef struct _CERT_BASIC_CONSTRAINTS_INFO CERT_BASIC_CONSTRAINTS_INFO;
struct _CRYPTOAPI_BLOB;
typedef struct _CRYPTOAPI_BLOB CERT_BLOB;
struct _CERT_CHAIN;
typedef struct _CERT_CHAIN CERT_CHAIN;
struct _CERT_CONTEXT;
typedef struct _CERT_CONTEXT CERT_CONTEXT;
struct _CERT_DSS_PARAMETERS;
typedef struct _CERT_DSS_PARAMETERS CERT_DSS_PARAMETERS;
struct _CTL_USAGE;
typedef struct _CTL_USAGE CERT_ENHKEY_USAGE;
struct _CERT_EXTENSION;
typedef struct _CERT_EXTENSION CERT_EXTENSION;
struct _CERT_EXTENSIONS;
typedef struct _CERT_EXTENSIONS CERT_EXTENSIONS;
struct _CERT_INFO;
typedef struct _CERT_INFO CERT_INFO;
struct _CERT_KEYGEN_REQUEST_INFO;
typedef struct _CERT_KEYGEN_REQUEST_INFO CERT_KEYGEN_REQUEST_INFO;
struct _CERT_KEY_ATTRIBUTES_INFO;
typedef struct _CERT_KEY_ATTRIBUTES_INFO CERT_KEY_ATTRIBUTES_INFO;
struct _CERT_KEY_CONTEXT;
typedef struct _CERT_KEY_CONTEXT CERT_KEY_CONTEXT;
struct _CERT_KEY_USAGE_RESTRICTION_INFO;
typedef struct _CERT_KEY_USAGE_RESTRICTION_INFO CERT_KEY_USAGE_RESTRICTION_INFO;
typedef struct _CRYPTOAPI_BLOB CERT_NAME_BLOB;
struct _CERT_NAME_INFO;
typedef struct _CERT_NAME_INFO CERT_NAME_INFO;
struct _CERT_NAME_VALUE;
typedef struct _CERT_NAME_VALUE CERT_NAME_VALUE;
struct _CERT_POLICIES_INFO;
typedef struct _CERT_POLICIES_INFO CERT_POLICIES_INFO;
struct _CERT_POLICY_ID;
typedef struct _CERT_POLICY_ID CERT_POLICY_ID;
struct _CERT_POLICY_INFO;
typedef struct _CERT_POLICY_INFO CERT_POLICY_INFO;
struct _CERT_POLICY_QUALIFIER_INFO;
typedef struct _CERT_POLICY_QUALIFIER_INFO CERT_POLICY_QUALIFIER_INFO;
struct _CERT_PRIVATE_KEY_VALIDITY;
typedef struct _CERT_PRIVATE_KEY_VALIDITY CERT_PRIVATE_KEY_VALIDITY;
struct _CERT_PUBLIC_KEY_INFO;
typedef struct _CERT_PUBLIC_KEY_INFO CERT_PUBLIC_KEY_INFO;
struct _CERT_RDN;
typedef struct _CERT_RDN CERT_RDN;
struct _CERT_RDN_ATTR;
typedef struct _CERT_RDN_ATTR CERT_RDN_ATTR;
typedef struct _CRYPTOAPI_BLOB CERT_RDN_VALUE_BLOB;
struct _CERT_REQUEST_INFO;
typedef struct _CERT_REQUEST_INFO CERT_REQUEST_INFO;
struct _CERT_REVOCATION_PARA;
typedef struct _CERT_REVOCATION_PARA CERT_REVOCATION_PARA;
struct _CERT_REVOCATION_STATUS;
typedef struct _CERT_REVOCATION_STATUS CERT_REVOCATION_STATUS;
struct _CERT_SIGNED_CONTENT_INFO;
typedef struct _CERT_SIGNED_CONTENT_INFO CERT_SIGNED_CONTENT_INFO;
struct _CERT_STORE_PROV_INFO;
typedef struct _CERT_STORE_PROV_INFO CERT_STORE_PROV_INFO;
struct _CRYPT_ATTRIBUTES;
typedef struct _CRYPT_ATTRIBUTES CRYPT_ATTRIBUTES;
typedef CRYPT_ATTRIBUTES CMSG_ATTR;
struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA;
typedef struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA;
struct _CMSG_CTRL_DECRYPT_PARA;
typedef struct _CMSG_CTRL_DECRYPT_PARA CMSG_CTRL_DECRYPT_PARA;
struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA;
typedef struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA;
struct _CMSG_ENCRYPTED_ENCODE_INFO;
typedef struct _CMSG_ENCRYPTED_ENCODE_INFO CMSG_ENCRYPTED_ENCODE_INFO;
struct _CMSG_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_ENVELOPED_ENCODE_INFO CMSG_ENVELOPED_ENCODE_INFO;
struct _CMSG_HASHED_ENCODE_INFO;
typedef struct _CMSG_HASHED_ENCODE_INFO CMSG_HASHED_ENCODE_INFO;
struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO;
struct _CMSG_SIGNED_ENCODE_INFO;
typedef struct _CMSG_SIGNED_ENCODE_INFO CMSG_SIGNED_ENCODE_INFO;
struct _CMSG_SIGNER_ENCODE_INFO;
typedef struct _CMSG_SIGNER_ENCODE_INFO CMSG_SIGNER_ENCODE_INFO;
struct _CMSG_SIGNER_INFO;
typedef struct _CMSG_SIGNER_INFO CMSG_SIGNER_INFO;
struct _CMSG_STREAM_INFO;
typedef struct _CMSG_STREAM_INFO CMSG_STREAM_INFO;
typedef struct _CRYPTOAPI_BLOB CRL_BLOB;
struct _CRL_CONTEXT;
typedef struct _CRL_CONTEXT CRL_CONTEXT;
struct _CRL_DIST_POINT;
typedef struct _CRL_DIST_POINT CRL_DIST_POINT;
struct _CRL_DIST_POINTS_INFO;
typedef struct _CRL_DIST_POINTS_INFO CRL_DIST_POINTS_INFO;
struct _CRL_DIST_POINT_NAME;
typedef struct _CRL_DIST_POINT_NAME CRL_DIST_POINT_NAME;
struct _CRL_ENTRY;
typedef struct _CRL_ENTRY CRL_ENTRY;
struct _CRL_INFO;
typedef struct _CRL_INFO CRL_INFO;
struct _CRYPT_ALGORITHM_IDENTIFIER;
typedef struct _CRYPT_ALGORITHM_IDENTIFIER CRYPT_ALGORITHM_IDENTIFIER;
struct _CRYPT_ATTRIBUTE;
typedef struct _CRYPT_ATTRIBUTE CRYPT_ATTRIBUTE;
struct _CRYPT_ATTRIBUTE_TYPE_VALUE;
typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE CRYPT_ATTRIBUTE_TYPE_VALUE;
typedef struct _CRYPTOAPI_BLOB CRYPT_ATTR_BLOB;
struct _CRYPT_BIT_BLOB;
typedef struct _CRYPT_BIT_BLOB CRYPT_BIT_BLOB;
struct _CRYPT_CONTENT_INFO;
typedef struct _CRYPT_CONTENT_INFO CRYPT_CONTENT_INFO;
struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY;
typedef struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY;
typedef struct _CRYPTOAPI_BLOB CRYPT_DATA_BLOB;
struct _CRYPT_DECRYPT_MESSAGE_PARA;
typedef struct _CRYPT_DECRYPT_MESSAGE_PARA CRYPT_DECRYPT_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB CRYPT_DER_BLOB;
typedef struct _CRYPTOAPI_BLOB CRYPT_DIGEST_BLOB;
struct _CRYPT_ENCRYPT_MESSAGE_PARA;
typedef struct _CRYPT_ENCRYPT_MESSAGE_PARA CRYPT_ENCRYPT_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB CRYPT_HASH_BLOB;
struct _CRYPT_HASH_INFO;
typedef struct _CRYPT_HASH_INFO CRYPT_HASH_INFO;
struct _CRYPT_HASH_MESSAGE_PARA;
typedef struct _CRYPT_HASH_MESSAGE_PARA CRYPT_HASH_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB CRYPT_INTEGER_BLOB;
struct _CRYPT_KEY_PROV_INFO;
typedef struct _CRYPT_KEY_PROV_INFO CRYPT_KEY_PROV_INFO;
struct _CRYPT_KEY_PROV_PARAM;
typedef struct _CRYPT_KEY_PROV_PARAM CRYPT_KEY_PROV_PARAM;
struct _CRYPT_KEY_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_KEY_SIGN_MESSAGE_PARA CRYPT_KEY_SIGN_MESSAGE_PARA;
struct _CRYPT_KEY_VERIFY_MESSAGE_PARA;
typedef struct _CRYPT_KEY_VERIFY_MESSAGE_PARA CRYPT_KEY_VERIFY_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB CRYPT_OBJID_BLOB;
struct _CRYPT_OBJID_TABLE;
typedef struct _CRYPT_OBJID_TABLE CRYPT_OBJID_TABLE;
struct _CRYPT_OID_FUNC_ENTRY;
typedef struct _CRYPT_OID_FUNC_ENTRY CRYPT_OID_FUNC_ENTRY;
struct _CRYPT_RC2_CBC_PARAMETERS;
typedef struct _CRYPT_RC2_CBC_PARAMETERS CRYPT_RC2_CBC_PARAMETERS;
struct _CRYPT_SEQUENCE_OF_ANY;
typedef struct _CRYPT_SEQUENCE_OF_ANY CRYPT_SEQUENCE_OF_ANY;
struct _CRYPT_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_SIGN_MESSAGE_PARA CRYPT_SIGN_MESSAGE_PARA;
struct _CRYPT_SMIME_CAPABILITIES;
typedef struct _CRYPT_SMIME_CAPABILITIES CRYPT_SMIME_CAPABILITIES;
struct _CRYPT_SMIME_CAPABILITY;
typedef struct _CRYPT_SMIME_CAPABILITY CRYPT_SMIME_CAPABILITY;
struct _CRYPT_TIME_STAMP_REQUEST_INFO;
typedef struct _CRYPT_TIME_STAMP_REQUEST_INFO CRYPT_TIME_STAMP_REQUEST_INFO;
typedef struct _CRYPTOAPI_BLOB CRYPT_UINT_BLOB;
struct _CRYPT_VERIFY_MESSAGE_PARA;
typedef struct _CRYPT_VERIFY_MESSAGE_PARA CRYPT_VERIFY_MESSAGE_PARA;
struct _CTL_ANY_SUBJECT_INFO;
typedef struct _CTL_ANY_SUBJECT_INFO CTL_ANY_SUBJECT_INFO;
struct _CTL_CONTEXT;
typedef struct _CTL_CONTEXT CTL_CONTEXT;
struct _CTL_ENTRY;
typedef struct _CTL_ENTRY CTL_ENTRY;
struct _CTL_FIND_SUBJECT_PARA;
typedef struct _CTL_FIND_SUBJECT_PARA CTL_FIND_SUBJECT_PARA;
struct _CTL_FIND_USAGE_PARA;
typedef struct _CTL_FIND_USAGE_PARA CTL_FIND_USAGE_PARA;
struct _CTL_INFO;
typedef struct _CTL_INFO CTL_INFO;
typedef struct _CTL_USAGE CTL_USAGE;
struct _CTL_VERIFY_USAGE_PARA;
typedef struct _CTL_VERIFY_USAGE_PARA CTL_VERIFY_USAGE_PARA;
struct _CTL_VERIFY_USAGE_STATUS;
typedef struct _CTL_VERIFY_USAGE_STATUS CTL_VERIFY_USAGE_STATUS;
typedef struct _CRYPTOAPI_BLOB DATA_BLOB;
struct _PUBKEY;
typedef struct _PUBKEY DHPUBKEY;
typedef struct _PUBKEY DSSPUBKEY;
struct _DSSSEED;
typedef struct _DSSSEED DSSSEED;
typedef void *HCERTSTORE;
typedef void *HCERTSTOREPROV;
typedef void *HCRYPTMSG;
typedef void *HCRYPTOIDFUNCADDR;
typedef void *HCRYPTOIDFUNCSET;
struct _HMAC_Info;
typedef struct _HMAC_Info HMAC_INFO;
typedef struct _PUBKEY KEAPUBKEY;
struct _KEY_TYPE_SUBTYPE;
typedef struct _KEY_TYPE_SUBTYPE KEY_TYPE_SUBTYPE;
typedef const CERT_CONTEXT *PCCERT_CONTEXT;
typedef const CRL_CONTEXT *PCCRL_CONTEXT;
typedef const CRYPT_OID_INFO *PCCRYPT_OID_INFO;
typedef const CTL_CONTEXT *PCCTL_CONTEXT;
typedef struct _CERT_ALT_NAME_ENTRY *PCERT_ALT_NAME_ENTRY;
typedef struct _CERT_ALT_NAME_INFO *PCERT_ALT_NAME_INFO;
typedef struct _CERT_AUTHORITY_KEY_ID2_INFO *PCERT_AUTHORITY_KEY_ID2_INFO;
typedef struct _CERT_AUTHORITY_KEY_ID_INFO *PCERT_AUTHORITY_KEY_ID_INFO;
typedef struct _CERT_BASIC_CONSTRAINTS2_INFO *PCERT_BASIC_CONSTRAINTS2_INFO;
typedef struct _CERT_BASIC_CONSTRAINTS_INFO *PCERT_BASIC_CONSTRAINTS_INFO;
typedef struct _CRYPTOAPI_BLOB *PCERT_BLOB;
typedef struct _CERT_CHAIN *PCERT_CHAIN;
typedef struct _CERT_CONTEXT *PCERT_CONTEXT;
typedef struct _CERT_DSS_PARAMETERS *PCERT_DSS_PARAMETERS;
typedef struct _CTL_USAGE *PCERT_ENHKEY_USAGE;
typedef struct _CERT_EXTENSION *PCERT_EXTENSION;
typedef struct _CERT_EXTENSIONS *PCERT_EXTENSIONS;
typedef struct _CERT_INFO *PCERT_INFO;
typedef struct _CERT_KEYGEN_REQUEST_INFO *PCERT_KEYGEN_REQUEST_INFO;
typedef struct _CERT_KEY_ATTRIBUTES_INFO *PCERT_KEY_ATTRIBUTES_INFO;
typedef struct _CERT_KEY_CONTEXT *PCERT_KEY_CONTEXT;
typedef struct _CERT_KEY_USAGE_RESTRICTION_INFO *PCERT_KEY_USAGE_RESTRICTION_INFO;
typedef struct _CRYPTOAPI_BLOB *PCERT_NAME_BLOB;
typedef struct _CERT_NAME_INFO *PCERT_NAME_INFO;
typedef struct _CERT_NAME_VALUE *PCERT_NAME_VALUE;
typedef struct _CERT_POLICIES_INFO *PCERT_POLICIES_INFO;
typedef struct _CERT_POLICY_ID *PCERT_POLICY_ID;
typedef struct _CERT_POLICY_INFO *PCERT_POLICY_INFO;
typedef struct _CERT_POLICY_QUALIFIER_INFO *PCERT_POLICY_QUALIFIER_INFO;
typedef struct _CERT_PRIVATE_KEY_VALIDITY *PCERT_PRIVATE_KEY_VALIDITY;
typedef struct _CERT_PUBLIC_KEY_INFO *PCERT_PUBLIC_KEY_INFO;
typedef struct _CERT_RDN *PCERT_RDN;
typedef struct _CERT_RDN_ATTR *PCERT_RDN_ATTR;
typedef struct _CRYPTOAPI_BLOB *PCERT_RDN_VALUE_BLOB;
typedef struct _CERT_REQUEST_INFO *PCERT_REQUEST_INFO;
typedef struct _CERT_REVOCATION_PARA *PCERT_REVOCATION_PARA;
typedef struct _CERT_REVOCATION_STATUS *PCERT_REVOCATION_STATUS;
typedef struct _CERT_SIGNED_CONTENT_INFO *PCERT_SIGNED_CONTENT_INFO;
typedef struct _CERT_STORE_PROV_INFO *PCERT_STORE_PROV_INFO;
typedef CRYPT_ATTRIBUTES *PCMSG_ATTR;
typedef struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA *PCMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA;
typedef struct _CMSG_CTRL_DECRYPT_PARA *PCMSG_CTRL_DECRYPT_PARA;
typedef struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA *PCMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA;
typedef struct _CMSG_ENCRYPTED_ENCODE_INFO *PCMSG_ENCRYPTED_ENCODE_INFO;
typedef struct _CMSG_ENVELOPED_ENCODE_INFO *PCMSG_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_HASHED_ENCODE_INFO *PCMSG_HASHED_ENCODE_INFO;
typedef struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO *PCMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO;
typedef struct _CMSG_SIGNED_ENCODE_INFO *PCMSG_SIGNED_ENCODE_INFO;
typedef struct _CMSG_SIGNER_ENCODE_INFO *PCMSG_SIGNER_ENCODE_INFO;
typedef struct _CMSG_SIGNER_INFO *PCMSG_SIGNER_INFO;
typedef struct _CMSG_STREAM_INFO *PCMSG_STREAM_INFO;
typedef struct _CRYPTOAPI_BLOB *PCRL_BLOB;
typedef struct _CRL_CONTEXT *PCRL_CONTEXT;
typedef struct _CRL_DIST_POINT *PCRL_DIST_POINT;
typedef struct _CRL_DIST_POINTS_INFO *PCRL_DIST_POINTS_INFO;
typedef struct _CRL_DIST_POINT_NAME *PCRL_DIST_POINT_NAME;
typedef struct _CRL_ENTRY *PCRL_ENTRY;
typedef struct _CRL_INFO *PCRL_INFO;
typedef struct _CRYPT_ALGORITHM_IDENTIFIER *PCRYPT_ALGORITHM_IDENTIFIER;
typedef struct _CRYPT_ATTRIBUTE *PCRYPT_ATTRIBUTE;
typedef struct _CRYPT_ATTRIBUTES *PCRYPT_ATTRIBUTES;
typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE *PCRYPT_ATTRIBUTE_TYPE_VALUE;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_ATTR_BLOB;
typedef struct _CRYPT_BIT_BLOB *PCRYPT_BIT_BLOB;
typedef struct _CRYPT_CONTENT_INFO *PCRYPT_CONTENT_INFO;
typedef struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *PCRYPT_CONTENT_INFO_SEQUENCE_OF_ANY;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_DATA_BLOB;
typedef struct _CRYPT_DECRYPT_MESSAGE_PARA *PCRYPT_DECRYPT_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_DER_BLOB;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_DIGEST_BLOB;
typedef struct _CRYPT_ENCRYPT_MESSAGE_PARA *PCRYPT_ENCRYPT_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_HASH_BLOB;
typedef struct _CRYPT_HASH_INFO *PCRYPT_HASH_INFO;
typedef struct _CRYPT_HASH_MESSAGE_PARA *PCRYPT_HASH_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_INTEGER_BLOB;
typedef struct _CRYPT_KEY_PROV_INFO *PCRYPT_KEY_PROV_INFO;
typedef struct _CRYPT_KEY_PROV_PARAM *PCRYPT_KEY_PROV_PARAM;
typedef struct _CRYPT_KEY_SIGN_MESSAGE_PARA *PCRYPT_KEY_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_KEY_VERIFY_MESSAGE_PARA *PCRYPT_KEY_VERIFY_MESSAGE_PARA;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_OBJID_BLOB;
typedef struct _CRYPT_OBJID_TABLE *PCRYPT_OBJID_TABLE;
typedef struct _CRYPT_OID_FUNC_ENTRY *PCRYPT_OID_FUNC_ENTRY;
typedef struct _CRYPT_OID_INFO *PCRYPT_OID_INFO;
typedef struct _CRYPT_RC2_CBC_PARAMETERS *PCRYPT_RC2_CBC_PARAMETERS;
typedef struct _CRYPT_SEQUENCE_OF_ANY *PCRYPT_SEQUENCE_OF_ANY;
typedef struct _CRYPT_SIGN_MESSAGE_PARA *PCRYPT_SIGN_MESSAGE_PARA;
typedef struct _CRYPT_SMIME_CAPABILITIES *PCRYPT_SMIME_CAPABILITIES;
typedef struct _CRYPT_SMIME_CAPABILITY *PCRYPT_SMIME_CAPABILITY;
typedef struct _CRYPT_TIME_STAMP_REQUEST_INFO *PCRYPT_TIME_STAMP_REQUEST_INFO;
typedef struct _CRYPTOAPI_BLOB *PCRYPT_UINT_BLOB;
typedef struct _CRYPT_VERIFY_MESSAGE_PARA *PCRYPT_VERIFY_MESSAGE_PARA;
typedef struct _CTL_ANY_SUBJECT_INFO *PCTL_ANY_SUBJECT_INFO;
typedef struct _CTL_CONTEXT *PCTL_CONTEXT;
typedef struct _CTL_ENTRY *PCTL_ENTRY;
typedef struct _CTL_FIND_SUBJECT_PARA *PCTL_FIND_SUBJECT_PARA;
typedef struct _CTL_FIND_USAGE_PARA *PCTL_FIND_USAGE_PARA;
typedef struct _CTL_INFO *PCTL_INFO;
typedef struct _CTL_USAGE *PCTL_USAGE;
typedef struct _CTL_VERIFY_USAGE_PARA *PCTL_VERIFY_USAGE_PARA;
typedef struct _CTL_VERIFY_USAGE_STATUS *PCTL_VERIFY_USAGE_STATUS;
typedef struct _CRYPTOAPI_BLOB *PDATA_BLOB;
typedef BOOL (*PFN_CERT_DLL_OPEN_STORE_PROV_FUNC)(LPCSTR, DWORD, HCRYPTPROV, DWORD, const void *, HCERTSTORE, PCERT_STORE_PROV_INFO);
typedef void (*PFN_CERT_STORE_PROV_CLOSE)(HCERTSTOREPROV, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_DELETE_CERT)(HCERTSTOREPROV, PCCERT_CONTEXT, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_DELETE_CRL)(HCERTSTOREPROV, PCCRL_CONTEXT, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_DELETE_CTL)(HCERTSTOREPROV, PCCTL_CONTEXT, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_READ_CERT)(HCERTSTOREPROV, PCCERT_CONTEXT, DWORD, PCCERT_CONTEXT *);
typedef BOOL (*PFN_CERT_STORE_PROV_READ_CRL)(HCERTSTOREPROV, PCCRL_CONTEXT, DWORD, PCCRL_CONTEXT *);
typedef BOOL (*PFN_CERT_STORE_PROV_READ_CTL)(HCERTSTOREPROV, PCCTL_CONTEXT, DWORD, PCCTL_CONTEXT *);
typedef BOOL (*PFN_CERT_STORE_PROV_SET_CERT_PROPERTY)(HCERTSTOREPROV, PCCERT_CONTEXT, DWORD, DWORD, const void *);
typedef BOOL (*PFN_CERT_STORE_PROV_SET_CRL_PROPERTY)(HCERTSTOREPROV, PCCRL_CONTEXT, DWORD, DWORD, const void *);
typedef BOOL (*PFN_CERT_STORE_PROV_SET_CTL_PROPERTY)(HCERTSTOREPROV, PCCTL_CONTEXT, DWORD, DWORD, const void *);
typedef BOOL (*PFN_CERT_STORE_PROV_WRITE_CERT)(HCERTSTOREPROV, PCCERT_CONTEXT, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_WRITE_CRL)(HCERTSTOREPROV, PCCRL_CONTEXT, DWORD);
typedef BOOL (*PFN_CERT_STORE_PROV_WRITE_CTL)(HCERTSTOREPROV, PCCTL_CONTEXT, DWORD);
typedef BOOL (*PFN_CMSG_EXPORT_ENCRYPT_KEY)(HCRYPTPROV, HCRYPTKEY, PCERT_PUBLIC_KEY_INFO, PBYTE, PDWORD);
typedef BOOL (*PFN_CMSG_GEN_ENCRYPT_KEY)(HCRYPTPROV *, PCRYPT_ALGORITHM_IDENTIFIER, PVOID, PCERT_PUBLIC_KEY_INFO, HCRYPTKEY *);
typedef BOOL (*PFN_CMSG_IMPORT_ENCRYPT_KEY)(HCRYPTPROV, DWORD, PCRYPT_ALGORITHM_IDENTIFIER, PCRYPT_ALGORITHM_IDENTIFIER, PBYTE, DWORD, HCRYPTKEY *);
typedef BOOL (*PFN_CMSG_STREAM_OUTPUT)(const void *, BYTE *, DWORD, BOOL);
typedef BOOL (*PFN_CRYPT_ENUM_OID_FUNC)(DWORD, LPCSTR, LPCSTR, DWORD, const DWORD *, const LPCWSTR *, const BYTE *const *, const DWORD *, void *);
typedef PCCERT_CONTEXT (*PFN_CRYPT_GET_SIGNER_CERTIFICATE)(void *, DWORD, PCERT_INFO, HCERTSTORE);
typedef struct _HMAC_Info *PHMAC_INFO;
typedef struct _KEY_TYPE_SUBTYPE *PKEY_TYPE_SUBTYPE;
struct _PROV_ENUMALGS;
typedef struct _PROV_ENUMALGS PROV_ENUMALGS;
struct _PROV_ENUMALGS_EX;
typedef struct _PROV_ENUMALGS_EX PROV_ENUMALGS_EX;
struct _SCHANNEL_ALG;
typedef struct _SCHANNEL_ALG *PSCHANNEL_ALG;
typedef struct _PUBLICKEYSTRUC PUBLICKEYSTRUC;
struct _VTableProvStruc;
typedef struct _VTableProvStruc *PVTableProvStruc;
struct _RSAPUBKEY;
typedef struct _RSAPUBKEY RSAPUBKEY;
typedef struct _SCHANNEL_ALG SCHANNEL_ALG;
typedef struct _PUBKEY TEKPUBKEY;
typedef struct _VTableProvStruc VTableProvStruc;
struct _CRYPTOAPI_BLOB {
    DWORD cbData;
    BYTE *pbData;
};

struct _CERT_ALT_NAME_ENTRY {
    DWORD dwAltNameChoice;
    union {
        LPWSTR pwszRfc822Name;
        LPWSTR pwszDNSName;
        CERT_NAME_BLOB DirectoryName;
        LPWSTR pwszURL;
        CRYPT_DATA_BLOB IPAddress;
        LPSTR pszRegisteredID;
    };
};

struct _CERT_ALT_NAME_INFO {
    DWORD cAltEntry;
    PCERT_ALT_NAME_ENTRY rgAltEntry;
};

struct _CERT_AUTHORITY_KEY_ID2_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_ALT_NAME_INFO AuthorityCertIssuer;
    CRYPT_INTEGER_BLOB AuthorityCertSerialNumber;
};

struct _CERT_AUTHORITY_KEY_ID_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_NAME_BLOB CertIssuer;
    CRYPT_INTEGER_BLOB CertSerialNumber;
};

struct _CERT_BASIC_CONSTRAINTS2_INFO {
    BOOL fCA;
    BOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
};

struct _CRYPT_BIT_BLOB {
    DWORD cbData;
    BYTE *pbData;
    DWORD cUnusedBits;
};

struct _CERT_BASIC_CONSTRAINTS_INFO {
    CRYPT_BIT_BLOB SubjectType;
    BOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
    DWORD cSubtreesConstraint;
    CERT_NAME_BLOB *rgSubtreesConstraint;
};

struct _CRYPT_KEY_PROV_INFO {
    LPWSTR pwszContainerName;
    LPWSTR pwszProvName;
    DWORD dwProvType;
    DWORD dwFlags;
    DWORD cProvParam;
    PCRYPT_KEY_PROV_PARAM rgProvParam;
    DWORD dwKeySpec;
};

struct _CERT_CHAIN {
    DWORD cCerts;
    PCERT_BLOB certs;
    CRYPT_KEY_PROV_INFO keyLocatorInfo;
};

struct _CERT_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCertEncoded;
    DWORD cbCertEncoded;
    PCERT_INFO pCertInfo;
    HCERTSTORE hCertStore;
};

struct _CERT_DSS_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB q;
    CRYPT_UINT_BLOB g;
};

struct _CERT_EXTENSION {
    LPSTR pszObjId;
    BOOL fCritical;
    CRYPT_OBJID_BLOB Value;
};

struct _CERT_EXTENSIONS {
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
};

struct _CRYPT_ALGORITHM_IDENTIFIER {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
};

struct _CERT_PUBLIC_KEY_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_BIT_BLOB PublicKey;
};

struct _CERT_INFO {
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME NotBefore;
    FILETIME NotAfter;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    CRYPT_BIT_BLOB IssuerUniqueId;
    CRYPT_BIT_BLOB SubjectUniqueId;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
};

struct _CERT_KEYGEN_REQUEST_INFO {
    DWORD dwVersion;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    LPWSTR pwszChallengeString;
};

struct _CERT_KEY_ATTRIBUTES_INFO {
    CRYPT_DATA_BLOB KeyId;
    CRYPT_BIT_BLOB IntendedKeyUsage;
    PCERT_PRIVATE_KEY_VALIDITY pPrivateKeyUsagePeriod;
};

struct _CERT_KEY_CONTEXT {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
};

struct _CERT_KEY_USAGE_RESTRICTION_INFO {
    DWORD cCertPolicyId;
    PCERT_POLICY_ID rgCertPolicyId;
    CRYPT_BIT_BLOB RestrictedKeyUsage;
};

struct _CERT_NAME_INFO {
    DWORD cRDN;
    PCERT_RDN rgRDN;
};

struct _CERT_NAME_VALUE {
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
};

struct _CERT_POLICIES_INFO {
    DWORD cPolicyInfo;
    CERT_POLICY_INFO *rgPolicyInfo;
};

struct _CERT_POLICY_ID {
    DWORD cCertPolicyElementId;
    LPSTR *rgpszCertPolicyElementId;
};

struct _CERT_POLICY_INFO {
    LPSTR pszPolicyIdentifier;
    DWORD cPolicyQualifier;
    CERT_POLICY_QUALIFIER_INFO *rgPolicyQualifier;
};

struct _CERT_POLICY_QUALIFIER_INFO {
    LPSTR pszPolicyQualifierId;
    CRYPT_OBJID_BLOB Qualifier;
};

struct _CERT_PRIVATE_KEY_VALIDITY {
    FILETIME NotBefore;
    FILETIME NotAfter;
};

struct _CERT_RDN {
    DWORD cRDNAttr;
    PCERT_RDN_ATTR rgRDNAttr;
};

struct _CERT_RDN_ATTR {
    LPSTR pszObjId;
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
};

struct _CERT_REQUEST_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
};

struct _CERT_REVOCATION_PARA {
    DWORD cbSize;
    PCCERT_CONTEXT pIssuerCert;
    DWORD cCertStore;
    HCERTSTORE *rgCertStore;
};

struct _CERT_REVOCATION_STATUS {
    DWORD cbSize;
    DWORD dwIndex;
    DWORD dwError;
    DWORD dwReason;
};

struct _CERT_SIGNED_CONTENT_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_BIT_BLOB Signature;
};

struct _CERT_STORE_PROV_INFO {
    DWORD cbSize;
    DWORD cStoreProvFunc;
    void **rgpvStoreProvFunc;
    HCERTSTOREPROV hStoreProv;
    DWORD dwStoreProvFlags;
};

struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    CRYPT_DATA_BLOB blob;
};

struct _CMSG_CTRL_DECRYPT_PARA {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
    DWORD dwRecipientIndex;
};

struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    DWORD dwUnauthAttrIndex;
};

struct _CMSG_ENCRYPTED_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
};

struct _CMSG_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD cRecipients;
    PCERT_INFO *rgpRecipients;
};

struct _CMSG_HASHED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
};

struct _CMSG_SIGNED_ENCODE_INFO {
    DWORD cbSize;
    DWORD cSigners;
    PCMSG_SIGNER_ENCODE_INFO rgSigners;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
    DWORD cCrlEncoded;
    PCRL_BLOB rgCrlEncoded;
};

struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    CMSG_SIGNED_ENCODE_INFO SignedInfo;
    CMSG_ENVELOPED_ENCODE_INFO EnvelopedInfo;
};

struct _CMSG_SIGNER_ENCODE_INFO {
    DWORD cbSize;
    PCERT_INFO pCertInfo;
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
};

struct _CRYPT_ATTRIBUTES {
    DWORD cAttr;
    PCRYPT_ATTRIBUTE rgAttr;
};

struct _CMSG_SIGNER_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedHash;
    CRYPT_ATTRIBUTES AuthAttrs;
    CRYPT_ATTRIBUTES UnauthAttrs;
};

struct _CMSG_STREAM_INFO {
    DWORD cbContent;
    PFN_CMSG_STREAM_OUTPUT pfnStreamOutput;
    void *pvArg;
};

struct _CRL_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCrlEncoded;
    DWORD cbCrlEncoded;
    PCRL_INFO pCrlInfo;
    HCERTSTORE hCertStore;
};

struct _CRL_DIST_POINT_NAME {
    DWORD dwDistPointNameChoice;
    union {
        CERT_ALT_NAME_INFO FullName;
    };
};

struct _CRL_DIST_POINT {
    CRL_DIST_POINT_NAME DistPointName;
    CRYPT_BIT_BLOB ReasonFlags;
    CERT_ALT_NAME_INFO CRLIssuer;
};

struct _CRL_DIST_POINTS_INFO {
    DWORD cDistPoint;
    PCRL_DIST_POINT rgDistPoint;
};

struct _CRL_ENTRY {
    CRYPT_INTEGER_BLOB SerialNumber;
    FILETIME RevocationDate;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
};

struct _CRL_INFO {
    DWORD dwVersion;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    DWORD cCRLEntry;
    PCRL_ENTRY rgCRLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
};

struct _CRYPT_ATTRIBUTE {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_ATTR_BLOB rgValue;
};

struct _CRYPT_ATTRIBUTE_TYPE_VALUE {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
};

struct _CRYPT_CONTENT_INFO {
    LPSTR pszObjId;
    CRYPT_DER_BLOB Content;
};

struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
};

struct _CRYPT_DECRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    DWORD cCertStore;
    HCERTSTORE *rghCertStore;
};

struct _CRYPT_ENCRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD dwFlags;
    DWORD dwInnerContentType;
};

struct _CRYPT_HASH_INFO {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB Hash;
};

struct _CRYPT_HASH_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
};

struct _CRYPT_KEY_PROV_PARAM {
    DWORD dwParam;
    BYTE *pbData;
    DWORD cbData;
    DWORD dwFlags;
};

struct _CRYPT_KEY_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    CRYPT_ALGORITHM_IDENTIFIER PubKeyAlgorithm;
};

struct _CRYPT_KEY_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV hCryptProv;
};

struct _CRYPT_OBJID_TABLE {
    DWORD dwAlgId;
    LPCSTR pszObjId;
};

struct _CRYPT_OID_FUNC_ENTRY {
    LPCSTR pszOID;
    void *pvFuncAddr;
};

struct _CRYPT_OID_INFO {
    DWORD cbSize;
    LPCSTR pszOID;
    LPCWSTR pwszName;
    DWORD dwGroupId;
    union {
        DWORD dwValue;
        ALG_ID Algid;
        DWORD dwLength;
    };
    CRYPT_DATA_BLOB ExtraInfo;
};

struct _CRYPT_RC2_CBC_PARAMETERS {
    DWORD dwVersion;
    BOOL fIV;
    BYTE rgbIV[8];
};

struct _CRYPT_SEQUENCE_OF_ANY {
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
};

struct _CRYPT_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    PCCERT_CONTEXT pSigningCert;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cMsgCert;
    PCCERT_CONTEXT *rgpMsgCert;
    DWORD cMsgCrl;
    PCCRL_CONTEXT *rgpMsgCrl;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
    DWORD dwFlags;
    DWORD dwInnerContentType;
};

struct _CRYPT_SMIME_CAPABILITIES {
    DWORD cCapability;
    PCRYPT_SMIME_CAPABILITY rgCapability;
};

struct _CRYPT_SMIME_CAPABILITY {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
};

struct _CRYPT_TIME_STAMP_REQUEST_INFO {
    LPSTR pszTimeStampAlgorithm;
    LPSTR pszContentType;
    CRYPT_OBJID_BLOB Content;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
};

struct _CRYPT_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    HCRYPTPROV hCryptProv;
    PFN_CRYPT_GET_SIGNER_CERTIFICATE pfnGetSignerCertificate;
    void *pvGetArg;
};

struct _CTL_ANY_SUBJECT_INFO {
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    CRYPT_DATA_BLOB SubjectIdentifier;
};

struct _CTL_CONTEXT {
    DWORD dwMsgAndCertEncodingType;
    BYTE *pbCtlEncoded;
    DWORD cbCtlEncoded;
    PCTL_INFO pCtlInfo;
    HCERTSTORE hCertStore;
    HCRYPTMSG hCryptMsg;
    BYTE *pbCtlContent;
    DWORD cbCtlContent;
};

struct _CTL_ENTRY {
    CRYPT_DATA_BLOB SubjectIdentifier;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
};

struct _CTL_FIND_SUBJECT_PARA {
    DWORD cbSize;
    PCTL_FIND_USAGE_PARA pUsagePara;
    DWORD dwSubjectType;
    void *pvSubject;
};

struct _CTL_USAGE {
    DWORD cUsageIdentifier;
    LPSTR *rgpszUsageIdentifier;
};

struct _CTL_FIND_USAGE_PARA {
    DWORD cbSize;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    PCERT_INFO pSigner;
};

struct _CTL_INFO {
    DWORD dwVersion;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    CRYPT_INTEGER_BLOB SequenceNumber;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    DWORD cCTLEntry;
    PCTL_ENTRY rgCTLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
};

struct _CTL_VERIFY_USAGE_PARA {
    DWORD cbSize;
    CRYPT_DATA_BLOB ListIdentifier;
    DWORD cCtlStore;
    HCERTSTORE *rghCtlStore;
    DWORD cSignerStore;
    HCERTSTORE *rghSignerStore;
};

struct _CTL_VERIFY_USAGE_STATUS {
    DWORD cbSize;
    DWORD dwError;
    DWORD dwFlags;
    PCCTL_CONTEXT *ppCtl;
    DWORD dwCtlEntryIndex;
    PCCERT_CONTEXT *ppSigner;
    DWORD dwSignerIndex;
};

struct _DSSSEED {
    DWORD counter;
    BYTE seed[20];
};

struct _HMAC_Info {
    ALG_ID HashAlgid;
    BYTE *pbInnerString;
    DWORD cbInnerString;
    BYTE *pbOuterString;
    DWORD cbOuterString;
};

struct _KEY_TYPE_SUBTYPE {
    DWORD dwKeySpec;
    GUID Type;
    GUID Subtype;
};

struct _PROV_ENUMALGS {
    ALG_ID aiAlgid;
    DWORD dwBitLen;
    DWORD dwNameLen;
    WCHAR szName[20];
};

struct _PROV_ENUMALGS_EX {
    ALG_ID aiAlgid;
    DWORD dwDefaultLen;
    DWORD dwMinLen;
    DWORD dwMaxLen;
    DWORD dwProtocols;
    DWORD dwNameLen;
    WCHAR szName[20];
    DWORD dwLongNameLen;
    WCHAR szLongName[40];
};

struct _PUBKEY {
    DWORD magic;
    DWORD bitlen;
};

struct _PUBLICKEYSTRUC {
    BYTE bType;
    BYTE bVersion;
    WORD reserved;
    ALG_ID aiKeyAlg;
};

struct _RSAPUBKEY {
    DWORD magic;
    DWORD bitlen;
    DWORD pubexp;
};

struct _SCHANNEL_ALG {
    DWORD dwUse;
    ALG_ID Algid;
    DWORD cBits;
};

struct _VTableProvStruc {
    DWORD Version;
    FARPROC FuncVerifyImage;
    FARPROC FuncReturnhWnd;
    DWORD dwProvType;
    BYTE *pbContextInfo;
    DWORD cbContextInfo;
    LPWSTR pszProvName;
};


#ifdef __cplusplus
}
#endif

#endif

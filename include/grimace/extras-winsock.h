#ifndef GRIMACE_EXTRAS_WINSOCK_H
#define GRIMACE_EXTRAS_WINSOCK_H

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sets or queries a socket's mode, including the secure socket (SSL)
 * settings.
 *
 * Windows CE has no overlapped socket I/O. Besides FIONBIO, FIONREAD and
 * SIOCATMARK, secure sockets accept SO_SSL_GET_CAPABILITIES,
 * SO_SSL_GET_FLAGS, SO_SSL_SET_FLAGS, SO_SSL_GET_PROTOCOLS,
 * SO_SSL_SET_PROTOCOLS, SO_SSL_SET_VALIDATE_CERT_HOOK and
 * SO_SSL_PERFORM_HANDSHAKE. Clients must install a certificate validation
 * hook that at least checks expiry and the remote party's identity.
 *
 * @param s The socket.
 * @param dwIoControlCode The control code.
 * @param lpvInBuffer Input data, or NULL.
 * @param cbInBuffer Size of lpvInBuffer, in bytes.
 * @param lpvOutBuffer Output buffer, or NULL.
 * @param cbOutBuffer Size of lpvOutBuffer, in bytes.
 * @param lpcbBytesReturned Receives the number of bytes written to
 *        lpvOutBuffer.
 * @param lpOverlapped Must be NULL.
 * @param lpCompletionRoutine Must be NULL.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 *
 * @note Windows CE 2.0 and later.
 */
int WINAPI WSAIoctl(SOCKET s, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer,
                    LPDWORD lpcbBytesReturned, LPVOID lpOverlapped, LPVOID lpCompletionRoutine);

#define IOCGROUP(x) (((x) >> 8) & 0xff)

#ifdef __cplusplus
}
#endif

#endif

#endif

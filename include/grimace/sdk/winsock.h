#ifndef GRIMACE_SDK_WINSOCK_H
#define GRIMACE_SDK_WINSOCK_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sets the device's host name, as gethostname returns it.
 *
 * Windows CE specific.
 *
 * @param pName The new host name.
 * @param cName Length of pName in bytes.
 * @return 0 on success, or SOCKET_ERROR (see WSAGetLastError).
 *
 * @note Windows CE 2.0 and later.
 */
int sethostname(char *pName, int cName);

#ifdef __cplusplus
}
#endif

#endif

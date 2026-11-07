#include <windows.h>

#ifndef GRIMACE_WINSCARD_H
#define GRIMACE_WINSCARD_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/winscard.h>
#endif
#include <wtypes.h>
#include <winioctl.h>
#include <winsmcrd.h>
#define GRIMACE_WINSCARD_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

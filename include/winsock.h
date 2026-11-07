#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINSOCK_H
#define GRIMACE_WRAPPED_WINSOCK_H

#ifdef GRIMACE_INSIDE
#include_next <winsock.h>
#include <grimace/extras-winsock.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/winsock.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winsock.h>
#include <grimace/extras-winsock.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/winsock.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

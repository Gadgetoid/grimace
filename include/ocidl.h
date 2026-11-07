#include <windows.h>

#ifndef GRIMACE_OCIDL_H
#define GRIMACE_OCIDL_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/ocidl.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <ole2.h>
#include <oleidl.h>
#include <oaidl.h>
#define GRIMACE_OCIDL_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

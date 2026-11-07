#include <windows.h>

#ifndef GRIMACE_OAIDL_H
#define GRIMACE_OAIDL_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/oaidl.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <ole2.h>
#include <objidl.h>
#define GRIMACE_OAIDL_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

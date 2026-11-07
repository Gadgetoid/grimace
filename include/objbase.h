#include <windows.h>

#ifndef GRIMACE_OBJBASE_H
#define GRIMACE_OBJBASE_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/objbase.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <wtypes.h>
#include <unknwn.h>
#include <objidl.h>
#define GRIMACE_OBJBASE_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

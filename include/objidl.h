#include <windows.h>

#ifndef GRIMACE_OBJIDL_H
#define GRIMACE_OBJIDL_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/objbase.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <ole2.h>
#include <unknwn.h>
#define GRIMACE_OBJIDL_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

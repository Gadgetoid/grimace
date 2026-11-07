#include <windows.h>

#ifndef GRIMACE_OLEIDL_H
#define GRIMACE_OLEIDL_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/oleidl.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <ole2.h>
#include <objidl.h>
#define GRIMACE_OLEIDL_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

#include <windows.h>

#ifndef GRIMACE_URLMON_H
#define GRIMACE_URLMON_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/urlmon.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <ole2.h>
#include <objidl.h>
#include <oleidl.h>
#include <servprov.h>
#include <msxml.h>
#define GRIMACE_URLMON_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

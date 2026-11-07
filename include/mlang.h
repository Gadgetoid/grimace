#include <windows.h>

#ifndef GRIMACE_MLANG_H
#define GRIMACE_MLANG_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/mlang.h>
#endif
#include <rpc.h>
#include <rpcndr.h>
#include <unknwn.h>
#define GRIMACE_MLANG_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

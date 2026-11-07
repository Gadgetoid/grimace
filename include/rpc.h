#include <windows.h>

#ifndef GRIMACE_RPC_H
#define GRIMACE_RPC_H

#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/rpc.h>
#endif
#include <rpcdce.h>
#define GRIMACE_RPC_H_CONTENT
#ifndef GRIMACE_NO_CONSTANTS
#include <grimace/constants.h>
#endif

#endif

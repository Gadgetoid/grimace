#include <windows.h>
#ifndef GRIMACE_WRAPPED_IMM_H
#define GRIMACE_WRAPPED_IMM_H

#ifdef GRIMACE_INSIDE
#include_next <imm.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/imm.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <imm.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/imm.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

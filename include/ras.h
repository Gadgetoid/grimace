#include <windows.h>
#ifndef GRIMACE_WRAPPED_RAS_H
#define GRIMACE_WRAPPED_RAS_H

#ifdef GRIMACE_INSIDE
#include_next <ras.h>
#include <grimace/extras-ras.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/ras.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <ras.h>
#include <grimace/extras-ras.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/ras.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

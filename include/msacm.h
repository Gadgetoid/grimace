#include <windows.h>
#ifndef GRIMACE_WRAPPED_MSACM_H
#define GRIMACE_WRAPPED_MSACM_H

#ifdef GRIMACE_INSIDE
#include_next <msacm.h>
#include <grimace/extras-msacm.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/msacm.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <msacm.h>
#include <grimace/extras-msacm.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/msacm.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

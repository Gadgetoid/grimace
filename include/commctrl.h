#include <windows.h>
#ifndef GRIMACE_WRAPPED_COMMCTRL_H
#define GRIMACE_WRAPPED_COMMCTRL_H

#ifdef GRIMACE_INSIDE
#include_next <commctrl.h>
#include <grimace/extras-commctrl.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/commctrl.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <commctrl.h>
#include <grimace/extras-commctrl.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/commctrl.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

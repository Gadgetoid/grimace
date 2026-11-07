#include <windows.h>
#ifndef GRIMACE_WRAPPED_NOTIFY_H
#define GRIMACE_WRAPPED_NOTIFY_H

#ifdef GRIMACE_INSIDE
#include_next <notify.h>
#include <grimace/extras-notify.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/notify.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <notify.h>
#include <grimace/extras-notify.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/notify.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

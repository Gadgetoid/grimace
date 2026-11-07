#include <windows.h>
#ifndef GRIMACE_WRAPPED_COMMDLG_H
#define GRIMACE_WRAPPED_COMMDLG_H

#ifdef GRIMACE_INSIDE
#include_next <commdlg.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/commdlg.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <commdlg.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/commdlg.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

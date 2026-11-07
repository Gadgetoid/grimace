#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINNETWK_H
#define GRIMACE_WRAPPED_WINNETWK_H

#ifdef GRIMACE_INSIDE
#include_next <winnetwk.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winnetwk.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

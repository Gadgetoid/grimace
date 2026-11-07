#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINDOWSX_H
#define GRIMACE_WRAPPED_WINDOWSX_H

#ifdef GRIMACE_INSIDE
#include_next <windowsx.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <windowsx.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

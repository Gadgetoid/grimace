#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINUSER_H
#define GRIMACE_WRAPPED_WINUSER_H

#ifdef GRIMACE_INSIDE
#include_next <winuser.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winuser.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

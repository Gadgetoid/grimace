#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINVER_H
#define GRIMACE_WRAPPED_WINVER_H

#ifdef GRIMACE_INSIDE
#include_next <winver.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winver.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

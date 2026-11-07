#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINBASE_H
#define GRIMACE_WRAPPED_WINBASE_H

#ifdef GRIMACE_INSIDE
#include_next <winbase.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winbase.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINNT_H
#define GRIMACE_WRAPPED_WINNT_H

#ifdef GRIMACE_INSIDE
#include_next <winnt.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winnt.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

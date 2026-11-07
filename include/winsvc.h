#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINSVC_H
#define GRIMACE_WRAPPED_WINSVC_H

#ifdef GRIMACE_INSIDE
#include_next <winsvc.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winsvc.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

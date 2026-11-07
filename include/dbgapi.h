#include <windows.h>
#ifndef GRIMACE_WRAPPED_DBGAPI_H
#define GRIMACE_WRAPPED_DBGAPI_H

#ifdef GRIMACE_INSIDE
#include_next <dbgapi.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <dbgapi.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

#include <windows.h>
#ifndef GRIMACE_WRAPPED_SHELLAPI_H
#define GRIMACE_WRAPPED_SHELLAPI_H

#ifdef GRIMACE_INSIDE
#include_next <shellapi.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <shellapi.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

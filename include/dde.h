#include <windows.h>
#ifndef GRIMACE_WRAPPED_DDE_H
#define GRIMACE_WRAPPED_DDE_H

#ifdef GRIMACE_INSIDE
#include_next <dde.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <dde.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

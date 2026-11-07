#include <windows.h>
#ifndef GRIMACE_WRAPPED_LMCONS_H
#define GRIMACE_WRAPPED_LMCONS_H

#ifdef GRIMACE_INSIDE
#include_next <lmcons.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <lmcons.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

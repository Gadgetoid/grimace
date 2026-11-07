#include <windows.h>
#ifndef GRIMACE_WRAPPED_DLGS_H
#define GRIMACE_WRAPPED_DLGS_H

#ifdef GRIMACE_INSIDE
#include_next <dlgs.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <dlgs.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

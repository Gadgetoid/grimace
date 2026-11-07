#include <windows.h>
#ifndef GRIMACE_WRAPPED_KFUNCS_H
#define GRIMACE_WRAPPED_KFUNCS_H

#ifdef GRIMACE_INSIDE
#include_next <kfuncs.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <kfuncs.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

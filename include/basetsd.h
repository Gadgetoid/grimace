#include <windows.h>
#ifndef GRIMACE_WRAPPED_BASETSD_H
#define GRIMACE_WRAPPED_BASETSD_H

#ifdef GRIMACE_INSIDE
#include_next <basetsd.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <basetsd.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

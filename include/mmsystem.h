#include <windows.h>
#ifndef GRIMACE_WRAPPED_MMSYSTEM_H
#define GRIMACE_WRAPPED_MMSYSTEM_H

#ifdef GRIMACE_INSIDE
#include_next <mmsystem.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <mmsystem.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

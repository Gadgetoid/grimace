#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINDEF_H
#define GRIMACE_WRAPPED_WINDEF_H

#ifdef GRIMACE_INSIDE
#include_next <windef.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <windef.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

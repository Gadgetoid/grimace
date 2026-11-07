#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINCON_H
#define GRIMACE_WRAPPED_WINCON_H

#ifdef GRIMACE_INSIDE
#include_next <wincon.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <wincon.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

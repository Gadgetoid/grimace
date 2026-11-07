#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINRESRC_H
#define GRIMACE_WRAPPED_WINRESRC_H

#ifdef GRIMACE_INSIDE
#include_next <winresrc.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winresrc.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

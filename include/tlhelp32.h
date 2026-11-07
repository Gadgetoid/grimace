#include <windows.h>
#ifndef GRIMACE_WRAPPED_TLHELP32_H
#define GRIMACE_WRAPPED_TLHELP32_H

#ifdef GRIMACE_INSIDE
#include_next <tlhelp32.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <tlhelp32.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

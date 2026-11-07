#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINREG_H
#define GRIMACE_WRAPPED_WINREG_H

#ifdef GRIMACE_INSIDE
#include_next <winreg.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winreg.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

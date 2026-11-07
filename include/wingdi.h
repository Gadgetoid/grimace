#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINGDI_H
#define GRIMACE_WRAPPED_WINGDI_H

#ifdef GRIMACE_INSIDE
#include_next <wingdi.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <wingdi.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

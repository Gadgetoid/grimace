#include <windows.h>
#ifndef GRIMACE_WRAPPED_WINNLS_H
#define GRIMACE_WRAPPED_WINNLS_H

#ifdef GRIMACE_INSIDE
#include_next <winnls.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <winnls.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

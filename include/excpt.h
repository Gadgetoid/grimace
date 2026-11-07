#include <windows.h>
#ifndef GRIMACE_WRAPPED_EXCPT_H
#define GRIMACE_WRAPPED_EXCPT_H

#ifdef GRIMACE_INSIDE
#include_next <excpt.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <excpt.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

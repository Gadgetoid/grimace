#include <windows.h>
#ifndef GRIMACE_WRAPPED_PRSHT_H
#define GRIMACE_WRAPPED_PRSHT_H

#ifdef GRIMACE_INSIDE
#include_next <prsht.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <prsht.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

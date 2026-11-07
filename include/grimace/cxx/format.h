#ifndef GRIMACE_CXX_FORMAT_H
#define GRIMACE_CXX_FORMAT_H

#include <windows.h>

#if GRIMACE_CE >= 3
#include <grimace/cxx/detail/format-snwprintf.h>
#else
#include <grimace/cxx/detail/format-wsprintf.h>
#endif

#endif

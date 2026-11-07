#include <windows.h>
#include <winsock.h>
#ifndef GRIMACE_WRAPPED_MSWSOCK_H
#define GRIMACE_WRAPPED_MSWSOCK_H

#ifdef GRIMACE_INSIDE
#include_next <mswsock.h>
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <mswsock.h>
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

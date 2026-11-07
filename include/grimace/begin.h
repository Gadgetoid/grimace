#ifndef UNDER_CE
#define UNDER_CE
#endif
#include <grimace/version.h>
#if GRIMACE_ARM
#ifndef ARM
#define ARM
#endif
#ifndef _ARM_
#define _ARM_
#endif
#ifndef ARMV4
#define ARMV4
#endif
#elif GRIMACE_X86
#ifndef _X86_
#define _X86_
#endif
#ifndef x86
#define x86
#endif
#elif GRIMACE_SH3
#ifndef SHx
#define SHx
#endif
#ifndef SH3
#define SH3
#endif
#ifndef _SH3_
#define _SH3_
#endif
#else
#ifndef _MIPS_
#define _MIPS_
#endif
#ifndef MIPS
#define MIPS
#endif
#endif
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef __stdcall
#define __stdcall
#endif
#ifndef __cdecl
#define __cdecl
#endif

#if GRIMACE_WCE == 101 && !defined(INTERNATIONAL)
#define INTERNATIONAL
#endif

#if GRIMACE_CE < 3 && !defined(GRIMACE_NO_SDK)
#define GRIMACE_NO_SDK
#endif

#ifndef _WIN32_IE
#if GRIMACE_CE >= 2
#define _WIN32_IE 0x0400
#else
#define _WIN32_IE 0x0300
#endif
#endif

#pragma push_macro("_WIN32_WCE")
#undef _WIN32_WCE
#if GRIMACE_CE >= 3
#define _WIN32_WCE 0x300
#elif GRIMACE_CE >= 2
#define _WIN32_WCE 0x200
#elif GRIMACE_WCE == 101
#define _WIN32_WCE 0x101
#else
#define _WIN32_WCE 0x100
#endif

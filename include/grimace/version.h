#ifndef GRIMACE_VERSION_H
#define GRIMACE_VERSION_H

#ifndef GRIMACE_CE
#if defined(_WIN32_WCE) && _WIN32_WCE >= 600
#define GRIMACE_CE 6
#elif defined(_WIN32_WCE) && _WIN32_WCE >= 300
#define GRIMACE_CE 3
#elif defined(_WIN32_WCE) && _WIN32_WCE >= 200
#define GRIMACE_CE 2
#else
#define GRIMACE_CE 1
#endif
#endif
#ifndef GRIMACE_WCE
#if GRIMACE_CE >= 6
#define GRIMACE_WCE 600
#elif GRIMACE_CE >= 3
#define GRIMACE_WCE 300
#elif GRIMACE_CE >= 2
#define GRIMACE_WCE 200
#elif defined(_WIN32_WCE) && _WIN32_WCE == 101
#define GRIMACE_WCE 101
#else
#define GRIMACE_WCE 100
#endif
#endif

#ifndef GRIMACE_ARM
#if defined(__arm__) || defined(ARM) || defined(_ARM_)
#define GRIMACE_ARM 1
#else
#define GRIMACE_ARM 0
#endif
#endif
#ifndef GRIMACE_SH3
#if defined(__SH__) || defined(__sh__) || defined(SHx) || defined(SH3) || defined(_SH3_)
#define GRIMACE_SH3 1
#else
#define GRIMACE_SH3 0
#endif
#endif
#ifndef GRIMACE_X86
#if defined(__i386__) || defined(_X86_)
#define GRIMACE_X86 1
#else
#define GRIMACE_X86 0
#endif
#endif
#ifndef GRIMACE_MIPS
#if !GRIMACE_ARM && !GRIMACE_SH3 && !GRIMACE_X86
#define GRIMACE_MIPS 1
#else
#define GRIMACE_MIPS 0
#endif
#endif

#endif

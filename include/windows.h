#ifndef GRIMACE_WRAPPED_WINDOWS_H
#define GRIMACE_WRAPPED_WINDOWS_H

#ifdef GRIMACE_INSIDE
#include_next <windows.h>
#ifndef RC_INVOKED
#include <stdint.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <setjmp.h>
#include <time.h>
#include <windbase.h>
#if GRIMACE_WCE == 101
#include <windowsx.h>
#endif
#if GRIMACE_CE >= 2 || GRIMACE_WCE == 101
#include <tchar.h>
#endif
#endif
#include <grimace/extras.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/windows.h>
#endif
#else
#define GRIMACE_INSIDE
#include <grimace/begin.h>
#include_next <windows.h>
#ifndef RC_INVOKED
#include <stdint.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <setjmp.h>
#include <time.h>
#include <windbase.h>
#if GRIMACE_WCE == 101
#include <windowsx.h>
#endif
#if GRIMACE_CE >= 2 || GRIMACE_WCE == 101
#include <tchar.h>
#endif
#endif
#include <grimace/extras.h>
#if !defined(RC_INVOKED) && !defined(GRIMACE_NO_SDK)
#include <grimace/sdk/windows.h>
#endif
#include <grimace/end.h>
#undef GRIMACE_INSIDE
#endif

#endif

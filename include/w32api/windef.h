#ifndef _WINDEF_H
#define _WINDEF_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINVER
#define WINVER 0x0400
/*
 * If you need Win32 API features newer the Win95 and WinNT then you must
 * define WINVER before including windows.h or any other method of including
 * the windef.h header.
 */
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT WINVER
/*
 * There may be the need to define _WIN32_WINNT to a value different from
 * the value of WINVER.  I don't have any example of why you would do that.
 * However, if you must then define _WIN32_WINNT to the value required before
 * including windows.h or any other method of including the windef.h header.
 */
#endif

#if defined(__CEGCC__) || defined(__MINGW32CE__)
#ifndef _WIN32_WCE
#define _WIN32_WCE 0x0300
/*
 * If you need WinCE API features newer than WinCE 3.0 then you must
 * define _WIN32_WCE to the value required before including windows.h 
 * or any other method of including the windef.h header.
 */
#endif
#endif

/*
 * Macro to deal with wide names - WinCE functions not receiving LPTSTR
 * directly don't have W suffix, even though they are implicitly wide
 * (expect wide strings in structures passed, etc.)
 */
#ifdef _WIN32_WCE
#define _WNAME(name) name
#else
#define _WNAME(name) name ## W
#endif

#ifndef WIN32
#define WIN32
#endif
#ifndef _WIN32
#define _WIN32
#endif
#define FAR
#define far
#define NEAR
#define near
#ifndef CONST
#define CONST const
#endif
#undef MAX_PATH
#define MAX_PATH 260

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

/* Pseudo modifiers for parameters
   We don't use these unnecessary defines in the w32api headers. Define
   them by default since that is what people expect, but allow users
   to avoid the pollution.  */
#ifndef _NO_W32_PSEUDO_MODIFIERS
#define IN
#define OUT
#ifndef OPTIONAL
#define OPTIONAL
#endif
#endif

#ifdef __GNUC__
#define PACKED __attribute__((packed))
#ifndef _fastcall
#define _fastcall __attribute__((fastcall))
#endif
#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif
#ifndef _stdcall
#define _stdcall __attribute__((stdcall))
#endif
#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif
#ifndef _cdecl
#define _cdecl __attribute__((cdecl))
#endif
#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif
#ifndef __declspec
#define __declspec(e) __attribute__((e))
#endif
#ifndef _declspec
#define _declspec(e) __attribute__((e))
#endif
#elif defined(__WATCOMC__)
#define PACKED
#else
#define PACKED
#define _cdecl
#define __cdecl
#endif

#undef pascal
#undef _pascal
#undef __pascal
#define pascal __stdcall
#define _pascal __stdcall
#define __pascal __stdcall
#define PASCAL _pascal
#define CDECL _cdecl
#define STDCALL __stdcall
#define FASTCALL __fastcall
#define WINAPI __stdcall
#define WINAPIV __cdecl
#define APIENTRY __stdcall
#define CALLBACK __stdcall
#define APIPRIVATE __stdcall

#define DECLSPEC_IMPORT __declspec(dllimport)
#define DECLSPEC_EXPORT __declspec(dllexport)
#ifdef __GNUC__
#define DECLSPEC_NORETURN __declspec(noreturn)
#define DECLARE_STDCALL_P( type ) __stdcall type
#elif defined(__WATCOMC__)
#define DECLSPEC_NORETURN
#define DECLARE_STDCALL_P( type ) type __stdcall
#endif /* __GNUC__/__WATCOMC__ */
/**
 * This macro creates an unsigned 16-bit integer by concatenating two
 * spscified unsigned character values.
 *
 * The MAKEWORD macro is defined as follows:
 *
 *     #define MAKEWORD(a, b) \
 *         ((WORD) (((BYTE) (a)) | ((WORD) ((BYTE) (b))) << 8))
 *
 * @param bLow Specifies the low-order byte of the new short value.
 * @param bHigh Specifies the high-order byte of the new short value.
 * @return The return value is an unsigned 16-bit integer value.
 */
#define MAKEWORD(a,b)	((WORD)(((BYTE)(a))|(((WORD)((BYTE)(b)))<<8)))
/**
 * This macro creates an unsigned 32-bit value by concatenating two
 * specified 16-bit values.
 *
 * The MAKELONG macro is defined as follows:
 *
 *     #define MAKELONG(a, b) \
 *         ((LONG) (((WORD) (a)) | ((DWORD) ((WORD) (b))) << 16))
 *
 * @param wLow Specifies the low-order word of the new long value.
 * @param wHigh Specifies the high-order word of the new long value.
 * @return The return value is an unsigned 32-bit value.
 */
#define MAKELONG(a,b)	((LONG)(((WORD)(a))|(((DWORD)((WORD)(b)))<<16)))
/**
 * This macro retrieves the low-order word from the specified 32-bit value.
 *
 * The LOWORD macro is defined as follows:
 *
 *     #define LOWORD(l)   ((WORD) (l))
 *
 * @param dwValue Specifies the value to be converted.
 * @return The return value is the low-order word of the specified value.
 */
#define LOWORD(l)	((WORD)((DWORD)(l)))
/**
 * This macro retrieves the high-order word from the specified 32-bit
 * value.
 *
 * The HIWORD macro is defined as follows:
 *
 *     #define HIWORD(l)   ((WORD) (((DWORD) (l) >> 16) & 0xFFFF))
 *
 * @param dwValue Specifies the value to be converted.
 * @return The return value is the high-order word of the specified value.
 */
#define HIWORD(l)	((WORD)(((DWORD)(l)>>16)&0xFFFF))
/**
 * This macro retrieves the low-order byte from the specified 16-bit value.
 *
 * The LOBYTE macro is defined as follows:
 *
 *     #define LOBYTE(w)   ((BYTE) (w))
 *
 * @param wValue Specifies the value to be converted.
 * @return The return value is the low-order byte of the specified value.
 */
#define LOBYTE(w)	((BYTE)(w))
/**
 * This macro retrieves the high-order byte from the specified 16-bit
 * value.
 *
 * The HIBYTE macro is defined as follows:
 *
 *     #define HIBYTE(w)   ((BYTE) (((WORD) (w) >> 8) & 0xFF))
 *
 * @param wValue Specifies the value to be converted.
 * @return The return value is the high-order byte of the specified value.
 */
#define HIBYTE(w)	((BYTE)(((WORD)(w)>>8)&0xFF))

#ifndef __WATCOMC__
#ifndef _export
#define _export
#endif
#ifndef __export
#define __export
#endif
#endif

#ifndef NOMINMAX
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#endif

#define UNREFERENCED_PARAMETER(P) {(P)=(P);}
#define UNREFERENCED_LOCAL_VARIABLE(L) {(L)=(L);}
#define DBG_UNREFERENCED_PARAMETER(P)
#define DBG_UNREFERENCED_LOCAL_VARIABLE(L)

#ifndef NONAMELESSUNION
#ifdef __GNUC__
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define _ANONYMOUS_UNION __extension__
#define _ANONYMOUS_STRUCT __extension__
#else
#if defined(__cplusplus)
#define _ANONYMOUS_UNION __extension__
#endif /* __cplusplus */
#endif /* __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95) */
#elif defined(__WATCOMC__)
#define _ANONYMOUS_UNION
#define _ANONYMOUS_STRUCT
#endif /* __GNUC__/__WATCOMC__ */
#endif /* NONAMELESSUNION */

#ifndef _ANONYMOUS_UNION
#define _ANONYMOUS_UNION
#define _UNION_NAME(x) x
#define DUMMYUNIONNAME	u
#define DUMMYUNIONNAME2	u2
#define DUMMYUNIONNAME3	u3
#define DUMMYUNIONNAME4	u4
#define DUMMYUNIONNAME5	u5
#define DUMMYUNIONNAME6	u6
#define DUMMYUNIONNAME7	u7
#define DUMMYUNIONNAME8	u8
#else
#define _UNION_NAME(x)
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define DUMMYUNIONNAME6
#define DUMMYUNIONNAME7
#define DUMMYUNIONNAME8
#endif
#ifndef _ANONYMOUS_STRUCT
#define _ANONYMOUS_STRUCT
#define _STRUCT_NAME(x) x
#define DUMMYSTRUCTNAME	s
#define DUMMYSTRUCTNAME2 s2
#define DUMMYSTRUCTNAME3 s3
#else
#define _STRUCT_NAME(x)
#define DUMMYSTRUCTNAME
#define DUMMYSTRUCTNAME2
#define DUMMYSTRUCTNAME3
#endif

#ifndef NO_STRICT
#ifndef STRICT
#define STRICT 1
#endif
#endif

/* FIXME: This will make some code compile. The programs will most
   likely crash when an exception is raised, but at least they will
   compile. */
#if defined (__GNUC__) && defined (__SEH_NOOP)
#define __try
#define __except(x) if (0) /* don't execute handler */
#define __finally

#define _try __try
#define _except __except
#define _finally __finally
#endif

typedef unsigned long DWORD;
typedef int WINBOOL,*PWINBOOL,*LPWINBOOL;
/* FIXME: Is there a good solution to this? */
#ifndef XFree86Server
#ifndef __OBJC__
typedef WINBOOL BOOL;
#else
#define BOOL WINBOOL
#endif
typedef unsigned char BYTE;
#endif /* ndef XFree86Server */
typedef BOOL *PBOOL,*LPBOOL;
typedef unsigned short WORD;
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef BYTE *PBYTE,*LPBYTE;
typedef int *PINT,*LPINT;
typedef WORD *PWORD,*LPWORD;
typedef long *LPLONG;
typedef DWORD *PDWORD,*LPDWORD;
typedef CONST void *PCVOID,*LPCVOID;
typedef int INT;
typedef unsigned int UINT,*PUINT,*LPUINT;

#include <winnt.h>

typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef LONG_PTR LRESULT;
#ifndef _HRESULT_DEFINED
typedef LONG HRESULT;
#define _HRESULT_DEFINED
#endif
#ifndef XFree86Server
typedef WORD ATOM;
#endif /* XFree86Server */
typedef HANDLE HHOOK;
typedef HANDLE HGLOBAL;
typedef HANDLE HLOCAL;
typedef HANDLE GLOBALHANDLE;
typedef HANDLE LOCALHANDLE;
typedef void *HGDIOBJ;
DECLARE_HANDLE(HACCEL);
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HBRUSH);
DECLARE_HANDLE(HCOLORSPACE);
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HGLRC);
DECLARE_HANDLE(HDESK);
DECLARE_HANDLE(HENHMETAFILE);
DECLARE_HANDLE(HFONT);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HKEY);
/* FIXME: How to handle these. SM_CMONITORS etc in winuser.h also. */
DECLARE_HANDLE(HMONITOR);
#define HMONITOR_DECLARED 1
DECLARE_HANDLE(HTERMINAL);
DECLARE_HANDLE(HWINEVENTHOOK);

typedef HKEY *PHKEY;
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HMETAFILE);
DECLARE_HANDLE(HINSTANCE);
typedef HINSTANCE HMODULE;
DECLARE_HANDLE(HPALETTE);
DECLARE_HANDLE(HPEN);
DECLARE_HANDLE(HRGN);
DECLARE_HANDLE(HRSRC);
DECLARE_HANDLE(HSTR);
DECLARE_HANDLE(HTASK);
DECLARE_HANDLE(HWND);
DECLARE_HANDLE(HWINSTA);
DECLARE_HANDLE(HKL);
typedef int HFILE;
typedef HICON HCURSOR;
typedef DWORD COLORREF;
typedef int (WINAPI *FARPROC)();
typedef int (WINAPI *NEARPROC)();
typedef int (WINAPI *PROC)();
/**
 * This structure defines the coordinates of the upper-left and lower-right
 * corners of a rectangle.
 *
 * When RECT is passed to the FillRect function, the rectangle is filled up
 * to, but not including, the right column and bottom row of pixels. This
 * structure is identical to the RECTL structure.
 */
typedef struct tagRECT {
	/**
	 * Specifies the x-coordinate of the upper-left corner of the
	 * rectangle.
	 */
	LONG left;
	/**
	 * Specifies the y-coordinate of the upper-left corner of the
	 * rectangle.
	 */
	LONG top;
	/**
	 * Specifies the x-coordinate of the lower-right corner of
	 * the rectangle.
	 */
	LONG right;
	/**
	 * Specifies the y-coordinate of the lower-right corner of
	 * the rectangle.
	 */
	LONG bottom;
} RECT,*PRECT,*LPRECT;
typedef const RECT *LPCRECT;
typedef struct tagRECTL {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECTL,*PRECTL,*LPRECTL;
typedef const RECTL *LPCRECTL;
/**
 * This structure defines the x- and y-coordinates of a point.
 */
typedef struct tagPOINT {
	/**
	 * Specifies the x-coordinate of the point.
	 */
	LONG x;
	/**
	 * Specifies the y-coordinate of the point.
	 */
	LONG y;
} POINT,POINTL,*PPOINT,*LPPOINT,*PPOINTL,*LPPOINTL;
/**
 * This structure specifies the width and height of a rectangle.
 *
 * The rectangle dimensions stored in this structure may correspond to
 * viewport extents, window extents, text extents, bitmap dimensions, or
 * the aspect-ratio filter for some extended functions.
 */
typedef struct tagSIZE {
	/**
	 * Specifies the rectangle's width.
	 */
	LONG cx;
	/**
	 * Specifies the rectangle's height.
	 */
	LONG cy;
} SIZE,SIZEL,*PSIZE,*LPSIZE,*PSIZEL,*LPSIZEL;
/**
 * This structure defines the coordinates of a point.
 */
typedef struct tagPOINTS {
	/**
	 * Specifies the x-coordinate of the point.
	 */
	SHORT x;
	/**
	 * Specifies the y-coordinate of the point.
	 */
	SHORT y;
} POINTS,*PPOINTS,*LPPOINTS;

#ifdef __cplusplus
}
#endif
#endif

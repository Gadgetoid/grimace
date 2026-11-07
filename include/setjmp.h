#ifndef GRIMACE_SETJMP_H
#define GRIMACE_SETJMP_H

#ifdef __cplusplus
extern "C" {
#endif

#define _JBLEN 11

typedef int jmp_buf[_JBLEN];

/**
 * Saves the current stack environment for a later longjmp.
 *
 * It returns 0 when saving the environment. After longjmp, it returns the
 * value passed to longjmp, or 1 if that value was 0. These functions do
 * not preserve C++ object semantics.
 *
 * @param environment Receives the saved stack environment.
 * @return 0 when called directly, or the value passed to longjmp.
 *
 * @note Windows CE 3.0 and later.
 */
int setjmp(jmp_buf environment) __attribute__((returns_twice));
#define _setjmp setjmp
/**
 * Restores a stack environment saved by setjmp and resumes after that call.
 *
 * Call longjmp before the function that called setjmp returns. A value of
 * 0 is changed to 1. Register variables may not retain their values, and
 * these functions do not preserve C++ object semantics.
 *
 * @param environment Stack environment previously saved by setjmp.
 * @param value Value returned by setjmp after control resumes.
 *
 * @note Windows CE 2.0 and later.
 */
void longjmp(jmp_buf environment, int value);

#ifdef __cplusplus
}
#endif

#endif

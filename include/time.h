#ifndef GRIMACE_TIME_H
#define GRIMACE_TIME_H

#include <grimace/version.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _TIME_T_DEFINED
#if GRIMACE_CE >= 3
typedef unsigned long time_t;
#else
typedef long time_t;
#endif
#define _TIME_T_DEFINED
#endif

/**
 * Returns the difference between two times in seconds.
 *
 * @param end The later time.
 * @param start The earlier time.
 * @return end minus start, in seconds.
 *
 * @note Windows CE 3.0 only.
 */
double difftime(time_t end, time_t start);

#ifdef __cplusplus
}
#endif

#endif

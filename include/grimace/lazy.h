#ifndef GRIMACE_LAZY_H
#define GRIMACE_LAZY_H

#ifdef __cplusplus
extern "C" {
#endif

struct grimace_lazy_import {
    void *target;
    const wchar_t *dll;
    const wchar_t *name;
    long bound;
};

int __grimace_lazy_resolve(struct grimace_lazy_import *import);

#ifdef __cplusplus
}
#endif

#include <grimace/lazy-imports.h>

#define __grimace_placeholder_1 0,
#define __grimace_second(ignored, value, ...) value
#define __grimace_is_one(argument_or_junk) __grimace_second(argument_or_junk 1, 0)
#define __grimace_paste_placeholder(value) __grimace_is_one(__grimace_placeholder_##value)
#define __grimace_expand_marker(marker) __grimace_paste_placeholder(marker)
#define __grimace_is_lazy(function) __grimace_expand_marker(__grimace_lazy_##function)
#define __grimace_has_0(function) ((void)(function), 1)
#define __grimace_has_1(function) (__grimace_lazy_resolve(&__grimace_lazy_import_##function) != 0)
#define __grimace_has_choose(lazy, function) __grimace_has_##lazy(function)
#define __grimace_has_select(lazy, function) __grimace_has_choose(lazy, function)
#define __grimace_has(function) __grimace_has_select(__grimace_is_lazy(function), function)

/**
 * Whether the device has a function the program imports.
 *
 * Always true for a function every device the target covers exports. For a lazy import, one only some of them export,
 * it binds the function if it hasn't been called yet, and says whether the device has it. Calling a lazy import the
 * device lacks sets ERROR_CALL_NOT_IMPLEMENTED and returns 0, so check first where 0 isn't a failure value.
 *
 * A function no device the target covers exports is a compile error, as calling it would be.
 */
#define ce_has(function) __grimace_has(function)

#endif

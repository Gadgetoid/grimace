#include <windows.h>

#include "runtime.h"

static void run_exit_handlers();

struct exit_handler {
    void (*function)(void *);
    void *argument;
    exit_handler *next;
};

static exit_handler *exit_handlers;

extern "C" {

__attribute__((visibility("hidden"))) void *__dso_handle = &__dso_handle;

int __cxa_atexit(void (*function)(void *), void *argument, void *) {
    exit_handler *handler = static_cast<exit_handler *>(LocalAlloc(LMEM_FIXED, sizeof(exit_handler)));
    if (!handler) {
        return -1;
    }
    handler->function = function;
    handler->argument = argument;
    handler->next = exit_handlers;
    exit_handlers = handler;
    grimace_run_exit_handlers = run_exit_handlers;
    return 0;
}

[[noreturn]] void __cxa_pure_virtual() {
    __builtin_trap();
}

[[noreturn]] void __cxa_deleted_virtual() {
    __builtin_trap();
}

}

static void run_exit_handlers() {
    while (exit_handler *handler = exit_handlers) {
        exit_handlers = handler->next;
        handler->function(handler->argument);
        LocalFree(handler);
    }
}

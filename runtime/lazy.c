typedef unsigned short wchar_type;

struct grimace_lazy_import {
    void *target;
    const wchar_type *dll;
    const wchar_type *name;
    long bound;
};

void *LoadLibraryW(const wchar_type *name);
void *GetProcAddressW(void *module, const wchar_type *name);
void SetLastError(unsigned long error);
unsigned long GetLastError(void);

#define ERROR_CALL_NOT_IMPLEMENTED 120

static long missing_function(void) {
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    return 0;
}

static void *find_function(void *module, const wchar_type *name) {
    wchar_type other[128];
    unsigned length = 0;
    void *target = GetProcAddressW(module, name);
    if (target) {
        return target;
    }
    while (name[length] && length < sizeof(other) / sizeof(other[0]) - 2) {
        other[length] = name[length];
        length++;
    }
    if (name[length]) {
        return 0;
    }
    if (length > 1 && other[length - 1] == 'W') {
        length--;
    } else {
        other[length++] = 'W';
    }
    other[length] = 0;
    return GetProcAddressW(module, other);
}

void *__grimace_lazy_bind(struct grimace_lazy_import *import) {
    if (!import->bound) {
        unsigned long error = GetLastError();
        void *module = LoadLibraryW(import->dll);
        void *target = module ? find_function(module, import->name) : 0;
        SetLastError(error);
        import->target = target ? target : (void *)missing_function;
        import->bound = target ? 1 : -1;
    }
    return import->target;
}

int __grimace_lazy_resolve(struct grimace_lazy_import *import) {
    __grimace_lazy_bind(import);
    return import->bound > 0;
}

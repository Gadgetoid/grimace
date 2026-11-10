typedef int BOOL;

__attribute__((weak)) BOOL DllMain(void *instance, unsigned long reason, void *reserved) {
    return 1;
}

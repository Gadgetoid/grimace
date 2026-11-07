#ifndef GRIMACE_SDK_KEYBD_H
#define GRIMACE_SDK_KEYBD_H


#ifdef __cplusplus
extern "C" {
#endif

typedef UINT8 KEY_STATE[256];
typedef UINT32 KEY_STATE_FLAGS;
struct KBDI_AUTOREPEAT_INFO;
struct KBDI_AUTOREPEAT_INFO {
    INT32 CurrentInitialDelay;
    INT32 CurrentRepeatRate;
    INT32 cInitialDelaysSelectable;
    INT32 cRepeatRatesSelectable;
};

struct KBDI_VKEY_TO_UNICODE_INFO;
struct KBDI_VKEY_TO_UNICODE_INFO {
    UINT32 cbToUnicodeState;
    UINT32 cMaxToUnicodeCharacters;
};


#ifdef __cplusplus
}
#endif

#endif

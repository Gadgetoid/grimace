#ifndef GRIMACE_SDK_NLED_H
#define GRIMACE_SDK_NLED_H


#ifdef __cplusplus
extern "C" {
#endif

struct NLED_COUNT_INFO;
struct NLED_COUNT_INFO {
    UINT cLeds;
};

struct NLED_SETTINGS_INFO;
struct NLED_SETTINGS_INFO {
    UINT LedNum;
    INT OffOnBlink;
    LONG TotalCycleTime;
    LONG OnTime;
    LONG OffTime;
    INT MetaCycleOn;
    INT MetaCycleOff;
};

struct NLED_SUPPORTS_INFO;
struct NLED_SUPPORTS_INFO {
    UINT LedNum;
    LONG lCycleAdjust;
    BOOL fAdjustTotalCycleTime;
    BOOL fAdjustOnTime;
    BOOL fAdjustOffTime;
    BOOL fMetaCycleOn;
    BOOL fMetaCycleOff;
};


#ifdef __cplusplus
}
#endif

#endif

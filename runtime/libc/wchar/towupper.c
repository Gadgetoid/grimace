#include <wchar.h>

wchar_t towupper(wchar_t character) {
    if ((character >= 'a' && character <= 'z') || (character >= 0xE0 && character <= 0xFE && character != 0xF7)) {
        return (wchar_t)(character - 32);
    }
    return character;
}

#include <wchar.h>

wchar_t towlower(wchar_t character) {
    if ((character >= 'A' && character <= 'Z') || (character >= 0xC0 && character <= 0xDE && character != 0xD7)) {
        return (wchar_t)(character + 32);
    }
    return character;
}

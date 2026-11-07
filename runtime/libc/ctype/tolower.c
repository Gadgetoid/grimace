#include <ctype.h>

int tolower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;
}

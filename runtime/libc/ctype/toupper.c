#include <ctype.h>

int toupper(int character) {
    return character >= 'a' && character <= 'z' ? character - 32 : character;
}

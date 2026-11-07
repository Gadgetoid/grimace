#include <ctype.h>

#define UPPER 0x0001
#define LOWER 0x0002
#define DIGIT 0x0004
#define SPACE 0x0008
#define PUNCT 0x0010
#define CONTROL 0x0020
#define BLANK 0x0040
#define HEX 0x0080
#define ALPHA 0x0100

static unsigned classify(int character) {
    if (character < 0 || character > 0x7F) {
        return 0;
    }
    if (character >= 'A' && character <= 'Z') {
        return UPPER | ALPHA | (character <= 'F' ? HEX : 0);
    }
    if (character >= 'a' && character <= 'z') {
        return LOWER | ALPHA | (character <= 'f' ? HEX : 0);
    }
    if (character >= '0' && character <= '9') {
        return DIGIT | HEX;
    }
    if (character == ' ') {
        return SPACE | BLANK;
    }
    if (character >= '\t' && character <= '\r') {
        return SPACE | CONTROL | (character == '\t' ? BLANK : 0);
    }
    if (character < 0x20 || character == 0x7F) {
        return CONTROL;
    }
    return PUNCT;
}

int _isctype(int character, int type) {
    return (int)(classify(character) & (unsigned)type);
}

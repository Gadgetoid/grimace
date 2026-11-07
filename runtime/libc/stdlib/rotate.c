#include <stdlib.h>

unsigned int _rotl(unsigned int value, int shift) {
    shift &= 31;
    return shift ? value << shift | value >> (32 - shift) : value;
}

unsigned int _rotr(unsigned int value, int shift) {
    shift &= 31;
    return shift ? value >> shift | value << (32 - shift) : value;
}

unsigned long _lrotl(unsigned long value, int shift) {
    return _rotl((unsigned int)value, shift);
}

unsigned long _lrotr(unsigned long value, int shift) {
    return _rotr((unsigned int)value, shift);
}

#include <string.h>

static char *next_token;

char *strtok(char *string, const char *delimiters) {
    if (!string) {
        string = next_token;
    }
    if (!string) {
        return NULL;
    }
    string += strspn(string, delimiters);
    if (!*string) {
        next_token = NULL;
        return NULL;
    }
    char *end = string + strcspn(string, delimiters);
    if (*end) {
        *end = 0;
        next_token = end + 1;
    } else {
        next_token = NULL;
    }
    return string;
}

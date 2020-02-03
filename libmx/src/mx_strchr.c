#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    int i = 0;

    if (!s)
        return NULL;

    while (s[i]) {
        if (s[i] == c) 
            return (char*) &s[i];
        i++;
    }
    return NULL;
}

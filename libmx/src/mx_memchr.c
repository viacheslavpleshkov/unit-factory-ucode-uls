#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *temp = (char*) s;

    for (size_t i = 0; i < n; i++)
        if (temp[i] == c)
            return (void*) &temp[i];

    return NULL;
}


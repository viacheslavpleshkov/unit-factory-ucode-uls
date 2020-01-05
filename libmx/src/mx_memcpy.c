#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *s1 = (char*) dst;
    char *s2 = (char*) src;

    for (size_t i = 0; i < n; i++)
        s1[i] = s2[i];

    dst = (void*) s1;

    return dst;
}

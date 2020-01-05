#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *s1 = (char*) dst;
    char *s2 = (char*) src;

    for (size_t i = 0; i < n; i++) {
        if (s2[i] == c) {
            s1[i] = s2[i];
            return (void*) (s1 + (i + 1));
        }
        s1[i] = s2[i];
    }

    return NULL;
}

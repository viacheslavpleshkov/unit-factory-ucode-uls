#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *c1 = (char*) s1;
    char *c2 = (char*) s2;
    unsigned long i = 0;

    while (i < n) {
        if (c1[i] != c2[i])
            break;
        i++;
    }
    if (i == n)
        return 0;
    return c1[i] - c2[i];
}

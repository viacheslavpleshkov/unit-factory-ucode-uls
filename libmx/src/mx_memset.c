#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *temp = (char*) b;

    for (size_t i = 0; i < len; i++)
        temp[i] = c;

    return (void*) temp;
}

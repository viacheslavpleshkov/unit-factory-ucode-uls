#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len < little_len || little_len <= 0 || big_len <= 0)
        return NULL;

    char *temp = (char*) big;

    for (size_t i = 0; i <= big_len - little_len; i++)
        if (!mx_memcmp(&temp[i], little, little_len))
            return (void*) &temp[i];

    return NULL;
}


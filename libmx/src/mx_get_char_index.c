#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    int i = 0;

    if (!str)
        return -2;

    while (str[i] && str[i] != c)
        i++;

    if (str[i])
        return i;

    return -1;
}

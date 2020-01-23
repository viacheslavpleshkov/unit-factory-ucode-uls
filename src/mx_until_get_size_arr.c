#include "uls.h"

int mx_until_get_size_arr(char **str_arr) {
    int i = 0;

    if (str_arr)
        for (i = 0; str_arr[i]; i++);
    return i;
}

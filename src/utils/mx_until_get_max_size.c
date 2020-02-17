#include "uls.h"

int mx_until_get_max_size(t_ls **files) {
    long long int max_size = 0;

    for (int i = 0; files[i]; i++)
        if (files[i]->size > max_size)
            max_size = files[i]->size;
    return mx_until_get_len_number(max_size);
}

#include "uls.h"

static void mx_swap_t_ls(t_ls **s1, t_ls **s2) {
    t_ls *temp = NULL;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void mx_ls_sort_flag_r(t_ls **arr, int size) {
    for (int i = 0; i < size / 2; i++)
        mx_swap_t_ls(&arr[i], &arr[size - i - 1]);
}

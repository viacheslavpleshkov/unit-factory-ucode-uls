#include "uls.h"


void mx_ls_sort_flag_c(t_ls **arr) {
    t_ls *temp;
    int size = mx_until_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((arr[i]->ctime < arr[j]->ctime)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

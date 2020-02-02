#include "uls.h"

void mx_ls_sort_flag_t(t_ls **arr) {
    t_ls *temp;
    int size = mx_until_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((arr[i]->mtime < arr[j]->mtime) && arr[i]->mtime != arr[j]->mtime) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } else {
                if (mx_strcmp(arr[i]->name, arr[j]->name) > 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            
        }
    }
}

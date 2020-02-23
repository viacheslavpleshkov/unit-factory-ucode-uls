#include "uls.h"

void mx_ls_sort_flag_u(t_ls **arr, int size) {
    t_ls *temp;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if ((arr[i]->atime < arr[j]->atime) 
                && (arr[i]->atime != arr[j]->atime)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } else {
                if (mx_strcmp(arr[i]->print_name, arr[j]->print_name) > 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

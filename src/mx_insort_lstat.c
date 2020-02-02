#include "uls.h"

t_ls **mx_insort_lstat(char **main_files, t_ls **files, int str_size) {
    for (int i = 0; i < str_size; i++)
        files[i] = mx_get_lstat(main_files[i]);
    files[str_size] = NULL;
    return files;
}

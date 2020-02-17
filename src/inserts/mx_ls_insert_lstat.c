#include "uls.h"

t_ls **mx_ls_insort_lstat(char **main_files, t_main *main) {
    for (int i = 0; i < main->str_size; i++) {
        free(main->files_struct[i]);
        main->files_struct[i] = mx_ls_get_lstat(main_files[i]);
    }
    main->files_struct[main->str_size] = NULL;
    return main->files_struct;
}

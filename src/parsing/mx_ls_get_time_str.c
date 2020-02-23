#include "uls.h"

char *mx_ls_get_time_str(t_ls *file, t_ls_print_l *print_struct) {
    char *str = NULL;
    char *tem = ctime(&file->mtime);

    if (!print_struct->st) {
        if (print_struct->cur_time - file->mtime > LS_HALF_YEAR)
            str = mx_strjoin(mx_strndup(&tem[4], 7), mx_strndup(&tem[19], 5));
        else
            str = mx_strndup(&tem[4], 12);
    }
    else 
        str = mx_strndup(&tem[4], 20);
    return str;
}

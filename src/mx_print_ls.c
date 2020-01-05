#include "uls.h"

static int get_max_len(char **files) {
    int max_len = 0;

    if (files)
        for (int i = 0; files[i]; i++)
            if (mx_strlen(files[i]) > max_len)
                max_len = mx_strlen(files[i]);
    return max_len;
}


void mx_print_ls(t_file **files, int file_n, char *opt) {
    char **files_name = mx_create_char_arr(file_n + 1);
    
    for (int i = 0; i < file_n; i++)
        files_name[i] = mx_strdup(files[i]->print_name);

    if (mx_get_char_index(opt, 'l') >= 0)
        mx_print_ls_l(files, file_n, opt);
    else if (mx_get_char_index(opt, '1') >= 0)
        mx_print_strarr(files_name, "\n");
    else
        mx_print_ls_C(files_name, file_n, get_max_len(files_name), mx_get_terminal_width());
}

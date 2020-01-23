#include "uls.h"

static int get_max_len(char **files) {
    int max_len = 0;

    if (files)
        for (int i = 0; files[i]; i++)
            if (mx_strlen(files[i]) > max_len)
                max_len = mx_strlen(files[i]);
    return max_len;
}


void mx_ls_print(t_ls **files, int file_n, char *flags) {
    char **files_name = mx_until_create_char_arr(file_n + 1); //массив для хранения имен файлов
    
    for (int i = 0; i < file_n; i++)
        files_name[i] = mx_strdup(files[i]->print_name);

    if (mx_get_char_index(flags, 'l') >= 0)
        mx_ls_print_l(files, file_n, flags);
    else if (mx_get_char_index(flags, '1') >= 0)
        mx_print_strarr(files_name, "\n");
    else
        mx_ls_print_big_c(files_name, file_n, get_max_len(files_name), mx_get_terminal_width());
}

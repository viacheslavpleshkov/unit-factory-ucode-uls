#include "uls.h"

static int get_max_len(char **files) {
    int max_len = 0;

    if (files)
        for (int i = 0; files[i]; i++)
            if (mx_strlen(files[i]) > max_len)
                max_len = mx_strlen(files[i]);
    return max_len;
}


void mx_ls_print(t_ls **files, int file_n, char *flags, bool color) {
    char **files_name = mx_until_create_char_arr(file_n + 1); //массив для хранения имен файлов
    
    for (int i = 0; i < file_n; i++)
        files_name[i] = mx_strdup(files[i]->print_name);
    if ((mx_ls_check_flag(flags, 'l')) && (mx_ls_check_flag(flags, 'T')))
        mx_ls_print_big_t(files, file_n, flags);
    else if(mx_ls_check_flag(flags, 'l'))
        mx_ls_print_l(files, file_n, flags, color);
    else if (mx_ls_check_flag(flags, '1')) {
        for (int i = 0; files_name[i] != NULL; i++) {
            if (i != 0)
                mx_printstr("\n");
            mx_printstr(files_name[i]);
        }
    } else
        mx_ls_print_big_c(files_name, file_n, get_max_len(files_name), mx_get_terminal_width());
}

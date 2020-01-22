#include "uls.h"

void mx_ls(char  **str_arr, char *flags) {
    // char *new_flags = mx_clear_flags(char *flags);
    int str_size = mx_get_size_arr(str_arr);
    t_ls **files = mx_ls_create_struct_arr(str_size);
    char **files_without_dir = mx_until_create_char_arr(str_size);
    int k = 0;

    if (!str_size)
        mx_ls_loop(mx_read_dir(".", mx_ls_get_hidden(flags)), flags);
    
    for (int i = 0; i < str_size; i++)
        files[i] = mx_get_lstat(str_arr[i]);
    files[str_size] = NULL;
    for (int i = 0; files[i]; i++) {
        files_without_dir[k] = mx_strdup(files[i]->name);
        if (files[i]-> type != 'd')
            k++;
        else
            mx_strdel(&files_without_dir[k]);
    }
    mx_ls_loop(files_without_dir, flags);
    
    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd') {
            mx_printstr(files[i]->print_name);
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, mx_ls_get_hidden(flags)), flags);
        }
}

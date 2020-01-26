#include "uls.h"

void static print_dir(t_ls **files, t_main *main) {
    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd') {
            mx_printstr(files[i]->print_name);
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, mx_ls_get_hidden(main->flags)), main->flags, main);
        }
    }
}

void static print_files_without_dir(int str_size, t_main *main, t_ls **files) {
    char **files_without_dir = mx_until_create_char_arr(str_size);
    int k = 0;
    
    if (!str_size)
        mx_ls_loop(mx_read_dir(".", mx_ls_get_hidden(main->flags)), main->flags, main);

    for (int i = 0; i < str_size; i++)
        files[i] = mx_get_lstat(main->files[i]);
    files[str_size] = NULL;
    for (int i = 0; files[i]; i++) {
        files_without_dir[k] = mx_strdup(files[i]->name);
        if (files[i]->type != 'd')
            k++;
        else
            mx_strdel(&files_without_dir[k]);
    }
    mx_ls_loop(files_without_dir, main->flags, main);
    print_dir(files, main);
}

void mx_ls(t_main *main) {
    int str_size = mx_until_get_size_arr(main->files);
    t_ls **files = mx_ls_create_struct_arr(str_size);

    print_files_without_dir(str_size, main, files);

    if (mx_ls_check_flag(main->flags, '1'))
        mx_printstr("\n");
}

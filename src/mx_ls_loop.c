#include "uls.h"

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}

static void print_dir_name(char *dir_name) {
    mx_printstr("\n");
    if (dir_name && dir_name[0] == '/' && dir_name[1] == '/' 
        && dir_name[2] != '/')
            mx_printstr(&dir_name[1]);
    mx_printstr(dir_name);
    mx_printstr(":\n");
}

static void recursive(t_ls **files, t_main *main) {
    char **memory = NULL;
    ino_t dev_fd = mx_ls_get_ino_dev_fd();

    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd' && mx_until_check_flag(main->flags, 'R')) {
            if (mx_until_check_flag(main->flags, 'a')
                && !check_symbol(files[i]->print_name))
                continue;
            print_dir_name(files[i]->name);
            if (files[i]->ino == dev_fd)
                continue;
            memory = mx_ls_read_dir(files[i]->name, mx_ls_get_hidden(main->flags));
            if (!memory) {
                mx_ls_error(ERR_EACCES, files[i]->print_name);
                continue;
            }
            mx_ls_loop(memory, main, false);
            mx_del_strarr(&memory);
        }
    }
}

void mx_ls_loop(char **files_name, t_main *main, bool prin) {
    main->file_n = mx_until_get_size_arr(files_name);
    t_ls **files = mx_ls_create_struct_arr(main->file_n);
    for (int i = 0; files_name[i]; i++){
        free(files[i]);
        files[i] = mx_ls_get_lstat(files_name[i]);
        if (prin) {
            files[i]->print_name = files[i]->name;
        }
    }
    mx_ls_sort(files, main->flags, main->file_n);
    mx_ls_print(files, main);
    recursive(files, main);
    mx_until_del_tls(&files);
}

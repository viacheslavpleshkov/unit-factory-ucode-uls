#include "uls.h"

void static print_dir(t_ls **files, t_main *main);
void static print_files_without_dir(t_main *main);

void mx_ls(t_main *main) {
    char **memory = NULL;

    if (!main->str_size) {
        memory = mx_read_dir(".", mx_ls_get_hidden(main->flags));
        mx_ls_loop(memory, main);
        mx_del_strarr(&memory);
    }
    main->files_struct = mx_insort_lstat(main->files, main->files_struct, main->str_size);
    print_files_without_dir(main);
    mx_untill_del_tls(&main->files_struct);
}

void static print_files_without_dir(t_main *main) {
    char **files_without_dir = mx_until_create_char_arr(main->str_size);
    int k = 0;

    for (int i = 0; main->files_struct[i]; i++) {
        files_without_dir[k] = mx_strdup(main->files_struct[i]->name);
        if (main->files_struct[i]->type != 'd')
            k++;
        else
            mx_strdel(&files_without_dir[k]);
    }

    mx_ls_loop(files_without_dir, main);
    print_dir(main->files_struct, main);
    mx_del_strarr(&files_without_dir);

}

void static print_dir(t_ls **files, t_main *main) {
    char **memory = NULL;

    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd') {
            if (!(i == 0 && files[i + 1] == NULL)) {
                mx_printstr(files[i]->print_name);
                mx_printstr(":\n");
            }
            if (files[i + 1] != NULL)
                mx_printchar('\n');
            memory = mx_read_dir(files[i]->name, mx_ls_get_hidden(main->flags));
            if (!memory) {
                mx_ls_error(ERR_EACCES, files[i]->print_name);
                continue;
            }
            mx_ls_loop(memory, main);
            mx_del_strarr(&memory);
        }
    }
}

#include "uls.h"

void static print_dir(t_main *main) {
    for (int i = 0; main->files_struct[i]; i++) {
        if (main->files_struct[i]->type == 'd') {
            mx_printstr(main->files_struct[i]->print_name);
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(main->files_struct[i]->name, mx_ls_get_hidden(main->flags)), main);
        }
    }
}

void static print_files_without_dir(t_main *main) {
    char **files_without_dir = mx_until_create_char_arr(main->str_size);
    int k = 0;
    
    if (!main->str_size)
        mx_ls_loop(mx_read_dir(".", mx_ls_get_hidden(main->flags)), main);

    for (int i = 0; i < main->str_size; i++)
        main->files_struct[i] = mx_get_lstat(main->files[i]);
    main->files_struct[main->str_size] = NULL;
    for (int i = 0; main->files_struct[i]; i++) {
        files_without_dir[k] = mx_strdup(main->files_struct[i]->name);
        if (main->files_struct[i]->type != 'd')
            k++;
        else
            mx_strdel(&files_without_dir[k]);
    }
    mx_ls_loop(files_without_dir, main);
    print_dir(main);
}

void mx_ls(t_main *main) {
    mx_valid_flags(LS_VALIDATION_FLAG, "uls", main->flags, LS_CURRENT_FLAGS);
    print_files_without_dir(main);

    if (mx_ls_check_flag(main->flags, '1'))
        mx_printstr("\n");
}

#include "uls.h"

void static print_dir(t_ls **files, char *flags);
void static print_files_without_dir(t_ls **files, char *flags, int str_size);

void mx_ls(t_main *main) {
    if (!main->str_size) {
        char **memory = mx_read_dir(".", mx_ls_get_hidden(main->flags));
        mx_ls_loop(memory, main->flags);
        mx_del_strarr(&memory);
    }
    main->files_struct = mx_insort_lstat(main->files, main->files_struct, main->str_size);
    print_files_without_dir(main->files_struct, main->flags, main->str_size);
    if (mx_ls_check_flag(main->flags, '1'))
        mx_printstr("\n");
    mx_untill_del_tls(&main->files_struct);
}

void static print_files_without_dir(t_ls **files, char *flags, int str_size) {
    char **files_without_dir = mx_until_create_char_arr(str_size);
    int k = 0;

    for (int i = 0; files[i]; i++) {
        files_without_dir[k] = mx_strdup(files[i]->name);
        if (files[i]->type != 'd')
            k++;
        else
            mx_strdel(&files_without_dir[k]);
    }

    mx_ls_loop(files_without_dir, flags);
    print_dir(files, flags);
    mx_del_strarr(&files_without_dir);

}

void static print_dir(t_ls **files, char *flags) {
    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd') {
            mx_printstr(files[i]->print_name);
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, mx_ls_get_hidden(flags)), flags);
        }
    }
}

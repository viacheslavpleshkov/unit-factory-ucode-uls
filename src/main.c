#include "uls.h"
static bool mx_check_color(char *flags){
    if (mx_ls_check_flag(flags, 'G'))
        return true;
    return false;
}

t_main *mx_create_main(int argc, char **argv){
    t_main *main = malloc(sizeof(t_main));
    char *flags = mx_create_flags_str(argv, argc);
    char **files = mx_create_param_arr(argv, argc);
    int str_size = mx_until_get_size_arr(files);

    main->files = files;
    main->flags = flags;
    main->files_struct = mx_ls_create_struct_arr(str_size);
    main->files_struct_two = NULL;
    main->color = mx_check_color(flags);
    main->str_size = str_size;
    main->file_n = 0;
    main->terminal_width = mx_get_terminal_width();
    return main;
}

int main(int argc, char **argv) {
    t_main *main = NULL;
    main = mx_create_main(argc, argv);
    mx_ls(main);
    //system("leaks -q uls");
    return 0;
}

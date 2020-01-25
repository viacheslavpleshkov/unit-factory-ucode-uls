#include "uls.h"
static bool mx_check_color(char *flags){
    if (mx_ls_check_flag(flags, 'G'))
        return true;
    return false;
}

t_main *mx_create_main(int argc, char **argv){
    t_main *main = malloc(sizeof(t_main));
    char *flags = mx_create_flags_str(argv, argc);

    main->files = mx_create_param_arr(argv, argc);
    main->flags = mx_create_flags_str(argv, argc);
    main->color = mx_check_color(flags);
    return main;
}

int main(int argc, char **argv) {
    t_main *main = NULL;
    main = mx_create_main(argc, argv);
    mx_ls(main);
    //system("leaks -q uls");
    return 0;
}

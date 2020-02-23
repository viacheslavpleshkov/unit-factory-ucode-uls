#include "uls.h"

static bool check_colÎor(char *flags) {
    if (mx_until_check_flag(flags, 'G'))
        if (isatty(1) != 0)
            return true;
    return false;
}

static bool check_isatty(void) {
    bool result = true;

    if (isatty(1) == 0)
        result = false;
    return result;
}
static char *add_flag(int argc, char **argv) {
    char *temp = mx_ls_create_flags_str(argv, argc);
    char *flags = NULL;
    char *str = mx_strjoin(LS_VALID_STR_ONE, LS_VALID_STR_TWO);
    
    mx_ls_valid_flags(str, LS_FUNC_NAME, temp, LS_VALID_FLAGS);
    flags = mx_ls_clear_flags(temp, LS_CLEAR_STR);
    mx_strdel(&temp);
    mx_strdel(&str);
    return flags;
}

t_main *mx_ls_create_main(int argc, char **argv) {
    t_main *main = malloc(sizeof(t_main));
    char **files = mx_ls_create_param_arr(argv, argc);
    int str_size = mx_until_get_size_arr(files);
    char *flags = add_flag(argc, argv);

    main->files = files;
    main->files_struct = mx_ls_create_struct_arr(str_size);
    main->flags = flags;
    main->color = check_colÎor(flags);
    main->str_size = str_size;
    main->terminal_width = mx_ls_get_terminal_width();
    main->out_in_terminal = check_isatty();
    return main;
}

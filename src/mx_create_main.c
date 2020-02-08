#include "uls.h"

static bool check_colÎor(char *flags);
static bool check_isatty();

t_main *mx_create_main(int argc, char **argv) {
    t_main *main = malloc(sizeof(t_main));
    char *temp = mx_create_flags_str(argv, argc);
    char **files = mx_create_param_arr(argv, argc);
    int str_size = mx_until_get_size_arr(files);
    char *flags = NULL;

    mx_valid_flags(LS_VALID_STR, LS_FUNC_NAME, temp, LS_VALID_FLAGS);
    flags = mx_clear_flags(temp, LS_CLEAR_STR);
    mx_strdel(&temp);
    main->files = files;
    main->files_struct = mx_ls_create_struct_arr(str_size);
    main->flags = flags;
    main->color = check_colÎor(flags);
    main->str_size = str_size;
    main->terminal_width = mx_get_terminal_width();
    main->out_in_terminal = check_isatty();
    return main;
}

static bool check_colÎor(char *flags) {
    if (mx_ls_check_flag(flags, 'G'))
        if (isatty(1) != 0)
            return true;
    return false;
}

static bool check_isatty() {
    bool result = true;

    if (isatty(1) == 0)
        result = false;
    return result;
}

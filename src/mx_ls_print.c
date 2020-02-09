#include "uls.h"

void mx_ls_print(t_ls **files, t_main *main) {
    char *flags = main->flags;

    if (mx_untill_get_max_size(files) == 1)
        mx_ls_error(ERR_DIR, files[0]->print_name);
    else {
        if (mx_ls_check_flag(flags, 'l'))
            mx_ls_print_l(files, main);
        else if (mx_ls_check_flag(flags, '1'))
            mx_ls_print_one(files, main);
        else if (main->out_in_terminal == false)
            mx_ls_print_one(files, main);
        else
            mx_ls_print_big_c(files, main);
    }
}

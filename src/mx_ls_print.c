#include "uls.h"

void mx_ls_print(t_ls **files, t_main *main) {
    char *flags = main->flags;
    char *name = NULL;
    
    if (mx_untill_get_max_size(files) == 1) {
        name = mx_strdup(files[0]->print_name);
        mx_ls_error(ERR_DIR, name);
        mx_strdel(&name);
    } else {
        if (mx_ls_check_flag(flags, 'l'))
            mx_ls_print_l(files, main);
        else if (mx_ls_check_flag(flags, '1'))
            mx_ls_print_one(files, main);
        else if (mx_ls_check_flag(flags, 'm'))
            mx_ls_print_m(files, main);
        else if (main->out_in_terminal == false)
            if (mx_ls_check_flag(flags, 'C'))
                mx_ls_print_big_c(files, main);
            else
                mx_ls_print_one(files, main);
        else
            mx_ls_print_big_c(files, main);
    }
}

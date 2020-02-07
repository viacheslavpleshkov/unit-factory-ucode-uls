#include "uls.h"

void mx_ls_print(t_ls **files, t_main *main) {
    char *flags = main->flags;
    
    if ((mx_ls_check_flag(flags, 'l')) && (mx_ls_check_flag(flags, 'T')))
        mx_ls_print_big_t(files, main);
    else if(mx_ls_check_flag(flags, 'l'))
        mx_ls_print_l(files, main);
    else if (mx_ls_check_flag(flags, '1')) {
        mx_ls_print_one(files, main);
    } else
        if (main->out_in_terminal == false)
            mx_ls_print_one(files, main);
        else 
            mx_ls_print_big_c(files, main);
}

#include "uls.h"

void mx_ls_print(t_main *main) {
    if ((mx_ls_check_flag(main->flags, 'l')) && (mx_ls_check_flag(main->flags, 'T')))
        mx_ls_print_big_t(main);
    else if(mx_ls_check_flag(main->flags, 'l'))
        mx_ls_print_l(main);
    else if (mx_ls_check_flag(main->flags, '1')) {
        mx_ls_print_1(main->files_struct_two, main->color, main->file_n);
    } else {
        mx_ls_print_big_c(main);
    }
}

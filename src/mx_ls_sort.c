#include "uls.h"

void mx_ls_sort(t_ls **files, char *flags) {
    mx_ls_sort_default(files);
    if (mx_ls_check_flag(flags, 'r'))
        mx_ls_sort_flag_r(files);
    if (mx_ls_check_flag(flags, 't'))
        mx_ls_sort_flag_t(files);
    if (mx_ls_check_flag(flags, 'u'))
        mx_ls_sort_flag_u(files);
    if (mx_ls_check_flag(flags, 'c'))
        mx_ls_sort_flag_c(files);
    if (mx_ls_check_flag(flags, 'S'))
        mx_ls_sort_flag_big_s(files);
}

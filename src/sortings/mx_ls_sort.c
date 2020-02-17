#include "uls.h"

void mx_ls_sort(t_ls **files, char *flags, int size) {
    mx_ls_sort_default(files, size);
    if (mx_until_check_flag(flags, 'r'))
        mx_ls_sort_flag_r(files, size);
    if (mx_until_check_flag(flags, 't'))
        mx_ls_sort_flag_t(files, size);
    if (mx_until_check_flag(flags, 'u'))
        mx_ls_sort_flag_u(files, size);
    if (mx_until_check_flag(flags, 'c'))
        mx_ls_sort_flag_c(files, size);
    if (mx_until_check_flag(flags, 'S'))
        mx_ls_sort_flag_big_s(files, size);
}

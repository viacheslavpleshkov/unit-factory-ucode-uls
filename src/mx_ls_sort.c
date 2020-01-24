#include "uls.h"

void mx_ls_sort(t_ls **files, char *flags) {
    mx_ls_sort_default(files);
    if (mx_get_char_index(flags, 'r') >= 0)
        mx_ls_sort_flag_r(files);
    if (mx_get_char_index(flags, 't') >= 0)
        mx_ls_sort_flag_t(files);
    if (mx_get_char_index(flags, 'u') >= 0)
        mx_ls_sort_flag_u(files);
    if (mx_get_char_index(flags, 'c') >= 0)
        mx_ls_sort_flag_c(files);
    if (mx_get_char_index(flags, 'S') >= 0)
        mx_ls_sort_flag_big_s(files);
}

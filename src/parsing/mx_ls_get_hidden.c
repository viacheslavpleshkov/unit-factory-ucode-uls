#include "uls.h"

int mx_ls_get_hidden(char *flags) {
    if (mx_until_check_flag(flags, 'a'))
        return LS_HIDDEN_a;
    else if (mx_until_check_flag(flags, 'A'))
        return LS_HIDDEN_A;
    else
        return LS_HIDDEN_NOT;
}

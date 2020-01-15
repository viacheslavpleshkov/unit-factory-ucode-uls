#include "uls.h"

int mx_ls_get_hidden(char *flags) {
    if (mx_get_char_index(flags, 'a') >= 0)
        return LS_HIDDEN_a;
    else if (mx_get_char_index(flags, 'A') >= 0)
        return LS_HIDDEN_A;
    else
        return LS_HIDDEN_NOT;
}

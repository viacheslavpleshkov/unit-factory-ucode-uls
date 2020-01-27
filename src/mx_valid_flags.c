#include "uls.h"

void mx_valid_flags(char *str, char *func_name, char *flags, char *valid_flags) {
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    char *tmp3 = NULL;

    if (!str || !func_name || !flags || !valid_flags)
        return;
    for (int i = 0; flags[i]; i++)
        if (mx_get_char_index(valid_flags, flags[i]) < 0) {
            tmp1 = mx_replace_substr(str, "&func_name", func_name);
            tmp2 = mx_replace_substr(tmp1, "&inv_flag", mx_strndup(&flags[i], 1));
            tmp3 = mx_replace_substr(tmp2, "&valid_flags", valid_flags);
            mx_print_error(tmp3, 1);
        }
}

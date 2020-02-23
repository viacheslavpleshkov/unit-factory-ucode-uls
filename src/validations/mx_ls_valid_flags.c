#include "uls.h"

void print_template(const char *str, char *f_name, char flag, char *v_flags) {
    char *tmp = NULL;

    if (str)
        tmp = mx_strndup(str, 10);
    if (!mx_strcmp(tmp, "&func_name"))
        write(2, f_name, mx_strlen(f_name));
    else if (!mx_strcmp(tmp, "&invalflag"))
        write(2, &flag, 1);
    else if (!mx_strcmp(tmp, "&val_flags"))
        write(2, v_flags, mx_strlen(v_flags));
    mx_strdel(&tmp);
}

void mx_ls_valid_flags(char *str, char *f_name, char *flags, char *v_flags) {
    int len = mx_strlen(str);

    if (!str || !f_name || !flags || !v_flags)
        return;
    for (int i = 0; flags[i]; i++)
        if (mx_get_char_index(v_flags, flags[i]) < 0) {
            for (int j = 0; j < len; j++)
                if (str[j] != '&')
                    write(2, &str[j], 1);
                else {
                    print_template(&str[j], f_name, flags[i], v_flags);
                    j += 10;
                }
            write(2, "\n", 1);
            exit(1);
        }
}

#include "uls.h"

void print_template(const char *str, char *func_name, char flag, char *valid_flags) {
    char *tmp = NULL;

    if (str)
        tmp = mx_strndup(str, 10);
    if (!mx_strcmp(tmp, "&func_name"))
        write(2, func_name, mx_strlen(func_name));
    else if (!mx_strcmp(tmp, "&invalflag"))
        write(2, &flag, 1);
    else if (!mx_strcmp(tmp, "&val_flags"))
        write(2, valid_flags, mx_strlen(valid_flags));
}

void mx_valid_flags(char *str, char *func_name, char *flags, char *valid_flags) {
    int len = mx_strlen(str);

    if (!str || !func_name || !flags || !valid_flags)
        return;
    for (int i = 0; flags[i]; i++)
        if (mx_get_char_index(valid_flags, flags[i]) < 0) {
            for (int j = 0; j < len; j++)
                if (str[j] != '&')
                    write(2, &str[j], 1);
                else {
                    print_template(&str[j], func_name, flags[i], valid_flags);
                    j += 10;
                }
            write(2, "\n", 1);
            exit(1);
        }
}

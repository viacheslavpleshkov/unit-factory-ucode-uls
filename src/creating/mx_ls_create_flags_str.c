#include "uls.h"

char *mx_ls_create_flags_str(char **argv, int argc) {
    char *flags = NULL;
    char *temp = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (flags)
                temp = mx_strdup(flags);
            mx_strdel(&flags);
            flags = mx_strjoin(temp, &argv[i][1]);
            mx_strdel(&temp);
        }
        else
            break;
    }
    return flags;
}

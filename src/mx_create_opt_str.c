#include "uls.h"

char *mx_create_opt_str(char **argv, int argc) {
    char *opt = NULL;
    char *temp = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (opt)
                temp = mx_strdup(opt);
            mx_strdel(&opt);
            opt = mx_strjoin(temp, &argv[i][1]);
            mx_strdel(&temp);
        }
        else
            break;
    }
    return opt;
}

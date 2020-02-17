
#include "uls.h"

static void mx_strdel_tls(t_ls **str) {
    free(*str);
    *str = NULL;
}

void mx_until_del_tls(t_ls ***arr) {
    int i = 0;

    while ((*arr)[i]) {
        free((*arr)[i]->gid_name);
        free((*arr)[i]->uid_name);
        free((*arr)[i]->name);
        mx_strdel_tls(&(*arr)[i]);
        i++;
    }
    free(*arr);
    *arr = NULL;
}

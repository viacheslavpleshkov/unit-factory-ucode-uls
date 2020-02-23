#include "uls.h"

char *mx_ls_get_uid_name(int st_uid) {
    struct passwd *pwd;
    char *srr = mx_itoa(st_uid);

    pwd = getpwuid(st_uid);
    if (pwd){
        mx_strdel(&srr);
        return mx_strdup(pwd->pw_name);
    }
    else
        return srr;
}

#include "uls.h"

char *mx_get_uid_name(int st_uid) {
    struct passwd *pwd;

    pwd = getpwuid(st_uid);
    if (pwd)
        return pwd->pw_name;
    else
        return mx_itoa(st_uid);
}

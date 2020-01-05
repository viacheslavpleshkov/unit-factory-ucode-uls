#include "uls.h"

char *mx_get_gid_name(int st_gid) {
    struct group *grp;

    grp = getgrgid(st_gid);
    if (grp)
        return grp->gr_name;
    else
        return mx_itoa(st_gid);
}

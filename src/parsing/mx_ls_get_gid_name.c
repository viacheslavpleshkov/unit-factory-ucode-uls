#include "uls.h"

char *mx_ls_get_gid_name(int st_gid) {
    struct group *grp = getgrgid(st_gid);
    
    if (grp)
        return mx_strdup(grp->gr_name);
    else
        return mx_itoa(st_gid);
}

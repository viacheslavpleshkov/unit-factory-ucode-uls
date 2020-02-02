#include "uls.h"

static struct stat get_stat(const char *file, int mode) {
    struct stat buf;

    if (mode == GET_STAT)
        stat(file, &buf);
    else
        lstat(file, &buf);
    return buf;
}

t_ls *mx_get_lstat(const char *file) {
    struct stat lbuf = get_stat(file, GET_LSTAT);
    t_ls *new_struct = malloc(sizeof(t_ls));
    char* gid_name = mx_ls_get_gid_name(lbuf.st_gid);
    char* uid_name = mx_ls_get_uid_name(lbuf.st_uid);

    new_struct->name = (char *)file;
    new_struct->print_name = mx_ls_get_print_name(file);
    new_struct->acl_inf = mx_ls_get_acl_inf(file);
    new_struct->type = mx_ls_get_type(lbuf.st_mode);
    new_struct->mode = lbuf.st_mode;
    new_struct->size = lbuf.st_size;
    new_struct->nlink = lbuf.st_nlink;
    new_struct->uid_name = uid_name;
    new_struct->gid_name = gid_name;
    new_struct->blksize = lbuf.st_blksize;
    new_struct->blocks = lbuf.st_blocks;
    new_struct->atime = lbuf.st_atime;
    new_struct->mtime = lbuf.st_mtime;
    new_struct->ctime = lbuf.st_ctime;
    // mx_strdel(&gid_name);
    return new_struct;
}

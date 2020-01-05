#include "uls.h"

static struct stat get_stat(const char *file, int mode) {
    struct stat buf;

    if (mode == GET_STAT) 
        stat(file, &buf);
    else
        lstat(file, &buf);
    return buf;
}

t_file *mx_get_lstat(const char *file) {
    //struct stat buf = get_stat(file, GET_STAT);
    struct stat lbuf = get_stat(file, GET_LSTAT);
    t_file *new_struct = NULL;

   
        new_struct = malloc(sizeof(t_file));
        new_struct->name = mx_strdup(file);
        new_struct->print_name = mx_get_print_name(file);
        new_struct->acl_inf = mx_get_acl_inf(file);
        new_struct->color = NULL;
        new_struct->type = mx_get_type(lbuf.st_mode);
        new_struct->mode = lbuf.st_mode;
        new_struct->size = lbuf.st_size;
        new_struct->nlink = lbuf.st_nlink;
        new_struct->uid_name = mx_get_uid_name(lbuf.st_uid);
        new_struct->gid_name = mx_get_gid_name(lbuf.st_gid);
        new_struct->blksize = lbuf.st_blksize;
        new_struct->blocks = lbuf.st_blocks;
        new_struct->atime = lbuf.st_atime;
        new_struct->mtime = lbuf.st_mtime;
        new_struct->ctime = lbuf.st_ctime;
    
    return new_struct;
}

#include "uls.h"

static struct stat get_stat(const char *file, int mode) {
    struct stat buf;

    if (mode == GET_STAT)
        stat(file, &buf);
    else
        lstat(file, &buf);
    return buf;
}

static char *pop_char(char *str, int index) {
    int len = 0;
    char *result = NULL;

    if (str) {
        len = mx_strlen(str);
        result = mx_strnew(len - 1);
        for (int i = 0; i < len; i++) {
            if (i < index)
                result[i] = str[i];
            else
                result[i] = str[i + 1];
        }
    }
    return result;
}

static char *check_file(const char *file, unsigned short int file_mode) {
    char *result = mx_strdup(file);
    char *tmp = NULL;
    char type = mx_ls_get_type(file_mode);

    if (file) {
        for (int i = 0; i < result[i]; i++)
            if (result[i] == '/' && result[i + 1] == '/' && type != 'd') {
                tmp = mx_strdup(result);
                mx_strdel(&result);
                result = pop_char(tmp, i + 1);
                mx_strdel(&tmp);
                i--;
            }
    }
    return result;
}

t_ls *mx_ls_get_lstat(const char *file) {
    struct stat lbuf = get_stat(file, GET_LSTAT);
    t_ls *new_struct = malloc(sizeof(t_ls));
    char *gid_name = mx_ls_get_gid_name(lbuf.st_gid);
    char *uid_name = mx_ls_get_uid_name(lbuf.st_uid);

    new_struct->name = check_file(file, lbuf.st_mode);
    new_struct->print_name = mx_ls_get_print_name(file);
    new_struct->acl_inf = mx_ls_get_acl_inf(file);
    new_struct->type = mx_ls_get_type(lbuf.st_mode);
    new_struct->color = mx_ls_get_color(lbuf);
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
    new_struct->ino = lbuf.st_ino;
    new_struct->file_major = major(lbuf.st_rdev);
    new_struct->file_minor = minor(lbuf.st_rdev);
    return new_struct;
}

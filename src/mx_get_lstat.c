#include "uls.h"

t_file *mx_get_lstat(char *file) {
    struct stat buf;

    lstat(file, &buf);
    return NULL;
}

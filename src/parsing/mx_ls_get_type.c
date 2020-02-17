#include "uls.h"

char mx_ls_get_type(unsigned short int file_mode) {
    if ((file_mode & S_IFMT) == S_IFBLK)
        return 'b';
    else if (((file_mode & S_IFMT) == S_IFREG) && (
        file_mode & S_IXUSR) == S_IXUSR)
        return '-';
    else if ((file_mode & S_IFMT) == S_IFCHR)
        return 'c';
    else if ((file_mode & S_IFMT) == S_IFIFO)
        return 'p';
    else if ((file_mode & S_IFMT) == S_IFSOCK)
        return 's';
    else if ((file_mode & S_IFMT) == S_IFDIR)
        return 'd';
    else if ((file_mode & S_IFMT) == S_IFLNK)
        return 'l';
    return '-';
}

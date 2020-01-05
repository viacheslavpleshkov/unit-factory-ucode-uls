#include "uls.h"

char mx_get_type(unsigned short int file_mode) {
    if (S_IFMT == (S_IFMT & file_mode))
        return '-';
    else if (S_IFBLK == (S_IFBLK & file_mode))
        return 'b';
    else if (S_IFCHR == (S_IFCHR & file_mode))
        return 'b';
    else if (S_IFIFO == (S_IFIFO & file_mode))
        return 'p';
    else if (S_IFREG == (S_IFREG & file_mode))
        return 's';
    else if (S_IFDIR == (S_IFDIR & file_mode))
        return 'd';
    else if (S_IFLNK == (S_IFLNK & file_mode))
        return 'l';
    return '-';
}

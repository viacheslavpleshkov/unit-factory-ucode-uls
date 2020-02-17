#include "uls.h"

static char dir_check(struct stat buf) {
    char c = '-';

    if ((buf.st_mode & S_IFMT) == S_IFDIR) {
        c = 'd';
        if ((buf.st_mode & S_ISVTX) == S_ISVTX
            && (buf.st_mode & S_IWOTH) == S_IWOTH)
            c = 'x';
        else if ((buf.st_mode & S_IWOTH) == S_IWOTH)
            c = 'n';
    }
    return c;
}

static char second_mode_unit(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT) {
        case (S_IFBLK):
            c = 'b';
            break;
        case (S_IFCHR):
            c = 'c';
            break;
        case (S_IFIFO):
            c = 'p';
            break;
    }
    if (c == '-')
        c = dir_check(buf);
    return c;
}

static char file_check(struct stat buf) {
    char c = '-';

    if ((buf.st_mode & S_IFMT) == S_IFREG) {
        c = 'f';
        if ((buf.st_mode & S_IXUSR) == S_IXUSR) {
            c = 'e';
            if ((buf.st_mode & S_ISUID) == S_ISUID)
                c = 'u';
            else if ((buf.st_mode & S_ISGID) == S_ISGID)
                c = 'g';
        }
    }
    return c;
}

static char one_mode_unit(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT) {
        case (S_IFSOCK):
            c = 's';
            break;
        case (S_IFLNK):
            c = 'l';
            break;
    }
    if (c == '-')
        c = file_check(buf);
    return c;
}

char mx_ls_get_color(struct stat buf) {
    char c;
    c = one_mode_unit(buf);
    if (c == '-')
        c = second_mode_unit(buf);
    return c;
}

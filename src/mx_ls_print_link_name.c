#include "uls.h"

void mx_ls_print_link_name(const char *file) {
    char *buf = NULL;
    struct stat sb;
    ssize_t nbytes = 0;
    ssize_t buf_size = 0;

    lstat(file, &sb);
    buf_size = sb.st_size + 1;
    buf = mx_strnew(buf_size);
    nbytes = readlink(file, buf, buf_size);
    mx_printstr(" -> ");
    if (nbytes >= 0)
        mx_printstr(buf);
    mx_strdel(&buf);
}

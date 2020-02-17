#include "uls.h"

ino_t mx_ls_get_ino_dev_fd() {
    struct  stat buf;
        
    lstat("/dev/fd", &buf);
    return buf.st_ino;
}

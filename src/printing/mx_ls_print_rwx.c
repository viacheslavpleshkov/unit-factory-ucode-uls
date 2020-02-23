#include "uls.h"

void mx_ls_print_rwx(t_ls *files) {
    char *rwx_str = mx_ls_get_rwx_str(files->mode);
    
    mx_printstr(rwx_str);
    mx_strdel(&rwx_str);
}

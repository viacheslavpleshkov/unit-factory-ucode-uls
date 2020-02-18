
#include "uls.h"

void mx_until_major_minor(t_ls *files) {
    char *major = mx_itoa((int)files->file_major);
    char *minor = mx_itoa((int)files->file_minor);
    
    mx_until_print_format_str(major, 'r', ' ', 5);
    mx_printstr(",");
    mx_until_print_format_str(minor, 'r', ' ', 4);
    mx_printstr(" ");
    mx_strdel(&major);
    mx_strdel(&minor);
}

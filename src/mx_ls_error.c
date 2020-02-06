#include "uls.h"

void mx_ls_error(t_error err, char *s) {
    if (err == ERR_EACCES) {
        mx_print_error_basic("uls: ");
        mx_print_error_basic(s);
        mx_print_error_basic(": ");
        mx_print_error_basic(strerror(errno));
        mx_print_error_basic("\n");
    }
}

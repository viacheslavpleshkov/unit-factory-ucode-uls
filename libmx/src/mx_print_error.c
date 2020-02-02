#include "libmx.h"

void mx_print_error(const char *str, int exit_code) {
    write(2, str, mx_strlen(str));
    write(2, "\n", 1);
    exit(exit_code);
}

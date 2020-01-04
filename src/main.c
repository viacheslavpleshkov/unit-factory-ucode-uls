#include "uls.h"

int main (int argc, char **argv) {
    char **files = mx_create_files_arr(argv, argc);
    char *opt = mx_create_opt_str(argv, argc);

    if (!files[0])
        files[0] = mx_strdup(".");
    mx_loop(".", files, opt);
    return 0;
}

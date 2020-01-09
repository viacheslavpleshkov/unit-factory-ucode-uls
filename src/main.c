#include "uls.h"

int main(int argc, char **argv) {
    char **files = mx_create_param_arr(argv, argc);
    char *flags = mx_create_flags_str(argv, argc);

    mx_ls(files, flags);
    //system("leaks -q uls");
    return 0;
}

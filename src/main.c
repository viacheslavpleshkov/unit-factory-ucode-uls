#include "uls.h"

int main(int argc, char **argv) {
    t_main *main = NULL;

    main = mx_ls_create_main(argc, argv);
    mx_ls(main);
    return(0);
}


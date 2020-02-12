#include "uls.h"

int main(int argc, char **argv) {
    t_main *main = NULL;

    main = mx_create_main(argc, argv);
    mx_ls(main);
    system("leaks -q uls");
}


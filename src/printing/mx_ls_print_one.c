#include "uls.h"

void mx_ls_print_one(t_ls **files, t_main *main) {
    for (int i = 0; i != main->file_n; i++) {
        mx_ls_print_color(files[i], main->color);
        mx_printstr("\n");
    }
}

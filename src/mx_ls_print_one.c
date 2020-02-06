#include "uls.h"

void mx_ls_print_one(t_ls **files, t_main *main) {
    for (int i = 0; i != main->file_n; i++) {
        if (i != 0)
            mx_printstr("\n");
        mx_ls_print_color(files[i]->color, files[i]->print_name, main->color);
    }   
}

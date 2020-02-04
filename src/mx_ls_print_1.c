#include "uls.h"

void mx_ls_print_1(t_ls **files, t_main *main) {
    for (int i = 0; i != main->file_n; i++) {
        if (i != 0)
            mx_printstr("\n");
        print_color(files[i]->type, files[i]->print_name, main->color);
    }   
}

#include "uls.h"

void mx_ls_print_1(t_ls **files, bool color, int file_n) {
    for (int i = 0; i < file_n; i++){
        if (i != 0)
            mx_printstr("\n");
        mx_ls_print_colors(files[i]->type, files[i]->print_name, color);
    }
}

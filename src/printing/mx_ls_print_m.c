#include "uls.h"

void mx_ls_print_m(t_ls **files, t_main *main) {
    int leng = 0;

    for (int i = 0; i != main->file_n; i++) {
        if (i != 0 && leng != 0){
            mx_printstr(" ");
            leng += mx_strlen(" ");
        }
        leng += mx_strlen(files[i]->name) ;
        mx_ls_print_color(files[i], main->color);
        if (i != main->file_n -1)
            mx_printstr(",");
        if (leng >= main->terminal_width) {
            mx_printstr("\n");
            leng = 0;
        }
        if (i == main->file_n - 1)
            mx_printstr("\n");
    }
}

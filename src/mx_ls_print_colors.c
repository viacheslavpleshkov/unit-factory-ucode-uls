#include "uls.h"

void mx_ls_print_colors(char type, char *name, bool color) {
    if (color == true) {
        if (type == 'd') {
            mx_printstr(LS_COLOR_BLUE);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } else if (type == 'x') {
            mx_printstr(LS_COLOR_RED);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } else {
            mx_printstr(name);
        }    
    } else
        mx_printstr(name);
}

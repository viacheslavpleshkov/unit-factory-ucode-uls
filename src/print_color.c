#include "uls.h"

void print_color(char type, char *name, bool status) {
    if (status == true){
        if (type == 'd') {
            mx_printstr(LS_COLOR_BLUE);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } else if (type == 'x') {
            mx_printstr(LS_COLOR_RED);
            mx_printstr(name);
            mx_printstr(LS_COLOR_RESET);
        } else
            mx_printstr(name);
    } else
        mx_printstr(name);
}

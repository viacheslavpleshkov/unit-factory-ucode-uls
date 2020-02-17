#include "uls.h"

static void print_color_one(char type, char *name) {
    if (type == 'd') {
        mx_printstr("\33[0;34m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'f') {
        mx_printstr(name);
    } else if (type == 'l') {
        mx_printstr("\33[0;35m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'e') {
        mx_printstr("\33[0;31m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'c') {
        mx_printstr("\33[0;34;43m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    }
}

static void print_color_two(char type, char *name) {
    if (type == 'b') {
        mx_printstr("\33[0;34;46m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'x') {
        mx_printstr("\33[0;30;42m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'u') {
        mx_printstr("\33[0;30;41m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    }
}

static void print_color_tree(char type, char *name) {
    if (type == 's') {
        mx_printstr("\33[0;32m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'g') {
        mx_printstr("\33[0;30;46m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == 'n') {
        mx_printstr("\33[0;30;41m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    } else if (type == '-') {
        mx_printstr("\33[0;34m");
        mx_printstr(name);
        mx_printstr("\33[0m");
    }
}

void mx_ls_print_color(t_ls *ls, bool status) {
    char *name = mx_ls_valid_name(ls->print_name);
    
    if (status == true) {
        print_color_one(ls->type, name);
        print_color_two(ls->type, name);
        print_color_tree(ls->type, name);
    } else
        mx_printstr(name);
    mx_strdel(&name);
}

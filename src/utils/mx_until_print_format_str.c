#include "uls.h"

static void print_symbol(char symbol, int number) {
	for (int i = 0; i < number; i++)
		mx_printchar(symbol);
}

void mx_until_print_format_str(char *str, char local, char symbol, int size) {
    int len = mx_strlen(str);

    if (local == 'c')
        print_symbol(symbol, (size - len) / 2); 
    if (local == 'r')
        print_symbol(symbol, size - len); 
    mx_printstr(str);
    if (local == 'c')
        print_symbol(symbol, size - len - (size - len) / 2);
    if (local == 'l')
        print_symbol(symbol, size - len);
}

void mx_until_print_format_l(t_ls *file, t_main *main, int size) {
    int len = mx_strlen(file->print_name);
    char name = 'l';

    if (name == 'c')
        print_symbol(' ', (size - len) / 2); 
    if (name == 'r')
        print_symbol(' ', size - len); 
    mx_ls_print_color(file, main->color);
    if (name == 'c')
        print_symbol(' ', size - len - (size - len) / 2);
    if (name == 'l')
        print_symbol(' ', size - len); 
}


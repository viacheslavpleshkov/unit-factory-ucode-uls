#include "libmx.h"

static void print_symbol(char symbol, int number) {
	for (int i = 0; i < number; i++)
		mx_printchar(symbol);
}

void mx_print_format_str(char *str, char location, char symbol, int size) {
    int len = mx_strlen(str);

    switch (location) {
        case 'c': print_symbol(symbol, (size - len) / 2); break;
        case 'r': print_symbol(symbol, size - len); break;
    }

    mx_printstr(str);

    switch (location) {
        case 'c': print_symbol(symbol, size - len - (size - len) / 2); break;
        case 'l': print_symbol(symbol, size - len); break;
    }
}

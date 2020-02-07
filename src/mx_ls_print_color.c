#include "uls.h"

void mx_ls_print_color(char type, char *name, bool status) {
    if (status == true){
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
        } else if (type == 'b') { 
            mx_printstr("\33[0;34;46m");
            mx_printstr(name);
            mx_printstr("\33[0m");
        } else if (type == 'x') { 
            mx_printstr("\33[0;30;42m");
            mx_printstr(name);
            mx_printstr("\33[0m");
        }else if (type == 'u') { 
            mx_printstr("\33[0;30;41m");
            mx_printstr(name);
            mx_printstr("\33[0m");
        } else if (type == 's') { 
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
        } else
            mx_printstr(name);
        
    } else
        mx_printstr(name);
    
}

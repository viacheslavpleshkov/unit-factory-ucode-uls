#include "uls.h"

char *mx_ls_get_print_name(const char *file) {
    for (int i = mx_strlen(file) - 1; i != 0; i--)
        if (file[i] == '/') 
         return (char*) &file[i + 1];
    return (char*) file;
}

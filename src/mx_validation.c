#include "uls.h"

char *mx_validation_name(char *name) {
    char name_rename = NULL;
    name_rename = mx_replace_substr(name, '?', '\n');
    if (!name_rename)
       return name_rename;
   return name;
}
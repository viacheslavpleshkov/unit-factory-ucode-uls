#include "uls.h"

bool mx_ls_check_character_files(t_ls **files) {
    bool result = false;

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'c' || files[i]->type == 'b') {
            result = true;
            break;
        }
    return result;
}


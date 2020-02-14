#include "uls.h"

int mx_max_uid_str(t_ls **files) {
    int max_len = 0;
    int len = 0;

    for (int i = 0; files[i]; i++) {
        len = mx_strlen(files[i]->uid_name);
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

int mx_max_gid_str(t_ls **files) {
    int max_len = 0;
    int len = 0;

    for (int i = 0; files[i]; i++) {
        len = mx_strlen(files[i]->gid_name);
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

bool mx_check_character_files(t_ls **files) {
    bool result = false;

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'c' || files[i]->type == 'b') {
            result = true;
            break;
        }
    return result;
}


#include "uls.h"

int mx_until_max_uid_str(t_ls **files) {
    int max_len = 0;
    int len = 0;

    for (int i = 0; files[i]; i++) {
        len = mx_strlen(files[i]->uid_name);
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

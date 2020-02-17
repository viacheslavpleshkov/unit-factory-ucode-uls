#include "uls.h"

bool mx_until_check_flag(const char *flags, char flag) {
    if (mx_get_char_index(flags, flag) >= 0)
       return true;
    return false;
}

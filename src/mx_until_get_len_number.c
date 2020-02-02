#include "uls.h"

int mx_until_get_len_number(unsigned long long int number) {
    int len = 0;

    for (unsigned long long int i = number; i != 0; i /= 10)
        len++;
    return len;
}

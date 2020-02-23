#include "uls.h"

char **mx_until_create_char_arr(int number) {
    char **res = (char **)malloc(sizeof(char*) * (number + 1));

    for (int i = 0; i <= number; i++)
        res[i] = NULL;
    return res;
}

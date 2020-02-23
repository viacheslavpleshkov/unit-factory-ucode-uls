#include "uls.h"

t_ls **mx_ls_create_struct_arr(int files_number) {
    t_ls **head = malloc(sizeof(t_ls*) * (files_number + 1));

    for (int i = 0; i < files_number; i++)
        head[i] = malloc(sizeof(t_ls));
    head[files_number] = NULL;
    return head;
}

#include "uls.h"

static int get_hidden(char *flags) {
    if (mx_get_char_index(flags, 'a') >= 0)
        return LS_HIDDEN_a;
    else if (mx_get_char_index(flags, 'A') >= 0)
        return LS_HIDDEN_A;
    else
        return LS_HIDDEN_NOT;
}

static t_ls **create_struct_arr(int files_number) {
    t_ls **head = malloc(sizeof(t_ls *) * (files_number + 1));

    for (int i = 0; i < files_number; i++)
        head[i] = malloc(sizeof(t_ls));
    head[files_number] = NULL;
    return head;
}

void mx_ls(char **str_arr, char *flags) {
    //char *new_flags = mx_clear_flags(char *flags);
    // int str_size = mx_get_size_arr(str_arr);
    // t_ls **files = create_struct_arr(str_size);
    // char **files_without_dir = mx_until_create_char_arr(str_size);
    // int k = 0;

    // if (!str_size)
    //     mx_ls_loop(mx_read_dir(".", get_hidden(flags)), flags);
    
    // for (int i = 0; i < str_size; i++) {
    //     files[k] = mx_get_lstat(str_arr[i]);
    //     if (files[k]->type == 'd')
    //         free(files[k]);
    //     else
    //         k++;
    //     mx_print_lstat(files[i]);
    // }
    
    // for (int i = 0; files[i]; i++)
    //     files_without_dir[i] = mx_strdup(files[i]->name);
    
    // mx_ls_loop(files_without_dir, flags);
    
    mx_ls_loop(str_arr, flags);
}

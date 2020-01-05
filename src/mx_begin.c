#include "uls.h"

static t_file **create_struct_arr(int files_number) {
    t_file **head = malloc(sizeof(t_file*) * (files_number + 1));

    for (int i = 0; i < files_number; i++)
        head[i] = malloc(sizeof(t_file));
    head[files_number] = NULL;
    return head;
}

static int size_arr(char **files_name) {
    int i = 0;

    if (files_name)
        for (i = 0; files_name[i]; i++);
    return i;
}

static int get_hidden(char *opt) {
    if (mx_get_char_index(opt, 'a') >= 0)
        return HIDDEN_a;
    else if (mx_get_char_index(opt, 'A') >= 0)
        return HIDDEN_A;
    else
        return HIDDEN_NOT;
}

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}

void mx_begin(char **files_name, char *opt) {
    int file_n = size_arr(files_name);
    t_file **files = create_struct_arr(file_n);

    for (int i = 0; files_name[i]; i++)
        files[i] = mx_get_lstat(files_name[i]);

    mx_print_ls(files, file_n, opt);

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' && mx_get_char_index(opt, 'R') >= 0) {
            if (mx_get_char_index(opt, 'a') >= 0 
                && !check_symbol(files[i]->print_name))
                    continue;
            mx_printstr("\n");
            mx_printstr(files[i]->name);
            mx_printstr(":\n");
            mx_begin(mx_read_dir(files[i]->name, get_hidden(opt)), opt);
        }
}

#include "uls.h"

static int get_max_len(t_ls **files) {
    int max_len = 0;

    for (int i = 0; files[i] != NULL; i++)
        if (mx_strlen(files[i]->print_name) > max_len)
            max_len = mx_strlen(files[i]->print_name);
    return max_len;
}

void mx_ls_print_big_c(t_main *main) {
    int row = LEN_TAB * (get_max_len(main->files_struct_two) / LEN_TAB) + LEN_TAB;
    int cols = main->terminal_width / row;
    int rows = main->file_n / cols;

    if (main->file_n % cols != 0)
        rows++;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (main->file_n - 1 == j * rows + i)
                mx_ls_print_colors(main->files_struct_two[j * rows + i]->type, main->files_struct_two[j * rows + i]->print_name, main->color);
            if (main->file_n - 1> j * rows + i)
                mx_until_print_format_str(main->files_struct_two[j * rows + i]->print_name, 'l', ' ', row);
        }
        mx_printchar('\n');
    }
}

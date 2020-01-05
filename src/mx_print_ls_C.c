#include "uls.h"

void mx_print_ls_C(char **files, int file_n, int max_len, int len_terminal) {
    int row = LEN_TAB * (max_len / LEN_TAB) + LEN_TAB;
    int cols = len_terminal / row;
    int rows = file_n / cols;

    if (file_n % cols != 0)
        rows++;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (file_n - 1 == j * rows + i)
                mx_printstr(files[j * rows + i]);
            if (file_n - 1> j * rows + i)
                mx_print_format_str(files[j * rows + i], 'l', ' ', row);
        }
        mx_printchar('\n');
    }
}

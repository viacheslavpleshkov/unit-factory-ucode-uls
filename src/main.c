#include "uls.h"

static int get_hidden(char *flags) {
    if (mx_get_char_index(flags, 'a') >= 0)
        return HIDDEN_a;
    else if (mx_get_char_index(flags, 'A') >= 0)
        return HIDDEN_A;
    else
        return HIDDEN_NOT;
}

int main(int argc, char **argv) {
    char **files = mx_create_files_arr(argv, argc);
    char *flags = mx_create_flags_str(argv, argc);

    if (!files[0])
        mx_ls(mx_read_dir(".", get_hidden(flags)), flags);
    else
        mx_ls(files, flags);
    return 0;
}

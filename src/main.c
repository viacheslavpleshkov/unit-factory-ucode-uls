#include "uls.h"

static int get_hidden(char *opt) {
    if (mx_get_char_index(opt, 'a') >= 0)
        return HIDDEN_a;
    else if (mx_get_char_index(opt, 'A') >= 0)
        return HIDDEN_A;
    else
        return HIDDEN_NOT;
}

int main(int argc, char **argv) {
    char **files = mx_create_files_arr(argv, argc);
    char *opt = mx_create_opt_str(argv, argc);

    if (!files[0])
        mx_begin(mx_read_dir(".", get_hidden(opt)), opt);
    else
        mx_begin(files, opt);
    return 0;
}

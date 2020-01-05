#include "uls.h"

static int get_len_number(unsigned long long int number) {
    int len = 0;

    for (unsigned long long int i = number; i != 0; i /= 10)
        len++;

    return len;
}

static int get_max_nlink(t_file **files) {
    unsigned int max_nlink = 0;

    for (int i = 0; files[i]; i++)
        if (files[i]->nlink > max_nlink)
            max_nlink = files[i]->nlink;
    return get_len_number(max_nlink);
}

static int get_max_size(t_file **files) {
    long long int max_size = 0;

    for (int i = 0; files[i]; i++)
        if (files[i]->size > max_size)
            max_size = files[i]->size;
    return get_len_number(max_size);
}

void mx_print_ls_l(t_file **files, int file_n, char *opt) {
    int max_nlink_len = get_max_nlink(files);
    int max_size_len = get_max_size(files);
    char *time_str = NULL;
    char *temp = NULL;
    long long int total = 0;
 
    mx_printstr("total ");  
    for (int i = 0; i < file_n; i++)
        total += files[i]->blocks;
    mx_printstr(mx_itoa(total));
    mx_printchar('\n');

    for (int i = 0; i < file_n; i++) {
        temp = ctime(&files[i]->mtime);
        time_str = mx_strndup(&temp[4], 12);
        mx_printchar(files[i]->type);
        mx_printstr(mx_get_rwx_str(files[i]->mode));
        mx_printstr(" ");
        mx_printstr(" ");
        mx_print_format_str(mx_itoa((int)files[i]->nlink), 'r', ' ', max_nlink_len);
        mx_printstr(" ");
        mx_printstr(files[i]->uid_name);
        mx_printstr("  ");
        mx_printstr(files[i]->gid_name);
        mx_printstr("  ");
        mx_print_format_str(mx_itoa((int)files[i]->size), 'r', ' ', max_size_len);
        mx_printstr(" ");
        mx_printstr(time_str);
        mx_printstr(" ");
        mx_printstr(files[i]->print_name);
        mx_printstr("\n");
        // mx_strdel(&temp);
        // mx_strdel(&time_str);
    }
    opt = NULL;
}

#include "uls.h"

void mx_ls_print_big_t(t_ls **files, int file_n, char *opt) {
    int max_nlink_len = mx_untill_get_max_nlink(files);
    int max_size_len = mx_untill_get_max_size(files);
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
        time_str = mx_strndup(&temp[4], 20);
        mx_printchar(files[i]->type);
        mx_printstr(mx_ls_get_rwx_str(files[i]->mode));
        mx_printstr(" ");
        mx_printstr(" ");
        mx_until_print_format_str(mx_itoa((int)files[i]->nlink), 'r', ' ', max_nlink_len);
        mx_printstr(" ");
        mx_printstr(files[i]->uid_name);
        mx_printstr("  ");
        mx_printstr(files[i]->gid_name);
        mx_printstr("  ");
        mx_until_print_format_str(mx_itoa((int)files[i]->size), 'r', ' ', max_size_len);
        mx_printstr(" ");
        mx_printstr(time_str);
        mx_printstr(" ");
        mx_printstr(files[i]->print_name);
        mx_printstr("\n");
    }
    opt = NULL;
}

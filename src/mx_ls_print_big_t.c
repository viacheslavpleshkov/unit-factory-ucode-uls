#include "uls.h"

void mx_ls_print_big_t(t_main *main) {
    int max_nlink_len = mx_untill_get_max_nlink(main->files_struct_two);
    int max_size_len = mx_untill_get_max_size(main->files_struct_two);
    char *time_str = NULL;
    char *temp = NULL;
    long long int total = 0;
 
    mx_printstr("total ");  
    for (int i = 0; i < main->file_n; i++)
        total += main->files_struct_two[i]->blocks;
    mx_printstr(mx_itoa(total));
    mx_printchar('\n');

    for (int i = 0; i < main->file_n; i++) {
        temp = ctime(&main->files_struct_two[i]->mtime);
        time_str = mx_strndup(&temp[4], 20);
        mx_printchar(main->files_struct_two[i]->type);
        mx_printstr(mx_ls_get_rwx_str(main->files_struct_two[i]->mode));
        mx_printstr(" ");
        mx_printstr(" ");
        mx_until_print_format_str(mx_itoa((int)main->files_struct_two[i]->nlink), 'r', ' ', max_nlink_len);
        mx_printstr(" ");
        mx_printstr(main->files_struct_two[i]->uid_name);
        mx_printstr("  ");
        mx_printstr(main->files_struct_two[i]->gid_name);
        mx_printstr("  ");
        mx_until_print_format_str(mx_itoa((int)main->files_struct_two[i]->size), 'r', ' ', max_size_len);
        mx_printstr(" ");
        mx_printstr(time_str);
        mx_printstr(" ");
        mx_ls_print_colors(main->files_struct_two[i]->type, main->files_struct_two[i]->print_name, main->color);
        mx_printstr("\n");
    }
}

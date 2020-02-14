#include "uls.h"

static void print_total(t_ls **files, int file_n) {
    long long int total = 0;
    char *printtotal = NULL;

    if (*files != NULL) {
        mx_printstr("total ");
        for (int i = 0; i < file_n; i++)
            total += files[i]->blocks;
        printtotal = mx_itoa(total);
        mx_printstr(printtotal);
        mx_strdel(&printtotal);
        mx_printchar('\n');
    }
}

static void print_rwx(t_ls *files) {
    char *rwx_str = mx_ls_get_rwx_str(files->mode);
    mx_printstr(rwx_str);
    mx_strdel(&rwx_str);
}

static void print_size(t_ls *files, int max_size_len) {
    char *size = mx_itoa((int)files->size);
    mx_printstr("  ");
    mx_until_print_format_str(size, 'r', ' ', max_size_len);
    mx_printstr(" ");
    mx_strdel(&size);
}

static void print_link(t_ls *files, int max_nlink_len) {
    char *link= mx_itoa((int)files->nlink);
    mx_printstr(" ");
    mx_printstr(" ");
    mx_until_print_format_str(link, 'r', ' ', max_nlink_len);
    mx_printstr(" ");
    mx_strdel(&link);
}

void mx_ls_print_l(t_ls **files, t_main *main) {
    char *time_str = NULL;
    char *temp = NULL;
    bool st = mx_ls_check_flag(main->flags, 'T');
    int max_uid = mx_max_uid_str(files);
    int max_gid = mx_max_gid_str(files);
    bool chararter_files = mx_check_character_files(files);

    print_total(files, main->file_n);
    for (int i = 0; i < main->file_n; i++) {
        temp = ctime(&files[i]->mtime);
        time_str = (st) ? mx_strndup(&temp[4], 20) : mx_strndup(&temp[4], 12);
        mx_printchar(files[i]->type);
        print_rwx(files[i]);
        print_link(files[i], mx_untill_get_max_nlink(files));
        mx_until_print_format_str(files[i]->uid_name, 'l', ' ', max_uid);
        mx_printstr("  ");
        mx_until_print_format_str(files[i]->gid_name, 'l', ' ', max_gid);
        if (files[i]->type != 'c' || files[i]->type == 'b') {
            if (!chararter_files)
                print_size(files[i], mx_untill_get_max_size(files));
            else
                print_size(files[i], 8 + mx_untill_get_max_size(files));
        }
        else 
            mx_ls_major_minor(files[i]);
        mx_printstr(time_str);
        mx_printstr(" ");
        mx_ls_print_color(files[i], main->color);
        if (files[i]->type == 'l')
            mx_ls_print_link_name(files[i]->name);
        mx_printstr("\n");
        mx_strdel(&time_str); 
    }
}

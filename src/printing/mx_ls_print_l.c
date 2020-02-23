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

static void print_size(t_ls *files, int max_size_len) {
    char *size = mx_itoa((int)files->size);
    mx_printstr("  ");
    mx_until_print_format_str(size, 'r', ' ', max_size_len);
    mx_printstr(" ");
    mx_strdel(&size);
}

static void print_link(t_ls *files, int max_nlink_len) {
    char *link= mx_itoa((int)files->nlink);
    mx_until_print_format_str(link, 'r', ' ', max_nlink_len);
    mx_printstr(" ");
    mx_strdel(&link);
}

static void print_l2(t_ls *file, t_ls_print_l *print_struct) {
    mx_printchar(file->type);
    mx_ls_print_rwx(file);
    if (mx_ls_get_xattr(file->name))
        mx_printstr("@ ");
    else if (file->acl_inf)
        mx_printstr("+ ");
    else
        mx_printstr("  ");
    print_link(file, print_struct->max_link);
    mx_until_print_format_str(file->uid_name, 'l', ' ', print_struct->max_uid);
    mx_printstr("  ");
    mx_until_print_format_str(file->gid_name, 'l', ' ', print_struct->max_gid);
    if (file->type != 'c' || file->type == 'b') {
        if (!print_struct->chararter_files)
            print_size(file, print_struct->max_size);
        else
            print_size(file, 8 + print_struct->max_size);
    }
    else 
        mx_until_major_minor(file);
}

void mx_ls_print_l(t_ls **files, t_main *main) {
    t_ls_print_l *print_struct = mx_ls_create_struct_print_l(files, main);
    char *time_str = NULL;
    char *temp = NULL;
    
    if (print_struct->check_dir)
        print_total(files, main->file_n);
    for (int i = 0; i < main->file_n; i++) {
        print_l2(files[i], print_struct);
        temp = ctime(&files[i]->mtime);
        time_str = mx_ls_get_time_str(files[i], print_struct);
        mx_printstr(time_str);
        mx_printstr(" ");
        mx_ls_print_color(files[i], main->color);
        if (files[i]->type == 'l')
            mx_ls_print_link_name(files[i]->name);
        mx_printstr("\n");
        mx_strdel(&time_str);
    }
}

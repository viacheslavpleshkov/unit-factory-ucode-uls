#include "uls.h"

t_ls_print_l *mx_ls_create_struct_print_l(t_ls **files, t_main *main) {
    t_ls_print_l *res = malloc(sizeof(t_ls_print_l));

    res->st = mx_until_check_flag(main->flags, 'T');
    res->max_uid = mx_until_max_uid_str(files);
    res->max_gid = mx_until_max_gid_str(files);
    res->chararter_files = mx_ls_check_character_files(files);
    res->max_size = mx_until_get_max_size(files);
    res->cur_time = time(NULL);
    res->max_link = mx_until_get_max_nlink(files);
    res->check_dir = false;
    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' 
            || mx_strcmp(files[i]->name, files[i]->print_name)) {
                res->check_dir = true;
                break;
        }
    return res; 
}

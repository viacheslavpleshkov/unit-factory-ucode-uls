#include "uls.h"

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}

void mx_ls_loop(char **files_name, t_main *main) {
    main->file_n = mx_until_get_size_arr(files_name);
    main->files_struct_two = mx_ls_create_struct_arr(main->file_n);

    for (int i = 0; files_name[i]; i++)
        main->files_struct_two[i] = mx_get_lstat(files_name[i]); //заполнение массива структурами

    //здесь нужно вставить функцию сортировки
    mx_ls_sort(main->files_struct_two, main->flags);
    mx_ls_print(main); //печать файлов
    

    for (int i = 0; main->files_struct_two[i]; i++)
        if (main->files_struct_two[i]->type == 'd' && mx_ls_check_flag(main->flags, 'R')) {//если файл - директория и есть флаг R
            if (mx_ls_check_flag(main->flags, 'a') && !check_symbol(main->files_struct_two[i]->print_name)) //проверка на . ..
                continue;
            mx_printstr("\n");
            mx_printstr(main->files_struct_two[i]->name); //печатает имя директории
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(main->files_struct_two[i]->name, mx_ls_get_hidden(main->flags)), main); // печатает содержимое директории
        }
}

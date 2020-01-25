#include "uls.h"

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}

void mx_ls_loop(char **files_name, char *flags) {
    int file_n = mx_until_get_size_arr(files_name);
    t_ls **files = mx_ls_create_struct_arr(file_n); //массив структур файлов

    for (int i = 0; files_name[i]; i++)
        files[i] = mx_get_lstat(files_name[i]); //заполнение массива структурами

    //здесь нужно вставить функцию сортировки
    mx_ls_sort(files, flags);
    mx_ls_print(files, file_n, flags); //печать файлов
    

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' && mx_ls_check_flag(flags, 'R')) {//если файл - директория и есть флаг R
            if (mx_ls_check_flag(flags, 'a') && !check_symbol(files[i]->print_name)) //проверка на . ..
                continue;
            mx_printstr("\n");
            mx_printstr(files[i]->name); //печатает имя директории
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, mx_ls_get_hidden(flags)), flags); // печатает содержимое директории
        }
}

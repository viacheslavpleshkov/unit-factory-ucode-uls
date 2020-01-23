#include "uls.h"

static t_ls **create_struct_arr(int files_number) {
    t_ls **head = malloc(sizeof(t_ls *) * (files_number + 1));

    for (int i = 0; i < files_number; i++)
        head[i] = malloc(sizeof(t_ls));
    head[files_number] = NULL;
    return head;
}

static int get_hidden(char *flags) {
    if (mx_get_char_index(flags, 'a') >= 0)
        return LS_HIDDEN_a;
    else if (mx_get_char_index(flags, 'A') >= 0)
        return LS_HIDDEN_A;
    else
        return LS_HIDDEN_NOT;
}

static bool check_symbol(char *print_name) {
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}

void mx_ls_loop(char **files_name, char *flags) {
    int file_n = mx_until_get_size_arr(files_name);
    t_ls **files = create_struct_arr(file_n); //массив структур файлов

    for (int i = 0; files_name[i]; i++)
        files[i] = mx_get_lstat(files_name[i]); //заполнение массива структурами

    //здесь нужно вставить функцию сортировки
    mx_ls_sort_default(files);
    if (mx_get_char_index(flags, 'r') >= 0)
        mx_ls_sort_flag_r(files);
    if (mx_get_char_index(flags, 't') >= 0)
        mx_ls_sort_flag_t(files);
    if (mx_get_char_index(flags, 'u') >= 0)
        mx_ls_sort_flag_u(files);
    if (mx_get_char_index(flags, 'c') >= 0)
        mx_ls_sort_flag_c(files);
    if (mx_get_char_index(flags, 'S') >= 0)
        mx_ls_sort_flag_big_s(files);
    
    mx_ls_print(files, file_n, flags); //печать файлов

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' && mx_get_char_index(flags, 'R') >= 0) {//если файл - директория и есть флаг R
            if (mx_get_char_index(flags, 'a') >= 0 && !check_symbol(files[i]->print_name)) //проверка на . ..
                continue;
            mx_printstr("\n");
            mx_printstr(files[i]->name); //печатает имя директории
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, get_hidden(flags)), flags); // печатает содержимое директории
        }
}

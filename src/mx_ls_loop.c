#include "uls.h"

static t_ls **create_struct_arr(int files_number)
{
    t_ls **head = malloc(sizeof(t_ls *) * (files_number + 1));

    for (int i = 0; i < files_number; i++)
        head[i] = malloc(sizeof(t_ls));
    head[files_number] = NULL;
    return head;
}

static int get_hidden(char *flags)
{
    if (mx_get_char_index(flags, 'a') >= 0)
        return LS_HIDDEN_a;
    else if (mx_get_char_index(flags, 'A') >= 0)
        return LS_HIDDEN_A;
    else
        return LS_HIDDEN_NOT;
}

static bool check_symbol(char *print_name)
{
    if (!mx_strcmp(print_name, ".") || !mx_strcmp(print_name, ".."))
        return false;
    else
        return true;
}
//sort default
void sort_default(t_ls **arr)
{
    t_ls *temp;
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (strcmp(arr[i]->name, arr[j]->name) > 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//sort default
void sort_flag_t(t_ls **arr) {
    t_ls *temp;
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((arr[i]->mtime < arr[j]->mtime) && arr[i]->mtime != arr[j]->mtime) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } else {
                if (strcmp(arr[i]->name, arr[j]->name) > 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            
        }
    }
}
void sort_flag_u(t_ls **arr) {
    t_ls *temp;
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((arr[i]->atime < arr[j]->atime)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sort_flag_big_s(t_ls **arr) {
    t_ls *temp;
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((arr[i]->size < arr[j]->size)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//reverse
void mx_swap_t_ls(t_ls **s1, t_ls **s2)
{
    t_ls *temp = NULL;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void sort_flag_r(t_ls **arr)
{
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size / 2; i++)
    {
        mx_swap_t_ls(&arr[i], &arr[size - i - 1]);
    }
}

void sort_flag_c(t_ls **arr) {
    t_ls *temp;
    int size = mx_get_size_arr((char **)arr);

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j) {
            if ((arr[i]->ctime < arr[j]->ctime)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void mx_ls_loop(char **files_name, char *flags)
{
    int file_n = mx_get_size_arr(files_name);
    t_ls **files = create_struct_arr(file_n); //массив структур файлов

    for (int i = 0; files_name[i]; i++)
        files[i] = mx_get_lstat(files_name[i]); //заполнение массива структурами

    //здесь нужно вставить функцию сортировки
    sort_default(files);
    if (mx_get_char_index(flags, 'r') >= 0)
        sort_flag_r(files);
    if (mx_get_char_index(flags, 't') >= 0)
        sort_flag_t(files);
    if (mx_get_char_index(flags, 'u') >= 0)
        sort_flag_u(files);
    if (mx_get_char_index(flags, 'c') >= 0)
        sort_flag_c(files);
    if (mx_get_char_index(flags, 'S') >= 0)
        sort_flag_big_s(files);
    
    mx_ls_print(files, file_n, flags); //печать файлов

    for (int i = 0; files[i]; i++)
        if (files[i]->type == 'd' && mx_get_char_index(flags, 'R') >= 0)
        {                                                                                  //если файл - директория и есть флаг R
            if (mx_get_char_index(flags, 'a') >= 0 && !check_symbol(files[i]->print_name)) //проверка на . ..
                continue;
            mx_printstr("\n");
            mx_printstr(files[i]->name); //печатает имя директории
            mx_printstr(":\n");
            mx_ls_loop(mx_read_dir(files[i]->name, get_hidden(flags)), flags); // печатает содержимое директории
        }
}

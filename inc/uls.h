#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define LEN_TAB 8
#define GET_STAT 1
#define GET_LSTAT 2

#define HIDDEN_NOT 0
#define HIDDEN_a 1
#define HIDDEN_A 2

typedef struct s_file {
    char *name;              //полное имя файла, например ./src/main.c
    char *print_name;        //имя которое будет выведено на конслоль, например main.c
    char *acl_inf;           // нужно для флага l (дополнительная информация)
    char *color;             //цвет, для флага G
    char type;               //тип файла - - файл, d - директория, l - ссылка и т.д
    unsigned short int mode; //нужно для флага l, из него мы получаем права доступа и тип файла
    long long int size;      //размер в байтах
    unsigned int nlink;      //количество ссылок на файл, нужно для флага l
    char *uid_name;          //имя пользователя
    char *gid_name;          //имя группы
    int blksize;             //количество занимаемых блоков(в байтах)
    long long int blocks;    //количество занимаемых блоков (в блоках)
    long int atime;          //время последнего доступа
    long int mtime;          //время последнего изменения
    long int ctime;          //время последнего изменения прав доступа
} t_file;

int main(int argc, char **argv);
void mx_begin(char **files_name, char *opt);             //начало программы
char **mx_create_files_arr(char **argv, int argc);       //получение файлов из введенных пользователей параметров
char *mx_create_opt_str(char **argv, int argc);          // получение флагов из введенных пользователем параметров
int mx_files_in_dir(char *dir, int headen);              //возвращает к-ство файлов в директории
char *mx_get_acl_inf(const char *file);                  //получение acl информации, нужно для флага l
char *mx_get_gid_name(int st_gid);                       //получение имени группы
t_file *mx_get_lstat(const char *file);                  //получение структуры stat
char *mx_get_print_name(const char *file);               //получение имени для вывода на консоль
char *mx_get_rwx_str(unsigned short int file_mode);      //нужно для флага l
int mx_get_terminal_width();                             // получение ширины терминала
char mx_get_type(unsigned short int file_mode);          //получение типа файла(файл, директория, ссылка и т.д)
char *mx_get_uid_name(int st_uid);                       //получение имени пользователя
void mx_loop(char *direct, char **inp_files, char *opt); //пока не нужно
void mx_print_ls(t_file **files, int file_n, char *opt); //функция, которая получает файлы для печати и передает их нужной функции в зависимости от флагов
void mx_print_ls_C(char **files, int file_n, int max_len, int len_terminal);
void mx_print_ls_l(t_file **files, int file_n, char *opt);
void mx_print_lstat(t_file *file);         //эта функция мне нужна для тестов, потом ее нужно будет удалить
char **mx_read_dir(char *dir, int headen); //возвращает все файлы в этой директории

char **mx_until_create_char_arr(int number);
void mx_until_print_format_str(char *str, char location, char symbol, int size);
#endif

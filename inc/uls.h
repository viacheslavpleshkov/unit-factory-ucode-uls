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

#define LS_HIDDEN_NOT 0
#define LS_HIDDEN_a 1
#define LS_HIDDEN_A 2

#define LS_COLOR_RED        "\x1b[31m"
#define LS_COLOR_GREEN      "\x1b[32m"
#define LS_COLOR_BOLD_GREEN "\x1b[32;1m"
#define LS_COLOR_YELLOW     "\x1b[33m"
#define LS_COLOR_BLUE       "\x1b[34m"
#define LS_COLOR_MAGENTA    "\x1b[35m"
#define LS_COLOR_BOLD_CYAN  "\x1b[96;1m"
#define LS_COLOR_RESET      "\x1b[0m"

//Error
typedef enum e_error {
    INVLD_CMD_ARGS,
} t_error;

//Struct
typedef struct s_ls {
    char *name;              //full file name, example ./src/main.c
    char *print_name;        //short file name, example main.c
    char *acl_inf;           //needed for flag l (additional information)
    char type;               //file type
    unsigned short int mode; //needed for flag l, from it we get permissions and file type
    long long int size;      //size in bytes
    unsigned int nlink;      //number of file links needed for flag l
    char *uid_name;          //user name
    char *gid_name;          //group name
    int blksize;             //number of occupied blocks (in bytes)
    long long int blocks;    //number of occupied blocks (in blocks)
    long int atime;          //last access time
    long int mtime;          //last change time
    long int ctime;          //last change of access rights
} t_ls;

typedef struct s_main {
    char **files;
    char *flags;
    bool color;
} t_main;

//Official function
int main(int argc, char **argv);
void mx_ls(t_main *main);
void mx_ls_loop(char **files_name, char *flags, t_main *main);
int mx_files_in_dir(char *dir, int headen);
char *mx_ls_get_rwx_str(unsigned short int file_mode);
t_ls **mx_ls_create_struct_arr(int files_number);
int mx_ls_get_hidden(char *flags);
//Ls validation
bool mx_ls_check_flag(const char *flags, char flag);
//Ls parse 
char **mx_read_dir(char *dir, int headen);                          //возвращает все файлы в этой директории
char *mx_ls_get_uid_name(int st_uid);                               //получение имени пользователя
char **mx_create_param_arr(char **argv, int argc);                  //получение файлов из введенных пользователей параметров
char *mx_create_flags_str(char **argv, int argc);                   //получение флагов из введенных пользователем параметров
char *mx_ls_get_acl_inf(const char *file);                          //получение acl информации, нужно для флага l
char *mx_ls_get_gid_name(int st_gid);                               //получение имени группы
t_ls *mx_get_lstat(const char *file);                               //получение структуры stat
char *mx_ls_get_print_name(const char *file);                       //получение имени для вывода на консоль
int mx_get_terminal_width();                                        //получение ширины терминала
char mx_ls_get_type(unsigned short int file_mode);                  //получение типа файла(файл, директория, ссылка и т.д)
//Print function
void mx_ls_print(t_ls **files, int file_n, char *flags, bool color); //функция, которая получает файлы для печати и передает их нужной функции в зависимости от флагов
void mx_ls_print_big_c(char **files, int file_n, int max_len, int len_terminal);
void mx_ls_print_big_t(t_ls **files, int file_n, char *opt);
void mx_ls_print_l(t_ls **files, int file_n, char *opt, bool color);
//Sort function
void mx_ls_sort(t_ls **files, char *flags);
void mx_ls_sort_default(t_ls **arr);
void mx_ls_sort_flag_r(t_ls **arr);
void mx_ls_sort_flag_big_s(t_ls **arr);                        
void mx_ls_sort_flag_c(t_ls **arr);                         
void mx_ls_sort_flag_t(t_ls **arr);                             
void mx_ls_sort_flag_u(t_ls **arr);
//Until function
int mx_until_get_size_arr(char **str_arr);
char **mx_until_create_char_arr(int number);
void mx_until_print_format_str(char *str, char location, char symbol, int size);
int mx_until_get_len_number(unsigned long long int number);
int mx_untill_get_max_nlink(t_ls **files);
int mx_untill_get_max_size(t_ls **files);

#endif

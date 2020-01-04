#ifndef ULS_H
#define ULS_H

#include "libmx.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
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

typedef struct s_file {
    char *name;
    char *print_name;
    char *acl_inf;
    char *color;
    char type;
    unsigned short int file_mode;
    long long int size;
    unsigned int nlink;
    int file_uid;
    unsigned int file_gid;
    char *gid_name;
    int file_blksize;
    long int file_atime;
    long int file_mtime;
    long int file_ctime;
} t_file;

int main (int argc, char **argv);
char **mx_create_char_arr(int number);
void mx_print_format_str(char *str, char location, char symbol, int size);
char **mx_create_files_arr(char **argv, int argc); //создает двумерный массив с файлами, которые передаются при вызове приложения
char *mx_create_opt_str(char **argv, int argc); //создает строку параметров ls
int mx_files_in_dir(char *dir, bool headen); //возвращает количество файлов в каталоге
t_file *mx_get_lstat(char *file); //возвращает структуру t_file
int mx_get_terminal_width(); // получение ширины терминала
void mx_loop(char *direct, char **inp_files, char *opt); // потом объясню
void mx_print_ls(char **files, int file_n, int max_len, int len_terminal); //печатает ls -C
char **mx_read_dir(char *dir, bool headen); //возвращает количество файлов в директории

#endif


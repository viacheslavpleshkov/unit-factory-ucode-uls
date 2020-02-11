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

#define LS_VALID_STR "&func_name: illegal option -- &invalflag \nusage: &func_name  [-&val_flags]] [file ...]"
#define LS_VALID_FLAGS "ACGRSTaclmrstu1"
#define LS_CLEAR_STR "*-aA*+lh@eT*--rtucS*--1Cml"
#define LS_FUNC_NAME "uls"

typedef enum e_error {
    ERR_EACCES,
    ERR_DIR,
} t_error;

//Struct
typedef struct s_ls {
    char *name;              //full file name, example ./src/main.c
    char *print_name;        //short file name, example main.c
    char *acl_inf;           //needed for flag l (additional information)
    char type;               //file type
    char color;              //file color
    unsigned short int mode; //from it we get permissions and file type
    long long int size;      //size in bytes
    unsigned int nlink;      //number of file links needed for flag l
    char *uid_name;          //user name
    char *gid_name;          //group name
    int blksize;             //number of occupied blocks (in bytes)
    long long int blocks;    //number of occupied blocks (in blocks)
    long int atime;          //last access time
    long int mtime;          //last change time
    long int ctime;          //last change of access rights
    ino_t ino;               //file serial number
    int file_minor;
    int file_major;
} t_ls;

typedef struct s_main {
    char **files;
    t_ls **files_struct;
    char *flags;
    bool color;
    int str_size;
    int file_n;
    int terminal_width;
    bool out_in_terminal;
} t_main;

//Official function
int main(int argc, char **argv);
t_ls **mx_insort_lstat(char **main_files, t_main *main);
t_main *mx_create_main(int argc, char **argv);
void mx_ls(t_main *main);
void mx_ls_loop(char **files_name, t_main *main);
int mx_files_in_dir(char *dir, int headen);
char *mx_ls_get_rwx_str(unsigned short int file_mode);
t_ls **mx_ls_create_struct_arr(int files_number);
int mx_ls_get_hidden(char *flags);
ino_t mx_get_ino_dev_fd();
//Ls validation
void mx_ls_error(t_error err, char *s);
bool mx_ls_check_flag(const char *flags, char flag);
void mx_valid_flags(char *str, char *func_name, char *flags, char *valid_flags);
char *mx_clear_flags(char *flags, char *valid_str);
char *mx_validation_name(char *name);
//Ls parse 
char **mx_read_dir(char *dir, int headen);
char *mx_ls_get_uid_name(int st_uid);
char **mx_create_param_arr(char **argv, int argc);
char *mx_create_flags_str(char **argv, int argc);
char *mx_ls_get_acl_inf(const char *file);
char *mx_ls_get_gid_name(int st_gid);
t_ls *mx_get_lstat(const char *file);
char *mx_ls_get_print_name(const char *file);
int mx_get_terminal_width();
char mx_ls_get_type(unsigned short int file_mode);
char mx_ls_get_color(struct stat buf);
//Print function
void mx_ls_print(t_ls **files, t_main *main);
void mx_ls_print_big_c(t_ls **files, t_main *main);
void mx_ls_print_l(t_ls **files, t_main *main);
void mx_ls_print_one(t_ls **files, t_main *main);
void mx_ls_print_m(t_ls **files, t_main *main);
void mx_ls_print_link_name(const char *file);
void mx_ls_print_color(t_ls *ls, bool status);
//Sort function
void mx_ls_sort(t_ls **files, char *flags);
void mx_ls_sort_default(t_ls **arr);
void mx_ls_sort_flag_r(t_ls **arr);
void mx_ls_sort_flag_big_s(t_ls **arr);                        
void mx_ls_sort_flag_c(t_ls **arr);                         
void mx_ls_sort_flag_t(t_ls **arr);                             
void mx_ls_sort_flag_u(t_ls **arr);
//Until function
void mx_untill_del_tls(t_ls ***arr);
int mx_until_get_size_arr(char **str_arr);
char **mx_until_create_char_arr(int number);
void mx_until_print_format_str(char *str, char location, char symbol, int size);
void mx_until_print_format_l(t_ls *file, t_main *main, int size);
int mx_until_get_len_number(unsigned long long int number);
int mx_untill_get_max_nlink(t_ls **files);
int mx_untill_get_max_size(t_ls **files);
#endif

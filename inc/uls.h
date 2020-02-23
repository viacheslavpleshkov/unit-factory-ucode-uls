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

#define LS_VALID_STR_ONE "&func_name: illegal option -- &invalflag \n"
#define LS_VALID_STR_TWO "usage: &func_name  [-&val_flags]] [file ...]"
#define LS_VALID_FLAGS "ACGRSTaclmrtu1"
#define LS_CLEAR_STR "*-aA*+lh@eT*--rtucS*--1Cml"
#define LS_FUNC_NAME "uls"

#define LS_HALF_YEAR 15552000

typedef enum e_error {
    ERR_EACCES,
    ERR_DIR,
}            t_error;

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
}              t_ls;

typedef struct s_ls_print_l {
    bool st;
    int max_uid;
    int max_gid;
    bool chararter_files;
    int max_size;
    time_t cur_time;
    bool check_dir;
    int max_link;
}              t_ls_print_l;

typedef struct s_main {
    char **files;
    t_ls **files_struct;
    char *flags;
    bool color;
    int str_size;
    int file_n;
    int terminal_width;
    bool out_in_terminal;
}              t_main;

//Official function
int main(int argc, char **argv);
void mx_ls(t_main *main);
void mx_ls_loop(char **files_name, t_main *main, bool prin);
//Creating function
char *mx_ls_create_flags_str(char **argv, int argc);
t_main *mx_ls_create_main(int argc, char **argv);
char **mx_ls_create_param_arr(char **argv, int argc);
t_ls **mx_ls_create_struct_arr(int files_number);
t_ls_print_l *mx_ls_create_struct_print_l(t_ls **files, t_main *main);
//Inserts function
t_ls **mx_ls_insort_lstat(char **main_files, t_main *main);
//Validation function
void mx_ls_error(t_error err, char *s);
void mx_ls_valid_flags(char *str, char *f_name, char *flags, char *v_flags);
char *mx_ls_clear_flags(char *flags, char *valid_str);
char *mx_ls_valid_name(char *name);
bool mx_ls_check_character_files(t_ls **files);
//Parse function
ino_t mx_ls_get_ino_dev_fd(void);
t_ls *mx_ls_get_lstat(const char *file);
int mx_ls_get_terminal_width(void);
char *mx_ls_get_time_str(t_ls *file, t_ls_print_l *print_struct);
char *mx_ls_get_acl_inf(const char *file);
char mx_ls_get_color(struct stat buf);
char *mx_ls_get_gid_name(int st_gid);
int mx_ls_get_hidden(char *flags);
char *mx_ls_get_print_name(const char *file);
char *mx_ls_get_rwx_str(unsigned short int file_mode);
char mx_ls_get_type(unsigned short int file_mode);
char *mx_ls_get_uid_name(int st_uid);
int mx_ls_get_xattr(char *file);
char **mx_ls_read_dir(char *dir, int headen);
//Print function
void mx_ls_print_big_c(t_ls **files, t_main *main);
void mx_ls_print_color(t_ls *ls, bool status);
void mx_ls_print_l(t_ls **files, t_main *main);
void mx_ls_print_link_name(const char *file);
void mx_ls_print_m(t_ls **files, t_main *main);
void mx_ls_print_one(t_ls **files, t_main *main);
void mx_ls_print_rwx(t_ls *files);
void mx_ls_print(t_ls **files, t_main *main);
//Sort function
void mx_ls_sort(t_ls **files, char *flags, int size);
void mx_ls_sort_default(t_ls **arr, int size);
void mx_ls_sort_flag_r(t_ls **arr, int size);
void mx_ls_sort_flag_big_s(t_ls **arr, int size);                        
void mx_ls_sort_flag_c(t_ls **arr, int size);                         
void mx_ls_sort_flag_t(t_ls **arr, int size);                             
void mx_ls_sort_flag_u(t_ls **arr, int size);
//Until function
void mx_until_major_minor(t_ls *files);
int mx_until_max_uid_str(t_ls **files);
int mx_until_max_gid_str(t_ls **files);
bool mx_until_check_flag(const char *flags, char flag);
char **mx_until_create_char_arr(int number);
int mx_until_get_len_number(unsigned long long int number);
int mx_until_get_size_arr(char **str_arr);
void mx_until_print_format_str(char *str, char local, char symbol, int size);
void mx_until_print_format_l(t_ls *file, t_main *main, int size);
void mx_until_del_tls(t_ls ***arr);
int mx_until_files_in_dir(char *dir, int headen);
int mx_until_get_max_nlink(t_ls **files);
int mx_until_get_max_size(t_ls **files);
#endif

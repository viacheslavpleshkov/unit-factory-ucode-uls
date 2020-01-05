#ifndef uls_h
#define uls_h

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>#ifndef uls_h
#define uls_h

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
#include <#ifndef uls_h
#define uls_h

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

#include "libmx.h"

#define LEN_TAB 8
#define GET_STAT 1
#define GET_LSTAT 2

#define HIDDEN_NOT 0
#define HIDDEN_a 1
#define HIDDEN_A 2

typedef struct s_file {
char *name;
char *print_name;
char *acl_inf;
char *color;
char type;
unsigned short int mode;
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <#ifndef uls_h
#define uls_h

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
    
#define LEN_TAB 8
#define GET_STAT 1
#define GET_LSTAT 2

#define HIDDEN_NOT 0
#define HIDDEN_a 1
#define HIDDEN_A 2

typedef struct s_file {
char *name;
char *print_name;
char *acl_inf;
char *color;
char type;
unsigned short int mode;
long long int size;
unsigned int nlink;
char *uid_name;
char *gid_name;
int blksize;
long long int blocks;
long int atime;
long int mtime;
long int ctime;
} t_file;

int main (int argc, char **argv);
void mx_begin(char **files_name, char *opt);
char **mx_create_files_arr(char **argv, int argc);
char *mx_create_opt_str(char **argv, int argc);
int mx_files_in_dir(chstdio.h>
    
#define LEN_TAB 8
#define GET_STAT 1
#define GET_LSTAT 2

#define HIDDEN_NOT 0
#define HIDDEN_a 1
#define HIDDEN_A 2

typedef struct s_file {
char *name;
char *print_name;
char *acl_inf;
char *color;
char type;
unsigned short int mode;
long long int size;
unsigned int nlink;
char *uid_name;
char *gid_name;
int blksize;
long long int blocks;
long int atime;
long int mtime;
long int ctime;
} t_file;

int main (int argc, char **argv);
void mx_begin(char **files_name, char *opt);
char **mx_create_files_arr(char **argv, int argc);
char *mx_create_opt_str(char **argv, int argc);
int mx_files_in_dir(char *dir, int headen);
char *mx_get_acl_inf(const char *file);
char *mx_get_gid_name(int st_gid);
t_file *mx_get_lstat(const char *file);
char *mx_get_print_name(const char *file);
char *mx_get_rwx_str(unsigned short int file_mode);
int mx_get_terminal_width();
char mx_get_type(unsigned short int file_mode);
char *mx_get_uid_name(int st_uid);
void mx_loop(char *direct, char **inp_files, char *opt);
void mx_print_ls(t_file **files, int file_n, char *opt);
void mx_print_ls_C(char **files, int file_n, int max_len, int len_terminal);
void mx_print_ls_l(t_file **files, int file_n, char *opt);
void mx_print_lstat(t_file *file);
char **mx_read_dir(char *dir, int headen);

#endif

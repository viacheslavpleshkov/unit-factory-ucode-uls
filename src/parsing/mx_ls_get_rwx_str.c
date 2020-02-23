#include "uls.h"

char *mx_ls_get_rwx_str(unsigned short int file_mode) {
    char *result = mx_strdup("---------");

    for (int i = 0; i < 9; i++) {
        if ((i == 0) && (S_IRUSR == (S_IRUSR & file_mode)))
            result[0] = 'r';
        if ((i == 1) && (S_IWUSR == (S_IWUSR & file_mode)))
            result[1] = 'w'; 
        if ((i == 2) && S_IXUSR == (S_IXUSR & file_mode)) 
            result[2] = 'x'; 
        if ((i == 3) && S_IRGRP == (S_IRGRP & file_mode)) 
            result[3] = 'r'; 
        if ((i == 4) && S_IWGRP == (S_IWGRP & file_mode)) 
            result[4] = 'w'; 
        if ((i == 5) && S_IXGRP == (S_IXGRP & file_mode)) 
            result[5] = 'x'; 
        if ((i == 6) && S_IROTH == (S_IROTH & file_mode)) 
            result[6] = 'r'; 
        if ((i == 7) && S_IWOTH == (S_IWOTH & file_mode)) 
            result[7] = 'w'; 
        if ((i == 8) && S_IXOTH == (S_IXOTH & file_mode)) 
            result[8] = 'x'; 
    }
    return result;
}

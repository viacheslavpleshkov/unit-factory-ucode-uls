#include "uls.h"

char *mx_get_rwx_str(unsigned short int file_mode) {
    char *result = mx_strdup("---------");

    for (int i = 0; i < 9; i++)
        switch (i) {
            case 0: if (S_IRUSR == (S_IRUSR & file_mode)) result[0] = 'r'; break;
            case 1: if (S_IWUSR == (S_IWUSR & file_mode)) result[1] = 'w'; break;
            case 2: if (S_IXUSR == (S_IXUSR & file_mode)) result[2] = 'x'; break;
            case 3: if (S_IRGRP == (S_IRGRP & file_mode)) result[3] = 'r'; break;
            case 4: if (S_IWGRP == (S_IWGRP & file_mode)) result[4] = 'w'; break;
            case 5: if (S_IXGRP == (S_IXGRP & file_mode)) result[5] = 'x'; break;
            case 6: if (S_IROTH == (S_IROTH & file_mode)) result[6] = 'r'; break;
            case 7: if (S_IWOTH == (S_IWOTH & file_mode)) result[7] = 'w'; break;
            case 8: if (S_IXOTH == (S_IXOTH & file_mode)) result[8] = 'x'; break;
        }
    return result;
}

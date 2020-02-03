#include "libmx.h"

static int len_file(const char *file) {
    int fd = open(file, O_RDONLY);
    char buf;
    int len = 0; 

    if (fd != -1) {
        while(read(fd, &buf, 1)) {
            if (!buf)
                return 0;
            len++;
        }
    }
    else 
        return 0;
    close(fd);
    return len;   
}

char *mx_file_to_str(const char *file) {
    int len = 0;
    int fd = 0;
    char *str = NULL;

    len = len_file(file); 
    if (len == 0) 
        return NULL;
    str = mx_strnew(len);
    fd = open(file, O_RDONLY);
    if (fd != -1) 
        read(fd, str, len);
    else 
        return NULL;
    close(fd);
    return str;
}

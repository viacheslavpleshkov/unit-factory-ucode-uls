#include "uls.h"

int mx_files_in_dir(char *dir, bool headen) {
    DIR *folder = opendir(dir);
    struct dirent *temp = NULL;
    int files = 0;

    if (!folder)
        return -1;
    temp = readdir(folder);
    while (temp) {
        if (headen || temp->d_name[0] != '.')
            files++;
        temp = readdir(folder);
    }
    closedir(folder);
    return files;
}

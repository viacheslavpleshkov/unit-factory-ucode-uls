#include "uls.h"

int mx_until_files_in_dir(char *dir, int headen) {
    DIR *folder = opendir(dir);
    struct dirent *temp = NULL;
    int files = 0;

    if (!folder)
        return -1;
    temp = readdir(folder);
    while (temp) {
        if (headen == LS_HIDDEN_NOT && temp->d_name[0] == '.') 
            files--;
        else if (headen == LS_HIDDEN_A && (!mx_strcmp(temp->d_name, ".") 
            || !mx_strcmp(temp->d_name, "..")))
                files--;
        files++;
        temp = readdir(folder);
    }
    closedir(folder);
    return files;
}

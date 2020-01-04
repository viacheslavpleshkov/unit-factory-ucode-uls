#include "uls.h"

char **mx_read_dir(char *dir, bool headen) {
    DIR *folder = opendir(dir);
    struct dirent *temp = NULL;
    int files = mx_files_in_dir(dir, headen);
    char **result = NULL;

    if (files < 0)
        return NULL;
    temp = readdir(folder);
    result = (char**)malloc(sizeof(char*) * (files + 1));

    for (int i = 0; i < files; i++) {
        if (headen || temp->d_name[0] != '.')
            result[i] = mx_strdup(temp->d_name);
        else
            i--;
        temp = readdir(folder);
    }
    result[files] = NULL;
    closedir(folder);
    return result;
}

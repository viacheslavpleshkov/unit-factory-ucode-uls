#include "uls.h"

static bool get_result(char *d_name, int headen, int *i) {
    if (headen == LS_HIDDEN_NOT && d_name[0] == '.')
        *i -= 1;
    else if (headen == LS_HIDDEN_A && (!mx_strcmp(d_name, ".")
             || !mx_strcmp(d_name, "..")))
        *i -=1;
    else
        return true;
    return false;
}

char **mx_ls_read_dir(char *dir, int headen) {
    DIR *folder = opendir(dir);
    struct dirent *temp = NULL;
    int files = mx_until_files_in_dir(dir, headen);
    char **result = NULL;

    if (!folder) 
        return NULL;
    if (files < 0)
        return NULL;
    temp = readdir(folder);
    result = (char**)malloc(sizeof(char*) * (files + 1));
    for (int i = 0; i < files; i++) {
        if (get_result(temp->d_name, headen, &i)) {
            char *mem = mx_strjoin(dir, "/");
            result[i] = mx_strjoin(mem, temp->d_name);
            mx_strdel(&mem);
        }
        temp = readdir(folder);
    }
    result[files] = NULL;
    closedir(folder);
    return result;
}

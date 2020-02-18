#include "uls.h"

static bool check_link_dir(char *file) {
    struct stat buf;
    struct stat lbuf;
    int res = 0;

    res = stat(file, &buf);
    lstat(file, &lbuf);
    
    if (res == -1)
        mx_ls_error(ERR_DIR, file);
    if ((buf.st_mode & S_IFMT) == S_IFDIR 
        && (lbuf.st_mode & S_IFMT) == S_IFLNK)
        return true;
    return false;
}

static t_ls *print_dir_name(t_ls *file, t_main *main) {
    struct stat buf;
    t_ls *result = NULL;
    int buf_size = 0;
    char *link = NULL;
    
    if (!file)
        return NULL;
    stat(file->name, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR && file->type == 'l'
        && mx_get_char_index(main->flags, 'l') < 0) {
            buf_size = buf.st_size + 1;
            link = malloc(buf_size);
            readlink(file->name, link, buf_size);
            result = mx_ls_get_lstat(link);
            result->print_name = mx_strdup(file->name);
            result->type = 'd';
    }
    else {
        mx_printstr(file->name);
        mx_printstr(":\n");
        return file;
    }
    return result;
}

void static print_dir(t_ls **files, t_main *main) {
    char **mem = NULL;
    ino_t dev_fd = mx_ls_get_ino_dev_fd();

    for (int i = 0; files[i]; i++) {
        if (files[i]->type == 'd' || files[i]->type == 'l') {
            if (files[i]->ino == dev_fd)
                continue;
            if (!(i == 0 && files[i + 1] == NULL))
                files[i] = print_dir_name(files[i], main);
            mem = mx_ls_read_dir(files[i]->name, mx_ls_get_hidden(main->flags));
            if (!mem) {
                mx_ls_error(ERR_EACCES, files[i]->print_name);
                continue;
            }
            if (files[i]->type != 'd')
                continue;
            mx_ls_loop(mem, main, false);
            if (files[i + 1] != NULL)
                mx_printchar('\n');
            mx_del_strarr(&mem);
        }
    }
}

void static print_files_without_dir(t_main *main) {
    char **files_without_dir = mx_until_create_char_arr(main->str_size);
    int k = 0;

    for (int i = 0; main->files_struct[i]; i++) {
        files_without_dir[k] = mx_strdup(main->files_struct[i]->name);
        if (main->files_struct[i]->type == 'd')
            mx_strdel(&files_without_dir[k]);
        else if (check_link_dir(main->files_struct[i]->name) 
            && mx_get_char_index(main->flags, 'l') < 0)
                mx_strdel(&files_without_dir[k]);
        else if (check_link_dir(main->files_struct[i]->name) 
            && mx_get_char_index(main->flags, 'l') >= 0)
                k++;
        else if (main->files_struct[i]->type != 'd')
            k++;
    }
    mx_ls_loop(files_without_dir, main, true);
    print_dir(main->files_struct, main);
    mx_del_strarr(&files_without_dir);
}

void mx_ls(t_main *main) {
    char **memory = NULL;

    if (!main->str_size) {
        memory = mx_ls_read_dir(".", mx_ls_get_hidden(main->flags));
        mx_ls_loop(memory, main, false);
        mx_del_strarr(&memory);
    }
    main->files_struct = mx_ls_insort_lstat(main->files, main);
    print_files_without_dir(main);
    mx_until_del_tls(&main->files_struct);
}

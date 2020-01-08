#include "uls.h"

void mx_ls(char **files_name, char *flags) {
	//char *new_flags = mx_clear_flags(char *flags);
	//char *new_files_name = mx_add_stars(char **files_name);

    mx_ls_loop(files_name, flags);
}

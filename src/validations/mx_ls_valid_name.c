#include "uls.h"

char *mx_ls_valid_name(char *name) {
    char *namerepleca = NULL;
    char *namereplecatwo = NULL;

    namerepleca = mx_replace_substr(name, "\r", "?");
    namereplecatwo = mx_replace_substr(namerepleca, "\n", "?");
    mx_strdel(&namerepleca);
    return namereplecatwo;
}

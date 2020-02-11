#include "uls.h"

char *mx_validation_name(char *name) {
    char *namerepleca = mx_replace_substr(name, "\r", "?");
    namerepleca = mx_replace_substr(namerepleca, "\n", "?");
    return namerepleca;
}

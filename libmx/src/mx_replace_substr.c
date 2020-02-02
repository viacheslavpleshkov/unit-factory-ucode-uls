#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *result = NULL;
    int k = 0;
    int i = 0;

    if (!str || !sub || !replace)
        return NULL;
    result = mx_strnew(mx_strlen(str) 
        + mx_count_substr(str, sub) * (mx_strlen(replace) - mx_strlen(sub)));
    while(str[i]) {
        while (mx_strncmp(&str[i], sub, mx_strlen(sub))) {
            result[k] = str[i];
            k++;
            i++;
        }
        i += mx_strlen(sub);
        for (int j = 0; j < mx_strlen(replace); j++, k++)
            result[k] = replace[j];
    }
    return result;
}

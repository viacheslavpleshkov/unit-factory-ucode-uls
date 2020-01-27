#include "libmx.h"

static int check_end_str(const char *str, int i, int sub_len) {
    for (int j = i; j < i + sub_len; j++)
        if (!str[j])
            return -1;
    return i + sub_len;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *result = NULL;
    int k = 0;
    int i = 0;

    if (!str || !sub || !replace)
        return NULL;
    result = mx_strnew(mx_strlen(str)
        + mx_count_substr(str, sub) * (mx_strlen(replace) - mx_strlen(sub)));
    while(str[i]) {
        while (str[i] && mx_strncmp(&str[i], sub, mx_strlen(sub))) {
            result[k] = str[i];
            k++;
            i++;
        }
        i = check_end_str(str, i, mx_strlen(sub));
        if (i >= 0)
            for (int j = 0; j < mx_strlen(replace); j++, k++)
                result[k] = replace[j];
    }
    return result;
}

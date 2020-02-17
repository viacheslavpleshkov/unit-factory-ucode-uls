#include "uls.h"

static char *pop_char(char *str, char c) {
    char *result = NULL;
    int k = 0;

    if (str) {
        result = mx_strnew(mx_strlen(str) - mx_count_char(str, c));
        for (int i = 0; str[i]; i++) {
            if (str[i] != c) {
                result[k] = str[i];
                k++;
            }
        }
    }
    return result;
}

static void swap_value(char **tmp, char **result, char v_char) {
    *tmp = mx_strdup(*result);
    mx_strdel(result);
    *result = pop_char(*tmp, v_char);
    mx_strdel(tmp);
}

static char *del_without_last(char *v_str, char *flags) {
    char *result = NULL;
    char *tmp = NULL;
    char last;

    for (int i = 0; flags[i]; i++)
        if (mx_get_char_index(v_str, flags[i]) >= 0)
            last = flags[i];
    result = mx_strdup(flags);
    for (int i = 0; v_str[i]; i++)
        if (v_str[i] != last) {
            tmp = mx_strdup(result);
            mx_strdel(&result);
            result = pop_char(tmp, v_str[i]);
            mx_strdel(&tmp);
        }
    return result;
}

static char *del_char(char *flags, char *v_str) {
    char *result = NULL;
    char *tmp = NULL;
    int len = mx_strlen(v_str);

    if (!flags || !v_str)
        return NULL;
    result = mx_strdup(flags);
    if (v_str[0] == '-' && v_str[1] == '-') {
        mx_strdel(&result);
        return del_without_last(&v_str[2], flags);
    }
    else if (v_str[0] == '-' && v_str[1] != '-' 
        && mx_get_char_index(flags, v_str[1]) >= 0)
            for (int i = 2; i < len; i++)
                swap_value(&tmp, &result, v_str[i]);
    else if (v_str[0] == '+' && v_str[1] != '-' 
        && mx_get_char_index(flags, v_str[1]) < 0)
            for (int i = 2; i < len; i++)
                swap_value(&tmp, &result, v_str[i]);
    return result;
}

char *mx_ls_clear_flags(char *flags, char *valid_str) {
    char **v_arr = mx_strsplit(valid_str, '*');
    char *result = mx_strdup(flags);
    char *tmp = NULL;

    for (int i = 0; v_arr[i]; i++) {
        tmp = mx_strdup(result);
        mx_strdel(&result);
        result = del_char(tmp, v_arr[i]);
        mx_strdel(&tmp);
    }
    mx_del_strarr(&v_arr);
    return result;
}

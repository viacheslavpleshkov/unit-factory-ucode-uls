#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *result = NULL;
    int len_s1 = 0;
    int len_s2 = 0;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);
    result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    len_s1 = mx_strlen(s1);
    len_s2 = mx_strlen(s2);
    for (int i = 0; i < len_s1; i++, s1++) 
        result[i] = *s1;
    for (int i = len_s1; i < len_s1 + len_s2; i++, s2++)
        result[i] = *s2;
    return result;
}

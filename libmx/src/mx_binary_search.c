#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    (*count) = 0;
    int left = -1;
    int right = size;
    long mid = 0;

    while (left < right) {
        if (*count >= size)
            break;
        (*count) += 1;
        mid = (left + right) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return (int) mid;
        else if (mx_strcmp(arr[mid], s) < 0)
            left = mid;
        else
            right = mid;
    }
    (*count) = 0;
    return -1;
}

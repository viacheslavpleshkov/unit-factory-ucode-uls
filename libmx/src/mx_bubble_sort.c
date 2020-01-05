#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *temp;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) 
            if (mx_strcmp(arr[j], arr[j - 1]) < 0) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                count++;
            }
    }
    return count;
}

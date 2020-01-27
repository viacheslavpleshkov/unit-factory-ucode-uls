#include "libmx.h"

static void *get_data(t_list *list, int index) {
    t_list *temp = list;

    for (int i = 0; i < index; i++)
        temp = temp -> next;

    return temp -> data;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    int min_elem = 0;
    int size = mx_list_size(list);

    if (size <= 1)
        return list;

    for (int i = 0; i < size; i++) {
        min_elem = i;
        for (int j = i; j < size; j++)
            if (cmp(get_data(list, min_elem), get_data(list, j)))
                min_elem = j;
        if (min_elem > i)
            mx_swap_str(get_data(list, i), get_data(list, min_elem));
    }

    return list;
}

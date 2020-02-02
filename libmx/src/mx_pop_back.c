#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *last = *head;
    t_list *present = *head;

    if (*head == NULL)
        return;

    if (present -> next == NULL) {
        free(*head);
        *head= NULL;
        return;
    }

    while (present -> next != NULL) {
        last = present;
        present = present -> next;
    }
    last -> next = NULL;
    free(present);
}

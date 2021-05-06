#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (*head == NULL || head == NULL)
        return;

    t_list *current = *head;

    if ((*head)->next == NULL) {
        free((*head)->data);
        (*head)->data = NULL;
        free(*head);
        *head = NULL;
    }
    else {
        while (current->next->next != NULL)
            current = current->next;
    free(current->next->data);
    current->next->data = NULL;
    free(current->next);
    current->next = NULL;
    }
}

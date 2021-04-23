#include <stdlib.h>

#include "LinkedList.h"

struct LinkedList* make_linked_list(void)
{
    return NULL;
}

void linked_list_append(struct LinkedList** head, const void* data)
{
    struct LinkedList *new_node, *temp;

    for (temp = *head; temp && temp->next; temp = temp->next)
        ;

    new_node = malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->next = NULL;

    if (temp) {
        temp->next = new_node;
    }
    else {
        *head = new_node;
    }
}

void destroy_linked_list(struct LinkedList* head)
{
    struct LinkedList* current = head;
    while (current) {
        struct LinkedList* to_free = current;
        current = current->next;
        free(to_free);
    }
}

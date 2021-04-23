#include <stdlib.h>
#include <string.h>

#include "LinkedMap.h"

struct LinkedMap* make_linked_map(void)
{
    return NULL;
}

void linked_map_put(struct LinkedMap** head, const char* name, const void* data)
{
    struct LinkedMap *new_node, *temp;

    for (temp = *head; temp && temp->next; temp = temp->next)
        ;

    new_node = malloc(sizeof(*new_node));
    new_node->name = name;
    new_node->data = data;
    new_node->next = NULL;

    if (temp) {
        temp->next = new_node;
    }
    else {
        *head = new_node;
    }
}

bool linked_map_contains(const struct LinkedMap* head, const char* name)
{
    for (const struct LinkedMap* node = head; node; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            return true;
        }
    }
    return false;
}

const void* linked_map_get(const struct LinkedMap* head, const char* name)
{
    for (const struct LinkedMap* node = head; node; node = node->next) {
        if (strcmp(node->name, name) == 0) {
            return node->data;
        }
    }
    return NULL;
}

const struct LinkedList* linked_map_values(const struct LinkedMap* head)
{
    struct LinkedList* list = make_linked_list();
    for (const struct LinkedMap* node = head; node; node = node->next) {
        linked_list_append(&list, node->data);
    }
    return list;
}

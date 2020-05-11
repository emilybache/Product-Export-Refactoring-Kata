#include <stdbool.h>

#include "LinkedList.h"

#ifndef LINKED_MAP
#define LINKED_MAP

struct LinkedMap {
    const char* name;
    const void* data;
    struct LinkedMap* next;
};

#endif

extern struct LinkedMap* make_linked_map(void);
extern void linked_map_put(struct LinkedMap** head, const char* name, const void* data);
extern const void* linked_map_remove(struct LinkedMap** head, const char* name);
extern bool linked_map_contains(const struct LinkedMap* head, const char* name);
extern const void* linked_map_get(const struct LinkedMap* head, const char* name);
extern const struct LinkedList* linked_map_values(const struct LinkedMap* map);

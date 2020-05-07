#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "LinkedMap.h"
#include "Product.h"

/*
 * Represents a physical Store where you can go and buy products and attend
 * events.
 */
struct Store {
    struct LinkedMap* items_in_stock; /* Map<char*, Product> */
    const char* name;
    const char* id;
};

struct Store* make_store(const char* name, const char* id, const struct LinkedList* products)
{
    void store_add_stocked_items(struct Store*, const struct LinkedList*);

    struct Store* this = (struct Store*)malloc(sizeof(struct Store));
    this->name = name;
    this->id = id;
    this->items_in_stock = make_linked_map();
    store_add_stocked_items(this, products);
    return this;
}

void store_add_stocked_items(struct Store* this, const struct LinkedList* items)
{
    for (const struct LinkedList* node = items; node; node = node->next) {
        const struct Product* item = (const struct Product*)node->data;
        const char* product_name = get_product_name(item);
        linked_map_put(&this->items_in_stock, product_name, item);
    }
}

void store_add_store_event(struct Store* this, const struct Product* store_event)
{
    const char* store_event_name = get_product_name(store_event);
    linked_map_put(&this->items_in_stock, store_event_name, store_event);
}

bool store_has_item(const struct Store* this, const struct Product* item)
{
    const char* product_name = get_product_name(item);
    return linked_map_contains(this->items_in_stock, product_name);
}

const struct Product* store_get_item(const struct Store* this, const char* name)
{
    return (const struct Product*)linked_map_get(this->items_in_stock, name);
}

const char* get_store_id(const struct Store* this)
{
    return this->id;
}

void save_store_to_database(const struct Store* this)
{
    (void)this; /* unused */
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}

const char* get_store_name(const struct Store* this)
{
    return this->name;
}

const struct LinkedList* get_store_stock(const struct Store* this)
{
    return linked_map_values(this->items_in_stock);
}

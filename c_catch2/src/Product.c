#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Price.h"

struct Product {
    const char* name;
    const char* id;
    int weight;
    const struct Price* price;
    void* location; /* struct Store* */
};

struct Product* make_product(const char* name, const char* id, int weight, const struct Price* price)
{
    struct Product* this = (struct Product*)malloc(sizeof(struct Product));
    this->name = name;
    this->id = id;
    this->weight = weight;
    this->price = price;
    this->location = NULL;
    return this;
}

void save_product_to_database(const struct Product* this)
{
    (void)this; /* unused */
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}

const char* get_product_name(const struct Product* this)
{
    return this->name;
}

const char* get_product_id(const struct Product* this)
{
    return this->id;
}

int get_product_weight(const struct Product* this)
{
    return this->weight;
}

const struct Price* get_product_price(const struct Product* this)
{
    return this->price;
}

bool is_product_event(const struct Product* this)
{
    return this->location != NULL;
}

void product_set_location(struct Product* this, void* location_store)
{
    this->location = location_store;
}

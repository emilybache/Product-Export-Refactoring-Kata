#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "Product.h"
#include "Store.h"

struct Order {
    const char* id;
    time_t date;
    struct LinkedList* products;
    struct Store* store;
};

struct Order* make_order(const char* id, time_t date, struct Store* store, const struct LinkedList* products)
{
    void add_order_products(struct Order*, const struct LinkedList*);

    struct Order* this = (struct Order*)malloc(sizeof(struct Order));
    this->id = id;
    this->date = date;
    this->store = store;
    this->products = make_linked_list();
    add_order_products(this, products);
    return this;
}

double order_total_dollars(const struct Order* this)
{
    double dollars = 0.0;
    for (struct LinkedList* node = this->products; node; node = node->next) {
        const struct Product* product = (const struct Product*)node->data;
        const struct Price* price = get_product_price(product);
        dollars += get_price_amount_in_currency(price, "USD");
    }
    return dollars;
}

void save_order_to_database(const struct Order* this)
{
    (void)this; /* unused */
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}

const char* get_order_id(const struct Order* this)
{
    return this->id;
}

const struct LinkedList* get_order_products(const struct Order* this)
{
    return this->products;
}

time_t get_order_date(const struct Order* this)
{
    return this->date;
}

void add_order_products(struct Order* this, const struct LinkedList* products)
{
    for (const struct LinkedList* node = products; node; node = node->next) {
        const struct Product* product = (const struct Product*)node->data;
        linked_list_append(&this->products, (void*)product);
    }
}

struct Store* get_order_store(const struct Order* this)
{
    return this->store;
}

#include <stdbool.h>
#include <stdlib.h>

#include "Price.h"
#include "Product.h"
#include "Store.h"

/**
 * Ticket to In-store event, eg. makeover, eyeshadow masterclass
 * or beauty product launch evening reception
 */

struct Product* make_store_event(const char* name,
                                 const char* id,
                                 struct Store* location,
                                 const struct Price* price)
{
    void store_event_set_location(struct Product*, struct Store*);

    struct Product* this = make_product(name, id, 0, price);
    store_event_set_location(this, location);
    return this;
}

void store_event_set_location(struct Product* this, struct Store* store)
{
    product_set_location(this, store);
    store_add_store_event(store, this);
}

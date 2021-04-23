#include "Price.h"
#include "Product.h"
#include "Store.h"

extern struct Product* make_store_event(const char* name,
                                        const char* id,
                                        struct Store* location,
                                        const struct Price* price);
extern void store_event_set_location(struct Product* this, struct Store* locationStore);

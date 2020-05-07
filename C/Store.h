#include <stdbool.h>

#include "LinkedList.h"
#include "Product.h"

struct Store;

extern struct Store* make_store(const char* name, const char* id, const struct LinkedList* products);
extern void store_add_stocked_items(struct Store* this, const struct LinkedList* products);
extern void store_add_store_event(struct Store* this, const struct Product* store_event);
extern bool store_has_item(const struct Store* this, const struct Product* item);
extern const struct Product* store_get_item(const struct Store* this, const char* name);
extern const char* get_store_id(const struct Store* this);
extern void save_store_to_database(const struct Store* this);
extern const char* get_store_name(const struct Store* this);
extern const struct LinkedList* get_store_stock(const struct Store* this);

#include <stdbool.h>

#include "LinkedList.h"
#include "Product.h"

struct Store;

extern struct Store* make_store(const char* name, const char* id, const struct LinkedList* products);
extern void store_add_stocked_items(struct Store*, const struct LinkedList* products);
extern void store_add_store_event(struct Store*, const struct Product* store_event);
extern bool store_has_item(const struct Store*, const struct Product* item);
extern const struct Product* store_get_item(const struct Store*, const char* name);
extern const char* get_store_id(const struct Store*);
extern void save_store_to_database(const struct Store*);
extern const char* get_store_name(const struct Store*);
extern const struct LinkedList* get_store_stock(const struct Store*);

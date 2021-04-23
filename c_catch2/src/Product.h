#include <stdbool.h>

#include "Price.h"

struct Product;

extern struct Product* make_product(const char* name, const char* id, int weight, const struct Price* price);
extern void save_product_to_database(const struct Product*);
extern const char* get_product_name(const struct Product*);
extern const char* get_product_id(const struct Product*);
extern int get_product_weight(const struct Product*);
extern const struct Price* get_product_price(const struct Product*);
extern bool is_product_event(const struct Product*);

extern void product_set_location(struct Product*, void* location_store);

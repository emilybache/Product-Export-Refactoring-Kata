#include "LinkedList.h"
#include "Store.h"

extern const char* xml_export_full(const struct LinkedList* orders);
extern const char* xml_export_tax_details(struct LinkedList* orders);
extern const char* xml_export_store(struct Store* store);
extern const char* xml_export_history(struct LinkedList* orders);

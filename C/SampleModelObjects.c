#include "LinkedList.h"
#include "Order.h"
#include "Price.h"
#include "Product.h"
#include "Store.h"
#include "StoreEvent.h"
#include "Util.h"

/*
 * Some sample product data that you could use in your tests.
 */
struct Product* CherryBloom;
struct Product* RosePetal;
struct Product* BlusherBrush;
struct Product* EyelashCurler;
struct Product* WildRose;
struct Product* CocoaButter;

struct Store* FlagshipStore;

/* Store events add themselves to the stocked items at their store */
struct Product* Masterclass;
struct Product* Makeover;

struct Order* RecentOrder;
struct Order* OldOrder;

void make_sample_model_objects(void)
{
    CherryBloom =
        make_product("Cherry Bloom", "LIPSTICK01", 30, make_price(14.99, "USD"));
    RosePetal =
        make_product("Rose Petal", "LIPSTICK02", 30, make_price(14.99, "USD"));
    BlusherBrush =
        make_product("Blusher Brush", "TOOL01", 50, make_price(24.99, "USD"));
    EyelashCurler =
        make_product("Eyelash curler", "TOOL01", 100, make_price(19.99, "USD"));
    WildRose =
        make_product("Wild Rose", "PURFUME01", 200, make_price(34.99, "USD"));
    CocoaButter =
        make_product("Cocoa Butter", "SKIN_CREAM01", 250, make_price(10.99, "USD"));

    struct LinkedList* store_products = make_linked_list();
    linked_list_append(&store_products, CherryBloom);
    FlagshipStore = make_store("Nordstan", "4189", store_products);
    destroy_linked_list(store_products);

    /* Store events add themselves to the stocked items at their store */
    Masterclass = make_store_event("Eyeshadow Masterclass", "EVENT01",
                                   FlagshipStore, make_price(119.99, "USD"));
    Makeover = make_store_event("Makeover", "EVENT02",
                                FlagshipStore, make_price(149.99, "USD"));

    struct LinkedList* order_products = make_linked_list();
    linked_list_append(&order_products, Makeover);
    RecentOrder = make_order("1234", from_iso_date("2018-09-01T00:00Z"),
                             FlagshipStore, order_products);
    destroy_linked_list(order_products);

    order_products = make_linked_list();
    linked_list_append(&order_products, CherryBloom);
    OldOrder = make_order("1235", from_iso_date("2017-09-01T00:00Z"),
                             FlagshipStore, order_products);
    destroy_linked_list(order_products);
}

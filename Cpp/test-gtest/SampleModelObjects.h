#ifndef SAMPLE_H
#define SAMPLE_H


#include <StoreEvent.h>
#include <Util.h>
#include "Order.h"
#include "Product.h"
#include "Store.h"

/*
 * Some sample product data that you could use in your tests.
 */
Product* CherryBloom;
Product* RosePetal;
Product* BlusherBrush;
Product* EyelashCurler;
Product* WildRose;
Product* CocoaButter;

Store* FlagshipStore;

/* Store events add themselves to the stocked items at their store */
Product* Masterclass;
Product* Makeover;

Order* RecentOrder;
Order* OldOrder;

void make_sample_model_objects()
{
    CherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99, "USD"));
    RosePetal =
            new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99, "USD"));
    BlusherBrush =
            new Product("Blusher Brush", "TOOL01", 50, new Price(24.99, "USD"));
    EyelashCurler =
            new Product("Eyelash curler", "TOOL01", 100, new Price(19.99, "USD"));
    WildRose =
            new Product("Wild Rose", "PURFUME01", 200, new Price(34.99, "USD"));
    CocoaButter =
            new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99, "USD"));

    std::vector<Product*> store_products;
    store_products.push_back(CherryBloom);
    FlagshipStore = new Store("Nordstan", "4189", store_products);

    /* Store events add themselves to the stocked items at their store */
    Masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01",
                                 FlagshipStore, new Price(119.99, "USD"));
    Makeover = new StoreEvent("Makeover", "EVENT02",
                              FlagshipStore, new Price(149.99, "USD"));

    std::vector<Product*> order_products;
    order_products.push_back(Makeover);
    RecentOrder = new Order("1234", from_iso_date("2018-09-01T00:00Z"),
                            FlagshipStore, order_products);

    std::vector<Product*> old_order_products;
    order_products.push_back(CherryBloom);
    OldOrder = new Order("1235", from_iso_date("2017-09-01T00:00Z"),
                         FlagshipStore, old_order_products);

}

#endif
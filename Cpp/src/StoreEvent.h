#ifndef STORE_EVENT_H
#define STORE_EVENT_H


#include <utility>

#include "Price.h"
#include "Product.h"
#include "Store.h"

class StoreEvent : public Product {
public:
    StoreEvent(std::string name, std::string id,
               Store *location, Price *price) : Product(std::move(name), std::move(id), 0, price) {
        product_set_location(location);
    }
    bool is_product_event() override;
    void product_set_location(Store* location);
private:
    Store *_location;
};

#endif
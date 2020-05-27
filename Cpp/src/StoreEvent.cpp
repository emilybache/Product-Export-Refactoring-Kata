
#include "Store.h"
#include "StoreEvent.h"

bool StoreEvent::is_product_event() {
    return true;
}

void StoreEvent::product_set_location(Store *location) {
    _location = location;
}

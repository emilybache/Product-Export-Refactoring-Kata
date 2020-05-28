

#include "Price.h"
#include "Product.h"


void Product::save_product_to_database()
{
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}

std::string Product::get_product_name() {
    return _name;
}

std::string Product::get_product_id() {
    return _id;
}

int Product::get_product_weight() {
    return _weight;
}

Price *Product::get_product_price() {
    return _price;
}

bool Product::is_product_event() {
    return false;
}


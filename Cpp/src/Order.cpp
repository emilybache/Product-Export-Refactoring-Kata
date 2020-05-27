
#include "Order.h"
#include "Product.h"



double Order::order_total_dollars()
{
    double dollars = 0.0;
    for (int i = 0; i < this->_products.size(); i++)
        dollars += _products[i]->get_product_price()->get_price_in_currency("USD");
    return dollars;
}

void Order::save_order_to_database()
{
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}

std::string Order::get_order_id() {
    return _id;
}

std::vector<Product *> Order::get_order_products() {
    return _products;
}

time_t Order::get_order_date() {
    return _date;
}

void Order::add_order_products(std::vector<Product *> products) {
    for (int i = 0; i < products.size(); ++i) {
        _products.push_back(products[i]);
    }
}




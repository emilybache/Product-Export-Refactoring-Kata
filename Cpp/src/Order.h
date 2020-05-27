#ifndef ORDER_H
#define ORDER_H


#include <utility>

#include "Product.h"
#include "Store.h"

class Order {
public:
    Order(std::string id, time_t date, Store *store, std::vector<Product *> products) : _id(std::move(id)), _date(date), _store(store), _products(products) {}

    double order_total_dollars();

    void save_order_to_database();

    std::string get_order_id();

    std::vector<Product *> get_order_products();

    time_t get_order_date();

    void add_order_products(std::vector<Product *> products);

    Store *get_order_store();

private:
    std::string _id;
    time_t _date;
    std::vector<Product *> _products;
    Store* _store;
};

#endif


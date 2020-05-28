#ifndef PRODUCT_H
#define PRODUCT_H


#include <utility>

#include "Price.h"

class Store;

class Product
{
    public:
    Product(std::string name, std::string id, int weight, Price* price) : _name(std::move(name)), _id(std::move(id)), _weight(weight), _price(price) {};
    void save_product_to_database();
    std::string get_product_name();
    std::string get_product_id();

    int get_product_weight();
    Price* get_product_price();
    virtual bool is_product_event();
private:
    std::string _name;
    std::string _id;
    int _weight;
    Price* _price;
    Store* _location;
};

#endif


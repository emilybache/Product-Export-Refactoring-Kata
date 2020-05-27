#ifndef STORE_H
#define STORE_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include "Product.h"

/*
 * Represents a physical Store where you can go and buy products and attend
 * events.
 */
class Store
{
    public:
    Store(std::string name, std::string id, const std::vector<Product*>& products) : _name(std::move(name)), _id(std::move(id)) {
        for (int i = 0; i < products.size(); ++i) {
            _items_in_stock[products[i]->get_product_name()] = products[i];
        }
    };

    void add_stocked_items(std::vector<Product*> products);
    void add_store_event(Product* store_event);
    Product* get_item(std::string name);
    std::string get_store_id();
    void save_store_to_database();
    std::string get_store_name();
    void add_product(Product *product);
    std::vector<Product*> get_store_stock();
private:
    std::string _name;
    std::string _id;
    std::map<std::string, Product*> _items_in_stock;
};

#endif
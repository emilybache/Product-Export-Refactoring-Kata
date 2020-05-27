
#include "Product.h"
#include "Store.h"


void Store::save_store_to_database()
{
    printf("Unsupported Operation %s\n",
           "missing from this exercise - shouldn't be called from a unit test");
    exit(1);
}



void Store::add_stocked_items(std::vector<Product *> products) {
    for (int i = 0; i < products.size(); ++i) {
        add_product(products[i]);
    }

}

std::string Store::get_store_name() {
    return _name;
}

void Store::add_product(Product *product) {
    _items_in_stock[product->get_product_name()] = product;
}

void Store::add_store_event(Product *store_event) {
    add_product(store_event);
}

Product *Store::get_item(std::string name) {
    return _items_in_stock[name];
}

std::string Store::get_store_id() {
    return _id;
}

std::vector<Product *> Store::get_store_stock() {
    std::vector<Product*> products;
    for (auto & it : _items_in_stock) {
        products.push_back( it.second );
    }
    return products;
}

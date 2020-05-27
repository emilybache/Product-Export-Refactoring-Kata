#ifndef TAX_H
#define TAX_H


#include "Util.h"

static double calculate_added_tax(std::vector<Order*> orders){
    double tax = 0.0;
    for (int i = 0 ; i < orders.size(); ++i) {
        Order* order = orders[i];
        if (order->get_order_date() < from_iso_date("2018-01-01T00:00Z"))
            tax += 10;

        else
            tax += 20;

        std::vector<Product*> products = order->get_order_products();
        for (int i = 0; i < products.size(); ++i) {
            Product* product = products[i];
            if (product->is_product_event())
                tax += product->get_product_price()->get_price_in_currency("USD") * 0.25;

            else
                tax += product->get_product_price()->get_price_in_currency("USD") * 0.175;
        }
    }

    return tax;
}

#endif
#include "LinkedList.h"
#include "Order.h"
#include "Price.h"
#include "Product.h"
#include "Util.h"

double calculate_added_tax(const struct LinkedList* orders)
{
    double tax = 0.0;
    for (const struct LinkedList* node = orders; node; node = node->next) {
        const struct Order* order = (const struct Order*)node->data;
        if (get_order_date(order) < from_iso_date("2018-01-01T00:00Z"))
            tax += 10;

        else
            tax += 20;

        const struct LinkedList* products = get_order_products(order);
        for (const struct LinkedList* node = products; node; node = node->next) {
            const struct Product* product = (const struct Product*)node->data;
            if (is_product_event(product))
                tax += get_price_amount_in_currency(get_product_price(product), "USD") * 0.25;

            else
                tax += get_price_amount_in_currency(get_product_price(product), "USD") * 0.175;
        }
    }

    return tax;
}

#include "LinkedList.h"
#include "Order.h"
#include "Price.h"
#include "Product.h"
#include "Store.h"
#include "StringBuilder.h"
#include "TaxCalculator.h"
#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* stylist_for(const struct Product*);
static const char* make_formatted_double(double);

const char* xml_export_full(const struct LinkedList* orders)
{
    struct StringBuilder* xml = make_sb();
    sb_append(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    sb_append(xml, "<orders>");
    for (const struct LinkedList* node = orders; node; node = node->next) {
        const struct Order* order = (const struct Order*)node->data;
        sb_append(xml, "<order");
        sb_append(xml, " id='");
        sb_append(xml, get_order_id(order));
        sb_append(xml, "'>");
        const struct LinkedList* products = get_order_products(order);
        for (const struct LinkedList* node = products; node; node = node->next) {
            const struct Product* product = (const struct Product*)node->data;
            sb_append(xml, "<product");
            sb_append(xml, " id='");
            sb_append(xml, get_product_id(product));
            sb_append(xml, "'");
            if (is_product_event(product)) {
                sb_append(xml, " stylist='");
                sb_append(xml, stylist_for(product));
                sb_append(xml, "'");
            }

            if (get_product_weight(product) > 0) {
                sb_append(xml, " weight='");
                sb_append_long(xml, get_product_weight(product));
                sb_append(xml, "'");
            }

            sb_append(xml, ">");
            sb_append(xml, "<price");
            sb_append(xml, " currency='");
            sb_append(xml, get_price_currency(get_product_price(product)));
            sb_append(xml, "'>");
            const char* formatted = make_formatted_double(get_price_amount(get_product_price(product)));
            sb_append(xml, formatted);
            free((void*)formatted);
            sb_append(xml, "</price>");
            sb_append(xml, get_product_name(product));
            sb_append(xml, "</product>");
        }

        sb_append(xml, "</order>");
    }

    sb_append(xml, "</orders>");
    return sb_string(xml);
}

const char* xml_export_tax_details(struct LinkedList* orders)
{
    struct StringBuilder* xml = make_sb();
    sb_append(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    sb_append(xml, "<orderTax>");
    for (const struct LinkedList* node = orders; node; node = node->next) {
        const struct Order* order = (const struct Order*)node->data;
        sb_append(xml, "<order");
        sb_append(xml, " date='");
        const char* formatted = make_iso_date_str(get_order_date(order));
        sb_append(xml, formatted);
        free((void*)formatted);
        sb_append(xml, "'");
        sb_append(xml, ">");
        double tax = 0.0;
        const struct LinkedList* products = get_order_products(order);
        for (const struct LinkedList* node = products; node; node = node->next) {
            const struct Product* product = (const struct Product*)node->data;
            sb_append(xml, "<product");
            sb_append(xml, " id='");
            sb_append(xml, get_product_id(product));
            sb_append(xml, "'");
            sb_append(xml, ">");
            sb_append(xml, get_product_name(product));
            sb_append(xml, "</product>");
            if (is_product_event(product))
                tax += get_price_amount_in_currency(get_product_price(product), "USD") * 0.25;
            else
                tax += get_price_amount_in_currency(get_product_price(product), "USD") * 0.175;

        }

        sb_append(xml, "<orderTax currency='USD'>");
        if (get_order_date(order) < from_iso_date("2018-01-01T00:00Z"))
            tax += 10;
        else
            tax += 20;
        const char* formatted_tax = make_formatted_double(tax);
        sb_append(xml, formatted_tax);
        free((void*)formatted_tax);
        sb_append(xml, "</orderTax>");
        sb_append(xml, "</order>");
    }

    double total_tax = calculate_added_tax(orders);
    const char* formatted_total_tax = make_formatted_double(total_tax);
    sb_append(xml, formatted_total_tax);
    free((void*)formatted_total_tax);
    sb_append(xml, "</orderTax>");
    return sb_string(xml);
}

static const char* make_formatted_double(double d)
{
    char* s = (char*)malloc(sizeof(char[24 + 1]));
    sprintf(s, "%03.2f", d);
    return s;
}

const char* xml_export_store(struct Store* store)
{
    struct StringBuilder* xml = make_sb();
    sb_append(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    sb_append(xml, "<store");
    sb_append(xml, " name='");
    sb_append(xml, get_store_name(store));
    sb_append(xml, "'");
    sb_append(xml, ">");
    const struct LinkedList* products = get_store_stock(store);
    for (const struct LinkedList* node = products; node; node = node->next) {
        const struct Product* product = (const struct Product*)node->data;
        sb_append(xml, "<product");
        sb_append(xml, " id='");
        sb_append(xml, get_product_id(product));
        sb_append(xml, "'");
        if (is_product_event(product)) {
            sb_append(xml, " location='");
            sb_append(xml, get_store_name(store));
            sb_append(xml, "'");
        }
        else {
            sb_append(xml, " weight='");
            sb_append_long(xml, get_product_weight(product));
            sb_append(xml, "'");
        }

        sb_append(xml, ">");
        sb_append(xml, "<price");
        sb_append(xml, " currency='");
        sb_append(xml, get_price_currency(get_product_price(product)));
        sb_append(xml, "'>");
        const char* formatted = make_formatted_double(get_price_amount(get_product_price(product)));
        sb_append(xml, formatted);
        free((void*)formatted);
        sb_append(xml, "</price>");
        sb_append(xml, get_product_name(product));
        sb_append(xml, "</product>");
    }

    sb_append(xml, "</store>");

    return sb_string(xml);
}

const char* xml_export_history(struct LinkedList* orders)
{
    struct StringBuilder* xml = make_sb();
    sb_append(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    sb_append(xml, "<orderHistory");
    sb_append(xml, " createdAt='");
    time_t now = time(NULL);
    const char* formatted_now = make_iso_date_str(now);
    sb_append(xml, formatted_now);
    free((void*)formatted_now);
    sb_append(xml, "'");
    sb_append(xml, ">");
    for (const struct LinkedList* node = orders; node; node = node->next) {
        const struct Order* order = (const struct Order*)node->data;
        sb_append(xml, "<order");
        sb_append(xml, " date='");
        const char* formatted_date = make_iso_date_str(get_order_date(order));
        sb_append(xml, formatted_date);
        free((void*)formatted_date);
        sb_append(xml, "'");
        sb_append(xml, " totalDollars='");
        const char* formatted_total = make_formatted_double(order_total_dollars(order));
        sb_append(xml, formatted_total);
        free((void*)formatted_total);
        sb_append(xml, "'>");
        const struct LinkedList* products = get_order_products(order);
        for (const struct LinkedList* node = products; node; node = node->next) {
            const struct Product* product = (const struct Product*)node->data;
            sb_append(xml, "<product");
            sb_append(xml, " id='");
            sb_append(xml, get_product_id(product));
            sb_append(xml, "'");
            sb_append(xml, ">");
            sb_append(xml, get_product_name(product));
            sb_append(xml, "</product>");
        }

        sb_append(xml, "</order>");
    }

    sb_append(xml, "</orderHistory>");
    return sb_string(xml);
}

static const char* stylist_for(const struct Product* product)
{
    (void)product; /* unused */

    return "Celeste Pulchritudo"; /* in future we will look up the name of the stylist from the database */
}

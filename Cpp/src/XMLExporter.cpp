
#include <iomanip>
#include "Order.h"
#include "Price.h"
#include "Product.h"
#include "Store.h"
#include "TaxCalculator.h"
#include "Util.h"
#include "XMLExporter.h"

std::string XMLExporter::export_full(std::vector<Order *> orders) {
    std::string xml;
    xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    xml.append("<orders>");
    for (auto &it : orders){
        Order *order = it;
        xml.append("<order");
        xml.append(" id='");
        xml.append(order->get_order_id());
        xml.append("'>");
        auto products = order->get_order_products();
        for (auto &it : products) {
            Product *product = it;
            xml.append("<product");
            xml.append(" id='");
            xml.append(product->get_product_id());
            xml.append("'");
            if (product->is_product_event()) {
                xml.append(" stylist='");
                xml.append(stylist_for(product));
                xml.append("'");
            }

            if (product->get_product_weight() > 0) {
                xml.append(" weight='");
                xml.append(std::to_string(product->get_product_weight()));
                xml.append("'");
            }

            xml.append(">");
            xml.append("<price");
            xml.append(" currency='");
            xml.append(product->get_product_price()->get_price_currency());
            xml.append("'>");
            std::string formatted = make_formatted_double(product->get_product_price()->get_price_amount());
            xml.append(formatted);

            xml.append("</price>");
            xml.append(product->get_product_name());
            xml.append("</product>");
        }

        xml.append("</order>");
    }

    xml.append("</orders>");
    return xml;
}

std::string XMLExporter::export_tax_details(std::vector<Order *> orders) {
    std::string xml;
    xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    xml.append("<orderTax>");
    for (auto &it : orders) {
        Order *order = it;
        xml.append("<order");
        xml.append(" date='");
        std::string formatted = make_iso_date_str(order->get_order_date());
        xml.append(formatted);

        xml.append("'");
        xml.append(">");
        double tax = 0.0;
        auto products = order->get_order_products();
        for (auto &it : products) {
            Product *product = it;
            xml.append("<product");
            xml.append(" id='");
            xml.append(product->get_product_id());
            xml.append("'");
            xml.append(">");
            xml.append(product->get_product_name());
            xml.append("</product>");
            if (product->is_product_event())
                tax += product->get_product_price()->get_price_in_currency("USD") * 0.25;
            else
                tax += product->get_product_price()->get_price_in_currency("USD") * 0.175;

        }

        xml.append("<orderTax currency='USD'>");
        if (order->get_order_date() < from_iso_date("2018-01-01T00:00Z"))
            tax += 10;
        else
            tax += 20;
        std::string formatted_tax = make_formatted_double(tax);
        xml.append(formatted_tax);

        xml.append("</orderTax>");
        xml.append("</order>");
    }

    double total_tax = calculate_added_tax(orders);
    std::string formatted_total_tax = make_formatted_double(total_tax);
    xml.append(formatted_total_tax);

    xml.append("</orderTax>");
    return xml;
}

static const char *make_formatted_double(double d) {
    char *s = (char *) malloc(sizeof(char[24 + 1]));
    sprintf(s, "%03.2f", d);
    return s;
}

std::string XMLExporter::export_store(Store *store) {
    std::string xml;
    xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    xml.append("<store");
    xml.append(" name='");
    xml.append(store->get_store_name());
    xml.append("'");
    xml.append(">");
    for (auto &it : store->get_store_stock()) {
        Product *product = it;
        xml.append("<product");
        xml.append(" id='");
        xml.append(product->get_product_id());
        xml.append("'");
        if (product->is_product_event()) {
            xml.append(" location='");
            xml.append(store->get_store_name());
            xml.append("'");
        } else {
            xml.append(" weight='");
            xml.append(std::to_string(product->get_product_weight()));
            xml.append("'");
        }

        xml.append(">");
        xml.append("<price");
        xml.append(" currency='");
        xml.append(product->get_product_price()->get_price_currency());
        xml.append("'>");
        std::string formatted = make_formatted_double(product->get_product_price()->get_price_amount());
        xml.append(formatted);

        xml.append("</price>");
        xml.append(product->get_product_name());
        xml.append("</product>");
    }

    xml.append("</store>");

    return xml;
}

std::string XMLExporter::export_history(std::vector<Order *> orders) {
    std::string xml;
    xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    xml.append("<orderHistory");
    xml.append(" createdAt='");
    time_t now = std::time(NULL);
    std::string formatted_now = make_iso_date_str(now);
    xml.append(formatted_now);

    xml.append("'");
    xml.append(">");
    for (auto &it : orders) {
        Order* order = it;
        xml.append("<order");
        xml.append(" date='");
        std::string formatted_date = make_iso_date_str(order->get_order_date());
        xml.append(formatted_date);

        xml.append("'");
        xml.append(" totalDollars='");
        std::string formatted_total = make_formatted_double(order->order_total_dollars());
        xml.append(formatted_total);
        xml.append("'>");
        for (auto &it2: order->get_order_products()) {
            Product *product = it2;
            xml.append("<product");
            xml.append(" id='");
            xml.append(product->get_product_id());
            xml.append("'");
            xml.append(">");
            xml.append(product->get_product_name());
            xml.append("</product>");
        }

        xml.append("</order>");
    }

    xml.append("</orderHistory>");
    return xml;
}

std::string XMLExporter::stylist_for(Product *product) {

    return "Celeste Pulchritudo"; /* in future we will look up the name of the stylist from the database */
}

std::string XMLExporter::make_formatted_double(double d) {
    std::stringstream ss;
    ss << std::fixed;
    ss << std::setprecision(2);
    ss << d;
    return ss.str();
}





#include <string>
#include <vector>
#include "Store.h"
#include "Order.h"

class XMLExporter {
public:
    std::string export_full(std::vector<Order*> orders);
    std::string export_tax_details(std::vector<Order*> orders);
    std::string export_store(Store* store);
    std::string export_history(std::vector<Order*> orders);

private:
    std::string stylist_for(Product*);
    std::string make_formatted_double(double);
};



#import "Price.h"

double Price::get_price_in_currency(std::string currency_code)
{
    if ((this->_currency_code == currency_code)) {
        return this->_amount;
    }
    else {
        printf("Unsupported Operation %s\n",
               "shouldn't call this from a unit test, it will do a slow db "
               "lookup");
        exit(1);
    }
}

std::string Price::get_price_currency() {
    return _currency_code;
}

double Price::get_price_amount() {
    return _amount;
}

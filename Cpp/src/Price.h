#ifndef PRICE_H
#define PRICE_H


#include <utility>

#import <string>

class Price {
public:
    Price(double price, std::string currencyCode) : _amount(price), _currency_code(std::move(currencyCode)) {};

    std::string get_price_currency();

    double get_price_amount();

    double get_price_in_currency(std::string currencyCode);

private:
    double _amount;
    std::string _currency_code;
};

#endif
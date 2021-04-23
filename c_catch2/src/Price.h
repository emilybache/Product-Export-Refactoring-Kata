#ifndef PRICE_H
#define PRICE_H

struct Price;

extern const struct Price* make_price(double, const char*);
extern const char* get_price_currency(const struct Price*);
extern double get_price_amount(const struct Price*);
extern double get_price_amount_in_currency(const struct Price*, const char*);

#endif
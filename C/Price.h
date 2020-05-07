struct Price;

extern const struct Price* make_price(double, const char* currency_code);
extern const char* get_price_currency(const struct Price* this);
extern double get_price_amount(const struct Price* this);
extern double get_price_amount_in_currency(const struct Price* this, const char* currency_code);

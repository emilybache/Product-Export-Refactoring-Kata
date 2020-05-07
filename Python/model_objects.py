
class ModelObject(object):
    def save_to_database(self):
        raise Exception("You shouldn't call save_to_database from a unit test")


class Order(ModelObject):
    def __init__(self, id, date, store, products):
        self.id = id
        self.date = date
        self.store = store
        self.products = products[:]

    def total_dollars(self):
        dollars = 0
        for product in self.products:
            dollars += product.price.get_amount_in_currency("USD")
        return dollars


class Price(ModelObject):
    def __init__(self, amount, currency):
        self.amount = amount
        self.currency = currency

    def get_amount_in_currency(self, currency):
        return self.amount


class Product(ModelObject):
    def __init__(self, name, id, weight, price):
        self.name = name
        self.id = id
        self.weight = weight
        self.price = price
        self.isEvent = False


class Store(ModelObject):
    """Represents a physical Store where you can go and buy products and attend events."""
    def __init__(self, name, id, products=None):
        self.name = name
        self.id = id
        self.stock = products or []


class StoreEvent(Product):
    """Ticket to In-store event, eg makeover, eyeshadow masterclass
    or beauty product launch evening reception"""
    def __init__(self, name, store, id, price):
        super(StoreEvent, self).__init__(name, id, 0, price)
        self.store = store
        self.isEvent = True

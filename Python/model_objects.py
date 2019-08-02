
class ModelObject:
    def save_to_database(self):
        raise Exception("You shouldn't call save_to_database from a unit test")


class Order(ModelObject):
    def __init__(self, id, date, store, products):
        self.id = id
        self.date = date
        self.store = store
        self.products = products[:]


class Price(ModelObject):
    def __init__(self, amount, currency):
        self.amount = amount
        self.currency = currency


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
        self.products = products or []


class StoreEvent(Product):
    """Ticket to In-store event, eg makeover, eyeshadow masterclass
    or beauty product launch evening reception"""
    def __init__(self, name, store, id, price):
        super().__init__(name, id, 0, price)
        self.store = store
        self.isEvent = True




import datetime

from dateutil.parser import parse

from .tax_calculator import calculate_added_tax


def export_full(orders):
    xml = ""
    xml += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    xml += "<orders>"
    for order in orders:
        xml += "<order"
        xml += " id='"
        xml += order.id
        xml += "'>"
        for product in order.products:
            xml += "<product"
            xml += " id='"
            xml += product.id
            xml += "'"
            if product.isEvent:
                xml += " stylist='"
                xml += stylist_for(product)
                xml += "'"

            if product.weight > 0:
                xml += " weight='"
                xml += "{:.2f}".format(product.weight)
                xml += "'"

            xml += ">"
            xml += "<price"
            xml += " currency='"
            xml += product.price.currency
            xml += "'>"
            xml += "{:.2f}".format(product.price.amount)
            xml += "</price>"
            xml += product.name
            xml += "</product>"

        xml += "</order>"

    xml += "</orders>"
    return xml


def export_tax_details(orders):
    xml = ""
    xml += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    xml += "<orderTax>"
    for order in orders:
        xml += "<order"
        xml += " date='"
        xml += order.date.isoformat()
        xml += "'"
        xml += ">"
        tax = 0
        for product in order.products:
            xml += "<product"
            xml += " id='"
            xml += product.id
            xml += "'"
            xml += ">"
            xml += product.name
            xml += "</product>"
            if product.isEvent:
                tax += product.price.get_amount_in_currency("USD") * 0.2
            else:
                tax += product.price.get_amount_in_currency("USD") * 0.175

        xml += "<orderTax currency='USD'>"
        if order.date < parse("2018-01-01T00:00Z"):
            tax += 10
        else:
            tax += 20
        xml += "{:.2f}".format(tax)
        xml += "</orderTax>"
        xml += "</order>"

    total_tax = calculate_added_tax(orders)
    xml += "{:.2f}".format(total_tax)
    xml += "</orderTax>"
    return xml


def export_store(store):
    xml = ""
    xml += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"

    xml += "<store"
    xml += " name='"
    xml += store.name
    xml += "'"
    xml += ">"
    for product in store.stock:
        xml += "<product"
        xml += " id='"
        xml += product.id
        xml += "'"
        if product.isEvent:
            xml += " location='"
            xml += store.name
            xml += "'"
        else:
            xml += " weight='"
            xml += "{:.2f}".format(product.weight)
            xml += "'"

        xml += ">"
        xml += "<price"
        xml += " currency='"
        xml += product.price.currency
        xml += "'>"
        xml += "{:.2f}".format(product.price.amount)
        xml += "</price>"
        xml += product.name
        xml += "</product>"

    xml += "</store>"
    
    return xml


def export_history(orders):
    xml = ""
    xml += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    xml += "<orderHistory"
    xml += " createdAt='"
    now = datetime.datetime.now()
    xml += now.isoformat()
    xml += "'"
    xml += ">"
    for order in orders:
        xml += "<order"
        xml += " date='"
        xml += order.date.isoformat()
        xml += "'"
        xml += " totalDollars='"
        xml += "{:.2f}".format(order.total_dollars())
        xml += "'>"
        for product in order.products:
            xml += "<product"
            xml += " id='"
            xml += product.id
            xml += "'"
            xml += ">"
            xml += product.name
            xml += "</product>"

        xml += "</order>"

    xml += "</orderHistory>"
    return xml


def stylist_for(product):
    return "Celeste Pulchritudo"  # in future we will look up the name of the stylist from the database

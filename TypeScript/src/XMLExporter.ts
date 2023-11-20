import { Order } from "./Order";
import { Product } from "./Product";
import { Store } from "./Store";
import { TaxCalculator } from "./TaxCalculator";
import { Util } from "./Util";

export class XMLExporter {

    static exportFull(orders: Order[]): string {
        let xml: string[] = [];
        xml.push(`<?xml version="1.0" encoding="UTF-8"?>`);
        xml.push("<orders>");

        for (const order of orders) {
            xml.push(`<order id='${order.getId()}'>`);

            for (const product of order.getProducts()) {
                xml.push(`<product id='${product.getId()}'`);

                if (product.isEvent()) {
                    xml.push(` stylist='${XMLExporter.stylistFor(product)}'`);
                }

                if (product.getWeight() > 0) {
                    xml.push(` weight='${product.getWeight()}'`);
                }

                xml.push(">");
                xml.push(`<price currency='${product.getPrice().getCurrency()}'>${product.getPrice().getAmount()}</price>`);
                xml.push(product.getName());
                xml.push("</product>");
            }

            xml.push("</order>");
        }

        xml.push("</orders>");
        return xml.join("\n");
    }

    static exportTaxDetails(orders: Order[]): string {
        function formatNumber(value: number): string {
            return value.toFixed(2);
        }

        let xml: string[] = [];
        xml.push(`<?xml version="1.0" encoding="UTF-8"?>`);
        xml.push("<orderTax>");

        for (const order of orders) {
            xml.push(`<order date='${Util.toIsoDate(order.getDate())}'>`);
            let tax = 0;

            for (const product of order.getProducts()) {
                xml.push(`<product id='${product.getId()}'>${product.getName()}</product>`);

                if (product.isEvent()) {
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.25;
                } else {
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.175;
                }
            }

            if (order.getDate() < Util.fromIsoDate("2018-01-01T00:00Z")) {
                tax += 10;
            } else {
                tax += 20;
            }

            xml.push(`<orderTax currency='USD'>${formatNumber(tax)}</orderTax>`);
            xml.push("</order>");
        }

        const totalTax = TaxCalculator.calculateAddedTax(orders);
        xml.push(formatNumber(totalTax));
        xml.push("</orderTax>");

        return xml.join("\n");
    }

    static exportStore(store: Store): string {
        let xml: string[] = [];
        xml.push(`<?xml version="1.0" encoding="UTF-8"?>`);
        xml.push(`<store name='${store.getName()}'>`);

        for (const product of store.getStock()) {
            xml.push(`<product id='${product.getId()}'`);

            if (product.isEvent()) {
                xml.push(` location='${store.getName()}'`);
            } else {
                xml.push(` weight='${product.getWeight()}'`);
            }

            xml.push(">");
            xml.push(`<price currency='${product.getPrice().getCurrency()}'>${product.getPrice().getAmount()}</price>`);
            xml.push(product.getName());
            xml.push("</product>");
        }

        xml.push("</store>");
        return xml.join("\n");
    }

    static exportHistory(orders: Order[]): string {
        let xml: string[] = [];
        xml.push(`<?xml version="1.0" encoding="UTF-8"?>`);
        xml.push(`<orderHistory createdAt='${Util.toIsoDate(new Date())}'>`);

        for (const order of orders) {
            xml.push(`<order date='${Util.toIsoDate(order.getDate())}' totalDollars='${order.totalDollars()}'>`);

            for (const product of order.getProducts()) {
                xml.push(`<product id='${product.getId()}'>${product.getName()}</product>`);
            }

            xml.push("</order>");
        }

        xml.push("</orderHistory>");
        return xml.join("\n");
    }


    private static stylistFor(product: Product): string {
        return "Celeste Pulchritudo"; // In the future, look up the name of the stylist from the database
    }

}

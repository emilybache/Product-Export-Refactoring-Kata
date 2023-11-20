import { Order } from "./Order";
import { Util } from "./Util";

export class TaxCalculator {

    static calculateAddedTax(orders: Order[]): number {
        let tax = 0.0;
        for (const order of orders) {
            if (order.getDate() < Util.fromIsoDate("2018-01-01T00:00Z")) {
                tax += 10;
            } else {
                tax += 20;
            }

            for (const product of order.getProducts()) {
                if (product.isEvent()) {
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.25;
                } else {
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.175;
                }
            }
        }

        return tax;
    }

}

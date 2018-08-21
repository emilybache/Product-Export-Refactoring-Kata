package codingdojo;

import java.text.ParseException;
import java.util.Collection;

import static codingdojo.Util.fromISO8601UTC;

public class TaxCalculator {

    public static double calculateAddedTax(Collection<Order> orders) throws ParseException {
        double tax = 0D;
        for (Order order : orders) {
            if (order.getDate().before(fromISO8601UTC("2018-01-01T00:00Z"))) {
                tax += 10;
            } else {
                tax += 20;
            }
            for (Product product : order.getProducts()) {
                if (product.isEvent()) {
                    tax += product.getPrice().getAmountInCurrency("USD")* 0.25;
                } else {
                    tax += product.getPrice().getAmountInCurrency("USD")* 0.175;
                }
            }
        }
        return tax;
    }
}

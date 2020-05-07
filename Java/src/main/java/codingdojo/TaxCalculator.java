package codingdojo;

import java.util.Collection;

public class TaxCalculator {

    public static double calculateAddedTax(Collection<Order> orders) {
        double tax = 0.0;
        for (Order order : orders) {
            if (order.getDate().before(Util.fromIsoDate("2018-01-01T00:00Z")))
                tax += 10;
            else
                tax += 20;

            for (Product product : order.getProducts())
                if (product.isEvent())
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.25;
                else
                    tax += product.getPrice().getAmountInCurrency("USD") * 0.175;
        }

        return tax;
    }
}

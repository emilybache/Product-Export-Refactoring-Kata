package codingdojo;

import java.text.*;
import java.util.Collection;
import java.util.Date;
import java.util.TimeZone;

import static codingdojo.Util.fromISO8601UTC;

public class XMLExporter {

    public static String exportFull(Collection<Order> orders) {
        StringBuffer xml = new StringBuffer();
        xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" + '\n');
        xml.append("<orders>" + '\n');
        for (Order order : orders) {
            xml.append("<order");
            xml.append(" id='");
            xml.append(order.getId());
            xml.append("'>" + '\n');
            for (Product product: order.getProducts()) {
                xml.append("<product");
                xml.append(" id='");
                xml.append(product.getId());
                xml.append("'");
                if (!product.isEvent()) {
                    xml.append(" colour='");
                    xml.append(colourGroupFor(product));
                    xml.append("'");
                }
                if (product.getWeight() > 0) {
                    xml.append(" weight='");
                    xml.append(product.getWeight());
                    xml.append("'");
                }
                xml.append(">" + '\n');
                xml.append("<price");
                xml.append(" currency='");
                xml.append(product.getPrice().getCurrency());
                xml.append("'>");
                xml.append(product.getPrice().getAmount());
                xml.append("</price>" + '\n');
                xml.append(product.getName() + '\n');
                xml.append("</product>" + '\n');
            }
            xml.append("</order>" + '\n');
        }
        xml.append("</orders>" + '\n');
        return xml.toString();
    }

    public static String exportHistory(Collection<Order> orders) {
        StringBuffer xml = new StringBuffer();
        xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" + '\n');
        xml.append("<orderHistory>" + '\n');
        for (Order order : orders) {
            xml.append("<order");
            xml.append(" date='");
            xml.append(isoDate(order.getDate()));
            xml.append("'");
            xml.append(" totalDollars='");
            xml.append(order.totalDollars());
            xml.append("'>" + '\n');
            for (Product product: order.getProducts()) {
                xml.append("<product");
                xml.append(" id='");
                xml.append(product.getId());
                xml.append("'");
                xml.append(">");
                xml.append(product.getName());
                xml.append("</product>" + '\n');
            }
            xml.append("</order>" + '\n');
        }
        xml.append("</orderHistory>" + '\n');
        return xml.toString();
    }

    public static String exportTaxDetails(Collection<Order> orders) throws Exception {
        NumberFormat formatter = new DecimalFormat("#0.00");
        StringBuffer xml = new StringBuffer();
        xml.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" + '\n');
        xml.append("<orderTax>" + '\n');
        for (Order order : orders) {
            xml.append("<order");
            xml.append(" date='");
            xml.append(isoDate(order.getDate()));
            xml.append("'");
            xml.append(">" + '\n');
            double tax = 0D;
            for (Product product: order.getProducts()) {
                xml.append("<product");
                xml.append(" id='");
                xml.append(product.getId());
                xml.append("'");
                xml.append(">");
                xml.append(product.getName());
                xml.append("</product>" + '\n');
                if (product.isEvent()) {
                    tax += product.getPrice().getAmountInCurrency("USD")* 0.25;
                } else {
                    tax += product.getPrice().getAmountInCurrency("USD")* 0.175;
                }
            }
            xml.append("<orderTax currency='USD'>");
            if (order.getDate().before(fromISO8601UTC("2018-01-01T00:00Z"))) {
                tax += 10;
            } else {
                tax += 20;
            }
            xml.append(formatter.format(tax));
            xml.append("</orderTax>");
            xml.append("</order>" + '\n');
        }
        double totalTax = TaxCalculator.calculateAddedTax(orders);
        xml.append(formatter.format(totalTax));
        xml.append('\n');
        xml.append("</orderTax>" + '\n');
        return xml.toString();
    }

    private static String isoDate(Date date) {
        TimeZone tz = TimeZone.getTimeZone("UTC");
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm'Z'");
        df.setTimeZone(tz);
        return df.format(date);
    }


    private static String colourGroupFor(Product product) {
        return "PINK"; // everything is pink right now. In future we might support other colours too. Perhaps mauve?
    }

}

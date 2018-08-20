package codingdojo;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Collection;
import java.util.Date;
import java.util.TimeZone;

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
                xml.append(" colour='");
                xml.append(colourGroupFor(product));
                xml.append("'");
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
            xml.append(" totalPrice='");
            xml.append(totalDollars(order));
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

    private static long totalDollars(Order order) {
        long dollars = 0L;
        for (Product product : order.getProducts()) {
            dollars += product.getPrice().getAmountInCurrency("USD");
        }
        return dollars;
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

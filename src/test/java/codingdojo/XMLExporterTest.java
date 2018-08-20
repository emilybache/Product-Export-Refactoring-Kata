package codingdojo;

import org.junit.Before;
import org.junit.Test;
import org.approvaltests.Approvals;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.TimeZone;

public class XMLExporterTest {


    private ArrayList<Order> orders;

    @Before
    public void setUp() throws ParseException {
        Store nordstan = new Store("Nordstan", "4189");

        Product cherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99D, "USD"));
        Product rosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99D, "USD"));
        Product blusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99D, "USD"));
        Product eyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99D, "USD"));
        Product wildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99D, "USD"));
        Product cocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99D, "USD"));

        nordstan.addStockedItems(cherryBloom, rosePetal, blusherBrush, eyelashCurler, wildRose, cocoaButter);

        // Store events add themselves to the stocked items at their store
        Product masterclass = new StoreEvent("Eyeshadow Masterclass", nordstan, new Price(119.99D, "USD"));
        Product makeover = new StoreEvent("Makeover", nordstan, new Price(149.99D, "USD"));

        Order order1 = new Order("1234", fromISO8601UTC("2018-09-01T13:24Z"), nordstan);
        order1.addProducts(cherryBloom, cherryBloom, wildRose, cocoaButter);

        Order order2 = new Order("1235", fromISO8601UTC("2018-08-31T14:02Z"), nordstan);
        order2.addProducts(eyelashCurler, blusherBrush, wildRose);

        orders = new ArrayList<Order>();
        orders.add(order1);
        orders.add(order2);
    }

    public static Date fromISO8601UTC(String dateStr) throws ParseException {
        TimeZone tz = TimeZone.getTimeZone("UTC");
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm'Z'");
        df.setTimeZone(tz);

        return df.parse(dateStr);
    }

    @Test
    public void testFullExport() {
        String xml = XMLExporter.exportFull(orders);
        Approvals.verify(xml);
    }

    @Test
    public void testExportHistory() {
        String xml = XMLExporter.exportHistory(orders);
        Approvals.verify(xml);
    }
}

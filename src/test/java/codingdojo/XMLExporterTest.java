package codingdojo;

import org.junit.Before;
import org.junit.Test;
import org.approvaltests.Approvals;

import java.text.ParseException;
import java.util.ArrayList;

public class XMLExporterTest {


    private ArrayList<Order> orders;

    @Test
    public void testSomething() throws Exception {
        Store nordstan = new Store("Nordstan", "4189");

        Product cherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99D, "USD"));
        Product rosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99D, "USD"));
        Product blusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99D, "USD"));
        Product eyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99D, "USD"));
        Product wildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99D, "USD"));
        Product cocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99D, "USD"));
        nordstan.addStockedItems(cherryBloom, rosePetal, blusherBrush, eyelashCurler, wildRose, cocoaButter);

        // Store events add themselves to the stocked items at their store
        Product masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01", nordstan, new Price(119.99D, "USD"));
        Product makeover = new StoreEvent("Makeover", "EVENT02", nordstan, new Price(149.99D, "USD"));

        Order order = new Order("1234", Util.fromISO8601UTC("2018-09-01T13:24Z"), nordstan);

        // TODO: Finish this test case
    }


}

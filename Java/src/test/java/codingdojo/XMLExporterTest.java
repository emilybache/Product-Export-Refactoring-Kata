package codingdojo;

import org.approvaltests.Approvals;
import org.junit.Test;

import java.util.Arrays;
import java.util.Collection;

import static codingdojo.SampleModelObjects.RecentOrder;

public class XMLExporterTest {

    @Test
    public void exportFull() throws Exception {

        Collection<Order> orders = Arrays.asList(RecentOrder);
        String xml = XMLExporter.exportFull(orders);
        Approvals.verifyXml(xml);

    }


}

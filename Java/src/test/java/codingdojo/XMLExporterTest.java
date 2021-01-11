package codingdojo;

import org.approvaltests.Approvals;
import org.approvaltests.core.Options;
import org.approvaltests.scrubbers.RegExScrubber;
import org.junit.Test;

import java.util.Arrays;
import java.util.Collection;

import static codingdojo.SampleModelObjects.FlagshipStore;
import static codingdojo.SampleModelObjects.OldOrder;
import static codingdojo.SampleModelObjects.RecentOrder;

public class XMLExporterTest {

    @Test
    public void exportFull() throws Exception {
        Collection<Order> orders = Arrays.asList(RecentOrder, OldOrder);
        String xml = XMLExporter.exportFull(orders);
        Approvals.verifyXml(xml);
    }

    @Test
    public void exportTaxDetails() throws Exception {
        Collection<Order> orders = Arrays.asList(RecentOrder, OldOrder);
        String xml = XMLExporter.exportTaxDetails(orders);
        Approvals.verifyXml(xml);
    }

    @Test
    public void exportStore() throws Exception {
        Store store = FlagshipStore;
        String xml = XMLExporter.exportStore(store);
        Approvals.verifyXml(xml);
    }

    @Test
    public void exportHistory() throws Exception {
        Collection<Order> orders = Arrays.asList(RecentOrder, OldOrder);
        String xml = XMLExporter.exportHistory(orders);
        String regex = "createdAt='[^']+'";
        Approvals.verifyXml(xml, new Options(new RegExScrubber(
                "createdAt=\"[^\"]+\"",
                "createdAt=\"2018-09-20T00:00Z\"")));
    }
}

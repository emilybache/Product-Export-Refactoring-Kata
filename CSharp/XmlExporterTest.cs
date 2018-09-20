
using System;
using System.Collections.Generic;
using ApprovalTests;
using ApprovalTests.Reporters;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace export
{
    [UseReporter(typeof(DiffReporter))]
    [TestClass]
    public class XmlExporterTest
    {

        [TestMethod]
        public void TestSomething()
        {
            var flagshipStore = new Store { Name = "Nordstan", Id = "4189" };

            var cherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99D, "USD"));
            var rosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99D, "USD"));
            var blusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99D, "USD"));
            var eyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99D, "USD"));
            var wildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99D, "USD"));
            var cocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99D, "USD"));
            flagshipStore.AddStockedItems(cherryBloom, rosePetal, blusherBrush, eyelashCurler, wildRose, cocoaButter);

            // Store events add themselves to the stocked items at their store
            var masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01", flagshipStore, new Price(119.99D, "USD"));
            var makeover = new StoreEvent("Makeover", "EVENT02", flagshipStore, new Price(149.99D, "USD"));

            var order = new Order
            {
                Id = "1234",
                Date = DateTime.Parse("2018-09-01T13:24Z", null, System.Globalization.DateTimeStyles.RoundtripKind),
                Store = flagshipStore
            };
            var orders = new List<Order> { order };

            // TODO: finish writing this test case
        }


    }


}
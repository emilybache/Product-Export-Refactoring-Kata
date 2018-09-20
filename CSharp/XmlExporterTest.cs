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
        public void ExportFull()
        {
            var orders = new List<Order>
            {
                SampleModelObjects.RecentOrder
            };
            Approvals.Verify(XmlExporter.ExportFull(orders));
        }

        [TestMethod]
        public void ExportHistory()
        {
            var orders = new List<Order>
            {
                SampleModelObjects.RecentOrder
            };
            Approvals.Verify(XmlExporter.ExportHistory(orders));
        }

        [TestMethod]
        public void ExportTaxDetails()
        {
            var orders = new List<Order>
            {
                SampleModelObjects.RecentOrder,
                new Order("1234", Util.FromIsoDate("2017-09-01T00:00Z"),
                    SampleModelObjects.FlagshipStore, 
                    new Product[] { SampleModelObjects.CherryBloom, SampleModelObjects.Makeover })
                
            };
            Approvals.Verify(XmlExporter.ExportTaxDetails(orders));
        }

        [TestMethod]
        public void ExportStore()
        {
            Approvals.Verify(XmlExporter.ExportStore(SampleModelObjects.BigStore));
        }


    }


}
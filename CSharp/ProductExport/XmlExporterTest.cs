using System.Collections.Generic;
using System.Text.RegularExpressions;
using ApprovalTests;
using ApprovalTests.Reporters;
using Xunit;

namespace ProductExport
{
    [UseReporter(typeof(DiffReporter))]
    public class XmlExporterTest
    {
        [Fact]
        public void ExportFull()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportFull(orders);
            Approvals.VerifyXml(xml);
        }

        [Fact]
        public void ExportTaxDetails()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportTaxDetails(orders);
            Approvals.VerifyXml(xml);
        }

        [Fact]
        public void ExportStore()
        {
            var store = SampleModelObjects.FlagshipStore;
            var xml = XmlExporter.ExportStore(store);
            Approvals.VerifyXml(xml);
        }

        [Fact]
        public void ExportHistory()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportHistory(orders);
            var regex = "createdAt=\"[^\"]+\"";
            var report = Regex.Replace(xml, regex, "createdAt=\"2018-09-20T00:00Z\"");
            Approvals.VerifyXml(report);
        }
    }
}
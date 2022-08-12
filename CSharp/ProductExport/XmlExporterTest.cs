using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml.Linq;
using VerifyTests;
using VerifyXunit;
using Xunit;

namespace ProductExport
{
    [UsesVerify]
    public class XmlExporterTest
    {
        [Fact]
        public Task ExportFull()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportFull(orders);
            return VerifyXml(xml);
        }

        private Task VerifyXml(string xml)
        {
            var settings = new VerifySettings();
            return VerifyXml(xml, settings);
        }

        private static Task VerifyXml(string xml, VerifySettings settings)
        {
            try
            {
                var xDoc = XDocument.Parse(xml);
                return Verifier.Verify(xDoc, settings);
            }
            catch (Exception e)
            {
                return Verifier.Verify(xml, settings);
            }
        }
        
        [Fact]
        public Task ExportTaxDetails()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportTaxDetails(orders);
            return VerifyXml(xml);
        }

        [Fact]
        public Task ExportStore()
        {
            var store = SampleModelObjects.FlagshipStore;
            var xml = XmlExporter.ExportStore(store);
            return VerifyXml(xml);
        }

        [Fact]
        public Task ExportHistory()
        {
            var orders = new List<Order>() {SampleModelObjects.RecentOrder, SampleModelObjects.OldOrder};
            var xml = XmlExporter.ExportHistory(orders);
            var settings = new VerifySettings();
            settings.AddScrubber(
                input =>
                {
                    var regex = "createdAt=\"[^\"]+\"";
                    var replacement = "createdAt=\"2018-09-20T00:00Z\"";
                    var scrubbed = Regex.Replace(input.ToString(), regex, replacement);
                    input.Clear().Append(scrubbed);
                });
            return VerifyXml(xml, settings);
        }
    }
}
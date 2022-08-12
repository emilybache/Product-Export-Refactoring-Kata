using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
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
        public Task Something()
        {
            // TODO: finish writing this test
            var xml = "";
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
        

    }
}
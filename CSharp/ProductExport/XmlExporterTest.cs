using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
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
                settings.UseExtension("xml");
                var xmlDoc = new XmlDocument();
                xmlDoc.LoadXml(xml);
                return Verifier.Verify(ToIndentedString(xmlDoc), settings);
            }
            catch (Exception e)
            {
                return Verifier.Verify(xml);
            }
        }

        static string ToIndentedString( XmlDocument doc )
        {
            var stringWriter = new StringWriter(new StringBuilder());
            var xmlTextWriter = new XmlTextWriter(stringWriter) {Formatting = Formatting.Indented};
            doc.Save( xmlTextWriter );
            return stringWriter.ToString();
        }

    }
}
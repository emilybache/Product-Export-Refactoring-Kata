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
            return Verifier.VerifyXml(xml);
        }

    }
}
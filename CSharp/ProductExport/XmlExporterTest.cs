using System.Collections.Generic;
using System.Threading.Tasks;
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
            var something = "";
            return Verifier.Verify(something);
        }
    }
}
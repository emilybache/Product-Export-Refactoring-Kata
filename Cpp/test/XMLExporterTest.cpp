#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

#include "SampleModelObjects.h"
#include "XMLExporter.h"

#include <vector>

// This is a convenience function that writes an xml string into a file with name <something>.xml
// it also inserts some linebreaks to make the file easier to read and diff.
void verifyXml(std::string xml, ApprovalTests::Options options=ApprovalTests::Options()) {
    xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
    ApprovalTests::Approvals::verify(xml, options.fileOptions().withFileExtension(".xml"));
}


TEST_CASE("XMLExporter")
{
    make_sample_model_objects();

    // TODO: write this test case

}




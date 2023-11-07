#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "LinkedList.h"
#include "SampleModelObjects.h"
#include "XMLExporter.h"
#include "Util.h"
}

void verifyXml(std::string xml, ApprovalTests::Options options = ApprovalTests::Options()) {
    // Not as good as actual formatting and layout but better than nothing.
    xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");

    ApprovalTests::Approvals::verify(xml,
                                     options.fileOptions().withFileExtension(".xml"));
}

TEST_CASE ("XMLExporter") {
    make_sample_model_objects();

    SECTION("sample section") {
        REQUIRE(true == false);
    }
}





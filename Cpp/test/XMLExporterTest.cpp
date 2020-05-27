#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

#include "SampleModelObjects.h"
#include "XMLExporter.h"

#include <vector>

std::string scrubDate(const std::string& input)
{
    static const std::regex regex("createdAt='[^']+'");

    int matchNumber = 1;
    auto result = input;
    std::smatch m;
    if (std::regex_search(result, m, regex))
    {
        auto guid_match = m.str();
        auto replacement = "createdAt='date_" + std::to_string(matchNumber) + "'";
        result = ApprovalTests::StringUtils::replaceAll(result, guid_match, replacement);
        matchNumber += 1;
    }
    return result;
}

void verifyXml(std::string xml, ApprovalTests::Options options=ApprovalTests::Options()) {
    //auto path = "/Users/emily/Library/Application\\ Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/CLion.app";
    //auto args = "diff {Received} {Approved}";
    //auto reporter = ApprovalTests::CustomReporter::create(path, args);
    xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
    ApprovalTests::Approvals::verify(xml, options.fileOptions().withFileExtension(".xml"));
}



TEST_CASE("XMLExporter")
{
    make_sample_model_objects();

    SECTION("export store") {
        auto xml = XMLExporter().export_store(FlagshipStore);
        verifyXml(xml);
    }

   auto orders = std::vector<Order*>();
   orders.push_back(RecentOrder);
   orders.push_back(OldOrder);

   SECTION("export full") {
        auto xml = XMLExporter().export_full(orders);
        verifyXml(xml);
    }
    SECTION("export tax details") {
        auto xml = XMLExporter().export_tax_details(orders);
        verifyXml(xml);
   }
   SECTION("export history") {
        auto xml = XMLExporter().export_history(orders);
        auto options = ApprovalTests::Options().withScrubber(scrubDate);
        verifyXml(xml, options);
   }
}




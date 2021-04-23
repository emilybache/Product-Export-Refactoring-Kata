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
                                     options.withScrubber(ApprovalTests::Scrubbers::createRegexScrubber("createdAt='[^']+'", "createdAt='date'"))
                                     .fileOptions().withFileExtension(".xml"));
}

TEST_CASE ("XMLExporter") {
    LinkedList* orders = make_linked_list();
    make_sample_model_objects();
    linked_list_append(&orders, RecentOrder);

    SECTION("xml_export_full") {
        LinkedList* additionalProducts = make_linked_list();
        linked_list_append(&additionalProducts, CherryBloom);
        add_order_products(RecentOrder, additionalProducts);
        const char* result = xml_export_full(orders);
        verifyXml(result);
    }

    SECTION("xml_export_store") {
        LinkedList* products = make_linked_list();
        linked_list_append(&products, CherryBloom);
        linked_list_append(&products, RosePetal);
        linked_list_append(&products, BlusherBrush);
        linked_list_append(&products, EyelashCurler);
        linked_list_append(&products, WildRose);
        linked_list_append(&products, CocoaButter);
        store_add_stocked_items(FlagshipStore, products);
        const char* result = xml_export_store(FlagshipStore);
        verifyXml(result);
    }

    SECTION("xml_export_tax_details") {
        LinkedList* products = make_linked_list();
        linked_list_append(&products, WildRose);
        Order* OldOrder = make_order("1235", from_iso_date("2016-09-01T00:00Z"),
                                     FlagshipStore, products);
        linked_list_append(&orders, OldOrder);
        const char* result = xml_export_tax_details(orders);
        verifyXml(result);
    }

    SECTION("xml_export_history") {

        const char* result = xml_export_history(orders);
        verifyXml(result);
    }
}





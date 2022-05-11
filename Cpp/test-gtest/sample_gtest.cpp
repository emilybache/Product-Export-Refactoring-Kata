#include "ApprovalTests.hpp"
#include <gtest/gtest.h>

#include "XMLExporter.h"
#include "StoreEvent.h"
#include "Util.h"

using namespace std;

void verifyXml(std::string xml, ApprovalTests::Options options = ApprovalTests::Options()) {
    xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
    ApprovalTests::Approvals::verify(xml, options.fileOptions().withFileExtension(".xml"));
}

class ProductExportTest : public ::testing::Test {
protected:
    Product *CherryBloom;
    Product *RosePetal;
    Product *BlusherBrush;
    Product *EyelashCurler;
    Product *WildRose;
    Product *CocoaButter;

    std::vector<Product *> storeProducts;
    std::vector<Order *> orders;
    std::vector<Product *> orderProducts;
    std::vector<Product *> oldOrderProducts;


    Store *FlagshipStore;
    Product *Masterclass;
    Product *Makeover;
    Order *RecentOrder;
    Order *OldOrder;

    void SetUp() override {
        CherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99, "USD"));
        RosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99, "USD"));
        BlusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99, "USD"));
        EyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99, "USD"));
        WildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99, "USD"));
        CocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99, "USD"));

        storeProducts = std::vector<Product *>();
        storeProducts.push_back(CherryBloom);
        storeProducts.push_back(RosePetal);
        storeProducts.push_back(BlusherBrush);
        storeProducts.push_back(EyelashCurler);
        storeProducts.push_back(WildRose);
        storeProducts.push_back(CocoaButter);

        FlagshipStore = new Store("Nordstan", "4189", storeProducts);
        /* Store events add themselves to the stocked items at their store */
        Masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01",
                                     FlagshipStore, new Price(119.99, "USD"));
        Makeover = new StoreEvent("Makeover", "EVENT02",
                                  FlagshipStore, new Price(149.99, "USD"));

        orderProducts = std::vector<Product *>();
        orderProducts.push_back(Makeover);
        orderProducts.push_back(EyelashCurler);

        oldOrderProducts = std::vector<Product *>();
        oldOrderProducts.push_back(CherryBloom);
        oldOrderProducts.push_back(Masterclass);

        RecentOrder = new Order("1234", from_iso_date("2018-09-01T00:00Z"),
                                FlagshipStore, orderProducts);

        OldOrder = new Order("1235", from_iso_date("2017-09-01T00:00Z"),
                             FlagshipStore, oldOrderProducts);

        orders = std::vector<Order *>();
        orders.push_back(RecentOrder);
        orders.push_back(OldOrder);

    }


};

TEST_F(ProductExportTest, exportStore) {
    auto xml = XMLExporter().export_store(FlagshipStore);
    verifyXml(xml);
}


TEST_F(ProductExportTest, exportFull) {
    auto xml = XMLExporter().export_full(orders);
    verifyXml(xml);
}

TEST_F(ProductExportTest, exportTaxDetails) {
    auto xml = XMLExporter().export_tax_details(orders);
    verifyXml(xml);
}

TEST_F(ProductExportTest, exportHistory) {
    auto xml = XMLExporter().export_history(orders);
    auto options = ApprovalTests::Options().withScrubber(
            ApprovalTests::Scrubbers::createRegexScrubber(
                    "createdAt='[^']+'", "createdAt='date'")
    );
    verifyXml(xml, options
    );
}

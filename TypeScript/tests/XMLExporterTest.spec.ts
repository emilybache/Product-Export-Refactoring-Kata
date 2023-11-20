import { Order } from "../src/Order";
import { Util } from "../src/Util";
import { XMLExporter } from "../src/XMLExporter";

import { FlagshipStore, Makeover, CherryBloom } from "./SampleModelObjects";

const RecentOrder = new Order("1234", Util.fromIsoDate("2018-09-01T00:00Z"), FlagshipStore, [Makeover]);
const OldOrder = new Order("1235", Util.fromIsoDate("2017-09-01T00:00Z"), FlagshipStore, [CherryBloom]);

describe("XMLExporter", () => {

    it("exportFull", () => {
        const orders = [RecentOrder, OldOrder];
        const xml = XMLExporter.exportFull(orders);
        expect(xml).toMatchSnapshot();
    });

    it("exportTaxDetails", () => {
        const orders = [RecentOrder, OldOrder];
        const xml = XMLExporter.exportTaxDetails(orders);
        expect(xml).toMatchSnapshot();
    });

    it("exportStore", () => {
        const store = FlagshipStore;
        const xml = XMLExporter.exportStore(store);
        expect(xml).toMatchSnapshot();
    });

    it("exportHistory", () => {
        const orders = [RecentOrder, OldOrder];
        let xml = XMLExporter.exportHistory(orders);
        xml = xml.replace(/createdAt='[^']+'/, "createdAt='2018-09-20T00:00Z'");
        expect(xml).toMatchSnapshot();
    });

});

import { XMLExporter } from "../src/XMLExporter";
import { Order } from "../src/Order";

describe("XMLExporter", () => {
    it("Something", () => {

        // TODO: implement this test

        const orders: Order[] = [/* create your orders here */];
        const xml = XMLExporter.exportFull(orders);
        // Use Jest assertions to check if the generated XML is as expected
        // expect(xml).toMatchSnapshot(); // Use snapshot testing for complex XML structures
    });

});

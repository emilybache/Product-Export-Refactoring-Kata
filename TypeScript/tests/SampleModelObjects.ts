import { Product } from "../src/Product";
import { Store } from "../src/Store";
import { StoreEvent } from "../src/StoreEvent";
import { Order } from "../src/Order";
import { Price } from "../src/Price";
import { Util } from "../src/Util";

/**
 * This file contains some sample product data that you could use in your tests.
 */

export const CherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99, "USD"));
export const RosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99, "USD"));
export const BlusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99, "USD"));
export const EyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99, "USD"));
export const WildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99, "USD"));
export const CocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99, "USD"));

export const FlagshipStore = new Store("Nordstan", "4189", [CherryBloom]);

// Store events add themselves to the stocked items at their store
export const Masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01", FlagshipStore, new Price(119.99, "USD"));
export const Makeover = new StoreEvent("Makeover", "EVENT02", FlagshipStore, new Price(149.99, "USD"));

export const RecentOrder = new Order("1234", Util.fromIsoDate("2018-09-01T00:00Z"), FlagshipStore, [Makeover]);

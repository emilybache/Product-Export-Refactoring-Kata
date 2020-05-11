from dateutil.parser import parse

from ..model_objects import Product, Price, Store, StoreEvent, Order


CherryBloom = Product("Cherry Bloom", "LIPSTICK01", 30, Price(14.99, "USD"))
RosePetal = Product("Rose Petal", "LIPSTICK02", 30, Price(14.99, "USD"))
BlusherBrush = Product("Blusher Brush", "TOOL01", 50, Price(24.99, "USD"))
EyelashCurler = Product("Eyelash curler", "TOOL01", 100, Price(19.99, "USD"))
WildRose = Product("Wild Rose", "PURFUME01", 200, Price(34.99, "USD"))
CocoaButter = Product("Cocoa Butter", "SKIN_CREAM01", 250, Price(10.99, "USD"))

FlagshipStore = Store("Nordstan", "4189", [CherryBloom])

# Store events add themselves to the stocked items at their store
Masterclass = StoreEvent("Eyeshadow Masterclass", "EVENT01", FlagshipStore, Price(119.99, "USD"))
Makeover = StoreEvent("Makeover", FlagshipStore, "EVENT02", Price(149.99, "USD"))

RecentOrder = Order("1234", parse("2018-09-01T00:00Z"), FlagshipStore, [Makeover])
OldOrder = Order("1235", parse("2017-09-01T00:00Z"), FlagshipStore, [CherryBloom])

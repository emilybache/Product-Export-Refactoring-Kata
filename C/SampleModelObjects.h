#include "Order.h"
#include "Product.h"
#include "Store.h"

/*
 * Some sample product data that you could use in your tests.
 */
extern struct Product* CherryBloom;
extern struct Product* RosePetal;
extern struct Product* BlusherBrush;
extern struct Product* EyelashCurler;
extern struct Product* WildRose;
extern struct Product* CocoaButter;

extern struct Store* FlagshipStore;

/* Store events add themselves to the stocked items at their store */
extern struct Product* Masterclass;
extern struct Product* Makeover;

extern struct Order* RecentOrder;
extern struct Order* OldOrder;

extern void make_sample_model_objects(void);

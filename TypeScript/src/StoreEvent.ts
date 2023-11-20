import { Product } from "./Product";
import { Store } from "./Store";
import { Price } from "./Price";

/**
 * Ticket to In-store event, eg makeover, eyeshadow masterclass
 * or beauty product launch evening reception
 */
export class StoreEvent extends Product {

    private location: Store;

    constructor(name: string, id: string, location: Store, price: Price) {
        super(name, id, 0, price);

        this.location = location;
        this.location.addStoreEvent(this);
    }

    setLocation(store: Store) {
        this.location = store;
        this.location.addStoreEvent(this);
    }

    toString(): string {
        return "StoreEvent{" + this.name + "}";
    }

    isEvent(): boolean {
        return true;
    }

}

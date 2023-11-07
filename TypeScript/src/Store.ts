import { Product } from "./Product";
import { StoreEvent } from "./StoreEvent";

/**
 * Represents a physical Store where you can go and buy
 * products and attend events.
 */
export class Store {

    private readonly itemsInStock: Map<string, Product>;
    private readonly name: string;
    private readonly id: string;

    constructor(name: string, id: string, products: Product[]) {
        this.itemsInStock = new Map<string, Product>();
        this.name = name;
        this.id = id;
        this.addStockedItems(...products);
    }

    addStockedItems(...items: Product[]) {
        for (const item of items) {
            this.itemsInStock.set(item.getName(), item);
        }
    }

    addStoreEvent(storeEvent: StoreEvent) {
        this.itemsInStock.set(storeEvent.getName(), storeEvent);
    }

    hasItem(item: Product): boolean {
        return this.itemsInStock.has(item.getName());
    }

    getItem(name: string): Product | undefined {
        return this.itemsInStock.get(name);
    }

    getId(): string {
        return this.id;
    }

    toString(): string {
        return "Store{" + this.name + "}";
    }

    saveToDatabase(): void {
        throw new Error("missing from this exercise - shouldn't be called from a unit test");
    }

    getName(): string {
        return this.name;
    }

    getStock(): Product[] {
        return Array.from(this.itemsInStock.values());
    }

}

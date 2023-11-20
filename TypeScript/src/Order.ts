import { Product } from "./Product";
import { Store } from "./Store";

export class Order {

    private readonly id: string;
    private readonly date: Date;
    private products: Product[];
    private store: Store;

    constructor(id: string, date: Date, store: Store, products: Product[]) {
        this.id = id;
        this.date = date;
        this.products = [];
        this.store = store;
        this.addProducts(...products);
    }

    totalDollars(): number {
        return this.products.reduce((total, product) => total + product.getPrice().getAmountInCurrency("USD"), 0);
    }

    toString(): string {
        return "Order{" + this.id + "}";
    }

    saveToDatabase(): void {
        throw new Error("missing from this exercise - shouldn't be called from a unit test");
    }

    getId(): string {
        return this.id;
    }

    getProducts(): Product[] {
        return this.products;
    }

    getDate(): Date {
        return this.date;
    }

    addProducts(...products: Product[]) {
        this.products.push(...products);
    }

    getStore(): Store {
        return this.store;
    }

}

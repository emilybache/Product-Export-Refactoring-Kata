import { Price } from "./Price";

export class Product {

    protected readonly name: string;
    protected readonly id: string;
    protected readonly weight: number;
    protected readonly price: Price;

    constructor(name: string, id: string, weight: number, price: Price) {
        this.name = name;
        this.id = id;
        this.weight = weight;
        this.price = price;
    }

    saveToDatabase(): void {
        throw new Error("missing from this exercise - shouldn't be called from a unit test");
    }

    getName(): string {
        return this.name;
    }

    getId(): string {
        return this.id;
    }

    toString(): string {
        return "Product{" + this.name + "}";
    }

    getWeight(): number {
        return this.weight;
    }

    getPrice(): Price {
        return this.price;
    }

    isEvent(): boolean {
        return false;
    }

}

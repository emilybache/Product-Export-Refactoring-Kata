export class Price {

    private readonly amount: number;
    private readonly currencyCode: string;

    constructor(amount: number, currencyCode: string) {
        this.amount = amount;
        this.currencyCode = currencyCode;
    }

    toString(): string {
        return "Price{" + this.amount + "}";
    }

    getCurrency(): string {
        return this.currencyCode;
    }

    getAmount(): number {
        return this.amount;
    }

    getAmountInCurrency(currencyCode: string): number {
        if (this.currencyCode === currencyCode) {
            return this.amount;
        } else {
            throw new Error("shouldn't call this from a unit test, it will do a slow db lookup");
        }
    }

}

package codingdojo;

public class Price {

    private final double amount;
    private final String currencyCode;

    public Price(double amount, String currencyCode) {
        this.amount = amount;
        this.currencyCode = currencyCode;
    }

    @Override
    public String toString() {
        return "Price{" + amount + '}';
    }

    public String getCurrency() {
        return currencyCode;
    }

    public double getAmount() {
        return amount;
    }

    public double getAmountInCurrency(String currencyCode) {
        if (this.currencyCode.equals(currencyCode))
            return amount;
        else {
            throw new UnsupportedOperationException("shouldn't call this from a unit test, it will do a slow db lookup");
        }
    }
}

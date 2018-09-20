package codingdojo;

public class Product implements ModelObject {

    protected final String name;
    protected final String id;
    protected final long weight;
    protected final Price price;

    public Product(String name, String id, long weight, Price price) {
        this.name = name;
        this.id = id;
        this.weight = weight;
        this.price = price;
    }

    @Override
    public void saveToDatabase() {
        throw new UnsupportedOperationException("missing from this exercise - shouldn't be called from a unit test");
    }

    public String getName() {
        return name;
    }

    @Override
    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Product{" + name + '}';
    }

    public long getWeight() {
        return weight;
    }

    public Price getPrice() {
        return price;
    }

    public boolean isEvent() {
        return false;
    }
}

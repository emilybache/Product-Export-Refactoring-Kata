package codingdojo;

public class Product {

    protected final String name;
    protected final String id;
    protected final int weight;
    protected final Price price;

    public Product(String name, String id, int weight, Price price) {
        this.name = name;
        this.id = id;
        this.weight = weight;
        this.price = price;
    }

    public void saveToDatabase() {
        throw new UnsupportedOperationException("missing from this exercise - shouldn't be called from a unit test");
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Product{" + name + '}';
    }

    public int getWeight() {
        return weight;
    }

    public Price getPrice() {
        return price;
    }

    public boolean isEvent() {
        return false;
    }
}

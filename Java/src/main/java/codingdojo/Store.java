package codingdojo;

import java.util.HashMap;
import java.util.Map;

/**
 * Represents a physical Store where you can go and buy
 * products and attend events.
 */
public class Store implements ModelObject {

    private final Map<String, Product> itemsInStock = new HashMap<>();
    private final String name;
    private final String id;

    public Store(String name, String id) {
        this.name = name;
        this.id = id;
    }
    public void addStockedItems(Product... items) {
        for (Product item: items) {
            this.itemsInStock.put(item.getName(), item);
        }
    }

    public void addStoreEvent(StoreEvent storeEvent) {
        this.itemsInStock.put(storeEvent.getName(), storeEvent);
    }

    public void removeStockedItems(Product... items) {
        for (Product item: items) {
            this.itemsInStock.remove(item.getName());
        }
    }

    public boolean hasItem(Product item) {
        return itemsInStock.containsKey(item.getName());
    }

    public Product getItem(String name) {
        return itemsInStock.get(name);
    }

    @Override
    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Store{" +
                "id='" + id + '\'' +
                ", itemsInStock=" + itemsInStock +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public void saveToDatabase() {
        throw new UnsupportedOperationException("missing from this exercise - shouldn't be called from a unit test");
    }

}

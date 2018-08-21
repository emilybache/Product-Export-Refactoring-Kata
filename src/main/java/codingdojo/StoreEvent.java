package codingdojo;

/**
 * Ticket to In-store event, eg makeover, eyeshadow masterclass
 * or beauty product launch evening reception
 */
public class StoreEvent extends Product {
    protected Store location;

    public StoreEvent(String name, String id, Store location, Price price) {
        super(name, id, 0, price);
        setLocation(location);
    }

    public void setLocation(Store locationStore) {
        this.location = locationStore;
        location.addStoreEvent(this);
    }



    @Override
    public String toString() {
        return "StoreEvent{" +
                "id='" + id + '\'' +
                ", location=" + location +
                ", name='" + name + '\'' +
                ", price=" + price +
                '}';
    }

    @Override
    public boolean isEvent() {
        return true;
    }
}

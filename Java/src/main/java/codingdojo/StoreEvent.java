package codingdojo;

/**
 * Ticket to In-store event, eg makeover, eyeshadow masterclass
 * or beauty product launch evening reception
 */
public class StoreEvent extends Product {
    
    private Store location;

    public StoreEvent(String name, String id, Store location, Price price) {
        super(name, id, 0, price);
        setLocation(location);
    }

    public void setLocation(Store store) {
        location = store;
        location.addStoreEvent(this);
    }

    @Override
    public String toString() {
        return "StoreEvent{" + name + '}';
    }

    @Override
    public boolean isEvent() {
        return true;
    }
}

public class EventTransaction extends Entry {

    private String eventName;
    private String sellName;
    private double price;
    private int numTickets;

    /**
     * 
     * @param type
     * @param eventName
     * @param sellName
     * @param price
     * @param numTickets
     */
    public EventTransaction(final int type, final String eventName, final String sellName, final double price, final int numTickets) {
        super(type);
        throw new UnsupportedOperationException();
    }

    public String getSellName() {
        return this.sellName;
    }

    /**
     * 
     * @param sellName
     */
    public void setSellName(final String sellName) {
        this.sellName = sellName;
    }

    public String getEventName() {
        return this.eventName;
    }

    /**
     * 
     * @param eventName
     */
    public void setEventName(final String eventName) {
        this.eventName = eventName;
    }

    public double getPrice() {
        return this.price;
    }

    /**
     * 
     * @param price
     */
    public void setPrice(final double price) {
        this.price = price;
    }

    public int getNumTickets() {
        return this.numTickets;
    }

    /**
     * 
     * @param numTickets
     */
    public void setNumTickets(final int numTickets) {
        this.numTickets = numTickets;
    }
}
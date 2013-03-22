 /**
 *
 * This class covers the basic transactions for the sale of events 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

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
     * Constructor sets the initial conditions for the transaction
     * 
     */
    public EventTransaction(final int type, final String eventName, final String sellName, final double price, final int numTickets) {
        super(type);
        this.eventName = eventName;
        this.sellName = sellName;
        this.price = price;
        this.numTickets = numTickets;
    }

    /**
     *
     * @return sellName
     * Accessor method responsible for returning the event seller's name
     */
    public String getSellName() {
        return this.sellName;
    }

    /**
     * 
     * @param sellName
     * Mutator method responsible for setting the event seller's name
     */
    public void setSellName(final String sellName) {
        this.sellName = sellName;
    }
    /**
     * 
     * @return eventName
     * Accessor method responsible for returnig the event name 
     */
    public String getEventName() {
        return this.eventName;
    }

    /**
     * 
     * @param eventName
     * Mutator method responsible for setting the event name 
     */
    public void setEventName(final String eventName) {
        this.eventName = eventName;
    }
    /**
     * 
     * @return numTickets
     * accessor method responsible for returning the price per ticket of an event
     */
    public double getPrice() {
        return this.price;
    }

    /**
     * 
     * @param price
     * Mutator method for setting the ticket price of an event
     */
    public void setPrice(final double price) {
        this.price = price;
    }
    /**
     * 
     * @return numTickets
     * accessor method responsible for returning the available tickets for an event
     */
    public int getNumTickets() {
        return this.numTickets;
    }

    /**
     * 
     * @param numTickets
     * Mutator method responsible for setting the number of tickets that an event has
     */
    public void setNumTickets(final int numTickets) {
        this.numTickets = numTickets;
    }
}
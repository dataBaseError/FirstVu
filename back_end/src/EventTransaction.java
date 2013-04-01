/**
* This class covers the basic transactions for the sale of events.
* 
* @author Ryan Crawford
* @author Khalil Fazal
* @author Joseph Heron
* @author Carly Marshall
*/

public class EventTransaction extends Entry {

    /**
     * Sell transactions are noted in the daily transaction file by the number 3.
     */
    public static final int SELL = 3;

    /**
     * Buy transactions are noted in the daily transaction file by the number 4.
     */
    public static final int BUY = 4;

    /**
     * The name of the event a ticket is for in a transaction
     */
    private final String eventName;

    /**
     * The username of the ticket vendor
     */
    private final String sellName;

    /**
     * The price of each ticket
     */
    private final double price;

    /**
     * The number of tickets being sold
     */
    private int numTickets;

    /**
     * Constructor sets the initial conditions for the transaction.
     * 
     * @param type the type of transaction, could be either BUY or SELL
     * @param eventName the name of the event a ticket is for in a transaction
     * @param sellName the username of the ticket vendor
     * @param price the price of each ticket
     * @param numTickets the number of tickets being sold
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
     * Accessor method responsible for returning the event seller's name.
     * 
     * @return sellName The name of the seller for the event.
     */
    public String getSellName() {
        return this.sellName;
    }

    /**
     * Accessor method responsible for returning the event name.
     * 
     * @return eventName The name of the event the tickets are for.
     */
    public String getEventName() {
        return this.eventName;
    }

    /**
     * Accessor method responsible for returning the price per ticket of an
     * event.
     * 
     * @return price The price per ticket. 
     */
    public double getPrice() {
        return this.price;
    }

    /**
     * Accessor method responsible for returning the available tickets for an
     * event.
     * 
     * @return numTickets The number of tickets for sale for the event.
     */
    public int getNumTickets() {
        return this.numTickets;
    }
}
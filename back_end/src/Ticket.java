/**
 * Class for holding information involving tickets for sale in the program. 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Ticket {

    private String event;
    private String username;
    private int ticketNumber;
    private double cost;

    public static final int MAX_EVENT_LENGTH = 19;

    public static final int MAX_TICKET_LENGTH = 3;

    /**
     * Constructor for making a ticket listing for an event.
     * @param event The name of the event.
     * @param username The username of the seller.
     * @param ticketNumber The number of tickets available.
     * @param cost The cost per ticket.
     */
    public Ticket(final String event, final String username, final int ticketNumber, final double cost) {
        this.event = event;
        this.username = username;
        this.ticketNumber = ticketNumber;
        this.cost = cost;
    }

    /**
     * Accessor method for getting the event name.
     * @return The name of the event.
     */
    public String getEvent() {
        return this.event;
    }

    /**
     * Mutator method for the event name.
     * @param event The name of the event.
     */
    public void setEvent(final String event) {
        this.event = event;
    }

    /**
     * Accessor method for getting the seller’s username.
     * @return The username of the seller.
     */
    public String getUsername() {
        return this.username;
    }

    /**
     * Mutator method for the seller’s username.
     * @param username The username of the seller.
     */
    public void setUsername(final String username) {
        this.username = username;
    }

    /**
     * Accessor method for getting the number of tickets available for the show.
     * @return The number of available tickets.
     */
    public int getTicketNumber() {
        return this.ticketNumber;
    }

    /**
     * Mutator method for number of remaining tickets for sale.
     * @param ticketNumber The number of available tickets.
     */
    public void setTicketNumber(final int ticketNumber) {
        this.ticketNumber = ticketNumber;
    }

    /**
     * Decrement the number of tickets for sale for the event.
     * @param ticketNumber The number of available tickets.
     */
    public void decreaseTicketNumber(final int ticketNumber) {
        this.ticketNumber -= ticketNumber;
    }

    /**
     * Accessor method for getting the cost of the event per ticket.
     * @return Cost per ticket.
     */
    public double getCost() {
        return this.cost;
    }

    /**
     * Mutator method for the cost per ticket for the event.
     * @param cost Cost per ticket.
     */
    public void setCost(final double cost) {
        this.cost = cost;
    }

    /**
     * Get the ticket information as a line of the Available Tickets file. This
     * will be used to store the update tickets into the new Available Tickets
     * file. 
     * @return The ticket's information formatted for the Available Tickets
     * file.
     */
    public String getTicketEntry() {
        return this.event + Utility.createLine(' ', MAX_EVENT_LENGTH -
                this.event.length()) + " " + this.username
                + Utility.createLine(' ', Account.MAX_USERNAME_LENGTH -
                        this.username.length()) + " " +
                String.format("%03.0f", (double) this.ticketNumber) + " " +
                String.format("%03.2f", this.cost);
    }

}
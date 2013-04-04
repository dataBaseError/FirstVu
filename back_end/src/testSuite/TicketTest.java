package testSuite;

import junit.framework.TestCase;
import main.Ticket;

/**
 * Tests the functionality of the Ticket class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class TicketTest extends TestCase {

    /**
     * A sample ticket entry that will be tested
     */
    private Ticket ticket;

    /**
     * @see junit.framework.TestCase#setUp()
     */
    @Override
    public void setUp() {
        this.ticket = new Ticket("event", "seller", 1, 1.0);
    }

    /**
     * Tests the ticket's type
     */
    public void testGetType() {
        assertSame(this.ticket.getEvent(), "event");
    }

    /**
     * Tests the ticket's seller's username
     */
    public void testGetUsernames() {
        assertSame(this.ticket.getUsername(), "seller");
    }

    /**
     * Tests the quantity of tickets for the same event
     */
    public void testGetTicketNumber() {
        assertTrue(this.ticket.getTicketNumber() == 1);
    }

    /**
     * Tests the way the ticket quantity increases
     */
    public void testDecreaseTicketNumber() {
        this.ticket.decreaseTicketNumber(1);

        assertTrue(this.ticket.getTicketNumber() == 0);
    }

    /**
     * Tests the ticket's cost
     */
    public void testGetCost() {
        assertTrue(this.ticket.getCost() == 1.0);
    }

    /**
     * Tests the format of the account's entry in the Tickets file
     */
    public void testGetTicketEntry() {
        assertTrue(this.ticket.getTicketEntry().equals("event               seller          001 001.00"));
    }
}

package testSuite;

import main.Ticket;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the functionality of the Ticket class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class TicketTest {

    /**
     * A sample ticket entry that will be tested
     */
    private Ticket ticket;

    /**
     * Set up a test ticket entry
     */
    @Before
    public void setUp() {
        this.ticket = new Ticket("event", "seller", 1, 1.00);
    }

    /**
     * Tests the ticket's type
     */
    @Test
    public void testGetType() {
        Assert.assertEquals("event", this.ticket.getEvent());
    }

    /**
     * Tests the ticket's seller's username
     */
    @Test
    public void testGetUsernames() {
        Assert.assertEquals("seller", this.ticket.getUsername());
    }

    /**
     * Tests the quantity of tickets for the same event
     */
    @Test
    public void testGetTicketNumber() {
        Assert.assertEquals(1, this.ticket.getTicketNumber());
    }

    /**
     * Tests the way the ticket quantity increases
     */
    @Test
    public void testDecreaseTicketNumber() {
        this.ticket.decreaseTicketNumber(1);

        Assert.assertEquals(0, this.ticket.getTicketNumber());
    }

    /**
     * Tests the ticket's cost
     */
    @Test
    public void testGetCost() {
        Assert.assertEquals(1.00, this.ticket.getCost(), 0.01);
    }

    /**
     * Tests the format of the account's entry in the Tickets file
     */
    @Test
    public void testGetTicketEntry() {
        Assert.assertEquals("event               seller          001 001.00", this.ticket.getTicketEntry());
    }
}

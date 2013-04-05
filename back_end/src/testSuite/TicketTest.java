package testSuite;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Ticket;

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
        this.ticket = new Ticket("event", "seller", 1, 1.0);
    }

    /**
     * Tests the ticket's type
     */
    @Test
    public void testGetType() {
        assertSame(this.ticket.getEvent(), "event");
    }

    /**
     * Tests the ticket's seller's username
     */
    @Test
    public void testGetUsernames() {
        assertSame(this.ticket.getUsername(), "seller");
    }

    /**
     * Tests the quantity of tickets for the same event
     */
    @Test
    public void testGetTicketNumber() {
        assertEquals(this.ticket.getTicketNumber(), 1);
    }

    /**
     * Tests the way the ticket quantity increases
     */
    @Test
    public void testDecreaseTicketNumber() {
        this.ticket.decreaseTicketNumber(1);

        assertEquals(this.ticket.getTicketNumber(), 0);
    }

    /**
     * Tests the ticket's cost
     */
    @Test
    public void testGetCost() {
        assertEquals(this.ticket.getCost(), 1.0, 0.1);
    }

    /**
     * Tests the format of the account's entry in the Tickets file
     */
    @Test
    public void testGetTicketEntry() {
        assertTrue(this.ticket.getTicketEntry().equals("event               seller          001 001.00"));
    }
}

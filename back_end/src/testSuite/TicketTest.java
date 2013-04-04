package testSuite;

import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Ticket;

import org.junit.Test;

public class TicketTest {

    private final Ticket ticket;

    public TicketTest() {
        this.ticket = new Ticket("event", "seller", 1, 1.0);
    }

    @Test
    public void getType() {
        assertSame(this.ticket.getEvent(), "event");
    }

    @Test
    public void getUsernames() {
        assertSame(this.ticket.getUsername(), "seller");
    }

    @Test
    public void getTicketNumber() {
        assertTrue(this.ticket.getTicketNumber() == 1);
    }

    @Test
    public void decreaseTicketNumber() {
        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
        testTicket.decreaseTicketNumber(1);

        assertTrue(testTicket.getTicketNumber() == 0);
    }

    @Test
    public void getCost() {
        assertTrue(this.ticket.getCost() == 1.0);
    }

    @Test
    public void getTicketEntry() {
        assertTrue(this.ticket.getTicketEntry().equals("event               seller          001 001.00"));
    }
}

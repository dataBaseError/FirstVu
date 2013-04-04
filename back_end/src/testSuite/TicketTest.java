package testSuite;

import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Ticket;

import org.junit.Test;

public class TicketTest {

    @Test
    public void testGetType() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
        assertSame(testTicket.getEvent(), "event");
    }

    @Test
    public void testGetUsernames() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
        assertSame(testTicket.getUsername(), "seller");
    }

    @Test
    public void testGetTicketNumber() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
        assertTrue(testTicket.getTicketNumber() == 1);
    }

    @Test
    public void testDecreaseTicketNumber() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);
        testTicket.decreaseTicketNumber(1);

        assertTrue(testTicket.getTicketNumber() == 0);
    }

    @Test
    public void testGetCost() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);

        assertTrue(testTicket.getCost() == 1.0);
    }

    @Test
    public void testGetTicketEntry() {

        final Ticket testTicket = new Ticket("event", "seller", 1, 1.0);

        System.out.println(testTicket.getTicketEntry() + "\n" + "event               seller          001 001.00");
        assertTrue(testTicket.getTicketEntry().equals("event               seller          001 001.00"));
    }
}

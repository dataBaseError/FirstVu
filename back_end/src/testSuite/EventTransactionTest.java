package testSuite;

import main.EventTransaction;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the {@link EventTransaction} class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class EventTransactionTest {

    /**
     * A test event transaction to test with
     */
    private EventTransaction transactionTest;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.transactionTest = new EventTransaction(EventTransaction.BUY, "event", "seller", 1.00, 1);
    }

    /**
     * Tests to see if the username of the user who is selling a ticket is accessible
     */
    @Test
    public void getSellName() {
        Assert.assertEquals("seller", this.transactionTest.getSellName());
    }

    /**
     * Tests to see if the event name of the event involved in the transaction is accessible
     */
    @Test
    public void getEventName() {
        Assert.assertEquals("event", this.transactionTest.getEventName());
    }

    /**
     * Tests to see if the price of the event involved in the transaction is accessible
     */
    @Test
    public void getPrice() {
        Assert.assertEquals(1.00, this.transactionTest.getPrice(), 0.01);
    }

    /**
     * Tests to see if the amount of tickets being sold for an event by a seller is accessible
     */
    @Test
    public void getNumTickets() {
        Assert.assertEquals(1, this.transactionTest.getNumTickets());
    }

    /**
     * Tests to see if the entry type is valid
     */
    @Test
    public void getTransactionType() {
        Assert.assertEquals(EventTransaction.BUY, this.transactionTest.getTransactionType());
    }

}

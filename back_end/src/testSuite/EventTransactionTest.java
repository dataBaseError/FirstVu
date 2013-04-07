package testSuite;

import main.EventTransaction;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class EventTransactionTest {

    private EventTransaction EventTransactionTest;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.EventTransactionTest = new EventTransaction(EventTransaction.BUY, "event", "seller", 1.00, 1);
    }

    @Test
    public void getSellName() {
        Assert.assertEquals("seller", this.EventTransactionTest.getSellName());
    }

    @Test
    public void getEventName() {
        Assert.assertEquals("event", this.EventTransactionTest.getEventName());
    }

    @Test
    public void getPrice() {
        Assert.assertEquals(1.00, this.EventTransactionTest.getPrice(), 0.01);
    }

    @Test
    public void getNumTickets() {
        Assert.assertEquals(1, this.EventTransactionTest.getNumTickets());
    }

    @Test
    public void getTransactionType() {
        Assert.assertEquals(EventTransaction.BUY, this.EventTransactionTest.getTransactionType());
    }

}

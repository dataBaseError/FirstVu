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
        this.EventTransactionTest = new EventTransaction(EventTransaction.BUY, "event", "seller", 1.0, 1);
    }

    @Test
    public void getSellName() {
        Assert.assertSame(this.EventTransactionTest.getSellName(), "seller");
    }

    @Test
    public void getEventName() {
        Assert.assertSame(this.EventTransactionTest.getEventName(), "event");
    }

    @Test
    public void getPrice() {
        Assert.assertEquals(this.EventTransactionTest.getPrice(), 1.0, 0.1);
    }

    @Test
    public void getNumTickets() {
        Assert.assertEquals(this.EventTransactionTest.getNumTickets(), 1);
    }

    @Test
    public void getTransactionType() {
        Assert.assertEquals(this.EventTransactionTest.getTransactionType(), EventTransaction.BUY);
    }

}

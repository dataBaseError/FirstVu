package testSuite;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertSame;
import main.Refund;

import org.junit.Before;
import org.junit.Test;

/**
 * Tests the functionality of how refunds are handled
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class RefundTest {

    /**
     * A sample refund transaction which will be tested
     */
    private Refund refund;

    /**
     * Set up a test refund transaction
     */
    @Before
    public void setUp() {
        this.refund = new Refund(Refund.REFUND, "buyer", "seller", 1.0);
    }

    /**
     * Tests the debtor of a refund
     */
    @Test
    public void getBuyName() {
        assertSame(this.refund.getBuyName(), "buyer");
    }

    /**
     * Tests the creditor of a refund
     */
    @Test
    public void getSellName() {
        assertSame(this.refund.getSellName(), "seller");
    }

    /**
     * Tests the amount refunded
     */
    @Test
    public void getCredit() {
        assertEquals(this.refund.getCredit(), 1.0, 0.1);
    }

    /**
     * Tests the transaction type
     */
    @Test
    public void getTransactionType() {
        assertEquals(this.refund.getTransactionType(), Refund.REFUND);
    }
}
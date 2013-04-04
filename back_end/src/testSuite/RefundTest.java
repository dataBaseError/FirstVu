package testSuite;

import junit.framework.TestCase;
import main.Refund;

/**
 * Tests the functionality of how refunds are handled
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class RefundTest extends TestCase {

    /**
     * A sample refund transaction which will be tested
     */
    private Refund refund;

    /**
     * @see junit.framework.TestCase#setUp()
     */
    @Override
    public void setUp() {
        this.refund = new Refund(Refund.REFUND, "buyer", "seller", 1.0);
    }

    /**
     * Tests the debtor of a refund
     */
    public void testGetBuyName() {
        assertSame(this.refund.getBuyName(), "buyer");
    }

    /**
     * Tests the creditor of a refund
     */
    public void testGetSellName() {
        assertSame(this.refund.getSellName(), "seller");
    }
}

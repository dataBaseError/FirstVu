package testSuite;

import static org.junit.Assert.assertSame;
import main.Refund;

import org.junit.Test;

public class RefundTest {

    private final Refund refund;

    public RefundTest() {
        this.refund = new Refund(Refund.REFUND, "buyer", "seller", 1.0);
    }

    @Test
    public void getBuyName() {
        assertSame(this.refund.getBuyName(), "buyer");
    }

    @Test
    public void getSellName() {
        assertSame(this.refund.getSellName(), "seller");
    }
}

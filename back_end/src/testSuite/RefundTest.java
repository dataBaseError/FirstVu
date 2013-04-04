package test;

import static org.junit.Assert.*;
import main.Refund;

import org.junit.Test;

public class RefundTest {

	/*@Test
	public void test() {
		testGetBuyName();
		testGetSellName();
	}*/

	@Test
	public void testGetBuyName()
	{
		Refund testRefund = new Refund(Refund.REFUND, "buyer", "seller", 1.0);
		
		assertSame(testRefund.getBuyName(), "buyer");
	}
	
	@Test
	public void testGetSellName()
	{
		Refund testRefund = new Refund(Refund.REFUND, "buyer", "seller", 1.0);
		
		assertSame(testRefund.getSellName(), "seller");
	}	
}

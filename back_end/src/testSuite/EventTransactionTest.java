package testSuite;

import static org.junit.Assert.*;

import main.AuxiliaryTransaction;
import main.EventTransaction;

import org.junit.Before;
import org.junit.Test;

public class EventTransactionTest {

	private EventTransaction EventTransactionTest;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.EventTransactionTest = new EventTransaction(EventTransaction.BUY,
        		"event", "seller", 1.0, 1);
    }
    
	@Test
	public void getSellName() {
		assertSame(EventTransactionTest.getSellName(), "seller");
	}

	@Test
	public void getEventName() {
		assertSame(EventTransactionTest.getEventName(), "event");
	}

	@Test
	public void getPrice() {
		assertEquals(EventTransactionTest.getPrice(), 1.0, 0.1);
	}

	@Test
	public void getNumTickets() {
		assertEquals(EventTransactionTest.getNumTickets(), 1);
	}

	@Test
	public void getTransactionType() {
		assertEquals(EventTransactionTest.getTransactionType(),
				EventTransaction.BUY);
	}

}

package testSuite;

import static org.junit.Assert.*;

import main.Account;
import main.AuxiliaryTransaction;

import org.junit.Before;
import org.junit.Test;

public class AuxiliaryTransactionTest {

	
    private AuxiliaryTransaction AuxiliaryTransactionTest;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.AuxiliaryTransactionTest = new AuxiliaryTransaction(
        		AuxiliaryTransaction.CREATE, "test", 0.0, Account.ADMIN);
    }

	@Test
	public void testGetUsername() {
		assertSame(this.AuxiliaryTransactionTest.getUsername(), "test");
	}

	@Test
	public void testGetCredit() {
		assertEquals(this.AuxiliaryTransactionTest.getCredit(), 0.0, 0.1);
	}

	@Test
	public void testGetAccountType() {
		assertSame(this.AuxiliaryTransactionTest.getAccountType(), Account.ADMIN);
	}

	@Test
	public void testGetTransactionType() {
		assertSame(this.AuxiliaryTransactionTest.getTransactionType(), AuxiliaryTransaction.CREATE);
	}

}

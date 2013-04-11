package test;

import static org.junit.Assert.*;

import main.Account;
import main.AuxiliaryTransaction;

import org.junit.Test;

public class AuxiliaryTransactionTest {

	@Test
	public void test() {
		testGetUsername();
	}
	
	public void testGetUsername() {
		AuxiliaryTransaction testTransaction = new AuxiliaryTransaction(
				AuxiliaryTransaction.CREATE, "test", 0.0, Account.ADMIN);
		assertSame(testTransaction.getUsername(), "test");
	}

	public void testGetCredit() {
		fail("Not yet implemented");
	}

	public void testGetAccountType() {
		fail("Not yet implemented");
	}
	
	public void testGetTransactionType() {
		fail("Not yet implemented");
	}

}

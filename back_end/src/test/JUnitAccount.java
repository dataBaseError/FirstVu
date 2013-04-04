package test;

import static org.junit.Assert.*;

import main.Account;

import org.junit.Test;


public class JUnitAccount {

	@Test
	public void test() {
		
		testGetType();
		testGetBalance();
		testIncreaseBalance();
		testDecreaseBalance();
		testGetUsername();
		testGetAccountEntry();
	}
	
	public void testGetType() {
		
		Account testAccount = new Account("test", Account.ADMIN, 0.0);
		assertSame(testAccount.getType(), Account.ADMIN);
	}

	public void testGetBalance() {
		
		Account testAccount = new Account("test", Account.ADMIN, 0.0);
		assertTrue(testAccount.getBalance() == 0.0);
	}
	
	public void testIncreaseBalance() {
		
		Account testAccount = new Account("test", Account.ADMIN, 0.0);
		testAccount.increaseBalance(1.0);

		assertTrue(testAccount.getBalance() == 1.0);
	}
	
	public void testDecreaseBalance() {
		
		Account testAccount = new Account("test", Account.ADMIN, 1.0);
		testAccount.decreaseBalance(1.0);

		assertTrue(testAccount.getBalance() == 0.0);
	}
	
	public void testGetUsername() {
		
		Account testAccount = new Account("test", Account.ADMIN, 0.0);

		assertSame(testAccount.getUsername(), "test");
	}
	
	public void testGetAccountEntry() {
		
		Account testAccount = new Account("test", Account.ADMIN, 0.0);
		
		assertTrue(testAccount.getAccountEntry().equals("test            AA 000000.00"));
	}
}

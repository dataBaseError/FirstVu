package testSuite;

import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Account;

import org.junit.Test;

public class AccountTest {

    @Test
    public void testGetType() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        assertSame(testAccount.getType(), Account.ADMIN);
    }

    @Test
    public void testGetBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        assertTrue(testAccount.getBalance() == 0.0);
    }

    @Test
    public void testIncreaseBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        testAccount.increaseBalance(1.0);

        assertTrue(testAccount.getBalance() == 1.0);
    }

    @Test
    public void testDecreaseBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 1.0);
        testAccount.decreaseBalance(1.0);

        assertTrue(testAccount.getBalance() == 0.0);
    }

    @Test
    public void testGetUsername() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);

        assertSame(testAccount.getUsername(), "test");
    }

    @Test
    public void testGetAccountEntry() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);

        assertTrue(testAccount.getAccountEntry().equals("test            AA 000000.00"));
    }
}

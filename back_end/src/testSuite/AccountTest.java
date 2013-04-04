package testSuite;

import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Account;

import org.junit.Test;

public class AccountTest {

    @Test
    public void getType() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        assertSame(testAccount.getType(), Account.ADMIN);
    }

    @Test
    public void getBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        assertTrue(testAccount.getBalance() == 0.0);
    }

    @Test
    public void increaseBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);
        testAccount.increaseBalance(1.0);

        assertTrue(testAccount.getBalance() == 1.0);
    }

    @Test
    public void decreaseBalance() {

        final Account testAccount = new Account("test", Account.ADMIN, 1.0);
        testAccount.decreaseBalance(1.0);

        assertTrue(testAccount.getBalance() == 0.0);
    }

    @Test
    public void getUsername() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);

        assertSame(testAccount.getUsername(), "test");
    }

    @Test
    public void getAccountEntry() {

        final Account testAccount = new Account("test", Account.ADMIN, 0.0);

        assertTrue(testAccount.getAccountEntry().equals("test            AA 000000.00"));
    }
}

package testSuite;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import main.Account;

import org.junit.Before;
import org.junit.Test;

/**
 * Tests the functionality of the Account class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class AccountTest {

    /**
     * A sample account that will be tested
     */
    private Account adminAccount;

    /**
     * Set up the test account
     */
    @Before
    public void setUp() {
        this.adminAccount = new Account("test", Account.ADMIN, 1.0);
    }

    /**
     * Tests the account's type
     */
    @Test
    public void getType() {
        assertSame(this.adminAccount.getType(), Account.ADMIN);
    }

    /**
     * Tests the account's balance
     */
    @Test
    public void getBalance() {
        assertEquals(this.adminAccount.getBalance(), 1.0, 0.1);
    }

    /**
     * Tests the way the account's balance increases
     */
    @Test
    public void increaseBalance() {
        this.adminAccount.increaseBalance(1.0);

        assertEquals(this.adminAccount.getBalance(), 2.0, 0.1);
    }

    /**
     * Test the way the account's balance decreases
     */
    @Test
    public void decreaseBalance() {
        this.adminAccount.decreaseBalance(1.0);

        assertEquals(this.adminAccount.getBalance(), 0.0, 0.1);
    }

    /**
     * Tests the account's username
     */
    @Test
    public void getUsername() {
        assertSame(this.adminAccount.getUsername(), "test");
    }

    /**
     * Tests the format of the account's entry in the User Accounts File
     */
    @Test
    public void getAccountEntry() {
        assertTrue(this.adminAccount.getAccountEntry().equals("test            AA 000001.00"));
    }
}

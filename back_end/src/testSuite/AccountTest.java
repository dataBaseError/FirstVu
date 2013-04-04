package testSuite;

import junit.framework.TestCase;
import main.Account;

/**
 * Tests the functionality of the Account class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class AccountTest extends TestCase {

    /**
     * A sample account that will be tested
     */
    private Account adminAccount;

    /**
     * @see junit.framework.TestCase#setUp()
     */
    @Override
    public void setUp() {
        this.adminAccount = new Account("test", Account.ADMIN, 1.0);
    }

    /**
     * Tests the account's type
     */
    public void testGetType() {
        assertSame(this.adminAccount.getType(), Account.ADMIN);
    }

    /**
     * Tests the account's balance
     */
    public void testGetBalance() {
        assertTrue(this.adminAccount.getBalance() == 1.0);
    }

    /**
     * Tests the way the account's balance increases
     */
    public void testIncreaseBalance() {
        this.adminAccount.increaseBalance(1.0);

        assertTrue(this.adminAccount.getBalance() == 2.0);
    }

    /**
     * Test the way the account's balance decreases
     */
    public void testDecreaseBalance() {
        this.adminAccount.decreaseBalance(1.0);

        assertTrue(this.adminAccount.getBalance() == 0.0);
    }

    /**
     * Tests the account's username
     */
    public void testGetUsername() {
        assertSame(this.adminAccount.getUsername(), "test");
    }

    /**
     * Tests the format of the account's entry in the User Accounts File
     */
    public void testGetAccountEntry() {
        assertTrue(this.adminAccount.getAccountEntry().equals("test            AA 000001.00"));
    }
}

package testSuite;

import main.Account;

import org.junit.Assert;
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
        this.adminAccount = new Account("test", Account.ADMIN, 1.00);
    }

    /**
     * Tests the account's type
     */
    @Test
    public void getType() {
        Assert.assertEquals(Account.ADMIN, this.adminAccount.getType());
    }

    /**
     * Tests the account's balance
     */
    @Test
    public void getBalance() {
        Assert.assertEquals(1.00, this.adminAccount.getBalance(), 0.01);
    }

    /** 
     * Tests the way the account's balance increases
     */
    @Test
    public void increaseBalance() {
        this.adminAccount.increaseBalance(1.0);

        Assert.assertEquals(2.00, this.adminAccount.getBalance(), 0.01);
    }

    /**
     * Test the way the account's balance decreases
     */
    @Test
    public void decreaseBalance() {
        this.adminAccount.decreaseBalance(1.0);

        Assert.assertEquals(0.00, this.adminAccount.getBalance(), 0.01);
    }

    /**
     * Tests the account's username
     */
    @Test
    public void getUsername() {
        Assert.assertEquals("test", this.adminAccount.getUsername());
    }

    /**
     * Tests the format of the account's entry in the User Accounts File
     */
    @Test
    public void getAccountEntry() {
        Assert.assertEquals("test            AA 000001.00", this.adminAccount.getAccountEntry());
    }
}

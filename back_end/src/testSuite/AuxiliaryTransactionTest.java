package testSuite;

import main.Account;
import main.AuxiliaryTransaction;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the {@link AuxiliaryTransaction} class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class AuxiliaryTransactionTest {

    /**
     * A test auxillary transaction to test with
     */
    private AuxiliaryTransaction transactionTest;

    /** 
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.transactionTest = new AuxiliaryTransaction(AuxiliaryTransaction.CREATE, "test", 0.00, Account.ADMIN);
    }

    /**
     * Test to see if the user who is involved in the transaction is accessible
     */
    @Test
    public void getUsername() {
        Assert.assertEquals("test", this.transactionTest.getUsername());
    }

    /**
     * Test to see if the amount of credit involved in the transaction is accessible
     */
    @Test
    public void getCredit() {
        Assert.assertEquals(0.00, this.transactionTest.getCredit(), 0.01);
    }

    /**
     * Tests to see if the account type involved in the transaction is accessible
     */
    @Test
    public void getAccountType() {
        Assert.assertEquals(Account.ADMIN, this.transactionTest.getAccountType());
    }

    /**
     * Tests to see if the entry type is valid
     */
    @Test
    public void getTransactionType() {
        Assert.assertEquals(AuxiliaryTransaction.CREATE, this.transactionTest.getTransactionType());
    }

}

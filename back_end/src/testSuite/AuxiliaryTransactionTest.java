package testSuite;

import main.Account;
import main.AuxiliaryTransaction;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class AuxiliaryTransactionTest {

    /**
     * A test auxillary transaction to test with
     */
    private AuxiliaryTransaction AuxiliaryTransactionTest;

    /** 
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.AuxiliaryTransactionTest = new AuxiliaryTransaction(AuxiliaryTransaction.CREATE, "test", 0.00, Account.ADMIN);
    }

    /**
     * Test to see if the user who is involved in the transaction is accessible
     */
    @Test
    public void getUsername() {
        Assert.assertEquals("test", this.AuxiliaryTransactionTest.getUsername());
    }

    /**
     * Test to see if the amount of credit involved in the transaction is accessible
     */
    @Test
    public void getCredit() {
        Assert.assertEquals(0.00, this.AuxiliaryTransactionTest.getCredit(), 0.01);
    }

    /**
     * Tests to see if the account type involved in the transaction is accessible
     */
    @Test
    public void getAccountType() {
        Assert.assertEquals(Account.ADMIN, this.AuxiliaryTransactionTest.getAccountType());
    }

    /**
     * Tests to see if the entry type is valid
     */
    @Test
    public void getTransactionType() {
        Assert.assertEquals(AuxiliaryTransaction.CREATE, this.AuxiliaryTransactionTest.getTransactionType());
    }

}

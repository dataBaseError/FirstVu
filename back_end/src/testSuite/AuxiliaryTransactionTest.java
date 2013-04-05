package testSuite;

import main.Account;
import main.AuxiliaryTransaction;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class AuxiliaryTransactionTest {

    private AuxiliaryTransaction AuxiliaryTransactionTest;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.AuxiliaryTransactionTest = new AuxiliaryTransaction(AuxiliaryTransaction.CREATE, "test", 0.0, Account.ADMIN);
    }

    @Test
    public void testGetUsername() {
        Assert.assertSame(this.AuxiliaryTransactionTest.getUsername(), "test");
    }

    @Test
    public void testGetCredit() {
        Assert.assertEquals(this.AuxiliaryTransactionTest.getCredit(), 0.0, 0.1);
    }

    @Test
    public void testGetAccountType() {
        Assert.assertSame(this.AuxiliaryTransactionTest.getAccountType(), Account.ADMIN);
    }

    @Test
    public void testGetTransactionType() {
        Assert.assertSame(this.AuxiliaryTransactionTest.getTransactionType(), AuxiliaryTransaction.CREATE);
    }

}

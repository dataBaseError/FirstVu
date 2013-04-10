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
        this.AuxiliaryTransactionTest = new AuxiliaryTransaction(AuxiliaryTransaction.CREATE, "test", 0.00, Account.ADMIN);
    }

    @Test
    public void getUsername() {
        Assert.assertEquals("test", this.AuxiliaryTransactionTest.getUsername());
    }

    @Test
    public void getCredit() {
        Assert.assertEquals(0.00, this.AuxiliaryTransactionTest.getCredit(), 0.01);
    }

    @Test
    public void getAccountType() {
        Assert.assertEquals(Account.ADMIN, this.AuxiliaryTransactionTest.getAccountType());
    }

    @Test
    public void getTransactionType() {
        Assert.assertEquals(AuxiliaryTransaction.CREATE, this.AuxiliaryTransactionTest.getTransactionType());
    }

}

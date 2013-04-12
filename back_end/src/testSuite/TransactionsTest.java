package testSuite;

import java.io.File;
import java.lang.reflect.Field;

import main.AuxiliaryTransaction;
import main.EventTransaction;
import main.Refund;
import main.Transactions;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the transactions class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class TransactionsTest {
    /**  
     * The location of the input files 
     */
    private static String filePrefix = "./tests/full_test/full";

    /**
     * The input Daily Transaction File.
     * To ensure proper coverage, the daily transaction file for testing must contain a variety of transactions.
     * 
     * It's good enough if it contains a refund, buy and logout transaction.
     */
    private static String dtf = filePrefix + ".etf";

    /**
     * The input ticket file
     */
    private static String ato = "./tests/global/glob_available_tickets.inp";

    /**
     * the input user accounts file
     */
    private static String uao = "./tests/global/glob_account.inp";

    /**
     * An etf containing an invalid buy transaction
     */
    private static String buyFaildtf = "./tests/buy/buy.etf";

    /**
     * An etf containing an invalid delete transaction
     */
    private static String deleteFaildtf = "./tests/delete/delete.etf";

    /**An etf containing an invalid create transaction
     * 
     */
    private static String createFaildtf = "./tests/create/create.etf";

    /**
     * An etf containing an invalid refund transaction
     */
    private static String refundFaildtf = "./tests/refund/refund.etf";

    /**
     * An etf containing an invalid addcredit transaction
     */
    private static String addcreditFaildtf = "./tests/addcredit/addcredit.etf";

    /**
     * An empty dtf
     */
    private static String emptydtf = "./tests/empty/empty.etf";

    /**
     * A sample new User Account file name
     */
    private static String uaoSample = filePrefix + ".usr";

    /**
     * A sample new Tickets file name
     */
    private static String atoSample = filePrefix + ".tic";

    /**
     * Instance of a transaction
     */
    private Transactions transaction;

    /**
     * Instance of a buy transaction
     */
    private Transactions buyTransaction;

    /**
     * Instance of a create transaction
     */
    private Transactions createTransaction;

    /**
     * Instance of a delete transaction
     */
    private Transactions deleteTransaction;

    /**
     * Instance of a refund transaction
     */
    private Transactions refundTransaction;

    /**
     * Instance of a addcredit transaction
     */
    private Transactions addcreditTransaction;

    /**
     * Instance of an empty transaction
     */
    private Transactions emptyTransaction;

    /**
     * A sample new user accounts file
     */
    private File uaoSampleFile;

    /**
     * A sample new ticket file
     */
    private File atoSampleFile;

    /**
     * Setup a test case
     */
    @Before
    public void setUp() {
        this.transaction = new Transactions(dtf, uao, ato, uaoSample, atoSample);

        this.buyTransaction = new Transactions(buyFaildtf, uao, ato, uaoSample, atoSample);

        this.createTransaction = new Transactions(createFaildtf, uao, ato, uaoSample, atoSample);

        this.deleteTransaction = new Transactions(deleteFaildtf, uao, ato, uaoSample, atoSample);

        this.refundTransaction = new Transactions(refundFaildtf, uao, ato, uaoSample, atoSample);

        this.addcreditTransaction = new Transactions(addcreditFaildtf, uao, ato, uaoSample, atoSample);

        this.emptyTransaction = new Transactions(emptydtf, uao, ato, uaoSample, atoSample);

        this.uaoSampleFile = new File(uaoSample);
        this.atoSampleFile = new File(atoSample);
    }

    /**
     * Delete the files created by {@link Transactions}
     */
    @After
    public void tearDown() {
        this.uaoSampleFile.delete();
        this.atoSampleFile.delete();
    }

    /**
     * Test the set up of the different entries
     */
    @Test
    public void initTransactionList() {
        Assert.assertTrue(this.transaction.initTransactionList());
    }

    /**
     * Test for the case where the daily transaction file is empty
     */
    @Test
    public void failEmptyDTF() {
        final File dtfFile = new File(dtf);
        final File backup = new File(dtf + "~");

        dtfFile.renameTo(backup);
        Assert.assertFalse(this.emptyTransaction.initTransactionList());
        backup.renameTo(dtfFile);
    }

    /**
     * Test for the case that the accounts file can't be read
     */
    @Test
    public void failReadAccounts() {
        final File accountFile = new File(uao);
        final File accountBackup = new File(uao + "~");

        accountFile.renameTo(accountBackup);
        Assert.assertFalse(this.transaction.initTransactionList());
        accountBackup.renameTo(accountFile);
    }

    /**
     * Test for writing out to the new user accounts file the new tickets file
     */
    @Test
    public void endSession() {
        this.transaction.initTransactionList();
        Assert.assertTrue(this.transaction.endSession());
    }

    /**
     * Test for cases where the session will fail to end
     */
    @Test
    public void failEndSession() {
        this.transaction.initTransactionList();

        // Block the creation of the output user account file by making a
        // directory in its place
        this.uaoSampleFile.mkdir();

        Assert.assertFalse(this.transaction.endSession());

        // the dummy directory is eventually deleted in tearDown.
    }

    /** 
     * Check that there is one transaction in the daily transaction file
     */
    @Test
    public void getTransactions() {
        this.transaction.initTransactionList();
        Assert.assertEquals(12, this.transaction.getTransactions().size());
    }

    /**
     * Check that the logout transaction has sucessfully occured
     */
    @Test
    public void logout() {
        this.transaction.logout();

        try {
            final Field currentUser = this.transaction.getClass().getDeclaredField("currentUser");

            currentUser.setAccessible(true);
            Assert.assertEquals(-1, currentUser.getInt(this.transaction));
            currentUser.setAccessible(false);
        } catch (final NoSuchFieldException e) {
            Assert.fail(e.getMessage());
        } catch (final SecurityException e) {
            Assert.fail(e.getMessage());
        } catch (final IllegalAccessException e) {
            Assert.fail(e.getMessage());
        }
    }

    /**
     * Tests to see if the current user can be found 
     */
    @Test
    public void loginSuccess() {
        this.transaction.initTransactionList();
        Assert.assertTrue(this.transaction.login(1));
    }

    /**
     * Tests to see if the current user can not be found
     */
    @Test
    public void failLogin() {
        this.transaction.initTransactionList();
        Assert.assertFalse(this.transaction.login(-1));
    }

    /**
     * Tests to see if a buy transaction can be processed
     */
    @Test
    public void buySuccess() {
        this.transaction.initTransactionList();
        this.transaction.login(3);

        Assert.assertTrue(this.transaction.buy((EventTransaction) this.transaction.getTransactions().get(2)));
    }

    /**
     * Tests to see if an invalid buy transaction can be caught
     */
    @Test
    public void failBuySeller() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(1);

        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(0)));
    }

    /**
     * Tests to see if a sell transaction is invalid if the same ticket is sold twice by the same user
     */
    @Test
    public void nextLogout() {
        this.createTransaction.initTransactionList();
        final int temp = this.createTransaction.findNextLogout(0);

        Assert.assertTrue(temp >= 0);
        Assert.assertTrue(this.createTransaction.findNextLogout(temp + 1) < 0);

    }

    /**
     * Tests to see if a sell transaction is invalid if the same ticket is sold twice by the same user
     */
    @Test
    public void sellError() {
        this.transaction.initTransactionList();
        this.transaction.login(11);

        this.transaction.sell((EventTransaction) this.transaction.getTransactions().get(10));

        Assert.assertFalse(this.transaction.sell((EventTransaction) this.transaction.getTransactions().get(10)));
    }

    /**
     * Tests to see how buy transactions specifying an invalid ticket name are handled
     */
    @Test
    public void failBuyTicket() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(3);

        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(2)));
    }

    /**
     * Tests to see how buy transactions specifying an invalid ticket number are handled
     */
    @Test
    public void failBuyTicketNumber() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(5);

        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(4)));
    }

    /**
     * Tests to see how buy transactions involving a buyer's account with an insufficient balance are handled
     */
    @Test
    public void failBuyFunds() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(7);

        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(6)));
    }

    /**
     * Tests to see how buy transactions involving a seller's account with an invalid balance are handled
     */
    @Test
    public void failBuySellerBalance() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(9);

        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(8)));
    }

    /**
     * Test a scenario where a seller attempts to buy their own tickets
     */
    @Test
    public void failBuySellout() {
        this.buyTransaction.initTransactionList();
        this.buyTransaction.login(11);

        Assert.assertTrue(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(10)));
        Assert.assertFalse(this.buyTransaction.buy((EventTransaction) this.buyTransaction.getTransactions().get(10)));

    }

    /**
     * Tests a successful create transaction
     */
    @Test
    public void createSuccess() {
        this.transaction.initTransactionList();
        this.transaction.login(5);

        Assert.assertTrue(this.transaction.create((AuxiliaryTransaction) this.transaction.getTransactions().get(4)));
    }

    /**
     * Tests for a failed create transaction
     */
    @Test
    public void failCreate() {
        this.createTransaction.initTransactionList();
        this.createTransaction.login(1);

        Assert.assertFalse(this.createTransaction.create((AuxiliaryTransaction) this.createTransaction.getTransactions().get(0)));
    }

    /**
     * Tests for a successful delete transaction
     */
    @Test
    public void deleteSuccess() {
        this.transaction.initTransactionList();
        this.transaction.login(6);

        Assert.assertTrue(this.transaction.delete((AuxiliaryTransaction) this.transaction.getTransactions().get(5)));
    }

    /**
     * Tests for a failed delete transaction
     */
    @Test
    public void failDelete() {
        this.deleteTransaction.initTransactionList();
        this.deleteTransaction.login(1);

        Assert.assertFalse(this.deleteTransaction.delete((AuxiliaryTransaction) this.deleteTransaction.getTransactions().get(0)));
    }

    /**
     * Tests for a successful refund transaction
     */
    @Test
    public void refundSuccess() {
        this.transaction.initTransactionList();
        this.transaction.login(9);

        Assert.assertTrue(this.transaction.refund((Refund) this.transaction.getTransactions().get(8)));
    }

    /**
     * Tests for a failed refund transaction concerning the buyer
     */
    @Test
    public void failRefundBuyer() {
        this.refundTransaction.initTransactionList();
        this.refundTransaction.login(1);

        Assert.assertFalse(this.refundTransaction.refund((Refund) this.refundTransaction.getTransactions().get(0)));
    }

    /**
     * Tests for a failed refund transaction concerning the seller
     */
    @Test
    public void failRefundSeller() {
        this.refundTransaction.initTransactionList();
        this.refundTransaction.login(3);

        Assert.assertFalse(this.refundTransaction.refund((Refund) this.refundTransaction.getTransactions().get(2)));
    }

    /**
     * Tests for a failed refund transaction concerning the seller's account balance
     */
    @Test
    public void failRefundSellerBalance() {
        this.refundTransaction.initTransactionList();
        this.refundTransaction.login(5);

        Assert.assertFalse(this.refundTransaction.refund((Refund) this.refundTransaction.getTransactions().get(4)));
    }

    /**
     * Tests for a failed refund transaction concerning the buyer's account balance
     */
    @Test
    public void failRefundBuyerBalance() {
        this.refundTransaction.initTransactionList();
        this.refundTransaction.login(7);

        Assert.assertFalse(this.refundTransaction.refund((Refund) this.refundTransaction.getTransactions().get(6)));
    }

    /**
     * Test for a successful addcredit transaction
     */
    @Test
    public void addcreditSuccess() {
        this.transaction.initTransactionList();
        this.transaction.login(1);

        Assert.assertTrue(this.transaction.addcredit((AuxiliaryTransaction) this.transaction.getTransactions().get(0)));
    }

    /**
     * Tests for a failed addcredit transaction concerning the user
     */
    @Test
    public void failAddcreditUser() {
        this.addcreditTransaction.initTransactionList();
        this.addcreditTransaction.login(1);

        Assert.assertFalse(this.addcreditTransaction.addcredit((AuxiliaryTransaction) this.addcreditTransaction.getTransactions().get(0)));
    }

    /**
     * Tests for a failed addcredit transaction concerning the user's account balance
     */
    @Test
    public void failAddcreditBalance() {
        this.addcreditTransaction.initTransactionList();
        this.addcreditTransaction.login(3);

        Assert.assertFalse(this.addcreditTransaction.addcredit((AuxiliaryTransaction) this.addcreditTransaction.getTransactions().get(2)));
    }
}

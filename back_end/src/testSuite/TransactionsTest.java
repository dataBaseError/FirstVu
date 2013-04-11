package testSuite;

import java.io.File;
import java.lang.reflect.Field;

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
    private static String ato = filePrefix + ".ato";

    /**
     * the input user accounts file
     */
    private static String uao = filePrefix + ".uao";

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
        Assert.assertFalse(this.transaction.initTransactionList());
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

    @Test
    public void logout() {
        this.transaction.logout();

        try {
            final Field currentUser = this.transaction.getClass().getDeclaredField("currentUser");
            currentUser.setAccessible(true);
            Assert.assertEquals(-1, currentUser.getInt(this.transaction));
            currentUser.setAccessible(false);
        } catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
            Assert.fail(e.getMessage());
        }
    }
}

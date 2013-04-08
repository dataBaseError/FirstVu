package testSuite;

import java.io.File;
import java.util.Collections;

import junitx.framework.FileAssert;
import main.FileIO;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the FileIO class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron 
 * @author Carly Marshall
 */
public class FileIOTest {

    /** 
     * The location of the input files
     */
    private static String filePrefix = "./tests/login/login";

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
     * Instance of the FileIO class
     */
    private FileIO fileIO;

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
        this.fileIO = new FileIO(dtf, uao, ato, uaoSample, atoSample);
        this.uaoSampleFile = new File(uaoSample);
        this.atoSampleFile = new File(atoSample);
    }

    /**
     * Delete the files created by {@link FileIO}
     */
    @After
    public void tearDown() {
        this.uaoSampleFile.delete();
        this.atoSampleFile.delete();
    }

    /**
     * Cover the {@link FileIO#getAccountList()}
     */
    @Test
    public void getAccountList() {
        Assert.assertTrue(this.fileIO.getAccountList().isEmpty());
    }

    /**
     * Cover the {@link FileIO#getEventList()}
     */
    @Test
    public void getEventList() {
        Assert.assertTrue(this.fileIO.getEventList().isEmpty());
    }

    /**
     * Test to see if the account file can be read
     */
    @Test
    public void readAccountFile() {
        Assert.assertTrue(this.fileIO.readAccountFile());
    }

    /**
     * Test to see if the ticket file can be read
     */
    @Test
    public void readTicketFile() {
        Assert.assertTrue(this.fileIO.readTicketFile());
    }

    /**
     * Test to see if transactions can be read
     */
    @Test
    public void readTransactions() {
        Assert.assertNotEquals(Collections.emptyList(), this.fileIO.readTransactions());
    }

    /**
     * See if the new user account file can be written to 
     */
    @Test
    public void writeAccountFile() {
        this.fileIO.readAccountFile();
        this.fileIO.writeAccountFile();

        FileAssert.assertEquals(this.uaoSampleFile, new File(uao));
    }

    /**
     * See if the new ticket file can be written to 
     */
    @Test
    public void writeTicketFile() {
        this.fileIO.readTicketFile();
        this.fileIO.writeTicketFile();

        FileAssert.assertEquals(this.atoSampleFile, new File(ato));
    }

    /**
     * See if the account file can't be read if it doesn't exit
     */
    @Test
    public void failReadAccountFile() {
        final File accountFile = new File(uao);
        final File accountBackup = new File(uao + "~");

        accountFile.renameTo(accountBackup);
        Assert.assertFalse(this.fileIO.readAccountFile());
        accountBackup.renameTo(accountFile);
    }

    /**
     * See if the account file can't be read if it doesn't exit
     */
    @Test
    public void failReadTicketFile() {
        final File ticketFile = new File(ato);
        final File ticketBackup = new File(ato + "~");

        ticketFile.renameTo(ticketBackup);
        Assert.assertFalse(this.fileIO.readTicketFile());
        ticketBackup.renameTo(ticketFile);
    }

    /**
     * See if the daily transaction file can't be read if the file does not exist
     */
    @Test
    public void failReadTransactions() {
        final File transactionsFile = new File(dtf);
        final File transactionsBackup = new File(dtf + "~");

        transactionsFile.renameTo(transactionsBackup);
        Assert.assertEquals(Collections.emptyList(), this.fileIO.readTransactions());
        transactionsBackup.renameTo(transactionsFile);
    }

    /**
     * {@link FileIO#writeAccountFile} can fail if the path to the new user accounts file is a directory.
     */
    @Test
    public void failWriteAccountFile() {
        this.fileIO.readAccountFile();

        // Block the creation of the output user account file by making a
        // directory in its place
        new File(uaoSample).mkdir();

        Assert.assertFalse(this.fileIO.writeAccountFile());

        // the dummy directory is eventually deleted in tearDown.
    }

    /**
     * {@link FileIO#writeTicketFile} can fail if the path to the new ticket file is a directory.
     */
    @Test
    public void failWriteTicketFile() {
        this.fileIO.readTicketFile();

        // Block the creation of the output ticket file by making a
        // directory in its place
        new File(atoSample).mkdir();

        Assert.assertFalse(this.fileIO.writeTicketFile());

        // the dummy directory is eventually deleted in tearDown.
    }

    /**
     * Test to see if a user can be found from the user account file
     */
    @Test
    public void findUser() {
        this.fileIO.readAccountFile();
        Assert.assertEquals(1, this.fileIO.findUser("full_standard"));
    }

    /**
     * Test to see what happens when a user does not exist in the user accounts file
     */
    @Test
    public void failFindUser() {
        this.fileIO.readAccountFile();
        Assert.assertEquals(-1, this.fileIO.findUser("Kim Jong il"));
    }

    /**
     * Test to see if an event can be found from the ticket file
     */
    @Test
    public void findEvent() {
        this.fileIO.readTicketFile();
        Assert.assertEquals(1, this.fileIO.findEvent("JB_Cubed", "sell_standard"));
    }

    /**
     * Test to see what happens if an event can't be found from the ticket file
     */
    @Test
    public void failFindEvent() {
        this.fileIO.readTicketFile();
        Assert.assertEquals(-1, this.fileIO.findEvent("Aaron's Party", "Kim Jong il"));
    }

    /**
     * Test to see what happens if a seller can't be found for an existing event
     */
    @Test
    public void failFindSeller() {
        this.fileIO.readTicketFile();
        Assert.assertEquals(-1, this.fileIO.findEvent("Captain_Canary", "Kim Jong il"));
    }

    /**
     * Test to see if all the tickets sold by a user can be removed.
     */
    @Test
    public void removeUserTickets() {
        this.fileIO.readTicketFile();
        this.fileIO.removeUserTickets("sell_standard");

        Assert.assertEquals(1, this.fileIO.getEventList().size());
    }
}

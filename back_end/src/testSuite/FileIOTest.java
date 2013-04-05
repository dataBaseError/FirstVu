package testSuite;

import java.io.File;

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
     * The input Daily Transaction File
     */
    private static String etf = filePrefix + ".etf";

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
     * A sample new User Account file
     */
    private File uaoSampleFile;

    /**
     * A sample new Tickets file
     */
    private File atoSampleFile;

    /**
     * Setup a test instance of the FileIO class 
     */
    @Before
    public void setUp() {
        this.fileIO = new FileIO(etf, uao, ato, uaoSample, atoSample);
        this.uaoSampleFile = new File(uaoSample);
        this.atoSampleFile = new File(atoSample);
    }

    /**
     * Delete the files created by FileIO
     */
    @After
    public void tearDown() {
        this.uaoSampleFile.delete();
        this.atoSampleFile.delete();
    }

    /**
     * Test to see if the account file can be read
     */
    @Test
    public void readAccountFile() {
        Assert.assertTrue(this.fileIO.readAccountFile());
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
     * Test to see if the ticket file can be read
     */
    @Test
    public void readTicketFile() {
        Assert.assertTrue(this.fileIO.readTicketFile());
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
     * See if the new user account file can be written to 
     */
    @Test
    public void writeAccountFile() {
        this.fileIO.readAccountFile();
        this.fileIO.writeAccountFile();

        FileAssert.assertEquals(new File(uao), this.uaoSampleFile);
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
}

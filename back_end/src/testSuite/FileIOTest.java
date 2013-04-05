package testSuite;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.File;

import main.FileIO;

import org.junit.After;
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
     * A sample new User Account file
     */
    private static String uaoSample = filePrefix + ".usr";

    /**
     * A sample new Tickets file
     */
    private static String atoSample = filePrefix + ".tic";

    /**
     * Instance of the FileIO class
     */
    private FileIO fileIO;

    /**
     * Setup a test instance of the FileIO class 
     */
    @Before
    public void setUp() {
        this.fileIO = new FileIO(etf, uao, ato, uaoSample, atoSample);
    }

    /**
     * Delete the files created by FileIO
     */
    @After
    public void tearDown() {
        new File(uaoSample).delete();
        new File(atoSample).delete();
    }

    /**
     * Test to see if the account file can be read
     */
    @Test
    public void readAccountFile() {
        assertTrue(this.fileIO.readAccountFile());
    }

    /**
     * See if the account file can't be read if it doesn't exit
     */
    @Test
    public void dontReadAccountFile() {
        final File accountFile = new File(uao);
        final File accountBackup = new File(uao + "~");

        accountFile.renameTo(accountBackup);
        assertFalse(this.fileIO.readAccountFile());
        accountBackup.renameTo(accountFile);
    }
}

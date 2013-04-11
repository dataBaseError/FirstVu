package testSuite;

import static org.junit.Assert.assertEquals;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.PrintStream;

import junitx.framework.FileAssert;
import main.Backend;
import main.ErrorMessages;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the {@link Backend} class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class BackendTest {

    /**
     * Backs up the default standard output
     */
    private static final PrintStream stdout = System.out;

    /**
     * Backs up the default standard error output
     */
    private static final PrintStream stderr = System.err;

    /**
     * The content of the redirected output
     */
    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    private final ByteArrayOutputStream errContent = new ByteArrayOutputStream();

    private final String argsSuccess[] = new String[5];
    private final String args[] = new String[4];
    private final String argsFail[] = new String[5];

    private BufferedReader accountOutput;
    private BufferedReader accountExpected;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        System.setOut(new PrintStream(this.outContent));
        System.setErr(new PrintStream(this.errContent));

        this.argsSuccess[0] = "./tests/full_test/full.etf";
        this.argsSuccess[1] = "./tests/global/glob_account.inp";
        this.argsSuccess[2] = "./tests/global/glob_available_tickets.inp";
        this.argsSuccess[3] = "./tests/output/newaccounts.out";
        this.argsSuccess[4] = "./tests/output/newtickets.out";
    }

    @After
    public void cleanUpStreams() {

        System.setOut(new PrintStream(stdout));
        System.setErr(new PrintStream(stderr));
    }

    @Test
    public void mainToFewArguments() {
        // Should print out
        // ERROR: ErrorMessages.INPUTS_ERROR_TYPE
        // ErrorMessages.INPUT_FILES_MISSING
        Backend.main(this.args);
        // System.out.println("ERROR: " + ErrorMessages.INPUTS_ERROR_TYPE + " "
        // + ErrorMessages.INPUT_FILES_MISSING);
        assertEquals("ERROR: " + ErrorMessages.getString("INPUTS_ERROR_TYPE") + " "
                + ErrorMessages.getString("INPUT_FILES_MISSING") + "\n", this.outContent.toString());
    }

    /*@Test
    public void mainnInputFail() {
    	// Should print out
    	// ERROR: ErrorMessages.INPUTS_ERROR_TYPE ErrorMessages.INPUT_FILES_INVALID
    	Backend.main(argsFail);
    	assertEquals("ERROR: " + ErrorMessages.DAILY_TRANSACTION_FILE + " " 
    			+ ErrorMessages.INPUT_ERROR_TYPE + "\n", outContent.toString());
    }*/

    @Test
    public void mainInputSuccess() {

        // TODO make a dtf that contains each transaction to allow for full
        // coverage.
        Backend.main(this.argsSuccess);

        FileAssert.assertEquals(new File(this.argsSuccess[3]), new File("./tests/full_test/full.uao"));
        /*try {
            this.accountOutput = new BufferedReader(
                    new FileReader();
            this.accountExpected = new BufferedReader(
                    new FileReader("./tests/full_test/full.uao"));

            String actual = "";
            String expected = "";

            do {
                actual = this.accountOutput.readLine();
                expected = this.accountExpected.readLine();

                assertEquals(actual, expected);
            } while (actual != null && expected != null);

            this.accountOutput.close();
            this.accountExpected.close();

        } catch (final IOException e) {
            fail(e.getMessage());
        }*/

        FileAssert.assertEquals(new File(this.argsSuccess[4]), new File("./tests/full_test/full.ato"));

        /*try {
            final BufferedReader ticketOutput = new BufferedReader(
                    new FileReader(this.argsSuccess[4]));
            final BufferedReader ticketExpected = new BufferedReader(
                    new FileReader("./tests/full_test/full.ato"));
            String actual = "";
            String expected = "";

            do {
                actual = ticketOutput.readLine();
                expected = ticketExpected.readLine();

                assertEquals(actual, expected);
            } while (actual != null && expected != null);

            ticketOutput.close();
            ticketExpected.close();
        } catch (final IOException e) {
            fail(e.getMessage());
        }*/
    }
}

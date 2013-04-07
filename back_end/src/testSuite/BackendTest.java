package testSuite;

import static org.junit.Assert.assertEquals;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import main.Backend;
import main.Messages;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class BackendTest {

    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    private final ByteArrayOutputStream errContent = new ByteArrayOutputStream();

    private final String argsSuccess[] = new String[5];
    private final String args[] = new String[4];
    private final String argsFail[] = new String[5];

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        System.setOut(new PrintStream(this.outContent));
        System.setErr(new PrintStream(this.errContent));

        // argsSuccess.

    }

    @Test
    public void mainToFewArugements() {
        // Should print out
        // ERROR: Messages.getString("INPUTS_ERROR_TYPE")
        // Messages.getString("INPUT_FILES_MISSING")
        Backend.main(this.args);
        // System.out.println("ERROR: " +
        // Messages.getString("INPUTS_ERROR_TYPE") + " "
        // + Messages.getString("INPUT_FILES_MISSING") );
        assertEquals("ERROR: " + Messages.getString("INPUTS_ERROR_TYPE") + " " + Messages.getString("INPUT_FILES_MISSING") + "\n", this.outContent.toString());
    }

    /*@Test
    public void mainInputFail() {
    	// Should print out
    	// ERROR: Messages.getString("INPUTS_ERROR_TYPE")  Messages.getString("INPUT_FILES_INVALID") 
    	Backend.main(argsFail);
    	assertEquals("ERROR: " + Messages.getString("DAILY_TRANSACTION_FILE")  + " " 
    			+ Messages.getString("INPUT_ERROR_TYPE")  + "\n", outContent.toString());
    }*/

    @Test
    public void mainInputFail() {
        // Should print out
        // ERROR: Messages.getString("INPUTS_ERROR_TYPE")
        // Messages.getString("INPUT_FILES_INVALID")
        Backend.main(this.argsSuccess);
        assertEquals("ERROR: " + Messages.getString("DAILY_TRANSACTION_FILE") + " " + Messages.getString("INPUT_ERROR_TYPE") + "\n", this.outContent.toString());
    }

    @After
    public void cleanUpStreams() {
        System.setOut(null);
        System.setErr(null);
    }
}

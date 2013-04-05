package testSuite;

import static org.junit.Assert.*;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import main.Backend;
import main.ErrorMessages;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class BackendTest {

	private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
	private final ByteArrayOutputStream errContent = new ByteArrayOutputStream();
	
	private String argsSuccess[] = new String[5];
	private String args[] = new String[4];
	private String argsFail[] = new String[5];
	
	/**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
    	System.setOut(new PrintStream(outContent));
        System.setErr(new PrintStream(errContent));
        
        argsSuccess.
        
    }
    
	@Test
	public void mainToFewArugements() {
		// Should print out
		// ERROR: ErrorMessages.INPUTS_ERROR_TYPE ErrorMessages.INPUT_FILES_MISSING
		Backend.main(args);
		//System.out.println("ERROR: " + ErrorMessages.INPUTS_ERROR_TYPE + " " + ErrorMessages.INPUT_FILES_MISSING);
		assertEquals("ERROR: " + ErrorMessages.INPUTS_ERROR_TYPE + " "
				+ ErrorMessages.INPUT_FILES_MISSING + "\n", outContent.toString());
	}
	
	/*@Test
	public void mainInputFail() {
		// Should print out
		// ERROR: ErrorMessages.INPUTS_ERROR_TYPE ErrorMessages.INPUT_FILES_INVALID
		Backend.main(argsFail);
		assertEquals("ERROR: " + ErrorMessages.DAILY_TRANSACTION_FILE + " " 
				+ ErrorMessages.INPUT_ERROR_TYPE + "\n", outContent.toString());
	}*/
	
	@Test
	public void mainInputFail() {
		// Should print out
		// ERROR: ErrorMessages.INPUTS_ERROR_TYPE ErrorMessages.INPUT_FILES_INVALID
		Backend.main(argsSuccess);
		assertEquals("ERROR: " + ErrorMessages.DAILY_TRANSACTION_FILE + " " 
				+ ErrorMessages.INPUT_ERROR_TYPE + "\n", outContent.toString());
	}

	@After
	public void cleanUpStreams() {
	    System.setOut(null);
	    System.setErr(null);
	}
}

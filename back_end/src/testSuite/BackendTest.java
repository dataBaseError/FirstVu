package testSuite;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
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
	
	private BufferedReader accountOutput;
	private BufferedReader accountExpected;

	
	/**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
    	System.setOut(new PrintStream(outContent));
        System.setErr(new PrintStream(errContent));
        
        argsSuccess[0] = "./tests/full_test/full.etf";
        argsSuccess[1] = "./tests/global/glob_account.inp";
        argsSuccess[2] = "./tests/global/glob_available_tickets.inp";
        argsSuccess[3] = "./tests/output/newaccounts.out";
        argsSuccess[4] = "./tests/output/newtickets.out";
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
	public void mainnInputFail() {
		// Should print out
		// ERROR: ErrorMessages.INPUTS_ERROR_TYPE ErrorMessages.INPUT_FILES_INVALID
		Backend.main(argsFail);
		assertEquals("ERROR: " + ErrorMessages.DAILY_TRANSACTION_FILE + " " 
				+ ErrorMessages.INPUT_ERROR_TYPE + "\n", outContent.toString());
	}*/
	
	@Test
	public void mainInputSuccess() {
		
		// TODO make a dtf that contains each transaction to allow for full coverage.
		Backend.main(argsSuccess);
		
		try {
			accountOutput = new BufferedReader(
			        new FileReader(argsSuccess[3]));
			accountExpected = new BufferedReader(
                new FileReader("./tests/full_test/full.uao"));
			
			String actual = "";
			String expected = "";
			
			do {
				actual = accountOutput.readLine();
				expected = accountExpected.readLine();
				
				assertEquals(actual, expected);
			}while(actual != null && expected != null);
			
			accountOutput.close();
			accountExpected.close();
		
		} catch (final IOException e) {
			fail(e.getMessage());
		}
		
		try {
			final BufferedReader ticketOutput = new BufferedReader(
	                new FileReader(argsSuccess[4]));
			final BufferedReader ticketExpected = new BufferedReader(
	                new FileReader("./tests/full_test/full.ato"));
			String actual = "";
			String expected = "";
			
			do {
				actual = ticketOutput.readLine();
				expected = ticketExpected.readLine();
					
				assertEquals(actual, expected);
			}while(actual != null && expected != null);
			
			ticketOutput.close();
			ticketExpected.close();
		} catch (final IOException e) {
			fail(e.getMessage());
		}		
	}

	@After
	public void cleanUpStreams() {
		
	    System.setOut(null);
	    System.setErr(null);
	}
}

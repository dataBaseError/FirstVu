package testSuite;

import static org.junit.Assert.*;

import main.Account;
import main.AuxiliaryTransaction;
import main.ErrorMessages;

import org.junit.Before;
import org.junit.Test;

public class ErrorMessagesTest {

	private String output;
	
	/**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        output = "ERROR: " + ErrorMessages.INPUT_ERROR_TYPE + " "
        		+ ErrorMessages.DAILY_TRANSACTION_FILE;
    }
    
	@Test
	public void testPrintError() {
		//assertSame(ErrorMessages.printError(ErrorMessages.INPUT_ERROR_TYPE,
		//		ErrorMessages.DAILY_TRANSACTION_FILE), output);
	}

}

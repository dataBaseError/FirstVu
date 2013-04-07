package testSuite;

import main.Messages;

import org.junit.Before;
import org.junit.Test;

public class ErrorMessagesTest {

    private String output;

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.output = "ERROR: " + Messages.getString("INPUT_ERROR_TYPE") + " " + Messages.getString("DAILY_TRANSACTION_FILE");
    }

    @Test
    public void testPrintError() {
        // assertSame(ErrorMessages.printError(Messages.getString("INPUT_ERROR_TYPE")
        // ,
        // Messages.getString("DAILY_TRANSACTION_FILE") ), output);
    }

}

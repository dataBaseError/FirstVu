/**
 * Used to print error messages to the console's output
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class ErrorMessages {

    public static final String USER_ACCOUNTS = "user accounts file";
    public static final String AVAILABLE_TICKET_FILE = "available tickets file";
    public static final String DAILY_TRANSACTION_FILE = "daily transaction file";

    public static final String INPUT_ERROR_TYPE = "Input File";
    public static final String OUTPUT_ERROR_TYPE = "Output File";

    public static final String UNABLE_TO_READ = "cannot read from ";
    public static final String UNABLE_TO_WRITE = "cannot write to ";

    /**
     * Create an error message given the type of message and the error message.
     * 
     * @param type the type of error message
     * @param message the error message
     */
    public static void printError(final String type, final String message) {
        System.out.printf("ERROR: %s %s\n", type, message);
    }
}

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
    public static final String USER_DNE = "User does not exist";
    public static final String BUYER_DNE = "Buyer does not exist";
    public static final String SELLER_DNE = "Seller does not exist";
    public static final String EVENT_DNE = "Event does not exist";
    public static final String NOT_ENOUGH_TICKETS = "Not enough tickets available";
    public static final String BUYER_FUNDS = "Buyer has insufficient funds";
    public static final String SELLER_FUNDS = "Seller has insufficient funds";
    public static final String USER_BALANCE = "User balance will exceed max balance";
    public static final String BUYER_BALANCE = "Buyer balance will exceed max balance";
    public static final String SELLER_BALANCE = "Seller balance will exceed max balance";
    public static final String ALREADY_SELLING = "Seller is already selling tickets for the event";
    public static final String USER_ALREADY_EXISTS = "User already exists with username";
    
    public static final String INPUT_ERROR_TYPE = "Input File";
    public static final String OUTPUT_ERROR_TYPE = "Output File";
    public static final String BUY_ERROR_TYPE = "Buy transaction";
    public static final String SELL_ERROR_TYPE = "Sell transaction";
    public static final String CREATE_ERROR_TYPE = "Create transaction";
    public static final String DELETE_ERROR_TYPE = "Delete transaction";
    public static final String REFUND_ERROR_TYPE = "Refund transaction";
    public static final String ADDCREDIT_ERROR_TYPE = "Addcredit transaction";

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

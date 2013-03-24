import java.util.ArrayList;

public class Transactions {

    private ArrayList<Entry> transactions;
    private FileIO fileIO;
    private String transactionLocation;

    /**
     * Constructor for creating a transaction session.
     * @param transactionLocation The location of the daily transaction file.
     * @param accountLocation The location of the user accounts file.
     * @param ticketLocation The location of the available tickets file.
     * @param newAccountLocation The location of the output user accounts file.
     * @param newTicketLocation The location of the output available tickets
     * file.
     */
    public Transactions(final String transactionLocation, final String accountLocation, final String ticketLocation, final String newAccountLocation, final String newTicketLocation) {
        this.transactionLocation = transactionLocation;
        this.fileIO = new FileIO(accountLocation, ticketLocation, newAccountLocation, newTicketLocation);
        this.transactions = new ArrayList<Entry>();
    }

    /**
     * Accessor for the transaction list
     * @return The list of transactions.
     */
    public ArrayList<Entry> getTransactions() {
        return this.transactions;
    }

    /**
     * MIGHT NOT BE NEEDED
     * Mutator for the list of transactions.
     * @param transactions The new list of transactions.
     */
    public void setTransactions(final ArrayList<Entry> transactions) {
        this.transactions = transactions;
    }

    /**
     * Transaction to log out. This transaction is used to identify which user
     * was previously logged in and therefore who will have the previous
     * transactions applied to.
     */
    public void logout() {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for buy tickets. 
     * @param buyName The buyer's username.
     * @param event The name of the event the tickets are for.
     * @param numTickets The number of tickets being purchased.
     * @param sellName The seller's username.
     * @return Whether the transaction succeeded or not.
     */
    public boolean buy(final String buyName, final String event, final int numTickets, final String sellName) {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for selling tickets.
     * @param sellName The sell'er username.
     * @param event The name of the event the tickets are for.
     * @param sellPrice The price per ticket.
     * @param availTicket The number of tickets available to for the event.
     * @return Whether the transaction succeeded or not.
     */
    public boolean sell(final String sellName, final String event, final double sellPrice, final int availTicket) {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for creating new user accounts.
     * @param newUser The new user's username.
     * @param accountType The account type of the new user.
     * @param accountBalance The new user's account balance.
     * @return Whether the transaction succeeded or not.
     */
    public boolean create(final String newUser, final String accountType, final double accountBalance) {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for deleting user accounts.
     * @param username The username of the user to be deleted.
     * @return Whether the transaction succeeded or not.
     */
    public boolean delete(final String username) {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for refunding a buyer of a previous transaction.
     * @param buyName The buyer's username.
     * @param sellName The seller's username.
     * @param account The amount of money to transfer as part of the refund.
     * @return Whether the transaction succeeded or not.
     */
    public boolean refund(final String buyName, final String sellName, final double account) {
        throw new UnsupportedOperationException();
    }

    /**
     * Transaction for adding credit to a user's account.
     * @param username The username of the user to add the credit to.
     * @param amount The amount of money added to the user's account.
     * @return Whether the transaction succeeded or not.
     */
    public boolean addcredit(final String username, final double amount) {
        throw new UnsupportedOperationException();
    }
    
    /**
     * Find the next logout in the daily transaction list.
     * @return The location of the next logout transaction.
     */
    public int findNextLogout(int startLocation)
    {
    	return -1;
    }

}
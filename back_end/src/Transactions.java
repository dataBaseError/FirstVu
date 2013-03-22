import java.util.ArrayList;

public class Transactions {

    private ArrayList<Entry> transactions;
    private FileIO fileIO;
    private String transactionLocation;

    /**
     * 
     * @param accountLocation
     * @param ticketLocation
     * @param transactionLocation
     */
    public Transactions(final String transactionLocation, final String accountLocation, final String ticketLocation, final String newAccountLocation, final String newTicketLocation) {
        this.transactionLocation = transactionLocation;
        this.fileIO = new FileIO(accountLocation, ticketLocation, newAccountLocation, newTicketLocation);
        this.transactions = new ArrayList<Entry>();
    }

    public ArrayList<Entry> getTransactions() {
        return this.transactions;
    }

    /**
     * 
     * @param transactions
     */
    public void setTransactions(final ArrayList<Entry> transactions) {
        this.transactions = transactions;
    }

    public void logout() {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param buyName
     * @param event
     * @param numTickets
     * @param sellName
     */
    public boolean buy(final String buyName, final String event, final int numTickets, final String sellName) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param sellName
     * @param event
     * @param sellPrice
     * @param availTicket
     */
    public boolean sell(final String sellName, final String event, final double sellPrice, final int availTicket) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param newUser
     * @param accountType
     * @param accountBalance
     */
    public boolean create(final String newUser, final String accountType, final double accountBalance) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param username
     */
    public boolean delete(final String username) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param buyName
     * @param sellName
     * @param account
     */
    public boolean refund(final String buyName, final String sellName, final double account) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param username
     * @param amount
     */
    public boolean addcredit(final String username, final double amount) {
        throw new UnsupportedOperationException();
    }

}
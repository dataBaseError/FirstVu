import java.util.ArrayList;

/**
 * A class for applying the transactions in the daily transaction file to the 
 * user accounts file and available tickets file.
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Transactions {
    /**
     * An array list of type entry to store entries  
      */
    private ArrayList<Entry> transactions;

    /**
     * instance of the fileio class
     */
    private final FileIO fileIO;

    /**
     * index of the current user in the array list  
     */
    private int currentUser;

    /**
     * Constructor for creating a transaction session.
     * 
     * @param transactionLocation The location of the daily transaction file.
     * @param accountLocation The location of the user accounts file.
     * @param ticketLocation The location of the available tickets file.
     * @param newAccountLocation The location of the output user accounts file.
     * @param newTicketLocation The location of the output available tickets
     * file.
     */
    public Transactions(final String transactionLocation, final String accountLocation, final String ticketLocation, final String newAccountLocation, final String newTicketLocation) {

        this.fileIO = new FileIO(transactionLocation, accountLocation, ticketLocation, newAccountLocation, newTicketLocation);
        this.transactions = new ArrayList<Entry>();
        this.currentUser = -1;
    }

    /**
     * Initialize the transaction session by reading in the needed files.
     * @return Whether the initialization was successful.
     */
    public boolean initTransactionList() {

        this.transactions = this.fileIO.readTransactions();

        if (this.transactions == null) {
            // Error reading dtf
            return false;
        }

        if (!this.fileIO.readAccountFile()) {
            // Error reading account file
            return false;
        }

        if (!this.fileIO.readTicketFile()) {
            // Error reading ticket file
            return false;
        }

        return true;
    }

    /**
     * writes to the global account and global tickets file
     * @return whether the end of session was successful
     */
    public boolean endSession() {

        if (!this.fileIO.writeAccountFile()) {
            // Error writing to current account file
            return false;
        }

        if (!this.fileIO.writeTicketFile()) {
            // Error writing to available ticket file
            return false;
        }

        return true;
    }

    /**
     * Accessor for the transaction list
     * 
     * @return The list of transactions.
     */
    public ArrayList<Entry> getTransactions() {
        return this.transactions;
    }

    /**
     * Transaction to set the current user who is calling the transactions. This
     * is primarily needed for the buy transaction where the user who is
     * actually buying the tickets is not included in the daily transaction
     * file.
     * @param loginEntry The index of the transaction that contains the username
     * of the user to apply the next set of transactions to.
     */
    public void login(final int loginEntry) {
        if (loginEntry >= 0) {
            this.currentUser = this.fileIO.findUser(
                    ((AuxiliaryTransaction) this.transactions.get(loginEntry))
                            .getUsername());
        }
    }

    /**
     * Transaction to log out. This transaction is used to identify which user
     * was previously logged in and therefore who will have the previous
     * transactions applied to.
     */
    public void logout() {
        this.currentUser = -1;
    }

    /**
     * TODO add seller buy back.
     * 
     * Transaction for buy tickets. 
     * 
     * @param buyTransaction an instance of the EventTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean buy(final EventTransaction buyTransaction) {

        // final int buyerLocation = this.fileIO.findUser(buyName); // current
        // user
        final Account buyer = this.fileIO.getAccountList().get(this.currentUser);

        final int sellerLocation = this.fileIO.findUser(buyTransaction.getSellName());
        final Account seller = this.fileIO.getAccountList().get(sellerLocation);

        final int ticketLocation = this.fileIO.findEvent(buyTransaction.getEventName(), buyTransaction.getSellName());
        final Ticket eventTicket = this.fileIO.getEventList().get(ticketLocation);

        // Check that the event has enough tickets left.
        if (eventTicket.getTicketNumber() < buyTransaction.getNumTickets()) {

            // Not enough tickets available.
            return false;
        }

        final double cost = buyTransaction.getNumTickets() * eventTicket.getCost();

        buyer.decreaseBalance(cost);

        seller.increaseBalance(cost);

        eventTicket.decreaseTicketNumber(buyTransaction.getNumTickets());

        this.fileIO.getAccountList().set(this.currentUser, buyer);
        this.fileIO.getAccountList().set(sellerLocation, seller);

        if (eventTicket.getTicketNumber() == 0) {
            this.fileIO.getEventList().remove(ticketLocation);
        }
        else {
            this.fileIO.getEventList().set(ticketLocation, eventTicket);
        }

        return true;
    }

    /**
     * Transaction for selling tickets.
     * 
     * @param sellTransaction an instance of the EventTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean sell(final EventTransaction sellTransaction) {

        final Ticket newEvent = new Ticket(sellTransaction.getEventName(),
                sellTransaction.getSellName(), sellTransaction.getNumTickets(),
                sellTransaction.getPrice());

        this.fileIO.getEventList().add(newEvent);

        return true;
    }

    /**
     * Transaction for creating new user accounts.
     * 
     * @param createTransaction An instance of the AuxiliaryTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean create(final AuxiliaryTransaction createTransaction) {

        final Account user = new Account(createTransaction.getUsername(),
                createTransaction.getAccountType(), createTransaction.getCredit());

        this.fileIO.getAccountList().add(user);

        return true;
    }

    /**
     * Transaction for deleting user accounts.
     * 
     * @param deleteTransaction an instance of the AuxiliaryTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean delete(final AuxiliaryTransaction deleteTransaction) {

        final int userLocation = this.fileIO.findUser
                (deleteTransaction.getUsername());

        this.fileIO.getAccountList().remove(userLocation);

        return true;
    }

    /**
     * Transaction for refunding a buyer of a previous transaction.
     * 
     * @param refundTransaction an instance of the Refund class
     * @return Whether the transaction succeeded or not.
     */
    public boolean refund(final Refund refundTransaction) {

        final int buyerLocation = this.fileIO.findUser
                (refundTransaction.getBuyName());
        final Account buyer = this.fileIO.getAccountList().get(buyerLocation);

        final int sellerLocation = this.fileIO.findUser
                (refundTransaction.getSellName());
        final Account seller = this.fileIO.getAccountList().get(sellerLocation);

        buyer.decreaseBalance(refundTransaction.getCredit());

        seller.increaseBalance(refundTransaction.getCredit());

        this.fileIO.getAccountList().set(buyerLocation, buyer);
        this.fileIO.getAccountList().set(sellerLocation, seller);

        return true;
    }

    /**
     * Transaction for adding credit to a user's account.
     * 
     * @param addcreditTransaction an instance of the AuxiliaryTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean addcredit(final AuxiliaryTransaction addcreditTransaction) {

        final int userLocation = this.fileIO.findUser
                (addcreditTransaction.getUsername());
        final Account user = this.fileIO.getAccountList().get(userLocation);

        user.increaseBalance(addcreditTransaction.getCredit());

        this.fileIO.getAccountList().set(userLocation, user);

        return true;
    }

    /**
     * Find the next logout in the daily transaction list.
     * 
     * @param startLocation the position from where to start looking for a logout
     * @return The location of the next logout transaction.
     */
    public int findNextLogout(final int startLocation) {
        for (int i = startLocation; i < this.transactions.size(); i++) {
            if (this.transactions.get(i).getTransactionType() == AuxiliaryTransaction.LOGOUT
                    && ((AuxiliaryTransaction) this.transactions.get(i)).getUsername() != null) {
                return i;
            }
        }

        // No logout found
        return -1;
    }

}
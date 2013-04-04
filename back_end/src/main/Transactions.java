package main;
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
    public Transactions(final String transactionLocation,
            final String accountLocation, final String ticketLocation,
            final String newAccountLocation, final String newTicketLocation) {

        this.fileIO = new FileIO(transactionLocation, accountLocation,
                ticketLocation, newAccountLocation, newTicketLocation);
        this.transactions = new ArrayList<Entry>();
        this.currentUser = -1;
    }

    /**
     * Initialize the transaction session by reading in the needed files.
     * 
     * @return Whether the initialization was successful.
     */
    public boolean initTransactionList() {

        this.transactions = this.fileIO.readTransactions();

        if (this.transactions.isEmpty()) {   
            return false;
        }

        if (!this.fileIO.readAccountFile()) {
            return false;
        }

        return this.fileIO.readTicketFile();
    }

    /**
     * Writes to the global account and global tickets file.
     * 
     * @return whether the end of session was successful
     */
    public boolean endSession() {

        if (!this.fileIO.writeAccountFile()) {
            return false;
        }
        
        return this.fileIO.writeTicketFile();
    }

    /**
     * Accessor for the transaction list.
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
     * 
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
     * Transaction for buy tickets. 
     * 
     * @param buyTransaction an instance of the EventTransaction class
     * @return Whether the transaction succeeded or not.
     */
    public boolean buy(final EventTransaction buyTransaction) {

        final Account buyer = this.fileIO.getAccountList().get(this.currentUser);

        final int sellerLocation = this.fileIO.findUser(buyTransaction.getSellName());
        
        if (sellerLocation == -1) {
        	// Seller does not exist
        	ErrorMessages.printError(ErrorMessages.BUY_ERROR_TYPE, ErrorMessages.SELLER_DNE);
        	return false;
        }
        
        final Account seller = this.fileIO.getAccountList().get(sellerLocation);

        final int ticketLocation = this.fileIO.findEvent(buyTransaction.getEventName(),
                buyTransaction.getSellName());
        
        if (ticketLocation == -1) {
        	// Event does not exist
        	ErrorMessages.printError(ErrorMessages.BUY_ERROR_TYPE, ErrorMessages.EVENT_DNE);
        	return false;
        }
        
        final Ticket eventTicket = this.fileIO.getEventList().get(ticketLocation);

        if (eventTicket.getTicketNumber() < buyTransaction.getNumTickets()) {
            // Not enough tickets available
        	ErrorMessages.printError(ErrorMessages.BUY_ERROR_TYPE, ErrorMessages.NOT_ENOUGH_TICKETS);
            return false;
        }
        
        if (this.currentUser != sellerLocation) {
	
	        final double cost = buyTransaction.getNumTickets() * eventTicket.getCost();
	        
	        if (buyer.getBalance() < cost) {
	        	// Buyer does not have enough money
	        	ErrorMessages.printError(ErrorMessages.BUY_ERROR_TYPE, ErrorMessages.BUYER_FUNDS);
	        	return false;
	        }
	        
	        if (seller.getBalance() + cost > Account.MAX_BALANCE) {
	        	// Seller balance will exceed max balance
	        	ErrorMessages.printError(ErrorMessages.BUY_ERROR_TYPE, ErrorMessages.SELLER_BALANCE);
	        	return false;
	        }
	
	        buyer.decreaseBalance(cost);
	
	        seller.increaseBalance(cost);
        
		    this.fileIO.getAccountList().set(this.currentUser, buyer);
	        this.fileIO.getAccountList().set(sellerLocation, seller);
        }
        
        eventTicket.decreaseTicketNumber(buyTransaction.getNumTickets());
        
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
        
        if(this.fileIO.findEvent(newEvent.getEvent(), newEvent.getUsername()) != -1) {
        	// Seller is already selling tickets for the event
        	ErrorMessages.printError(ErrorMessages.SELL_ERROR_TYPE, ErrorMessages.ALREADY_SELLING);
        	return false;
        }

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
        
        if (this.fileIO.findUser(user.getUsername()) != -1) {
        	// User already exists with username
        	ErrorMessages.printError(ErrorMessages.CREATE_ERROR_TYPE, ErrorMessages.USER_ALREADY_EXISTS);
        	return false;
        }

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
        
        if (userLocation == -1) {
        	// User does not exist
        	ErrorMessages.printError(ErrorMessages.DELETE_ERROR_TYPE, ErrorMessages.USER_DNE);
        	return false;
        }
        
        this.fileIO.getAccountList().remove(userLocation);
        
        // Remove tickets that are related to the user
        this.fileIO.removeUserTickets(deleteTransaction.getUsername());       

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
        
        if (buyerLocation == -1) {
        	// Buyer does not exist
        	ErrorMessages.printError(ErrorMessages.REFUND_ERROR_TYPE, ErrorMessages.BUYER_DNE);
        	return false;
        }
        
        final Account buyer = this.fileIO.getAccountList().get(buyerLocation);

        final int sellerLocation = this.fileIO.findUser
                (refundTransaction.getSellName());
        
        if (sellerLocation == -1) {
        	// Seller does not exist
        	ErrorMessages.printError(ErrorMessages.REFUND_ERROR_TYPE, ErrorMessages.SELLER_DNE);
        	return false;
        }
        
        final Account seller = this.fileIO.getAccountList().get(sellerLocation);
        
        if (seller.getBalance() < refundTransaction.getCredit()) {
        	// Seller has insufficent funds
        	ErrorMessages.printError(ErrorMessages.REFUND_ERROR_TYPE, ErrorMessages.SELLER_FUNDS);
        	return false;
        }
      
        if (buyer.getBalance() + refundTransaction.getCredit() >
        		Account.MAX_BALANCE) {
        	// Buyer will exceed max funds
        	ErrorMessages.printError(ErrorMessages.REFUND_ERROR_TYPE, ErrorMessages.BUYER_BALANCE);
        	return false;
        }

        seller.decreaseBalance(refundTransaction.getCredit());

        buyer.increaseBalance(refundTransaction.getCredit());

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
        
        if (userLocation == -1) {
        	// User does not exist
        	ErrorMessages.printError(ErrorMessages.ADDCREDIT_ERROR_TYPE, ErrorMessages.USER_DNE);
        	return false;
        }
        
        final Account user = this.fileIO.getAccountList().get(userLocation);

        if (user.getBalance() + addcreditTransaction.getCredit()
        		> Account.MAX_BALANCE) {
        	// User balance will exceed max balance
        	ErrorMessages.printError(ErrorMessages.ADDCREDIT_ERROR_TYPE, ErrorMessages.USER_BALANCE);
        	return false;
        }
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
            if (this.transactions.get(i).getTransactionType() ==
                    AuxiliaryTransaction.LOGOUT && ((AuxiliaryTransaction)
                    this.transactions.get(i)).getUsername() != null) {
                return i;
            }
        }

        // No logout found
        return -1;
    }

}
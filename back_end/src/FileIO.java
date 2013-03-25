import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class FileIO {

    private ArrayList<Account> accountList;
    private ArrayList<Ticket> eventList;
    private String accountLocation;
    private String ticketLocation;
    private String transactionLocation;
    private String newAccountLocation;
    private String newTicketLocation;

    /**
     * Constructor for the file input and output.
     * @param accountLocation The location of the current User Accounts file.
     * @param ticketLocation The location of the current Available Tickets file.
     * @param newAccountLocation The location for the new User Accounts file to
     * be stored to. 
     * @param newTicketLocation The location for the new Available Tickets file
     * to be stored to.
     */
    public FileIO(final String transactionLocation, final String accountLocation, final String ticketLocation, final String newAccountLocation, final String newTicketLocation) {
        this.accountList = new ArrayList<Account>();
        this.eventList = new ArrayList<Ticket>();
        
    	this.accountLocation = accountLocation;
    	this.transactionLocation = transactionLocation;
        this.ticketLocation = ticketLocation;
        this.newAccountLocation = newAccountLocation;
        this.newTicketLocation = newTicketLocation;
    }

    /**
     * Accessor for the current list of user accounts.
     * @return The current list of user accounts.
     */
    public ArrayList<Account> getAccountList() {
        return this.accountList;
    }

    /**
     * MIGHT NOT BE NEEDED
     * Mutator method for the current user account list.
     * @param accountList The new list of accounts.
     */
    public void setAccountList(final ArrayList<Account> accountList) {
        this.accountList = accountList;
    }

    /**
     * Accessor for the list of currently available tickets.
     * @return The list of currently available tickets.
     */
    public ArrayList<Ticket> getEventList() {
        return this.eventList;
    }

    /**
     * MIGHT NOT BE NEEDED
     * Mutator for the list of currently available tickets.
     * @param eventList The new list of currently available tickets.
     */
    public void setEventList(final ArrayList<Ticket> eventList) {
        this.eventList = eventList;
    }

    /**
     * Read in the User Accounts file.
     * @return Whether the file was successfully read or not.
     */
    public boolean readAccountFile() {
    	String line = "";
    	String[] lineArray = new String[3];
    	Double balance;
    	try{
    	BufferedReader fStream = new BufferedReader (new FileReader(this.accountLocation));
    	while((line = fStream.readLine()) != null){
    		lineArray =line.split("\\s+");
    		balance = (Double.parseDouble(lineArray[2]));
    		accountList.add(new Account(lineArray[0],lineArray[1],balance));
    	}
    	
    	fStream.close();
    	}catch(IOException e){
    		e.printStackTrace();
    		return false;
    	}
    	return true;
    	
    }

    /**
     * Read in the Available Tickets file.
     * @return Whether the file was successfully read or not.
     */
    public boolean readTicketFile() {
    	String line = "";
    	String[] lineArray = new String[4];
    	int ticketNumber;
    	Double cost;
    	try{
    	BufferedReader fStream = new BufferedReader (new FileReader(this.ticketLocation));
    	while((line = fStream.readLine()) != null){
    		lineArray =line.split("\\s+");
    		ticketNumber = (Integer.parseInt(lineArray[2]));
    		cost = (Double.parseDouble(lineArray[3]));
    		eventList.add(new Ticket(lineArray[0],lineArray[1],ticketNumber,cost));
    	}
    	
    	fStream.close();
    	}catch(IOException e){
    		e.printStackTrace();
    		return false;
    	}
    	return true;
        
    }

    /**
     * Write out to the new User Accounts file.
     * @return Whether the file was successfully read or not.
     */
    public boolean writeAccountFile() {
        throw new UnsupportedOperationException();
    }

    /**
     * Write out to the new Available Tickets file.
     * @return Whether the file was successfully read or not.
     */
    public boolean writeTicketFile() {
        throw new UnsupportedOperationException();
    }

    /**
     * Read in the daily transaction file.
     * @return The list of transactions to apply to the User Accounts and 
     * Available Tickets file. 
     */
    //UNFINISHED
    public ArrayList<Entry> readTransactions() {
    	String line = "";
    	String[] lineArray = new String[5];
    	int type;
    	
    	try{
    	BufferedReader fStream = new BufferedReader (new FileReader(this.transactionLocation));
    	while((line = fStream.readLine()) != null){
    		lineArray =line.split("\\s+");
    		type = (Integer.parseInt(lineArray[0]));

    		
    	}
    	
    	fStream.close();
    	}catch(IOException e){
    		e.printStackTrace();
    		
    	}
		return null;
    	
    }

    /**
     * Find the user in the list of user accounts given their username.
     * @param username The username of the user to find.
     * @return The location of that user in the user accounts list.
     */
    public int findUser(final String username) {
        throw new UnsupportedOperationException();
    }

    /**
     * Find a ticket given the event's name and the seller's name.
     * @param event The name of the event.
     * @param sellName The name of the seller.
     * @return The location of the ticket in the available tickets list.
     */
    public int fintEvent(final String event, final String sellName) {
        throw new UnsupportedOperationException();
    }

}
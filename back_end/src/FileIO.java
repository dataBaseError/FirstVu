import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Handles all file inputs and output
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class FileIO {

    /**
     * A collection of user accounts
     */
    private final ArrayList<Account> accountList;

    /**
     * A collection of events
     */
    private final ArrayList<Ticket> eventList;

    /**
     * The location of the current User Accounts file.
     */
    private final String accountLocation;

    /**
     * The location of the current Available Tickets file.
     */
    private final String ticketLocation;

    /**
     * The location of the daily transaction file.
     */
    private final String transactionLocation;

    /**
     * The location for the new User Accounts file to
     * be stored to. 
     */
    private final String newAccountLocation;

    /**
     * The location for the new Available Tickets file
     * to be stored to.
     */
    private final String newTicketLocation;

    /**
     * Constructor for the file input and output.
     * @param transactionLocation The location of the daily transaction file.
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
     * Accessor for the list of currently available tickets.
     * @return The list of currently available tickets.
     */
    public ArrayList<Ticket> getEventList() {
        return this.eventList;
    }

    /**
     * Read in the User Accounts file.
     * @return Whether the file was successfully read or not.
     */
    public boolean readAccountFile() {
        String line = "";
        String[] lineArray = new String[3];
        Double balance;
        try {
            final BufferedReader fStream = new BufferedReader(new FileReader(this.accountLocation));
            while ((line = fStream.readLine()) != null) {
                lineArray = line.split("\\s+");
                balance = Double.parseDouble(lineArray[2]);
                this.accountList.add(new Account(lineArray[0], lineArray[1], balance));
            }

            fStream.close();
        } catch (final IOException e) {
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
        try {
            final BufferedReader fStream = new BufferedReader(new FileReader(this.ticketLocation));
            while ((line = fStream.readLine()) != null) {
                lineArray = line.split("\\s+");
                ticketNumber = Integer.parseInt(lineArray[2]);
                cost = Double.parseDouble(lineArray[3]);
                this.eventList.add(new Ticket(lineArray[0], lineArray[1], ticketNumber, cost));
            }

            fStream.close();
        } catch (final IOException e) {
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
    // UNFINISHED
    public ArrayList<Entry> readTransactions() {
        String line = "";
        String[] lineArray = new String[5];
        double balance;
        int numTickets;
        double price;
        try {
            final BufferedReader fStream = new BufferedReader(new FileReader(this.transactionLocation));
            while ((line = fStream.readLine()) != null) {
                lineArray = line.split("\\s+");
                final int transaction = Integer.parseInt(lineArray[0]);
                final String username = lineArray[1];

                switch (transaction) {
                    case 0:
                        // logout
                    case 1:
                        // create
                    case 2:
                        // delete
                    case 6:
                        // addcredit
                        balance = Double.parseDouble(lineArray[3]);
                        new AuxiliaryTransaction(transaction, username, balance, lineArray[2]);
                        break;
                    case 3:
                        // sell
                    case 4:
                        // buy
                        numTickets = Integer.parseInt(lineArray[3]);
                        price = Double.parseDouble(lineArray[4]);
                        new EventTransaction(transaction, lineArray[1], lineArray[2], price, numTickets);
                        break;
                    case 5:
                        // refund
                        final double amount = Double.parseDouble(lineArray[3]);
                        new Refund(transaction, lineArray[1], lineArray[2], amount);
                        break;
                }

            }

            fStream.close();
        } catch (final IOException e) {
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
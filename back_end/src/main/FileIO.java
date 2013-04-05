package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
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
     * 
     * @param transactionLocation The location of the daily transaction file.
     * @param accountLocation The location of the current User Accounts file.
     * @param ticketLocation The location of the current Available Tickets file.
     * @param newAccountLocation The location for the new User Accounts file to
     * be stored to. 
     * @param newTicketLocation The location for the new Available Tickets file
     * to be stored to.
     */
    public FileIO(final String transactionLocation,
            final String accountLocation, final String ticketLocation,
            final String newAccountLocation, final String newTicketLocation) {
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
     * 
     * @return The current list of user accounts.
     */
    public ArrayList<Account> getAccountList() {
        return this.accountList;
    }

    /**
     * Accessor for the list of currently available tickets.
     * 
     * @return The list of currently available tickets.
     */
    public ArrayList<Ticket> getEventList() {
        return this.eventList;
    }

    /**
     * Read in the User Accounts file.
     * 
     * @return Whether the file was successfully read or not.
     */
    public boolean readAccountFile() {
        String line = "";
        String[] lineArray;
        Double balance;

        try {

            // Open the user account file
            final BufferedReader fStream = new BufferedReader(
                    new FileReader(this.accountLocation));

            // Read lines from the user accounts from the file
            while ((line = fStream.readLine()) != null) {

                lineArray = line.split("\\s+");

                if (lineArray.length == 3) {
                    balance = Double.parseDouble(lineArray[2]);
                    this.accountList.add(new Account(lineArray[0], lineArray[1],
                            balance));
                }
            }

            // Close the user account file
            fStream.close();
        } catch (final IOException e) {
            // Error reading account file
            ErrorMessages.printError(ErrorMessages.INPUT_ERROR_TYPE, ErrorMessages.USER_ACCOUNTS);
            return false;
        }

        return true;
    }

    /**
     * Read in the Available Tickets file.
     * 
     * @return Whether the file was successfully read or not.
     */
    public boolean readTicketFile() {
        String line = "";
        String[] lineArray;
        int ticketNumber;
        Double cost;

        try {
            // Open the available tickets file
            final BufferedReader fStream = new BufferedReader(
                    new FileReader(this.ticketLocation));

            // Read lines from the tickets available from the file
            while ((line = fStream.readLine()) != null) {
                lineArray = line.split("\\s+");

                if (lineArray.length > 3) {

                    ticketNumber = Integer.parseInt(lineArray[2]);
                    cost = Double.parseDouble(lineArray[3]);
                    this.eventList.add(new Ticket(lineArray[0], lineArray[1],
                            ticketNumber, cost));
                }
            }

            fStream.close();
        } catch (final IOException e) {
            // Error reading ticket file
            ErrorMessages.printError(ErrorMessages.AVAILABLE_TICKET_FILE,
                    ErrorMessages.INPUT_ERROR_TYPE);
            return false;
        }

        return true;
    }

    /**
     * Write out to the new User Accounts file.
     * 
     * @return Whether the file was successfully read or not.
     */
    public boolean writeAccountFile() {
        try {
            final BufferedWriter writer = new BufferedWriter(
                    new FileWriter(this.newAccountLocation));

            // The format of the line is %-15s %2s %09.2f
            final String format = String.format("%s%d%s%d%s", "%-",
                    Account.MAX_USERNAME_LENGTH, "s %2s %0",
                    Account.MAX_BALANCE_LENGTH + 3, ".2f");

            // Add the user accounts to the output file
            for (final Account account : this.accountList) {
                final String username = account.getUsername();
                final String type = account.getType();
                final double balance = account.getBalance();

                writer.write(String.format(format + "\n", username, type,
                        balance));
            }

            writer.write(String.format(format, "END", "", 0.0));

            writer.close();
        } catch (final IOException e) {
            // Error writing to current account file
            ErrorMessages.printError(ErrorMessages.USER_ACCOUNTS,
                    ErrorMessages.OUTPUT_ERROR_TYPE);
            return false;
        }

        return true;
    }

    /**
     * Write out to the new Available Tickets file.
     * 
     * @return Whether the file was successfully read or not.
     */
    public boolean writeTicketFile() {
        try {
            final BufferedWriter writer = new BufferedWriter(
                    new FileWriter(this.newTicketLocation));

            // The format of the line is %-19s %-15s %03d %06.2f
            final String format = String.format("%s%d%s%d%s%d%s%d%s", "%-",
                    Ticket.MAX_EVENT_LENGTH, "s %-", Account.MAX_USERNAME_LENGTH,
                    "s %0", Ticket.MAX_TICKET_LENGTH, "d %0",
                    Account.MAX_BALANCE_LENGTH, ".2f");

            // Add the tickets available to the output file
            for (final Ticket ticket : this.eventList) {
                final String event = ticket.getEvent();
                final String seller = ticket.getUsername();
                final int quantity = ticket.getTicketNumber();
                final double cost = ticket.getCost();

                writer.write(String.format(format + "\n", event, seller,
                        quantity, cost));
            }

            writer.write(String.format(format, "END", "", 0, 0.0));

            writer.close();
        } catch (final IOException e) {
            // Error writing to available ticket file
            ErrorMessages.printError(ErrorMessages.AVAILABLE_TICKET_FILE,
                    ErrorMessages.OUTPUT_ERROR_TYPE);
            return false;
        }

        return true;
    }

    /**
     * Read in the daily transaction file.
     * 
     * @return The list of transactions to apply to the User Accounts and 
     * Available Tickets file. 
     */
    public ArrayList<Entry> readTransactions() {
        final ArrayList<Entry> entries = new ArrayList<Entry>();

        try {
            // Open the daily transaction file
            final BufferedReader fStream = new BufferedReader(
                    new FileReader(this.transactionLocation));
            String line;

            // Read the lines of the daily transaction file
            while ((line = fStream.readLine()) != null) {
                final String[] lineArray = line.split("\\s+");
                final int transaction = Integer.parseInt(lineArray[0]);

                if (lineArray.length > 1) {
                    final String username = lineArray[1];
                    switch (transaction) {
                        case 0:
                            // logout or
                        case 1:
                            // create or
                        case 2:
                            // delete or
                        case 6:
                            // addcredit
                            final double balance = Double.parseDouble(lineArray[3]);

                            entries.add(new AuxiliaryTransaction(transaction,
                                    username, balance, lineArray[2]));
                            break;
                        case 3:
                            // sell or
                        case 4:
                            // buy
                            final int numTickets = Integer.parseInt(lineArray[3]);
                            final double price = Double.parseDouble(lineArray[4]);

                            entries.add(new EventTransaction(transaction,
                                    lineArray[1], lineArray[2], price,
                                    numTickets));
                            break;
                        case 5:
                            // refund
                            final double amount = Double.parseDouble(lineArray[3]);

                            entries.add(new Refund(transaction, lineArray[1],
                                    lineArray[2], amount));
                            break;
                    }
                }
            }

            fStream.close();
        } catch (final IOException e) {
            // Error reading dtf
            ErrorMessages.printError(ErrorMessages.DAILY_TRANSACTION_FILE,
                    ErrorMessages.INPUT_ERROR_TYPE);
        }

        return entries;
    }

    /**
     * Find the user in the list of user accounts given their username.
     * 
     * @param username The username of the user to find.
     * @return The location of that user in the user accounts list.
     */
    public int findUser(final String username) {
        for (int i = 0; i < this.accountList.size(); i++) {
            if (this.accountList.get(i).getUsername().equals(username)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Find a ticket given the event's name and the seller's name.
     * 
     * @param eventName The name of the event.
     * @param sellName The name of the seller.
     * @return The location of the ticket in the available tickets list.
     */
    public int findEvent(final String eventName, final String sellName) {
        for (int i = 0; i < this.eventList.size(); i++) {
            final Ticket event = this.eventList.get(i);
            if (event.getEvent().equals(eventName) && event.getUsername()
                    .equals(sellName)) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Removes all events who's tickets are sold by a user
     * 
     * @param username the event's ticket's seller
     */
    public void removeUserTickets(final String username) {
        for (int i = 0; i < this.eventList.size(); i++) {
            if (this.eventList.get(i).getUsername().equals(username)) {
                this.eventList.remove(i);
            }
        }
    }

}
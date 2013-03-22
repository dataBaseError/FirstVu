import java.util.ArrayList;

public class FileIO {

    private ArrayList<Account> accountList;
    private ArrayList<Ticket> eventList;

    /**
     * 
     * @param accountLocation
     * @param ticketLocation
     */
    public FileIO(final String accountLocation, final String ticketLocation) {
        throw new UnsupportedOperationException();
    }

    public ArrayList<Account> getAccountList() {
        return this.accountList;
    }

    /**
     * 
     * @param accountList
     */
    public void setAccountList(final ArrayList<Account> accountList) {
        this.accountList = accountList;
    }

    public ArrayList<Ticket> getEventList() {
        return this.eventList;
    }

    /**
     * 
     * @param eventList
     */
    public void setEventList(final ArrayList<Ticket> eventList) {
        this.eventList = eventList;
    }

    public boolean readAccountFile() {
        throw new UnsupportedOperationException();
    }

    public boolean readTicketFile() {
        throw new UnsupportedOperationException();
    }

    public boolean writeAccountFile() {
        throw new UnsupportedOperationException();
    }

    public boolean writeTicketFile() {
        throw new UnsupportedOperationException();
    }

    public ArrayList<Entry> readTransactions() {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param username
     */
    public int findUser(final String username) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param event
     * @param sellName
     */
    public int fintEvent(final String event, final String sellName) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param username
     */
    public boolean isUserUnique(final String username) {
        throw new UnsupportedOperationException();
    }

    /**
     * 
     * @param event
     */
    public boolean isEventUnique(final String event) {
        throw new UnsupportedOperationException();
    }

}
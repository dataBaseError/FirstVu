public class FileIO {

	private ArrayList<Account> accountList;
	private ArrayList<Ticket> eventList;

	/**
	 * 
	 * @param accountLocation
	 * @param ticketLocation
	 */
	public FileIO(String accountLocation, String ticketLocation) {
		throw new UnsupportedOperationException();
	}

	public ArrayList<Account> getAccountList() {
		return this.accountList;
	}

	/**
	 * 
	 * @param accountList
	 */
	public void setAccountList(ArrayList<Account> accountList) {
		this.accountList = accountList;
	}

	public ArrayList<Ticket> getEventList() {
		return this.eventList;
	}

	/**
	 * 
	 * @param eventList
	 */
	public void setEventList(ArrayList<Ticket> eventList) {
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
	public int findUser(String username) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param event
	 * @param sellName
	 */
	public int fintEvent(String event, String sellName) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param username
	 */
	public boolean isUserUnique(String username) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param event
	 */
	public boolean isEventUnique(String event) {
		throw new UnsupportedOperationException();
	}

}
public class Transactions {

	private ArrayList<Entry> transactions;

	/**
	 * 
	 * @param accountLocation
	 * @param ticketLocation
	 * @param transactionLocation
	 */
	public Transactions(String accountLocation, String ticketLocation, String transactionLocation) {
		throw new UnsupportedOperationException();
	}

	public ArrayList<Entry> getTransactions() {
		return this.transactions;
	}

	/**
	 * 
	 * @param transactions
	 */
	public void setTransactions(ArrayList<Entry> transactions) {
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
	public boolean buy(String buyName, String event, int numTickets, String sellName) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param sellName
	 * @param event
	 * @param sellPrice
	 * @param availTicket
	 */
	public boolean sell(String sellName, String event, double sellPrice, int availTicket) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param newUser
	 * @param accountType
	 * @param accountBalance
	 */
	public boolean create(String newUser, String accountType, double accountBalance) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param username
	 */
	public boolean delete(String username) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param buyName
	 * @param sellName
	 * @param account
	 */
	public boolean refund(String buyName, String sellName, double account) {
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param username
	 * @param amount
	 */
	public boolean addcredit(String username, double amount) {
		throw new UnsupportedOperationException();
	}

}
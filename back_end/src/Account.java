public class Account {

	private string username;
	private string type;
	private double balance;

	/**
	 * 
	 * @param username
	 * @param type
	 * @param balance
	 */
	public Account(string username, string type, double balance) {
		throw new UnsupportedOperationException();
	}

	public string getType() {
		return this.type;
	}

	/**
	 * 
	 * @param type
	 */
	public void setType(string type) {
		this.type = type;
	}

	public double getBalance() {
		return this.balance;
	}

	/**
	 * 
	 * @param balance
	 */
	public void setBalance(double balance) {
		this.balance = balance;
	}

	public string getUsername() {
		return this.username;
	}

	/**
	 * 
	 * @param username
	 */
	public void setUsername(string username) {
		this.username = username;
	}

}

 /**
 * This class is responsible for setting the initial conditions for the account (type, balance, username)
 * and is responsible for changing any of these values
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Account {

	private String username;
	private String type;
	private double balance;
	
	/**
	 * 
	 * @param username
	 * @param type
	 * @param balance
	 * Account contructor to set the username, type and balance for the account
	 */
	
	public Account(String username, String type, double balance) {
		this.type = type;
		this.username = username;
		this.balance = balance;
	}

	/**
	 * This accessor method will return the type of the account
	 * @return type
	 */
	public String getType() {
		return this.type;
	}

	/**
	 * This mutator method will set the type of the account
	 * @param type
	 */
	public void setType(String type) {
		this.type = type;
	}	
	/**
	 * 
	 * @return balance
	 * This accessor method will return the available balance for the account
	 */

	public double getBalance() {
		return this.balance;
	}

	/**
	 * 
	 * @param balance
	 * This mutator method will be called when the balance is changed
	 */
	public void setBalance(double balance) {
		this.balance = balance;
	}
	/**
	 * 
	 * @return username
	 * This accessor method will retrieve the username for the account
	 */
	public String getUsername() {
		return this.username;
	}

	/**
	 * 
	 * @param username
	 * This mutator method sets the username for the account
	 */
	public void setUsername(String username) {
		this.username = username;
	}

	/**
	 * Get the account information as a line of the User Accounts file. This
	 * will be used to store the update account into the new accounts file. 
	 * @return The account's information formatted for the User Accounts file.
	 */
	public String getAccountEntry() {
		return null;
	}
	
}
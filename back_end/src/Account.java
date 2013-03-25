
 /**
 * This class is responsible for setting the initial conditions for the account (type, balance, username)
 * and is responsible for changing any of these values
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Account {
	
	// The account type for administrative users
	public static final String ADMIN = "AA";
	
	// The account type for full standard users
	public static final String FULL = "FS";
	
	// The account type for sell standard users
	public static final String SELL = "SS";
	
	// The account type for buy standard users
	public static final String BUY = "BS";
	
	public static final int MAX_USERNAME_LENGTH = 15;
	public static final int MAX_BALANCE_LENGTH = 6;
	

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
	 * This accessor method will return the available balance for the account
	 * @return balance 
	 */
	public double getBalance() {
		return this.balance;
	}

	/**
	 * This mutator method will be called when the balance is changed
	 * @param balance
	 */
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	/**
	 * Increase the balance by the given amount.
	 * @param balance The amount to increase the user's balance by.
	 */
	public void increaseBalance(double balance) {
		this.balance += balance;
	}
	
	/**
	 * Decrease the balance by the given amount.
	 * @param balance The amount to decrease the user's balance by.
	 */
	public void decreaseBalance(double balance) {
		this.balance -= balance;
	}
	
	/**
	 * This accessor method will retrieve the username for the account
	 * @return username
	 */
	public String getUsername() {
		return this.username;
	}

	/**
	 * This mutator method sets the username for the account
	 * @param username
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
		return this.username + Utility.createLine(' ', MAX_USERNAME_LENGTH
				- username.length()) + " " + this.type + " " 
				+ String.format("%09.2f", this.balance);		
	}
	
}
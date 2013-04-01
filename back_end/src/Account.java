/**
* This class is responsible for setting the initial conditions for the account (type, balance, username)
* and is responsible for changing any of these values
* 
* @author Ryan Crawford
* @author Khalil Fazal
* @author Joseph Heron
* @author Carly Marshall
*/

public class Account {

    /**
     * The account type for administrative users
     */
    public static final String ADMIN = "AA";

    /**
     * The account type for full standard users
     */
    public static final String FULL = "FS";

    /**
     * The account type for sell standard users
     */
    public static final String SELL = "SS";

    /**
     * The account type for buy standard users
     */
    public static final String BUY = "BS";

    /**
     * The maximum length of a username's length
     */
    public static final int MAX_USERNAME_LENGTH = 15;

    /**
     * The maximum length of a balance if represented as a string
     */
    public static final int MAX_BALANCE_LENGTH = 6;

    /**
     * The current account's username
     */
    private final String username;

    /**
     * The current account's type
     */
    private final String type;

    /**
     * The current account's balance
     */
    private double balance;

    /**
     * Account constructor to set the username, type and balance for the account.
     * 
     * @param username the account's username
     * @param type the account's type
     * @param balance the account's balance
     */
    public Account(final String username, final String type, final double balance) {
        this.type = type;
        this.username = username;
        this.balance = balance;
    }

    /**
     * This accessor method will return the type of the account
     * 
     * @return type
     */
    public String getType() {
        return this.type;
    }

    /**
     * This accessor method will return the available balance for the account
     * 
     * @return balance 
     */
    public double getBalance() {
        return this.balance;
    }

    /**
     * Increase the balance by the given amount.
     * 
     * @param balance The amount to increase the user's balance by.
     */
    public void increaseBalance(final double balance) {
        this.balance += balance;
    }

    /**
     * Decrease the balance by the given amount.
     * 
     * @param balance The amount to decrease the user's balance by.
     */
    public void decreaseBalance(final double balance) {
        this.balance -= balance;
    }

    /**
     * This accessor method will retrieve the username for the account
     * 
     * @return username
     */
    public String getUsername() {
        return this.username;
    }

    /**
     * Get the account information as a line of the User Accounts file. This
     * will be used to store the update account into the new accounts file.
     *  
     * @return The account's information formatted for the User Accounts file.
     */
    public String getAccountEntry() {
        return this.username + Utility.createLine(' ', MAX_USERNAME_LENGTH - this.username.length()) + " " + this.type + " "
                + String.format("%09.2f", this.balance);
    }
}
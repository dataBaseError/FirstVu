/**
 * A class to hold information for a create, delete, addcredit, or end transaction.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 *
 */
public class AuxiliaryTransaction extends Entry {

    /**
     * A symbol for a logout entry in the Daily Transaction File
     */
    public static final int LOGOUT = 0;

    /**
     * A symbol for a create entry in the Daily Transaction File
     */
    public static final int CREATE = 1;

    /**
     * A symbol for a delete entry in the Daily Transaction File
     */
    public static final int DELETE = 2;

    /**
     * A symbol for an addcredit entry in the Daily Transaction File
     */
    public static final int ADDCREDIT = 6;

    /**
     * The username of the affected account during the transaction
     */
    private String username;

    /**
     * The credit amount involved during a transaction
     */
    private double credit;

    /**
     * The account type of the account being manipulated during a transaction
     */
    private String accountType;

    /**
     * Constructor for creating a new transaction.
     * @param type The transaction type.
     * @param username The username used during transaction.
     * @param credit Amount of credit used during transaction.
     * @param accountType Type of account.
     */
    public AuxiliaryTransaction(final int type, final String username, final double credit, final String accountType) {
        super(type);
        this.username = username;
        this.credit = credit;
        this.accountType = accountType;
    }

    /**
     * Accessor method for getting the username.
     * @return Username used for transaction.
     */
    public String getUsername() {
        return this.username;
    }

    /**
     * Accessor method for getting the credit amount associated with the transaction.
     * @return Amount of credit used for transaction.
     */
    public double getCredit() {
        return this.credit;
    }


    /**
     * Accessor method for getting the user account type.
     * @return Type of the account.
     */
    public String getAccountType() {
        return this.accountType;
    }

}
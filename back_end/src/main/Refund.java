package main;


/**
 * The class for holding information about refund transactions from the daily
 * transaction file
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Refund extends Entry {

    /**
     * Refund transactions are noted in the daily transaction file by the number 5.
     */
    public static final int REFUND = 5;

    /**
     * The username of the user who is meant to receive the refund
     */
    private final String buyName;

    /**
     * The username of the user who's account is where the refund will come from
     */
    private final String sellName;

    /**
     * The amount of credit that needs to be transferred
     */
    private double credit;

    /**
     * Constructor for creating a refund transactions
     * @param type The type of transaction.
     * @param buyName The buyer's username.
     * @param sellName The seller's username.
     * @param credit The credit transferred from the seller to the buyer.
     */
    public Refund(final int type, final String buyName, final String sellName,
    		final double credit) {
        super(type);
        this.buyName = buyName;
        this.sellName = sellName;
        this.credit = credit;
    }

    /**
     * Accessor for the buyer's username.
     * @return The buyer's username.
     */
    public String getBuyName() {
        return this.buyName;
    }

    /**
     * Accessor for the seller's username.
     * @return The seller's username.
     */
    public String getSellName() {
        return this.sellName;
    }

    /**
     * Accessor for the credit transfered in the refund.
     * @return The credit amount transferred.
     */
    public double getCredit() {
        return this.credit;
    }
}
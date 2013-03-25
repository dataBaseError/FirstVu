/**
 * The class for holding information about refund transactions from the daily
 * transaction file
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public class Refund extends Entry {

	public static final int REFUND = 5;
	
    private String buyName;
    private String sellName;
    private double credit;

    /**
     * Constructor for creating a refund transactions
     * @param type The type of transaction.
     * @param buyName The buyer's username.
     * @param sellName The seller's username.
     * @param credit The credit transferred from the seller to the buyer.
     */
    public Refund(final int type, final String buyName, final String sellName, final double credit) {
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
     * Mutator method for the buyer's username.
     * @param buyName The buyer's new username.
     */
    public void setBuyName(final String buyName) {
        this.buyName = buyName;
    }

    /**
     * Accessor for the seller's username.
     * @return The seller's username.
     */
    public String getSellName() {
        return this.sellName;
    }

    /**
     * Mutator method for the seller's username.
     * @param sellName The seller's new username.
     */
    public void setSellName(final String sellName) {
        this.sellName = sellName;
    }

    /**
     * Accessor for the credit transfered in the refund.
     * @return The credit amount transferred.
     */
    public double getCredit() {
        return this.credit;
    }

    /**
     * Mutator method for the credit transferred in the refund.
     * @param credit The new amount of credit transferred.
     */
    public void setCredit(final double credit) {
        this.credit = credit;
    }
}
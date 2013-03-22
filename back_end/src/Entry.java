/**
 * Class that allows for entries to the daily transaction file.
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 *
 */
public abstract class Entry {

    protected int transactionType;

    /**
     * Constructor for creating an entry.
     * @param transactionType A number indicating the type of transaction.
     */
    public Entry(final int transactionType) {
        this.transactionType = transactionType;
    }

    /**
     * Accessor method for getting the type of transaction.
     * @return A number indicating the type of transaction.
     */
    public int getTransactionType() {
        return this.transactionType;
    }

    /**
     * Mutator method for setting the transaction type.
     * @param transactionType A number indicating the type of transaction.
     */
    public void setTransactionType(final int transactionType) {
        this.transactionType = transactionType;
    }
}
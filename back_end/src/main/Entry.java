package main;

/**
 * Class that allows for entries to the daily transaction file.
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 *
 */
public abstract class Entry {

    /**
     * The type of entry in the daily transaction file
     */
    protected int transactionType;

    /**
     * Constructor for creating an entry.
     * 
     * @param transactionType A number indicating the type of transaction.
     */
    public Entry(final int transactionType) {
        this.transactionType = transactionType;
    }

    /**
     * Accessor method for getting the type of transaction.
     * 
     * @return A number indicating the type of transaction.
     */
    public int getTransactionType() {
        return this.transactionType;
    }
}
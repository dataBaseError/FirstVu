public abstract class Entry {

    private int transactionType;

    /**
     * 
     * @param transactionType
     */
    public Entry(final int transactionType) {
        throw new UnsupportedOperationException();
    }

    public int getTransactionType() {
        return this.transactionType;
    }

    /**
     * 
     * @param transactionType
     */
    public void setTransactionType(final int transactionType) {
        this.transactionType = transactionType;
    }
}
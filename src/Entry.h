 /**
  * Abstract class that allows for entries to the daily transaction file.
  *
  * @author Ryan Crawford
  * @author Khalil Fazal
  * @author Joseph Heron
  * @author Carly Marshall
  */
class Entry {

private:
    int transactionType;

public:
    /**
     * Constructor for creating an entry.
     */
    Entry(int transactionType);

    /**
     * De-constructor for delete an entry.
     */
    ~Entry();

    /**
     * Accessor method for getting the type of transaction.
     *
     * @return Type of the transaction
     */
    int getTransactionType();

    /**
     * Mutator method for setting the transaction type
     *
     * @param transactionType Type of the transaction
     */
    void setTransactionType(int transactionType);
};

#ifndef _ENTRY_H_
#define _ENTRY_H_

/**
 * Class that allows for entries to the daily transaction file.
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

	static const int logout;
	static const int create;
	static const int del;
	static const int sell;
	static const int buy;
	static const int refund;
	static const int addcredit;

	/**
	 * Constructor for creating an entry.
	 *
	 * @param transactionType the type of transaction.
	 */
	explicit Entry(int transactionType);

	/**
	 * De-constructor for delete an entry.
	 */
	~Entry();

	/**
	 * Accessor method for getting the type of transaction.
	 *
	 * @return the type of transaction.
	 */
	int getTransactionType();

	/**
	 * Mutator method for setting the transaction type.
	 *
	 * @param transactionType the type of transaction
	 */
	void setTransactionType(int transactionType);
};

#endif // _ENTRY_H_
